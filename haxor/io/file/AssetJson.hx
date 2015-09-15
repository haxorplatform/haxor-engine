package haxor.io.file;
import haxe.crypto.Base64;
import haxe.io.Bytes;
import haxe.Json;
import haxor.io.Buffer;
import haxor.io.file.AssetFile;
import haxor.platform.Types.Float32;
import js.Error;

/**
 * Class that implements a parser for the json model file.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class AssetJson extends AssetFile
{

	/**
	 * Parses the loaded data and returns a Haxor entity.
	 * @return
	 */
	override function get_asset():Dynamic 
	{
		return null;
	}
	
	/**
	 * Returns the list of texture buffers.
	 * @return
	 */
	override function get_images():Array<ImageFile> 
	{
		var res : Array<ImageFile> = [];
		for (t in textures)
		{
			var img : ImageFile = new ImageFile(t.format, t.data);
			res.push(img);
		}
		return res;
	}
	
	/**
	 * Metadata.
	 */
	public var meta : JsonMeta;
	
	/**
	 * Root node of the hierarchy.
	 */
	public var root : JsonNode;
	
	/**
	 * 
	 */
	public var flags : Int;
	
	/**
	 * List of scene elements.
	 */
	public var meshes 		: Array<JsonMesh>;
	public var materials 	: Array<JsonMaterial>;
	public var animations 	: Array<JsonAnimationClip>;
	public var lights 		: Array<JsonLight>;
	public var cameras 		: Array<JsonCamera>;
	public var textures		: Array<JsonTexture>;
	
	/**
	 * Creates a new json asset file.
	 * @param	p_name
	 * @param	p_src
	 */
	public function new(p_name:String,p_src : String) 
	{	
		super(p_name);
		meta   		= new JsonMeta();
		flags  		= 0;
		meshes 		= [];
		materials 	= [];
		animations  = [];
		lights		= [];
		cameras		= [];
		textures	= [];
		var n : Dynamic = Json.parse(p_src);
		Traverse(null, n, Parse);
	}
	
	/**
	 * Parses the content of the file, field by field.
	 * @param	p_parent
	 * @param	p_target
	 * @param	p_key
	 * @param	p_value
	 * @return
	 */
	private function Parse(p_parent:Dynamic, p_target:Dynamic, p_key:String, p_value:String):Bool
	{
		switch(p_key)
		{
			case "__metadata__":
			{
				meta.format  = get(p_value, "format");
				meta.version = get(p_value, "version");
				return false;
			}
			
			case "rootnode":
			{				
				root = ParseNode(null, p_value);
				return false;
			}		
			
			case "flags":
			{
				flags = assert(p_value, 0);
				return false;
			}
			
			case "meshes":
			{
				var l : Array<Dynamic> = assert(p_value, []);
				for (i in 0...l.length) { var m : JsonMesh = ParseMesh(l[i]); meshes.push(m); }				
				return false;
			}
			
			case "materials":
			{
				var l : Array<Dynamic> = assert(p_value, []);
				for (i in 0...l.length) { var m : JsonMaterial = ParseMaterial(l[i]); materials.push(m); }				
				return false;
			}
			
			case "animations":
			{
				var l : Array<Dynamic> = assert(p_value, []);
				for (i in 0...l.length) { var a : JsonAnimationClip = ParseAnimationClip(l[i]); animations.push(a); }				
				return false;
			}
			
			case "lights":
			{
				var l : Array<Dynamic> = assert(p_value, []);
				for (i in 0...l.length) { var d : JsonLight = ParseLight(l[i]); lights.push(d); }				
				return false;
			}
			
			case "cameras":
			{
				var l : Array<Dynamic> = assert(p_value, []);
				for (i in 0...l.length) { var d : JsonCamera = ParseCamera(l[i]); cameras.push(d); }				
				return false;
			}
			
			case "textures":
			{
				var l : Array<Dynamic> = assert(p_value, []);
				for (i in 0...l.length) { var d : JsonTexture = ParseTexture(l[i]); textures.push(d); }				
				return false;
			}
		}
		return true;
	}
	
	/**
	 * Parses a texture from the file.
	 * @param	p_material
	 * @return
	 */
	private function ParseTexture(p_data:Dynamic):JsonTexture
	{
		var d   : Dynamic  	  = p_data;
		var res : JsonTexture = new JsonTexture();
		res.width		 = assert(get(d, "width"), 		res.width	);
		res.height		 = assert(get(d, "height"), 	res.height	);
		res.format		 = assert(get(d, "formathint"), res.format	);		
		var b64 : String = assert(get(d, "data"), 		"");
		b64 = StringTools.replace(b64, "\t", "");
		b64 = StringTools.replace(b64, "\n", "");
		b64 = StringTools.replace(b64, "\r", "");
		b64 = StringTools.replace(b64, " ", "");
		b64 = StringTools.trim(b64);
		if (b64 != "")
		{	
			var b : Bytes = Base64.decode(b64);
			res.data = new Buffer(b.length);			
			for (i in 0...b.length) res.data.SetByte(i, b.get(i));			
		}		
		return res;
	}
	
	/**
	 * Parses a camera from the file.
	 * @param	p_material
	 * @return
	 */
	private function ParseCamera(p_data:Dynamic):JsonCamera
	{
		var d   : Dynamic  	  = p_data;
		var res : JsonCamera = new JsonCamera();
		res.name		= assert(get(d, "name"), 			res.name	);
		res.aspect		= assert(get(d, "aspect"), 			res.aspect	);
		res.far			= assert(get(d, "clipplanefar"), 	res.far		);
		res.near		= assert(get(d, "clipplanenear"), 	res.near	);
		res.hfov		= assert(get(d, "horizontalfov"), 	res.hfov	);
		res.up			= assert(get(d, "up"), 				res.up		);
		res.lookAt		= assert(get(d, "lookat"), 			res.lookAt  );			
		return res;
	}
	
	/**
	 * Parses a light from the file.
	 * @param	p_material
	 * @return
	 */
	private function ParseLight(p_data:Dynamic):JsonLight
	{
		var d   : Dynamic  	  = p_data;
		var res : JsonLight = new JsonLight();		
		res.name		= assert(get(d, "name"), res.name);
		res.type		= assert(get(d, "type"), res.type);
		res.constant	= assert(get(d, "attenuationconstant"),  res.constant);
		res.linear		= assert(get(d, "attenuationlinear"), 	 res.linear);
		res.quadratic	= assert(get(d, "attenuationquadratic"), res.quadratic);
		res.color		= assert(get(d, "diffusecolor"), res.color);
		res.specular	= assert(get(d, "specularcolor"), res.specular);
		res.ambient		= assert(get(d, "specularcolor"), res.specular);
		res.color		= assert(get(d, "ambientcolor"), res.ambient);
		res.position	= assert(get(d, "position"), res.position);
		res.direction	= assert(get(d, "direction"), res.direction);		
		res.angleInnerCone	= assert(get(d, "angleInnerCone"), res.angleInnerCone);
		res.angleOuterCone	= assert(get(d, "angleOuterCone"), res.angleOuterCone);
		return res;
	}
	
	/**
	 * Parses a animation from the file.
	 * @param	p_material
	 * @return
	 */
	private function ParseAnimationClip(p_clip:Dynamic):JsonAnimationClip
	{
		var d : Dynamic  	  = p_clip;
		var a : JsonAnimationClip = new JsonAnimationClip();
		
		a.name		= assert(get(d, "name"), a.name);
		a.fps 		= assert(get(d, "tickspersecond"), 0);
		a.duration  = assert(get(d, "duration"), 0);
		
		var cl : Array<Dynamic> = assert(get(d, "channels"), []);
		for (i in 0...cl.length)
		{
			var td : Dynamic = cl[i];
			var t  : JsonClipTrack = new JsonClipTrack();
			t.name = assert(get(td, "name"), 		t.name);
			t.pre  = Std.int(assert(get(td, "prestate"), 	t.pre));
			t.post = Std.int(assert(get(td, "poststate"),   t.post));
			
			var kl : Array<Dynamic>;
			var fl : Array<JsonTrackFrame>;
			
			kl = assert(get(td, "positionkeys"), []); fl = t.position;
			for (j in 0...kl.length) { var t : JsonTrackFrame = new JsonTrackFrame(); t.time = kl[j][0]; t.value = kl[j][1]; fl.push(t); }
			
			kl = assert(get(td, "rotationkeys"), []); fl = t.rotation;
			for (j in 0...kl.length) { var t : JsonTrackFrame = new JsonTrackFrame(); t.time = kl[j][0]; t.value = kl[j][1]; fl.push(t); }
			
			kl = assert(get(td, "scalingkeys"), []); fl = t.scale;
			for (j in 0...kl.length) { var t : JsonTrackFrame = new JsonTrackFrame(); t.time = kl[j][0]; t.value = kl[j][1]; fl.push(t); }
			
			a.tracks.push(t);			
		}
		return a;
	}
	
	/**
	 * Parses a material from the file.
	 * @param	p_material
	 * @return
	 */
	private function ParseMaterial(p_material:Dynamic):JsonMaterial
	{
		var d : Dynamic  	 = p_material;
		var m : JsonMaterial = new JsonMaterial();
		
		var pl : Array<Dynamic> = assert(get(d, "properties"), []);
		for (i in 0...pl.length)
		{
			var pd : Dynamic = pl[i];
			var p  : JsonMaterialProperty = new JsonMaterialProperty();
			p.key 		= assert(get(pd, "key"), p.key);
			p.semantic  = assert(get(pd, "semantic"), p.semantic);
			p.index  	= assert(get(pd, "index"), p.index);
			p.type  	= assert(get(pd, "type"), p.type);
			p.value		= assert(get(pd, "value"), [0]);
			m.properties.push(p);
		}
		return m;
	}
	
	
	/**
	 * Parses a mesh from the file.
	 * @param	p_mesh
	 * @return
	 */
	private function ParseMesh(p_mesh:Dynamic):JsonMesh
	{
		var d : Dynamic  = p_mesh;
		var m : JsonMesh = new JsonMesh();
		
		m.name 	 	 = assert(get(d, "name"), "");
		m.material   = assert(get(d, "materialindex"),   0);
		m.primitive  = assert(get(d, "primitivetypes"),  0);
		m.vertex 	 = assert(get(d, "vertices"), 		[]);
		m.normal 	 = assert(get(d, "normals"), 		[]);
		m.tangent 	 = assert(get(d, "tangents"), 		[]);
		m.binormal 	 = assert(get(d, "bitangents"),		[]);
		m.uvcount	 = assert(get(d, "numuvcomponents"),  0);		
		m.uv	 	 = assert(get(d, "texturecoords"),  []);
		var jl : Array<Dynamic> = assert(get(d, "bones"),  []);
		for (i in 0...jl.length)
		{
			var it : Dynamic = jl[i];
			var jj : JsonJoint = new JsonJoint();
			jj.name 	= assert(get(it, "name"), jj.name);
			jj.bind 	= assert(get(it, "offsetmatrix"), jj.bind);
			jj.weight 	= assert(get(it, "weights"), jj.weight);
			m.joint.push(jj);
		}
		m.topology = assert(get(d, "faces"),  []);
		
		return m;
	}
	
	/**
	 * Process a json node.
	 * @param	p_parent
	 * @param	p_node
	 */
	private function ParseNode(p_parent:JsonNode, p_node:Dynamic):JsonNode
	{
		var n : JsonNode = new JsonNode();				
		n.parent 		 = p_parent;		
		n.name 			 = assert(get(p_node, "name"), "");
		n.transform 	 = assert(get(p_node, "transformation"), [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]);
		n.meshes	 	 = assert(get(p_node, "meshes"),[]);
		if (n.parent != null) n.parent.children.push(n);		
		var cl : Array<Dynamic> = assert(get(p_node, "children"), []);		
		for (i in 0...cl.length) { ParseNode(n, cl[i]); }		
		return n;
		
	}
	
	/**
	 * 
	 * @param	t
	 * @param	cb
	 */
	private function Traverse(p:Dynamic,t:Dynamic, cb:Dynamic->Dynamic->String->Dynamic->Bool):Void
	{
		var kl : Array<String> = Reflect.fields(t);
		for (f in kl)
		{
			var v : Dynamic = get(t, f);
			var res : Bool  = cb(p, t, f, v);
			if (!res) continue;
			if (Std.is(v, Float))   continue;
			if (Std.is(v, String))  continue;
			if (Std.is(v, Array)) 	continue;
			Traverse(t, v, cb);
		}		
	}
	
	private function get(t:Dynamic, f:String):Dynamic { return Reflect.getProperty(t, f); }
}



