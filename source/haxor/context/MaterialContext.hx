package haxor.context;
import haxor.component.Camera;
import haxor.component.light.Light;
import haxor.component.light.PointLight;
import haxor.component.MeshRenderer;
import haxor.component.Transform;
import haxor.core.Console;
import haxor.core.Debug;
import haxor.core.Time;
import haxor.core.Enums.BlendMode;
import haxor.core.Enums.CullMode;
import haxor.core.Enums.DepthTest;
import haxor.graphics.Gizmo;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.material.UberShader;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.mesh.Mesh.MeshAttrib;
import haxor.io.FloatArray;
import haxor.io.Int32Array;
import haxor.graphics.GL;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Random;
import haxor.math.Vector3;
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
	private var uniform_globals : Array<String> = ["ViewMatrix", "ProjectionMatrix", "WorldMatrix","WorldMatrixInverse","WorldMatrixIT", "Time", "RandomSeed", "RandomTexture", "ScreenTexture", "ScreenDepth", "Ambient", "CameraPosition", "ProjectionMatrixInverse", "ViewMatrixInverse","Lights"];
	/**
	 * List of global uniforms.
	 */
	private var globals : Array<Array<String>>;
	
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
	 * List of camera reference cache. To check if material needs to update camera uniforms.
	 */
	private var camera : Array<Camera>;
	
	/**
	 * List of transform reference cache. To check if material needs to update transform uniforms.
	 */
	private var transform : Array<Transform>;
	
	/**
	 * List of flags per program that indicates if the view matrix changed.
	 */
	private var viewmatrix : Array<Bool>;
	
	/**
	 * List of flags per program that indicates if the projection matrix changed.
	 */
	private var projmatrix : Array<Bool>;
	
	/**
	 * List of locations per program.
	 */
	private var locations : Array<Array<Int>>;
	
	/**
	 * Texture slot counter;
	 */
	private var slot : Int;
	
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
	 * Flag that indicates if point smoothing is activated.
	 */
	public var pointSmooth : Bool;
	
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
		pointSmooth		= true;
		
		var max_buffers : Int = 512;
		var max_programs : Int = 1024;
		
		locations			= [];
		uniforms			= [];
		programs			= [];
		vertex_shaders 	 	= [];
		fragment_shaders 	= [];
		globals				= [];
		camera				= [];
		transform			= [];
		slot 				= 0;
		viewmatrix			= [];
		projmatrix			= [];
		
		for (i in 0...max_programs)
		{
			var l : Array<Int> = [];
			var ul : Array<UniformLocation> = [];
			for (j in 0...max_buffers) l.push( -1);
			for (j in 0...200) ul.push(GL.INVALID);
			camera.push(null);
			transform.push(null);
			globals.push([]);
			locations.push(l);
			uniforms.push(ul);
			programs.push(GL.INVALID);
			vertex_shaders.push(GL.INVALID);
			fragment_shaders.push(GL.INVALID);
			
			viewmatrix.push(false);
			projmatrix.push(false);
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
	 * Updates the point smoothing flag.
	 * @param	p_flag
	 */
	private function SetPointSmooth(p_flag : Bool):Void
	{
		if (p_flag == pointSmooth) return;
		pointSmooth = p_flag;
		//if (pointSmooth) GL.Enable(GL.POINT_SMOOTH); else GL.Disable(GL.POINT_SMOOTH);
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
		#if gldebug
		GL.Assert("Shader> Init");
		#end
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
		u.exists = (loc != GL.INVALID) ;
	}
	
	/**
	 * Removes the reference for the uniform location.
	 * @param	m
	 * @param	u
	 */
	private function DestroyUniform(m:Material, u:MaterialUniform)
	{
		//var p 	: ProgramId 		= programs[m.__cid];		
		//var loc : UniformLocation 	= GL.GetUniformLocation(p, u.name);
		if(m!=null) uniforms[m.__cid][u.__cid] 	= GL.INVALID;
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
			
			//Resets the global list and filters the ones that doesn't exists in the shaders.		
			var gl : Array<String>  = uniform_globals.copy();
			var k  : Int 			= 0;
			var m4 : Matrix4		= Matrix4.temp.SetIdentity();
			while(k < gl.length)
			{
				var un : String = gl[k];
				if (GL.GetUniformLocation(p, un) == GL.INVALID) { gl.remove(un); continue; }
				//Initializes these uniforms so they don't need to be searched later.
				
				switch(un)
				{
					case "Lights":					m.SetFloat4Array(un, Light.m_buffer);
					case "Ambient":					m.SetColor(un, Color.temp.Set(1,1,1,1));					
					case "Time":					m.SetFloat(un, 0.0);					
					case "RandomSeed":				m.SetFloat(un, 0.0);
					//case "RandomTexture":			current.SetTexture(un, Asset.Get("haxor/texture/random"));
					//case "ScreenTexture":			if (current.grab) current.SetTexture("ScreenTexture", current.screen);						
					//case "ScreenDepth":			current.SetTexture("ScreenDepth",   p_camera.m_grab.depth);						
					case "WorldMatrix":				m.SetMatrix4(un,m4);
					case "WorldMatrixInverse":		m.SetMatrix4(un,m4);
					case "WorldMatrixIT":			m.SetMatrix4(un,m4);
					case "CameraPosition": 			m.SetVector3(un,Vector3.temp.Set(0,0,0));
					case "ViewMatrix":				m.SetMatrix4(un,m4);
					case "ViewMatrixInverse":		m.SetMatrix4(un,m4);					
					case "ProjectionMatrix":  		m.SetMatrix4(un,m4);					
					case "ProjectionMatrixInverse": m.SetMatrix4(un,m4);				
				}	
				k++;
			}		
			globals[m.__cid] = gl;			
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
	private function Bind(m : Material,t:Transform=null,c:Camera=null,msh:Mesh=null):Void
	{		
		var material_change : Bool = (m != current);		
		UseMaterial(m);		
		UpdateMaterialUniforms(t,c,msh,material_change);
	}
	
	/**
	 * Checks if the material differs and activates it.
	 * @param	m
	 */
	private function UseMaterial(m:Material):Void
	{
		if (m != current) 
		{ 
			Unbind(); 
			current = m; 			
			if (m != null)
			{
				slot = 0;				
				viewmatrix[m.__cid] = false;
				projmatrix[m.__cid] = false;				
				var p : ProgramId = programs[m.__cid];
				UpdateFlags(m);				
				GL.UseProgram(p);
			}			
		}		
	}
	
	/**
	 * Update and use the uniforms of the current material.
	 * @param	t
	 * @param	c
	 * @param	p_changed
	 */
	private function UpdateMaterialUniforms(t:Transform,c:Camera,msh:Mesh,p_changed:Bool):Void
	{
		
		//var mr : MeshRenderer = MeshRenderer.current;
		
		if (current != null)
		{	
			//if (p_changed)
			{
				viewmatrix[current.__cid] = (c == null) ? false : c.m_view_uniform_dirty;
				projmatrix[current.__cid] = (c == null) ? false : c.m_proj_uniform_dirty;								
			}
			
			//update transform uniform if transform changed or if material changed
			t = t == null ? Transform.root : t;
			var ut : Bool = (t != transform[current.__cid]);
			
			if(ut) if (transform[current.__cid] != null) transform[current.__cid].m_uniform_dirty = false;
			
			transform[current.__cid] = t;
			
			ut = ut || t.m_uniform_dirty;
			
			//update camera uniform if camera changed or if material changed
			var uc : Bool  = (c != camera[current.__cid]) && (c!=null);
			var ucv : Bool = viewmatrix[current.__cid] || uc; 
			var ucp : Bool = projmatrix[current.__cid] || uc;
			if(c!=null) camera[current.__cid] = c;
			
			SetLights(t, current, msh);
			
			UploadUniforms(ut,ucv,ucp,t,c);
			
			viewmatrix[current.__cid] = false;
			projmatrix[current.__cid] = false;
						
		}
	}
	
	/**
	 * 
	 */
	private function UploadUniforms(ut:Bool,ucv:Bool,ucp:Bool,t:Transform,c:Camera):Void
	{
		var ul : Array<MaterialUniform> = current.m_uniforms;			
		
		for (i in 0...ul.length)
		{
			var u : MaterialUniform = ul[i];				
			
			//After Shader upload and setup. The globals are initialized and don't need to be searched again.
			UploadGlobalUniform(u, ut, ucv, ucp, t, c);
			
			//Uploads all collected uniforms.
			UploadUniform(current, u);
		}
	}
	
	/**
	 * Uploads the uniform to the GPU.
	 * @param	u
	 */
	private function UploadUniform(m:Material,u:MaterialUniform):Void
	{
		var loc:UniformLocation;		
		loc = uniforms[m.__cid][u.__cid];
		if (loc == GL.INVALID)
		{			
			return;		
		}
		
		var is_texture : Bool = u.texture != null;
		var changed : Bool = u.__d;
		var texture_slot : Int = -1;
		
		if (is_texture) 
		{ 				
			if (u.texture.__slot < 0) { u.texture.__slot = texture_slot = slot++; }
			var b : Int32Array = cast u.data;
			if (u.texture.__slot != b.Get(0)) { changed = true; b.Set(0, u.texture.__slot); }
			
			EngineContext.texture.Bind(u.texture, u.texture.__slot);
			
		} 					
		if (!changed) return;		
		
		ApplyUniform(loc, u,texture_slot);
	}
	
	/**
	 * 
	 * @param	loc
	 * @param	u
	 */
	private function ApplyUniform(loc : UniformLocation,u:MaterialUniform,ts : Int):Void
	{
		var off : Int = u.offset;
		
		var is_array : Bool = u.data.length > off;
		
		if (u.isFloat)
		{
			var b : FloatArray = cast u.data;
			
			switch(off)
			{
				case 1:  if(is_array) GL.Uniform1fv(loc, b); else GL.Uniform1f(loc, b.Get(0));
				case 2:  if(is_array) GL.Uniform2fv(loc, b); else GL.Uniform2f(loc, b.Get(0), b.Get(1));
				case 3:  if(is_array) GL.Uniform3fv(loc, b); else GL.Uniform3f(loc, b.Get(0), b.Get(1), b.Get(2));
				case 4:  if(is_array) GL.Uniform4fv(loc, b); else GL.Uniform4f(loc, b.Get(0), b.Get(1), b.Get(2), b.Get(3));
				case 16: GL.UniformMatrix4fv(loc, false, b);
				
			}
		}
		else
		{						
			var b : Int32Array = cast u.data;			
			switch(off)
			{
				case 1:  if(is_array) GL.Uniform1iv(loc, b); else GL.Uniform1i(loc, b.Get(0));				
				case 2:  if(is_array) GL.Uniform2iv(loc, b); else GL.Uniform2i(loc, b.Get(0), b.Get(1));
				case 3:  if(is_array) GL.Uniform3iv(loc, b); else GL.Uniform3i(loc, b.Get(0), b.Get(1), b.Get(2));
				case 4:  if(is_array) GL.Uniform4iv(loc, b); else GL.Uniform4i(loc, b.Get(0), b.Get(1), b.Get(2), b.Get(3));
				
			}
		}				
		u.__d = false;
	}
	
	/**
	 * Updates the material global uniform if any change.
	 * @param	u
	 */
	private function UploadGlobalUniform(u:MaterialUniform,ut:Bool,ucv:Bool,ucp:Bool,t:Transform,c:Camera):Void
	{
		
		//var mr : MeshRenderer = MeshRenderer.current;
		
		switch(u.name)
		{
			case "Lights":									
				u.SetFloat4Array(Light.m_buffer);
			case "Ambient":					u.SetColor(Light.ambient);					
			case "Time":					u.SetFloat(Time.elapsed);					
			case "RandomSeed":				u.SetFloat(Random.value);
			//case "RandomTexture":			u.SetTexture(un, Asset.Get("haxor/texture/random"));
			//case "ScreenTexture":			if (current.grab) u.SetTexture("ScreenTexture", current.screen);						
			//case "ScreenDepth":			current.SetTexture("ScreenDepth",   c.m_grab.depth);						
			case "WorldMatrix":				if(ut) 	u.SetMatrix4(t.WorldMatrix);
			case "WorldMatrixInverse":		if(ut)	u.SetMatrix4(t.WorldMatrixInverse);
			case "WorldMatrixIT":			if (ut)	{ u.SetMatrix4(t.WorldMatrixInverse, true); }
			case "CameraPosition": 			if(ucv)	u.SetVector3(c.transform.position);
			case "ViewMatrix":				if(ucv) u.SetMatrix4(c.transform.WorldMatrixInverse);
			case "ViewMatrixInverse":		if(ucv) u.SetMatrix4(c.transform.WorldMatrix);					
			case "ProjectionMatrix":  		if(ucp)	u.SetMatrix4(c.ProjectionMatrix);					
			case "ProjectionMatrixInverse": if(ucp)	u.SetMatrix4(c.ProjectionMatrixInverse);										
		}	
	}
	
	/**
	 * 
	 * @param	t
	 * @param	m
	 * @param	msh
	 */
	private function SetLights(t : Transform,m : Material,msh:Mesh):Void
	{
		if (!m.lighting) 	return;
		
		var ll : Array<Light> = Light.m_list;
		if (ll.length <= 0) return;
		
		var b : AABB3 	= msh.m_bounds;		
		
		var c : Vector3 = Vector3.temp;
		var p  : Vector3 = Vector3.temp;
		
		AABB3.Center(msh.bounds, c);		
		t.WorldMatrix.Transform3x4(c);
		
		var k : Int = 0;
		//trace(" ");
		
		for (i in 0...ll.length)
		{
			//if (k >= Light.max) break;
			var l : Light = ll[i];
			if (!l.enabled) continue;
			if (Std.is(l, PointLight))
			{
				//trace(l.name);
				var pl : PointLight = cast l;								
				l.transform.WorldMatrix.Transform3x4(p.Set());
								
				if (Vector3.Distance(c, p) > (pl.radius * 0.5)) continue;				
				
				if (Debug.light)
				{
					var cl : Color = new Color(1, 1, 1, 0.1);
					Gizmo.Line(c, p,cl);
					Gizmo.Point(c, 3.0,cl);
					Gizmo.Point(p, 3.0,cl);
				}
				
				//trace(l.name+" "+l.intensity+" "+l.color.ToString()+" "+l.intensity);
				Light.SetLightData(k, 
				0.0, pl.intensity, pl.radius, pl.atten,  
				p.x, p.y, p.z,   
				pl.color.r, pl.color.g, pl.color.b, pl.color.a);
				k++;
			}
			/*
			else
			if (Std.is(l, DirectionalLight))
			{
				var p : Vector3 = l.transform.forward;
				Light.SetLightData(k, 
				1.0, l.intensity, 0.0,0.0,  
				p.x, p.y, p.z,   
				l.color.r, l.color.g, l.color.b, l.color.a);
				k++;
			}
			//*/
		}
		//*/		
		
		while(k < Light.max)
		{
			Light.SetLightData(k, -1.0, 0.0, 0.0,0.0,  0.0,0.0,0.0,   1.0, 0.0, 1.0, 1.0);
			k++;
		}
		//*/
		
	}
	
	/**
	 * Disables the bound Material
	 */
	private function Unbind():Void
	{	
		//Disable something
		if (current == null) return;
		var ul : Array<MaterialUniform> = current.m_uniforms;
		for (i in 0...ul.length) if (ul[i].texture != null) ul[i].texture.__slot = -1;
	}
	
	/**
	 * Destroys the API structure of the material.
	 * @param	m
	 */
	private function DestroyMaterial(m : Material):Void
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
	private function DestroyShader(s : Shader):Void
	{
		GL.DeleteShader(vertex_shaders[s.__cid]);
		GL.DeleteShader(fragment_shaders[s.__cid]);
		EngineContext.material.sid.id = s.__cid;
	}
	
	
}