package haxor.graphics.material;

import haxor.context.EngineContext;
import haxor.core.Resource;
import haxor.core.Enums.BlendMode;
import haxor.core.Enums.CullMode;
import haxor.core.Enums.DepthTest;
import haxor.core.Enums.RenderQueue;
import haxor.graphics.material.Material.MaterialUniform;
import haxor.graphics.texture.Texture;
import haxor.io.Buffer;
import haxor.io.FloatArray;
import haxor.io.Int32Array;
import haxor.io.serialization.Formatter;
import haxor.io.serialization.ISerializable;
import haxor.io.serialization.SerializedData;
import haxor.io.serialization.SerializedField;
import haxor.io.UInt16Array;
import haxor.math.Color;
import haxor.math.Matrix4;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.platform.Types.Float32;

class UniformInfo
{
	public var name:String;
	public var type:String;
	public var texture:Bool;
	public function new():Void{}
}

/**
 * Class that holds rendering information for a Renderer. 
 * The user can manipulate how pixels will be written in the buffer and pass information to the selected Shader.
 * @author Eduardo Pons
 */
@:allow(haxor)
class Material extends Resource implements ISerializable
{
	/**
	 * List of all materials.
	 */
	static public var list : Array<Material> = [];
	
	/**
	 * Shortcut for an Opaque material.
	 * @param	p_texture
	 * @param	p_ztest
	 * @param	p_zwrite
	 * @return
	 */
	static public function Opaque(p_texture:Texture = null, p_ztest:Bool = true, p_zwrite:Bool = true):Material
	{
		var m : Material = new Material("Opaque");				
		m.shader	= p_texture == null ? Shader.Flat : Shader.FlatTexture;
		m.queue 	= RenderQueue.Opaque;
		m.ztest 	= p_ztest;
		m.zwrite 	= p_zwrite;
		if(p_texture!=null) m.SetTexture("DiffuseTexture", p_texture);		
		return m;
	}
	
	
	/**
	 * Shortcut for an AlphaBlended material.
	 * @param	p_ztest
	 * @param	p_zwrite
	 * @param	p_double_sided
	 * @return
	 */
	static public function Transparent(p_texture:Texture=null,p_ztest:Bool=true,p_zwrite:Bool=true,p_double_sided:Bool=false):Material
	{
		var m : Material = new Material("Transparent");		
		if (p_double_sided) m.cull = CullMode.None;
		m.SetBlending(BlendMode.SrcAlpha, BlendMode.OneMinusSrcAlpha);
		m.shader	= p_texture == null ? Shader.Flat : Shader.FlatTexture;
		m.queue 	= RenderQueue.Transparent;
		m.ztest 	= p_ztest;
		m.zwrite 	= p_zwrite;
		m.blend		= true;
		if(p_texture!=null) m.SetTexture("DiffuseTexture", p_texture);
		//*/
		return m;
	}
	
	/**
	 * Shortcut for an Additive material using alpha as intensity.
	 * @param	p_ztest
	 * @param	p_zwrite
	 * @param	p_double_sided
	 * @return
	 */
	static public function AdditiveAlpha(p_texture:Texture=null,p_ztest:Bool=true,p_zwrite:Bool=true,p_double_sided:Bool=false):Material
	{
		var m : Material = Transparent(p_ztest, p_zwrite, p_double_sided);
		m.name = "AdditiveAlpha";
		m.SetBlending(BlendMode.SrcAlpha, BlendMode.One);
		return m;
	}
	
	/**
	 * Shortcut for an Additive material.
	 * @param	p_ztest
	 * @param	p_zwrite
	 * @param	p_double_sided
	 * @return
	 */
	static public function Additive(p_texture:Texture=null,p_ztest:Bool=true,p_zwrite:Bool=true,p_double_sided:Bool=false):Material
	{
		var m : Material = Transparent(p_ztest, p_zwrite, p_double_sided);
		m.name = "Additive";
		m.SetBlending(BlendMode.One, BlendMode.One);
		return m;
	}
	
	
	/**
	 * Flag that indicates if this material will use Z-Testing.
	 */
	@serialize
	public var ztest:Bool;
	
	/**
	 * Flag that indicates which criteria will be used for the Z-Test.
	 * Check 'DepthTest' enumeration.
	 */
	@serialize
	public var zfunc : Int;

