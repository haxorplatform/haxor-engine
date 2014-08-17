(function () { "use strict";
var $hxClasses = {};
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
HxOverrides.indexOf = function(a,obj,i) {
	var len = a.length;
	if(i < 0) {
		i += len;
		if(i < 0) i = 0;
	}
	while(i < len) {
		if(a[i] === obj) return i;
		i++;
	}
	return -1;
};
HxOverrides.remove = function(a,obj) {
	var i = HxOverrides.indexOf(a,obj,0);
	if(i == -1) return false;
	a.splice(i,1);
	return true;
};
var haxor = {};
haxor.core = {};
haxor.core.IDisposable = function() { };
$hxClasses["haxor.core.IDisposable"] = haxor.core.IDisposable;
haxor.core.IDisposable.__name__ = ["haxor","core","IDisposable"];
haxor.core.IDisposable.prototype = {
	__class__: haxor.core.IDisposable
};
haxor.core.Resource = function(p_name) {
	if(p_name == null) p_name = "";
	this.m_uid = haxor.context.EngineContext.uid++;
	this.m_destroyed = false;
	this._cid_ = 0;
	this.m_pid = [-1,-1,-1,-1,-1,-1];
	this.m_name = p_name;
	this.m_is_behaviour = js.Boot.__instanceof(this,haxor.component.Behaviour);
	this.m_type_class = Type.getClass(this);
	this.m_type_full_name = Type.getClassName(this.m_type_class);
	var nt = this.m_type_full_name.split(".");
	nt.reverse();
	this.m_type_name = nt[0];
	if(p_name == "") this.m_name = this.m_type_name + this.m_uid; else this.m_name = p_name;
	haxor.context.EngineContext.resources.Add(this);
};
$hxClasses["haxor.core.Resource"] = haxor.core.Resource;
haxor.core.Resource.__name__ = ["haxor","core","Resource"];
haxor.core.Resource.__interfaces__ = [haxor.core.IDisposable];
haxor.core.Resource.Destroy = function(p_target) {
	haxor.context.EngineContext.Destroy(p_target);
};
haxor.core.Resource.prototype = {
	get_application: function() {
		return haxor.core.BaseApplication.m_instance;
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
	,__class__: haxor.core.Resource
};
haxor.component = {};
haxor.component.Component = function() {
	haxor.core.Resource.call(this,"");
	this.OnBuild();
};
$hxClasses["haxor.component.Component"] = haxor.component.Component;
haxor.component.Component.__name__ = ["haxor","component","Component"];
haxor.component.Component.__super__ = haxor.core.Resource;
haxor.component.Component.prototype = $extend(haxor.core.Resource.prototype,{
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
	,OnBuild: function() {
	}
	,__class__: haxor.component.Component
});
haxor.component.Behaviour = function() {
	haxor.component.Component.call(this);
	this.m_enabled = true;
	this.m_is_behaviour = true;
	this.m_is_updateable = js.Boot.__instanceof(this,haxor.core.IUpdateable);
	this.m_is_renderable = js.Boot.__instanceof(this,haxor.core.IRenderable);
	this.m_is_resizeable = js.Boot.__instanceof(this,haxor.core.IResizeable);
	this.UpdateContextFlag(true);
};
$hxClasses["haxor.component.Behaviour"] = haxor.component.Behaviour;
haxor.component.Behaviour.__name__ = ["haxor","component","Behaviour"];
haxor.component.Behaviour.__super__ = haxor.component.Component;
haxor.component.Behaviour.prototype = $extend(haxor.component.Component.prototype,{
	get_enabled: function() {
		return this.m_enabled && !this.m_destroyed;
	}
	,set_enabled: function(v) {
		if(this.m_destroyed) return false;
		this.m_enabled = v;
		this.UpdateContextFlag(v);
		return v;
	}
	,OnAwake: function() {
	}
	,OnStart: function() {
	}
	,UpdateContextFlag: function(p_flag) {
		if(this.m_is_updateable) {
			if(p_flag) haxor.context.EngineContext.update.Add(this); else haxor.context.EngineContext.update.Remove(this);
		}
		if(this.m_is_renderable) {
			if(p_flag) haxor.context.EngineContext.render.Add(this); else haxor.context.EngineContext.render.Remove(this);
		}
		if(this.m_is_resizeable) {
			if(p_flag) haxor.context.EngineContext.resize.Add(this); else haxor.context.EngineContext.resize.Remove(this);
		}
	}
	,__class__: haxor.component.Behaviour
});
haxor.core.BaseApplication = function() {
	haxor.component.Behaviour.call(this);
	haxor.core.BaseApplication.m_instance = this;
	this.m_scenes = [];
	this.set_fps(60);
	this.m_frame_ms = 0.0;
	this.m_init_allowed = false;
	this.m_platform = haxor.core.Platform.Unknown;
	haxor.core.Time.Initialize();
	haxor.graphics.Screen.m_application = this;
	haxor.graphics.Screen.Initialize();
};
$hxClasses["haxor.core.BaseApplication"] = haxor.core.BaseApplication;
haxor.core.BaseApplication.__name__ = ["haxor","core","BaseApplication"];
haxor.core.BaseApplication.__super__ = haxor.component.Behaviour;
haxor.core.BaseApplication.prototype = $extend(haxor.component.Behaviour.prototype,{
	get_protocol: function() {
		if(window.location.protocol.toLowerCase() == "file:") return haxor.core.ApplicationProtocol.File;
		if(window.location.protocol.toLowerCase() == "http:") return haxor.core.ApplicationProtocol.HTTP;
		if(window.location.protocol.toLowerCase() == "https:") return haxor.core.ApplicationProtocol.HTTPS;
		return haxor.core.ApplicationProtocol.None;
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
		f *= 1.24;
		this.m_mspf = 1.0 / f * 1000.0;
		return v;
	}
	,get_platform: function() {
		return this.m_platform;
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
		haxor.core.Time.Update();
		this.CheckResize();
		haxor.core.Engine.Update();
		haxor.core.Engine.Collect();
	}
	,Render: function() {
		if(this.m_init_allowed) {
			haxor.core.Console.Log("Application> Initialize.",3);
			this.Initialize();
			this.m_init_allowed = false;
		}
		if(haxor.core.Time.m_clock - this.m_frame_ms >= this.m_mspf) {
			this.m_frame_ms += haxor.core.Time.m_clock - this.m_frame_ms;
			haxor.core.Time.Render();
			haxor.platform.graphics.GL.m_gl.Focus();
			haxor.core.Engine.Render();
			haxor.platform.graphics.GL.m_gl.Flush();
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
		if(Math.abs(haxor.graphics.Screen.m_width - this.GetContainerWidth()) > 0.0) {
			haxor.graphics.Screen.m_width = this.GetContainerWidth();
			has_resize = true;
		}
		if(Math.abs(haxor.graphics.Screen.m_height - this.GetContainerHeight()) > 0.0) {
			haxor.graphics.Screen.m_height = this.GetContainerHeight();
			has_resize = true;
		}
		if(has_resize) this.OnResize();
	}
	,OnResize: function() {
		haxor.core.Console.Log("Application> Resize [" + haxor.graphics.Screen.m_width + "," + haxor.graphics.Screen.m_height + "]",5);
		haxor.platform.graphics.GL.m_gl.Resize();
		haxor.core.Engine.Resize();
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
	,__class__: haxor.core.BaseApplication
});
haxor.platform = {};
haxor.platform.html = {};
haxor.platform.html.HTMLApplication = function() {
	haxor.core.BaseApplication.call(this);
	this.m_platform = haxor.core.Platform.HTML;
};
$hxClasses["haxor.platform.html.HTMLApplication"] = haxor.platform.html.HTMLApplication;
haxor.platform.html.HTMLApplication.__name__ = ["haxor","platform","html","HTMLApplication"];
haxor.platform.html.HTMLApplication.__super__ = haxor.core.BaseApplication;
haxor.platform.html.HTMLApplication.prototype = $extend(haxor.core.BaseApplication.prototype,{
	GetContainerWidth: function() {
		return this.m_container.clientWidth;
	}
	,GetContainerHeight: function() {
		return this.m_container.clientHeight;
	}
	,__class__: haxor.platform.html.HTMLApplication
});
haxor.core.Application = function() {
	haxor.platform.html.HTMLApplication.call(this);
};
$hxClasses["haxor.core.Application"] = haxor.core.Application;
haxor.core.Application.__name__ = ["haxor","core","Application"];
haxor.core.Application.__super__ = haxor.platform.html.HTMLApplication;
haxor.core.Application.prototype = $extend(haxor.platform.html.HTMLApplication.prototype,{
	__class__: haxor.core.Application
});
haxor.core.IRenderable = function() { };
$hxClasses["haxor.core.IRenderable"] = haxor.core.IRenderable;
haxor.core.IRenderable.__name__ = ["haxor","core","IRenderable"];
haxor.core.IRenderable.prototype = {
	__class__: haxor.core.IRenderable
};
haxor.core.IUpdateable = function() { };
$hxClasses["haxor.core.IUpdateable"] = haxor.core.IUpdateable;
haxor.core.IUpdateable.__name__ = ["haxor","core","IUpdateable"];
haxor.core.IUpdateable.prototype = {
	__class__: haxor.core.IUpdateable
};
var Main = function() {
	this.init = false;
	haxor.core.Application.call(this);
};
$hxClasses["Main"] = Main;
Main.__name__ = ["Main"];
Main.__interfaces__ = [haxor.core.IRenderable,haxor.core.IUpdateable];
Main.main = function() {
	haxor.platform.html.Entry.Initialize();
};
Main.__super__ = haxor.core.Application;
Main.prototype = $extend(haxor.core.Application.prototype,{
	Load: function() {
		haxor.platform.html.Web.root = "https://dl.dropboxusercontent.com/u/20655747/haxor/resources/";
		return true;
	}
	,Initialize: function() {
		haxor.core.Console.Log("Initialize!");
		this.get_application().set_fps(50);
		var s = 0.8;
		var vl = haxor.io.FloatArray.Alloc([-s,-s,0.5,s,-s,0.5,s,s,0.5,-s,s,0.5]);
		var cl = haxor.io.FloatArray.Alloc([1.0,0.0,0.0,1.0,0.0,1.0,0.0,1.0,0.0,0.0,1.0,1.0,1.0,1.0,0.0,1.0]);
		var il = haxor.io.UInt16Array.Alloc([0,1,2,0,2,3]);
		var m = this.mesh = new haxor.graphics.mesh.Mesh();
		m.Set("vertex",vl,3);
		m.Set("color",cl,4);
		m.set_topology(il);
		if(this.ss == null) this.ss = "\r\n\t\t\t<shader id=\"haxor/debug\">\r\n\t\t\t\t<vertex>\t\t\t\r\n\t\t\t\tattribute vec3 vertex;\r\n\t\t\t\tattribute vec4 color;\t\t\t\r\n\t\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tv_color = color;\r\n\t\t\t\t\tgl_Position = vec4(vertex, 1.0);\t\t\t\t\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</vertex>\t\t\t\r\n\t\t\t\t<fragment>\t\t\t\t\t\r\n\t\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tgl_FragColor = v_color;\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</fragment>\r\n\t\t\t</shader>\r\n\t\t\t";
		var shd = new haxor.graphics.material.Shader(this.ss);
		this.mat = new haxor.graphics.material.Material("DebugMaterial");
		this.mat.blend = true;
		this.mat.SetBlending(770,771);
		this.mat.set_shader(shd);
		haxor.core.Console.Log("Start");
		var t0 = haxor.core.Time.m_clock;
		var len = 10000000;
		var max = 4;
		var total = max;
	}
	,OnActivityComplete: function() {
		haxor.thread.Activity.Run(function(t) {
			if(t < 3.0) return true;
			haxor.core.Console.Log("Time: " + t);
			return false;
		},true);
	}
	,OnUpdate: function() {
		haxor.core.Console.Log("ups[" + haxor.core.Time.m_ups + "] fps[" + haxor.core.Time.m_fps + "] elapsed[" + haxor.core.Time.m_elapsed + "] frames[" + haxor.core.Time.m_frame + "] a[" + this.get_application().get_fps() + "]");
	}
	,OnRender: function() {
		haxor.platform.graphics.GL.m_gl.ClearColor(1.0,0.0,1.0,1.0);
		haxor.platform.graphics.GL.m_gl.ClearDepth(1.0);
		haxor.platform.graphics.GL.m_gl.Clear(16640);
		if(this.mesh == null) return;
		if(this.mat == null) return;
		haxor.graphics.Graphics.RenderMesh(this.mesh,this.mat);
	}
	,__class__: Main
});
var IMap = function() { };
$hxClasses["IMap"] = IMap;
IMap.__name__ = ["IMap"];
Math.__name__ = ["Math"];
var Std = function() { };
$hxClasses["Std"] = Std;
Std.__name__ = ["Std"];
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
};
Std.parseInt = function(x) {
	var v = parseInt(x,10);
	if(v == 0 && (HxOverrides.cca(x,1) == 120 || HxOverrides.cca(x,1) == 88)) v = parseInt(x);
	if(isNaN(v)) return null;
	return v;
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
	,addSub: function(s,pos,len) {
		if(len == null) this.b += HxOverrides.substr(s,pos,null); else this.b += HxOverrides.substr(s,pos,len);
	}
	,__class__: StringBuf
};
var StringTools = function() { };
$hxClasses["StringTools"] = StringTools;
StringTools.__name__ = ["StringTools"];
StringTools.replace = function(s,sub,by) {
	return s.split(sub).join(by);
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
	return haxe.xml.Parser.parse(str);
};
Xml.createElement = function(name) {
	var r = new Xml();
	r.nodeType = Xml.Element;
	r._children = new Array();
	r._attributes = new haxe.ds.StringMap();
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
	,__class__: Xml
};
var haxe = {};
haxe.ds = {};
haxe.ds.StringMap = function() {
	this.h = { };
};
$hxClasses["haxe.ds.StringMap"] = haxe.ds.StringMap;
haxe.ds.StringMap.__name__ = ["haxe","ds","StringMap"];
haxe.ds.StringMap.__interfaces__ = [IMap];
haxe.ds.StringMap.prototype = {
	set: function(key,value) {
		this.h["$" + key] = value;
	}
	,get: function(key) {
		return this.h["$" + key];
	}
	,exists: function(key) {
		return this.h.hasOwnProperty("$" + key);
	}
	,__class__: haxe.ds.StringMap
};
haxe.xml = {};
haxe.xml.Parser = function() { };
$hxClasses["haxe.xml.Parser"] = haxe.xml.Parser;
haxe.xml.Parser.__name__ = ["haxe","xml","Parser"];
haxe.xml.Parser.parse = function(str) {
	var doc = Xml.createDocument();
	haxe.xml.Parser.doParse(str,0,doc);
	return doc;
};
haxe.xml.Parser.doParse = function(str,p,parent) {
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
			p = haxe.xml.Parser.doParse(str,p,xml);
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
				} else if(!haxe.xml.Parser.escapes.exists(s)) buf.b += Std.string("&" + s + ";"); else buf.add(haxe.xml.Parser.escapes.get(s));
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
haxor.context = {};
haxor.context.EngineContext = function() { };
$hxClasses["haxor.context.EngineContext"] = haxor.context.EngineContext;
haxor.context.EngineContext.__name__ = ["haxor","context","EngineContext"];
haxor.context.EngineContext.Initialize = function() {
	haxor.core.Console.Log("Haxor> Engine Context Initialize.",3);
	haxor.context.EngineContext.update = new haxor.context.Process("process.update",haxor.context.EngineContext.maxNodes);
	haxor.context.EngineContext.render = new haxor.context.Process("process.render",haxor.context.EngineContext.maxNodes);
	haxor.context.EngineContext.resize = new haxor.context.Process("process.resize",haxor.context.EngineContext.maxNodes);
	haxor.context.EngineContext.resources = new haxor.context.Process("process.resources",haxor.context.EngineContext.maxNodes);
	haxor.context.EngineContext.disposables = new haxor.context.Process("process.disposables",haxor.context.EngineContext.maxNodes);
	haxor.context.EngineContext.list = [haxor.context.EngineContext.update,haxor.context.EngineContext.render,haxor.context.EngineContext.resize,haxor.context.EngineContext.resources,haxor.context.EngineContext.disposables];
	haxor.context.EngineContext.mesh = new haxor.context.MeshContext();
	haxor.context.EngineContext.material = new haxor.context.MaterialContext();
};
haxor.context.EngineContext.Build = function() {
	haxor.context.EngineContext.mesh.Initialize();
	haxor.context.EngineContext.material.Initialize();
};
haxor.context.EngineContext.Destroy = function(p_resource) {
	if(p_resource.m_destroyed) return;
	p_resource.m_destroyed = true;
	var _g1 = 0;
	var _g = haxor.context.EngineContext.list.length;
	while(_g1 < _g) {
		var i = _g1++;
		haxor.context.EngineContext.list[i].Remove(p_resource);
	}
	haxor.context.EngineContext.disposables.Add(p_resource);
};
haxor.context.MaterialContext = function() {
	this.mid = 0;
	this.sid = 0;
	this.zfunc = 515;
	this.ztest = true;
	this.zwrite = true;
	this.blend = false;
	this.blendSrc = 1;
	this.blendDst = 0;
	this.invert = false;
	this.cull = 2;
	var max_buffers = 512;
	var max_programs = 256;
	this.locations = [];
	this.programs = [];
	this.vertex_shaders = [];
	this.fragment_shaders = [];
	var _g = 0;
	while(_g < max_programs) {
		var i = _g++;
		var l = [];
		var _g1 = 0;
		while(_g1 < max_buffers) {
			var j = _g1++;
			l.push(-1);
		}
		this.locations.push(l);
		this.programs.push(haxor.platform.graphics.GL.NULL);
		this.vertex_shaders.push(haxor.platform.graphics.GL.NULL);
		this.fragment_shaders.push(haxor.platform.graphics.GL.NULL);
	}
};
$hxClasses["haxor.context.MaterialContext"] = haxor.context.MaterialContext;
haxor.context.MaterialContext.__name__ = ["haxor","context","MaterialContext"];
haxor.context.MaterialContext.prototype = {
	Initialize: function() {
		haxor.core.Console.Log("MaterialContext> Initialize.",3);
		haxor.platform.graphics.GL.m_gl.DepthFunc(515);
		haxor.platform.graphics.GL.m_gl.Enable(2929);
		haxor.platform.graphics.GL.m_gl.DepthMask(true);
		haxor.platform.graphics.GL.m_gl.Disable(3042);
		haxor.platform.graphics.GL.m_gl.BlendFunc(1,0);
		haxor.platform.graphics.GL.m_gl.Enable(2884);
		haxor.platform.graphics.GL.m_gl.FrontFace(2305);
		haxor.platform.graphics.GL.m_gl.CullFace(1029);
	}
	,UpdateFlags: function(m) {
		if(m.zfunc != this.zfunc) {
			this.zfunc = m.zfunc;
			haxor.platform.graphics.GL.m_gl.DepthFunc(this.zfunc);
		}
		if(m.ztest != this.ztest) {
			this.ztest = m.ztest;
			if(this.ztest) haxor.platform.graphics.GL.m_gl.Enable(2929); else haxor.platform.graphics.GL.m_gl.Disable(2929);
		}
		if(m.zwrite != this.zwrite) {
			this.zwrite = m.zwrite;
			haxor.platform.graphics.GL.m_gl.DepthMask(this.zwrite);
		}
		if(m.blend != this.blend) {
			this.blend = m.blend;
			if(this.blend) haxor.platform.graphics.GL.m_gl.Enable(3042); else haxor.platform.graphics.GL.m_gl.Disable(3042);
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
		if(blend_change) haxor.platform.graphics.GL.m_gl.BlendFunc(this.blendSrc,this.blendDst);
		if(m.invert != this.invert) {
			this.invert = m.invert;
			haxor.platform.graphics.GL.m_gl.FrontFace(this.invert?2304:2305);
		}
		if(m.cull != this.cull) {
			this.cull = m.cull;
			if(this.cull == 0) haxor.platform.graphics.GL.m_gl.Disable(2884); else {
				haxor.platform.graphics.GL.m_gl.Enable(2884);
				haxor.platform.graphics.GL.m_gl.CullFace(this.cull == 1?1028:1029);
			}
		}
	}
	,InitializeMaterial: function(m) {
		this.programs[m._cid_] = haxor.platform.graphics.GL.m_gl.CreateProgram();
		haxor.core.Console.Log("Material> id[" + Std.string(this.programs[m._cid_]) + "]");
	}
	,InitializeShader: function(s) {
		if(js.Boot.__instanceof(s,haxor.graphics.material.UberShader)) return;
		var vs_err = "";
		var fs_err = "";
		vs_err = this.CreateCompileShader(s,35633,this.vertex_shaders);
		fs_err = this.CreateCompileShader(s,35632,this.fragment_shaders);
		if(s.m_hasError) {
			haxor.core.Console.LogError("Shader> Compile Error @ [" + s.get_name() + "]");
			haxor.core.Console.Log("[vertex]\n" + vs_err);
			haxor.core.Console.Log("[fragment]\n" + fs_err);
		}
		null;
	}
	,CreateCompileShader: function(s,t,c) {
		var id = haxor.platform.graphics.GL.m_gl.CreateShader(t);
		var ss;
		if(t == 35633) ss = s.m_vss; else ss = s.m_fss;
		c[s._cid_] = id;
		haxor.platform.graphics.GL.m_gl.ShaderSource(id,ss);
		haxor.platform.graphics.GL.m_gl.CompileShader(id);
		if(haxor.platform.graphics.GL.m_gl.GetShaderParameter(id,35713) == 0) {
			s.m_hasError = true;
			return haxor.platform.graphics.GL.m_gl.GetShaderInfoLog(id);
		}
		return "";
	}
	,UpdateShader: function(m,s0,s1) {
		var p = this.programs[m._cid_];
		var vs_id;
		var fs_id;
		if(s0 != null) {
			vs_id = this.vertex_shaders[s0._cid_];
			fs_id = this.fragment_shaders[s0._cid_];
			haxor.platform.graphics.GL.m_gl.DetachShader(p,vs_id);
			haxor.platform.graphics.GL.m_gl.DetachShader(p,fs_id);
		}
		if(s1 != null) {
			vs_id = this.vertex_shaders[s1._cid_];
			fs_id = this.fragment_shaders[s1._cid_];
			haxor.platform.graphics.GL.m_gl.AttachShader(p,vs_id);
			haxor.platform.graphics.GL.m_gl.AttachShader(p,fs_id);
			var al = haxor.context.EngineContext.mesh.attribs;
			var _g1 = 0;
			var _g = al.length;
			while(_g1 < _g) {
				var i = _g1++;
				haxor.platform.graphics.GL.m_gl.BindAttribLocation(p,i,al[i]);
			}
			haxor.platform.graphics.GL.m_gl.LinkProgram(p);
			if(haxor.platform.graphics.GL.m_gl.GetProgramParameter(p,35714) == 0) haxor.core.Console.LogError("Material> [" + m.get_name() + "] Link Error @ [" + s1.get_name() + "]");
			var _g11 = 0;
			var _g2 = this.locations[m._cid_].length;
			while(_g11 < _g2) {
				var i1 = _g11++;
				this.locations[m._cid_][i1] = -1;
			}
		}
	}
	,UpdateMaterial: function(m) {
	}
	,GetAttribLocation: function(a) {
		if(this.current == null) return -1;
		var p = this.programs[this.current._cid_];
		var loc = this.locations[this.current._cid_][a._cid_];
		if(loc == -1) {
			loc = haxor.platform.graphics.GL.m_gl.GetAttribLocation(p,a.m_name);
			if(loc < 0) this.locations[this.current._cid_][a._cid_] = -2;
		}
		return loc;
	}
	,Bind: function(m) {
		if(m != this.current) {
			this.current = m;
			if(m != null) {
				this.UpdateFlags(m);
				haxor.platform.graphics.GL.m_gl.UseProgram(this.programs[m._cid_]);
			}
		}
	}
	,Unbind: function() {
	}
	,DestroyMaterial: function(m) {
		var p = this.programs[m._cid_];
		if(m.m_shader != null) {
			haxor.platform.graphics.GL.m_gl.DetachShader(p,this.vertex_shaders[m.m_shader._cid_]);
			haxor.platform.graphics.GL.m_gl.DetachShader(p,this.fragment_shaders[m.m_shader._cid_]);
		}
		haxor.platform.graphics.GL.m_gl.DeleteProgram(p);
	}
	,DestroyShader: function(s) {
		haxor.platform.graphics.GL.m_gl.DeleteShader(this.vertex_shaders[s._cid_]);
		haxor.platform.graphics.GL.m_gl.DeleteShader(this.fragment_shaders[s._cid_]);
	}
	,__class__: haxor.context.MaterialContext
};
haxor.context.MeshContext = function() {
	this.attribs = ["vertex","normal","uv0","uv1","uv2","color","weight","index"];
	this.aid = 0;
	this.mid = 0;
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
		this.buffers.push(haxor.platform.graphics.GL.NULL);
	}
};
$hxClasses["haxor.context.MeshContext"] = haxor.context.MeshContext;
haxor.context.MeshContext.__name__ = ["haxor","context","MeshContext"];
haxor.context.MeshContext.prototype = {
	Initialize: function() {
		haxor.core.Console.Log("MeshContext> Initialize.",3);
	}
	,Bind: function(p_mesh) {
		if(p_mesh != this.current) {
			this.current = p_mesh;
			var a;
			if(this.current != null) {
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
						loc = haxor.context.EngineContext.material.GetAttribLocation(a);
						if(loc < 0) continue;
					}
					type = 5126;
					if(!this.activated[loc]) {
						this.activated[loc] = true;
						this.active_max = Math.max(this.active_max,loc);
						haxor.platform.graphics.GL.m_gl.EnableVertexAttrib(loc);
					}
					haxor.platform.graphics.GL.m_gl.BindBuffer(34962,this.buffers[a._cid_]);
					haxor.platform.graphics.GL.m_gl.VertexAttribPointer(loc,a.offset,type,false,0,0);
				}
				if(!has_color) haxor.platform.graphics.GL.m_gl.VertexAttrib4f(5,1.0,1.0,1.0,1.0);
				if(this.current.m_indexed) {
					a = this.current.m_topology_attrib;
					haxor.platform.graphics.GL.m_gl.BindBuffer(34963,this.buffers[a._cid_]);
				}
				null;
			}
		}
	}
	,Unbind: function() {
	}
	,Draw: function(m) {
		if(m.m_indexed) {
			haxor.platform.graphics.GL.m_gl.DrawElements(m.primitive,m.m_topology_attrib.data.m_length,5123,0);
			null;
		} else {
			haxor.platform.graphics.GL.m_gl.DrawArrays(m.primitive,0,m.m_vcount);
			null;
		}
	}
	,RemoveAttrib: function(p_attrib) {
		var id = this.buffers[p_attrib._cid_];
		if(id == haxor.platform.graphics.GL.NULL) return;
		haxor.platform.graphics.GL.m_gl.DeleteBuffer(id);
		this.buffers[p_attrib._cid_] = haxor.platform.graphics.GL.NULL;
	}
	,UpdateAttrib: function(a,p_mode,p_is_index) {
		var id = this.buffers[a._cid_];
		var target_flag;
		if(p_is_index) target_flag = 34963; else target_flag = 34962;
		a._loc_ = HxOverrides.indexOf(this.attribs,a.m_name,0);
		if(id == haxor.platform.graphics.GL.NULL) {
			id = haxor.platform.graphics.GL.m_gl.CreateBuffer();
			this.buffers[a._cid_] = id;
		}
		haxor.platform.graphics.GL.m_gl.BindBuffer(target_flag,id);
		haxor.platform.graphics.GL.m_gl.BufferData(target_flag,a.data,p_mode);
		null;
	}
	,__class__: haxor.context.MeshContext
};
haxor.context.BaseProcess = function(p_name) {
	this.name = p_name;
	haxor.core.Console.Log("\tProcess [" + p_name + "] created.",4);
	this._cid_ = haxor.context.BaseProcess.m_cid++;
};
$hxClasses["haxor.context.BaseProcess"] = haxor.context.BaseProcess;
haxor.context.BaseProcess.__name__ = ["haxor","context","BaseProcess"];
haxor.context.BaseProcess.prototype = {
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
	,__class__: haxor.context.BaseProcess
};
haxor.context.Process = function(p_name,p_size) {
	haxor.context.BaseProcess.call(this,p_name);
	this.list = [];
	this.m_length = 0;
	var _g = 0;
	while(_g < p_size) {
		var i = _g++;
		this.list.push(null);
	}
};
$hxClasses["haxor.context.Process"] = haxor.context.Process;
haxor.context.Process.__name__ = ["haxor","context","Process"];
haxor.context.Process.__super__ = haxor.context.BaseProcess;
haxor.context.Process.prototype = $extend(haxor.context.BaseProcess.prototype,{
	get_length: function() {
		return this.m_length;
	}
	,Add: function(p_item) {
		var iid = p_item.m_pid[this._cid_];
		if(iid >= 0) return;
		this.list[this.m_length] = p_item;
		p_item.m_pid[this._cid_] = this.m_length++;
	}
	,Remove: function(p_item) {
		var iid = p_item.m_pid[this._cid_];
		if(iid < 0) return p_item;
		p_item.m_pid[this._cid_] = -1;
		this.m_length--;
		if(this.m_length <= 0) return p_item;
		this.list[iid] = this.list[this.m_length];
		p_item = this.list[iid];
		p_item.m_pid[this._cid_] = iid;
		return p_item;
	}
	,Clear: function() {
		this.m_length = 0;
		this.list = [];
	}
	,__class__: haxor.context.Process
});
haxor.core.Platform = { __ename__ : true, __constructs__ : ["Unknown","Windows","Linux","Android","MacOS","iOS","HTML","NodeJS"] };
haxor.core.Platform.Unknown = ["Unknown",0];
haxor.core.Platform.Unknown.__enum__ = haxor.core.Platform;
haxor.core.Platform.Windows = ["Windows",1];
haxor.core.Platform.Windows.__enum__ = haxor.core.Platform;
haxor.core.Platform.Linux = ["Linux",2];
haxor.core.Platform.Linux.__enum__ = haxor.core.Platform;
haxor.core.Platform.Android = ["Android",3];
haxor.core.Platform.Android.__enum__ = haxor.core.Platform;
haxor.core.Platform.MacOS = ["MacOS",4];
haxor.core.Platform.MacOS.__enum__ = haxor.core.Platform;
haxor.core.Platform.iOS = ["iOS",5];
haxor.core.Platform.iOS.__enum__ = haxor.core.Platform;
haxor.core.Platform.HTML = ["HTML",6];
haxor.core.Platform.HTML.__enum__ = haxor.core.Platform;
haxor.core.Platform.NodeJS = ["NodeJS",7];
haxor.core.Platform.NodeJS.__enum__ = haxor.core.Platform;
haxor.core.ApplicationProtocol = { __ename__ : true, __constructs__ : ["None","File","HTTP","HTTPS"] };
haxor.core.ApplicationProtocol.None = ["None",0];
haxor.core.ApplicationProtocol.None.__enum__ = haxor.core.ApplicationProtocol;
haxor.core.ApplicationProtocol.File = ["File",1];
haxor.core.ApplicationProtocol.File.__enum__ = haxor.core.ApplicationProtocol;
haxor.core.ApplicationProtocol.HTTP = ["HTTP",2];
haxor.core.ApplicationProtocol.HTTP.__enum__ = haxor.core.ApplicationProtocol;
haxor.core.ApplicationProtocol.HTTPS = ["HTTPS",3];
haxor.core.ApplicationProtocol.HTTPS.__enum__ = haxor.core.ApplicationProtocol;
haxor.core.Console = function() { };
$hxClasses["haxor.core.Console"] = haxor.core.Console;
haxor.core.Console.__name__ = ["haxor","core","Console"];
haxor.core.Console.Initialize = function() {
};
haxor.core.Console.Breakpoint = function() {
	debugger;
};
haxor.core.Console.Log = function(p_msg,p_level) {
	if(p_level == null) p_level = 0;
	if(haxor.core.Console.verbose >= p_level) console.log(p_msg);
};
haxor.core.Console.LogImage = function(p_url,p_height) {
	var s = "background: transparent url(" + p_url + ") no-repeat; font-size: " + (p_height - 3) + "px;";
	haxor.core.Console.m_console.log("%c                                                                                                                                                            ",s);
};
haxor.core.Console.LogWarning = function(p_msg,p_obj) {
	if(haxor.core.Console.m_console == null) console.log("[W] " + p_msg);
	if(p_obj == null) p_obj = [];
	var _g = p_obj.length;
	switch(_g) {
	case 0:
		haxor.core.Console.m_console.warn(p_msg);
		break;
	case 1:
		haxor.core.Console.m_console.warn(p_msg,p_obj[0]);
		break;
	case 2:
		haxor.core.Console.m_console.warn(p_msg,p_obj[0],p_obj[1]);
		break;
	case 3:
		haxor.core.Console.m_console.warn(p_msg,p_obj[0],p_obj[1],p_obj[2]);
		break;
	case 4:
		haxor.core.Console.m_console.warn(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3]);
		break;
	}
};
haxor.core.Console.LogError = function(p_msg,p_obj) {
	if(haxor.core.Console.m_console == null) {
		console.log("[E] " + p_msg);
		return;
	}
	if(p_obj == null) p_obj = [];
	var _g = p_obj.length;
	switch(_g) {
	case 0:
		haxor.core.Console.m_console.error(p_msg);
		break;
	case 1:
		haxor.core.Console.m_console.error(p_msg,p_obj[0]);
		break;
	case 2:
		haxor.core.Console.m_console.error(p_msg,p_obj[0],p_obj[1]);
		break;
	case 3:
		haxor.core.Console.m_console.error(p_msg,p_obj[0],p_obj[1],p_obj[2]);
		break;
	case 4:
		haxor.core.Console.m_console.error(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3]);
		break;
	}
};
haxor.core.Console.ClearStyle = function() {
	haxor.core.Console.m_style = "";
};
haxor.core.Console.Clear = function() {
	if(haxor.core.Console.m_console != null) haxor.core.Console.m_console.clear();
};
haxor.core.Console.TimeStart = function(p_id) {
	if(haxor.core.Console.m_console != null) haxor.core.Console.m_console.time(p_id);
};
haxor.core.Console.TimeEnd = function(p_id) {
	if(haxor.core.Console.m_console != null) haxor.core.Console.m_console.timeEnd(p_id);
};
haxor.core.Console.StackTrace = function() {
	if(haxor.core.Console.m_console != null) haxor.core.Console.m_console.trace();
};
haxor.core.Console.SetStyle = function(p_size,p_color,p_background,p_font) {
	if(p_font == null) p_font = "'Lucida Console', Monaco, monospace";
	if(p_background == null) p_background = "rgba(255,255,255,0)";
	if(p_color == null) p_color = "rgba(0,0,0,1)";
	if(p_size == null) p_size = "12px";
	haxor.core.Console.m_style = "background-color: " + p_background + "; font-size: " + p_size + "; color: " + p_color + "; font-family: " + p_font + ";";
};
haxor.core.EngineState = { __ename__ : true, __constructs__ : ["Play","Editor"] };
haxor.core.EngineState.Play = ["Play",0];
haxor.core.EngineState.Play.__enum__ = haxor.core.EngineState;
haxor.core.EngineState.Editor = ["Editor",1];
haxor.core.EngineState.Editor.__enum__ = haxor.core.EngineState;
haxor.core.Engine = function() { };
$hxClasses["haxor.core.Engine"] = haxor.core.Engine;
haxor.core.Engine.__name__ = ["haxor","core","Engine"];
haxor.core.Engine.Initialize = function() {
	haxor.core.Console.Log("Haxor> Engine Initialize.",3);
	haxor.context.EngineContext.Initialize();
	haxor.core.Engine.state = haxor.core.EngineState.Play;
};
haxor.core.Engine.Collect = function() {
	var dp = haxor.context.EngineContext.disposables;
	var _g1 = 0;
	var _g = haxor.context.EngineContext.collectRate;
	while(_g1 < _g) {
		var i = _g1++;
		if(dp.m_length <= 0) break;
		var o = dp.list[0];
		o.OnDestroy();
		dp.Remove(o);
	}
};
haxor.core.Engine.Update = function() {
	if(haxor.core.Engine.state == haxor.core.EngineState.Editor) return;
	var up = haxor.context.EngineContext.update;
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
haxor.core.Engine.Render = function() {
	var rp = haxor.context.EngineContext.render;
	var _g1 = 0;
	var _g = rp.m_length;
	while(_g1 < _g) {
		var i = _g1++;
		var r = rp.list[i];
		if(r.m_destroyed) continue;
		rp.list[i].OnRender();
	}
};
haxor.core.Engine.Resize = function() {
	if(haxor.core.Engine.state == haxor.core.EngineState.Editor) return;
	var rp = haxor.context.EngineContext.resize;
	var _g1 = 0;
	var _g = rp.m_length;
	while(_g1 < _g) {
		var i = _g1++;
		var r = rp.list[i];
		if(r.m_destroyed) continue;
		rp.list[i].OnResize(haxor.graphics.Screen.m_width,haxor.graphics.Screen.m_height);
	}
};
haxor.core.Entity = function(p_name) {
	haxor.core.Resource.call(this,p_name);
	this.m_enabled = true;
	this.m_components = [];
};
$hxClasses["haxor.core.Entity"] = haxor.core.Entity;
haxor.core.Entity.__name__ = ["haxor","core","Entity"];
haxor.core.Entity.__super__ = haxor.core.Resource;
haxor.core.Entity.prototype = $extend(haxor.core.Resource.prototype,{
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
	,AddComponent: function(p_type) {
		if(this.m_destroyed) return null;
		var c = Type.createInstance(p_type,[]);
		c.m_entity = this;
		if(c.m_is_behaviour) {
			var b = c;
			b.set_enabled(this.m_enabled && !this.m_destroyed);
		}
		this.m_components.push(c);
		return c;
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
	,__class__: haxor.core.Entity
});
haxor.core.IResizeable = function() { };
$hxClasses["haxor.core.IResizeable"] = haxor.core.IResizeable;
haxor.core.IResizeable.__name__ = ["haxor","core","IResizeable"];
haxor.core.IResizeable.prototype = {
	__class__: haxor.core.IResizeable
};
haxor.core.Scene = function(p_name) {
	haxor.core.Resource.call(this,p_name);
};
$hxClasses["haxor.core.Scene"] = haxor.core.Scene;
haxor.core.Scene.__name__ = ["haxor","core","Scene"];
haxor.core.Scene.__super__ = haxor.core.Resource;
haxor.core.Scene.prototype = $extend(haxor.core.Resource.prototype,{
	__class__: haxor.core.Scene
});
haxor.core.Time = function() { };
$hxClasses["haxor.core.Time"] = haxor.core.Time;
haxor.core.Time.__name__ = ["haxor","core","Time"];
haxor.core.Time.get_clock = function() {
	return haxor.core.Time.m_clock;
};
haxor.core.Time.get_delta = function() {
	return haxor.core.Time.m_delta;
};
haxor.core.Time.get_elapsed = function() {
	return haxor.core.Time.m_elapsed;
};
haxor.core.Time.get_fps = function() {
	return haxor.core.Time.m_fps;
};
haxor.core.Time.get_ups = function() {
	return haxor.core.Time.m_ups;
};
haxor.core.Time.get_frame = function() {
	return haxor.core.Time.m_frame;
};
haxor.core.Time.Initialize = function() {
	haxor.core.Time.m_clock = 0.0;
	haxor.core.Time.m_clock_dt = 0.0;
	haxor.core.Time.m_clock_0 = 0.0;
	haxor.core.Time.m_clock_0 = haxor.core.Time.m_clock;
	haxor.core.Time.m_start_clock = haxor.core.Time.m_clock;
	haxor.core.Time.m_last_clock = haxor.core.Time.m_clock;
	haxor.core.Time.m_last_frame_clock = haxor.core.Time.m_clock;
	haxor.core.Time.m_stats_clock = haxor.core.Time.m_clock;
	haxor.core.Time.m_elapsed = 0.0;
	haxor.core.Time.m_delta = 0.0;
	haxor.core.Time.m_frame_delta = 0.0;
	haxor.core.Time.m_ups = 0;
	haxor.core.Time.m_fps = 0;
	haxor.core.Time.m_updates = 0.0;
	haxor.core.Time.m_frame_count = 0.0;
	haxor.core.Time.m_frame = 0;
	null;
};
haxor.core.Time.Update = function() {
	haxor.core.Time.m_clock_dt = haxor.core.Time.m_clock - haxor.core.Time.m_last_clock;
	if(haxor.core.Time.m_clock_dt <= 0) haxor.core.Time.m_clock_dt = 1.0;
	haxor.core.Time.m_last_clock = haxor.core.Time.m_clock;
	haxor.core.Time.m_delta = haxor.core.Time.m_clock_dt * 0.001;
	haxor.core.Time.m_elapsed = haxor.core.Time.m_clock * 0.001;
	haxor.core.Time.m_updates += 1.0;
	if(haxor.core.Time.m_clock - haxor.core.Time.m_stats_clock >= 1000.0) {
		haxor.core.Time.m_stats_clock += haxor.core.Time.m_clock - haxor.core.Time.m_stats_clock;
		haxor.core.Time.m_ups = haxor.core.Time.m_updates;
		haxor.core.Time.m_fps = haxor.core.Time.m_frame_count;
		haxor.core.Time.m_updates = 0.0;
		haxor.core.Time.m_frame_count = 0.0;
	}
};
haxor.core.Time.Render = function() {
	haxor.core.Time.m_frame_count += 1.0;
	haxor.core.Time.m_frame++;
	haxor.core.Time.m_frame_delta = (haxor.core.Time.m_clock - haxor.core.Time.m_last_frame_clock) * 0.001;
	haxor.core.Time.m_last_frame_clock = haxor.core.Time.m_clock;
};
haxor.core.Time.UpdateClock = function() {
};
haxor.graphics = {};
haxor.graphics.RenderQueue = function() { };
$hxClasses["haxor.graphics.RenderQueue"] = haxor.graphics.RenderQueue;
haxor.graphics.RenderQueue.__name__ = ["haxor","graphics","RenderQueue"];
haxor.graphics.BlendMode = function() { };
$hxClasses["haxor.graphics.BlendMode"] = haxor.graphics.BlendMode;
haxor.graphics.BlendMode.__name__ = ["haxor","graphics","BlendMode"];
haxor.graphics.MeshMode = function() { };
$hxClasses["haxor.graphics.MeshMode"] = haxor.graphics.MeshMode;
haxor.graphics.MeshMode.__name__ = ["haxor","graphics","MeshMode"];
haxor.graphics.MeshPrimitive = function() { };
$hxClasses["haxor.graphics.MeshPrimitive"] = haxor.graphics.MeshPrimitive;
haxor.graphics.MeshPrimitive.__name__ = ["haxor","graphics","MeshPrimitive"];
haxor.graphics.CullMode = function() { };
$hxClasses["haxor.graphics.CullMode"] = haxor.graphics.CullMode;
haxor.graphics.CullMode.__name__ = ["haxor","graphics","CullMode"];
haxor.graphics.DepthTest = function() { };
$hxClasses["haxor.graphics.DepthTest"] = haxor.graphics.DepthTest;
haxor.graphics.DepthTest.__name__ = ["haxor","graphics","DepthTest"];
haxor.graphics.BufferPrimitive = function() { };
$hxClasses["haxor.graphics.BufferPrimitive"] = haxor.graphics.BufferPrimitive;
haxor.graphics.BufferPrimitive.__name__ = ["haxor","graphics","BufferPrimitive"];
haxor.graphics.Graphics = function() { };
$hxClasses["haxor.graphics.Graphics"] = haxor.graphics.Graphics;
haxor.graphics.Graphics.__name__ = ["haxor","graphics","Graphics"];
haxor.graphics.Graphics.RenderMesh = function(p_mesh,p_material) {
	haxor.context.EngineContext.material.Bind(p_material);
	haxor.context.EngineContext.mesh.Bind(p_mesh);
	if(p_mesh.m_indexed) {
		haxor.platform.graphics.GL.m_gl.DrawElements(p_mesh.primitive,p_mesh.m_topology_attrib.data.m_length,5123,0);
		null;
	} else {
		haxor.platform.graphics.GL.m_gl.DrawArrays(p_mesh.primitive,0,p_mesh.m_vcount);
		null;
	}
};
haxor.graphics.Screen = function() { };
$hxClasses["haxor.graphics.Screen"] = haxor.graphics.Screen;
haxor.graphics.Screen.__name__ = ["haxor","graphics","Screen"];
haxor.graphics.Screen.get_width = function() {
	return haxor.graphics.Screen.m_width;
};
haxor.graphics.Screen.get_height = function() {
	return haxor.graphics.Screen.m_height;
};
haxor.graphics.Screen.get_fullscreen = function() {
	return haxor.graphics.Screen.m_fullscreen;
};
haxor.graphics.Screen.set_fullscreen = function(v) {
	haxor.graphics.Screen.m_fullscreen = haxor.graphics.Screen.m_application.OnFullscreenRequest(v);
	return haxor.graphics.Screen.m_fullscreen;
};
haxor.graphics.Screen.get_cursor = function() {
	return haxor.graphics.Screen.m_cursor;
};
haxor.graphics.Screen.set_cursor = function(v) {
	if(v == haxor.graphics.CursorMode.Lock) {
		var is_locked = haxor.graphics.Screen.m_application.OnPointerLockRequest(true);
		if(!is_locked) return haxor.graphics.Screen.m_cursor = haxor.graphics.CursorMode.Show;
		haxor.graphics.Screen.m_application.OnPointerVisibilityRequest(false);
		return haxor.graphics.Screen.m_cursor = haxor.graphics.CursorMode.Lock;
	}
	haxor.graphics.Screen.m_application.OnPointerLockRequest(false);
	var is_visible = haxor.graphics.Screen.m_application.OnPointerVisibilityRequest(v == haxor.graphics.CursorMode.Show);
	return is_visible?haxor.graphics.Screen.m_cursor = haxor.graphics.CursorMode.Show:haxor.graphics.Screen.m_cursor = haxor.graphics.CursorMode.Hide;
};
haxor.graphics.Screen.Initialize = function() {
	haxor.graphics.Screen.m_width = 0;
	haxor.graphics.Screen.m_height = 0;
	haxor.graphics.Screen.m_fullscreen = false;
	haxor.graphics.Screen.m_cursor = haxor.graphics.CursorMode.Show;
	haxor.graphics.Screen.m_application = null;
};
haxor.graphics.CursorMode = { __ename__ : true, __constructs__ : ["Show","Hide","Lock"] };
haxor.graphics.CursorMode.Show = ["Show",0];
haxor.graphics.CursorMode.Show.__enum__ = haxor.graphics.CursorMode;
haxor.graphics.CursorMode.Hide = ["Hide",1];
haxor.graphics.CursorMode.Hide.__enum__ = haxor.graphics.CursorMode;
haxor.graphics.CursorMode.Lock = ["Lock",2];
haxor.graphics.CursorMode.Lock.__enum__ = haxor.graphics.CursorMode;
haxor.graphics.material = {};
haxor.graphics.material.Material = function(p_name) {
	this.grab = false;
	haxor.core.Resource.call(this,p_name);
	this._cid_ = haxor.context.EngineContext.material.mid++;
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
	haxor.context.EngineContext.material.InitializeMaterial(this);
};
$hxClasses["haxor.graphics.material.Material"] = haxor.graphics.material.Material;
haxor.graphics.material.Material.__name__ = ["haxor","graphics","material","Material"];
haxor.graphics.material.Material.__super__ = haxor.core.Resource;
haxor.graphics.material.Material.prototype = $extend(haxor.core.Resource.prototype,{
	get_shader: function() {
		return this.m_shader;
	}
	,set_shader: function(v) {
		if(this.m_shader == v) return v;
		haxor.context.EngineContext.material.UpdateShader(this,this.m_shader,v);
		this.m_shader = v;
		return v;
	}
	,SetBlending: function(p_src,p_dst) {
		this.blend = !(p_src == 1 && p_dst == 0);
		this.blendSrc = p_src;
		this.blendDst = p_dst;
	}
	,OnDestroy: function() {
		haxor.context.EngineContext.material.DestroyMaterial(this);
	}
	,__class__: haxor.graphics.material.Material
});
haxor.graphics.material.Shader = function(p_source) {
	haxor.core.Resource.call(this);
	this._cid_ = haxor.context.EngineContext.material.sid++;
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
	if(this.get_name() == null || this.get_name() == "") this.set_name("Shader" + this._cid_);
	var vs = x.elementsNamed("vertex").next();
	var fs = x.elementsNamed("fragment").next();
	this.m_vss = this.GetShaderSource(vs);
	this.m_fss = this.GetShaderSource(fs);
	this.m_hasError = false;
	haxor.context.EngineContext.material.InitializeShader(this);
};
$hxClasses["haxor.graphics.material.Shader"] = haxor.graphics.material.Shader;
haxor.graphics.material.Shader.__name__ = ["haxor","graphics","material","Shader"];
haxor.graphics.material.Shader.__super__ = haxor.core.Resource;
haxor.graphics.material.Shader.prototype = $extend(haxor.core.Resource.prototype,{
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
		haxor.context.EngineContext.material.DestroyShader(this);
	}
	,__class__: haxor.graphics.material.Shader
});
haxor.graphics.material.UberShader = function(p_source) {
	haxor.graphics.material.Shader.call(this,p_source);
};
$hxClasses["haxor.graphics.material.UberShader"] = haxor.graphics.material.UberShader;
haxor.graphics.material.UberShader.__name__ = ["haxor","graphics","material","UberShader"];
haxor.graphics.material.UberShader.__super__ = haxor.graphics.material.Shader;
haxor.graphics.material.UberShader.prototype = $extend(haxor.graphics.material.Shader.prototype,{
	__class__: haxor.graphics.material.UberShader
});
haxor.graphics.mesh = {};
haxor.graphics.mesh.Mesh = function() {
	haxor.core.Resource.call(this);
	this._cid_ = haxor.context.EngineContext.mesh.mid++;
	this.m_attribs = [];
	this.m_indexed = false;
	this.m_vcount = 0;
	this.m_mode = 35048;
	this.primitive = 4;
	this.m_topology_attrib = new haxor.graphics.mesh.MeshAttrib();
	this.m_topology_attrib.m_name = "$topology";
	this.m_topology_attrib.offset = 1;
};
$hxClasses["haxor.graphics.mesh.Mesh"] = haxor.graphics.mesh.Mesh;
haxor.graphics.mesh.Mesh.__name__ = ["haxor","graphics","mesh","Mesh"];
haxor.graphics.mesh.Mesh.__super__ = haxor.core.Resource;
haxor.graphics.mesh.Mesh.prototype = $extend(haxor.core.Resource.prototype,{
	get_topology: function() {
		if(this.m_topology_attrib.data == null) return new haxor.io.UInt16Array(0);
		return this.m_topology_attrib.data;
	}
	,set_topology: function(v) {
		if(v == null) {
			this.m_topology_attrib.data = null;
			this.m_indexed = false;
			haxor.context.EngineContext.mesh.RemoveAttrib(this.m_topology_attrib);
		} else {
			this.m_topology_attrib.data = v;
			this.m_indexed = true;
			haxor.context.EngineContext.mesh.UpdateAttrib(this.m_topology_attrib,this.m_mode,true);
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
		if(this.m_indexed) haxor.context.EngineContext.mesh.UpdateAttrib(this.m_topology_attrib,this.m_mode,true);
		var _g1 = 0;
		var _g = this.m_attribs.length;
		while(_g1 < _g) {
			var i = _g1++;
			haxor.context.EngineContext.mesh.UpdateAttrib(this.m_attribs[i],this.m_mode,false);
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
	,Clear: function(p_from_gpu) {
		if(p_from_gpu == null) p_from_gpu = true;
		var _g1 = 0;
		var _g = this.m_attribs.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_attribs[i].data = null;
			this.m_attribs[i].m_name = "";
			if(p_from_gpu) haxor.context.EngineContext.mesh.RemoveAttrib(this.m_attribs[i]);
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
		haxor.context.EngineContext.mesh.RemoveAttrib(a);
	}
	,Set: function(p_name,p_data,p_offset) {
		if(p_offset == null) p_offset = 3;
		if(p_data == null) {
			haxor.core.Console.Log("Mesh> [" + this.get_name() + "] tried to set null array.",1);
			return;
		}
		if(p_data.m_length <= 0) {
			haxor.core.Console.Log("Mesh> [" + this.get_name() + "] tried to set empty array.",1);
			return;
		}
		var a = this.GetAttribute(p_name);
		if(a == null) {
			a = new haxor.graphics.mesh.MeshAttrib();
			a.m_name = p_name;
			this.m_attribs.push(a);
		}
		a.offset = p_offset;
		a.data = p_data;
		this.m_vcount = this.m_attribs[0].get_count();
		var _g1 = 1;
		var _g = this.m_attribs.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = this.m_attribs[i].get_count();
			if(this.m_vcount < c) this.m_vcount = this.m_vcount; else this.m_vcount = c;
		}
		haxor.context.EngineContext.mesh.UpdateAttrib(a,this.m_mode,false);
	}
	,OnDestroy: function() {
		this.Clear();
	}
	,__class__: haxor.graphics.mesh.Mesh
});
haxor.graphics.mesh.MeshAttrib = function() {
	this._cid_ = haxor.context.EngineContext.mesh.aid++;
	this._loc_ = -1;
	this.m_name = "";
	this.data = null;
	this.offset = 0;
};
$hxClasses["haxor.graphics.mesh.MeshAttrib"] = haxor.graphics.mesh.MeshAttrib;
haxor.graphics.mesh.MeshAttrib.__name__ = ["haxor","graphics","mesh","MeshAttrib"];
haxor.graphics.mesh.MeshAttrib.prototype = {
	get_name: function() {
		return this.m_name;
	}
	,get_count: function() {
		if(this.data == null) return 0; else return this.data.m_length / this.offset | 0;
	}
	,__class__: haxor.graphics.mesh.MeshAttrib
};
haxor.io = {};
haxor.io.Buffer = function(p_length) {
	this.m_length = p_length;
	var len = this.m_length * this.get_bytesPerElement();
	this.m_buffer = new Uint8Array(len);
};
$hxClasses["haxor.io.Buffer"] = haxor.io.Buffer;
haxor.io.Buffer.__name__ = ["haxor","io","Buffer"];
haxor.io.Buffer.prototype = {
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
	,GetByte: function(p_index) {
		return this.m_buffer[p_index];
		return 0;
	}
	,SetByte: function(p_index,p_value) {
		this.m_buffer[p_index] = p_value;
	}
	,__class__: haxor.io.Buffer
};
haxor.io.FloatArray = function(p_length) {
	haxor.io.Buffer.call(this,p_length);
	this.aux = new Float32Array(this.m_buffer.buffer);
};
$hxClasses["haxor.io.FloatArray"] = haxor.io.FloatArray;
haxor.io.FloatArray.__name__ = ["haxor","io","FloatArray"];
haxor.io.FloatArray.Alloc = function(p_data) {
	var b = new haxor.io.FloatArray(p_data.length);
	b.SetRange(p_data);
	return b;
};
haxor.io.FloatArray.__super__ = haxor.io.Buffer;
haxor.io.FloatArray.prototype = $extend(haxor.io.Buffer.prototype,{
	get_bytesPerElement: function() {
		return 4;
	}
	,Get: function(p_index) {
		return this.aux[p_index];
	}
	,Set: function(p_index,p_value) {
		this.aux[p_index] = p_value;
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
	,__class__: haxor.io.FloatArray
});
haxor.io.UInt16Array = function(p_length) {
	haxor.io.Buffer.call(this,p_length);
	this.aux = new Uint16Array(this.m_buffer.buffer);
};
$hxClasses["haxor.io.UInt16Array"] = haxor.io.UInt16Array;
haxor.io.UInt16Array.__name__ = ["haxor","io","UInt16Array"];
haxor.io.UInt16Array.Alloc = function(p_data) {
	var b = new haxor.io.UInt16Array(p_data.length);
	b.SetRange(p_data);
	return b;
};
haxor.io.UInt16Array.__super__ = haxor.io.Buffer;
haxor.io.UInt16Array.prototype = $extend(haxor.io.Buffer.prototype,{
	get_bytesPerElement: function() {
		return 2;
	}
	,Get: function(p_index) {
		return this.aux[p_index];
	}
	,Set: function(p_index,p_value) {
		this.aux[p_index] = p_value;
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
	,__class__: haxor.io.UInt16Array
});
haxor.platform.graphics = {};
haxor.platform.graphics.GL = function() { };
$hxClasses["haxor.platform.graphics.GL"] = haxor.platform.graphics.GL;
haxor.platform.graphics.GL.__name__ = ["haxor","platform","graphics","GL"];
haxor.platform.graphics.GL.get_api = function() {
	return haxor.platform.graphics.GL.m_gl.get_api();
};
haxor.platform.graphics.GL.Initialize = function(p_application) {
	haxor.platform.graphics.GL.m_gl = new haxor.platform.graphics.WebGL(p_application);
	haxor.platform.graphics.GL.m_gl.CheckExtensions();
};
haxor.platform.graphics.GL.Resize = function() {
	haxor.platform.graphics.GL.m_gl.Resize();
};
haxor.platform.graphics.GL.BindBuffer = function(p_target,p_id) {
	haxor.platform.graphics.GL.m_gl.BindBuffer(p_target,p_id);
};
haxor.platform.graphics.GL.BufferData = function(p_target,p_data,p_mode) {
	haxor.platform.graphics.GL.m_gl.BufferData(p_target,p_data,p_mode);
};
haxor.platform.graphics.GL.BufferSubData = function(p_target,p_offset,p_data) {
	haxor.platform.graphics.GL.m_gl.BufferSubData(p_target,p_offset,p_data);
};
haxor.platform.graphics.GL.CreateBuffer = function() {
	return haxor.platform.graphics.GL.m_gl.CreateBuffer();
};
haxor.platform.graphics.GL.DrawArrays = function(p_primitive,p_start,p_count) {
	haxor.platform.graphics.GL.m_gl.DrawArrays(p_primitive,p_start,p_count);
};
haxor.platform.graphics.GL.DrawElements = function(p_primitive,p_count,p_type,p_offset) {
	haxor.platform.graphics.GL.m_gl.DrawElements(p_primitive,p_count,p_type,p_offset);
};
haxor.platform.graphics.GL.DeleteBuffer = function(p_id) {
	haxor.platform.graphics.GL.m_gl.DeleteBuffer(p_id);
};
haxor.platform.graphics.GL.DisableVertexAttrib = function(p_location) {
	haxor.platform.graphics.GL.m_gl.DisableVertexAttrib(p_location);
};
haxor.platform.graphics.GL.EnableVertexAttrib = function(p_location) {
	haxor.platform.graphics.GL.m_gl.EnableVertexAttrib(p_location);
};
haxor.platform.graphics.GL.VertexAttrib3f = function(p_location,p_x,p_y,p_z) {
	haxor.platform.graphics.GL.m_gl.VertexAttrib3f(p_location,p_x,p_y,p_z);
};
haxor.platform.graphics.GL.VertexAttrib4f = function(p_location,p_x,p_y,p_z,p_w) {
	haxor.platform.graphics.GL.m_gl.VertexAttrib4f(p_location,p_x,p_y,p_z,p_w);
};
haxor.platform.graphics.GL.VertexAttribPointer = function(p_location,p_components_size,p_type,p_normalized,p_stride,p_offset) {
	haxor.platform.graphics.GL.m_gl.VertexAttribPointer(p_location,p_components_size,p_type,p_normalized,p_stride,p_offset);
};
haxor.platform.graphics.GL.CompileShader = function(p_shader) {
	haxor.platform.graphics.GL.m_gl.CompileShader(p_shader);
};
haxor.platform.graphics.GL.CreateShader = function(p_type) {
	return haxor.platform.graphics.GL.m_gl.CreateShader(p_type);
};
haxor.platform.graphics.GL.DetachShader = function(p_program,p_shader) {
	haxor.platform.graphics.GL.m_gl.DetachShader(p_program,p_shader);
};
haxor.platform.graphics.GL.DeleteShader = function(p_shader) {
	haxor.platform.graphics.GL.m_gl.DeleteShader(p_shader);
};
haxor.platform.graphics.GL.GetShaderInfoLog = function(p_shader) {
	return haxor.platform.graphics.GL.m_gl.GetShaderInfoLog(p_shader);
};
haxor.platform.graphics.GL.GetShaderParameter = function(p_shader,p_parameter) {
	return haxor.platform.graphics.GL.m_gl.GetShaderParameter(p_shader,p_parameter);
};
haxor.platform.graphics.GL.ShaderSource = function(p_shader,p_source) {
	haxor.platform.graphics.GL.m_gl.ShaderSource(p_shader,p_source);
};
haxor.platform.graphics.GL.AttachShader = function(p_program,p_shader) {
	haxor.platform.graphics.GL.m_gl.AttachShader(p_program,p_shader);
};
haxor.platform.graphics.GL.BindAttribLocation = function(p_program,p_location,p_name) {
	haxor.platform.graphics.GL.m_gl.BindAttribLocation(p_program,p_location,p_name);
};
haxor.platform.graphics.GL.CreateProgram = function() {
	return haxor.platform.graphics.GL.m_gl.CreateProgram();
};
haxor.platform.graphics.GL.DeleteProgram = function(p_program) {
	haxor.platform.graphics.GL.m_gl.DeleteProgram(p_program);
};
haxor.platform.graphics.GL.GetAttribLocation = function(p_program,p_name) {
	return haxor.platform.graphics.GL.m_gl.GetAttribLocation(p_program,p_name);
};
haxor.platform.graphics.GL.GetProgramInfoLog = function(p_program) {
	return haxor.platform.graphics.GL.m_gl.GetProgramInfoLog(p_program);
};
haxor.platform.graphics.GL.GetProgramParameter = function(p_program,p_parameter) {
	return haxor.platform.graphics.GL.m_gl.GetProgramParameter(p_program,p_parameter);
};
haxor.platform.graphics.GL.LinkProgram = function(p_program) {
	haxor.platform.graphics.GL.m_gl.LinkProgram(p_program);
};
haxor.platform.graphics.GL.UseProgram = function(p_program) {
	haxor.platform.graphics.GL.m_gl.UseProgram(p_program);
};
haxor.platform.graphics.GL.BlendFunc = function(p_src,p_dst) {
	haxor.platform.graphics.GL.m_gl.BlendFunc(p_src,p_dst);
};
haxor.platform.graphics.GL.Disable = function(p_flag) {
	haxor.platform.graphics.GL.m_gl.Disable(p_flag);
};
haxor.platform.graphics.GL.Enable = function(p_flag) {
	haxor.platform.graphics.GL.m_gl.Enable(p_flag);
};
haxor.platform.graphics.GL.DepthMask = function(p_flag) {
	haxor.platform.graphics.GL.m_gl.DepthMask(p_flag);
};
haxor.platform.graphics.GL.DepthFunc = function(p_flag) {
	haxor.platform.graphics.GL.m_gl.DepthFunc(p_flag);
};
haxor.platform.graphics.GL.CullFace = function(p_face) {
	haxor.platform.graphics.GL.m_gl.CullFace(p_face);
};
haxor.platform.graphics.GL.FrontFace = function(p_face) {
	haxor.platform.graphics.GL.m_gl.FrontFace(p_face);
};
haxor.platform.graphics.GL.Clear = function(p_flag) {
	haxor.platform.graphics.GL.m_gl.Clear(p_flag);
};
haxor.platform.graphics.GL.ClearDepth = function(p_value) {
	haxor.platform.graphics.GL.m_gl.ClearDepth(p_value);
};
haxor.platform.graphics.GL.ClearColor = function(p_r,p_g,p_b,p_a) {
	haxor.platform.graphics.GL.m_gl.ClearColor(p_r,p_g,p_b,p_a);
};
haxor.platform.graphics.GL.GetError = function() {
	return haxor.platform.graphics.GL.m_gl.GetError();
};
haxor.platform.graphics.GL.GetErrorCode = function() {
	return haxor.platform.graphics.GL.m_gl.GetErrorCode();
};
haxor.platform.graphics.GL.GetErrorString = function(p_code) {
	return haxor.platform.graphics.GL.m_gl.GetErrorString(p_code);
};
haxor.platform.graphics.GL.LogError = function() {
	haxor.platform.graphics.GL.m_gl.LogError();
};
haxor.platform.graphics.GL.Assert = function(p_log) {
};
haxor.platform.graphics.GL.Flush = function() {
	haxor.platform.graphics.GL.m_gl.Flush();
};
haxor.platform.graphics.GL.Focus = function() {
	haxor.platform.graphics.GL.m_gl.Focus();
};
haxor.platform.graphics.GraphicAPI = { __ename__ : true, __constructs__ : ["None","OpenGL","OpenGLES","WebGL"] };
haxor.platform.graphics.GraphicAPI.None = ["None",0];
haxor.platform.graphics.GraphicAPI.None.__enum__ = haxor.platform.graphics.GraphicAPI;
haxor.platform.graphics.GraphicAPI.OpenGL = ["OpenGL",1];
haxor.platform.graphics.GraphicAPI.OpenGL.__enum__ = haxor.platform.graphics.GraphicAPI;
haxor.platform.graphics.GraphicAPI.OpenGLES = ["OpenGLES",2];
haxor.platform.graphics.GraphicAPI.OpenGLES.__enum__ = haxor.platform.graphics.GraphicAPI;
haxor.platform.graphics.GraphicAPI.WebGL = ["WebGL",3];
haxor.platform.graphics.GraphicAPI.WebGL.__enum__ = haxor.platform.graphics.GraphicAPI;
haxor.platform.graphics.GraphicContext = function(p_application) {
	this.m_api = haxor.platform.graphics.GraphicAPI.None;
	this.m_application = p_application;
};
$hxClasses["haxor.platform.graphics.GraphicContext"] = haxor.platform.graphics.GraphicContext;
haxor.platform.graphics.GraphicContext.__name__ = ["haxor","platform","graphics","GraphicContext"];
haxor.platform.graphics.GraphicContext.prototype = {
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
		return haxor.platform.graphics.GL.NULL;
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
		return haxor.platform.graphics.GL.NULL;
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
		return haxor.platform.graphics.GL.NULL;
	}
	,DeleteProgram: function(p_program) {
	}
	,GetAttribLocation: function(p_program,p_name) {
		return -1;
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
		haxor.core.Console.Log(this.GetError());
	}
	,__class__: haxor.platform.graphics.GraphicContext
};
haxor.platform.graphics.WebGL = function(p_application) {
	haxor.platform.graphics.GraphicContext.call(this,p_application);
	this.m_api = haxor.platform.graphics.GraphicAPI.WebGL;
};
$hxClasses["haxor.platform.graphics.WebGL"] = haxor.platform.graphics.WebGL;
haxor.platform.graphics.WebGL.__name__ = ["haxor","platform","graphics","WebGL"];
haxor.platform.graphics.WebGL.__super__ = haxor.platform.graphics.GraphicContext;
haxor.platform.graphics.WebGL.prototype = $extend(haxor.platform.graphics.GraphicContext.prototype,{
	Initialize: function(p_container_id) {
		var app = this.m_application;
		app.m_container = this.m_container = window.document.getElementById(p_container_id);
		if(this.m_container == null) {
			haxor.core.Console.Log("Graphics> Canvas container not defined id[" + p_container_id + "].");
			return false;
		}
		var _this = window.document;
		this.m_canvas = _this.createElement("canvas");
		this.m_canvas.width = this.m_container.clientWidth;
		this.m_canvas.height = this.m_container.clientHeight;
		this.m_container.appendChild(this.m_canvas);
		var ctx_attrib = { };
		var ctx_attrib_list = ["alpha","antialias","depth","stencil","premultipliedAlpha","preserveDrawingBuffer"];
		var ctx_attrib_default = [false,false,true,false,true,false];
		haxor.core.Console.Log("Graphics> Initialize WebGL",1);
		var _g1 = 0;
		var _g = ctx_attrib_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			var a = ctx_attrib_list[i];
			var ca = this.m_container.getAttribute(ctx_attrib_list[i]);
			var flag;
			if(ca == null) flag = ctx_attrib_default[i]; else flag = ca == "true";
			haxor.core.Console.Log("\t" + ctx_attrib_list[i] + ": " + (flag == null?"null":"" + flag),1);
			ctx_attrib[a]=flag;
		}
		var attribs = ctx_attrib;
		this.c = js.html._CanvasElement.CanvasUtil.getContextWebGL(this.m_canvas,attribs);
		if(this.c == null) {
			haxor.core.Console.Log("Graphics> Could not create RenderingContext3D.");
			return false;
		}
		return true;
	}
	,CheckExtensions: function() {
		if(this.c == null) return;
		haxor.core.Console.Log("Graphics> Available Extensions.",1);
		var extensions = this.c.getSupportedExtensions();
		var _g1 = 0;
		var _g = extensions.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(extensions[i].indexOf("MOZ_") >= 0) continue;
			var ext = this.c.getExtension(extensions[i]);
			haxor.core.Console.Log("\t" + extensions[i],1);
			var _g2 = extensions[i];
			switch(_g2) {
			case "OES_texture_half_float":
				break;
			case "OES_texture_half_float_linear":
				break;
			case "EXT_texture_filter_anisotropic":case "WEBKIT_EXT_texture_filter_anisotropic":
				break;
			case "OES_texture_float":
				break;
			case "WEBGL_depth_texture":
				break;
			}
		}
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
	,Clear: function(p_flag) {
		this.c.clear(p_flag);
	}
	,ClearDepth: function(p_value) {
		this.c.clearDepth(p_value);
	}
	,ClearColor: function(p_r,p_g,p_b,p_a) {
		this.c.clearColor(p_r,p_g,p_b,p_a);
	}
	,GetErrorCode: function() {
		return this.c.getError();
	}
	,__class__: haxor.platform.graphics.WebGL
});
haxor.platform.html.Entry = function() { };
$hxClasses["haxor.platform.html.Entry"] = haxor.platform.html.Entry;
haxor.platform.html.Entry.__name__ = ["haxor","platform","html","Entry"];
haxor.platform.html.Entry.Initialize = function() {
	haxor.core.Console.Initialize();
	window.onload = haxor.platform.html.Entry.OnWindowLoad;
};
haxor.platform.html.Entry.OnWindowLoad = function(p_event) {
	var script_list = window.document.getElementsByTagName("SCRIPT");
	var attrib = "";
	var app_class_type = "Main";
	var app_container_id = "haxor";
	var _g1 = 0;
	var _g = script_list.length;
	while(_g1 < _g) {
		var i = _g1++;
		var scr = script_list.item(i);
		attrib = scr.getAttribute("verbose");
		if(attrib != null) {
			if(attrib == "") attrib = "0"; else attrib = attrib;
			haxor.core.Console.verbose = Std.parseInt(attrib);
		}
		attrib = scr.getAttribute("application");
		if(attrib != null) app_class_type = attrib;
		attrib = scr.getAttribute("container");
		if(attrib != null) app_container_id = attrib;
	}
	haxor.core.Console.Log("Haxor> HTML Platform Init verbose[" + haxor.core.Console.verbose + "] application[" + app_class_type + "] container[" + app_container_id + "]",1);
	if(app_class_type == "") {
		haxor.core.Console.Log("Haxor> Error. You must define an Application class.");
		return;
	}
	var app_class = Type.resolveClass(app_class_type);
	if(app_class == null) {
		haxor.core.Console.Log("Haxor> Error. Class [" + app_class_type + "] not found! Try adding 'import " + app_class_type + "' in your Main file.");
		return;
	}
	haxor.core.Engine.Initialize();
	var e = new haxor.core.Entity("application");
	haxor.platform.html.Entry.m_application = e.AddComponent(app_class);
	if(!js.Boot.__instanceof(haxor.platform.html.Entry.m_application,haxor.core.BaseApplication)) {
		haxor.core.Console.Log("Haxor> Error. Class [" + app_class_type + "] does not extends Application!");
		return;
	}
	haxor.core.Console.Log("Haxor> Application [" + app_class_type + "] created successfully!",1);
	haxor.platform.graphics.GL.Initialize(haxor.platform.html.Entry.m_application);
	haxor.platform.graphics.GL.m_gl.Initialize(app_container_id);
	if(($_=window,$bind($_,$_.requestAnimationFrame)) != null) window.requestAnimationFrame(haxor.platform.html.Entry.RequestAnimationCallback);
	haxor.context.EngineContext.Build();
	if(haxor.platform.html.Entry.m_application.Load()) haxor.platform.html.Entry.m_application.LoadComplete();
};
haxor.platform.html.Entry.RequestAnimationCallback = function(p_time) {
	haxor.core.Time.m_clock = p_time;
	haxor.platform.html.Entry.m_application.Update();
	haxor.platform.html.Entry.m_application.Render();
	window.requestAnimationFrame(haxor.platform.html.Entry.RequestAnimationCallback);
	return true;
};
haxor.platform.html.Web = function() { };
$hxClasses["haxor.platform.html.Web"] = haxor.platform.html.Web;
haxor.platform.html.Web.__name__ = ["haxor","platform","html","Web"];
haxor.platform.html.Web.CreateRequest = function(p_url,p_binary) {
	if(p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url,"./",haxor.platform.html.Web.root);
	var req = new XMLHttpRequest();
	if(req.withCredentials) req.withCredentials = false;
	if($bind(req,req.overrideMimeType) != null) req.overrideMimeType(p_binary?"application/octet-stream":"text/plain");
	req.open("get",p_url,true);
	return req;
};
haxor.platform.html.Web.Load = function(p_url,p_callback) {
	var req = haxor.platform.html.Web.CreateRequest(p_url,false);
	req.onprogress = function(e) {
		var f;
		if(e.total <= 0) f = 0; else f = e.loaded / (e.total + 5);
		p_callback(null,f);
	};
	req.onload = function(e1) {
		p_callback(req.responseText,1.0);
	};
	req.onerror = function(e2) {
		p_callback(null,1.0);
	};
	req.send();
};
haxor.thread = {};
haxor.thread.Activity = function(p_callback,p_threaded) {
	if(p_threaded == null) p_threaded = false;
	haxor.core.Resource.call(this);
	if(p_callback == null) return;
	this.m_time_start = haxor.core.Time.m_elapsed;
	this.m_elapsed = 0.0;
	this.m_callback = p_callback;
	p_threaded = false;
	if(!p_threaded) haxor.context.EngineContext.update.Add(this); else {
	}
};
$hxClasses["haxor.thread.Activity"] = haxor.thread.Activity;
haxor.thread.Activity.__name__ = ["haxor","thread","Activity"];
haxor.thread.Activity.__interfaces__ = [haxor.core.IUpdateable];
haxor.thread.Activity.Iterate = function(p_offset,p_length,p_callback,p_step,p_threaded) {
	if(p_threaded == null) p_threaded = false;
	if(p_step == null) p_step = 1;
	var it = p_offset;
	return new haxor.thread.Activity(function(t) {
		var finished = false;
		var _g = 0;
		while(_g < p_step) {
			var i = _g++;
			if(!p_callback(it)) {
				finished = true;
				break;
			}
			it++;
			if(it >= p_length) return false;
		}
		return !finished;
	},p_threaded);
};
haxor.thread.Activity.Delay = function(p_time,p_callback,p_threaded) {
	if(p_threaded == null) p_threaded = false;
	return new haxor.thread.Activity(function(t) {
		if(t >= p_time) {
			p_callback();
			return false;
		}
		return true;
	},p_threaded);
};
haxor.thread.Activity.Run = function(p_callback,p_threaded) {
	if(p_threaded == null) p_threaded = false;
	return new haxor.thread.Activity(p_callback,p_threaded);
};
haxor.thread.Activity.__super__ = haxor.core.Resource;
haxor.thread.Activity.prototype = $extend(haxor.core.Resource.prototype,{
	get_elapsed: function() {
		return this.m_elapsed;
	}
	,OnUpdate: function() {
		this.m_elapsed = haxor.core.Time.m_elapsed - this.m_time_start;
		if(!this.m_callback(this.m_elapsed)) haxor.core.Resource.Destroy(this);
	}
	,__class__: haxor.thread.Activity
});
var js = {};
js.Boot = function() { };
$hxClasses["js.Boot"] = js.Boot;
js.Boot.__name__ = ["js","Boot"];
js.Boot.getClass = function(o) {
	if((o instanceof Array) && o.__enum__ == null) return Array; else return o.__class__;
};
js.Boot.__string_rec = function(o,s) {
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
					if(i != 2) str += "," + js.Boot.__string_rec(o[i],s); else str += js.Boot.__string_rec(o[i],s);
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
				str1 += (i2 > 0?",":"") + js.Boot.__string_rec(o[i2],s);
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
		str2 += s + k + " : " + js.Boot.__string_rec(o[k],s);
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
js.Boot.__interfLoop = function(cc,cl) {
	if(cc == null) return false;
	if(cc == cl) return true;
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0;
		var _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js.Boot.__interfLoop(i1,cl)) return true;
		}
	}
	return js.Boot.__interfLoop(cc.__super__,cl);
};
js.Boot.__instanceof = function(o,cl) {
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
				if(js.Boot.__interfLoop(js.Boot.getClass(o),cl)) return true;
			}
		} else return false;
		if(cl == Class && o.__name__ != null) return true;
		if(cl == Enum && o.__ename__ != null) return true;
		return o.__enum__ == cl;
	}
};
js.html = {};
js.html._CanvasElement = {};
js.html._CanvasElement.CanvasUtil = function() { };
$hxClasses["js.html._CanvasElement.CanvasUtil"] = js.html._CanvasElement.CanvasUtil;
js.html._CanvasElement.CanvasUtil.__name__ = ["js","html","_CanvasElement","CanvasUtil"];
js.html._CanvasElement.CanvasUtil.getContextWebGL = function(canvas,attribs) {
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
if(Array.prototype.indexOf) HxOverrides.indexOf = function(a,o,i) {
	return Array.prototype.indexOf.call(a,o,i);
};
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
haxe.xml.Parser.escapes = (function($this) {
	var $r;
	var h = new haxe.ds.StringMap();
	h.set("lt","<");
	h.set("gt",">");
	h.set("amp","&");
	h.set("quot","\"");
	h.set("apos","'");
	h.set("nbsp",String.fromCharCode(160));
	$r = h;
	return $r;
}(this));
haxor.context.EngineContext.uid = 0;
haxor.context.EngineContext.maxNodes = 1000;
haxor.context.EngineContext.collectRate = 10;
haxor.context.BaseProcess.m_cid = 0;
haxor.core.Console.m_console = console;
haxor.core.Console.m_style = "";
haxor.core.Console.verbose = 0;
haxor.graphics.RenderQueue.Background = 0;
haxor.graphics.RenderQueue.Opaque = 1000;
haxor.graphics.RenderQueue.Transparent = 2000;
haxor.graphics.RenderQueue.Overlay = 3000;
haxor.graphics.RenderQueue.Interface = 4000;
haxor.graphics.BlendMode.Zero = 0;
haxor.graphics.BlendMode.One = 1;
haxor.graphics.BlendMode.SrcColor = 768;
haxor.graphics.BlendMode.OneMinusSrcColor = 769;
haxor.graphics.BlendMode.SrcAlpha = 770;
haxor.graphics.BlendMode.OneMinusSrcAlpha = 771;
haxor.graphics.BlendMode.DstAlpha = 772;
haxor.graphics.BlendMode.OneMinusDstAlpha = 773;
haxor.graphics.BlendMode.DstColor = 774;
haxor.graphics.BlendMode.OneMinusDstColor = 775;
haxor.graphics.BlendMode.SrcAlphaSaturate = 776;
haxor.graphics.MeshMode.StaticDraw = 35044;
haxor.graphics.MeshMode.StreamDraw = 35040;
haxor.graphics.MeshMode.DynamicDraw = 35048;
haxor.graphics.MeshPrimitive.Points = 0;
haxor.graphics.MeshPrimitive.Triangles = 4;
haxor.graphics.MeshPrimitive.TriangleStrip = 5;
haxor.graphics.MeshPrimitive.TriangleFan = 6;
haxor.graphics.MeshPrimitive.Lines = 1;
haxor.graphics.MeshPrimitive.LineLoop = 2;
haxor.graphics.MeshPrimitive.LineStrip = 3;
haxor.graphics.CullMode.None = 0;
haxor.graphics.CullMode.Front = 1;
haxor.graphics.CullMode.Back = 2;
haxor.graphics.DepthTest.Never = 512;
haxor.graphics.DepthTest.Less = 513;
haxor.graphics.DepthTest.Equal = 514;
haxor.graphics.DepthTest.LessEqual = 515;
haxor.graphics.DepthTest.Greater = 516;
haxor.graphics.DepthTest.NotEqual = 517;
haxor.graphics.DepthTest.GreaterEqual = 518;
haxor.graphics.DepthTest.Always = 519;
haxor.graphics.BufferPrimitive.U8 = 0;
haxor.graphics.BufferPrimitive.U16 = 1;
haxor.graphics.BufferPrimitive.U32 = 2;
haxor.graphics.BufferPrimitive.I8 = 3;
haxor.graphics.BufferPrimitive.I16 = 4;
haxor.graphics.BufferPrimitive.I32 = 5;
haxor.graphics.BufferPrimitive.F32 = 6;
haxor.graphics.BufferPrimitive.F64 = 7;
haxor.platform.graphics.GL.ACTIVE_ATTRIBUTES = 35721;
haxor.platform.graphics.GL.ACTIVE_TEXTURE = 34016;
haxor.platform.graphics.GL.ACTIVE_UNIFORMS = 35718;
haxor.platform.graphics.GL.ALIASED_LINE_WIDTH_RANGE = 33902;
haxor.platform.graphics.GL.ALIASED_POINT_SIZE_RANGE = 33901;
haxor.platform.graphics.GL.ALPHA = 6406;
haxor.platform.graphics.GL.ALPHA_BITS = 3413;
haxor.platform.graphics.GL.ALWAYS = 519;
haxor.platform.graphics.GL.ARRAY_BUFFER = 34962;
haxor.platform.graphics.GL.ARRAY_BUFFER_BINDING = 34964;
haxor.platform.graphics.GL.ATTACHED_SHADERS = 35717;
haxor.platform.graphics.GL.BACK = 1029;
haxor.platform.graphics.GL.BLEND = 3042;
haxor.platform.graphics.GL.BLEND_COLOR = 32773;
haxor.platform.graphics.GL.BLEND_DST_ALPHA = 32970;
haxor.platform.graphics.GL.BLEND_DST_RGB = 32968;
haxor.platform.graphics.GL.BLEND_EQUATION = 32777;
haxor.platform.graphics.GL.BLEND_EQUATION_ALPHA = 34877;
haxor.platform.graphics.GL.BLEND_EQUATION_RGB = 32777;
haxor.platform.graphics.GL.BLEND_SRC_ALPHA = 32971;
haxor.platform.graphics.GL.BLEND_SRC_RGB = 32969;
haxor.platform.graphics.GL.BLUE_BITS = 3412;
haxor.platform.graphics.GL.BOOL = 35670;
haxor.platform.graphics.GL.BOOL_VEC2 = 35671;
haxor.platform.graphics.GL.BOOL_VEC3 = 35672;
haxor.platform.graphics.GL.BOOL_VEC4 = 35673;
haxor.platform.graphics.GL.BROWSER_DEFAULT_WEBGL = 37444;
haxor.platform.graphics.GL.BUFFER_SIZE = 34660;
haxor.platform.graphics.GL.BUFFER_USAGE = 34661;
haxor.platform.graphics.GL.BYTE = 5120;
haxor.platform.graphics.GL.CCW = 2305;
haxor.platform.graphics.GL.CLAMP_TO_EDGE = 33071;
haxor.platform.graphics.GL.COLOR_ATTACHMENT0 = 36064;
haxor.platform.graphics.GL.COLOR_BUFFER_BIT = 16384;
haxor.platform.graphics.GL.COLOR_CLEAR_VALUE = 3106;
haxor.platform.graphics.GL.COLOR_WRITEMASK = 3107;
haxor.platform.graphics.GL.COMPILE_STATUS = 35713;
haxor.platform.graphics.GL.COMPRESSED_TEXTURE_FORMATS = 34467;
haxor.platform.graphics.GL.CONSTANT_ALPHA = 32771;
haxor.platform.graphics.GL.CONSTANT_COLOR = 32769;
haxor.platform.graphics.GL.CONTEXT_LOST_WEBGL = 37442;
haxor.platform.graphics.GL.CULL_FACE = 2884;
haxor.platform.graphics.GL.CULL_FACE_MODE = 2885;
haxor.platform.graphics.GL.CURRENT_PROGRAM = 35725;
haxor.platform.graphics.GL.CURRENT_VERTEX_ATTRIB = 34342;
haxor.platform.graphics.GL.CW = 2304;
haxor.platform.graphics.GL.DECR = 7683;
haxor.platform.graphics.GL.DECR_WRAP = 34056;
haxor.platform.graphics.GL.DELETE_STATUS = 35712;
haxor.platform.graphics.GL.DEPTH_ATTACHMENT = 36096;
haxor.platform.graphics.GL.DEPTH_BITS = 3414;
haxor.platform.graphics.GL.DEPTH_BUFFER_BIT = 256;
haxor.platform.graphics.GL.DEPTH_CLEAR_VALUE = 2931;
haxor.platform.graphics.GL.DEPTH_COMPONENT = 6402;
haxor.platform.graphics.GL.DEPTH_COMPONENT16 = 33189;
haxor.platform.graphics.GL.DEPTH_FUNC = 2932;
haxor.platform.graphics.GL.DEPTH_RANGE = 2928;
haxor.platform.graphics.GL.DEPTH_STENCIL = 34041;
haxor.platform.graphics.GL.DEPTH_STENCIL_ATTACHMENT = 33306;
haxor.platform.graphics.GL.DEPTH_TEST = 2929;
haxor.platform.graphics.GL.DEPTH_WRITEMASK = 2930;
haxor.platform.graphics.GL.DITHER = 3024;
haxor.platform.graphics.GL.DONT_CARE = 4352;
haxor.platform.graphics.GL.DST_ALPHA = 772;
haxor.platform.graphics.GL.DST_COLOR = 774;
haxor.platform.graphics.GL.DYNAMIC_DRAW = 35048;
haxor.platform.graphics.GL.ELEMENT_ARRAY_BUFFER = 34963;
haxor.platform.graphics.GL.ELEMENT_ARRAY_BUFFER_BINDING = 34965;
haxor.platform.graphics.GL.EQUAL = 514;
haxor.platform.graphics.GL.FASTEST = 4353;
haxor.platform.graphics.GL.FLOAT = 5126;
haxor.platform.graphics.GL.FLOAT_MAT2 = 35674;
haxor.platform.graphics.GL.FLOAT_MAT3 = 35675;
haxor.platform.graphics.GL.FLOAT_MAT4 = 35676;
haxor.platform.graphics.GL.FLOAT_VEC2 = 35664;
haxor.platform.graphics.GL.FLOAT_VEC3 = 35665;
haxor.platform.graphics.GL.FLOAT_VEC4 = 35666;
haxor.platform.graphics.GL.FRAGMENT_SHADER = 35632;
haxor.platform.graphics.GL.FRAMEBUFFER = 36160;
haxor.platform.graphics.GL.FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 36049;
haxor.platform.graphics.GL.FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 36048;
haxor.platform.graphics.GL.FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 36051;
haxor.platform.graphics.GL.FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 36050;
haxor.platform.graphics.GL.FRAMEBUFFER_BINDING = 36006;
haxor.platform.graphics.GL.FRAMEBUFFER_COMPLETE = 36053;
haxor.platform.graphics.GL.FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 36054;
haxor.platform.graphics.GL.FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 36057;
haxor.platform.graphics.GL.FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 36055;
haxor.platform.graphics.GL.FRAMEBUFFER_UNSUPPORTED = 36061;
haxor.platform.graphics.GL.FRONT = 1028;
haxor.platform.graphics.GL.FRONT_AND_BACK = 1032;
haxor.platform.graphics.GL.FRONT_FACE = 2886;
haxor.platform.graphics.GL.FUNC_ADD = 32774;
haxor.platform.graphics.GL.FUNC_REVERSE_SUBTRACT = 32779;
haxor.platform.graphics.GL.FUNC_SUBTRACT = 32778;
haxor.platform.graphics.GL.GENERATE_MIPMAP_HINT = 33170;
haxor.platform.graphics.GL.GEQUAL = 518;
haxor.platform.graphics.GL.GREATER = 516;
haxor.platform.graphics.GL.GREEN_BITS = 3411;
haxor.platform.graphics.GL.HIGH_FLOAT = 36338;
haxor.platform.graphics.GL.HIGH_INT = 36341;
haxor.platform.graphics.GL.INCR = 7682;
haxor.platform.graphics.GL.INCR_WRAP = 34055;
haxor.platform.graphics.GL.INT = 5124;
haxor.platform.graphics.GL.INT_VEC2 = 35667;
haxor.platform.graphics.GL.INT_VEC3 = 35668;
haxor.platform.graphics.GL.INT_VEC4 = 35669;
haxor.platform.graphics.GL.INVALID_ENUM = 1280;
haxor.platform.graphics.GL.INVALID_FRAMEBUFFER_OPERATION = 1286;
haxor.platform.graphics.GL.INVALID_OPERATION = 1282;
haxor.platform.graphics.GL.INVALID_VALUE = 1281;
haxor.platform.graphics.GL.INVERT = 5386;
haxor.platform.graphics.GL.KEEP = 7680;
haxor.platform.graphics.GL.LEQUAL = 515;
haxor.platform.graphics.GL.LESS = 513;
haxor.platform.graphics.GL.LINEAR = 9729;
haxor.platform.graphics.GL.LINEAR_MIPMAP_LINEAR = 9987;
haxor.platform.graphics.GL.LINEAR_MIPMAP_NEAREST = 9985;
haxor.platform.graphics.GL.LINES = 1;
haxor.platform.graphics.GL.LINE_LOOP = 2;
haxor.platform.graphics.GL.LINE_STRIP = 3;
haxor.platform.graphics.GL.LINE_WIDTH = 2849;
haxor.platform.graphics.GL.LINK_STATUS = 35714;
haxor.platform.graphics.GL.LOW_FLOAT = 36336;
haxor.platform.graphics.GL.LOW_INT = 36339;
haxor.platform.graphics.GL.LUMINANCE = 6409;
haxor.platform.graphics.GL.LUMINANCE_ALPHA = 6410;
haxor.platform.graphics.GL.MAX_COMBINED_TEXTURE_IMAGE_UNITS = 35661;
haxor.platform.graphics.GL.MAX_CUBE_MAP_TEXTURE_SIZE = 34076;
haxor.platform.graphics.GL.MAX_FRAGMENT_UNIFORM_VECTORS = 36349;
haxor.platform.graphics.GL.MAX_RENDERBUFFER_SIZE = 34024;
haxor.platform.graphics.GL.MAX_TEXTURE_IMAGE_UNITS = 34930;
haxor.platform.graphics.GL.MAX_TEXTURE_SIZE = 3379;
haxor.platform.graphics.GL.MAX_VARYING_VECTORS = 36348;
haxor.platform.graphics.GL.MAX_VERTEX_ATTRIBS = 34921;
haxor.platform.graphics.GL.MAX_VERTEX_TEXTURE_IMAGE_UNITS = 35660;
haxor.platform.graphics.GL.MAX_VERTEX_UNIFORM_VECTORS = 36347;
haxor.platform.graphics.GL.MAX_VIEWPORT_DIMS = 3386;
haxor.platform.graphics.GL.MEDIUM_FLOAT = 36337;
haxor.platform.graphics.GL.MEDIUM_INT = 36340;
haxor.platform.graphics.GL.MIRRORED_REPEAT = 33648;
haxor.platform.graphics.GL.NEAREST = 9728;
haxor.platform.graphics.GL.NEAREST_MIPMAP_LINEAR = 9986;
haxor.platform.graphics.GL.NEAREST_MIPMAP_NEAREST = 9984;
haxor.platform.graphics.GL.NEVER = 512;
haxor.platform.graphics.GL.NICEST = 4354;
haxor.platform.graphics.GL.NONE = 0;
haxor.platform.graphics.GL.NOTEQUAL = 517;
haxor.platform.graphics.GL.NO_ERROR_GL = 0;
haxor.platform.graphics.GL.ONE = 1;
haxor.platform.graphics.GL.ONE_MINUS_CONSTANT_ALPHA = 32772;
haxor.platform.graphics.GL.ONE_MINUS_CONSTANT_COLOR = 32770;
haxor.platform.graphics.GL.ONE_MINUS_DST_ALPHA = 773;
haxor.platform.graphics.GL.ONE_MINUS_DST_COLOR = 775;
haxor.platform.graphics.GL.ONE_MINUS_SRC_ALPHA = 771;
haxor.platform.graphics.GL.ONE_MINUS_SRC_COLOR = 769;
haxor.platform.graphics.GL.OUT_OF_MEMORY = 1285;
haxor.platform.graphics.GL.PACK_ALIGNMENT = 3333;
haxor.platform.graphics.GL.POINTS = 0;
haxor.platform.graphics.GL.POLYGON_OFFSET_FACTOR = 32824;
haxor.platform.graphics.GL.POLYGON_OFFSET_FILL = 32823;
haxor.platform.graphics.GL.POLYGON_OFFSET_UNITS = 10752;
haxor.platform.graphics.GL.RED_BITS = 3410;
haxor.platform.graphics.GL.RENDERBUFFER = 36161;
haxor.platform.graphics.GL.RENDERBUFFER_ALPHA_SIZE = 36179;
haxor.platform.graphics.GL.RENDERBUFFER_BINDING = 36007;
haxor.platform.graphics.GL.RENDERBUFFER_BLUE_SIZE = 36178;
haxor.platform.graphics.GL.RENDERBUFFER_DEPTH_SIZE = 36180;
haxor.platform.graphics.GL.RENDERBUFFER_GREEN_SIZE = 36177;
haxor.platform.graphics.GL.RENDERBUFFER_HEIGHT = 36163;
haxor.platform.graphics.GL.RENDERBUFFER_INTERNAL_FORMAT = 36164;
haxor.platform.graphics.GL.RENDERBUFFER_RED_SIZE = 36176;
haxor.platform.graphics.GL.RENDERBUFFER_STENCIL_SIZE = 36181;
haxor.platform.graphics.GL.RENDERBUFFER_WIDTH = 36162;
haxor.platform.graphics.GL.RENDERER = 7937;
haxor.platform.graphics.GL.REPEAT = 10497;
haxor.platform.graphics.GL.REPLACE = 7681;
haxor.platform.graphics.GL.RGB = 6407;
haxor.platform.graphics.GL.RGB565 = 36194;
haxor.platform.graphics.GL.RGB5_A1 = 32855;
haxor.platform.graphics.GL.RGBA = 6408;
haxor.platform.graphics.GL.RGBA4 = 32854;
haxor.platform.graphics.GL.SAMPLER_2D = 35678;
haxor.platform.graphics.GL.SAMPLER_CUBE = 35680;
haxor.platform.graphics.GL.SAMPLES = 32937;
haxor.platform.graphics.GL.SAMPLE_ALPHA_TO_COVERAGE = 32926;
haxor.platform.graphics.GL.SAMPLE_BUFFERS = 32936;
haxor.platform.graphics.GL.SAMPLE_COVERAGE = 32928;
haxor.platform.graphics.GL.SAMPLE_COVERAGE_INVERT = 32939;
haxor.platform.graphics.GL.SAMPLE_COVERAGE_VALUE = 32938;
haxor.platform.graphics.GL.SCISSOR_BOX = 3088;
haxor.platform.graphics.GL.SCISSOR_TEST = 3089;
haxor.platform.graphics.GL.SHADER_TYPE = 35663;
haxor.platform.graphics.GL.SHADING_LANGUAGE_VERSION = 35724;
haxor.platform.graphics.GL.SHORT = 5122;
haxor.platform.graphics.GL.SRC_ALPHA = 770;
haxor.platform.graphics.GL.SRC_ALPHA_SATURATE = 776;
haxor.platform.graphics.GL.SRC_COLOR = 768;
haxor.platform.graphics.GL.STATIC_DRAW = 35044;
haxor.platform.graphics.GL.STENCIL_ATTACHMENT = 36128;
haxor.platform.graphics.GL.STENCIL_BACK_FAIL = 34817;
haxor.platform.graphics.GL.STENCIL_BACK_FUNC = 34816;
haxor.platform.graphics.GL.STENCIL_BACK_PASS_DEPTH_FAIL = 34818;
haxor.platform.graphics.GL.STENCIL_BACK_PASS_DEPTH_PASS = 34819;
haxor.platform.graphics.GL.STENCIL_BACK_REF = 36003;
haxor.platform.graphics.GL.STENCIL_BACK_VALUE_MASK = 36004;
haxor.platform.graphics.GL.STENCIL_BACK_WRITEMASK = 36005;
haxor.platform.graphics.GL.STENCIL_BITS = 3415;
haxor.platform.graphics.GL.STENCIL_BUFFER_BIT = 1024;
haxor.platform.graphics.GL.STENCIL_CLEAR_VALUE = 2961;
haxor.platform.graphics.GL.STENCIL_FAIL = 2964;
haxor.platform.graphics.GL.STENCIL_FUNC = 2962;
haxor.platform.graphics.GL.STENCIL_INDEX = 6401;
haxor.platform.graphics.GL.STENCIL_INDEX8 = 36168;
haxor.platform.graphics.GL.STENCIL_PASS_DEPTH_FAIL = 2965;
haxor.platform.graphics.GL.STENCIL_PASS_DEPTH_PASS = 2966;
haxor.platform.graphics.GL.STENCIL_REF = 2967;
haxor.platform.graphics.GL.STENCIL_TEST = 2960;
haxor.platform.graphics.GL.STENCIL_VALUE_MASK = 2963;
haxor.platform.graphics.GL.STENCIL_WRITEMASK = 2968;
haxor.platform.graphics.GL.STREAM_DRAW = 35040;
haxor.platform.graphics.GL.SUBPIXEL_BITS = 3408;
haxor.platform.graphics.GL.TEXTURE = 5890;
haxor.platform.graphics.GL.TEXTURE0 = 33984;
haxor.platform.graphics.GL.TEXTURE1 = 33985;
haxor.platform.graphics.GL.TEXTURE10 = 33994;
haxor.platform.graphics.GL.TEXTURE11 = 33995;
haxor.platform.graphics.GL.TEXTURE12 = 33996;
haxor.platform.graphics.GL.TEXTURE13 = 33997;
haxor.platform.graphics.GL.TEXTURE14 = 33998;
haxor.platform.graphics.GL.TEXTURE15 = 33999;
haxor.platform.graphics.GL.TEXTURE16 = 34000;
haxor.platform.graphics.GL.TEXTURE17 = 34001;
haxor.platform.graphics.GL.TEXTURE18 = 34002;
haxor.platform.graphics.GL.TEXTURE19 = 34003;
haxor.platform.graphics.GL.TEXTURE2 = 33986;
haxor.platform.graphics.GL.TEXTURE20 = 34004;
haxor.platform.graphics.GL.TEXTURE21 = 34005;
haxor.platform.graphics.GL.TEXTURE22 = 34006;
haxor.platform.graphics.GL.TEXTURE23 = 34007;
haxor.platform.graphics.GL.TEXTURE24 = 34008;
haxor.platform.graphics.GL.TEXTURE25 = 34009;
haxor.platform.graphics.GL.TEXTURE26 = 34010;
haxor.platform.graphics.GL.TEXTURE27 = 34011;
haxor.platform.graphics.GL.TEXTURE28 = 34012;
haxor.platform.graphics.GL.TEXTURE29 = 34013;
haxor.platform.graphics.GL.TEXTURE3 = 33987;
haxor.platform.graphics.GL.TEXTURE30 = 34014;
haxor.platform.graphics.GL.TEXTURE31 = 34015;
haxor.platform.graphics.GL.TEXTURE4 = 33988;
haxor.platform.graphics.GL.TEXTURE5 = 33989;
haxor.platform.graphics.GL.TEXTURE6 = 33990;
haxor.platform.graphics.GL.TEXTURE7 = 33991;
haxor.platform.graphics.GL.TEXTURE8 = 33992;
haxor.platform.graphics.GL.TEXTURE9 = 33993;
haxor.platform.graphics.GL.TEXTURE_2D = 3553;
haxor.platform.graphics.GL.TEXTURE_BINDING_2D = 32873;
haxor.platform.graphics.GL.TEXTURE_BINDING_CUBE_MAP = 34068;
haxor.platform.graphics.GL.TEXTURE_CUBE_MAP = 34067;
haxor.platform.graphics.GL.TEXTURE_CUBE_MAP_NEGATIVE_X = 34070;
haxor.platform.graphics.GL.TEXTURE_CUBE_MAP_NEGATIVE_Y = 34072;
haxor.platform.graphics.GL.TEXTURE_CUBE_MAP_NEGATIVE_Z = 34074;
haxor.platform.graphics.GL.TEXTURE_CUBE_MAP_POSITIVE_X = 34069;
haxor.platform.graphics.GL.TEXTURE_CUBE_MAP_POSITIVE_Y = 34071;
haxor.platform.graphics.GL.TEXTURE_CUBE_MAP_POSITIVE_Z = 34073;
haxor.platform.graphics.GL.TEXTURE_MAG_FILTER = 10240;
haxor.platform.graphics.GL.TEXTURE_MIN_FILTER = 10241;
haxor.platform.graphics.GL.TEXTURE_WRAP_S = 10242;
haxor.platform.graphics.GL.TEXTURE_WRAP_T = 10243;
haxor.platform.graphics.GL.TRIANGLES = 4;
haxor.platform.graphics.GL.TRIANGLE_FAN = 6;
haxor.platform.graphics.GL.TRIANGLE_STRIP = 5;
haxor.platform.graphics.GL.UNPACK_ALIGNMENT = 3317;
haxor.platform.graphics.GL.UNPACK_COLORSPACE_CONVERSION_WEBGL = 37443;
haxor.platform.graphics.GL.UNPACK_FLIP_Y_WEBGL = 37440;
haxor.platform.graphics.GL.UNPACK_PREMULTIPLY_ALPHA_WEBGL = 37441;
haxor.platform.graphics.GL.UNSIGNED_BYTE = 5121;
haxor.platform.graphics.GL.UNSIGNED_INT = 5125;
haxor.platform.graphics.GL.UNSIGNED_SHORT = 5123;
haxor.platform.graphics.GL.UNSIGNED_SHORT_4_4_4_4 = 32819;
haxor.platform.graphics.GL.UNSIGNED_SHORT_5_5_5_1 = 32820;
haxor.platform.graphics.GL.UNSIGNED_SHORT_5_6_5 = 33635;
haxor.platform.graphics.GL.VALIDATE_STATUS = 35715;
haxor.platform.graphics.GL.VENDOR = 7936;
haxor.platform.graphics.GL.VERSION = 7938;
haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 34975;
haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_ENABLED = 34338;
haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_NORMALIZED = 34922;
haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_POINTER = 34373;
haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_SIZE = 34339;
haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_STRIDE = 34340;
haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_TYPE = 34341;
haxor.platform.graphics.GL.VERTEX_SHADER = 35633;
haxor.platform.graphics.GL.VIEWPORT = 2978;
haxor.platform.graphics.GL.ZERO = 0;
haxor.platform.html.Web.root = "";
Main.main();
})();
