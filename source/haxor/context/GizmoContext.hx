package haxor.context;
import haxor.component.Camera;
import haxor.component.MeshRenderer;
import haxor.component.physics.Collider;
import haxor.component.Renderer;
import haxor.component.Transform;
import haxor.context.GizmoContext.Gizmo;
import haxor.context.GizmoContext.PointGizmo;
import haxor.core.Console;
import haxor.core.Debug;
import haxor.core.Enums.BlendMode;
import haxor.core.Enums.CullMode;
import haxor.core.Enums.MeshPrimitive;
import haxor.core.Enums.PixelFormat;
import haxor.graphics.GL;
import haxor.graphics.GraphicContext;
import haxor.graphics.Graphics;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.mesh.MeshLayout.Mesh3;
import haxor.graphics.Screen;
import haxor.graphics.texture.ComputeTexture;
import haxor.graphics.texture.Texture;
import haxor.io.FloatArray;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.platform.Types.Float32;

/**
 * Class that handles gizmo structures and operations.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class GizmoContext
{
	/**
	 * Mesh of a grid.
	 */
	private var grid : Mesh;
	
	/**
	 * Mesh of a axis.
	 */
	private var axis : Mesh;
	
	/**
	 * Mesh of a screen texture.
	 */
	private var texture : Mesh;
	
	/**
	 * Material to be used by gizmos.
	 */
	private var gizmo_material : Material;
	
	/**
	 * Material used to draw textures in screen.
	 */
	private var texture_material : Material;
	
	private var wire_sphere_renderer : WireSphereGizmo;	
	private var wire_cube_renderer 	 : WireCubeGizmo;
	private var axis_renderer 		 : AxisGizmo;
	private var line_renderer 		 : LineGizmo;
	private var point_renderer 		 : PointGizmo;
	private var canvas_renderer		 : CanvasGizmo;	
	
	private function new() { }
	
	
	private function Initialize():Void
	{
		var mat : Material;
		mat = gizmo_material	= new Material("$GizmoMaterial");
		mat.shader 	= new Shader(ShaderContext.grid_source);
		mat.blend = true;
		mat.SetBlending(BlendMode.SrcAlpha, BlendMode.OneMinusSrcAlpha);		
		mat.SetFloat("Area", 1000.0);
		mat.SetColor("Tint", new Color(1.0, 1.0, 1.0, 0.4));
		mat.ztest = false;
		
		mat = texture_material	= new Material("$TextureMaterial");
		mat.shader 	= new Shader(ShaderContext.texture_source);
		mat.blend = true;
		mat.SetBlending(BlendMode.SrcAlpha, BlendMode.OneMinusSrcAlpha);		
		mat.SetFloat2("Screen", Screen.width, Screen.height);
		mat.SetFloat4("Rect", 0, 0, 100, 100);
		mat.SetColor("Tint", new Color(1.0, 1.0, 1.0, 1.0));
		mat.cull = CullMode.None;
		mat.ztest = false;
				
		CreateAxis();
		CreateGrid(100.0);
		CreateTextureQuad();
		
		
		wire_sphere_renderer  = new WireSphereGizmo();
		wire_cube_renderer    = new WireCubeGizmo();
		axis_renderer		  = new AxisGizmo();
		canvas_renderer       = new CanvasGizmo();
		line_renderer		  = new LineGizmo();
		point_renderer		  = new PointGizmo();		
	}
	
	/**
	 * Creates the quad which will render textures on the screen.
	 */
	private function CreateTextureQuad():Void
	{
		var m : Mesh = texture = new Mesh("$TextureQuad");
		var vl : FloatArray;		
		vl = FloatArray.Alloc([
		0, 0, 0, 
		0,-1, 0,
		1,-1, 0,		
		0, 0, 0, 
		1,-1, 0,
		1, 0, 0		
		]);		
		m.Set("vertex", vl, 3);		
		m.bounds = m.GenerateAttribBounds("vertex", AABB3.temp);
	}
	
	/**
	 * Creates lines to show the world space axis.
	 */
	private function CreateAxis():Void
	{
		var m : Mesh = axis = new Mesh("$GridAxis");
		m.primitive = MeshPrimitive.Lines;
		var vl : FloatArray = new FloatArray(18);
		var cl : FloatArray = new FloatArray(24);
		var k : Int;
		
		//Positions
		k = 0;		
		//X
		vl.Set(k++, 0.0); vl.Set(k++, 0.0); vl.Set(k++, 0.0);
		vl.Set(k++, 1.0); vl.Set(k++, 0.0); vl.Set(k++, 0.0);
		
		//Y
		vl.Set(k++, 0.0); vl.Set(k++, 0.0); vl.Set(k++, 0.0);
		vl.Set(k++, 0.0); vl.Set(k++, 1.0); vl.Set(k++, 0.0);
		
		//Z
		vl.Set(k++, 0.0); vl.Set(k++, 0.0); vl.Set(k++, 0.0);
		vl.Set(k++, 0.0); vl.Set(k++, 0.0); vl.Set(k++, 1.0);
		
		//Color
		k = 0;
		//X
		cl.Set(k++, 1.0); cl.Set(k++, 0.0); cl.Set(k++, 0.0); cl.Set(k++, 1.0);
		cl.Set(k++, 1.0); cl.Set(k++, 0.3); cl.Set(k++, 0.3); cl.Set(k++, 1.0);
		
		//Y
		cl.Set(k++, 0.0); cl.Set(k++, 1.0); cl.Set(k++, 0.0); cl.Set(k++, 1.0);
		cl.Set(k++, 0.3); cl.Set(k++, 1.0); cl.Set(k++, 0.3); cl.Set(k++, 1.0);
		
		//Z
		cl.Set(k++, 0.0); cl.Set(k++, 0.0); cl.Set(k++, 1.0); cl.Set(k++, 1.0);
		cl.Set(k++, 0.3); cl.Set(k++, 0.3); cl.Set(k++, 1.0); cl.Set(k++, 1.0);
		
		
		m.Set("vertex", vl, 3);
		m.Set("color",  cl, 4);
		
		m.bounds = m.GenerateAttribBounds("vertex", AABB3.temp);		
	}
	
	/**
	 * Creates a Gizmo for grid.
	 * @param	p_step
	 */
	private function CreateGrid(p_step:Float32):Void
	{	
		grid = new Mesh("$GridMesh");
		grid.primitive = MeshPrimitive.Lines;
		var len : Int = cast(p_step+1);
		p_step = 1.0 / p_step;
		var ox : Float32 = 0.5;
		var oz : Float32 = 0.5;
		var px : Float32 = 0.0;
		var pz : Float32 = 0.0;		
		var vl : FloatArray = new FloatArray(12 * len);		
		var k : Int;		
		//x
		k = 0;
		for (i in 0...len)
		{	
			vl.Set(k++, px-ox); vl.Set(k++, 0.0); vl.Set(k++, oz);
			vl.Set(k++, px-ox); vl.Set(k++, 0.0); vl.Set(k++,-oz);			
			px += p_step;
		}	
		
		//z		
		for (i in 0...len)
		{	
			vl.Set(k++, ox); vl.Set(k++, 0.0); vl.Set(k++, pz-oz);
			vl.Set(k++,-ox); vl.Set(k++, 0.0); vl.Set(k++, pz-oz);
			pz += p_step;
		}		
		grid.Set("vertex", vl, 3);		
		grid.bounds = grid.GenerateAttribBounds("vertex", AABB3.temp);		
	}
	
	/**
	 * Renders the Grid gizmo.
	 * @param	p_area
	 * @param	p_color
	 */
	private function DrawGrid(p_area:Float32,p_color:Color=null):Void
	{
		gizmo_material.SetFloat("Area", p_area);
		if (p_color != null) gizmo_material.SetColor("Tint", p_color);					
		Graphics.Render(grid, gizmo_material,null,Camera.main);
	}
		
	/**
	 * 
	 * @param	p_color
	 * @param	p_radius
	 * @param	p_transform
	 */
	private function DrawWireSphere(p_position:Vector3,p_radius : Float,p_color : Color, p_transform : Matrix4):Void
	{
		wire_sphere_renderer.Push(p_color, Vector4.temp.Set(p_radius, p_radius, p_radius, 1.0), Vector4.temp.Set3(p_position), p_transform);
	}
	
	/**
	 * 
	 * @param	p_position
	 * @param	p_size
	 * @param	p_color
	 * @param	p_transform
	 */
	private function DrawWireCube(p_position:Vector3,p_size : Vector3,p_color : Color, p_transform : Matrix4):Void
	{
		wire_cube_renderer.Push(p_color, Vector4.temp.Set3(p_size), Vector4.temp.Set3(p_position), p_transform);
	}
	
	/**
	 * 
	 * @param	p_position
	 * @param	p_size
	 * @param	p_color
	 * @param	p_transform
	 */
	private function DrawAxis(p_position:Vector3,p_size : Vector3,p_color : Color, p_transform : Matrix4):Void
	{
		axis_renderer.Push(p_color, Vector4.temp.Set3(p_size), Vector4.temp.Set3(p_position), p_transform);
	}
	
	/**
	 * 
	 * @param	p_from
	 * @param	p_to
	 * @param	p_color
	 * @param	p_transform
	 */
	private function DrawLine(p_from:Vector3,p_to : Vector3,p_color : Color, p_transform : Matrix4):Void
	{		
		line_renderer.Push(p_color, Vector4.temp.Set3(p_from), Vector4.temp.Set3(p_to), p_transform);
	}
	
	/**
	 * 
	 * @param	p_position
	 * @param	p_radius
	 * @param	p_color
	 * @param	p_smooth
	 * @param	p_transform
	 */
	private function DrawPoint(p_position:Vector3,p_size : Float,p_color : Color,p_smooth:Bool, p_transform : Matrix4):Void
	{
		point_renderer.Push(p_color, Vector4.temp.Set(p_size, p_smooth ? 1.0 : 0.0, 0.0, 0.0), Vector4.temp.Set3(p_position), p_transform);
	}
	
	/**
	 * Render all gizmos if any have queued rendering.
	 */
	private function Render():Void
	{
		var gr : Gizmo;		
		gr = wire_sphere_renderer; gr.Render(); gr.Clear();
		gr = wire_cube_renderer; gr.Render(); gr.Clear();
		gr = axis_renderer; gr.Render(); gr.Clear();
		gr = canvas_renderer; gr.Render(); gr.Clear();
		gr = line_renderer; gr.Render(); gr.Clear();
		gr = point_renderer; gr.Render(); gr.Clear();
	}
}

