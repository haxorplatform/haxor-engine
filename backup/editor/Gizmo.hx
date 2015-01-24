/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.editor;
import haxor.api.MaterialAPI;
import haxor.component.Camera;
import haxor.component.Component;
import haxor.component.Light;
import haxor.component.MeshRenderer;
import haxor.component.ParticleRenderer;
import haxor.component.PointLight;
import haxor.component.Transform;
import haxor.core.Asset;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.core.Resource;
import haxor.graphics.BlendMode;
import haxor.graphics.CullMode;
import haxor.graphics.Graphics;
import haxor.graphics.Material;
import haxor.graphics.Mesh;
import haxor.graphics.MeshTemplate.Mesh3;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.physics.BoxCollider;
import haxor.physics.Collider;
import haxor.physics.SphereCollider;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Gizmo
{
	static var GIZMO_POINT				: Float = 0.0;	
	static var GIZMO_LINE				: Float = 1.0;	
	static var GIZMO_TRANSFORM			: Float = 2.0;	
	static var GIZMO_BOX				: Float = 3.0;
	static var GIZMO_SPHERE				: Float = 4.0;
	
	static public var selection			: Array<Entity>;
	
	static public var colliders 		: Bool = false;
	
	static public var lights	 		: Bool = false;
	
	static public var sphereBounds		: Bool = false;
	
	static public var AABBBounds		: Bool = false;
	
	static public var meshes 	 		: Bool = false;
	
	static public var particles	 		: Bool = false;
	
	static public var transforms 		: Bool = false;

	
	
	static private var m_wireframes 	: Map<Mesh,Mesh3>;
	
	static private var m_handlers		: Array<IGizmoRenderer>;
	
	static private var m_color_collider  : Color = new Color(0.5, 0.9, 0.5);
	static private var m_color_trigger   : Color = new Color(0.9, 0.5, 0.5);
	
	static private var m_color_light	 : Color = new Color(1.0, 1.0, 0.5);
	static private var m_color_bounds	 : Color = new Color(0.95, 0.95, 0.5);	
	static private var m_color_mesh 	 : Color = new Color(0.6, 0.6, 0.95);	
	static private var m_color_particle	 : Color = new Color(0.95, 0.6, 0.95);	
	static private var m_color_x 		 : Color = new Color(0.9, 0.3, 0.3);
	static private var m_color_y 		 : Color = new Color(0.3, 0.9, 0.3);
	static private var m_color_z 		 : Color = new Color(0.3, 0.3, 0.9);
	
	static private var m_gizmo_point	   : PointGizmo;
	static private var m_gizmo_line 	   : LineGizmo;
	static private var m_gizmo_transform   : TransformGizmo;
	static private var m_gizmo_cube_wire   : WireCubeGizmo;
	static private var m_gizmo_sphere_wire : WireSphereGizmo;
	
	static public function Initialize():Void
	{
		m_handlers = [];
		
		m_wireframes 		= new Map<Mesh,Mesh3>();
		selection 			= [];
		
		m_gizmo_point		= new PointGizmo();
		m_gizmo_line		= new LineGizmo();
		m_gizmo_transform   = new TransformGizmo();
		m_gizmo_cube_wire   = new WireCubeGizmo();
		m_gizmo_sphere_wire = new WireSphereGizmo();
	}
	
	static public function Render():Void
	{
		//if (m_material.shader == null) { m_material.shader = Asset.Get("haxor/internal/Gizmo"); return; }
		
		var fp : Float = Camera.current.far;
		
		Camera.current.far = 200000;
		
		for (i in 0...m_handlers.length) m_handlers[i].OnGizmoRender();
		
		for (i in 0...selection.length) RenderEntity(selection[i], true);
		
		RenderColliders();
		
		if (transforms) RenderTransforms();
		
		if (lights) RenderLights();
		
		if (meshes) RenderMeshes();
		
		if (particles) RenderParticles();
		
		Camera.current.far = fp;
	}
	
	static private function RenderMeshes():Void
	{
		var l : Array<MeshRenderer> = MeshRenderer.list;
		for (i in 0...l.length)
		{
			var mr : MeshRenderer = l[i];
			if (mr.mesh == null) continue;
			
			//if (mr.visible) continue;
			m_color_mesh.a = mr.visible ? 1.0 : 0.0;
			
			var mb : AABB3 = mr.mesh.bounds;
			WireCube(mb.center, mb.size, m_color_mesh, mr.transform);
			//WireSphere(mb.center, mb.size.Scale(0.01).length, m_color_mesh, mr.transform);
		}
	}
	
	static private function RenderParticles():Void
	{
		var l : Array<MeshRenderer> = MeshRenderer.list;
		for (i in 0...l.length)
		{
			var mr : MeshRenderer = l[i];
			if (mr.mesh == null) continue;
			if (!Std.is(mr, ParticleRenderer)) continue;
			
			var pr : ParticleRenderer = cast mr;
			
			//if (mr.visible) continue;
			m_color_particle.a = mr.visible ? 1.0 : 0.0;
			
			var pe : ParticleEmitter = pr.emitter;
			
			if (Std.is(pe, SphereEmitter))
			{
				var e : SphereEmitter = cast pe;
				WireSphere(Vector3.zero, e.radius, m_color_particle, pr.transform);
			}
			
			if (Std.is(pe, BoxEmitter))
			{
				var e : BoxEmitter = cast pe;
				WireCube(Vector3.zero,new Vector3(e.width,e.height,e.depth), m_color_particle, pr.transform);
			}
			
			if (Std.is(pe, ConeEmitter))
			{
				//var e : BoxEmitter = cast pe;
				//WireSphere(Vector3.zero,new Vector3(e.width,e.height,e.depth), m_color_particle, pr.transform);
			}
			
			if (Std.is(pe, CylinderEmitter))
			{
				//var e : BoxEmitter = cast pe;
				//WireSphere(Vector3.zero,new Vector3(e.width,e.height,e.depth), m_color_particle, pr.transform);
			}
			
		}
	}
	
	static private function RenderColliders():Void
	{
		var l : Array<Collider> = Collider.list;
		for (i in 0...l.length)
		{
			if (colliders)    RenderCollider(l[i]);			
			if (sphereBounds) RenderSphereBound(l[i]);
			if (AABBBounds)   RenderAABBBound(l[i]);
		}
	}
	
	static private function RenderLights():Void
	{
		var l : Array<Light> = Light.m_list;
		for (i in 0...l.length)
		{
			if (Std.is(l[i], PointLight))
			{
				var pl : PointLight = cast l[i];
				var p : Vector3 = pl.transform.WorldMatrix.Transform3x4(Vector3.zero);				
				//if(i==0)trace(pl.transform.parent.name+" "+pl.transform.WorldMatrix.ToString()+" "+p.y);
				m_color_light.a = pl.enabled ? 1.0 : 0.2;				
				WireSphere(p, pl.radius, m_color_light);				
				
			}
		}
	}
		
	static private function RenderSphereBound(c :Collider):Void
	{
		var b : Vector4 = c.boundSphere;
		WireSphere(Vector3.temp.Set(b.x, b.y, b.z), b.w, m_color_bounds);
	}
	
	static private function RenderAABBBound(c :Collider):Void
	{
		var b : AABB3 = c.boundAABB;
		//trace(b.center.ToString() + " " + b.size.ToString()+" "+c.transform.m_worldMatrix.GetColumn(3).xyz.ToString());
		WireCube(b.center, b.size, m_color_bounds);
	}
	
	static private function RenderTransforms():Void
	{
		var l : Array<Transform> = Transform.m_list;
		for (i in 0...l.length) WireAxis(cast l[i]);
	}
	
	static private function RenderEntity(e : Entity,all : Bool=false):Void
	{		
		var cl : Array<Component> = e.GetComponents(Component);
		for (i in 0...cl.length) RenderComponent(cl[i]);
		
		if (all)
		{
			e.transform.Traverse(function(it : Transform):Bool
			{
				RenderEntity(it.entity, false);
				return true;
			});
		}
	}
	
	static private function RenderComponent(c : Component):Void
	{
		if (Std.is(c, Collider)) 		RenderCollider(cast c);   else		
		if (Std.is(c, Transform)) 		WireAxis(cast c);
	}
	
	static private function RenderCollider(c : Collider):Void
	{
		if (Std.is(c, BoxCollider))    RenderBoxCollider(cast c); else
		if (Std.is(c, SphereCollider)) RenderSphereCollider(cast c);
	}
	
	static private function RenderBoxCollider   (c : BoxCollider):Void	    
	{ 
		var cl : Color = c.trigger ? m_color_trigger : m_color_collider;		
		cl.a = c.enabled ? 1.0 : 0.2; 
		WireCube(c.center, c.size, cl, c.transform); 
	}
	
	static private function RenderSphereCollider(c : SphereCollider):Void	
	{ 
		var cl : Color = c.trigger ? m_color_trigger : m_color_collider;		
		cl.a = c.enabled ? 1.0 : 0.2; 
		cl.a = c.enabled ? 1.0 : 0.2; 
		WireSphere(c.center, c.radius, cl, c.transform); 
	}
	
	static public function WireAxis(p_transform : Transform,p_size : Vector3 = null):Void
	{
		var s : Float = 0.025;
		m_gizmo_transform.size.Set(p_size == null ? s : p_size.x, p_size == null ? s : p_size.y, p_size == null ? s : p_size.z);
		m_gizmo_transform.Render(p_transform,null);
	}
	
	static public function WireCube(p_center:Vector3, p_size:Vector3, p_color:Color=null, p_cs : Transform=null):Void
	{
		m_gizmo_cube_wire.center.Set(p_center.x, p_center.y, p_center.z);
		m_gizmo_cube_wire.size.Set(p_size.x, p_size.y, p_size.z);
		m_gizmo_cube_wire.Render(p_cs, p_color);
	}
	
	static public function WireSphere(p_center:Vector3, p_radius:Float, p_color:Color=null, p_cs : Transform=null):Void
	{
		m_gizmo_sphere_wire.center.Set(p_center.x, p_center.y, p_center.z);
		m_gizmo_sphere_wire.radius = p_radius;
		m_gizmo_sphere_wire.Render(p_cs, p_color);
	}
	
	static public function Point(p_position:Vector3, p_radius : Float = 1.0,p_color:Color=null, p_cs : Transform = null):Void
	{
		m_gizmo_point.center.Set(p_position.x, p_position.y, p_position.z);
		m_gizmo_point.radius = p_radius;
		m_gizmo_point.Render(p_cs, p_color);
	}
	
	static public function Line(p_from:Vector3,p_to:Vector3,p_color:Color=null, p_cs : Transform = null):Void
	{
		m_gizmo_line.p0.Set(p_from.x, p_from.y, p_from.z);
		m_gizmo_line.p1.Set(p_to.x, p_to.y, p_to.z);
		m_gizmo_line.Render(p_cs, p_color);
	}
	
}

