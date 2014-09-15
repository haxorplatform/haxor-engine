package haxor.io.file;
import haxe.Json;
import haxor.component.Component;
import haxor.component.DataComponent;
import haxor.component.MeshRenderer;
import haxor.component.PointLight;
import haxor.component.SkinnedMeshRenderer;
import haxor.component.Transform;
import haxor.core.Console;
import haxor.core.Entity;
import haxor.core.Resource;
import haxor.graphics.material.Material;
import haxor.graphics.mesh.MeshLayout.Mesh3;
import haxor.graphics.mesh.MeshLayout.SkinnedMesh3;
import haxor.graphics.texture.Bitmap;
import haxor.math.Color;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.platform.Types.Float32;

/**
 * Class that describes a Collada file. After parsing it will contain internal ColladaClasses that describes the Collada content.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class ColladaFile extends AssetXML
{
	static private function GenerateTriangles(p_type : String, p_indexes : Array< Array< Array<Int> > >, p_vcount : Array<Int>):Array< Array<Int> >
	{
		var triangles : Array<Array<Int>> = [];
		switch(p_type)
		{
			case "triangles": triangles = p_indexes.length <= 0 ? [] : p_indexes[0];			
			case "polygons":
				for (i in 0...p_indexes.length)
				{
					var tris : Array< Array<Int> > = TriangulatePolygon(p_indexes[i], p_indexes[i].length);
					while (tris.length > 0) triangles.push(tris.shift());				
				}			
			case "polylist":
				var k : Int = 0;
				for (i in 0...p_vcount.length)
				{
					var o : Int = p_vcount[i];				
					var tris : Array< Array<Int> > = TriangulatePolygon(p_indexes[0], o,k);
					while (tris.length > 0) triangles.push(tris.shift());				
					k += o;
				}
		}		
		return triangles;
	}
	
	static private function TriangulatePolygon(t : Array< Array<Int> >, c : Int,o : Int = 0) : Array< Array<Int> >
	{
		var i : Int = 0;
		var i0 : Int = 0;
		var i1 : Int = 1;
		var i2 : Int = 2;
		var res : Array< Array<Int> > = [];
		while (i2 < c)
		{			
			res.push(t[i0+o].copy());		res.push(t[i1+o].copy());	res.push(t[i2+o].copy());
			i1++; i2++;			
		}
		return res;
	}
	
	/**
	 * XMLns data.
	 */
	public var xmlns : String;
	
	/**
	 * Collada Version.
	 */
	public var version : String;
	
	/**
	 * Asset Data
	 */
	public var data 		: ColladaAssetData;
	
	/**
	 * Geometries Library
	 */
	public var geometries   : Array<ColladaGeometry>;
	
	/**
	 * Images Library
	 */
	public var images	   : Array<ColladaImage>;
	
	/**
	 * Controllers Library
	 */
	public var controllers : Array<ColladaController>;
	
	/**
	 * Materials Library.
	 */
	public var materials   : Array<ColladaMaterial>;
	
	/**
	 * Lights Library.
	 */
	public var lights		: Array<ColladaLight>;
	
	/**
	 * Animations Library.
	 */
	public var animations	: Array<ColladaAnimation>;
	
	/**
	 * Scenes Library.
	 */
	public var scene	   : ColladaVisualScene;

	/**
	 * Internal id.
	 */
	private var m_id : Int;
	
	public function new(p_name:String,p_src : String) 
	{	
		xmlns 			= "";
		version 		= "";		
		data 			= new ColladaAssetData();		
		geometries 		= [];
		images			= [];
		controllers		= [];
		materials		= [];
		animations		= [];
		lights			= [];
		scene			= null;
		m_id			= Std.int(Math.random() * 0xffffff);
		
		super(p_name, p_src);
		
		
	}
	
	override function get_asset():Entity
	{
		var re : Entity = new Entity();	
		re.name = "collada_asset";
		if (scene == null)
		{
			Console.LogError("ColladaFile> Trying to get asset of NULL scene.");
			return re;
		}		
		
		if (scene.name != "") re.name = scene.name; else
		if (scene.id != "")   re.name = scene.id;
		
		var hm : Map<ColladaNode,Entity> 			= new Map<ColladaNode,Entity>();
		var cm : Map<Transform,ColladaController>	= new Map<Transform,ColladaController>();
		var mm : Map<ColladaMaterial,Material>		= new Map<ColladaMaterial,Material>();
		
		var joint_transforms  : Array<Transform> 			= [];
		var joint_nodes  	  : Array<ColladaNode> 			= [];				
		var skinned_meshes 	  : Array<SkinnedMeshRenderer>  = [];
		
		for (i in 0...materials.length)
		{
			var m : ColladaMaterial = materials[i];
			
			var mn : String = m.name;
			for(i in 0...10) mn = StringTools.replace(mn, "_"+i, "");
			mn = StringTools.replace(mn, "_", "/");
			var mat : Material = Asset.Get(mn);
			
			if (mat == null)
			{
				mat = new Material();
				mat.name = mn;
				mat.shader = Asset.Get("haxor/unlit/FlatTexture");
				Asset.Add(mn, mat);
			}			
			mm.set(m, mat);
		}
		
		scene.Traverse(function(n : ColladaNode):Void
		{						
			var pe : Entity = n.parent == null ? re : (hm.exists(n.parent) ? hm.get(n.parent) : re);			
			var ne : Entity = null;			
			if (n.name == "EnvironmentAmbientLight") return;
			ne 					= new Entity();
			ne.name 			= "node" + ne.uid;	
			if (n.sid  != "") ne.name = n.sid;  else
			if (n.id   != "") ne.name = n.id;   else			
			if (n.name != "") ne.name = n.name;			
			if (n.type == "joint")
			{				
				joint_transforms.push(ne.transform);
				joint_nodes.push(n);				
			}			
			ne.transform.parent = pe.transform;						
			ne.transform.localPosition	= n.position;
			ne.transform.localRotation 	= n.rotation;			
			ne.transform.localScale 	= n.scale;
			
			if (n.data != "")
			{
				var ad : DataComponent = ne.AddComponent(DataComponent);
				try
				{
					ad.data = Json.parse(n.data);
				}
				catch(err:Dynamic) { }
				/*
				var tk : Array<String> = n.data.split(";");
				for (i in 0...tk.length)
				{
					var dp : Array<String> = StringTools.trim(tk[i]).split("=");
					if (dp.length != 2) continue;
					var adk  : String = StringTools.trim(dp[0]);
					var adv  : String = StringTools.trim(dp[1]);
					
					var ktk : Array<String> = adk.split(".");
					
					var o : Map<String,Dynamic> = ad.data;
					for (i in 0...ktk.length)
					{
						var prop : String = StringTools.trim(ktk[i]);
						if (i == (ktk.length - 1))
						{
							o.set(prop, adv);						
							if (adv == "true")  o.set(prop, true); else
							if (adv == "false") o.set(prop, false); else
							{							
								var nchar : String = "0123456789., ";
								var is_number : Bool = true;
								for (i in 0...adv.length) if (nchar.indexOf(adv.charAt(i)) < 0) { is_number = false; break; }								
								if (is_number)
								{
									var n : Float = Std.parseFloat(adv);
									o.set(prop, n);
								}
								else
								{
									o.set(prop, adv);					
								}
							}							
						}
						else
						{
							var nprop : Dynamic = o.get(prop);
							if (nprop == null)
							{
								//trace("created: " + prop + " @ "+adk);
								o.set(prop, new Map<String,Dynamic>());
								//Reflect.setProperty(o, prop, nprop = { } );
							}
							o = o.get(prop);
						}
					}										
				}
				//*/
				
			}
			
			hm.set(n,ne);			
			for (i in 0...n.instances.length)
			{
				var ci : ColladaInstance 	= n.instances[i];
				var mr : MeshRenderer 		= null;
				var cmat : ColladaMaterial  = null;				
				var cg : ColladaGeometry 	= null;
				var cc : ColladaController  = null;
				var cg_target : String 		= "";	
				
				switch(ci.type)
				{
					case "light":
						
						var cl : ColladaLight = FindLightById(ci.target);
						
						if (cl == null) continue;
						
						switch(cl.type)
						{
							case "ambient":
							case "point":
								var pl : PointLight = ne.AddComponent(PointLight);								
								pl.color.SetColor(cl.color);
								pl.intensity = cl.intensity;
								pl.radius    = cl.radius*2.0;
								pl.atten     = cl.atten;
								
							case "directional":
								//var dl : DirectionalLight = ne.AddComponent(DirectionalLight);
								//dl.color.Set4(cl.color);
								//dl.intensity = cl.intensity;
						}
						
						continue;
						
						
					case "geometry": 	cg_target = ci.target;						
					case "controller":					
						cc = FindControllerById(ci.target);						
						if (cc != null)
						{
							cm.set(ne.transform, cc);
							cg_target = cc.source;
						}	
						
					
				}				
				
				cg   = FindGeometryById(cg_target);
				if (cg != null)
				{
					for (i in 0...cg.mesh.primitives.length)
					{							
						var mn : String = cg.mesh.primitives[i].material;
						cmat = FindMaterialById(mn);
						
						mr = CreateMeshRenderer(ne, cg_target, cg.mesh.primitives[i], cc == null ? MeshRenderer : SkinnedMeshRenderer, cc);
						
						if (cc != null) skinned_meshes.push(cast mr);
						if (cmat != null)
						{
							mr.material = mm.exists(cmat) ? mm.get(cmat) : mr.material;							
						}
						else //Fail-safe because sometimes '_1' appears and screw everything
						{
							for(i in 0...10) mn = StringTools.replace(mn, "_"+i, ""); //Maybe 10 checks will hold?
							mn = StringTools.replace(mn, "_", "/");
							var mat : Material = Asset.Get(mn);
							mr.material = mat;
						}
					}					
				}				
			}			
		});
		
		for (i in 0...skinned_meshes.length)
		{
			var skr : SkinnedMeshRenderer = skinned_meshes[i];
			var cc	: ColladaController   = cm.exists(skr.transform) ? cm.get(skr.transform) : null;
			if (cc == null) continue;				
			skr.joints  = [];	
			//skr.jointsm = [];
			for (j in 0...cc.joints.length)				
			for (k in 0...joint_transforms.length)
			{
				if (joint_transforms[k].name == cc.joints[j])
				{
					//trace(joint_transforms[k].name + " " + j);
					//skr.jointsm.push(joint_nodes[k].world);
					skr.joints.push(joint_transforms[k]);				
				}
			}
			//skr.ApplyBinds();
		}	
		
		var nit : Iterator<ColladaNode> = hm.keys();
		while (nit.hasNext())
		{
			var n : ColladaNode = nit.next();
			var e : Entity = hm.get(n);
			if (e == re) continue;
			e.name = n.name;
		}
		AddAnimations(re);		
		if (data.axis == "z_up")
		{			
			re.transform.rotation = Quaternion.FromAxisAngle(Vector3.right, -90.0);
		}
		return re;
	}
	
	/**
	 * Fills the Animation component of the informed Entity with the animations inside this collada.
	 * If the component does not exists, a new one will be created.
	 * @param	p_entity
	 * @param	p_exact
	 */
	public function AddAnimations(p_entity : Entity,p_exact : Bool=true):Void
	{
		/*
		if (animations.length <= 0) return;
		var re : Entity   = p_entity;
		var a : Animation = re.animation;
		if (a == null) a = cast re.AddComponent(Animation);
		
		for (i in 0...animations.length)
		{
			var ca : ColladaAnimation = animations[i];
			var clip : AnimationClip = new AnimationClip();
			clip.name = ca.id == "" ? (ca.name == "" ? "clip" + i : ca.name) : ca.id;			
			
			for (j in 0...ca.channels.length)
			{
				var cch : ColladaAnimationChannel = ca.channels[j];
				var src_node   : String = cch.target.split("/")[0];
				src_node = StringTools.replace(src_node, "node-", "");
				var src_target : String = cch.target.split("/")[1];				
				var nt :Transform = re.transform.Search(src_node, p_exact);
				//if (nt != null) trace("clip node: " + src_node + " " + nt.name);
				//var cn : ColladaNode = FindNodeById(src_node);				
				//if (cn == null){ continue; }				
				if (nt == null) continue;
				
				var n : Entity = nt.entity;
				//hm.get(cn);
				
				switch(src_target)
				{
					case "matrix":
						var position_track  : ClipTrack = clip.Add(n.transform, "position");							
						var rotation_track  : ClipTrack = clip.Add(n.transform, "rotation");
						//var scale_track 	: ClipTrack = clip.Add(n.transform, "scale");
						for (k in 0...cch.keyframes.length)
						{
							var kf : ColladaAnimationKeyFrame = cch.keyframes[k];
							var m : Matrix4 = Matrix4.FromArray(kf.values);
							var td : Array<Dynamic> = m.transform;
							position_track.Add(kf.time, td[0]);
							rotation_track.Add(kf.time, td[1]);
							//scale_track.Add(kf.time, td[2]);
						}
						
				}
			}
			
			a.Add(clip);				
		}	
		//*/
	}
	
	private function CreateMeshRenderer(e : Entity,msh : String, cp : ColladaPrimitive, t : Class<Component>, cc : ColladaController=null) : MeshRenderer
	{		
		var r 	: MeshRenderer = cast e.AddComponent(t);
		
		var mid : String = msh+"_"+m_id;
		
		var m 	: Mesh3 = Asset.Get(mid);
		
		if (m != null)
		{
			r.mesh = m;
			return r;
		}
		
		var mv : Array<Vector3> 	= cp.GetTriangulatedVectorArray("vertex");		
		var mn : Array<Vector3> 	= cp.GetTriangulatedVectorArray("normal");		
		var mc : Array<Color>   	= cp.GetTriangulatedVectorArray("color");
		var muv0 : Array<Vector3> 	= cp.GetTriangulatedVectorArray("texcoord", 0);
		var muv1 : Array<Vector3> 	= cp.GetTriangulatedVectorArray("texcoord", 1);
		var mbn  : Array<Vector3> 	= cp.GetTriangulatedVectorArray("texbinormal");
		var mtg  : Array<Vector3> 	= cp.GetTriangulatedVectorArray("textangent");
		
		var is_skinned : Bool = Std.is(r, SkinnedMeshRenderer);
		
		m 		= is_skinned ? (new SkinnedMesh3()) : (new Mesh3());		
		m.name  = mid;
		
		Asset.Add(mid, m);
		
		if(mc.length>0)   m.color    = mc;
		if(muv0.length>0) m.uv0      = muv0;
		if(muv1.length>0) m.uv1      = muv1;
		
		if(is_skinned)
		{
			if (cc != null)
			{			
				cc.GenerateBonesAndWeights();
				
				var skm : SkinnedMesh3 = cast m;
				var mvw	: Array<Vector4> = cc.GetTriangulatedWeights(cp);
				var mbi	: Array<Vector4> = cc.GetTriangulatedBones(cp);				
				var mbm : Array<Matrix4> = cc.GetBinds();				
				skm.binds  = mbm;
				skm.weight = mvw; 
				skm.bone   = mbi;				
				var bsm : Matrix4 = cc.GetBSM();
				
				for (i in 0...mv.length)  { mv[i]  = (bsm.Transform3x4(mv[i].clone));   }
				for (i in 0...mn.length)  { mn[i]  = (bsm.Transform3x3(mn[i].clone));  }
				for (i in 0...mbn.length) { mbn[i] = (bsm.Transform3x3(mbn[i].clone)); }
				for (i in 0...mtg.length) { mtg[i] = (bsm.Transform3x3(mtg[i].clone)); }
				//*/
			}
		}			
		if (mv.length > 0)   m.vertex   = mv;
		if (mn.length > 0)   m.normal   = mn;
		if (mbn.length > 0)  m.binormal = mbn;
		if (mtg.length > 0)  m.tangent  = mtg;	
		
		
		
		m.GenerateBounds();		
		r.mesh = m;		
		return r;
	}
	
	public function FindLightById(p_id : String):ColladaLight 	{ for (i in 0...lights.length)  if (lights[i].id == p_id)  return lights[i];  return null; }
	
	public function FindGeometryById(p_id : String):ColladaGeometry 	{ for (i in 0...geometries.length)  if (geometries[i].id == p_id)  return geometries[i];  return null; }
	
	public function FindControllerById(p_id : String):ColladaController { for (i in 0...controllers.length) if (controllers[i].id == p_id) return controllers[i]; return null; }
	
	public function FindNodeById(p_id : String):ColladaNode 
	{ 
		var res : ColladaNode = null; 
		scene.Traverse(function(it : ColladaNode):Void 
		{ 
			if (it.id == p_id) { res = it; } 			
		});
		return res; 
	}
	
	public function FindMaterialById(p_id : String):ColladaMaterial
	{
		for (i in 0...materials.length)
		{
			if (materials[i].id == p_id)   return materials[i];
			else
			if (materials[i].name == p_id) return materials[i];
		}
		return null;
	}
	
	override private function Parse(n : Xml):Void
	{
		switch(n.nodeName)
		{
			case "COLLADA":
				xmlns   = _a(n, "xmlns", "");
				version = _a(n, "version", "0.0");
				
			case "asset":
				data.author 			= _p(n, "contributor.author.$text", "none");
				data.tool				= _p(n, "contributor.authoring_tool.$text", "none");
				data.source			= _p(n, "contributor.source_data.$text", "none");
				data.axis    			= _p(n, "up_axis.$text", "y_up").toLowerCase();
				data.creation			= _p(n, "created.$text", "00/00/00");
				data.modification		= _p(n, "modified.$text", "00/00/00");
				data.unitName			= _p(n, "unit.@name", "none");
				data.unitValue			= Std.parseFloat(_p(n, "unit.@meter", "0.0"));				
				
			case "library_effects":		//Will not use for now				
			case "library_materials":	ParseMaterialLibrary(n);
			case "scene":				//Will not use for now
				
			case "library_geometries": 		ParseGeometryLibrary(n);
			case "library_controllers":		ParseControllerLibrary(n);
			case "library_images":			ParseImageLibrary(n);
			case "library_visual_scenes":	ParseSceneLibrary(n);
			case "library_animations":		ParseAnimationLibrary(n);
			case "library_lights":			ParseLightLibrary(n);
			
		}
	}
	
	private function ParseLightLibrary(n : Xml):Void
	{
		var it : Iterator<Xml> = n.elementsNamed("light");
		var l : ColladaLight;
		var lit : Iterator<Xml>;
		var ln  : Xml;
		while (it.hasNext())
		{
			n = it.next();			
			l = new ColladaLight();
			l.id    = _p(n, "@id",   "light" + lights.length);
			l.name  = _p(n, "@name", l.id);
			
			lights.push(l);
			
			lit 	= n.elementsNamed("technique_common");			
			if (!lit.hasNext()) continue;			lit = lit.next().elements();			
			if (!lit.hasNext()) continue;			ln = lit.next();
			
			l.type = ln.nodeName.toLowerCase();
			
			var ca : Array<Float32> = [1, 1, 1, 1];
			switch(l.type)
			{
				case "point":			ca = _f32a(_p(ln, "color.$text", ""));					
				case "ambient":			ca = _f32a(_p(ln, "color.$text", ""));
				case "directional":		ca = _f32a(_p(ln, "color.$text", ""));
			}
			
			l.color.Set(ca[0], ca[1], ca[2], ca.length >= 4 ? ca[3] : 1.0);
			
			lit 	= n.elementsNamed("extra");
			if (!lit.hasNext()) continue;			lit = lit.next().elementsNamed("technique");
			if (!lit.hasNext()) continue;			lit = lit.next().elementsNamed("max_light");
			if (!lit.hasNext()) continue; 			ln = lit.next();
			
			switch(l.type)
			{
				case "point":			
					l.radius 	= Std.parseFloat(_p(ln, "decay_radius.$text", "1.0"));
					l.intensity = Std.parseFloat(_p(ln, "multiplier.$text", "1.0"));
					var atten_type : Int = Std.parseInt(_p(ln, "decay_type.$text", "1.0"));					
					l.atten = atten_type == 0 ? 0.0 : (atten_type == 1 ? 1.0 : 2.0);
					
				case "ambient":				
				case "directional":					
					l.intensity = Std.parseFloat(_p(ln, "multiplier.$text", "1.0"));
			}
			
			//trace(l.type + " " + l.name + " " + l.radius + " " + l.atten + " " + l.intensity);
		}
	}
	
	private function ParseAnimationLibrary(n : Xml):Void
	{
		var it : Iterator<Xml> = n.elementsNamed("animation");
		var anim_id : Int = 0;
		while (it.hasNext())
		{
			n = it.next();
			if (n.elementsNamed("animation").hasNext()) n = n.elementsNamed("animation").next();
			
			var ca : ColladaAnimation = new ColladaAnimation();
			
			ca.id   = _a(n, "id", "");
			ca.id   = ca.id == "" ? "Clip" + (anim_id++) : ca.id;
			ca.name = _a(n, "name", ca.id);
			
			var source_iterator  : Iterator<Xml> = n.elementsNamed("source");
			var sampler_iterator : Iterator<Xml> = n.elementsNamed("sampler");			
			var source_list		 : Array<Xml>    = [];
			var sampler_list	 : Array<Xml>    = [];
			
			while (source_iterator.hasNext())  source_list.push(source_iterator.next());
			while (sampler_iterator.hasNext()) sampler_list.push(sampler_iterator.next());
			
			var channel_list : Iterator<Xml> = n.elementsNamed("channel");
			
			
			while (channel_list.hasNext())
			{
				var chn : Xml = channel_list.next();
				var cch : ColladaAnimationChannel = new ColladaAnimationChannel();
				cch.source = _a(chn, "source", "").substr(1);
				cch.target = _a(chn, "target", "");
				
				for (i in 0...sampler_list.length)
				{
					var sampler_id : String = _a(sampler_list[i], "id", "");
					if (sampler_id != cch.source) continue;
					var input_iterator : Iterator<Xml> = sampler_list[i].elementsNamed("input");
					var keyframe_time_source : String = "";
					var keyframe_value_source : String = "";
					
					while (input_iterator.hasNext())
					{
						var chsi : Xml = input_iterator.next();
						switch(_a(chsi, "semantic", "").toLowerCase())
						{
							case "input":	keyframe_time_source = _a(chsi, "source", "").substr(1);								
							case "output":  keyframe_value_source = _a(chsi, "source", "").substr(1);								
						}						
					}
					
					if (keyframe_time_source  == "") continue;
					if (keyframe_value_source == "") continue;
					
					var kf_time_node  : Xml=null;
					var kf_value_node : Xml=null;
					
					for (j in 0...source_list.length)
					{
						var sn : Xml = source_list[j];
						if (_a(sn, "id", "") == keyframe_time_source)  kf_time_node  = sn;
						if (_a(sn, "id", "") == keyframe_value_source) kf_value_node = sn;
					}
					
					if (kf_time_node  == null) continue;
					if (kf_value_node == null) continue;
					
					var kf_time_buffer  : Array<Float32>  = _f32a(_p(kf_time_node, "float_array.$text", ""));
					var kf_value_buffer : Array<Float32>  = _f32a(_p(kf_value_node, "float_array.$text", ""));
					var kf_value_stride : Int 			= Std.parseInt(_p(kf_value_node, "technique_common.accessor.@stride", "0")); 
					
					for (j in 0...kf_time_buffer.length)
					{
						var kf : ColladaAnimationKeyFrame = new ColladaAnimationKeyFrame();
						kf.time = kf_time_buffer[j];
						for (k in 0...kf_value_stride)
						{
							kf.values.push(kf_value_buffer.shift());
						}
						cch.keyframes.push(kf);
					}					
				}
				ca.channels.push(cch);
			}			
			animations.push(ca);
		}
		
	}
	
	private function ParseMaterialLibrary(n : Xml):Void
	{		
		var it : Iterator<Xml> = n.elements();		
		while (it.hasNext())
		{
			n = it.next();
			switch(n.nodeName) 
			{
				case "material":
					var mat : ColladaMaterial = new ColladaMaterial();
					mat.id 	 = _a(n, "id", "");
					mat.name = _a(n, "name", "");
					if (mat.id == "") mat.id = mat.name;
					materials.push(mat);
			}			
		}
	}
	
	private function ParseSceneLibrary(n : Xml):Void
	{		
		var it : Iterator<Xml> = n.elements();		
		while (it.hasNext())
		{
			n = it.next();
			switch(n.nodeName) { case "visual_scene": ParseVisualScene(n); }
		}
	}
	
	private function ParseVisualScene(n : Xml):Void
	{
		if (scene != null) return;
		scene 		= new ColladaVisualScene();
		scene.id 	= _a(n, "id", "collada_scene");
		scene.name 	= _a(n, "name", scene.id);
		scene.type	= n.nodeName;		
		TraverseVisualSceneNodes(scene, null, n);
	}
	
	private function TraverseVisualSceneNodes(scn : ColladaVisualScene, p : ColladaNode,n : Xml):Void
	{
		var cn : ColladaNode = null;		
		if (n.nodeName == "node") cn = ParseVisualSceneNode(scn, p, n);		
		var cn_it : Iterator<Xml> = n.elementsNamed("node");
		while (cn_it.hasNext()) TraverseVisualSceneNodes(scn, cn, cn_it.next());		
	}
	
	private function ParseVisualSceneNode(scn : ColladaVisualScene, p : ColladaNode, n : Xml) : ColladaNode
	{
		var cn : ColladaNode = new ColladaNode();
		cn.scene  = scn;
		
		cn.sid 		= _a(n, "sid", "node"+Std.int(Math.random()*0xffffff));
		cn.id 		= _a(n, "id", cn.sid);		
		cn.name 	= _a(n, "name", cn.sid);
		if (cn.sid == "") cn.sid = cn.id;
		cn.type		= _a(n, "type", "NODE").toLowerCase();
		cn.matrix   = _f32a(_p(n, "matrix.$text", "1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1"));
		cn.parent 	= p;
		cn.GenerateTranform();
		
		var iit : Iterator<Xml> = n.elements();
		while (iit.hasNext())
		{
			var nin : Xml = iit.next();
			var ni : ColladaInstance = null;
			switch(nin.nodeName)
			{
				case "instance_geometry":
					ni 			= new ColladaInstance();
					ni.type 	= "geometry";
					ni.target 	= _a(nin, "url", "").substr(1);
					
					
				case "instance_controller":
					ni 			= new ColladaInstance();
					ni.type 	= "controller";
					ni.target 	= _a(nin, "url", "").substr(1);
				
				case "instance_light":
					ni 			= new ColladaInstance();
					ni.type 	= "light";
					ni.target 	= _a(nin, "url", "").substr(1);
				
				case "extra":
					cn.data     = _p(nin, "technique.user_properties.$text", "");
					if (cn.data.indexOf(";") < 0) cn.data = "";
					//if (cn.data != "") trace(cn.sid + " " + cn.data);
					
			}			
			if (ni != null) cn.instances.push(ni);
		}
		
		if (p == null) scn.children.push(cn) else p.children.push(cn);
		return cn;
	}
	
	private function ParseInstanceMaterials(ci : ColladaInstance, n : Xml):Void
	{
		
	}
	
	private function ParseControllerLibrary(n : Xml):Void
	{
		var it : Iterator<Xml> = n.elementsNamed("controller");
		var c : ColladaController = null;		
		while (it.hasNext())
		{
			n = it.next();			
			c 	 		= new ColladaController();
			c.id 		= _a(n, "id", "none");
			c.name  	= _a(n, "name", c.id);			
			ParseController(c, n);
			controllers.push(c);
		}
	}
	
	private function ParseController(c : ColladaController, n : Xml):Void
	{		
		n = n.firstElement();
		if (n == null) return;				
		c.type = n.nodeName == null ? "none" : n.nodeName.toLowerCase();		
		switch(c.type)
		{
			case "skin": 		ParseControllerSkin(c, n);
			case "morph":		//Will not use for now			
		}
	}
	
	private function ParseControllerSkin(c : ColladaController, n : Xml):Void
	{
		c.source 	= _a(n, "source", "").substr(1);
		c.matrix	= _f32a(_p(n, "bind_shape_matrix.$text", ""));
		
		var source  : String = "";
		var sn 		: Xml	 = null;
		
		var jn : Xml = _p(n, "joints") == null ? null : _p(n, "joints").next();
		
		if (jn != null)
		{
			var jn_it : Iterator<Xml> = jn.elementsNamed("input");
			while (jn_it.hasNext())
			{
				var jni : Xml = jn_it.next();
				source = _a(jni, "source", "").substr(1);				
				if (source == "") 	continue;
				sn = _f(n, "source", "id", source);
				if (sn == null) 	continue;
				
				switch(_a(jni, "semantic", "").toLowerCase())
				{
					case "joint": c.joints = StringTools.trim(StringTools.replace(_p(sn, "Name_array.$text", ""),"\n"," ")).split(" ");						
						
					case "inv_bind_matrix": 
						var ml : Array<Float32> = _f32a(_p(sn, "float_array.$text", ""));
						while (ml.length > 0) 
						{
							var mtx : Array<Float32> = []; 
							for (i in 0...16) mtx.push(ml.shift()); 
							c.binds.push(mtx);	
						}					
				}
			}
		}
		
		var vwn : Xml = _p(n, "vertex_weights") == null ? null : _p(n, "vertex_weights").next();		
		if (vwn != null)
		{
			c.inputs  = ParseInputList(n, vwn);
			c.vcount  = _i16a(_p(vwn, "vcount.$text", ""));
			var vwb : String = _p(vwn, "v.$text", "");
			c.indexes = _i16ta(vwb,c.offset);
		}
		
	}
	
	private function ParseImageLibrary(n : Xml):Void
	{
		var it : Iterator<Xml> = n.elementsNamed("image");
		var img : ColladaImage = null;		
		while (it.hasNext())
		{
			n = it.next();			
			img 	 	= new ColladaImage();
			img.id 		= _a(n, "id", "none");
			img.name  	= _a(n, "name", img.id);
			img.format	= _a(n, "format", "");
			img.width	= Std.parseInt(_a(n, "width", "-1"));
			img.height	= Std.parseInt(_a(n, "height", "-1"));
			img.depth	= Std.parseInt(_a(n, "depth", "-1"));
			//img.data	= _i16a(...); //Will not use for now
			images.push(img);
		}
	}
	
	private function ParseGeometryLibrary(n : Xml):Void
	{		
		var it : Iterator<Xml> = n.elementsNamed("geometry");
		var g : ColladaGeometry = null;		
		while (it.hasNext())
		{
			n = it.next();			
			g 	 	= new ColladaGeometry();
			g.id 	= _a(n, "id", "none");
			g.name  = _a(n, "name", "none");			
			ParseGeometry(g, n);						
			geometries.push(g);
		}
	}
	
	private function ParseGeometry(g : ColladaGeometry, n : Xml):Void
	{		
		n = n.firstElement();
		if (n == null) return;		
		g.mesh 		= new ColladaMesh();		
		g.mesh.type = n.nodeName == null ? "none" : n.nodeName.toLowerCase();		
		switch(g.mesh.type)
		{
			case "mesh": 		ParseMesh(g.mesh, n);				
			case "convex_mesh":	//Will not use for now			
			case "spline":		//Will not use for now
		}
	}
	
	private function ParseMesh(m : ColladaMesh, n : Xml):Void
	{
		var it : Iterator<Xml> = n.elements();
		var p  : Xml = n;
		while (it.hasNext())
		{
			n = it.next();			
			if (n.nodeName == "vertices") continue;
			if (n.nodeName == "source")   continue;
			var cp : ColladaPrimitive = new ColladaPrimitive();
			
			cp.type 	 = n.nodeName;			
			cp.material  = _a(n, "material", "");			
			ParsePrimitive(cp, p, n);
			m.primitives.push(cp);
		}
	}
	
	private function ParsePrimitive(cp : ColladaPrimitive, p : Xml, n : Xml):Void
	{
		cp.inputs = ParseInputList(p, n);		
		var p_it  : Iterator<Xml> = n.elementsNamed("p");
		var vc_it : Iterator<Xml> = n.elementsNamed("vcount");		
		if (vc_it.hasNext()) 	
		{ 
			var ncitn : Xml = vc_it.next().firstChild();
			cp.vcount = ncitn == null ? [] : _i16a(ncitn.toString());	
		}
		
		while (p_it.hasNext())
		{ 			
			var vn : Xml = p_it.next();
			var vb  : String = vn.firstChild() != null ? vn.firstChild().toString() : "0";
			var off : Int 	 = cp.offset;			
			var ti : Array< Array<Int> > = _i16ta(vb, off);			
			cp.indexes.push(ti);
		}
		
		
		/*
		switch(cp.type)
		{
			case "lines": 		//Will not use for now
			case "linestrips":  //Will not use for now
			case "trifans":		//Will not use for now
			case "tristrips":	//Will not use for now				
			case "triangles": 
			case "polylist":				
			case "polygons":				
		}
		//*/
	}
	
	private function ParseInputList(p : Xml, n : Xml) : Array<ColladaInput>
	{
		var l : Array<ColladaInput> = [];		
		var it : Iterator<Xml> = n.elementsNamed("input");		
		while (it.hasNext())
		{
			var pi : Xml = it.next();
			var ci : ColladaInput = new ColladaInput();
			var source	 : String = _a(pi, "source", "");			
			ci.semantic	 = _a(pi, "semantic", "").toLowerCase();						
			ci.offset	 = Std.parseInt(_a(pi, "offset", "-1"));			
			ci.set 		 = Std.parseInt(_a(pi, "set", "-1"));
			if (ci.semantic == "joint") { l.push(ci); continue; }
			if (ci.semantic == "vertex")
			{				
				source = _p(p, "vertices.input.@source", "");
			}
			if (source == "") continue;			
			source = source.substr(1);						
			var sn : Xml = _f(p, "source", "id", source);						
			if (sn == null) continue;						
			var stride_str:String = _p(sn, "technique_common.accessor.@stride", "0");			
			ci.stride = Std.parseInt(stride_str);			
			ci.values = _f32a(_p(sn, "float_array.$text", ""));						
			l.push(ci);
		}
		return l;
	}
	
	override private function TraverseStep(n : Xml):Void
	{
		Parse(n);
		var l : Iterator<Xml> = n.elements();		
		while (l.hasNext()) TraverseStep(l.next());		
	}
	
	private function _f32a(v : String) : Array<Float32>
	{
		var l : Array<String> = StringTools.trim(StringTools.replace(v,"\n"," ")).split(" ");
		var a : Array<Float32> = [];
		
		for (i in 0...l.length) a.push(Std.parseFloat(l[i]));
		
		return a;
	}
	
	private function _i16a(v : String) : Array<Int>
	{
		var l : Array<String> = StringTools.trim(StringTools.replace(v,"\n"," ")).split(" ");		
		var a : Array<Int> = [];
		for (i in 0...l.length) a.push(Std.parseInt(l[i]));
		return a;
	}
	
	private function _i16ta(v : String,s:Int) : Array< Array<Int> >
	{		
		var l  : Array<String>  = StringTools.trim(StringTools.replace(v, "\n", " ")).split(" ");
		var tl : String 		= "";
		var a : Array< Array<Int> > 		= [];
		var bf : Array<Int>;
		var k :Int = 0;
		
		while(k < l.length)
		{			
			bf = [];
			for (j in 0...s) bf.push(Std.parseInt(l[k++]));
			a.push(bf);
		}
		return a;
	}
	
	
}