class JsonNode
{
	public var parent 	 : JsonNode;
	public var name   	 : String;
	public var transform : Array<Float32>;
	public var children  : Array<JsonNode>;
	public var meshes	 : Array<Int>;
	
	public function new()
	{
		name 		= "";
		transform   = [];
		children	= [];
		meshes 		= [];
	}
}

class JsonMeshPrimitive
{	 
	static public var Point 	:Int = 0x1;
	static public var Line 		:Int = 0x2;
	static public var Triangle 	:Int = 0x4;
	static public var Polygon 	:Int = 0x8;
}



class JsonMesh
{
	public var name			: String;
	public var material		: Int;
	public var primitive	: Int;
	public var vertex	 	: Array<Float32>;
	public var normal	 	: Array<Float32>;
	public var tangent	 	: Array<Float32>;
	public var binormal	 	: Array<Float32>;
	public var uvcount	 	: Int;
	public var uv		 	: Array<Array<Float32>>;
	public var joint		: Array<JsonJoint>;
	public var topology		: Array<Array<Int>>;
	
	public function new():Void
	{
		name 	  = "";
		material  = -1;
		primitive = -1;		
		vertex		= [];
		normal		= [];
		uv			= [];
		uvcount		= 0;
		joint		= [];
		topology    = [];
	}
}

