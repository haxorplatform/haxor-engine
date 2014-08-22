
package haxor.graphics.material;

import haxor.context.EngineContext;
import haxor.core.Resource;
import haxor.graphics.Enums.BlendMode;
import haxor.graphics.Enums.CullMode;
import haxor.graphics.Enums.DepthTest;
import haxor.graphics.Enums.RenderQueue;
import haxor.graphics.texture.Texture;
import haxor.io.Buffer;
import haxor.io.FloatArray;
import haxor.io.Int32Array;
import haxor.io.UInt16Array;


/**
 * Class that holds rendering information for a Renderer. 
 * The user can manipulate how pixels will be written in the buffer and pass information to the selected Shader.
 * @author Eduardo Pons
 */
@:allow(haxor)
class Material extends Resource
{
	
	/**
	 * Flag that indicates if this material will use Z-Testing.
	 */	
	public var ztest:Bool;
	
	/**
	 * Flag that indicates which criteria will be used for the Z-Test.
	 * Check 'DepthTest' enumeration.
	 */
	public var zfunc : Int;

	/**
	 * Flag that indicates that the renderer will write its Z-Depth in the ZBuffer.
	 */
	public var zwrite:Bool;
	
	/**
	 * Flag that indicates if blending is enabled for this material.
	 */
	public var blend:Bool;
		
	/**
	 * Rendering order of this material.
	 * Check the 'RenderQueue' enumeration.
	 */
	public var queue : Int;

	/**
	 * Source equation for this material. Only works if the 'blend' flag is true.
	 * Check the 'BlendMode' enumeration.
	 */
	public var blendSrc : Int;
	
	/**
	 * Destination equation for this material. Only works if the 'blend' flag is true.
	 * Check the 'BlendMode' enumeration.
	 */
	public var blendDst : Int;

	/**
	 * Flag that indicates if the Back triangles will be rendered instead of the Front ones.
	 */
	public var invert : Bool;

	/**
	 * Flag that indicates the type of triangle culling.
	 * Check 'CullMode' enumeration.
	 */
	public var cull : Int;
	
	/**
	 * Flag that indicates that the shader of this material will use Lighting information such Light Position or Type.
	 */
	public var lighting : Bool;

	/**
	 * Reference to the current Screen texture in the rendering loop.
	 */
	//public var screen : RenderTexture;
	
	/**
	 * Flag that indicates this material will grab the screen texture before rendering.
	 */
	public var grab : Bool = false;
	
	/**
	 * Reference to this material shader.
	 */
	public var shader(get_shader,set_shader) : Shader;
	private inline function get_shader():Shader { return m_shader; }
	private function set_shader(v:Shader):Shader 
	{		
		if (m_shader == v) return v;		
		EngineContext.material.UpdateShader(this, m_shader, v);
		m_shader = v;
		return v; 
	}
	private var m_shader : Shader;
	
	/**
	 * List of uniforms of this material.
	 */
	private var m_uniforms : Array<MaterialUniform>;
	