@:allow(haxor)
class ColladaAssetData
{
	public var author 		: String = "";
	public var tool 		: String = "";
	public var source 		: String = "";
	public var creation 	: String = "";
	public var modification	: String = "";
	public var unitName 	: String = "";
	public var unitValue 	: Float32  = 0.0;
	public var axis 		: String = "y_up";	
	public function new() { }		
}

@:allow(haxor)
class ColladaGeometry
{
	public var id 		: String = "";	
	public var name 	: String = "";		
	public var mesh		: ColladaMesh = null;
	public function new() { }		
}

@:allow(haxor)
class ColladaMesh
{	
	public var type			: String 					= "";		
	public var primitives	: Array<ColladaPrimitive> 	= null;	
	public function new() 
	{
		primitives = [];
	}		
}

@:allow(haxor)
class ColladaPrimitive
{	
	public var type			: String 				= ""; // triangles polylist polygons		
	public var material		: String				= "";
	public var inputs	 	: Array<ColladaInput>	= null;
	public var vcount		: Array<Int>			= null;
	public var indexes		: Array< Array< Array<Int> > >	= null;
	
	public var triangles(get_triangles, never):Array< Array<Int> >;
	private function get_triangles() : Array< Array<Int> >
	{
		if (m_triangles != null) return m_triangles;
		m_triangles = ColladaFile.GenerateTriangles(type, indexes, vcount);
		return m_triangles;
	}	
	private var m_triangles : Array< Array<Int> >;
	
	
	