	/**
	 * Flag that indicates that the renderer will write its Z-Depth in the ZBuffer.
	 */
	@serialize
	public var zwrite:Bool;
	
	/**
	 * Flag that indicates if blending is enabled for this material.
	 */
	@serialize
	public var blend:Bool;
		
	/**
	 * Rendering order of this material.
	 * Check the 'RenderQueue' enumeration.
	 */
	@serialize
	public var queue : Int;

	/**
	 * Source equation for this material. Only works if the 'blend' flag is true.
	 * Check the 'BlendMode' enumeration.
	 */
	@serialize
	public var blendSrc : Int;
	
	/**
	 * Destination equation for this material. Only works if the 'blend' flag is true.
	 * Check the 'BlendMode' enumeration.
	 */
	@serialize
	public var blendDst : Int;

	/**
	 * Flag that indicates if the Back triangles will be rendered instead of the Front ones.
	 */
	@serialize
	public var invert : Bool;

	/**
	 * Flag that indicates the type of triangle culling.
	 * Check 'CullMode' enumeration.
	 */
	@serialize
	public var cull : Int;
	
	/**
	 * Flag that indicates that the shader of this material will use Lighting information such Light Position or Type.
	 */
	@serialize
	public var lighting : Bool;

	/**
	 * Reference to the current Screen texture in the rendering loop.
	 */
	//public var screen : RenderTexture;
	
	/**
	 * Flag that indicates this material will grab the screen texture before rendering.
	 */
	@serialize
	public var grab : Bool = false;
	
	/**
	 * Reference to this material shader.
	 */
	@serialize
	public var shader(get_shader,set_shader) : Shader;	
	private inline function get_shader():Shader { return m_shader; }	
	private function set_shader(v:Shader):Shader 
	{		
		//if (m_shader == v) return v;		
		EngineContext.material.UpdateShader(this, m_shader, v);
		m_shader = v;
		return v; 
	}
	private var m_shader : Shader;
	
	/**
	 * List of uniforms of this material.
	 */
	@serialize
	public var uniforms(get, never):Array<MaterialUniform>;
	private function get_uniforms():Array<MaterialUniform> { return m_uniforms; }
	private var m_uniforms : Array<MaterialUniform>;
	
	/**
	 * Creates a new Material.
	 * @param	p_name
	 */
	public function new(p_name:String="")
	{
		super(p_name);	
		__cid 			= EngineContext.material.mid.id;
		m_uniforms		= [];
		queue           = RenderQueue.Opaque;
		zfunc           = DepthTest.LessEqual;
		ztest		    = true;
		zwrite			= true;
		blend		    = false;
		blendSrc        = BlendMode.One;
		blendDst        = BlendMode.Zero;
		invert		    = false;
		cull            = CullMode.Back;
		lighting		= false;
		grab			= false;			
		EngineContext.material.InitializeMaterial(this);
		list.push(this);
	}
	
	/**
	 * Simultaneously sets this material blending Source and Destination equations.
	 * @param	p_src
	 * @param	p_dst
	 */
	public function SetBlending(p_src : Int, p_dst : Int):Void
	{
		blendSrc = p_src;
		blendDst = p_dst;
	}
	
	/**
	 * Returns the list of uniforms present in the shader/program context.
	 */
	public function GetActiveUniforms():Array<UniformInfo>
	{
		if (shader == null) return [];
		return EngineContext.material.GetActiveUniforms(this);		
	}
	
	
	/**
	 * Sets a Texture sampler uniform.
	 * @param	p_name
	 * @param	p_texture
	 */
	public function SetTexture(p_name:String, p_texture:Texture):Void
	{
		if (p_texture == null) { RemoveUniform(p_name); return; }
		var u : MaterialUniform = FetchUniform(p_name, false, 1, 1, true);		
		if (u.exists)
		{			
			u.SetTexture(p_texture);
		}
	}
	
	/**
	 * Sets a mat4 uniform.
	 * @param	p_name
	 * @param	p_matrix4
	 */
	public function SetMatrix4(p_name:String, p_matrix4:Matrix4,p_transpose:Bool=false):Void 
	{ 
		if (p_matrix4 == null) { RemoveUniform(p_name); return; } 
		var u : MaterialUniform = FetchUniform(p_name, true, 16, 16, true);
		if (u.exists) u.SetMatrix4(p_matrix4,p_transpose);		
	}
	