class GizmoRenderer
{	
	public var material  : Material;	
	public var transform : Transform;	
	public var color 	 : Color;	
	public var type		 : Float;
	
	public function new()
	{
		type 				= -1;
		material 			= new Material();
		material.name 		= "$Material"+Type.getClassName(Type.getClass(this));
		material.blend 		= true;
		material.cull     	= CullMode.None;
		material.blendSrc 	= BlendMode.SrcAlpha;
		material.blendDst 	= BlendMode.OneMinusSrcAlpha;				
		material.ztest		= false;
		color 				= Color.white;
		transform 			= Transform.root;
	}
	
	public function Render(p_cs : Transform,p_color : Color):Void
	{
		if (material.shader == null) { material.shader = Asset.Get("haxor/internal/Gizmo"); return; }
		
		transform = p_cs    == null ? Transform.root : p_cs;
		color	  = p_color == null ? color.Set(1, 1, 1, 1) : color.Set(p_color.r, p_color.g, p_color.b, p_color.a);
		
		material.SetUniform("Type", type+0.00001);
		material.SetUniform("Tint", color);
		OnRender();
		MaterialAPI.m_current = null;
	}
	
	public function OnRender():Void { }
}

class PointGizmo extends GizmoRenderer
{
	private var m_mesh : Mesh3;	
	public var center 	: Vector3;
	public var radius 	: Float;
	