	public var offset(get_offset, never):Int;
	private function get_offset():Int { var mo : Int = 0; for (i in 0...inputs.length) mo = cast Math.max(mo, inputs[i].offset+1); return mo; }
		
	public function new() 
	{
		inputs	 	= [];
		vcount 		= [];
		indexes		= [];	
		m_triangles = null;
	}
	
	public function GetInput(p_semantic : String, p_set : Int = -1) : ColladaInput
	{
		for (i in 0...inputs.length)
		{
			if (inputs[i].semantic == p_semantic)
			{
				if (p_set < 0) 					{ return inputs[i]; }
				else
				if (p_set == inputs[i].set) 	{ return inputs[i]; }
			}
		}		
		return null;
	}
	
	public function GetTriangulatedVectorArray(p_semantic : String, p_set : Int = -1,p_debug :Bool=false):Dynamic
	{
		var ci  : ColladaInput = GetInput(p_semantic, p_set);
		if (ci == null) return [];
		
		var vec : Dynamic = ci.GetVectorArray();
		var off : Int 	  = ci.offset;
		var res : Dynamic = [];
		
		if (vec.length <= 0) return [];
		if (off < 0) 		 return [];
		
		for (i in 0...triangles.length)
		{
			var tuple : Array<Int> = triangles[i];			
			var idx   : Int = tuple[off];
			res.push(vec[idx]);
			//if(p_debug) if(vec[idx] == null) Console.Breakpoint();
		}
		
		
		
		return res;
	}
	