	/**
	 * Sets a vec2.
	 * @param	p_name
	 * @param	p_v
	 */
	public inline function SetVector2(p_name:String, p_v : Vector2):Void  { SetFloat2(p_name, p_v.x, p_v.y); }
	
	/**
	 * Sets a vec3.
	 * @param	p_name
	 * @param	p_v
	 */
	public inline function SetVector3(p_name:String, p_v : Vector3):Void  { SetFloat3(p_name, p_v.x, p_v.y, p_v.z); }
	
	/**
	 * Sets a vec4.
	 * @param	p_name
	 * @param	p_v
	 */
	public inline function SetVector4(p_name:String, p_v : Vector4):Void  { SetFloat4(p_name, p_v.x, p_v.y, p_v.z, p_v.w); }
	
	/**
	 * Sets a vec4.
	 * @param	p_name
	 * @param	p_color
	 */
	public inline function SetColor(p_name:String, p_color : Color):Void { SetFloat4(p_name, p_color.r, p_color.g, p_color.b, p_color.a); }
	
	/**
	 * Sets a float.
	 * @param	p_name
	 * @param	p_v
	 */
	public function SetFloat(p_name : String, p_v : Float32):Void {  var u : MaterialUniform = FetchUniform(p_name, true, 1,1,true);if (u.exists) u.SetFloat(p_v); }
	
	/**
	 * Sets a vec2.
	 * @param	p_name
	 * @param	p_x
	 * @param	p_y
	 */
	public function SetFloat2(p_name : String, p_x:Float32, p_y:Float32):Void { var u : MaterialUniform = FetchUniform(p_name, true, 2,2,true); if (u.exists) u.SetFloat2(p_x,p_y); }
	
	/**
	 * Sets a vec3.
	 * @param	p_name
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 */
	public function SetFloat3(p_name : String, p_x:Float32, p_y:Float32, p_z:Float32):Void { var u : MaterialUniform = FetchUniform(p_name, true, 3,3,true); if (u.exists) u.SetFloat3(p_x,p_y,p_z); }
	
	/**
	 * Sets vec4.
	 * @param	p_name
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 */
	public function SetFloat4(p_name : String, p_x:Float32, p_y:Float32, p_z:Float32,p_w:Float32):Void { var u : MaterialUniform = FetchUniform(p_name, true, 4,4, true); if (u.exists) u.SetFloat4(p_x,p_y,p_z,p_w);	}
	
	/**
	 * Sets a float[].
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetFloatArray(p_name:String, p_list : Array<Float32>):Void { var u : MaterialUniform = FetchUniform(p_name, true, p_list.length, 1, true);if (u.exists) u.SetFloatArray(p_list); }
	
	/**
	 * Sets a vec2[].
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetFloat2Array(p_name:String, p_list : Array<Float32>):Void { var u : MaterialUniform = FetchUniform(p_name, true, p_list.length, 2, true); if (u.exists) u.SetFloat2Array(p_list); }
	
	/**
	 * Sets a vec3[].
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetFloat3Array(p_name:String, p_list : Array<Float32>):Void { var u : MaterialUniform = FetchUniform(p_name, true, p_list.length, 3, true); if (u.exists) u.SetFloat3Array(p_list); }
	
	/**
	 * Sets vec4[].
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetFloat4Array(p_name:String, p_list : Array<Float32>):Void { var u : MaterialUniform = FetchUniform(p_name, true, p_list.length,4,true);if (u.exists) u.SetFloat4Array(p_list); }
	
	/**
	 * Sets an int.
	 * @param	p_name
	 * @param	p_v
	 */
	public function SetInt(p_name : String, p_v : Int):Void  {  var u : MaterialUniform = FetchUniform(p_name, false, 1, 1, true); if (u.exists) u.SetInt(p_v); }
	
	/**
	 * Sets an int2.
	 * @param	p_name
	 * @param	p_x
	 * @param	p_y
	 */
	public function SetInt2(p_name : String, p_x:Int, p_y:Int):Void { var u : MaterialUniform = FetchUniform(p_name, false, 2, 2, true); if (u.exists) u.SetInt2(p_x, p_y);	 }
	