class JsonJoint
{
	public var name 	: String;
	public var bind 	: Array<Float32>;
	public var weight   : Array<Array<Float32>>;
		
	public function new()
	{
		name 	= "";
		bind 	= [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];
		weight 	= [];		
	}
	
	
}

class JsonMaterial
{
	public var properties:Array<JsonMaterialProperty>;
	
	public function new()
	{
		properties = [];
	}	
}

class JsonMaterialPropertyType
{
	static public var Name					: String = "?mat.name";
	static public var BlendMode 			: String = "$mat.blend";
	static public var BumpScale 			: String = "$mat.bumpscaling";
	static public var AmbientColor 			: String = "$clr.ambient";
	static public var DiffuseColor 			: String = "$clr.diffuse";
	static public var EmissiveColor 		: String = "$clr.emissive";
	static public var ReflectiveColor 		: String = "$clr.reflective";
	static public var SpecularColor 		: String = "$clr.specular";
	static public var TransparentColor 		: String = "$clr.transparent";
	static public var EnableWireFrame 		: String = "$mat.wireframe";
	static public var BackgroundImage 		: String = "?bg.global";
	static public var Opacity 				: String = "$mat.opacity";
	static public var Reflectivity 			: String = "$mat.reflectivity";
	static public var Refracti 				: String = "$mat.refracti";
	static public var ShadingModel 			: String = "$mat.shadingm";
	static public var Shininess 			: String = "$mat.shininess";
	static public var ShininessStrength 	: String = "$mat.shinpercent";
	static public var TwoSided 				: String = "$mat.twosided";
	static public var TextureFile			: String = "$tex.file";
	static public var TextureUVSrc			: String = "$tex.uvwsrc";
	static public var TextureOp				: String = "$tex.op";
	static public var TextureMapping		: String = "$tex.mapping";
	static public var TextureBlend			: String = "$tex.blend";
	static public var TextureWrapX			: String = "$tex.mapmodeu";
	static public var TextureWrapY			: String = "$tex.mapmodev";
	static public var TextureAxis			: String = "$tex.mapaxis";
	static public var UVTransform			: String = "$tex.uvtrafo";
	static public var TextureFlags			: String = "$tex.flags";
	
}

