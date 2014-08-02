/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.component;
import js.html.AbstractWorker;
import js.html.Float32Array;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.graphics.Graphics;
import haxor.graphics.Mesh;
import haxor.graphics.MeshTemplate.Mesh3;
import haxor.graphics.MeshTemplate.SkinnedMesh3;
import haxor.input.Input;
import haxor.input.KeyCode;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.texture.KernelTexture;
import haxor.texture.Texture.TextureFormat;

/**
 * ...
 * @author ...
 */
class SkinnedMeshRenderer extends MeshRenderer
{
	public var joints(get_joints,set_joints)  : Array<Transform>;
	private function set_joints(v:Array<Transform>):Array<Transform> 
	{ 
		m_joints = v == null ? [] : v;
		/*
		var skm : SkinnedMesh3 = cast mesh;
		for (i in 0...m_joints.length)			
		{				
			material.SetUniform("joints_id[" + i + "]", m_joints[i].m_tid + 0.00001);
			material.SetUniform("binds[" + i + "]", skm.binds[i]);
		}
		material.SetUniform("Transform", Transform.m_kernel.output);
		//*/
		return m_joints;
	}
	
	private function get_joints():Array<Transform> { return m_joints; }
	private var m_joints : Array<Transform>;
	
	private var m_buffer : Float32Array;
	
	private var m_sampler : KernelTexture;
		
	function new(p_entity : Entity) 
	{
		m_joints = [];		
		//MAX_JOINTS = 50
		//MAX_BINDS  = 50
		m_buffer  = new Float32Array(8192);// 12 * (50 + 50));
		m_sampler = new KernelTexture(1, 2048, TextureFormat.Float4);
		m_sampler.name = "SkinningTexture" + id;
		super(p_entity);	
	}
	
	override public function OnRender():Void 
	{	
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
					m_buffer[k] 		 = jm.GetIndex(j);
					m_buffer[k + 4096]   = bm.GetIndex(j);
					k++;
				}
			}
			
			m_sampler.WriteRange(m_buffer);
			
			material.SetUniform("Skinning", m_sampler);
			//material.SetUniform("Skinning", m_buffer);
			
		}
		super.OnRender();
	}
	
}