	public function new()
	{
		super();		
		type   = Gizmo.GIZMO_POINT;
		center   = Vector3.zero;
		radius   = 1.0;
		m_mesh = new Mesh3();
		m_mesh.name 		= "$PointMesh";
		m_mesh.primitive 	= MeshPrimitive.Points;
		var p : Array<Vector3> = [ Vector3.zero ];
		m_mesh.vertex = p;
		m_mesh.color = [Color.white];
	}
	
	override public function OnRender():Void 
	{		
		material.SetUniform("Center", center);
		material.SetUniform("Radius", radius+0.00000001);
		Graphics.Render(Camera.current, transform, m_mesh, material);
		
	}
	
}

class LineGizmo extends GizmoRenderer
{
	private var m_mesh : Mesh3;	
	public var p0	 	: Vector3;
	public var p1 		: Vector3;
	
	public function new()
	{
		super();		
		type   = Gizmo.GIZMO_LINE;
		p0	     = Vector3.zero;
		p1	     = Vector3.zero;
		m_mesh = new Mesh3();
		m_mesh.name 		= "$LineMesh";
		m_mesh.primitive 	= MeshPrimitive.Lines;
		var p : Array<Vector3> = [ Vector3.zero, Vector3.one ];
		m_mesh.vertex = p;
		m_mesh.color = [Color.white,Color.white];
	}
	