class JsonMaterialBlendMode
{
	static public var Transparent 	:Int = 0x0;
	static public var Additive 		:Int = 0x1;
}

class JsonMaterialShadingMode
{
	  static public var Flat 		 :Int = 0x1;
	  static public var Gouraud 	 :Int = 0x2;
	  static public var Phong 		 :Int = 0x3;
	  static public var Blinn 		 :Int = 0x4;	  
	  static public var Toon 		 :Int = 0x5;
	  static public var OrenNayar 	 :Int = 0x6; 
	  static public var Minnaert 	 :Int = 0x7;
	  static public var CookTorrance :Int = 0x8; 
	  static public var NoShading 	 :Int = 0x9;
	  static public var Fresnes 	 :Int = 0xa; 	
}

class JsonMaterialTextureFlag
{
	static public var Invert :Int = 0x1;
	static public var RGBA 	 :Int = 0x2;
	static public var RGB 	 :Int = 0x4;
}

class JsonMaterialTextureWrap
{
	static public var Wrap 			:Int = 0x0;
	static public var Clamp 		:Int = 0x1;
	static public var Decal 		:Int = 0x3;
	static public var Mirror 		:Int = 0x2; 
}

class JsonMaterialTextureMap
{
	static public var UV 			: Int	= 0x0;
	static public var Sphere 		: Int	= 0x1;
	static public var Cylinder 		: Int	= 0x2;
	static public var Box 			: Int	= 0x3;
	static public var Plane 		: Int	= 0x4;
	static public var Other 		: Int	= 0x5;
}