/**
 * 
 */
@:noCompletion
class Gizmo
{
	static public var POINT       : Int = 0;
	static public var LINE        : Int = 1;
	static public var AXIS		  : Int = 2;
	static public var WIRE_CUBE   : Int = 3;
	static public var WIRE_SPHERE : Int = 4;
	static public var CANVAS	  : Int = 10;
	static var DATA_OFFSET 		  : Int = 24;
	static var MAX_GIZMOS		  : Int = 500;
	static var IDM				  : Matrix4 = Matrix4.identity;
	static var SHADER			  : Shader;
	
	/**
	 * Texture data for information such as color, position, transform and others.
	 */
	public var data : ComputeTexture;
	
	/**
	 * Mesh of the gizmos.
	 */
	public var mesh : Mesh;
	
	/**
	 * Material used for rendering.
	 */
	public var material : Material;
	
	/**
	 * Type of the gizmo.
	 */
	public var type : Int;
	
	/**
	 * Currently rendered elements.
	 */
	private var m_render_count : Int;
	
	/**
	 * Number of gizmos pre-allocated.
	 */
	private var m_gizmo_count : Int;
	
	/**
	 * Creates the gizmo renderer.
	 */
	public function new(p_type : Int,p_count : Int)
	{		
		type 			= p_type;
		m_render_count  = 0;				
		m_gizmo_count 	= p_count;		
		
		if (SHADER == null) SHADER = new Shader(ShaderContext.gizmo_source);
		
		material = new Material("Gizmo" + p_type+"Material");
		material.shader = SHADER;
		material.blend = true;
		material.SetBlending(BlendMode.SrcAlpha, BlendMode.OneMinusSrcAlpha);		
		material.SetInt("Type", p_type);				
		material.ztest = false;		
		var tw : Int = 0;
		var th : Int = 0;
		
		if (p_count >= 1)
		{
			var data_tex_size	 : Int = cast Mathf.Max(2,cast Mathf.NextPOT(cast Mathf.Ceil(Mathf.Sqrt((p_count * (DATA_OFFSET/4))))));
			data = new ComputeTexture(data_tex_size, data_tex_size, PixelFormat.Float4);
			var f32 : FloatArray = cast data.data.buffer;
			for (i in 0...f32.length) f32.Set(i, ((i % 4) == 3 ? 1.0 : 0.0));
			material.SetTexture("Data", data);
			material.SetInt("DataSize", data.width);
			tw = data.width;
			th = data.height;
		}		
		Console.Log("Gizmos> Created Renderer [" + p_type+"] data["+tw+"x"+th+"]",6);		
		OnBuild();
	}
	
