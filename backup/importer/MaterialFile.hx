package haxor.importer;
import js.html.Float32Array;
import haxor.core.Asset;
import haxor.core.Console;
import haxor.graphics.BlendMode;
import haxor.graphics.CullMode;
import haxor.graphics.DepthTest;
import haxor.graphics.Material;
import haxor.graphics.RenderQueue;
import haxor.math.Color;
import haxor.math.Matrix4;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class MaterialFile extends AssetFile<Material>
{
	
	public var id 		: String;	
	public var name 	: String;	
	public var queue 	: String;	
	public var shader 	: String;	
	public var offset 	: Int;	
	public var ztest 	: Bool;	
	public var zfunc 	: String;	
	public var zwrite 	: Bool;	
	public var blend	: Bool;	
	public var blendSrc	: String;	
	public var blendDst	: String;	
	public var invert   : Bool;	
	public var lighting	: Bool;
	public var grab  	: Bool;
	public var cull		: String;	
	public var uniforms	: Array<MaterialFileUniform>;
	
	public function new(p_src : String) 
	{	
		id       = "";
		name     = "";
		queue    = "geometry";		
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
		super(p_src);
		
	}
	
	override public function GetAsset() : Material
	{		
		var m : Material = new Material();
		
		m.name = name;
		
		switch(queue)
		{
			case "background":   m.queue = RenderQueue.Background;
			case "opaque":   	 m.queue = RenderQueue.Opaque;
			case "geometry":     m.queue = RenderQueue.Geometry;
			case "transparent":	 m.queue = RenderQueue.Transparent;
			case "overlay":		 m.queue = RenderQueue.Overlay;
			case "interface":	 m.queue = RenderQueue.Interface;
		}
		
		m.queue += offset;
		
		m.shader = Asset.Get(shader);
		
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
			var a    : Array<Float> = _f32a(u.value);						
			switch(u.type)
			{
				case "float":	
					var f32a : Float32Array = new Float32Array(a); 
					m.SetUniform(u.name, f32a.length == 1 ? (f32a[0]+0.00001) : f32a);
				case "int":		m.SetUniform(u.name, Std.parseInt(u.value));				
				case "vec2":    m.SetUniform(u.name, new Vector2(a[0], a[1]));
				case "vec3":    m.SetUniform(u.name, new Vector3(a[0], a[1],a[2]));
				case "vec4":    m.SetUniform(u.name, new Vector4(a[0], a[1], a[2], a[3]));
				case "mat4":    m.SetUniform(u.name, Matrix4.FromArray(a));
				case "color":	m.SetUniform(u.name, new Color(a[0], a[1], a[2], a[3]));
				case "texture":	m.SetUniform(u.name, Asset.Get(u.value));				
			}
		}
		
		return m;
	}
	
	override private function Parse(n : Xml):Void
	{
		switch(n.nodeName)
		{
			case "material":
				id    = _a(n, "id", "");
				name  = _a(n, "name", "");
				
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

class MaterialFileUniform
{
	public var type : String;
	
	public var name : String;
	
	public var value : String;
	
	public function new()
	{
		type  = "";
		name  = "";
		value = "";
	}
}