	override public function OnRender():Void 
	{		
		material.SetUniform("P0", p0);
		material.SetUniform("P1", p1);
		Graphics.Render(Camera.current, transform, m_mesh, material);
		
	}
	
}

class WireCubeGizmo extends GizmoRenderer
{
	private var m_mesh : Mesh3;	
	public var center 	: Vector3;
	public var size 	: Vector3;	
	
	public function new()
	{
		super();		
		type   = Gizmo.GIZMO_BOX;
		center = Vector3.zero;
		size   = Vector3.one;
		m_mesh = new Mesh3();
		m_mesh.name 		= "$WireCubeMesh";
		m_mesh.primitive 	= MeshPrimitive.Lines;
		var a : Float = -0.5;
		var b : Float =  0.5;
		var p : Array<Vector3> = 
		[
			new Vector3(a, a, a), new Vector3(a, a, b), new Vector3(b, a, b), new Vector3(b, a, a), 
			new Vector3(a, b, a), new Vector3(a, b, b), new Vector3(b, b, b), new Vector3(b, b, a)
		];		
		m_mesh.vertex =
		[			
			p[0], p[1], p[1], p[2], p[2], p[3], p[3], p[0], //Top			
			p[4], p[5], p[5], p[6], p[6], p[7], p[7], p[4], //Bottom	
			p[0], p[1], p[1], p[5], p[5], p[4], p[4], p[0], //Left
			p[3], p[2], p[2], p[6], p[6], p[7], p[7], p[3], //Right			
			p[0], p[3], p[3], p[7], p[7], p[4], p[4], p[0], //Front
			p[1], p[5], p[5], p[6], p[6], p[2], p[2], p[1]  //Back			
		];
		var cl : Array<Color> = [];
		for (i in 0...m_mesh.vertexCount) cl.push(Color.white);
		m_mesh.color = cl;
	}
	
	override public function OnRender():Void 
	{		
		material.SetUniform("Center", center);
		material.SetUniform("Size", size);
		Graphics.Render(Camera.current, transform, m_mesh, material);
		
	}
}

class WireSphereGizmo extends GizmoRenderer
{
	private var m_mesh : Mesh3;	
	public var center 	: Vector3;	
	public var radius 	: Float;	
	
	public function new()
	{
		super();
		type   = Gizmo.GIZMO_SPHERE;
		center = Vector3.zero;
		radius = 1.0;
		m_mesh			 = new Mesh3();	
		m_mesh.name 	 = "$WireSphereMesh";
		m_mesh.primitive = MeshPrimitive.Lines;
		
		var r : Float = radius;
		var v : Vector3;
		var steps : Int = 720;
		var p : Array<Vector3> = [];
		for (i in 0...steps)
		{
			var astp : Float = 1.0 / (steps - 1);
			var a : Float;
			a = 360 * i * astp;
			var sv0 : Float = Mathf.Sin(a * Mathf.Deg2Rad)*r*0.5;
			var cv0 : Float = Mathf.Cos(a * Mathf.Deg2Rad) * r * 0.5;
			a = 360 * (i+1) * astp;
			var sv1 : Float = Mathf.Sin(a * Mathf.Deg2Rad)*r*0.5;
			var cv1 : Float = Mathf.Cos(a * Mathf.Deg2Rad)*r* 0.5;
			var  v0 : Vector3;			
			var  v1 : Vector3;			
			v0 = new Vector3(cv0, 0.0, sv0); v1 = new Vector3(cv1, 0.0, sv1); p.push(v0); p.push(v1);
			v0 = new Vector3(0.0, cv0, sv0); v1 = new Vector3(0.0, cv1, sv1); p.push(v0); p.push(v1);
			v0 = new Vector3(cv0, sv0, 0.0); v1 = new Vector3(cv1, sv1, 0.0); p.push(v0); p.push(v1);			
		}		
		
		m_mesh.vertex = p;
		
		var cl : Array<Color> = [];
		for (i in 0...m_mesh.vertexCount) cl.push(Color.white);
		m_mesh.color = cl;		
	}
	
	override public function OnRender():Void 
	{
		material.SetUniform("Radius",radius+0.00000001);
		material.SetUniform("Center",center);		
		Graphics.Render(Camera.current, transform, m_mesh, material);
		
	}
}

class TransformGizmo extends GizmoRenderer
{
	private var m_mesh : Mesh3;	
	public var size 	: Vector3;	
	
