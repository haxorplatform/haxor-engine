package haxor.component;
import haxor.core.Enums.PixelFormat;
import haxor.graphics.texture.ComputeTexture;
import haxor.io.FloatArray;

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
	private function set_joints(v:Array<Transform>):Array<Transform> {  m_joints = v == null ? [] : v; return m_joints; }	
	private inline function get_joints():Array<Transform> { return m_joints; }
	private var m_joints : Array<Transform>;
	
	private var m_buffer : FloatArray;
	
	private var m_data : ComputeTexture;
	
	/**
	 * Method called after component creation.
	 */
	override function OnBuild():Void 
	{
		super.OnBuild();
		m_joints = [];		
		//MAX_JOINTS = 50
		//MAX_BINDS  = 50
		m_buffer  	= new FloatArray(8192);// 12 * (50 + 50));
		m_data 		= new ComputeTexture(1, 2048, PixelFormat.Float4);
		m_data.name = "SkinningTexture" + uid;
	}
	
	override public function OnRender():Void 
	{	
		/*
		if (material != null)
		{	
			var skm : SkinnedMesh3 = cast mesh;
			var k : Int = 0;
			var jm : Matrix4;
			var bm : Matrix4;		
			
			for (i in 0...m_joints.length)			
			{	
				jm = m_joints[i].m_worldMatrix;
				bm = skm.binds[i];
				for (j in 0...12)
				{
					m_buffer.Set(k,jm.GetIndex(j));
					m_buffer.Set(k + 4096,bm.GetIndex(j));
					k++;
				}
			}
			
			m_data.WriteRange(m_buffer);
			
			material.SetUniform("Skinning", m_data);			
			
		}
		//*/
		super.OnRender();
	}
	
}