	/**
	 * Method that will be overriden in order to create extra data for a specific gizmo.
	 */
	public function OnBuild():Void { }
	
	/**
	 * Adds one gizmo to the rendering queue.
	 * @param	p_color
	 * @param	p_a
	 * @param	p_b
	 * @param	p_transform
	 */
	public function Push(p_color : Color, p_a : Vector4, p_b : Vector4, p_transform : Matrix4):Void
	{		
		if (m_render_count >= m_gizmo_count)
		{			
			return;
		}
		var id  : Int 		 = m_render_count;
		var f32 : FloatArray = cast data.data.buffer;
		var p   : Int 		 = id * DATA_OFFSET;		
		var c   : Color      = p_color == null ? Color.temp.Set(1, 1, 1, 1) : p_color;
		f32.Set(p++,c.r);
		f32.Set(p++,c.g);
		f32.Set(p++,c.b);
		f32.Set(p++,c.a);		
		f32.Set(p++,p_a.x);
		f32.Set(p++,p_a.y);
		f32.Set(p++,p_a.z);
		f32.Set(p++,p_a.w);
		f32.Set(p++,p_b.x);
		f32.Set(p++,p_b.y);
		f32.Set(p++,p_b.z);
		f32.Set(p++,p_b.w);		
		//trace("push "+m_render_count);
		var m : Matrix4 = (p_transform == null ? IDM : p_transform);
		var ms : String = "";
		for (i in 0...12)
		{			
			f32.Set(p++, m.GetIndex(i));			
		}
		
		m_render_count++;
	}
	