	public function new()
	{
		super();
		type   = Gizmo.GIZMO_TRANSFORM;
		size   = Vector3.one;				
		m_mesh			 = new Mesh3();	
		m_mesh.name 	 = "$TransformMesh";
		m_mesh.primitive = MeshPrimitive.Lines;
		
		m_mesh.vertex = 
		[
		new Vector3(0, 0, 0), new Vector3(1, 0, 0),
		new Vector3(0, 0, 0), new Vector3(0, 1, 0),
		new Vector3(0, 0, 0), new Vector3(0, 0, 1)		
		];
				
		m_mesh.color = 
		[
		Gizmo.m_color_x, Gizmo.m_color_x,
		Gizmo.m_color_y, Gizmo.m_color_y,
		Gizmo.m_color_z, Gizmo.m_color_z
		];	
	}
	
	override public function OnRender():Void 
	{
		material.SetUniform("Size",size);		
		Graphics.Render(Camera.current, transform, m_mesh, material);		
	}
}


class MeshGizmo
{
	var p : Array<Vector3>;
	var m : Mesh3;	
	var cx : Float;
	var cy : Float;
	var cz : Float;	
	var fc : Color;
	
	public function new()
	{
		m 			= new Mesh3();	
		m.name 		= "$MeshGizmoMesh";
		m.primitive = MeshPrimitive.Lines;		
		cx = 0.0; cy = 0.0; cz = 0.0;		
		fc = new Color(1, 1, 1, 1);		
		Resize(1.0, 1.0, 1.0);
	}
	
	private function Resize(x : Float, y:Float, z:Float):Void
	{
		if (Mathf.Abs(x - cx) < 0.001)
		if (Mathf.Abs(y - cy) < 0.001)
		if (Mathf.Abs(z - cz) < 0.001) return;		
		cx = x; cy = y; cz = z;		
		var a : Float = -0.5;
		var b : Float =  0.5;
		p = 
		[
			new Vector3(a*x, a*y, a*z), new Vector3(a*x, a*y, b*z), new Vector3(b*x, a*y, b*z), new Vector3(b*x, a*y, a*z), 
			new Vector3(a*x, b*y, a*z), new Vector3(a*x, b*y, b*z), new Vector3(b*x, b*y, b*z), new Vector3(b*x, b*y, a*z)
		];		
		m.vertex =
		[			
			p[0], p[1], p[1], p[2], p[2], p[3], p[3], p[0], //Top			
			p[4], p[5], p[5], p[6], p[6], p[7], p[7], p[4], //Bottom	
			p[0], p[1], p[1], p[5], p[5], p[4], p[4], p[0], //Left
			p[3], p[2], p[2], p[6], p[6], p[7], p[7], p[3], //Right			
			p[0], p[3], p[3], p[7], p[7], p[4], p[4], p[0], //Front
			p[1], p[5], p[5], p[6], p[6], p[2], p[2], p[1], //Back			
		];
		//for (i in 0...p.length) p[i].Normalize();
		
		var c : Color = Gizmo.m_color_mesh;			
		var cl : Array<Color> = [];
		for (i in 0...m.vertexCount) cl.push(c);
		m.color = cl;
		
		var uv : Vector3 = Vector3.up.Invert();
		var dv : Vector3 = uv.inverse;
		var fv : Vector3 = Vector3.forward.Invert();
		var bv : Vector3 = fv.inverse;
		var rv : Vector3 = Vector3.right;		
		var lv : Vector3 = rv.inverse;
		
		m.normal =
		[
			uv, uv, uv, uv, uv, uv, uv, uv, //Top			
			dv, dv, dv, dv, dv, dv, dv, dv, //Bottom	
			lv, lv, lv, lv, lv, lv, lv, lv, //Left
			rv, rv, rv, rv, rv, rv, rv, rv, //Right			
			fv, fv, fv, fv, fv, fv, fv, fv, //Front
			bv, bv, bv, bv, bv, bv, bv, bv, //Back
		];
		//*/
	}
	
	public function Render(c : MeshRenderer):Void
	{
		var b : AABB3 = c.mesh.m_bounds;
		var gm : Material = null;// Gizmo.m_material;
		gm.SetUniform("Size", b.size);
		gm.SetUniform("Center", b.center);		
		gm.SetUniform("Tint", fc);		
		//trace(c.name + " " + b.size.ToString() + " " + b.center.ToString());
		Graphics.Render(Camera.current, c.transform, m, gm);
		MaterialAPI.m_current = null;
	}
}