	/**
	 * Sets an int3
	 * @param	p_name
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 */
	public function SetInt3(p_name : String, p_x:Int, p_y:Int, p_z:Int):Void { var u : MaterialUniform = FetchUniform(p_name, false, 3, 3, true); if (u.exists) u.SetInt3(p_x, p_y, p_z); }
		
	/**
	 * Sets an int4.
	 * @param	p_name
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 */
	public function SetInt4(p_name : String, p_x:Int, p_y:Int, p_z:Int,p_w:Int):Void { var u : MaterialUniform = FetchUniform(p_name, false, 4, 4, true); if (u.exists) u.SetInt4(p_x, p_y, p_z, p_w); }
	
	/**
	 * Sets an int[].
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetIntArray(p_name:String, p_list : Array<Int>):Void { var u : MaterialUniform = FetchUniform(p_name, false, p_list.length,1,true);if (u.exists) u.SetIntArray(p_list); }
	
	/**
	 * Sets an int2[].
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetInt2Array(p_name:String, p_list : Array<Int>):Void { var u : MaterialUniform = FetchUniform(p_name, false, p_list.length, 2, true); if (u.exists) u.SetInt2Array(p_list); }
	
	/**
	 * Sets an int3[].
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetInt3Array(p_name:String, p_list : Array<Int>):Void { var u : MaterialUniform = FetchUniform(p_name, false, p_list.length, 3, true); if(u.exists)u.SetInt3Array(p_list); }
	
	/**
	 * Sets an int4[].
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetInt4Array(p_name:String, p_list : Array<Int>):Void { var u : MaterialUniform = FetchUniform(p_name, false, p_list.length,4,true); if (u.exists) u.SetInt4Array(p_list); }
	
	/**
	 * Returns the explicit uniform instance.
	 * @param	p_name
	 * @return
	 */
	public function GetUniform(p_name:String):MaterialUniform
	{		
		for (i in 0...m_uniforms.length) if (m_uniforms[i].name == p_name) return m_uniforms[i];
		return null;
	}
	
	/**
	 * Returns true if the uniform exists. If the 'check_shader' flag is true, it will also check if the uniform exists in the current shader.
	 * @param	p_name
	 * @param	p_check_shader
	 * @return
	 */
	public function HasUniform(p_name:String,p_check_shader:Bool=false):Bool
	{
		for (i in 0...m_uniforms.length)
		{
			if (m_uniforms[i].name == p_name)
			{
				if (p_check_shader) return m_uniforms[i].exists;
				return true;
			}
		}
		return false;
	}
	
	/**
	 * Removes an uniform from this material.
	 * @param	p_name
	 */
	public function RemoveUniform(p_name:String):Void
	{
		var u : MaterialUniform=null;
		for (i in 0...m_uniforms.length)
		{
			u = m_uniforms[i];
			if (u.name == p_name) break;
		}			
		if (u != null)
		{
			if (u.texture != null) u.texture.__slot = -1;
			EngineContext.material.DestroyUniform(this, u);
			m_uniforms.remove(u);
		}
	}
	
	
	/**
	 * Internal method to search for uniforms.
	 * @param	p_name
	 * @return
	 */
	private function FetchUniform(p_name:String,p_is_float:Bool,p_length:Int,p_offset:Int,p_create:Bool):MaterialUniform
	{
		
		var u : MaterialUniform = null;
		for (i in 0...m_uniforms.length)
		{
			u = m_uniforms[i];			
			if (u.name == p_name)
			{
				if (u.isFloat == p_is_float)
				{
					if (u.offset == p_offset)
					{
						if (u.data.length == p_length)						
						return u;
					}
				}
				//Found by name but different setup.
				EngineContext.material.DestroyUniform(this, u);
				m_uniforms.remove(u);
				break;
			}
		}
		if (p_create)
		{
			u = new MaterialUniform(p_name, p_is_float, p_length,p_offset); 
			EngineContext.material.CreateUniform(this, u);
			m_uniforms.push(u);			
		}		
		return u;
	}
	
