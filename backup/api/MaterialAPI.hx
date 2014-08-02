/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.api;
import js.html.Float32Array;
import js.html.Int32Array;
import js.html.webgl.GL;
import js.html.webgl.Program;
import js.html.webgl.RenderingContext;
import js.html.webgl.UniformLocation;
import haxor.component.Camera;
import haxor.component.DirectionalLight;
import haxor.component.Light;
import haxor.component.PointLight;
import haxor.component.Transform;
import haxor.core.Asset;
import haxor.core.Console;
import haxor.core.Time;
import haxor.graphics.BlendMode;
import haxor.graphics.CullMode;
import haxor.graphics.DepthTest;
import haxor.graphics.filters.RenderFX;
import haxor.graphics.Graphics;
import haxor.graphics.Material;
import haxor.graphics.Mesh;
import haxor.graphics.Shader;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Matrix4;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.texture.RenderTexture;
import haxor.texture.Texture;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class MaterialAPI
{
	static private var c 				: RenderingContext;
	
	static private var m_zTest 			: Int;
	
	static private var m_zTestEnabled 	: Bool;
	
	static private var m_zWriteEnabled 	: Bool;
	
	static private var m_srcBlend 		: Int;
	
	static private var m_dstBlend 		: Int;
	
	static private var m_blendEnabled 	: Bool;
	
	static private var m_cull			: Int;
	
	static private var m_invertFace		: Bool;
	
	static private var m_globals		: Array<String>;
	
	static private var m_current		: Material;
	
	static private var m_camera			: Camera;
	
	static private var m_transform		: Transform;
	
	static public function Initialize(p_context : RenderingContext):Void
	{
		c = p_context;
		m_globals = ["ViewMatrix", "ProjectionMatrix", "WorldMatrix", "Time","RandomSeed","RandomTexture","ScreenTexture","ScreenDepth", "Ambient", "WSCameraPosition", "ProjectionMatrixInverse", "ViewMatrixInverse"];
		
		Reset();
	}
	
	static public function Reset():Void
	{
		m_current		= null;
		m_camera		= null;
		
		m_zTest 		= DepthTest.LessEqual;
		m_zTestEnabled  = true;
		m_srcBlend		= BlendMode.One;
		m_dstBlend		= BlendMode.Zero;
		m_blendEnabled  = false;
		m_zWriteEnabled = true;
		m_cull			= CullMode.Back;
		m_invertFace	= false;	
		
		c.enable(GL.DEPTH_TEST);
		c.depthMask(true);
		c.depthFunc(m_zTest);
		c.disable(GL.BLEND);
		c.blendFunc(m_srcBlend, m_dstBlend);
		c.enable(GL.CULL_FACE);				
		c.cullFace(GL.BACK); 
		c.frontFace(GL.CCW); //WHY?
	}
	
	static public function Bind(p_material : Material):Void
	{		
		//if (m_current == p_material) return;
		SetFlags(p_material);
	}
	
	static private function GetUniformLocation(p : Program,u:String, m : Material) : UniformLocation
	{
		var sid : String = m.shader.id + "";
		var k : String = u + sid;		
		if (m.m_locations.exists(k)) return m.m_locations.get(k);		
		var loc : UniformLocation = c.getUniformLocation(p, u);
		m.m_locations.set(k, loc);
		return loc;
	}
	/*
	static private function ValidateUniformFlag(u:String, m : Material) : Bool
	{
		var sid : String = m.shader.id + "";
		var k : String = u + sid;		
		var f : Bool = true;
		if (m.m_changed.exists(k))
		{
			f = m.m_changed.get(k);
			m.m_changed.set(k, false);
		}		
		return f;
	}
	//*/
	
	static public function SetLights(p_transform : Transform,p_material : Material,p_mesh:Mesh):Void
	{
		var m : Material = p_material;
		var ll : Array<Light> = Light.m_list;
		if (ll.length <= 0) return;
		if (!m.lighting) return;
		var b : AABB3 	= p_mesh.bounds;		
		var c : Vector3 = p_transform.WorldMatrix.Transform3x4(Vector3.zero);
		var k : Int = 0;
		//trace(" ");
		var b : Float32Array = Light.m_buffer;
		for (i in 0...ll.length)
		{
			//if (k >= Light.max) break;
			var l : Light = ll[i];
			if (!l.enabled) continue;
			if (Std.is(l, PointLight))
			{
				//trace(l.name);
				var pl : PointLight = cast l;				
				var p : Vector3 = l.transform.WorldMatrix.Transform3x4(Vector3.zero);
				if (Vector3.Distance(c, p) > (pl.radius * 0.9)) continue;				
				//trace(l.name+" "+l.intensity+" "+l.color.ToString()+" "+l.intensity);
				Light.SetLightData(k, 
				0.0, pl.intensity, pl.radius, pl.atten,  
				p.x, p.y, p.z,   
				pl.color.r, pl.color.g, pl.color.b, pl.color.a);
				k++;
			}
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
		}
		//*/		
		//trace(k);
		while(k < Light.max)
		{
			Light.SetLightData(k, -1.0, 0, 0, 0,   0, 0, 0,   0, 0, 0, 0);
			k++;
		}
		//*/
		
		m.SetUniform("Lights",b);
		
		
	}
	
	static public function SetUniforms(p_camera : Camera, p_transform : Transform, p_material : Material):Void
	{		
		var camera_change 	 : Bool = 
		//(m_camera != p_camera) && (p_camera != null);
		(p_camera != null);
		
		var transform_change : Bool = 
		(m_transform != p_transform) && (p_transform != null);
		//(p_transform != null);
		
		m_transform = p_transform;
		m_camera 	= p_camera;
		var loc : UniformLocation = null;
		var m : Material   = p_material;
		var prog : Program = m.shader.gid;
		var k:String;
		var hc : Bool;
		var hl : Bool;
		var has_flush : Bool = false;
		for (i in 0...m_globals.length)
		{	
			k = m_globals[i];
			loc = GetUniformLocation(prog, k, m);						
			if (loc == null) continue;			
			//if (!ValidateUniformFlag(k, m)) continue;
			
			//Shader uniform forces the use of matrixes.
			//Can postpone some inverses calculations with a 'dirt flag'.
			switch(k)
			{
				case "Ambient":					c.uniform4f(loc,Light.ambient.r,Light.ambient.g,Light.ambient.b,Light.ambient.a);
				case "Time":					c.uniform1f(loc, Time.elapsed);
				case "RandomSeed":				c.uniform1f(loc, Math.random());				
				case "RandomTexture":			m.SetUniform("RandomTexture", Asset.Get("haxor/texture/random"));
				case "ScreenTexture":				
					if (m.grab)
					{
						m.SetUniform("ScreenTexture", m.screen);
					}
				case "ScreenDepth":															
					m.SetUniform("ScreenDepth",   p_camera.m_grab.depth);
					
				case "WorldMatrix": 			if(transform_change) c.uniformMatrix4fv(loc, false, p_transform.m_worldMatrix.ToBuffer());
				case "WorldMatrixInverse":		if(transform_change)c.uniformMatrix4fv(loc, false, p_transform.m_worldMatrixInverse.ToBuffer());
				case "ViewMatrix": 				if (camera_change) c.uniformMatrix4fv(loc, false, (p_camera.WorldToCamera.ToBuffer()));
				case "ViewMatrixInverse":											
					if(camera_change) c.uniformMatrix4fv(loc, false,(p_camera.CameraToWorld.ToBuffer()));
				
				case "ProjectionMatrix":  		if(camera_change)c.uniformMatrix4fv(loc, false, (p_camera.ProjectionMatrix.ToBuffer()));				
				case "ProjectionMatrixInverse": if(camera_change)c.uniformMatrix4fv(loc, false, (p_camera.ProjectionMatrixInverse.ToBuffer()));
				case "WSCameraPosition": 		
				{	
					if(camera_change)c.uniform3f(loc, p_camera.CameraToWorld.m03, p_camera.CameraToWorld.m13, p_camera.CameraToWorld.m23); 
				}
				
			}
		}
		
		
		
		var u : Iterator<String> = m.uniforms;
		var tex_count :Int = 0;
		
		while (u.hasNext())
		{
			k = u.next();
			
			//if(!Std.is(m,RenderFX)) if(k != "Skinning") if (m == m_current) continue;
			
		
			
			var d:Dynamic = m.GetUniform(k);			
			loc = GetUniformLocation(prog, k, m);
			
			if (loc == null)
			{	
				
				continue;
			}
			var has_change : Bool = true;// ValidateUniformFlag(k, m);
			if (Std.is(d, Texture))
			{				
				TextureAPI.Activate(cast d, tex_count);
				if (has_change) 
				c.uniform1i(loc, tex_count);
				tex_count++;
				continue;
			}				
			//if (k == "Tint") trace(m.name + " " + d.r+" "+d.g+" "+d.b+" "+d.a);
			//if (!has_change) continue;
			
			var tn : String = Type.typeof(d).getName();
			
			//if (k.indexOf("Lights") >= 0) trace(k + " " + d+" "+tn);
			
			if (tn == "TFloat") c.uniform1f(loc, cast d);
			else
			if (Std.is(d, Float32Array)) { var v : Float32Array = cast d; c.uniform4fv(loc, v); }
			else
			if (Std.is(d, Vector2)) { var v:Vector2 = cast d; c.uniform2f(loc, v.x, v.y); }
			else			
			if (Std.is(d, Vector3)) { var v:Vector3 = cast d; c.uniform3f(loc, v.x, v.y, v.z); }
			else
			if (Std.is(d, Vector4)) { var v:Vector4 = cast d; c.uniform4f(loc, v.x, v.y, v.z, v.w); }
			else
			if (Std.is(d, Color)) { var v:Color = cast d; c.uniform4f(loc, v.r, v.g, v.b, v.a); }
			else				
			if (Std.is(d, Matrix4)) { var v:Matrix4 = cast d; c.uniformMatrix4fv(loc, false, (v.ToBuffer())); }
			else
			if (tn == "TInt")
			{	
				c.uniform1i(loc, d);
			}				
			
		}		
		
		
	}
	
	static private function SetFlags(p_material : Material):Void
	{
		
		if (p_material.ztest)
		{
			if (!m_zTestEnabled) { c.enable(GL.DEPTH_TEST); m_zTestEnabled = true; }
		} 
		else
		{
			if (m_zTestEnabled) { c.disable(GL.DEPTH_TEST); m_zTestEnabled = false; }
		}
		if (m_zWriteEnabled != p_material.zwrite) { c.depthMask(p_material.zwrite); m_zWriteEnabled = p_material.zwrite; }
		if (m_zTest != p_material.zfunc) { c.depthFunc(p_material.zfunc); m_zTest = p_material.zfunc; }
		
		if (p_material.blend)
		{
			if (!m_blendEnabled) { c.enable(GL.BLEND); m_blendEnabled = true; }
		}
		else
		{
			if (m_blendEnabled) { c.disable(GL.BLEND); m_blendEnabled = false; }
		}
		
		if (m_srcBlend != p_material.blendSrc)
		{
			c.blendFunc(p_material.blendSrc, p_material.blendDst); 
			m_srcBlend = p_material.blendSrc;
		}
		else
		if (m_dstBlend != p_material.blendDst)
		{
			c.blendFunc(p_material.blendSrc, p_material.blendDst); 
			m_dstBlend = p_material.blendDst;
		}
		
		if (p_material.cull != m_cull)
		{	
			
			if (p_material.cull == CullMode.None) c.disable(GL.CULL_FACE);
			else
			{
				c.enable(GL.CULL_FACE);				
				c.cullFace(p_material.cull == CullMode.Front ? GL.FRONT : GL.BACK);
			}			
			m_cull = p_material.cull;
		}
		
		
		if (m_invertFace != p_material.invert)
		{
			c.frontFace(p_material.invert ? GL.CW : GL.CCW); //WHY?
			m_invertFace = p_material.invert;
		}
				
	}
	
	
	
	
}