	/**
	 * Clears the rendering.
	 */
	public function Clear():Void 
	{ 
		m_render_count = 0;		
	}
	
	/**
	 * Render all gizmos in the queue.
	 */
	public function Render():Void 
	{	
		var gizmo_collider : Bool = Debug.collider || Debug.colliderAABB || Debug.colliderSB;
		
		if (gizmo_collider)
		{
			var cl : Array<Collider> = EngineContext.physics.colliders;			
			for (i in 0...cl.length)
			{
				var c : Collider = cl[i];				
				if (Debug.collider) Debug.Collider(c);
				if (Debug.colliderAABB)     Debug.BoundingAABB(c.aabb);
				if (Debug.colliderSB)   Debug.BoundingSphere(c.sphere);				
			}
		}
		
		if (Debug.renderer)
		{
			var rpl :Array<Process<Renderer>> = EngineContext.renderer.display;
			for (i in 0...rpl.length)
			{
				var rp : Process<Renderer> = rpl[i];
				for (j in 0...rp.length)
				{	
					var mr : MeshRenderer = cast rp.list[j];
					
					if (mr == null) continue;
					Debug.MeshRenderer(mr);
				}
			}
		}
		
		if (Debug.transform)
		{
			Transform.root.Traverse(function(p_t : Transform, p_d : Int):Bool
			{
				if (p_t == Transform.root) return true;
				if (p_t == Camera.main.transform) return true;
				Debug.Transform(p_t);
				return true;
			});
		}
		
		if (m_render_count > 0)
		{			
			data.Apply();
			material.SetInt("Count", m_render_count);
			var np : Float32 = Camera.main.near;
			var fp : Float32 = Camera.main.far;
			Camera.main.near = 1.0;
			Camera.main.far  = 50000;
			Graphics.Render(mesh, material, null, Camera.main);			
			Camera.main.near = np;
			Camera.main.far = fp;
		}
	}
	
	
}

/**
 * Wireframe sphere gizmo.
 */
class WireSphereGizmo extends Gizmo
{
	/**
	 * Creates the gizmo.
	 */
	public function new() { super(Gizmo.WIRE_SPHERE, Gizmo.MAX_GIZMOS); }
	
