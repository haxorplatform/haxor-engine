(function () { "use strict";
var $hxClasses = {},$estr = function() { return js_Boot.__string_rec(this,''); };
function $extend(from, fields) {
	function Inherit() {} Inherit.prototype = from; var proto = new Inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
var HxOverrides = function() { };
$hxClasses["HxOverrides"] = HxOverrides;
HxOverrides.__name__ = ["HxOverrides"];
HxOverrides.cca = function(s,index) {
	var x = s.charCodeAt(index);
	if(x != x) return undefined;
	return x;
};
HxOverrides.substr = function(s,pos,len) {
	if(pos != null && pos != 0 && len != null && len < 0) return "";
	if(len == null) len = s.length;
	if(pos < 0) {
		pos = s.length + pos;
		if(pos < 0) pos = 0;
	} else if(len < 0) len = s.length + len - pos;
	return s.substr(pos,len);
};
HxOverrides.remove = function(a,obj) {
	var i = a.indexOf(obj);
	if(i == -1) return false;
	a.splice(i,1);
	return true;
};
HxOverrides.iter = function(a) {
	return { cur : 0, arr : a, hasNext : function() {
		return this.cur < this.arr.length;
	}, next : function() {
		return this.arr[this.cur++];
	}};
};
var haxor_core_IDisposable = function() { };
$hxClasses["haxor.core.IDisposable"] = haxor_core_IDisposable;
haxor_core_IDisposable.__name__ = ["haxor","core","IDisposable"];
haxor_core_IDisposable.prototype = {
	__class__: haxor_core_IDisposable
};
var haxor_core_Resource = function(p_name) {
	if(p_name == null) p_name = "";
	this.m_uid = haxor_context_EngineContext.uid++;
	this.m_destroyed = false;
	this.__cid = 0;
	this.__db = "";
	this.__pid = [-1,-1,-1,-1,-1,-1,-1,-1,-1];
	this.m_name = p_name;
	this.m_is_behaviour = js_Boot.__instanceof(this,haxor_component_Behaviour);
	this.m_type_class = Type.getClass(this);
	this.m_type_full_name = Type.getClassName(this.m_type_class);
	var nt = this.m_type_full_name.split(".");
	nt.reverse();
	this.m_type_name = nt[0];
	if(p_name == "") this.m_name = this.m_type_name + this.m_uid; else this.m_name = p_name;
	this.m_guid = "";
	this.m_guid += StringTools.hex(Math.floor(268435455 * Math.random()));
	this.m_guid += StringTools.hex(Math.floor(268435455 * Math.random()));
	this.m_guid += StringTools.hex(Math.floor(268435455 * Math.random()));
	this.m_guid += StringTools.hex(Math.floor(268435455 * Math.random()));
	haxor_context_EngineContext.resources.Add(this);
};
$hxClasses["haxor.core.Resource"] = haxor_core_Resource;
haxor_core_Resource.__name__ = ["haxor","core","Resource"];
haxor_core_Resource.__interfaces__ = [haxor_core_IDisposable];
haxor_core_Resource.Destroy = function(p_target) {
	if(p_target.__db != "") haxor_io_file_Asset.Remove(p_target.__db);
	haxor_context_EngineContext.Destroy(p_target);
};
haxor_core_Resource.prototype = {
	get_application: function() {
		return haxor_core_BaseApplication.m_instance;
	}
	,get_guid: function() {
		return this.m_guid;
	}
	,get_uid: function() {
		return this.m_uid;
	}
	,get_name: function() {
		return this.m_name;
	}
	,set_name: function(v) {
		this.m_name = v;
		return v;
	}
	,get_destroyed: function() {
		return this.m_destroyed;
	}
	,GetType: function() {
		return this.m_type_class;
	}
	,GetTypeName: function() {
		return this.m_type_name;
	}
	,GetTypeFullName: function() {
		return this.m_type_full_name;
	}
	,OnDestroy: function() {
	}
	,__class__: haxor_core_Resource
	,__properties__: {get_destroyed:"get_destroyed",set_name:"set_name",get_name:"get_name",get_uid:"get_uid",get_guid:"get_guid",get_application:"get_application"}
};
var haxor_component_Component = function(p_name) {
	haxor_core_Resource.call(this,p_name);
};
$hxClasses["haxor.component.Component"] = haxor_component_Component;
haxor_component_Component.__name__ = ["haxor","component","Component"];
haxor_component_Component.__super__ = haxor_core_Resource;
haxor_component_Component.prototype = $extend(haxor_core_Resource.prototype,{
	get_name: function() {
		return this.m_entity.get_name();
	}
	,set_name: function(v) {
		this.m_entity.set_name(v);
		return v;
	}
	,get_entity: function() {
		return this.m_entity;
	}
	,get_transform: function() {
		return this.m_entity.m_transform;
	}
	,AddComponent: function(p_type) {
		return this.m_entity.AddComponent(p_type);
	}
	,GetComponent: function(p_type) {
		return this.m_entity.GetComponent(p_type);
	}
	,GetComponents: function(p_type) {
		return this.m_entity.GetComponents(p_type);
	}
	,GetComponentInChildren: function(p_type) {
		return this.m_entity.GetComponentInChildren(p_type);
	}
	,GetComponentsInChildren: function(p_type) {
		return this.m_entity.GetComponentsInChildren(p_type);
	}
	,OnBuild: function() {
	}
	,OnTransformUpdate: function() {
	}
	,OnVisibilityChange: function(p_visible) {
	}
	,__class__: haxor_component_Component
	,__properties__: $extend(haxor_core_Resource.prototype.__properties__,{get_transform:"get_transform",get_entity:"get_entity"})
});
var haxor_component_Behaviour = function(p_name) {
	haxor_component_Component.call(this,p_name);
};
$hxClasses["haxor.component.Behaviour"] = haxor_component_Behaviour;
haxor_component_Behaviour.__name__ = ["haxor","component","Behaviour"];
haxor_component_Behaviour.__super__ = haxor_component_Component;
haxor_component_Behaviour.prototype = $extend(haxor_component_Component.prototype,{
	get_enabled: function() {
		return this.m_enabled && !this.m_destroyed;
	}
	,set_enabled: function(v) {
		if(this.m_destroyed) return false;
		if(this.m_enabled == v) return v;
		this.m_enabled = v;
		if(v) haxor_context_EngineContext.Enable(this); else haxor_context_EngineContext.Disable(this);
		return v;
	}
	,OnBuild: function() {
		haxor_component_Component.prototype.OnBuild.call(this);
		this.m_enabled = true;
		this.m_is_behaviour = true;
		haxor_context_EngineContext.Enable(this);
	}
	,OnAwake: function() {
	}
	,OnStart: function() {
	}
	,__class__: haxor_component_Behaviour
	,__properties__: $extend(haxor_component_Component.prototype.__properties__,{set_enabled:"set_enabled",get_enabled:"get_enabled"})
});
var haxor_core_BaseApplication = function(p_name) {
	haxor_component_Behaviour.call(this,p_name);
};
$hxClasses["haxor.core.BaseApplication"] = haxor_core_BaseApplication;
haxor_core_BaseApplication.__name__ = ["haxor","core","BaseApplication"];
haxor_core_BaseApplication.__super__ = haxor_component_Behaviour;
haxor_core_BaseApplication.prototype = $extend(haxor_component_Behaviour.prototype,{
	get_protocol: function() {
		if(window.location.protocol.toLowerCase() == "file:") return haxor_core_ApplicationProtocol.File;
		if(window.location.protocol.toLowerCase() == "http:") return haxor_core_ApplicationProtocol.HTTP;
		if(window.location.protocol.toLowerCase() == "https:") return haxor_core_ApplicationProtocol.HTTPS;
		return haxor_core_ApplicationProtocol.None;
	}
	,get_vendor: function() {
		if(this.m_vendor != null) return this.m_vendor;
		var vdr = "";
		if(window.msRequestAnimationFrame 		!= null) vdr = "-ms-";
		if(window.oRequestAnimationFrame 		!= null) vdr = "-o-";
		if(window.webkitRequestAnimationFrame 	!= null) vdr = "-webkit-";
		if(window.mozRequestAnimationFrame 		!= null) vdr = "-moz-";
		return this.m_vendor = vdr;
		return this.m_vendor = "";
	}
	,get_fps: function() {
		return this.m_fps;
	}
	,set_fps: function(v) {
		this.m_fps = v;
		var f = v;
		if(f >= 60.0) f = 1000000.0;
		f *= 1.25;
		this.m_mspf = 1.0 / f * 1000.0;
		return v;
	}
	,get_platform: function() {
		return this.m_platform;
	}
	,OnBuild: function() {
		haxor_component_Behaviour.prototype.OnBuild.call(this);
		haxor_core_BaseApplication.m_instance = this;
		this.m_scenes = [];
		this.set_fps(60);
		this.m_frame_ms = 0.0;
		this.m_init_allowed = false;
		this.m_platform = haxor_core_Platform.Unknown;
		haxor_core_Time.Initialize();
		haxor_graphics_Screen.Initialize(this);
		haxor_input_Input.Initialize();
	}
	,LoadScene: function(p_name) {
	}
	,DestroyScene: function(p_name) {
	}
	,Load: function() {
		return true;
	}
	,Initialize: function() {
	}
	,LoadComplete: function() {
		this.m_init_allowed = true;
	}
	,Update: function() {
		haxor_core_Time.Update();
		haxor_input_Input.m_handler.Update();
		this.CheckResize();
		haxor_core_Engine.Update();
		haxor_core_Engine.Collect();
		haxor_input_Input.m_handler.Clear();
	}
	,Render: function() {
		if(this.m_init_allowed) {
			haxor_core_Console.Log("Application> Initialize.",3);
			this.Initialize();
			this.m_init_allowed = false;
		}
		if(haxor_core_Time.m_clock - this.m_frame_ms >= this.m_mspf) {
			this.m_frame_ms += haxor_core_Time.m_clock - this.m_frame_ms;
			haxor_core_Time.Render();
			haxor_graphics_GL.m_gl.Focus();
			haxor_core_Engine.Render();
			null;
		}
	}
	,OnQuit: function() {
	}
	,OnFocus: function() {
	}
	,OnUnfocus: function() {
	}
	,CheckResize: function() {
		var has_resize = false;
		if(Math.abs(haxor_graphics_Screen.m_width - this.GetContainerWidth()) > 0.0) {
			haxor_graphics_Screen.m_width = this.GetContainerWidth();
			has_resize = true;
		}
		if(Math.abs(haxor_graphics_Screen.m_height - this.GetContainerHeight()) > 0.0) {
			haxor_graphics_Screen.m_height = this.GetContainerHeight();
			has_resize = true;
		}
		if(has_resize) this.OnResize();
	}
	,OnResize: function() {
		haxor_core_Console.Log("Application> Resize [" + haxor_graphics_Screen.m_width + "," + haxor_graphics_Screen.m_height + "]",6);
		haxor_graphics_GL.m_gl.Resize();
		haxor_core_Engine.Resize();
	}
	,OnFullscreenEnter: function() {
	}
	,OnFullscreenExit: function() {
	}
	,OnFullscreenRequest: function(v) {
		return false;
	}
	,OnPointerLockRequest: function(v) {
		return false;
	}
	,OnPointerVisibilityRequest: function(v) {
		return false;
	}
	,OnMousePosition: function(p_x,p_y) {
	}
	,GetContainerWidth: function() {
		return 0.0;
	}
	,GetContainerHeight: function() {
		return 0.0;
	}
	,__class__: haxor_core_BaseApplication
	,__properties__: $extend(haxor_component_Behaviour.prototype.__properties__,{get_platform:"get_platform",set_fps:"set_fps",get_fps:"get_fps",get_vendor:"get_vendor",get_protocol:"get_protocol"})
});
var haxor_platform_html_HTMLApplication = function() {
	haxor_core_BaseApplication.call(this);
	this.m_platform = haxor_core_Platform.HTML;
};
$hxClasses["haxor.platform.html.HTMLApplication"] = haxor_platform_html_HTMLApplication;
haxor_platform_html_HTMLApplication.__name__ = ["haxor","platform","html","HTMLApplication"];
haxor_platform_html_HTMLApplication.__super__ = haxor_core_BaseApplication;
haxor_platform_html_HTMLApplication.prototype = $extend(haxor_core_BaseApplication.prototype,{
	get_stage: function() {
		return haxor_dom_DOMStage.m_instance;
	}
	,GetContainerWidth: function() {
		return this.m_container.clientWidth;
	}
	,GetContainerHeight: function() {
		return this.m_container.clientHeight;
	}
	,__class__: haxor_platform_html_HTMLApplication
	,__properties__: $extend(haxor_core_BaseApplication.prototype.__properties__,{get_stage:"get_stage"})
});
var haxor_core_Application = function() {
	haxor_platform_html_HTMLApplication.call(this);
};
$hxClasses["haxor.core.Application"] = haxor_core_Application;
haxor_core_Application.__name__ = ["haxor","core","Application"];
haxor_core_Application.__super__ = haxor_platform_html_HTMLApplication;
haxor_core_Application.prototype = $extend(haxor_platform_html_HTMLApplication.prototype,{
	__class__: haxor_core_Application
});
var haxor_core_IRenderable = function() { };
$hxClasses["haxor.core.IRenderable"] = haxor_core_IRenderable;
haxor_core_IRenderable.__name__ = ["haxor","core","IRenderable"];
haxor_core_IRenderable.prototype = {
	__class__: haxor_core_IRenderable
};
var haxor_core_IUpdateable = function() { };
$hxClasses["haxor.core.IUpdateable"] = haxor_core_IUpdateable;
haxor_core_IUpdateable.__name__ = ["haxor","core","IUpdateable"];
haxor_core_IUpdateable.prototype = {
	__class__: haxor_core_IUpdateable
};
var Main = function() {
	this.queue = 3;
	haxor_core_Application.call(this);
};
$hxClasses["Main"] = Main;
Main.__name__ = ["Main"];
Main.__interfaces__ = [haxor_core_IRenderable,haxor_core_IUpdateable];
Main.main = function() {
	haxor_platform_html_Entry.Initialize();
};
Main.__super__ = haxor_core_Application;
Main.prototype = $extend(haxor_core_Application.prototype,{
	Load: function() {
		var _g = this;
		haxor_net_Web.root = "http://www.haxor.xyz/resources/";
		haxor_net_Web.LoadCollada("./character/skeleton/grunt/animation_idle01.DAE",function(f,p) {
			if(p >= 1.0) {
				haxor_io_file_Asset.Add("animation_idle",f);
				if(--_g.queue <= 0) _g.LoadComplete();
			}
		});
		haxor_net_Web.LoadTexture2D("./character/skeleton/grunt/DiffuseTexture.png",true,function(t,p1) {
			if(p1 >= 1.0) {
				haxor_io_file_Asset.Add("texture_diffuse",t);
				if(--_g.queue <= 0) _g.LoadComplete();
			}
		});
		haxor_net_Web.LoadCollada("./character/skeleton/grunt/model.DAE",function(f1,p2) {
			if(p2 >= 1.0) {
				haxor_io_file_Asset.Add("model",f1);
				if(--_g.queue <= 0) _g.LoadComplete();
			}
		});
		return false;
	}
	,Initialize: function() {
		haxor_core_Console.Log("Initialize!");
		this.field = window.document.getElementById("field");
		var ui = new Stats();
		ui.domElement.style.position = "absolute";
		ui.domElement.style.top = "0px";
		window.document.body.appendChild(ui.domElement);
		haxor_thread_Activity.Run(function(t) {
			ui.update();
			return true;
		});
		this.orbit = haxor_component_CameraOrbit.Create(40.0,45,30);
		var ci = this.orbit.m_entity.AddComponent(haxor_component_CameraOrbitInput);
		this.orbit.smooth = 5.0;
		ci.zoomSpeed = 1.0;
		this.cam = this.orbit.m_entity.GetComponentInChildren(haxor_component_Camera);
		this.cam.set_far(1000.0);
		this.cam.background = new haxor_math_Color(0.3,0.3,0.3);
		this.container = new haxor_core_Entity("container").get_transform();
		this.mat = haxor_graphics_material_Material.Opaque(haxor_io_file_Asset.Get("texture_diffuse"),null,null);
		this.mat.set_shader(haxor_graphics_material_Shader.m_flat_texture_skin_shader == null?haxor_graphics_material_Shader.m_flat_texture_skin_shader = new haxor_graphics_material_Shader(haxor_context_ShaderContext.flat_texture_skin_source):haxor_graphics_material_Shader.m_flat_texture_skin_shader);
		this.mat.set_name("PlayerMaterial");
		this.mat.SetTexture("DiffuseTexture",haxor_io_file_Asset.Get("texture_diffuse"));
		var cf;
		cf = haxor_io_file_Asset.Get("model");
		this.player = new haxor_core_Entity("player").get_transform();
		var asset = (js_Boot.__cast(cf.get_asset() , haxor_core_Entity)).get_transform();
		asset.set_parent(this.player);
		asset.set_localScale(new haxor_math_Vector3(0.1,0.1,0.1));
		var mr = this.player.m_entity.GetComponentsInChildren(haxor_component_MeshRenderer);
		var _g1 = 0;
		var _g = mr.length;
		while(_g1 < _g) {
			var i = _g1++;
			mr[i].set_material(this.mat);
		}
		var anim;
		cf = haxor_io_file_Asset.Get("animation_idle");
		cf.AddAnimations(asset.m_entity);
		anim = asset.m_entity.m_animation;
		anim.Play(anim.clips[0]);
		anim.clips[0].wrap = haxor_core_AnimationWrap.Loop;
	}
	,OnUpdate: function() {
		var log = "";
		log += "Stats";
		log += "\nVisible: " + haxor_core_Stats.visible;
		log += "\nCulled: " + haxor_core_Stats.culled;
		log += "\nActive: " + haxor_core_Stats.get_total();
		log += "\nRenderers: " + haxor_core_Stats.renderers;
		log += "\nTris: " + haxor_core_Stats.triangles;
		if(this.player != null) {
			var r = this.player.get_localRotation();
			r = haxor_math_Quaternion.FromAxisAngle(new haxor_math_Vector3(0,1,0),33.0);
			this.player.set_localRotation(r);
		}
		if(this.field != null) this.field.innerText = log;
	}
	,OnRender: function() {
		haxor_graphics_Gizmo.Grid(100.0,new haxor_math_Color(1,1,1,0.1));
	}
	,__class__: Main
});
var IMap = function() { };
$hxClasses["IMap"] = IMap;
IMap.__name__ = ["IMap"];
Math.__name__ = ["Math"];
var Reflect = function() { };
$hxClasses["Reflect"] = Reflect;
Reflect.__name__ = ["Reflect"];
Reflect.getProperty = function(o,field) {
	var tmp;
	if(o == null) return null; else if(o.__properties__ && (tmp = o.__properties__["get_" + field])) return o[tmp](); else return o[field];
};
Reflect.setProperty = function(o,field,value) {
	var tmp;
	if(o.__properties__ && (tmp = o.__properties__["set_" + field])) o[tmp](value); else o[field] = value;
};
var Std = function() { };
$hxClasses["Std"] = Std;
Std.__name__ = ["Std"];
Std.string = function(s) {
	return js_Boot.__string_rec(s,"");
};
Std["int"] = function(x) {
	return x | 0;
};
Std.parseInt = function(x) {
	var v = parseInt(x,10);
	if(v == 0 && (HxOverrides.cca(x,1) == 120 || HxOverrides.cca(x,1) == 88)) v = parseInt(x);
	if(isNaN(v)) return null;
	return v;
};
Std.parseFloat = function(x) {
	return parseFloat(x);
};
var StringBuf = function() {
	this.b = "";
};
$hxClasses["StringBuf"] = StringBuf;
StringBuf.__name__ = ["StringBuf"];
StringBuf.prototype = {
	add: function(x) {
		this.b += Std.string(x);
	}
	,addChar: function(c) {
		this.b += String.fromCharCode(c);
	}
	,addSub: function(s,pos,len) {
		if(len == null) this.b += HxOverrides.substr(s,pos,null); else this.b += HxOverrides.substr(s,pos,len);
	}
	,__class__: StringBuf
};
var StringTools = function() { };
$hxClasses["StringTools"] = StringTools;
StringTools.__name__ = ["StringTools"];
StringTools.htmlEscape = function(s,quotes) {
	s = s.split("&").join("&amp;").split("<").join("&lt;").split(">").join("&gt;");
	if(quotes) return s.split("\"").join("&quot;").split("'").join("&#039;"); else return s;
};
StringTools.isSpace = function(s,pos) {
	var c = HxOverrides.cca(s,pos);
	return c > 8 && c < 14 || c == 32;
};
StringTools.ltrim = function(s) {
	var l = s.length;
	var r = 0;
	while(r < l && StringTools.isSpace(s,r)) r++;
	if(r > 0) return HxOverrides.substr(s,r,l - r); else return s;
};
StringTools.rtrim = function(s) {
	var l = s.length;
	var r = 0;
	while(r < l && StringTools.isSpace(s,l - r - 1)) r++;
	if(r > 0) return HxOverrides.substr(s,0,l - r); else return s;
};
StringTools.trim = function(s) {
	return StringTools.ltrim(StringTools.rtrim(s));
};
StringTools.replace = function(s,sub,by) {
	return s.split(sub).join(by);
};
StringTools.hex = function(n,digits) {
	var s = "";
	var hexChars = "0123456789ABCDEF";
	do {
		s = hexChars.charAt(n & 15) + s;
		n >>>= 4;
	} while(n > 0);
	if(digits != null) while(s.length < digits) s = "0" + s;
	return s;
};
StringTools.fastCodeAt = function(s,index) {
	return s.charCodeAt(index);
};
var Type = function() { };
$hxClasses["Type"] = Type;
Type.__name__ = ["Type"];
Type.getClass = function(o) {
	if(o == null) return null;
	if((o instanceof Array) && o.__enum__ == null) return Array; else return o.__class__;
};
Type.getClassName = function(c) {
	var a = c.__name__;
	return a.join(".");
};
Type.resolveClass = function(name) {
	var cl = $hxClasses[name];
	if(cl == null || !cl.__name__) return null;
	return cl;
};
Type.createInstance = function(cl,args) {
	var _g = args.length;
	switch(_g) {
	case 0:
		return new cl();
	case 1:
		return new cl(args[0]);
	case 2:
		return new cl(args[0],args[1]);
	case 3:
		return new cl(args[0],args[1],args[2]);
	case 4:
		return new cl(args[0],args[1],args[2],args[3]);
	case 5:
		return new cl(args[0],args[1],args[2],args[3],args[4]);
	case 6:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5]);
	case 7:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6]);
	case 8:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6],args[7]);
	default:
		throw "Too many arguments";
	}
	return null;
};
var XmlType = { __ename__ : true, __constructs__ : [] };
var Xml = function() {
};
$hxClasses["Xml"] = Xml;
Xml.__name__ = ["Xml"];
Xml.parse = function(str) {
	return haxe_xml_Parser.parse(str);
};
Xml.createElement = function(name) {
	var r = new Xml();
	r.nodeType = Xml.Element;
	r._children = new Array();
	r._attributes = new haxe_ds_StringMap();
	r.set_nodeName(name);
	return r;
};
Xml.createPCData = function(data) {
	var r = new Xml();
	r.nodeType = Xml.PCData;
	r.set_nodeValue(data);
	return r;
};
Xml.createCData = function(data) {
	var r = new Xml();
	r.nodeType = Xml.CData;
	r.set_nodeValue(data);
	return r;
};
Xml.createComment = function(data) {
	var r = new Xml();
	r.nodeType = Xml.Comment;
	r.set_nodeValue(data);
	return r;
};
Xml.createDocType = function(data) {
	var r = new Xml();
	r.nodeType = Xml.DocType;
	r.set_nodeValue(data);
	return r;
};
Xml.createProcessingInstruction = function(data) {
	var r = new Xml();
	r.nodeType = Xml.ProcessingInstruction;
	r.set_nodeValue(data);
	return r;
};
Xml.createDocument = function() {
	var r = new Xml();
	r.nodeType = Xml.Document;
	r._children = new Array();
	return r;
};
Xml.prototype = {
	get_nodeName: function() {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._nodeName;
	}
	,set_nodeName: function(n) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._nodeName = n;
	}
	,get_nodeValue: function() {
		if(this.nodeType == Xml.Element || this.nodeType == Xml.Document) throw "bad nodeType";
		return this._nodeValue;
	}
	,set_nodeValue: function(v) {
		if(this.nodeType == Xml.Element || this.nodeType == Xml.Document) throw "bad nodeType";
		return this._nodeValue = v;
	}
	,get: function(att) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._attributes.get(att);
	}
	,set: function(att,value) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		this._attributes.set(att,value);
	}
	,exists: function(att) {
		if(this.nodeType != Xml.Element) throw "bad nodeType";
		return this._attributes.exists(att);
	}
	,iterator: function() {
		if(this._children == null) throw "bad nodetype";
		return { cur : 0, x : this._children, hasNext : function() {
			return this.cur < this.x.length;
		}, next : function() {
			return this.x[this.cur++];
		}};
	}
	,elements: function() {
		if(this._children == null) throw "bad nodetype";
		return { cur : 0, x : this._children, hasNext : function() {
			var k = this.cur;
			var l = this.x.length;
			while(k < l) {
				if(this.x[k].nodeType == Xml.Element) break;
				k += 1;
			}
			this.cur = k;
			return k < l;
		}, next : function() {
			var k1 = this.cur;
			var l1 = this.x.length;
			while(k1 < l1) {
				var n = this.x[k1];
				k1 += 1;
				if(n.nodeType == Xml.Element) {
					this.cur = k1;
					return n;
				}
			}
			return null;
		}};
	}
	,elementsNamed: function(name) {
		if(this._children == null) throw "bad nodetype";
		return { cur : 0, x : this._children, hasNext : function() {
			var k = this.cur;
			var l = this.x.length;
			while(k < l) {
				var n = this.x[k];
				if(n.nodeType == Xml.Element && n._nodeName == name) break;
				k++;
			}
			this.cur = k;
			return k < l;
		}, next : function() {
			var k1 = this.cur;
			var l1 = this.x.length;
			while(k1 < l1) {
				var n1 = this.x[k1];
				k1++;
				if(n1.nodeType == Xml.Element && n1._nodeName == name) {
					this.cur = k1;
					return n1;
				}
			}
			return null;
		}};
	}
	,firstChild: function() {
		if(this._children == null) throw "bad nodetype";
		return this._children[0];
	}
	,firstElement: function() {
		if(this._children == null) throw "bad nodetype";
		var cur = 0;
		var l = this._children.length;
		while(cur < l) {
			var n = this._children[cur];
			if(n.nodeType == Xml.Element) return n;
			cur++;
		}
		return null;
	}
	,addChild: function(x) {
		if(this._children == null) throw "bad nodetype";
		if(x._parent != null) HxOverrides.remove(x._parent._children,x);
		x._parent = this;
		this._children.push(x);
	}
	,toString: function() {
		if(this.nodeType == Xml.PCData) return StringTools.htmlEscape(this._nodeValue);
		if(this.nodeType == Xml.CData) return "<![CDATA[" + this._nodeValue + "]]>";
		if(this.nodeType == Xml.Comment) return "<!--" + this._nodeValue + "-->";
		if(this.nodeType == Xml.DocType) return "<!DOCTYPE " + this._nodeValue + ">";
		if(this.nodeType == Xml.ProcessingInstruction) return "<?" + this._nodeValue + "?>";
		var s = new StringBuf();
		if(this.nodeType == Xml.Element) {
			s.b += "<";
			s.b += Std.string(this._nodeName);
			var $it0 = this._attributes.keys();
			while( $it0.hasNext() ) {
				var k = $it0.next();
				s.b += " ";
				if(k == null) s.b += "null"; else s.b += "" + k;
				s.b += "=\"";
				s.add(this._attributes.get(k));
				s.b += "\"";
			}
			if(this._children.length == 0) {
				s.b += "/>";
				return s.b;
			}
			s.b += ">";
		}
		var $it1 = this.iterator();
		while( $it1.hasNext() ) {
			var x = $it1.next();
			s.add(x.toString());
		}
		if(this.nodeType == Xml.Element) {
			s.b += "</";
			s.b += Std.string(this._nodeName);
			s.b += ">";
		}
		return s.b;
	}
	,__class__: Xml
	,__properties__: {set_nodeValue:"set_nodeValue",get_nodeValue:"get_nodeValue",set_nodeName:"set_nodeName",get_nodeName:"get_nodeName"}
};
var haxe_Timer = function(time_ms) {
	var me = this;
	this.id = setInterval(function() {
		me.run();
	},time_ms);
};
$hxClasses["haxe.Timer"] = haxe_Timer;
haxe_Timer.__name__ = ["haxe","Timer"];
haxe_Timer.delay = function(f,time_ms) {
	var t = new haxe_Timer(time_ms);
	t.run = function() {
		t.stop();
		f();
	};
	return t;
};
haxe_Timer.stamp = function() {
	return new Date().getTime() / 1000;
};
haxe_Timer.prototype = {
	stop: function() {
		if(this.id == null) return;
		clearInterval(this.id);
		this.id = null;
	}
	,run: function() {
	}
	,__class__: haxe_Timer
};
var haxe_io_Bytes = function(length,b) {
	this.length = length;
	this.b = b;
};
$hxClasses["haxe.io.Bytes"] = haxe_io_Bytes;
haxe_io_Bytes.__name__ = ["haxe","io","Bytes"];
haxe_io_Bytes.alloc = function(length) {
	var a = new Array();
	var _g = 0;
	while(_g < length) {
		var i = _g++;
		a.push(0);
	}
	return new haxe_io_Bytes(length,a);
};
haxe_io_Bytes.ofString = function(s) {
	var a = new Array();
	var i = 0;
	while(i < s.length) {
		var c = StringTools.fastCodeAt(s,i++);
		if(55296 <= c && c <= 56319) c = c - 55232 << 10 | StringTools.fastCodeAt(s,i++) & 1023;
		if(c <= 127) a.push(c); else if(c <= 2047) {
			a.push(192 | c >> 6);
			a.push(128 | c & 63);
		} else if(c <= 65535) {
			a.push(224 | c >> 12);
			a.push(128 | c >> 6 & 63);
			a.push(128 | c & 63);
		} else {
			a.push(240 | c >> 18);
			a.push(128 | c >> 12 & 63);
			a.push(128 | c >> 6 & 63);
			a.push(128 | c & 63);
		}
	}
	return new haxe_io_Bytes(a.length,a);
};
haxe_io_Bytes.prototype = {
	get: function(pos) {
		return this.b[pos];
	}
	,set: function(pos,v) {
		this.b[pos] = v & 255;
	}
	,getString: function(pos,len) {
		if(pos < 0 || len < 0 || pos + len > this.length) throw haxe_io_Error.OutsideBounds;
		var s = "";
		var b = this.b;
		var fcc = String.fromCharCode;
		var i = pos;
		var max = pos + len;
		while(i < max) {
			var c = b[i++];
			if(c < 128) {
				if(c == 0) break;
				s += fcc(c);
			} else if(c < 224) s += fcc((c & 63) << 6 | b[i++] & 127); else if(c < 240) {
				var c2 = b[i++];
				s += fcc((c & 31) << 12 | (c2 & 127) << 6 | b[i++] & 127);
			} else {
				var c21 = b[i++];
				var c3 = b[i++];
				var u = (c & 15) << 18 | (c21 & 127) << 12 | (c3 & 127) << 6 | b[i++] & 127;
				s += fcc((u >> 10) + 55232);
				s += fcc(u & 1023 | 56320);
			}
		}
		return s;
	}
	,toString: function() {
		return this.getString(0,this.length);
	}
	,__class__: haxe_io_Bytes
};
var haxe_crypto_Base64 = function() { };
$hxClasses["haxe.crypto.Base64"] = haxe_crypto_Base64;
haxe_crypto_Base64.__name__ = ["haxe","crypto","Base64"];
haxe_crypto_Base64.encode = function(bytes,complement) {
	if(complement == null) complement = true;
	var str = new haxe_crypto_BaseCode(haxe_crypto_Base64.BYTES).encodeBytes(bytes).toString();
	if(complement) {
		var _g1 = 0;
		var _g = (3 - bytes.length * 4 % 3) % 3;
		while(_g1 < _g) {
			var i = _g1++;
			str += "=";
		}
	}
	return str;
};
haxe_crypto_Base64.decode = function(str,complement) {
	if(complement == null) complement = true;
	if(complement) while(HxOverrides.cca(str,str.length - 1) == 61) str = HxOverrides.substr(str,0,-1);
	return new haxe_crypto_BaseCode(haxe_crypto_Base64.BYTES).decodeBytes(haxe_io_Bytes.ofString(str));
};
var haxe_crypto_BaseCode = function(base) {
	var len = base.length;
	var nbits = 1;
	while(len > 1 << nbits) nbits++;
	if(nbits > 8 || len != 1 << nbits) throw "BaseCode : base length must be a power of two.";
	this.base = base;
	this.nbits = nbits;
};
$hxClasses["haxe.crypto.BaseCode"] = haxe_crypto_BaseCode;
haxe_crypto_BaseCode.__name__ = ["haxe","crypto","BaseCode"];
haxe_crypto_BaseCode.prototype = {
	encodeBytes: function(b) {
		var nbits = this.nbits;
		var base = this.base;
		var size = b.length * 8 / nbits | 0;
		var out = haxe_io_Bytes.alloc(size + (b.length * 8 % nbits == 0?0:1));
		var buf = 0;
		var curbits = 0;
		var mask = (1 << nbits) - 1;
		var pin = 0;
		var pout = 0;
		while(pout < size) {
			while(curbits < nbits) {
				curbits += 8;
				buf <<= 8;
				buf |= b.get(pin++);
			}
			curbits -= nbits;
			out.set(pout++,base.b[buf >> curbits & mask]);
		}
		if(curbits > 0) out.set(pout++,base.b[buf << nbits - curbits & mask]);
		return out;
	}
	,initTable: function() {
		var tbl = new Array();
		var _g = 0;
		while(_g < 256) {
			var i = _g++;
			tbl[i] = -1;
		}
		var _g1 = 0;
		var _g2 = this.base.length;
		while(_g1 < _g2) {
			var i1 = _g1++;
			tbl[this.base.b[i1]] = i1;
		}
		this.tbl = tbl;
	}
	,decodeBytes: function(b) {
		var nbits = this.nbits;
		var base = this.base;
		if(this.tbl == null) this.initTable();
		var tbl = this.tbl;
		var size = b.length * nbits >> 3;
		var out = haxe_io_Bytes.alloc(size);
		var buf = 0;
		var curbits = 0;
		var pin = 0;
		var pout = 0;
		while(pout < size) {
			while(curbits < 8) {
				curbits += nbits;
				buf <<= nbits;
				var i = tbl[b.get(pin++)];
				if(i == -1) throw "BaseCode : invalid encoded char";
				buf |= i;
			}
			curbits -= 8;
			out.set(pout++,buf >> curbits & 255);
		}
		return out;
	}
	,__class__: haxe_crypto_BaseCode
};
var haxe_ds_IntMap = function() {
	this.h = { };
};
$hxClasses["haxe.ds.IntMap"] = haxe_ds_IntMap;
haxe_ds_IntMap.__name__ = ["haxe","ds","IntMap"];
haxe_ds_IntMap.__interfaces__ = [IMap];
haxe_ds_IntMap.prototype = {
	set: function(key,value) {
		this.h[key] = value;
	}
	,get: function(key) {
		return this.h[key];
	}
	,__class__: haxe_ds_IntMap
};
var haxe_ds_ObjectMap = function() {
	this.h = { };
	this.h.__keys__ = { };
};
$hxClasses["haxe.ds.ObjectMap"] = haxe_ds_ObjectMap;
haxe_ds_ObjectMap.__name__ = ["haxe","ds","ObjectMap"];
haxe_ds_ObjectMap.__interfaces__ = [IMap];
haxe_ds_ObjectMap.prototype = {
	set: function(key,value) {
		var id = key.__id__ || (key.__id__ = ++haxe_ds_ObjectMap.count);
		this.h[id] = value;
		this.h.__keys__[id] = key;
	}
	,keys: function() {
		var a = [];
		for( var key in this.h.__keys__ ) {
		if(this.h.hasOwnProperty(key)) a.push(this.h.__keys__[key]);
		}
		return HxOverrides.iter(a);
	}
	,__class__: haxe_ds_ObjectMap
};
var haxe_ds_StringMap = function() {
	this.h = { };
};
$hxClasses["haxe.ds.StringMap"] = haxe_ds_StringMap;
haxe_ds_StringMap.__name__ = ["haxe","ds","StringMap"];
haxe_ds_StringMap.__interfaces__ = [IMap];
haxe_ds_StringMap.prototype = {
	set: function(key,value) {
		this.h["$" + key] = value;
	}
	,get: function(key) {
		return this.h["$" + key];
	}
	,exists: function(key) {
		return this.h.hasOwnProperty("$" + key);
	}
	,remove: function(key) {
		key = "$" + key;
		if(!this.h.hasOwnProperty(key)) return false;
		delete(this.h[key]);
		return true;
	}
	,keys: function() {
		var a = [];
		for( var key in this.h ) {
		if(this.h.hasOwnProperty(key)) a.push(key.substr(1));
		}
		return HxOverrides.iter(a);
	}
	,__class__: haxe_ds_StringMap
};
var haxe_io_Eof = function() { };
$hxClasses["haxe.io.Eof"] = haxe_io_Eof;
haxe_io_Eof.__name__ = ["haxe","io","Eof"];
haxe_io_Eof.prototype = {
	toString: function() {
		return "Eof";
	}
	,__class__: haxe_io_Eof
};
var haxe_io_Error = { __ename__ : true, __constructs__ : ["Blocked","Overflow","OutsideBounds","Custom"] };
haxe_io_Error.Blocked = ["Blocked",0];
haxe_io_Error.Blocked.toString = $estr;
haxe_io_Error.Blocked.__enum__ = haxe_io_Error;
haxe_io_Error.Overflow = ["Overflow",1];
haxe_io_Error.Overflow.toString = $estr;
haxe_io_Error.Overflow.__enum__ = haxe_io_Error;
haxe_io_Error.OutsideBounds = ["OutsideBounds",2];
haxe_io_Error.OutsideBounds.toString = $estr;
haxe_io_Error.OutsideBounds.__enum__ = haxe_io_Error;
haxe_io_Error.Custom = function(e) { var $x = ["Custom",3,e]; $x.__enum__ = haxe_io_Error; $x.toString = $estr; return $x; };
var haxe_xml_Parser = function() { };
$hxClasses["haxe.xml.Parser"] = haxe_xml_Parser;
haxe_xml_Parser.__name__ = ["haxe","xml","Parser"];
haxe_xml_Parser.parse = function(str) {
	var doc = Xml.createDocument();
	haxe_xml_Parser.doParse(str,0,doc);
	return doc;
};
haxe_xml_Parser.doParse = function(str,p,parent) {
	if(p == null) p = 0;
	var xml = null;
	var state = 1;
	var next = 1;
	var aname = null;
	var start = 0;
	var nsubs = 0;
	var nbrackets = 0;
	var c = str.charCodeAt(p);
	var buf = new StringBuf();
	while(!(c != c)) {
		switch(state) {
		case 0:
			switch(c) {
			case 10:case 13:case 9:case 32:
				break;
			default:
				state = next;
				continue;
			}
			break;
		case 1:
			switch(c) {
			case 60:
				state = 0;
				next = 2;
				break;
			default:
				start = p;
				state = 13;
				continue;
			}
			break;
		case 13:
			if(c == 60) {
				var child = Xml.createPCData(buf.b + HxOverrides.substr(str,start,p - start));
				buf = new StringBuf();
				parent.addChild(child);
				nsubs++;
				state = 0;
				next = 2;
			} else if(c == 38) {
				buf.addSub(str,start,p - start);
				state = 18;
				next = 13;
				start = p + 1;
			}
			break;
		case 17:
			if(c == 93 && str.charCodeAt(p + 1) == 93 && str.charCodeAt(p + 2) == 62) {
				var child1 = Xml.createCData(HxOverrides.substr(str,start,p - start));
				parent.addChild(child1);
				nsubs++;
				p += 2;
				state = 1;
			}
			break;
		case 2:
			switch(c) {
			case 33:
				if(str.charCodeAt(p + 1) == 91) {
					p += 2;
					if(HxOverrides.substr(str,p,6).toUpperCase() != "CDATA[") throw "Expected <![CDATA[";
					p += 5;
					state = 17;
					start = p + 1;
				} else if(str.charCodeAt(p + 1) == 68 || str.charCodeAt(p + 1) == 100) {
					if(HxOverrides.substr(str,p + 2,6).toUpperCase() != "OCTYPE") throw "Expected <!DOCTYPE";
					p += 8;
					state = 16;
					start = p + 1;
				} else if(str.charCodeAt(p + 1) != 45 || str.charCodeAt(p + 2) != 45) throw "Expected <!--"; else {
					p += 2;
					state = 15;
					start = p + 1;
				}
				break;
			case 63:
				state = 14;
				start = p;
				break;
			case 47:
				if(parent == null) throw "Expected node name";
				start = p + 1;
				state = 0;
				next = 10;
				break;
			default:
				state = 3;
				start = p;
				continue;
			}
			break;
		case 3:
			if(!(c >= 97 && c <= 122 || c >= 65 && c <= 90 || c >= 48 && c <= 57 || c == 58 || c == 46 || c == 95 || c == 45)) {
				if(p == start) throw "Expected node name";
				xml = Xml.createElement(HxOverrides.substr(str,start,p - start));
				parent.addChild(xml);
				state = 0;
				next = 4;
				continue;
			}
			break;
		case 4:
			switch(c) {
			case 47:
				state = 11;
				nsubs++;
				break;
			case 62:
				state = 9;
				nsubs++;
				break;
			default:
				state = 5;
				start = p;
				continue;
			}
			break;
		case 5:
			if(!(c >= 97 && c <= 122 || c >= 65 && c <= 90 || c >= 48 && c <= 57 || c == 58 || c == 46 || c == 95 || c == 45)) {
				var tmp;
				if(start == p) throw "Expected attribute name";
				tmp = HxOverrides.substr(str,start,p - start);
				aname = tmp;
				if(xml.exists(aname)) throw "Duplicate attribute";
				state = 0;
				next = 6;
				continue;
			}
			break;
		case 6:
			switch(c) {
			case 61:
				state = 0;
				next = 7;
				break;
			default:
				throw "Expected =";
			}
			break;
		case 7:
			switch(c) {
			case 34:case 39:
				state = 8;
				start = p;
				break;
			default:
				throw "Expected \"";
			}
			break;
		case 8:
			if(c == str.charCodeAt(start)) {
				var val = HxOverrides.substr(str,start + 1,p - start - 1);
				xml.set(aname,val);
				state = 0;
				next = 4;
			}
			break;
		case 9:
			p = haxe_xml_Parser.doParse(str,p,xml);
			start = p;
			state = 1;
			break;
		case 11:
			switch(c) {
			case 62:
				state = 1;
				break;
			default:
				throw "Expected >";
			}
			break;
		case 12:
			switch(c) {
			case 62:
				if(nsubs == 0) parent.addChild(Xml.createPCData(""));
				return p;
			default:
				throw "Expected >";
			}
			break;
		case 10:
			if(!(c >= 97 && c <= 122 || c >= 65 && c <= 90 || c >= 48 && c <= 57 || c == 58 || c == 46 || c == 95 || c == 45)) {
				if(start == p) throw "Expected node name";
				var v = HxOverrides.substr(str,start,p - start);
				if(v != parent.get_nodeName()) throw "Expected </" + parent.get_nodeName() + ">";
				state = 0;
				next = 12;
				continue;
			}
			break;
		case 15:
			if(c == 45 && str.charCodeAt(p + 1) == 45 && str.charCodeAt(p + 2) == 62) {
				parent.addChild(Xml.createComment(HxOverrides.substr(str,start,p - start)));
				p += 2;
				state = 1;
			}
			break;
		case 16:
			if(c == 91) nbrackets++; else if(c == 93) nbrackets--; else if(c == 62 && nbrackets == 0) {
				parent.addChild(Xml.createDocType(HxOverrides.substr(str,start,p - start)));
				state = 1;
			}
			break;
		case 14:
			if(c == 63 && str.charCodeAt(p + 1) == 62) {
				p++;
				var str1 = HxOverrides.substr(str,start + 1,p - start - 2);
				parent.addChild(Xml.createProcessingInstruction(str1));
				state = 1;
			}
			break;
		case 18:
			if(c == 59) {
				var s = HxOverrides.substr(str,start,p - start);
				if(s.charCodeAt(0) == 35) {
					var i;
					if(s.charCodeAt(1) == 120) i = Std.parseInt("0" + HxOverrides.substr(s,1,s.length - 1)); else i = Std.parseInt(HxOverrides.substr(s,1,s.length - 1));
					buf.add(String.fromCharCode(i));
				} else if(!haxe_xml_Parser.escapes.exists(s)) buf.b += Std.string("&" + s + ";"); else buf.add(haxe_xml_Parser.escapes.get(s));
				start = p + 1;
				state = next;
			}
			break;
		}
		c = StringTools.fastCodeAt(str,++p);
	}
	if(state == 1) {
		start = p;
		state = 13;
	}
	if(state == 13) {
		if(p != start || nsubs == 0) parent.addChild(Xml.createPCData(buf.b + HxOverrides.substr(str,start,p - start)));
		return p;
	}
	throw "Unexpected end";
};
var haxor_component_Camera = function(p_name) {
	haxor_component_Behaviour.call(this,p_name);
};
$hxClasses["haxor.component.Camera"] = haxor_component_Camera;
haxor_component_Camera.__name__ = ["haxor","component","Camera"];
haxor_component_Camera.__properties__ = {set_main:"set_main",get_main:"get_main",get_current:"get_current",get_list:"get_list"}
haxor_component_Camera.get_list = function() {
	return haxor_context_EngineContext.camera.list.slice();
};
haxor_component_Camera.get_current = function() {
	return haxor_component_Camera.m_current;
};
haxor_component_Camera.get_main = function() {
	return haxor_component_Camera.m_main;
};
haxor_component_Camera.set_main = function(v) {
	return haxor_component_Camera.m_main = v;
};
haxor_component_Camera.__super__ = haxor_component_Behaviour;
haxor_component_Camera.prototype = $extend(haxor_component_Behaviour.prototype,{
	get_mask: function() {
		return this.m_mask;
	}
	,set_mask: function(v) {
		if(this.m_mask == v) return v;
		this.m_mask = v;
		var it = this.m_mask;
		this.m_layers = [];
		var _g = 0;
		while(_g < 32) {
			var i = _g++;
			if((it & 1) != 0) this.m_layers.push(1 << i);
			it = it >> 1;
		}
		return v;
	}
	,get_fov: function() {
		return this.m_fov;
	}
	,set_fov: function(v) {
		this.m_fov = v;
		this.m_projection_dirty = true;
		return v;
	}
	,get_near: function() {
		return this.m_near;
	}
	,set_near: function(v) {
		this.m_near = v;
		this.m_projection_dirty = true;
		this.m_proj_uniform_dirty = true;
		return v;
	}
	,get_far: function() {
		return this.m_far;
	}
	,set_far: function(v) {
		this.m_far = v;
		this.m_projection_dirty = true;
		this.m_proj_uniform_dirty = true;
		return v;
	}
	,get_order: function() {
		return this.m_order;
	}
	,set_order: function(v) {
		if(this.m_order == v) return v;
		this.m_order = v;
		haxor_context_EngineContext.camera.SortCameraList();
		return this.m_order;
	}
	,get_pixelViewport: function() {
		return this.m_pixelViewport.get_clone();
	}
	,get_viewport: function() {
		return this.m_viewport.get_clone();
	}
	,set_viewport: function(v) {
		this.m_viewport.SetAABB2(v);
		haxor_context_EngineContext.camera.UpdateViewport(this);
		return v;
	}
	,get_CameraToWorld: function() {
		return this.m_entity.m_transform.get_WorldMatrix();
	}
	,get_WorldToCamera: function() {
		return this.m_entity.m_transform.get_WorldMatrixInverse();
	}
	,get_ProjectionMatrix: function() {
		this.UpdateProjection();
		return this.m_projectionMatrix;
	}
	,get_ProjectionMatrixInverse: function() {
		this.UpdateProjection();
		return this.m_projectionMatrixInverse;
	}
	,get_target: function() {
		return this.m_target;
	}
	,set_target: function(v) {
		this.m_target = v;
		haxor_context_EngineContext.camera.UpdateViewport(this);
		return v;
	}
	,get_quality: function() {
		return this.m_quality;
	}
	,set_quality: function(v) {
		if(v <= 0.0) this.m_quality = 0.0; else if(v >= 1.0) this.m_quality = 1.0; else this.m_quality = v;
		haxor_context_EngineContext.camera.UpdateViewport(this);
		return v;
	}
	,get_captureDepth: function() {
		return this.m_captureDepth;
	}
	,set_captureDepth: function(v) {
		this.m_captureDepth = v;
		haxor_context_EngineContext.camera.ClearTargets(this);
		haxor_context_EngineContext.camera.UpdateViewport(this);
		return v;
	}
	,get_filters: function() {
		return this.m_filters;
	}
	,set_filters: function(v) {
		if(v == null) this.m_filters = []; else this.m_filters = v;
		return this.m_filters;
	}
	,get_frustum: function() {
		this.UpdateProjection();
		return this.m_frustum;
	}
	,OnBuild: function() {
		haxor_component_Behaviour.prototype.OnBuild.call(this);
		haxor_context_EngineContext.camera.Create(this);
		if(haxor_component_Camera.m_main == null) haxor_component_Camera.m_main = this;
		this.m_order = 0;
		this.m_quality = 1.0;
		this.m_pixelViewport = haxor_math_AABB2.get_empty();
		this.m_viewport = haxor_math_AABB2.get_empty();
		this.m_projectionMatrix = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_projectionMatrixInverse = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_skyboxProjection = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_skyboxProjectionInverse = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_fov = 60;
		this.m_near = 0.1;
		this.m_far = 500;
		this.m_filters = [];
		this.background = new haxor_math_Color(0,0,0,1);
		this.clear = haxor_core_ClearFlag.ColorDepth;
		this.set_mask(1);
		this.set_viewport(new haxor_math_AABB2(0,0,1,1));
		this.m_projection_dirty = true;
		this.m_view_uniform_dirty = true;
		this.m_proj_uniform_dirty = true;
		this.m_frustum = [new haxor_math_Vector4(),new haxor_math_Vector4(),new haxor_math_Vector4(),new haxor_math_Vector4(),new haxor_math_Vector4(),new haxor_math_Vector4(),new haxor_math_Vector4(),new haxor_math_Vector4()];
	}
	,WorldToProjection: function(p_world_point,p_result) {
		var p;
		if(p_result == null) p = new haxor_math_Vector4(); else p = p_result;
		p.w = 1.0;
		p.x = p_world_point.x;
		p.y = p_world_point.y;
		p.z = p_world_point.z;
		this.get_WorldToCamera().Transform4x4(p);
		((function($this) {
			var $r;
			$this.UpdateProjection();
			$r = $this.m_projectionMatrix;
			return $r;
		}(this))).Transform4x4(p);
		return p;
	}
	,WorldToDepth: function(p_world_point) {
		var wm = this.get_WorldToCamera();
		return wm.m20 * p_world_point.x + wm.m21 * p_world_point.y + wm.m22 * p_world_point.z + wm.m23;
	}
	,IsCulled: function(p_world_point) {
		return this.WorldToProjection(p_world_point).IsCulled();
	}
	,LookAt: function(p_at,p_up,p_smooth) {
		if(p_smooth == null) p_smooth = 0.0;
		this.m_entity.m_transform.LookAt(p_at,p_up,p_smooth);
	}
	,UpdateProjection: function() {
		if(!this.m_projection_dirty) return;
		this.m_projection_dirty = false;
		this.m_view_uniform_dirty = true;
		haxor_math_Matrix4.Perspective(this.m_fov,this.m_aspect,this.m_near,this.m_far,this.m_projectionMatrix);
		haxor_math_Matrix4.PerspectiveInverse(this.m_fov,this.m_aspect,this.m_near,this.m_far,this.m_projectionMatrixInverse);
		haxor_math_Matrix4.Perspective(this.m_fov,this.m_aspect,0.1,100000.0,this.m_skyboxProjection);
		haxor_math_Matrix4.PerspectiveInverse(this.m_fov,this.m_aspect,0.1,100000.0,this.m_skyboxProjectionInverse);
		var p;
		var iw = 0.0;
		p = this.m_frustum[0];
		p.Set(-1.0,1.0,0.0,1.0);
		this.m_projectionMatrixInverse.Transform4x4(p);
		if(p.w <= 0.0) iw = 0.0; else iw = 1.0 / p.w;
		p.Scale(iw);
		p = this.m_frustum[1];
		p.Set(1.0,1.0,0.0,1.0);
		this.m_projectionMatrixInverse.Transform4x4(p);
		if(p.w <= 0.0) iw = 0.0; else iw = 1.0 / p.w;
		p.Scale(iw);
		p = this.m_frustum[2];
		p.Set(-1.0,-1.0,0.0,1.0);
		this.m_projectionMatrixInverse.Transform4x4(p);
		if(p.w <= 0.0) iw = 0.0; else iw = 1.0 / p.w;
		p.Scale(iw);
		p = this.m_frustum[3];
		p.Set(1.0,-1.0,0.0,1.0);
		this.m_projectionMatrixInverse.Transform4x4(p);
		if(p.w <= 0.0) iw = 0.0; else iw = 1.0 / p.w;
		p.Scale(iw);
		p = this.m_frustum[4];
		p.Set(-1.0,1.0,1.0,1.0);
		this.m_projectionMatrixInverse.Transform4x4(p);
		if(p.w <= 0.0) iw = 0.0; else iw = 1.0 / p.w;
		p.Scale(iw);
		p = this.m_frustum[5];
		p.Set(1.0,1.0,1.0,1.0);
		this.m_projectionMatrixInverse.Transform4x4(p);
		if(p.w <= 0.0) iw = 0.0; else iw = 1.0 / p.w;
		p.Scale(iw);
		p = this.m_frustum[6];
		p.Set(-1.0,-1.0,1.0,1.0);
		this.m_projectionMatrixInverse.Transform4x4(p);
		if(p.w <= 0.0) iw = 0.0; else iw = 1.0 / p.w;
		p.Scale(iw);
		p = this.m_frustum[7];
		p.Set(1.0,-1.0,1.0,1.0);
		this.m_projectionMatrixInverse.Transform4x4(p);
		if(p.w <= 0.0) iw = 0.0; else iw = 1.0 / p.w;
		p.Scale(iw);
	}
	,OnTransformUpdate: function() {
		this.m_view_uniform_dirty = true;
	}
	,OnDestroy: function() {
		haxor_context_EngineContext.camera.Destroy(this);
	}
	,__class__: haxor_component_Camera
	,__properties__: $extend(haxor_component_Behaviour.prototype.__properties__,{get_frustum:"get_frustum",set_filters:"set_filters",get_filters:"get_filters",set_captureDepth:"set_captureDepth",get_captureDepth:"get_captureDepth",set_quality:"set_quality",get_quality:"get_quality",get_ProjectionMatrixInverse:"get_ProjectionMatrixInverse",get_ProjectionMatrix:"get_ProjectionMatrix",get_WorldToCamera:"get_WorldToCamera",get_CameraToWorld:"get_CameraToWorld",set_viewport:"set_viewport",get_viewport:"get_viewport",get_pixelViewport:"get_pixelViewport",set_order:"set_order",get_order:"get_order",set_far:"set_far",get_far:"get_far",set_near:"set_near",get_near:"get_near",set_fov:"set_fov",get_fov:"get_fov",set_mask:"set_mask",get_mask:"get_mask"})
});
var haxor_component_CameraOrbit = function(p_name) {
	haxor_component_Behaviour.call(this,p_name);
};
$hxClasses["haxor.component.CameraOrbit"] = haxor_component_CameraOrbit;
haxor_component_CameraOrbit.__name__ = ["haxor","component","CameraOrbit"];
haxor_component_CameraOrbit.__interfaces__ = [haxor_core_IUpdateable];
haxor_component_CameraOrbit.Create = function(p_distance,p_angle_x,p_angle_y) {
	if(p_angle_y == null) p_angle_y = 0;
	if(p_angle_x == null) p_angle_x = 0;
	if(p_distance == null) p_distance = 1;
	var e = new haxor_core_Entity();
	e.set_name("camera_orbit");
	var c = e.AddComponent(haxor_component_Camera);
	c.background = new haxor_math_Color(0,0,0,1);
	var orbit = e.AddComponent(haxor_component_CameraOrbit);
	orbit.distance = p_distance;
	orbit.smooth = 0;
	orbit.angle = new haxor_math_Vector2(p_angle_x,p_angle_y);
	return orbit;
};
haxor_component_CameraOrbit.__super__ = haxor_component_Behaviour;
haxor_component_CameraOrbit.prototype = $extend(haxor_component_Behaviour.prototype,{
	get_pivot: function() {
		if(this.m_pivot == null) {
			var e = new haxor_core_Entity();
			this.m_pivot = e.m_transform;
			this.m_pivot.set_name(this.m_entity.get_name());
			this.m_pivot.set_parent(this.m_entity.m_transform.m_parent);
			this.m_entity.m_transform.set_parent(this.m_pivot);
			this.m_entity.set_name("camera");
			this.m_pivot.set_position(this.m_entity.m_transform.get_position());
		}
		return this.m_pivot;
	}
	,OnBuild: function() {
		haxor_component_Behaviour.prototype.OnBuild.call(this);
		this.distance = 0.0;
		this.m_pivot = this.get_pivot();
	}
	,OnStart: function() {
		this.m_distance = this.distance;
		if(this.angle == null) this.m_angle = new haxor_math_Vector2(0,0); else this.m_angle = this.angle.get_clone();
		this.m_rotation = new haxor_math_Quaternion(0,0,0,1.0);
		var p = haxor_context_EngineContext.data.get_v3();
		p.Set(0,0,this.m_distance);
		this.m_entity.m_transform.set_localPosition(p);
	}
	,OnUpdate: function() {
		var blend;
		if(this.smooth <= 0) blend = 1.0; else blend = haxor_core_Time.m_delta * this.smooth;
		this.m_angle.x = haxor_math_Mathf.Lerp(this.m_angle.x,this.angle.x,blend);
		this.m_angle.y = haxor_math_Mathf.Lerp(this.m_angle.y,this.angle.y,blend);
		this.m_distance = haxor_math_Mathf.Lerp(this.m_distance,this.distance,blend);
		var q = haxor_context_EngineContext.data.get_q();
		q.SetAxisAngle(new haxor_math_Vector3(0,1,0),this.m_angle.x);
		q.Multiply(haxor_context_EngineContext.data.get_q().SetAxisAngle(new haxor_math_Vector3(1,0,0),-this.m_angle.y));
		this.get_pivot().set_localRotation(q);
		var p = haxor_context_EngineContext.data.get_v3();
		p.Set(0,0,this.m_distance);
		this.m_entity.m_transform.set_localPosition(p);
		if(this.target != null) {
			var p1 = this.get_pivot().get_localPosition();
			p1 = haxor_math_Vector3.Lerp(p1,this.target.get_localPosition(),haxor_core_Time.m_delta * this.smooth);
			this.get_pivot().set_localPosition(p1);
		}
	}
	,__class__: haxor_component_CameraOrbit
	,__properties__: $extend(haxor_component_Behaviour.prototype.__properties__,{get_pivot:"get_pivot"})
});
var haxor_component_CameraOrbitInput = function(p_name) {
	this.rotateSpeed = 0.5;
	this.zoomSpeed = 0.5;
	this.zoom = true;
	this.rotate = true;
	haxor_component_Behaviour.call(this,p_name);
};
$hxClasses["haxor.component.CameraOrbitInput"] = haxor_component_CameraOrbitInput;
haxor_component_CameraOrbitInput.__name__ = ["haxor","component","CameraOrbitInput"];
haxor_component_CameraOrbitInput.__interfaces__ = [haxor_core_IUpdateable];
haxor_component_CameraOrbitInput.__super__ = haxor_component_Behaviour;
haxor_component_CameraOrbitInput.prototype = $extend(haxor_component_Behaviour.prototype,{
	OnStart: function() {
		this.m_orbit = this.m_entity.GetComponent(haxor_component_CameraOrbit);
	}
	,OnUpdate: function() {
		var dx;
		if(haxor_input_Input.get_touches().length == 1) dx = haxor_input_Input.get_touches()[0].delta.x; else dx = haxor_input_Input.deltaMouse.x;
		var dy;
		if(haxor_input_Input.get_touches().length == 1) dy = haxor_input_Input.get_touches()[0].delta.y; else dy = haxor_input_Input.deltaMouse.y;
		if(this.rotate) {
			var is_rotate = haxor_input_Input.Pressed(haxor_input_KeyCode.Mouse0) || haxor_input_Input.get_touches().length == 1;
			if(is_rotate) {
				this.m_orbit.angle.x += -dx * this.rotateSpeed;
				this.m_orbit.angle.y += dy * this.rotateSpeed;
			}
		}
		if(this.zoom) {
			if(Math.abs(haxor_input_Input.wheel) > 0) if(haxor_input_Input.wheel < 0) this.m_orbit.distance += this.zoomSpeed; else this.m_orbit.distance += -this.zoomSpeed;
			if(haxor_input_Input.get_touches().length == 2) this.m_orbit.distance += haxor_input_Input.get_touches()[0].delta.y * this.zoomSpeed * 0.05;
		}
	}
	,__class__: haxor_component_CameraOrbitInput
});
var haxor_component_DataComponent = function() {
	haxor_component_Component.call(this);
	this.data = new haxe_ds_StringMap();
};
$hxClasses["haxor.component.DataComponent"] = haxor_component_DataComponent;
haxor_component_DataComponent.__name__ = ["haxor","component","DataComponent"];
haxor_component_DataComponent.__super__ = haxor_component_Component;
haxor_component_DataComponent.prototype = $extend(haxor_component_Component.prototype,{
	__class__: haxor_component_DataComponent
});
var haxor_component_Renderer = function(p_name) {
	this.m_has_mesh = false;
	haxor_component_Behaviour.call(this,p_name);
};
$hxClasses["haxor.component.Renderer"] = haxor_component_Renderer;
haxor_component_Renderer.__name__ = ["haxor","component","Renderer"];
haxor_component_Renderer.__super__ = haxor_component_Behaviour;
haxor_component_Renderer.prototype = $extend(haxor_component_Behaviour.prototype,{
	get_material: function() {
		return this.m_material;
	}
	,set_material: function(v) {
		if(this.m_material == v) return v;
		this.m_material = v;
		if(v == null) this.m_last_queue = -1; else this.m_last_queue = v.queue;
		haxor_context_EngineContext.renderer.OnMaterialChange(this);
		return v;
	}
	,get_visible: function() {
		return this.m_visible && !this.m_culled;
	}
	,set_visible: function(v) {
		this.m_visible = v;
		return v;
	}
	,OnBuild: function() {
		haxor_component_Behaviour.prototype.OnBuild.call(this);
		this.m_last_queue = -1;
		this.m_visible = true;
		this.m_culled = false;
		haxor_context_EngineContext.renderer.Create(this);
	}
	,OnRender: function() {
		if(this.m_material != null) {
			if(this.m_last_queue != this.m_material.queue) {
				this.m_last_queue = this.m_material.queue;
				haxor_context_EngineContext.renderer.OnMaterialChange(this);
			}
		}
	}
	,UpdateCulling: function() {
		var v0 = this.m_culled;
		var v1 = this.CheckCulling();
		this.m_culled = v1;
		if(v0 != v1) haxor_context_EngineContext.renderer.OnVisibilityChange(this,!v1);
	}
	,CheckCulling: function() {
		return false;
	}
	,OnDestroy: function() {
		haxor_context_EngineContext.renderer.Destroy(this);
	}
	,__class__: haxor_component_Renderer
	,__properties__: $extend(haxor_component_Behaviour.prototype.__properties__,{get_visible:"get_visible",set_material:"set_material",get_material:"get_material"})
});
var haxor_component_MeshRenderer = function(p_name) {
	haxor_component_Renderer.call(this,p_name);
};
$hxClasses["haxor.component.MeshRenderer"] = haxor_component_MeshRenderer;
haxor_component_MeshRenderer.__name__ = ["haxor","component","MeshRenderer"];
haxor_component_MeshRenderer.__super__ = haxor_component_Renderer;
haxor_component_MeshRenderer.prototype = $extend(haxor_component_Renderer.prototype,{
	get_mesh: function() {
		return this.m_mesh;
	}
	,set_mesh: function(v) {
		if(this.m_mesh == v) return v;
		this.m_mesh = v;
		this.UpdateWorldBounds();
		return v;
	}
	,OnBuild: function() {
		this.m_has_mesh = true;
		haxor_component_Renderer.prototype.OnBuild.call(this);
		this.m_ws_center = new haxor_math_Vector3(0,0,0);
		this.m_ws_radius = new haxor_math_Vector3(0,0,0);
		this.m_culling_dirty = false;
	}
	,IsVisible: function(p_camera) {
		var c = p_camera;
		if(c == null) return false;
		if(this.m_mesh == null) return false;
		var ps_center = c.WorldToProjection(haxor_context_EngineContext.data.get_v3().Set3(this.m_ws_center),haxor_context_EngineContext.data.get_v4());
		var w = ps_center.w;
		var p = ps_center;
		if(w <= 0.0) return false;
		if(p.x >= -w) {
			if(p.x <= w) {
				if(p.y >= -w) {
					if(p.y <= w) {
						if(p.z >= -w) {
							if(p.z <= w) return true;
						}
					}
				}
			}
		}
		var v = c.WorldToProjection(haxor_context_EngineContext.data.get_v3().Set3(this.m_ws_radius),haxor_context_EngineContext.data.get_v4());
		var r = Math.sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
		if(p.x + r >= -w) {
			if(p.x - r <= w) {
				if(p.y + r >= -w) {
					if(p.y - r <= w) {
						if(p.z + r >= -w) {
							if(p.z - r <= w) return true;
						}
					}
				}
			}
		}
		return false;
	}
	,CheckCulling: function() {
		var c = haxor_component_Camera.m_current;
		if(c == null) return this.m_culled;
		if(!c.m_view_uniform_dirty) {
			if(!c.m_proj_uniform_dirty) {
				if(!this.m_culling_dirty) return this.m_culled;
			}
		}
		this.UpdateWorldBounds();
		return !this.IsVisible(c);
	}
	,OnTransformUpdate: function() {
		this.m_culling_dirty = true;
	}
	,UpdateWorldBounds: function() {
		if(this.m_mesh != null) {
			haxor_math_AABB3.Center(this.m_mesh.m_bounds,this.m_ws_center);
			this.m_entity.m_transform.get_WorldMatrix().Transform3x4(this.m_ws_center);
			this.m_ws_radius.Set(this.m_mesh.m_bounds.get_width(),this.m_mesh.m_bounds.get_height(),this.m_mesh.m_bounds.get_depth());
			this.m_entity.m_transform.get_WorldMatrix().Transform3x3(this.m_ws_radius);
			var r = this.m_ws_radius.get_length();
			var pmin = haxor_context_EngineContext.data.get_v3();
			var pmax = haxor_context_EngineContext.data.get_v3();
			pmin.Set(this.m_ws_center.x - r,this.m_ws_center.y - r,this.m_ws_center.z - r);
			pmax.Set(this.m_ws_center.x + r,this.m_ws_center.y + r,this.m_ws_center.z + r);
			haxor_context_EngineContext.renderer.UpdateSAP(this.__fcid,this,pmin,pmax);
			this.m_culling_dirty = false;
		}
	}
	,OnRender: function() {
		haxor_component_Renderer.prototype.OnRender.call(this);
		if(this.m_mesh == null) return;
		haxor_graphics_Graphics.Render(this.m_mesh,this.m_material,this.m_entity.m_transform,haxor_component_Camera.m_current);
	}
	,__class__: haxor_component_MeshRenderer
	,__properties__: $extend(haxor_component_Renderer.prototype.__properties__,{set_mesh:"set_mesh",get_mesh:"get_mesh"})
});
var haxor_component_SkinnedMeshRenderer = function(p_name) {
	haxor_component_MeshRenderer.call(this,p_name);
};
$hxClasses["haxor.component.SkinnedMeshRenderer"] = haxor_component_SkinnedMeshRenderer;
haxor_component_SkinnedMeshRenderer.__name__ = ["haxor","component","SkinnedMeshRenderer"];
haxor_component_SkinnedMeshRenderer.__super__ = haxor_component_MeshRenderer;
haxor_component_SkinnedMeshRenderer.prototype = $extend(haxor_component_MeshRenderer.prototype,{
	set_joints: function(v) {
		if(v == null) this.m_joints = []; else this.m_joints = v;
		return this.m_joints;
	}
	,get_joints: function() {
		return this.m_joints;
	}
	,OnBuild: function() {
		haxor_component_MeshRenderer.prototype.OnBuild.call(this);
		this.m_joints = [];
		this.m_buffer = [];
		var _g = 0;
		while(_g < 8192) {
			var i = _g++;
			this.m_buffer.push(0);
		}
		this.m_data = new haxor_graphics_texture_ComputeTexture(1,2048,haxor_core_PixelFormat.Float4);
		this.m_data.set_name("SkinningTexture" + this.get_uid());
	}
	,OnRender: function() {
		if(this.m_material != null) {
			var skm = this.m_mesh;
			var k = 0;
			var jm;
			var bm;
			var f32 = this.m_data.m_data.get_buffer();
			var _g1 = 0;
			var _g = this.m_joints.length;
			while(_g1 < _g) {
				var i = _g1++;
				jm = this.m_joints[i].get_WorldMatrix();
				bm = skm.get_binds()[i];
				var _g2 = 0;
				while(_g2 < 12) {
					var j = _g2++;
					f32.Set(k,jm.GetIndex(j));
					f32.Set(k + 4096,bm.GetIndex(j));
					k++;
				}
			}
			this.m_data.Invalidate();
			this.m_material.SetTexture("Skinning",this.m_data);
		}
		haxor_component_MeshRenderer.prototype.OnRender.call(this);
		var sh = haxor_graphics_Screen.m_height;
		var th = 2048.0;
		haxor_graphics_Graphics.DrawTexture(this.m_data,0,th + 105,256,-th);
	}
	,__class__: haxor_component_SkinnedMeshRenderer
	,__properties__: $extend(haxor_component_MeshRenderer.prototype.__properties__,{set_joints:"set_joints",get_joints:"get_joints"})
});
var haxor_component_Transform = function(p_name) {
	haxor_component_Component.call(this,p_name);
};
$hxClasses["haxor.component.Transform"] = haxor_component_Transform;
haxor_component_Transform.__name__ = ["haxor","component","Transform"];
haxor_component_Transform.__properties__ = {get_root:"get_root"}
haxor_component_Transform.TransformConcat = function(t) {
	var v = t.m_parent.m_worldMatrix;
	var m = t.m_worldMatrix;
	m.m00 = v.m00;
	m.m01 = v.m01;
	m.m02 = v.m02;
	m.m03 = v.m03;
	m.m10 = v.m10;
	m.m11 = v.m11;
	m.m12 = v.m12;
	m.m13 = v.m13;
	m.m20 = v.m20;
	m.m21 = v.m21;
	m.m22 = v.m22;
	m.m23 = v.m23;
	m.MultiplyTransform(t.m_localMatrix);
	t.m_wsp_dirty = true;
	t.m_wsrs_dirty = true;
	t.m_right.Set(m.m00,m.m10,m.m20).Normalize();
	t.m_up.Set(m.m01,m.m11,m.m21).Normalize();
	t.m_forward.Set(m.m02,m.m12,m.m22).Normalize();
	t.m_inverse_dirty = true;
};
haxor_component_Transform.get_root = function() {
	return haxor_component_Transform.m_root;
};
haxor_component_Transform.__super__ = haxor_component_Component;
haxor_component_Transform.prototype = $extend(haxor_component_Component.prototype,{
	get_right: function() {
		this.UpdateWorldMatrix();
		return this.m_right.get_clone();
	}
	,set_right: function(v) {
		return v;
	}
	,get_up: function() {
		this.UpdateWorldMatrix();
		return this.m_up.get_clone();
	}
	,set_up: function(v) {
		return v;
	}
	,get_forward: function() {
		this.UpdateWorldMatrix();
		return this.m_forward.get_inverse();
	}
	,set_forward: function(v) {
		return v;
	}
	,get_parent: function() {
		return this.m_parent;
	}
	,set_parent: function(v) {
		var wp = this.get_position();
		var wr = this.get_rotation();
		var ws = this.get_scale();
		if(this.m_parent != null) HxOverrides.remove(this.m_parent.m_hierarchy,this);
		if(v == null) this.m_parent = haxor_component_Transform.m_root; else this.m_parent = v;
		this.m_parent.m_hierarchy.push(this);
		return this.m_parent;
	}
	,get_childCount: function() {
		return this.m_hierarchy.length;
	}
	,get_localPosition: function() {
		return this.m_localPosition.get_clone();
	}
	,set_localPosition: function(v) {
		var dx = v.x - this.m_localPosition.x;
		var dy = v.y - this.m_localPosition.y;
		var dz = v.z - this.m_localPosition.z;
		if(Math.abs(dx) < 0.0001) {
			if(Math.abs(dy) < 0.0001) {
				if(Math.abs(dz) < 0.0001) return v;
			}
		}
		this.m_localPosition.Set3(v);
		this.m_lmt_dirty = true;
		this.Invalidate();
		return v;
	}
	,get_localRotation: function() {
		return this.m_localRotation.get_clone();
	}
	,set_localRotation: function(v) {
		var dx = v.x - this.m_localRotation.x;
		var dy = v.y - this.m_localRotation.y;
		var dz = v.z - this.m_localRotation.z;
		var dw = v.w - this.m_localRotation.w;
		if(Math.abs(dx) < 0.0001) {
			if(Math.abs(dy) < 0.0001) {
				if(Math.abs(dz) < 0.0001) {
					if(Math.abs(dw) < 0.0001) return v;
				}
			}
		}
		this.m_localRotation.SetQuaternion(v);
		this.m_lmrs_dirty = true;
		this.Invalidate();
		return v;
	}
	,get_localEuler: function() {
		return this.m_localRotation.get_euler();
	}
	,set_localEuler: function(v) {
		this.set_localRotation(haxor_math_Quaternion.FromEuler(v,haxor_context_EngineContext.data.get_q()));
		return v;
	}
	,get_localScale: function() {
		return this.m_localScale.get_clone();
	}
	,set_localScale: function(v) {
		var dx = v.x - this.m_localScale.x;
		var dy = v.y - this.m_localScale.y;
		var dz = v.z - this.m_localScale.z;
		if(Math.abs(dx) < 0.0001) {
			if(Math.abs(dy) < 0.0001) {
				if(Math.abs(dz) < 0.0001) return v;
			}
		}
		this.m_localScale.Set3(v);
		this.m_lmrs_dirty = true;
		this.Invalidate();
		return v;
	}
	,get_position: function() {
		this.UpdateWorldMatrix();
		this.UpdateWSP();
		return this.m_position.get_clone();
	}
	,set_position: function(v) {
		this.set_localPosition(this.m_parent.get_WorldMatrixInverse().Transform3x4(haxor_context_EngineContext.data.get_v3().Set3(v)));
		return v;
	}
	,get_rotation: function() {
		this.UpdateWorldMatrix();
		this.UpdateWSRS();
		return this.m_rotation.get_clone();
	}
	,set_rotation: function(v) {
		this.UpdateWorldMatrix();
		this.UpdateWSRS();
		var iq = haxor_math_Quaternion.Inverse(this.m_rotation,haxor_context_EngineContext.data.get_q());
		this.set_localRotation(haxor_context_EngineContext.data.get_q().SetQuaternion(v).Multiply(iq));
		return v;
	}
	,get_euler: function() {
		return this.get_rotation().get_euler();
	}
	,set_euler: function(v) {
		this.set_rotation(haxor_math_Quaternion.FromEuler(v,haxor_context_EngineContext.data.get_q()));
		return v;
	}
	,get_scale: function() {
		this.UpdateWorldMatrix();
		this.UpdateWSRS();
		return this.m_scale.get_clone();
	}
	,get_WorldMatrix: function() {
		this.UpdateWorldMatrix();
		return this.m_worldMatrix;
	}
	,get_WorldMatrixInverse: function() {
		this.UpdateWorldMatrix();
		if(this.m_inverse_dirty) {
			haxor_math_Matrix4.GetInverseTransform(this.m_worldMatrix,this.m_worldMatrixInverse);
			this.m_inverse_dirty = false;
		}
		return this.m_worldMatrixInverse;
	}
	,OnBuild: function() {
		haxor_component_Component.prototype.OnBuild.call(this);
		this.__cid = haxor_context_EngineContext.transform.tid.get_id();
		this.m_localPosition = new haxor_math_Vector3(0,0,0);
		this.m_localRotation = new haxor_math_Quaternion(0,0,0,1.0);
		this.m_localScale = new haxor_math_Vector3(1,1,1);
		this.m_position = new haxor_math_Vector3(0,0,0);
		this.m_rotation = new haxor_math_Quaternion(0,0,0,1.0);
		this.m_scale = new haxor_math_Vector3(1,1,1);
		this.m_lmt_dirty = false;
		this.m_lmrs_dirty = false;
		this.m_dirty = false;
		this.m_inverse_dirty = false;
		this.m_wsp_dirty = false;
		this.m_wsrs_dirty = false;
		this.m_uniform_dirty = true;
		this.m_right = new haxor_math_Vector3(1,0,0);
		this.m_up = new haxor_math_Vector3(0,1,0);
		this.m_forward = haxor_math_Vector3.get_forward();
		this.m_localMatrix = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_worldMatrixInverse = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_worldMatrix = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_hierarchy = [];
		if(haxor_component_Transform.m_root != null) this.set_parent(null); else haxor_component_Transform.m_root = this;
	}
	,UpdateLMT: function() {
		this.m_localMatrix.m03 = this.m_localPosition.x;
		this.m_localMatrix.m13 = this.m_localPosition.y;
		this.m_localMatrix.m23 = this.m_localPosition.z;
	}
	,UpdateWSP: function() {
		if(this.m_wsp_dirty) {
			this.m_position.x = this.m_worldMatrix.m03;
			this.m_position.y = this.m_worldMatrix.m13;
			this.m_position.z = this.m_worldMatrix.m23;
			this.m_wsp_dirty = false;
		}
	}
	,UpdateLMRS: function() {
		var sx = this.m_localScale.x;
		var sy = this.m_localScale.y;
		var sz = this.m_localScale.z;
		var r = haxor_math_Matrix4.FromQuaternion(this.m_localRotation,haxor_context_EngineContext.data.get_m4());
		var l = this.m_localMatrix;
		l.m00 = r.m00 * sx;
		l.m01 = r.m01 * sy;
		l.m02 = r.m02 * sz;
		l.m10 = r.m10 * sx;
		l.m11 = r.m11 * sy;
		l.m12 = r.m12 * sz;
		l.m20 = r.m20 * sx;
		l.m21 = r.m21 * sy;
		l.m22 = r.m22 * sz;
	}
	,UpdateWSRS: function() {
		if(this.m_wsrs_dirty) {
			var m = this.m_worldMatrix;
			var c0 = haxor_context_EngineContext.data.get_v3().Set(m.m00,m.m10,m.m20);
			var c1 = haxor_context_EngineContext.data.get_v3().Set(m.m01,m.m11,m.m21);
			var c2 = haxor_context_EngineContext.data.get_v3().Set(m.m02,m.m12,m.m22);
			var l0 = Math.sqrt(c0.x * c0.x + c0.y * c0.y + c0.z * c0.z);
			var l1 = Math.sqrt(c1.x * c1.x + c1.y * c1.y + c1.z * c1.z);
			var l2 = Math.sqrt(c2.x * c2.x + c2.y * c2.y + c2.z * c2.z);
			this.m_scale.x = l0;
			this.m_scale.y = l1;
			this.m_scale.z = l2;
			if(l0 <= 0.0) l0 = 0.0; else l0 = 1.0 / l0;
			if(l1 <= 0.0) l1 = 0.0; else l1 = 1.0 / l1;
			if(l2 <= 0.0) l2 = 0.0; else l2 = 1.0 / l2;
			c0.Scale(l0);
			c1.Scale(l1);
			c2.Scale(l2);
			var r = haxor_context_EngineContext.data.get_m4().Set(c0.x,c1.x,c2.x,0.0,c0.y,c1.y,c2.y,0.0,c0.z,c1.z,c2.z,0.0,0.0,0.0,0.0,1.0);
			haxor_math_Quaternion.FromMatrix4(r,this.m_rotation);
			this.m_wsrs_dirty = false;
		}
	}
	,UpdateWorldMatrix: function() {
		var need_concat = this.m_dirty;
		if(this.m_lmt_dirty) {
			this.UpdateLMT();
			this.m_lmt_dirty = false;
			need_concat = true;
		}
		if(this.m_lmrs_dirty) {
			this.UpdateLMRS();
			this.m_lmrs_dirty = false;
			need_concat = true;
		}
		if(this.m_parent != null) {
			if(this.m_dirty) this.m_parent.UpdateWorldMatrix();
			this.m_dirty = false;
			if(need_concat) haxor_component_Transform.TransformConcat(this);
		}
	}
	,Invalidate: function() {
		if(this.m_dirty) return;
		this.m_uniform_dirty = true;
		this.m_dirty = true;
		haxor_context_EngineContext.transform.OnChange(this);
		var _g1 = 0;
		var _g = this.m_hierarchy.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_hierarchy[i].Invalidate();
		}
	}
	,LookAt: function(p_at,p_up,p_smooth) {
		if(p_smooth == null) p_smooth = 0.0;
		var p = this.m_entity.m_transform.get_position();
		var r = haxor_context_EngineContext.data.get_q();
		var q = haxor_math_Quaternion.LookAt(p,p_at,p_up,haxor_context_EngineContext.data.get_q());
		if(p_smooth > 0) r = haxor_math_Quaternion.Lerp(r,q,p_smooth * haxor_core_Time.m_delta,haxor_context_EngineContext.data.get_q()); else r = q;
		this.m_entity.m_transform.set_rotation(r);
	}
	,GetChild: function(p_index) {
		return this.m_hierarchy[p_index];
	}
	,GetChildByName: function(p_name) {
		var _g1 = 0;
		var _g = this.m_hierarchy.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.m_hierarchy[i].get_name() == p_name) return this.m_hierarchy[i];
		}
		return null;
	}
	,Navigate: function(p_path) {
		var tk = p_path.split(".");
		var t = this;
		while(tk.length > 0) {
			var p = tk.shift();
			t = t.GetChildByName(p);
			if(t == null) return null;
		}
		return t;
	}
	,Search: function(p_name,p_exact) {
		if(p_exact == null) p_exact = true;
		var _g = this;
		var res = null;
		this.Traverse(function(it,d) {
			if(it == _g) return true;
			if(res != null) return true;
			if(p_exact) {
				if(it.get_name() == p_name) res = it;
			} else if(it.get_name().indexOf(p_name) >= 0) res = it;
			return true;
		});
		return res;
	}
	,GetPathToRoot: function() {
		var p = this.m_parent;
		var res = [];
		while(p != null) {
			res.push(p);
			p = p.m_parent;
		}
		res.reverse();
		return res;
	}
	,OutputHierarchy: function(p_show_transform,p_show_world) {
		if(p_show_world == null) p_show_world = false;
		if(p_show_transform == null) p_show_transform = true;
		var d0 = 0;
		var hs = "";
		this.Traverse(function(t,d) {
			var tab = "";
			var td = d;
			var d1 = Math.max(0,td - d0);
			var _g = 0;
			while(_g < d1) {
				var i = _g++;
				tab += " ";
			}
			hs += tab + t.get_name() + " ";
			if(p_show_transform) hs += t.get_position().ToString() + t.get_rotation().ToString() + t.get_scale().ToString();
			if(p_show_world) hs += t.get_WorldMatrix().ToString(true,3);
			hs += "\n";
			return true;
		});
		return hs;
	}
	,Traverse: function(p_callback) {
		this.TraverseStep(this,0,p_callback);
	}
	,TraverseStep: function(p_child,p_depth,p_callback) {
		if(p_callback(p_child,p_depth)) {
			var _g1 = 0;
			var _g = p_child.m_hierarchy.length;
			while(_g1 < _g) {
				var i = _g1++;
				this.TraverseStep(p_child.GetChild(i),p_depth + 1,p_callback);
			}
		}
	}
	,OnDestroy: function() {
		haxor_context_EngineContext.transform.tid.set_id(this.__cid);
	}
	,ToString: function(p_use_local,p_places) {
		if(p_places == null) p_places = 2;
		if(p_use_local == null) p_use_local = false;
		var p;
		if(p_use_local) p = this.get_localPosition(); else p = this.get_position();
		var e;
		if(p_use_local) e = this.get_localEuler(); else e = this.get_euler();
		var s;
		if(p_use_local) s = this.get_localScale(); else s = this.get_scale();
		return this.get_name() + " " + p.ToString(p_places) + "" + e.ToString(p_places) + "" + s.ToString(p_places);
	}
	,__class__: haxor_component_Transform
	,__properties__: $extend(haxor_component_Component.prototype.__properties__,{get_WorldMatrixInverse:"get_WorldMatrixInverse",get_WorldMatrix:"get_WorldMatrix",get_scale:"get_scale",set_euler:"set_euler",get_euler:"get_euler",set_rotation:"set_rotation",get_rotation:"get_rotation",set_position:"set_position",get_position:"get_position",set_localScale:"set_localScale",get_localScale:"get_localScale",set_localEuler:"set_localEuler",get_localEuler:"get_localEuler",set_localRotation:"set_localRotation",get_localRotation:"get_localRotation",set_localPosition:"set_localPosition",get_localPosition:"get_localPosition",get_childCount:"get_childCount",set_parent:"set_parent",get_parent:"get_parent",get_forward:"get_forward",get_up:"get_up",get_right:"get_right"})
});
var haxor_component_animation_Animation = function() {
	haxor_component_Behaviour.call(this);
	haxor_component_animation_Animation.m_list.push(this);
	this.clips = [];
	this.m_time = 0;
	this.reverse = false;
	this.m_clock = haxor_core_Time.m_elapsed;
	this.m_fade_elapsed = 0.0;
	this.m_fade_duration = 0.0;
};
$hxClasses["haxor.component.animation.Animation"] = haxor_component_animation_Animation;
haxor_component_animation_Animation.__name__ = ["haxor","component","animation","Animation"];
haxor_component_animation_Animation.Update = function() {
	if(haxor_component_animation_Animation.m_list.length > 0) {
		var steps = Std["int"](Math.max(haxor_component_animation_Animation.m_list.length / 2,1));
		var _g = 0;
		while(_g < steps) {
			var i = _g++;
			haxor_component_animation_Animation.m_list[haxor_component_animation_Animation.m_iterator].Animate();
			haxor_component_animation_Animation.m_iterator = (haxor_component_animation_Animation.m_iterator + 1) % haxor_component_animation_Animation.m_list.length;
		}
	}
};
haxor_component_animation_Animation.Initialize = function() {
	haxor_component_animation_Animation.m_list = [];
	haxor_component_animation_Animation.m_iterator = 0;
};
haxor_component_animation_Animation.__super__ = haxor_component_Behaviour;
haxor_component_animation_Animation.prototype = $extend(haxor_component_Behaviour.prototype,{
	get_time: function() {
		return this.m_time;
	}
	,set_time: function(v) {
		this.m_time = v;
		var _g1 = 0;
		var _g = this.clips.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.clips[i].Sample(this.m_time);
		}
		return v;
	}
	,get_playing: function() {
		var _g1 = 0;
		var _g = this.clips.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.clips[i].playing) return true;
		}
		return false;
	}
	,Contains: function(p_clip) {
		var _g1 = 0;
		var _g = this.clips.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.clips[i] == p_clip) return true;
		}
		return false;
	}
	,Add: function(p_clip) {
		if(this.Contains(p_clip)) return;
		this.clips.push(p_clip);
	}
	,Remove: function(p_clip) {
		if(!this.Contains(p_clip)) return;
		HxOverrides.remove(this.clips,p_clip);
	}
	,Get: function(p_clip_name) {
		var _g1 = 0;
		var _g = this.clips.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.clips[i].get_name() == p_clip_name) return this.clips[i];
		}
		return null;
	}
	,Fade: function(p_clip,p_time,p_fade) {
		if(p_fade == null) p_fade = 0.0;
		if(p_time == null) p_time = 0.0;
		this.Play(p_clip,p_time);
		this.m_fade_elapsed = 0.0;
		this.m_fade_duration = p_fade;
		this.m_fade_clip = p_clip;
	}
	,Play: function(p_clip,p_time) {
		if(p_time == null) p_time = 0.0;
		if(!this.Contains(p_clip)) return;
		this.m_time = p_time;
		p_clip.Sample(p_time);
		p_clip.playing = true;
	}
	,Stop: function(p_clip) {
		if(p_clip == null) {
			var _g1 = 0;
			var _g = this.clips.length;
			while(_g1 < _g) {
				var i = _g1++;
				this.clips[i].playing = false;
			}
			return;
		}
		if(!this.Contains(p_clip)) return;
		p_clip.playing = false;
	}
	,Animate: function() {
		var is_playing = false;
		if(this.m_fade_elapsed >= this.m_fade_duration) this.m_fade_elapsed = this.m_fade_duration;
		var w;
		if(this.m_fade_duration <= 0.0) w = 1.0; else w = this.m_fade_elapsed / this.m_fade_duration;
		var spd = 1.0;
		var _g1 = 0;
		var _g = this.clips.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = this.clips[i];
			if(c.playing) {
				c.Sample(this.get_time(),w);
				spd = c.speed;
				is_playing = true;
			}
		}
		if(w >= 1.0) {
			this.m_fade_clip = null;
			this.m_fade_duration = this.m_fade_elapsed = 0.0;
		}
		var dt = haxor_core_Time.m_elapsed - this.m_clock;
		this.m_clock = haxor_core_Time.m_elapsed;
		if(is_playing) {
			this.m_time += (this.reverse?-dt:dt) * spd;
			this.m_fade_elapsed += dt;
		}
	}
	,__class__: haxor_component_animation_Animation
	,__properties__: $extend(haxor_component_Behaviour.prototype.__properties__,{get_playing:"get_playing",set_time:"set_time",get_time:"get_time"})
});
var haxor_component_animation_AnimationClip = function() {
	haxor_core_Resource.call(this);
	this.tracks = [];
	this.speed = 1.0;
	this.playing = false;
	this.m_length = 0;
	this.wrap = haxor_core_AnimationWrap.Clamp;
	this.m_events = [];
	this.m_last_frame = 0;
};
$hxClasses["haxor.component.animation.AnimationClip"] = haxor_component_animation_AnimationClip;
haxor_component_animation_AnimationClip.__name__ = ["haxor","component","animation","AnimationClip"];
haxor_component_animation_AnimationClip.__super__ = haxor_core_Resource;
haxor_component_animation_AnimationClip.prototype = $extend(haxor_core_Resource.prototype,{
	get_length: function() {
		return this.m_length;
	}
	,AddEvent: function(p_frame,p_listener,p_repeat,p_args) {
		if(p_repeat == null) p_repeat = 0;
		var e = new haxor_component_animation_AnimationEvent(p_frame,p_listener,p_repeat,p_args);
		this.m_events.push(e);
		this.m_events.sort(function(a,b) {
			if(a.frame < b.frame) return -1; else return 1;
		});
	}
	,RemoveEvent: function(p_frame) {
		if(p_frame == null) p_frame = -1;
		var i = 0;
		while(i < this.m_events.length) {
			if(this.m_events[i].frame == p_frame || p_frame < 0) {
				var x = this.m_events[i--];
				HxOverrides.remove(this.m_events,x);
			}
			i++;
		}
	}
	,Add: function(p_target,p_property) {
		var ct = new haxor_component_animation_ClipTrack();
		ct.target = p_target;
		ct.property = p_property;
		this.tracks.push(ct);
		this.UpdateLength();
		return ct;
	}
	,Remove: function(p_target,p_property) {
		if(p_property == null) p_property = "";
		var _g1 = 0;
		var _g = this.tracks.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.tracks[i].target == p_target) {
				if(p_property == "") HxOverrides.remove(this.tracks,this.tracks[i]); else if(p_property == p_property) HxOverrides.remove(this.tracks,this.tracks[i]);
			}
		}
		this.UpdateLength();
	}
	,Sample: function(p_time,p_weight) {
		if(p_weight == null) p_weight = 1.0;
		if(!this.playing) return;
		var spd = Math.max(0,this.speed);
		var t = p_time;
		var _g = this.wrap;
		switch(_g[1]) {
		case 0:
			t = haxor_math_Mathf.Min(Math.max(t,0),this.get_length());
			break;
		case 1:
			t = haxor_math_Mathf.Loop(t,0,this.get_length());
			break;
		case 2:
			t = haxor_math_Mathf.Oscilate(t,0,this.get_length());
			break;
		}
		var frame = -1;
		var _g1 = 0;
		var _g2 = this.tracks.length;
		while(_g1 < _g2) {
			var i = _g1++;
			frame = this.tracks[i].Sample(t,p_weight);
		}
		if(frame >= 0) {
			var i1 = 0;
			if(this.m_last_frame != frame) {
				while(i1 < this.m_events.length) {
					var ev = this.m_events[i1];
					var ef = ev.frame;
					if(ef >= this.m_last_frame) {
						if(ef <= frame) {
							if(!ev.Dispatch()) {
								HxOverrides.remove(this.m_events,ev);
								i1--;
							}
						}
					}
					i1++;
				}
				this.m_last_frame = frame;
			}
		}
	}
	,Split: function(p_start,p_end) {
		var nc = new haxor_component_animation_AnimationClip();
		nc.speed = this.speed;
		nc.wrap = this.wrap;
		nc.playing = this.playing;
		var _g1 = 0;
		var _g = this.tracks.length;
		while(_g1 < _g) {
			var i = _g1++;
			var ct = this.tracks[i];
			var nct = ct.Split(p_start,p_end);
			nc.tracks.push(nct);
		}
		nc.UpdateLength();
		return nc;
	}
	,UpdateLength: function() {
		this.m_length = 0;
		var _g1 = 0;
		var _g = this.tracks.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_length = Math.max(this.tracks[i].get_length(),this.m_length);
		}
	}
	,__class__: haxor_component_animation_AnimationClip
	,__properties__: $extend(haxor_core_Resource.prototype.__properties__,{get_length:"get_length"})
});
var haxor_component_animation_AnimationEvent = function(p_frame,p_listener,p_repeat,p_args) {
	if(p_repeat == null) p_repeat = 0;
	this.frame = p_frame;
	this.listener = p_listener;
	if(p_args == null) this.args = []; else this.args = p_args;
	this.repeat = p_repeat;
};
$hxClasses["haxor.component.animation.AnimationEvent"] = haxor_component_animation_AnimationEvent;
haxor_component_animation_AnimationEvent.__name__ = ["haxor","component","animation","AnimationEvent"];
haxor_component_animation_AnimationEvent.prototype = {
	Dispatch: function() {
		if(this.listener != null) {
			this.listener(this);
			if(this.repeat <= 0) return true;
			this.repeat--;
			if(this.repeat <= 0) return false;
			return true;
		}
		return false;
	}
	,__class__: haxor_component_animation_AnimationEvent
};
var haxor_component_animation_ClipTrack = function() {
	this.target = null;
	this.keyframes = [];
	this.property = "";
	this.m_head = 0;
	this.m_length = 0;
};
$hxClasses["haxor.component.animation.ClipTrack"] = haxor_component_animation_ClipTrack;
haxor_component_animation_ClipTrack.__name__ = ["haxor","component","animation","ClipTrack"];
haxor_component_animation_ClipTrack.prototype = {
	get_length: function() {
		return this.m_length;
	}
	,Add: function(p_time,p_value) {
		var k = null;
		if(typeof(p_value) == "number") {
			var nk = k = new haxor_component_animation_FloatKeyFrame();
			nk.time = p_time;
			nk.value = p_value;
		} else if(js_Boot.__instanceof(p_value,haxor_math_Vector3)) {
			var nk1 = k = new haxor_component_animation_Vector3KeyFrame();
			nk1.time = p_time;
			nk1.value = p_value;
		} else if(js_Boot.__instanceof(p_value,haxor_math_Quaternion)) {
			var nk2 = k = new haxor_component_animation_QuaternionKeyFrame();
			nk2.time = p_time;
			nk2.value = p_value;
		}
		if(k != null) {
			this.keyframes.push(k);
			this.m_length = Math.max(k.time,this.m_length);
		}
		return k;
	}
	,Sample: function(p_time,p_weight) {
		if(p_weight == null) p_weight = 1.0;
		if(this.keyframes.length <= 0) return 0;
		if(this.keyframes.length <= 1) {
			Reflect.setProperty(this.target,this.property,this.keyframes[0].Sample());
			return 0;
		}
		var mid = this.keyframes.length / 2 | 0;
		var step = this.keyframes.length / 2 | 0;
		var i0 = -1;
		var _g1 = 0;
		var _g = this.keyframes.length;
		while(_g1 < _g) {
			var i = _g1++;
			i0 = haxor_math_Mathf.ClampInt(mid,0,this.keyframes.length - 1);
			var i1 = haxor_math_Mathf.ClampInt(mid + 1,0,this.keyframes.length - 1);
			var k0 = this.keyframes[i0];
			var k1 = this.keyframes[i1];
			if(p_time < k0.time) {
				step = step / 2;
				mid -= step;
				continue;
			}
			if(p_time > k1.time) {
				step = step / 2;
				mid += step;
				continue;
			}
			var dt = k1.time - k0.time;
			var r;
			if(dt <= 0) r = 0.0; else r = (p_time - k0.time) / dt;
			if(r <= 0.0) r = 0.0; else if(r >= 1.0) r = 1.0; else r = r;
			var nk = k0.Blend(k1,r);
			if(nk.changed) {
				var v = Reflect.getProperty(this.target,this.property);
				Reflect.setProperty(this.target,this.property,nk.Sample(v,p_weight));
			}
			break;
		}
		return i0;
	}
	,Split: function(p_start,p_end) {
		var nct = new haxor_component_animation_ClipTrack();
		nct.target = this.target;
		nct.property = this.property;
		var i0 = Math.min(p_start,this.keyframes.length - 1);
		var i1 = Math.min(p_end,this.keyframes.length - 1);
		var kf = this.keyframes[i0];
		if(kf == null) return nct;
		var t0 = kf.time;
		var _g = i0;
		while(_g < i1) {
			var i = _g++;
			kf = this.keyframes[i];
			if(kf != null) nct.Add(kf.time - t0,kf.Sample());
		}
		return nct;
	}
	,Clear: function() {
		this.keyframes = [];
		this.m_length = 0;
	}
	,__class__: haxor_component_animation_ClipTrack
	,__properties__: {get_length:"get_length"}
};
var haxor_component_animation_KeyFrame = function() {
	this.time = 0;
	this.changed = false;
};
$hxClasses["haxor.component.animation.KeyFrame"] = haxor_component_animation_KeyFrame;
haxor_component_animation_KeyFrame.__name__ = ["haxor","component","animation","KeyFrame"];
haxor_component_animation_KeyFrame.prototype = {
	Blend: function(b,r) {
		return null;
	}
	,Sample: function(v,w) {
		if(w == null) w = 1.0;
		return null;
	}
	,__class__: haxor_component_animation_KeyFrame
};
var haxor_component_animation_FloatKeyFrame = function() {
	haxor_component_animation_KeyFrame.call(this);
	this.value = 0;
};
$hxClasses["haxor.component.animation.FloatKeyFrame"] = haxor_component_animation_FloatKeyFrame;
haxor_component_animation_FloatKeyFrame.__name__ = ["haxor","component","animation","FloatKeyFrame"];
haxor_component_animation_FloatKeyFrame.__super__ = haxor_component_animation_KeyFrame;
haxor_component_animation_FloatKeyFrame.prototype = $extend(haxor_component_animation_KeyFrame.prototype,{
	Blend: function(b,r) {
		this.changed = false;
		var ka = this;
		var kb = b;
		var va = ka.value;
		var vb = kb.value;
		if(Math.abs(va - vb) < 0.0001) return ka;
		var k = haxor_component_animation_FloatKeyFrame.m_temp;
		k.value = haxor_math_Mathf.Lerp(ka.value,kb.value,r);
		k.changed = true;
		return k;
	}
	,Sample: function(v,w) {
		if(w == null) w = 1.0;
		if(v == null) return this.value; else return haxor_math_Mathf.Lerp(v,this.value,w);
	}
	,__class__: haxor_component_animation_FloatKeyFrame
});
var haxor_math_Vector3 = function(p_x,p_y,p_z) {
	if(p_z == null) p_z = 0;
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.x = p_x;
	this.y = p_y;
	this.z = p_z;
};
$hxClasses["haxor.math.Vector3"] = haxor_math_Vector3;
haxor_math_Vector3.__name__ = ["haxor","math","Vector3"];
haxor_math_Vector3.__properties__ = {get_forward:"get_forward",get_up:"get_up",get_right:"get_right",get_one:"get_one",get_zero:"get_zero",get_temp:"get_temp"}
haxor_math_Vector3.get_temp = function() {
	return haxor_context_EngineContext.data.get_v3();
};
haxor_math_Vector3.get_zero = function() {
	return new haxor_math_Vector3(0,0,0);
};
haxor_math_Vector3.get_one = function() {
	return new haxor_math_Vector3(1,1,1);
};
haxor_math_Vector3.get_right = function() {
	return new haxor_math_Vector3(1,0,0);
};
haxor_math_Vector3.get_up = function() {
	return new haxor_math_Vector3(0,1,0);
};
haxor_math_Vector3.get_forward = function() {
	return new haxor_math_Vector3(0,0,1);
};
haxor_math_Vector3.Dot = function(p_a,p_b) {
	return p_a.x * p_b.x + p_a.y * p_b.y + p_a.z * p_b.z;
};
haxor_math_Vector3.Distance = function(p_a,p_b) {
	var dx = p_a.x - p_b.x;
	var dy = p_a.y - p_b.y;
	var dz = p_a.z - p_b.z;
	return Math.sqrt(dx * dx + dy * dy + dz * dz);
};
haxor_math_Vector3.Cross = function(p_a,p_b,p_result) {
	if(p_result == null) p_result = new haxor_math_Vector3(); else p_result = p_result;
	return p_result.Set(p_a.y * p_b.z - p_a.z * p_b.y,p_a.z * p_b.x - p_a.x * p_b.z,p_a.x * p_b.y - p_a.y * p_b.x);
};
haxor_math_Vector3.Lerp = function(p_a,p_b,p_r,p_result) {
	if(p_result == null) p_result = new haxor_math_Vector3(); else p_result = p_result;
	return p_result.Set(p_a.x + (p_b.x - p_a.x) * p_r,p_a.y + (p_b.y - p_a.y) * p_r,p_a.z + (p_b.z - p_a.z) * p_r);
};
haxor_math_Vector3.Min = function(p_a,p_b,p_result) {
	if(p_result == null) p_result = new haxor_math_Vector3(); else p_result = p_result;
	p_result.x = Math.min(p_a.x,p_b.x);
	p_result.y = Math.min(p_a.y,p_b.y);
	p_result.z = Math.min(p_a.z,p_b.z);
	return p_result;
};
haxor_math_Vector3.Max = function(p_a,p_b,p_result) {
	if(p_result == null) p_result = new haxor_math_Vector3(); else p_result = p_result;
	p_result.x = Math.max(p_a.x,p_b.x);
	p_result.y = Math.max(p_a.y,p_b.y);
	p_result.z = Math.max(p_a.z,p_b.z);
	return p_result;
};
haxor_math_Vector3.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	return new haxor_math_Vector3(0,0,0).Set(Std.parseFloat(StringTools.trim(tk[0])),Std.parseFloat(StringTools.trim(tk[1])),Std.parseFloat(StringTools.trim(tk[2])));
};
haxor_math_Vector3.prototype = {
	get_clone: function() {
		return new haxor_math_Vector3(this.x,this.y,this.z);
	}
	,get_color: function() {
		return new haxor_math_Color(this.x,this.y,this.z);
	}
	,get_xzy: function() {
		return new haxor_math_Vector3(this.x,this.z,this.y);
	}
	,get_yxz: function() {
		return new haxor_math_Vector3(this.y,this.z,this.x);
	}
	,get_yzx: function() {
		return new haxor_math_Vector3(this.y,this.z,this.x);
	}
	,get_zxy: function() {
		return new haxor_math_Vector3(this.z,this.x,this.y);
	}
	,get_zyx: function() {
		return new haxor_math_Vector3(this.z,this.y,this.x);
	}
	,get_xy: function() {
		return new haxor_math_Vector2(this.x,this.y);
	}
	,get_xz: function() {
		return new haxor_math_Vector2(this.x,this.z);
	}
	,get_yx: function() {
		return new haxor_math_Vector2(this.y,this.x);
	}
	,get_yz: function() {
		return new haxor_math_Vector2(this.y,this.z);
	}
	,get_zx: function() {
		return new haxor_math_Vector2(this.z,this.x);
	}
	,get_zy: function() {
		return new haxor_math_Vector2(this.z,this.y);
	}
	,get_length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
	}
	,get_lengthSqr: function() {
		return this.x * this.x + this.y * this.y + this.z * this.z;
	}
	,get_normalized: function() {
		return new haxor_math_Vector3(this.x,this.y,this.z).Normalize();
	}
	,get_inverse: function() {
		return new haxor_math_Vector3(this.x,this.y,this.z).Invert();
	}
	,Set: function(p_x,p_y,p_z) {
		if(p_z == null) p_z = 0;
		if(p_y == null) p_y = 0;
		if(p_x == null) p_x = 0;
		this.x = p_x;
		this.y = p_y;
		this.z = p_z;
		return this;
	}
	,Set2: function(v) {
		this.x = v.x;
		this.y = v.y;
		return this;
	}
	,Set3: function(v) {
		this.x = v.x;
		this.y = v.y;
		this.z = v.z;
		return this;
	}
	,Set4: function(v) {
		this.x = v.x;
		this.y = v.y;
		this.z = v.z;
		return this;
	}
	,SetColor: function(v) {
		this.x = v.r;
		this.y = v.g;
		this.z = v.b;
		return this;
	}
	,Get: function(p) {
		if(p == 0) return this.x; else if(p == 1) return this.y; else return this.z;
	}
	,Add: function(p_v) {
		this.x += p_v.x;
		this.y += p_v.y;
		this.z += p_v.z;
		return this;
	}
	,Add3: function(p_x,p_y,p_z) {
		this.x += p_x;
		this.y += p_y;
		this.z += p_z;
		return this;
	}
	,Sub: function(p_v) {
		this.x -= p_v.x;
		this.y -= p_v.y;
		this.z -= p_v.z;
		return this;
	}
	,Multiply: function(p_v) {
		this.x *= p_v.x;
		this.y *= p_v.y;
		this.z *= p_v.z;
		return this;
	}
	,Step: function(p_to,p_step) {
		var vx = p_to.x - this.x;
		var vy = p_to.y - this.y;
		var vz = p_to.z - this.z;
		var l = Math.sqrt(vx * vx + vy * vy + vz * vz);
		if(l <= 0.0001) return false;
		var s;
		if(p_step > l) s = l; else s = p_step;
		l = s / l;
		vx *= l;
		vy *= l;
		vz *= l;
		this.x += vx;
		this.y += vy;
		this.z += vz;
		return true;
	}
	,Reflect: function(p_normal) {
		var d = Math.min(0.0,p_normal.x * this.x + p_normal.y * this.y + p_normal.z * this.z) * 2.0;
		this.x += -p_normal.x * d;
		this.y += -p_normal.y * d;
		this.z += -p_normal.z * d;
		return this;
	}
	,Invert: function() {
		this.x = -this.x;
		this.y = -this.y;
		this.z = -this.z;
		return this;
	}
	,Scale: function(p_s) {
		this.x *= p_s;
		this.y *= p_s;
		this.z *= p_s;
		return this;
	}
	,Normalize: function() {
		var l = Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
		if(l <= 0) return this;
		this.x *= l = 1.0 / l;
		this.y *= l;
		this.z *= l;
		return this;
	}
	,ToArray: function() {
		return [this.x,this.y,this.z];
	}
	,ToString: function(p_places) {
		if(p_places == null) p_places = 2;
		return "[" + haxor_math_Mathf.RoundPlaces(this.x,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.y,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.z,p_places) + "]";
	}
	,__class__: haxor_math_Vector3
	,__properties__: {get_inverse:"get_inverse",get_normalized:"get_normalized",get_lengthSqr:"get_lengthSqr",get_length:"get_length",get_zy:"get_zy",get_zx:"get_zx",get_yz:"get_yz",get_yx:"get_yx",get_xz:"get_xz",get_xy:"get_xy",get_zyx:"get_zyx",get_zxy:"get_zxy",get_yzx:"get_yzx",get_yxz:"get_yxz",get_xzy:"get_xzy",get_color:"get_color",get_clone:"get_clone"}
};
var haxor_component_animation_Vector3KeyFrame = function() {
	haxor_component_animation_KeyFrame.call(this);
	this.value = new haxor_math_Vector3();
};
$hxClasses["haxor.component.animation.Vector3KeyFrame"] = haxor_component_animation_Vector3KeyFrame;
haxor_component_animation_Vector3KeyFrame.__name__ = ["haxor","component","animation","Vector3KeyFrame"];
haxor_component_animation_Vector3KeyFrame.__super__ = haxor_component_animation_KeyFrame;
haxor_component_animation_Vector3KeyFrame.prototype = $extend(haxor_component_animation_KeyFrame.prototype,{
	Blend: function(b,r) {
		this.changed = false;
		var ka = this;
		var kb = b;
		var va = ka.value;
		var vb = kb.value;
		if(Math.abs(va.x - vb.x) < 0.0001) {
			if(Math.abs(va.y - vb.y) < 0.0001) {
				if(Math.abs(va.z - vb.z) < 0.0001) return ka;
			}
		}
		var k = haxor_component_animation_Vector3KeyFrame.m_temp;
		k.value = haxor_math_Vector3.Lerp(va,vb,r,k.value);
		k.changed = true;
		return k;
	}
	,Sample: function(v,w) {
		if(w == null) w = 1.0;
		if(v == null) return this.value; else return haxor_math_Vector3.Lerp(v,this.value,w,haxor_context_EngineContext.data.get_v3());
	}
	,__class__: haxor_component_animation_Vector3KeyFrame
});
var haxor_math_Quaternion = function(p_x,p_y,p_z,p_w) {
	if(p_w == null) p_w = 1.0;
	if(p_z == null) p_z = 0;
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.x = p_x;
	this.y = p_y;
	this.z = p_z;
	this.w = p_w;
};
$hxClasses["haxor.math.Quaternion"] = haxor_math_Quaternion;
haxor_math_Quaternion.__name__ = ["haxor","math","Quaternion"];
haxor_math_Quaternion.__properties__ = {get_identity:"get_identity",get_temp:"get_temp"}
haxor_math_Quaternion.get_temp = function() {
	return haxor_context_EngineContext.data.get_q();
};
haxor_math_Quaternion.get_identity = function() {
	return new haxor_math_Quaternion(0,0,0,1.0);
};
haxor_math_Quaternion.FromEuler = function(p_euler,p_result) {
	var r;
	if(p_result == null) r = new haxor_math_Quaternion(); else r = p_result;
	var c = haxor_context_EngineContext.data.get_v3();
	var s = haxor_context_EngineContext.data.get_v3();
	var k = 0.0087266462599716477;
	var e = haxor_context_EngineContext.data.get_v3().Set(p_euler.x * k,p_euler.y * k,p_euler.z * k);
	c.Set(Math.cos(e.x),Math.cos(e.y),Math.cos(e.z));
	s.Set(Math.sin(e.x),Math.sin(e.y),Math.sin(e.z));
	r.x = s.x * c.y * c.z - c.x * s.y * s.z;
	r.y = c.x * s.y * c.z + s.x * c.y * s.z;
	r.z = c.x * c.y * s.z - s.x * s.y * c.z;
	r.w = c.x * c.y * c.z + s.x * s.y * s.z;
	return r;
};
haxor_math_Quaternion.ToEuler = function(p_quaternion,p_result) {
	var q = p_quaternion;
	var r;
	if(p_result == null) r = new haxor_math_Vector3(); else r = p_result;
	var test = q.x * q.y + q.z * q.w;
	if(test > 0.499) {
		r.y = 2 * Math.atan2(q.x,q.w) * 57.295779513082320876798154814105;
		r.z = Math.PI * 0.5 * 57.295779513082320876798154814105;
		r.x = 0;
		return r;
	}
	if(test < -0.499) {
		r.y = -2. * Math.atan2(q.x,q.w);
		r.z = -Math.PI * 0.5 * 57.295779513082320876798154814105;
		r.x = 0;
		return r;
	}
	var sqx = q.x * q.x;
	var sqy = q.y * q.y;
	var sqz = q.z * q.z;
	r.y = Math.atan2(2.0 * q.y * q.w - 2.0 * q.x * q.z,1.0 - 2.0 * sqy - 2.0 * sqz) * 57.295779513082320876798154814105;
	r.z = Math.asin(2.0 * test) * 57.295779513082320876798154814105;
	r.x = Math.atan2(2.0 * q.x * q.w - 2.0 * q.y * q.z,1.0 - 2.0 * sqx - 2.0 * sqz) * 57.295779513082320876798154814105;
	return r;
};
haxor_math_Quaternion.FromMatrix4 = function(p_matrix,p_result) {
	var r;
	if(p_result == null) r = new haxor_math_Quaternion(); else r = p_result;
	var v = p_matrix;
	var fourXSquaredMinus1 = v.m00 - v.m11 - v.m22;
	var fourYSquaredMinus1 = v.m11 - v.m00 - v.m22;
	var fourZSquaredMinus1 = v.m22 - v.m00 - v.m11;
	var fourWSquaredMinus1 = v.m00 + v.m11 + v.m22;
	var biggestIndex = 0;
	var fourBiggestSquaredMinus1 = fourWSquaredMinus1;
	if(fourXSquaredMinus1 > fourBiggestSquaredMinus1) {
		fourBiggestSquaredMinus1 = fourXSquaredMinus1;
		biggestIndex = 1;
	}
	if(fourYSquaredMinus1 > fourBiggestSquaredMinus1) {
		fourBiggestSquaredMinus1 = fourYSquaredMinus1;
		biggestIndex = 2;
	}
	if(fourZSquaredMinus1 > fourBiggestSquaredMinus1) {
		fourBiggestSquaredMinus1 = fourZSquaredMinus1;
		biggestIndex = 3;
	}
	var biggestVal = Math.sqrt(fourBiggestSquaredMinus1 + 1.0) * 0.5;
	var mult = 0.25 / biggestVal;
	switch(biggestIndex) {
	case 0:
		r.w = biggestVal;
		r.x = (v.m21 - v.m12) * mult;
		r.y = (v.m02 - v.m20) * mult;
		r.z = (v.m10 - v.m01) * mult;
		break;
	case 1:
		r.w = (v.m21 - v.m12) * mult;
		r.x = biggestVal;
		r.y = (v.m10 + v.m01) * mult;
		r.z = (v.m02 + v.m20) * mult;
		break;
	case 2:
		r.w = (v.m02 - v.m20) * mult;
		r.x = (v.m10 + v.m01) * mult;
		r.y = biggestVal;
		r.z = (v.m21 + v.m12) * mult;
		break;
	case 3:
		r.w = (v.m10 - v.m01) * mult;
		r.x = (v.m02 + v.m20) * mult;
		r.y = (v.m21 + v.m12) * mult;
		r.z = biggestVal;
		break;
	}
	return r;
};
haxor_math_Quaternion.Dot = function(p_a,p_b) {
	return p_a.x * p_b.x + p_a.y * p_b.y + p_a.z * p_b.z + p_a.w * p_b.w;
};
haxor_math_Quaternion.DeltaRotation = function(p_a,p_b,p_result) {
	var r;
	if(p_result == null) r = new haxor_math_Quaternion(); else r = p_result;
	haxor_math_Quaternion.Inverse(p_a,r);
	r.Multiply(p_b);
	return r;
};
haxor_math_Quaternion.Inverse = function(p_q,p_result) {
	var d = p_q.x * p_q.x + p_q.y * p_q.y + p_q.z * p_q.z + p_q.w * p_q.w;
	if(d <= 0.0) d = 0.0; else d = 1.0 / d;
	var r;
	if(p_result == null) r = new haxor_math_Quaternion(); else r = p_result;
	return r.Set(-p_q.x * d,-p_q.y * d,-p_q.z * d,p_q.w * d);
};
haxor_math_Quaternion.Lerp = function(p_a,p_b,p_ratio,p_result) {
	var c;
	if(p_result == null) c = new haxor_math_Quaternion(); else c = p_result;
	var ca = new haxor_math_Quaternion(p_a.x,p_a.y,p_a.z,p_a.w);
	var dot = p_a.x * p_b.x + p_a.y * p_b.y + p_a.z * p_b.z + p_a.w * p_b.w;
	if(dot < 0.0) {
		ca.w = -ca.w;
		ca.x = -ca.x;
		ca.y = -ca.y;
		ca.z = -ca.z;
	}
	c.x = ca.x + (p_b.x - ca.x) * p_ratio;
	c.y = ca.y + (p_b.y - ca.y) * p_ratio;
	c.z = ca.z + (p_b.z - ca.z) * p_ratio;
	c.w = ca.w + (p_b.w - ca.w) * p_ratio;
	c.Normalize();
	return c;
};
haxor_math_Quaternion.Slerp = function(p_a,p_b,p_ratio) {
	var qm = new haxor_math_Quaternion();
	var z = haxor_context_EngineContext.data.get_q().SetQuaternion(p_b);
	var cosTheta = p_a.x * p_b.x + p_a.y * p_b.y + p_a.z * p_b.z + p_a.w * p_b.w;
	if(cosTheta < 0.0) {
		z.Invert();
		cosTheta = -cosTheta;
	}
	if(cosTheta > 0.9999) qm.Set(haxor_math_Mathf.Lerp(p_a.x,z.x,p_ratio),haxor_math_Mathf.Lerp(p_a.y,z.y,p_ratio),haxor_math_Mathf.Lerp(p_a.z,z.z,p_ratio),haxor_math_Mathf.Lerp(p_a.w,z.w,p_ratio)); else {
		var angle = Math.acos(cosTheta);
		var s = 1.0 / Math.sin(angle);
		var s0 = Math.sin((1.0 - p_ratio) * angle);
		var s1 = Math.sin(p_ratio * angle);
		qm.x = (s0 * p_a.x + s1 * z.x) * s;
		qm.y = (s0 * p_a.y + s1 * z.y) * s;
		qm.z = (s0 * p_a.z + s1 * z.z) * s;
		qm.w = (s0 * p_a.w + s1 * z.w) * s;
	}
	return qm;
};
haxor_math_Quaternion.FromAxisAngle = function(p_axis,p_angle) {
	p_angle = p_angle * 0.5 * 0.01745329251994329576923690768489;
	var l = Math.sqrt(p_axis.x * p_axis.x + p_axis.y * p_axis.y + p_axis.z * p_axis.z);
	if(haxor_math_Mathf.Abs(l - 1.0) > 0.0001) p_axis.Normalize();
	var s = Math.sin(p_angle);
	return new haxor_math_Quaternion(p_axis.x * s,p_axis.y * s,p_axis.z * s,Math.cos(p_angle));
};
haxor_math_Quaternion.LookAt = function(p_eye,p_at,p_up,p_result) {
	return haxor_math_Quaternion.FromMatrix4(haxor_math_Matrix4.LookAt(p_eye,p_at,p_up,haxor_context_EngineContext.data.get_m4()),p_result);
};
haxor_math_Quaternion.LookRotation = function(p_forward,p_up) {
	return haxor_math_Matrix4.LookRotation(p_forward,p_up,haxor_context_EngineContext.data.get_m4()).get_quaternion();
};
haxor_math_Quaternion.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	return new haxor_math_Quaternion(0,0,0,1.0).Set(Std.parseFloat(StringTools.trim(tk[0])),Std.parseFloat(StringTools.trim(tk[1])),Std.parseFloat(StringTools.trim(tk[2])),Std.parseFloat(StringTools.trim(tk[3])));
};
haxor_math_Quaternion.prototype = {
	get_matrix: function() {
		return haxor_math_Matrix4.FromQuaternion(this);
	}
	,set_matrix: function(v) {
		haxor_math_Quaternion.FromMatrix4(v,this);
		return v;
	}
	,get_euler: function() {
		return haxor_math_Quaternion.ToEuler(this);
	}
	,set_euler: function(v) {
		haxor_math_Quaternion.FromEuler(v,this);
		return v;
	}
	,get_clone: function() {
		return new haxor_math_Quaternion(this.x,this.y,this.z,this.w);
	}
	,get_xyzw: function() {
		return new haxor_math_Vector4(this.x,this.y,this.z,this.w);
	}
	,get_length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
	}
	,get_normalized: function() {
		return new haxor_math_Quaternion(this.x,this.y,this.z,this.w).Normalize();
	}
	,Set: function(p_x,p_y,p_z,p_w) {
		if(p_w == null) p_w = 1.0;
		if(p_z == null) p_z = 0;
		if(p_y == null) p_y = 0;
		if(p_x == null) p_x = 0;
		this.x = p_x;
		this.y = p_y;
		this.z = p_z;
		this.w = p_w;
		return this;
	}
	,SetQuaternion: function(p_q) {
		this.x = p_q.x;
		this.y = p_q.y;
		this.z = p_q.z;
		this.w = p_q.w;
		return this;
	}
	,Normalize: function() {
		var l = Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
		if(l <= 0) {
			this.x = this.y = this.z = 0.0;
			this.w = 1.0;
			return this;
		}
		this.x *= l = 1.0 / l;
		this.y *= l;
		this.z *= l;
		this.w *= l;
		return this;
	}
	,get_conjugate: function() {
		return new haxor_math_Quaternion(-this.x,-this.y,-this.z,this.w);
	}
	,get_inverse: function() {
		return haxor_math_Quaternion.Inverse(this);
	}
	,Invert: function() {
		this.x = -this.x;
		this.y = -this.y;
		this.z = -this.z;
		this.w = -this.w;
		return this;
	}
	,Scale: function(p_v) {
		this.x *= p_v;
		this.y *= p_v;
		this.z *= p_v;
		this.w *= p_v;
		return this;
	}
	,Multiply: function(p_v,p_normalize) {
		if(p_normalize == null) p_normalize = false;
		var vx = this.w * p_v.x + this.x * p_v.w + this.y * p_v.z - this.z * p_v.y;
		var vy = this.w * p_v.y + this.y * p_v.w + this.z * p_v.x - this.x * p_v.z;
		var vz = this.w * p_v.z + this.z * p_v.w + this.x * p_v.y - this.y * p_v.x;
		var vw = this.w * p_v.w - this.x * p_v.x - this.y * p_v.y - this.z * p_v.z;
		this.x = vx;
		this.y = vy;
		this.z = vz;
		this.w = vw;
		if(p_normalize) return this.Normalize(); else return this;
	}
	,Transform: function(p_v) {
		var l = Math.sqrt(p_v.x * p_v.x + p_v.y * p_v.y + p_v.z * p_v.z);
		var nl;
		if(l <= 0.0) nl = 0.0; else nl = 1.0 / l;
		p_v.x *= nl;
		p_v.y *= nl;
		p_v.z *= nl;
		var qv = haxor_context_EngineContext.data.get_q().Set(p_v.x,p_v.y,p_v.z,0);
		var a = haxor_context_EngineContext.data.get_q().SetQuaternion(this);
		var c = haxor_context_EngineContext.data.get_q().Set(-this.x,-this.y,-this.z,this.w);
		a.Multiply(qv.Multiply(c));
		p_v.x = a.x * l;
		p_v.y = a.y * l;
		p_v.z = a.z * l;
		return p_v;
	}
	,Delta: function(p_q) {
		return this.SetQuaternion(haxor_math_Quaternion.DeltaRotation(this,p_q,haxor_context_EngineContext.data.get_q()));
	}
	,SetAxisAngle: function(p_axis,p_angle) {
		p_angle = p_angle * 0.5 * 0.01745329251994329576923690768489;
		var l = Math.sqrt(p_axis.x * p_axis.x + p_axis.y * p_axis.y + p_axis.z * p_axis.z);
		if(haxor_math_Mathf.Abs(l - 1.0) > 0.0001) p_axis.Normalize();
		var s = Math.sin(p_angle);
		return this.Set(p_axis.x * s,p_axis.y * s,p_axis.z * s,Math.cos(p_angle));
	}
	,ToArray: function() {
		return [this.x,this.y,this.z,this.w];
	}
	,ToString: function(p_places) {
		if(p_places == null) p_places = 2;
		return "[" + haxor_math_Mathf.RoundPlaces(this.x,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.y,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.z,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.w,p_places) + "]";
	}
	,__class__: haxor_math_Quaternion
	,__properties__: {get_inverse:"get_inverse",get_conjugate:"get_conjugate",get_normalized:"get_normalized",get_length:"get_length",get_xyzw:"get_xyzw",get_clone:"get_clone",set_euler:"set_euler",get_euler:"get_euler",set_matrix:"set_matrix",get_matrix:"get_matrix"}
};
var haxor_component_animation_QuaternionKeyFrame = function() {
	haxor_component_animation_KeyFrame.call(this);
	this.value = new haxor_math_Quaternion(0,0,0,1.0);
};
$hxClasses["haxor.component.animation.QuaternionKeyFrame"] = haxor_component_animation_QuaternionKeyFrame;
haxor_component_animation_QuaternionKeyFrame.__name__ = ["haxor","component","animation","QuaternionKeyFrame"];
haxor_component_animation_QuaternionKeyFrame.__super__ = haxor_component_animation_KeyFrame;
haxor_component_animation_QuaternionKeyFrame.prototype = $extend(haxor_component_animation_KeyFrame.prototype,{
	Blend: function(b,r) {
		this.changed = true;
		var ka = this;
		var kb = b;
		var va = ka.value;
		var vb = kb.value;
		if(Math.abs(va.x - vb.x) < 0.0001) {
			if(Math.abs(va.y - vb.y) < 0.0001) {
				if(Math.abs(va.z - vb.z) < 0.0001) {
					if(Math.abs(va.w - vb.w) < 0.0001) return ka;
				}
			}
		}
		var k = haxor_component_animation_QuaternionKeyFrame.m_temp;
		k.value = haxor_math_Quaternion.Lerp(va,vb,r,k.value);
		k.changed = true;
		return k;
	}
	,Sample: function(v,w) {
		if(w == null) w = 1.0;
		if(v == null) return this.value; else return haxor_math_Quaternion.Lerp(v,this.value,w,haxor_context_EngineContext.data.get_q());
	}
	,__class__: haxor_component_animation_QuaternionKeyFrame
});
var haxor_math_Color = function(p_r,p_g,p_b,p_a) {
	if(p_a == null) p_a = 1;
	if(p_b == null) p_b = 0;
	if(p_g == null) p_g = 0;
	if(p_r == null) p_r = 0;
	this.r = p_r;
	this.g = p_g;
	this.b = p_b;
	this.a = p_a;
};
$hxClasses["haxor.math.Color"] = haxor_math_Color;
haxor_math_Color.__name__ = ["haxor","math","Color"];
haxor_math_Color.__properties__ = {get_gray90:"get_gray90",get_gray75:"get_gray75",get_gray50:"get_gray50",get_gray25:"get_gray25",get_gray10:"get_gray10",get_empty:"get_empty",get_white:"get_white",get_black:"get_black",get_magenta:"get_magenta",get_blue:"get_blue",get_cyan:"get_cyan",get_green:"get_green",get_yellow:"get_yellow",get_red:"get_red",get_temp:"get_temp"}
haxor_math_Color.get_temp = function() {
	return haxor_context_EngineContext.data.get_c();
};
haxor_math_Color.get_red = function() {
	return new haxor_math_Color(1.0,0,0,1);
};
haxor_math_Color.get_yellow = function() {
	return new haxor_math_Color(1,1,0,1);
};
haxor_math_Color.get_green = function() {
	return new haxor_math_Color(0,1,0,1);
};
haxor_math_Color.get_cyan = function() {
	return new haxor_math_Color(0,1,1,1);
};
haxor_math_Color.get_blue = function() {
	return new haxor_math_Color(0,0,1,1);
};
haxor_math_Color.get_magenta = function() {
	return new haxor_math_Color(1,0,1,1);
};
haxor_math_Color.get_black = function() {
	return new haxor_math_Color(0,0,0,1);
};
haxor_math_Color.get_white = function() {
	return new haxor_math_Color(1,1,1,1);
};
haxor_math_Color.get_empty = function() {
	return new haxor_math_Color(0,0,0,0);
};
haxor_math_Color.get_gray10 = function() {
	return new haxor_math_Color(0.1,0.1,0.1,1);
};
haxor_math_Color.get_gray25 = function() {
	return new haxor_math_Color(0.25,0.25,0.25,1);
};
haxor_math_Color.get_gray50 = function() {
	return new haxor_math_Color(0.5,0.5,0.5,1);
};
haxor_math_Color.get_gray75 = function() {
	return new haxor_math_Color(0.75,0.75,0.75,1);
};
haxor_math_Color.get_gray90 = function() {
	return new haxor_math_Color(0.9,0.9,0.9,1);
};
haxor_math_Color.FromHex = function(p_hex) {
	var c = new haxor_math_Color();
	if(p_hex.length == 10) c.set_argb(Std.parseInt(p_hex)); else c.set_rgb(Std.parseInt(p_hex));
	return c;
};
haxor_math_Color.FromBytes = function(p_r,p_g,p_b,p_a) {
	if(p_a == null) p_a = 255.0;
	if(p_b == null) p_b = 0;
	if(p_g == null) p_g = 0;
	if(p_r == null) p_r = 0;
	return new haxor_math_Color(p_r * 0.00392156863,p_g * 0.00392156863,p_b * 0.00392156863,p_a * 0.00392156863);
};
haxor_math_Color.Lerp = function(a,b,r) {
	return new haxor_math_Color(haxor_math_Mathf.Lerp(a.r,b.r,r),haxor_math_Mathf.Lerp(a.g,b.g,r),haxor_math_Mathf.Lerp(a.b,b.b,r),haxor_math_Mathf.Lerp(a.a,b.a,r));
};
haxor_math_Color.Sample = function(g,r) {
	var pos = g.length - 1;
	pos *= r * 0.9999;
	var i0 = pos | 0;
	var i1 = (i0 + 1) % g.length;
	r = pos - Math.floor(pos);
	var c0 = g[i0];
	var c1 = g[i1];
	return haxor_math_Color.Lerp(c0,c1,r);
};
haxor_math_Color.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	return new haxor_math_Color(0,0,0,1).Set(Std.parseFloat(StringTools.trim(tk[0])),Std.parseFloat(StringTools.trim(tk[1])),Std.parseFloat(StringTools.trim(tk[2])),Std.parseFloat(StringTools.trim(tk[3])));
};
haxor_math_Color.prototype = {
	get_clone: function() {
		return new haxor_math_Color(this.r,this.g,this.b,this.a);
	}
	,get_xyz: function() {
		return new haxor_math_Vector3(this.r,this.g,this.b);
	}
	,get_xyzw: function() {
		return new haxor_math_Vector4(this.r,this.g,this.b,this.a);
	}
	,get_argb: function() {
		var rb = this.r * 255.0;
		var gb = this.g * 255.0;
		var bb = this.b * 255.0;
		var ab = this.a * 255.0;
		return ab << 24 | rb << 16 | gb << 8 | bb;
	}
	,set_argb: function(v) {
		this.a = (v >> 24 & 255) * 0.00392156863;
		this.r = (v >> 16 & 255) * 0.00392156863;
		this.g = (v >> 8 & 255) * 0.00392156863;
		this.b = (v & 255) * 0.00392156863;
		return v;
	}
	,get_css: function() {
		return "rgba(" + (this.r * 255 | 0) + "," + (this.g * 255 | 0) + "," + (this.b * 255 | 0) + "," + this.a + ")";
	}
	,get_rgba: function() {
		var rb = this.r * 255.0;
		var gb = this.g * 255.0;
		var bb = this.b * 255.0;
		var ab = this.a * 255.0;
		return rb << 24 | gb << 16 | bb << 8 | ab;
	}
	,set_rgba: function(v) {
		this.r = (v >> 24 & 255) * 0.00392156863;
		this.g = (v >> 16 & 255) * 0.00392156863;
		this.b = (v >> 8 & 255) * 0.00392156863;
		this.a = (v & 255) * 0.00392156863;
		return v;
	}
	,get_rgb: function() {
		var rb = this.r * 255.0;
		var gb = this.g * 255.0;
		var bb = this.b * 255.0;
		return rb << 16 | gb << 8 | bb;
	}
	,set_rgb: function(v) {
		this.r = (v >> 16 & 255) * 0.00392156863;
		this.g = (v >> 8 & 255) * 0.00392156863;
		this.b = (v & 255) * 0.00392156863;
		return v;
	}
	,get_luminance: function() {
		return this.r * 0.3 + this.g * 0.59 + this.b * 0.11;
	}
	,get_negative: function() {
		return new haxor_math_Color(1.0 - this.r,1.0 - this.g,1.0 - this.b,1.0 - this.a);
	}
	,Set: function(p_r,p_g,p_b,p_a) {
		if(p_a == null) p_a = 1;
		if(p_b == null) p_b = 0;
		if(p_g == null) p_g = 0;
		if(p_r == null) p_r = 0;
		this.r = p_r;
		this.g = p_g;
		this.b = p_b;
		this.a = p_a;
		return this;
	}
	,Set3: function(v) {
		this.r = v.x;
		this.g = v.y;
		this.b = v.z;
		return this;
	}
	,Set4: function(v) {
		this.r = v.x;
		this.g = v.y;
		this.b = v.z;
		this.a = v.w;
		return this;
	}
	,SetColor: function(p_color) {
		this.r = p_color.r;
		this.g = p_color.g;
		this.b = p_color.b;
		this.a = p_color.a;
		return this;
	}
	,Get: function(p) {
		if(p == 0) return this.r; else if(p == 1) return this.g; else if(p == 2) return this.b; else return this.a;
	}
	,Add: function(p_v) {
		this.r += p_v.r;
		this.g += p_v.g;
		this.b += p_v.b;
		this.a += p_v.a;
		return this;
	}
	,Sub: function(p_v) {
		this.r -= p_v.r;
		this.g -= p_v.g;
		this.b -= p_v.b;
		this.a -= p_v.a;
		return this;
	}
	,Multiply: function(p_v) {
		this.r *= p_v.r;
		this.g *= p_v.g;
		this.b *= p_v.b;
		this.a *= p_v.a;
		return this;
	}
	,MultiplyRGB: function(p_v) {
		this.r *= p_v.r;
		this.g *= p_v.g;
		this.b *= p_v.b;
		return this;
	}
	,Scale: function(p_s) {
		this.r *= p_s;
		this.g *= p_s;
		this.b *= p_s;
		this.a *= p_s;
		return this;
	}
	,ScaleRGB: function(p_s) {
		this.r *= p_s;
		this.g *= p_s;
		this.b *= p_s;
		return this;
	}
	,ToArray: function() {
		return [this.r,this.g,this.b,this.a];
	}
	,ToString: function(p_places) {
		if(p_places == null) p_places = 2;
		return "[" + haxor_math_Mathf.RoundPlaces(this.r,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.g,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.b,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.a,p_places) + "]";
	}
	,__class__: haxor_math_Color
	,__properties__: {get_negative:"get_negative",get_luminance:"get_luminance",set_rgb:"set_rgb",get_rgb:"get_rgb",set_rgba:"set_rgba",get_rgba:"get_rgba",get_css:"get_css",set_argb:"set_argb",get_argb:"get_argb",get_xyzw:"get_xyzw",get_xyz:"get_xyz",get_clone:"get_clone"}
};
var haxor_component_light_Light = function() {
	if(haxor_component_light_Light.m_list == null) haxor_component_light_Light.m_list = [];
	if(haxor_component_light_Light.m_buffer == null) haxor_component_light_Light.m_buffer = new haxor_io_FloatArray(12 * haxor_component_light_Light.max);
	haxor_component_light_Light.m_list.push(this);
	haxor_component_Behaviour.call(this);
	this.color = new haxor_math_Color(1,1,1,1);
	this.intensity = 1.0;
};
$hxClasses["haxor.component.light.Light"] = haxor_component_light_Light;
haxor_component_light_Light.__name__ = ["haxor","component","light","Light"];
haxor_component_light_Light.__properties__ = {get_list:"get_list"}
haxor_component_light_Light.get_list = function() {
	var l = new Array();
	if(haxor_component_light_Light.m_list == null) return l;
	var i = 0;
	while(i < haxor_component_light_Light.m_list.length) {
		l.push(haxor_component_light_Light.m_list[i]);
		i++;
	}
	return l;
};
haxor_component_light_Light.SetLightData = function(p_id,p_type,p_intensity,p_radius,p_atten,p_x,p_y,p_z,p_r,p_g,p_b,p_a) {
	var pos = p_id * 12;
	haxor_component_light_Light.m_buffer.Set(pos,p_type);
	haxor_component_light_Light.m_buffer.Set(pos + 1,p_intensity);
	haxor_component_light_Light.m_buffer.Set(pos + 2,p_radius);
	haxor_component_light_Light.m_buffer.Set(pos + 3,p_atten);
	haxor_component_light_Light.m_buffer.Set(pos + 4,p_x);
	haxor_component_light_Light.m_buffer.Set(pos + 5,p_y);
	haxor_component_light_Light.m_buffer.Set(pos + 6,p_z);
	haxor_component_light_Light.m_buffer.Set(pos + 8,p_r);
	haxor_component_light_Light.m_buffer.Set(pos + 9,p_g);
	haxor_component_light_Light.m_buffer.Set(pos + 10,p_b);
	haxor_component_light_Light.m_buffer.Set(pos + 11,p_a);
};
haxor_component_light_Light.__super__ = haxor_component_Behaviour;
haxor_component_light_Light.prototype = $extend(haxor_component_Behaviour.prototype,{
	OnDestroy: function() {
		haxor_component_Behaviour.prototype.OnDestroy.call(this);
		HxOverrides.remove(haxor_component_light_Light.m_list,this);
	}
	,__class__: haxor_component_light_Light
});
var haxor_component_light_PointLight = function() {
	haxor_component_light_Light.call(this);
	this.atten = 1.0;
	this.radius = 1.0;
};
$hxClasses["haxor.component.light.PointLight"] = haxor_component_light_PointLight;
haxor_component_light_PointLight.__name__ = ["haxor","component","light","PointLight"];
haxor_component_light_PointLight.Create = function(p_color,p_intensity,p_atten,p_radius) {
	var e = new haxor_core_Entity();
	e.set_name("PointLight");
	var l = e.AddComponent(haxor_component_light_PointLight);
	l.color = p_color;
	l.intensity = p_intensity;
	l.atten = p_atten;
	l.radius = p_radius;
	return l;
};
haxor_component_light_PointLight.__super__ = haxor_component_light_Light;
haxor_component_light_PointLight.prototype = $extend(haxor_component_light_Light.prototype,{
	__class__: haxor_component_light_PointLight
});
var haxor_context_CameraContext = function() {
	this.cid = new haxor_context_UID();
	this.list = [];
	this.front = [];
	this.back = [];
	var _g = 0;
	while(_g < 64) {
		var i = _g++;
		this.front.push(null);
		this.back.push(null);
	}
};
$hxClasses["haxor.context.CameraContext"] = haxor_context_CameraContext;
haxor_context_CameraContext.__name__ = ["haxor","context","CameraContext"];
haxor_context_CameraContext.prototype = {
	Create: function(c) {
		this.list.push(c);
		this.SortCameraList();
		haxor_context_EngineContext.renderer.AddCamera(c);
	}
	,Destroy: function(c) {
		this.ClearTargets(c);
		HxOverrides.remove(this.list,c);
		this.SortCameraList();
		this.cid.set_id(c.__cid);
		haxor_context_EngineContext.renderer.RemoveCamera(c);
	}
	,Bind: function(c) {
		var ft = this.front[c.__cid];
		var rt = c.m_target;
		var target;
		if(ft == null) target = rt; else target = ft;
		c.UpdateProjection();
		haxor_context_EngineContext.renderer.UpdateCameraSAP(c);
		haxor_context_EngineContext.texture.BindTarget(target);
		haxor_context_EngineContext.renderer.UpdateDisplayList(c);
		haxor_graphics_Graphics.Clear(c);
	}
	,Resize: function() {
		var _g1 = 0;
		var _g = this.list.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.UpdateViewport(this.list[i]);
		}
	}
	,ClearTargets: function(c) {
		var rt;
		rt = this.front[c.__cid];
		if(rt != null) haxor_core_Resource.Destroy(rt);
		rt = this.back[c.__cid];
		if(rt != null) haxor_core_Resource.Destroy(rt);
		this.front[c.__cid] = null;
		this.back[c.__cid] = null;
	}
	,Unbind: function(c) {
		this.SwapTargets(c);
	}
	,SwapTargets: function(c) {
		var tmp;
		tmp = this.front[c.__cid];
		this.front[c.__cid] = this.back[c.__cid];
		this.back[c.__cid] = tmp;
	}
	,UpdateViewport: function(c) {
		var need_buffer = false;
		if(c.m_quality < 1.0) need_buffer = true; else if(c.get_filters().length > 0) need_buffer = true;
		var w = haxor_graphics_Screen.m_width;
		var h = haxor_graphics_Screen.m_height;
		if(c.m_target != null) {
			w = c.m_target.m_width;
			h = c.m_target.m_height;
		}
		c.m_aspect = w / h;
		var sw = w * c.m_quality;
		var sh = h * c.m_quality;
		if(sw < 1.0) w = 1.0; else w = sw;
		if(sh < 1.0) h = 1.0; else h = sh;
		var vx = Std["int"](c.m_viewport.get_xMin() * w);
		var vy = Std["int"](c.m_viewport.get_yMin() * h);
		var aw = c.m_viewport.get_width() * w;
		var ah = c.m_viewport.get_height() * h;
		c.m_pixelViewport.set_xMin(vx);
		vx;
		c.m_pixelViewport.set_y(h - ah - vy);
		c.m_pixelViewport.set_width(aw);
		c.m_pixelViewport.set_height(ah);
		var tw = aw;
		var th = ah;
		var grt;
		grt = this.front[c.__cid];
		if(grt != null) {
			if(tw != grt.m_width) this.ClearTargets(c); else if(th != grt.m_height) this.ClearTargets(c);
		}
		grt = this.front[c.__cid];
		if(grt == null) {
			if(need_buffer) {
				var tf;
				if(c.m_target == null) tf = haxor_core_PixelFormat.RGB8; else tf = c.m_target.m_format;
				this.front[c.__cid] = new haxor_graphics_texture_RenderTexture(aw,ah,tf,c.m_captureDepth);
				if(c.get_filters().length <= 0) this.back[c.__cid] = this.front[c.__cid]; else this.back[c.__cid] = new haxor_graphics_texture_RenderTexture(aw,ah,tf,c.m_captureDepth);
				this.front[c.__cid].set_name(this.back[c.__cid].set_name("CameraScreenBuffer"));
			}
		}
		c.m_projection_dirty = true;
		c.m_proj_uniform_dirty = true;
	}
	,SortCameraList: function() {
		if(this.list.length > 1) this.list.sort(function(a,b) {
			if(a.get_order() == b.get_order()) {
				if(a.m_entity.get_name() < b.m_entity.get_name()) return -1; else return 1;
			} else if(a.get_order() < b.get_order()) return -1; else return 1;
		});
	}
	,__class__: haxor_context_CameraContext
};
var haxor_context_DataContext = function() {
	this.i = [];
	this.v = [];
	this.m_v2 = [];
	this.m_v3 = [];
	this.m_v4 = [];
	this.m_c = [];
	this.m_q = [];
	this.m_m4 = [];
	this.m_aabb3 = [];
	this.m_aabb2 = [];
	this.m_nv2 = 0;
	this.m_nv3 = 0;
	this.m_nv4 = 0;
	this.m_nc = 0;
	this.m_nq = 0;
	this.m_nm4 = 0;
	this.m_naabb3 = 0;
	this.m_naabb2 = 0;
	this.m4l = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
	var _g1 = 0;
	var _g = haxor_context_DataContext.MAX_TEMP;
	while(_g1 < _g) {
		var k = _g1++;
		this.i.push(0);
		this.v.push(0.0);
		this.m_v2.push(new haxor_math_Vector2(0,0));
		this.m_v3.push(new haxor_math_Vector3(0,0,0));
		this.m_v4.push(new haxor_math_Vector4(0,0,0,0));
		this.m_c.push(new haxor_math_Color(0,0,0,1));
		this.m_q.push(new haxor_math_Quaternion(0,0,0,1.0));
		this.m_m4.push(new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1));
		this.m_aabb3.push(haxor_math_AABB3.get_empty());
		this.m_aabb2.push(haxor_math_AABB2.get_empty());
	}
};
$hxClasses["haxor.context.DataContext"] = haxor_context_DataContext;
haxor_context_DataContext.__name__ = ["haxor","context","DataContext"];
haxor_context_DataContext.prototype = {
	get_v2: function() {
		return this.m_v2[this.m_nv2 = (this.m_nv2 + 1) % this.m_v2.length];
	}
	,get_v3: function() {
		return this.m_v3[this.m_nv3 = (this.m_nv3 + 1) % this.m_v3.length];
	}
	,get_v4: function() {
		return this.m_v4[this.m_nv4 = (this.m_nv4 + 1) % this.m_v4.length];
	}
	,get_c: function() {
		return this.m_c[this.m_nc = (this.m_nc + 1) % this.m_c.length];
	}
	,get_q: function() {
		return this.m_q[this.m_nq = (this.m_nq + 1) % this.m_q.length];
	}
	,get_aabb3: function() {
		return this.m_aabb3[this.m_naabb3 = (this.m_naabb3 + 1) % this.m_aabb3.length];
	}
	,get_aabb2: function() {
		return this.m_aabb2[this.m_naabb2 = (this.m_naabb2 + 1) % this.m_aabb2.length];
	}
	,get_m4: function() {
		return this.m_m4[this.m_nq = (this.m_nm4 + 1) % this.m_m4.length];
	}
	,__class__: haxor_context_DataContext
	,__properties__: {get_m4:"get_m4",get_aabb2:"get_aabb2",get_aabb3:"get_aabb3",get_q:"get_q",get_c:"get_c",get_v4:"get_v4",get_v3:"get_v3",get_v2:"get_v2"}
};
var haxor_context_EngineContext = function() { };
$hxClasses["haxor.context.EngineContext"] = haxor_context_EngineContext;
haxor_context_EngineContext.__name__ = ["haxor","context","EngineContext"];
haxor_context_EngineContext.Initialize = function() {
	haxor_core_Console.Log("Haxor> Engine Context Initialize.",3);
	haxor_context_EngineContext.update = new haxor_context_Process("process.update",haxor_context_EngineContext.maxNodes);
	haxor_context_EngineContext.render = new haxor_context_Process("process.render",haxor_context_EngineContext.maxNodes);
	haxor_context_EngineContext.resize = new haxor_context_Process("process.resize",haxor_context_EngineContext.maxNodes);
	haxor_context_EngineContext.resources = new haxor_context_Process("process.resources",haxor_context_EngineContext.maxNodes);
	haxor_context_EngineContext.disposables = new haxor_context_Process("process.disposables",haxor_context_EngineContext.maxNodes);
	haxor_context_EngineContext.list = [haxor_context_EngineContext.update,haxor_context_EngineContext.render,haxor_context_EngineContext.resize,haxor_context_EngineContext.resources,haxor_context_EngineContext.disposables];
	haxor_context_EngineContext.data = new haxor_context_DataContext();
	haxor_component_animation_Animation.Initialize();
	haxor_context_EngineContext.renderer = new haxor_context_RendererContext();
	haxor_context_EngineContext.mesh = new haxor_context_MeshContext();
	haxor_context_EngineContext.material = new haxor_context_MaterialContext();
	haxor_context_EngineContext.texture = new haxor_context_TextureContext();
	haxor_context_EngineContext.gizmo = new haxor_context_GizmoContext();
	haxor_context_EngineContext.camera = new haxor_context_CameraContext();
	haxor_context_EngineContext.transform = new haxor_context_TransformContext();
};
haxor_context_EngineContext.Build = function() {
	haxor_context_EngineContext.mesh.Initialize();
	haxor_context_EngineContext.material.Initialize();
	haxor_context_EngineContext.texture.Initialize();
	haxor_context_EngineContext.gizmo.Initialize();
	haxor_context_EngineContext.transform.Initialize();
	haxor_context_EngineContext.renderer.Initialize();
};
haxor_context_EngineContext.Enable = function(p_resource) {
	if(js_Boot.__instanceof(p_resource,haxor_core_IUpdateable)) haxor_context_EngineContext.update.Add(p_resource);
	if(js_Boot.__instanceof(p_resource,haxor_core_IRenderable)) haxor_context_EngineContext.render.Add(p_resource);
	if(js_Boot.__instanceof(p_resource,haxor_core_IResizeable)) haxor_context_EngineContext.resize.Add(p_resource);
	if(js_Boot.__instanceof(p_resource,haxor_component_Renderer)) haxor_context_EngineContext.renderer.Enable(p_resource);
	if(js_Boot.__instanceof(p_resource,haxor_core_Entity)) {
		var e = p_resource;
		var _g1 = 0;
		var _g = e.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = e.m_components[i];
			if(js_Boot.__instanceof(c,haxor_component_MeshRenderer)) haxor_context_EngineContext.renderer.Enable(c);
		}
	}
};
haxor_context_EngineContext.Disable = function(p_resource) {
	if(js_Boot.__instanceof(p_resource,haxor_core_IUpdateable)) haxor_context_EngineContext.update.Remove(p_resource);
	if(js_Boot.__instanceof(p_resource,haxor_core_IRenderable)) haxor_context_EngineContext.render.Remove(p_resource);
	if(js_Boot.__instanceof(p_resource,haxor_core_IResizeable)) haxor_context_EngineContext.resize.Remove(p_resource);
	if(js_Boot.__instanceof(p_resource,haxor_component_Renderer)) haxor_context_EngineContext.renderer.Disable(p_resource);
	if(js_Boot.__instanceof(p_resource,haxor_core_Entity)) {
		var e = p_resource;
		var _g1 = 0;
		var _g = e.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = e.m_components[i];
			if(js_Boot.__instanceof(c,haxor_component_MeshRenderer)) haxor_context_EngineContext.renderer.Disable(c);
		}
	}
};
haxor_context_EngineContext.OnEntiyLayerChange = function(p_entity,p_from,p_to) {
	var e = p_entity;
	var _g1 = 0;
	var _g = e.m_components.length;
	while(_g1 < _g) {
		var i = _g1++;
		var c = e.m_components[i];
		if(js_Boot.__instanceof(c,haxor_component_Renderer)) haxor_context_EngineContext.renderer.OnLayerChange(c,p_from,p_to);
	}
};
haxor_context_EngineContext.Destroy = function(p_resource) {
	if(p_resource.m_destroyed) return;
	p_resource.m_destroyed = true;
	var _g1 = 0;
	var _g = haxor_context_EngineContext.list.length;
	while(_g1 < _g) {
		var i = _g1++;
		haxor_context_EngineContext.list[i].Remove(p_resource);
	}
	haxor_context_EngineContext.disposables.Add(p_resource);
};
var haxor_context_GizmoContext = function() {
};
$hxClasses["haxor.context.GizmoContext"] = haxor_context_GizmoContext;
haxor_context_GizmoContext.__name__ = ["haxor","context","GizmoContext"];
haxor_context_GizmoContext.prototype = {
	Initialize: function() {
		var mat;
		mat = this.gizmo_material = new haxor_graphics_material_Material("$GizmoMaterial");
		mat.set_shader(new haxor_graphics_material_Shader(haxor_context_ShaderContext.gizmo_source));
		mat.blend = true;
		mat.SetBlending(770,771);
		mat.SetFloat("Area",1000.0);
		mat.SetColor("Tint",new haxor_math_Color(1.0,1.0,1.0,0.4));
		mat.ztest = false;
		mat = this.texture_material = new haxor_graphics_material_Material("$TextureMaterial");
		mat.set_shader(new haxor_graphics_material_Shader(haxor_context_ShaderContext.texture_source));
		mat.blend = true;
		mat.SetBlending(770,771);
		mat.SetFloat2("Screen",haxor_graphics_Screen.m_width,haxor_graphics_Screen.m_height);
		mat.SetFloat4("Rect",0,0,100,100);
		mat.SetColor("Tint",new haxor_math_Color(1.0,1.0,1.0,1.0));
		mat.cull = 0;
		mat.ztest = false;
		this.CreateAxis();
		this.CreateGrid(100.0);
		this.CreateTextureQuad();
	}
	,CreateTextureQuad: function() {
		var m = this.texture = new haxor_graphics_mesh_Mesh("$TextureQuad");
		var vl;
		vl = haxor_io_FloatArray.Alloc([0,0,0,0,-1,0,1,-1,0,0,0,0,1,-1,0,1,0,0]);
		m.Set("vertex",vl,3);
		m.set_bounds(m.GenerateAttribBounds("vertex",haxor_context_EngineContext.data.get_aabb3()));
	}
	,CreateAxis: function() {
		var m = this.axis = new haxor_graphics_mesh_Mesh("$GridAxis");
		m.primitive = 1;
		var vl = new haxor_io_FloatArray(18);
		var cl = new haxor_io_FloatArray(24);
		var k;
		k = 0;
		vl.Set(k++,0.0);
		vl.Set(k++,0.0);
		vl.Set(k++,0.0);
		vl.Set(k++,1.0);
		vl.Set(k++,0.0);
		vl.Set(k++,0.0);
		vl.Set(k++,0.0);
		vl.Set(k++,0.0);
		vl.Set(k++,0.0);
		vl.Set(k++,0.0);
		vl.Set(k++,1.0);
		vl.Set(k++,0.0);
		vl.Set(k++,0.0);
		vl.Set(k++,0.0);
		vl.Set(k++,0.0);
		vl.Set(k++,0.0);
		vl.Set(k++,0.0);
		vl.Set(k++,1.0);
		k = 0;
		cl.Set(k++,1.0);
		cl.Set(k++,0.0);
		cl.Set(k++,0.0);
		cl.Set(k++,1.0);
		cl.Set(k++,1.0);
		cl.Set(k++,0.3);
		cl.Set(k++,0.3);
		cl.Set(k++,1.0);
		cl.Set(k++,0.0);
		cl.Set(k++,1.0);
		cl.Set(k++,0.0);
		cl.Set(k++,1.0);
		cl.Set(k++,0.3);
		cl.Set(k++,1.0);
		cl.Set(k++,0.3);
		cl.Set(k++,1.0);
		cl.Set(k++,0.0);
		cl.Set(k++,0.0);
		cl.Set(k++,1.0);
		cl.Set(k++,1.0);
		cl.Set(k++,0.3);
		cl.Set(k++,0.3);
		cl.Set(k++,1.0);
		cl.Set(k++,1.0);
		m.Set("vertex",vl,3);
		m.Set("color",cl,4);
		m.set_bounds(m.GenerateAttribBounds("vertex",haxor_context_EngineContext.data.get_aabb3()));
	}
	,CreateGrid: function(p_step) {
		this.grid = new haxor_graphics_mesh_Mesh("$GridMesh");
		this.grid.primitive = 1;
		var len = p_step + 1;
		p_step = 1.0 / p_step;
		var ox = 0.5;
		var oz = 0.5;
		var px = 0.0;
		var pz = 0.0;
		var vl = new haxor_io_FloatArray(12 * len);
		var k;
		k = 0;
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			vl.Set(k++,px - ox);
			vl.Set(k++,0.0);
			vl.Set(k++,oz);
			vl.Set(k++,px - ox);
			vl.Set(k++,0.0);
			vl.Set(k++,-oz);
			px += p_step;
		}
		var _g1 = 0;
		while(_g1 < len) {
			var i1 = _g1++;
			vl.Set(k++,ox);
			vl.Set(k++,0.0);
			vl.Set(k++,pz - oz);
			vl.Set(k++,-ox);
			vl.Set(k++,0.0);
			vl.Set(k++,pz - oz);
			pz += p_step;
		}
		this.grid.Set("vertex",vl,3);
		this.grid.set_bounds(this.grid.GenerateAttribBounds("vertex",haxor_context_EngineContext.data.get_aabb3()));
	}
	,DrawGrid: function(p_area,p_color) {
		this.gizmo_material.SetFloat("Area",p_area);
		if(p_color != null) this.gizmo_material.SetFloat4("Tint",p_color.r,p_color.g,p_color.b,p_color.a);
		haxor_graphics_Graphics.Render(this.grid,this.gizmo_material,null,haxor_component_Camera.m_main);
	}
	,DrawAxis: function(p_area) {
		this.gizmo_material.SetFloat("Area",p_area);
		this.gizmo_material.SetColor("Tint",haxor_context_EngineContext.data.get_c().Set(1,1,1,1));
		haxor_graphics_Graphics.Render(this.axis,this.gizmo_material,null,haxor_component_Camera.m_main);
	}
	,__class__: haxor_context_GizmoContext
};
var haxor_context_MaterialContext = function() {
	this.uniform_globals = ["ViewMatrix","ProjectionMatrix","WorldMatrix","WorldMatrixInverse","WorldMatrixIT","Time","RandomSeed","RandomTexture","ScreenTexture","ScreenDepth","Ambient","CameraPosition","ProjectionMatrixInverse","ViewMatrixInverse"];
	this.mid = new haxor_context_UID();
	this.sid = new haxor_context_UID();
	this.uid = new haxor_context_UID();
	this.zfunc = 515;
	this.ztest = true;
	this.zwrite = true;
	this.blend = false;
	this.blendSrc = 1;
	this.blendDst = 0;
	this.invert = false;
	this.cull = 2;
	var max_buffers = 512;
	var max_programs = 1024;
	this.locations = [];
	this.uniforms = [];
	this.programs = [];
	this.vertex_shaders = [];
	this.fragment_shaders = [];
	this.globals = [];
	this.camera = [];
	this.transform = [];
	this.slot = 0;
	this.viewmatrix = [];
	this.projmatrix = [];
	var _g = 0;
	while(_g < max_programs) {
		var i = _g++;
		var l = [];
		var ul = [];
		var _g1 = 0;
		while(_g1 < max_buffers) {
			var j = _g1++;
			l.push(-1);
		}
		var _g11 = 0;
		while(_g11 < 200) {
			var j1 = _g11++;
			ul.push(haxor_graphics_GL.INVALID);
		}
		this.camera.push(null);
		this.transform.push(null);
		this.globals.push([]);
		this.locations.push(l);
		this.uniforms.push(ul);
		this.programs.push(haxor_graphics_GL.INVALID);
		this.vertex_shaders.push(haxor_graphics_GL.INVALID);
		this.fragment_shaders.push(haxor_graphics_GL.INVALID);
		this.viewmatrix.push(false);
		this.projmatrix.push(false);
	}
};
$hxClasses["haxor.context.MaterialContext"] = haxor_context_MaterialContext;
haxor_context_MaterialContext.__name__ = ["haxor","context","MaterialContext"];
haxor_context_MaterialContext.prototype = {
	Initialize: function() {
		haxor_graphics_GL.m_gl.DepthFunc(515);
		haxor_graphics_GL.m_gl.Enable(2929);
		haxor_graphics_GL.m_gl.DepthMask(true);
		haxor_graphics_GL.m_gl.Disable(3042);
		haxor_graphics_GL.m_gl.BlendFunc(1,0);
		haxor_graphics_GL.m_gl.Enable(2884);
		haxor_graphics_GL.m_gl.FrontFace(2305);
		haxor_graphics_GL.m_gl.CullFace(1029);
		haxor_graphics_GL.m_gl.Enable(3089);
	}
	,UpdateFlags: function(m) {
		if(m.zfunc != this.zfunc) {
			this.zfunc = m.zfunc;
			haxor_graphics_GL.m_gl.DepthFunc(this.zfunc);
		}
		if(m.ztest != this.ztest) {
			this.ztest = m.ztest;
			if(this.ztest) haxor_graphics_GL.m_gl.Enable(2929); else haxor_graphics_GL.m_gl.Disable(2929);
		}
		if(m.zwrite != this.zwrite) {
			this.zwrite = m.zwrite;
			haxor_graphics_GL.m_gl.DepthMask(this.zwrite);
		}
		if(m.blend != this.blend) {
			this.blend = m.blend;
			if(this.blend) haxor_graphics_GL.m_gl.Enable(3042); else haxor_graphics_GL.m_gl.Disable(3042);
		}
		var blend_change = false;
		if(m.blendSrc != this.blendSrc) {
			blend_change = true;
			this.blendSrc = m.blendSrc;
		}
		if(m.blendDst != this.blendDst) {
			blend_change = true;
			this.blendDst = m.blendDst;
		}
		if(blend_change) haxor_graphics_GL.m_gl.BlendFunc(this.blendSrc,this.blendDst);
		if(m.invert != this.invert) {
			this.invert = m.invert;
			haxor_graphics_GL.m_gl.FrontFace(this.invert?2304:2305);
		}
		if(m.cull != this.cull) {
			this.cull = m.cull;
			if(this.cull == 0) haxor_graphics_GL.m_gl.Disable(2884); else {
				haxor_graphics_GL.m_gl.Enable(2884);
				haxor_graphics_GL.m_gl.CullFace(this.cull == 1?1028:1029);
			}
		}
	}
	,InitializeMaterial: function(m) {
		this.programs[m.__cid] = haxor_graphics_GL.m_gl.CreateProgram();
	}
	,InitializeShader: function(s) {
		if(js_Boot.__instanceof(s,haxor_graphics_material_UberShader)) return;
		var vs_err = "";
		var fs_err = "";
		vs_err = this.CreateCompileShader(s,35633,this.vertex_shaders);
		fs_err = this.CreateCompileShader(s,35632,this.fragment_shaders);
		if(s.m_hasError) {
			haxor_core_Console.LogError("Shader> Compile Error @ [" + s.get_name() + "]");
			haxor_core_Console.Log("[vertex]\n" + vs_err);
			haxor_core_Console.Log("[fragment]\n" + fs_err);
		}
	}
	,CreateUniform: function(m,u) {
		var p = this.programs[m.__cid];
		var loc = haxor_graphics_GL.m_gl.GetUniformLocation(p,u.name);
		this.uniforms[m.__cid][u.__cid] = loc;
		u.__d = true;
		u.exists = loc != haxor_graphics_GL.INVALID;
	}
	,DestroyUniform: function(m,u) {
		if(m != null) this.uniforms[m.__cid][u.__cid] = haxor_graphics_GL.INVALID;
		haxor_context_EngineContext.material.uid.set_id(u.__cid);
	}
	,CreateCompileShader: function(s,t,c) {
		var id = haxor_graphics_GL.m_gl.CreateShader(t);
		var ss;
		if(t == 35633) ss = s.m_vss; else ss = s.m_fss;
		c[s.__cid] = id;
		haxor_graphics_GL.m_gl.ShaderSource(id,ss);
		haxor_graphics_GL.m_gl.CompileShader(id);
		if(haxor_graphics_GL.m_gl.GetShaderParameter(id,35713) == 0) {
			s.m_hasError = true;
			return haxor_graphics_GL.m_gl.GetShaderInfoLog(id);
		}
		return "";
	}
	,UpdateShader: function(m,s0,s1) {
		var p = this.programs[m.__cid];
		var vs_id;
		var fs_id;
		if(s0 != null) {
			vs_id = this.vertex_shaders[s0.__cid];
			fs_id = this.fragment_shaders[s0.__cid];
			haxor_graphics_GL.m_gl.DetachShader(p,vs_id);
			haxor_graphics_GL.m_gl.DetachShader(p,fs_id);
		}
		if(s1 != null) {
			vs_id = this.vertex_shaders[s1.__cid];
			fs_id = this.fragment_shaders[s1.__cid];
			haxor_graphics_GL.m_gl.AttachShader(p,vs_id);
			haxor_graphics_GL.m_gl.AttachShader(p,fs_id);
			var al = haxor_context_EngineContext.mesh.attribs;
			var _g1 = 0;
			var _g = al.length;
			while(_g1 < _g) {
				var i = _g1++;
				haxor_graphics_GL.m_gl.BindAttribLocation(p,i,al[i]);
			}
			haxor_graphics_GL.m_gl.LinkProgram(p);
			if(haxor_graphics_GL.m_gl.GetProgramParameter(p,35714) == 0) haxor_core_Console.LogError("Material> [" + m.get_name() + "] Link Error @ [" + s1.get_name() + "]");
			var ul = m.m_uniforms;
			var _g11 = 0;
			var _g2 = ul.length;
			while(_g11 < _g2) {
				var i1 = _g11++;
				this.CreateUniform(m,ul[i1]);
			}
			var _g12 = 0;
			var _g3 = this.locations[m.__cid].length;
			while(_g12 < _g3) {
				var i2 = _g12++;
				this.locations[m.__cid][i2] = -1;
			}
		}
		var gl = this.uniform_globals.slice();
		var k = 0;
		var m4 = haxor_context_EngineContext.data.get_m4().SetIdentity();
		while(k < gl.length) {
			var un = gl[k];
			if(haxor_graphics_GL.m_gl.GetUniformLocation(p,un) == haxor_graphics_GL.INVALID) {
				HxOverrides.remove(gl,un);
				continue;
			}
			switch(un) {
			case "Ambient":
				m.SetColor(un,haxor_context_EngineContext.data.get_c().Set(1,1,1,1));
				break;
			case "Time":
				m.SetFloat(un,0.0);
				break;
			case "RandomSeed":
				m.SetFloat(un,0.0);
				break;
			case "WorldMatrix":
				m.SetMatrix4(un,m4);
				break;
			case "WorldMatrixInverse":
				m.SetMatrix4(un,m4);
				break;
			case "WorldMatrixIT":
				m.SetMatrix4(un,m4);
				break;
			case "CameraPosition":
				m.SetVector3(un,haxor_context_EngineContext.data.get_v3().Set(0,0,0));
				break;
			case "ViewMatrix":
				m.SetMatrix4(un,m4);
				break;
			case "ViewMatrixInverse":
				m.SetMatrix4(un,m4);
				break;
			case "ProjectionMatrix":
				m.SetMatrix4(un,m4);
				break;
			case "ProjectionMatrixInverse":
				m.SetMatrix4(un,m4);
				break;
			}
			k++;
		}
		this.globals[m.__cid] = gl;
	}
	,UpdateMaterial: function(m) {
	}
	,GetAttribLocation: function(a) {
		if(this.current == null) return -1;
		var p = this.programs[this.current.__cid];
		var loc = this.locations[this.current.__cid][a.__cid];
		if(loc == -1) {
			loc = haxor_graphics_GL.m_gl.GetAttribLocation(p,a.m_name);
			if(loc < 0) this.locations[this.current.__cid][a.__cid] = -2;
		}
		return loc;
	}
	,Bind: function(m,t,c) {
		var material_change = m != this.current;
		this.UseMaterial(m);
		this.UpdateMaterialUniforms(t,c,material_change);
	}
	,UseMaterial: function(m) {
		if(m != this.current) {
			this.Unbind();
			this.current = m;
			if(m != null) {
				this.viewmatrix[m.__cid] = false;
				this.projmatrix[m.__cid] = false;
				var p = this.programs[m.__cid];
				this.UpdateFlags(m);
				haxor_graphics_GL.m_gl.UseProgram(p);
			}
		}
	}
	,UpdateMaterialUniforms: function(t,c,p_changed) {
		if(this.current != null) {
			if(c == null) this.viewmatrix[this.current.__cid] = false; else this.viewmatrix[this.current.__cid] = c.m_view_uniform_dirty;
			if(c == null) this.projmatrix[this.current.__cid] = false; else this.projmatrix[this.current.__cid] = c.m_proj_uniform_dirty;
			if(t == null) t = haxor_component_Transform.get_root(); else t = t;
			var ut = t != this.transform[this.current.__cid];
			if(this.transform[this.current.__cid] != null) this.transform[this.current.__cid].m_uniform_dirty = false;
			this.transform[this.current.__cid] = t;
			ut = ut || t.m_uniform_dirty;
			var uc = c != this.camera[this.current.__cid] && c != null;
			var ucv = this.viewmatrix[this.current.__cid] || uc;
			var ucp = this.projmatrix[this.current.__cid] || uc;
			if(c != null) this.camera[this.current.__cid] = c;
			this.UploadUniforms(ut,ucv,ucp,t,c);
			this.viewmatrix[this.current.__cid] = false;
			this.projmatrix[this.current.__cid] = false;
		}
	}
	,UploadUniforms: function(ut,ucv,ucp,t,c) {
		var ul = this.current.m_uniforms;
		var _g1 = 0;
		var _g = ul.length;
		while(_g1 < _g) {
			var i = _g1++;
			var u = ul[i];
			this.UploadGlobalUniform(u,ut,ucv,ucp,t,c);
			this.UploadUniform(this.current,u);
		}
	}
	,UploadUniform: function(m,u) {
		var loc;
		loc = this.uniforms[m.__cid][u.__cid];
		if(loc == haxor_graphics_GL.INVALID) return;
		if(u.texture != null) haxor_context_EngineContext.texture.Bind(u.texture);
		if(!u.__d) return;
		this.ApplyUniform(loc,u);
	}
	,ApplyUniform: function(loc,u) {
		var off = u.offset;
		if(u.isFloat) {
			var b = u.data;
			switch(off) {
			case 1:
				haxor_graphics_GL.Uniform1f(loc,b.Get(0));
				break;
			case 2:
				haxor_graphics_GL.Uniform2f(loc,b.Get(0),b.Get(1));
				break;
			case 3:
				haxor_graphics_GL.Uniform3f(loc,b.Get(0),b.Get(1),b.Get(2));
				break;
			case 4:
				haxor_graphics_GL.Uniform4f(loc,b.Get(0),b.Get(1),b.Get(2),b.Get(3));
				break;
			case 16:
				haxor_graphics_GL.m_gl.UniformMatrix4fv(loc,false,b);
				break;
			default:
				haxor_graphics_GL.m_gl.Uniform1fv(loc,b);
			}
		} else {
			var b1 = u.data;
			switch(off) {
			case 1:
				haxor_graphics_GL.Uniform1i(loc,b1.Get(0));
				break;
			case 2:
				haxor_graphics_GL.Uniform2i(loc,b1.Get(0),b1.Get(1));
				break;
			case 3:
				haxor_graphics_GL.Uniform3i(loc,b1.Get(0),b1.Get(1),b1.Get(2));
				break;
			case 4:
				haxor_graphics_GL.Uniform4i(loc,b1.Get(0),b1.Get(1),b1.Get(2),b1.Get(3));
				break;
			default:
				haxor_graphics_GL.m_gl.Uniform1iv(loc,b1);
			}
		}
		u.__d = false;
	}
	,UploadGlobalUniform: function(u,ut,ucv,ucp,t,c) {
		var _g = u.name;
		switch(_g) {
		case "Ambient":
			u.SetColor(haxor_component_light_Light.ambient);
			break;
		case "Time":
			u.SetFloat(haxor_core_Time.m_elapsed);
			break;
		case "RandomSeed":
			u.SetFloat(Math.random());
			break;
		case "WorldMatrix":
			if(ut) u.SetMatrix4(t.get_WorldMatrix());
			break;
		case "WorldMatrixInverse":
			if(ut) u.SetMatrix4(t.get_WorldMatrixInverse());
			break;
		case "WorldMatrixIT":
			if(ut) u.SetMatrix4(t.get_WorldMatrixInverse(),true);
			break;
		case "CameraPosition":
			if(ucv) u.SetVector3(c.m_entity.m_transform.get_position());
			break;
		case "ViewMatrix":
			if(ucv) u.SetMatrix4(c.m_entity.m_transform.get_WorldMatrixInverse());
			break;
		case "ViewMatrixInverse":
			if(ucv) u.SetMatrix4(c.m_entity.m_transform.get_WorldMatrix());
			break;
		case "ProjectionMatrix":
			if(ucp) u.SetMatrix4((function($this) {
				var $r;
				c.UpdateProjection();
				$r = c.m_projectionMatrix;
				return $r;
			}(this)));
			break;
		case "ProjectionMatrixInverse":
			if(ucp) u.SetMatrix4((function($this) {
				var $r;
				c.UpdateProjection();
				$r = c.m_projectionMatrixInverse;
				return $r;
			}(this)));
			break;
		}
	}
	,Unbind: function() {
	}
	,DestroyMaterial: function(m) {
		var p = this.programs[m.__cid];
		if(m.m_shader != null) {
			haxor_graphics_GL.m_gl.DetachShader(p,this.vertex_shaders[m.m_shader.__cid]);
			haxor_graphics_GL.m_gl.DetachShader(p,this.fragment_shaders[m.m_shader.__cid]);
		}
		haxor_graphics_GL.m_gl.DeleteProgram(p);
		haxor_context_EngineContext.material.mid.set_id(m.__cid);
		var _g1 = 0;
		var _g = m.m_uniforms.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.uid.set_id(m.m_uniforms[i].__cid);
		}
	}
	,DestroyShader: function(s) {
		haxor_graphics_GL.m_gl.DeleteShader(this.vertex_shaders[s.__cid]);
		haxor_graphics_GL.m_gl.DeleteShader(this.fragment_shaders[s.__cid]);
		haxor_context_EngineContext.material.sid.set_id(s.__cid);
	}
	,__class__: haxor_context_MaterialContext
};
var haxor_context_MeshContext = function() {
	this.attribs = ["vertex","normal","uv0","uv1","uv2","color","weight","bone"];
	this.aid = new haxor_context_UID();
	this.mid = new haxor_context_UID();
	this.buffers = [];
	this.activated = [];
	var _g = 0;
	while(_g < 32) {
		var i = _g++;
		this.activated.push(false);
	}
	var max_buffers = 512;
	var _g1 = 0;
	while(_g1 < max_buffers) {
		var i1 = _g1++;
		this.buffers.push(haxor_graphics_GL.INVALID);
	}
};
$hxClasses["haxor.context.MeshContext"] = haxor_context_MeshContext;
haxor_context_MeshContext.__name__ = ["haxor","context","MeshContext"];
haxor_context_MeshContext.prototype = {
	Initialize: function() {
		haxor_core_Console.Log("MeshContext> Initialize.",3);
	}
	,Bind: function(p_mesh) {
		if(p_mesh != this.current) {
			this.Unbind();
			this.current = p_mesh;
			if(this.current != null) this.ActivateAttributes();
		}
	}
	,ActivateAttributes: function() {
		var a;
		var al = this.current.m_attribs;
		var id;
		var type;
		var has_color = false;
		var _g1 = 0;
		var _g = al.length;
		while(_g1 < _g) {
			var i = _g1++;
			a = al[i];
			var loc = a._loc_;
			if(loc == 5) has_color = true;
			if(loc < 0) {
				loc = haxor_context_EngineContext.material.GetAttribLocation(a);
				if(loc < 0) continue;
			}
			type = 5126;
			if(!this.activated[loc]) {
				this.activated[loc] = true;
				this.active_max = Math.max(this.active_max,loc);
				haxor_graphics_GL.m_gl.EnableVertexAttrib(loc);
			}
			haxor_graphics_GL.m_gl.BindBuffer(34962,this.buffers[a.__cid]);
			haxor_graphics_GL.m_gl.VertexAttribPointer(loc,a.offset,type,false,0,0);
		}
		if(!has_color) {
			if(this.activated[5]) {
				haxor_graphics_GL.m_gl.DisableVertexAttrib(5);
				this.activated[5] = false;
			}
			haxor_graphics_GL.m_gl.VertexAttrib4f(5,1.0,1.0,1.0,1.0);
		}
		if(this.current.m_indexed) {
			a = this.current.m_topology_attrib;
			haxor_graphics_GL.m_gl.BindBuffer(34963,this.buffers[a.__cid]);
		}
	}
	,Unbind: function() {
	}
	,Draw: function(m) {
		if(m.m_indexed) {
			haxor_graphics_GL.m_gl.DrawElements(m.primitive,m.m_topology_attrib.data.m_length,5123,0);
			haxor_core_Stats.triangles += m.m_topology_attrib.data.m_length / 3;
		} else {
			haxor_graphics_GL.m_gl.DrawArrays(m.primitive,0,m.m_vcount);
			var off = 3;
			if(m.primitive == 1) off = 2;
			haxor_core_Stats.triangles += m.m_vcount / off;
		}
	}
	,RemoveAttrib: function(p_attrib) {
		var id = this.buffers[p_attrib.__cid];
		if(id == haxor_graphics_GL.INVALID) return;
		haxor_graphics_GL.m_gl.DeleteBuffer(id);
		this.buffers[p_attrib.__cid] = haxor_graphics_GL.INVALID;
		this.aid.set_id(p_attrib.__cid);
	}
	,UpdateAttrib: function(a,p_mode,p_is_index) {
		var id = this.buffers[a.__cid];
		var target_flag;
		if(p_is_index) target_flag = 34963; else target_flag = 34962;
		a._loc_ = this.attribs.indexOf(a.m_name);
		if(id == haxor_graphics_GL.INVALID) {
			id = haxor_graphics_GL.m_gl.CreateBuffer();
			this.buffers[a.__cid] = id;
		}
		haxor_graphics_GL.m_gl.BindBuffer(target_flag,id);
		haxor_graphics_GL.m_gl.BufferData(target_flag,a.data,p_mode);
	}
	,__class__: haxor_context_MeshContext
};
var haxor_context_BaseProcess = function(p_name,p_update_cid) {
	if(p_update_cid == null) p_update_cid = true;
	this.name = p_name;
	this.__cid = haxor_context_BaseProcess.m_cid;
	haxor_core_Console.Log("\tProcess [" + p_name + "][" + this.__cid + "] created.",8);
	if(p_update_cid) haxor_context_BaseProcess.m_cid++;
};
$hxClasses["haxor.context.BaseProcess"] = haxor_context_BaseProcess;
haxor_context_BaseProcess.__name__ = ["haxor","context","BaseProcess"];
haxor_context_BaseProcess.prototype = {
	get_length: function() {
		return 0;
	}
	,Add: function(p_item) {
	}
	,Remove: function(p_item) {
		return null;
	}
	,Clear: function() {
	}
	,__class__: haxor_context_BaseProcess
	,__properties__: {get_length:"get_length"}
};
var haxor_context_Process = function(p_name,p_size,p_update_cid) {
	if(p_update_cid == null) p_update_cid = true;
	haxor_context_BaseProcess.call(this,p_name,p_update_cid);
	this.list = [];
	this.m_length = 0;
	var _g = 0;
	while(_g < p_size) {
		var i = _g++;
		this.list.push(null);
	}
};
$hxClasses["haxor.context.Process"] = haxor_context_Process;
haxor_context_Process.__name__ = ["haxor","context","Process"];
haxor_context_Process.__super__ = haxor_context_BaseProcess;
haxor_context_Process.prototype = $extend(haxor_context_BaseProcess.prototype,{
	get_length: function() {
		return this.m_length;
	}
	,Add: function(p_item) {
		var iid = p_item.__pid[this.__cid];
		if(iid >= 0) return;
		if(this.m_length >= this.list.length) this.list.push(null);
		this.list[this.m_length] = p_item;
		p_item.__pid[this.__cid] = this.m_length++;
	}
	,Remove: function(p_item) {
		var iid = p_item.__pid[this.__cid];
		if(iid < 0) return p_item;
		p_item.__pid[this.__cid] = -1;
		this.m_length--;
		if(this.m_length <= 0) return p_item;
		this.list[iid] = this.list[this.m_length];
		p_item = this.list[iid];
		p_item.__pid[this.__cid] = iid;
		return p_item;
	}
	,Swap: function(p_a,p_b,p_index_only) {
		if(p_index_only == null) p_index_only = false;
		var ra = p_a;
		var rb = p_b;
		var ia = ra.__pid[this.__cid];
		if(ia < 0) return;
		var ib = rb.__pid[this.__cid];
		if(ib < 0) return;
		if(!p_index_only) {
			this.list[ia] = p_b;
			this.list[ib] = p_a;
		}
		rb.__pid[this.__cid] = ia;
		ra.__pid[this.__cid] = ib;
	}
	,Clear: function() {
		this.m_length = 0;
		this.list = [];
	}
	,Sort: function(p_method) {
		this.list.sort(p_method);
		var _g1 = 0;
		var _g = this.m_length;
		while(_g1 < _g) {
			var i = _g1++;
			var it = this.list[i];
			if(it != null) it.__pid[this.__cid] = i;
		}
	}
	,ToString: function() {
		var log = "";
		var _g1 = 0;
		var _g = this.m_length;
		while(_g1 < _g) {
			var i = _g1++;
			var it = this.list[i];
			log += "[" + it.get_name() + "," + it.__pid[this.__cid] + "]";
		}
		return log;
	}
	,__class__: haxor_context_Process
});
var haxor_context_RendererContext = function() {
	this.rid = new haxor_context_UID();
	this.fcid = new haxor_context_UID();
	this.sap = new haxor_ds_SAP(0.01,false);
	this.sap_dirty = false;
	this.deferred_culling = 0;
	this.deferred_offset = 100;
	this.display = [];
	this.sort = [];
	var _g = 0;
	while(_g < 32) {
		var i = _g++;
		var p = new haxor_context_Process("process.renderers",haxor_context_EngineContext.maxNodes,i == 31);
		this.display.push(p);
		this.sort.push(false);
	}
};
$hxClasses["haxor.context.RendererContext"] = haxor_context_RendererContext;
haxor_context_RendererContext.__name__ = ["haxor","context","RendererContext"];
haxor_context_RendererContext.prototype = {
	Initialize: function() {
		this.skinning = new haxor_graphics_texture_ComputeTexture(512,512,haxor_core_PixelFormat.Float4);
	}
	,Create: function(r) {
		r.__cid = this.rid.get_id();
		if(r.m_has_mesh) {
			var mr = r;
			mr.__fcid = this.fcid.get_id();
			this.sap.Create(mr.__fcid);
		}
	}
	,AddCamera: function(c) {
		c.__fcid = this.fcid.get_id();
		this.sap.Create(c.__fcid);
	}
	,RemoveCamera: function(c) {
		this.fcid.set_id(c.__fcid);
		this.sap.Remove(c.__fcid);
	}
	,OnMaterialChange: function(r) {
		var l = r.m_entity.m_layer;
		this.sort[l] = true;
	}
	,OnMeshChange: function(r) {
		var l = r.m_entity.m_layer;
		this.sort[l] = true;
	}
	,OnVisibilityChange: function(r,f) {
		var cl = r.m_entity.m_components;
		var _g1 = 0;
		var _g = cl.length;
		while(_g1 < _g) {
			var i = _g1++;
			cl[i].OnVisibilityChange(f);
		}
	}
	,DeferredCulling: function(r) {
		return false;
		if(!(r.m_visible && !r.m_culled)) return false;
		var c_id = haxor_context_EngineContext.renderer.deferred_culling;
		var c_off = this.deferred_offset;
		this.deferred_culling = (this.deferred_culling + this.deferred_offset) % this.rid.get_next();
		if(haxor_math_Mathf.AbsInt(c_id - r.__cid) > c_off) return true;
		return false;
	}
	,OnLayerChange: function(r,from,to) {
		this.sort[from] = true;
		this.display[from].Remove(r);
		if(r.get_enabled()) {
			this.display[to].Add(r);
			this.sort[to] = true;
		}
	}
	,UpdateDisplayList: function(c) {
		var ll = c.m_layers;
		var _g1 = 0;
		var _g = ll.length;
		while(_g1 < _g) {
			var i = _g1++;
			var l = ll[i];
			var rl = this.display[l];
			var need_sort = this.sort[l];
			if(need_sort) {
				this.sort[l] = false;
				if(rl.m_length > 1) rl.Sort($bind(this,this.DisplayListSort));
			}
		}
	}
	,Enable: function(r) {
		this.display[r.m_entity.m_layer].Add(r);
		this.sort[r.m_entity.m_layer] = true;
		if(r.m_has_mesh) {
			var mr = r;
			mr.m_culling_dirty = true;
		}
	}
	,Disable: function(r) {
		this.display[r.m_entity.m_layer].Remove(r);
		this.sort[r.m_entity.m_layer] = true;
	}
	,UpdateCameraSAP: function(c) {
		var need_sap = this.sap_dirty || c.m_view_uniform_dirty || c.m_proj_uniform_dirty;
		if(!need_sap) return;
		var n0 = haxor_context_EngineContext.data.get_v3().Set4(c.m_frustum[0]);
		var n1 = haxor_context_EngineContext.data.get_v3().Set4(c.m_frustum[1]);
		var n2 = haxor_context_EngineContext.data.get_v3().Set4(c.m_frustum[2]);
		var n3 = haxor_context_EngineContext.data.get_v3().Set4(c.m_frustum[3]);
		var f0 = haxor_context_EngineContext.data.get_v3().Set4(c.m_frustum[4]);
		var f1 = haxor_context_EngineContext.data.get_v3().Set4(c.m_frustum[5]);
		var f2 = haxor_context_EngineContext.data.get_v3().Set4(c.m_frustum[6]);
		var f3 = haxor_context_EngineContext.data.get_v3().Set4(c.m_frustum[7]);
		c.m_entity.m_transform.get_WorldMatrix().Transform3x4(n0);
		c.m_entity.m_transform.get_WorldMatrix().Transform3x4(n1);
		c.m_entity.m_transform.get_WorldMatrix().Transform3x4(n2);
		c.m_entity.m_transform.get_WorldMatrix().Transform3x4(n3);
		c.m_entity.m_transform.get_WorldMatrix().Transform3x4(f0);
		c.m_entity.m_transform.get_WorldMatrix().Transform3x4(f1);
		c.m_entity.m_transform.get_WorldMatrix().Transform3x4(f2);
		c.m_entity.m_transform.get_WorldMatrix().Transform3x4(f3);
		var pmin = haxor_context_EngineContext.data.get_v3().Set(n0.x,n0.y,n0.z);
		var pmax = haxor_context_EngineContext.data.get_v3().Set(n0.x,n0.y,n0.z);
		pmin.x = haxor_math_Mathf.Min(pmin.x,haxor_math_Mathf.Min(n1.x,Math.min(n2.x,n3.x)));
		pmin.y = haxor_math_Mathf.Min(pmin.y,haxor_math_Mathf.Min(n1.y,Math.min(n2.y,n3.y)));
		pmin.z = haxor_math_Mathf.Min(pmin.z,haxor_math_Mathf.Min(n1.z,Math.min(n2.z,n3.z)));
		pmax.x = haxor_math_Mathf.Max(pmax.x,haxor_math_Mathf.Max(n1.x,Math.max(n2.x,n3.x)));
		pmax.y = haxor_math_Mathf.Max(pmax.y,haxor_math_Mathf.Max(n1.y,Math.max(n2.y,n3.y)));
		pmax.z = haxor_math_Mathf.Max(pmax.z,haxor_math_Mathf.Max(n1.z,Math.max(n2.z,n3.z)));
		pmin.x = haxor_math_Mathf.Min(pmin.x,haxor_math_Mathf.Min(f0.x,haxor_math_Mathf.Min(f1.x,Math.min(f2.x,f3.x))));
		pmin.y = haxor_math_Mathf.Min(pmin.y,haxor_math_Mathf.Min(f0.y,haxor_math_Mathf.Min(f1.y,Math.min(f2.y,f3.y))));
		pmin.z = haxor_math_Mathf.Min(pmin.z,haxor_math_Mathf.Min(f0.z,haxor_math_Mathf.Min(f1.z,Math.min(f2.z,f3.z))));
		pmax.x = haxor_math_Mathf.Max(pmax.x,haxor_math_Mathf.Max(f0.x,haxor_math_Mathf.Max(f1.x,Math.max(f2.x,f3.x))));
		pmax.y = haxor_math_Mathf.Max(pmax.y,haxor_math_Mathf.Max(f0.y,haxor_math_Mathf.Max(f1.y,Math.max(f2.y,f3.y))));
		pmax.z = haxor_math_Mathf.Max(pmax.z,haxor_math_Mathf.Max(f0.z,haxor_math_Mathf.Max(f1.z,Math.max(f2.z,f3.z))));
		this.UpdateSAP(c.__fcid,c,pmin,pmax);
	}
	,UpdateSAP: function(p_id,p_d,p_min,p_max) {
		this.sap_dirty = true;
		this.sap.Update(p_id,p_d,p_min,p_max);
	}
	,IsSAPCulled: function(r,c) {
		if(!r.m_has_mesh) return false;
		var mr = r;
		return this.sap.Overlap(mr.__fcid,c.__fcid);
	}
	,Destroy: function(r) {
		this.display[r.m_entity.m_layer].Remove(r);
		this.sort[r.m_entity.m_layer] = true;
		this.rid.set_id(r.__cid);
		if(r.m_has_mesh) {
			var mr = r;
			this.fcid.set_id(mr.__fcid);
			this.sap.Remove(mr.__fcid);
		}
	}
	,DisplayListSort: function(a,b) {
		if(a == null) {
			if(b == null) return 0;
		}
		if(a == null) return 1;
		if(b == null) return -1;
		if(a.m_material == null) {
			if(b.m_material == null) return 0;
		}
		if(a.m_material == null) return 1;
		if(b.m_material == null) return -1;
		var ma = a.m_material;
		var mb = b.m_material;
		var ia = ma.queue;
		var ib = mb.queue;
		if(ia != ib) if(ia < ib) return -1; else return 1;
		if(!a.m_has_mesh) {
			if(!b.m_has_mesh) return 0;
		}
		if(!a.m_has_mesh) return 1;
		if(!b.m_has_mesh) return -1;
		var mra = a;
		var mrb = b;
		if(mra.m_material.get_uid() < mrb.m_material.get_uid()) return -1;
		if(mra.m_material.get_uid() > mrb.m_material.get_uid()) return 1;
		if(mra.m_mesh == null) {
			if(mrb.m_mesh == null) return 0;
		}
		if(mra.m_mesh == null) return 1;
		if(mrb.m_mesh == null) return -1;
		if(mra.m_mesh.get_uid() < mrb.m_mesh.get_uid()) return -1;
		if(mra.m_mesh.get_uid() > mrb.m_mesh.get_uid()) return 1;
		return 0;
	}
	,__class__: haxor_context_RendererContext
};
var haxor_context_ShaderContext = function() { };
$hxClasses["haxor.context.ShaderContext"] = haxor_context_ShaderContext;
haxor_context_ShaderContext.__name__ = ["haxor","context","ShaderContext"];
var haxor_context_TextureContext = function() {
	this.tid = new haxor_context_UID();
	this.bind = null;
	this.target = null;
	this.active = -1;
	this.next_slot = 0;
	this.bind = [];
	this.ids = [];
	this.framebuffers = [];
	this.renderbuffers = [];
};
$hxClasses["haxor.context.TextureContext"] = haxor_context_TextureContext;
haxor_context_TextureContext.__name__ = ["haxor","context","TextureContext"];
haxor_context_TextureContext.TextureToTarget = function(p_texture) {
	if(p_texture.get_type() == haxor_core_TextureType.Texture2D) return 3553;
	if(p_texture.get_type() == haxor_core_TextureType.RenderTexture) return 3553;
	if(p_texture.get_type() == haxor_core_TextureType.TextureCube) return 34067;
	return 3553;
};
haxor_context_TextureContext.FormatToChannelBits = function(p_format) {
	switch(p_format[1]) {
	case 0:
		return 6406;
	case 2:
		return 6407;
	case 3:
		return 6408;
	case 7:case 4:
		return 6409;
	case 8:case 5:
		return 6407;
	case 9:case 6:
		return 6408;
	case 1:
		return 6409;
	case 10:
		return 6402;
	}
	return 6408;
};
haxor_context_TextureContext.FormatToChannelType = function(p_format) {
	switch(p_format[1]) {
	case 4:case 5:case 6:
		return haxor_graphics_GL.HALF_FLOAT;
	case 7:case 8:case 9:
		return 5126;
	case 10:
		return 5123;
	case 3:case 2:case 1:case 0:
		return 5121;
	}
	return 5121;
};
haxor_context_TextureContext.FormatToChannelLayout = function(p_format) {
	switch(p_format[1]) {
	case 0:
		return 6406;
	case 2:
		return 6407;
	case 3:
		return 6408;
	case 1:case 4:case 7:
		return 6409;
	case 8:case 5:
		return 6407;
	case 9:case 6:
		return 6408;
	case 10:
		return 6402;
	}
	return 6408;
};
haxor_context_TextureContext.prototype = {
	Initialize: function() {
		var _g1 = 0;
		var _g = haxor_graphics_GL.MAX_ACTIVE_TEXTURE;
		while(_g1 < _g) {
			var i = _g1++;
			this.bind.push(null);
		}
		var _g2 = 0;
		while(_g2 < 2048) {
			var i1 = _g2++;
			this.ids.push(haxor_graphics_GL.INVALID);
			this.framebuffers.push(haxor_graphics_GL.INVALID);
			this.renderbuffers.push(haxor_graphics_GL.INVALID);
		}
	}
	,Alloc: function(p_texture) {
		var w = p_texture.m_width;
		var h = p_texture.m_height;
		var chn_fmt = haxor_context_TextureContext.FormatToChannelLayout(p_texture.m_format);
		var chn_bit = haxor_context_TextureContext.FormatToChannelBits(p_texture.m_format);
		var chn_type = haxor_context_TextureContext.FormatToChannelType(p_texture.m_format);
		var tex_type;
		if(p_texture.get_type() == haxor_core_TextureType.Texture2D) tex_type = 3553; else if(p_texture.get_type() == haxor_core_TextureType.RenderTexture) tex_type = 3553; else if(p_texture.get_type() == haxor_core_TextureType.TextureCube) tex_type = 34067; else tex_type = 3553;
		this.Bind(p_texture);
		haxor_graphics_GL.m_gl.TexImage2DAlloc(tex_type,0,chn_fmt,w,h,0,chn_bit,chn_type);
	}
	,Create: function(p_texture) {
		p_texture.__slot = this.next_slot % haxor_graphics_GL.MAX_ACTIVE_TEXTURE;
		this.next_slot++;
		var id = haxor_graphics_GL.m_gl.CreateTexture();
		this.ids[p_texture.__cid] = id;
		this.UpdateParameters(p_texture);
		if(p_texture.get_type() != haxor_core_TextureType.TextureCube) this.Alloc(p_texture);
		if(p_texture.get_type() == haxor_core_TextureType.RenderTexture) {
			var rt = p_texture;
			var fb_id = haxor_graphics_GL.m_gl.CreateFramebuffer();
			this.framebuffers[p_texture.__cid] = fb_id;
			haxor_graphics_GL.m_gl.BindFramebuffer(36160,fb_id);
			haxor_graphics_GL.m_gl.FramebufferTexture2D(36160,36064,3553,id,0);
			if(rt.m_depth != null) {
				var depth_id = this.ids[rt.m_depth.__cid];
				haxor_graphics_GL.m_gl.FramebufferTexture2D(36160,36096,3553,depth_id,0);
			} else {
				var rb_id = haxor_graphics_GL.m_gl.CreateRenderbuffer();
				this.renderbuffers[p_texture.__cid] = rb_id;
				haxor_graphics_GL.m_gl.BindRenderbuffer(36161,rb_id);
				haxor_graphics_GL.m_gl.RenderbufferStorage(36161,33189,rt.m_width,rt.m_height);
				haxor_graphics_GL.m_gl.FramebufferRenderbuffer(36160,36096,36161,rb_id);
			}
			haxor_graphics_GL.BindFramebuffer(36160,haxor_graphics_GL.NULL);
			haxor_graphics_GL.BindRenderbuffer(36161,haxor_graphics_GL.NULL);
			this.Unbind();
		}
	}
	,Bind: function(p_texture) {
		var slot = p_texture.__slot;
		haxor_graphics_GL.m_gl.ActiveTexture(33984 + slot);
		this.active = slot;
		var id = this.ids[p_texture.__cid];
		var target;
		if(p_texture.get_type() == haxor_core_TextureType.Texture2D) target = 3553; else if(p_texture.get_type() == haxor_core_TextureType.RenderTexture) target = 3553; else if(p_texture.get_type() == haxor_core_TextureType.TextureCube) target = 34067; else target = 3553;
		haxor_graphics_GL.m_gl.BindTexture(target,id);
		this.bind[slot] = p_texture;
	}
	,Unbind: function() {
		if(this.active < 0) return;
		if(this.bind[this.active] == null) return;
		var target = haxor_context_TextureContext.TextureToTarget(this.bind[this.active]);
		this.bind[this.active] = null;
		haxor_graphics_GL.BindTexture(3553,haxor_graphics_GL.NULL);
	}
	,UpdateParameters: function(p_texture) {
		var target;
		if(p_texture.get_type() == haxor_core_TextureType.Texture2D) target = 3553; else if(p_texture.get_type() == haxor_core_TextureType.RenderTexture) target = 3553; else if(p_texture.get_type() == haxor_core_TextureType.TextureCube) target = 34067; else target = 3553;
		this.Bind(p_texture);
		haxor_graphics_GL.m_gl.TexParameteri(target,10242,(p_texture.m_wrap & haxor_core_TextureWrap.ClampX) != 0?33071:10497);
		haxor_graphics_GL.m_gl.TexParameteri(target,10243,(p_texture.m_wrap & haxor_core_TextureWrap.ClampY) != 0?33071:10497);
		if(haxor_graphics_GL.TEXTURE_ANISOTROPY_ENABLED) haxor_graphics_GL.TexParameterf(target,haxor_graphics_GL.TEXTURE_ANISOTROPY,Math.max(1,p_texture.m_aniso));
		var minf = p_texture.m_minFilter;
		var magf = p_texture.m_magFilter;
		if(p_texture.m_format == haxor_core_PixelFormat.Half) {
			if(!haxor_graphics_GL.TEXTURE_HALF_LINEAR) {
				minf = haxor_core_TextureFilter.Nearest;
				magf = haxor_core_TextureFilter.Nearest;
			}
		}
		switch(minf[1]) {
		case 0:
			haxor_graphics_GL.m_gl.TexParameteri(target,10241,9728);
			break;
		case 3:
			haxor_graphics_GL.m_gl.TexParameteri(target,10241,9986);
			break;
		case 2:
			haxor_graphics_GL.m_gl.TexParameteri(target,10241,9984);
			break;
		case 1:
			haxor_graphics_GL.m_gl.TexParameteri(target,10241,9729);
			break;
		case 5:
			haxor_graphics_GL.m_gl.TexParameteri(target,10241,9987);
			break;
		case 6:
			haxor_graphics_GL.m_gl.TexParameteri(target,10241,9987);
			break;
		case 4:
			haxor_graphics_GL.m_gl.TexParameteri(target,10241,9985);
			break;
		}
		switch(magf[1]) {
		case 0:
			haxor_graphics_GL.m_gl.TexParameteri(target,10240,9728);
			break;
		case 3:
			haxor_graphics_GL.m_gl.TexParameteri(target,10240,9728);
			break;
		case 2:
			haxor_graphics_GL.m_gl.TexParameteri(target,10240,9728);
			break;
		case 1:
			haxor_graphics_GL.m_gl.TexParameteri(target,10240,9729);
			break;
		case 5:
			haxor_graphics_GL.m_gl.TexParameteri(target,10240,9729);
			break;
		case 6:
			haxor_graphics_GL.m_gl.TexParameteri(target,10240,9729);
			break;
		case 4:
			haxor_graphics_GL.m_gl.TexParameteri(target,10240,9729);
			break;
		}
	}
	,Update: function(p_texture) {
		var target;
		if(p_texture.get_type() == haxor_core_TextureType.Texture2D) target = 3553; else if(p_texture.get_type() == haxor_core_TextureType.RenderTexture) target = 3553; else if(p_texture.get_type() == haxor_core_TextureType.TextureCube) target = 34067; else target = 3553;
		this.Bind(p_texture);
		if(target == 34067) {
			var tc = p_texture;
			if(tc.m_faces[0] != null) this.WriteTexture(34069,tc.m_faces[0]);
			if(tc.m_faces[1] != null) this.WriteTexture(34070,tc.m_faces[1]);
			if(tc.m_faces[2] != null) this.WriteTexture(34071,tc.m_faces[2]);
			if(tc.m_faces[3] != null) this.WriteTexture(34072,tc.m_faces[3]);
			if(tc.m_faces[4] != null) this.WriteTexture(34073,tc.m_faces[4]);
			if(tc.m_faces[5] != null) this.WriteTexture(34074,tc.m_faces[5]);
		} else this.WriteTexture(target,p_texture);
	}
	,UploadTexture: function(p_texture,p_x,p_y,p_width,p_height,p_steps,p_on_complete) {
		var _g = this;
		var b = p_texture.m_data;
		var py = p_y;
		var chn_fmt = haxor_context_TextureContext.FormatToChannelLayout(p_texture.m_format);
		var chn_bit = haxor_context_TextureContext.FormatToChannelBits(p_texture.m_format);
		var chn_type = haxor_context_TextureContext.FormatToChannelType(p_texture.m_format);
		var steps = p_height / p_steps | 0;
		if(steps <= 1) steps = 1;
		var ua = new haxor_thread_Activity(function(t) {
			if(py >= p_height) {
				if(p_on_complete != null) p_on_complete();
				return false;
			}
			_g.Bind(p_texture);
			var _g1 = 0;
			while(_g1 < steps) {
				var i = _g1++;
				if(py < 0) {
					py++;
					continue;
				}
				if(py >= b.m_height) {
					if(p_on_complete != null) p_on_complete();
					return false;
				}
				var pos = (p_x + py * p_width) * b.m_channels;
				var len = p_width * b.m_channels;
				b.get_buffer().SetViewSlice(pos,len);
				haxor_graphics_GL.TexSubImage2D(3553,0,p_x,py,p_width,1,chn_fmt,chn_type,b.get_buffer());
				b.get_buffer().ResetSlice();
				py++;
			}
			return true;
		},false,true);
	}
	,WriteTexture: function(p_target,p_texture) {
		var w = p_texture.m_width;
		var h = p_texture.m_height;
		var chn_fmt = haxor_context_TextureContext.FormatToChannelLayout(p_texture.m_format);
		var chn_bit = haxor_context_TextureContext.FormatToChannelBits(p_texture.m_format);
		var chn_type = haxor_context_TextureContext.FormatToChannelType(p_texture.m_format);
		if(p_texture.m_format == haxor_core_PixelFormat.Depth) haxor_graphics_GL.m_gl.TexImage2DAlloc(p_target,0,chn_fmt,w,h,0,chn_fmt,chn_type); else {
			var is_ti2d = p_texture.get_type() == haxor_core_TextureType.Compute || p_texture.get_type() == haxor_core_TextureType.Texture2D;
			if(is_ti2d) {
				var t2d = p_texture;
				haxor_graphics_GL.TexImage2D(p_target,0,chn_fmt,w,h,0,chn_bit,chn_type,t2d.m_data.get_buffer());
			} else if(p_texture.get_type() == haxor_core_TextureType.RenderTexture) {
				var rt = p_texture;
				var id = this.ids[rt.__cid];
				haxor_graphics_GL.m_gl.FramebufferTexture2D(36160,36064,p_target,id,0);
			}
		}
	}
	,BindTarget: function(rt) {
		if(rt == null) {
			if(this.target != rt) {
				haxor_graphics_GL.BindFramebuffer(36160,haxor_graphics_GL.NULL);
				haxor_graphics_GL.BindRenderbuffer(36161,haxor_graphics_GL.NULL);
				this.target = null;
			}
		} else if(this.target != rt) {
			var fb_id = this.framebuffers[rt.__cid];
			haxor_graphics_GL.m_gl.BindFramebuffer(36160,fb_id);
			if(rt.m_depth == null) {
				var rb_id = this.renderbuffers[rt.__cid];
				haxor_graphics_GL.m_gl.BindRenderbuffer(36161,rb_id);
			}
			this.target = rt;
		}
	}
	,UpdateMipmaps: function(p_texture) {
		this.Bind(p_texture);
		var target;
		if(p_texture.get_type() == haxor_core_TextureType.Texture2D) target = 3553; else if(p_texture.get_type() == haxor_core_TextureType.RenderTexture) target = 3553; else if(p_texture.get_type() == haxor_core_TextureType.TextureCube) target = 34067; else target = 3553;
		haxor_graphics_GL.m_gl.GenerateMipmap(target);
	}
	,Destroy: function(p_texture) {
		var tex_id = this.ids[p_texture.__cid];
		if(tex_id != haxor_graphics_GL.INVALID) haxor_graphics_GL.m_gl.DeleteTexture(tex_id);
		if(p_texture.get_type() == haxor_core_TextureType.RenderTexture) {
			var fb_id = this.framebuffers[p_texture.__cid];
			var rb_id = this.renderbuffers[p_texture.__cid];
			if(fb_id != haxor_graphics_GL.INVALID) haxor_graphics_GL.m_gl.DeleteFramebuffer(fb_id);
			if(rb_id != haxor_graphics_GL.INVALID) haxor_graphics_GL.m_gl.DeleteRenderbuffer(rb_id);
		}
		haxor_context_EngineContext.texture.tid.set_id(p_texture.__cid);
	}
	,__class__: haxor_context_TextureContext
};
var haxor_context_TransformContext = function() {
	this.tid = new haxor_context_UID();
};
$hxClasses["haxor.context.TransformContext"] = haxor_context_TransformContext;
haxor_context_TransformContext.__name__ = ["haxor","context","TransformContext"];
haxor_context_TransformContext.prototype = {
	Initialize: function() {
	}
	,OnChange: function(t) {
		t.m_uniform_dirty = true;
		var cl = t.m_entity.m_components;
		var _g1 = 0;
		var _g = cl.length;
		while(_g1 < _g) {
			var i = _g1++;
			cl[i].OnTransformUpdate();
		}
	}
	,__class__: haxor_context_TransformContext
};
var haxor_context_UID = function() {
	this.m_id = 0;
	this.m_cache = [];
};
$hxClasses["haxor.context.UID"] = haxor_context_UID;
haxor_context_UID.__name__ = ["haxor","context","UID"];
haxor_context_UID.prototype = {
	get_id: function() {
		if(this.m_cache.length <= 0) return this.m_id++; else return this.m_cache.shift();
	}
	,set_id: function(v) {
		this.m_cache.push(v);
		return v;
	}
	,get_next: function() {
		return this.m_id;
	}
	,__class__: haxor_context_UID
	,__properties__: {get_next:"get_next",set_id:"set_id",get_id:"get_id"}
};
var haxor_core_Platform = { __ename__ : true, __constructs__ : ["Unknown","Windows","Linux","Android","MacOS","iOS","HTML","NodeJS"] };
haxor_core_Platform.Unknown = ["Unknown",0];
haxor_core_Platform.Unknown.toString = $estr;
haxor_core_Platform.Unknown.__enum__ = haxor_core_Platform;
haxor_core_Platform.Windows = ["Windows",1];
haxor_core_Platform.Windows.toString = $estr;
haxor_core_Platform.Windows.__enum__ = haxor_core_Platform;
haxor_core_Platform.Linux = ["Linux",2];
haxor_core_Platform.Linux.toString = $estr;
haxor_core_Platform.Linux.__enum__ = haxor_core_Platform;
haxor_core_Platform.Android = ["Android",3];
haxor_core_Platform.Android.toString = $estr;
haxor_core_Platform.Android.__enum__ = haxor_core_Platform;
haxor_core_Platform.MacOS = ["MacOS",4];
haxor_core_Platform.MacOS.toString = $estr;
haxor_core_Platform.MacOS.__enum__ = haxor_core_Platform;
haxor_core_Platform.iOS = ["iOS",5];
haxor_core_Platform.iOS.toString = $estr;
haxor_core_Platform.iOS.__enum__ = haxor_core_Platform;
haxor_core_Platform.HTML = ["HTML",6];
haxor_core_Platform.HTML.toString = $estr;
haxor_core_Platform.HTML.__enum__ = haxor_core_Platform;
haxor_core_Platform.NodeJS = ["NodeJS",7];
haxor_core_Platform.NodeJS.toString = $estr;
haxor_core_Platform.NodeJS.__enum__ = haxor_core_Platform;
var haxor_core_ApplicationProtocol = { __ename__ : true, __constructs__ : ["None","File","HTTP","HTTPS"] };
haxor_core_ApplicationProtocol.None = ["None",0];
haxor_core_ApplicationProtocol.None.toString = $estr;
haxor_core_ApplicationProtocol.None.__enum__ = haxor_core_ApplicationProtocol;
haxor_core_ApplicationProtocol.File = ["File",1];
haxor_core_ApplicationProtocol.File.toString = $estr;
haxor_core_ApplicationProtocol.File.__enum__ = haxor_core_ApplicationProtocol;
haxor_core_ApplicationProtocol.HTTP = ["HTTP",2];
haxor_core_ApplicationProtocol.HTTP.toString = $estr;
haxor_core_ApplicationProtocol.HTTP.__enum__ = haxor_core_ApplicationProtocol;
haxor_core_ApplicationProtocol.HTTPS = ["HTTPS",3];
haxor_core_ApplicationProtocol.HTTPS.toString = $estr;
haxor_core_ApplicationProtocol.HTTPS.__enum__ = haxor_core_ApplicationProtocol;
var haxor_core_Console = function() { };
$hxClasses["haxor.core.Console"] = haxor_core_Console;
haxor_core_Console.__name__ = ["haxor","core","Console"];
haxor_core_Console.Initialize = function() {
	var c = { log : function(s) {
	}};
	try {
		haxor_core_Console.m_console = console;
	} catch( err ) {
		haxor_core_Console.m_console = c;
	}
};
haxor_core_Console.Breakpoint = function() {
	debugger;
};
haxor_core_Console.Log = function(p_msg,p_level) {
	if(p_level == null) p_level = 0;
	if(haxor_core_Console.verbose >= p_level) haxor_core_Console.m_console.log(p_msg);
};
haxor_core_Console.LogImage = function(p_url,p_height) {
	var s = "background: transparent url(" + p_url + ") no-repeat; font-size: " + (p_height - 3) + "px;";
	haxor_core_Console.m_console.log("%c                                                                                                                                                            ",s);
};
haxor_core_Console.LogWarning = function(p_msg,p_obj) {
	if(haxor_core_Console.m_console == null) console.log("[W] " + p_msg);
	if(p_obj == null) p_obj = [];
	var _g = p_obj.length;
	switch(_g) {
	case 0:
		haxor_core_Console.m_console.warn(p_msg);
		break;
	case 1:
		haxor_core_Console.m_console.warn(p_msg,p_obj[0]);
		break;
	case 2:
		haxor_core_Console.m_console.warn(p_msg,p_obj[0],p_obj[1]);
		break;
	case 3:
		haxor_core_Console.m_console.warn(p_msg,p_obj[0],p_obj[1],p_obj[2]);
		break;
	case 4:
		haxor_core_Console.m_console.warn(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3]);
		break;
	}
};
haxor_core_Console.LogError = function(p_msg,p_obj) {
	if(haxor_core_Console.m_console == null) {
		console.log("[E] " + p_msg);
		return;
	}
	if(p_obj == null) p_obj = [];
	var _g = p_obj.length;
	switch(_g) {
	case 0:
		haxor_core_Console.m_console.error(p_msg);
		break;
	case 1:
		haxor_core_Console.m_console.error(p_msg,p_obj[0]);
		break;
	case 2:
		haxor_core_Console.m_console.error(p_msg,p_obj[0],p_obj[1]);
		break;
	case 3:
		haxor_core_Console.m_console.error(p_msg,p_obj[0],p_obj[1],p_obj[2]);
		break;
	case 4:
		haxor_core_Console.m_console.error(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3]);
		break;
	}
};
haxor_core_Console.ClearStyle = function() {
	haxor_core_Console.m_style = "";
};
haxor_core_Console.Clear = function() {
	if(haxor_core_Console.m_console != null) haxor_core_Console.m_console.clear();
};
haxor_core_Console.TimeStart = function(p_id) {
	if(haxor_core_Console.m_console != null) haxor_core_Console.m_console.time(p_id);
};
haxor_core_Console.TimeEnd = function(p_id) {
	if(haxor_core_Console.m_console != null) haxor_core_Console.m_console.timeEnd(p_id);
};
haxor_core_Console.StackTrace = function() {
	if(haxor_core_Console.m_console != null) haxor_core_Console.m_console.trace();
};
haxor_core_Console.SetStyle = function(p_size,p_color,p_background,p_font) {
	if(p_font == null) p_font = "'Lucida Console', Monaco, monospace";
	if(p_background == null) p_background = "rgba(255,255,255,0)";
	if(p_color == null) p_color = "rgba(0,0,0,1)";
	if(p_size == null) p_size = "12px";
	haxor_core_Console.m_style = "background-color: " + p_background + "; font-size: " + p_size + "; color: " + p_color + "; font-family: " + p_font + ";";
};
var haxor_core_EngineState = { __ename__ : true, __constructs__ : ["Play","Editor"] };
haxor_core_EngineState.Play = ["Play",0];
haxor_core_EngineState.Play.toString = $estr;
haxor_core_EngineState.Play.__enum__ = haxor_core_EngineState;
haxor_core_EngineState.Editor = ["Editor",1];
haxor_core_EngineState.Editor.toString = $estr;
haxor_core_EngineState.Editor.__enum__ = haxor_core_EngineState;
var haxor_core_Engine = function() { };
$hxClasses["haxor.core.Engine"] = haxor_core_Engine;
haxor_core_Engine.__name__ = ["haxor","core","Engine"];
haxor_core_Engine.Initialize = function() {
	haxor_core_Console.Log("Haxor> Engine Initialize.",3);
	haxor_context_EngineContext.Initialize();
	haxor_core_Engine.state = haxor_core_EngineState.Play;
};
haxor_core_Engine.Collect = function() {
	var dp = haxor_context_EngineContext.disposables;
	var _g1 = 0;
	var _g = haxor_context_EngineContext.collectRate;
	while(_g1 < _g) {
		var i = _g1++;
		if(dp.m_length <= 0) break;
		var o = dp.list[0];
		o.OnDestroy();
		dp.Remove(o);
	}
};
haxor_core_Engine.Update = function() {
	if(haxor_core_Engine.state == haxor_core_EngineState.Editor) return;
	haxor_component_animation_Animation.Update();
	var up = haxor_context_EngineContext.update;
	var _g1 = 0;
	var _g = up.m_length;
	while(_g1 < _g) {
		var i = _g1++;
		var r = up.list[i];
		if(r.m_destroyed) continue;
		if(r.m_is_behaviour) {
			var b = r;
			if(!b.m_is_awake) {
				b.OnAwake();
				b.m_is_awake = true;
			}
			if(!b.m_is_start) {
				b.OnStart();
				b.m_is_start = true;
			}
		}
		up.list[i].OnUpdate();
	}
};
haxor_core_Engine.Render = function() {
	haxor_core_RenderEngine.Render();
	haxor_core_Engine.RenderIRenderers();
	haxor_core_RenderEngine.RenderFinish();
};
haxor_core_Engine.RenderIRenderers = function() {
	var rp = haxor_context_EngineContext.render;
	var _g1 = 0;
	var _g = rp.m_length;
	while(_g1 < _g) {
		var i = _g1++;
		var r = rp.list[i];
		if(r.m_destroyed) continue;
		rp.list[i].OnRender();
	}
};
haxor_core_Engine.Resize = function() {
	haxor_core_RenderEngine.Resize();
	if(haxor_core_Engine.state == haxor_core_EngineState.Editor) return;
	var rp = haxor_context_EngineContext.resize;
	var _g1 = 0;
	var _g = rp.m_length;
	while(_g1 < _g) {
		var i = _g1++;
		var r = rp.list[i];
		if(r.m_destroyed) continue;
		rp.list[i].OnResize(haxor_graphics_Screen.m_width,haxor_graphics_Screen.m_height);
	}
};
var haxor_core_Entity = function(p_name) {
	if(p_name == null) p_name = "";
	haxor_core_Resource.call(this,p_name);
	this.m_enabled = true;
	this.m_components = [];
	this.m_layer = 1;
	this.m_transform = this.AddComponent(haxor_component_Transform);
};
$hxClasses["haxor.core.Entity"] = haxor_core_Entity;
haxor_core_Entity.__name__ = ["haxor","core","Entity"];
haxor_core_Entity.__super__ = haxor_core_Resource;
haxor_core_Entity.prototype = $extend(haxor_core_Resource.prototype,{
	get_enabled: function() {
		return this.m_enabled && !this.m_destroyed;
	}
	,set_enabled: function(v) {
		if(this.m_destroyed) return false;
		if(this.m_enabled == v) return v;
		this.m_enabled = v;
		var _g1 = 0;
		var _g = this.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = this.m_components[i];
			if(c.m_is_behaviour) {
				var b = c;
				b.set_enabled(v);
			}
		}
		return v;
	}
	,get_transform: function() {
		return this.m_transform;
	}
	,get_animation: function() {
		return this.m_animation;
	}
	,get_layer: function() {
		return this.m_layer;
	}
	,set_layer: function(v) {
		if(v <= 0) v = 1;
		if(this.m_layer == v) return v;
		var ll = this.m_layer;
		this.m_layer = v;
		haxor_context_EngineContext.OnEntiyLayerChange(this,ll,this.m_layer);
		return this.m_layer;
	}
	,AddComponent: function(p_type) {
		if(this.m_destroyed) return null;
		if(this.m_transform != null) {
			if(p_type == haxor_component_Transform) return this.m_transform; else if(this.m_animation != null) {
				if(p_type == haxor_component_animation_Animation) return this.m_animation;
			}
		}
		var c = null;
		c = Type.createInstance(p_type,[""]);
		if(c == null) return null;
		c.m_entity = this;
		if(p_type == haxor_component_animation_Animation) this.m_animation = c;
		if(c.m_is_behaviour) {
			var b = c;
			b.set_enabled(this.m_enabled && !this.m_destroyed);
		}
		c.OnBuild();
		this.m_components.push(c);
		return c;
	}
	,GetComponent: function(p_type) {
		var _g1 = 0;
		var _g = this.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(js_Boot.__instanceof(this.m_components[i],p_type)) return this.m_components[i];
		}
		return null;
	}
	,GetComponents: function(p_type) {
		var res = [];
		var _g1 = 0;
		var _g = this.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(js_Boot.__instanceof(this.m_components[i],p_type)) res.push(this.m_components[i]);
		}
		return res;
	}
	,GetComponentInChildren: function(p_type) {
		var res = [];
		var res1 = null;
		this.m_transform.Traverse(function(t,d) {
			if(res1 != null) return true;
			var l = t.m_entity.GetComponents(p_type);
			if(l.length > 0) {
				res1 = l[0];
				return true;
			}
			return true;
		});
		return res1;
	}
	,GetComponentsInChildren: function(p_type) {
		var res = [];
		this.m_transform.Traverse(function(t,d) {
			var l = t.m_entity.GetComponents(p_type);
			var _g1 = 0;
			var _g = l.length;
			while(_g1 < _g) {
				var i = _g1++;
				res.push(l[i]);
			}
			return true;
		});
		return res;
	}
	,OnDestroy: function() {
		var _g1 = 0;
		var _g = this.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_components[i].OnDestroy();
		}
		this.m_components = null;
	}
	,__class__: haxor_core_Entity
	,__properties__: $extend(haxor_core_Resource.prototype.__properties__,{set_layer:"set_layer",get_layer:"get_layer",get_animation:"get_animation",get_transform:"get_transform",set_enabled:"set_enabled",get_enabled:"get_enabled"})
});
var haxor_core_RenderQueue = function() { };
$hxClasses["haxor.core.RenderQueue"] = haxor_core_RenderQueue;
haxor_core_RenderQueue.__name__ = ["haxor","core","RenderQueue"];
var haxor_core_BlendMode = function() { };
$hxClasses["haxor.core.BlendMode"] = haxor_core_BlendMode;
haxor_core_BlendMode.__name__ = ["haxor","core","BlendMode"];
var haxor_core_MeshMode = function() { };
$hxClasses["haxor.core.MeshMode"] = haxor_core_MeshMode;
haxor_core_MeshMode.__name__ = ["haxor","core","MeshMode"];
var haxor_core_MeshPrimitive = function() { };
$hxClasses["haxor.core.MeshPrimitive"] = haxor_core_MeshPrimitive;
haxor_core_MeshPrimitive.__name__ = ["haxor","core","MeshPrimitive"];
var haxor_core_CullMode = function() { };
$hxClasses["haxor.core.CullMode"] = haxor_core_CullMode;
haxor_core_CullMode.__name__ = ["haxor","core","CullMode"];
var haxor_core_DepthTest = function() { };
$hxClasses["haxor.core.DepthTest"] = haxor_core_DepthTest;
haxor_core_DepthTest.__name__ = ["haxor","core","DepthTest"];
var haxor_core_PixelFormat = { __ename__ : true, __constructs__ : ["Alpha8","Luminance","RGB8","RGBA8","Half","Half3","Half4","Float","Float3","Float4","Depth"] };
haxor_core_PixelFormat.Alpha8 = ["Alpha8",0];
haxor_core_PixelFormat.Alpha8.toString = $estr;
haxor_core_PixelFormat.Alpha8.__enum__ = haxor_core_PixelFormat;
haxor_core_PixelFormat.Luminance = ["Luminance",1];
haxor_core_PixelFormat.Luminance.toString = $estr;
haxor_core_PixelFormat.Luminance.__enum__ = haxor_core_PixelFormat;
haxor_core_PixelFormat.RGB8 = ["RGB8",2];
haxor_core_PixelFormat.RGB8.toString = $estr;
haxor_core_PixelFormat.RGB8.__enum__ = haxor_core_PixelFormat;
haxor_core_PixelFormat.RGBA8 = ["RGBA8",3];
haxor_core_PixelFormat.RGBA8.toString = $estr;
haxor_core_PixelFormat.RGBA8.__enum__ = haxor_core_PixelFormat;
haxor_core_PixelFormat.Half = ["Half",4];
haxor_core_PixelFormat.Half.toString = $estr;
haxor_core_PixelFormat.Half.__enum__ = haxor_core_PixelFormat;
haxor_core_PixelFormat.Half3 = ["Half3",5];
haxor_core_PixelFormat.Half3.toString = $estr;
haxor_core_PixelFormat.Half3.__enum__ = haxor_core_PixelFormat;
haxor_core_PixelFormat.Half4 = ["Half4",6];
haxor_core_PixelFormat.Half4.toString = $estr;
haxor_core_PixelFormat.Half4.__enum__ = haxor_core_PixelFormat;
haxor_core_PixelFormat.Float = ["Float",7];
haxor_core_PixelFormat.Float.toString = $estr;
haxor_core_PixelFormat.Float.__enum__ = haxor_core_PixelFormat;
haxor_core_PixelFormat.Float3 = ["Float3",8];
haxor_core_PixelFormat.Float3.toString = $estr;
haxor_core_PixelFormat.Float3.__enum__ = haxor_core_PixelFormat;
haxor_core_PixelFormat.Float4 = ["Float4",9];
haxor_core_PixelFormat.Float4.toString = $estr;
haxor_core_PixelFormat.Float4.__enum__ = haxor_core_PixelFormat;
haxor_core_PixelFormat.Depth = ["Depth",10];
haxor_core_PixelFormat.Depth.toString = $estr;
haxor_core_PixelFormat.Depth.__enum__ = haxor_core_PixelFormat;
var haxor_core_TextureFilter = { __ename__ : true, __constructs__ : ["Nearest","Linear","NearestMipmapNearest","NearestMipmapLinear","LinearMipmapNearest","LinearMipmapLinear","Trilinear"] };
haxor_core_TextureFilter.Nearest = ["Nearest",0];
haxor_core_TextureFilter.Nearest.toString = $estr;
haxor_core_TextureFilter.Nearest.__enum__ = haxor_core_TextureFilter;
haxor_core_TextureFilter.Linear = ["Linear",1];
haxor_core_TextureFilter.Linear.toString = $estr;
haxor_core_TextureFilter.Linear.__enum__ = haxor_core_TextureFilter;
haxor_core_TextureFilter.NearestMipmapNearest = ["NearestMipmapNearest",2];
haxor_core_TextureFilter.NearestMipmapNearest.toString = $estr;
haxor_core_TextureFilter.NearestMipmapNearest.__enum__ = haxor_core_TextureFilter;
haxor_core_TextureFilter.NearestMipmapLinear = ["NearestMipmapLinear",3];
haxor_core_TextureFilter.NearestMipmapLinear.toString = $estr;
haxor_core_TextureFilter.NearestMipmapLinear.__enum__ = haxor_core_TextureFilter;
haxor_core_TextureFilter.LinearMipmapNearest = ["LinearMipmapNearest",4];
haxor_core_TextureFilter.LinearMipmapNearest.toString = $estr;
haxor_core_TextureFilter.LinearMipmapNearest.__enum__ = haxor_core_TextureFilter;
haxor_core_TextureFilter.LinearMipmapLinear = ["LinearMipmapLinear",5];
haxor_core_TextureFilter.LinearMipmapLinear.toString = $estr;
haxor_core_TextureFilter.LinearMipmapLinear.__enum__ = haxor_core_TextureFilter;
haxor_core_TextureFilter.Trilinear = ["Trilinear",6];
haxor_core_TextureFilter.Trilinear.toString = $estr;
haxor_core_TextureFilter.Trilinear.__enum__ = haxor_core_TextureFilter;
var haxor_core_TextureWrap = function() { };
$hxClasses["haxor.core.TextureWrap"] = haxor_core_TextureWrap;
haxor_core_TextureWrap.__name__ = ["haxor","core","TextureWrap"];
var haxor_core_TextureType = { __ename__ : true, __constructs__ : ["None","Texture2D","TextureCube","RenderTexture","Compute"] };
haxor_core_TextureType.None = ["None",0];
haxor_core_TextureType.None.toString = $estr;
haxor_core_TextureType.None.__enum__ = haxor_core_TextureType;
haxor_core_TextureType.Texture2D = ["Texture2D",1];
haxor_core_TextureType.Texture2D.toString = $estr;
haxor_core_TextureType.Texture2D.__enum__ = haxor_core_TextureType;
haxor_core_TextureType.TextureCube = ["TextureCube",2];
haxor_core_TextureType.TextureCube.toString = $estr;
haxor_core_TextureType.TextureCube.__enum__ = haxor_core_TextureType;
haxor_core_TextureType.RenderTexture = ["RenderTexture",3];
haxor_core_TextureType.RenderTexture.toString = $estr;
haxor_core_TextureType.RenderTexture.__enum__ = haxor_core_TextureType;
haxor_core_TextureType.Compute = ["Compute",4];
haxor_core_TextureType.Compute.toString = $estr;
haxor_core_TextureType.Compute.__enum__ = haxor_core_TextureType;
var haxor_core_ClearFlag = function() { };
$hxClasses["haxor.core.ClearFlag"] = haxor_core_ClearFlag;
haxor_core_ClearFlag.__name__ = ["haxor","core","ClearFlag"];
var haxor_core_InputState = { __ename__ : true, __constructs__ : ["None","Down","Up","Hold"] };
haxor_core_InputState.None = ["None",0];
haxor_core_InputState.None.toString = $estr;
haxor_core_InputState.None.__enum__ = haxor_core_InputState;
haxor_core_InputState.Down = ["Down",1];
haxor_core_InputState.Down.toString = $estr;
haxor_core_InputState.Down.__enum__ = haxor_core_InputState;
haxor_core_InputState.Up = ["Up",2];
haxor_core_InputState.Up.toString = $estr;
haxor_core_InputState.Up.__enum__ = haxor_core_InputState;
haxor_core_InputState.Hold = ["Hold",3];
haxor_core_InputState.Hold.toString = $estr;
haxor_core_InputState.Hold.__enum__ = haxor_core_InputState;
var haxor_core_AnimationWrap = { __ename__ : true, __constructs__ : ["Clamp","Loop","Oscilate"] };
haxor_core_AnimationWrap.Clamp = ["Clamp",0];
haxor_core_AnimationWrap.Clamp.toString = $estr;
haxor_core_AnimationWrap.Clamp.__enum__ = haxor_core_AnimationWrap;
haxor_core_AnimationWrap.Loop = ["Loop",1];
haxor_core_AnimationWrap.Loop.toString = $estr;
haxor_core_AnimationWrap.Loop.__enum__ = haxor_core_AnimationWrap;
haxor_core_AnimationWrap.Oscilate = ["Oscilate",2];
haxor_core_AnimationWrap.Oscilate.toString = $estr;
haxor_core_AnimationWrap.Oscilate.__enum__ = haxor_core_AnimationWrap;
var haxor_core_ILateUpdateable = function() { };
$hxClasses["haxor.core.ILateUpdateable"] = haxor_core_ILateUpdateable;
haxor_core_ILateUpdateable.__name__ = ["haxor","core","ILateUpdateable"];
haxor_core_ILateUpdateable.prototype = {
	__class__: haxor_core_ILateUpdateable
};
var haxor_core_IResizeable = function() { };
$hxClasses["haxor.core.IResizeable"] = haxor_core_IResizeable;
haxor_core_IResizeable.__name__ = ["haxor","core","IResizeable"];
haxor_core_IResizeable.prototype = {
	__class__: haxor_core_IResizeable
};
var haxor_core_RenderEngine = function() { };
$hxClasses["haxor.core.RenderEngine"] = haxor_core_RenderEngine;
haxor_core_RenderEngine.__name__ = ["haxor","core","RenderEngine"];
haxor_core_RenderEngine.Render = function() {
	haxor_core_Stats.BeginRender();
	haxor_core_RenderEngine.RenderCameras();
};
haxor_core_RenderEngine.RenderCameras = function() {
	var cl = haxor_context_EngineContext.camera.list;
	var _g1 = 0;
	var _g = cl.length;
	while(_g1 < _g) {
		var i = _g1++;
		var c = haxor_component_Camera.m_current = cl[i];
		haxor_core_RenderEngine.RenderCamera(c);
	}
};
haxor_core_RenderEngine.RenderCamera = function(c) {
	if(!c.get_enabled()) return;
	haxor_context_EngineContext.camera.Bind(c);
	var layers = c.m_layers;
	var _g1 = 0;
	var _g = layers.length;
	while(_g1 < _g) {
		var i = _g1++;
		var l = layers[i];
		haxor_core_RenderEngine.RenderCameraLayer(l,c);
	}
	haxor_context_EngineContext.camera.Unbind(c);
};
haxor_core_RenderEngine.RenderCameraLayer = function(l,c) {
	var lt = null;
	var renderers = haxor_context_EngineContext.renderer.display[l];
	var _g1 = 0;
	var _g = renderers.m_length;
	while(_g1 < _g) {
		var j = _g1++;
		var r = renderers.list[j];
		if(haxor_context_EngineContext.renderer.IsSAPCulled(r,c)) continue;
		haxor_core_RenderEngine.RenderRenderer(r);
	}
};
haxor_core_RenderEngine.RenderRenderer = function(r) {
	r.UpdateCulling();
	if(!(r.m_visible && !r.m_culled)) {
		haxor_core_Stats.culled++;
		return;
	}
	haxor_core_Stats.visible++;
	r.OnRender();
};
haxor_core_RenderEngine.RenderFinish = function() {
	var cl = haxor_context_EngineContext.camera.list;
	var _g1 = 0;
	var _g = cl.length;
	while(_g1 < _g) {
		var i = _g1++;
		cl[i].m_view_uniform_dirty = false;
		cl[i].m_proj_uniform_dirty = false;
	}
	haxor_context_EngineContext.renderer.sap_dirty = false;
};
haxor_core_RenderEngine.Resize = function() {
	haxor_context_EngineContext.camera.Resize();
};
var haxor_core_Scene = function(p_name) {
	haxor_core_Resource.call(this,p_name);
};
$hxClasses["haxor.core.Scene"] = haxor_core_Scene;
haxor_core_Scene.__name__ = ["haxor","core","Scene"];
haxor_core_Scene.__super__ = haxor_core_Resource;
haxor_core_Scene.prototype = $extend(haxor_core_Resource.prototype,{
	__class__: haxor_core_Scene
});
var haxor_core_Stats = function() { };
$hxClasses["haxor.core.Stats"] = haxor_core_Stats;
haxor_core_Stats.__name__ = ["haxor","core","Stats"];
haxor_core_Stats.__properties__ = {get_total:"get_total"}
haxor_core_Stats.get_total = function() {
	return haxor_core_Stats.visible + haxor_core_Stats.culled;
};
haxor_core_Stats.Initialize = function() {
	haxor_core_Stats.visible = 0;
	haxor_core_Stats.culled = 0;
	haxor_core_Stats.triangles = 0;
	haxor_core_Stats.renderers = 0;
};
haxor_core_Stats.BeginRender = function() {
	haxor_core_Stats.visible = 0;
	haxor_core_Stats.culled = 0;
	haxor_core_Stats.triangles = 0;
	haxor_core_Stats.renderers = haxor_context_EngineContext.renderer.rid.get_next();
};
var haxor_core_Time = function() { };
$hxClasses["haxor.core.Time"] = haxor_core_Time;
haxor_core_Time.__name__ = ["haxor","core","Time"];
haxor_core_Time.__properties__ = {get_frame:"get_frame",get_ups:"get_ups",get_fps:"get_fps",get_elapsed:"get_elapsed",get_framedelta:"get_framedelta",get_delta:"get_delta",get_clock:"get_clock",get_system:"get_system"}
haxor_core_Time.get_system = function() {
	return haxor_core_Time.m_system;
};
haxor_core_Time.get_clock = function() {
	return haxor_core_Time.m_clock;
};
haxor_core_Time.get_delta = function() {
	return haxor_core_Time.m_delta;
};
haxor_core_Time.get_framedelta = function() {
	return haxor_core_Time.m_frame_delta;
};
haxor_core_Time.get_elapsed = function() {
	return haxor_core_Time.m_elapsed;
};
haxor_core_Time.get_fps = function() {
	return haxor_core_Time.m_fps;
};
haxor_core_Time.get_ups = function() {
	return haxor_core_Time.m_ups;
};
haxor_core_Time.get_frame = function() {
	return haxor_core_Time.m_frame;
};
haxor_core_Time.Initialize = function() {
	haxor_core_Time.m_system = 0.0;
	haxor_core_Time.m_clock_0 = 0.0;
	haxor_core_Time.m_clock_0 = haxor_core_Time.m_system;
	haxor_core_Time.m_clock = haxor_core_Time.m_system;
	haxor_core_Time.m_clock_dt = 0.0;
	haxor_core_Time.m_start_clock = haxor_core_Time.m_clock;
	haxor_core_Time.m_last_clock = haxor_core_Time.m_clock;
	haxor_core_Time.m_last_frame_clock = haxor_core_Time.m_clock;
	haxor_core_Time.m_stats_clock = haxor_core_Time.m_clock;
	haxor_core_Time.m_elapsed = 0.0;
	haxor_core_Time.m_delta = 0.0;
	haxor_core_Time.m_frame_delta = 0.0;
	haxor_core_Time.m_ups = 0;
	haxor_core_Time.m_fps = 0;
	haxor_core_Time.m_updates = 0.0;
	haxor_core_Time.m_frame_count = 0.0;
	haxor_core_Time.m_frame = 0;
};
haxor_core_Time.Update = function() {
	haxor_core_Time.m_clock = haxor_core_Time.m_system;
	haxor_core_Time.m_clock_dt = haxor_core_Time.m_clock - haxor_core_Time.m_last_clock;
	if(haxor_core_Time.m_clock_dt <= 0) haxor_core_Time.m_clock_dt = 1.0;
	haxor_core_Time.m_last_clock = haxor_core_Time.m_clock;
	haxor_core_Time.m_delta = haxor_core_Time.m_clock_dt * 0.001;
	haxor_core_Time.m_elapsed = haxor_core_Time.m_clock * 0.001;
	haxor_core_Time.m_updates += 1.0;
	if(haxor_core_Time.m_clock - haxor_core_Time.m_stats_clock >= 1000.0) {
		haxor_core_Time.m_stats_clock += haxor_core_Time.m_clock - haxor_core_Time.m_stats_clock;
		haxor_core_Time.m_ups = haxor_core_Time.m_updates;
		haxor_core_Time.m_fps = haxor_core_Time.m_frame_count;
		haxor_core_Time.m_updates = 0.0;
		haxor_core_Time.m_frame_count = 0.0;
		haxor_core_Console.Log("FPS: " + haxor_core_Time.m_fps,7);
	}
};
haxor_core_Time.Render = function() {
	haxor_core_Time.m_frame_count += 1.0;
	haxor_core_Time.m_frame++;
	haxor_core_Time.m_frame_delta = (haxor_core_Time.m_clock - haxor_core_Time.m_last_frame_clock) * 0.001;
	haxor_core_Time.m_last_frame_clock = haxor_core_Time.m_clock;
};
var haxor_dom_DOMEntity = function(p_element,p_name) {
	if(p_name == null) p_name = "";
	haxor_core_Resource.call(this,p_name);
	this.m_layout = new haxor_dom_DOMLayout(this);
	this.m_x = 0;
	this.m_y = 0;
	this.m_px = 0;
	this.m_py = 0;
	this.m_width = 0;
	this.m_height = 0;
	this.m_rotation = 0;
	this.m_sx = 1.0;
	this.m_sy = 1.0;
	this.m_mouseEnabled = true;
	this.m_alpha = 1;
	this.m_globalAlpha = 1;
	this.m_globalVisible = true;
	this.m_visible = true;
	this.m_parent = null;
	this.set_element(p_element);
	if(p_name == "") this.set_name(this.m_type_name + this.get_uid()); else this.set_name(p_name);
};
$hxClasses["haxor.dom.DOMEntity"] = haxor_dom_DOMEntity;
haxor_dom_DOMEntity.__name__ = ["haxor","dom","DOMEntity"];
haxor_dom_DOMEntity.__super__ = haxor_core_Resource;
haxor_dom_DOMEntity.prototype = $extend(haxor_core_Resource.prototype,{
	get_x: function() {
		return this.m_x;
	}
	,set_x: function(v) {
		this.m_x = v;
		this.UpdateTransform();
		return v;
	}
	,get_y: function() {
		return this.m_y;
	}
	,set_y: function(v) {
		this.m_y = v;
		this.UpdateTransform();
		return v;
	}
	,get_px: function() {
		return this.m_px;
	}
	,set_px: function(v) {
		this.m_px = v;
		this.UpdateTransform();
		return v;
	}
	,get_py: function() {
		return this.m_py;
	}
	,set_py: function(v) {
		this.m_py = v;
		this.UpdateTransform();
		return v;
	}
	,get_width: function() {
		return this.m_width;
	}
	,set_width: function(v) {
		this.m_width = Math.max(0,v);
		this.UpdateRect();
		return this.m_width;
	}
	,get_height: function() {
		return this.m_height;
	}
	,set_height: function(v) {
		this.m_height = Math.max(0,v);
		this.UpdateRect();
		return this.m_height;
	}
	,get_sx: function() {
		return this.m_sx;
	}
	,set_sx: function(v) {
		this.m_sx = v;
		this.UpdateTransform();
		return v;
	}
	,get_sy: function() {
		return this.m_sy;
	}
	,set_sy: function(v) {
		this.m_sy = v;
		this.UpdateTransform();
		return v;
	}
	,get_rotation: function() {
		return this.m_rotation;
	}
	,set_rotation: function(v) {
		this.m_rotation = v;
		this.UpdateTransform();
		return v;
	}
	,get_mouseX: function() {
		if(this.get_parent() == null) return haxor_input_Input.mouse.x; else return this.get_parent().get_mouseX() - this.m_x;
	}
	,get_mouseY: function() {
		if(this.get_parent() == null) return haxor_input_Input.mouse.y; else return this.get_parent().get_mouseY() - this.get_y();
	}
	,get_rect: function() {
		var m = this.get_layout().get_margin();
		return new haxor_math_AABB2(Std["int"](this.m_x - this.m_px + m.get_xMin()),Std["int"](this.m_y - this.m_py + m.get_yMin()),Std["int"](this.m_width - (m.get_xMin() + m.get_xMax())),Std["int"](this.m_height - (m.get_yMin() + m.get_yMax())));
	}
	,get_alpha: function() {
		return this.m_alpha;
	}
	,set_alpha: function(v) {
		this.m_alpha = v;
		this.UpdateMaterial();
		return v;
	}
	,get_visible: function() {
		return this.m_visible;
	}
	,set_visible: function(v) {
		this.m_visible = v;
		this.UpdateMaterial();
		return v;
	}
	,get_mouseEnabled: function() {
		return this.m_mouseEnabled;
	}
	,set_mouseEnabled: function(v) {
		this.m_mouseEnabled = v;
		if(this.m_element != null) this.m_element.style.setProperty("pointer-events",v?"auto":"none","");
		return v;
	}
	,get_layout: function() {
		return this.m_layout;
	}
	,get_parent: function() {
		return this.m_parent;
	}
	,get_stage: function() {
		return haxor_dom_DOMStage.m_instance;
	}
	,set_name: function(v) {
		haxor_core_Resource.prototype.set_name.call(this,v);
		if(this.m_element != null) this.m_element.setAttribute("name",v);
		return v;
	}
	,get_element: function() {
		return this.m_element;
	}
	,set_element: function(v) {
		if(this.m_element == v) return v;
		var e = this.m_element;
		if(this.get_stage() != this) {
			if(e != null) {
				var pe = e.parentElement;
				pe.replaceChild(v,e);
				e.remove();
			}
		}
		this.m_element = e = v;
		if(this.get_stage() != this) {
			if(e != null) {
				e.style.position = "absolute";
				e.style.left = e.style.top = "0px";
				e.setAttribute("script",this.m_type_name);
				e.setAttribute("name",this.get_name());
			}
		}
		return e;
	}
	,UpdateMaterial: function() {
		if(this.get_stage() == this) return;
		var pa;
		if(this.get_parent() == null) pa = 1.0; else pa = this.get_parent().m_globalAlpha;
		var pv;
		if(this.get_parent() == null) pv = true; else pv = this.get_parent().m_globalVisible;
		var e = this.m_element;
		var is_negative = pa < 0 || this.m_alpha < 0;
		this.m_globalAlpha = haxor_math_Mathf.Clamp01(this.m_alpha) * haxor_math_Mathf.Clamp01(this.m_alpha);
		if(is_negative) this.m_globalAlpha = -this.m_globalAlpha;
		this.m_globalVisible = this.m_visible && pv && !is_negative;
		e.style.opacity = this.m_globalAlpha + "";
		if(this.m_globalVisible) e.style.display = "block"; else e.style.display = "none";
	}
	,UpdateRect: function() {
		if(this.get_stage() == this) return;
		var e = this.m_element;
		var m = this.get_layout().m_margin;
		this.get_layout().Update();
		e.style.width = Std["int"](this.m_width - (m.get_xMin() + m.get_xMax())) + "px";
		e.style.height = Std["int"](this.m_height - (m.get_yMin() + m.get_yMax())) + "px";
		this.OnRepaint();
	}
	,UpdateTransform: function() {
		if(this.get_stage() == this) return;
		var e = this.m_element;
		var m = this.get_layout().m_margin;
		this.get_layout().Update();
		var px = haxor_math_Mathf.Floor(this.m_x - this.m_px + m.get_xMin());
		var py = haxor_math_Mathf.Floor(this.m_y - this.m_py + m.get_yMin());
		var ox = px + this.m_px;
		var oy = py + this.m_py;
		var vdn = this.get_application().get_vendor();
		var tov = e.style.getPropertyValue(vdn + "transform-origin");
		if(tov != "" && tov != null) e.style.removeProperty(vdn + "transform-origin");
		e.style.cssText = e.style.cssText + " " + vdn + "transform-origin: " + ox + "px " + oy + "px;";
		var tp = vdn + "transform(" + "rotate3d(0,0,1," + this.m_rotation + "deg) scale3d(" + this.m_sx + "," + this.m_sy + ",1.0) translate3d(" + px + "px," + py + "px,0px)" + ")";
		e.style.setProperty(vdn + "transform","rotate3d(0,0,1," + this.m_rotation + "deg) scale3d(" + this.m_sx + "," + this.m_sy + ",1.0) translate3d(" + px + "px," + py + "px,0px)","");
	}
	,OnRepaint: function() {
	}
	,OnAdded: function() {
	}
	,OnAddedToStage: function() {
	}
	,OnRemoved: function() {
	}
	,AddedToStage: function() {
		if(!this.m_added_stage) {
			this.m_added_stage = true;
			this.OnAddedToStage();
		}
	}
	,__class__: haxor_dom_DOMEntity
	,__properties__: $extend(haxor_core_Resource.prototype.__properties__,{set_element:"set_element",get_element:"get_element",get_stage:"get_stage",get_parent:"get_parent",get_layout:"get_layout",set_mouseEnabled:"set_mouseEnabled",get_mouseEnabled:"get_mouseEnabled",set_visible:"set_visible",get_visible:"get_visible",set_alpha:"set_alpha",get_alpha:"get_alpha",get_rect:"get_rect",get_mouseY:"get_mouseY",get_mouseX:"get_mouseX",set_rotation:"set_rotation",get_rotation:"get_rotation",set_sy:"set_sy",get_sy:"get_sy",set_sx:"set_sx",get_sx:"get_sx",set_height:"set_height",get_height:"get_height",set_width:"set_width",get_width:"get_width",set_py:"set_py",get_py:"get_py",set_px:"set_px",get_px:"get_px",set_y:"set_y",get_y:"get_y",set_x:"set_x",get_x:"get_x"})
});
var haxor_dom_Container = function(p_element,p_name) {
	if(p_name == null) p_name = "";
	this.m_children = [];
	var e;
	if(p_element == null) {
		var _this = window.document;
		e = _this.createElement("div");
	} else e = p_element;
	haxor_dom_DOMEntity.call(this,e,p_name);
};
$hxClasses["haxor.dom.Container"] = haxor_dom_Container;
haxor_dom_Container.__name__ = ["haxor","dom","Container"];
haxor_dom_Container.DOMPath = function(p_element) {
	var p = [];
	var it = p_element;
	while(it != null) {
		if(it.hasAttribute("script")) {
			if(it.getAttribute("script").toLowerCase().indexOf("stage") >= 0) break;
			p.push(it.getAttribute("name"));
		}
		it = it.parentElement;
	}
	p.reverse();
	return p.join(".");
};
haxor_dom_Container.__super__ = haxor_dom_DOMEntity;
haxor_dom_Container.prototype = $extend(haxor_dom_DOMEntity.prototype,{
	get_childCount: function() {
		if(this.m_children == null) return 0; else return this.m_children.length;
	}
	,IsChild: function(p_child) {
		if(this.m_children == null) return false;
		var _g = 0;
		var _g1 = this.m_children;
		while(_g < _g1.length) {
			var it = _g1[_g];
			++_g;
			if(it == p_child) return true;
		}
		return false;
	}
	,Parse: function(p_target) {
		var l = p_target.children;
		var _g1 = 1;
		var _g = l.length;
		while(_g1 < _g) {
			var i = _g1++;
			var it = l.item(i);
			haxor_dom_DOMStage.BuildStep(it,this);
		}
		var _g11 = 0;
		var _g2 = l.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			var it1 = l.item(i1);
			if(it1 == null) continue;
			var _g21 = it1.nodeName.toLowerCase();
			switch(_g21) {
			case "container":
				it1.remove();
				break;
			case "sprite":
				it1.remove();
				break;
			}
		}
	}
	,AddChild: function(p_child) {
		this.AddChildAt(p_child);
	}
	,AddChildAt: function(p_child,p_index) {
		if(p_index == null) p_index = -1;
		if(p_child == this) return;
		if(this.IsChild(p_child)) return;
		if(p_child.get_parent() != null) p_child.get_parent().RemoveChild(p_child);
		var pos;
		if(p_index < 0) pos = this.m_children.length; else pos = p_index;
		this.m_children.push(p_child);
		this.m_element.appendChild(p_child.m_element);
		p_child.m_parent = this;
		this.SetChildIndex(p_child,pos);
		this.UpdateTransform();
		this.UpdateRect();
		this.UpdateMaterial();
		if(this.get_stage() != null || haxor_dom_DOMStage.m_instance == this) this.AddedToStage();
	}
	,RemoveChild: function(p_child) {
		if(!this.IsChild(p_child)) return;
		HxOverrides.remove(this.m_children,p_child);
		this.m_element.removeChild(p_child.m_element);
		p_child.m_parent = null;
	}
	,GetChildByName: function(p_name) {
		var _g1 = 0;
		var _g = this.m_children.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.m_children[i].get_name() == p_name) return this.m_children[i];
		}
		return null;
	}
	,GetChildAt: function(p_index) {
		return this.m_children[p_index];
	}
	,GetChildIndex: function(p_child) {
		var _g1 = 0;
		var _g = this.m_children.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.m_children[i] == p_child) return i;
		}
		return -1;
	}
	,SetChildIndex: function(p_child,p_index) {
		if(!this.IsChild(p_child)) return;
		var p = haxor_math_Mathf.ClampInt(p_index,0,this.m_children.length - 1);
		if(p_child == this.m_children[p]) return;
		var e1 = this.m_children[p].m_element;
		this.m_element.removeChild(p_child.m_element);
		this.m_element.insertBefore(p_child.m_element,e1);
		HxOverrides.remove(this.m_children,p_child);
		this.m_children.splice(p,0,p_child);
	}
	,Find: function(p_path) {
		var pth = p_path.split(".");
		if(pth.length <= 0) return null;
		var it = this;
		var _g1 = 0;
		var _g = pth.length;
		while(_g1 < _g) {
			var i = _g1++;
			var p = pth[i];
			it = it.GetChildByName(p);
			if(!js_Boot.__instanceof(it,haxor_dom_Container)) {
				if(i >= pth.length - 1) return it;
			}
		}
		return it;
	}
	,Traverse: function(p_callback) {
		this.TraverseStep(0,this,p_callback);
	}
	,TraverseStep: function(d,it,p_c) {
		if(p_c != null) {
			if(!p_c(d,it)) return;
		}
		if(js_Boot.__instanceof(it,haxor_dom_Container)) {
			var c = it;
			var _g1 = 0;
			var _g = c.m_children.length;
			while(_g1 < _g) {
				var i = _g1++;
				this.TraverseStep(d + 1,c.m_children[i],p_c);
			}
		}
	}
	,UpdateMaterial: function() {
		haxor_dom_DOMEntity.prototype.UpdateMaterial.call(this);
		var _g1 = 0;
		var _g = this.m_children.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_children[i].UpdateMaterial();
		}
	}
	,UpdateTransform: function() {
		haxor_dom_DOMEntity.prototype.UpdateTransform.call(this);
		var _g1 = 0;
		var _g = this.m_children.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_children[i].UpdateTransform();
		}
	}
	,UpdateRect: function() {
		haxor_dom_DOMEntity.prototype.UpdateRect.call(this);
		var _g1 = 0;
		var _g = this.m_children.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_children[i].UpdateRect();
		}
	}
	,AddedToStage: function() {
		haxor_dom_DOMEntity.prototype.AddedToStage.call(this);
		var _g1 = 0;
		var _g = this.m_children.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_children[i].AddedToStage();
		}
	}
	,__class__: haxor_dom_Container
	,__properties__: $extend(haxor_dom_DOMEntity.prototype.__properties__,{get_childCount:"get_childCount"})
});
var haxor_dom_DOMLayout = function(p_element) {
	this.m_element = p_element;
	this.m_lock = false;
	this.m_margin = haxor_math_AABB2.get_empty();
	this.m_x = this.m_y = 0;
	this.m_width = 1;
	this.m_height = 1;
	this.m_px = 0;
	this.m_py = 0;
};
$hxClasses["haxor.dom.DOMLayout"] = haxor_dom_DOMLayout;
haxor_dom_DOMLayout.__name__ = ["haxor","dom","DOMLayout"];
haxor_dom_DOMLayout.prototype = {
	get_px: function() {
		return this.m_px;
	}
	,set_px: function(v) {
		this.m_px = v;
		if((this.m_flag & haxor_dom_LayoutFlag.PivotX) != 0) this.Update();
		return v;
	}
	,get_py: function() {
		return this.m_py;
	}
	,set_py: function(v) {
		this.m_py = v;
		if((this.m_flag & haxor_dom_LayoutFlag.PivotY) != 0) this.Update();
		return v;
	}
	,get_x: function() {
		return this.m_x;
	}
	,set_x: function(v) {
		this.m_x = v;
		if((this.m_flag & haxor_dom_LayoutFlag.PositionX) != 0) this.Update();
		return v;
	}
	,get_y: function() {
		return this.m_y;
	}
	,set_y: function(v) {
		this.m_y = v;
		if((this.m_flag & haxor_dom_LayoutFlag.PositionY) != 0) this.Update();
		return v;
	}
	,get_width: function() {
		return this.m_width;
	}
	,set_width: function(v) {
		this.m_width = v;
		if((this.m_flag & haxor_dom_LayoutFlag.SizeX) != 0) this.Update();
		return v;
	}
	,get_height: function() {
		return this.m_height;
	}
	,set_height: function(v) {
		this.m_height = v;
		if((this.m_flag & haxor_dom_LayoutFlag.SizeY) != 0) this.Update();
		return v;
	}
	,get_flag: function() {
		return this.m_flag;
	}
	,set_flag: function(v) {
		this.m_flag = v;
		this.Update();
		return v;
	}
	,get_margin: function() {
		return this.m_margin.get_clone();
	}
	,set_margin: function(v) {
		this.m_margin.SetAABB2(v);
		this.m_element.UpdateTransform();
		return v;
	}
	,Set: function(p_flag,p_px,p_py,p_x,p_y) {
		this.m_flag = p_flag;
		this.m_px = p_px;
		this.m_py = p_py;
		this.m_x = p_x;
		this.m_y = p_y;
		this.Update();
	}
	,FitSize: function() {
		this.m_width = 1;
		this.m_height = 1;
		this.set_flag(haxor_dom_LayoutFlag.SizeXY);
	}
	,FitWidth: function() {
		this.set_width(1);
		this.set_flag(this.m_flag | haxor_dom_LayoutFlag.SizeX);
	}
	,FitHeight: function() {
		this.set_height(1);
		this.set_flag(this.m_flag | haxor_dom_LayoutFlag.SizeY);
	}
	,Update: function() {
		if(this.m_lock) return;
		this.m_lock = true;
		var p = this.m_element.get_parent();
		var pw;
		if(p == null) pw = 0; else pw = p.get_width() - p.get_layout().get_margin().get_xMin() - p.get_layout().get_margin().get_xMax();
		var ph;
		if(p == null) ph = 0; else ph = p.get_height() - p.get_layout().get_margin().get_yMin() - p.get_layout().get_margin().get_yMax();
		if((this.m_flag & haxor_dom_LayoutFlag.PositionX) != 0) this.m_element.set_x(pw * this.m_x);
		if((this.m_flag & haxor_dom_LayoutFlag.PositionY) != 0) this.m_element.set_y(ph * this.m_y);
		if((this.m_flag & haxor_dom_LayoutFlag.PivotX) != 0) this.m_element.set_px(this.m_element.get_width() * this.m_px);
		if((this.m_flag & haxor_dom_LayoutFlag.PivotY) != 0) this.m_element.set_py(this.m_element.get_height() * this.m_py);
		if((this.m_flag & haxor_dom_LayoutFlag.SizeX) != 0) this.m_element.set_width(pw * this.m_width);
		if((this.m_flag & haxor_dom_LayoutFlag.SizeY) != 0) this.m_element.set_height(ph * this.m_height);
		this.m_lock = false;
	}
	,__class__: haxor_dom_DOMLayout
	,__properties__: {set_margin:"set_margin",get_margin:"get_margin",set_flag:"set_flag",get_flag:"get_flag",set_height:"set_height",get_height:"get_height",set_width:"set_width",get_width:"get_width",set_y:"set_y",get_y:"get_y",set_x:"set_x",get_x:"get_x",set_py:"set_py",get_py:"get_py",set_px:"set_px",get_px:"get_px"}
};
var haxor_dom_DOMStage = function(p_container) {
	haxor_dom_DOMStage.m_instance = this;
	haxor_dom_Container.call(this,p_container,"stage");
	haxor_context_EngineContext.resize.Add(this);
};
$hxClasses["haxor.dom.DOMStage"] = haxor_dom_DOMStage;
haxor_dom_DOMStage.__name__ = ["haxor","dom","DOMStage"];
haxor_dom_DOMStage.__interfaces__ = [haxor_core_IResizeable];
haxor_dom_DOMStage.BuildStep = function(n,p) {
	var e = null;
	if(n == null) return false;
	if(p != null) {
		var _g = n.nodeName.toLowerCase();
		switch(_g) {
		case "container":
			e = haxor_dom_DOMStage.BuildContainer(n);
			break;
		case "sprite":
			e = haxor_dom_DOMStage.BuildSprite(n);
			break;
		}
		if(e != null) p.AddChild(e); else if(p.m_element != null) {
			if(n.getAttribute("script") == null) {
				if(p.m_element != n) {
					p.m_element.appendChild(n);
					return true;
				}
			}
		}
	}
	if(js_Boot.__instanceof(e,haxor_dom_Container)) {
		var l = n.children;
		var i = 0;
		while(i < l.length) {
			var it = l.item(i);
			var is_dom = haxor_dom_DOMStage.BuildStep(it,e);
			if(is_dom) i--;
			i++;
		}
	}
	return false;
};
haxor_dom_DOMStage.BuildSprite = function(n) {
	var a_src = haxor_dom_DOMStage._ss(n.getAttribute("src"));
	var a_canvas = n.getAttribute("canvas") != null;
	var a_pattern = n.getAttribute("pattern") != null;
	var res = new haxor_dom_Sprite(a_src,a_canvas);
	res.set_pattern(a_pattern);
	haxor_dom_DOMStage.BuildDOMEntity(n,res);
	return res;
};
haxor_dom_DOMStage.BuildContainer = function(n) {
	var res = new haxor_dom_Container();
	haxor_dom_DOMStage.BuildDOMEntity(n,res);
	return res;
};
haxor_dom_DOMStage.BuildDOMEntity = function(n,e) {
	var sa;
	sa = n.getAttribute("name");
	if(sa != null) {
		if(sa != "") e.set_name(haxor_dom_DOMStage._ss(sa));
	}
	sa = n.getAttribute("style");
	if(sa != null) {
		if(sa != "") e.m_element.style.cssText = sa;
	}
	if(e.m_element != null) e.m_element.style.position = "absolute";
	var pivot = haxor_dom_DOMStage._tv(n.getAttribute("px"),n.getAttribute("py"),n.getAttribute("pxy"));
	var position = haxor_dom_DOMStage._tv(n.getAttribute("x"),n.getAttribute("y"),n.getAttribute("xy"));
	var scale = haxor_dom_DOMStage._tv(n.getAttribute("sx"),n.getAttribute("sy"),n.getAttribute("sxy"),1,1);
	var size = haxor_dom_DOMStage._tv(n.getAttribute("w"),n.getAttribute("h"),n.getAttribute("wh"));
	var tv;
	var v = [0];
	var fx;
	var fy;
	tv = scale;
	e.set_sx(tv[2]);
	e.set_sy(tv[3]);
	tv = pivot;
	fx = haxor_dom_LayoutFlag.PivotX;
	fy = haxor_dom_LayoutFlag.PivotY;
	if(tv[0] > 0) {
		var _g = e.get_layout();
		_g.set_flag(_g.m_flag | fx);
		e.get_layout().set_px(tv[2]);
	} else e.set_px(tv[2]);
	if(tv[1] > 0) {
		var _g1 = e.get_layout();
		_g1.set_flag(_g1.m_flag | fy);
		e.get_layout().set_py(tv[3]);
	} else e.set_py(tv[3]);
	tv = position;
	fx = haxor_dom_LayoutFlag.PositionX;
	fy = haxor_dom_LayoutFlag.PositionY;
	if(tv[0] > 0) {
		var _g2 = e.get_layout();
		_g2.set_flag(_g2.m_flag | fx);
		e.get_layout().set_x(tv[2]);
	} else e.set_x(tv[2]);
	if(tv[1] > 0) {
		var _g3 = e.get_layout();
		_g3.set_flag(_g3.m_flag | fy);
		e.get_layout().set_y(tv[3]);
	} else e.set_y(tv[3]);
	tv = size;
	fx = haxor_dom_LayoutFlag.SizeX;
	fy = haxor_dom_LayoutFlag.SizeY;
	if(tv[0] > 0) {
		var _g4 = e.get_layout();
		_g4.set_flag(_g4.m_flag | fx);
		e.get_layout().set_width(tv[2]);
	} else e.set_width(tv[2]);
	if(tv[1] > 0) {
		var _g5 = e.get_layout();
		_g5.set_flag(_g5.m_flag | fy);
		e.get_layout().set_height(tv[3]);
	} else e.set_height(tv[3]);
	haxor_dom_DOMStage._sn(n.getAttribute("alpha"),v,1.0);
	e.set_alpha(v[0]);
	haxor_dom_DOMStage._sn(n.getAttribute("rotation"),v,0.0);
	e.set_rotation(v[0]);
	sa = n.getAttribute("margin");
	if(sa != null) {
		if(sa != "") {
			var mtk = sa.split(" ");
			var m = e.get_layout().m_margin;
			var n1 = 0.0;
			if(mtk.length == 1) {
				n1 = Std.parseFloat(mtk[0]);
				m.Set(n1,n1,n1,n1);
			} else {
				if(mtk.length >= 1) {
					n1 = Std.parseFloat(mtk[0]);
					m.set_xMin(n1);
				}
				if(mtk.length >= 2) {
					n1 = Std.parseFloat(mtk[1]);
					m.set_xMax(n1);
				}
				if(mtk.length >= 3) {
					n1 = Std.parseFloat(mtk[2]);
					m.set_yMin(n1);
				}
				if(mtk.length >= 4) {
					n1 = Std.parseFloat(mtk[3]);
					m.set_yMax(n1);
				}
			}
			e.get_layout().set_margin(m);
		}
	}
};
haxor_dom_DOMStage._tv = function(sx,sy,sxy,v0,v1) {
	if(v1 == null) v1 = 0.0;
	if(v0 == null) v0 = 0.0;
	var res = [0,0,0,0];
	var v = [0];
	var ixr = false;
	var iyr = false;
	if(sxy != null) {
		var sl = sxy.split(" ");
		if(sl.length == 1) {
			ixr = ixr || haxor_dom_DOMStage._sn(sl[0],v);
			iyr = iyr || ixr;
			res[2] = v[0];
			res[3] = v[0];
		}
		if(sl.length >= 2) {
			ixr = ixr || haxor_dom_DOMStage._sn(sl[0],v);
			res[2] = v[0];
			iyr = iyr || haxor_dom_DOMStage._sn(sl[1],v);
			res[3] = v[0];
		}
	} else {
		if(sx != null) {
			ixr = ixr || haxor_dom_DOMStage._sn(sx,v);
			res[2] = v[0];
		}
		if(sy != null) {
			iyr = iyr || haxor_dom_DOMStage._sn(sy,v);
			res[3] = v[0];
		}
	}
	if(sxy == null) {
		if(sx == null) res[2] = v0;
	}
	if(sxy == null) {
		if(sy == null) res[3] = v1;
	}
	if(ixr) if(haxor_math_Mathf.Abs(res[2]) <= 0.000001) res[2] = 0.0; else res[2] = res[2] / 100;
	if(iyr) if(haxor_math_Mathf.Abs(res[3]) <= 0.000001) res[3] = 0.0; else res[3] = res[3] / 100;
	if(ixr) res[0] = 1; else res[0] = 0;
	if(iyr) res[1] = 1; else res[1] = 0;
	return res;
};
haxor_dom_DOMStage._sn = function(s,v,n) {
	if(s == null) {
		v[0] = n;
		return false;
	}
	var isr = false;
	if(s.indexOf("%") >= 0) {
		isr = true;
		s = StringTools.replace(s,"%","");
	}
	v[0] = Std.parseFloat(s);
	return isr;
};
haxor_dom_DOMStage._ss = function(s) {
	if(s == null) return "";
	if(s.indexOf("@") == 0) return haxor_io_file_Asset.Get(HxOverrides.substr(s,1,null)); else return s;
};
haxor_dom_DOMStage.__super__ = haxor_dom_Container;
haxor_dom_DOMStage.prototype = $extend(haxor_dom_Container.prototype,{
	set_width: function(v) {
		return v;
	}
	,set_height: function(v) {
		return v;
	}
	,OnResize: function(p_width,p_height) {
		this.m_width = p_width;
		this.m_height = p_height;
		this.UpdateRect();
	}
	,__class__: haxor_dom_DOMStage
});
var haxor_dom_LayoutFlag = function() { };
$hxClasses["haxor.dom.LayoutFlag"] = haxor_dom_LayoutFlag;
haxor_dom_LayoutFlag.__name__ = ["haxor","dom","LayoutFlag"];
var haxor_dom_Sprite = function(p_src,p_use_canvas,p_name) {
	if(p_name == null) p_name = "";
	if(p_use_canvas == null) p_use_canvas = false;
	this.m_pattern = false;
	this.m_slices = [];
	this.m_src = "";
	var e = null;
	if(p_use_canvas) {
		var c;
		var _this = window.document;
		c = _this.createElement("canvas");
		c.style.position = "absolute";
		this._rc = c.getContext("2d");
		e = c;
	}
	var img = new Image();
	if(p_src != "") {
		img.src = this.m_src = p_src;
		img.style.backgroundImage = "url(" + this.m_src + ")";
		img.style.backgroundRepeat = "repeat";
		this.set_image(img);
	}
	if(e == null) e = img;
	haxor_dom_Container.call(this,e,p_name);
};
$hxClasses["haxor.dom.Sprite"] = haxor_dom_Sprite;
haxor_dom_Sprite.__name__ = ["haxor","dom","Sprite"];
haxor_dom_Sprite.__super__ = haxor_dom_Container;
haxor_dom_Sprite.prototype = $extend(haxor_dom_Container.prototype,{
	get_slices: function() {
		return this.m_slices.slice();
	}
	,set_slices: function(v) {
		if(v == null) this.m_slices = v = []; else this.m_slices = v.slice();
		this.OnRepaint();
		return v;
	}
	,get_image: function() {
		return this.m_image;
	}
	,set_image: function(v) {
		var _g = this;
		if(this.m_image == v) return v;
		this.m_image = v;
		var olc = function() {
			if(_g.get_width() <= 0) _g.set_width(_g.m_image.naturalWidth);
			if(_g.get_height() <= 0) _g.set_height(_g.m_image.naturalHeight);
			_g.m_image.onload = null;
		};
		this.m_image.onload = olc;
		if(this.get_width() <= 0) this.set_width(this.m_image.naturalWidth);
		if(this.get_height() <= 0) this.set_height(this.m_image.naturalHeight);
		if(this.m_image == null) return v;
		this.OnRepaint();
		return v;
	}
	,set_pattern: function(v) {
		if(this.m_pattern == v) return v;
		this.m_pattern = v;
		this.OnRepaint();
		return v;
	}
	,get_pattern: function() {
		return this.m_pattern;
	}
	,OnRepaint: function() {
		haxor_dom_Container.prototype.OnRepaint.call(this);
		if(this.m_image == null) return;
		if(this.m_element == null) return;
		if(this._rc == null) {
			if(this.m_pattern) {
				this.m_image.src = "";
				this.m_image.style.backgroundImage = "url(" + this.m_src + ")";
				this.m_image.style.backgroundRepeat = "repeat";
			} else {
				this.m_image.src = this.m_src;
				this.m_image.style.removeProperty("background-image");
			}
		} else {
			var c = this.m_element;
			c.width = this.m_width - (this.get_layout().get_margin().get_xMin() + this.get_layout().get_margin().get_xMax());
			c.height = this.m_height - (this.get_layout().get_margin().get_yMin() + this.get_layout().get_margin().get_yMax());
			if(!this.m_pattern) this.DrawSlicedImage(this._rc,this.m_image,c.width,c.height,this.m_slices); else {
				var p = this._rc.createPattern(this.m_image,"repeat");
				this._rc.rect(0,0,c.width,c.height);
				this._rc.fillStyle = p;
				this._rc.fill();
			}
		}
	}
	,DrawSlicedImage: function(p_graphics,p_image,w,h,p_slices) {
		if(p_image == null) return;
		if(p_slices == null) p_slices = []; else p_slices = p_slices;
		var c = p_graphics.canvas;
		var iw = p_image.naturalWidth;
		var ih = p_image.naturalHeight;
		var w1 = c.width;
		var h1 = c.height;
		var l;
		if(p_slices.length <= 0) l = 0; else if(p_slices.length <= 1) l = p_slices[0]; else l = p_slices[0];
		l = Math.min(l,w1 / 2);
		var r;
		if(p_slices.length <= 0) r = 0; else if(p_slices.length <= 1) r = p_slices[0]; else r = p_slices[1];
		r = Math.min(r,w1 / 2);
		var t;
		if(p_slices.length <= 0) t = 0; else if(p_slices.length <= 1) t = p_slices[0]; else t = p_slices[2];
		t = Math.min(t,h1 / 2);
		var b;
		if(p_slices.length <= 0) b = 0; else if(p_slices.length <= 1) b = p_slices[0]; else b = p_slices[3];
		b = Math.min(b,h1 / 2);
		var ix0 = 0;
		var iy0 = 0;
		var iw0 = l;
		var ih0 = t;
		var ix1 = l;
		var iy1 = 0;
		var iw1 = Math.max(1,iw - l - r);
		var ih1 = t;
		var ix2 = Math.max(1,iw - r);
		var iy2 = 0;
		var iw2 = r;
		var ih2 = t;
		var ix3 = 0;
		var iy3 = t;
		var iw3 = l;
		var ih3 = Math.max(1,ih - t - b);
		var ix4 = l;
		var iy4 = t;
		var iw4 = Math.max(1,iw - l - r);
		var ih4 = Math.max(1,ih - t - b);
		var ix5 = Math.max(1,iw - r);
		var iy5 = t;
		var iw5 = r;
		var ih5 = Math.max(1,ih - t - b);
		var ix6 = 0;
		var iy6 = Math.max(1,ih - b);
		var iw6 = l;
		var ih6 = b;
		var ix7 = l;
		var iy7 = Math.max(1,ih - b);
		var iw7 = Math.max(1,iw - l - r);
		var ih7 = b;
		var ix8 = Math.max(1,iw - r);
		var iy8 = Math.max(1,ih - b);
		var iw8 = r;
		var ih8 = b;
		var x0 = 0;
		var y0 = 0;
		var w0 = l;
		var h0 = t;
		var x1 = l;
		var y1 = 0;
		var w11 = Math.max(0,w1 - l - r);
		var h11 = t;
		var x2 = Math.max(0,w1 - r);
		var y2 = 0;
		var w2 = r;
		var h2 = t;
		var x3 = 0;
		var y3 = t;
		var w3 = l;
		var h3 = Math.max(0,h1 - t - b);
		var x4 = l;
		var y4 = t;
		var w4 = Math.max(0,w1 - l - r);
		var h4 = Math.max(0,h1 - t - b);
		var x5 = Math.max(0,w1 - r);
		var y5 = t;
		var w5 = r;
		var h5 = Math.max(0,h1 - t - b);
		var x6 = 0;
		var y6 = Math.max(0,h1 - b);
		var w6 = l;
		var h6 = b;
		var x7 = l;
		var y7 = Math.max(0,h1 - b);
		var w7 = Math.max(0,w1 - l - r);
		var h7 = b;
		var x8 = Math.max(0,w1 - r);
		var y8 = Math.max(0,h1 - b);
		var w8 = r;
		var h8 = b;
		if(l > 0) {
			if(t > 0) p_graphics.drawImage(p_image,ix0,iy0,iw0,ih0,x0,y0,w0,h0);
		}
		if(t > 0) p_graphics.drawImage(p_image,ix1,iy1,iw1,ih1,x1,y1,w11,h11);
		if(r > 0) {
			if(t > 0) p_graphics.drawImage(p_image,ix2,iy2,iw2,ih2,x2,y2,w2,h2);
		}
		if(l > 0) p_graphics.drawImage(p_image,ix3,iy3,iw3,ih3,x3,y3,w3,h3);
		p_graphics.drawImage(p_image,ix4,iy4,iw4,ih4,x4,y4,w4,h4);
		if(r > 0) p_graphics.drawImage(p_image,ix5,iy5,iw5,ih5,x5,y5,w5,h5);
		if(l > 0) {
			if(b > 0) p_graphics.drawImage(p_image,ix6,iy6,iw6,ih6,x6,y6,w6,h6);
		}
		if(b > 0) p_graphics.drawImage(p_image,ix7,iy7,iw7,ih7,x7,y7,w7,h7);
		if(r > 0) {
			if(b > 0) p_graphics.drawImage(p_image,ix8,iy8,iw8,ih8,x8,y8,w8,h8);
		}
	}
	,__class__: haxor_dom_Sprite
	,__properties__: $extend(haxor_dom_Container.prototype.__properties__,{set_pattern:"set_pattern",get_pattern:"get_pattern",set_image:"set_image",get_image:"get_image",set_slices:"set_slices",get_slices:"get_slices"})
});
var haxor_ds_SAP = function(p_bias,p_has_query) {
	if(p_has_query == null) p_has_query = true;
	if(p_bias == null) p_bias = 0.0;
	this.m_has_query = p_has_query;
	this.x = new haxor_ds_SAPList(p_bias,this.m_has_query);
	this.y = new haxor_ds_SAPList(p_bias,this.m_has_query);
	this.z = new haxor_ds_SAPList(p_bias,this.m_has_query);
	this.inside = [];
	this.outside = [];
	this.countIn = 0;
	this.countOut = 0;
};
$hxClasses["haxor.ds.SAP"] = haxor_ds_SAP;
haxor_ds_SAP.__name__ = ["haxor","ds","SAP"];
haxor_ds_SAP.prototype = {
	Create: function(p_id) {
		this.x.Create(p_id);
		this.y.Create(p_id);
		this.z.Create(p_id);
		while(this.inside.length <= p_id) {
			this.inside.push(-1);
			this.outside.push(-1);
		}
	}
	,Update: function(p_id,p_data,p_min,p_max) {
		this.x.Update(p_id,p_data,p_min.x,p_max.x);
		this.y.Update(p_id,p_data,p_min.y,p_max.y);
		this.z.Update(p_id,p_data,p_min.z,p_max.z);
	}
	,Remove: function(p_id) {
		this.x.RemoveById(p_id);
		this.y.RemoveById(p_id);
		this.z.RemoveById(p_id);
	}
	,Overlap: function(p_a,p_b) {
		var ax = this.x.list[p_a];
		var bx = this.x.list[p_b];
		if(!ax.Overlap(bx)) return true;
		var ay = this.y.list[p_a];
		var by = this.y.list[p_b];
		if(!ay.Overlap(by)) return true;
		var az = this.z.list[p_a];
		var bz = this.z.list[p_b];
		if(!az.Overlap(bz)) return true;
		return false;
	}
	,Query: function(p_id,p_outside) {
		if(p_outside == null) p_outside = false;
		if(!this.m_has_query) return;
		this.countIn = 0;
		this.countOut = 0;
		var tx;
		var ty;
		var tz;
		var it;
		var nx;
		var ny;
		var nz;
		tx = this.x.list[p_id];
		ty = this.y.list[p_id];
		tz = this.z.list[p_id];
		it = tx.next;
		while(it != null) {
			if(it.Overlap(tx)) {
				if(this.y.list[it.id].Overlap(ty)) {
					if(this.z.list[it.id].Overlap(tz)) this.inside[this.countIn++] = it.id; else if(p_outside) this.outside[this.countOut++] = it.id;
				} else if(p_outside) this.outside[this.countOut++] = it.id;
			} else if(p_outside) this.outside[this.countOut++] = it.id;
			it = it.next;
		}
		it = tx.prev;
		while(it != null) {
			if(it.Overlap(tx)) {
				if(this.y.list[it.id].Overlap(ty)) {
					if(this.z.list[it.id].Overlap(tz)) this.inside[this.countIn++] = it.id; else if(p_outside) this.outside[this.countOut++] = it.id;
				} else if(p_outside) this.outside[this.countOut++] = it.id;
			} else if(p_outside) this.outside[this.countOut++] = it.id;
			it = it.prev;
		}
	}
	,__class__: haxor_ds_SAP
};
var haxor_ds_SAPList = function(p_bias,p_has_query) {
	if(p_has_query == null) p_has_query = true;
	if(p_bias == null) p_bias = 0.0;
	this.list = [];
	var _g = 0;
	while(_g < 5000) {
		var i = _g++;
		this.list.push(null);
	}
	this.m_has_query = p_has_query;
	this.m_bias = p_bias;
};
$hxClasses["haxor.ds.SAPList"] = haxor_ds_SAPList;
haxor_ds_SAPList.__name__ = ["haxor","ds","SAPList"];
haxor_ds_SAPList.prototype = {
	Create: function(p_id) {
		while(this.list.length <= p_id) this.list.push(null);
		if(this.list[p_id] == null) this.list[p_id] = new haxor_ds_SAPInterval();
	}
	,Update: function(p_id,p_data,p_min,p_max) {
		this.list[p_id].id = p_id;
		this.list[p_id].data = p_data;
		var d = (p_max - p_min) * this.m_bias * 0.5;
		this.list[p_id].Set(p_min - d,p_max + d);
		if(this.m_has_query) this.Relocate(this.list[p_id]);
	}
	,Add: function(p_item) {
		if(this.start == null) {
			this.start = p_item;
			p_item.next = p_item.prev = null;
			return;
		}
		if(p_item == this.start) return;
		var it = this.start;
		while(it != null) {
			if(p_item.min < it.min) {
				this.Insert(p_item,it);
				return;
			}
			if(it.next == null) {
				this.Insert(p_item,it);
				return;
			}
			it = it.next;
		}
	}
	,Insert: function(p_item,p_at) {
		if(p_item == p_at) return;
		if(p_item.min > p_at.min) {
			p_item.next = p_at.next;
			p_item.prev = p_at;
			p_at.next = p_item;
			if(p_item.next != null) p_item.next.prev = p_item;
		} else {
			p_item.next = p_at;
			p_item.prev = p_at.prev;
			p_at.prev = p_item;
			if(p_item.prev != null) p_item.prev.next = p_item;
			if(p_at == this.start) this.start = p_item;
		}
	}
	,Relocate: function(p_item) {
		if(p_item.prev == null) {
			if(p_item.next == null) {
				this.Add(p_item);
				return;
			}
		}
		var it = p_item;
		var nav = 0;
		var location = null;
		while(it != null) {
			var n = it.next;
			var p = it.prev;
			if(n == null) {
				if(p == null) break;
			}
			if(p != null) {
				if(p_item.min < p.min) {
					nav = -1;
					location = p;
				}
			}
			if(n != null) {
				if(p_item.min > n.min) {
					nav = 1;
					location = n;
				}
			}
			if(nav == 0) break;
			if(nav < 0) it = p; else it = n;
			nav = 0;
		}
		if(location != null) {
			this.Remove(p_item);
			this.Insert(p_item,location);
		}
	}
	,RemoveById: function(p_id) {
		this.Remove(this.list[p_id]);
	}
	,Remove: function(p_item) {
		if(!this.m_has_query) return;
		var p = p_item.prev;
		var n = p_item.next;
		if(p != null) p.next = n;
		if(n != null) n.prev = p;
		p_item.next = p_item.prev = null;
		if(p_item == this.start) this.start = n;
	}
	,ToString: function(p_places) {
		if(p_places == null) p_places = 2;
		var s = "";
		if(this.m_has_query) {
			var it = this.start;
			while(it != null) {
				s += it.ToString(p_places);
				it = it.next;
			}
		} else {
			var _g1 = 0;
			var _g = this.list.length;
			while(_g1 < _g) {
				var i = _g1++;
				s += this.list[i].ToString(p_places);
			}
		}
		return s;
	}
	,__class__: haxor_ds_SAPList
};
var haxor_ds_SAPInterval = function() {
	this.min = 0.0;
	this.max = 0.0;
	this.id = 0;
};
$hxClasses["haxor.ds.SAPInterval"] = haxor_ds_SAPInterval;
haxor_ds_SAPInterval.__name__ = ["haxor","ds","SAPInterval"];
haxor_ds_SAPInterval.prototype = {
	Set: function(p_min,p_max) {
		this.min = p_min;
		this.max = p_max;
	}
	,Overlap: function(p_interval) {
		if(p_interval.min > this.min) return p_interval.min <= this.max;
		return p_interval.max >= this.min;
	}
	,ToString: function(p_places) {
		if(p_places == null) p_places = 2;
		return "[" + haxor_math_Mathf.RoundPlaces(this.min,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.max,p_places) + "]";
	}
	,__class__: haxor_ds_SAPInterval
};
var haxor_graphics_GL = function() { };
$hxClasses["haxor.graphics.GL"] = haxor_graphics_GL;
haxor_graphics_GL.__name__ = ["haxor","graphics","GL"];
haxor_graphics_GL.__properties__ = {get_api:"get_api"}
haxor_graphics_GL.get_api = function() {
	return haxor_graphics_GL.m_gl.get_api();
};
haxor_graphics_GL.Initialize = function(p_application) {
	haxor_graphics_GL.m_gl = new haxor_platform_html_graphics_WebGL(p_application);
};
haxor_graphics_GL.Resize = function() {
	haxor_graphics_GL.m_gl.Resize();
};
haxor_graphics_GL.BindBuffer = function(p_target,p_id) {
	haxor_graphics_GL.m_gl.BindBuffer(p_target,p_id);
};
haxor_graphics_GL.BufferData = function(p_target,p_data,p_mode) {
	haxor_graphics_GL.m_gl.BufferData(p_target,p_data,p_mode);
};
haxor_graphics_GL.BufferSubData = function(p_target,p_offset,p_data) {
	haxor_graphics_GL.m_gl.BufferSubData(p_target,p_offset,p_data);
};
haxor_graphics_GL.CreateBuffer = function() {
	return haxor_graphics_GL.m_gl.CreateBuffer();
};
haxor_graphics_GL.DrawArrays = function(p_primitive,p_start,p_count) {
	haxor_graphics_GL.m_gl.DrawArrays(p_primitive,p_start,p_count);
};
haxor_graphics_GL.DrawElements = function(p_primitive,p_count,p_type,p_offset) {
	haxor_graphics_GL.m_gl.DrawElements(p_primitive,p_count,p_type,p_offset);
};
haxor_graphics_GL.DeleteBuffer = function(p_id) {
	haxor_graphics_GL.m_gl.DeleteBuffer(p_id);
};
haxor_graphics_GL.DisableVertexAttrib = function(p_location) {
	haxor_graphics_GL.m_gl.DisableVertexAttrib(p_location);
};
haxor_graphics_GL.EnableVertexAttrib = function(p_location) {
	haxor_graphics_GL.m_gl.EnableVertexAttrib(p_location);
};
haxor_graphics_GL.VertexAttrib3f = function(p_location,p_x,p_y,p_z) {
	haxor_graphics_GL.m_gl.VertexAttrib3f(p_location,p_x,p_y,p_z);
};
haxor_graphics_GL.VertexAttrib4f = function(p_location,p_x,p_y,p_z,p_w) {
	haxor_graphics_GL.m_gl.VertexAttrib4f(p_location,p_x,p_y,p_z,p_w);
};
haxor_graphics_GL.VertexAttribPointer = function(p_location,p_components_size,p_type,p_normalized,p_stride,p_offset) {
	haxor_graphics_GL.m_gl.VertexAttribPointer(p_location,p_components_size,p_type,p_normalized,p_stride,p_offset);
};
haxor_graphics_GL.CompileShader = function(p_shader) {
	haxor_graphics_GL.m_gl.CompileShader(p_shader);
};
haxor_graphics_GL.CreateShader = function(p_type) {
	return haxor_graphics_GL.m_gl.CreateShader(p_type);
};
haxor_graphics_GL.DetachShader = function(p_program,p_shader) {
	haxor_graphics_GL.m_gl.DetachShader(p_program,p_shader);
};
haxor_graphics_GL.DeleteShader = function(p_shader) {
	haxor_graphics_GL.m_gl.DeleteShader(p_shader);
};
haxor_graphics_GL.GetShaderInfoLog = function(p_shader) {
	return haxor_graphics_GL.m_gl.GetShaderInfoLog(p_shader);
};
haxor_graphics_GL.GetShaderParameter = function(p_shader,p_parameter) {
	return haxor_graphics_GL.m_gl.GetShaderParameter(p_shader,p_parameter);
};
haxor_graphics_GL.ShaderSource = function(p_shader,p_source) {
	haxor_graphics_GL.m_gl.ShaderSource(p_shader,p_source);
};
haxor_graphics_GL.AttachShader = function(p_program,p_shader) {
	haxor_graphics_GL.m_gl.AttachShader(p_program,p_shader);
};
haxor_graphics_GL.BindAttribLocation = function(p_program,p_location,p_name) {
	haxor_graphics_GL.m_gl.BindAttribLocation(p_program,p_location,p_name);
};
haxor_graphics_GL.CreateProgram = function() {
	return haxor_graphics_GL.m_gl.CreateProgram();
};
haxor_graphics_GL.DeleteProgram = function(p_program) {
	haxor_graphics_GL.m_gl.DeleteProgram(p_program);
};
haxor_graphics_GL.GetAttribLocation = function(p_program,p_name) {
	return haxor_graphics_GL.m_gl.GetAttribLocation(p_program,p_name);
};
haxor_graphics_GL.GetUniformLocation = function(p_program,p_name) {
	return haxor_graphics_GL.m_gl.GetUniformLocation(p_program,p_name);
};
haxor_graphics_GL.GetProgramInfoLog = function(p_program) {
	return haxor_graphics_GL.m_gl.GetProgramInfoLog(p_program);
};
haxor_graphics_GL.GetProgramParameter = function(p_program,p_parameter) {
	return haxor_graphics_GL.m_gl.GetProgramParameter(p_program,p_parameter);
};
haxor_graphics_GL.LinkProgram = function(p_program) {
	haxor_graphics_GL.m_gl.LinkProgram(p_program);
};
haxor_graphics_GL.UseProgram = function(p_program) {
	haxor_graphics_GL.m_gl.UseProgram(p_program);
};
haxor_graphics_GL.ActiveTexture = function(p_slot) {
	haxor_graphics_GL.m_gl.ActiveTexture(p_slot);
};
haxor_graphics_GL.BindFramebuffer = function(p_target,p_id) {
	haxor_graphics_GL.m_gl.BindFramebuffer(p_target,p_id);
};
haxor_graphics_GL.BindRenderbuffer = function(p_target,p_id) {
	haxor_graphics_GL.m_gl.BindRenderbuffer(p_target,p_id);
};
haxor_graphics_GL.BindTexture = function(p_target,p_id) {
	haxor_graphics_GL.m_gl.BindTexture(p_target,p_id);
};
haxor_graphics_GL.CreateFramebuffer = function() {
	return haxor_graphics_GL.m_gl.CreateFramebuffer();
};
haxor_graphics_GL.CreateRenderbuffer = function() {
	return haxor_graphics_GL.m_gl.CreateRenderbuffer();
};
haxor_graphics_GL.CreateTexture = function() {
	return haxor_graphics_GL.m_gl.CreateTexture();
};
haxor_graphics_GL.DeleteFramebuffer = function(p_id) {
	haxor_graphics_GL.m_gl.DeleteFramebuffer(p_id);
};
haxor_graphics_GL.DeleteRenderbuffer = function(p_id) {
	haxor_graphics_GL.m_gl.DeleteRenderbuffer(p_id);
};
haxor_graphics_GL.DeleteTexture = function(p_id) {
	haxor_graphics_GL.m_gl.DeleteTexture(p_id);
};
haxor_graphics_GL.FramebufferRenderbuffer = function(p_target,p_attachment,p_renderbuffer_target,p_renderbuffer_id) {
	haxor_graphics_GL.m_gl.FramebufferRenderbuffer(p_target,p_attachment,p_renderbuffer_target,p_renderbuffer_id);
};
haxor_graphics_GL.FramebufferTexture2D = function(p_target,p_attachment,p_texture_target,p_texture_id,p_miplevel) {
	haxor_graphics_GL.m_gl.FramebufferTexture2D(p_target,p_attachment,p_texture_target,p_texture_id,p_miplevel);
};
haxor_graphics_GL.GenerateMipmap = function(p_target) {
	haxor_graphics_GL.m_gl.GenerateMipmap(p_target);
};
haxor_graphics_GL.PixelStorei = function(p_parameter,p_value) {
	haxor_graphics_GL.m_gl.PixelStorei(p_parameter,p_value);
};
haxor_graphics_GL.RenderbufferStorage = function(p_target,p_format,p_width,p_height) {
	haxor_graphics_GL.m_gl.RenderbufferStorage(p_target,p_format,p_width,p_height);
};
haxor_graphics_GL.TexImage2D = function(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type,p_data) {
	haxor_graphics_GL.m_gl.TexImage2D(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type,p_data);
};
haxor_graphics_GL.TexImage2DAlloc = function(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type) {
	haxor_graphics_GL.m_gl.TexImage2DAlloc(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type);
};
haxor_graphics_GL.TexSubImage2D = function(p_target,p_level,p_x,p_y,p_width,p_height,p_format,p_channel_type,p_data) {
	haxor_graphics_GL.m_gl.TexSubImage2D(p_target,p_level,p_x,p_y,p_width,p_height,p_format,p_channel_type,p_data);
};
haxor_graphics_GL.TexStorage2D = function(p_target,p_num_mipmaps,p_channels,p_width,p_height) {
	haxor_graphics_GL.m_gl.TexStorage2D(p_target,p_num_mipmaps,p_channels,p_width,p_height);
};
haxor_graphics_GL.TexParameterf = function(p_target,p_parameter,p_value) {
	haxor_graphics_GL.m_gl.TexParameterf(p_target,p_parameter,p_value);
};
haxor_graphics_GL.TexParameteri = function(p_target,p_parameter,p_value) {
	haxor_graphics_GL.m_gl.TexParameteri(p_target,p_parameter,p_value);
};
haxor_graphics_GL.Uniform1f = function(p_location,p_x) {
	haxor_graphics_GL.m_gl.Uniform1f(p_location,p_x);
};
haxor_graphics_GL.Uniform2f = function(p_location,p_x,p_y) {
	haxor_graphics_GL.m_gl.Uniform2f(p_location,p_x,p_y);
};
haxor_graphics_GL.Uniform3f = function(p_location,p_x,p_y,p_z) {
	haxor_graphics_GL.m_gl.Uniform3f(p_location,p_x,p_y,p_z);
};
haxor_graphics_GL.Uniform4f = function(p_location,p_x,p_y,p_z,p_w) {
	haxor_graphics_GL.m_gl.Uniform4f(p_location,p_x,p_y,p_z,p_w);
};
haxor_graphics_GL.Uniform1i = function(p_location,p_x) {
	haxor_graphics_GL.m_gl.Uniform1i(p_location,p_x);
};
haxor_graphics_GL.Uniform2i = function(p_location,p_x,p_y) {
	haxor_graphics_GL.m_gl.Uniform2i(p_location,p_x,p_y);
};
haxor_graphics_GL.Uniform3i = function(p_location,p_x,p_y,p_z) {
	haxor_graphics_GL.m_gl.Uniform3i(p_location,p_x,p_y,p_z);
};
haxor_graphics_GL.Uniform4i = function(p_location,p_x,p_y,p_z,p_w) {
	haxor_graphics_GL.m_gl.Uniform4i(p_location,p_x,p_y,p_z,p_w);
};
haxor_graphics_GL.Uniform1fv = function(p_location,p_v) {
	haxor_graphics_GL.m_gl.Uniform1fv(p_location,p_v);
};
haxor_graphics_GL.Uniform2fv = function(p_location,p_v) {
	haxor_graphics_GL.m_gl.Uniform2fv(p_location,p_v);
};
haxor_graphics_GL.Uniform3fv = function(p_location,p_v) {
	haxor_graphics_GL.m_gl.Uniform3fv(p_location,p_v);
};
haxor_graphics_GL.Uniform4fv = function(p_location,p_v) {
	haxor_graphics_GL.m_gl.Uniform4fv(p_location,p_v);
};
haxor_graphics_GL.Uniform1iv = function(p_location,p_v) {
	haxor_graphics_GL.m_gl.Uniform1iv(p_location,p_v);
};
haxor_graphics_GL.Uniform2iv = function(p_location,p_v) {
	haxor_graphics_GL.m_gl.Uniform2iv(p_location,p_v);
};
haxor_graphics_GL.Uniform3iv = function(p_location,p_v) {
	haxor_graphics_GL.m_gl.Uniform3iv(p_location,p_v);
};
haxor_graphics_GL.Uniform4iv = function(p_location,p_v) {
	haxor_graphics_GL.m_gl.Uniform4iv(p_location,p_v);
};
haxor_graphics_GL.UniformMatrix2fv = function(p_location,p_transpose,p_v) {
	haxor_graphics_GL.m_gl.UniformMatrix2fv(p_location,p_transpose,p_v);
};
haxor_graphics_GL.UniformMatrix3fv = function(p_location,p_transpose,p_v) {
	haxor_graphics_GL.m_gl.UniformMatrix3fv(p_location,p_transpose,p_v);
};
haxor_graphics_GL.UniformMatrix4fv = function(p_location,p_transpose,p_v) {
	haxor_graphics_GL.m_gl.UniformMatrix4fv(p_location,p_transpose,p_v);
};
haxor_graphics_GL.BlendFunc = function(p_src,p_dst) {
	haxor_graphics_GL.m_gl.BlendFunc(p_src,p_dst);
};
haxor_graphics_GL.Disable = function(p_flag) {
	haxor_graphics_GL.m_gl.Disable(p_flag);
};
haxor_graphics_GL.Enable = function(p_flag) {
	haxor_graphics_GL.m_gl.Enable(p_flag);
};
haxor_graphics_GL.DepthMask = function(p_flag) {
	haxor_graphics_GL.m_gl.DepthMask(p_flag);
};
haxor_graphics_GL.DepthFunc = function(p_flag) {
	haxor_graphics_GL.m_gl.DepthFunc(p_flag);
};
haxor_graphics_GL.CullFace = function(p_face) {
	haxor_graphics_GL.m_gl.CullFace(p_face);
};
haxor_graphics_GL.FrontFace = function(p_face) {
	haxor_graphics_GL.m_gl.FrontFace(p_face);
};
haxor_graphics_GL.Clear = function(p_flag) {
	haxor_graphics_GL.m_gl.Clear(p_flag);
};
haxor_graphics_GL.ClearDepth = function(p_value) {
	haxor_graphics_GL.m_gl.ClearDepth(p_value);
};
haxor_graphics_GL.ClearColor = function(p_r,p_g,p_b,p_a) {
	haxor_graphics_GL.m_gl.ClearColor(p_r,p_g,p_b,p_a);
};
haxor_graphics_GL.Viewport = function(p_x,p_y,p_width,p_height) {
	haxor_graphics_GL.m_gl.Viewport(p_x,p_y,p_width,p_height);
};
haxor_graphics_GL.Scissor = function(p_x,p_y,p_width,p_height) {
	haxor_graphics_GL.m_gl.Scissor(p_x,p_y,p_width,p_height);
};
haxor_graphics_GL.ReadPixels = function(p_x,p_y,p_width,p_height,p_format,p_type,p_pixels) {
	haxor_graphics_GL.m_gl.ReadPixels(p_x,p_y,p_width,p_height,p_format,p_type,p_pixels);
};
haxor_graphics_GL.GetError = function() {
	return haxor_graphics_GL.m_gl.GetError();
};
haxor_graphics_GL.GetErrorCode = function() {
	return haxor_graphics_GL.m_gl.GetErrorCode();
};
haxor_graphics_GL.GetErrorString = function(p_code) {
	return haxor_graphics_GL.m_gl.GetErrorString(p_code);
};
haxor_graphics_GL.LogError = function() {
	haxor_graphics_GL.m_gl.LogError();
};
haxor_graphics_GL.Assert = function(p_log) {
};
haxor_graphics_GL.Flush = function() {
	null;
};
haxor_graphics_GL.Focus = function() {
	haxor_graphics_GL.m_gl.Focus();
};
var haxor_graphics_Gizmo = function() { };
$hxClasses["haxor.graphics.Gizmo"] = haxor_graphics_Gizmo;
haxor_graphics_Gizmo.__name__ = ["haxor","graphics","Gizmo"];
haxor_graphics_Gizmo.Grid = function(p_area,p_color) {
	haxor_context_EngineContext.gizmo.DrawGrid(p_area,p_color);
};
haxor_graphics_Gizmo.Axis = function(p_area) {
	haxor_context_EngineContext.gizmo.DrawAxis(p_area);
};
var haxor_graphics_GraphicAPI = { __ename__ : true, __constructs__ : ["None","OpenGL","OpenGLES","WebGL"] };
haxor_graphics_GraphicAPI.None = ["None",0];
haxor_graphics_GraphicAPI.None.toString = $estr;
haxor_graphics_GraphicAPI.None.__enum__ = haxor_graphics_GraphicAPI;
haxor_graphics_GraphicAPI.OpenGL = ["OpenGL",1];
haxor_graphics_GraphicAPI.OpenGL.toString = $estr;
haxor_graphics_GraphicAPI.OpenGL.__enum__ = haxor_graphics_GraphicAPI;
haxor_graphics_GraphicAPI.OpenGLES = ["OpenGLES",2];
haxor_graphics_GraphicAPI.OpenGLES.toString = $estr;
haxor_graphics_GraphicAPI.OpenGLES.__enum__ = haxor_graphics_GraphicAPI;
haxor_graphics_GraphicAPI.WebGL = ["WebGL",3];
haxor_graphics_GraphicAPI.WebGL.toString = $estr;
haxor_graphics_GraphicAPI.WebGL.__enum__ = haxor_graphics_GraphicAPI;
var haxor_graphics_GraphicContext = function(p_application) {
	this.m_api = haxor_graphics_GraphicAPI.None;
	this.m_application = p_application;
};
$hxClasses["haxor.graphics.GraphicContext"] = haxor_graphics_GraphicContext;
haxor_graphics_GraphicContext.__name__ = ["haxor","graphics","GraphicContext"];
haxor_graphics_GraphicContext.prototype = {
	get_api: function() {
		return this.m_api;
	}
	,CheckExtensions: function() {
	}
	,Destroy: function() {
	}
	,Flush: function() {
	}
	,Focus: function() {
	}
	,Resize: function() {
	}
	,BindBuffer: function(p_target,p_id) {
	}
	,BufferData: function(p_target,p_data,p_mode) {
	}
	,BufferSubData: function(p_target,p_offset,p_data) {
	}
	,CreateBuffer: function() {
		return haxor_graphics_GL.INVALID;
	}
	,DeleteBuffer: function(p_id) {
	}
	,DrawArrays: function(p_primitive,p_start,p_count) {
	}
	,DrawElements: function(p_primitive,p_count,p_type,p_offset) {
	}
	,EnableVertexAttrib: function(p_location) {
	}
	,DisableVertexAttrib: function(p_location) {
	}
	,VertexAttrib3f: function(p_location,p_x,p_y,p_z) {
	}
	,VertexAttrib4f: function(p_location,p_x,p_y,p_z,p_w) {
	}
	,VertexAttribPointer: function(p_location,p_components_size,p_type,p_normalized,p_stride,p_offset) {
	}
	,CompileShader: function(p_shader) {
	}
	,CreateShader: function(p_type) {
		return haxor_graphics_GL.INVALID;
	}
	,DeleteShader: function(p_shader) {
	}
	,DetachShader: function(p_program,p_shader) {
	}
	,GetShaderInfoLog: function(p_shader) {
		return "";
	}
	,GetShaderParameter: function(p_shader,p_parameter) {
		return -1;
	}
	,ShaderSource: function(p_shader,p_source) {
	}
	,AttachShader: function(p_program,p_shader) {
	}
	,BindAttribLocation: function(p_program,p_location,p_name) {
	}
	,CreateProgram: function() {
		return haxor_graphics_GL.INVALID;
	}
	,DeleteProgram: function(p_program) {
	}
	,GetAttribLocation: function(p_program,p_name) {
		return -1;
	}
	,GetUniformLocation: function(p_program,p_name) {
		return haxor_graphics_GL.INVALID;
	}
	,GetProgramInfoLog: function(p_program) {
		return "";
	}
	,GetProgramParameter: function(p_program,p_parameter) {
		return -1;
	}
	,LinkProgram: function(p_program) {
	}
	,UseProgram: function(p_program) {
	}
	,Uniform1f: function(p_location,p_x) {
	}
	,Uniform2f: function(p_location,p_x,p_y) {
	}
	,Uniform3f: function(p_location,p_x,p_y,p_z) {
	}
	,Uniform4f: function(p_location,p_x,p_y,p_z,p_w) {
	}
	,Uniform1i: function(p_location,p_x) {
	}
	,Uniform2i: function(p_location,p_x,p_y) {
	}
	,Uniform3i: function(p_location,p_x,p_y,p_z) {
	}
	,Uniform4i: function(p_location,p_x,p_y,p_z,p_w) {
	}
	,Uniform1fv: function(p_location,p_v) {
	}
	,Uniform2fv: function(p_location,p_v) {
	}
	,Uniform3fv: function(p_location,p_v) {
	}
	,Uniform4fv: function(p_location,p_v) {
	}
	,Uniform1iv: function(p_location,p_v) {
	}
	,Uniform2iv: function(p_location,p_v) {
	}
	,Uniform3iv: function(p_location,p_v) {
	}
	,Uniform4iv: function(p_location,p_v) {
	}
	,UniformMatrix2fv: function(p_location,p_transpose,p_v) {
	}
	,UniformMatrix3fv: function(p_location,p_transpose,p_v) {
	}
	,UniformMatrix4fv: function(p_location,p_transpose,p_v) {
	}
	,ActiveTexture: function(p_slot) {
	}
	,BindFramebuffer: function(p_target,p_id) {
	}
	,BindRenderbuffer: function(p_target,p_id) {
	}
	,BindTexture: function(p_target,p_id) {
	}
	,CreateFramebuffer: function() {
		return haxor_graphics_GL.INVALID;
	}
	,CreateRenderbuffer: function() {
		return haxor_graphics_GL.INVALID;
	}
	,CreateTexture: function() {
		return haxor_graphics_GL.INVALID;
	}
	,DeleteFramebuffer: function(p_id) {
	}
	,DeleteRenderbuffer: function(p_id) {
	}
	,DeleteTexture: function(p_id) {
	}
	,FramebufferRenderbuffer: function(p_target,p_attachment,p_renderbuffer_target,p_renderbuffer_id) {
	}
	,FramebufferTexture2D: function(p_target,p_attachment,p_texture_target,p_texture_id,p_miplevel) {
	}
	,GenerateMipmap: function(p_target) {
	}
	,PixelStorei: function(p_parameter,p_value) {
	}
	,RenderbufferStorage: function(p_target,p_format,p_width,p_height) {
	}
	,TexImage2DAlloc: function(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type) {
	}
	,TexImage2D: function(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type,p_data) {
	}
	,TexSubImage2D: function(p_target,p_level,p_x,p_y,p_width,p_height,p_format,p_channel_type,p_data) {
	}
	,TexStorage2D: function(p_target,p_num_mipmaps,p_channels,p_width,p_height) {
	}
	,TexParameterf: function(p_target,p_parameter,p_value) {
	}
	,TexParameteri: function(p_target,p_parameter,p_value) {
	}
	,BlendFunc: function(p_src,p_dst) {
	}
	,Disable: function(p_flag) {
	}
	,Enable: function(p_flag) {
	}
	,DepthMask: function(p_flag) {
	}
	,DepthFunc: function(p_flag) {
	}
	,CullFace: function(p_face) {
	}
	,FrontFace: function(p_face) {
	}
	,Clear: function(p_flag) {
	}
	,ClearDepth: function(p_value) {
	}
	,ClearColor: function(p_r,p_g,p_b,p_a) {
	}
	,Viewport: function(p_x,p_y,p_width,p_height) {
	}
	,Scissor: function(p_x,p_y,p_width,p_height) {
	}
	,ReadPixels: function(p_x,p_y,p_width,p_height,p_format,p_type,p_pixels) {
	}
	,GetErrorCode: function() {
		return 0;
	}
	,GetErrorString: function(p_code) {
		switch(p_code) {
		case 0:
			return "";
		case 1280:
			return "Invalid Enum.";
		case 1281:
			return "Numeric argument is out of range.";
		case 1282:
			return "Operation not allowed in the current state.";
		case 1286:
			return "Write or Read in FrameBuffer not complete.";
		case 1285:
			return "Out of Memory.";
		}
		return "Unknown Error.";
	}
	,GetError: function() {
		return this.GetErrorString(this.GetErrorCode());
	}
	,Assert: function(p_log) {
		var err = this.GetErrorCode();
		if(err != 0) throw "GraphicContext> " + this.GetErrorString(err) + " - " + p_log;
	}
	,LogError: function() {
		haxor_core_Console.Log(this.GetError());
	}
	,__class__: haxor_graphics_GraphicContext
	,__properties__: {get_api:"get_api"}
};
var haxor_math_AABB2 = function(p_x,p_y,p_width,p_height) {
	if(p_height == null) p_height = 0;
	if(p_width == null) p_width = 0;
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.SetXYWH(p_x,p_y,p_width,p_height);
};
$hxClasses["haxor.math.AABB2"] = haxor_math_AABB2;
haxor_math_AABB2.__name__ = ["haxor","math","AABB2"];
haxor_math_AABB2.__properties__ = {get_empty:"get_empty",get_temp:"get_temp"}
haxor_math_AABB2.get_temp = function() {
	return haxor_context_EngineContext.data.get_aabb2();
};
haxor_math_AABB2.FromMinMax = function(p_xmin,p_xmax,p_ymin,p_ymax) {
	var b = new haxor_math_AABB2();
	b.m_xMin = p_xmin;
	b.m_xMax = p_xmax;
	b.m_yMin = p_ymin;
	b.m_yMax = p_ymax;
	b.Validate();
	return b;
};
haxor_math_AABB2.get_empty = function() {
	return new haxor_math_AABB2();
};
haxor_math_AABB2.prototype = {
	get_clone: function() {
		return haxor_math_AABB2.FromMinMax(this.get_xMin(),this.get_xMax(),this.get_yMin(),this.get_yMax());
	}
	,get_min: function() {
		return new haxor_math_Vector2(this.m_xMin,this.m_yMin);
	}
	,set_min: function(v) {
		this.set_xMin(v.x);
		this.set_yMin(v.y);
		return v;
	}
	,get_max: function() {
		return new haxor_math_Vector2(this.m_xMax,this.m_yMax);
	}
	,set_max: function(v) {
		this.set_xMax(v.x);
		this.set_yMax(v.y);
		return v;
	}
	,get_xMin: function() {
		return this.m_xMin;
	}
	,set_xMin: function(v) {
		this.m_xMin = v;
		this.Validate();
		return v;
	}
	,get_yMin: function() {
		return this.m_yMin;
	}
	,set_yMin: function(v) {
		this.m_yMin = v;
		this.Validate();
		return v;
	}
	,get_xMax: function() {
		return this.m_xMax;
	}
	,set_xMax: function(v) {
		this.m_xMax = v;
		this.Validate();
		return v;
	}
	,get_yMax: function() {
		return this.m_yMax;
	}
	,set_yMax: function(v) {
		this.m_yMax = v;
		this.Validate();
		return v;
	}
	,get_center: function() {
		return new haxor_math_Vector2(this.get_xMin() + (this.get_xMax() - this.get_xMin()) * 0.5,this.get_yMin() + (this.get_yMax() - this.get_yMin()) * 0.5);
	}
	,set_center: function(v) {
		var hw = haxor_math_Mathf.Abs(this.get_xMax() - this.get_xMin()) * 0.5;
		var hh = haxor_math_Mathf.Abs(this.get_yMax() - this.get_yMin()) * 0.5;
		this.m_xMin = v.x - hw;
		this.m_xMax = v.x + hw;
		this.m_yMin = v.y - hh;
		this.m_yMax = v.y + hh;
		return v;
	}
	,get_x: function() {
		return this.get_xMin();
	}
	,set_x: function(v) {
		this.set_xMin(v);
		return v;
	}
	,get_y: function() {
		return this.get_yMin();
	}
	,set_y: function(v) {
		this.set_yMin(v);
		return v;
	}
	,get_width: function() {
		return haxor_math_Mathf.Abs(this.get_xMax() - this.get_xMin());
	}
	,set_width: function(v) {
		this.set_xMax(this.get_xMin() + v);
		return v;
	}
	,get_height: function() {
		return haxor_math_Mathf.Abs(this.get_yMax() - this.get_yMin());
	}
	,set_height: function(v) {
		this.set_yMax(this.get_yMin() + v);
		return v;
	}
	,get_size: function() {
		return new haxor_math_Vector2(haxor_math_Mathf.Abs(this.get_xMax() - this.get_xMin()),haxor_math_Mathf.Abs(this.get_yMax() - this.get_yMin()));
	}
	,set_size: function(v) {
		this.set_width(v.x);
		this.set_height(v.y);
		return v;
	}
	,Validate: function() {
	}
	,Add: function(p_v) {
		this.m_xMax = Math.max(p_v.m_xMax,this.m_xMax);
		this.m_xMin = Math.min(p_v.m_xMin,this.m_xMin);
		this.m_yMax = Math.max(p_v.m_yMax,this.m_yMax);
		this.m_yMin = Math.min(p_v.m_yMin,this.m_yMin);
		return this;
	}
	,Set: function(p_xmin,p_xmax,p_ymin,p_ymax) {
		this.m_xMin = p_xmin;
		this.m_yMin = p_ymin;
		this.m_xMax = p_xmax;
		this.m_yMax = p_ymax;
		this.Validate();
		return this;
	}
	,SetXYWH: function(p_x,p_y,p_width,p_height) {
		this.m_xMin = p_x;
		this.m_yMin = p_y;
		this.m_xMax = this.m_xMin + p_width;
		this.m_yMax = this.m_yMin + p_height;
		return this;
	}
	,SetAABB2: function(p_v) {
		this.m_xMin = p_v.m_xMin;
		this.m_yMin = p_v.m_yMin;
		this.m_xMax = p_v.m_xMax;
		this.m_yMax = p_v.m_yMax;
		return this;
	}
	,Encapsulate: function(p_point) {
		this.set_xMin(haxor_math_Mathf.Min(p_point.x,this.get_xMin()));
		this.set_xMax(haxor_math_Mathf.Max(p_point.x,this.get_xMax()));
		this.set_yMin(haxor_math_Mathf.Min(p_point.y,this.get_yMin()));
		this.set_yMax(haxor_math_Mathf.Max(p_point.y,this.get_yMax()));
	}
	,Encapsulate3: function(p_x,p_y) {
		if(p_y == null) p_y = 0;
		if(p_x == null) p_x = 0;
		this.m_xMin = Math.min(p_x,this.m_xMin);
		this.m_xMax = Math.max(p_x,this.m_xMax);
		this.m_yMin = Math.min(p_y,this.m_yMin);
		this.m_yMax = Math.max(p_y,this.m_yMax);
		this.Validate();
		return this;
	}
	,ToString: function(p_places) {
		if(p_places == null) p_places = 2;
		var s0 = haxor_math_Mathf.RoundPlaces(this.m_xMin,p_places) + "";
		var s1 = haxor_math_Mathf.RoundPlaces(this.m_xMax,p_places) + "";
		var s2 = haxor_math_Mathf.RoundPlaces(this.m_yMin,p_places) + "";
		var s3 = haxor_math_Mathf.RoundPlaces(this.m_yMax,p_places) + "";
		return "[" + s0 + "," + s1 + "|" + s2 + "," + s3 + "]";
	}
	,__class__: haxor_math_AABB2
	,__properties__: {set_size:"set_size",get_size:"get_size",set_height:"set_height",get_height:"get_height",set_width:"set_width",get_width:"get_width",set_y:"set_y",get_y:"get_y",set_x:"set_x",get_x:"get_x",set_center:"set_center",get_center:"get_center",set_yMax:"set_yMax",get_yMax:"get_yMax",set_xMax:"set_xMax",get_xMax:"get_xMax",set_yMin:"set_yMin",get_yMin:"get_yMin",set_xMin:"set_xMin",get_xMin:"get_xMin",set_max:"set_max",get_max:"get_max",set_min:"set_min",get_min:"get_min",get_clone:"get_clone"}
};
var haxor_graphics_Graphics = function() { };
$hxClasses["haxor.graphics.Graphics"] = haxor_graphics_Graphics;
haxor_graphics_Graphics.__name__ = ["haxor","graphics","Graphics"];
haxor_graphics_Graphics.Viewport = function(p_viewport) {
	var vp = p_viewport;
	var dirty = false;
	if(haxor_math_Mathf.Abs(vp.get_xMin() - haxor_graphics_Graphics.m_last_viewport.get_xMin()) > 0.0) dirty = true; else if(haxor_math_Mathf.Abs(vp.get_yMin() - haxor_graphics_Graphics.m_last_viewport.get_yMin()) > 0.0) dirty = true; else if(haxor_math_Mathf.Abs(haxor_math_Mathf.Abs(vp.get_xMax() - vp.get_xMin()) - haxor_graphics_Graphics.m_last_viewport.get_width()) > 0.0) dirty = true; else if(haxor_math_Mathf.Abs(haxor_math_Mathf.Abs(vp.get_yMax() - vp.get_yMin()) - haxor_graphics_Graphics.m_last_viewport.get_height()) > 0.0) dirty = true;
	if(dirty) {
		haxor_graphics_Graphics.m_last_viewport.SetAABB2(vp);
		haxor_graphics_GL.Viewport(vp.get_xMin(),vp.get_yMin(),haxor_math_Mathf.Abs(vp.get_xMax() - vp.get_xMin()),haxor_math_Mathf.Abs(vp.get_yMax() - vp.get_yMin()));
		haxor_graphics_GL.Scissor(vp.get_xMin(),vp.get_yMin(),haxor_math_Mathf.Abs(vp.get_xMax() - vp.get_xMin()),haxor_math_Mathf.Abs(vp.get_yMax() - vp.get_yMin()));
	}
};
haxor_graphics_Graphics.Clear = function(p_camera) {
	var c = p_camera;
	haxor_graphics_Graphics.Viewport(p_camera.m_pixelViewport);
	if(c.clear != haxor_core_ClearFlag.None) {
		var flag = 0;
		if((c.clear & haxor_core_ClearFlag.Color) != 0) flag |= 16384;
		if((c.clear & haxor_core_ClearFlag.Skybox) != 0) flag |= 16384;
		if((c.clear & haxor_core_ClearFlag.Depth) != 0) flag |= 256;
		haxor_graphics_GL.m_gl.ClearColor(c.background.r,c.background.g,c.background.b,c.background.a);
		haxor_graphics_GL.m_gl.ClearDepth(1.0);
		haxor_graphics_GL.m_gl.Clear(flag);
	}
};
haxor_graphics_Graphics.Render = function(p_mesh,p_material,p_transform,p_camera) {
	haxor_context_EngineContext.material.Bind(p_material,p_transform,p_camera);
	haxor_context_EngineContext.mesh.Bind(p_mesh);
	haxor_context_EngineContext.mesh.Draw(p_mesh);
};
haxor_graphics_Graphics.DrawTexture = function(p_texture,p_x,p_y,p_width,p_height,p_color) {
	if(p_height == null) p_height = 256;
	if(p_width == null) p_width = 256;
	if(p_y == null) p_y = 0.0;
	if(p_x == null) p_x = 0.0;
	if(p_texture == null) return;
	var mat = haxor_context_EngineContext.gizmo.texture_material;
	mat.SetFloat2("Screen",haxor_graphics_Screen.m_width,haxor_graphics_Screen.m_height);
	mat.SetFloat4("Rect",p_x,p_y,p_width,p_height);
	mat.SetTexture("Texture",p_texture);
	var c;
	if(p_color == null) c = haxor_context_EngineContext.data.get_c().Set(1,1,1,1); else c = p_color;
	mat.SetFloat4("Tint",c.r,c.g,c.b,c.a);
	haxor_graphics_Graphics.Render(haxor_context_EngineContext.gizmo.texture,mat);
};
var haxor_graphics_Screen = function() { };
$hxClasses["haxor.graphics.Screen"] = haxor_graphics_Screen;
haxor_graphics_Screen.__name__ = ["haxor","graphics","Screen"];
haxor_graphics_Screen.__properties__ = {set_cursor:"set_cursor",get_cursor:"get_cursor",set_fullscreen:"set_fullscreen",get_fullscreen:"get_fullscreen",get_height:"get_height",get_width:"get_width"}
haxor_graphics_Screen.get_width = function() {
	return haxor_graphics_Screen.m_width;
};
haxor_graphics_Screen.get_height = function() {
	return haxor_graphics_Screen.m_height;
};
haxor_graphics_Screen.get_fullscreen = function() {
	return haxor_graphics_Screen.m_fullscreen;
};
haxor_graphics_Screen.set_fullscreen = function(v) {
	haxor_graphics_Screen.m_fullscreen = haxor_graphics_Screen.m_application.OnFullscreenRequest(v);
	return haxor_graphics_Screen.m_fullscreen;
};
haxor_graphics_Screen.get_cursor = function() {
	return haxor_graphics_Screen.m_cursor;
};
haxor_graphics_Screen.set_cursor = function(v) {
	if(v == haxor_graphics_CursorMode.Lock) {
		var is_locked = haxor_graphics_Screen.m_application.OnPointerLockRequest(true);
		if(!is_locked) return haxor_graphics_Screen.m_cursor = haxor_graphics_CursorMode.Show;
		haxor_graphics_Screen.m_application.OnPointerVisibilityRequest(false);
		return haxor_graphics_Screen.m_cursor = haxor_graphics_CursorMode.Lock;
	}
	haxor_graphics_Screen.m_application.OnPointerLockRequest(false);
	var is_visible = haxor_graphics_Screen.m_application.OnPointerVisibilityRequest(v == haxor_graphics_CursorMode.Show);
	return is_visible?haxor_graphics_Screen.m_cursor = haxor_graphics_CursorMode.Show:haxor_graphics_Screen.m_cursor = haxor_graphics_CursorMode.Hide;
};
haxor_graphics_Screen.Initialize = function(p_application) {
	haxor_graphics_Screen.m_application = p_application;
	haxor_graphics_Screen.m_width = 0;
	haxor_graphics_Screen.m_height = 0;
	haxor_graphics_Screen.m_fullscreen = false;
	haxor_graphics_Screen.m_cursor = haxor_graphics_CursorMode.Show;
	haxor_graphics_Screen.m_application = null;
};
var haxor_graphics_CursorMode = { __ename__ : true, __constructs__ : ["Show","Hide","Lock"] };
haxor_graphics_CursorMode.Show = ["Show",0];
haxor_graphics_CursorMode.Show.toString = $estr;
haxor_graphics_CursorMode.Show.__enum__ = haxor_graphics_CursorMode;
haxor_graphics_CursorMode.Hide = ["Hide",1];
haxor_graphics_CursorMode.Hide.toString = $estr;
haxor_graphics_CursorMode.Hide.__enum__ = haxor_graphics_CursorMode;
haxor_graphics_CursorMode.Lock = ["Lock",2];
haxor_graphics_CursorMode.Lock.toString = $estr;
haxor_graphics_CursorMode.Lock.__enum__ = haxor_graphics_CursorMode;
var haxor_graphics_material_Material = function(p_name) {
	if(p_name == null) p_name = "";
	this.grab = false;
	haxor_core_Resource.call(this,p_name);
	this.__cid = haxor_context_EngineContext.material.mid.get_id();
	this.m_uniforms = [];
	this.queue = 1000;
	this.zfunc = 515;
	this.ztest = true;
	this.zwrite = true;
	this.blend = false;
	this.blendSrc = 1;
	this.blendDst = 0;
	this.invert = false;
	this.cull = 2;
	this.lighting = false;
	this.grab = false;
	haxor_context_EngineContext.material.InitializeMaterial(this);
};
$hxClasses["haxor.graphics.material.Material"] = haxor_graphics_material_Material;
haxor_graphics_material_Material.__name__ = ["haxor","graphics","material","Material"];
haxor_graphics_material_Material.Opaque = function(p_texture,p_ztest,p_zwrite) {
	if(p_zwrite == null) p_zwrite = true;
	if(p_ztest == null) p_ztest = true;
	var m = new haxor_graphics_material_Material("Opaque");
	m.set_shader(p_texture == null?haxor_graphics_material_Shader.m_flat_shader == null?haxor_graphics_material_Shader.m_flat_shader = new haxor_graphics_material_Shader(haxor_context_ShaderContext.flat_source):haxor_graphics_material_Shader.m_flat_shader:haxor_graphics_material_Shader.m_flat_texture_shader == null?haxor_graphics_material_Shader.m_flat_texture_shader = new haxor_graphics_material_Shader(haxor_context_ShaderContext.flat_texture_source):haxor_graphics_material_Shader.m_flat_texture_shader);
	m.queue = 1000;
	m.ztest = p_ztest;
	m.zwrite = p_zwrite;
	if(p_texture != null) m.SetTexture("DiffuseTexture",p_texture);
	return m;
};
haxor_graphics_material_Material.Transparent = function(p_texture,p_ztest,p_zwrite,p_double_sided) {
	if(p_double_sided == null) p_double_sided = false;
	if(p_zwrite == null) p_zwrite = true;
	if(p_ztest == null) p_ztest = true;
	var m = new haxor_graphics_material_Material("Transparent");
	if(p_double_sided) m.cull = 0;
	m.SetBlending(770,771);
	m.set_shader(p_texture == null?haxor_graphics_material_Shader.m_flat_shader == null?haxor_graphics_material_Shader.m_flat_shader = new haxor_graphics_material_Shader(haxor_context_ShaderContext.flat_source):haxor_graphics_material_Shader.m_flat_shader:haxor_graphics_material_Shader.m_flat_texture_shader == null?haxor_graphics_material_Shader.m_flat_texture_shader = new haxor_graphics_material_Shader(haxor_context_ShaderContext.flat_texture_source):haxor_graphics_material_Shader.m_flat_texture_shader);
	m.queue = 2000;
	m.ztest = p_ztest;
	m.zwrite = p_zwrite;
	m.blend = true;
	if(p_texture != null) m.SetTexture("DiffuseTexture",p_texture);
	return m;
};
haxor_graphics_material_Material.AdditiveAlpha = function(p_texture,p_ztest,p_zwrite,p_double_sided) {
	if(p_double_sided == null) p_double_sided = false;
	if(p_zwrite == null) p_zwrite = true;
	if(p_ztest == null) p_ztest = true;
	var m = haxor_graphics_material_Material.Transparent(null,p_ztest,p_zwrite,p_double_sided);
	m.set_name("AdditiveAlpha");
	m.SetBlending(770,1);
	return m;
};
haxor_graphics_material_Material.Additive = function(p_texture,p_ztest,p_zwrite,p_double_sided) {
	if(p_double_sided == null) p_double_sided = false;
	if(p_zwrite == null) p_zwrite = true;
	if(p_ztest == null) p_ztest = true;
	var m = haxor_graphics_material_Material.Transparent(null,p_ztest,p_zwrite,p_double_sided);
	m.set_name("Additive");
	m.SetBlending(1,1);
	return m;
};
haxor_graphics_material_Material.__super__ = haxor_core_Resource;
haxor_graphics_material_Material.prototype = $extend(haxor_core_Resource.prototype,{
	get_shader: function() {
		return this.m_shader;
	}
	,set_shader: function(v) {
		if(this.m_shader == v) return v;
		haxor_context_EngineContext.material.UpdateShader(this,this.m_shader,v);
		this.m_shader = v;
		return v;
	}
	,SetBlending: function(p_src,p_dst) {
		this.blendSrc = p_src;
		this.blendDst = p_dst;
	}
	,SetTexture: function(p_name,p_texture) {
		if(p_texture == null) {
			this.RemoveUniform(p_name);
			return;
		}
		var u = this.FetchUniform(p_name,false,1,1,true);
		if(u.exists) u.SetTexture(p_texture);
	}
	,SetMatrix4: function(p_name,p_matrix4,p_transpose) {
		if(p_transpose == null) p_transpose = false;
		if(p_matrix4 == null) {
			this.RemoveUniform(p_name);
			return;
		}
		var u = this.FetchUniform(p_name,true,16,16,true);
		if(u.exists) u.SetMatrix4(p_matrix4,p_transpose);
	}
	,SetVector2: function(p_name,p_v) {
		this.SetFloat2(p_name,p_v.x,p_v.y);
	}
	,SetVector3: function(p_name,p_v) {
		this.SetFloat3(p_name,p_v.x,p_v.y,p_v.z);
	}
	,SetVector4: function(p_name,p_v) {
		this.SetFloat4(p_name,p_v.x,p_v.y,p_v.z,p_v.w);
	}
	,SetColor: function(p_name,p_color) {
		this.SetFloat4(p_name,p_color.r,p_color.g,p_color.b,p_color.a);
	}
	,SetFloat: function(p_name,p_v) {
		var u = this.FetchUniform(p_name,true,1,1,true);
		if(u.exists) u.SetFloat(p_v);
	}
	,SetFloat2: function(p_name,p_x,p_y) {
		var u = this.FetchUniform(p_name,true,2,2,true);
		if(u.exists) u.SetFloat2(p_x,p_y);
	}
	,SetFloat3: function(p_name,p_x,p_y,p_z) {
		var u = this.FetchUniform(p_name,true,3,3,true);
		if(u.exists) u.SetFloat3(p_x,p_y,p_z);
	}
	,SetFloat4: function(p_name,p_x,p_y,p_z,p_w) {
		var u = this.FetchUniform(p_name,true,4,4,true);
		if(u.exists) u.SetFloat4(p_x,p_y,p_z,p_w);
	}
	,SetFloatArray: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,true,p_list.length,1,true);
		if(u.exists) u.SetFloatArray(p_list);
	}
	,SetFloat2Array: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,true,p_list.length,2,true);
		if(u.exists) u.SetFloat2Array(p_list);
	}
	,SetFloat3Array: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,true,p_list.length,3,true);
		if(u.exists) u.SetFloat3Array(p_list);
	}
	,SetFloat4Array: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,true,p_list.length,4,true);
		if(u.exists) u.SetFloat4Array(p_list);
	}
	,SetInt: function(p_name,p_v) {
		var u = this.FetchUniform(p_name,false,1,1,true);
		if(u.exists) u.SetInt(p_v);
	}
	,SetInt2: function(p_name,p_x,p_y) {
		var u = this.FetchUniform(p_name,false,2,2,true);
		if(u.exists) u.SetInt2(p_x,p_y);
	}
	,SetInt3: function(p_name,p_x,p_y,p_z) {
		var u = this.FetchUniform(p_name,false,3,3,true);
		if(u.exists) u.SetInt3(p_x,p_y,p_z);
	}
	,SetInt4: function(p_name,p_x,p_y,p_z,p_w) {
		var u = this.FetchUniform(p_name,false,4,4,true);
		if(u.exists) u.SetInt4(p_x,p_y,p_z,p_w);
	}
	,SetIntArray: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,false,p_list.length,1,true);
		if(u.exists) u.SetIntArray(p_list);
	}
	,SetInt2Array: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,false,p_list.length,2,true);
		if(u.exists) u.SetInt2Array(p_list);
	}
	,SetInt3Array: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,false,p_list.length,3,true);
		if(u.exists) u.SetInt3Array(p_list);
	}
	,SetInt4Array: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,false,p_list.length,4,true);
		if(u.exists) u.SetInt4Array(p_list);
	}
	,GetUniform: function(p_name) {
		var _g1 = 0;
		var _g = this.m_uniforms.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.m_uniforms[i].name == p_name) return this.m_uniforms[i];
		}
		return null;
	}
	,HasUniform: function(p_name,p_check_shader) {
		if(p_check_shader == null) p_check_shader = false;
		var _g1 = 0;
		var _g = this.m_uniforms.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.m_uniforms[i].name == p_name) {
				if(p_check_shader) return this.m_uniforms[i].exists;
				return true;
			}
		}
		return false;
	}
	,RemoveUniform: function(p_name) {
		var u = null;
		var _g1 = 0;
		var _g = this.m_uniforms.length;
		while(_g1 < _g) {
			var i = _g1++;
			u = this.m_uniforms[i];
			if(u.name == p_name) break;
		}
		if(u != null) {
			haxor_context_EngineContext.material.DestroyUniform(this,u);
			HxOverrides.remove(this.m_uniforms,u);
		}
	}
	,FetchUniform: function(p_name,p_is_float,p_length,p_offset,p_create) {
		var u = null;
		var _g1 = 0;
		var _g = this.m_uniforms.length;
		while(_g1 < _g) {
			var i = _g1++;
			u = this.m_uniforms[i];
			if(u.name == p_name) {
				if(u.isFloat == p_is_float) {
					if(u.offset == p_offset) {
						if(u.data.m_length == p_length) return u;
					}
				}
				haxor_context_EngineContext.material.DestroyUniform(this,u);
				HxOverrides.remove(this.m_uniforms,u);
				break;
			}
		}
		if(p_create) {
			u = new haxor_graphics_material_MaterialUniform(p_name,p_is_float,p_length,p_offset);
			haxor_context_EngineContext.material.CreateUniform(this,u);
			this.m_uniforms.push(u);
		}
		return u;
	}
	,OnDestroy: function() {
		haxor_context_EngineContext.material.DestroyMaterial(this);
	}
	,__class__: haxor_graphics_material_Material
	,__properties__: $extend(haxor_core_Resource.prototype.__properties__,{set_shader:"set_shader",get_shader:"get_shader"})
});
var haxor_graphics_material_MaterialUniform = function(p_name,p_is_float,p_length,p_offset) {
	this.__cid = haxor_context_EngineContext.material.uid.get_id();
	this.__d = true;
	this.name = p_name;
	this.isFloat = p_is_float;
	this.offset = p_offset;
	this.exists = false;
	if(p_is_float) this.data = new haxor_io_FloatArray(p_length); else this.data = new haxor_io_Int32Array(p_length);
};
$hxClasses["haxor.graphics.material.MaterialUniform"] = haxor_graphics_material_MaterialUniform;
haxor_graphics_material_MaterialUniform.__name__ = ["haxor","graphics","material","MaterialUniform"];
haxor_graphics_material_MaterialUniform.prototype = {
	SetFloat: function(p_v) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		b.Set(0,p_v);
	}
	,SetFloat2: function(p_x,p_y) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		b.Set(0,p_x);
		b.Set(1,p_y);
	}
	,SetFloat3: function(p_x,p_y,p_z) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		b.Set(0,p_x);
		b.Set(1,p_y);
		b.Set(2,p_z);
	}
	,SetFloat4: function(p_x,p_y,p_z,p_w) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		b.Set(0,p_x);
		b.Set(1,p_y);
		b.Set(2,p_z);
		b.Set(3,p_w);
	}
	,SetFloatArray: function(p_list) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetFloat2Array: function(p_list) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetFloat3Array: function(p_list) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetFloat4Array: function(p_list) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetInt: function(p_v) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		b.Set(0,p_v);
	}
	,SetInt2: function(p_x,p_y) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		b.Set(0,p_x);
		b.Set(1,p_y);
	}
	,SetInt3: function(p_x,p_y,p_z) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		b.Set(0,p_x);
		b.Set(1,p_y);
		b.Set(2,p_z);
	}
	,SetInt4: function(p_x,p_y,p_z,p_w) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		b.Set(0,p_x);
		b.Set(1,p_y);
		b.Set(2,p_z);
		b.Set(3,p_w);
	}
	,SetIntArray: function(p_list) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetInt2Array: function(p_list) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetInt3Array: function(p_list) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetInt4Array: function(p_list) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetTexture: function(p_texture) {
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		b.Set(0,p_texture.__slot);
		this.texture = p_texture;
	}
	,SetMatrix4: function(m,t) {
		if(t == null) t = false;
		if(!this.exists) return;
		this.__d = true;
		var b = this.data;
		if(!t) {
			b.Set(0,m.m00);
			b.Set(1,m.m01);
			b.Set(2,m.m02);
			b.Set(3,m.m03);
			b.Set(4,m.m10);
			b.Set(5,m.m11);
			b.Set(6,m.m12);
			b.Set(7,m.m13);
			b.Set(8,m.m20);
			b.Set(9,m.m21);
			b.Set(10,m.m22);
			b.Set(11,m.m23);
			b.Set(12,m.m30);
			b.Set(13,m.m31);
			b.Set(14,m.m32);
			b.Set(15,m.m33);
		} else {
			b.Set(0,m.m00);
			b.Set(1,m.m10);
			b.Set(2,m.m20);
			b.Set(3,m.m30);
			b.Set(4,m.m01);
			b.Set(5,m.m11);
			b.Set(6,m.m21);
			b.Set(7,m.m31);
			b.Set(8,m.m02);
			b.Set(9,m.m12);
			b.Set(10,m.m22);
			b.Set(11,m.m32);
			b.Set(12,m.m03);
			b.Set(13,m.m13);
			b.Set(14,m.m23);
			b.Set(15,m.m33);
		}
	}
	,SetVector2: function(p_v) {
		this.SetFloat2(p_v.x,p_v.y);
	}
	,SetVector3: function(p_v) {
		this.SetFloat3(p_v.x,p_v.y,p_v.z);
	}
	,SetVector4: function(p_v) {
		this.SetFloat4(p_v.x,p_v.y,p_v.z,p_v.w);
	}
	,SetColor: function(p_color) {
		this.SetFloat4(p_color.r,p_color.g,p_color.b,p_color.a);
	}
	,__class__: haxor_graphics_material_MaterialUniform
};
var haxor_graphics_material_Shader = function(p_source) {
	haxor_core_Resource.call(this);
	this.__cid = haxor_context_EngineContext.material.sid.get_id();
	var vt0 = p_source.indexOf("<vertex");
	var vt1 = p_source.indexOf(">",vt0 + 1);
	var vt = p_source.substring(vt0,vt1 + 1);
	var ft0 = p_source.indexOf("<fragment");
	var ft1 = p_source.indexOf(">",ft0 + 1);
	var ft = p_source.substring(ft0,ft1 + 1);
	p_source = StringTools.replace(p_source,vt,vt + "<![CDATA[");
	p_source = StringTools.replace(p_source,"</vertex>","]]></vertex>");
	p_source = StringTools.replace(p_source,ft,ft + "<![CDATA[");
	p_source = StringTools.replace(p_source,"</fragment>","]]></fragment>");
	var x;
	x = Xml.parse(p_source);
	x = x.firstElement();
	this.set_name(x.get("id"));
	if(this.get_name() == null || this.get_name() == "") this.set_name("Shader" + this.__cid);
	var vs = x.elementsNamed("vertex").next();
	var fs = x.elementsNamed("fragment").next();
	this.m_vss = this.GetShaderSource(vs);
	this.m_fss = this.GetShaderSource(fs);
	this.m_hasError = false;
	haxor_context_EngineContext.material.InitializeShader(this);
};
$hxClasses["haxor.graphics.material.Shader"] = haxor_graphics_material_Shader;
haxor_graphics_material_Shader.__name__ = ["haxor","graphics","material","Shader"];
haxor_graphics_material_Shader.__properties__ = {get_FlatTextureSkin:"get_FlatTextureSkin",get_FlatTexture:"get_FlatTexture",get_Flat:"get_Flat"}
haxor_graphics_material_Shader.get_Flat = function() {
	if(haxor_graphics_material_Shader.m_flat_shader == null) return haxor_graphics_material_Shader.m_flat_shader = new haxor_graphics_material_Shader(haxor_context_ShaderContext.flat_source); else return haxor_graphics_material_Shader.m_flat_shader;
};
haxor_graphics_material_Shader.get_FlatTexture = function() {
	if(haxor_graphics_material_Shader.m_flat_texture_shader == null) return haxor_graphics_material_Shader.m_flat_texture_shader = new haxor_graphics_material_Shader(haxor_context_ShaderContext.flat_texture_source); else return haxor_graphics_material_Shader.m_flat_texture_shader;
};
haxor_graphics_material_Shader.get_FlatTextureSkin = function() {
	if(haxor_graphics_material_Shader.m_flat_texture_skin_shader == null) return haxor_graphics_material_Shader.m_flat_texture_skin_shader = new haxor_graphics_material_Shader(haxor_context_ShaderContext.flat_texture_skin_source); else return haxor_graphics_material_Shader.m_flat_texture_skin_shader;
};
haxor_graphics_material_Shader.__super__ = haxor_core_Resource;
haxor_graphics_material_Shader.prototype = $extend(haxor_core_Resource.prototype,{
	get_hasError: function() {
		return this.m_hasError;
	}
	,GetShaderSource: function(n) {
		if(n == null) return "";
		var src = n.firstChild().get_nodeValue().toString();
		var prec = (n.get("precision") == null?"low":n.get("precision")).toLowerCase();
		switch(prec) {
		case "low":
			prec = "precision lowp float;";
			break;
		case "medium":
			prec = "precision mediump float;";
			break;
		case "high":
			prec = "precision highp float;";
			break;
		}
		return prec + src;
	}
	,OnDestroy: function() {
		haxor_context_EngineContext.material.DestroyShader(this);
	}
	,__class__: haxor_graphics_material_Shader
	,__properties__: $extend(haxor_core_Resource.prototype.__properties__,{get_hasError:"get_hasError"})
});
var haxor_graphics_material_UberShader = function(p_source) {
	haxor_graphics_material_Shader.call(this,p_source);
};
$hxClasses["haxor.graphics.material.UberShader"] = haxor_graphics_material_UberShader;
haxor_graphics_material_UberShader.__name__ = ["haxor","graphics","material","UberShader"];
haxor_graphics_material_UberShader.__super__ = haxor_graphics_material_Shader;
haxor_graphics_material_UberShader.prototype = $extend(haxor_graphics_material_Shader.prototype,{
	__class__: haxor_graphics_material_UberShader
});
var haxor_graphics_mesh_Mesh = function(p_name) {
	if(p_name == null) p_name = "";
	haxor_core_Resource.call(this,p_name);
	this.__cid = haxor_context_EngineContext.mesh.mid.get_id();
	this.m_attribs = [];
	this.m_indexed = false;
	this.m_vcount = 0;
	this.m_bounds = haxor_math_AABB3.get_empty();
	this.m_mode = 35044;
	this.primitive = 4;
	this.m_topology_attrib = new haxor_graphics_mesh_MeshAttrib();
	this.m_topology_attrib.m_name = "$topology";
	this.m_topology_attrib.offset = 1;
};
$hxClasses["haxor.graphics.mesh.Mesh"] = haxor_graphics_mesh_Mesh;
haxor_graphics_mesh_Mesh.__name__ = ["haxor","graphics","mesh","Mesh"];
haxor_graphics_mesh_Mesh.__super__ = haxor_core_Resource;
haxor_graphics_mesh_Mesh.prototype = $extend(haxor_core_Resource.prototype,{
	get_topology: function() {
		if(this.m_topology_attrib.data == null) return new haxor_io_UInt16Array(0);
		return this.m_topology_attrib.data;
	}
	,set_topology: function(v) {
		if(v == null) {
			this.m_topology_attrib.data = null;
			this.m_indexed = false;
			haxor_context_EngineContext.mesh.RemoveAttrib(this.m_topology_attrib);
		} else {
			this.m_topology_attrib.data = v;
			this.m_indexed = true;
			haxor_context_EngineContext.mesh.UpdateAttrib(this.m_topology_attrib,this.m_mode,true);
		}
		return v;
	}
	,get_indexed: function() {
		return this.m_indexed;
	}
	,get_mode: function() {
		return this.m_mode;
	}
	,set_mode: function(v) {
		if(this.m_mode == v) return v;
		this.m_mode = v;
		if(this.m_indexed) haxor_context_EngineContext.mesh.UpdateAttrib(this.m_topology_attrib,this.m_mode,true);
		var _g1 = 0;
		var _g = this.m_attribs.length;
		while(_g1 < _g) {
			var i = _g1++;
			haxor_context_EngineContext.mesh.UpdateAttrib(this.m_attribs[i],this.m_mode,false);
		}
		return v;
	}
	,get_attribs: function() {
		var l = [];
		var _g1 = 0;
		var _g = this.m_attribs.length;
		while(_g1 < _g) {
			var i = _g1++;
			l.push(this.m_attribs[i].m_name);
		}
		return l;
	}
	,get_vcount: function() {
		return this.m_vcount;
	}
	,get_bounds: function() {
		return this.m_bounds;
	}
	,set_bounds: function(v) {
		return this.m_bounds.SetAABB3(v);
	}
	,Clear: function(p_from_gpu) {
		if(p_from_gpu == null) p_from_gpu = true;
		var _g1 = 0;
		var _g = this.m_attribs.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_attribs[i].data = null;
			this.m_attribs[i].m_name = "";
			if(p_from_gpu) haxor_context_EngineContext.mesh.RemoveAttrib(this.m_attribs[i]);
		}
		this.m_vcount = 0;
		if(p_from_gpu) this.set_topology(null); else this.m_topology_attrib.data = null;
	}
	,Exists: function(p_name) {
		return this.GetAttribute(p_name) != null;
	}
	,Get: function(p_name) {
		var a = this.GetAttribute(p_name);
		if(a == null) return null; else return a.data;
	}
	,GetAttribute: function(p_name) {
		var _g1 = 0;
		var _g = this.m_attribs.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.m_attribs[i].m_name == p_name) return this.m_attribs[i];
		}
		return null;
	}
	,Remove: function(p_name) {
		var a = this.GetAttribute(p_name);
		if(a == null) return;
		HxOverrides.remove(this.m_attribs,a);
		haxor_context_EngineContext.mesh.RemoveAttrib(a);
	}
	,Set: function(p_name,p_data,p_offset) {
		if(p_offset == null) p_offset = 0;
		if(p_data == null) {
			haxor_core_Console.Log("Mesh> [" + this.get_name() + "] tried to set null array.",1);
			return null;
		}
		var a = this.GetAttribute(p_name);
		if(a == null) {
			a = new haxor_graphics_mesh_MeshAttrib();
			a.m_name = p_name;
			this.m_attribs.push(a);
		}
		if(p_offset > 0) a.offset = p_offset;
		a.data = p_data;
		this.m_vcount = this.m_attribs[0].get_count();
		var _g1 = 1;
		var _g = this.m_attribs.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = this.m_attribs[i].get_count();
			if(this.m_vcount < c) this.m_vcount = this.m_vcount; else this.m_vcount = c;
		}
		haxor_context_EngineContext.mesh.UpdateAttrib(a,this.m_mode,false);
		return a;
	}
	,GenerateAttribBounds: function(p_attrib,p_result) {
		var b;
		if(p_result == null) b = haxor_math_AABB3.get_empty(); else b = p_result;
		var a = this.GetAttribute(p_attrib);
		if(a == null) return b.Set(0,0,0,0,0,0);
		var step = a.offset;
		if(step <= 0) return b.Set(0,0,0,0,0,0);
		var i = step;
		var f = a.data;
		var vx;
		if(step > 0) vx = f.Get(0); else vx = 0;
		var vy;
		if(step > 1) vy = f.Get(1); else vy = 0;
		var vz;
		if(step > 2) vz = f.Get(2); else vz = 0;
		b.Set(vx,vx,vy,vy,vz,vz);
		while(i < f.m_length) {
			if(step > 0) vx = f.Get(i); else vx = 0;
			if(step > 1) vy = f.Get(i + 1); else vy = 0;
			if(step > 2) vz = f.Get(i + 2); else vz = 0;
			b.Encapsulate3(vx,vy,vz);
			i += step;
		}
		return b;
	}
	,OnDestroy: function() {
		this.Clear();
		haxor_context_EngineContext.mesh.mid.set_id(this.__cid);
	}
	,__class__: haxor_graphics_mesh_Mesh
	,__properties__: $extend(haxor_core_Resource.prototype.__properties__,{set_bounds:"set_bounds",get_bounds:"get_bounds",get_vcount:"get_vcount",get_attribs:"get_attribs",set_mode:"set_mode",get_mode:"get_mode",get_indexed:"get_indexed",set_topology:"set_topology",get_topology:"get_topology"})
});
var haxor_graphics_mesh_MeshAttrib = function() {
	this.__cid = haxor_context_EngineContext.mesh.aid.get_id();
	this._loc_ = -1;
	this.m_name = "";
	this.data = null;
	this.offset = 0;
};
$hxClasses["haxor.graphics.mesh.MeshAttrib"] = haxor_graphics_mesh_MeshAttrib;
haxor_graphics_mesh_MeshAttrib.__name__ = ["haxor","graphics","mesh","MeshAttrib"];
haxor_graphics_mesh_MeshAttrib.prototype = {
	get_name: function() {
		return this.m_name;
	}
	,get_count: function() {
		if(this.data == null) return 0; else return this.data.m_length / this.offset | 0;
	}
	,__class__: haxor_graphics_mesh_MeshAttrib
	,__properties__: {get_count:"get_count",get_name:"get_name"}
};
var haxor_graphics_mesh_MeshLayout = function(p_name) {
	if(p_name == null) p_name = "";
	haxor_graphics_mesh_Mesh.call(this,p_name);
	this.m_vertex = [];
	this.m_normal = [];
	this.m_color = [];
	this.m_uv0 = [];
	this.m_uv1 = [];
	this.m_tangent = [];
	this.m_binormal = [];
};
$hxClasses["haxor.graphics.mesh.MeshLayout"] = haxor_graphics_mesh_MeshLayout;
haxor_graphics_mesh_MeshLayout.__name__ = ["haxor","graphics","mesh","MeshLayout"];
haxor_graphics_mesh_MeshLayout.__super__ = haxor_graphics_mesh_Mesh;
haxor_graphics_mesh_MeshLayout.prototype = $extend(haxor_graphics_mesh_Mesh.prototype,{
	get_vertex: function() {
		return this.m_vertex;
	}
	,set_vertex: function(v) {
		return this.m_vertex = this.UpdateAttribute("vertex",v,false);
	}
	,get_normal: function() {
		return this.m_normal;
	}
	,set_normal: function(v) {
		return this.m_normal = this.UpdateAttribute("normal",v,false);
	}
	,get_color: function() {
		return this.m_color;
	}
	,set_color: function(v) {
		return this.m_color = this.UpdateAttribute("color",v,true);
	}
	,get_uv0: function() {
		return this.m_uv0;
	}
	,set_uv0: function(v) {
		return this.m_uv0 = this.UpdateAttribute("uv0",v,false);
	}
	,get_uv1: function() {
		return this.m_uv1;
	}
	,set_uv1: function(v) {
		return this.m_uv1 = this.UpdateAttribute("uv1",v,false);
	}
	,get_tangent: function() {
		return this.m_tangent;
	}
	,set_tangent: function(v) {
		return this.m_tangent = this.UpdateAttribute("tangent",v,false);
	}
	,get_binormal: function() {
		return this.m_binormal;
	}
	,set_binormal: function(v) {
		return this.m_binormal = this.UpdateAttribute("binormal",v,false);
	}
	,GenerateBounds: function() {
		this.GenerateAttribBounds("vertex",this.m_bounds);
	}
	,UpdateAttribute: function(p_name,p_list,p_is_color) {
		if(p_is_color == null) p_is_color = false;
		if(p_list == null) {
			this.Remove(p_name);
			return [];
		}
		if(p_list.length <= 0) {
			this.Remove(p_name);
			return [];
		}
		var a = this.GetAttribute(p_name);
		var off = 1;
		if(js_Boot.__instanceof(p_list[0],haxor_math_Vector2)) off = 2;
		if(js_Boot.__instanceof(p_list[0],haxor_math_Vector3)) off = 3;
		if(js_Boot.__instanceof(p_list[0],haxor_math_Vector4)) off = 4;
		if(js_Boot.__instanceof(p_list[0],haxor_math_Color)) off = 4;
		if(a == null) a = this.Set(p_name,new haxor_io_FloatArray(1),off);
		var p = 0;
		var f = a.data = new haxor_io_FloatArray(p_list.length * off);
		console.log(this.get_name() + " a[" + p_name + "] off[" + off + "] len[" + f.m_length + "]");
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			var it = p_list[i];
			switch(off) {
			case 1:
				var v = it;
				f.Set(p++,v);
				break;
			case 2:
				var v2 = it;
				f.Set(p++,v2.x);
				f.Set(p++,v2.y);
				break;
			case 3:
				var v3 = it;
				f.Set(p++,v3.x);
				f.Set(p++,v3.y);
				f.Set(p++,v3.z);
				break;
			case 4:
				if(p_is_color) {
					var c = it;
					f.Set(p++,c.r);
					f.Set(p++,c.g);
					f.Set(p++,c.b);
					f.Set(p++,c.a);
				} else {
					var v4 = it;
					f.Set(p++,v4.x);
					f.Set(p++,v4.y);
					f.Set(p++,v4.z);
					f.Set(p++,v4.w);
				}
				break;
			}
		}
		this.Set(p_name,f,off);
		return p_list;
	}
	,__class__: haxor_graphics_mesh_MeshLayout
	,__properties__: $extend(haxor_graphics_mesh_Mesh.prototype.__properties__,{set_binormal:"set_binormal",get_binormal:"get_binormal",set_tangent:"set_tangent",get_tangent:"get_tangent",set_uv1:"set_uv1",get_uv1:"get_uv1",set_uv0:"set_uv0",get_uv0:"get_uv0",set_color:"set_color",get_color:"get_color",set_normal:"set_normal",get_normal:"get_normal",set_vertex:"set_vertex",get_vertex:"get_vertex"})
});
var haxor_graphics_mesh_Mesh3 = function(p_name) {
	haxor_graphics_mesh_MeshLayout.call(this,p_name);
};
$hxClasses["haxor.graphics.mesh.Mesh3"] = haxor_graphics_mesh_Mesh3;
haxor_graphics_mesh_Mesh3.__name__ = ["haxor","graphics","mesh","Mesh3"];
haxor_graphics_mesh_Mesh3.__super__ = haxor_graphics_mesh_MeshLayout;
haxor_graphics_mesh_Mesh3.prototype = $extend(haxor_graphics_mesh_MeshLayout.prototype,{
	__class__: haxor_graphics_mesh_Mesh3
});
var haxor_graphics_mesh_SkinnedMesh3 = function(p_name) {
	haxor_graphics_mesh_Mesh3.call(this,p_name);
};
$hxClasses["haxor.graphics.mesh.SkinnedMesh3"] = haxor_graphics_mesh_SkinnedMesh3;
haxor_graphics_mesh_SkinnedMesh3.__name__ = ["haxor","graphics","mesh","SkinnedMesh3"];
haxor_graphics_mesh_SkinnedMesh3.__super__ = haxor_graphics_mesh_Mesh3;
haxor_graphics_mesh_SkinnedMesh3.prototype = $extend(haxor_graphics_mesh_Mesh3.prototype,{
	get_binds: function() {
		return this.m_binds;
	}
	,set_binds: function(v) {
		this.m_binds = v.slice();
		return v;
	}
	,get_bone: function() {
		return this.m_bone;
	}
	,set_bone: function(v) {
		return this.m_bone = this.UpdateAttribute("bone",v,false);
	}
	,get_weight: function() {
		return this.m_weight;
	}
	,set_weight: function(v) {
		return this.m_weight = this.UpdateAttribute("weight",v,false);
	}
	,__class__: haxor_graphics_mesh_SkinnedMesh3
	,__properties__: $extend(haxor_graphics_mesh_Mesh3.prototype.__properties__,{set_weight:"set_weight",get_weight:"get_weight",set_bone:"set_bone",get_bone:"get_bone",set_binds:"set_binds",get_binds:"get_binds"})
});
var haxor_graphics_mesh_Mesh2D = function(p_name) {
	haxor_graphics_mesh_MeshLayout.call(this,p_name);
};
$hxClasses["haxor.graphics.mesh.Mesh2D"] = haxor_graphics_mesh_Mesh2D;
haxor_graphics_mesh_Mesh2D.__name__ = ["haxor","graphics","mesh","Mesh2D"];
haxor_graphics_mesh_Mesh2D.__super__ = haxor_graphics_mesh_MeshLayout;
haxor_graphics_mesh_Mesh2D.prototype = $extend(haxor_graphics_mesh_MeshLayout.prototype,{
	__class__: haxor_graphics_mesh_Mesh2D
});
var haxor_graphics_mesh_Mesh23 = function(p_name) {
	haxor_graphics_mesh_MeshLayout.call(this,p_name);
};
$hxClasses["haxor.graphics.mesh.Mesh23"] = haxor_graphics_mesh_Mesh23;
haxor_graphics_mesh_Mesh23.__name__ = ["haxor","graphics","mesh","Mesh23"];
haxor_graphics_mesh_Mesh23.__super__ = haxor_graphics_mesh_MeshLayout;
haxor_graphics_mesh_Mesh23.prototype = $extend(haxor_graphics_mesh_MeshLayout.prototype,{
	__class__: haxor_graphics_mesh_Mesh23
});
var haxor_graphics_mesh_Mesh2 = function(p_name) {
	haxor_graphics_mesh_MeshLayout.call(this,p_name);
};
$hxClasses["haxor.graphics.mesh.Mesh2"] = haxor_graphics_mesh_Mesh2;
haxor_graphics_mesh_Mesh2.__name__ = ["haxor","graphics","mesh","Mesh2"];
haxor_graphics_mesh_Mesh2.__super__ = haxor_graphics_mesh_MeshLayout;
haxor_graphics_mesh_Mesh2.prototype = $extend(haxor_graphics_mesh_MeshLayout.prototype,{
	__class__: haxor_graphics_mesh_Mesh2
});
var haxor_graphics_mesh_Mesh4 = function(p_name) {
	haxor_graphics_mesh_MeshLayout.call(this,p_name);
};
$hxClasses["haxor.graphics.mesh.Mesh4"] = haxor_graphics_mesh_Mesh4;
haxor_graphics_mesh_Mesh4.__name__ = ["haxor","graphics","mesh","Mesh4"];
haxor_graphics_mesh_Mesh4.__super__ = haxor_graphics_mesh_MeshLayout;
haxor_graphics_mesh_Mesh4.prototype = $extend(haxor_graphics_mesh_MeshLayout.prototype,{
	__class__: haxor_graphics_mesh_Mesh4
});
var haxor_graphics_mesh_Model = function() { };
$hxClasses["haxor.graphics.mesh.Model"] = haxor_graphics_mesh_Model;
haxor_graphics_mesh_Model.__name__ = ["haxor","graphics","mesh","Model"];
haxor_graphics_mesh_Model.__properties__ = {get_sphere:"get_sphere",get_tetrahedron:"get_tetrahedron",get_cube:"get_cube",get_planeYZ:"get_planeYZ",get_planeXZ:"get_planeXZ",get_planeXY:"get_planeXY",get_screen:"get_screen"}
haxor_graphics_mesh_Model.get_screen = function() {
	if(haxor_graphics_mesh_Model.m_screen != null) return haxor_graphics_mesh_Model.m_screen;
	var m = new haxor_graphics_mesh_Mesh("$ModelScreen");
	var s = 1.0;
	var v = haxor_io_FloatArray.Alloc([-s,-s,0.5,s,-s,0.5,s,s,0.5,-s,s,0.5]);
	var uv = haxor_io_FloatArray.Alloc([0.0,0.0,0.0,1.0,0.0,0.0,1.0,1.0,0.0,0.0,1.0,0.0]);
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.set_bounds(m.GenerateAttribBounds("vertex",haxor_context_EngineContext.data.get_aabb3()));
	m.set_topology(haxor_io_UInt16Array.Alloc([0,1,2,0,2,3]));
	return haxor_graphics_mesh_Model.m_screen = m;
};
haxor_graphics_mesh_Model.get_planeXY = function() {
	if(haxor_graphics_mesh_Model.m_planeXY != null) return haxor_graphics_mesh_Model.m_planeXY;
	var m = new haxor_graphics_mesh_Mesh("$ModelPlaneXY");
	var s = 0.5;
	var v = haxor_io_FloatArray.Alloc([-s,-s,0.0,s,-s,0.0,s,s,0.0,-s,s,0.0]);
	var uv = haxor_io_FloatArray.Alloc([0.0,0.0,0.0,1.0,0.0,0.0,1.0,1.0,0.0,0.0,1.0,0.0]);
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.set_bounds(m.GenerateAttribBounds("vertex",haxor_context_EngineContext.data.get_aabb3()));
	m.set_topology(haxor_io_UInt16Array.Alloc([0,1,2,0,2,3]));
	return haxor_graphics_mesh_Model.m_planeXY = m;
};
haxor_graphics_mesh_Model.get_planeXZ = function() {
	if(haxor_graphics_mesh_Model.m_planeXZ != null) return haxor_graphics_mesh_Model.m_planeXZ;
	var m = new haxor_graphics_mesh_Mesh("$ModelPlaneXZ");
	var s = 0.5;
	var v = haxor_io_FloatArray.Alloc([-s,0.0,-s,s,0.0,-s,s,0.0,s,-s,0.0,s]);
	var uv = haxor_io_FloatArray.Alloc([0.0,0.0,0.0,1.0,0.0,0.0,1.0,1.0,0.0,0.0,1.0,0.0]);
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.set_bounds(m.GenerateAttribBounds("vertex",haxor_context_EngineContext.data.get_aabb3()));
	m.set_topology(haxor_io_UInt16Array.Alloc([0,1,2,0,2,3]));
	return haxor_graphics_mesh_Model.m_planeXZ = m;
};
haxor_graphics_mesh_Model.get_planeYZ = function() {
	if(haxor_graphics_mesh_Model.m_planeYZ != null) return haxor_graphics_mesh_Model.m_planeYZ;
	var m = new haxor_graphics_mesh_Mesh("$ModelPlaneYZ");
	var s = 0.5;
	var v = haxor_io_FloatArray.Alloc([0.0,-s,-s,0.0,s,-s,0.0,s,s,0.0,-s,s]);
	var uv = haxor_io_FloatArray.Alloc([0.0,0.0,0.0,1.0,0.0,0.0,1.0,1.0,0.0,0.0,1.0,0.0]);
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.set_bounds(m.GenerateAttribBounds("vertex",haxor_context_EngineContext.data.get_aabb3()));
	m.set_topology(haxor_io_UInt16Array.Alloc([0,1,2,0,2,3]));
	return haxor_graphics_mesh_Model.m_planeYZ = m;
};
haxor_graphics_mesh_Model.get_cube = function() {
	if(haxor_graphics_mesh_Model.m_cube != null) return haxor_graphics_mesh_Model.m_cube;
	var m = new haxor_graphics_mesh_Mesh("$ModelCube");
	var v = haxor_io_FloatArray.FromBase64("AAAAvwAAAL8AAAC/AAAAvwAAAD8AAAC/AAAAPwAAAD8AAAC/AAAAPwAAAD8AAAC/AAAAPwAAAL8AAAC/AAAAvwAAAL8AAAC/AAAAvwAAAL8AAAA/AAAAPwAAAL8AAAA/AAAAPwAAAD8AAAA/AAAAPwAAAD8AAAA/AAAAvwAAAD8AAAA/AAAAvwAAAL8AAAA/AAAAvwAAAL8AAAC/AAAAPwAAAL8AAAC/AAAAPwAAAL8AAAA/AAAAPwAAAL8AAAA/AAAAvwAAAL8AAAA/AAAAvwAAAL8AAAC/AAAAPwAAAL8AAAC/AAAAPwAAAD8AAAC/AAAAPwAAAD8AAAA/AAAAPwAAAD8AAAA/AAAAPwAAAL8AAAA/AAAAPwAAAL8AAAC/AAAAPwAAAD8AAAC/AAAAvwAAAD8AAAC/AAAAvwAAAD8AAAA/AAAAvwAAAD8AAAA/AAAAPwAAAD8AAAA/AAAAPwAAAD8AAAC/AAAAvwAAAD8AAAC/AAAAvwAAAL8AAAC/AAAAvwAAAL8AAAA/AAAAvwAAAL8AAAA/AAAAvwAAAD8AAAA/AAAAvwAAAD8AAAC/");
	var uv = haxor_io_FloatArray.FromBase64("AACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAA");
	var n = haxor_io_FloatArray.FromBase64("AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAA");
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.Set("normal",n,3);
	m.set_bounds(m.GenerateAttribBounds("vertex",haxor_context_EngineContext.data.get_aabb3()));
	return haxor_graphics_mesh_Model.m_cube = m;
};
haxor_graphics_mesh_Model.get_tetrahedron = function() {
	if(haxor_graphics_mesh_Model.m_tetrahedron != null) return haxor_graphics_mesh_Model.m_tetrahedron;
	var m = new haxor_graphics_mesh_Mesh("$ModelTetrahedron");
	var v = haxor_io_FloatArray.FromBase64("AAAAAAAAAAAAAAAAsb+cvpm/Bz8AAAAAsb8cPwAAAAAAAAAAAAAAAAAAAAAAAAAArr+cvpu/B78AAAAAsb+cvpm/Bz8AAAAAAAAAAAAAAAAAAAAAsb8cPwAAAAAAAAAArr+cvpu/B78AAAAAsb8cPwAAAAAAAAAAAAAAAAAAAACX/1A/AAAAAAAAAACX/1A/sb8cPwAAAAAAAAAAsb+cvpm/Bz8AAAAAAAAAAAAAAACX/1A/sb+cvpm/Bz8AAAAAAAAAAAAAAACX/1A/AAAAAAAAAACX/1A/sb+cvpm/Bz8AAAAArr+cvpu/B78AAAAAAAAAAAAAAACX/1A/rr+cvpu/B78AAAAAAAAAAAAAAACX/1A/AAAAAAAAAACX/1A/rr+cvpu/B78AAAAAsb8cPwAAAAAAAAAAAAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/");
	var uv = haxor_io_FloatArray.FromBase64("AAAAPwAAAAAAAAAAraqqPQAAAAAAAIA/AACAvgAAAAAAAIA/AAAAPwAAAAAAAAAAVlXVPgAAAAD+/38/raqqPQAAAAAAAIA/AAAAPwAAAAAAAAAAAABAPwAAAAAAAIA/VlXVPgAAAAD+/38/AABAPwAAAAAAAIA/AAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAACAvgAAAAAAAIA/raqqPQAAAAAAAIA/AAAAPwAAgD8AAAAAraqqPQAAAAAAAIA/AAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAraqqPQAAAAAAAIA/VlXVPgAAAAD+/38/AAAAPwAAgD8AAAAAVlXVPgAAAAD+/38/AAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAVlXVPgAAAAD+/38/AABAPwAAAAAAAIA/AAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAA");
	var n = haxor_io_FloatArray.FromBase64("AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAQrPvPiWWTz9yxrM+QrPvPiWWTz9yxrM+QrPvPiWWTz9yxrM+AACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAARbNvv4aDqbNyxrM+RbNvv4aDqbN2xrM+RLNvv4aDqbNyxrM+AACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAARbPvPiWWT792xrM+SbPvPiWWT792xrM+RbPvPiWWT792xrM+AACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAA");
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.Set("normal",n,3);
	m.set_bounds(m.GenerateAttribBounds("vertex",haxor_context_EngineContext.data.get_aabb3()));
	return haxor_graphics_mesh_Model.m_tetrahedron = m;
};
haxor_graphics_mesh_Model.get_sphere = function() {
	if(haxor_graphics_mesh_Model.m_sphere != null) return haxor_graphics_mesh_Model.m_sphere;
	var m = new haxor_graphics_mesh_Mesh("$ModelSphere");
	var v = haxor_io_FloatArray.FromBase64("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");
	var uv = haxor_io_FloatArray.FromBase64("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");
	var n = haxor_io_FloatArray.FromBase64("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");
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.Set("normal",n,3);
	m.set_bounds(m.GenerateAttribBounds("vertex",haxor_context_EngineContext.data.get_aabb3()));
	return haxor_graphics_mesh_Model.m_sphere = m;
};
var haxor_graphics_texture_Bitmap = function(p_width,p_height,p_format) {
	haxor_core_Resource.call(this);
	this.m_width = p_width;
	this.m_height = p_height;
	this.m_format = p_format;
	this.m_float = false;
	this.m_channels = 1;
	switch(p_format[1]) {
	case 1:
		this.m_channels = 1;
		break;
	case 0:
		this.m_channels = 1;
		break;
	case 2:
		this.m_channels = 3;
		break;
	case 3:
		this.m_channels = 4;
		break;
	case 10:
		this.m_channels = 1;
		this.m_float = true;
		break;
	case 7:
		this.m_channels = 1;
		this.m_float = true;
		break;
	case 4:
		this.m_channels = 1;
		this.m_float = true;
		break;
	case 8:
		this.m_channels = 3;
		this.m_float = true;
		break;
	case 5:
		this.m_channels = 3;
		this.m_float = true;
		break;
	case 9:
		this.m_channels = 4;
		this.m_float = true;
		break;
	case 6:
		this.m_channels = 4;
		this.m_float = true;
		break;
	}
	var len = this.m_width * this.m_height * this.m_channels;
	if(this.m_float) this.m_buffer = new haxor_io_FloatArray(len); else this.m_buffer = new haxor_io_Buffer(len);
};
$hxClasses["haxor.graphics.texture.Bitmap"] = haxor_graphics_texture_Bitmap;
haxor_graphics_texture_Bitmap.__name__ = ["haxor","graphics","texture","Bitmap"];
haxor_graphics_texture_Bitmap.__super__ = haxor_core_Resource;
haxor_graphics_texture_Bitmap.prototype = $extend(haxor_core_Resource.prototype,{
	get_buffer: function() {
		return this.m_buffer;
	}
	,get_float: function() {
		return this.m_float;
	}
	,get_width: function() {
		return this.m_width;
	}
	,get_height: function() {
		return this.m_height;
	}
	,get_channels: function() {
		return this.m_channels;
	}
	,get_format: function() {
		return this.m_format;
	}
	,GetPixel: function(p_x,p_y) {
		if(p_x < 0) return new haxor_math_Color();
		if(p_y < 0) return new haxor_math_Color();
		if(p_x >= this.m_width) return new haxor_math_Color();
		if(p_y >= this.m_height) return new haxor_math_Color();
		p_y = this.m_height - 1 - p_y;
		var cc = this.m_channels;
		var pos = (p_x + p_y * this.m_width) * cc;
		if(this.m_float) {
			var c = new haxor_math_Color();
			var b = this.m_buffer;
			switch(cc) {
			case 1:
				c.r = b.Get(pos);
				c.g = c.r;
				c.b = c.r;
				c.a = 1.0;
				break;
			case 2:
				c.r = b.Get(pos);
				c.g = b.Get(pos + 1);
				c.b = c.r;
				c.a = 1.0;
				break;
			case 3:
				c.r = b.Get(pos);
				c.g = b.Get(pos + 1);
				c.b = b.Get(pos + 2);
				c.a = 1.0;
				break;
			case 4:
				c.r = b.Get(pos);
				c.g = b.Get(pos + 1);
				c.b = b.Get(pos + 2);
				c.a = b.Get(pos + 3);
				break;
			}
			return c;
		}
		var b1 = this.m_buffer;
		var rb = b1.GetByte(pos);
		var gb;
		if(cc >= 2) gb = b1.GetByte(pos + 1); else gb = rb;
		var bb;
		if(cc >= 3) bb = b1.GetByte(pos + 2); else bb = rb;
		var ab;
		if(cc >= 4) ab = b1.GetByte(pos + 3); else ab = rb;
		return haxor_math_Color.FromBytes(rb,gb,bb,ab);
	}
	,SetPixel: function(p_x,p_y,p_color) {
		if(p_x < 0) return;
		if(p_y < 0) return;
		if(p_x >= this.m_width) return;
		if(p_y >= this.m_height) return;
		p_y = this.m_height - 1 - p_y;
		var cc = this.m_channels;
		var pos = (p_x + p_y * this.m_width) * cc;
		if(this.m_float) {
			var b = this.m_buffer;
			b.Set(pos,p_color.r);
			if(cc >= 2) b.Set(pos + 1,p_color.g);
			if(cc >= 3) b.Set(pos + 2,p_color.b);
			if(cc >= 4) b.Set(pos + 3,p_color.a);
			return;
		}
		var b1 = this.m_buffer;
		b1.SetByte(pos,p_color.r * 255.0);
		if(cc >= 2) b1.SetByte(pos + 1,p_color.g * 255.0);
		if(cc >= 3) b1.SetByte(pos + 2,p_color.b * 255.0);
		if(cc >= 4) b1.SetByte(pos + 3,p_color.a * 255.0);
	}
	,Fill: function(p_color) {
		var _g1 = 0;
		var _g = this.m_width;
		while(_g1 < _g) {
			var ix = _g1++;
			var _g3 = 0;
			var _g2 = this.m_height;
			while(_g3 < _g2) {
				var iy = _g3++;
				this.SetPixel(ix,iy,p_color);
			}
		}
	}
	,Set: function(p_x,p_y,p_v0,p_v1,p_v2,p_v3) {
		if(p_v3 == null) p_v3 = 0.0;
		if(p_v2 == null) p_v2 = 0.0;
		if(p_v1 == null) p_v1 = 0.0;
		if(p_v0 == null) p_v0 = 0.0;
		var cc = this.m_channels;
		p_y = this.m_height - 1 - p_y;
		var pos = (p_x + p_y * this.m_width) * cc;
		if(this.m_float) {
			var b = this.m_buffer;
			b.Set(pos,p_v0);
			if(cc >= 2) b.Set(pos + 1,p_v1);
			if(cc >= 3) b.Set(pos + 2,p_v2);
			if(cc >= 4) b.Set(pos + 3,p_v3);
			return;
		}
		var b1 = this.m_buffer;
		b1.SetByte(pos,p_v0 * 255.0);
		if(cc >= 2) b1.SetByte(pos + 1,p_v1 * 255.0);
		if(cc >= 3) b1.SetByte(pos + 2,p_v2 * 255.0);
		if(cc >= 4) b1.SetByte(pos + 3,p_v3 * 255.0);
	}
	,SetRange: function(p_x,p_y,p_width,p_height,p_values,p_length) {
		if(p_length == null) p_length = -1;
		p_y = this.m_height - 1 - p_y;
		var cc = this.m_channels;
		var len;
		if(p_length < 0) len = p_values.length; else len = p_length;
		var k = 0;
		var px = p_x;
		var py = p_y;
		var v0 = 0.0;
		var v1 = 0.0;
		var v2 = 0.0;
		var v3 = 0.0;
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			var pos = (px + py * this.m_width) * cc;
			px++;
			if(px >= p_width) {
				px = p_x;
				py++;
			}
			v0 = p_values[k++];
			if(cc >= 2) v1 = p_values[k++];
			if(cc >= 3) v2 = p_values[k++];
			if(cc >= 4) v3 = p_values[k++];
			if(this.m_float) {
				var b = this.m_buffer;
				b.Set(pos,v0);
				if(cc >= 2) b.Set(pos + 1,v1);
				if(cc >= 3) b.Set(pos + 2,v2);
				if(cc >= 4) b.Set(pos + 3,v3);
				continue;
			}
			var b1 = this.m_buffer;
			b1.SetByte(pos,v0 * 255.0);
			if(cc >= 2) b1.SetByte(pos + 1,v1 * 255.0);
			if(cc >= 3) b1.SetByte(pos + 2,v2 * 255.0);
			if(cc >= 4) b1.SetByte(pos + 3,v3 * 255.0);
		}
	}
	,__class__: haxor_graphics_texture_Bitmap
	,__properties__: $extend(haxor_core_Resource.prototype.__properties__,{get_format:"get_format",get_channels:"get_channels",get_height:"get_height",get_width:"get_width",get_float:"get_float",get_buffer:"get_buffer"})
});
var haxor_graphics_texture_Texture = function() {
	haxor_core_Resource.call(this);
	this.m_mipmaps = false;
	this.m_format = haxor_core_PixelFormat.RGBA8;
	this.m_minFilter = haxor_core_TextureFilter.Linear;
	this.m_magFilter = haxor_core_TextureFilter.Linear;
	this.m_wrap = haxor_core_TextureWrap.ClampX | haxor_core_TextureWrap.ClampY | haxor_core_TextureWrap.ClampZ;
	this.m_width = 0;
	this.m_height = 0;
	this.m_aniso = 0;
	this.__cid = haxor_context_EngineContext.texture.tid.get_id();
};
$hxClasses["haxor.graphics.texture.Texture"] = haxor_graphics_texture_Texture;
haxor_graphics_texture_Texture.__name__ = ["haxor","graphics","texture","Texture"];
haxor_graphics_texture_Texture.__super__ = haxor_core_Resource;
haxor_graphics_texture_Texture.prototype = $extend(haxor_core_Resource.prototype,{
	get_width: function() {
		return this.m_width;
	}
	,get_height: function() {
		return this.m_height;
	}
	,get_format: function() {
		return this.m_format;
	}
	,get_wrap: function() {
		return this.m_wrap;
	}
	,set_wrap: function(v) {
		if(this.m_wrap == v) return v;
		this.m_wrap = v;
		haxor_context_EngineContext.texture.UpdateParameters(this);
		return v;
	}
	,get_aniso: function() {
		return this.m_aniso;
	}
	,set_aniso: function(v) {
		if(this.m_aniso == v) return v;
		this.m_aniso = v;
		haxor_context_EngineContext.texture.UpdateParameters(this);
		return v;
	}
	,get_minFilter: function() {
		return this.m_minFilter;
	}
	,set_minFilter: function(v) {
		if(this.m_minFilter == v) return v;
		this.m_minFilter = v;
		haxor_context_EngineContext.texture.UpdateParameters(this);
		return v;
	}
	,get_magFilter: function() {
		return this.m_magFilter;
	}
	,set_magFilter: function(v) {
		if(this.m_magFilter == v) return v;
		this.m_magFilter = v;
		haxor_context_EngineContext.texture.UpdateParameters(this);
		return v;
	}
	,get_mipmaps: function() {
		return this.m_mipmaps;
	}
	,get_type: function() {
		return haxor_core_TextureType.None;
	}
	,Apply: function() {
		haxor_context_EngineContext.texture.Update(this);
	}
	,GenerateMipmaps: function() {
		if(this.m_mipmaps) return;
		this.m_mipmaps = true;
		haxor_context_EngineContext.texture.UpdateMipmaps(this);
	}
	,OnDestroy: function() {
		haxor_core_Resource.prototype.OnDestroy.call(this);
		haxor_context_EngineContext.texture.Destroy(this);
	}
	,__class__: haxor_graphics_texture_Texture
	,__properties__: $extend(haxor_core_Resource.prototype.__properties__,{get_type:"get_type",get_mipmaps:"get_mipmaps",set_magFilter:"set_magFilter",get_magFilter:"get_magFilter",set_minFilter:"set_minFilter",get_minFilter:"get_minFilter",set_aniso:"set_aniso",get_aniso:"get_aniso",set_wrap:"set_wrap",get_wrap:"get_wrap",get_format:"get_format",get_height:"get_height",get_width:"get_width"})
});
var haxor_graphics_texture_Texture2D = function(p_width,p_height,p_format) {
	haxor_graphics_texture_Texture.call(this);
	this.m_format = p_format;
	this.m_width = p_width;
	this.m_height = p_height;
	if(p_width <= 0) return;
	if(p_height <= 0) return;
	this.m_data = new haxor_graphics_texture_Bitmap(p_width,p_height,p_format);
	haxor_context_EngineContext.texture.Create(this);
};
$hxClasses["haxor.graphics.texture.Texture2D"] = haxor_graphics_texture_Texture2D;
haxor_graphics_texture_Texture2D.__name__ = ["haxor","graphics","texture","Texture2D"];
haxor_graphics_texture_Texture2D.__properties__ = {get_random:"get_random",get_green:"get_green",get_red:"get_red",get_black:"get_black",get_white:"get_white"}
haxor_graphics_texture_Texture2D.get_white = function() {
	if(haxor_graphics_texture_Texture2D.m_white != null) return haxor_graphics_texture_Texture2D.m_white;
	haxor_graphics_texture_Texture2D.m_white = new haxor_graphics_texture_Texture2D(1,1,haxor_core_PixelFormat.RGB8);
	haxor_graphics_texture_Texture2D.m_white.set_name("White");
	haxor_graphics_texture_Texture2D.m_white.m_data.Fill(new haxor_math_Color(1,1,1,1));
	haxor_graphics_texture_Texture2D.m_white.Apply();
	return haxor_graphics_texture_Texture2D.m_white;
};
haxor_graphics_texture_Texture2D.get_black = function() {
	if(haxor_graphics_texture_Texture2D.m_black != null) return haxor_graphics_texture_Texture2D.m_black;
	haxor_graphics_texture_Texture2D.m_black = new haxor_graphics_texture_Texture2D(1,1,haxor_core_PixelFormat.RGB8);
	haxor_graphics_texture_Texture2D.m_black.set_name("Black");
	haxor_graphics_texture_Texture2D.m_black.m_data.Fill(new haxor_math_Color(0,0,0,1));
	haxor_graphics_texture_Texture2D.m_black.Apply();
	return haxor_graphics_texture_Texture2D.m_black;
};
haxor_graphics_texture_Texture2D.get_red = function() {
	if(haxor_graphics_texture_Texture2D.m_red != null) return haxor_graphics_texture_Texture2D.m_red;
	haxor_graphics_texture_Texture2D.m_red = new haxor_graphics_texture_Texture2D(1,1,haxor_core_PixelFormat.RGB8);
	haxor_graphics_texture_Texture2D.m_red.set_name("Red");
	haxor_graphics_texture_Texture2D.m_red.m_data.Fill(new haxor_math_Color(1.0,0,0,1));
	haxor_graphics_texture_Texture2D.m_red.Apply();
	return haxor_graphics_texture_Texture2D.m_red;
};
haxor_graphics_texture_Texture2D.get_green = function() {
	if(haxor_graphics_texture_Texture2D.m_green != null) return haxor_graphics_texture_Texture2D.m_green;
	haxor_graphics_texture_Texture2D.m_green = new haxor_graphics_texture_Texture2D(1,1,haxor_core_PixelFormat.RGB8);
	haxor_graphics_texture_Texture2D.m_green.set_name("Green");
	haxor_graphics_texture_Texture2D.m_green.m_data.Fill(new haxor_math_Color(0,1,0,1));
	haxor_graphics_texture_Texture2D.m_green.Apply();
	return haxor_graphics_texture_Texture2D.m_green;
};
haxor_graphics_texture_Texture2D.get_random = function() {
	if(haxor_graphics_texture_Texture2D.m_random != null) return haxor_graphics_texture_Texture2D.m_random;
	haxor_graphics_texture_Texture2D.m_random = new haxor_graphics_texture_Texture2D(512,512,haxor_core_PixelFormat.Float4);
	haxor_graphics_texture_Texture2D.m_random.set_wrap(haxor_core_TextureWrap.RepeatX | haxor_core_TextureWrap.RepeatY);
	var _g1 = 0;
	var _g = haxor_graphics_texture_Texture2D.m_random.m_width;
	while(_g1 < _g) {
		var i = _g1++;
		var _g3 = 0;
		var _g2 = haxor_graphics_texture_Texture2D.m_random.m_height;
		while(_g3 < _g2) {
			var j = _g3++;
			haxor_graphics_texture_Texture2D.m_random.m_data.Set(j,i,Math.random(),Math.random(),Math.random(),Math.random());
		}
	}
	haxor_graphics_texture_Texture2D.m_random.Upload(10);
	return haxor_graphics_texture_Texture2D.m_random;
};
haxor_graphics_texture_Texture2D.FromBitmap = function(p_bitmap,p_apply) {
	if(p_apply == null) p_apply = true;
	var t = new haxor_graphics_texture_Texture2D(0,0,p_bitmap.m_format);
	t.m_data = p_bitmap;
	t.m_width = p_bitmap.m_width;
	t.m_height = p_bitmap.m_height;
	haxor_context_EngineContext.texture.Create(t);
	t.Apply();
	return t;
};
haxor_graphics_texture_Texture2D.__super__ = haxor_graphics_texture_Texture;
haxor_graphics_texture_Texture2D.prototype = $extend(haxor_graphics_texture_Texture.prototype,{
	get_data: function() {
		return this.m_data;
	}
	,get_type: function() {
		return haxor_core_TextureType.Texture2D;
	}
	,Upload: function(p_steps,p_on_complete) {
		if(p_steps == null) p_steps = 200;
		haxor_context_EngineContext.texture.UploadTexture(this,0,0,this.m_width,this.m_height,p_steps,p_on_complete);
	}
	,__class__: haxor_graphics_texture_Texture2D
	,__properties__: $extend(haxor_graphics_texture_Texture.prototype.__properties__,{get_data:"get_data"})
});
var haxor_graphics_texture_ComputeTexture = function(p_width,p_height,p_format) {
	haxor_graphics_texture_Texture2D.call(this,p_width,p_height,p_format);
	this.set_minFilter(haxor_core_TextureFilter.Nearest);
	this.set_magFilter(haxor_core_TextureFilter.Nearest);
	this.m_lock = false;
	this.m_dirty = false;
};
$hxClasses["haxor.graphics.texture.ComputeTexture"] = haxor_graphics_texture_ComputeTexture;
haxor_graphics_texture_ComputeTexture.__name__ = ["haxor","graphics","texture","ComputeTexture"];
haxor_graphics_texture_ComputeTexture.__super__ = haxor_graphics_texture_Texture2D;
haxor_graphics_texture_ComputeTexture.prototype = $extend(haxor_graphics_texture_Texture2D.prototype,{
	get_type: function() {
		return haxor_core_TextureType.Compute;
	}
	,Write: function(p_x,p_y,p_v0,p_v1,p_v2,p_v3) {
		if(p_v3 == null) p_v3 = 0;
		if(p_v2 == null) p_v2 = 0;
		if(p_v1 == null) p_v1 = 0;
		if(p_v0 == null) p_v0 = 0;
		this.m_data.SetPixel(p_x,p_y,haxor_context_EngineContext.data.get_c().Set(p_v0,p_v1,p_v2,p_v3));
		this.m_dirty = true;
		this.Invalidate();
	}
	,WriteRange: function(p_values,p_x,p_y,p_width,p_height) {
		if(p_height == null) p_height = -1;
		if(p_width == null) p_width = -1;
		if(p_y == null) p_y = 0;
		if(p_x == null) p_x = 0;
		var w;
		if(p_width < 0) w = this.m_width; else w = p_width;
		var h;
		if(p_height < 0) h = this.m_height; else h = p_height;
		this.m_data.SetRange(p_x,p_y,w,h,p_values);
		this.Invalidate();
		this.m_dirty = true;
	}
	,Invalidate: function() {
		this.Apply();
	}
	,OnUploadComplete: function() {
		this.m_lock = false;
		if(this.m_dirty) this.Invalidate();
		this.m_dirty = false;
	}
	,__class__: haxor_graphics_texture_ComputeTexture
});
var haxor_graphics_texture_RenderTexture = function(p_width,p_height,p_format,p_store_depth) {
	if(p_store_depth == null) p_store_depth = false;
	haxor_graphics_texture_Texture.call(this);
	this.m_format = p_format;
	this.m_width = p_width | 0;
	this.m_height = p_height | 0;
	var store_depth = p_store_depth && haxor_graphics_GL.TEXTURE_DEPTH_ENABLED;
	if(store_depth) this.m_depth = new haxor_graphics_texture_Texture2D(this.m_width,this.m_height,haxor_core_PixelFormat.Depth);
	haxor_context_EngineContext.texture.Create(this);
};
$hxClasses["haxor.graphics.texture.RenderTexture"] = haxor_graphics_texture_RenderTexture;
haxor_graphics_texture_RenderTexture.__name__ = ["haxor","graphics","texture","RenderTexture"];
haxor_graphics_texture_RenderTexture.__super__ = haxor_graphics_texture_Texture;
haxor_graphics_texture_RenderTexture.prototype = $extend(haxor_graphics_texture_Texture.prototype,{
	get_depth: function() {
		return this.m_depth;
	}
	,get_type: function() {
		return haxor_core_TextureType.RenderTexture;
	}
	,__class__: haxor_graphics_texture_RenderTexture
	,__properties__: $extend(haxor_graphics_texture_Texture.prototype.__properties__,{get_depth:"get_depth"})
});
var haxor_graphics_texture_TextureCube = function() {
	this.m_faces = [null,null,null,null,null,null];
	this.m_is_cross = false;
	haxor_graphics_texture_Texture.call(this);
	haxor_context_EngineContext.texture.Create(this);
};
$hxClasses["haxor.graphics.texture.TextureCube"] = haxor_graphics_texture_TextureCube;
haxor_graphics_texture_TextureCube.__name__ = ["haxor","graphics","texture","TextureCube"];
haxor_graphics_texture_TextureCube.FromCrossTexture = function(p_texture) {
	return null;
};
haxor_graphics_texture_TextureCube.__super__ = haxor_graphics_texture_Texture;
haxor_graphics_texture_TextureCube.prototype = $extend(haxor_graphics_texture_Texture.prototype,{
	get_px: function() {
		return this.m_faces[0];
	}
	,set_px: function(v) {
		this.InvalidateCross();
		this.m_faces[0] = v;
		return v;
	}
	,get_nx: function() {
		return this.m_faces[1];
	}
	,set_nx: function(v) {
		this.InvalidateCross();
		this.m_faces[1] = v;
		return v;
	}
	,get_py: function() {
		return this.m_faces[2];
	}
	,set_py: function(v) {
		this.InvalidateCross();
		this.m_faces[2] = v;
		return v;
	}
	,get_ny: function() {
		return this.m_faces[3];
	}
	,set_ny: function(v) {
		this.InvalidateCross();
		this.m_faces[3] = v;
		return v;
	}
	,get_pz: function() {
		return this.m_faces[4];
	}
	,set_pz: function(v) {
		this.InvalidateCross();
		this.m_faces[4] = v;
		return v;
	}
	,get_nz: function() {
		return this.m_faces[5];
	}
	,set_nz: function(v) {
		this.InvalidateCross();
		this.m_faces[5] = v;
		return v;
	}
	,OnDestroy: function() {
		haxor_graphics_texture_Texture.prototype.OnDestroy.call(this);
		var _g1 = 0;
		var _g = this.m_faces.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.m_faces[i] != null) haxor_core_Resource.Destroy(this.m_faces[i]);
		}
	}
	,InvalidateCross: function() {
		if(!this.m_is_cross) return;
		var _g1 = 0;
		var _g = this.m_faces.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.m_faces[i] != null) haxor_core_Resource.Destroy(this.m_faces[i]);
		}
	}
	,__class__: haxor_graphics_texture_TextureCube
	,__properties__: $extend(haxor_graphics_texture_Texture.prototype.__properties__,{set_nz:"set_nz",get_nz:"get_nz",set_pz:"set_pz",get_pz:"get_pz",set_ny:"set_ny",get_ny:"get_ny",set_py:"set_py",get_py:"get_py",set_nx:"set_nx",get_nx:"get_nx",set_px:"set_px",get_px:"get_px"})
});
var haxor_input_Input = function() { };
$hxClasses["haxor.input.Input"] = haxor_input_Input;
haxor_input_Input.__name__ = ["haxor","input","Input"];
haxor_input_Input.__properties__ = {get_multitouch:"get_multitouch",get_joystick:"get_joystick",get_touches:"get_touches"}
haxor_input_Input.get_touches = function() {
	return haxor_input_Input.m_touches;
};
haxor_input_Input.get_joystick = function() {
	return haxor_input_Input.m_joysticks;
};
haxor_input_Input.get_multitouch = function() {
	return haxor_input_Input.m_multitouch;
};
haxor_input_Input.GetInputState = function(p_code) {
	return haxor_input_Input.m_state.get(p_code);
};
haxor_input_Input.Pressed = function(p_code) {
	var s = haxor_input_Input.GetInputState(p_code);
	return s == haxor_core_InputState.Down || s == haxor_core_InputState.Hold;
};
haxor_input_Input.Down = function(p_code) {
	var s = haxor_input_Input.GetInputState(p_code);
	return s == haxor_core_InputState.Down;
};
haxor_input_Input.Hit = function(p_code) {
	var s = haxor_input_Input.GetInputState(p_code);
	return s == haxor_core_InputState.Up;
};
haxor_input_Input.GetHoldTime = function(p_code) {
	return haxor_input_Input.m_hold.get(p_code);
};
haxor_input_Input.Initialize = function() {
	haxor_input_Input.m_state = new haxe_ds_IntMap();
	haxor_input_Input.m_hold = new haxe_ds_IntMap();
	haxor_input_Input.m_active = new Array();
	haxor_input_Input.m_down = new Array();
	haxor_input_Input.m_touches = [];
	haxor_input_Input.m_api_touches = [];
	var _g = 0;
	while(_g < 10) {
		var i = _g++;
		haxor_input_Input.m_api_touches.push(new haxor_input_Touch());
	}
	var _g1 = 0;
	while(_g1 < 256) {
		var i1 = _g1++;
		haxor_input_Input.m_state.set(i1,haxor_core_InputState.None);
		haxor_input_Input.m_hold.set(i1,0);
		haxor_input_Input.m_down.push(false);
	}
	haxor_input_Input.m_joysticks = [];
	haxor_input_Input.m_api_joystick = [];
	var _g2 = 0;
	while(_g2 < 10) {
		var i2 = _g2++;
		haxor_input_Input.m_api_joystick.push(new haxor_input_Joystick());
	}
	haxor_input_Input.mouse = new haxor_math_Vector2();
	haxor_input_Input.deltaMouse = new haxor_math_Vector2();
	haxor_input_Input.relativeMouse = new haxor_math_Vector2();
	haxor_core_Console.Log("Haxor> Input Initialize",4);
};
haxor_input_Input.UpdateTouchFSM = function() {
	var _g1 = 0;
	var _g = haxor_input_Input.m_touches.length;
	while(_g1 < _g) {
		var j = _g1++;
		haxor_input_Input.TouchFSM(haxor_input_Input.m_touches[j]);
	}
};
haxor_input_Input.UpdateInput = function() {
	var _g1 = 0;
	var _g = haxor_input_Input.m_active.length;
	while(_g1 < _g) {
		var i = _g1++;
		haxor_input_Input.UpdateInputState(haxor_input_Input.m_active[i],haxor_input_Input.m_down[haxor_input_Input.m_active[i]]);
	}
};
haxor_input_Input.TouchFSM = function(t) {
	if(t == null) return;
	var current = t.state;
	var d = t.m_down;
	if(current == haxor_core_InputState.Up) HxOverrides.remove(haxor_input_Input.m_touches,t);
	if(current == haxor_core_InputState.Hold) t.hold += haxor_core_Time.m_delta;
	t.state = haxor_input_Input.InputStateFSM(current,d);
};
haxor_input_Input.UpdateInputState = function(p_code,p_is_down,p_update_state) {
	if(p_update_state == null) p_update_state = true;
	var current = haxor_input_Input.m_state.get(p_code);
	if(current == null) current = haxor_core_InputState.None;
	var next = current;
	var d0 = haxor_input_Input.m_down[p_code];
	var d = haxor_input_Input.m_down[p_code] = p_is_down;
	if(!d0) {
		if(d) haxor_input_Input.m_active.push(p_code);
	}
	if(!d) {
		if(d0) return;
	}
	if(p_update_state) {
		if(current == haxor_core_InputState.Up) {
			haxor_input_Input.m_hold.set(p_code,0);
			HxOverrides.remove(haxor_input_Input.m_active,p_code);
		}
		if(current == haxor_core_InputState.Hold) {
			var h = haxor_input_Input.m_hold.get(p_code);
			haxor_input_Input.m_hold.set(p_code,h + haxor_core_Time.m_delta);
		}
		next = haxor_input_Input.InputStateFSM(current,d);
		if(current != next) haxor_input_Input.m_state.set(p_code,next);
	}
};
haxor_input_Input.InputStateFSM = function(p_current,p_is_down) {
	var current = p_current;
	var next = current;
	var d = p_is_down;
	switch(current[1]) {
	case 0:
		if(d) next = haxor_core_InputState.Down;
		break;
	case 1:
		if(!d) next = haxor_core_InputState.Up;
		next = haxor_core_InputState.Hold;
		break;
	case 2:
		next = haxor_core_InputState.None;
		break;
	case 3:
		if(!d) next = haxor_core_InputState.Up;
		break;
	}
	return next;
};
var haxor_input_InputHandler = function() {
};
$hxClasses["haxor.input.InputHandler"] = haxor_input_InputHandler;
haxor_input_InputHandler.__name__ = ["haxor","input","InputHandler"];
haxor_input_InputHandler.prototype = {
	Update: function() {
		haxor_input_Input.UpdateInput();
		haxor_input_Input.UpdateTouchFSM();
		this.UpdateInput();
		if(haxor_input_Input.emulateTouch) {
			this.EmulateTouch(haxor_input_KeyCode.Mouse0,0);
			this.EmulateTouch(haxor_input_KeyCode.Mouse1,2);
			this.EmulateTouch(haxor_input_KeyCode.Mouse2,1);
		}
	}
	,UpdateInput: function() {
	}
	,Clear: function() {
		haxor_input_Input.wheel = 0;
		haxor_input_Input.deltaMouse.x = 0;
		haxor_input_Input.deltaMouse.y = 0;
	}
	,OnMouseMove: function(p_x,p_y) {
		haxor_input_Input.deltaMouse.x = p_x - haxor_input_Input.mouse.x;
		haxor_input_Input.deltaMouse.y = p_y - haxor_input_Input.mouse.y;
		haxor_input_Input.mouse.x = p_x;
		haxor_input_Input.mouse.y = p_y;
		haxor_input_Input.relativeMouse.x = haxor_input_Input.mouse.x / haxor_graphics_Screen.m_width;
		haxor_input_Input.relativeMouse.y = haxor_input_Input.mouse.y / haxor_graphics_Screen.m_height;
	}
	,OnMouseWheel: function(p_wheel) {
		haxor_input_Input.wheel = p_wheel;
	}
	,OnMouseButton: function(p_button,p_down) {
		switch(p_button) {
		case 0:
			haxor_input_Input.UpdateInputState(haxor_input_KeyCode.Mouse0,p_down,false);
			break;
		case 1:
			haxor_input_Input.UpdateInputState(haxor_input_KeyCode.Mouse1,p_down,false);
			break;
		case 2:
			haxor_input_Input.UpdateInputState(haxor_input_KeyCode.Mouse2,p_down,false);
			break;
		case 3:
			haxor_input_Input.UpdateInputState(haxor_input_KeyCode.Mouse3,p_down,false);
			break;
		case 4:
			haxor_input_Input.UpdateInputState(haxor_input_KeyCode.Mouse4,p_down,false);
			break;
		}
	}
	,OnKey: function(p_code,p_down) {
		haxor_input_Input.UpdateInputState(p_code,p_down,false);
	}
	,OnTouchStart: function(p_id,p_x,p_y,p_rx,p_ry,p_pressure,p_angle) {
		if(p_angle == null) p_angle = 0.0;
		if(p_pressure == null) p_pressure = 0.0;
		if(p_ry == null) p_ry = 0.0;
		if(p_rx == null) p_rx = 0.0;
		var t = haxor_input_Input.m_api_touches[p_id];
		t.id = p_id;
		t.position.x = p_x;
		t.position.y = p_y;
		t.relativePosition.x = t.position.x / haxor_graphics_Screen.m_width;
		t.relativePosition.y = t.position.y / haxor_graphics_Screen.m_height;
		t.delta.x = 0.0;
		t.delta.y = 0.0;
		t.pressure = p_pressure;
		t.radius.x = p_rx;
		t.radius.y = p_ry;
		t.angle = p_angle;
		t.m_down = true;
		if(haxor_input_Input.m_touches.indexOf(t) < 0) haxor_input_Input.m_touches.push(t);
	}
	,OnTouchMove: function(p_id,p_x,p_y) {
		var t = haxor_input_Input.m_api_touches[p_id];
		if(t.id >= 0) {
			t.delta.x = p_x - t.position.x;
			t.delta.y = p_y - t.position.y;
		}
		t.position.x = p_x;
		t.position.y = p_y;
		t.relativePosition.x = t.position.x / haxor_graphics_Screen.m_width;
		t.relativePosition.y = t.position.y / haxor_graphics_Screen.m_height;
	}
	,OnTouchCancel: function(p_id) {
		var t = haxor_input_Input.m_api_touches[p_id];
		t.m_down = false;
	}
	,OnTouchEnd: function(p_id) {
		var t = haxor_input_Input.m_api_touches[p_id];
		t.m_down = false;
	}
	,OnJoystickStart: function(p_id,p_name) {
		this.m_joystick = null;
		var jk = haxor_input_Input.m_api_joystick[p_id];
		if(jk == null) return;
		this.m_joystick = jk;
		if(haxor_input_Input.m_joysticks.indexOf(jk) >= 0) return;
		jk.id = p_id;
		jk.name = p_name;
		haxor_input_Input.m_joysticks.push(jk);
		haxor_input_Joystick.available = haxor_input_Input.m_joysticks.length > 0;
	}
	,OnJoystickDataUpdate: function(p_code,p_value,p_is_analog) {
		if(this.m_joystick == null) return;
		if(!p_is_analog) {
			this.m_joystick.button[p_code] = p_value;
			this.m_joystick.state[p_code] = haxor_input_Input.InputStateFSM(this.m_joystick.state[p_code],this.m_joystick.button[p_code] >= haxor_input_Joystick.buttonBias);
			if(this.m_joystick.state[p_code] == haxor_core_InputState.Hold) this.m_joystick.hold[p_code] += haxor_core_Time.m_delta;
			if(this.m_joystick.state[p_code] == haxor_core_InputState.None) this.m_joystick.hold[p_code] = 0.0;
		} else this.m_joystick.analog[p_code] = p_value;
	}
	,OnJoystickAnalogUpdate: function() {
		if(this.m_joystick == null) return;
		var b0 = haxor_input_Joystick.analogBias[0];
		var b1 = haxor_input_Joystick.analogBias[1];
		var s = 1.0;
		var v;
		var jk = this.m_joystick;
		v = jk.analogLeft;
		v.x = jk.analog[haxor_input_KeyCode.LeftAnalogueHor];
		if(v.x < 0.0) s = -1.0; else s = 1.0;
		v.x = haxor_math_Mathf.Clamp01((haxor_math_Mathf.Abs(v.x) - b0) / (b1 - b0));
		v.x = s * (v.x * 100.0 | 0) * 0.01;
		v.y = jk.analog[haxor_input_KeyCode.LeftAnalogueVert];
		if(v.y < 0.0) s = -1.0; else s = 1.0;
		v.y = haxor_math_Mathf.Clamp01((haxor_math_Mathf.Abs(v.y) - b0) / (b1 - b0));
		v.y = -s * (v.y * 100.0 | 0) * 0.01;
		if(jk.button[haxor_input_KeyCode.LeftAnalogueStick] > 0.5) v.z = 1.0; else v.z = 0.0;
		v = jk.analogRight;
		v.x = jk.analog[haxor_input_KeyCode.RightAnalogueHor];
		if(v.x < 0.0) s = -1.0; else s = 1.0;
		v.x = haxor_math_Mathf.Clamp01((haxor_math_Mathf.Abs(v.x) - b0) / (b1 - b0));
		v.x = s * (v.x * 100.0 | 0) * 0.01;
		v.y = jk.analog[haxor_input_KeyCode.RightAnalogueVert];
		if(v.y < 0.0) s = -1.0; else s = 1.0;
		v.y = haxor_math_Mathf.Clamp01((haxor_math_Mathf.Abs(v.y) - b0) / (b1 - b0));
		v.y = -s * (v.y * 100.0 | 0) * 0.01;
		if(jk.button[haxor_input_KeyCode.RightAnalogueStick] > 0.5) v.z = 1.0; else v.z = 0.0;
		jk.triggerLeft = jk.button[haxor_input_KeyCode.LeftShoulderBottom];
		jk.triggerLeft = haxor_math_Mathf.Clamp01((jk.triggerLeft - b0) / (b1 - b0));
		jk.triggerRight = jk.button[haxor_input_KeyCode.RightShoulderBottom];
		jk.triggerRight = haxor_math_Mathf.Clamp01((jk.triggerRight - b0) / (b1 - b0));
	}
	,RequestJoystickVibration: function(p_joystick) {
	}
	,EmulateTouch: function(p_code,p_id) {
		if(haxor_input_Input.Down(p_code)) {
			var p = haxor_context_EngineContext.data.get_v2();
			switch(p_id) {
			case 0:
				p.Set2(haxor_input_Input.mouse);
				break;
			case 1:
				p.Set(haxor_graphics_Screen.m_width * 0.5,haxor_graphics_Screen.m_height * 0.5);
				break;
			case 2:
				p.Set(haxor_graphics_Screen.m_width * Math.random(),haxor_graphics_Screen.m_height * Math.random());
				break;
			}
			this.OnTouchStart(p_id,p.x,p.y);
		}
		if(p_id == 0) {
			if(haxor_input_Input.Pressed(p_code)) {
				if(haxor_input_Input.deltaMouse.get_length() > 0) this.OnTouchMove(p_id,haxor_input_Input.mouse.x,haxor_input_Input.mouse.y);
			}
		}
		if(haxor_input_Input.Hit(p_code)) this.OnTouchEnd(p_id);
	}
	,__class__: haxor_input_InputHandler
};
var haxor_input_Joystick = function() {
	var st = haxor_core_InputState.None;
	this.name = "";
	this.id = -1;
	this.button = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
	this.state = [st,st,st,st,st,st,st,st,st,st,st,st,st,st,st,st,st,st,st,st];
	this.hold = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
	this.analog = [0,0,0,0,0,0,0,0];
	this.analogLeft = new haxor_math_Vector3();
	this.analogRight = new haxor_math_Vector3();
	this.triggerLeft = 0.0;
	this.triggerRight = 0.0;
	this.m_vibrationLeft = 0.0;
	this.m_vibrationRight = 0.0;
};
$hxClasses["haxor.input.Joystick"] = haxor_input_Joystick;
haxor_input_Joystick.__name__ = ["haxor","input","Joystick"];
haxor_input_Joystick.prototype = {
	get_vibrationLeft: function() {
		return this.m_vibrationLeft;
	}
	,set_vibrationLeft: function(v) {
		if(haxor_math_Mathf.Abs(this.m_vibrationLeft - v) <= 0.0) return v;
		this.m_vibrationLeft = v;
		haxor_input_Input.m_handler.RequestJoystickVibration(this);
		return v;
	}
	,get_vibrationRight: function() {
		return this.m_vibrationRight;
	}
	,set_vibrationRight: function(v) {
		if(haxor_math_Mathf.Abs(this.m_vibrationRight - v) <= 0.0) return v;
		this.m_vibrationRight = v;
		haxor_input_Input.m_handler.RequestJoystickVibration(this);
		return v;
	}
	,Pressed: function(p_button) {
		return this.state[p_button] == haxor_core_InputState.Hold || this.state[p_button] == haxor_core_InputState.Down;
	}
	,Down: function(p_button) {
		return this.state[p_button] == haxor_core_InputState.Down;
	}
	,Hit: function(p_button) {
		return this.state[p_button] == haxor_core_InputState.Up;
	}
	,ToString: function(p_analog,p_button,p_trigger,p_pad) {
		if(p_pad == null) p_pad = true;
		if(p_trigger == null) p_trigger = true;
		if(p_button == null) p_button = true;
		if(p_analog == null) p_analog = true;
		var s = "";
		s += "J" + this.id;
		if(p_analog) {
			s += " AL" + this.analogLeft.ToString(1);
			s += " AR" + this.analogRight.ToString(1);
		}
		if(p_button) {
			s += " A[" + (this.Pressed(haxor_input_KeyCode.ButtonA)?"1]":"0]");
			s += " B[" + (this.Pressed(haxor_input_KeyCode.ButtonB)?"1]":"0]");
			s += " X[" + (this.Pressed(haxor_input_KeyCode.ButtonX)?"1]":"0]");
			s += " Y[" + (this.Pressed(haxor_input_KeyCode.ButtonY)?"1]":"0]");
			s += " L[" + (this.Pressed(haxor_input_KeyCode.LeftShoulder)?"1]":"0]");
			s += " R[" + (this.Pressed(haxor_input_KeyCode.RightShoulder)?"1]":"0]");
			s += " LB[" + (this.Pressed(haxor_input_KeyCode.LeftShoulderBottom)?"1]":"0]");
			s += " RB[" + (this.Pressed(haxor_input_KeyCode.RightShoulderBottom)?"1]":"0]");
			s += " Start[" + (this.Pressed(haxor_input_KeyCode.ButtonStart)?"1]":"0]");
			s += " Select[" + (this.Pressed(haxor_input_KeyCode.ButtonSelect)?"1]":"0]");
		}
		if(p_pad) {
			s += " PL[" + (this.Pressed(haxor_input_KeyCode.PadLeft)?"1]":"0]");
			s += " PR[" + (this.Pressed(haxor_input_KeyCode.PadRight)?"1]":"0]");
			s += " PU[" + (this.Pressed(haxor_input_KeyCode.PadTop)?"1]":"0]");
			s += " PD[" + (this.Pressed(haxor_input_KeyCode.PadBottom)?"1]":"0]");
		}
		if(p_trigger) {
			s += " TL[" + haxor_math_Mathf.RoundPlaces(this.triggerLeft,1) + "]";
			s += " TR[" + haxor_math_Mathf.RoundPlaces(this.triggerRight,1) + "]";
		}
		return s;
	}
	,__class__: haxor_input_Joystick
	,__properties__: {set_vibrationRight:"set_vibrationRight",get_vibrationRight:"get_vibrationRight",set_vibrationLeft:"set_vibrationLeft",get_vibrationLeft:"get_vibrationLeft"}
};
var haxor_input_KeyCode = function() { };
$hxClasses["haxor.input.KeyCode"] = haxor_input_KeyCode;
haxor_input_KeyCode.__name__ = ["haxor","input","KeyCode"];
var haxor_input_Touch = function() {
	this.state = haxor_core_InputState.None;
	this.id = -1;
	this.position = new haxor_math_Vector2();
	this.delta = new haxor_math_Vector2();
	this.relativePosition = new haxor_math_Vector2();
	this.pressure = 0;
	this.hold = 0;
	this.angle = 0;
	this.radius = new haxor_math_Vector2();
	this.m_down = false;
};
$hxClasses["haxor.input.Touch"] = haxor_input_Touch;
haxor_input_Touch.__name__ = ["haxor","input","Touch"];
haxor_input_Touch.prototype = {
	ToString: function() {
		return "id[" + this.id + "] pos" + this.position.ToString(2) + "[" + Std.string(this.state) + "]";
	}
	,__class__: haxor_input_Touch
};
var haxor_io_Buffer = function(p_length) {
	this.Resize(p_length);
};
$hxClasses["haxor.io.Buffer"] = haxor_io_Buffer;
haxor_io_Buffer.__name__ = ["haxor","io","Buffer"];
haxor_io_Buffer.FromString = function(p_string) {
	var b = new haxor_io_Buffer(p_string.length);
	b.SetString(p_string);
	return b;
};
haxor_io_Buffer.prototype = {
	get_buffer: function() {
		return this.m_buffer;
	}
	,get_byteLength: function() {
		return this.m_length * this.get_bytesPerElement();
	}
	,get_bytesPerElement: function() {
		return 1;
	}
	,get_length: function() {
		return this.m_length;
	}
	,Resize: function(p_length) {
		this.m_length = p_length;
		var len = this.m_length * this.get_bytesPerElement();
		this.m_offset = 0;
		this.m_buffer = new Uint8Array(len);
		this.aux = this.m_buffer;
	}
	,GetByte: function(p_index) {
		return this.m_buffer[p_index];
		return 0;
	}
	,SetByte: function(p_index,p_value) {
		this.m_buffer[p_index] = p_value;
	}
	,SetBytes: function(p_list,p_offset) {
		if(p_offset == null) p_offset = 0;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.SetByte(i + p_offset,p_list[i]);
		}
	}
	,SetBuffer: function(p_target,p_offset) {
		if(p_offset == null) p_offset = 0;
		var _g1 = 0;
		var _g = p_target.m_length * p_target.get_bytesPerElement();
		while(_g1 < _g) {
			var i = _g1++;
			this.SetByte(i + p_offset,p_target.GetByte(i));
		}
	}
	,EncodeBase64: function() {
		var b = haxe_io_Bytes.alloc(this.m_length * this.get_bytesPerElement());
		var _g1 = 0;
		var _g = b.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.set(i,this.GetByte(i));
		}
		var res = haxe_crypto_Base64.encode(b);
		var new_len = Std["int"](res.length / this.get_bytesPerElement());
		this.Resize(new_len);
		this.SetString(res);
		return res;
	}
	,DecodeBase64: function() {
		var b64 = this.GetString();
		var b = haxe_crypto_Base64.decode(b64);
		var new_len = Std["int"](b.length / this.get_bytesPerElement());
		this.Resize(new_len);
		var _g1 = 0;
		var _g = b.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.SetByte(i,b.b[i]);
		}
	}
	,GetString: function(p_offset,p_length) {
		if(p_length == null) p_length = 0;
		if(p_offset == null) p_offset = 0;
		var len;
		if(p_length <= 0) len = this.m_length * this.get_bytesPerElement(); else len = p_length;
		var s = new StringBuf();
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			s.addChar(this.GetByte(i + p_offset));
		}
		return s.b;
	}
	,SetString: function(p_string,p_offset) {
		if(p_offset == null) p_offset = 0;
		var _g1 = 0;
		var _g = p_string.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.SetByte(i + p_offset,HxOverrides.cca(p_string,i));
		}
	}
	,SetViewSlice: function(p_start,p_length) {
		var i0 = p_start * this.get_bytesPerElement();
		var i1 = i0 + p_length * this.get_bytesPerElement();
		this.orig = this.aux;
		if(this.get_bytesPerElement() == 1) {
			var i8 = this.aux;
			this.aux = i8.subarray(i0,i1);
		}
	}
	,ResetSlice: function() {
		this.aux = this.orig;
	}
	,__class__: haxor_io_Buffer
	,__properties__: {get_length:"get_length",get_bytesPerElement:"get_bytesPerElement",get_byteLength:"get_byteLength",get_buffer:"get_buffer"}
};
var haxor_io_FloatArray = function(p_length) {
	haxor_io_Buffer.call(this,p_length);
};
$hxClasses["haxor.io.FloatArray"] = haxor_io_FloatArray;
haxor_io_FloatArray.__name__ = ["haxor","io","FloatArray"];
haxor_io_FloatArray.Alloc = function(p_data) {
	var b = new haxor_io_FloatArray(p_data.length);
	b.SetRange(p_data);
	return b;
};
haxor_io_FloatArray.FromBase64 = function(p_data) {
	var b = new haxor_io_FloatArray(p_data.length / 4 | 0);
	b.SetString(p_data);
	b.DecodeBase64();
	return b;
};
haxor_io_FloatArray.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	var res = new haxor_io_FloatArray(tk.length);
	var _g1 = 0;
	var _g = tk.length;
	while(_g1 < _g) {
		var i = _g1++;
		res.Set(i,Std.parseFloat(StringTools.trim(tk[i])));
	}
	return res;
};
haxor_io_FloatArray.__super__ = haxor_io_Buffer;
haxor_io_FloatArray.prototype = $extend(haxor_io_Buffer.prototype,{
	get_bytesPerElement: function() {
		return 4;
	}
	,Resize: function(p_length) {
		haxor_io_Buffer.prototype.Resize.call(this,p_length);
		this.aux = new Float32Array(this.m_buffer.buffer);
	}
	,Get: function(p_index) {
		var f32 = this.aux;
		return f32[p_index];
	}
	,Set: function(p_index,p_value) {
		var f32 = this.aux;
		f32[p_index] = p_value;
	}
	,SetRange: function(p_data,p_offset) {
		if(p_offset == null) p_offset = 0;
		var _g1 = 0;
		var _g = p_data.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.Set(i + p_offset,p_data[i]);
		}
	}
	,SetViewSlice: function(p_start,p_length) {
		haxor_io_Buffer.prototype.SetViewSlice.call(this,p_start,p_length);
		var i0 = p_start;
		var i1 = i0 + p_length;
		var f32 = this.aux;
		this.aux = f32.subarray(i0,i1);
	}
	,__class__: haxor_io_FloatArray
});
var haxor_io_Int32Array = function(p_length) {
	haxor_io_Buffer.call(this,p_length);
};
$hxClasses["haxor.io.Int32Array"] = haxor_io_Int32Array;
haxor_io_Int32Array.__name__ = ["haxor","io","Int32Array"];
haxor_io_Int32Array.Alloc = function(p_data) {
	var b = new haxor_io_Int32Array(p_data.length);
	b.SetRange(p_data);
	return b;
};
haxor_io_Int32Array.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	var res = new haxor_io_Int32Array(tk.length);
	var _g1 = 0;
	var _g = tk.length;
	while(_g1 < _g) {
		var i = _g1++;
		res.Set(i,Std.parseInt(StringTools.trim(tk[i])));
	}
	return res;
};
haxor_io_Int32Array.__super__ = haxor_io_Buffer;
haxor_io_Int32Array.prototype = $extend(haxor_io_Buffer.prototype,{
	get_bytesPerElement: function() {
		return 4;
	}
	,Resize: function(p_length) {
		haxor_io_Buffer.prototype.Resize.call(this,p_length);
		this.aux = new Int32Array(this.m_buffer.buffer);
	}
	,Get: function(p_index) {
		var i32 = this.aux;
		return i32[p_index];
	}
	,Set: function(p_index,p_value) {
		var i32 = this.aux;
		i32[p_index] = p_value;
	}
	,SetRange: function(p_data,p_offset) {
		if(p_offset == null) p_offset = 0;
		var _g1 = 0;
		var _g = p_data.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.Set(i + p_offset,p_data[i]);
		}
	}
	,SetViewSlice: function(p_start,p_length) {
		haxor_io_Buffer.prototype.SetViewSlice.call(this,p_start,p_length);
		var i0 = p_start;
		var i1 = i0 + p_length;
		var i32 = this.aux;
		this.aux = i32.subarray(i0,i1);
	}
	,__class__: haxor_io_Int32Array
});
var haxor_io_UInt16Array = function(p_length) {
	haxor_io_Buffer.call(this,p_length);
};
$hxClasses["haxor.io.UInt16Array"] = haxor_io_UInt16Array;
haxor_io_UInt16Array.__name__ = ["haxor","io","UInt16Array"];
haxor_io_UInt16Array.Alloc = function(p_data) {
	var b = new haxor_io_UInt16Array(p_data.length);
	b.SetRange(p_data);
	return b;
};
haxor_io_UInt16Array.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	var res = new haxor_io_UInt16Array(tk.length);
	var _g1 = 0;
	var _g = tk.length;
	while(_g1 < _g) {
		var i = _g1++;
		res.Set(i,Std.parseInt(StringTools.trim(tk[i])));
	}
	return res;
};
haxor_io_UInt16Array.__super__ = haxor_io_Buffer;
haxor_io_UInt16Array.prototype = $extend(haxor_io_Buffer.prototype,{
	get_bytesPerElement: function() {
		return 2;
	}
	,Resize: function(p_length) {
		haxor_io_Buffer.prototype.Resize.call(this,p_length);
		this.aux = new Uint16Array(this.m_buffer.buffer);
	}
	,Get: function(p_index) {
		var i16 = this.aux;
		return i16[p_index];
	}
	,Set: function(p_index,p_value) {
		var i16 = this.aux;
		i16[p_index] = p_value;
	}
	,SetRange: function(p_data,p_offset) {
		if(p_offset == null) p_offset = 0;
		var _g1 = 0;
		var _g = p_data.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.Set(i + p_offset,p_data[i]);
		}
	}
	,SetViewSlice: function(p_start,p_length) {
		haxor_io_Buffer.prototype.SetViewSlice.call(this,p_start,p_length);
		var i0 = p_start;
		var i1 = i0 + p_length;
		var i16 = this.aux;
		this.aux = i16.subarray(i0,i1);
	}
	,__class__: haxor_io_UInt16Array
});
var haxor_io_file_Asset = function() { };
$hxClasses["haxor.io.file.Asset"] = haxor_io_file_Asset;
haxor_io_file_Asset.__name__ = ["haxor","io","file","Asset"];
haxor_io_file_Asset.Get = function(p_id) {
	if(haxor_io_file_Asset.m_database.exists(p_id)) return haxor_io_file_Asset.m_database.get(p_id); else return null;
};
haxor_io_file_Asset.Remove = function(p_id) {
	if(haxor_io_file_Asset.m_database.exists(p_id)) {
		var a = haxor_io_file_Asset.m_database.get(p_id);
		haxor_io_file_Asset.m_database.remove(p_id);
		return a;
	}
	return null;
};
haxor_io_file_Asset.Add = function(p_id,p_asset) {
	var value = p_asset;
	haxor_io_file_Asset.m_database.set(p_id,value);
	if(js_Boot.__instanceof(p_asset,haxor_core_Resource)) (js_Boot.__cast(p_asset , haxor_core_Resource)).__db = p_id;
};
var haxor_io_file_AssetFile = function(p_name) {
	haxor_core_Resource.call(this,p_name);
};
$hxClasses["haxor.io.file.AssetFile"] = haxor_io_file_AssetFile;
haxor_io_file_AssetFile.__name__ = ["haxor","io","file","AssetFile"];
haxor_io_file_AssetFile.__super__ = haxor_core_Resource;
haxor_io_file_AssetFile.prototype = $extend(haxor_core_Resource.prototype,{
	get_asset: function() {
		return null;
	}
	,stof32a: function(v,sep) {
		if(sep == null) sep = " ";
		var l = StringTools.trim(StringTools.replace(v,"\n"," ")).split(sep);
		var a = [];
		var _g1 = 0;
		var _g = l.length;
		while(_g1 < _g) {
			var i = _g1++;
			a.push(Std.parseFloat(l[i]));
		}
		return a;
	}
	,stoi16a: function(v,sep) {
		if(sep == null) sep = " ";
		var l = StringTools.trim(StringTools.replace(v,"\n"," ")).split(sep);
		var a = [];
		var _g1 = 0;
		var _g = l.length;
		while(_g1 < _g) {
			var i = _g1++;
			a.push(Std.parseInt(l[i]));
		}
		return a;
	}
	,stoi16ta: function(v,s,sep) {
		if(sep == null) sep = " ";
		var l = StringTools.trim(StringTools.replace(v,"\n"," ")).split(sep);
		var tl = "";
		var a = [];
		var bf;
		var k = 0;
		while(k < l.length) {
			bf = [];
			var _g = 0;
			while(_g < s) {
				var j = _g++;
				bf.push(Std.parseInt(l[k++]));
			}
			a.push(bf);
		}
		return a;
	}
	,__class__: haxor_io_file_AssetFile
	,__properties__: $extend(haxor_core_Resource.prototype.__properties__,{get_asset:"get_asset"})
});
var haxor_io_file_AssetXML = function(p_name,p_src) {
	haxor_io_file_AssetFile.call(this,p_name);
	this.x = Xml.parse(p_src);
	this.TraverseStep(this.x.firstElement());
};
$hxClasses["haxor.io.file.AssetXML"] = haxor_io_file_AssetXML;
haxor_io_file_AssetXML.__name__ = ["haxor","io","file","AssetXML"];
haxor_io_file_AssetXML.__super__ = haxor_io_file_AssetFile;
haxor_io_file_AssetXML.prototype = $extend(haxor_io_file_AssetFile.prototype,{
	Parse: function(n) {
	}
	,TraverseStep: function(n) {
		this.Parse(n);
		var l = n.elements();
		while(l.hasNext()) this.TraverseStep(l.next());
	}
	,_a: function(n,a,v) {
		if(n.exists(a)) return n.get(a); else return v;
	}
	,_tla: function(n,a,v) {
		if(n.exists(a)) return StringTools.trim(n.get(a)).toLowerCase(); else return v;
	}
	,_p: function(n,p,v,t,tl) {
		if(tl == null) tl = false;
		if(t == null) t = false;
		var l = p.split(".");
		var it = n;
		var _g1 = 0;
		var _g = l.length;
		while(_g1 < _g) {
			var i = _g1++;
			var tk = l[i];
			switch(tk) {
			case "$text":
				if(it.firstChild() == null) return v;
				var txt = it.firstChild().toString();
				if(t) txt = StringTools.trim(txt);
				if(tl) txt = txt.toLowerCase();
				return txt;
			default:
				if(tk.charAt(0) == "@") {
					if(t) {
						if(tl) return this._tla(it,HxOverrides.substr(tk,1,null),v);
					}
					return this._a(it,HxOverrides.substr(tk,1,null),v);
				}
				var eit = it.elementsNamed(tk);
				if(eit == null) return v;
				if(i == l.length - 1) return eit;
				if(!eit.hasNext()) return v;
				it = eit.next();
			}
		}
		return v;
	}
	,_f: function(n,p,a,t) {
		var f = this._p(n,p,"");
		var it;
		if(f == "") it = null; else it = f;
		if(it == null) return null;
		while(it.hasNext()) {
			var e = it.next();
			if(this._a(e,a,"") == t) return e;
		}
		return null;
	}
	,__class__: haxor_io_file_AssetXML
});
var haxor_io_file_ColladaFile = function(p_name,p_src) {
	this.xmlns = "";
	this.version = "";
	this.data = new haxor_io_file_ColladaAssetData();
	this.geometries = [];
	this.images = [];
	this.controllers = [];
	this.materials = [];
	this.animations = [];
	this.lights = [];
	this.scene = null;
	this.m_id = Std["int"](Math.random() * 16777215);
	haxor_io_file_AssetXML.call(this,p_name,p_src);
};
$hxClasses["haxor.io.file.ColladaFile"] = haxor_io_file_ColladaFile;
haxor_io_file_ColladaFile.__name__ = ["haxor","io","file","ColladaFile"];
haxor_io_file_ColladaFile.GenerateTriangles = function(p_type,p_indexes,p_vcount) {
	var triangles = [];
	switch(p_type) {
	case "triangles":
		if(p_indexes.length <= 0) triangles = []; else triangles = p_indexes[0];
		break;
	case "polygons":
		var _g1 = 0;
		var _g = p_indexes.length;
		while(_g1 < _g) {
			var i = _g1++;
			var tris = haxor_io_file_ColladaFile.TriangulatePolygon(p_indexes[i],p_indexes[i].length);
			while(tris.length > 0) triangles.push(tris.shift());
		}
		break;
	case "polylist":
		var k = 0;
		var _g11 = 0;
		var _g2 = p_vcount.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			var o = p_vcount[i1];
			var tris1 = haxor_io_file_ColladaFile.TriangulatePolygon(p_indexes[0],o,k);
			while(tris1.length > 0) triangles.push(tris1.shift());
			k += o;
		}
		break;
	}
	return triangles;
};
haxor_io_file_ColladaFile.TriangulatePolygon = function(t,c,o) {
	if(o == null) o = 0;
	var i = 0;
	var i0 = 0;
	var i1 = 1;
	var i2 = 2;
	var res = [];
	while(i2 < c) {
		res.push(t[i0 + o].slice());
		res.push(t[i1 + o].slice());
		res.push(t[i2 + o].slice());
		i1++;
		i2++;
	}
	return res;
};
haxor_io_file_ColladaFile.__super__ = haxor_io_file_AssetXML;
haxor_io_file_ColladaFile.prototype = $extend(haxor_io_file_AssetXML.prototype,{
	get_asset: function() {
		var _g3 = this;
		var re = new haxor_core_Entity();
		re.set_name("collada_asset");
		if(this.scene == null) {
			haxor_core_Console.LogError("ColladaFile> Trying to get asset of NULL scene.");
			return re;
		}
		if(this.scene.name != "") re.set_name(this.scene.name); else if(this.scene.id != "") re.set_name(this.scene.id);
		var hm = new haxe_ds_ObjectMap();
		var cm = new haxe_ds_ObjectMap();
		var mm = new haxe_ds_ObjectMap();
		var joint_transforms = [];
		var joint_nodes = [];
		var skinned_meshes = [];
		var _g1 = 0;
		var _g = this.materials.length;
		while(_g1 < _g) {
			var i = _g1++;
			var m = this.materials[i];
			var mn = m.name;
			var _g2 = 0;
			while(_g2 < 10) {
				var i1 = _g2++;
				mn = StringTools.replace(mn,"_" + i1,"");
			}
			mn = StringTools.replace(mn,"_","/");
			var mat = haxor_io_file_Asset.Get(mn);
			if(mat == null) {
				mat = new haxor_graphics_material_Material();
				mat.set_name(mn);
				mat.set_shader(haxor_io_file_Asset.Get("haxor/unlit/FlatTexture"));
				haxor_io_file_Asset.Add(mn,mat);
			}
			mm.set(m,mat);
		}
		this.scene.Traverse(function(n) {
			var pe;
			if(n.parent == null) pe = re; else if(hm.h.__keys__[n.parent.__id__] != null) pe = hm.h[n.parent.__id__]; else pe = re;
			var ne = null;
			if(n.name == "EnvironmentAmbientLight") return;
			ne = new haxor_core_Entity();
			ne.set_name("node" + ne.get_uid());
			if(n.sid != "") ne.set_name(n.sid); else if(n.id != "") ne.set_name(n.id); else if(n.name != "") ne.set_name(n.name);
			if(n.type == "joint") {
				joint_transforms.push(ne.m_transform);
				joint_nodes.push(n);
			}
			ne.m_transform.set_parent(pe.m_transform);
			ne.m_transform.set_localPosition(n.position);
			ne.m_transform.set_localRotation(n.rotation);
			ne.m_transform.set_localScale(n.scale);
			if(n.data != "") {
				var ad = ne.AddComponent(haxor_component_DataComponent);
				try {
					ad.data = JSON.parse(n.data);
				} catch( err ) {
				}
			}
			hm.set(n,ne);
			var _g11 = 0;
			var _g4 = n.instances.length;
			while(_g11 < _g4) {
				var i2 = _g11++;
				var ci = n.instances[i2];
				var mr = null;
				var cmat = null;
				var cg = null;
				var cc = null;
				var cg_target = "";
				var _g21 = ci.type;
				switch(_g21) {
				case "light":
					var cl = _g3.FindLightById(ci.target);
					if(cl == null) continue;
					var _g41 = cl.type;
					switch(_g41) {
					case "ambient":
						break;
					case "point":
						var pl = ne.AddComponent(haxor_component_light_PointLight);
						pl.color.SetColor(cl.color);
						pl.intensity = cl.intensity;
						pl.radius = cl.radius * 2.0;
						pl.atten = cl.atten;
						break;
					case "directional":
						break;
					}
					continue;
					break;
				case "geometry":
					cg_target = ci.target;
					break;
				case "controller":
					cc = _g3.FindControllerById(ci.target);
					if(cc != null) {
						cm.set(ne.m_transform,cc);
						cg_target = cc.source;
					}
					break;
				}
				cg = _g3.FindGeometryById(cg_target);
				if(cg != null) {
					var _g42 = 0;
					var _g22 = cg.mesh.primitives.length;
					while(_g42 < _g22) {
						var i3 = _g42++;
						var mn1 = cg.mesh.primitives[i3].material;
						cmat = _g3.FindMaterialById(mn1);
						mr = _g3.CreateMeshRenderer(ne,cg_target,cg.mesh.primitives[i3],cc == null?haxor_component_MeshRenderer:haxor_component_SkinnedMeshRenderer,cc);
						if(cc != null) skinned_meshes.push(mr);
						if(cmat != null) mr.set_material(mm.h.__keys__[cmat.__id__] != null?mm.h[cmat.__id__]:mr.m_material); else {
							var _g5 = 0;
							while(_g5 < 10) {
								var i4 = _g5++;
								mn1 = StringTools.replace(mn1,"_" + i4,"");
							}
							mn1 = StringTools.replace(mn1,"_","/");
							var mat1 = haxor_io_file_Asset.Get(mn1);
							mr.set_material(mat1);
						}
					}
				}
			}
		});
		var _g12 = 0;
		var _g6 = skinned_meshes.length;
		while(_g12 < _g6) {
			var i5 = _g12++;
			var skr = skinned_meshes[i5];
			var cc1;
			if(cm.h.__keys__[skr.m_entity.m_transform.__id__] != null) cc1 = cm.h[skr.m_entity.m_transform.__id__]; else cc1 = null;
			if(cc1 == null) continue;
			skr.set_joints([]);
			var _g31 = 0;
			var _g23 = cc1.joints.length;
			while(_g31 < _g23) {
				var j = _g31++;
				var _g51 = 0;
				var _g43 = joint_transforms.length;
				while(_g51 < _g43) {
					var k = _g51++;
					if(joint_transforms[k].get_name() == cc1.joints[j]) skr.m_joints.push(joint_transforms[k]);
				}
			}
		}
		var nit = hm.keys();
		while(nit.hasNext()) {
			var n1 = nit.next();
			var e = hm.h[n1.__id__];
			if(e == re) continue;
			e.set_name(n1.name);
		}
		this.AddAnimations(re);
		if(this.data.axis == "z_up") re.m_transform.set_rotation(haxor_math_Quaternion.FromAxisAngle(new haxor_math_Vector3(1,0,0),-90.0));
		return re;
	}
	,AddAnimations: function(p_entity,p_exact) {
		if(p_exact == null) p_exact = true;
		if(this.animations.length <= 0) return;
		var re = p_entity;
		var a = re.m_animation;
		if(a == null) a = re.AddComponent(haxor_component_animation_Animation);
		var _g1 = 0;
		var _g = this.animations.length;
		while(_g1 < _g) {
			var i = _g1++;
			var ca = this.animations[i];
			var clip = new haxor_component_animation_AnimationClip();
			clip.set_name(ca.id == ""?ca.name == ""?"clip" + i:ca.name:ca.id);
			var _g3 = 0;
			var _g2 = ca.channels.length;
			while(_g3 < _g2) {
				var j = _g3++;
				var cch = ca.channels[j];
				var src_node = cch.target.split("/")[0];
				src_node = StringTools.replace(src_node,"node-","");
				var src_target = cch.target.split("/")[1];
				var nt = re.m_transform.Search(src_node,p_exact);
				if(nt == null) continue;
				var n = nt.m_entity;
				switch(src_target) {
				case "matrix":
					var position_track = clip.Add(n.m_transform,"localPosition");
					var rotation_track = clip.Add(n.m_transform,"localRotation");
					var _g5 = 0;
					var _g4 = cch.keyframes.length;
					while(_g5 < _g4) {
						var k = _g5++;
						var kf = cch.keyframes[k];
						var m = haxor_math_Matrix4.FromArray(kf.values);
						position_track.Add(kf.time,m.GetColumn(3,null).get_xyz());
						rotation_track.Add(kf.time,haxor_math_Quaternion.FromMatrix4(haxor_context_EngineContext.data.get_m4().SetMatrix4(m).ToRotation()));
					}
					break;
				}
			}
			a.Add(clip);
		}
	}
	,CreateMeshRenderer: function(e,msh,cp,t,cc) {
		var r = e.AddComponent(t);
		var mid = msh + "_" + this.m_id;
		var m = haxor_io_file_Asset.Get(mid);
		if(m != null) {
			r.set_mesh(m);
			return r;
		}
		var mv = cp.GetTriangulatedVectorArray("vertex");
		var mn = cp.GetTriangulatedVectorArray("normal");
		var mc = cp.GetTriangulatedVectorArray("color");
		var muv0 = cp.GetTriangulatedVectorArray("texcoord",0);
		var muv1 = cp.GetTriangulatedVectorArray("texcoord",1);
		var mbn = cp.GetTriangulatedVectorArray("texbinormal");
		var mtg = cp.GetTriangulatedVectorArray("textangent");
		var is_skinned = js_Boot.__instanceof(r,haxor_component_SkinnedMeshRenderer);
		if(is_skinned) m = new haxor_graphics_mesh_SkinnedMesh3(); else m = new haxor_graphics_mesh_Mesh3();
		m.set_name(mid);
		haxor_io_file_Asset.Add(mid,m);
		if(mc.length > 0) m.set_color(mc);
		if(muv0.length > 0) m.set_uv0(muv0);
		if(muv1.length > 0) m.set_uv1(muv1);
		if(is_skinned) {
			if(cc != null) {
				cc.GenerateBonesAndWeights();
				var skm = m;
				var mvw = cc.GetTriangulatedWeights(cp);
				var mbi = cc.GetTriangulatedBones(cp);
				var mbm = cc.GetBinds();
				skm.set_binds(mbm);
				skm.set_weight(mvw);
				skm.set_bone(mbi);
				var bsm = cc.GetBSM();
				var _g1 = 0;
				var _g = mv.length;
				while(_g1 < _g) {
					var i = _g1++;
					mv[i] = bsm.Transform3x4(mv[i].get_clone());
				}
				var _g11 = 0;
				var _g2 = mn.length;
				while(_g11 < _g2) {
					var i1 = _g11++;
					mn[i1] = bsm.Transform3x3(mn[i1].get_clone());
				}
				var _g12 = 0;
				var _g3 = mbn.length;
				while(_g12 < _g3) {
					var i2 = _g12++;
					mbn[i2] = bsm.Transform3x3(mbn[i2].get_clone());
				}
				var _g13 = 0;
				var _g4 = mtg.length;
				while(_g13 < _g4) {
					var i3 = _g13++;
					mtg[i3] = bsm.Transform3x3(mtg[i3].get_clone());
				}
			}
		}
		if(mv.length > 0) m.set_vertex(mv);
		if(mn.length > 0) m.set_normal(mn);
		if(mbn.length > 0) m.set_binormal(mbn);
		if(mtg.length > 0) m.set_tangent(mtg);
		m.GenerateBounds();
		r.set_mesh(m);
		return r;
	}
	,FindLightById: function(p_id) {
		var _g1 = 0;
		var _g = this.lights.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.lights[i].id == p_id) return this.lights[i];
		}
		return null;
	}
	,FindGeometryById: function(p_id) {
		var _g1 = 0;
		var _g = this.geometries.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.geometries[i].id == p_id) return this.geometries[i];
		}
		return null;
	}
	,FindControllerById: function(p_id) {
		var _g1 = 0;
		var _g = this.controllers.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.controllers[i].id == p_id) return this.controllers[i];
		}
		return null;
	}
	,FindNodeById: function(p_id) {
		var res = null;
		this.scene.Traverse(function(it) {
			if(it.id == p_id) res = it;
		});
		return res;
	}
	,FindMaterialById: function(p_id) {
		var _g1 = 0;
		var _g = this.materials.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.materials[i].id == p_id) return this.materials[i]; else if(this.materials[i].name == p_id) return this.materials[i];
		}
		return null;
	}
	,Parse: function(n) {
		var _g = n.get_nodeName();
		switch(_g) {
		case "COLLADA":
			this.xmlns = this._a(n,"xmlns","");
			this.version = this._a(n,"version","0.0");
			break;
		case "asset":
			this.data.author = this._p(n,"contributor.author.$text","none");
			this.data.tool = this._p(n,"contributor.authoring_tool.$text","none");
			this.data.source = this._p(n,"contributor.source_data.$text","none");
			this.data.axis = this._p(n,"up_axis.$text","y_up").toLowerCase();
			this.data.creation = this._p(n,"created.$text","00/00/00");
			this.data.modification = this._p(n,"modified.$text","00/00/00");
			this.data.unitName = this._p(n,"unit.@name","none");
			this.data.unitValue = Std.parseFloat(this._p(n,"unit.@meter","0.0"));
			break;
		case "library_effects":
			break;
		case "library_materials":
			this.ParseMaterialLibrary(n);
			break;
		case "scene":
			break;
		case "library_geometries":
			this.ParseGeometryLibrary(n);
			break;
		case "library_controllers":
			this.ParseControllerLibrary(n);
			break;
		case "library_images":
			this.ParseImageLibrary(n);
			break;
		case "library_visual_scenes":
			this.ParseSceneLibrary(n);
			break;
		case "library_animations":
			this.ParseAnimationLibrary(n);
			break;
		case "library_lights":
			this.ParseLightLibrary(n);
			break;
		}
	}
	,ParseLightLibrary: function(n) {
		var it = n.elementsNamed("light");
		var l;
		var lit;
		var ln;
		while(it.hasNext()) {
			n = it.next();
			l = new haxor_io_file_ColladaLight();
			l.id = this._p(n,"@id","light" + this.lights.length);
			l.name = this._p(n,"@name",l.id);
			this.lights.push(l);
			lit = n.elementsNamed("technique_common");
			if(!lit.hasNext()) continue;
			lit = lit.next().elements();
			if(!lit.hasNext()) continue;
			ln = lit.next();
			l.type = ln.get_nodeName().toLowerCase();
			var ca = [1,1,1,1];
			var _g = l.type;
			switch(_g) {
			case "point":
				ca = this._f32a(this._p(ln,"color.$text",""));
				break;
			case "ambient":
				ca = this._f32a(this._p(ln,"color.$text",""));
				break;
			case "directional":
				ca = this._f32a(this._p(ln,"color.$text",""));
				break;
			}
			l.color.Set(ca[0],ca[1],ca[2],ca.length >= 4?ca[3]:1.0);
			lit = n.elementsNamed("extra");
			if(!lit.hasNext()) continue;
			lit = lit.next().elementsNamed("technique");
			if(!lit.hasNext()) continue;
			lit = lit.next().elementsNamed("max_light");
			if(!lit.hasNext()) continue;
			ln = lit.next();
			var _g1 = l.type;
			switch(_g1) {
			case "point":
				l.radius = Std.parseFloat(this._p(ln,"decay_radius.$text","1.0"));
				l.intensity = Std.parseFloat(this._p(ln,"multiplier.$text","1.0"));
				var atten_type = Std.parseInt(this._p(ln,"decay_type.$text","1.0"));
				if(atten_type == 0) l.atten = 0.0; else if(atten_type == 1) l.atten = 1.0; else l.atten = 2.0;
				break;
			case "ambient":
				break;
			case "directional":
				l.intensity = Std.parseFloat(this._p(ln,"multiplier.$text","1.0"));
				break;
			}
		}
	}
	,ParseAnimationLibrary: function(n) {
		var it = n.elementsNamed("animation");
		var anim_id = 0;
		while(it.hasNext()) {
			n = it.next();
			if(n.elementsNamed("animation").hasNext()) n = n.elementsNamed("animation").next();
			var ca = new haxor_io_file_ColladaAnimation();
			ca.id = this._a(n,"id","");
			if(ca.id == "") ca.id = "Clip" + anim_id++; else ca.id = ca.id;
			ca.name = this._a(n,"name",ca.id);
			var source_iterator = n.elementsNamed("source");
			var sampler_iterator = n.elementsNamed("sampler");
			var source_list = [];
			var sampler_list = [];
			while(source_iterator.hasNext()) source_list.push(source_iterator.next());
			while(sampler_iterator.hasNext()) sampler_list.push(sampler_iterator.next());
			var channel_list = n.elementsNamed("channel");
			while(channel_list.hasNext()) {
				var chn = channel_list.next();
				var cch = new haxor_io_file_ColladaAnimationChannel();
				var _this = this._a(chn,"source","");
				cch.source = HxOverrides.substr(_this,1,null);
				cch.target = this._a(chn,"target","");
				var _g1 = 0;
				var _g = sampler_list.length;
				while(_g1 < _g) {
					var i = _g1++;
					var sampler_id = this._a(sampler_list[i],"id","");
					if(sampler_id != cch.source) continue;
					var input_iterator = sampler_list[i].elementsNamed("input");
					var keyframe_time_source = "";
					var keyframe_value_source = "";
					while(input_iterator.hasNext()) {
						var chsi = input_iterator.next();
						var _g2 = this._a(chsi,"semantic","").toLowerCase();
						switch(_g2) {
						case "input":
							var _this1 = this._a(chsi,"source","");
							keyframe_time_source = HxOverrides.substr(_this1,1,null);
							break;
						case "output":
							var _this2 = this._a(chsi,"source","");
							keyframe_value_source = HxOverrides.substr(_this2,1,null);
							break;
						}
					}
					if(keyframe_time_source == "") continue;
					if(keyframe_value_source == "") continue;
					var kf_time_node = null;
					var kf_value_node = null;
					var _g3 = 0;
					var _g21 = source_list.length;
					while(_g3 < _g21) {
						var j = _g3++;
						var sn = source_list[j];
						if(this._a(sn,"id","") == keyframe_time_source) kf_time_node = sn;
						if(this._a(sn,"id","") == keyframe_value_source) kf_value_node = sn;
					}
					if(kf_time_node == null) continue;
					if(kf_value_node == null) continue;
					var kf_time_buffer = this._f32a(this._p(kf_time_node,"float_array.$text",""));
					var kf_value_buffer = this._f32a(this._p(kf_value_node,"float_array.$text",""));
					var kf_value_stride = Std.parseInt(this._p(kf_value_node,"technique_common.accessor.@stride","0"));
					var _g31 = 0;
					var _g22 = kf_time_buffer.length;
					while(_g31 < _g22) {
						var j1 = _g31++;
						var kf = new haxor_io_file_ColladaAnimationKeyFrame();
						kf.time = kf_time_buffer[j1];
						var _g4 = 0;
						while(_g4 < kf_value_stride) {
							var k = _g4++;
							kf.values.push(kf_value_buffer.shift());
						}
						cch.keyframes.push(kf);
					}
				}
				ca.channels.push(cch);
			}
			this.animations.push(ca);
		}
	}
	,ParseMaterialLibrary: function(n) {
		var it = n.elements();
		while(it.hasNext()) {
			n = it.next();
			var _g = n.get_nodeName();
			switch(_g) {
			case "material":
				var mat = new haxor_io_file_ColladaMaterial();
				mat.id = this._a(n,"id","");
				mat.name = this._a(n,"name","");
				if(mat.id == "") mat.id = mat.name;
				this.materials.push(mat);
				break;
			}
		}
	}
	,ParseSceneLibrary: function(n) {
		var it = n.elements();
		while(it.hasNext()) {
			n = it.next();
			var _g = n.get_nodeName();
			switch(_g) {
			case "visual_scene":
				this.ParseVisualScene(n);
				break;
			}
		}
	}
	,ParseVisualScene: function(n) {
		if(this.scene != null) return;
		this.scene = new haxor_io_file_ColladaVisualScene();
		this.scene.id = this._a(n,"id","collada_scene");
		this.scene.name = this._a(n,"name",this.scene.id);
		this.scene.type = n.get_nodeName();
		this.TraverseVisualSceneNodes(this.scene,null,n);
	}
	,TraverseVisualSceneNodes: function(scn,p,n) {
		var cn = null;
		if(n.get_nodeName() == "node") cn = this.ParseVisualSceneNode(scn,p,n);
		var cn_it = n.elementsNamed("node");
		while(cn_it.hasNext()) this.TraverseVisualSceneNodes(scn,cn,cn_it.next());
	}
	,ParseVisualSceneNode: function(scn,p,n) {
		var cn = new haxor_io_file_ColladaNode();
		cn.scene = scn;
		cn.sid = this._a(n,"sid","node" + Std["int"](Math.random() * 16777215));
		cn.id = this._a(n,"id",cn.sid);
		cn.name = this._a(n,"name",cn.sid);
		if(cn.sid == "") cn.sid = cn.id;
		cn.type = this._a(n,"type","NODE").toLowerCase();
		cn.matrix = this._f32a(this._p(n,"matrix.$text","1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1"));
		cn.parent = p;
		cn.GenerateTranform();
		var iit = n.elements();
		while(iit.hasNext()) {
			var nin = iit.next();
			var ni = null;
			var _g = nin.get_nodeName();
			switch(_g) {
			case "instance_geometry":
				ni = new haxor_io_file_ColladaInstance();
				ni.type = "geometry";
				var _this = this._a(nin,"url","");
				ni.target = HxOverrides.substr(_this,1,null);
				break;
			case "instance_controller":
				ni = new haxor_io_file_ColladaInstance();
				ni.type = "controller";
				var _this1 = this._a(nin,"url","");
				ni.target = HxOverrides.substr(_this1,1,null);
				break;
			case "instance_light":
				ni = new haxor_io_file_ColladaInstance();
				ni.type = "light";
				var _this2 = this._a(nin,"url","");
				ni.target = HxOverrides.substr(_this2,1,null);
				break;
			case "extra":
				cn.data = this._p(nin,"technique.user_properties.$text","");
				if(cn.data.indexOf(";") < 0) cn.data = "";
				break;
			}
			if(ni != null) cn.instances.push(ni);
		}
		if(p == null) scn.children.push(cn); else p.children.push(cn);
		return cn;
	}
	,ParseInstanceMaterials: function(ci,n) {
	}
	,ParseControllerLibrary: function(n) {
		var it = n.elementsNamed("controller");
		var c = null;
		while(it.hasNext()) {
			n = it.next();
			c = new haxor_io_file_ColladaController();
			c.id = this._a(n,"id","none");
			c.name = this._a(n,"name",c.id);
			this.ParseController(c,n);
			this.controllers.push(c);
		}
	}
	,ParseController: function(c,n) {
		n = n.firstElement();
		if(n == null) return;
		if(n.get_nodeName() == null) c.type = "none"; else c.type = n.get_nodeName().toLowerCase();
		var _g = c.type;
		switch(_g) {
		case "skin":
			this.ParseControllerSkin(c,n);
			break;
		case "morph":
			break;
		}
	}
	,ParseControllerSkin: function(c,n) {
		var _this = this._a(n,"source","");
		c.source = HxOverrides.substr(_this,1,null);
		c.matrix = this._f32a(this._p(n,"bind_shape_matrix.$text",""));
		var source = "";
		var sn = null;
		var jn;
		if(this._p(n,"joints") == null) jn = null; else jn = this._p(n,"joints").next();
		if(jn != null) {
			var jn_it = jn.elementsNamed("input");
			while(jn_it.hasNext()) {
				var jni = jn_it.next();
				var _this1 = this._a(jni,"source","");
				source = HxOverrides.substr(_this1,1,null);
				if(source == "") continue;
				sn = this._f(n,"source","id",source);
				if(sn == null) continue;
				var _g = this._a(jni,"semantic","").toLowerCase();
				switch(_g) {
				case "joint":
					c.joints = StringTools.trim(StringTools.replace(this._p(sn,"Name_array.$text",""),"\n"," ")).split(" ");
					break;
				case "inv_bind_matrix":
					var ml = this._f32a(this._p(sn,"float_array.$text",""));
					while(ml.length > 0) {
						var mtx = [];
						var _g1 = 0;
						while(_g1 < 16) {
							var i = _g1++;
							mtx.push(ml.shift());
						}
						c.binds.push(mtx);
					}
					break;
				}
			}
		}
		var vwn;
		if(this._p(n,"vertex_weights") == null) vwn = null; else vwn = this._p(n,"vertex_weights").next();
		if(vwn != null) {
			c.inputs = this.ParseInputList(n,vwn);
			c.vcount = this._i16a(this._p(vwn,"vcount.$text",""));
			var vwb = this._p(vwn,"v.$text","");
			c.indexes = this._i16ta(vwb,c.get_offset());
		}
	}
	,ParseImageLibrary: function(n) {
		var it = n.elementsNamed("image");
		var img = null;
		while(it.hasNext()) {
			n = it.next();
			img = new haxor_io_file_ColladaImage();
			img.id = this._a(n,"id","none");
			img.name = this._a(n,"name",img.id);
			img.format = this._a(n,"format","");
			img.width = Std.parseInt(this._a(n,"width","-1"));
			img.height = Std.parseInt(this._a(n,"height","-1"));
			img.depth = Std.parseInt(this._a(n,"depth","-1"));
			this.images.push(img);
		}
	}
	,ParseGeometryLibrary: function(n) {
		var it = n.elementsNamed("geometry");
		var g = null;
		while(it.hasNext()) {
			n = it.next();
			g = new haxor_io_file_ColladaGeometry();
			g.id = this._a(n,"id","none");
			g.name = this._a(n,"name","none");
			this.ParseGeometry(g,n);
			this.geometries.push(g);
		}
	}
	,ParseGeometry: function(g,n) {
		n = n.firstElement();
		if(n == null) return;
		g.mesh = new haxor_io_file_ColladaMesh();
		if(n.get_nodeName() == null) g.mesh.type = "none"; else g.mesh.type = n.get_nodeName().toLowerCase();
		var _g = g.mesh.type;
		switch(_g) {
		case "mesh":
			this.ParseMesh(g.mesh,n);
			break;
		case "convex_mesh":
			break;
		case "spline":
			break;
		}
	}
	,ParseMesh: function(m,n) {
		var it = n.elements();
		var p = n;
		while(it.hasNext()) {
			n = it.next();
			if(n.get_nodeName() == "vertices") continue;
			if(n.get_nodeName() == "source") continue;
			var cp = new haxor_io_file_ColladaPrimitive();
			cp.type = n.get_nodeName();
			cp.material = this._a(n,"material","");
			this.ParsePrimitive(cp,p,n);
			m.primitives.push(cp);
		}
	}
	,ParsePrimitive: function(cp,p,n) {
		cp.inputs = this.ParseInputList(p,n);
		var p_it = n.elementsNamed("p");
		var vc_it = n.elementsNamed("vcount");
		if(vc_it.hasNext()) {
			var ncitn = vc_it.next().firstChild();
			if(ncitn == null) cp.vcount = []; else cp.vcount = this._i16a(ncitn.toString());
		}
		while(p_it.hasNext()) {
			var vn = p_it.next();
			var vb;
			if(vn.firstChild() != null) vb = vn.firstChild().toString(); else vb = "0";
			var off = cp.get_offset();
			var ti = this._i16ta(vb,off);
			cp.indexes.push(ti);
		}
	}
	,ParseInputList: function(p,n) {
		var l = [];
		var it = n.elementsNamed("input");
		while(it.hasNext()) {
			var pi = it.next();
			var ci = new haxor_io_file_ColladaInput();
			var source = this._a(pi,"source","");
			ci.semantic = this._a(pi,"semantic","").toLowerCase();
			ci.offset = Std.parseInt(this._a(pi,"offset","-1"));
			ci.set = Std.parseInt(this._a(pi,"set","-1"));
			if(ci.semantic == "joint") {
				l.push(ci);
				continue;
			}
			if(ci.semantic == "vertex") source = this._p(p,"vertices.input.@source","");
			if(source == "") continue;
			source = HxOverrides.substr(source,1,null);
			var sn = this._f(p,"source","id",source);
			if(sn == null) continue;
			var stride_str = this._p(sn,"technique_common.accessor.@stride","0");
			ci.stride = Std.parseInt(stride_str);
			ci.values = this._f32a(this._p(sn,"float_array.$text",""));
			l.push(ci);
		}
		return l;
	}
	,TraverseStep: function(n) {
		this.Parse(n);
		var l = n.elements();
		while(l.hasNext()) this.TraverseStep(l.next());
	}
	,_f32a: function(v) {
		var l = StringTools.trim(StringTools.replace(v,"\n"," ")).split(" ");
		var a = [];
		var _g1 = 0;
		var _g = l.length;
		while(_g1 < _g) {
			var i = _g1++;
			a.push(Std.parseFloat(l[i]));
		}
		return a;
	}
	,_i16a: function(v) {
		var l = StringTools.trim(StringTools.replace(v,"\n"," ")).split(" ");
		var a = [];
		var _g1 = 0;
		var _g = l.length;
		while(_g1 < _g) {
			var i = _g1++;
			a.push(Std.parseInt(l[i]));
		}
		return a;
	}
	,_i16ta: function(v,s) {
		var l = StringTools.trim(StringTools.replace(v,"\n"," ")).split(" ");
		var tl = "";
		var a = [];
		var bf;
		var k = 0;
		while(k < l.length) {
			bf = [];
			var _g = 0;
			while(_g < s) {
				var j = _g++;
				bf.push(Std.parseInt(l[k++]));
			}
			a.push(bf);
		}
		return a;
	}
	,__class__: haxor_io_file_ColladaFile
});
var haxor_io_file_ColladaAssetData = function() {
	this.axis = "y_up";
	this.unitValue = 0.0;
	this.unitName = "";
	this.modification = "";
	this.creation = "";
	this.source = "";
	this.tool = "";
	this.author = "";
};
$hxClasses["haxor.io.file.ColladaAssetData"] = haxor_io_file_ColladaAssetData;
haxor_io_file_ColladaAssetData.__name__ = ["haxor","io","file","ColladaAssetData"];
haxor_io_file_ColladaAssetData.prototype = {
	__class__: haxor_io_file_ColladaAssetData
};
var haxor_io_file_ColladaGeometry = function() {
	this.mesh = null;
	this.name = "";
	this.id = "";
};
$hxClasses["haxor.io.file.ColladaGeometry"] = haxor_io_file_ColladaGeometry;
haxor_io_file_ColladaGeometry.__name__ = ["haxor","io","file","ColladaGeometry"];
haxor_io_file_ColladaGeometry.prototype = {
	__class__: haxor_io_file_ColladaGeometry
};
var haxor_io_file_ColladaMesh = function() {
	this.primitives = null;
	this.type = "";
	this.primitives = [];
};
$hxClasses["haxor.io.file.ColladaMesh"] = haxor_io_file_ColladaMesh;
haxor_io_file_ColladaMesh.__name__ = ["haxor","io","file","ColladaMesh"];
haxor_io_file_ColladaMesh.prototype = {
	__class__: haxor_io_file_ColladaMesh
};
var haxor_io_file_ColladaPrimitive = function() {
	this.indexes = null;
	this.vcount = null;
	this.inputs = null;
	this.material = "";
	this.type = "";
	this.inputs = [];
	this.vcount = [];
	this.indexes = [];
	this.m_triangles = null;
};
$hxClasses["haxor.io.file.ColladaPrimitive"] = haxor_io_file_ColladaPrimitive;
haxor_io_file_ColladaPrimitive.__name__ = ["haxor","io","file","ColladaPrimitive"];
haxor_io_file_ColladaPrimitive.prototype = {
	get_triangles: function() {
		if(this.m_triangles != null) return this.m_triangles;
		this.m_triangles = haxor_io_file_ColladaFile.GenerateTriangles(this.type,this.indexes,this.vcount);
		return this.m_triangles;
	}
	,get_offset: function() {
		var mo = 0;
		var _g1 = 0;
		var _g = this.inputs.length;
		while(_g1 < _g) {
			var i = _g1++;
			mo = Math.max(mo,this.inputs[i].offset + 1);
		}
		return mo;
	}
	,GetInput: function(p_semantic,p_set) {
		if(p_set == null) p_set = -1;
		var _g1 = 0;
		var _g = this.inputs.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.inputs[i].semantic == p_semantic) {
				if(p_set < 0) return this.inputs[i]; else if(p_set == this.inputs[i].set) return this.inputs[i];
			}
		}
		return null;
	}
	,GetTriangulatedVectorArray: function(p_semantic,p_set,p_debug) {
		if(p_debug == null) p_debug = false;
		if(p_set == null) p_set = -1;
		var ci = this.GetInput(p_semantic,p_set);
		if(ci == null) return [];
		var vec = ci.GetVectorArray();
		var off = ci.offset;
		var res = [];
		if(vec.length <= 0) return [];
		if(off < 0) return [];
		var _g1 = 0;
		var _g = this.get_triangles().length;
		while(_g1 < _g) {
			var i = _g1++;
			var tuple = this.get_triangles()[i];
			var idx = tuple[off];
			res.push(vec[idx]);
		}
		return res;
	}
	,GetVectorArray: function(p_semantic,p_set) {
		if(p_set == null) p_set = -1;
		var res = [];
		var _g1 = 0;
		var _g = this.inputs.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.inputs[i].semantic == p_semantic) {
				if(p_set < 0) {
					res = this.inputs[i].GetVectorArray();
					break;
				} else if(p_set == this.inputs[i].set) {
					res = this.inputs[i].GetVectorArray();
					break;
				}
			}
		}
		if(p_semantic == "color") {
			if(p_set < 0) {
				var l = this.GetVectorArray("color",0);
				if(l.length > 0) {
					var len = Math.min(l.length,res.length);
					var _g2 = 0;
					while(_g2 < len) {
						var i1 = _g2++;
						res[i1].a = l[i1].r;
					}
				}
			}
		}
		return res;
	}
	,__class__: haxor_io_file_ColladaPrimitive
	,__properties__: {get_offset:"get_offset",get_triangles:"get_triangles"}
};
var haxor_io_file_ColladaInput = function() {
	this.stride = 0;
	this.values = null;
	this.set = -1;
	this.offset = 0;
	this.semantic = "";
	this.values = [];
};
$hxClasses["haxor.io.file.ColladaInput"] = haxor_io_file_ColladaInput;
haxor_io_file_ColladaInput.__name__ = ["haxor","io","file","ColladaInput"];
haxor_io_file_ColladaInput.prototype = {
	GetVectorArray: function() {
		if(this.stride <= 0) return [];
		var res = [];
		var i = 0;
		while(i < this.values.length) {
			var v = null;
			var _g = this.stride;
			switch(_g) {
			case 1:
				v = this.values[i];
				break;
			case 2:
				v = new haxor_math_Vector2(this.values[i],this.values[i + 1]);
				break;
			case 3:
				if(this.semantic == "color") v = new haxor_math_Color(this.values[i],this.values[i + 1],this.values[i + 2]); else v = new haxor_math_Vector3(this.values[i],this.values[i + 1],this.values[i + 2]);
				break;
			case 4:
				if(this.semantic == "color") v = new haxor_math_Color(this.values[i],this.values[i + 1],this.values[i + 2],this.values[i + 3]); else v = new haxor_math_Vector4(this.values[i],this.values[i + 1],this.values[i + 2],this.values[i + 3]);
				break;
			}
			if(v == null) continue;
			res.push(v);
			i += this.stride;
		}
		return res;
	}
	,__class__: haxor_io_file_ColladaInput
};
var haxor_io_file_ColladaImage = function() {
	this.data = null;
	this.depth = 0;
	this.height = 0;
	this.width = 0;
	this.source = "";
	this.format = "";
	this.name = "";
	this.id = "";
};
$hxClasses["haxor.io.file.ColladaImage"] = haxor_io_file_ColladaImage;
haxor_io_file_ColladaImage.__name__ = ["haxor","io","file","ColladaImage"];
haxor_io_file_ColladaImage.prototype = {
	__class__: haxor_io_file_ColladaImage
};
var haxor_io_file_ColladaController = function() {
	this.bones = null;
	this.weights = null;
	this.indexes = null;
	this.vcount = null;
	this.inputs = null;
	this.joints = null;
	this.binds = null;
	this.matrix = null;
	this.name = "";
	this.id = "";
	this.source = "";
	this.type = "";
	this.matrix = [];
	this.binds = [];
	this.inputs = [];
	this.joints = [];
	this.vcount = [];
	this.indexes = [];
};
$hxClasses["haxor.io.file.ColladaController"] = haxor_io_file_ColladaController;
haxor_io_file_ColladaController.__name__ = ["haxor","io","file","ColladaController"];
haxor_io_file_ColladaController.prototype = {
	get_offset: function() {
		var mo = 0;
		var _g1 = 0;
		var _g = this.inputs.length;
		while(_g1 < _g) {
			var i = _g1++;
			mo = Math.max(mo,this.inputs[i].offset + 1);
		}
		return mo;
	}
	,GetBSM: function() {
		var mtx = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		var _g1 = 0;
		var _g = this.matrix.length;
		while(_g1 < _g) {
			var i = _g1++;
			mtx.SetIndex(i,this.matrix[i]);
		}
		return mtx;
	}
	,GetJointIndex: function(p_joint) {
		var _g1 = 0;
		var _g = this.joints.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(p_joint == this.joints[i]) return i;
		}
		return -1;
	}
	,GetBinds: function() {
		var res = [];
		var _g1 = 0;
		var _g = this.binds.length;
		while(_g1 < _g) {
			var i = _g1++;
			var mtx = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
			var _g3 = 0;
			var _g2 = this.binds[i].length;
			while(_g3 < _g2) {
				var j = _g3++;
				mtx.SetIndex(j,this.binds[i][j]);
			}
			res.push(mtx);
		}
		return res;
	}
	,GetTriangulatedWeights: function(cp) {
		var v_off = cp.GetInput("vertex").offset;
		var res = [];
		var _g1 = 0;
		var _g = cp.get_triangles().length;
		while(_g1 < _g) {
			var i = _g1++;
			var idx = cp.get_triangles()[i][v_off];
			res.push(this.weights[idx]);
		}
		return res;
	}
	,GetTriangulatedBones: function(cp) {
		var v_off = cp.GetInput("vertex").offset;
		var res = [];
		var _g1 = 0;
		var _g = cp.get_triangles().length;
		while(_g1 < _g) {
			var i = _g1++;
			var idx = cp.get_triangles()[i][v_off];
			res.push(this.bones[idx]);
		}
		return res;
	}
	,GenerateBonesAndWeights: function() {
		this.weights = [];
		this.bones = [];
		var off = this.get_offset();
		var wi = null;
		var wo = 0;
		var bo = 0;
		var _g1 = 0;
		var _g = this.inputs.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.inputs[i].semantic == "weight") {
				wi = this.inputs[i];
				wo = wi.offset;
			}
			if(this.inputs[i].semantic == "joint") bo = this.inputs[i].offset;
		}
		var k = 0;
		var _g11 = 0;
		var _g2 = this.vcount.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			var n = this.vcount[i1];
			var wv4 = new haxor_math_Vector4();
			var bv4 = new haxor_math_Vector4();
			var _g21 = 0;
			while(_g21 < n) {
				var j = _g21++;
				var bi = this.indexes[k][bo];
				var wv = wi.values[this.indexes[k][wo]];
				if(j == 0) {
					wv4.x = wv;
					bv4.x = bi;
				} else if(j == 1) {
					wv4.y = wv;
					bv4.y = bi;
				} else if(j == 2) {
					wv4.z = wv;
					bv4.z = bi;
				} else if(j == 3) {
					wv4.w = wv;
					bv4.w = bi;
				}
				k++;
			}
			var sum = wv4.x + wv4.y + wv4.z + wv4.w;
			if(sum <= 0) sum = 0.0; else sum = 1.0 / sum;
			wv4.Scale(sum);
			this.weights.push(wv4);
			this.bones.push(bv4);
		}
	}
	,__class__: haxor_io_file_ColladaController
	,__properties__: {get_offset:"get_offset"}
};
var haxor_io_file_ColladaVisualScene = function() {
	this.children = null;
	this.name = "";
	this.id = "";
	this.type = "";
	this.children = [];
};
$hxClasses["haxor.io.file.ColladaVisualScene"] = haxor_io_file_ColladaVisualScene;
haxor_io_file_ColladaVisualScene.__name__ = ["haxor","io","file","ColladaVisualScene"];
haxor_io_file_ColladaVisualScene.prototype = {
	Traverse: function(p_callback) {
		var _g1 = 0;
		var _g = this.children.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.TraverseStep(this.children[i],p_callback);
		}
	}
	,TraverseStep: function(p_node,p_callback) {
		if(p_callback != null) p_callback(p_node);
		var _g1 = 0;
		var _g = p_node.children.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.TraverseStep(p_node.children[i],p_callback);
		}
	}
	,__class__: haxor_io_file_ColladaVisualScene
};
var haxor_io_file_ColladaNode = function() {
	this.instances = null;
	this.local = null;
	this.data = "";
	this.children = null;
	this.parent = null;
	this.scene = null;
	this.matrix = null;
	this.name = "";
	this.sid = "";
	this.id = "";
	this.type = "";
	this.children = [];
	this.instances = [];
	this.matrix = [1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1];
	this.position = new haxor_math_Vector3(0,0,0);
	this.rotation = new haxor_math_Quaternion(0,0,0,1.0);
	this.scale = new haxor_math_Vector3(1,1,1);
};
$hxClasses["haxor.io.file.ColladaNode"] = haxor_io_file_ColladaNode;
haxor_io_file_ColladaNode.__name__ = ["haxor","io","file","ColladaNode"];
haxor_io_file_ColladaNode.prototype = {
	get_world: function() {
		if(this.m_world != null) return this.m_world;
		this.m_world = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		var it = this;
		var h = [];
		while(it != null) {
			h.push(it);
			it = it.parent;
		}
		h.reverse();
		var _g1 = 0;
		var _g = h.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_world.MultiplyTransform(h[i].local);
		}
		return this.m_world;
	}
	,GenerateTranform: function() {
		var mtx = this.local = haxor_math_Matrix4.FromArray(this.matrix);
		this.position = new haxor_math_Matrix4(1,0,0,mtx.m03,0,1,0,mtx.m13,0,0,1,mtx.m23,0,0,0,1).GetColumn(3,null).get_xyz();
		this.rotation = haxor_math_Quaternion.FromMatrix4(haxor_context_EngineContext.data.get_m4().SetMatrix4(mtx).ToRotation());
		this.scale = mtx.get_scale().get_diagonalLR().get_xyz();
	}
	,__class__: haxor_io_file_ColladaNode
	,__properties__: {get_world:"get_world"}
};
var haxor_io_file_ColladaInstance = function() {
	this.target = "";
	this.type = "";
	this.materials = [];
};
$hxClasses["haxor.io.file.ColladaInstance"] = haxor_io_file_ColladaInstance;
haxor_io_file_ColladaInstance.__name__ = ["haxor","io","file","ColladaInstance"];
haxor_io_file_ColladaInstance.prototype = {
	__class__: haxor_io_file_ColladaInstance
};
var haxor_io_file_ColladaMaterial = function() {
	this.name = "";
	this.id = "";
};
$hxClasses["haxor.io.file.ColladaMaterial"] = haxor_io_file_ColladaMaterial;
haxor_io_file_ColladaMaterial.__name__ = ["haxor","io","file","ColladaMaterial"];
haxor_io_file_ColladaMaterial.prototype = {
	__class__: haxor_io_file_ColladaMaterial
};
var haxor_io_file_ColladaAnimation = function() {
	this.name = "";
	this.id = "";
	this.channels = [];
};
$hxClasses["haxor.io.file.ColladaAnimation"] = haxor_io_file_ColladaAnimation;
haxor_io_file_ColladaAnimation.__name__ = ["haxor","io","file","ColladaAnimation"];
haxor_io_file_ColladaAnimation.prototype = {
	__class__: haxor_io_file_ColladaAnimation
};
var haxor_io_file_ColladaAnimationChannel = function() {
	this.target = "";
	this.source = "";
	this.keyframes = [];
};
$hxClasses["haxor.io.file.ColladaAnimationChannel"] = haxor_io_file_ColladaAnimationChannel;
haxor_io_file_ColladaAnimationChannel.__name__ = ["haxor","io","file","ColladaAnimationChannel"];
haxor_io_file_ColladaAnimationChannel.prototype = {
	__class__: haxor_io_file_ColladaAnimationChannel
};
var haxor_io_file_ColladaAnimationKeyFrame = function() {
	this.time = 0.0;
	this.values = [];
};
$hxClasses["haxor.io.file.ColladaAnimationKeyFrame"] = haxor_io_file_ColladaAnimationKeyFrame;
haxor_io_file_ColladaAnimationKeyFrame.__name__ = ["haxor","io","file","ColladaAnimationKeyFrame"];
haxor_io_file_ColladaAnimationKeyFrame.prototype = {
	__class__: haxor_io_file_ColladaAnimationKeyFrame
};
var haxor_io_file_ColladaLight = function() {
	this.id = "";
	this.name = "";
	this.type = "";
	this.color = new haxor_math_Color(1,1,1,1);
	this.radius = 0.0;
	this.intensity = 0.0;
	this.atten = 0.0;
};
$hxClasses["haxor.io.file.ColladaLight"] = haxor_io_file_ColladaLight;
haxor_io_file_ColladaLight.__name__ = ["haxor","io","file","ColladaLight"];
haxor_io_file_ColladaLight.prototype = {
	__class__: haxor_io_file_ColladaLight
};
var haxor_io_file_MaterialFile = function(p_src) {
	this.mguid = "";
	this.mname = "";
	this.queue = "opaque";
	this.offset = 0;
	this.shader = "";
	this.ztest = true;
	this.zfunc = "lessequal";
	this.zwrite = true;
	this.blend = false;
	this.blendSrc = "one";
	this.blendDst = "zero";
	this.invert = false;
	this.lighting = false;
	this.grab = false;
	this.cull = "back";
	this.uniforms = [];
	haxor_io_file_AssetXML.call(this,"",p_src);
};
$hxClasses["haxor.io.file.MaterialFile"] = haxor_io_file_MaterialFile;
haxor_io_file_MaterialFile.__name__ = ["haxor","io","file","MaterialFile"];
haxor_io_file_MaterialFile.__super__ = haxor_io_file_AssetXML;
haxor_io_file_MaterialFile.prototype = $extend(haxor_io_file_AssetXML.prototype,{
	get_asset: function() {
		var m = new haxor_graphics_material_Material();
		m.set_name(this.mname);
		m.m_guid = this.mguid;
		var _g = this.queue;
		switch(_g) {
		case "background":
			m.queue = 0;
			break;
		case "opaque":
			m.queue = 1000;
			break;
		case "transparent":
			m.queue = 2000;
			break;
		case "overlay":
			m.queue = 3000;
			break;
		case "interface":
			m.queue = 4000;
			break;
		}
		m.queue += this.offset;
		m.set_shader(haxor_io_file_Asset.Get(this.shader));
		m.ztest = this.ztest;
		m.zfunc = 515;
		var _g1 = this.zfunc;
		switch(_g1) {
		case "never":
			m.zfunc = 512;
			break;
		case "always":
			m.zfunc = 519;
			break;
		case "notequal":
			m.zfunc = 517;
			break;
		case "equal":
			m.zfunc = 514;
			break;
		case "less":
			m.zfunc = 513;
			break;
		case "lessequal":
			m.zfunc = 515;
			break;
		case "greater":
			m.zfunc = 516;
			break;
		case "greaterequal":
			m.zfunc = 518;
			break;
		}
		m.zwrite = this.zwrite;
		m.blend = this.blend;
		m.blendSrc = this.BlendModeNameToEnum(this.blendSrc);
		m.blendDst = this.BlendModeNameToEnum(this.blendDst);
		m.invert = this.invert;
		m.lighting = this.lighting;
		m.grab = this.grab;
		var _g2 = this.cull;
		switch(_g2) {
		case "none":
			m.cull = 0;
			break;
		case "front":
			m.cull = 1;
			break;
		case "back":
			m.cull = 2;
			break;
		}
		var _g11 = 0;
		var _g3 = this.uniforms.length;
		while(_g11 < _g3) {
			var i = _g11++;
			var u = this.uniforms[i];
			var a = this.stof32a(u.value);
			var _g21 = u.type;
			switch(_g21) {
			case "int":
				m.SetInt(u.name,Std.parseInt(u.value));
				break;
			case "vec2":
				m.SetFloat2(u.name,a[0],a[1]);
				break;
			case "vec3":
				m.SetFloat3(u.name,a[0],a[1],a[2]);
				break;
			case "vec4":
				m.SetFloat4(u.name,a[0],a[1],a[2],a[3]);
				break;
			case "mat4":
				m.SetMatrix4(u.name,haxor_math_Matrix4.FromArray(a,haxor_context_EngineContext.data.get_m4()));
				break;
			case "color":
				m.SetFloat4(u.name,a[0],a[1],a[2],a[3]);
				break;
			case "texture":
				m.SetTexture(u.name,haxor_io_file_Asset.Get(u.value));
				break;
			}
		}
		return m;
	}
	,Parse: function(n) {
		var _g = n.get_nodeName();
		switch(_g) {
		case "material":
			this.guid = this._a(n,"guid","");
			this.set_name(this._a(n,"name",""));
			break;
		case "queue":
			this.offset = Std.parseInt(this._a(n,"offset","0"));
			this.queue = this._p(n,"$text","geometry",true,true);
			break;
		case "shader":
			this.shader = this._p(n,"$text","");
			break;
		case "ztest":
			this.ztest = this._p(n,"$text","true",true,true) == "true";
			break;
		case "zfunc":
			this.zfunc = this._p(n,"$text",this.zfunc);
			break;
		case "zwrite":
			this.zwrite = this._p(n,"$text","true",true,true) == "true";
			break;
		case "blend":
			this.blend = this._a(n,"enabled","false") == "true";
			this.blendSrc = this._p(n,"src.$text","one",true,true);
			this.blendDst = this._p(n,"dst.$text","zero",true,true);
			break;
		case "invert":
			this.invert = this._p(n,"$text","false",true,true) == "true";
			break;
		case "lighting":
			this.lighting = this._p(n,"$text","false",true,true) == "true";
			break;
		case "grab":
			this.grab = this._p(n,"$text","false",true,true) == "true";
			break;
		case "cull":
			this.cull = this._p(n,"$text",this.cull,true,true);
			break;
		case "uniforms":
			this.ParseUniforms(n);
			break;
		}
	}
	,ParseUniforms: function(n) {
		var it = n.elements();
		while(it.hasNext()) {
			n = it.next();
			var u = new haxor_io_file_MaterialFileUniform();
			u.type = n.get_nodeName().toLowerCase();
			u.name = this._a(n,"name","");
			u.value = this._p(n,"$text","",true);
			this.uniforms.push(u);
		}
	}
	,BlendModeNameToEnum: function(b) {
		switch(b) {
		case "zero":
			return 0;
		case "one":
			return 1;
		case "srccolor":
			return 768;
		case "oneminussrccolor":
			return 769;
		case "srcalpha":
			return 770;
		case "oneminussrcalpha":
			return 771;
		case "dstalpha":
			return 772;
		case "oneminusdstalpha":
			return 773;
		case "dstcolor":
			return 774;
		case "oneminusdstcolor":
			return 775;
		case "srcalphasaturate":
			return 776;
		}
		return 0;
	}
	,__class__: haxor_io_file_MaterialFile
});
var haxor_io_file_MaterialFileUniform = function() {
	this.type = "";
	this.name = "";
	this.value = "";
};
$hxClasses["haxor.io.file.MaterialFileUniform"] = haxor_io_file_MaterialFileUniform;
haxor_io_file_MaterialFileUniform.__name__ = ["haxor","io","file","MaterialFileUniform"];
haxor_io_file_MaterialFileUniform.prototype = {
	__class__: haxor_io_file_MaterialFileUniform
};
var haxor_math_AABB3 = function(p_x,p_y,p_z,p_width,p_height,p_depth) {
	if(p_depth == null) p_depth = 0;
	if(p_height == null) p_height = 0;
	if(p_width == null) p_width = 0;
	if(p_z == null) p_z = 0;
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.m_xMin = p_x;
	this.m_yMin = p_y;
	this.m_zMin = p_y;
	this.m_xMax = this.m_xMin + p_width;
	this.m_yMax = this.m_yMin + p_height;
	this.m_zMax = this.m_zMin + p_depth;
};
$hxClasses["haxor.math.AABB3"] = haxor_math_AABB3;
haxor_math_AABB3.__name__ = ["haxor","math","AABB3"];
haxor_math_AABB3.__properties__ = {get_empty:"get_empty",get_temp:"get_temp"}
haxor_math_AABB3.get_temp = function() {
	return haxor_context_EngineContext.data.get_aabb3();
};
haxor_math_AABB3.Center = function(p_b,p_result) {
	var v;
	if(p_result == null) v = new haxor_math_Vector3(0,0,0); else v = p_result;
	return v.Set(p_b.m_xMin + (p_b.m_xMax - p_b.m_xMin) * 0.5,p_b.m_yMin + (p_b.m_yMax - p_b.m_yMin) * 0.5,p_b.m_zMin + (p_b.m_zMax - p_b.m_zMin) * 0.5);
};
haxor_math_AABB3.FromMinMax = function(p_xmin,p_xmax,p_ymin,p_ymax,p_zmin,p_zmax,p_result) {
	var b;
	if(p_result == null) b = new haxor_math_AABB3(); else b = p_result;
	b.set_xMin(p_xmin);
	b.set_xMax(p_xmax);
	b.set_yMin(p_ymin);
	b.set_yMax(p_ymax);
	b.set_zMin(p_zmin);
	b.set_zMax(p_zmax);
	return b;
};
haxor_math_AABB3.FromCenter = function(p_x,p_y,p_z,p_width,p_height,p_depth,p_result) {
	var b;
	if(p_result == null) b = new haxor_math_AABB3(); else b = p_result;
	b.set_xMax(b.m_xMin + p_width);
	p_width;
	b.set_yMax(b.m_yMin + p_height);
	p_height;
	b.set_zMax(b.m_zMin + p_depth);
	p_depth;
	b.set_center(new haxor_math_Vector3(p_x,p_y,p_z));
	return b;
};
haxor_math_AABB3.get_empty = function() {
	return new haxor_math_AABB3();
};
haxor_math_AABB3.prototype = {
	get_clone: function() {
		return haxor_math_AABB3.FromMinMax(this.m_xMin,this.m_xMax,this.m_yMin,this.m_yMax,this.m_zMin,this.m_zMax);
	}
	,get_min: function() {
		return new haxor_math_Vector3(this.m_xMin,this.m_yMin);
	}
	,set_min: function(v) {
		this.set_xMin(v.x);
		this.set_yMin(v.y);
		return v;
	}
	,get_max: function() {
		return new haxor_math_Vector3(this.m_xMax,this.m_yMax);
	}
	,set_max: function(v) {
		this.set_xMax(v.x);
		this.set_yMax(v.y);
		return v;
	}
	,get_xMin: function() {
		return this.m_xMin;
	}
	,set_xMin: function(v) {
		this.m_xMin = v;
		this.Validate();
		return v;
	}
	,get_yMin: function() {
		return this.m_yMin;
	}
	,set_yMin: function(v) {
		this.m_yMin = v;
		this.Validate();
		return v;
	}
	,get_zMin: function() {
		return this.m_zMin;
	}
	,set_zMin: function(v) {
		this.m_zMin = v;
		this.Validate();
		return v;
	}
	,get_xMax: function() {
		return this.m_xMax;
	}
	,set_xMax: function(v) {
		this.m_xMax = v;
		this.Validate();
		return v;
	}
	,get_yMax: function() {
		return this.m_yMax;
	}
	,set_yMax: function(v) {
		this.m_yMax = v;
		this.Validate();
		return v;
	}
	,get_zMax: function() {
		return this.m_zMax;
	}
	,set_zMax: function(v) {
		this.m_zMax = v;
		this.Validate();
		return v;
	}
	,get_center: function() {
		return haxor_math_AABB3.Center(this);
	}
	,set_center: function(v) {
		var hw = haxor_math_Mathf.Abs(this.m_xMax - this.m_xMin) * 0.5;
		var hh = haxor_math_Mathf.Abs(this.m_yMax - this.m_yMin) * 0.5;
		var hd = haxor_math_Mathf.Abs(this.m_zMax - this.m_zMin) * 0.5;
		this.m_xMin = v.x - hw;
		this.m_xMax = v.x + hw;
		this.m_yMin = v.y - hh;
		this.m_yMax = v.y + hh;
		this.m_zMin = v.z - hd;
		this.m_zMax = v.z + hd;
		this.Validate();
		return v;
	}
	,get_x: function() {
		return this.m_xMin;
	}
	,set_x: function(v) {
		this.set_xMin(v);
		return v;
	}
	,get_y: function() {
		return this.m_yMin;
	}
	,set_y: function(v) {
		this.set_yMin(v);
		return v;
	}
	,get_z: function() {
		return this.m_zMin;
	}
	,set_z: function(v) {
		this.set_zMin(v);
		return v;
	}
	,get_width: function() {
		return haxor_math_Mathf.Abs(this.m_xMax - this.m_xMin);
	}
	,set_width: function(v) {
		this.set_xMax(this.m_xMin + v);
		return v;
	}
	,get_height: function() {
		return haxor_math_Mathf.Abs(this.m_yMax - this.m_yMin);
	}
	,set_height: function(v) {
		this.set_yMax(this.m_yMin + v);
		return v;
	}
	,get_depth: function() {
		return haxor_math_Mathf.Abs(this.m_zMax - this.m_zMin);
	}
	,set_depth: function(v) {
		this.set_zMax(this.m_zMin + v);
		return v;
	}
	,get_size: function() {
		return new haxor_math_Vector3(0,0,0).Set(haxor_math_Mathf.Abs(this.m_xMax - this.m_xMin),haxor_math_Mathf.Abs(this.m_yMax - this.m_yMin),haxor_math_Mathf.Abs(this.m_zMax - this.m_zMin));
	}
	,set_size: function(v) {
		this.set_width(v.x);
		this.set_height(v.y);
		this.set_depth(v.z);
		return v;
	}
	,Validate: function() {
		var x0 = this.m_xMin;
		var x1 = this.m_xMax;
		var y0 = this.m_yMin;
		var y1 = this.m_yMax;
		var z0 = this.m_zMin;
		var z1 = this.m_zMax;
		if(x0 <= x1) {
			this.m_xMin = x0;
			this.m_xMax = x1;
		} else {
			this.m_xMin = x1;
			this.m_xMax = x0;
		}
		if(y0 <= y1) {
			this.m_yMin = y0;
			this.m_yMax = y1;
		} else {
			this.m_yMin = y1;
			this.m_yMax = y0;
		}
		if(z0 <= z1) {
			this.m_zMin = z0;
			this.m_zMax = z1;
		} else {
			this.m_zMin = z1;
			this.m_zMax = z0;
		}
	}
	,Add: function(p_v) {
		this.m_xMax = Math.max(p_v.m_xMax,this.m_xMax);
		this.m_xMin = Math.min(p_v.m_xMin,this.m_xMin);
		this.m_yMax = Math.max(p_v.m_yMax,this.m_yMax);
		this.m_yMin = Math.min(p_v.m_yMin,this.m_yMin);
		this.m_zMax = Math.max(p_v.m_zMax,this.m_zMax);
		this.m_zMin = Math.min(p_v.m_zMin,this.m_zMin);
		return this;
	}
	,Set: function(p_xmin,p_xmax,p_ymin,p_ymax,p_zmin,p_zmax) {
		this.m_xMin = p_xmin;
		this.m_yMin = p_ymin;
		this.m_zMin = p_zmin;
		this.m_xMax = p_xmax;
		this.m_yMax = p_ymax;
		this.m_zMax = p_zmax;
		this.Validate();
		return this;
	}
	,SetAABB3: function(p_v) {
		this.m_xMin = p_v.m_xMin;
		this.m_yMin = p_v.m_yMin;
		this.m_zMin = p_v.m_zMin;
		this.m_xMax = p_v.m_xMax;
		this.m_yMax = p_v.m_yMax;
		this.m_zMax = p_v.m_zMax;
		return this;
	}
	,SetXYZWHD: function(p_x,p_y,p_z,p_width,p_height,p_depth) {
		if(p_depth == null) p_depth = 0;
		if(p_height == null) p_height = 0;
		if(p_width == null) p_width = 0;
		if(p_z == null) p_z = 0;
		if(p_y == null) p_y = 0;
		if(p_x == null) p_x = 0;
		this.m_xMin = p_x;
		this.m_yMin = p_y;
		this.m_zMin = p_y;
		this.m_xMax = this.m_xMin + p_width;
		this.m_yMax = this.m_yMin + p_height;
		this.m_zMax = this.m_zMin + p_depth;
		return this;
	}
	,Encapsulate: function(p_point) {
		return this.Encapsulate3(p_point.x,p_point.y,p_point.z);
	}
	,Encapsulate3: function(p_x,p_y,p_z) {
		if(p_z == null) p_z = 0;
		if(p_y == null) p_y = 0;
		if(p_x == null) p_x = 0;
		this.m_xMin = Math.min(p_x,this.m_xMin);
		this.m_xMax = Math.max(p_x,this.m_xMax);
		this.m_yMin = Math.min(p_y,this.m_yMin);
		this.m_yMax = Math.max(p_y,this.m_yMax);
		this.m_zMin = Math.min(p_z,this.m_zMin);
		this.m_zMax = Math.max(p_z,this.m_zMax);
		this.Validate();
		return this;
	}
	,ToString: function(p_places) {
		if(p_places == null) p_places = 2;
		var s0 = haxor_math_Mathf.RoundPlaces(this.m_xMin,p_places) + "";
		var s1 = haxor_math_Mathf.RoundPlaces(this.m_xMax,p_places) + "";
		var s2 = haxor_math_Mathf.RoundPlaces(this.m_yMin,p_places) + "";
		var s3 = haxor_math_Mathf.RoundPlaces(this.m_yMax,p_places) + "";
		var s4 = haxor_math_Mathf.RoundPlaces(this.m_zMin,p_places) + "";
		var s5 = haxor_math_Mathf.RoundPlaces(this.m_zMax,p_places) + "";
		return "[" + s0 + "," + s1 + "|" + s2 + "," + s3 + "|" + s4 + "," + s5 + "]";
	}
	,__class__: haxor_math_AABB3
	,__properties__: {set_size:"set_size",get_size:"get_size",set_depth:"set_depth",get_depth:"get_depth",set_height:"set_height",get_height:"get_height",set_width:"set_width",get_width:"get_width",set_z:"set_z",get_z:"get_z",set_y:"set_y",get_y:"get_y",set_x:"set_x",get_x:"get_x",set_center:"set_center",get_center:"get_center",set_zMax:"set_zMax",get_zMax:"get_zMax",set_yMax:"set_yMax",get_yMax:"get_yMax",set_xMax:"set_xMax",get_xMax:"get_xMax",set_zMin:"set_zMin",get_zMin:"get_zMin",set_yMin:"set_yMin",get_yMin:"get_yMin",set_xMin:"set_xMin",get_xMin:"get_xMin",set_max:"set_max",get_max:"get_max",set_min:"set_min",get_min:"get_min",get_clone:"get_clone"}
};
var haxor_math_Mathf = function() { };
$hxClasses["haxor.math.Mathf"] = haxor_math_Mathf;
haxor_math_Mathf.__name__ = ["haxor","math","Mathf"];
haxor_math_Mathf.IsPOT = function(p_v) {
	return p_v > 0 && (p_v & p_v - 1) == 0;
};
haxor_math_Mathf.NextPOT = function(p_v) {
	--p_v;
	p_v |= p_v >> 1;
	p_v |= p_v >> 2;
	p_v |= p_v >> 4;
	p_v |= p_v >> 8;
	p_v |= p_v >> 16;
	return ++p_v;
};
haxor_math_Mathf.Sign = function(p_a) {
	if(p_a < 0) return -1.0; else return 1.0;
};
haxor_math_Mathf.SignInt = function(p_a) {
	if(p_a < 0) return -1; else return 1;
};
haxor_math_Mathf.Abs = function(p_a) {
	if(p_a < 0) return -p_a; else return p_a;
};
haxor_math_Mathf.AbsInt = function(p_a) {
	if(p_a < 0) return -p_a; else return p_a;
};
haxor_math_Mathf.Clamp = function(p_v,p_min,p_max) {
	if(p_v <= p_min) return p_min; else if(p_v >= p_max) return p_max; else return p_v;
};
haxor_math_Mathf.Clamp01 = function(p_v) {
	if(p_v <= 0.0) return 0.0; else if(p_v >= 1.0) return 1.0; else return p_v;
};
haxor_math_Mathf.ClampInt = function(p_v,p_min,p_max) {
	return (p_v <= p_min?p_min:p_v >= p_max?p_max:p_v) | 0;
};
haxor_math_Mathf.Min = function(a,b) {
	return Math.min(a,b);
};
haxor_math_Mathf.MinRange = function(v) {
	if(v.length <= 0) return 0.0;
	var n = v[0];
	var _g1 = 1;
	var _g = v.length;
	while(_g1 < _g) {
		var i = _g1++;
		n = Math.min(n,v[i]);
	}
	return n;
};
haxor_math_Mathf.Max = function(a,b) {
	return Math.max(a,b);
};
haxor_math_Mathf.MaxRange = function(v) {
	if(v.length <= 0) return 0.0;
	var n = v[0];
	var _g1 = 1;
	var _g = v.length;
	while(_g1 < _g) {
		var i = _g1++;
		n = Math.max(n,v[i]);
	}
	return n;
};
haxor_math_Mathf.MinInt = function(a,b) {
	return Math.min(a,b);
};
haxor_math_Mathf.MaxInt = function(a,b) {
	return Math.max(a,b);
};
haxor_math_Mathf.Sin = function(v) {
	return Math.sin(v);
};
haxor_math_Mathf.Cos = function(v) {
	return Math.cos(v);
};
haxor_math_Mathf.Asin = function(v) {
	return Math.asin(v);
};
haxor_math_Mathf.Acos = function(v) {
	return Math.acos(v);
};
haxor_math_Mathf.Tan = function(v) {
	return Math.tan(v);
};
haxor_math_Mathf.ATan = function(v) {
	return Math.atan(v);
};
haxor_math_Mathf.ATan2 = function(y,x) {
	return Math.atan2(y,x);
};
haxor_math_Mathf.Sqrt = function(v) {
	return Math.sqrt(v);
};
haxor_math_Mathf.Pow = function(b,exp) {
	return Math.pow(b,exp);
};
haxor_math_Mathf.Floor = function(p_v) {
	return p_v | 0;
};
haxor_math_Mathf.Ceil = function(p_v) {
	return p_v + (p_v < 0?-0.9999999:0.9999999) | 0;
};
haxor_math_Mathf.Round = function(p_v) {
	return p_v + (p_v < 0?-0.5:0.5) | 0;
};
haxor_math_Mathf.RoundPlaces = function(p_v,p_decimal_places) {
	if(p_decimal_places == null) p_decimal_places = 2;
	var d = Math.pow(10,p_decimal_places);
	return haxor_math_Mathf.Round(p_v * d) / d;
};
haxor_math_Mathf.Lerp = function(p_a,p_b,p_ratio) {
	return p_a + (p_b - p_a) * p_ratio;
};
haxor_math_Mathf.LerpInt = function(p_a,p_b,p_ratio) {
	return Std["int"](haxor_math_Mathf.Lerp(p_a,p_b,p_ratio));
};
haxor_math_Mathf.Frac = function(p_v) {
	return p_v - Math.floor(p_v);
};
haxor_math_Mathf.Loop = function(p_v,p_v0,p_v1) {
	var vv0 = Math.min(p_v0,p_v1);
	var vv1 = Math.max(p_v0,p_v1);
	var dv = vv1 - vv0;
	if(dv <= 0) return vv0;
	var n = (p_v - p_v0) / dv;
	var r;
	if(p_v < 0) r = 1.0 - haxor_math_Mathf.Frac(n < 0?-n:n); else r = n - Math.floor(n);
	return p_v0 + (p_v1 - p_v0) * r;
};
haxor_math_Mathf.Linear2Gamma = function(p_v) {
	return Math.pow(p_v,2.2);
};
haxor_math_Mathf.Oscilate = function(p_v,p_v0,p_v1) {
	var w = -haxor_math_Mathf.Abs(haxor_math_Mathf.Loop(p_v - 1.0,-1.0,1.0)) + 1.0;
	return w + (p_v0 - w) * p_v1;
};
haxor_math_Mathf.WrapAngle = function(p_angle) {
	if(p_angle < -360.0) return 360 + p_angle;
	if(p_angle > 360.0) return p_angle - 360;
	return p_angle;
};
var haxor_math_Matrix4 = function(p_m00,p_m01,p_m02,p_m03,p_m10,p_m11,p_m12,p_m13,p_m20,p_m21,p_m22,p_m23,p_m30,p_m31,p_m32,p_m33) {
	if(p_m33 == null) p_m33 = 0;
	if(p_m32 == null) p_m32 = 0;
	if(p_m31 == null) p_m31 = 0;
	if(p_m30 == null) p_m30 = 0;
	if(p_m23 == null) p_m23 = 0;
	if(p_m22 == null) p_m22 = 0;
	if(p_m21 == null) p_m21 = 0;
	if(p_m20 == null) p_m20 = 0;
	if(p_m13 == null) p_m13 = 0;
	if(p_m12 == null) p_m12 = 0;
	if(p_m11 == null) p_m11 = 0;
	if(p_m10 == null) p_m10 = 0;
	if(p_m03 == null) p_m03 = 0;
	if(p_m02 == null) p_m02 = 0;
	if(p_m01 == null) p_m01 = 0;
	if(p_m00 == null) p_m00 = 0;
	this.m00 = p_m00;
	this.m01 = p_m01;
	this.m02 = p_m02;
	this.m03 = p_m03;
	this.m10 = p_m10;
	this.m11 = p_m11;
	this.m12 = p_m12;
	this.m13 = p_m13;
	this.m20 = p_m20;
	this.m21 = p_m21;
	this.m22 = p_m22;
	this.m23 = p_m23;
	this.m30 = p_m30;
	this.m31 = p_m31;
	this.m32 = p_m32;
	this.m33 = p_m33;
};
$hxClasses["haxor.math.Matrix4"] = haxor_math_Matrix4;
haxor_math_Matrix4.__name__ = ["haxor","math","Matrix4"];
haxor_math_Matrix4.__properties__ = {get_identity:"get_identity",get_temp:"get_temp"}
haxor_math_Matrix4.get_temp = function() {
	return haxor_context_EngineContext.data.get_m4();
};
haxor_math_Matrix4.get_identity = function() {
	return new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
};
haxor_math_Matrix4.FromQuaternion = function(p_quaternion,p_result) {
	var m;
	if(p_result == null) m = new haxor_math_Matrix4(); else m = p_result;
	var q = p_quaternion;
	var x2 = q.x * q.x;
	var y2 = q.y * q.y;
	var z2 = q.z * q.z;
	var xy = q.x * q.y;
	var xz = q.x * q.z;
	var yz = q.y * q.z;
	var xw = q.w * q.x;
	var yw = q.w * q.y;
	var zw = q.w * q.z;
	m.m00 = 1.0 - 2.0 * (y2 + z2);
	m.m01 = 2.0 * (xy - zw);
	m.m02 = 2.0 * (xz + yw);
	m.m10 = 2.0 * (xy + zw);
	m.m11 = 1.0 - 2.0 * (x2 + z2);
	m.m12 = 2.0 * (yz - xw);
	m.m20 = 2.0 * (xz - yw);
	m.m21 = 2.0 * (yz + xw);
	m.m22 = 1.0 - 2.0 * (x2 + y2);
	m.m30 = m.m31 = m.m32 = 0.0;
	m.m33 = 1.0;
	return m;
};
haxor_math_Matrix4.FromArray = function(p_array,p_result) {
	var res;
	if(p_result == null) res = new haxor_math_Matrix4(); else res = p_result;
	var _g1 = 0;
	var _g = p_array.length;
	while(_g1 < _g) {
		var i = _g1++;
		res.SetIndex(i,p_array[i]);
	}
	return res;
};
haxor_math_Matrix4.TRS = function(p_position,p_rotation,p_scale,p_result) {
	var sx;
	if(p_scale == null) sx = 1.0; else sx = p_scale.x;
	var sy;
	if(p_scale == null) sy = 1.0; else sy = p_scale.y;
	var sz;
	if(p_scale == null) sz = 1.0; else sz = p_scale.z;
	var px = p_position.x;
	var py = p_position.y;
	var pz = p_position.z;
	var r = haxor_context_EngineContext.data.get_m4();
	haxor_math_Matrix4.FromQuaternion(p_rotation,r);
	var l;
	if(p_result == null) l = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1); else l = p_result;
	l.m00 = r.m00 * sx;
	l.m01 = r.m01 * sy;
	l.m02 = r.m02 * sz;
	l.m03 = px;
	l.m10 = r.m10 * sx;
	l.m11 = r.m11 * sy;
	l.m12 = r.m12 * sz;
	l.m13 = py;
	l.m20 = r.m20 * sx;
	l.m21 = r.m21 * sy;
	l.m22 = r.m22 * sz;
	l.m23 = pz;
	l.m30 = l.m31 = l.m32 = 0.0;
	l.m33 = 1.0;
	return l;
};
haxor_math_Matrix4.Frustum = function(p_left,p_right,p_top,p_bottom,p_near,p_far,p_result) {
	var m;
	if(p_result == null) m = new haxor_math_Matrix4(); else m = p_result;
	var n2 = p_near * 2.0;
	var rml = 1.0 / (p_right - p_left);
	var tmb = 1.0 / (p_top - p_bottom);
	var fmn = 1.0 / (p_far - p_near);
	m.m00 = n2 * rml;
	m.m01 = 0.0;
	m.m02 = (p_right + p_left) * rml;
	m.m03 = 0.0;
	m.m10 = 0.0;
	m.m11 = n2 * tmb;
	m.m12 = (p_top + p_bottom) * tmb;
	m.m13 = 0.0;
	m.m20 = 0.0;
	m.m21 = 0.0;
	m.m22 = -(p_near + p_far) * fmn;
	m.m23 = -n2 * p_far * fmn;
	m.m30 = 0.0;
	m.m31 = 0.0;
	m.m32 = -1.0;
	m.m33 = 0;
	return m;
};
haxor_math_Matrix4.FrustumInverse = function(p_left,p_right,p_top,p_bottom,p_near,p_far,p_result) {
	var m;
	if(p_result == null) m = new haxor_math_Matrix4(); else m = p_result;
	var n2 = p_near * 2.0;
	var rml = p_right - p_left;
	var tmb = p_top - p_bottom;
	var fmn = p_far - p_near;
	m.m00 = rml / n2;
	m.m01 = 0.0;
	m.m02 = 0.0;
	m.m03 = (p_right + p_left) / n2;
	m.m10 = 0.0;
	m.m11 = tmb / n2;
	m.m12 = 0.0;
	m.m13 = (p_top + p_bottom) / n2;
	m.m20 = 0.0;
	m.m21 = 0.0;
	m.m22 = 0.0;
	m.m23 = -1.0;
	m.m30 = 0.0;
	m.m31 = 0.0;
	m.m32 = fmn / (-n2 * p_far);
	m.m33 = (p_far + p_near) / (n2 * p_far);
	return m;
};
haxor_math_Matrix4.Ortho = function(p_left,p_right,p_top,p_bottom,p_near,p_far,p_result) {
	var m;
	if(p_result == null) m = new haxor_math_Matrix4(); else m = p_result;
	var n2 = p_near * 2.0;
	var rml = 1.0 / (p_right - p_left);
	var tmb = 1.0 / (p_top - p_bottom);
	var fmn = 1.0 / (p_far - p_near);
	m.m00 = 2.0 * rml;
	m.m01 = 0.0;
	m.m02 = 0.0;
	m.m03 = -(p_right + p_left) * rml;
	m.m10 = 0.0;
	m.m11 = 2.0 * tmb;
	m.m12 = 0.0;
	m.m13 = -(p_top + p_bottom) * tmb;
	m.m20 = 0.0;
	m.m21 = 0.0;
	m.m22 = -2. * fmn;
	m.m23 = -(p_far + p_near) * fmn;
	m.m30 = 0.0;
	m.m31 = 0.0;
	m.m32 = 0.0;
	m.m33 = 1.0;
	return m;
};
haxor_math_Matrix4.OrthoInverse = function(p_left,p_right,p_top,p_bottom,p_near,p_far,p_result) {
	var m = haxor_context_EngineContext.data.get_m4().SetOrtho(p_left,p_right,p_top,p_bottom,p_near,p_far);
	return haxor_math_Matrix4.GetInverseTransform(m,p_result);
};
haxor_math_Matrix4.Perspective = function(p_fov,p_aspect,p_near,p_far,p_result) {
	var t = Math.tan(p_fov * 0.5 * 0.01745329251994329576923690768489) * p_near;
	var b = -t;
	var l = p_aspect * b;
	var r = p_aspect * t;
	return haxor_math_Matrix4.Frustum(l,r,t,b,p_near,p_far,p_result);
};
haxor_math_Matrix4.PerspectiveInverse = function(p_fov,p_aspect,p_near,p_far,p_result) {
	var t = Math.tan(p_fov * 0.5 * 0.01745329251994329576923690768489) * p_near;
	var b = -t;
	var l = p_aspect * b;
	var r = p_aspect * t;
	return haxor_math_Matrix4.FrustumInverse(l,r,t,b,p_near,p_far,p_result);
};
haxor_math_Matrix4.GetRotation = function(p_matrix4,p_result) {
	var m;
	if(p_result == null) m = new haxor_math_Matrix4(); else m = p_result;
	var tmp = haxor_context_EngineContext.data.get_v3();
	tmp.Set(m.m00,m.m01,m.m02).Normalize();
	m.m00 = tmp.x;
	m.m01 = tmp.y;
	m.m02 = tmp.z;
	m.m03 = 0.0;
	tmp.Set(m.m10,m.m11,m.m12).Normalize();
	m.m10 = tmp.x;
	m.m11 = tmp.y;
	m.m12 = tmp.z;
	m.m13 = 0.0;
	tmp.Set(m.m20,m.m21,m.m22).Normalize();
	m.m20 = tmp.x;
	m.m21 = tmp.y;
	m.m22 = tmp.z;
	m.m23 = 0.0;
	m.m30 = m.m31 = m.m32 = 0.0;
	m.m33 = 1.0;
	return m;
};
haxor_math_Matrix4.GetInverseTransform = function(p_matrix,p_result) {
	var result;
	if(p_result == null) result = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1); else result = p_result;
	var m = p_matrix;
	var l0x = m.m00;
	var l0y = m.m01;
	var l0z = m.m02;
	var l0w = m.m03;
	var l1x = m.m10;
	var l1y = m.m11;
	var l1z = m.m12;
	var l1w = m.m13;
	var l2x = m.m20;
	var l2y = m.m21;
	var l2z = m.m22;
	var l2w = m.m23;
	var vl0 = Math.sqrt(l0x * l0x + l1x * l1x + l2x * l2x);
	var vl1 = Math.sqrt(l0y * l0y + l1y * l1y + l2y * l2y);
	var vl2 = Math.sqrt(l0z * l0z + l1z * l1z + l2z * l2z);
	var sx;
	if((vl0 < 0?-vl0:vl0) <= 0.0001) sx = 0.0; else sx = 1.0 / vl0;
	var sy;
	if((vl1 < 0?-vl1:vl1) <= 0.0001) sy = 0.0; else sy = 1.0 / vl1;
	var sz;
	if((vl2 < 0?-vl2:vl2) <= 0.0001) sz = 0.0; else sz = 1.0 / vl2;
	l0x *= sx;
	l0y *= sy;
	l0z *= sz;
	l1x *= sx;
	l1y *= sy;
	l1z *= sz;
	l2x *= sx;
	l2y *= sy;
	l2z *= sz;
	result.Set(sx * l0x,sx * l1x,sx * l2x,sx * (l0x * -l0w + l1x * -l1w + l2x * -l2w),sy * l0y,sy * l1y,sy * l2y,sy * (l0y * -l0w + l1y * -l1w + l2y * -l2w),sz * l0z,sz * l1z,sz * l2z,sz * (l0z * -l0w + l1z * -l1w + l2z * -l2w),0,0,0,1);
	return result;
};
haxor_math_Matrix4.LookRotation = function(p_forward,p_up,p_result) {
	return haxor_math_Matrix4.LookAt(haxor_context_EngineContext.data.get_v3().Set(0,0,0),p_forward,p_up,p_result);
};
haxor_math_Matrix4.LookAt = function(p_eye,p_at,p_up,p_result) {
	if(p_result == null) p_result = new haxor_math_Matrix4(); else p_result = p_result;
	if(p_up == null) p_up = haxor_context_EngineContext.data.get_v3().Set(0,1,0); else p_up = p_up;
	var f = haxor_context_EngineContext.data.get_v3().Set3(p_at).Sub(p_eye).Normalize();
	var s = haxor_math_Vector3.Cross(f,p_up,haxor_context_EngineContext.data.get_v3()).Normalize();
	var u = haxor_math_Vector3.Cross(s,f,haxor_context_EngineContext.data.get_v3());
	p_result.m00 = s.x;
	p_result.m10 = s.y;
	p_result.m20 = s.z;
	p_result.m01 = u.x;
	p_result.m11 = u.y;
	p_result.m21 = u.z;
	p_result.m02 = -f.x;
	p_result.m12 = -f.y;
	p_result.m22 = -f.z;
	p_result.m03 = -(s.x * p_eye.x + s.y * p_eye.y + s.z * p_eye.z);
	p_result.m13 = -(u.x * p_eye.x + u.y * p_eye.y + u.z * p_eye.z);
	p_result.m23 = f.x * p_eye.x + f.y * p_eye.y + f.z * p_eye.z;
	p_result.m30 = p_result.m31 = p_result.m32 = 0.0;
	p_result.m33 = 1.0;
	return p_result;
};
haxor_math_Matrix4.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	var res = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	var _g1 = 0;
	var _g = tk.length;
	while(_g1 < _g) {
		var i = _g1++;
		var n = Std.parseFloat(StringTools.trim(tk[i]));
		res.SetIndex(i,n);
	}
	return res;
};
haxor_math_Matrix4.prototype = {
	get_clone: function() {
		return new haxor_math_Matrix4(this.m00,this.m01,this.m02,this.m03,this.m10,this.m11,this.m12,this.m13,this.m20,this.m21,this.m22,this.m23,this.m30,this.m31,this.m32,this.m33);
	}
	,get_quaternion: function() {
		return haxor_math_Quaternion.FromMatrix4(haxor_context_EngineContext.data.get_m4().SetMatrix4(this).ToRotation());
	}
	,set_quaternion: function(v) {
		haxor_math_Matrix4.FromQuaternion(v,this);
		return v;
	}
	,get_trace: function() {
		return this.m00 + this.m11 + this.m22 + this.m33;
	}
	,get_rotation: function() {
		return new haxor_math_Matrix4(this.m00,this.m01,this.m02,this.m03,this.m10,this.m11,this.m12,this.m13,this.m20,this.m21,this.m22,this.m23,this.m30,this.m31,this.m32,this.m33).ToRotation();
	}
	,get_scale: function() {
		var d0 = Math.sqrt(this.m00 * this.m00 + this.m10 * this.m10 + this.m20 * this.m20);
		var d1 = Math.sqrt(this.m01 * this.m01 + this.m11 * this.m11 + this.m21 * this.m21);
		var d2 = Math.sqrt(this.m02 * this.m02 + this.m12 * this.m12 + this.m22 * this.m22);
		return new haxor_math_Matrix4(d0,0,0,0,0,d1,0,0,0,0,d2,0,0,0,0,1);
	}
	,get_translation: function() {
		return new haxor_math_Matrix4(1,0,0,this.m03,0,1,0,this.m13,0,0,1,this.m23,0,0,0,1);
	}
	,get_inverseTransform: function() {
		var result = new haxor_math_Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		var l0 = new haxor_math_Vector3(this.m00,this.m01,this.m02);
		var l1 = new haxor_math_Vector3(this.m10,this.m11,this.m12);
		var l2 = new haxor_math_Vector3(this.m20,this.m21,this.m22);
		var vl0 = Math.sqrt(l0.x * l0.x + l0.y * l0.y + l0.z * l0.z);
		var vl1 = Math.sqrt(l1.x * l1.x + l1.y * l1.y + l1.z * l1.z);
		var vl2 = Math.sqrt(l2.x * l2.x + l2.y * l2.y + l2.z * l2.z);
		var sx;
		if((vl0 < 0?-vl0:vl0) <= 0.0001) sx = 0.0; else sx = 1.0 / vl0;
		var sy;
		if((vl1 < 0?-vl1:vl1) <= 0.0001) sy = 0.0; else sy = 1.0 / vl1;
		var sz;
		if((vl2 < 0?-vl2:vl2) <= 0.0001) sz = 0.0; else sz = 1.0 / vl2;
		l0.x *= sx;
		l0.y *= sx;
		l0.z *= sx;
		l1.x *= sy;
		l1.y *= sy;
		l1.z *= sy;
		l2.x *= sz;
		l2.y *= sz;
		l2.z *= sz;
		result.Set(sx * l0.x,sx * l1.x,sx * l2.x,sx * (l0.x * -this.m03 + l1.x * -this.m13 + l2.x * -this.m23),sy * l0.y,sy * l1.y,sy * l2.y,sy * (l0.y * -this.m03 + l1.y * -this.m13 + l2.y * -this.m23),sz * l0.z,sz * l1.z,sz * l2.z,sz * (l0.z * -this.m03 + l1.z * -this.m13 + l2.z * -this.m23),0,0,0,1);
		return result;
	}
	,get_transposed: function() {
		return new haxor_math_Matrix4(this.m00,this.m10,this.m20,this.m30,this.m01,this.m11,this.m21,this.m31,this.m02,this.m12,this.m22,this.m32,this.m03,this.m13,this.m23,this.m33);
	}
	,ToRowMajor: function() {
		return [this.m00,this.m01,this.m02,this.m03,this.m10,this.m11,this.m12,this.m13,this.m20,this.m21,this.m22,this.m23,this.m30,this.m31,this.m32,this.m33];
	}
	,ToColumnMajor: function() {
		return [this.m00,this.m10,this.m20,this.m30,this.m01,this.m11,this.m21,this.m31,this.m02,this.m12,this.m22,this.m32,this.m03,this.m13,this.m23,this.m33];
	}
	,GetLine: function(p_index,p_result) {
		if(p_result == null) p_result = new haxor_math_Vector4(); else p_result = p_result;
		return p_result.Set(this.GetRowCol(p_index,0),this.GetRowCol(p_index,1),this.GetRowCol(p_index,2),this.GetRowCol(p_index,3));
	}
	,SetLine: function(p_index,p_x,p_y,p_z,p_w) {
		switch(p_index) {
		case 0:
			this.m00 = p_x;
			this.m01 = p_y;
			this.m02 = p_z;
			this.m03 = p_w;
			break;
		case 1:
			this.m10 = p_x;
			this.m11 = p_y;
			this.m12 = p_z;
			this.m13 = p_w;
			break;
		case 2:
			this.m20 = p_x;
			this.m21 = p_y;
			this.m22 = p_z;
			this.m23 = p_w;
			break;
		case 3:
			this.m30 = p_x;
			this.m31 = p_y;
			this.m32 = p_z;
			this.m33 = p_w;
			break;
		}
	}
	,GetColumn: function(p_index,p_result) {
		if(p_result == null) p_result = new haxor_math_Vector4(); else p_result = p_result;
		return p_result.Set(this.GetRowCol(0,p_index),this.GetRowCol(1,p_index),this.GetRowCol(2,p_index),this.GetRowCol(3,p_index));
	}
	,SetColumn: function(p_index,p_x,p_y,p_z,p_w) {
		switch(p_index) {
		case 0:
			this.m00 = p_x;
			this.m10 = p_y;
			this.m20 = p_z;
			this.m30 = p_w;
			break;
		case 1:
			this.m01 = p_x;
			this.m11 = p_y;
			this.m21 = p_z;
			this.m31 = p_w;
			break;
		case 2:
			this.m02 = p_x;
			this.m12 = p_y;
			this.m22 = p_z;
			this.m32 = p_w;
			break;
		case 3:
			this.m03 = p_x;
			this.m13 = p_y;
			this.m23 = p_z;
			this.m33 = p_w;
			break;
		}
	}
	,get_diagonalLR: function() {
		return new haxor_math_Vector4(this.m00,this.m11,this.m22,this.m33);
	}
	,set_diagonalLR: function(v) {
		this.m00 = v.x;
		this.m11 = v.y;
		this.m22 = v.z;
		this.m33 = v.w;
		return v;
	}
	,SetIdentity: function() {
		return this.Set(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	}
	,Set: function(p_m00,p_m01,p_m02,p_m03,p_m10,p_m11,p_m12,p_m13,p_m20,p_m21,p_m22,p_m23,p_m30,p_m31,p_m32,p_m33) {
		if(p_m33 == null) p_m33 = 0;
		if(p_m32 == null) p_m32 = 0;
		if(p_m31 == null) p_m31 = 0;
		if(p_m30 == null) p_m30 = 0;
		if(p_m23 == null) p_m23 = 0;
		if(p_m22 == null) p_m22 = 0;
		if(p_m21 == null) p_m21 = 0;
		if(p_m20 == null) p_m20 = 0;
		if(p_m13 == null) p_m13 = 0;
		if(p_m12 == null) p_m12 = 0;
		if(p_m11 == null) p_m11 = 0;
		if(p_m10 == null) p_m10 = 0;
		if(p_m03 == null) p_m03 = 0;
		if(p_m02 == null) p_m02 = 0;
		if(p_m01 == null) p_m01 = 0;
		if(p_m00 == null) p_m00 = 0;
		this.m00 = p_m00;
		this.m01 = p_m01;
		this.m02 = p_m02;
		this.m03 = p_m03;
		this.m10 = p_m10;
		this.m11 = p_m11;
		this.m12 = p_m12;
		this.m13 = p_m13;
		this.m20 = p_m20;
		this.m21 = p_m21;
		this.m22 = p_m22;
		this.m23 = p_m23;
		this.m30 = p_m30;
		this.m31 = p_m31;
		this.m32 = p_m32;
		this.m33 = p_m33;
		return this;
	}
	,SetMatrix4: function(p_matrix) {
		this.m00 = p_matrix.m00;
		this.m01 = p_matrix.m01;
		this.m02 = p_matrix.m02;
		this.m03 = p_matrix.m03;
		this.m10 = p_matrix.m10;
		this.m11 = p_matrix.m11;
		this.m12 = p_matrix.m12;
		this.m13 = p_matrix.m13;
		this.m20 = p_matrix.m20;
		this.m21 = p_matrix.m21;
		this.m22 = p_matrix.m22;
		this.m23 = p_matrix.m23;
		this.m30 = p_matrix.m30;
		this.m31 = p_matrix.m31;
		this.m32 = p_matrix.m32;
		this.m33 = p_matrix.m33;
		return this;
	}
	,GetIndex: function(p_index) {
		switch(p_index) {
		case 0:
			return this.m00;
		case 1:
			return this.m01;
		case 2:
			return this.m02;
		case 3:
			return this.m03;
		case 4:
			return this.m10;
		case 5:
			return this.m11;
		case 6:
			return this.m12;
		case 7:
			return this.m13;
		case 8:
			return this.m20;
		case 9:
			return this.m21;
		case 10:
			return this.m22;
		case 11:
			return this.m23;
		case 12:
			return this.m30;
		case 13:
			return this.m31;
		case 14:
			return this.m32;
		case 15:
			return this.m33;
		}
		return 0;
	}
	,SetIndex: function(p_index,p_value) {
		switch(p_index) {
		case 0:
			this.m00 = p_value;
			break;
		case 1:
			this.m01 = p_value;
			break;
		case 2:
			this.m02 = p_value;
			break;
		case 3:
			this.m03 = p_value;
			break;
		case 4:
			this.m10 = p_value;
			break;
		case 5:
			this.m11 = p_value;
			break;
		case 6:
			this.m12 = p_value;
			break;
		case 7:
			this.m13 = p_value;
			break;
		case 8:
			this.m20 = p_value;
			break;
		case 9:
			this.m21 = p_value;
			break;
		case 10:
			this.m22 = p_value;
			break;
		case 11:
			this.m23 = p_value;
			break;
		case 12:
			this.m30 = p_value;
			break;
		case 13:
			this.m31 = p_value;
			break;
		case 14:
			this.m32 = p_value;
			break;
		case 15:
			this.m33 = p_value;
			break;
		}
		return this;
	}
	,SetRowCol: function(p_row,p_col,p_value) {
		return this.SetIndex(p_col + (p_row << 2),p_value);
	}
	,GetRowCol: function(p_row,p_col) {
		return this.GetIndex(p_col + (p_row << 2));
	}
	,SwapCol: function(p_a,p_b) {
		var a0 = this.GetRowCol(0,p_a);
		var a1 = this.GetRowCol(1,p_a);
		var a2 = this.GetRowCol(2,p_a);
		var a3 = this.GetRowCol(3,p_a);
		this.SetRowCol(0,p_a,this.GetRowCol(0,p_b));
		this.SetRowCol(1,p_a,this.GetRowCol(1,p_b));
		this.SetRowCol(2,p_a,this.GetRowCol(2,p_b));
		this.SetRowCol(3,p_a,this.GetRowCol(3,p_b));
		this.SetRowCol(0,p_b,a0);
		this.SetRowCol(1,p_b,a1);
		this.SetRowCol(2,p_b,a2);
		this.SetRowCol(3,p_b,a3);
		return this;
	}
	,SwapRow: function(p_a,p_b) {
		var a0 = this.GetRowCol(p_a,0);
		var a1 = this.GetRowCol(p_a,1);
		var a2 = this.GetRowCol(p_a,2);
		var a3 = this.GetRowCol(p_a,3);
		this.SetRowCol(p_a,0,this.GetRowCol(p_b,0));
		this.SetRowCol(p_a,1,this.GetRowCol(p_b,1));
		this.SetRowCol(p_a,2,this.GetRowCol(p_b,2));
		this.SetRowCol(p_a,3,this.GetRowCol(p_b,3));
		this.SetRowCol(p_b,0,a0);
		this.SetRowCol(p_b,1,a1);
		this.SetRowCol(p_b,2,a2);
		this.SetRowCol(p_b,3,a3);
		return this;
	}
	,Transpose: function() {
		var t00 = this.m00;
		var t01 = this.m01;
		var t02 = this.m02;
		var t03 = this.m03;
		var t10 = this.m10;
		var t11 = this.m11;
		var t12 = this.m12;
		var t13 = this.m13;
		var t20 = this.m20;
		var t21 = this.m21;
		var t22 = this.m22;
		var t23 = this.m23;
		var t30 = this.m30;
		var t31 = this.m31;
		var t32 = this.m32;
		var t33 = this.m33;
		return this.Set(t00,t10,t20,t30,t01,t11,t21,t31,t02,t12,t22,t32,t03,t13,t23,t33);
	}
	,ToRotation: function() {
		var tmp = haxor_context_EngineContext.data.get_v3();
		tmp.Set(this.m00,this.m01,this.m02).Normalize();
		this.m00 = tmp.x;
		this.m01 = tmp.y;
		this.m02 = tmp.z;
		this.m03 = 0.0;
		tmp.Set(this.m10,this.m11,this.m12).Normalize();
		this.m10 = tmp.x;
		this.m11 = tmp.y;
		this.m12 = tmp.z;
		this.m13 = 0.0;
		tmp.Set(this.m20,this.m21,this.m22).Normalize();
		this.m20 = tmp.x;
		this.m21 = tmp.y;
		this.m22 = tmp.z;
		this.m23 = 0.0;
		this.m30 = this.m31 = this.m32 = 0.0;
		this.m33 = 1.0;
		return this;
	}
	,Rotate: function(p_vector) {
		var tmp = haxor_context_EngineContext.data.get_v3();
		tmp.Set(this.m00,this.m01,this.m02).Normalize();
		p_vector.x = tmp.x * p_vector.x + tmp.y * p_vector.y + tmp.z * p_vector.z;
		tmp.Set(this.m10,this.m11,this.m12).Normalize();
		p_vector.y = tmp.x * p_vector.x + tmp.y * p_vector.y + tmp.z * p_vector.z;
		tmp.Set(this.m20,this.m21,this.m22).Normalize();
		p_vector.z = tmp.x * p_vector.x + tmp.y * p_vector.y + tmp.z * p_vector.z;
		return p_vector;
	}
	,SetTRS: function(p_position,p_rotation,p_scale) {
		return haxor_math_Matrix4.TRS(p_position,p_rotation,p_scale,this);
	}
	,MultiplyTransform: function(p_matrix) {
		var r00 = this.m00 * p_matrix.m00 + this.m01 * p_matrix.m10 + this.m02 * p_matrix.m20;
		var r01 = this.m00 * p_matrix.m01 + this.m01 * p_matrix.m11 + this.m02 * p_matrix.m21;
		var r02 = this.m00 * p_matrix.m02 + this.m01 * p_matrix.m12 + this.m02 * p_matrix.m22;
		var r03 = this.m00 * p_matrix.m03 + this.m01 * p_matrix.m13 + this.m02 * p_matrix.m23 + this.m03;
		var r10 = this.m10 * p_matrix.m00 + this.m11 * p_matrix.m10 + this.m12 * p_matrix.m20;
		var r11 = this.m10 * p_matrix.m01 + this.m11 * p_matrix.m11 + this.m12 * p_matrix.m21;
		var r12 = this.m10 * p_matrix.m02 + this.m11 * p_matrix.m12 + this.m12 * p_matrix.m22;
		var r13 = this.m10 * p_matrix.m03 + this.m11 * p_matrix.m13 + this.m12 * p_matrix.m23 + this.m13;
		var r20 = this.m20 * p_matrix.m00 + this.m21 * p_matrix.m10 + this.m22 * p_matrix.m20;
		var r21 = this.m20 * p_matrix.m01 + this.m21 * p_matrix.m11 + this.m22 * p_matrix.m21;
		var r22 = this.m20 * p_matrix.m02 + this.m21 * p_matrix.m12 + this.m22 * p_matrix.m22;
		var r23 = this.m20 * p_matrix.m03 + this.m21 * p_matrix.m13 + this.m22 * p_matrix.m23 + this.m23;
		this.Set(r00,r01,r02,r03,r10,r11,r12,r13,r20,r21,r22,r23,0,0,0,1);
		return this;
	}
	,Multiply3x4: function(p_matrix) {
		var r00 = this.m00 * p_matrix.m00 + this.m01 * p_matrix.m10 + this.m02 * p_matrix.m20 + this.m03 * p_matrix.m30;
		var r01 = this.m00 * p_matrix.m01 + this.m01 * p_matrix.m11 + this.m02 * p_matrix.m21 + this.m03 * p_matrix.m31;
		var r02 = this.m00 * p_matrix.m02 + this.m01 * p_matrix.m12 + this.m02 * p_matrix.m22 + this.m03 * p_matrix.m32;
		var r03 = this.m00 * p_matrix.m03 + this.m01 * p_matrix.m13 + this.m02 * p_matrix.m23 + this.m03 * p_matrix.m33;
		var r10 = this.m10 * p_matrix.m00 + this.m11 * p_matrix.m10 + this.m12 * p_matrix.m20 + this.m13 * p_matrix.m30;
		var r11 = this.m10 * p_matrix.m01 + this.m11 * p_matrix.m11 + this.m12 * p_matrix.m21 + this.m13 * p_matrix.m31;
		var r12 = this.m10 * p_matrix.m02 + this.m11 * p_matrix.m12 + this.m12 * p_matrix.m22 + this.m13 * p_matrix.m32;
		var r13 = this.m10 * p_matrix.m03 + this.m11 * p_matrix.m13 + this.m12 * p_matrix.m23 + this.m13 * p_matrix.m33;
		var r20 = this.m20 * p_matrix.m00 + this.m21 * p_matrix.m10 + this.m22 * p_matrix.m20 + this.m23 * p_matrix.m30;
		var r21 = this.m20 * p_matrix.m01 + this.m21 * p_matrix.m11 + this.m22 * p_matrix.m21 + this.m23 * p_matrix.m31;
		var r22 = this.m20 * p_matrix.m02 + this.m21 * p_matrix.m12 + this.m22 * p_matrix.m22 + this.m23 * p_matrix.m32;
		var r23 = this.m20 * p_matrix.m03 + this.m21 * p_matrix.m13 + this.m22 * p_matrix.m23 + this.m23 * p_matrix.m33;
		this.Set(r00,r01,r02,r03,r10,r11,r12,r13,r20,r21,r22,r23,this.m30,this.m31,this.m32,this.m33);
		return this;
	}
	,Multiply: function(p_matrix) {
		var r00 = this.m00 * p_matrix.m00 + this.m01 * p_matrix.m10 + this.m02 * p_matrix.m20 + this.m03 * p_matrix.m30;
		var r01 = this.m00 * p_matrix.m01 + this.m01 * p_matrix.m11 + this.m02 * p_matrix.m21 + this.m03 * p_matrix.m31;
		var r02 = this.m00 * p_matrix.m02 + this.m01 * p_matrix.m12 + this.m02 * p_matrix.m22 + this.m03 * p_matrix.m32;
		var r03 = this.m00 * p_matrix.m03 + this.m01 * p_matrix.m13 + this.m02 * p_matrix.m23 + this.m03 * p_matrix.m33;
		var r10 = this.m10 * p_matrix.m00 + this.m11 * p_matrix.m10 + this.m12 * p_matrix.m20 + this.m13 * p_matrix.m30;
		var r11 = this.m10 * p_matrix.m01 + this.m11 * p_matrix.m11 + this.m12 * p_matrix.m21 + this.m13 * p_matrix.m31;
		var r12 = this.m10 * p_matrix.m02 + this.m11 * p_matrix.m12 + this.m12 * p_matrix.m22 + this.m13 * p_matrix.m32;
		var r13 = this.m10 * p_matrix.m03 + this.m11 * p_matrix.m13 + this.m12 * p_matrix.m23 + this.m13 * p_matrix.m33;
		var r20 = this.m20 * p_matrix.m00 + this.m21 * p_matrix.m10 + this.m22 * p_matrix.m20 + this.m23 * p_matrix.m30;
		var r21 = this.m20 * p_matrix.m01 + this.m21 * p_matrix.m11 + this.m22 * p_matrix.m21 + this.m23 * p_matrix.m31;
		var r22 = this.m20 * p_matrix.m02 + this.m21 * p_matrix.m12 + this.m22 * p_matrix.m22 + this.m23 * p_matrix.m32;
		var r23 = this.m20 * p_matrix.m03 + this.m21 * p_matrix.m13 + this.m22 * p_matrix.m23 + this.m23 * p_matrix.m33;
		var r30 = this.m30 * p_matrix.m00 + this.m31 * p_matrix.m10 + this.m32 * p_matrix.m20 + this.m33 * p_matrix.m30;
		var r31 = this.m30 * p_matrix.m01 + this.m31 * p_matrix.m11 + this.m32 * p_matrix.m21 + this.m33 * p_matrix.m31;
		var r32 = this.m30 * p_matrix.m02 + this.m31 * p_matrix.m12 + this.m32 * p_matrix.m22 + this.m33 * p_matrix.m32;
		var r33 = this.m30 * p_matrix.m03 + this.m31 * p_matrix.m13 + this.m32 * p_matrix.m23 + this.m33 * p_matrix.m33;
		this.Set(r00,r01,r02,r03,r10,r11,r12,r13,r20,r21,r22,r23,r30,r31,r32,r33);
		return this;
	}
	,Transform4x4: function(p_point) {
		var vx = this.m00 * p_point.x + this.m01 * p_point.y + this.m02 * p_point.z + this.m03 * p_point.w;
		var vy = this.m10 * p_point.x + this.m11 * p_point.y + this.m12 * p_point.z + this.m13 * p_point.w;
		var vz = this.m20 * p_point.x + this.m21 * p_point.y + this.m22 * p_point.z + this.m23 * p_point.w;
		var vw = this.m30 * p_point.x + this.m31 * p_point.y + this.m32 * p_point.z + this.m33 * p_point.w;
		p_point.x = vx;
		p_point.y = vy;
		p_point.z = vz;
		p_point.w = vw;
		return p_point;
	}
	,Transform3x4: function(p_point) {
		var vx = this.m00 * p_point.x + this.m01 * p_point.y + this.m02 * p_point.z + this.m03;
		var vy = this.m10 * p_point.x + this.m11 * p_point.y + this.m12 * p_point.z + this.m13;
		var vz = this.m20 * p_point.x + this.m21 * p_point.y + this.m22 * p_point.z + this.m23;
		p_point.x = vx;
		p_point.y = vy;
		p_point.z = vz;
		return p_point;
	}
	,Transform3x3: function(p_point) {
		var vx = this.m00 * p_point.x + this.m01 * p_point.y + this.m02 * p_point.z;
		var vy = this.m10 * p_point.x + this.m11 * p_point.y + this.m12 * p_point.z;
		var vz = this.m20 * p_point.x + this.m21 * p_point.y + this.m22 * p_point.z;
		p_point.x = vx;
		p_point.y = vy;
		p_point.z = vz;
		return p_point;
	}
	,Transform2x3: function(p_point) {
		var vx = this.m00 * p_point.x + this.m01 * p_point.y + this.m03;
		var vy = this.m10 * p_point.x + this.m11 * p_point.y + this.m13;
		p_point.x = vx;
		p_point.y = vy;
	}
	,Transform2x2: function(p_point) {
		var vx = this.m00 * p_point.x + this.m01 * p_point.y;
		var vy = this.m10 * p_point.x + this.m11 * p_point.y;
		p_point.x = vx;
		p_point.y = vy;
	}
	,SetLookAt: function(p_eye,p_at,p_up) {
		return haxor_math_Matrix4.LookAt(p_eye,p_at,p_up,this);
	}
	,SetFrustum: function(p_left,p_right,p_top,p_bottom,p_near,p_far) {
		return haxor_math_Matrix4.Frustum(p_left,p_right,p_top,p_bottom,p_near,p_far,this);
	}
	,SetFrustumInverse: function(p_left,p_right,p_top,p_bottom,p_near,p_far) {
		return haxor_math_Matrix4.FrustumInverse(p_left,p_right,p_top,p_bottom,p_near,p_far,this);
	}
	,SetOrtho: function(p_left,p_right,p_top,p_bottom,p_near,p_far) {
		return haxor_math_Matrix4.Ortho(p_left,p_right,p_top,p_bottom,p_near,p_far,this);
	}
	,SetPerspective: function(p_fov,p_aspect,p_near,p_far) {
		return haxor_math_Matrix4.Perspective(p_fov,p_aspect,p_near,p_far,this);
	}
	,SetPerspectiveInverse: function(p_fov,p_aspect,p_near,p_far) {
		return haxor_math_Matrix4.PerspectiveInverse(p_fov,p_aspect,p_near,p_far,this);
	}
	,ToArray: function() {
		return [this.m00,this.m01,this.m02,this.m03,this.m10,this.m11,this.m12,this.m13,this.m20,this.m21,this.m22,this.m23,this.m30,this.m31,this.m32,this.m33];
	}
	,ToString: function(p_linear,p_places) {
		if(p_places == null) p_places = 2;
		if(p_linear == null) p_linear = true;
		var a = this.ToArray();
		var s = [];
		var _g1 = 0;
		var _g = a.length;
		while(_g1 < _g) {
			var i = _g1++;
			a[i] = haxor_math_Mathf.RoundPlaces(a[i],p_places);
			s.push(a[i] >= 0?" " + a[i]:a[i] + "");
		}
		var res;
		if(p_linear) res = "["; else res = "";
		var _g2 = 0;
		while(_g2 < 4) {
			var i1 = _g2++;
			var _g11 = 0;
			while(_g11 < 4) {
				var j = _g11++;
				res += s[j + i1 * 4] + (j < 3?",":"");
			}
			if(i1 == 3) res += ""; else if(p_linear) res += " |"; else res += "\n";
		}
		if(p_linear) res += "]";
		return res;
	}
	,__class__: haxor_math_Matrix4
	,__properties__: {set_diagonalLR:"set_diagonalLR",get_diagonalLR:"get_diagonalLR",get_transposed:"get_transposed",get_inverseTransform:"get_inverseTransform",get_translation:"get_translation",get_scale:"get_scale",get_rotation:"get_rotation",get_trace:"get_trace",set_quaternion:"set_quaternion",get_quaternion:"get_quaternion",get_clone:"get_clone"}
};
var haxor_math_Random = function() { };
$hxClasses["haxor.math.Random"] = haxor_math_Random;
haxor_math_Random.__name__ = ["haxor","math","Random"];
haxor_math_Random.__properties__ = {get_onCircle:"get_onCircle",get_circle:"get_circle",get_onSphere:"get_onSphere",get_sphere:"get_sphere",get_onSquare:"get_onSquare",get_square:"get_square",get_onBox:"get_onBox",get_box:"get_box",get_rotation:"get_rotation",get_interval:"get_interval",get_value:"get_value"}
haxor_math_Random.get_value = function() {
	return Math.random();
};
haxor_math_Random.get_interval = function() {
	return (Math.random() - 0.499995) * 2.0;
};
haxor_math_Random.get_rotation = function() {
	return haxor_math_Quaternion.FromAxisAngle(new haxor_math_Vector3((Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0).Normalize().Scale(Math.random()),(Math.random() - 0.499995) * 2.0 * 180.0);
};
haxor_math_Random.get_box = function() {
	return new haxor_math_Vector3((Math.random() - 0.499995) * 2.0 * 0.5,(Math.random() - 0.499995) * 2.0 * 0.5,(Math.random() - 0.499995) * 2.0 * 0.5);
};
haxor_math_Random.get_onBox = function() {
	var p = new haxor_math_Vector3((Math.random() - 0.499995) * 2.0 * 0.5,(Math.random() - 0.499995) * 2.0 * 0.5,(Math.random() - 0.499995) * 2.0 * 0.5);
	var i = Math.random() * 3 + 0.5;
	switch(i) {
	case 0:
		if(p.x < 0.0) p.x = -0.5; else p.x = 0.5;
		break;
	case 1:
		if(p.y < 0.0) p.y = -0.5; else p.y = 0.5;
		break;
	case 2:
		if(p.z < 0.0) p.z = -0.5; else p.z = 0.5;
		break;
	}
	return p;
};
haxor_math_Random.get_square = function() {
	return new haxor_math_Vector2((Math.random() - 0.499995) * 2.0 * 0.5,(Math.random() - 0.499995) * 2.0 * 0.5);
};
haxor_math_Random.get_onSquare = function() {
	var p = new haxor_math_Vector2((Math.random() - 0.499995) * 2.0 * 0.5,(Math.random() - 0.499995) * 2.0 * 0.5);
	var i = Math.random() * 2 + 0.5;
	switch(i) {
	case 0:
		if(p.x < 0.0) p.x = -0.5; else p.x = 0.5;
		break;
	case 1:
		if(p.y < 0.0) p.y = -0.5; else p.y = 0.5;
		break;
	}
	return p;
};
haxor_math_Random.get_sphere = function() {
	return new haxor_math_Vector3((Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0).Normalize().Scale(Math.random());
};
haxor_math_Random.get_onSphere = function() {
	return new haxor_math_Vector3((Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0).Normalize();
};
haxor_math_Random.get_circle = function() {
	return new haxor_math_Vector2((Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0).Normalize().Scale(Math.random());
};
haxor_math_Random.get_onCircle = function() {
	return new haxor_math_Vector2((Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0).Normalize();
};
haxor_math_Random.Length = function(v) {
	return (v + 1) * Math.random();
};
haxor_math_Random.Range = function(p_min,p_max) {
	return haxor_math_Mathf.Lerp(p_min,p_max,Math.random());
};
haxor_math_Random.RangeInt = function(p_min,p_max) {
	return haxor_math_Mathf.LerpInt(p_min,p_max + 1,Math.random());
};
haxor_math_Random.Item = function(p_list) {
	return p_list[p_list.length * Math.random()];
};
haxor_math_Random.Shuffle = function(p_list) {
	var m = p_list.length;
	var t;
	var i;
	while(m > 0) {
		i = Math.floor(Math.random() * m--);
		t = p_list[m];
		p_list[m] = p_list[i];
		p_list[i] = t;
	}
};
var haxor_math_Vector2 = function(p_x,p_y) {
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.x = p_x;
	this.y = p_y;
};
$hxClasses["haxor.math.Vector2"] = haxor_math_Vector2;
haxor_math_Vector2.__name__ = ["haxor","math","Vector2"];
haxor_math_Vector2.__properties__ = {get_up:"get_up",get_right:"get_right",get_one:"get_one",get_zero:"get_zero",get_temp:"get_temp"}
haxor_math_Vector2.get_temp = function() {
	return haxor_context_EngineContext.data.get_v2();
};
haxor_math_Vector2.get_zero = function() {
	return new haxor_math_Vector2(0,0);
};
haxor_math_Vector2.get_one = function() {
	return new haxor_math_Vector2(1,1);
};
haxor_math_Vector2.get_right = function() {
	return new haxor_math_Vector2(1,0);
};
haxor_math_Vector2.get_up = function() {
	return new haxor_math_Vector2(0,1);
};
haxor_math_Vector2.Dot = function(p_a,p_b) {
	return p_a.x * p_b.x + p_a.y * p_b.y;
};
haxor_math_Vector2.Lerp = function(p_a,p_b,p_r) {
	return new haxor_math_Vector2(p_a.x + (p_b.x - p_a.x) * p_r,p_a.y + (p_b.y - p_a.y) * p_r);
};
haxor_math_Vector2.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	return new haxor_math_Vector2(0,0).Set(Std.parseFloat(StringTools.trim(tk[0])),Std.parseFloat(StringTools.trim(tk[1])));
};
haxor_math_Vector2.prototype = {
	get_clone: function() {
		return new haxor_math_Vector2(this.x,this.y);
	}
	,get_xy: function() {
		return new haxor_math_Vector2(this.x,this.y);
	}
	,get_yx: function() {
		return new haxor_math_Vector2(this.y,this.x);
	}
	,get_length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y);
	}
	,get_lengthSqr: function() {
		return this.x * this.x + this.y * this.y;
	}
	,get_normalized: function() {
		return new haxor_math_Vector2(this.x,this.y).Normalize();
	}
	,get_inverse: function() {
		return new haxor_math_Vector2(this.x,this.y).Invert();
	}
	,Set: function(p_x,p_y) {
		if(p_y == null) p_y = 0;
		if(p_x == null) p_x = 0;
		this.x = p_x;
		this.y = p_y;
		return this;
	}
	,Set2: function(v) {
		this.x = v.x;
		this.y = v.y;
		return this;
	}
	,Set3: function(v) {
		this.x = v.x;
		this.y = v.y;
		return this;
	}
	,Set4: function(v) {
		this.x = v.x;
		this.y = v.y;
		return this;
	}
	,Get: function(p) {
		if(p == 0) return this.x; else return this.y;
	}
	,Add: function(p_v) {
		this.x += p_v.x;
		this.y += p_v.y;
		return this;
	}
	,Sub: function(p_v) {
		this.x -= p_v.x;
		this.y -= p_v.y;
		return this;
	}
	,Multiply: function(p_v) {
		this.x *= p_v.x;
		this.y *= p_v.y;
		return this;
	}
	,Scale: function(p_s) {
		this.x *= p_s;
		this.y *= p_s;
		return this;
	}
	,Step: function(p_to,p_step) {
		var vx = p_to.x - this.x;
		var vy = p_to.y - this.y;
		var l = Math.sqrt(vx * vx + vy * vy);
		if(l <= 0.0001) return false;
		var s;
		if(p_step > l) s = l; else s = p_step;
		l = s / l;
		vx *= l;
		vy *= l;
		this.x += vx;
		this.y += vy;
		return true;
	}
	,Reflect: function(p_normal) {
		var d = Math.min(0.0,p_normal.x * this.x + p_normal.y * this.y) * 2.0;
		this.x += -p_normal.x * d;
		this.y += -p_normal.y * d;
		return this;
	}
	,Invert: function() {
		this.x = -this.x;
		this.y = -this.y;
		return this;
	}
	,Normalize: function() {
		var l = Math.sqrt(this.x * this.x + this.y * this.y);
		if(l <= 0) return this;
		this.x *= l = 1.0 / l;
		this.y *= l;
		return this;
	}
	,ToArray: function() {
		return [this.x,this.y];
	}
	,ToString: function(p_places) {
		if(p_places == null) p_places = 2;
		return "[" + haxor_math_Mathf.RoundPlaces(this.x,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.y,p_places) + "]";
	}
	,__class__: haxor_math_Vector2
	,__properties__: {get_inverse:"get_inverse",get_normalized:"get_normalized",get_lengthSqr:"get_lengthSqr",get_length:"get_length",get_yx:"get_yx",get_xy:"get_xy",get_clone:"get_clone"}
};
var haxor_math_Vector4 = function(p_x,p_y,p_z,p_w) {
	if(p_w == null) p_w = 0;
	if(p_z == null) p_z = 0;
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.x = p_x;
	this.y = p_y;
	this.z = p_z;
	this.w = p_w;
};
$hxClasses["haxor.math.Vector4"] = haxor_math_Vector4;
haxor_math_Vector4.__name__ = ["haxor","math","Vector4"];
haxor_math_Vector4.__properties__ = {get_W:"get_W",get_one:"get_one",get_zero:"get_zero",get_temp:"get_temp"}
haxor_math_Vector4.get_temp = function() {
	return haxor_context_EngineContext.data.get_v4();
};
haxor_math_Vector4.get_zero = function() {
	return new haxor_math_Vector4(0,0,0,0);
};
haxor_math_Vector4.get_one = function() {
	return new haxor_math_Vector4(1,1,1,1);
};
haxor_math_Vector4.get_W = function() {
	return new haxor_math_Vector4(0,0,0,1);
};
haxor_math_Vector4.Lerp = function(p_a,p_b,p_r) {
	return new haxor_math_Vector4(p_a.x + (p_b.x - p_a.x) * p_r,p_a.y + (p_b.y - p_a.y) * p_r,p_a.z + (p_b.z - p_a.z) * p_r,p_a.w + (p_b.w - p_a.w) * p_r);
};
haxor_math_Vector4.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	return new haxor_math_Vector4(0,0,0,0).Set(Std.parseFloat(StringTools.trim(tk[0])),Std.parseFloat(StringTools.trim(tk[1])),Std.parseFloat(StringTools.trim(tk[2])),Std.parseFloat(StringTools.trim(tk[3])));
};
haxor_math_Vector4.prototype = {
	get_clone: function() {
		return new haxor_math_Vector4(this.x,this.y,this.z,this.w);
	}
	,get_rgba: function() {
		return new haxor_math_Color(this.x,this.y,this.z,this.w);
	}
	,get_rgb: function() {
		return new haxor_math_Color(this.x,this.y,this.z);
	}
	,get_xyz: function() {
		return new haxor_math_Vector3(this.x,this.y,this.z);
	}
	,get_xy: function() {
		return new haxor_math_Vector2(this.x,this.y);
	}
	,get_length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
	}
	,get_lengthSqr: function() {
		return this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w;
	}
	,get_normalized: function() {
		return new haxor_math_Vector4(this.x,this.y,this.z,this.w).Normalize();
	}
	,Get: function(p) {
		if(p == 0) return this.x; else if(p == 1) return this.y; else if(p == 2) return this.z; else return this.w;
	}
	,Set: function(p_x,p_y,p_z,p_w) {
		if(p_w == null) p_w = 0;
		if(p_z == null) p_z = 0;
		if(p_y == null) p_y = 0;
		if(p_x == null) p_x = 0;
		this.x = p_x;
		this.y = p_y;
		this.z = p_z;
		this.w = p_w;
		return this;
	}
	,Set2: function(v) {
		this.x = v.x;
		this.y = v.y;
		return this;
	}
	,Set3: function(v) {
		this.x = v.x;
		this.y = v.y;
		this.z = v.z;
		return this;
	}
	,SetColor: function(v) {
		this.x = v.r;
		this.y = v.g;
		this.z = v.b;
		return this;
	}
	,Add: function(p_v) {
		this.x += p_v.x;
		this.y += p_v.y;
		this.z += p_v.z;
		this.w += p_v.w;
		return this;
	}
	,Sub: function(p_v) {
		this.x -= p_v.x;
		this.y -= p_v.y;
		this.z -= p_v.z;
		this.w -= p_v.w;
		return this;
	}
	,Multiply: function(p_v) {
		this.x *= p_v.x;
		this.y *= p_v.y;
		this.z *= p_v.z;
		this.w *= p_v.w;
		return this;
	}
	,Scale: function(p_s) {
		this.x *= p_s;
		this.y *= p_s;
		this.z *= p_s;
		this.w *= p_s;
		return this;
	}
	,Normalize: function() {
		var l = Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
		if(l <= 0) return this;
		this.x *= l = 1.0 / l;
		this.y *= l;
		this.z *= l;
		this.w *= l;
		return this;
	}
	,IsCulled: function() {
		if(this.x < -this.w) return true;
		if(this.x > this.w) return true;
		if(this.y < -this.w) return true;
		if(this.y > this.w) return true;
		if(this.z < -this.w) return true;
		if(this.z > this.w) return true;
		return false;
	}
	,ToArray: function() {
		return [this.x,this.y,this.z,this.w];
	}
	,ToString: function(p_places) {
		if(p_places == null) p_places = 2;
		return "[" + haxor_math_Mathf.RoundPlaces(this.x,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.y,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.z,p_places) + "," + haxor_math_Mathf.RoundPlaces(this.w,p_places) + "]";
	}
	,__class__: haxor_math_Vector4
	,__properties__: {get_normalized:"get_normalized",get_lengthSqr:"get_lengthSqr",get_length:"get_length",get_xy:"get_xy",get_xyz:"get_xyz",get_rgb:"get_rgb",get_rgba:"get_rgba",get_clone:"get_clone"}
};
var haxor_thread_Activity = function(p_callback,p_threaded,p_graphics_context) {
	if(p_graphics_context == null) p_graphics_context = false;
	if(p_threaded == null) p_threaded = false;
	haxor_core_Resource.call(this);
	if(p_callback == null) return;
	this.m_time_start = haxor_core_Time.m_elapsed;
	this.m_elapsed = 0.0;
	this.m_callback = p_callback;
	this.m_cancelled = false;
	p_threaded = false;
	if(p_graphics_context) p_threaded = false;
	if(!p_threaded) {
		if(p_graphics_context) haxor_context_EngineContext.render.Add(this); else haxor_context_EngineContext.update.Add(this);
	} else {
	}
};
$hxClasses["haxor.thread.Activity"] = haxor_thread_Activity;
haxor_thread_Activity.__name__ = ["haxor","thread","Activity"];
haxor_thread_Activity.__interfaces__ = [haxor_core_IRenderable,haxor_core_IUpdateable];
haxor_thread_Activity.Iterate = function(p_offset,p_length,p_callback,p_step,p_threaded,p_graphics_context) {
	if(p_graphics_context == null) p_graphics_context = false;
	if(p_threaded == null) p_threaded = false;
	if(p_step == null) p_step = 1;
	var it = p_offset;
	return new haxor_thread_Activity(function(t) {
		var finished = false;
		var _g = 0;
		while(_g < p_step) {
			var i = _g++;
			if(it >= p_length) return false;
			if(!p_callback(it)) {
				finished = true;
				break;
			}
			it++;
		}
		return !finished;
	},p_threaded,p_graphics_context);
};
haxor_thread_Activity.Delay = function(p_time,p_callback,p_threaded,p_graphics_context) {
	if(p_graphics_context == null) p_graphics_context = false;
	if(p_threaded == null) p_threaded = false;
	return new haxor_thread_Activity(function(t) {
		if(t >= p_time) {
			p_callback();
			return false;
		}
		return true;
	},p_threaded,p_graphics_context);
};
haxor_thread_Activity.Run = function(p_callback,p_threaded,p_graphics_context) {
	if(p_graphics_context == null) p_graphics_context = false;
	if(p_threaded == null) p_threaded = false;
	return new haxor_thread_Activity(p_callback,p_threaded,p_graphics_context);
};
haxor_thread_Activity.RunOnce = function(p_callback,p_threaded,p_graphics_context) {
	if(p_graphics_context == null) p_graphics_context = false;
	if(p_threaded == null) p_threaded = false;
	return new haxor_thread_Activity(function(t) {
		p_callback();
		return false;
	},p_threaded,p_graphics_context);
};
haxor_thread_Activity.__super__ = haxor_core_Resource;
haxor_thread_Activity.prototype = $extend(haxor_core_Resource.prototype,{
	get_elapsed: function() {
		return this.m_elapsed;
	}
	,Cancel: function() {
		this.m_cancelled = true;
	}
	,OnUpdate: function() {
		this.OnRun();
	}
	,OnRender: function() {
		this.OnRun();
	}
	,OnRun: function() {
		if(this.m_cancelled) {
			haxor_core_Resource.Destroy(this);
			return;
		}
		this.m_elapsed = haxor_core_Time.m_elapsed - this.m_time_start;
		if(!this.m_callback(this.m_elapsed)) haxor_core_Resource.Destroy(this);
	}
	,__class__: haxor_thread_Activity
	,__properties__: $extend(haxor_core_Resource.prototype.__properties__,{get_elapsed:"get_elapsed"})
});
var haxor_thread_Task = function(p_threaded,p_callback) {
	if(p_threaded == null) p_threaded = false;
	var cb = p_callback;
	if(cb == null) cb = $bind(this,this.OnExecute);
	haxor_thread_Activity.call(this,cb,p_threaded);
	this.m_active = false;
	this.m_progress = 0.0;
	this.m_has_progress = false;
};
$hxClasses["haxor.thread.Task"] = haxor_thread_Task;
haxor_thread_Task.__name__ = ["haxor","thread","Task"];
haxor_thread_Task.__super__ = haxor_thread_Activity;
haxor_thread_Task.prototype = $extend(haxor_thread_Activity.prototype,{
	get_progress: function() {
		return this.m_progress;
	}
	,set_progress: function(v) {
		if(Math.abs(v - this.m_progress) > 0.0) {
			this.m_progress = v;
			this.m_has_progress = true;
		}
		return v;
	}
	,get_active: function() {
		return this.m_active;
	}
	,OnStart: function() {
	}
	,OnStep: function() {
	}
	,OnComplete: function() {
	}
	,OnProgress: function() {
	}
	,OnExecute: function(p_time) {
		if(!this.m_active) {
			this.m_active = true;
			this.OnStart();
		}
		this.OnStep();
		if(this.m_has_progress) {
			this.OnProgress();
			this.m_has_progress = false;
		}
		if(this.m_progress >= 1.0) {
			this.OnComplete();
			return false;
		}
		return true;
	}
	,__class__: haxor_thread_Task
	,__properties__: $extend(haxor_thread_Activity.prototype.__properties__,{get_active:"get_active",set_progress:"set_progress",get_progress:"get_progress"})
});
var haxor_net_HTTPRequestTask = function(p_url,p_method,p_binary,p_data) {
	haxor_thread_Task.call(this);
	if(p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url,"./",haxor_net_Web.root);
	this.url = p_url;
	this.binary = p_binary;
	this.method = p_method;
	this.data = p_data;
	this.bytesLoaded = 0;
	this.bytesTotal = 0;
	this.error = "";
	haxor_core_Console.Log("HTTPRequest> " + this.url,4);
};
$hxClasses["haxor.net.HTTPRequestTask"] = haxor_net_HTTPRequestTask;
haxor_net_HTTPRequestTask.__name__ = ["haxor","net","HTTPRequestTask"];
haxor_net_HTTPRequestTask.__super__ = haxor_thread_Task;
haxor_net_HTTPRequestTask.prototype = $extend(haxor_thread_Task.prototype,{
	OnStart: function() {
	}
	,OnError: function() {
		haxor_core_Console.LogError("HTTPRequest> Error [" + this.error + "]");
	}
	,__class__: haxor_net_HTTPRequestTask
});
var haxor_platform_html_net_HTTPRequest = function(p_url,p_method,p_binary,p_data) {
	var _g = this;
	haxor_net_HTTPRequestTask.call(this,p_url,p_method,p_binary,p_data);
	this.request = new XMLHttpRequest();
	if(this.request.withCredentials) this.request.withCredentials = false;
	if(($_=this.request,$bind($_,$_.overrideMimeType)) != null) this.request.overrideMimeType(p_binary?"application/octet-stream":"text/plain");
	this.request.onprogress = function(e) {
		_g.bytesLoaded = e.loaded;
		_g.bytesTotal = e.total;
		_g.set_progress((e.total <= 0?0:e.loaded / (e.total + 5)) * 0.999);
	};
	this.request.onload = function(e1) {
		_g.set_progress(1.0);
	};
	this.request.onerror = function(e2) {
		_g.request = null;
		_g.set_progress(1.0);
		_g.error = e2.message;
		_g.OnError();
	};
	this.request.open(this.method,this.url,true);
};
$hxClasses["haxor.platform.html.net.HTTPRequest"] = haxor_platform_html_net_HTTPRequest;
haxor_platform_html_net_HTTPRequest.__name__ = ["haxor","platform","html","net","HTTPRequest"];
haxor_platform_html_net_HTTPRequest.__super__ = haxor_net_HTTPRequestTask;
haxor_platform_html_net_HTTPRequest.prototype = $extend(haxor_net_HTTPRequestTask.prototype,{
	OnStart: function() {
		if(this.data == null) this.request.send(); else this.request.send(this.data);
	}
	,__class__: haxor_platform_html_net_HTTPRequest
});
var haxor_platform_html_net_HTTPLoader = function(p_url,p_binary,p_callback) {
	haxor_platform_html_net_HTTPRequest.call(this,p_url,"get",p_binary);
	this.callback = p_callback;
};
$hxClasses["haxor.platform.html.net.HTTPLoader"] = haxor_platform_html_net_HTTPLoader;
haxor_platform_html_net_HTTPLoader.__name__ = ["haxor","platform","html","net","HTTPLoader"];
haxor_platform_html_net_HTTPLoader.__super__ = haxor_platform_html_net_HTTPRequest;
haxor_platform_html_net_HTTPLoader.prototype = $extend(haxor_platform_html_net_HTTPRequest.prototype,{
	OnStart: function() {
		haxor_platform_html_net_HTTPRequest.prototype.OnStart.call(this);
		if(this.callback != null) this.callback(null,0.0);
	}
	,OnComplete: function() {
		if(this.callback == null) return;
		if(this.request == null) {
			this.callback(null,1.0);
			return;
		}
		this.response = this.request.response;
		if(this.binary) this.callback(this.request.response,1.0); else this.callback(this.request.responseText,1.0);
	}
	,__class__: haxor_platform_html_net_HTTPLoader
});
var haxor_platform_html_net_BitmapLoader = function(p_url,p_callback) {
	haxor_platform_html_net_HTTPLoader.call(this,p_url,true,$bind(this,this.OnBufferCallback));
	this.m_bitmap_callback = p_callback;
	this.request.responseType = "blob";
};
$hxClasses["haxor.platform.html.net.BitmapLoader"] = haxor_platform_html_net_BitmapLoader;
haxor_platform_html_net_BitmapLoader.__name__ = ["haxor","platform","html","net","BitmapLoader"];
haxor_platform_html_net_BitmapLoader.__super__ = haxor_platform_html_net_HTTPLoader;
haxor_platform_html_net_BitmapLoader.prototype = $extend(haxor_platform_html_net_HTTPLoader.prototype,{
	OnBufferCallback: function(p_data,p_progress) {
		var _g = this;
		if(p_progress < 1.0) {
			if(this.m_bitmap_callback != null) this.m_bitmap_callback(null,this.m_progress);
		} else {
			if(p_data == null) return;
			var img = new Image();
			img.onload = function(e) {
				var g;
				var _this;
				var _this1 = window.document;
				_this = _this1.createElement("canvas");
				g = _this.getContext("2d");
				g.canvas.width = img.width;
				g.canvas.height = img.height;
				g.scale(1.0,-1.0);
				g.drawImage(img,0,-img.height);
				var data = g.getImageData(0,0,g.canvas.width,g.canvas.height);
				var w = data.width;
				var h = data.height;
				var cc = data.data.byteLength / (w * h) | 0;
				var fmt = haxor_core_PixelFormat.RGBA8;
				switch(cc) {
				case 1:
					fmt = haxor_core_PixelFormat.Alpha8;
					break;
				case 3:
					fmt = haxor_core_PixelFormat.RGB8;
					break;
				}
				var b = new haxor_graphics_texture_Bitmap(w,h,fmt);
				b.get_buffer().m_buffer.set(data.data);
				if(_g.m_bitmap_callback != null) _g.m_bitmap_callback(b,1.0);
			};
			img.src = URL.createObjectURL(this.request.response);
		}
	}
	,OnError: function() {
		if(this.m_bitmap_callback != null) this.m_bitmap_callback(null,1.0);
	}
	,__class__: haxor_platform_html_net_BitmapLoader
});
var haxor_net_Texture2DLoader = function(p_url,p_apply,p_callback) {
	haxor_platform_html_net_BitmapLoader.call(this,p_url,$bind(this,this.OnBitmapCallback));
	this.m_t2d_callback = p_callback;
	this.m_apply = p_apply;
};
$hxClasses["haxor.net.Texture2DLoader"] = haxor_net_Texture2DLoader;
haxor_net_Texture2DLoader.__name__ = ["haxor","net","Texture2DLoader"];
haxor_net_Texture2DLoader.__super__ = haxor_platform_html_net_BitmapLoader;
haxor_net_Texture2DLoader.prototype = $extend(haxor_platform_html_net_BitmapLoader.prototype,{
	OnBitmapCallback: function(p_data,p_progress) {
		var _g = this;
		if(this.m_progress < 1.0) {
			if(this.m_t2d_callback != null) this.m_t2d_callback(null,this.m_progress);
		} else {
			if(p_data == null) return;
			haxor_thread_Activity.RunOnce(function() {
				var t = haxor_graphics_texture_Texture2D.FromBitmap(p_data,_g.m_apply);
				_g.m_t2d_callback(t,1.0);
			},false,true);
		}
	}
	,OnError: function() {
		haxor_platform_html_net_BitmapLoader.prototype.OnError.call(this);
		if(this.m_t2d_callback != null) this.m_bitmap_callback(null,1.0);
	}
	,__class__: haxor_net_Texture2DLoader
});
var haxor_net_Web = function() { };
$hxClasses["haxor.net.Web"] = haxor_net_Web;
haxor_net_Web.__name__ = ["haxor","net","Web"];
haxor_net_Web.Load = function(p_url,p_callback) {
	var ld = new haxor_platform_html_net_HTTPLoader(p_url,false,p_callback);
};
haxor_net_Web.LoadImg = function(p_url,p_callback) {
	var ld = new haxor_platform_html_net_BitmapLoader(p_url,p_callback);
};
haxor_net_Web.LoadTexture2D = function(p_url,p_apply,p_callback) {
	var ld = new haxor_net_Texture2DLoader(p_url,p_apply,p_callback);
};
haxor_net_Web.LoadCollada = function(p_url,p_callback) {
	haxor_net_Web.Load(p_url,function(d,p) {
		if(p < 1.0) p_callback(null,p); else p_callback(d == null?null:new haxor_io_file_ColladaFile(p_url,d),1.0);
	});
};
haxor_net_Web.LoadShader = function(p_url,p_callback) {
	haxor_net_Web.Load(p_url,function(d,p) {
		if(p < 1.0) p_callback(null,p); else p_callback(d == null?null:new haxor_graphics_material_Shader(d),1.0);
	});
};
var haxor_platform_html_Entry = function() { };
$hxClasses["haxor.platform.html.Entry"] = haxor_platform_html_Entry;
haxor_platform_html_Entry.__name__ = ["haxor","platform","html","Entry"];
haxor_platform_html_Entry.Initialize = function() {
	window.onload = haxor_platform_html_Entry.OnWindowLoad;
};
haxor_platform_html_Entry.OnWindowLoad = function(p_event) {
	haxor_core_Console.Initialize();
	var script_list = window.document.getElementsByTagName("SCRIPT");
	var attrib = "";
	var app_class_type = "Main";
	var app_container_id = "haxor";
	var app_input_id = "haxor";
	var _g1 = 0;
	var _g = script_list.length;
	while(_g1 < _g) {
		var i = _g1++;
		var scr = script_list.item(i);
		attrib = scr.getAttribute("verbose");
		if(attrib != null) {
			if(attrib == "") attrib = "0"; else attrib = attrib;
			haxor_core_Console.verbose = Std.parseInt(attrib);
		}
		attrib = scr.getAttribute("application");
		if(attrib != null) app_class_type = attrib;
		attrib = scr.getAttribute("container");
		if(attrib != null) app_container_id = attrib;
		attrib = scr.getAttribute("input");
		if(attrib != null) app_input_id = attrib;
	}
	haxor_core_Console.Log("Haxor> HTML Platform Init verbose[" + haxor_core_Console.verbose + "] application[" + app_class_type + "] container[" + app_container_id + "]",1);
	var tag_strings = window.document.getElementsByTagName("strings");
	if(tag_strings != null) {
		if(tag_strings.length > 0) {
			var k = 0;
			var _g11 = 0;
			var _g2 = tag_strings.length;
			while(_g11 < _g2) {
				var i1 = _g11++;
				var it = tag_strings.item(i1);
				var l = it.childNodes;
				var _g3 = 0;
				var _g21 = l.length;
				while(_g3 < _g21) {
					var j = _g3++;
					var e = l.item(j);
					var _g4 = e.nodeName.toLowerCase();
					switch(_g4) {
					case "entry":
						var key = e.getAttribute("key");
						var val = e.textContent;
						haxor_io_file_Asset.Add(key,val);
						k++;
						break;
					}
				}
				it.remove();
			}
			haxor_core_Console.Log("Haxor> Found " + k + " Strings",2);
		}
	}
	if(app_class_type == "") {
		haxor_core_Console.Log("Haxor> Error. You must define an Application class.");
		return;
	}
	var app_class = Type.resolveClass(app_class_type);
	if(app_class == null) {
		haxor_core_Console.Log("Haxor> Error. Class [" + app_class_type + "] not found! Try adding 'import " + app_class_type + "' in your Main file.");
		return;
	}
	haxor_core_Engine.Initialize();
	var e1 = new haxor_core_Entity("application");
	haxor_platform_html_Entry.m_application = e1.AddComponent(app_class);
	if(!js_Boot.__instanceof(haxor_platform_html_Entry.m_application,haxor_core_BaseApplication)) {
		haxor_core_Console.Log("Haxor> Error. Class [" + app_class_type + "] does not extends Application!");
		return;
	}
	haxor_core_Console.Log("Haxor> Application [" + app_class_type + "] created successfully!",1);
	haxor_platform_html_Entry.m_application.m_container = window.document.getElementById(app_container_id);
	if(haxor_platform_html_Entry.m_application.m_container == null) {
		haxor_core_Console.Log("Graphics> DOM container not defined id[" + app_container_id + "] using 'body'.");
		haxor_platform_html_Entry.m_application.m_container = window.document.body;
	}
	var cd = haxor_platform_html_Entry.m_application.m_container.style.display;
	haxor_platform_html_Entry.m_application.m_container.style.display = "none";
	haxor_graphics_GL.Initialize(haxor_platform_html_Entry.m_application);
	haxor_graphics_GL.m_gl.Initialize(app_container_id);
	haxor_graphics_GL.m_gl.CheckExtensions();
	haxor_core_Console.Log("Haxor> Creating Stage with [" + app_container_id + "]",1);
	var stage = new haxor_dom_DOMStage(haxor_platform_html_Entry.m_application.m_container);
	stage.Parse(haxor_platform_html_Entry.m_application.m_container);
	haxe_Timer.delay(function() {
		haxor_platform_html_Entry.m_application.m_container.style.display = cd;
	},100);
	haxor_context_EngineContext.Build();
	haxor_platform_html_Entry.m_input = new haxor_platform_html_input_HTMLInputHandler(app_input_id);
	haxor_input_Input.m_handler = haxor_platform_html_Entry.m_input;
	if(($_=window,$bind($_,$_.requestAnimationFrame)) != null) window.requestAnimationFrame(haxor_platform_html_Entry.RequestAnimationCallback); else {
		haxor_core_Time.m_clock_0 = haxe_Timer.stamp() * 1000.0;
		haxor_platform_html_Entry.TimeOutLoop();
	}
	if(haxor_platform_html_Entry.m_application.Load()) haxor_platform_html_Entry.m_application.LoadComplete();
};
haxor_platform_html_Entry.RequestAnimationCallback = function(p_time) {
	haxor_core_Time.m_system = p_time;
	haxor_platform_html_Entry.m_application.Update();
	haxor_platform_html_Entry.m_application.Render();
	window.requestAnimationFrame(haxor_platform_html_Entry.RequestAnimationCallback);
	return true;
};
haxor_platform_html_Entry.TimeOutLoop = function() {
	haxor_core_Time.m_system = haxe_Timer.stamp() * 1000.0 - haxor_core_Time.m_clock_0;
	haxor_platform_html_Entry.m_application.Update();
	haxor_platform_html_Entry.m_application.Render();
	window.setTimeout(haxor_platform_html_Entry.TimeOutLoop,10);
};
var haxor_platform_html_graphics_WebGL = function(p_application) {
	haxor_graphics_GraphicContext.call(this,p_application);
	this.m_api = haxor_graphics_GraphicAPI.WebGL;
};
$hxClasses["haxor.platform.html.graphics.WebGL"] = haxor_platform_html_graphics_WebGL;
haxor_platform_html_graphics_WebGL.__name__ = ["haxor","platform","html","graphics","WebGL"];
haxor_platform_html_graphics_WebGL.__super__ = haxor_graphics_GraphicContext;
haxor_platform_html_graphics_WebGL.prototype = $extend(haxor_graphics_GraphicContext.prototype,{
	Initialize: function(p_container_id) {
		var app = this.m_application;
		app.m_container = this.m_container = window.document.getElementById(p_container_id);
		if(this.m_container == null) {
			haxor_core_Console.Log("Graphics> Canvas container not defined id[" + p_container_id + "].");
			return false;
		}
		var _this = window.document;
		this.m_canvas = _this.createElement("canvas");
		this.m_canvas.style.position = "absolute";
		this.m_canvas.style.left = "0px";
		this.m_canvas.style.top = "0px";
		this.m_canvas.style.width = "100%";
		this.m_canvas.style.height = "100%";
		this.m_canvas.width = this.m_container.clientWidth;
		this.m_canvas.height = this.m_container.clientHeight;
		this.m_canvas.id = "haxor-canvas";
		var fc = this.m_container.firstElementChild;
		this.m_container.appendChild(this.m_canvas);
		if(fc != null) this.m_container.insertBefore(this.m_canvas,fc);
		var ctx_attrib = { };
		var ctx_attrib_list = ["alpha","antialias","depth","stencil","premultipliedAlpha","preserveDrawingBuffer"];
		var ctx_attrib_default = [false,false,true,false,true,false];
		haxor_core_Console.Log("Graphics> Initialize WebGL",1);
		var _g1 = 0;
		var _g = ctx_attrib_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			var a = ctx_attrib_list[i];
			var ca = this.m_container.getAttribute(ctx_attrib_list[i]);
			var flag;
			if(ca == null) flag = ctx_attrib_default[i]; else flag = ca == "true";
			haxor_core_Console.Log("\t" + ctx_attrib_list[i] + ": " + (flag == null?"null":"" + flag),1);
			ctx_attrib[a]=flag;
		}
		var attribs = ctx_attrib;
		this.c = js_html__$CanvasElement_CanvasUtil.getContextWebGL(this.m_canvas,attribs);
		if(this.c == null) {
			haxor_core_Console.Log("Graphics> Could not create RenderingContext3D.");
			return false;
		}
		return true;
	}
	,CheckExtensions: function() {
		if(this.c == null) return;
		haxor_core_Console.Log("Graphics> Available Extensions.",1);
		var extensions = this.c.getSupportedExtensions();
		var _g1 = 0;
		var _g = extensions.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(extensions[i].indexOf("MOZ_") >= 0) continue;
			if(extensions[i].indexOf("WEBKIT_") >= 0) continue;
			var ext = this.c.getExtension(extensions[i]);
			haxor_core_Console.Log("\t" + extensions[i],1);
			var _g2 = extensions[i];
			switch(_g2) {
			case "OES_vertex_array_object":
				haxor_graphics_GL.VERTEX_ARRAY_OBJECT = true;
				break;
			case "OES_texture_half_float":
				haxor_graphics_GL.HALF_FLOAT = 36193;
				haxor_graphics_GL.TEXTURE_HALF = true;
				break;
			case "OES_texture_half_float_linear":
				haxor_graphics_GL.TEXTURE_HALF_LINEAR = true;
				break;
			case "EXT_texture_filter_anisotropic":case "WEBKIT_EXT_texture_filter_anisotropic":
				haxor_graphics_GL.TEXTURE_ANISOTROPY = ext.TEXTURE_MAX_ANISOTROPY_EXT;
				haxor_graphics_GL.MAX_TEXTURE_ANISOTROPY = this.c.getParameter(ext.MAX_TEXTURE_MAX_ANISOTROPY_EXT);
				haxor_graphics_GL.TEXTURE_ANISOTROPY_ENABLED = true;
				haxor_core_Console.Log("\t\tMax Aniso: " + haxor_graphics_GL.MAX_TEXTURE_ANISOTROPY,1);
				break;
			case "OES_texture_float":
				haxor_graphics_GL.TEXTURE_FLOAT = true;
				break;
			case "OES_depth_texture":
				haxor_graphics_GL.TEXTURE_DEPTH_ENABLED = true;
				break;
			}
		}
		haxor_graphics_GL.MAX_ACTIVE_TEXTURE = this.c.getParameter(34930);
		haxor_core_Console.Log("\tMax Active Textures: " + haxor_graphics_GL.MAX_ACTIVE_TEXTURE,1);
	}
	,Resize: function() {
		this.m_canvas.width = this.m_container.clientWidth;
		this.m_canvas.height = this.m_container.clientHeight;
	}
	,CreateBuffer: function() {
		return this.c.createBuffer();
	}
	,BindBuffer: function(p_target,p_id) {
		this.c.bindBuffer(p_target,p_id);
	}
	,BufferData: function(p_target,p_data,p_mode) {
		this.c.bufferData(p_target,p_data.m_buffer,p_mode);
	}
	,BufferSubData: function(p_target,p_offset,p_data) {
		this.c.bufferSubData(p_target,p_offset,p_data.m_buffer);
	}
	,DeleteBuffer: function(p_id) {
		this.c.deleteBuffer(p_id);
	}
	,DrawArrays: function(p_primitive,p_start,p_count) {
		this.c.drawArrays(p_primitive,p_start,p_count);
	}
	,DrawElements: function(p_primitive,p_count,p_type,p_offset) {
		this.c.drawElements(p_primitive,p_count,p_type,p_offset);
	}
	,DisableVertexAttrib: function(p_location) {
		this.c.disableVertexAttribArray(p_location);
	}
	,EnableVertexAttrib: function(p_location) {
		this.c.enableVertexAttribArray(p_location);
	}
	,VertexAttrib3f: function(p_location,p_x,p_y,p_z) {
		this.c.vertexAttrib3f(p_location,p_x,p_y,p_z);
	}
	,VertexAttrib4f: function(p_location,p_x,p_y,p_z,p_w) {
		this.c.vertexAttrib4f(p_location,p_x,p_y,p_z,p_w);
	}
	,VertexAttribPointer: function(p_location,p_components_size,p_type,p_normalized,p_stride,p_offset) {
		this.c.vertexAttribPointer(p_location,p_components_size,p_type,p_normalized,p_stride,p_offset);
	}
	,CompileShader: function(p_shader) {
		this.c.compileShader(p_shader);
	}
	,CreateShader: function(p_type) {
		return this.c.createShader(p_type);
	}
	,DetachShader: function(p_program,p_shader) {
		this.c.detachShader(p_program,p_shader);
	}
	,DeleteShader: function(p_shader) {
		this.c.deleteShader(p_shader);
	}
	,GetShaderInfoLog: function(p_shader) {
		return this.c.getShaderInfoLog(p_shader);
	}
	,GetShaderParameter: function(p_shader,p_parameter) {
		return this.c.getShaderParameter(p_shader,p_parameter);
	}
	,ShaderSource: function(p_shader,p_source) {
		this.c.shaderSource(p_shader,p_source);
	}
	,AttachShader: function(p_program,p_shader) {
		this.c.attachShader(p_program,p_shader);
	}
	,BindAttribLocation: function(p_program,p_location,p_name) {
		this.c.bindAttribLocation(p_program,p_location,p_name);
	}
	,CreateProgram: function() {
		return this.c.createProgram();
	}
	,DeleteProgram: function(p_program) {
		this.c.deleteProgram(p_program);
	}
	,GetAttribLocation: function(p_program,p_name) {
		return this.c.getAttribLocation(p_program,p_name);
	}
	,GetUniformLocation: function(p_program,p_name) {
		return this.c.getUniformLocation(p_program,p_name);
	}
	,GetProgramInfoLog: function(p_program) {
		return this.c.getProgramInfoLog(p_program);
	}
	,GetProgramParameter: function(p_program,p_parameter) {
		return this.c.getProgramParameter(p_program,p_parameter);
	}
	,LinkProgram: function(p_program) {
		this.c.linkProgram(p_program);
	}
	,UseProgram: function(p_program) {
		this.c.useProgram(p_program);
	}
	,ActiveTexture: function(p_slot) {
		this.c.activeTexture(p_slot);
	}
	,BindFramebuffer: function(p_target,p_id) {
		this.c.bindFramebuffer(p_target,p_id);
	}
	,BindRenderbuffer: function(p_target,p_id) {
		this.c.bindRenderbuffer(p_target,p_id);
	}
	,BindTexture: function(p_target,p_id) {
		this.c.bindTexture(p_target,p_id);
	}
	,CreateFramebuffer: function() {
		return this.c.createFramebuffer();
	}
	,CreateRenderbuffer: function() {
		return this.c.createRenderbuffer();
	}
	,CreateTexture: function() {
		return this.c.createTexture();
	}
	,DeleteFramebuffer: function(p_id) {
		this.c.deleteFramebuffer(p_id);
	}
	,DeleteRenderbuffer: function(p_id) {
		this.c.deleteRenderbuffer(p_id);
	}
	,DeleteTexture: function(p_id) {
		this.c.deleteTexture(p_id);
	}
	,FramebufferRenderbuffer: function(p_target,p_attachment,p_renderbuffer_target,p_renderbuffer_id) {
		this.c.framebufferRenderbuffer(p_target,p_attachment,p_renderbuffer_target,p_renderbuffer_id);
	}
	,FramebufferTexture2D: function(p_target,p_attachment,p_texture_target,p_texture_id,p_miplevel) {
		this.c.framebufferTexture2D(p_target,p_attachment,p_texture_target,p_texture_id,p_miplevel);
	}
	,GenerateMipmap: function(p_target) {
		this.c.generateMipmap(p_target);
	}
	,PixelStorei: function(p_parameter,p_value) {
		this.c.pixelStorei(p_parameter,p_value);
	}
	,RenderbufferStorage: function(p_target,p_format,p_width,p_height) {
		this.c.renderbufferStorage(p_target,p_format,p_width,p_height);
	}
	,TexImage2D: function(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type,p_data) {
		this.c.texImage2D(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type,p_data.aux);
	}
	,TexImage2DAlloc: function(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type) {
		this.c.texImage2D(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type,null);
	}
	,TexSubImage2D: function(p_target,p_level,p_x,p_y,p_width,p_height,p_format,p_channel_type,p_data) {
		this.c.texSubImage2D(p_target,p_level,p_x,p_y,p_width,p_height,p_format,p_channel_type,p_data.aux);
	}
	,TexParameterf: function(p_target,p_parameter,p_value) {
		this.c.texParameterf(p_target,p_parameter,p_value);
	}
	,TexParameteri: function(p_target,p_parameter,p_value) {
		this.c.texParameteri(p_target,p_parameter,p_value);
	}
	,BlendFunc: function(p_src,p_dst) {
		this.c.blendFunc(p_src,p_dst);
	}
	,Disable: function(p_flag) {
		this.c.disable(p_flag);
	}
	,Enable: function(p_flag) {
		this.c.enable(p_flag);
	}
	,DepthMask: function(p_flag) {
		this.c.depthMask(p_flag);
	}
	,DepthFunc: function(p_flag) {
		this.c.depthFunc(p_flag);
	}
	,CullFace: function(p_face) {
		this.c.cullFace(p_face);
	}
	,FrontFace: function(p_face) {
		this.c.frontFace(p_face);
	}
	,Uniform1f: function(p_location,p_x) {
		this.c.uniform1f(p_location,p_x);
	}
	,Uniform2f: function(p_location,p_x,p_y) {
		this.c.uniform2f(p_location,p_x,p_y);
	}
	,Uniform3f: function(p_location,p_x,p_y,p_z) {
		this.c.uniform3f(p_location,p_x,p_y,p_z);
	}
	,Uniform4f: function(p_location,p_x,p_y,p_z,p_w) {
		this.c.uniform4f(p_location,p_x,p_y,p_z,p_w);
	}
	,Uniform1i: function(p_location,p_x) {
		this.c.uniform1i(p_location,p_x);
	}
	,Uniform2i: function(p_location,p_x,p_y) {
		this.c.uniform2i(p_location,p_x,p_y);
	}
	,Uniform3i: function(p_location,p_x,p_y,p_z) {
		this.c.uniform3i(p_location,p_x,p_y,p_z);
	}
	,Uniform4i: function(p_location,p_x,p_y,p_z,p_w) {
		this.c.uniform4i(p_location,p_x,p_y,p_z,p_w);
	}
	,Uniform1fv: function(p_location,p_v) {
		this.c.uniform1fv(p_location,p_v.aux);
	}
	,Uniform2fv: function(p_location,p_v) {
		this.c.uniform2fv(p_location,p_v.aux);
	}
	,Uniform3fv: function(p_location,p_v) {
		this.c.uniform3fv(p_location,p_v.aux);
	}
	,Uniform4fv: function(p_location,p_v) {
		this.c.uniform4fv(p_location,p_v.aux);
	}
	,Uniform1iv: function(p_location,p_v) {
		this.c.uniform1iv(p_location,p_v.aux);
	}
	,Uniform2iv: function(p_location,p_v) {
		this.c.uniform2iv(p_location,p_v.aux);
	}
	,Uniform3iv: function(p_location,p_v) {
		this.c.uniform3iv(p_location,p_v.aux);
	}
	,Uniform4iv: function(p_location,p_v) {
		this.c.uniform4iv(p_location,p_v.aux);
	}
	,UniformMatrix2fv: function(p_location,p_transpose,p_v) {
		this.c.uniformMatrix2fv(p_location,p_transpose,p_v.aux);
	}
	,UniformMatrix3fv: function(p_location,p_transpose,p_v) {
		this.c.uniformMatrix3fv(p_location,p_transpose,p_v.aux);
	}
	,UniformMatrix4fv: function(p_location,p_transpose,p_v) {
		this.c.uniformMatrix4fv(p_location,p_transpose,p_v.aux);
	}
	,Clear: function(p_flag) {
		this.c.clear(p_flag);
	}
	,ClearDepth: function(p_value) {
		this.c.clearDepth(p_value);
	}
	,ClearColor: function(p_r,p_g,p_b,p_a) {
		this.c.clearColor(p_r,p_g,p_b,p_a);
	}
	,Viewport: function(p_x,p_y,p_width,p_height) {
		this.c.viewport(p_x,p_y,p_width,p_height);
	}
	,Scissor: function(p_x,p_y,p_width,p_height) {
		this.c.scissor(p_x,p_y,p_width,p_height);
	}
	,ReadPixels: function(p_x,p_y,p_width,p_height,p_format,p_type,p_pixels) {
		this.c.readPixels(p_x,p_y,p_width,p_height,p_format,p_type,p_pixels.m_buffer);
	}
	,Flush: function() {
	}
	,GetErrorCode: function() {
		return this.c.getError();
	}
	,__class__: haxor_platform_html_graphics_WebGL
});
var haxor_platform_html_input_HTMLInputHandler = function(p_target_id) {
	haxor_input_InputHandler.call(this);
	this.m_navigator = window.navigator;
	this.m_target = window.document.getElementById(p_target_id);
	if(this.m_target == null) {
		haxor_core_Console.LogWarning("Input> Target Element not found! Using [document] as target.");
		this.m_target = window.document.body;
	}
	this.m_events = [];
	this.m_target.onmousedown = $bind(this,this.OnInputEvent);
	this.m_target.onmouseover = $bind(this,this.OnInputEvent);
	this.m_target.onmousewheel = $bind(this,this.OnInputEvent);
	this.m_target.oncontextmenu = $bind(this,this.OnInputEvent);
	window.document.onmousemove = $bind(this,this.OnInputEvent);
	window.document.onmouseup = $bind(this,this.OnInputEvent);
	window.document.onkeydown = $bind(this,this.OnInputEvent);
	window.document.onkeyup = $bind(this,this.OnInputEvent);
	try {
		this.m_target.addEventListener("DOMMouseScroll",$bind(this,this.OnInputEvent));
	} catch( ex ) {
	}
	try {
		haxor_input_Input.m_multitouch = TouchEvent != null;
	} catch( ex1 ) {
		haxor_input_Input.m_multitouch = false;
	}
	if(haxor_input_Input.get_multitouch()) {
		this.m_target.ontouchstart = $bind(this,this.OnTouchEvent);
		window.document.ontouchmove = $bind(this,this.OnTouchEvent);
		window.document.ontouchcancel = $bind(this,this.OnTouchEvent);
		window.document.ontouchend = $bind(this,this.OnTouchEvent);
	}
	var t = this.m_target;
	var nav = this.m_navigator;
	this.m_check_joystick = !(!nav.getGamepads) || nav.userAgent.indexOf("Firefox/") != -1;
};
$hxClasses["haxor.platform.html.input.HTMLInputHandler"] = haxor_platform_html_input_HTMLInputHandler;
haxor_platform_html_input_HTMLInputHandler.__name__ = ["haxor","platform","html","input","HTMLInputHandler"];
haxor_platform_html_input_HTMLInputHandler.__super__ = haxor_input_InputHandler;
haxor_platform_html_input_HTMLInputHandler.prototype = $extend(haxor_input_InputHandler.prototype,{
	UpdateInput: function() {
		if(this.m_events.length > 0) while(this.m_events.length > 0) this.ProcessInputEvent(this.m_events.shift());
		this.UpdateJoystick();
	}
	,OnInputEvent: function(p_event) {
		var e;
		if(p_event == null) e = window.event; else e = p_event;
		var c;
		c = e;
		this.m_events.push(c);
		var is_mousedown = c.type == "mousedown";
		var is_mousewheel = c.type == "mousewheel" || c.type == "wheel";
		var prevent = is_mousedown || is_mousewheel;
		prevent = prevent && js_Boot.__instanceof(this.m_target,HTMLCanvasElement);
		if(haxor_input_Input.scroll) prevent = false;
		if(c.type == "contextmenu") {
			if(!haxor_input_Input.menu) prevent = true;
		}
		if(prevent) {
			if(haxor_input_Input.relativeMouse.x >= 0) {
				if(haxor_input_Input.relativeMouse.x <= 1) {
					if(haxor_input_Input.relativeMouse.y >= 0) {
						if(haxor_input_Input.relativeMouse.y <= 1) {
							if($bind(e,e.preventDefault) != null) e.preventDefault();
						}
					}
				}
			}
		}
	}
	,ProcessInputEvent: function(p_event) {
		var me = p_event;
		var ke = p_event;
		var element = p_event.target;
		var _g = p_event.type;
		switch(_g) {
		case "wheel":case "mousewheel":case "DOMMouseScroll":
			var we = p_event;
			var dw;
			if(we.wheelDeltaY == null) dw = we.detail * 40; else dw = we.wheelDeltaY;
			this.OnMouseWheel(dw / 100.0);
			break;
		case "mousemove":
			var px = me.pageX;
			var py = me.pageY;
			if(px == null) px = me.clientX;
			if(py == null) py = me.clientY;
			var p = this.GetAbsolutePosition(this.m_target,px,py);
			this.OnMouseMove(p.x,p.y);
			break;
		case "mouseup":
			this.OnMouseButton(me.button,false);
			break;
		case "mousedown":
			this.OnMouseButton(me.button,true);
			break;
		case "keyup":
			this.OnKey(ke.keyCode,false);
			break;
		case "keydown":
			this.OnKey(ke.keyCode,true);
			break;
		case "contextmenu":
			break;
		}
	}
	,OnTouchEvent: function(p_event) {
		var te = p_event;
		var _g1 = 0;
		var _g = te.changedTouches.length;
		while(_g1 < _g) {
			var i = _g1++;
			var t = te.changedTouches.item(i);
			var p = this.GetAbsolutePosition(this.m_target,t.pageX,t.pageY);
			var _g2 = p_event.type;
			switch(_g2) {
			case "touchstart":
				this.OnTouchStart(t.identifier,p.x,p.y,t.radiusX,t.radiusY,t.force,t.rotationAngle);
				break;
			case "touchmove":
				this.OnTouchMove(t.identifier,p.x,p.y);
				break;
			case "touchcancel":
				this.OnTouchCancel(t.identifier);
				break;
			case "touchend":
				this.OnTouchEnd(t.identifier);
				break;
			}
		}
		if(haxor_input_Input.m_touches.length > 0) {
			if(!haxor_input_Input.scroll) p_event.preventDefault();
		}
	}
	,UpdateJoystick: function() {
		if(!this.m_check_joystick) return;
		var nav = this.m_navigator;
		var l = null;
		if(nav.getGamepads != null) l = nav.getGamepads();
		if(l == null) return;
		if(l.length <= 0) return;
		var _g1 = 0;
		var _g = l.length;
		while(_g1 < _g) {
			var i = _g1++;
			var gp = l.item(i);
			if(gp == null) continue;
			this.OnJoystickStart(gp.index,gp.id);
			var _g3 = 0;
			var _g2 = gp.buttons.length;
			while(_g3 < _g2) {
				var i1 = _g3++;
				var bt = gp.buttons[i1];
				this.OnJoystickDataUpdate(i1,bt.value,false);
			}
			var _g31 = 0;
			var _g21 = gp.axes.length;
			while(_g31 < _g21) {
				var i2 = _g31++;
				this.OnJoystickDataUpdate(i2,gp.axes[i2],true);
			}
			this.OnJoystickAnalogUpdate();
		}
	}
	,GetAbsolutePosition: function(p_element,p_x,p_y) {
		var px = 0;
		var py = 0;
		var e = p_element;
		do {
			px += e.offsetLeft;
			py += e.offsetTop;
			e = e.offsetParent;
		} while(e != null);
		px = p_x - px;
		py = p_y - py;
		return haxor_context_EngineContext.data.get_v2().Set(px,py);
	}
	,__class__: haxor_platform_html_input_HTMLInputHandler
});
var js_Boot = function() { };
$hxClasses["js.Boot"] = js_Boot;
js_Boot.__name__ = ["js","Boot"];
js_Boot.getClass = function(o) {
	if((o instanceof Array) && o.__enum__ == null) return Array; else return o.__class__;
};
js_Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (o.__name__ || o.__ename__)) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__) {
				if(o.length == 2) return o[0];
				var str = o[0] + "(";
				s += "\t";
				var _g1 = 2;
				var _g = o.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(i != 2) str += "," + js_Boot.__string_rec(o[i],s); else str += js_Boot.__string_rec(o[i],s);
				}
				return str + ")";
			}
			var l = o.length;
			var i1;
			var str1 = "[";
			s += "\t";
			var _g2 = 0;
			while(_g2 < l) {
				var i2 = _g2++;
				str1 += (i2 > 0?",":"") + js_Boot.__string_rec(o[i2],s);
			}
			str1 += "]";
			return str1;
		}
		var tostr;
		try {
			tostr = o.toString;
		} catch( e ) {
			return "???";
		}
		if(tostr != null && tostr != Object.toString) {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str2 = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) {
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__" || k == "__properties__") {
			continue;
		}
		if(str2.length != 2) str2 += ", \n";
		str2 += s + k + " : " + js_Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str2 += "\n" + s + "}";
		return str2;
	case "function":
		return "<function>";
	case "string":
		return o;
	default:
		return String(o);
	}
};
js_Boot.__interfLoop = function(cc,cl) {
	if(cc == null) return false;
	if(cc == cl) return true;
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0;
		var _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js_Boot.__interfLoop(i1,cl)) return true;
		}
	}
	return js_Boot.__interfLoop(cc.__super__,cl);
};
js_Boot.__instanceof = function(o,cl) {
	if(cl == null) return false;
	switch(cl) {
	case Int:
		return (o|0) === o;
	case Float:
		return typeof(o) == "number";
	case Bool:
		return typeof(o) == "boolean";
	case String:
		return typeof(o) == "string";
	case Array:
		return (o instanceof Array) && o.__enum__ == null;
	case Dynamic:
		return true;
	default:
		if(o != null) {
			if(typeof(cl) == "function") {
				if(o instanceof cl) return true;
				if(js_Boot.__interfLoop(js_Boot.getClass(o),cl)) return true;
			}
		} else return false;
		if(cl == Class && o.__name__ != null) return true;
		if(cl == Enum && o.__ename__ != null) return true;
		return o.__enum__ == cl;
	}
};
js_Boot.__cast = function(o,t) {
	if(js_Boot.__instanceof(o,t)) return o; else throw "Cannot cast " + Std.string(o) + " to " + Std.string(t);
};
var js_html__$CanvasElement_CanvasUtil = function() { };
$hxClasses["js.html._CanvasElement.CanvasUtil"] = js_html__$CanvasElement_CanvasUtil;
js_html__$CanvasElement_CanvasUtil.__name__ = ["js","html","_CanvasElement","CanvasUtil"];
js_html__$CanvasElement_CanvasUtil.getContextWebGL = function(canvas,attribs) {
	var _g = 0;
	var _g1 = ["webgl","experimental-webgl"];
	while(_g < _g1.length) {
		var name = _g1[_g];
		++_g;
		var ctx = canvas.getContext(name,attribs);
		if(ctx != null) return ctx;
	}
	return null;
};
var $_, $fid = 0;
function $bind(o,m) { if( m == null ) return null; if( m.__id__ == null ) m.__id__ = $fid++; var f; if( o.hx__closures__ == null ) o.hx__closures__ = {}; else f = o.hx__closures__[m.__id__]; if( f == null ) { f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; o.hx__closures__[m.__id__] = f; } return f; }
Math.NaN = Number.NaN;
Math.NEGATIVE_INFINITY = Number.NEGATIVE_INFINITY;
Math.POSITIVE_INFINITY = Number.POSITIVE_INFINITY;
$hxClasses.Math = Math;
Math.isFinite = function(i) {
	return isFinite(i);
};
Math.isNaN = function(i1) {
	return isNaN(i1);
};
String.prototype.__class__ = $hxClasses.String = String;
String.__name__ = ["String"];
$hxClasses.Array = Array;
Array.__name__ = ["Array"];
Date.prototype.__class__ = $hxClasses.Date = Date;
Date.__name__ = ["Date"];
var Int = $hxClasses.Int = { __name__ : ["Int"]};
var Dynamic = $hxClasses.Dynamic = { __name__ : ["Dynamic"]};
var Float = $hxClasses.Float = Number;
Float.__name__ = ["Float"];
var Bool = Boolean;
Bool.__ename__ = ["Bool"];
var Class = $hxClasses.Class = { __name__ : ["Class"]};
var Enum = { };
Xml.Element = "element";
Xml.PCData = "pcdata";
Xml.CData = "cdata";
Xml.Comment = "comment";
Xml.DocType = "doctype";
Xml.ProcessingInstruction = "processingInstruction";
Xml.Document = "document";
haxe_crypto_Base64.CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
haxe_crypto_Base64.BYTES = haxe_io_Bytes.ofString(haxe_crypto_Base64.CHARS);
haxe_ds_ObjectMap.count = 0;
haxe_xml_Parser.escapes = (function($this) {
	var $r;
	var h = new haxe_ds_StringMap();
	h.set("lt","<");
	h.set("gt",">");
	h.set("amp","&");
	h.set("quot","\"");
	h.set("apos","'");
	h.set("nbsp",String.fromCharCode(160));
	$r = h;
	return $r;
}(this));
haxor_component_animation_FloatKeyFrame.m_temp = new haxor_component_animation_FloatKeyFrame();
haxor_component_animation_Vector3KeyFrame.m_temp = new haxor_component_animation_Vector3KeyFrame();
haxor_component_animation_QuaternionKeyFrame.m_temp = new haxor_component_animation_QuaternionKeyFrame();
haxor_component_light_Light.ambient = new haxor_math_Color(0.0,0.0,0.0,1.0);
haxor_component_light_Light.max = 8;
haxor_component_light_Light.m_list = [];
haxor_context_DataContext.MAX_TEMP = 128;
haxor_context_EngineContext.uid = 0;
haxor_context_EngineContext.maxNodes = 5000;
haxor_context_EngineContext.collectRate = 10;
haxor_context_BaseProcess.m_cid = 0;
haxor_context_ShaderContext.flat_source = "\r\n\t<shader id=\"haxor/unlit/Flat\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\t\t\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\tv_color = color * Tint;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) { gl_FragColor = v_color; }\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
haxor_context_ShaderContext.flat_texture_source = "\r\n\t<shader id=\"haxor/unlit/FlatTexture\">\t\r\n\t\t<vertex>\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\t\r\n\t\tattribute vec4 color;\r\n\t\tattribute vec3 uv0;\t\t\r\n\t\tvarying vec3 v_uv0;\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\tv_uv0   = uv0;\r\n\t\t\tv_color = color;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\r\n\t\t\tvarying vec3 v_uv0;\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tuniform sampler2D DiffuseTexture;\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);\t\r\n\t\t\t\tgl_FragColor.xyz = (tex_diffuse.xyz * v_color.xyz);\r\n\t\t\t\tgl_FragColor.a \t = tex_diffuse.a * v_color.a;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t";
haxor_context_ShaderContext.flat_texture_skin_source = "\r\n\t<shader id=\"haxor/unlit/FlatTextureSkin\">\t\r\n\t\t<vertex precision=\"low\">\r\n\t\t\r\n\t\t#define SKINNING_TEXTURE_SIZE 2048.0\r\n\t\t#define BINDS_OFFSET\t\t  1024.0\r\n\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  WorldMatrixIT;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\r\n\t\tuniform vec3  WSCameraPosition;\t\t\r\n\t\t\r\n\t\t//uniform vec4  Skinning[MAX_BONES];\r\n\t\t\r\n\t\tuniform sampler2D Skinning;\r\n\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\t\r\n\t\tattribute vec4 color;\r\n\t\tattribute vec3 normal;\r\n\t\tattribute vec3 uv0;\r\n\t\tattribute vec4 bone;\r\n\t\tattribute vec4 weight;\r\n\t\t\r\n\t\tvarying vec3 v_uv0;\r\n\t\tvarying vec3 v_normal;\r\n\t\tvarying vec4 v_color;\r\n\t\tvarying vec4 v_wsVertex;\r\n\t\tvarying vec3 v_wsView;\t\r\n\t\t\r\n\t\tvec4 SkinningRead(float id)\r\n\t\t{\r\n\t\t\treturn texture2D(Skinning, vec2(0.0,(id/(SKINNING_TEXTURE_SIZE-1.0))));\r\n\t\t}\r\n\t\t\r\n\t\tmat4 GetSkinMatrix(float b,float o)\r\n\t\t{\r\n\t\t\tvec4 l0, l1, l2;\t\t\t\t\t\t\r\n\t\t\tl0 = SkinningRead(b+o); l1 = SkinningRead(b+1.0+o); l2 = SkinningRead(b+2.0+o);\r\n\t\t\treturn mat4(l0.x, l0.y, l0.z, l0.w, l1.x, l1.y, l1.z, l1.w, l2.x, l2.y, l2.z, l2.w, 0, 0, 0, 1);\t\t\t\r\n\t\t}\r\n\t\t\r\n\t\tmat4 SkinWorldMatrix()\r\n\t\t{\r\n\t\t\tvec4 b = bone * 3.0;\r\n\t\t\tvec4 w = weight;\r\n\t\t\tfloat ivs = 1.0 / (weight.x + weight.y + weight.z + weight.w);\r\n\t\t\tw *= ivs;\r\n\t\t\tmat4 j0 = GetSkinMatrix(b[0],0.0);\r\n\t\t\tmat4 b0 = GetSkinMatrix(b[0],BINDS_OFFSET);\r\n\t\t\tmat4 j1 = GetSkinMatrix(b[1],0.0);\r\n\t\t\tmat4 b1 = GetSkinMatrix(b[1],BINDS_OFFSET);\r\n\t\t\tmat4 j2 = GetSkinMatrix(b[2],0.0);\r\n\t\t\tmat4 b2 = GetSkinMatrix(b[2],BINDS_OFFSET);\r\n\t\t\tmat4 j3 = GetSkinMatrix(b[3],0.0);\r\n\t\t\tmat4 b3 = GetSkinMatrix(b[3],BINDS_OFFSET);\r\n\t\t\t\r\n\t\t\treturn    ((b0 * j0) * w[0])+\r\n\t\t\t          ((b1 * j1) * w[1])+\r\n\t\t\t          ((b2 * j2) * w[2])+\r\n\t\t\t          ((b3 * j3) * w[3]);\r\n\t\t\t\r\n\t\t\t\r\n\t\t}\r\n\t\t\t\t\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\r\n\t\t\tvec4 lv = vec4(vertex,1.0);\r\n\t\t\tvec3 ln = vec3(normal);\r\n\t\t\tmat4 swm = SkinWorldMatrix();\r\n\t\t\tmat4 wm;\t\t\t\t\t\r\n\t\t\twm = swm;\r\n\t\t\t//wm = WorldMatrix;\r\n\t\t\t\r\n\t\t\tv_uv0   = uv0;\r\n\t\t\tv_color = color;\t\t\t\r\n\t\t\tv_normal = ln * mat3(WorldMatrixIT);\t\t\t\r\n\t\t\tgl_Position = ((lv * wm) * ViewMatrix) * ProjectionMatrix;\r\n\t\t}\t\t\r\n\t\t</vertex>\r\n\t\t\r\n\t\t<fragment precision=\"low\">\r\n\t\t\t\t\t\r\n\t\t\tuniform sampler2D DiffuseTexture;\t\t\t\r\n\t\t\t\r\n\t\t\tuniform sampler2D Skinning;\r\n\t\t\t\r\n\t\t\tvarying vec3 v_uv0;\r\n\t\t\tvarying vec4 v_color;\r\n\t\t\tvarying vec3 v_normal;\r\n\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);\r\n\t\t\t\tgl_FragColor.xyz = tex_diffuse.xyz * v_color.xyz;\r\n\t\t\t\tgl_FragColor.a \t = tex_diffuse.a * v_color.a;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t";
haxor_context_ShaderContext.gizmo_source = "\r\n\t<shader id=\"haxor/gizmo/Grid\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\r\n\t\tuniform float Area;\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\tgl_Position = ((vec4(vertex*Area, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\tv_color = color * Tint;\t\t\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\r\n\t\t\t\tgl_FragColor = v_color;\r\n\t\t\t}\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
haxor_context_ShaderContext.texture_source = "\r\n\t<shader id=\"haxor/gizmo/Texture\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform vec2  Screen;\r\n\t\tuniform vec4  Rect;\r\n\t\tuniform vec4  Tint;\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\r\n\t\tvarying vec4 v_color;\r\n\t\tvarying vec2 v_uv0;\r\n\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tvec4 p = vec4(vertex, 1);\r\n\t\t\tfloat sw = Screen.x * 0.5;\r\n\t\t\tfloat sh = Screen.y * 0.5;\r\n\t\t\tp.x *= Rect.z / sw;\r\n\t\t\tp.y *= Rect.w / sh;\r\n\t\t\tp.x += Rect.x / sw;\r\n\t\t\tp.y -= Rect.y / sh;\t\t\t\r\n\t\t\tp.x -= 1.0;\r\n\t\t\tp.y += 1.0;\t\t\t\r\n\t\t\tp.z = 0.001;\r\n\t\t\tgl_Position = p;\r\n\t\t\tv_color = Tint;\t\t\r\n\t\t\tv_uv0   = vec2(vertex.x,1.0+vertex.y);\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\r\n\t\t\tvarying vec2 v_uv0;\r\n\t\t\tuniform sampler2D Texture;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\r\n\t\t\t\tgl_FragColor = texture2D(Texture, v_uv0) * v_color;\r\n\t\t\t}\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
haxor_core_Console.m_style = "";
haxor_core_Console.verbose = 0;
haxor_core_RenderQueue.Background = 0;
haxor_core_RenderQueue.Opaque = 1000;
haxor_core_RenderQueue.Transparent = 2000;
haxor_core_RenderQueue.Overlay = 3000;
haxor_core_RenderQueue.Interface = 4000;
haxor_core_BlendMode.Zero = 0;
haxor_core_BlendMode.One = 1;
haxor_core_BlendMode.SrcColor = 768;
haxor_core_BlendMode.OneMinusSrcColor = 769;
haxor_core_BlendMode.SrcAlpha = 770;
haxor_core_BlendMode.OneMinusSrcAlpha = 771;
haxor_core_BlendMode.DstAlpha = 772;
haxor_core_BlendMode.OneMinusDstAlpha = 773;
haxor_core_BlendMode.DstColor = 774;
haxor_core_BlendMode.OneMinusDstColor = 775;
haxor_core_BlendMode.SrcAlphaSaturate = 776;
haxor_core_MeshMode.StaticDraw = 35044;
haxor_core_MeshMode.StreamDraw = 35040;
haxor_core_MeshMode.DynamicDraw = 35048;
haxor_core_MeshPrimitive.Points = 0;
haxor_core_MeshPrimitive.Triangles = 4;
haxor_core_MeshPrimitive.TriangleStrip = 5;
haxor_core_MeshPrimitive.TriangleFan = 6;
haxor_core_MeshPrimitive.Lines = 1;
haxor_core_MeshPrimitive.LineLoop = 2;
haxor_core_MeshPrimitive.LineStrip = 3;
haxor_core_CullMode.None = 0;
haxor_core_CullMode.Front = 1;
haxor_core_CullMode.Back = 2;
haxor_core_DepthTest.Never = 512;
haxor_core_DepthTest.Less = 513;
haxor_core_DepthTest.Equal = 514;
haxor_core_DepthTest.LessEqual = 515;
haxor_core_DepthTest.Greater = 516;
haxor_core_DepthTest.NotEqual = 517;
haxor_core_DepthTest.GreaterEqual = 518;
haxor_core_DepthTest.Always = 519;
haxor_core_TextureWrap.ClampX = 1;
haxor_core_TextureWrap.RepeatX = 2;
haxor_core_TextureWrap.ClampY = 4;
haxor_core_TextureWrap.RepeatY = 8;
haxor_core_TextureWrap.ClampZ = 16;
haxor_core_TextureWrap.RepeatZ = 32;
haxor_core_ClearFlag.None = 0;
haxor_core_ClearFlag.Color = 1;
haxor_core_ClearFlag.Depth = 2;
haxor_core_ClearFlag.Skybox = 4;
haxor_core_ClearFlag.ColorDepth = 3;
haxor_core_ClearFlag.SkyboxDepth = 6;
haxor_dom_LayoutFlag.PivotX = 1;
haxor_dom_LayoutFlag.PivotY = 2;
haxor_dom_LayoutFlag.PivotXY = 3;
haxor_dom_LayoutFlag.PositionX = 4;
haxor_dom_LayoutFlag.PositionY = 8;
haxor_dom_LayoutFlag.PositionXY = 12;
haxor_dom_LayoutFlag.SizeX = 16;
haxor_dom_LayoutFlag.SizeY = 32;
haxor_dom_LayoutFlag.SizeXY = 48;
haxor_graphics_GL.ACTIVE_ATTRIBUTES = 35721;
haxor_graphics_GL.ACTIVE_TEXTURE = 34016;
haxor_graphics_GL.ACTIVE_UNIFORMS = 35718;
haxor_graphics_GL.ALIASED_LINE_WIDTH_RANGE = 33902;
haxor_graphics_GL.ALIASED_POINT_SIZE_RANGE = 33901;
haxor_graphics_GL.ALPHA = 6406;
haxor_graphics_GL.ALPHA_BITS = 3413;
haxor_graphics_GL.ALWAYS = 519;
haxor_graphics_GL.ARRAY_BUFFER = 34962;
haxor_graphics_GL.ARRAY_BUFFER_BINDING = 34964;
haxor_graphics_GL.ATTACHED_SHADERS = 35717;
haxor_graphics_GL.BACK = 1029;
haxor_graphics_GL.BLEND = 3042;
haxor_graphics_GL.BLEND_COLOR = 32773;
haxor_graphics_GL.BLEND_DST_ALPHA = 32970;
haxor_graphics_GL.BLEND_DST_RGB = 32968;
haxor_graphics_GL.BLEND_EQUATION = 32777;
haxor_graphics_GL.BLEND_EQUATION_ALPHA = 34877;
haxor_graphics_GL.BLEND_EQUATION_RGB = 32777;
haxor_graphics_GL.BLEND_SRC_ALPHA = 32971;
haxor_graphics_GL.BLEND_SRC_RGB = 32969;
haxor_graphics_GL.BLUE_BITS = 3412;
haxor_graphics_GL.BOOL = 35670;
haxor_graphics_GL.BOOL_VEC2 = 35671;
haxor_graphics_GL.BOOL_VEC3 = 35672;
haxor_graphics_GL.BOOL_VEC4 = 35673;
haxor_graphics_GL.BROWSER_DEFAULT_WEBGL = 37444;
haxor_graphics_GL.BUFFER_SIZE = 34660;
haxor_graphics_GL.BUFFER_USAGE = 34661;
haxor_graphics_GL.BYTE = 5120;
haxor_graphics_GL.CCW = 2305;
haxor_graphics_GL.CLAMP_TO_EDGE = 33071;
haxor_graphics_GL.COLOR_ATTACHMENT0 = 36064;
haxor_graphics_GL.COLOR_BUFFER_BIT = 16384;
haxor_graphics_GL.COLOR_CLEAR_VALUE = 3106;
haxor_graphics_GL.COLOR_WRITEMASK = 3107;
haxor_graphics_GL.COMPILE_STATUS = 35713;
haxor_graphics_GL.COMPRESSED_TEXTURE_FORMATS = 34467;
haxor_graphics_GL.CONSTANT_ALPHA = 32771;
haxor_graphics_GL.CONSTANT_COLOR = 32769;
haxor_graphics_GL.CONTEXT_LOST_WEBGL = 37442;
haxor_graphics_GL.CULL_FACE = 2884;
haxor_graphics_GL.CULL_FACE_MODE = 2885;
haxor_graphics_GL.CURRENT_PROGRAM = 35725;
haxor_graphics_GL.CURRENT_VERTEX_ATTRIB = 34342;
haxor_graphics_GL.CW = 2304;
haxor_graphics_GL.DECR = 7683;
haxor_graphics_GL.DECR_WRAP = 34056;
haxor_graphics_GL.DELETE_STATUS = 35712;
haxor_graphics_GL.DEPTH_ATTACHMENT = 36096;
haxor_graphics_GL.DEPTH_BITS = 3414;
haxor_graphics_GL.DEPTH_BUFFER_BIT = 256;
haxor_graphics_GL.DEPTH_CLEAR_VALUE = 2931;
haxor_graphics_GL.DEPTH_COMPONENT = 6402;
haxor_graphics_GL.DEPTH_COMPONENT16 = 33189;
haxor_graphics_GL.DEPTH_FUNC = 2932;
haxor_graphics_GL.DEPTH_RANGE = 2928;
haxor_graphics_GL.DEPTH_STENCIL = 34041;
haxor_graphics_GL.DEPTH_STENCIL_ATTACHMENT = 33306;
haxor_graphics_GL.DEPTH_TEST = 2929;
haxor_graphics_GL.DEPTH_WRITEMASK = 2930;
haxor_graphics_GL.DITHER = 3024;
haxor_graphics_GL.DONT_CARE = 4352;
haxor_graphics_GL.DST_ALPHA = 772;
haxor_graphics_GL.DST_COLOR = 774;
haxor_graphics_GL.DYNAMIC_DRAW = 35048;
haxor_graphics_GL.ELEMENT_ARRAY_BUFFER = 34963;
haxor_graphics_GL.ELEMENT_ARRAY_BUFFER_BINDING = 34965;
haxor_graphics_GL.EQUAL = 514;
haxor_graphics_GL.FASTEST = 4353;
haxor_graphics_GL.FLOAT = 5126;
haxor_graphics_GL.FLOAT_MAT2 = 35674;
haxor_graphics_GL.FLOAT_MAT3 = 35675;
haxor_graphics_GL.FLOAT_MAT4 = 35676;
haxor_graphics_GL.FLOAT_VEC2 = 35664;
haxor_graphics_GL.FLOAT_VEC3 = 35665;
haxor_graphics_GL.FLOAT_VEC4 = 35666;
haxor_graphics_GL.FRAGMENT_SHADER = 35632;
haxor_graphics_GL.FRAMEBUFFER = 36160;
haxor_graphics_GL.FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 36049;
haxor_graphics_GL.FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 36048;
haxor_graphics_GL.FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 36051;
haxor_graphics_GL.FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 36050;
haxor_graphics_GL.FRAMEBUFFER_BINDING = 36006;
haxor_graphics_GL.FRAMEBUFFER_COMPLETE = 36053;
haxor_graphics_GL.FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 36054;
haxor_graphics_GL.FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 36057;
haxor_graphics_GL.FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 36055;
haxor_graphics_GL.FRAMEBUFFER_UNSUPPORTED = 36061;
haxor_graphics_GL.FRONT = 1028;
haxor_graphics_GL.FRONT_AND_BACK = 1032;
haxor_graphics_GL.FRONT_FACE = 2886;
haxor_graphics_GL.FUNC_ADD = 32774;
haxor_graphics_GL.FUNC_REVERSE_SUBTRACT = 32779;
haxor_graphics_GL.FUNC_SUBTRACT = 32778;
haxor_graphics_GL.GENERATE_MIPMAP_HINT = 33170;
haxor_graphics_GL.GEQUAL = 518;
haxor_graphics_GL.GREATER = 516;
haxor_graphics_GL.GREEN_BITS = 3411;
haxor_graphics_GL.HIGH_FLOAT = 36338;
haxor_graphics_GL.HIGH_INT = 36341;
haxor_graphics_GL.INCR = 7682;
haxor_graphics_GL.INCR_WRAP = 34055;
haxor_graphics_GL.INT = 5124;
haxor_graphics_GL.INT_VEC2 = 35667;
haxor_graphics_GL.INT_VEC3 = 35668;
haxor_graphics_GL.INT_VEC4 = 35669;
haxor_graphics_GL.INVALID_ENUM = 1280;
haxor_graphics_GL.INVALID_FRAMEBUFFER_OPERATION = 1286;
haxor_graphics_GL.INVALID_OPERATION = 1282;
haxor_graphics_GL.INVALID_VALUE = 1281;
haxor_graphics_GL.INVERT = 5386;
haxor_graphics_GL.KEEP = 7680;
haxor_graphics_GL.LEQUAL = 515;
haxor_graphics_GL.LESS = 513;
haxor_graphics_GL.LINEAR = 9729;
haxor_graphics_GL.LINEAR_MIPMAP_LINEAR = 9987;
haxor_graphics_GL.LINEAR_MIPMAP_NEAREST = 9985;
haxor_graphics_GL.LINES = 1;
haxor_graphics_GL.LINE_LOOP = 2;
haxor_graphics_GL.LINE_STRIP = 3;
haxor_graphics_GL.LINE_WIDTH = 2849;
haxor_graphics_GL.LINK_STATUS = 35714;
haxor_graphics_GL.LOW_FLOAT = 36336;
haxor_graphics_GL.LOW_INT = 36339;
haxor_graphics_GL.LUMINANCE = 6409;
haxor_graphics_GL.LUMINANCE_ALPHA = 6410;
haxor_graphics_GL.MAX_COMBINED_TEXTURE_IMAGE_UNITS = 35661;
haxor_graphics_GL.MAX_CUBE_MAP_TEXTURE_SIZE = 34076;
haxor_graphics_GL.MAX_FRAGMENT_UNIFORM_VECTORS = 36349;
haxor_graphics_GL.MAX_RENDERBUFFER_SIZE = 34024;
haxor_graphics_GL.MAX_TEXTURE_IMAGE_UNITS = 34930;
haxor_graphics_GL.MAX_TEXTURE_SIZE = 3379;
haxor_graphics_GL.MAX_VARYING_VECTORS = 36348;
haxor_graphics_GL.MAX_VERTEX_ATTRIBS = 34921;
haxor_graphics_GL.MAX_VERTEX_TEXTURE_IMAGE_UNITS = 35660;
haxor_graphics_GL.MAX_VERTEX_UNIFORM_VECTORS = 36347;
haxor_graphics_GL.MAX_VIEWPORT_DIMS = 3386;
haxor_graphics_GL.MEDIUM_FLOAT = 36337;
haxor_graphics_GL.MEDIUM_INT = 36340;
haxor_graphics_GL.MIRRORED_REPEAT = 33648;
haxor_graphics_GL.NEAREST = 9728;
haxor_graphics_GL.NEAREST_MIPMAP_LINEAR = 9986;
haxor_graphics_GL.NEAREST_MIPMAP_NEAREST = 9984;
haxor_graphics_GL.NEVER = 512;
haxor_graphics_GL.NICEST = 4354;
haxor_graphics_GL.NONE = 0;
haxor_graphics_GL.NOTEQUAL = 517;
haxor_graphics_GL.NO_ERROR_GL = 0;
haxor_graphics_GL.ONE = 1;
haxor_graphics_GL.ONE_MINUS_CONSTANT_ALPHA = 32772;
haxor_graphics_GL.ONE_MINUS_CONSTANT_COLOR = 32770;
haxor_graphics_GL.ONE_MINUS_DST_ALPHA = 773;
haxor_graphics_GL.ONE_MINUS_DST_COLOR = 775;
haxor_graphics_GL.ONE_MINUS_SRC_ALPHA = 771;
haxor_graphics_GL.ONE_MINUS_SRC_COLOR = 769;
haxor_graphics_GL.OUT_OF_MEMORY = 1285;
haxor_graphics_GL.PACK_ALIGNMENT = 3333;
haxor_graphics_GL.POINTS = 0;
haxor_graphics_GL.POLYGON_OFFSET_FACTOR = 32824;
haxor_graphics_GL.POLYGON_OFFSET_FILL = 32823;
haxor_graphics_GL.POLYGON_OFFSET_UNITS = 10752;
haxor_graphics_GL.RED_BITS = 3410;
haxor_graphics_GL.RENDERBUFFER = 36161;
haxor_graphics_GL.RENDERBUFFER_ALPHA_SIZE = 36179;
haxor_graphics_GL.RENDERBUFFER_BINDING = 36007;
haxor_graphics_GL.RENDERBUFFER_BLUE_SIZE = 36178;
haxor_graphics_GL.RENDERBUFFER_DEPTH_SIZE = 36180;
haxor_graphics_GL.RENDERBUFFER_GREEN_SIZE = 36177;
haxor_graphics_GL.RENDERBUFFER_HEIGHT = 36163;
haxor_graphics_GL.RENDERBUFFER_INTERNAL_FORMAT = 36164;
haxor_graphics_GL.RENDERBUFFER_RED_SIZE = 36176;
haxor_graphics_GL.RENDERBUFFER_STENCIL_SIZE = 36181;
haxor_graphics_GL.RENDERBUFFER_WIDTH = 36162;
haxor_graphics_GL.RENDERER = 7937;
haxor_graphics_GL.REPEAT = 10497;
haxor_graphics_GL.REPLACE = 7681;
haxor_graphics_GL.RGB = 6407;
haxor_graphics_GL.RGB565 = 36194;
haxor_graphics_GL.RGB5_A1 = 32855;
haxor_graphics_GL.RGBA = 6408;
haxor_graphics_GL.RGBA4 = 32854;
haxor_graphics_GL.SAMPLER_2D = 35678;
haxor_graphics_GL.SAMPLER_CUBE = 35680;
haxor_graphics_GL.SAMPLES = 32937;
haxor_graphics_GL.SAMPLE_ALPHA_TO_COVERAGE = 32926;
haxor_graphics_GL.SAMPLE_BUFFERS = 32936;
haxor_graphics_GL.SAMPLE_COVERAGE = 32928;
haxor_graphics_GL.SAMPLE_COVERAGE_INVERT = 32939;
haxor_graphics_GL.SAMPLE_COVERAGE_VALUE = 32938;
haxor_graphics_GL.SCISSOR_BOX = 3088;
haxor_graphics_GL.SCISSOR_TEST = 3089;
haxor_graphics_GL.SHADER_TYPE = 35663;
haxor_graphics_GL.SHADING_LANGUAGE_VERSION = 35724;
haxor_graphics_GL.SHORT = 5122;
haxor_graphics_GL.SRC_ALPHA = 770;
haxor_graphics_GL.SRC_ALPHA_SATURATE = 776;
haxor_graphics_GL.SRC_COLOR = 768;
haxor_graphics_GL.STATIC_DRAW = 35044;
haxor_graphics_GL.STENCIL_ATTACHMENT = 36128;
haxor_graphics_GL.STENCIL_BACK_FAIL = 34817;
haxor_graphics_GL.STENCIL_BACK_FUNC = 34816;
haxor_graphics_GL.STENCIL_BACK_PASS_DEPTH_FAIL = 34818;
haxor_graphics_GL.STENCIL_BACK_PASS_DEPTH_PASS = 34819;
haxor_graphics_GL.STENCIL_BACK_REF = 36003;
haxor_graphics_GL.STENCIL_BACK_VALUE_MASK = 36004;
haxor_graphics_GL.STENCIL_BACK_WRITEMASK = 36005;
haxor_graphics_GL.STENCIL_BITS = 3415;
haxor_graphics_GL.STENCIL_BUFFER_BIT = 1024;
haxor_graphics_GL.STENCIL_CLEAR_VALUE = 2961;
haxor_graphics_GL.STENCIL_FAIL = 2964;
haxor_graphics_GL.STENCIL_FUNC = 2962;
haxor_graphics_GL.STENCIL_INDEX = 6401;
haxor_graphics_GL.STENCIL_INDEX8 = 36168;
haxor_graphics_GL.STENCIL_PASS_DEPTH_FAIL = 2965;
haxor_graphics_GL.STENCIL_PASS_DEPTH_PASS = 2966;
haxor_graphics_GL.STENCIL_REF = 2967;
haxor_graphics_GL.STENCIL_TEST = 2960;
haxor_graphics_GL.STENCIL_VALUE_MASK = 2963;
haxor_graphics_GL.STENCIL_WRITEMASK = 2968;
haxor_graphics_GL.STREAM_DRAW = 35040;
haxor_graphics_GL.SUBPIXEL_BITS = 3408;
haxor_graphics_GL.TEXTURE = 5890;
haxor_graphics_GL.TEXTURE0 = 33984;
haxor_graphics_GL.TEXTURE1 = 33985;
haxor_graphics_GL.TEXTURE10 = 33994;
haxor_graphics_GL.TEXTURE11 = 33995;
haxor_graphics_GL.TEXTURE12 = 33996;
haxor_graphics_GL.TEXTURE13 = 33997;
haxor_graphics_GL.TEXTURE14 = 33998;
haxor_graphics_GL.TEXTURE15 = 33999;
haxor_graphics_GL.TEXTURE16 = 34000;
haxor_graphics_GL.TEXTURE17 = 34001;
haxor_graphics_GL.TEXTURE18 = 34002;
haxor_graphics_GL.TEXTURE19 = 34003;
haxor_graphics_GL.TEXTURE2 = 33986;
haxor_graphics_GL.TEXTURE20 = 34004;
haxor_graphics_GL.TEXTURE21 = 34005;
haxor_graphics_GL.TEXTURE22 = 34006;
haxor_graphics_GL.TEXTURE23 = 34007;
haxor_graphics_GL.TEXTURE24 = 34008;
haxor_graphics_GL.TEXTURE25 = 34009;
haxor_graphics_GL.TEXTURE26 = 34010;
haxor_graphics_GL.TEXTURE27 = 34011;
haxor_graphics_GL.TEXTURE28 = 34012;
haxor_graphics_GL.TEXTURE29 = 34013;
haxor_graphics_GL.TEXTURE3 = 33987;
haxor_graphics_GL.TEXTURE30 = 34014;
haxor_graphics_GL.TEXTURE31 = 34015;
haxor_graphics_GL.TEXTURE4 = 33988;
haxor_graphics_GL.TEXTURE5 = 33989;
haxor_graphics_GL.TEXTURE6 = 33990;
haxor_graphics_GL.TEXTURE7 = 33991;
haxor_graphics_GL.TEXTURE8 = 33992;
haxor_graphics_GL.TEXTURE9 = 33993;
haxor_graphics_GL.TEXTURE_2D = 3553;
haxor_graphics_GL.TEXTURE_BINDING_2D = 32873;
haxor_graphics_GL.TEXTURE_BINDING_CUBE_MAP = 34068;
haxor_graphics_GL.TEXTURE_CUBE_MAP = 34067;
haxor_graphics_GL.TEXTURE_CUBE_MAP_NEGATIVE_X = 34070;
haxor_graphics_GL.TEXTURE_CUBE_MAP_NEGATIVE_Y = 34072;
haxor_graphics_GL.TEXTURE_CUBE_MAP_NEGATIVE_Z = 34074;
haxor_graphics_GL.TEXTURE_CUBE_MAP_POSITIVE_X = 34069;
haxor_graphics_GL.TEXTURE_CUBE_MAP_POSITIVE_Y = 34071;
haxor_graphics_GL.TEXTURE_CUBE_MAP_POSITIVE_Z = 34073;
haxor_graphics_GL.TEXTURE_MAG_FILTER = 10240;
haxor_graphics_GL.TEXTURE_MIN_FILTER = 10241;
haxor_graphics_GL.TEXTURE_WRAP_S = 10242;
haxor_graphics_GL.TEXTURE_WRAP_T = 10243;
haxor_graphics_GL.TRIANGLES = 4;
haxor_graphics_GL.TRIANGLE_FAN = 6;
haxor_graphics_GL.TRIANGLE_STRIP = 5;
haxor_graphics_GL.UNPACK_ALIGNMENT = 3317;
haxor_graphics_GL.UNPACK_COLORSPACE_CONVERSION_WEBGL = 37443;
haxor_graphics_GL.UNPACK_FLIP_Y_WEBGL = 37440;
haxor_graphics_GL.UNPACK_PREMULTIPLY_ALPHA_WEBGL = 37441;
haxor_graphics_GL.UNSIGNED_BYTE = 5121;
haxor_graphics_GL.UNSIGNED_INT = 5125;
haxor_graphics_GL.UNSIGNED_SHORT = 5123;
haxor_graphics_GL.UNSIGNED_SHORT_4_4_4_4 = 32819;
haxor_graphics_GL.UNSIGNED_SHORT_5_5_5_1 = 32820;
haxor_graphics_GL.UNSIGNED_SHORT_5_6_5 = 33635;
haxor_graphics_GL.VALIDATE_STATUS = 35715;
haxor_graphics_GL.VENDOR = 7936;
haxor_graphics_GL.VERSION = 7938;
haxor_graphics_GL.VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 34975;
haxor_graphics_GL.VERTEX_ATTRIB_ARRAY_ENABLED = 34338;
haxor_graphics_GL.VERTEX_ATTRIB_ARRAY_NORMALIZED = 34922;
haxor_graphics_GL.VERTEX_ATTRIB_ARRAY_POINTER = 34373;
haxor_graphics_GL.VERTEX_ATTRIB_ARRAY_SIZE = 34339;
haxor_graphics_GL.VERTEX_ATTRIB_ARRAY_STRIDE = 34340;
haxor_graphics_GL.VERTEX_ATTRIB_ARRAY_TYPE = 34341;
haxor_graphics_GL.VERTEX_SHADER = 35633;
haxor_graphics_GL.VIEWPORT = 2978;
haxor_graphics_GL.ZERO = 0;
haxor_graphics_GL.VERTEX_ARRAY_OBJECT = false;
haxor_graphics_GL.HALF_FLOAT = 5126;
haxor_graphics_GL.TEXTURE_HALF = false;
haxor_graphics_GL.TEXTURE_HALF_LINEAR = false;
haxor_graphics_GL.TEXTURE_ANISOTROPY = -1;
haxor_graphics_GL.TEXTURE_ANISOTROPY_ENABLED = false;
haxor_graphics_GL.MAX_TEXTURE_ANISOTROPY = 1;
haxor_graphics_GL.TEXTURE_FLOAT = false;
haxor_graphics_GL.TEXTURE_FLOAT_LINEAR = false;
haxor_graphics_GL.TEXTURE_DEPTH_ENABLED = false;
haxor_graphics_GL.MAX_ACTIVE_TEXTURE = 8;
haxor_graphics_Graphics.m_last_viewport = haxor_math_AABB2.get_empty();
haxor_input_Input.scroll = false;
haxor_input_Input.menu = false;
haxor_input_Input.emulateTouch = false;
haxor_input_Joystick.analogBias = [0.1,0.9];
haxor_input_Joystick.buttonBias = 0.9;
haxor_input_Joystick.available = false;
haxor_input_KeyCode.Modifiers = -65536;
haxor_input_KeyCode.None = 0;
haxor_input_KeyCode.Mouse0 = 1;
haxor_input_KeyCode.Mouse1 = 2;
haxor_input_KeyCode.Cancel = 3;
haxor_input_KeyCode.Mouse2 = 4;
haxor_input_KeyCode.Mouse3 = 5;
haxor_input_KeyCode.Mouse4 = 6;
haxor_input_KeyCode.Back = 8;
haxor_input_KeyCode.Tab = 9;
haxor_input_KeyCode.LineFeed = 10;
haxor_input_KeyCode.Clear = 12;
haxor_input_KeyCode.Enter = 13;
haxor_input_KeyCode.Return = 13;
haxor_input_KeyCode.ShiftKey = 16;
haxor_input_KeyCode.ControlKey = 17;
haxor_input_KeyCode.Alt = 18;
haxor_input_KeyCode.Pause = 19;
haxor_input_KeyCode.CapsLock = 20;
haxor_input_KeyCode.Capital = 20;
haxor_input_KeyCode.KanaMode = 21;
haxor_input_KeyCode.HanguelMode = 21;
haxor_input_KeyCode.HangulMode = 21;
haxor_input_KeyCode.JunjaMode = 23;
haxor_input_KeyCode.FinalMode = 24;
haxor_input_KeyCode.KanjiMode = 25;
haxor_input_KeyCode.HanjaMode = 25;
haxor_input_KeyCode.Escape = 27;
haxor_input_KeyCode.IMEConvert = 28;
haxor_input_KeyCode.IMENonconvert = 29;
haxor_input_KeyCode.IMEAceept = 30;
haxor_input_KeyCode.IMEAccept = 30;
haxor_input_KeyCode.IMEModeChange = 31;
haxor_input_KeyCode.Space = 32;
haxor_input_KeyCode.Prior = 33;
haxor_input_KeyCode.PageUp = 33;
haxor_input_KeyCode.Next = 34;
haxor_input_KeyCode.PageDown = 34;
haxor_input_KeyCode.End = 35;
haxor_input_KeyCode.Home = 36;
haxor_input_KeyCode.Left = 37;
haxor_input_KeyCode.Up = 38;
haxor_input_KeyCode.Right = 39;
haxor_input_KeyCode.Down = 40;
haxor_input_KeyCode.Select = 41;
haxor_input_KeyCode.Print = 42;
haxor_input_KeyCode.Execute = 43;
haxor_input_KeyCode.PrintScreen = 44;
haxor_input_KeyCode.Snapshot = 44;
haxor_input_KeyCode.Insert = 45;
haxor_input_KeyCode.Delete = 46;
haxor_input_KeyCode.Help = 47;
haxor_input_KeyCode.D0 = 48;
haxor_input_KeyCode.D1 = 49;
haxor_input_KeyCode.D2 = 50;
haxor_input_KeyCode.D3 = 51;
haxor_input_KeyCode.D4 = 52;
haxor_input_KeyCode.D5 = 53;
haxor_input_KeyCode.D6 = 54;
haxor_input_KeyCode.D7 = 55;
haxor_input_KeyCode.D8 = 56;
haxor_input_KeyCode.D9 = 57;
haxor_input_KeyCode.A = 65;
haxor_input_KeyCode.B = 66;
haxor_input_KeyCode.C = 67;
haxor_input_KeyCode.D = 68;
haxor_input_KeyCode.E = 69;
haxor_input_KeyCode.F = 70;
haxor_input_KeyCode.G = 71;
haxor_input_KeyCode.H = 72;
haxor_input_KeyCode.I = 73;
haxor_input_KeyCode.J = 74;
haxor_input_KeyCode.K = 75;
haxor_input_KeyCode.L = 76;
haxor_input_KeyCode.M = 77;
haxor_input_KeyCode.N = 78;
haxor_input_KeyCode.O = 79;
haxor_input_KeyCode.P = 80;
haxor_input_KeyCode.Q = 81;
haxor_input_KeyCode.R = 82;
haxor_input_KeyCode.S = 83;
haxor_input_KeyCode.T = 84;
haxor_input_KeyCode.U = 85;
haxor_input_KeyCode.V = 86;
haxor_input_KeyCode.W = 87;
haxor_input_KeyCode.X = 88;
haxor_input_KeyCode.Y = 89;
haxor_input_KeyCode.Z = 90;
haxor_input_KeyCode.LWin = 91;
haxor_input_KeyCode.RWin = 92;
haxor_input_KeyCode.Apps = 93;
haxor_input_KeyCode.Sleep = 95;
haxor_input_KeyCode.NumPad0 = 96;
haxor_input_KeyCode.NumPad1 = 97;
haxor_input_KeyCode.NumPad2 = 98;
haxor_input_KeyCode.NumPad3 = 99;
haxor_input_KeyCode.NumPad4 = 100;
haxor_input_KeyCode.NumPad5 = 101;
haxor_input_KeyCode.NumPad6 = 102;
haxor_input_KeyCode.NumPad7 = 103;
haxor_input_KeyCode.NumPad8 = 104;
haxor_input_KeyCode.NumPad9 = 105;
haxor_input_KeyCode.Multiply = 106;
haxor_input_KeyCode.Add = 107;
haxor_input_KeyCode.Separator = 108;
haxor_input_KeyCode.Subtract = 109;
haxor_input_KeyCode.Decimal = 110;
haxor_input_KeyCode.Divide = 111;
haxor_input_KeyCode.F1 = 112;
haxor_input_KeyCode.F2 = 113;
haxor_input_KeyCode.F3 = 114;
haxor_input_KeyCode.F4 = 115;
haxor_input_KeyCode.F5 = 116;
haxor_input_KeyCode.F6 = 117;
haxor_input_KeyCode.F7 = 118;
haxor_input_KeyCode.F8 = 119;
haxor_input_KeyCode.F9 = 120;
haxor_input_KeyCode.F10 = 121;
haxor_input_KeyCode.F11 = 122;
haxor_input_KeyCode.F12 = 123;
haxor_input_KeyCode.F13 = 124;
haxor_input_KeyCode.F14 = 125;
haxor_input_KeyCode.F15 = 126;
haxor_input_KeyCode.F16 = 127;
haxor_input_KeyCode.F17 = 128;
haxor_input_KeyCode.F18 = 129;
haxor_input_KeyCode.F19 = 130;
haxor_input_KeyCode.F20 = 131;
haxor_input_KeyCode.F21 = 132;
haxor_input_KeyCode.F22 = 133;
haxor_input_KeyCode.F23 = 134;
haxor_input_KeyCode.F24 = 135;
haxor_input_KeyCode.NumLock = 144;
haxor_input_KeyCode.Scroll = 145;
haxor_input_KeyCode.LShiftKey = 160;
haxor_input_KeyCode.RShiftKey = 161;
haxor_input_KeyCode.LControlKey = 162;
haxor_input_KeyCode.RControlKey = 163;
haxor_input_KeyCode.LAlt = 164;
haxor_input_KeyCode.RAlt = 165;
haxor_input_KeyCode.BrowserBack = 166;
haxor_input_KeyCode.BrowserForward = 167;
haxor_input_KeyCode.BrowserRefresh = 168;
haxor_input_KeyCode.BrowserStop = 169;
haxor_input_KeyCode.BrowserSearch = 170;
haxor_input_KeyCode.BrowserFavorites = 171;
haxor_input_KeyCode.BrowserHome = 172;
haxor_input_KeyCode.VolumeMute = 173;
haxor_input_KeyCode.VolumeDown = 174;
haxor_input_KeyCode.VolumeUp = 175;
haxor_input_KeyCode.MediaNextTrack = 176;
haxor_input_KeyCode.MediaPreviousTrack = 177;
haxor_input_KeyCode.MediaStop = 178;
haxor_input_KeyCode.MediaPlayPause = 179;
haxor_input_KeyCode.LaunchMail = 180;
haxor_input_KeyCode.SelectMedia = 181;
haxor_input_KeyCode.LaunchApplication1 = 182;
haxor_input_KeyCode.LaunchApplication2 = 183;
haxor_input_KeyCode.Oem1 = 186;
haxor_input_KeyCode.OemSemicolon = 186;
haxor_input_KeyCode.Oemplus = 187;
haxor_input_KeyCode.Oemcomma = 188;
haxor_input_KeyCode.OemMinus = 189;
haxor_input_KeyCode.OemPeriod = 190;
haxor_input_KeyCode.OemQuestion = 191;
haxor_input_KeyCode.Oem2 = 191;
haxor_input_KeyCode.Oemtilde = 192;
haxor_input_KeyCode.Oem3 = 192;
haxor_input_KeyCode.Oem4 = 219;
haxor_input_KeyCode.OemOpenBrackets = 219;
haxor_input_KeyCode.OemPipe = 220;
haxor_input_KeyCode.Oem5 = 220;
haxor_input_KeyCode.Oem6 = 221;
haxor_input_KeyCode.OemCloseBrackets = 221;
haxor_input_KeyCode.Oem7 = 222;
haxor_input_KeyCode.OemQuotes = 222;
haxor_input_KeyCode.Oem8 = 223;
haxor_input_KeyCode.Oem102 = 226;
haxor_input_KeyCode.OemBackslash = 226;
haxor_input_KeyCode.ProcessKey = 229;
haxor_input_KeyCode.Packet = 231;
haxor_input_KeyCode.Attn = 246;
haxor_input_KeyCode.Crsel = 247;
haxor_input_KeyCode.Exsel = 248;
haxor_input_KeyCode.EraseEof = 249;
haxor_input_KeyCode.Play = 250;
haxor_input_KeyCode.Zoom = 251;
haxor_input_KeyCode.NoName = 252;
haxor_input_KeyCode.Pa1 = 253;
haxor_input_KeyCode.OemClear = 254;
haxor_input_KeyCode.KeyCodeMask = 65535;
haxor_input_KeyCode.ShiftModifier = 65536;
haxor_input_KeyCode.ControlModifier = 131072;
haxor_input_KeyCode.AltModifier = 262144;
haxor_input_KeyCode.Face1 = 0;
haxor_input_KeyCode.Face2 = 1;
haxor_input_KeyCode.Face3 = 2;
haxor_input_KeyCode.Face4 = 3;
haxor_input_KeyCode.ButtonA = 0;
haxor_input_KeyCode.ButtonB = 1;
haxor_input_KeyCode.ButtonX = 2;
haxor_input_KeyCode.ButtonY = 3;
haxor_input_KeyCode.LeftShoulder = 4;
haxor_input_KeyCode.RightShoulder = 5;
haxor_input_KeyCode.LeftShoulderBottom = 6;
haxor_input_KeyCode.RightShoulderBottom = 7;
haxor_input_KeyCode.ButtonSelect = 8;
haxor_input_KeyCode.ButtonStart = 9;
haxor_input_KeyCode.LeftAnalogueStick = 10;
haxor_input_KeyCode.RightAnalogueStick = 11;
haxor_input_KeyCode.PadTop = 12;
haxor_input_KeyCode.PadBottom = 13;
haxor_input_KeyCode.PadLeft = 14;
haxor_input_KeyCode.PadRight = 15;
haxor_input_KeyCode.LeftAnalogueHor = 0;
haxor_input_KeyCode.LeftAnalogueVert = 1;
haxor_input_KeyCode.RightAnalogueHor = 2;
haxor_input_KeyCode.RightAnalogueVert = 3;
haxor_io_file_Asset.m_database = new haxe_ds_StringMap();
haxor_math_Mathf.Epsilon = 0.0001;
haxor_math_Mathf.NaN = Math.NaN;
haxor_math_Mathf.Infinity = Math.POSITIVE_INFINITY;
haxor_math_Mathf.NegativeInfinity = Math.NEGATIVE_INFINITY;
haxor_math_Mathf.E = 2.7182818284590452353602874713527;
haxor_math_Mathf.PI = 3.1415926535897932384626433832795028841971693993751058;
haxor_math_Mathf.HalfPI = 1.5707963267948966192313216916398;
haxor_math_Mathf.PI2 = 6.283185307179586476925286766559;
haxor_math_Mathf.PI4 = 12.566370614359172953850573533118;
haxor_math_Mathf.InvPI = 0.31830988618379067153776752674503;
haxor_math_Mathf.Rad2Deg = 57.295779513082320876798154814105;
haxor_math_Mathf.Deg2Rad = 0.01745329251994329576923690768489;
haxor_math_Mathf.Px2Em = 0.063;
haxor_math_Mathf.Em2Px = 15.87301587301587;
haxor_math_Mathf.Byte2Float = 0.00392156863;
haxor_math_Mathf.Short2Float = 0.0000152587890625;
haxor_math_Mathf.Long2Float = 0.00000000023283064365386962890625;
haxor_math_Mathf.Float2Byte = 255.0;
haxor_math_Mathf.Float2Short = 65536.0;
haxor_math_Mathf.Float2Long = 4294967296.0;
haxor_net_Web.root = "";
Main.main();
})();