	public function GetVectorArray(p_semantic : String,p_set : Int=-1) : Dynamic
	{
		var res : Dynamic = [];
		
		for (i in 0...inputs.length)
		{
			if (inputs[i].semantic == p_semantic)
			{
				if (p_set < 0) 					{ res = inputs[i].GetVectorArray(); break; }
				else
				if (p_set == inputs[i].set) 	{ res = inputs[i].GetVectorArray(); break; }
			}
		}
		
		if (p_semantic == "color") if (p_set < 0)
		{
			var l : Dynamic = GetVectorArray("color", 0);
			if (l.length > 0)
			{
				var len : Int = cast Math.min(l.length, res.length);
				for (i in 0...len) res[i].a = l[i].r;
			}
		}
		
		return res;
	}
	
}

@:allow(haxor)
class ColladaInput
{
	public var semantic 		: String 		 = "";
	public var offset			: Int    		 =  0;
	public var set				: Int    		 = -1;
	public var values			: Array<Dynamic> = null;
	public var stride			: Int			 = 0;
	
	public function new()
	{
		values = [];
	}
	
	public function GetVectorArray() : Dynamic
	{
		if (stride <= 0) return [];
		var res : Dynamic = [];				
		var i : Int = 0;
		
		while (i < values.length)
		{
			var v : Dynamic = null;
			switch(stride)
			{
				case 1: v = values[i];
				case 2: v = new Vector2(values[i], values[i + 1]);
				case 3: v = semantic == "color" ? new Color(values[i], values[i + 1], values[i + 2]) : new Vector3(values[i], values[i + 1], values[i + 2]);
				case 4: v = semantic == "color" ? new Color(values[i], values[i + 1], values[i + 2], values[i + 3]) : new Vector4(values[i], values[i + 1], values[i + 2], values[i + 3]);
			}						
			if (v == null) continue;
			
			res.push(v);			
			i += stride;
		}		
		return res;
	}
	
}

