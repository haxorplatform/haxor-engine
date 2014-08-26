package haxor.context;
import haxor.core.Console;
import haxor.graphics.Enums.BlendMode;
import haxor.graphics.Enums.CullMode;
import haxor.graphics.Enums.DepthTest;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.material.UberShader;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.mesh.Mesh.MeshAttrib;
import haxor.io.FloatArray;
import haxor.io.Int32Array;
import haxor.graphics.GL;
import haxor.platform.Types.MeshBufferId;
import haxor.platform.Types.ProgramId;
import haxor.platform.Types.ShaderId;
import haxor.platform.Types.UniformLocation;

/**
 * Class that handles Material related internal structures and behaviours.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class MaterialContext
{
	
	/**
	 * Unique material ids.
	 */
	private var mid : UID;
	
	/**
	 * Unique shader ids.
	 */
	private var sid : UID;
	
	/**
	 * Unique uniform ids.
	 */
	private var uid : UID;
	
	/**
	 * List of vertex shaders id for Shader classes.
	 */
	private var vertex_shaders : Array<ShaderId>;
	
	/**
	 * List of fragment shaders id for Shader classes.
	 */
	private var fragment_shaders : Array<ShaderId>;
	
	/**
	 * Shader to show that a given Material or Shader is invalid.
	 */
	private var error_shader : Shader;
	
	/**
	 * List of shader programs for Material classes.
	 */
	private var programs : Array<ProgramId>;
	
	/**
	 * List of locations per program.
	 */
	private var locations : Array<Array<Int>>;
	
	/**
	 * List of uniform locations by material.
	 */
	private var uniforms : Array <Array<UniformLocation>>;
	
	
	/**
	 * Currently bound material.
	 */
	private var current : Material;
	
	/**
	 * Flag that indicates if this material will use Z-Testing.
	 */	
	private var ztest:Bool;
	
	/**
	 * Flag that indicates which criteria will be used for the Z-Test.
	 * Check 'DepthTest' enumeration.
	 */
	private var zfunc : Int;

	/**
	 * Flag that indicates that the renderer will write its Z-Depth in the ZBuffer.
	 */
	private var zwrite:Bool;
	
	/**
	 * Flag that indicates if blending is enabled for this material.
	 */
	private var blend:Bool;
		
	/**
	 * Rendering order of this material.
	 * Check the 'RenderQueue' enumeration.
	 */
	private var queue : Int;

	/**
	 * Source equation for this material. Only works if the 'blend' flag is true.
	 * Check the 'BlendMode' enumeration.
	 */
	private var blendSrc : Int;
	
	/**
	 * Destination equation for this material. Only works if the 'blend' flag is true.
	 * Check the 'BlendMode' enumeration.
	 */
	private var blendDst : Int;

	/**
	 * Flag that indicates if the Back triangles will be rendered instead of the Front ones.
	 */
	private var invert : Bool;
		
	/**
	 * Flag that indicates the type of triangle culling.
	 * Check 'CullMode' enumeration.
	 */
	public var cull : Int;
	
	
	/**
	 * Creates the Mesh context to handle internal structures.
	 */
	private function new() 
	{
		mid = new UID();
		sid = new UID();		
		uid = new UID();
		
		
		zfunc           = DepthTest.LessEqual;
		ztest		    = true;
		zwrite			= true;
		blend		    = false;
		blendSrc        = BlendMode.One;
		blendDst        = BlendMode.Zero;
		invert		    = false;
		cull            = CullMode.Back;
		
		var max_buffers : Int = 512;
		var max_programs : Int = 256;
		
		locations			= [];
		uniforms			= [];
		programs			= [];
		vertex_shaders 	 	= [];
		fragment_shaders 	= [];
		
		for (i in 0...max_programs)
		{
			var l : Array<Int> = [];
			var ul : Array<UniformLocation> = [];
			for (j in 0...max_buffers) l.push( -1);
			for (j in 0...200) ul.push(GL.INVALID);
			locations.push(l);
			uniforms.push(ul);
			programs.push(GL.INVALID);
			vertex_shaders.push(GL.INVALID);
			fragment_shaders.push(GL.INVALID);
		}		
		
	}
	
	/**
	 * Callback called when the Graphics context is ready.
	 */
	private function Initialize():Void
	{
		//Console.Log("MaterialContext> Initialize.", 3);		
		
		//Set the default flags of the API
		GL.DepthFunc(GL.LEQUAL);
		GL.Enable(GL.DEPTH_TEST);
		GL.DepthMask(true);		
		GL.Disable(GL.BLEND);
		GL.BlendFunc(GL.ONE, GL.ZERO);
		GL.Enable(GL.CULL_FACE);
		GL.FrontFace(GL.CCW);
		GL.CullFace(GL.BACK);
		//Enables scissor test
		GL.Enable(GL.SCISSOR_TEST);
		
	}
	
	/**
	 * Updates the flags for the passed Material.
	 * @param	m
	 */
	private function UpdateFlags(m : Material):Void
	{
		/*
		zfunc           = DepthTest.LessEqual;
		ztest		    = true;
		zwrite			= true;
		blend		    = false;
		blendSrc        = BlendMode.One;
		blendDst        = BlendMode.Zero;
		invert		    = false;
		cull            = CullMode.Back;
		//*/
		
		if (m.zfunc != zfunc)   { zfunc  = m.zfunc; 		GL.DepthFunc(zfunc); }
		if (m.ztest != ztest)   { ztest  = m.ztest; 		if (ztest) GL.Enable(GL.DEPTH_TEST); else GL.Disable(GL.DEPTH_TEST); }
		if (m.zwrite != zwrite) { zwrite = m.zwrite;		GL.DepthMask(zwrite); }	
		if (m.blend != blend) 	{ blend = m.blend; 			if (blend) GL.Enable(GL.BLEND); else GL.Disable(GL.BLEND); }
		var blend_change : Bool = false;
		if (m.blendSrc != blendSrc) { blend_change = true; blendSrc = m.blendSrc; }
		if (m.blendDst != blendDst) { blend_change = true; blendDst = m.blendDst; }
		if (blend_change) GL.BlendFunc(blendSrc, blendDst);
		
		
		if (m.invert != invert) { invert = m.invert; 		GL.FrontFace(invert ? GL.CW : GL.CCW); }
		if (m.cull != cull) 
		{ 
			cull = m.cull; 
			if (cull == CullMode.None)
			{
				GL.Disable(GL.CULL_FACE); 
			}
			else
			{
				GL.Enable(GL.CULL_FACE);
				GL.CullFace(cull == CullMode.Front ? GL.FRONT : GL.BACK);
			}			
		}		
	}
	
	/**
	 * Initializes the material internal structures.
	 * @param	m
	 */
	private function InitializeMaterial(m:Material):Void
	{
		programs[m.__cid] = GL.CreateProgram();
		//Console.Log("Material> id["+programs[m.__cid]+"]",4);
	}
	
	/**
	 * Creates the API instance of a shader class.
	 * @param	s
	 */
	private function InitializeShader(s:Shader):Void
	{
		//UberShader will be a Shader container.
		if (Std.is(s, UberShader)) { return; }		
		var vs_err : String = "";
		var fs_err : String = "";		
		vs_err = CreateCompileShader(s, GL.VERTEX_SHADER,   vertex_shaders);
		fs_err = CreateCompileShader(s, GL.FRAGMENT_SHADER, fragment_shaders);		
		if (s.m_hasError)
		{
			Console.LogError("Shader> Compile Error @ [" + s.name + "]");
			//if (vs_err != "") 
			Console.Log("[vertex]\n" + vs_err);
			//if (fs_err != "") 
			Console.Log("[fragment]\n" + fs_err);
		}
		GL.Assert("Shader> Init");
	}
	
	/**
	 * Assigns a location for this uniform if any.
	 * @param	m
	 * @param	u
	 */
	private function CreateUniform(m:Material, u:MaterialUniform):Void
	{
		var p 	: ProgramId 		= programs[m.__cid];				
		var loc : UniformLocation 	= GL.GetUniformLocation(p, u.name);
		//Console.Log("Material> ["+m.name+"] @ ["+p+"] uniform["+u.name+"] loc["+loc+"]");
		uniforms[m.__cid][u.__cid] 	= loc;
		u.__d = true;
	}
	
	/**
	 * Removes the reference for the uniform location.
	 * @param	m
	 * @param	u
	 */
	private function DestroyUniform(m:Material, u:MaterialUniform)
	{
		var p 	: ProgramId 		= programs[m.__cid];		
		var loc : UniformLocation 	= GL.GetUniformLocation(p, u.name);
		uniforms[m.__cid][u.__cid] 	= GL.INVALID;
		EngineContext.material.uid.id = u.__cid;
	}
	
	/**
	 * Create and Compiles a Vertex or Fragment shader, then collects the error if any.
	 * @param	s
	 * @param	t
	 * @param	c
	 * @return
	 */
	private function CreateCompileShader(s:Shader,t:Int,c : Array<ShaderId>):String
	{
		var id : ShaderId = GL.CreateShader(t);
		var ss:String = t == GL.VERTEX_SHADER ? s.m_vss : s.m_fss;
		c[s.__cid] = id;		
		GL.ShaderSource(id, ss);		
		GL.CompileShader(id);			
		if (GL.GetShaderParameter(id, GL.COMPILE_STATUS)==0)
		{
			s.m_hasError = true;						
			return GL.GetShaderInfoLog(id);
		}
		return "";
	}
	
	/**
	 * Updates the shader source and compilation in the GPU.
	 * @param	p_shader
	 */
	private function UpdateShader(m:Material,s0 : Shader,s1 : Shader):Void
	{
		var p : ProgramId 			= programs[m.__cid];
		var vs_id : ShaderId;
		var fs_id : ShaderId;
		
		if (s0 != null)
		{
			vs_id = vertex_shaders[s0.__cid];
			fs_id = fragment_shaders[s0.__cid];
			GL.DetachShader(p, vs_id);
			GL.DetachShader(p, fs_id);
		}
		
		//if (s1 == null) s1 = error_shader;
		
		if (s1 != null)
		{
			vs_id = vertex_shaders[s1.__cid];
			fs_id = fragment_shaders[s1.__cid];
			GL.AttachShader(p, vs_id);
			GL.AttachShader(p, fs_id);
			
			var al : Array<String> = EngineContext.mesh.attribs;
			for (i in 0...al.length) GL.BindAttribLocation(p, i, al[i]);
			GL.LinkProgram(p);
				
			if (GL.GetProgramParameter(p, GL.LINK_STATUS)==0)
			{				
				Console.LogError("Material> ["+m.name+"] Link Error @ [" + s1.name + "]");				
			}
			
			var ul : Array<MaterialUniform> = m.m_uniforms;
			//Sets all uniforms to dirty
			for (i in 0...ul.length) CreateUniform(m, ul[i]);
			
			//Clear all attribs cache.
			for (i in 0...locations[m.__cid].length) locations[m.__cid][i] = -1;
		}
		
	}
	
	/**
	 * Updates the internal data of a material.
	 * @param	p_material
	 */
	private function UpdateMaterial(m : Material):Void
	{	
		
	}
	
	/**
	 * Returns the cached location of a given attrib for the the current program.
	 * @param	p_name
	 * @return
	 */
	private function GetAttribLocation(a : MeshAttrib):Int
	{
		if (current == null) return -1;		
		var p : ProgramId 	= programs[current.__cid];
		var loc : Int 		= locations[current.__cid][a.__cid];
		if (loc == -1)
		{
			loc = GL.GetAttribLocation(p, a.name);
			if (loc < 0) locations[current.__cid][a.__cid] = -2;
		}
		return loc;
	}
	
	/**
	 * Activates the passed material.
	 * @param	p_material
	 */
	private inline function Bind(m : Material):Void
	{
		if (m != current) 
		{ 
			Unbind(); 
			current = m; 			
			if (m != null)
			{
				var p : ProgramId = programs[m.__cid];
				UpdateFlags(m);								
				GL.UseProgram(p);
			}
		}
		
		if (current != null)
		{			
			var ul : Array<MaterialUniform> = current.m_uniforms;			
			for (i in 0...ul.length)
			{
				var u : MaterialUniform = ul[i];					
				if (u.__d)
				{
					u.__d = false;					
					var loc:UniformLocation = uniforms[current.__cid][u.__cid];
					if (loc == GL.INVALID) continue;					
					if (u.isFloat) ApplyFloatUniform(loc, u); else ApplyIntUniform(loc, u);
				}				
			}
		}
	}
	
	/**
	 * Applies the data from an uniform into the shader.
	 * @param	p_location
	 * @param	p_uniform
	 */
	private inline function ApplyFloatUniform(p_location:UniformLocation,p_uniform:MaterialUniform):Void
	{
		var b : FloatArray = cast p_uniform.data;		
		var off : Int = p_uniform.offset;
		switch(off)
		{
			case 1:  GL.Uniform1f(p_location, b.Get(0));				
			case 2:  GL.Uniform2f(p_location, b.Get(0), b.Get(1));
			case 3:  GL.Uniform3f(p_location, b.Get(0), b.Get(1), b.Get(2));
			case 4:  GL.Uniform4f(p_location, b.Get(0), b.Get(1), b.Get(2), b.Get(3));
			case 16: GL.UniformMatrix4fv(p_location, false, b);
			default: GL.Uniform1fv(p_location, b);
		}
	}
	
	/**
	 * Applies the data from an uniform into the shader.
	 * @param	p_location
	 * @param	p_uniform
	 */
	private inline function ApplyIntUniform(p_location:UniformLocation, p_uniform:MaterialUniform):Void
	{
		var b : Int32Array = cast p_uniform.data;
		var off : Int = p_uniform.offset;
		switch(off)
		{
			case 1: 
				if (p_uniform.texture != null) EngineContext.texture.Activate(p_uniform.texture);
				GL.Uniform1i(p_location, b.Get(0));
			case 2:  GL.Uniform2i(p_location, b.Get(0), b.Get(1));
			case 3:  GL.Uniform3i(p_location, b.Get(0), b.Get(1), b.Get(2));
			case 4:  GL.Uniform4i(p_location, b.Get(0), b.Get(1), b.Get(2), b.Get(3));
			default: GL.Uniform1iv(p_location, b);
		}
	}
	
	/**
	 * Disables the bound Material
	 */
	private inline function Unbind():Void
	{	
		//Disable something
	}
	
	/**
	 * Destroys the API structure of the material.
	 * @param	m
	 */
	private inline function DestroyMaterial(m : Material):Void
	{
		var p : ProgramId = programs[m.__cid];
		if (m.shader != null)
		{	
			GL.DetachShader(p, vertex_shaders[m.shader.__cid]);
			GL.DetachShader(p, fragment_shaders[m.shader.__cid]);			
		}
		GL.DeleteProgram(p);
		EngineContext.material.mid.id = m.__cid;
		for (i in 0...m.m_uniforms.length) uid.id = m.m_uniforms[i].__cid;		
	}
	
	/**
	 * Destroys the API structure of the shader.
	 * @param	s
	 */
	private inline function DestroyShader(s : Shader):Void
	{
		GL.DeleteShader(vertex_shaders[s.__cid]);
		GL.DeleteShader(fragment_shaders[s.__cid]);
		EngineContext.material.sid.id = s.__cid;
	}
	
	
}