	private function SetUniformFloat(u : MaterialUniform):Void
	{		
		var d : FloatArray = cast u.data;		
		var is_array : Bool = d.length > u.offset;
		var l : Array<Float32> = null;
		if (is_array)
		{
			l = [];
			for (i in 0...d.length) l.push(d.Get(i));			
		}
		
		switch(u.offset)
		{
			case 1:  if(is_array) SetFloatArray(u.name,l)  else SetFloat(u.name,  d.Get(0));
			case 2:  if(is_array) SetFloat2Array(u.name,l) else SetFloat2(u.name, d.Get(0), d.Get(1));
			case 3:  if(is_array) SetFloat3Array(u.name,l) else SetFloat3(u.name, d.Get(0), d.Get(1), d.Get(2));
			case 4:  if(is_array) SetFloat4Array(u.name,l) else SetFloat4(u.name, d.Get(0), d.Get(1), d.Get(2), d.Get(3));
			case 16: 			
			var mat : Matrix4 = Matrix4.temp;
			for (i in 0...16) mat.SetIndex(i, d.Get(i));			
			if (u.transposed) mat.Transpose();
			SetMatrix4(u.name, mat, u.transposed);
			
			default:			
			
		}
	}
	
	
	
	private function SetUniformInt(u : MaterialUniform):Void
	{		
		var d : Int32Array = cast u.data;
		var is_array : Bool = d.length > u.offset;
		var l : Array<Int> = null;
		if (is_array)
		{
			l = [];
			for (i in 0...d.length) l.push(d.Get(i));			
		}
		
		switch(u.offset)
		{
			case 1:  
				if (u.texture != null)
				{
					SetTexture(u.name, u.texture);
				}
				else
				{
					if(is_array) SetIntArray(u.name,l) else SetInt(u.name,  d.Get(0));
				}
			case 2: if(is_array) SetInt2Array(u.name,l) else SetInt2(u.name, d.Get(0), d.Get(1));
			case 3: if(is_array) SetInt3Array(u.name,l) else SetInt3(u.name, d.Get(0), d.Get(1), d.Get(2));
			case 4: if(is_array) SetInt4Array(u.name,l) else SetInt4(u.name, d.Get(0), d.Get(1), d.Get(2), d.Get(3));			
		}
	}
	
	/**
	 * Clears the Material data.
	 */
	override public function OnDestroy():Void 
	{
		list.remove(this);
		EngineContext.material.DestroyMaterial(this);
	}
	
	/**
	 * Callback called when a field can be serialized in a different way.
	 * @param	p_field
	 * @return
	 */
	public function OnSerializeField(p_field:SerializedField,p_fmt:Formatter):String { return null; }
	
	/**
	 * Callback called when a field should be deserialized in a different way.
	 * @param	p_field
	 * @return
	 */
	public function OnDeserializeField(p_field:SerializedField,p_fmt:Formatter):Bool
	{
		var fmt : Formatter = p_fmt;
		var uf: SerializedField = p_field;
		var m : Material = this;
		switch(uf.name)
		{
			case "uniforms":
			{
				var unl : Array<SerializedData> = cast uf.value;
				var f : SerializedField;
				
				for (i in 0...unl.length)
				{			
					var un 			: SerializedData = unl[i];
					var name 	    : String  = fmt.GetField(un,"name").value;
					f = fmt.GetField(un,"texture");
					if (f!=null)
					{	
						var texture	: Texture = cast Formatter.FromString(f.value, f.type);
						if (texture != null)
						{					
							m.SetTexture(name, texture);
						}
					}			
					else
					{				
						var offset	   : Int 	 = Std.parseInt(fmt.GetField(un,"offset").value);				
						var data	   : String  = fmt.GetField(un,"data").value;
						var is_float   : Bool    = fmt.GetField(un,"isFloat").value == "true";
						var transposed : Bool    = fmt.GetField(un,"transposed").value == "true";
					
						if (is_float)
						{
							var b 			: FloatArray 		= FloatArray.Parse(data, ",", true);
							var is_array 	: Bool     			= (b.length > offset);
							var l 			: Array<Float32>  	= is_array ? b.ToArray() : null;
							
							switch(offset)
							{
								case 1:  is_array ? m.SetFloatArray(name,l)   : m.SetFloat(name,  b.Get(0));
								case 2:  is_array ? m.SetFloat2Array(name, l) : m.SetFloat2(name, b.Get(0),b.Get(1));
								case 3:  is_array ? m.SetFloat3Array(name, l) : m.SetFloat3(name, b.Get(0),b.Get(1),b.Get(2));
								case 4:  is_array ? m.SetFloat4Array(name, l) : m.SetFloat4(name, b.Get(0), b.Get(1), b.Get(2), b.Get(3));
								case 16: m.SetMatrix4(name, Matrix4.FromArray(b.ToArray()), transposed);
							}
						}
						else
						{
							var b 			: Int32Array 	= Int32Array.Parse(data, ",", true);
							var is_array 	: Bool 			= (b.length > offset);
							var l 			: Array<Int>  	= is_array ? b.ToArray() : null;
							switch(offset)
							{
								case 1:  is_array ? m.SetIntArray(name,l)   : m.SetInt(name,  b.Get(0));
								case 2:  is_array ? m.SetInt2Array(name, l) : m.SetInt2(name, b.Get(0),b.Get(1));
								case 3:  is_array ? m.SetInt3Array(name, l) : m.SetInt3(name, b.Get(0),b.Get(1),b.Get(2));
								case 4:  is_array ? m.SetInt4Array(name, l) : m.SetInt4(name, b.Get(0), b.Get(1), b.Get(2), b.Get(3));
							}
						}				
					}
				}
				return true;
			}
		}		
		return false;
	}
	
}