@:allow(haxor)
class ColladaImage
{
	public var id 		: String = "";	
	public var name 	: String = "";
	public var format 	: String = "";
	public var source	: String = "";
	public var width	: Int 	 = 0;
	public var height	: Int 	 = 0;
	public var depth	: Int    = 0;
	public var data		: Bitmap = null;
	public function new() { }		
}

@:allow(haxor)
class ColladaController
{
	public var type		: String 				= "";	//skin morph
	public var source	: String				= "";
	public var id 		: String 				= "";	
	public var name 	: String 				= "";
	public var matrix	: Array<Float32> 			= null;
	public var binds	: Array< Array<Float32> >	= null;
	public var joints	: Array<String> 		= null;	
	public var inputs	: Array<ColladaInput>	= null;
	public var vcount	: Array<Int>			= null;
	public var indexes	: Array< Array<Int> >	= null;
	
	public var weights  : Array<Vector4>		= null;
	
	public var bones  	: Array<Vector4>		= null;
	
	public var offset(get_offset, never):Int;
	private function get_offset():Int { var mo : Int = 0; for (i in 0...inputs.length) mo = cast Math.max(mo, inputs[i].offset+1); return mo; }
	
	public function new() 
	{
		matrix 	= [];
		binds	= [];
		inputs 	= [];
		joints	= [];
		vcount  = [];
		indexes = [];
	}		
	