	/**
	 * Creates the mesh and other data.
	 */
	override public function OnBuild():Void
	{
		var m : Mesh3 = new Mesh3();		
		m.name 	 = "$GizmoWireSphereMesh";
		m.primitive = MeshPrimitive.Lines;		
		var r : Float32 = 1.0;
		var v : Vector3;
		var steps : Int = 720;				
		var ia : FloatArray = new FloatArray(steps * 6 * m_gizmo_count);
		var va : FloatArray = new FloatArray(steps * 18 * m_gizmo_count);		
		var va_k : Int = 0;
		var ia_k : Int = 0;		
		var id : Float32 = 0.0;		
		for (k in 0...m_gizmo_count)
		{		
			for (i in 0...steps)
			{
				var astp : Float32 = 1.0 / (steps - 1);
				var a : Float32;
				a = 360 * i * astp;
				var sv0 : Float32 = Mathf.Sin(a * Mathf.Deg2Rad)*r*0.5;
				var cv0 : Float32 = Mathf.Cos(a * Mathf.Deg2Rad) * r * 0.5;
				a = 360 * (i+1) * astp;
				var sv1 : Float32 = Mathf.Sin(a * Mathf.Deg2Rad)*r*0.5;
				var cv1 : Float32 = Mathf.Cos(a * Mathf.Deg2Rad)*r* 0.5;				
				va.Set(va_k++, cv0); va.Set(va_k++, 0.0); va.Set(va_k++, sv0); ia.Set(ia_k++, id);
				va.Set(va_k++, cv1); va.Set(va_k++, 0.0); va.Set(va_k++, sv1); ia.Set(ia_k++, id);				
				va.Set(va_k++, 0.0); va.Set(va_k++, cv0); va.Set(va_k++, sv0); ia.Set(ia_k++, id);
				va.Set(va_k++, 0.0); va.Set(va_k++, cv1); va.Set(va_k++, sv1); ia.Set(ia_k++, id);				
				va.Set(va_k++, cv0); va.Set(va_k++, sv0); va.Set(va_k++, 0.0); ia.Set(ia_k++, id);
				va.Set(va_k++, cv1); va.Set(va_k++, sv1); va.Set(va_k++, 0.0); ia.Set(ia_k++, id);				
			}
			id += 1.0;
		}		
		m.Set("id", ia, 1);
		m.Set("vertex", va, 3);		
		mesh = m;
	}
}

/**
 * Wireframe cube gizmo.
 */
class WireCubeGizmo extends Gizmo
{
	/**
	 * Creates the gizmo.
	 */
	public function new() { super(Gizmo.WIRE_CUBE, Gizmo.MAX_GIZMOS); }
	
	/**
	 * Creates the gizmo data.
	 */
	override public function OnBuild():Void 
	{
		var m : Mesh3 = new Mesh3();		
		m.name 	 = "$GizmoWireCubeMesh";
		m.primitive = MeshPrimitive.Lines;		
		var a : Float = -0.5;
		var b : Float =  0.5;
		var p : Array<Vector3> = 
		[
			new Vector3(a, a, a), new Vector3(a, a, b), new Vector3(b, a, b), new Vector3(b, a, a), 
			new Vector3(a, b, a), new Vector3(a, b, b), new Vector3(b, b, b), new Vector3(b, b, a)
		];				
		var tp : Array<Int> = 
		[
			0, 1, 1, 2, 2, 3, 3, 0,
			4, 5, 5, 6, 6, 7, 7, 4,
			0, 1, 1, 5, 5, 4, 4, 0,
			3, 2, 2, 6, 6, 7, 7, 3,
			0, 3, 3, 7, 7, 4, 4, 0,
			1, 5, 5, 6, 6, 2, 2, 1
		];
		var va : FloatArray = new FloatArray(tp.length * 3 * m_gizmo_count);
		var ia : FloatArray = new FloatArray(tp.length * 1 * m_gizmo_count);
		var va_k : Int = 0;
		var ia_k : Int = 0;
		var id : Float = 0.0;
		for (k in 0...m_gizmo_count)
		{
			for (i in 0...tp.length)
			{
				var vid : Int = tp[i];
				va.Set(va_k++, p[vid].x); 
				va.Set(va_k++, p[vid].y); 
				va.Set(va_k++, p[vid].z); 
				ia.Set(ia_k++, id);
			}
			id += 1.0;
		}
		m.Set("id", ia, 1);
		m.Set("vertex", va, 3);	
		mesh = m;
	}
}