/**
 * Class that represents an Uniform data that will be sent to shaders.
 */
@:allow(haxor)
class MaterialUniform
{
	/**
	 * Class instance id.
	 */
	private var __cid : Int;
	
	/**
	 * Flag that indicates that this uniform changed value.
	 */
	private var __d : Bool;
	
	/**
	 * Uniform name.
	 */
	@serialize
	public var name : String;
	
	/**
	 * Tuple offset.
	 */
	@serialize
	public var offset : Int;
	
	/**
	 * Uniform data. Can be Int Float or Buffer
	 */
	@serialize
	public var data : Buffer;
	
	/**
	 * If matrix4 uniform, is transposed?
	 */
	@serialize
	public var transposed : Bool;
	
	/**
	 * Reference to the texture if any.
	 */
	@serialize
	public var texture : Texture;
	
	/**
	 * Flag that indicates if the data is made of floats otherwise is int.
	 */
	@serialize
	public var isFloat : Bool;
	
	/**
	 * Flag that indicates if this uniforms exists within the material.
	 */
	private var exists : Bool;
	
	/**
	 * Creates a new MaterialUniform.
	 * @param	p_name
	 * @param	p_is_float
	 * @param	p_length
	 */
	private function new(p_name:String,p_is_float : Bool,p_length:Int,p_offset:Int):Void
	{
		__cid   = EngineContext.material.uid.id;
		__d		= true;
		name  	= p_name;
		isFloat   = p_is_float;
		offset	= p_offset;
		exists	= false;
		transposed = false;
		if (p_is_float)
		{
			data = new FloatArray(p_length);
		}
		else
		{
			data = new Int32Array(p_length);
		}
	}
		