	public function GetBSM():Matrix4
	{
		var mtx : Matrix4 = Matrix4.identity;
		//for (i in 0...matrix.length) mtx.m[i] = matrix[i];
		for (i in 0...matrix.length) mtx.SetIndex(i,matrix[i]);
		return mtx;
	}
	
	public function GetJointIndex(p_joint : String):Int
	{
		for (i in 0...joints.length) if (p_joint == joints[i]) return i;
		return -1;
	}
	
	public function GetBinds():Array<Matrix4>
	{
		var res : Array<Matrix4> = [];
		for (i in 0...binds.length)
		{
			var mtx : Matrix4 = Matrix4.identity;
			//for (j in 0...binds[i].length) mtx.m[j] = binds[i][j];
			for (j in 0...binds[i].length) mtx.SetIndex(j,binds[i][j]);
			res.push(mtx);
		}
		return res;
	}
	
	public function GetTriangulatedWeights(cp : ColladaPrimitive):Array<Vector4>
	{
		var v_off : Int = cp.GetInput("vertex").offset;
		var res : Array<Vector4> = [];		
		for (i in 0...cp.triangles.length)
		{
			var idx : Int = cp.triangles[i][v_off];
			res.push(weights[idx]);
		}		
		return res;
	}
	
	public function GetTriangulatedBones(cp : ColladaPrimitive):Array<Vector4>
	{
		var v_off : Int = cp.GetInput("vertex").offset;
		var res : Array<Vector4> = [];		
		for (i in 0...cp.triangles.length)
		{
			var idx : Int = cp.triangles[i][v_off];
			res.push(bones[idx]);
		}		
		return res;
	}
	