	/**
	 * Creates a new Material.
	 * @param	p_name
	 */
	public function new(p_name)
	{
		super(p_name);	
		__cid 			= EngineContext.material.mid++;
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
	 * Sets a texture sampler for this material.
	 * @param	p_name
	 * @param	p_texture
	 */
	public function SetTexture(p_name:String, p_texture:Texture):Void
	{
		if (p_texture == null) { RemoveUniform(p_name); return; } 
		var u : MaterialUniform = FetchUniform(p_name, false, 1,1,true);		
		var b : Int32Array = cast u.data; b.Set(0, p_texture.__slot);
		u.texture = p_texture;
	}
	
	/**
	 * Sets a Float.
	 * @param	p_name
	 * @param	p_v
	 */
	public function SetFloat(p_name : String, p_v : Float):Void {  var u : MaterialUniform = FetchUniform(p_name, true, 1,1,true);	var b : FloatArray = cast u.data; b.Set(0, p_v); }
	
	/**
	 * Sets 4 floats uniform.
	 * @param	p_name
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 */
	public function SetFloat4(p_name : String, p_x:Float, p_y:Float, p_z:Float,p_w:Float):Void { var u : MaterialUniform = FetchUniform(p_name, true, 4,4, true); var b : FloatArray = cast u.data; b.Set(0, p_x); b.Set(1, p_y); b.Set(2, p_z); b.Set(3, p_w);	}
	
	/**
	 * Sets 3 float uniform.
	 * @param	p_name
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 */
	public function SetFloat3(p_name : String, p_x:Float, p_y:Float, p_z:Float):Void { var u : MaterialUniform = FetchUniform(p_name, true, 3,3,true); var b : FloatArray = cast u.data; b.Set(0, p_x); b.Set(1, p_y); b.Set(2, p_z); }
	
	/**
	 * Sets 2 float uniform.
	 * @param	p_name
	 * @param	p_x
	 * @param	p_y
	 */
	public function SetFloat2(p_name : String, p_x:Float, p_y:Float):Void { var u : MaterialUniform = FetchUniform(p_name, true, 2,2,true); var b : FloatArray = cast u.data; b.Set(0, p_x); b.Set(1, p_y); }
	
	/**
	 * Sets a list of float uniform.
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetFloatArray(p_name:String, p_list : Array<Float>):Void { var u : MaterialUniform = FetchUniform(p_name, true, p_list.length, 1, true); var b : FloatArray = cast u.data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	
	/**
	 * Sets a list of 2 floats uniforms.
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetFloat2Array(p_name:String, p_list : Array<Float>):Void { var u : MaterialUniform = FetchUniform(p_name, true, p_list.length, 2, true); var b : FloatArray = cast u.data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	
	/**
	 * Sets a list of 3 floats uniforms.
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetFloat3Array(p_name:String, p_list : Array<Float>):Void { var u : MaterialUniform = FetchUniform(p_name, true, p_list.length, 3, true); var b : FloatArray = cast u.data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	
	/**
	 * Sets a list of 4 floats uniforms.
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetFloat4Array(p_name:String, p_list : Array<Float>):Void { var u : MaterialUniform = FetchUniform(p_name, true, p_list.length,4,true); var b : FloatArray = cast u.data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	
	
	/**
	 * Sets an Int.
	 * @param	p_name
	 * @param	p_v
	 */
	public function SetInt(p_name : String, p_v : Int):Void  
	{ 
		var u : MaterialUniform = FetchUniform(p_name, false, 1,1,true);		
		var b : Int32Array = cast u.data; b.Set(0, p_v); 
	}
	
	/**
	 * Sets 4 ints uniform.
	 * @param	p_name
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 */
	public function SetInt4(p_name : String, p_x:Int, p_y:Int, p_z:Int,p_w:Int):Void
	{
		var u : MaterialUniform = FetchUniform(p_name, false, 4,4,true);
		var b : Int32Array = cast u.data; b.Set(0, p_x); b.Set(1, p_y); b.Set(2, p_z); b.Set(3, p_w);
	}
	
	/**
	 * Sets 3 ints uniform.
	 * @param	p_name
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 */
	public function SetInt3(p_name : String, p_x:Int, p_y:Int, p_z:Int):Void
	{
		var u : MaterialUniform = FetchUniform(p_name, false, 3,3,true);
		var b : Int32Array = cast u.data; b.Set(0, p_x); b.Set(1, p_y); b.Set(2, p_z);
	}
	
	/**
	 * Sets a 2 int uniform.
	 * @param	p_name
	 * @param	p_x
	 * @param	p_y
	 */
	public function SetInt2(p_name : String, p_x:Int, p_y:Int):Void
	{
		var u : MaterialUniform = FetchUniform(p_name, false, 2,2,true);
		var b : Int32Array = cast u.data; b.Set(0, p_x); b.Set(1, p_y);
	}
	
	/**
	 * Sets a list of ints uniform.
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetIntArray(p_name:String, p_list : Array<Int>):Void { var u : MaterialUniform = FetchUniform(p_name, false, p_list.length,1,true); var b : Int32Array = cast u.data;  for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	
	/**
	 * Sets a list of 2 ints uniforms.
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetInt2Array(p_name:String, p_list : Array<Int>):Void { var u : MaterialUniform = FetchUniform(p_name, false, p_list.length, 2, true); var b : Int32Array = cast u.data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	
	/**
	 * Sets a list of 3 ints uniforms.
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetInt3Array(p_name:String, p_list : Array<Int>):Void { var u : MaterialUniform = FetchUniform(p_name, false, p_list.length, 3, true); var b : Int32Array = cast u.data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	
	/**
	 * Sets a list of 4 ints uniforms.
	 * @param	p_name
	 * @param	p_list
	 */
	public function SetInt4Array(p_name:String, p_list : Array<Int>):Void { var u : MaterialUniform = FetchUniform(p_name, false, p_list.length,4,true); var b : Int32Array = cast u.data; for (i in 0...p_list.length) b.Set(i, p_list[i]); }
	
	
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
						u.__d = true;
						return u;
					}
				}
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
		
	/*
	override private function Clone():Dynamic 
	{
		var m : Material = new Material();
		m.name 			= name + "Copy";
		m.shader 		= shader;
		m.queue         = queue;
		m.zfunc         = zfunc;
		m.ztest		    = ztest;
		m.zwrite		= zwrite;
		m.blend		    = blend;
		m.blendSrc      = blendSrc;
		m.blendDst      = blendDst;
		m.invert		= invert;
		m.cull          = cull; 	
		m.lighting		= lighting;
		m.grab			= grab;
		var ul : Iterator<String> = uniforms;
		while (ul.hasNext())
		{
			var u : String = ul.next();
			m.SetUniform(u, GetUniform(u));
		}
		return m;		
	}
	//*/
	
	/**
	 * Clears the Material data.
	 */
	override public function OnDestroy():Void 
	{
		EngineContext.material.DestroyMaterial(this);
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
	private var name : String;
	
	/**
	 * Uniform data. Can be Int Float or Buffer
	 */
	private var data : Buffer;
	
	/**
	 * Tuple offset.
	 */
	private var offset : Int;
	
	/**
	 * Reference to the texture if any.
	 */
	private var texture : Texture;
	
	/**
	 * Flag that indicates if the data is made of floats otherwise is int.
	 */
	private var isFloat : Bool;
	
	/**
	 * Creates a new MaterialUniform.
	 * @param	p_name
	 * @param	p_is_float
	 * @param	p_length
	 */
	private function new(p_name:String,p_is_float : Bool,p_length:Int,p_offset:Int):Void
	{
		__cid   = EngineContext.material.uid++;
		__d		= true;
		name  	= p_name;
		isFloat = p_is_float;
		offset	= p_offset;
		if (p_is_float)
		{
			data = new FloatArray(p_length);
		}
		else
		{
			data = new Int32Array(p_length);
		}
	}
	
	
	
}