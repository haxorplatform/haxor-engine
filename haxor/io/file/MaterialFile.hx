package haxor.io.file;
import haxor.core.Asset;
import haxor.core.Console;
import haxor.core.Enums.BlendMode;
import haxor.core.Enums.CullMode;
import haxor.core.Enums.DepthTest;
import haxor.core.Enums.RenderQueue;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.math.Color;
import haxor.math.Matrix4;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.platform.Types.Float32;

/**
 * Class that describes a MaterialFile.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class MaterialFile extends AssetXML
{
	
	/**
	 * Material guid. If it was created in the editor.
	 */
	public var mguid	: String;	
	
	/**
	 * Material name.
	 */
	public var mname 	: String;	
	
	/**
	 * Render queue.
	 */
	public var queue 	: String;	
	
	/**
	 * Shader id.
	 */
	public var shader 	: String;	
	
	/**
	 * Offset in the render queue.
	 */
	public var offset 	: Int;	
	
	/**
	 * Flag to ZTest.
	 */
	public var ztest 	: Bool;	
	
	/**
	 * Type of ztest func.
	 */
	public var zfunc 	: String;	
	
	/**
	 * Flag for zwrite.
	 */
	public var zwrite 	: Bool;
	
	/**
	 * Flag for blending.
	 */
	public var blend	: Bool;	
	
	/**
	 * Blend src function.
	 */
	public var blendSrc	: String;	
	
	/**
	 * Blend dst function.
	 */
	public var blendDst	: String;	
	
	/**
	 * Flag for inverted triangle rendering.
	 */
	public var invert   : Bool;	
	
	/**
	 * Flag for lighting
	 */
	public var lighting	: Bool;
	
	/**
	 * Flag for grab texture.
	 */
	public var grab  	: Bool;
	
	/**
	 * Flag for culling type.
	 */
	public var cull		: String;	
	
	/**
	 * List of serialized uniforms.
	 */
	public var uniforms	: Array<MaterialFileUniform>;
	
	/**
	 * Creates a new material file and parses the XML data.
	 * @param	p_src
	 */
	public function new(p_src : String) 
	{	
		mguid    = "";
		mname    = "";
		queue    = "opaque";		
		offset   = 0;
		shader   = "";
		ztest    = true;
		zfunc    = "lessequal";
		zwrite   = true;
		blend    = false;
		blendSrc = "one";
		blendDst = "zero";
		invert   = false;
		lighting = false;
		grab     = false;
		cull     = "back";
		uniforms = [];
		super("",p_src);		
	}
	
	override function get_asset():Dynamic 
	{
		var m : Material = new Material();				
		m.name   = mname;		
		m.m_guid = mguid;
		
		switch(queue)
		{
			case "geometry":   	 m.queue = RenderQueue.Opaque;
			case "background":   m.queue = RenderQueue.Background;
			case "opaque":   	 m.queue = RenderQueue.Opaque;
			case "transparent":	 m.queue = RenderQueue.Transparent;
			case "overlay":		 m.queue = RenderQueue.Overlay;
			case "interface":	 m.queue = RenderQueue.Interface;
		}		
		m.queue += offset;		
		var shd : Shader = Asset.Get(shader);
		if (shd == null) { Console.LogWarning("MaterialFile> [" + m_name+"] shader[" + shader + "] is null!"); shd = Shader.Flat; }
		m.shader = shd;		
		m.ztest  = ztest;		
		m.zfunc = DepthTest.LessEqual;
		switch(zfunc)
		{
			case "never":			m.zfunc = DepthTest.Never;
			case "always":			m.zfunc = DepthTest.Always;
			case "notequal":		m.zfunc = DepthTest.NotEqual;
			case "equal":			m.zfunc = DepthTest.Equal;
			case "less":			m.zfunc = DepthTest.Less;
			case "lessequal": 		m.zfunc = DepthTest.LessEqual;
			case "greater":			m.zfunc = DepthTest.Greater;
			case "greaterequal":	m.zfunc = DepthTest.GreaterEqual;
		}		
		m.zwrite = zwrite;
		m.blend  = blend;
		m.blendSrc = BlendModeNameToEnum(blendSrc);
		m.blendDst = BlendModeNameToEnum(blendDst);
		m.invert   = invert;
		m.lighting = lighting;
		m.grab     = grab;		
		switch(cull)
		{
			case "none": 	m.cull = CullMode.None;
			case "front": 	m.cull = CullMode.Front;
			case "back": 	m.cull = CullMode.Back;			
		}		
		for (i in 0...uniforms.length)
		{
			var u : MaterialFileUniform = uniforms[i];			
			var a    : Array<Float32> = stof32a(u.value);
			switch(u.type)
			{				
				case "int":		m.SetInt(u.name, Std.parseInt(u.value));				
				case "vec2":    m.SetFloat2(u.name,a[0], a[1]);
				case "vec3":    m.SetFloat3(u.name,a[0], a[1], a[2]);
				case "vec4":    m.SetFloat4(u.name,a[0], a[1], a[2], a[3]);
				case "mat4":    m.SetMatrix4(u.name, Matrix4.FromArray(a,Matrix4.temp));
				case "color":	m.SetFloat4(u.name,a[0], a[1], a[2], a[3]);
				case "texture":	m.SetTexture(u.name,Asset.Get(u.value));
			}
		}		
		return m;
	}
	
	
	
	override private function Parse(n : Xml):Void
	{
		switch(n.nodeName)
		{
			case "material":
				mguid    = _a(n, "guid", "");
				mname  = _a(n, "name", "");
				
			case "queue":
				offset = Std.parseInt(_a(n, "offset", "0"));
				queue  = _p(n, "$text", "geometry",true,true);
				
			case "shader":   shader   = _p(n, "$text", "");
			case "ztest":    ztest    = _p(n, "$text", "true", true, true) == "true";
			case "zfunc":    zfunc    = _p(n, "$text", zfunc);
			case "zwrite":   zwrite   = _p(n, "$text", "true", true, true) == "true";
			case "blend":    blend    = _a(n, "enabled", "false") == "true";
							 blendSrc = _p(n, "src.$text", "one", true, true);
							 blendDst = _p(n, "dst.$text", "zero", true, true);
			case "invert":   invert   = _p(n, "$text", "false", true, true) == "true";
			case "lighting": lighting = _p(n, "$text", "false", true, true) == "true";
			case "grab": 	 grab     = _p(n, "$text", "false", true, true) == "true";
			case "cull":	 cull	  = _p(n, "$text", cull, true, true);
			
			case "uniforms": ParseUniforms(n);
		}
	}	
	
	/**
	 * Parse a uniform tag.
	 * @param	n
	 */
	private function ParseUniforms(n : Xml):Void
	{		
		var it : Iterator<Xml> = n.elements();	
		while (it.hasNext())
		{
			n = it.next();						
			var u : MaterialFileUniform = new MaterialFileUniform();
			u.type  = n.nodeName.toLowerCase();
			u.name  = _a(n, "name", "");
			u.value = _p(n, "$text", "", true); 
			uniforms.push(u);
		}
		
	}
	
	private function BlendModeNameToEnum(b : String):Int
	{
		switch(b)
		{
			case "zero": 				return BlendMode.Zero;			
			case "one":					return BlendMode.One;
			case "srccolor":			return BlendMode.SrcColor;
			case "oneminussrccolor":	return BlendMode.OneMinusSrcColor;
			case "srcalpha":			return BlendMode.SrcAlpha;
			case "oneminussrcalpha":	return BlendMode.OneMinusSrcAlpha;
			case "dstalpha":			return BlendMode.DstAlpha;
			case "oneminusdstalpha":	return BlendMode.OneMinusDstAlpha;
			case "dstcolor":			return BlendMode.DstColor;
			case "oneminusdstcolor":	return BlendMode.OneMinusDstColor;
			case "srcalphasaturate":	return BlendMode.SrcAlphaSaturate;
		}
		return BlendMode.Zero;
	}
}

/**
 * Class that describes a serialized uniform.
 */
class MaterialFileUniform
{
	public var type  : String;	
	public var name  : String;	
	public var value : String;
	
	public function new()
	{
		type  = "";
		name  = "";
		value = "";
	}
}