	public function SetFloat	  (p_v : Float32):Void 									{ if (!exists) return; __d = true;	var b : FloatArray = cast data; b.Set(0, p_v); }
	public function SetFloat2	  (p_x:Float32, p_y:Float32):Void 						{ if (!exists) return; __d = true;	var b : FloatArray = cast data; b.Set(0, p_x); b.Set(1, p_y); }
	public function SetFloat3	  (p_x:Float32, p_y:Float32, p_z:Float32):Void 			{ if (!exists) return; __d = true;	var b : FloatArray = cast data; b.Set(0, p_x); b.Set(1, p_y); b.Set(2, p_z); }
	public function SetFloat4	  (p_x:Float32, p_y:Float32, p_z:Float32,p_w:Float32):Void 	{ if (!exists) return; __d = true;	var b : FloatArray = cast data; b.Set(0, p_x); b.Set(1, p_y); b.Set(2, p_z); b.Set(3, p_w);	}
	public function SetFloatArray (p_list : Array<Float32>):Void 						{ if (!exists) return; __d = true; 	var b : FloatArray = cast data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	public function SetFloat2Array(p_list : Array<Float32>):Void 						{ if (!exists) return; __d = true;	var b : FloatArray = cast data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	public function SetFloat3Array(p_list : Array<Float32>):Void 						{ if (!exists) return; __d = true;	var b : FloatArray = cast data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	public function SetFloat4Array(p_list : Array<Float32>):Void 						{ if (!exists) return; __d = true;	var b : FloatArray = cast data;	for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	
	public function SetInt		  (p_v : Int):Void  						{ if (!exists) return; __d = true; var b : Int32Array = cast data; b.Set(0, p_v); }
	public function SetInt2		  (p_x:Int, p_y:Int):Void					{ if (!exists) return; __d = true; var b : Int32Array = cast data; b.Set(0, p_x); b.Set(1, p_y); }
	public function SetInt3		  (p_x:Int, p_y:Int, p_z:Int):Void			{ if (!exists) return; __d = true; var b : Int32Array = cast data; b.Set(0, p_x); b.Set(1, p_y); b.Set(2, p_z); }
	public function SetInt4		  (p_x:Int, p_y:Int, p_z:Int,p_w:Int):Void	{ if (!exists) return; __d = true; var b : Int32Array = cast data; b.Set(0, p_x); b.Set(1, p_y); b.Set(2, p_z); b.Set(3, p_w); }
	public function SetIntArray	  (p_list : Array<Int>):Void 				{ if (!exists) return; __d = true; var b : Int32Array = cast data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	public function SetInt2Array  (p_list : Array<Int>):Void 				{ if (!exists) return; __d = true; var b : Int32Array = cast data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	public function SetInt3Array  (p_list : Array<Int>):Void 				{ if (!exists) return; __d = true; var b : Int32Array = cast data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	public function SetInt4Array  (p_list : Array<Int>):Void 				{ if (!exists) return; __d = true; var b : Int32Array = cast data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	
	public function Refresh():Void { if (!exists) return; __d = true; }
	
	public function SetTexture(p_texture:Texture):Void 
	{ 
		if (!exists) return; 
		if (p_texture == texture) return;
		if (texture == null) __d = true;
		var b : Int32Array = cast data;
		var ts:Int = texture == null ? -1 : texture.__slot;
		if (texture != null) texture.__slot = -1;
		texture = p_texture; 
		if (texture != null) texture.__slot = ts;		
		b.Set(0,ts);		
	}	
	
	public function SetMatrix4(m:Matrix4,t:Bool=false):Void 
	{ 
		if (!exists) return; __d = true; 
		transposed = t;
		var b : FloatArray = cast data; 		
		//var l : Array<Float32> = EngineContext.data.Matrix4ToArray(p_matrix4); 		for (i in 0...16) b.Set(i, l[i]); 		
		if (!t)
		{
			b.Set(0,  m.m00); b.Set(1,  m.m01); b.Set(2,  m.m02); b.Set(3,  m.m03);
			b.Set(4,  m.m10); b.Set(5,  m.m11); b.Set(6,  m.m12); b.Set(7,  m.m13);
			b.Set(8,  m.m20); b.Set(9,  m.m21); b.Set(10, m.m22); b.Set(11, m.m23);		
			b.Set(12, m.m30); b.Set(13, m.m31); b.Set(14, m.m32); b.Set(15, m.m33);
		}
		else
		{
			b.Set(0,  m.m00); b.Set(1,  m.m10); b.Set(2,  m.m20); b.Set(3,  m.m30);
			b.Set(4,  m.m01); b.Set(5,  m.m11); b.Set(6,  m.m21); b.Set(7,  m.m31);
			b.Set(8,  m.m02); b.Set(9,  m.m12); b.Set(10, m.m22); b.Set(11, m.m32);		
			b.Set(12, m.m03); b.Set(13, m.m13); b.Set(14, m.m23); b.Set(15, m.m33);
		}		
		
	}	
	public inline function SetVector2(p_v : Vector2):Void  { SetFloat2(p_v.x, p_v.y); }
	public inline function SetVector3(p_v : Vector3):Void  { SetFloat3(p_v.x, p_v.y, p_v.z); }	
	public inline function SetVector4(p_v : Vector4):Void  { SetFloat4(p_v.x, p_v.y, p_v.z, p_v.w); }
	public inline function SetColor(p_color : Color):Void  { SetFloat4(p_color.r, p_color.g, p_color.b, p_color.a); }	
	
}