/**
 * Gizmo that shows the axis of a transform space.
 */
class AxisGizmo extends Gizmo
{
	/**
	 * Creates the gizmo.
	 */
	public function new() { super(Gizmo.AXIS, Gizmo.MAX_GIZMOS); }
	
	/**
	 * Builds the gizmo data.
	 */
	override public function OnBuild():Void 
	{
		var m : Mesh3 = new Mesh3();		
		m.name 	 = "$GizmoAxisMesh";
		m.primitive = MeshPrimitive.Lines;
		
		var cr : Color = Color.red30;
		var cg : Color = Color.green30;
		var cb : Color = Color.blue30;
		
		var id : Float = 0.0;
		var ia : FloatArray = new FloatArray(m_gizmo_count * 6 * 1);
		var va : FloatArray = new FloatArray(m_gizmo_count * 6 * 3);
		var ca : FloatArray = new FloatArray(m_gizmo_count * 6 * 3);
		
		var va_k : Int = 0;
		var ca_k : Int = 0;
		var ia_k : Int = 0;
		
		for (k in 0...m_gizmo_count)
		{
			
			va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); ia.Set(ia_k++, id);
			va.Set(va_k++, 1.0); va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); ia.Set(ia_k++, id);			
			va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); ia.Set(ia_k++, id);			
			va.Set(va_k++, 0.0); va.Set(va_k++, 1.0); va.Set(va_k++, 0.0); ia.Set(ia_k++, id);			
			va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); ia.Set(ia_k++, id);			
			va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); va.Set(va_k++, 1.0); ia.Set(ia_k++, id);
			var c : Color;			
			c = cr;
			ca.Set(ca_k++, c.r); ca.Set(ca_k++, c.g); ca.Set(ca_k++, c.b); ca.Set(ca_k++, c.a);
			ca.Set(ca_k++, c.r); ca.Set(ca_k++, c.g); ca.Set(ca_k++, c.b); ca.Set(ca_k++, c.a);
			c = cg;
			ca.Set(ca_k++, c.r); ca.Set(ca_k++, c.g); ca.Set(ca_k++, c.b); ca.Set(ca_k++, c.a);
			ca.Set(ca_k++, c.r); ca.Set(ca_k++, c.g); ca.Set(ca_k++, c.b); ca.Set(ca_k++, c.a);
			c = cb;
			ca.Set(ca_k++, c.r); ca.Set(ca_k++, c.g); ca.Set(ca_k++, c.b); ca.Set(ca_k++, c.a);
			ca.Set(ca_k++, c.r); ca.Set(ca_k++, c.g); ca.Set(ca_k++, c.b); ca.Set(ca_k++, c.a);
			id += 1.0;
		}		
		m.Set("id", ia,1);
		m.Set("vertex", va,3);
		m.Set("color",  ca, 4);
		mesh = m;		
	}
}

/**
 * Gizmo that renders a line.
 */
class LineGizmo extends Gizmo
{
	/**
	 * Creates the gizmo.
	 */
	public function new() { super(Gizmo.LINE, Gizmo.MAX_GIZMOS*3); }
	
	/**
	 * Builds the gizmo data.
	 */
	override public function OnBuild():Void 
	{
		var m : Mesh3 = new Mesh3();		
		m.name 	 = "$GizmoLineMesh";
		m.primitive = MeshPrimitive.Lines;		
		var id : Float = 0.0;
		var ia : FloatArray = new FloatArray(m_gizmo_count * 2 * 1);
		var va : FloatArray = new FloatArray(m_gizmo_count * 2 * 3);
		var va_k : Int = 0;		
		var ia_k : Int = 0;		
		for (k in 0...m_gizmo_count)
		{
			va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); ia.Set(ia_k++, id);
			va.Set(va_k++, 1.0); va.Set(va_k++, 1.0); va.Set(va_k++, 1.0); ia.Set(ia_k++, id);			
			id += 1.0;
		}		
		m.Set("id", ia,1);
		m.Set("vertex", va,3);		
		mesh = m;		
	}
}

/**
 * Gizmo that renders points.
 */