class JsonMaterialTextureType
{
	static public var None 				:Int		= 0x0;
	static public var Diffuse 			:Int		= 0x1;
	static public var Specular 			:Int		= 0x2;
	static public var Ambient 			:Int		= 0x3; 
	static public var Emissive 			:Int		= 0x4;
	static public var Height 			:Int		= 0x5;
	static public var Normals 			:Int		= 0x6;
	static public var Shininess 		:Int		= 0x7; 
	static public var Opacity 			:Int		= 0x8;
	static public var Displacement 		:Int		= 0x9; 
	static public var Lightmap 			:Int		= 0xA;
	static public var Reflection 		:Int		= 0xB; 
	static public var Unknown 			:Int		= 0xC; 
}

class JsonMaterialProperty
{
	public var key		: String;
	public var semantic	: Int;
	public var index	: Int;
	public var type		: Int;
	public var value	: Dynamic;
	
	public function new()
	{
		key			= "";
		semantic 	= 0;
		index 		= 0;
		type 		= 0;
		value 		= null;
	}	
}

class JsonAnimationClip
{
	public var name 	: String;
	public var fps		: Int;
	public var duration	: Int;
	public var tracks	: Array<JsonClipTrack>;
	
	public function new()
	{
		name 	 = "";
		fps  	 = 0;
		duration = 0;
		tracks   = [];
	}
	
}

class JsonClipTrackWrap
{
	static public var Default  : Int = 0x0;
	static public var Constant : Int = 0x1;
	static public var Linear   : Int = 0x2;
	static public var Repeat   : Int = 0x3;
}

class JsonClipTrack
{
	public var name 	: String;
	/**
	 * JsonClipTrackWrap
	 */
	public var pre  	: Int;
	/**
	 * JsonClipTrackWrap
	 */
	public var post  	: Int;
	public var position : Array<JsonTrackFrame>;
	public var rotation : Array<JsonTrackFrame>;
	public var scale 	: Array<JsonTrackFrame>;
	
	public function new()
	{
		name = "";
		pre  = 0;
		post = 0;
		position = [];
		rotation = [];
		scale	 = [];
	}
	
}

class JsonTrackFrame
{
	public var time 	: Int;
	public var value	: Array<Float32>;
	
	public function new()
	{
		time 	 = 0;
		value	 = [];
	}
	
}

class JsonLightType
{
	static public var Undefined 	= 0x0;
	static public var Directional 	= 0x1;
	static public var Point 		= 0x2;
	static public var Spot 			= 0x3;  
}

class JsonLight
{
	public var name 			: String;
	/**
	 * JsonLightType
	 */
	public var type 			: Int;
	public var constant 		: Float32;
	public var linear 			: Float32;
	public var quadratic 		: Float32;
	public var angleInnerCone 	: Float32;
	public var angleOuterCone 	: Float32;	
	public var color			: Array<Float32>;
	public var specular			: Array<Float32>;
	public var ambient			: Array<Float32>;
	public var position			: Array<Float32>;
	public var direction		: Array<Float32>;
	
	public function new()
	{
		name = "";
		type = 0;
		constant  = 0.0;
		linear    = 0.0;
		quadratic = 0.0;
		angleInnerCone = 0.0;
		angleOuterCone = 0.0;
		color	  = [1, 1, 1];
		specular  = [1, 1, 1];
		ambient   = [1, 1, 1];
		position  = [0, 0, 0];
		direction = [0, 0, 1];
	}	
}


class JsonCamera
{
	public var name 	: String;
	public var aspect	: Float32;
	public var near		: Float32;
	public var far		: Float32;
	public var hfov		: Float32;
	public var up		: Array<Float32>;
	public var lookAt	: Array<Float32>;
	
	public function new()
	{
		name 	= "";
		aspect  = 1.0;
		near    = 0.1;
		far     = 100.0;
		hfov 	= 0.77;
		up		= [0, 1, 0];
		lookAt  = [0, 0, -1];
	}
	
}

class JsonTexture
{
	public var width  : Int;
	public var height : Int;
	public var format : String;
	//ARGB8888 or file
	public var data	  : Buffer;
	
	public var compressed(get, never):Bool;
	private function get_compressed():Bool { return (width > 0) && (height <= 0); }
	
	public function new()
	{
		width  = 0;
		height = 0;
		format = "";
		data   = new Buffer(0);
	}
	
}

class JsonMeta
{
	public var format  : String;
	public var version : Int;	
	public function new() { format = ""; version = 0; }
}
