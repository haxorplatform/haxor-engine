
package haxor.graphics.material;

import haxor.context.EngineContext;
import haxor.core.Resource;
import haxor.graphics.Enums.BlendMode;
import haxor.graphics.Enums.CullMode;
import haxor.graphics.Enums.DepthTest;
import haxor.graphics.Enums.RenderQueue;


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
	
	public function new(p_name)
	{
		super(p_name);	
		_cid_ 			= EngineContext.material.mid++;
		
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
		blend = !((p_src == BlendMode.One) && (p_dst == BlendMode.Zero));
		blendSrc = p_src;
		blendDst = p_dst;
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