class PointGizmo extends Gizmo
{
	/**
	 * Creates the gizmo.
	 */
	public function new() { super(Gizmo.POINT, Gizmo.MAX_GIZMOS * 5); }
	
	/**
	 * Builds the gizmo data.
	 */
	override public function OnBuild():Void 
	{
		var m : Mesh3 = new Mesh3();		
		m.name 	 = "$GizmoPointMesh";
		m.primitive = MeshPrimitive.Points;		
		var id : Float = 0.0;
		var ia : FloatArray = new FloatArray(m_gizmo_count * 1 * 1);
		var va : FloatArray = new FloatArray(m_gizmo_count * 1 * 3);
		var va_k : Int = 0;		
		var ia_k : Int = 0;		
		for (k in 0...m_gizmo_count)
		{
			va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); ia.Set(ia_k++, id);		
			id += 1.0;
		}		
		m.Set("id", ia,1);
		m.Set("vertex", va,3);		
		mesh = m;		
	}
}

/**
 * Gizmo that renders solid shapes using triangle fans.
 */
class CanvasGizmo extends Gizmo
{
	/**
	 * 
	 */
	public var fill : Color;
	
	/**
	 * 
	 */
	public var line : Color;
	
	/**
	 * 
	 */
	public var start : Vector3;
	
	/**
	 * 
	 */
	public var p0 : Vector3;
	public var p1 : Vector3;
	
	/**
	 * 
	 */
	public var transform : Matrix4;
	
	/**
	 * 
	 */
	public var count : Int;
	
	/**
	 * 
	 */
	public var active : Bool;
	
	/**
	 * Creates the gizmo.
	 */
	public function new() 
	{
		super(Gizmo.CANVAS, 3*1000);
		fill = Color.white;
		line = Color.black;
		p0 = Vector3.zero;
		p1 = Vector3.zero;
		start = Vector3.zero;
		count = 0;
		active = false;
		
		material.cull = CullMode.None;
	}
	
	/**
	 * 
	 * @param	p_fill
	 * @param	p_line
	 * @param	p_transform
	 */
	public function Begin(p_fill : Color, p_line : Color = null,p_transform : Matrix4 = null):Void
	{
		if (active) return;
		fill.SetColor(p_fill);
		if (p_line == null) { line.a = 0.0; } else line.SetColor(p_line);
		transform = p_transform;	
		count = 0;
		active = true;
	}
	
	/**
	 * 
	 * @param	p_position
	 */
	public function Line(p_position : Vector3):Void
	{		
		if (!active) return;
		if (count >= 2) haxor.graphics.Gizmo.Line(p0, p1, line, transform); 
		if (count <= 0) start.Set3(p_position);
		
		p1.Set3(p0);
		p0.Set3(p_position);		
		
		if (count >= 2)
		{			
			Push(fill, Vector4.temp.Set(1,0,0,1), Vector4.temp.Set3(start), transform);
			Push(fill, Vector4.temp.Set(1,0,0,1), Vector4.temp.Set3(p1), transform);
			Push(fill, Vector4.temp.Set(1,0,0,1), Vector4.temp.Set3(p0), transform);
		}
		
		count++;
	}
	
	/**
	 * 
	 */
	public function End():Void
	{
		if (!active) return;
		haxor.graphics.Gizmo.Line(p0, start, line, transform);
		haxor.graphics.Gizmo.Line(p0, p1, line, transform);		
		
		active = false;
	}
	
	/**
	 * Builds the gizmo data.
	 */
	override public function OnBuild():Void 
	{
		var m : Mesh3 = new Mesh3();		
		m.name 	 = "$GizmoCanvasMesh";
		m.primitive = MeshPrimitive.Triangles;		
		var id : Float = 0.0;
		var ia : FloatArray = new FloatArray(m_gizmo_count * 3 * 1);
		var va : FloatArray = new FloatArray(m_gizmo_count * 3 * 3);
		var va_k : Int = 0;		
		var ia_k : Int = 0;		
		for (k in 0...m_gizmo_count)
		{
			va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); ia.Set(ia_k++, id); id += 1.0;
			va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); ia.Set(ia_k++, id); id += 1.0;
			va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); va.Set(va_k++, 0.0); ia.Set(ia_k++, id); id += 1.0;
			
		}		
		m.Set("id", ia,1);
		m.Set("vertex", va,3);		
		mesh = m;		
	}
}