	public function GenerateBonesAndWeights():Void
	{
		weights = [];
		bones   = [];
		
		var off : Int = offset;
		var wi  : ColladaInput = null;
		var wo	: Int = 0;
		var bo  : Int = 0;
		
		for (i in 0...inputs.length)
		{
			if (inputs[i].semantic == "weight") { wi = inputs[i]; wo = wi.offset; }
			if (inputs[i].semantic == "joint")  { bo = inputs[i].offset; }
		}
		
		var k : Int = 0;		
		for (i in 0...vcount.length)
		{
			var n  : Int = vcount[i];
			var wv4  : Vector4 = new Vector4();
			var bv4  : Vector4 = new Vector4();
			for (j in 0...n)
			{
				var bi : Int   = indexes[k][bo];
				var wv : Float32 = wi.values[indexes[k][wo]];
				
				if (j == 0) { wv4.x = wv; bv4.x = bi; } else
				if (j == 1) { wv4.y = wv; bv4.y = bi; } else
				if (j == 2) { wv4.z = wv; bv4.z = bi; } else
				if (j == 3) { wv4.w = wv; bv4.w = bi; };				
				k++;
			}					
			
			var sum : Float32 = wv4.x + wv4.y +wv4.z + wv4.w;
			sum = sum <= 0 ? 0.0 : (1.0 / sum);								
			wv4.Scale(sum);
			weights.push(wv4);
			
			bones.push(bv4);
		}		
	}
}

