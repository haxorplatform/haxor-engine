package haxor.component;
import haxor.context.EngineContext;
import haxor.core.Enums.PixelFormat;
import haxor.graphics.Graphics;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.mesh.MeshLayout.SkinnedMesh3;
import haxor.graphics.Screen;
import haxor.graphics.texture.ComputeTexture;
import haxor.graphics.texture.Texture2D;
import haxor.io.FloatArray;
import haxor.math.Matrix4;
import haxor.math.Random;
import haxor.platform.Types.Float32;

/**
 * Class that renders a SkinnedMesh.
 * @author ...
 */
class SkinnedMeshRenderer extends MeshRenderer
{
	/**
	 * Array of joints that will act as skeleton of this renderer.
	 */
	public var joints(get_joints,set_joints)  : Array<Transform>;
	private function set_joints(v:Array<Transform>):Array<Transform> 
	{ 		
		m_joints = v == null ? [] : v;  
		m_joints_mat4 = [];
		for (i in 0...m_joints.length) for (j in 0...12)  m_joints_mat4.push(m_joints[i].WorldMatrix.GetIndex(j));
		return m_joints; 
	}
	private inline function get_joints():Array<Transform> { return m_joints; }
	private var m_joints : Array<Transform>;	
	private var m_joints_mat4 : Array<Float32>;
	
	override function set_mesh(v:Mesh):Mesh 
	{
		var skm : SkinnedMesh3 = cast v;
		m_bm_mat4 = [];
		if (skm != null)
		{
			for (i in 0...skm.binds.length) for (j in 0...12) m_bm_mat4.push(skm.binds[i].GetIndex(j));
		}		
		return super.set_mesh(v);
	}
	
	private var m_bm_mat4 	  : Array<Float32>;
	
	private var m_buffer : Array<Float32>;
	
	private var m_data : ComputeTexture;
	
	private var m_bmloaded : Bool;
	
	/**
	 * Method called after component creation.
	 */
	override function OnBuild():Void 
	{
		super.OnBuild();
		m_joints = [];		
		//MAX_JOINTS = 50
		//MAX_BINDS  = 50
		m_bmloaded = false;
		m_buffer  	= [];// new FloatArray(8192);// 12 * (50 + 50));
		for (i in 0...8192) m_buffer.push(0);
		m_data 		= new ComputeTexture(1, 2048, PixelFormat.Float4);
		m_data.name = "SkinningTexture" + uid;
		
		
		
	}
	
	override public function OnRender():Void 
	{	
		
		if (material != null)
		{	
			var skm : SkinnedMesh3 = cast mesh;
			var k : Int = 0;
			var jm : Matrix4;
			var bm : Matrix4;		
			var f32 : FloatArray = cast m_data.data.buffer;
			
			//Create rotation matrix and test upload.
			
			
			/*
			for (i in 0...m_joints.length) for (j in 0...12)  m_joints_mat4[k++] = m_joints[i].WorldMatrix.GetIndex(j);			
			k = 0;
			//*/
			
			for (i in 0...m_joints.length)			
			{	
				jm = m_joints[i].WorldMatrix;				
				bm = skm.binds[i];
				for (j in 0...12)
				{					
					f32.Set(k, jm.GetIndex(j));
					if(!m_bmloaded)f32.Set(k + 4096, bm.GetIndex(j));
					k++;
				}
				
			}
			m_bmloaded = true;
			m_data.Invalidate();
			//*/
			//material.SetFloat4Array("Joints", m_joints_mat4);
			//material.SetFloat4Array("Binds",  m_bm_mat4);			
			
			material.SetTexture("Skinning", m_data);
			
		}
		//*/
		
		super.OnRender();
		
		/*
		var sh : Float = Screen.height;
		var th : Float = 2048.0;// sh * 0.9;		
		Graphics.DrawTexture(m_data,0,th+105,256,-th);		
		//*/
		//Graphics.DrawTexture(EngineContext.gizmo.canvas_renderer.data,0,400,128,-128);
	}
	
}