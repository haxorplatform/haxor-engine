package haxor.component;
import haxor.context.EngineContext;
import haxor.core.Console;
import haxor.core.Enums.BoneQuality;
import haxor.core.Enums.PixelFormat;
import haxor.core.Resource;
import haxor.graphics.GL;
import haxor.graphics.Graphics;
import haxor.graphics.material.Material.MaterialUniform;
import haxor.graphics.mesh.Mesh;
import haxor.graphics.mesh.MeshLayout.SkinnedMesh3;
import haxor.graphics.Screen;
import haxor.graphics.texture.ComputeTexture;
import haxor.graphics.texture.Texture2D;
import haxor.io.FloatArray;
import haxor.math.Matrix4;
import haxor.math.Random;
import haxor.math.Vector2;
import haxor.platform.Types.Float32;


/**
 * Class that renders a SkinnedMesh.
 * @author ...
 */
@:allow(haxor)
class SkinnedMeshRenderer extends MeshRenderer
{	
	/**
	 * Array of joints that will act as skeleton of this renderer.
	 */	
	public var joints(get,set)  : Array<Transform>;
	private function set_joints(v:Array<Transform>):Array<Transform> 
	{ 	
		m_joints = v == null ? [] : v;		
		m_joint_names = [];
		for (i in 0...m_joints.length) m_joint_names.push(m_joints[i].name);		
		m_jf32   = [];				
		for (i in 0...m_joints.length) for (j in 0...12) m_jf32.push(m_joints[i].WorldMatrix.GetIndex(j));		
		UpdateSkinTexture(m_joints.length);
		if(!GL.BONE_TEXTURE) if (m_joints.length > GL.MAX_UNIFORM_BONES) Console.LogWarning("SkinnedMeshRenderer> ["+name+"] max bone count exceeded!");
		return m_joints; 
	}
	private function get_joints():Array<Transform> 
	{ 	
		if (m_joints == null) m_joints = [];
		
		if (m_joints.length != m_joint_names.length)
		{			
			if (m_joint_names == null) return [];
			m_joints = [];
			var rt : Transform = root;
			for (i in 0...m_joint_names.length) 
			{
				var jn : String = m_joint_names[i];
				var t : Transform = rt.GetChildByName(jn, true);
				if (t != null) m_joints.push(t);
			}				
		}
		return m_joints;
	}
	@serialize
	private var m_joint_names 	: Array<String>;
	private var m_joints 		: Array<Transform>;
	
	/**
	 * Root of the skeleton.
	 */
	public var root(get, set):Transform;
	private function get_root():Transform
	{
		if (m_root == null)
		{
			if (m_root_name == "") return null;
			var it : Transform = transform;
			while (it != Transform.root)
			{
				it = it.parent;
				m_root = it.GetChildByName(m_root_name, true);
				if (m_root != null) break;				
			}
		}
		return m_root;
	}
	private function set_root(v:Transform):Transform
	{
		m_root = v == null ? transform.parent : v;
		m_root_name = m_root.name;
		return v;
	}
	@serialize
	private var m_root_name:String;
	private var m_root : Transform;
	
	/**
	 * Overrides mesh set to handle binds matrix values.
	 * @param	v
	 * @return
	 */
	override function set_mesh(v:Mesh):Mesh 
	{
		var skm : SkinnedMesh3 = cast v;
		m_bmf32 = [];		
		if (skm != null)
		{
			UpdateSkinTexture(skm.binds.length);
			for (i in 0...skm.binds.length) for (j in 0...12) m_bmf32.push(skm.binds[i].GetIndex(j));
		}
		if (GL.BONE_TEXTURE)
		{
			EngineContext.renderer.UpdateSkinning(this, false);
		}
		return super.set_mesh(v);
	}
	
	/**
	 * Defines the quality of bone blending for this renderer.
	 */
	@serialize
	public var quality(get_quality, set_quality):Int;
	private function get_quality():Int { return m_quality; }
	private function set_quality(v:Int):Int { m_quality = v; return v; }
	private var m_quality : Int;
	
	
	
	/**
	 * Bind Matrix values
	 */
	private var m_bmf32	  : Array<Float32>;
	
	/**
	 * Joints values.
	 */
	private var m_jf32	  : Array<Float32>;
	
	/**
	 * Binds/Joints Textures.
	 */
	private var m_jt : ComputeTexture;	
	private var m_bmt : ComputeTexture;
	
	/**
	 * SkinnedMesh id.
	 */
	private var __smid : Int;
	
	/**
	 * Method called after component creation.
	 */
	override function OnBuild():Void 
	{
		__smid   		= -1;
		super.OnBuild();
		m_joint_names 	= [];
		m_bmf32  		= [];
		m_jf32   		= [];
		m_quality 		= BoneQuality.Bone2;
		//m_jt     = new ComputeTexture(32, 16, PixelFormat.Float4);
		//m_bmt    = new ComputeTexture(32, 16, PixelFormat.Float4);
	}
	
	override public function OnRender():Void 
	{	
		if (material != null)
		{	
			var k 	: Int = 0;
			var jl  : Array<Transform> = joints;
			//Transfer the joint matrix data to the array.
			for (i in 0...jl.length) for (j in 0...12)  m_jf32[k++] = jl[i].WorldMatrix.GetIndex(j);
				
			if (GL.BONE_TEXTURE)
			{				
				EngineContext.renderer.UpdateSkinning(this, true);				
			}
			else
			{
				//Create and set the uniform
				material.SetFloat4Array("Joints", m_jf32);			
				//Create and set the uniform
				material.SetFloat4Array("Binds",  m_bmf32);
			//*/			
			}
			var bq : Int = 2;
			switch(m_quality)
			{
				case BoneQuality.Auto:  bq = 2;
				case BoneQuality.Bone1: bq = 1;
				case BoneQuality.Bone2: bq = 2;
				case BoneQuality.Bone3: bq = 3;
				case BoneQuality.Bone4: bq = 4;
			}			
			material.SetInt("SkinQuality", bq);
		}
		super.OnRender();
		
	}
	
	/**
	 * Destroys the old textures and create new ones for the desired joint count.
	 * @param	p_joint_count
	 */
	private function UpdateSkinTexture(p_joint_count : Int):Void
	{
		if (!GL.BONE_TEXTURE) return;
		if (p_joint_count <= 0) return;
		if (m_jt != null)  Resource.Destroy(m_jt);
		if (m_bmt != null) Resource.Destroy(m_bmt);
		var ts : Vector2 = GetSkinTexSize(p_joint_count);
		m_jt = new ComputeTexture(cast ts.x,cast  ts.y, PixelFormat.Float4);
		m_bmt = new ComputeTexture(cast ts.x, cast  ts.y, PixelFormat.Float4);		
	}
	
	/**
	 * Returns the ideal texture size for given joint count.
	 * @param	p_joint_count
	 * @return
	 */
	private function GetSkinTexSize(p_joint_count : Int):Vector2
	{
		var w : Int = 1;
		var h : Int = 1;
		var t : Int = p_joint_count * 3;
		while((w*h) < t)
		{
			w = w << 1;
			if ((w * h) >= t) break;
			h = h << 1;
			if ((w * h) >= t) break;
			if (w >= 512) if (h >= 512) break;
		}
		return Vector2.temp.Set(w, h);
	}
}