@:allow(haxor)
class ColladaVisualScene
{
	public var type		: String 				= "";	//visual physics
	public var id		: String				= "";
	public var name		: String				= "";
	public var children : Array<ColladaNode> 	= null;
	
	public function new() 
	{
		children = [];		
	}
	
	public function Traverse(p_callback : ColladaNode -> Void):Void
	{
		for (i in 0...children.length) TraverseStep(children[i], p_callback);
	}
	
	private function TraverseStep(p_node : ColladaNode, p_callback : ColladaNode -> Void):Void
	{
		if (p_callback != null) p_callback(p_node);
		for (i in 0...p_node.children.length) TraverseStep(p_node.children[i], p_callback);
	}
}

@:allow(haxor)
class ColladaNode
{
	public var type		: String 				= "";	//joint node	
	public var id 		: String 				= "";	
	public var sid 		: String 				= "";	
	public var name 	: String 				= "";
	
	public var matrix	: Array<Float32>			= null;
	
	public var scene	: ColladaVisualScene	= null;
	public var parent	: ColladaNode		 	= null;
	public var children : Array<ColladaNode> 	= null;
	
	public var data		: String				= "";
	
	public var local 	: Matrix4 = null;
	
	public var world(get_world, never) : Matrix4;
	private function get_world():Matrix4
	{
		if (m_world != null) return m_world;
		m_world = Matrix4.identity;		
		var it : ColladaNode = this;
		var h : Array<ColladaNode> = [];
		while (it != null)
		{
			h.push(it);			
			it = it.parent;
		}
		h.reverse();
		for (i in 0...h.length)
		{
			m_world.MultiplyTransform(h[i].local);
		}
		return m_world;
	}
	private var m_world : Matrix4;
	
	public var position	: Vector3;
	public var rotation	: Quaternion;
	public var scale	: Vector3;
	
	public var instances : Array<ColladaInstance> = null;
	
	public function new() 
	{
		children  = [];
		instances = [];
		matrix    = [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];
		position  = Vector3.zero;
		rotation  = Quaternion.identity;
		scale     = Vector3.one;
	}	
	
	public function GenerateTranform():Void
	{
		var mtx : Matrix4 = local = Matrix4.FromArray(matrix);		
		position = mtx.translation.GetColumn(3).xyz;
		rotation = mtx.quaternion;
		scale	 = mtx.scale.diagonalLR.xyz;
		
		//if (name == "Collider_Wall_144") trace(position.ToString() + " " + rotation.ToString() + " " + scale.ToString()+" "+Quaternion.FromAxisAngle(Vector3.forward,90).ToString());
				
	}
}

@:allow(haxor)
class ColladaInstance
{
	public var type : String 	= ""; //controller geometry
	
	public var target : String 	= ""; //ColladaController ColladaGeometry	
	
	public var materials : Array<String>; //Used by ColladaController ColladaGeometry	
	
	public function new() 
	{
		materials = [];
	}
}

@:allow(haxor)
class ColladaMaterial
{
	public var id 		: String 				= "";			
	
	public var name 	: String 				= "";
	
	public function new() { }
}

@:allow(haxor)
class ColladaAnimation
{
	public var id 		: String 				= "";			
	
	public var name 	: String 				= "";
	
	public var channels : Array<ColladaAnimationChannel>;
	
	public function new() 
	{
		channels = [];
	}

}

@:allow(haxor)
class ColladaAnimationChannel
{
	public var source 		: String 	= "";			
	
	public var target 	: String 		= "";
	
	public var keyframes : Array<ColladaAnimationKeyFrame>;
	
	public function new()
	{
		keyframes = [];
	}	
	
}

@:allow(haxor)
class ColladaAnimationKeyFrame
{
	public var time : Float32;
	
	public var values : Array<Float32>;
	
	public function new ()
	{
		time 	= 0.0;
		values 	= [];
	}
}

@:allow(haxor)
class ColladaLight
{
	public var id 		  : String;	
	public var name 	  : String;
	public var type 	  : String;
	public var color 	  : Color;
	public var radius 	  : Float32;
	public var intensity  : Float32;
	public var atten	  : Float32;
	
	public function new ()
	{
		id 	  		= "";
		name  		= "";
		type  		= "";
		color 		= Color.white;
		radius 		= 0.0;
		intensity 	= 0.0;
		atten		= 0.0;
	}
}