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
HxOverrides.iter = function(a) {
	return { cur : 0, arr : a, hasNext : function() {
		return this.cur < this.arr.length;
	}, next : function() {
		return this.arr[this.cur++];
	}};
};
var haxor = {};
haxor.core = {};
haxor.core.IDisposable = function() { };
$hxClasses["haxor.core.IDisposable"] = haxor.core.IDisposable;
haxor.core.IDisposable.__name__ = ["haxor","core","IDisposable"];
haxor.core.IDisposable.prototype = {
	__class__: haxor.core.IDisposable
};
var IMap = function() { };
$hxClasses["IMap"] = IMap;
IMap.__name__ = ["IMap"];
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
	,__class__: haxe.ds.StringMap
};
haxor.core.Resource = function(p_name) {
	if(p_name == null) p_name = "";
	this.m_uid = haxor.context.EngineContext.uid++;
	this.m_destroyed = false;
	this.__cid = 0;
	this.__db = "";
	this.m_pid = [-1,-1,-1,-1,-1,-1,-1,-1,-1];
	this.m_name = p_name;
	this.m_is_behaviour = js.Boot.__instanceof(this,haxor.component.Behaviour);
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
	haxor.context.EngineContext.resources.Add(this);
};
$hxClasses["haxor.core.Resource"] = haxor.core.Resource;
haxor.core.Resource.__name__ = ["haxor","core","Resource"];
haxor.core.Resource.__interfaces__ = [haxor.core.IDisposable];
haxor.core.Resource.Get = function(p_id) {
	if(haxor.core.Resource.m_database.exists(p_id)) return haxor.core.Resource.m_database.get(p_id); else return null;
};
haxor.core.Resource.Remove = function(p_id) {
	if(haxor.core.Resource.m_database.exists(p_id)) {
		var a = haxor.core.Resource.m_database.get(p_id);
		haxor.core.Resource.m_database.remove(p_id);
		return a;
	}
	return null;
};
haxor.core.Resource.Add = function(p_id,p_asset) {
	var value = p_asset;
	haxor.core.Resource.m_database.set(p_id,value);
	if(js.Boot.__instanceof(p_asset,haxor.core.Resource)) (js.Boot.__cast(p_asset , haxor.core.Resource)).__db = p_id;
};
haxor.core.Resource.Destroy = function(p_target) {
	if(p_target.__db != "") haxor.core.Resource.Remove(p_target.__db);
	haxor.context.EngineContext.Destroy(p_target);
};
haxor.core.Resource.prototype = {
	get_application: function() {
		return haxor.core.BaseApplication.m_instance;
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
	,__class__: haxor.core.Resource
};
haxor.component = {};
haxor.component.Component = function() {
	haxor.core.Resource.call(this,"");
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
	,get_transform: function() {
		return this.m_entity.m_transform;
	}
	,OnBuild: function() {
	}
	,OnTransformUpdate: function() {
	}
	,__class__: haxor.component.Component
});
haxor.component.Behaviour = function() {
	haxor.component.Component.call(this);
	this.m_enabled = true;
	this.m_is_behaviour = true;
	haxor.context.EngineContext.Enable(this);
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
		if(this.m_enabled == v) return v;
		this.m_enabled = v;
		if(v) haxor.context.EngineContext.Enable(this); else haxor.context.EngineContext.Disable(this);
		return v;
	}
	,OnAwake: function() {
	}
	,OnStart: function() {
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
	haxor.graphics.Screen.Initialize(this);
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
		f *= 1.25;
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
			haxor.graphics.GL.m_gl.Focus();
			haxor.core.Engine.Render();
			haxor.graphics.GL.m_gl.Flush();
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
		haxor.graphics.GL.m_gl.Resize();
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
		haxor.net.Web.root = "http://haxor.thelaborat.org/resources/";
		return true;
	}
	,Initialize: function() {
		haxor.core.Console.Log("Initialize!");
		this.cam = this.m_entity.AddComponent(haxor.component.Camera);
		this.cam.background = new haxor.math.Color(0.3,0.3,0.3);
		this.mat = haxor.graphics.material.Material.Transparent(null,null,null,null);
	}
	,OnUpdate: function() {
	}
	,OnRender: function() {
		haxor.graphics.Graphics.Clear(this.cam);
		if(this.mat == null) return;
		this.mat.SetFloat("Time",haxor.core.Time.m_elapsed);
		haxor.graphics.Graphics.RenderMesh(haxor.graphics.mesh.Model.get_cube(),this.mat);
	}
	,__class__: Main
});
Math.__name__ = ["Math"];
var Std = function() { };
$hxClasses["Std"] = Std;
Std.__name__ = ["Std"];
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
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
};
haxe.io = {};
haxe.io.Bytes = function(length,b) {
	this.length = length;
	this.b = b;
};
$hxClasses["haxe.io.Bytes"] = haxe.io.Bytes;
haxe.io.Bytes.__name__ = ["haxe","io","Bytes"];
haxe.io.Bytes.alloc = function(length) {
	var a = new Array();
	var _g = 0;
	while(_g < length) {
		var i = _g++;
		a.push(0);
	}
	return new haxe.io.Bytes(length,a);
};
haxe.io.Bytes.ofString = function(s) {
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
	return new haxe.io.Bytes(a.length,a);
};
haxe.io.Bytes.prototype = {
	get: function(pos) {
		return this.b[pos];
	}
	,set: function(pos,v) {
		this.b[pos] = v & 255;
	}
	,getString: function(pos,len) {
		if(pos < 0 || len < 0 || pos + len > this.length) throw haxe.io.Error.OutsideBounds;
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
	,__class__: haxe.io.Bytes
};
haxe.crypto = {};
haxe.crypto.Base64 = function() { };
$hxClasses["haxe.crypto.Base64"] = haxe.crypto.Base64;
haxe.crypto.Base64.__name__ = ["haxe","crypto","Base64"];
haxe.crypto.Base64.encode = function(bytes,complement) {
	if(complement == null) complement = true;
	var str = new haxe.crypto.BaseCode(haxe.crypto.Base64.BYTES).encodeBytes(bytes).toString();
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
haxe.crypto.Base64.decode = function(str,complement) {
	if(complement == null) complement = true;
	if(complement) while(HxOverrides.cca(str,str.length - 1) == 61) str = HxOverrides.substr(str,0,-1);
	return new haxe.crypto.BaseCode(haxe.crypto.Base64.BYTES).decodeBytes(haxe.io.Bytes.ofString(str));
};
haxe.crypto.BaseCode = function(base) {
	var len = base.length;
	var nbits = 1;
	while(len > 1 << nbits) nbits++;
	if(nbits > 8 || len != 1 << nbits) throw "BaseCode : base length must be a power of two.";
	this.base = base;
	this.nbits = nbits;
};
$hxClasses["haxe.crypto.BaseCode"] = haxe.crypto.BaseCode;
haxe.crypto.BaseCode.__name__ = ["haxe","crypto","BaseCode"];
haxe.crypto.BaseCode.prototype = {
	encodeBytes: function(b) {
		var nbits = this.nbits;
		var base = this.base;
		var size = b.length * 8 / nbits | 0;
		var out = haxe.io.Bytes.alloc(size + (b.length * 8 % nbits == 0?0:1));
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
		var out = haxe.io.Bytes.alloc(size);
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
	,__class__: haxe.crypto.BaseCode
};
haxe.ds.ObjectMap = function() {
	this.h = { };
	this.h.__keys__ = { };
};
$hxClasses["haxe.ds.ObjectMap"] = haxe.ds.ObjectMap;
haxe.ds.ObjectMap.__name__ = ["haxe","ds","ObjectMap"];
haxe.ds.ObjectMap.__interfaces__ = [IMap];
haxe.ds.ObjectMap.prototype = {
	set: function(key,value) {
		var id = key.__id__ || (key.__id__ = ++haxe.ds.ObjectMap.count);
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
	,__class__: haxe.ds.ObjectMap
};
haxe.io.Eof = function() { };
$hxClasses["haxe.io.Eof"] = haxe.io.Eof;
haxe.io.Eof.__name__ = ["haxe","io","Eof"];
haxe.io.Eof.prototype = {
	toString: function() {
		return "Eof";
	}
	,__class__: haxe.io.Eof
};
haxe.io.Error = { __ename__ : true, __constructs__ : ["Blocked","Overflow","OutsideBounds","Custom"] };
haxe.io.Error.Blocked = ["Blocked",0];
haxe.io.Error.Blocked.__enum__ = haxe.io.Error;
haxe.io.Error.Overflow = ["Overflow",1];
haxe.io.Error.Overflow.__enum__ = haxe.io.Error;
haxe.io.Error.OutsideBounds = ["OutsideBounds",2];
haxe.io.Error.OutsideBounds.__enum__ = haxe.io.Error;
haxe.io.Error.Custom = function(e) { var $x = ["Custom",3,e]; $x.__enum__ = haxe.io.Error; return $x; };
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
haxor.component.Camera = function() {
	haxor.component.Behaviour.call(this);
};
$hxClasses["haxor.component.Camera"] = haxor.component.Camera;
haxor.component.Camera.__name__ = ["haxor","component","Camera"];
haxor.component.Camera.get_list = function() {
	return haxor.context.EngineContext.camera.list.slice();
};
haxor.component.Camera.get_current = function() {
	return haxor.component.Camera.m_current;
};
haxor.component.Camera.get_main = function() {
	return haxor.component.Camera.m_main;
};
haxor.component.Camera.set_main = function(v) {
	return haxor.component.Camera.m_main = v;
};
haxor.component.Camera.__super__ = haxor.component.Behaviour;
haxor.component.Camera.prototype = $extend(haxor.component.Behaviour.prototype,{
	get_fov: function() {
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
		return v;
	}
	,get_far: function() {
		return this.m_far;
	}
	,set_far: function(v) {
		this.m_far = v;
		this.m_projection_dirty = true;
		return v;
	}
	,get_order: function() {
		return this.m_order;
	}
	,set_order: function(v) {
		this.m_order = v;
		haxor.context.EngineContext.camera.SortCameraList();
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
		haxor.context.EngineContext.camera.UpdateViewport(this);
		return v;
	}
	,get_CameraToWorld: function() {
		return this.m_cameraToWorld.get_clone();
	}
	,get_WorldToCamera: function() {
		return this.m_worldToCamera;
	}
	,get_ProjectionMatrix: function() {
		this.UpdateProjection();
		return this.m_projectionMatrix.get_clone();
	}
	,get_ProjectionMatrixInverse: function() {
		this.UpdateProjection();
		return this.m_projectionMatrixInverse.get_clone();
	}
	,get_target: function() {
		return this.m_target;
	}
	,set_target: function(v) {
		this.m_target = v;
		haxor.context.EngineContext.camera.UpdateViewport(this);
		return v;
	}
	,get_quality: function() {
		return this.m_quality;
	}
	,set_quality: function(v) {
		if(v <= 0.0) this.m_quality = 0.0; else if(v >= 1.0) this.m_quality = 1.0; else this.m_quality = v;
		haxor.context.EngineContext.camera.UpdateViewport(this);
		return v;
	}
	,get_captureDepth: function() {
		return this.m_captureDepth;
	}
	,set_captureDepth: function(v) {
		this.m_captureDepth = v;
		haxor.context.EngineContext.camera.ClearTargets(this);
		haxor.context.EngineContext.camera.UpdateViewport(this);
		return v;
	}
	,get_filters: function() {
		return this.m_filters;
	}
	,set_filters: function(v) {
		if(v == null) this.m_filters = []; else this.m_filters = v;
		return this.m_filters;
	}
	,OnBuild: function() {
		haxor.component.Behaviour.prototype.OnBuild.call(this);
		this.__cid = haxor.context.EngineContext.camera.cid++;
		if(haxor.component.Camera.m_main == null) haxor.component.Camera.m_main = this;
		this.m_order = 0;
		this.m_quality = 1.0;
		this.m_pixelViewport = haxor.math.AABB2.get_empty();
		this.m_viewport = haxor.math.AABB2.get_empty();
		this.m_worldToCamera = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_cameraToWorld = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_projectionMatrix = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_projectionMatrixInverse = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_skyboxProjection = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_skyboxProjectionInverse = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		this.m_fov = 60;
		this.m_near = 0.1;
		this.m_far = 500;
		this.m_filters = [];
		this.background = new haxor.math.Color(0,0,0,1);
		this.clear = haxor.graphics.ClearFlag.ColorDepth;
		this.mask = 1;
		this.set_viewport(new haxor.math.AABB2(0,0,1,1));
		this.m_projection_dirty = true;
		haxor.context.EngineContext.camera.Create(this);
	}
	,WorldToProjection: function(p_world_point) {
		var p = haxor.context.EngineContext.data.get_v4();
		p.w = 1.0;
		p.x = p_world_point.x;
		p.y = p_world_point.y;
		p.z = p_world_point.z;
		this.m_worldToCamera.Transform4x4(p);
		this.m_projectionMatrix.Transform4x4(p);
		return p;
	}
	,WorldToDepth: function(p_world_point) {
		var wm = this.m_worldToCamera;
		return wm.m20 * p_world_point.x + wm.m21 * p_world_point.y + wm.m22 * p_world_point.z + wm.m23;
	}
	,IsCulled: function(p_world_point) {
		return this.WorldToProjection(p_world_point).IsCulled();
	}
	,LookAt: function(p_at,p_up,p_smooth) {
		if(p_smooth == null) p_smooth = 0.0;
		var p = this.m_entity.m_transform.get_position();
		var r = haxor.context.EngineContext.data.get_q();
		var q = haxor.math.Quaternion.LookAt(p,p_at,p_up,haxor.context.EngineContext.data.get_q());
		if(p_smooth > 0) r = haxor.math.Quaternion.Lerp(r,q,p_smooth * haxor.core.Time.m_delta,haxor.context.EngineContext.data.get_q()); else r = q;
		this.m_entity.m_transform.set_rotation(r);
	}
	,UpdateProjection: function() {
		if(!this.m_projection_dirty) return;
		this.m_projection_dirty = false;
		haxor.math.Matrix4.Perspective(this.m_fov,this.m_aspect,this.m_near,this.m_far,this.m_projectionMatrix);
		haxor.math.Matrix4.PerspectiveInverse(this.m_fov,this.m_aspect,this.m_near,this.m_far,this.m_projectionMatrixInverse);
		haxor.math.Matrix4.Perspective(this.m_fov,this.m_aspect,0.1,100000.0,this.m_skyboxProjection);
		haxor.math.Matrix4.PerspectiveInverse(this.m_fov,this.m_aspect,0.1,100000.0,this.m_skyboxProjectionInverse);
	}
	,OnTransformUpdate: function() {
		this.m_cameraToWorld.SetMatrix4(this.m_entity.m_transform.get_WorldMatrix());
		this.m_worldToCamera.SetMatrix4(this.m_entity.m_transform.get_WorldMatrixInverse());
	}
	,OnDestroy: function() {
		haxor.context.EngineContext.camera.Destroy(this);
	}
	,__class__: haxor.component.Camera
});
haxor.component.DataComponent = function() {
	haxor.component.Component.call(this);
	this.data = new haxe.ds.StringMap();
};
$hxClasses["haxor.component.DataComponent"] = haxor.component.DataComponent;
haxor.component.DataComponent.__name__ = ["haxor","component","DataComponent"];
haxor.component.DataComponent.__super__ = haxor.component.Component;
haxor.component.DataComponent.prototype = $extend(haxor.component.Component.prototype,{
	__class__: haxor.component.DataComponent
});
haxor.math = {};
haxor.math.Color = function(p_r,p_g,p_b,p_a) {
	if(p_a == null) p_a = 1;
	if(p_b == null) p_b = 0;
	if(p_g == null) p_g = 0;
	if(p_r == null) p_r = 0;
	this.r = p_r;
	this.g = p_g;
	this.b = p_b;
	this.a = p_a;
};
$hxClasses["haxor.math.Color"] = haxor.math.Color;
haxor.math.Color.__name__ = ["haxor","math","Color"];
haxor.math.Color.get_temp = function() {
	return haxor.context.EngineContext.data.get_c();
};
haxor.math.Color.get_red = function() {
	return new haxor.math.Color(1.0,0,0,1);
};
haxor.math.Color.get_yellow = function() {
	return new haxor.math.Color(1,1,0,1);
};
haxor.math.Color.get_green = function() {
	return new haxor.math.Color(0,1,0,1);
};
haxor.math.Color.get_cyan = function() {
	return new haxor.math.Color(0,1,1,1);
};
haxor.math.Color.get_blue = function() {
	return new haxor.math.Color(0,0,1,1);
};
haxor.math.Color.get_magenta = function() {
	return new haxor.math.Color(1,0,1,1);
};
haxor.math.Color.get_black = function() {
	return new haxor.math.Color(0,0,0,1);
};
haxor.math.Color.get_white = function() {
	return new haxor.math.Color(1,1,1,1);
};
haxor.math.Color.get_empty = function() {
	return new haxor.math.Color(0,0,0,0);
};
haxor.math.Color.get_gray10 = function() {
	return new haxor.math.Color(0.1,0.1,0.1,1);
};
haxor.math.Color.get_gray25 = function() {
	return new haxor.math.Color(0.25,0.25,0.25,1);
};
haxor.math.Color.get_gray50 = function() {
	return new haxor.math.Color(0.5,0.5,0.5,1);
};
haxor.math.Color.get_gray75 = function() {
	return new haxor.math.Color(0.75,0.75,0.75,1);
};
haxor.math.Color.get_gray90 = function() {
	return new haxor.math.Color(0.9,0.9,0.9,1);
};
haxor.math.Color.FromHex = function(p_hex) {
	var c = new haxor.math.Color();
	if(p_hex.length == 10) c.set_argb(Std.parseInt(p_hex)); else c.set_rgb(Std.parseInt(p_hex));
	return c;
};
haxor.math.Color.FromBytes = function(p_r,p_g,p_b,p_a) {
	if(p_a == null) p_a = 255.0;
	if(p_b == null) p_b = 0;
	if(p_g == null) p_g = 0;
	if(p_r == null) p_r = 0;
	return new haxor.math.Color(p_r * 0.00392156863,p_g * 0.00392156863,p_b * 0.00392156863,p_a * 0.00392156863);
};
haxor.math.Color.Lerp = function(a,b,r) {
	return new haxor.math.Color(haxor.math.Mathf.Lerp(a.r,b.r,r),haxor.math.Mathf.Lerp(a.g,b.g,r),haxor.math.Mathf.Lerp(a.b,b.b,r),haxor.math.Mathf.Lerp(a.a,b.a,r));
};
haxor.math.Color.Sample = function(g,r) {
	var pos = g.length - 1;
	pos *= r * 0.9999;
	var i0 = pos | 0;
	var i1 = (i0 + 1) % g.length;
	r = pos - Math.floor(pos);
	var c0 = g[i0];
	var c1 = g[i1];
	return haxor.math.Color.Lerp(c0,c1,r);
};
haxor.math.Color.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	return new haxor.math.Color(0,0,0,1).Set(Std.parseFloat(StringTools.trim(tk[0])),Std.parseFloat(StringTools.trim(tk[1])),Std.parseFloat(StringTools.trim(tk[2])),Std.parseFloat(StringTools.trim(tk[3])));
};
haxor.math.Color.prototype = {
	get_clone: function() {
		return new haxor.math.Color(this.r,this.g,this.b,this.a);
	}
	,get_xyz: function() {
		return new haxor.math.Vector3(this.r,this.g,this.b);
	}
	,get_xyzw: function() {
		return new haxor.math.Vector4(this.r,this.g,this.b,this.a);
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
		this.g = (v >> 16 & 255) * 0.00392156863;
		this.b = (v >> 8 & 255) * 0.00392156863;
		this.r = (v & 255) * 0.00392156863;
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
		return new haxor.math.Color(1.0 - this.r,1.0 - this.g,1.0 - this.b,1.0 - this.a);
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
		return "[" + haxor.math.Mathf.RoundPlaces(this.r,p_places) + "," + haxor.math.Mathf.RoundPlaces(this.g,p_places) + "," + haxor.math.Mathf.RoundPlaces(this.b,p_places) + "," + haxor.math.Mathf.RoundPlaces(this.a,p_places) + "]";
	}
	,__class__: haxor.math.Color
};
haxor.component.Light = function() {
	if(haxor.component.Light.m_list == null) haxor.component.Light.m_list = [];
	if(haxor.component.Light.m_buffer == null) haxor.component.Light.m_buffer = new haxor.io.FloatArray(12 * haxor.component.Light.max);
	haxor.component.Light.m_list.push(this);
	haxor.component.Behaviour.call(this);
	this.color = new haxor.math.Color(1,1,1,1);
	this.intensity = 1.0;
};
$hxClasses["haxor.component.Light"] = haxor.component.Light;
haxor.component.Light.__name__ = ["haxor","component","Light"];
haxor.component.Light.get_list = function() {
	var l = new Array();
	if(haxor.component.Light.m_list == null) return l;
	var i = 0;
	while(i < haxor.component.Light.m_list.length) {
		l.push(haxor.component.Light.m_list[i]);
		i++;
	}
	return l;
};
haxor.component.Light.SetLightData = function(p_id,p_type,p_intensity,p_radius,p_atten,p_x,p_y,p_z,p_r,p_g,p_b,p_a) {
	var pos = p_id * 12;
	haxor.component.Light.m_buffer.Set(pos,p_type);
	haxor.component.Light.m_buffer.Set(pos + 1,p_intensity);
	haxor.component.Light.m_buffer.Set(pos + 2,p_radius);
	haxor.component.Light.m_buffer.Set(pos + 3,p_atten);
	haxor.component.Light.m_buffer.Set(pos + 4,p_x);
	haxor.component.Light.m_buffer.Set(pos + 5,p_y);
	haxor.component.Light.m_buffer.Set(pos + 6,p_z);
	haxor.component.Light.m_buffer.Set(pos + 8,p_r);
	haxor.component.Light.m_buffer.Set(pos + 9,p_g);
	haxor.component.Light.m_buffer.Set(pos + 10,p_b);
	haxor.component.Light.m_buffer.Set(pos + 11,p_a);
};
haxor.component.Light.__super__ = haxor.component.Behaviour;
haxor.component.Light.prototype = $extend(haxor.component.Behaviour.prototype,{
	OnDestroy: function() {
		haxor.component.Behaviour.prototype.OnDestroy.call(this);
		HxOverrides.remove(haxor.component.Light.m_list,this);
	}
	,__class__: haxor.component.Light
});
haxor.component.Renderer = function() {
	haxor.component.Behaviour.call(this);
};
$hxClasses["haxor.component.Renderer"] = haxor.component.Renderer;
haxor.component.Renderer.__name__ = ["haxor","component","Renderer"];
haxor.component.Renderer.__super__ = haxor.component.Behaviour;
haxor.component.Renderer.prototype = $extend(haxor.component.Behaviour.prototype,{
	get_material: function() {
		return this.m_material;
	}
	,set_material: function(v) {
		if(this.m_material == v) return v;
		this.m_material = v;
		return v;
	}
	,OnRender: function() {
	}
	,__class__: haxor.component.Renderer
});
haxor.component.MeshRenderer = function() {
	haxor.component.Renderer.call(this);
};
$hxClasses["haxor.component.MeshRenderer"] = haxor.component.MeshRenderer;
haxor.component.MeshRenderer.__name__ = ["haxor","component","MeshRenderer"];
haxor.component.MeshRenderer.__super__ = haxor.component.Renderer;
haxor.component.MeshRenderer.prototype = $extend(haxor.component.Renderer.prototype,{
	get_mesh: function() {
		return this.m_mesh;
	}
	,set_mesh: function(v) {
		if(this.m_mesh == v) return v;
		this.m_mesh = v;
		return v;
	}
	,get_visible: function() {
		return this.IsVisible(haxor.component.Camera.m_main);
	}
	,IsVisible: function(p_camera) {
		if(p_camera == null) return false;
		return true;
	}
	,CheckCulling: function() {
		return true;
	}
	,OnRender: function() {
	}
	,__class__: haxor.component.MeshRenderer
});
haxor.component.PointLight = function() {
	haxor.component.Light.call(this);
	this.atten = 1.0;
	this.radius = 1.0;
};
$hxClasses["haxor.component.PointLight"] = haxor.component.PointLight;
haxor.component.PointLight.__name__ = ["haxor","component","PointLight"];
haxor.component.PointLight.Create = function(p_color,p_intensity,p_atten,p_radius) {
	var e = new haxor.core.Entity();
	e.set_name("PointLight");
	var l = e.AddComponent(haxor.component.PointLight);
	l.color = p_color;
	l.intensity = p_intensity;
	l.atten = p_atten;
	l.radius = p_radius;
	return l;
};
haxor.component.PointLight.__super__ = haxor.component.Light;
haxor.component.PointLight.prototype = $extend(haxor.component.Light.prototype,{
	__class__: haxor.component.PointLight
});
haxor.component.SkinnedMeshRenderer = function() {
	haxor.component.MeshRenderer.call(this);
	this.m_joints = [];
	this.m_buffer = new haxor.io.FloatArray(8192);
	this.m_data = new haxor.graphics.texture.ComputeTexture(1,2048,haxor.graphics.PixelFormat.Float4);
	this.m_data.set_name("SkinningTexture" + this.get_uid());
};
$hxClasses["haxor.component.SkinnedMeshRenderer"] = haxor.component.SkinnedMeshRenderer;
haxor.component.SkinnedMeshRenderer.__name__ = ["haxor","component","SkinnedMeshRenderer"];
haxor.component.SkinnedMeshRenderer.__super__ = haxor.component.MeshRenderer;
haxor.component.SkinnedMeshRenderer.prototype = $extend(haxor.component.MeshRenderer.prototype,{
	set_joints: function(v) {
		if(v == null) this.m_joints = []; else this.m_joints = v;
		return this.m_joints;
	}
	,get_joints: function() {
		return this.m_joints;
	}
	,OnRender: function() {
		haxor.component.MeshRenderer.prototype.OnRender.call(this);
	}
	,__class__: haxor.component.SkinnedMeshRenderer
});
haxor.component.Transform = function() {
	haxor.component.Component.call(this);
	this.__cid = haxor.context.EngineContext.transform.tid.get_id();
	this.m_position = new haxor.math.Vector3(0,0,0);
	this.m_euler = new haxor.math.Vector3(0,0,0);
	this.m_localScale = new haxor.math.Vector3(1,1,1);
	this.m_scale = new haxor.math.Vector3(1,1,1);
	this.m_dirty = false;
	this.m_right = new haxor.math.Vector3(1,0,0);
	this.m_up = new haxor.math.Vector3(0,1,0);
	this.m_forward = haxor.math.Vector3.get_forward();
	this.m_worldMatrixInverse = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	this.m_worldMatrix = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	this.m_hierarchy = [];
	if(haxor.component.Transform.m_root != null) this.set_parent(null); else haxor.component.Transform.m_root = this;
};
$hxClasses["haxor.component.Transform"] = haxor.component.Transform;
haxor.component.Transform.__name__ = ["haxor","component","Transform"];
haxor.component.Transform.get_root = function() {
	return haxor.component.Transform.m_root;
};
haxor.component.Transform.__super__ = haxor.component.Component;
haxor.component.Transform.prototype = $extend(haxor.component.Component.prototype,{
	get_right: function() {
		if(this.m_dirty) this.UpdateWorldMatrix();
		return this.m_right.get_clone();
	}
	,set_right: function(v) {
		return v;
	}
	,get_up: function() {
		if(this.m_dirty) this.UpdateWorldMatrix();
		return this.m_up.get_clone();
	}
	,set_up: function(v) {
		return v;
	}
	,get_forward: function() {
		if(this.m_dirty) this.UpdateWorldMatrix();
		return this.m_forward.get_clone();
	}
	,set_forward: function(v) {
		return v;
	}
	,get_parent: function() {
		return this.m_parent;
	}
	,set_parent: function(v) {
		if(this.m_parent != null) HxOverrides.remove(this.m_parent.m_hierarchy,this);
		if(v == null) this.m_parent = haxor.component.Transform.m_root; else this.m_parent = v;
		this.m_parent.m_hierarchy.push(this);
		return this.m_parent;
	}
	,get_childCount: function() {
		return this.m_hierarchy.length;
	}
	,get_position: function() {
		return new haxor.math.Vector3(0,0,0).Set(this.m_position.x,this.m_position.y,this.m_position.z);
	}
	,set_position: function(v) {
		var dx = v.x - this.m_position.x;
		var dy = v.y - this.m_position.y;
		var dz = v.z - this.m_position.z;
		if(Math.abs(dx) < 0.0001) {
			if(Math.abs(dy) < 0.0001) {
				if(Math.abs(dz) < 0.0001) return v;
			}
		}
		this.Translate(dx,dy,dz);
		return v;
	}
	,get_localPosition: function() {
		if(this.m_parent == null) return this.get_position();
		var wm = this.m_parent.get_WorldMatrix();
		return this.m_parent.get_WorldMatrixInverse().Transform3x4(haxor.context.EngineContext.data.get_v3().Set3(this.m_position));
	}
	,set_localPosition: function(v) {
		if(this.m_parent == null) return v;
		this.set_position(this.m_parent.get_WorldMatrix().Transform3x4(v));
		return v;
	}
	,get_euler: function() {
		return new haxor.math.Vector3(0,0,0).Set(this.m_euler.x,this.m_euler.y,this.m_euler.z);
	}
	,set_euler: function(v) {
		var dx = v.x - this.m_euler.x;
		var dy = v.y - this.m_euler.y;
		var dz = v.z - this.m_euler.z;
		if(Math.abs(dx) < 0.0001) {
			if(Math.abs(dy) < 0.0001) {
				if(Math.abs(dz) < 0.0001) return v;
			}
		}
		this.Rotate(dx,dy,dz);
		return v;
	}
	,get_localEuler: function() {
		if(this.m_parent == null) return this.get_euler();
		return new haxor.math.Vector3(0,0,0).Set(this.m_euler.x - this.m_parent.m_euler.x,this.m_euler.y - this.m_parent.m_euler.y,this.m_euler.z - this.m_parent.m_euler.z);
	}
	,set_localEuler: function(v) {
		if(this.m_parent == null) return v;
		this.set_euler(haxor.context.EngineContext.data.get_v3().Set3(this.m_parent.m_euler).Add(v));
		return v;
	}
	,get_rotation: function() {
		return haxor.math.Quaternion.FromEuler(this.m_euler);
	}
	,set_rotation: function(v) {
		this.set_euler(haxor.math.Quaternion.ToEuler(v,haxor.context.EngineContext.data.get_v3()));
		return v;
	}
	,get_localRotation: function() {
		if(this.m_parent == null) return this.get_rotation();
		return haxor.math.Quaternion.FromEuler(haxor.context.EngineContext.data.get_v3().Set(this.m_euler.x - this.m_parent.m_euler.x,this.m_euler.y - this.m_parent.m_euler.y,this.m_euler.z - this.m_parent.m_euler.z));
	}
	,set_localRotation: function(v) {
		this.set_localEuler(haxor.math.Quaternion.ToEuler(v,haxor.context.EngineContext.data.get_v3()));
		return v;
	}
	,get_scale: function() {
		return this.m_scale.get_clone();
	}
	,get_localScale: function() {
		return this.m_localScale.get_clone();
	}
	,set_localScale: function(v) {
		var _g = this;
		var dx = v.x - this.m_localScale.x;
		var dy = v.y - this.m_localScale.y;
		var dz = v.z - this.m_localScale.z;
		if(Math.abs(dx) < 0.0001) {
			if(Math.abs(dy) < 0.0001) {
				if(Math.abs(dz) < 0.0001) return v;
			}
		}
		this.m_localScale.Set3(v);
		var ps;
		if(this.m_parent == null) ps = haxor.context.EngineContext.data.get_v3().Set(1,1,1); else ps = this.m_parent.m_scale;
		this.m_scale.x = this.m_localScale.x * ps.x;
		this.m_scale.y = this.m_localScale.y * ps.y;
		this.m_scale.z = this.m_localScale.z * ps.z;
		this.Traverse(function(t) {
			if(t == _g) return true;
			var pp;
			if(t.m_parent == null) pp = haxor.context.EngineContext.data.get_v3().Set(0,0,0); else pp = t.m_parent.m_position;
			if(t.m_parent == null) ps = haxor.context.EngineContext.data.get_v3().Set(1,1,1); else ps = t.m_parent.m_scale;
			t.m_scale.x = t.m_localScale.x * ps.x;
			t.m_scale.y = t.m_localScale.y * ps.y;
			t.m_scale.z = t.m_localScale.z * ps.z;
			var v1 = haxor.context.EngineContext.data.get_v3().Set3(t.m_position).Sub(pp);
			v1.Multiply(ps);
			v1.Add(pp);
			t.set_position(v1);
			haxor.context.EngineContext.transform.OnChange(t);
			return true;
		});
		this.m_dirty = true;
		return v;
	}
	,get_WorldMatrix: function() {
		if(this.m_dirty) this.UpdateWorldMatrix();
		return this.m_worldMatrix;
	}
	,get_WorldMatrixInverse: function() {
		if(this.m_dirty) this.UpdateWorldMatrix();
		return this.m_worldMatrixInverse;
	}
	,Translate: function(p_dx,p_dy,p_dz) {
		this.m_position.Add3(p_dx,p_dy,p_dz);
		var _g1 = 0;
		var _g = this.m_hierarchy.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_hierarchy[i].Translate(p_dx,p_dy,p_dz);
		}
		this.m_dirty = true;
		haxor.context.EngineContext.transform.OnChange(this);
		return this;
	}
	,Rotate: function(p_dx,p_dy,p_dz) {
		this.m_euler.Add3(p_dx,p_dy,p_dz);
		var _g1 = 0;
		var _g = this.m_hierarchy.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = this.m_hierarchy[i];
			var q = haxor.math.Quaternion.FromEuler(this.m_euler,haxor.context.EngineContext.data.get_q());
			var v = haxor.context.EngineContext.data.get_v3().Set3(c.m_position).Sub(this.m_position);
			q.Rotate(v);
			v.Add(this.m_position);
			c.set_position(v);
			c.Rotate(p_dx,p_dy,p_dz);
		}
		this.m_dirty = true;
		haxor.context.EngineContext.transform.OnChange(this);
		return this;
	}
	,RefreshWM: function() {
		if(this.m_dirty) this.UpdateWorldMatrix();
	}
	,UpdateWorldMatrix: function() {
		var q = haxor.math.Quaternion.FromEuler(this.m_euler,haxor.context.EngineContext.data.get_q());
		var sx = this.m_scale.x;
		var sy = this.m_scale.y;
		var sz = this.m_scale.z;
		var px = this.m_position.x;
		var py = this.m_position.y;
		var pz = this.m_position.z;
		var rx = q.x;
		var ry = q.y;
		var rz = q.z;
		var rw = q.w;
		var x2 = rx * rx;
		var y2 = ry * ry;
		var z2 = rz * rz;
		var xy = rx * ry;
		var xz = rx * rz;
		var yz = ry * rz;
		var xw = rw * rx;
		var yw = rw * ry;
		var zw = rw * rz;
		var r = haxor.context.EngineContext.data.get_m4();
		r.m00 = 1.0 - 2.0 * (y2 + z2);
		r.m01 = 2.0 * (xy - zw);
		r.m02 = 2.0 * (xz + yw);
		r.m10 = 2.0 * (xy + zw);
		r.m11 = 1.0 - 2.0 * (x2 + z2);
		r.m12 = 2.0 * (yz - xw);
		r.m20 = 2.0 * (xz - yw);
		r.m21 = 2.0 * (yz + xw);
		r.m22 = 1.0 - 2.0 * (x2 + y2);
		this.m_right.Set(r.m00,r.m10,r.m20);
		this.m_up.Set(r.m01,r.m11,r.m21);
		this.m_forward.Set(r.m02,r.m12,r.m22);
		var l = this.m_worldMatrix;
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
		this.m_scale.x = sx;
		this.m_scale.y = sy;
		this.m_scale.z = sz;
		haxor.math.Matrix4.GetInverseTransform(this.m_worldMatrix,this.m_worldMatrixInverse);
		this.m_dirty = false;
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
	,Lock: function() {
	}
	,Unlock: function() {
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
		this.Traverse(function(it) {
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
	,OutputHierarchy: function() {
		var d0 = 0;
		var hs = "";
		this.Traverse(function(t) {
			var tab = "";
			var td = 0;
			var d = Math.max(0,td - d0);
			var _g = 0;
			while(_g < d) {
				var i = _g++;
				tab += " ";
			}
			hs += tab + t.get_name() + " " + t.get_position().ToString() + t.get_rotation().ToString() + t.get_scale().ToString() + "\n";
			return true;
		});
		return hs;
	}
	,Traverse: function(p_callback) {
		this.TraverseStep(this,p_callback);
	}
	,TraverseStep: function(p_child,p_callback) {
		if(p_callback(p_child)) {
			var _g1 = 0;
			var _g = p_child.m_hierarchy.length;
			while(_g1 < _g) {
				var i = _g1++;
				this.TraverseStep(p_child.GetChild(i),p_callback);
			}
		}
	}
	,OnDestroy: function() {
		haxor.context.EngineContext.transform.tid.set_id(this.__cid);
	}
	,ToString: function(p_use_local,p_places) {
		if(p_places == null) p_places = 2;
		if(p_use_local == null) p_use_local = false;
		var p;
		if(p_use_local) p = this.get_localPosition(); else p = this.m_position;
		var e;
		if(p_use_local) e = this.get_localEuler(); else e = this.m_euler;
		var s;
		if(p_use_local) s = this.get_localScale(); else s = this.get_scale();
		return this.get_name() + " " + p.ToString(p_places) + "" + e.ToString(p_places) + "" + s.ToString(p_places);
	}
	,__class__: haxor.component.Transform
});
haxor.context = {};
haxor.context.CameraContext = function() {
	this.cid = 0;
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
$hxClasses["haxor.context.CameraContext"] = haxor.context.CameraContext;
haxor.context.CameraContext.__name__ = ["haxor","context","CameraContext"];
haxor.context.CameraContext.prototype = {
	Create: function(p_camera) {
		this.list.push(p_camera);
		this.SortCameraList();
	}
	,Destroy: function(p_camera) {
		this.ClearTargets(p_camera);
		HxOverrides.remove(this.list,p_camera);
		this.SortCameraList();
	}
	,Bind: function(p_camera) {
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
		if(rt != null) haxor.core.Resource.Destroy(rt);
		rt = this.back[c.__cid];
		if(rt != null) haxor.core.Resource.Destroy(rt);
		this.front[c.__cid] = null;
		this.back[c.__cid] = null;
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
		var w = haxor.graphics.Screen.m_width;
		var h = haxor.graphics.Screen.m_height;
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
		console.log(haxor.graphics.Screen.m_width + " " + haxor.graphics.Screen.m_height);
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
				if(c.m_target == null) tf = haxor.graphics.PixelFormat.RGB8; else tf = c.m_target.m_format;
				this.front[c.__cid] = new haxor.graphics.texture.RenderTexture(aw,ah,tf,c.m_captureDepth);
				if(c.get_filters().length <= 0) this.back[c.__cid] = this.front[c.__cid]; else this.back[c.__cid] = new haxor.graphics.texture.RenderTexture(aw,ah,tf,c.m_captureDepth);
				this.front[c.__cid].set_name(this.back[c.__cid].set_name("CameraScreenBuffer"));
			}
		}
		c.m_projection_dirty = true;
	}
	,SortCameraList: function() {
		this.list.sort(function(a,b) {
			if(a.get_order() == b.get_order()) {
				if(a.m_entity.get_name() < b.m_entity.get_name()) return -1; else return 1;
			} else if(a.get_order() < b.get_order()) return -1; else return 1;
		});
	}
	,__class__: haxor.context.CameraContext
};
haxor.context.DataContext = function() {
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
	var _g = haxor.context.DataContext.MAX_TEMP;
	while(_g1 < _g) {
		var k = _g1++;
		this.i.push(0);
		this.v.push(0.0);
		this.m_v2.push(new haxor.math.Vector2(0,0));
		this.m_v3.push(new haxor.math.Vector3(0,0,0));
		this.m_v4.push(new haxor.math.Vector4(0,0,0,0));
		this.m_c.push(new haxor.math.Color(0,0,0,1));
		this.m_q.push(new haxor.math.Quaternion(0,0,0,1.0));
		this.m_m4.push(new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1));
		this.m_aabb3.push(haxor.math.AABB3.get_empty());
		this.m_aabb2.push(haxor.math.AABB2.get_empty());
	}
};
$hxClasses["haxor.context.DataContext"] = haxor.context.DataContext;
haxor.context.DataContext.__name__ = ["haxor","context","DataContext"];
haxor.context.DataContext.prototype = {
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
	,Matrix4ToArray: function(m) {
		this.m4l[0] = m.m00;
		this.m4l[1] = m.m01;
		this.m4l[2] = m.m02;
		this.m4l[3] = m.m03;
		this.m4l[4] = m.m10;
		this.m4l[5] = m.m11;
		this.m4l[6] = m.m12;
		this.m4l[7] = m.m13;
		this.m4l[8] = m.m20;
		this.m4l[9] = m.m21;
		this.m4l[10] = m.m22;
		this.m4l[11] = m.m23;
		this.m4l[12] = m.m30;
		this.m4l[13] = m.m31;
		this.m4l[14] = m.m32;
		this.m4l[15] = m.m33;
		return this.m4l;
	}
	,__class__: haxor.context.DataContext
};
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
	haxor.context.EngineContext.renderers = [];
	haxor.context.EngineContext.list = [haxor.context.EngineContext.update,haxor.context.EngineContext.render,haxor.context.EngineContext.resize,haxor.context.EngineContext.resources,haxor.context.EngineContext.disposables];
	var _g = 0;
	while(_g < 32) {
		var i = _g++;
		var p = new haxor.context.Process("process.renderers",haxor.context.EngineContext.maxNodes,i == 31);
		haxor.context.EngineContext.renderers.push(p);
		haxor.context.EngineContext.list.push(p);
	}
	haxor.context.EngineContext.mesh = new haxor.context.MeshContext();
	haxor.context.EngineContext.material = new haxor.context.MaterialContext();
	haxor.context.EngineContext.texture = new haxor.context.TextureContext();
	haxor.context.EngineContext.data = new haxor.context.DataContext();
	haxor.context.EngineContext.gizmo = new haxor.context.GizmoContext();
	haxor.context.EngineContext.camera = new haxor.context.CameraContext();
	haxor.context.EngineContext.transform = new haxor.context.TransformContext();
};
haxor.context.EngineContext.Build = function() {
	haxor.context.EngineContext.mesh.Initialize();
	haxor.context.EngineContext.material.Initialize();
	haxor.context.EngineContext.texture.Initialize();
	haxor.context.EngineContext.gizmo.Initialize();
	haxor.context.EngineContext.transform.Initialize();
};
haxor.context.EngineContext.Enable = function(p_resource) {
	if(js.Boot.__instanceof(p_resource,haxor.core.IUpdateable)) haxor.context.EngineContext.update.Add(p_resource);
	if(js.Boot.__instanceof(p_resource,haxor.core.IRenderable)) haxor.context.EngineContext.render.Add(p_resource);
	if(js.Boot.__instanceof(p_resource,haxor.core.IResizeable)) haxor.context.EngineContext.resize.Add(p_resource);
	if(js.Boot.__instanceof(p_resource,haxor.core.Entity)) {
		var e = p_resource;
		var _g1 = 0;
		var _g = e.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = e.m_components[i];
			if(js.Boot.__instanceof(c,haxor.component.MeshRenderer)) haxor.context.EngineContext.renderers[e.m_layer].Add(c);
		}
	}
};
haxor.context.EngineContext.Disable = function(p_resource) {
	if(js.Boot.__instanceof(p_resource,haxor.core.IUpdateable)) haxor.context.EngineContext.update.Remove(p_resource);
	if(js.Boot.__instanceof(p_resource,haxor.core.IRenderable)) haxor.context.EngineContext.render.Remove(p_resource);
	if(js.Boot.__instanceof(p_resource,haxor.core.IResizeable)) haxor.context.EngineContext.resize.Remove(p_resource);
	if(js.Boot.__instanceof(p_resource,haxor.core.Entity)) {
		var e = p_resource;
		var _g1 = 0;
		var _g = e.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = e.m_components[i];
			if(js.Boot.__instanceof(c,haxor.component.MeshRenderer)) haxor.context.EngineContext.renderers[e.m_layer].Remove(c);
		}
	}
};
haxor.context.EngineContext.OnEntiyLayerChange = function(p_entity,p_from,p_to) {
	var e = p_entity;
	var _g1 = 0;
	var _g = e.m_components.length;
	while(_g1 < _g) {
		var i = _g1++;
		var c = e.m_components[i];
		if(!js.Boot.__instanceof(c,haxor.component.MeshRenderer)) continue;
		haxor.context.EngineContext.renderers[p_from].Remove(c);
		if(e.m_enabled && !e.m_destroyed) haxor.context.EngineContext.renderers[p_to].Add(c);
	}
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
haxor.context.GizmoContext = function() {
};
$hxClasses["haxor.context.GizmoContext"] = haxor.context.GizmoContext;
haxor.context.GizmoContext.__name__ = ["haxor","context","GizmoContext"];
haxor.context.GizmoContext.prototype = {
	Initialize: function() {
		this.CreateGrid(10.0);
	}
	,CreateGrid: function(p_step) {
		this.grid = new haxor.graphics.mesh.Mesh("$GridMesh");
		var len = p_step;
		var ox = -0.5;
		var oz = -0.5;
		var px = 0.0;
		var pz = 0.0;
		var vl = new haxor.io.FloatArray(len * 2);
		var k;
		k = 0;
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			vl.Set(k++,px - ox);
			vl.Set(k++,oz);
			vl.Set(k++,px - ox);
			vl.Set(k++,-oz);
			px += p_step;
		}
		k = 0;
		var _g1 = 0;
		while(_g1 < len) {
			var i1 = _g1++;
			vl.Set(k++,ox);
			vl.Set(k++,pz - oz);
			vl.Set(k++,-ox);
			vl.Set(k++,pz - oz);
			pz += p_step;
		}
		this.grid.Set("vertex",vl);
		this.grid_material = new haxor.graphics.material.Material("$GridMaterial");
		this.grid_material.set_shader(new haxor.graphics.material.Shader(haxor.context.ShaderContext.gizmo_grid_source));
		this.grid_material.SetBlending(770,771);
		this.grid_material.SetFloat("Area",1000.0);
		this.grid_material.SetColor("Tint",new haxor.math.Color(1.0,1.0,1.0,0.4));
	}
	,DrawGrid: function(p_area,p_color) {
		this.grid_material.SetFloat("Area",p_area);
		if(p_color != null) this.grid_material.SetColor("Tint",new haxor.math.Color(1.0,1.0,1.0,0.4));
		haxor.graphics.Graphics.RenderMesh(this.grid,this.grid_material);
	}
	,__class__: haxor.context.GizmoContext
};
haxor.context.MaterialContext = function() {
	this.mid = new haxor.context.UID();
	this.sid = new haxor.context.UID();
	this.uid = new haxor.context.UID();
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
	this.uniforms = [];
	this.programs = [];
	this.vertex_shaders = [];
	this.fragment_shaders = [];
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
			ul.push(haxor.graphics.GL.INVALID);
		}
		this.locations.push(l);
		this.uniforms.push(ul);
		this.programs.push(haxor.graphics.GL.INVALID);
		this.vertex_shaders.push(haxor.graphics.GL.INVALID);
		this.fragment_shaders.push(haxor.graphics.GL.INVALID);
	}
};
$hxClasses["haxor.context.MaterialContext"] = haxor.context.MaterialContext;
haxor.context.MaterialContext.__name__ = ["haxor","context","MaterialContext"];
haxor.context.MaterialContext.prototype = {
	Initialize: function() {
		haxor.graphics.GL.m_gl.DepthFunc(515);
		haxor.graphics.GL.m_gl.Enable(2929);
		haxor.graphics.GL.m_gl.DepthMask(true);
		haxor.graphics.GL.m_gl.Disable(3042);
		haxor.graphics.GL.m_gl.BlendFunc(1,0);
		haxor.graphics.GL.m_gl.Enable(2884);
		haxor.graphics.GL.m_gl.FrontFace(2305);
		haxor.graphics.GL.m_gl.CullFace(1029);
		haxor.graphics.GL.m_gl.Enable(3089);
	}
	,UpdateFlags: function(m) {
		if(m.zfunc != this.zfunc) {
			this.zfunc = m.zfunc;
			haxor.graphics.GL.m_gl.DepthFunc(this.zfunc);
		}
		if(m.ztest != this.ztest) {
			this.ztest = m.ztest;
			if(this.ztest) haxor.graphics.GL.m_gl.Enable(2929); else haxor.graphics.GL.m_gl.Disable(2929);
		}
		if(m.zwrite != this.zwrite) {
			this.zwrite = m.zwrite;
			haxor.graphics.GL.m_gl.DepthMask(this.zwrite);
		}
		if(m.blend != this.blend) {
			this.blend = m.blend;
			if(this.blend) haxor.graphics.GL.m_gl.Enable(3042); else haxor.graphics.GL.m_gl.Disable(3042);
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
		if(blend_change) haxor.graphics.GL.m_gl.BlendFunc(this.blendSrc,this.blendDst);
		if(m.invert != this.invert) {
			this.invert = m.invert;
			haxor.graphics.GL.m_gl.FrontFace(this.invert?2304:2305);
		}
		if(m.cull != this.cull) {
			this.cull = m.cull;
			if(this.cull == 0) haxor.graphics.GL.m_gl.Disable(2884); else {
				haxor.graphics.GL.m_gl.Enable(2884);
				haxor.graphics.GL.m_gl.CullFace(this.cull == 1?1028:1029);
			}
		}
	}
	,InitializeMaterial: function(m) {
		this.programs[m.__cid] = haxor.graphics.GL.m_gl.CreateProgram();
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
	,CreateUniform: function(m,u) {
		var p = this.programs[m.__cid];
		var loc = haxor.graphics.GL.m_gl.GetUniformLocation(p,u.name);
		this.uniforms[m.__cid][u.__cid] = loc;
		u.__d = true;
	}
	,DestroyUniform: function(m,u) {
		var p = this.programs[m.__cid];
		var loc = haxor.graphics.GL.m_gl.GetUniformLocation(p,u.name);
		this.uniforms[m.__cid][u.__cid] = haxor.graphics.GL.INVALID;
		haxor.context.EngineContext.material.uid.set_id(u.__cid);
	}
	,CreateCompileShader: function(s,t,c) {
		var id = haxor.graphics.GL.m_gl.CreateShader(t);
		var ss;
		if(t == 35633) ss = s.m_vss; else ss = s.m_fss;
		c[s.__cid] = id;
		haxor.graphics.GL.m_gl.ShaderSource(id,ss);
		haxor.graphics.GL.m_gl.CompileShader(id);
		if(haxor.graphics.GL.m_gl.GetShaderParameter(id,35713) == 0) {
			s.m_hasError = true;
			return haxor.graphics.GL.m_gl.GetShaderInfoLog(id);
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
			haxor.graphics.GL.m_gl.DetachShader(p,vs_id);
			haxor.graphics.GL.m_gl.DetachShader(p,fs_id);
		}
		if(s1 != null) {
			vs_id = this.vertex_shaders[s1.__cid];
			fs_id = this.fragment_shaders[s1.__cid];
			haxor.graphics.GL.m_gl.AttachShader(p,vs_id);
			haxor.graphics.GL.m_gl.AttachShader(p,fs_id);
			var al = haxor.context.EngineContext.mesh.attribs;
			var _g1 = 0;
			var _g = al.length;
			while(_g1 < _g) {
				var i = _g1++;
				haxor.graphics.GL.m_gl.BindAttribLocation(p,i,al[i]);
			}
			haxor.graphics.GL.m_gl.LinkProgram(p);
			if(haxor.graphics.GL.m_gl.GetProgramParameter(p,35714) == 0) haxor.core.Console.LogError("Material> [" + m.get_name() + "] Link Error @ [" + s1.get_name() + "]");
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
	}
	,UpdateMaterial: function(m) {
	}
	,GetAttribLocation: function(a) {
		if(this.current == null) return -1;
		var p = this.programs[this.current.__cid];
		var loc = this.locations[this.current.__cid][a.__cid];
		if(loc == -1) {
			loc = haxor.graphics.GL.m_gl.GetAttribLocation(p,a.m_name);
			if(loc < 0) this.locations[this.current.__cid][a.__cid] = -2;
		}
		return loc;
	}
	,Bind: function(m) {
		if(m != this.current) {
			this.current = m;
			if(m != null) {
				var p = this.programs[m.__cid];
				this.UpdateFlags(m);
				haxor.graphics.GL.m_gl.UseProgram(p);
			}
		}
		if(this.current != null) {
			var ul = this.current.m_uniforms;
			var _g1 = 0;
			var _g = ul.length;
			while(_g1 < _g) {
				var i = _g1++;
				var u = ul[i];
				if(u.__d) {
					u.__d = false;
					var loc = this.uniforms[this.current.__cid][u.__cid];
					if(loc == haxor.graphics.GL.INVALID) continue;
					if(u.isFloat) this.ApplyFloatUniform(loc,u); else this.ApplyIntUniform(loc,u);
				}
			}
		}
	}
	,ApplyFloatUniform: function(p_location,p_uniform) {
		var b = p_uniform.data;
		var off = p_uniform.offset;
		switch(off) {
		case 1:
			haxor.graphics.GL.Uniform1f(p_location,b.Get(0));
			break;
		case 2:
			haxor.graphics.GL.Uniform2f(p_location,b.Get(0),b.Get(1));
			break;
		case 3:
			haxor.graphics.GL.Uniform3f(p_location,b.Get(0),b.Get(1),b.Get(2));
			break;
		case 4:
			haxor.graphics.GL.Uniform4f(p_location,b.Get(0),b.Get(1),b.Get(2),b.Get(3));
			break;
		case 16:
			haxor.graphics.GL.m_gl.UniformMatrix4fv(p_location,false,b);
			break;
		default:
			haxor.graphics.GL.m_gl.Uniform1fv(p_location,b);
		}
	}
	,ApplyIntUniform: function(p_location,p_uniform) {
		var b = p_uniform.data;
		var off = p_uniform.offset;
		switch(off) {
		case 1:
			if(p_uniform.texture != null) haxor.context.EngineContext.texture.Activate(p_uniform.texture);
			haxor.graphics.GL.Uniform1i(p_location,b.Get(0));
			break;
		case 2:
			haxor.graphics.GL.Uniform2i(p_location,b.Get(0),b.Get(1));
			break;
		case 3:
			haxor.graphics.GL.Uniform3i(p_location,b.Get(0),b.Get(1),b.Get(2));
			break;
		case 4:
			haxor.graphics.GL.Uniform4i(p_location,b.Get(0),b.Get(1),b.Get(2),b.Get(3));
			break;
		default:
			haxor.graphics.GL.m_gl.Uniform1iv(p_location,b);
		}
	}
	,Unbind: function() {
	}
	,DestroyMaterial: function(m) {
		var p = this.programs[m.__cid];
		if(m.m_shader != null) {
			haxor.graphics.GL.m_gl.DetachShader(p,this.vertex_shaders[m.m_shader.__cid]);
			haxor.graphics.GL.m_gl.DetachShader(p,this.fragment_shaders[m.m_shader.__cid]);
		}
		haxor.graphics.GL.m_gl.DeleteProgram(p);
		haxor.context.EngineContext.material.mid.set_id(m.__cid);
		var _g1 = 0;
		var _g = m.m_uniforms.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.uid.set_id(m.m_uniforms[i].__cid);
		}
	}
	,DestroyShader: function(s) {
		haxor.graphics.GL.m_gl.DeleteShader(this.vertex_shaders[s.__cid]);
		haxor.graphics.GL.m_gl.DeleteShader(this.fragment_shaders[s.__cid]);
		haxor.context.EngineContext.material.sid.set_id(s.__cid);
	}
	,__class__: haxor.context.MaterialContext
};
haxor.context.MeshContext = function() {
	this.attribs = ["vertex","normal","uv0","uv1","uv2","color","weight","index"];
	this.aid = new haxor.context.UID();
	this.mid = new haxor.context.UID();
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
		this.buffers.push(haxor.graphics.GL.INVALID);
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
						haxor.graphics.GL.m_gl.EnableVertexAttrib(loc);
					}
					haxor.graphics.GL.m_gl.BindBuffer(34962,this.buffers[a.__cid]);
					haxor.graphics.GL.m_gl.VertexAttribPointer(loc,a.offset,type,false,0,0);
				}
				if(!has_color) haxor.graphics.GL.m_gl.VertexAttrib4f(5,1.0,1.0,1.0,1.0);
				if(this.current.m_indexed) {
					a = this.current.m_topology_attrib;
					haxor.graphics.GL.m_gl.BindBuffer(34963,this.buffers[a.__cid]);
				}
				null;
			}
		}
	}
	,Unbind: function() {
	}
	,Draw: function(m) {
		if(m.m_indexed) {
			haxor.graphics.GL.m_gl.DrawElements(m.primitive,m.m_topology_attrib.data.m_length,5123,0);
			null;
		} else {
			haxor.graphics.GL.m_gl.DrawArrays(m.primitive,0,m.m_vcount);
			null;
		}
	}
	,RemoveAttrib: function(p_attrib) {
		var id = this.buffers[p_attrib.__cid];
		if(id == haxor.graphics.GL.INVALID) return;
		haxor.graphics.GL.m_gl.DeleteBuffer(id);
		this.buffers[p_attrib.__cid] = haxor.graphics.GL.INVALID;
		this.aid.set_id(p_attrib.__cid);
	}
	,UpdateAttrib: function(a,p_mode,p_is_index) {
		var id = this.buffers[a.__cid];
		var target_flag;
		if(p_is_index) target_flag = 34963; else target_flag = 34962;
		a._loc_ = HxOverrides.indexOf(this.attribs,a.m_name,0);
		if(id == haxor.graphics.GL.INVALID) {
			id = haxor.graphics.GL.m_gl.CreateBuffer();
			this.buffers[a.__cid] = id;
		}
		haxor.graphics.GL.m_gl.BindBuffer(target_flag,id);
		haxor.graphics.GL.m_gl.BufferData(target_flag,a.data,p_mode);
		null;
	}
	,__class__: haxor.context.MeshContext
};
haxor.context.BaseProcess = function(p_name,p_update_cid) {
	if(p_update_cid == null) p_update_cid = true;
	this.name = p_name;
	this.__cid = haxor.context.BaseProcess.m_cid;
	haxor.core.Console.Log("\tProcess [" + p_name + "][" + this.__cid + "] created.",4);
	if(p_update_cid) haxor.context.BaseProcess.m_cid++;
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
haxor.context.Process = function(p_name,p_size,p_update_cid) {
	if(p_update_cid == null) p_update_cid = true;
	haxor.context.BaseProcess.call(this,p_name,p_update_cid);
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
		var iid = p_item.m_pid[this.__cid];
		if(iid >= 0) return;
		if(this.m_length >= this.list.length) this.list.push(null);
		this.list[this.m_length] = p_item;
		p_item.m_pid[this.__cid] = this.m_length++;
	}
	,Remove: function(p_item) {
		var iid = p_item.m_pid[this.__cid];
		if(iid < 0) return p_item;
		p_item.m_pid[this.__cid] = -1;
		this.m_length--;
		if(this.m_length <= 0) return p_item;
		this.list[iid] = this.list[this.m_length];
		p_item = this.list[iid];
		p_item.m_pid[this.__cid] = iid;
		return p_item;
	}
	,Clear: function() {
		this.m_length = 0;
		this.list = [];
	}
	,__class__: haxor.context.Process
});
haxor.context.ShaderContext = function() { };
$hxClasses["haxor.context.ShaderContext"] = haxor.context.ShaderContext;
haxor.context.ShaderContext.__name__ = ["haxor","context","ShaderContext"];
haxor.context.TextureContext = function() {
	this.tid = new haxor.context.UID();
	this.bind = null;
	this.target = null;
	this.active = [];
	this.ids = [];
	this.framebuffers = [];
	this.renderbuffers = [];
};
$hxClasses["haxor.context.TextureContext"] = haxor.context.TextureContext;
haxor.context.TextureContext.__name__ = ["haxor","context","TextureContext"];
haxor.context.TextureContext.TextureToTarget = function(p_texture) {
	if(p_texture.get_type() == haxor.graphics.TextureType.Texture2D) return 3553;
	if(p_texture.get_type() == haxor.graphics.TextureType.RenderTexture) return 3553;
	if(p_texture.get_type() == haxor.graphics.TextureType.TextureCube) return 34067;
	return 3553;
};
haxor.context.TextureContext.FormatToChannelBits = function(p_format) {
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
haxor.context.TextureContext.FormatToChannelType = function(p_format) {
	switch(p_format[1]) {
	case 4:case 5:case 6:
		return haxor.graphics.GL.HALF_FLOAT;
	case 7:case 8:case 9:
		return 5126;
	case 10:
		return 5123;
	case 3:case 2:case 1:case 0:
		return 5121;
	}
	return 5121;
};
haxor.context.TextureContext.FormatToChannelLayout = function(p_format) {
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
haxor.context.TextureContext.prototype = {
	Initialize: function() {
		var _g1 = 0;
		var _g = haxor.graphics.GL.MAX_ACTIVE_TEXTURE;
		while(_g1 < _g) {
			var i = _g1++;
			this.active.push(null);
		}
		var _g2 = 0;
		while(_g2 < 2048) {
			var i1 = _g2++;
			this.ids.push(haxor.graphics.GL.INVALID);
			this.framebuffers.push(haxor.graphics.GL.INVALID);
			this.renderbuffers.push(haxor.graphics.GL.INVALID);
		}
	}
	,Alloc: function(p_texture) {
		var w = p_texture.m_width;
		var h = p_texture.m_height;
		var chn_fmt = haxor.context.TextureContext.FormatToChannelLayout(p_texture.m_format);
		var chn_bit = haxor.context.TextureContext.FormatToChannelBits(p_texture.m_format);
		var chn_type = haxor.context.TextureContext.FormatToChannelType(p_texture.m_format);
		var tex_type;
		if(p_texture.get_type() == haxor.graphics.TextureType.Texture2D) tex_type = 3553; else if(p_texture.get_type() == haxor.graphics.TextureType.RenderTexture) tex_type = 3553; else if(p_texture.get_type() == haxor.graphics.TextureType.TextureCube) tex_type = 34067; else tex_type = 3553;
		this.Bind(p_texture);
		haxor.graphics.GL.m_gl.TexImage2DAlloc(tex_type,0,chn_fmt,w,h,0,chn_bit,chn_type);
	}
	,Create: function(p_texture) {
		p_texture.__slot = p_texture.__cid % haxor.graphics.GL.MAX_ACTIVE_TEXTURE;
		var id = haxor.graphics.GL.m_gl.CreateTexture();
		this.ids[p_texture.__cid] = id;
		this.UpdateParameters(p_texture);
		if(p_texture.get_type() != haxor.graphics.TextureType.TextureCube) this.Alloc(p_texture);
		if(p_texture.get_type() == haxor.graphics.TextureType.RenderTexture) {
			var rt = p_texture;
			var fb_id = haxor.graphics.GL.m_gl.CreateFramebuffer();
			this.framebuffers[p_texture.__cid] = fb_id;
			haxor.graphics.GL.m_gl.BindFramebuffer(36160,fb_id);
			haxor.graphics.GL.m_gl.FramebufferTexture2D(36160,36064,3553,id,0);
			if(rt.m_depth != null) {
				var depth_id = this.ids[rt.m_depth.__cid];
				haxor.graphics.GL.m_gl.FramebufferTexture2D(36160,36096,3553,depth_id,0);
			} else {
				var rb_id = haxor.graphics.GL.m_gl.CreateRenderbuffer();
				this.renderbuffers[p_texture.__cid] = rb_id;
				haxor.graphics.GL.m_gl.BindRenderbuffer(36161,rb_id);
				haxor.graphics.GL.m_gl.RenderbufferStorage(36161,33189,rt.m_width,rt.m_height);
				haxor.graphics.GL.m_gl.FramebufferRenderbuffer(36160,36096,36161,rb_id);
			}
			haxor.graphics.GL.BindFramebuffer(36160,haxor.graphics.GL.NULL);
			haxor.graphics.GL.BindRenderbuffer(36161,haxor.graphics.GL.NULL);
			this.Unbind();
		}
	}
	,Bind: function(p_texture) {
		if(p_texture == this.bind) return;
		this.bind = p_texture;
		var id = this.ids[this.bind.__cid];
		var target = haxor.context.TextureContext.TextureToTarget(this.bind);
		haxor.graphics.GL.m_gl.BindTexture(target,id);
	}
	,Unbind: function() {
		if(this.bind == null) return;
		var target = haxor.context.TextureContext.TextureToTarget(this.bind);
		this.bind = null;
		haxor.graphics.GL.BindTexture(target,haxor.graphics.GL.NULL);
	}
	,UpdateParameters: function(p_texture) {
		var target;
		if(p_texture.get_type() == haxor.graphics.TextureType.Texture2D) target = 3553; else if(p_texture.get_type() == haxor.graphics.TextureType.RenderTexture) target = 3553; else if(p_texture.get_type() == haxor.graphics.TextureType.TextureCube) target = 34067; else target = 3553;
		this.Bind(p_texture);
		haxor.graphics.GL.m_gl.TexParameteri(target,10242,(p_texture.m_wrap & haxor.graphics.TextureWrap.ClampX) != 0?33071:10497);
		haxor.graphics.GL.m_gl.TexParameteri(target,10243,(p_texture.m_wrap & haxor.graphics.TextureWrap.ClampY) != 0?33071:10497);
		if(haxor.graphics.GL.TEXTURE_ANISOTROPY_ENABLED) haxor.graphics.GL.TexParameterf(target,haxor.graphics.GL.TEXTURE_ANISOTROPY,Math.max(1,p_texture.m_aniso));
		var minf = p_texture.m_minFilter;
		var magf = p_texture.m_magFilter;
		if(p_texture.m_format == haxor.graphics.PixelFormat.Half) {
			if(!haxor.graphics.GL.TEXTURE_HALF_LINEAR) {
				minf = haxor.graphics.TextureFilter.Nearest;
				magf = haxor.graphics.TextureFilter.Nearest;
			}
		}
		switch(minf[1]) {
		case 0:
			haxor.graphics.GL.m_gl.TexParameteri(target,10241,9728);
			break;
		case 3:
			haxor.graphics.GL.m_gl.TexParameteri(target,10241,9986);
			break;
		case 2:
			haxor.graphics.GL.m_gl.TexParameteri(target,10241,9984);
			break;
		case 1:
			haxor.graphics.GL.m_gl.TexParameteri(target,10241,9729);
			break;
		case 5:
			haxor.graphics.GL.m_gl.TexParameteri(target,10241,9987);
			break;
		case 6:
			haxor.graphics.GL.m_gl.TexParameteri(target,10241,9987);
			break;
		case 4:
			haxor.graphics.GL.m_gl.TexParameteri(target,10241,9985);
			break;
		}
		switch(magf[1]) {
		case 0:
			haxor.graphics.GL.m_gl.TexParameteri(target,10240,9728);
			break;
		case 3:
			haxor.graphics.GL.m_gl.TexParameteri(target,10240,9728);
			break;
		case 2:
			haxor.graphics.GL.m_gl.TexParameteri(target,10240,9728);
			break;
		case 1:
			haxor.graphics.GL.m_gl.TexParameteri(target,10240,9729);
			break;
		case 5:
			haxor.graphics.GL.m_gl.TexParameteri(target,10240,9729);
			break;
		case 6:
			haxor.graphics.GL.m_gl.TexParameteri(target,10240,9729);
			break;
		case 4:
			haxor.graphics.GL.m_gl.TexParameteri(target,10240,9729);
			break;
		}
	}
	,Update: function(p_texture) {
		var target;
		if(p_texture.get_type() == haxor.graphics.TextureType.Texture2D) target = 3553; else if(p_texture.get_type() == haxor.graphics.TextureType.RenderTexture) target = 3553; else if(p_texture.get_type() == haxor.graphics.TextureType.TextureCube) target = 34067; else target = 3553;
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
		var chn_fmt = haxor.context.TextureContext.FormatToChannelLayout(p_texture.m_format);
		var chn_bit = haxor.context.TextureContext.FormatToChannelBits(p_texture.m_format);
		var chn_type = haxor.context.TextureContext.FormatToChannelType(p_texture.m_format);
		var steps = p_height / p_steps | 0;
		if(steps <= 1) steps = 1;
		var ua = new haxor.thread.Activity(function(t) {
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
				haxor.graphics.GL.TexSubImage2D(3553,0,p_x,py,p_width,1,chn_fmt,chn_type,b.get_buffer());
				b.get_buffer().ResetSlice();
				py++;
			}
			return true;
		},false,true);
	}
	,WriteTexture: function(p_target,p_texture) {
		var w = p_texture.m_width;
		var h = p_texture.m_height;
		var chn_fmt = haxor.context.TextureContext.FormatToChannelLayout(p_texture.m_format);
		var chn_bit = haxor.context.TextureContext.FormatToChannelBits(p_texture.m_format);
		var chn_type = haxor.context.TextureContext.FormatToChannelType(p_texture.m_format);
		if(p_texture.m_format == haxor.graphics.PixelFormat.Depth) haxor.graphics.GL.m_gl.TexImage2DAlloc(p_target,0,chn_fmt,w,h,0,chn_fmt,chn_type); else if(p_texture.get_type() == haxor.graphics.TextureType.Texture2D) {
			var t2d = p_texture;
			haxor.graphics.GL.TexImage2D(p_target,0,chn_fmt,w,h,0,chn_bit,chn_type,t2d.m_data.get_buffer());
		} else if(p_texture.get_type() == haxor.graphics.TextureType.RenderTexture) {
			var rt = p_texture;
			var id = this.ids[rt.__cid];
			haxor.graphics.GL.m_gl.FramebufferTexture2D(36160,36064,p_target,id,0);
		}
	}
	,Activate: function(p_texture) {
		var slot = p_texture.__slot;
		if(this.active[p_texture.__cid] == p_texture) return slot;
		this.active[p_texture.__cid] = p_texture;
		haxor.graphics.GL.m_gl.ActiveTexture(33984 + slot);
		this.Bind(p_texture);
		return slot;
	}
	,BindTarget: function(rt) {
		if(rt == null) {
			if(this.target != rt) {
				haxor.graphics.GL.BindFramebuffer(36160,haxor.graphics.GL.NULL);
				haxor.graphics.GL.BindRenderbuffer(36161,haxor.graphics.GL.NULL);
				this.target = null;
			}
		} else if(this.target != rt) {
			var fb_id = this.framebuffers[rt.__cid];
			haxor.graphics.GL.m_gl.BindFramebuffer(36160,fb_id);
			if(rt.m_depth == null) {
				var rb_id = this.renderbuffers[rt.__cid];
				haxor.graphics.GL.m_gl.BindRenderbuffer(36161,rb_id);
			}
			this.target = rt;
		}
	}
	,UpdateMipmaps: function(p_texture) {
		this.Bind(p_texture);
		var target;
		if(p_texture.get_type() == haxor.graphics.TextureType.Texture2D) target = 3553; else if(p_texture.get_type() == haxor.graphics.TextureType.RenderTexture) target = 3553; else if(p_texture.get_type() == haxor.graphics.TextureType.TextureCube) target = 34067; else target = 3553;
		haxor.graphics.GL.m_gl.GenerateMipmap(target);
	}
	,Destroy: function(p_texture) {
		var tex_id = this.ids[p_texture.__cid];
		if(tex_id != haxor.graphics.GL.INVALID) haxor.graphics.GL.m_gl.DeleteTexture(tex_id);
		if(p_texture.get_type() == haxor.graphics.TextureType.RenderTexture) {
			var fb_id = this.framebuffers[p_texture.__cid];
			var rb_id = this.renderbuffers[p_texture.__cid];
			if(fb_id != haxor.graphics.GL.INVALID) haxor.graphics.GL.m_gl.DeleteFramebuffer(fb_id);
			if(rb_id != haxor.graphics.GL.INVALID) haxor.graphics.GL.m_gl.DeleteRenderbuffer(rb_id);
		}
		haxor.context.EngineContext.texture.tid.set_id(p_texture.__cid);
	}
	,__class__: haxor.context.TextureContext
};
haxor.context.TransformContext = function() {
	this.tid = new haxor.context.UID();
};
$hxClasses["haxor.context.TransformContext"] = haxor.context.TransformContext;
haxor.context.TransformContext.__name__ = ["haxor","context","TransformContext"];
haxor.context.TransformContext.prototype = {
	Initialize: function() {
	}
	,OnChange: function(t) {
		var cl = t.m_entity.m_components;
		var _g1 = 0;
		var _g = cl.length;
		while(_g1 < _g) {
			var i = _g1++;
			cl[i].OnTransformUpdate();
		}
	}
	,__class__: haxor.context.TransformContext
};
haxor.context.UID = function() {
	this.m_id = 0;
	this.m_cache = [];
};
$hxClasses["haxor.context.UID"] = haxor.context.UID;
haxor.context.UID.__name__ = ["haxor","context","UID"];
haxor.context.UID.prototype = {
	get_id: function() {
		if(this.m_cache.length <= 0) return this.m_id++; else return this.m_cache.shift();
	}
	,set_id: function(v) {
		this.m_cache.push(v);
		return v;
	}
	,__class__: haxor.context.UID
};
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
	haxor.context.EngineContext.camera.Resize();
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
	if(p_name == null) p_name = "";
	haxor.core.Resource.call(this,p_name);
	this.m_enabled = true;
	this.m_components = [];
	this.m_layer = 1;
	this.m_transform = this.AddComponent(haxor.component.Transform);
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
	,get_transform: function() {
		return this.m_transform;
	}
	,get_layer: function() {
		return this.m_layer;
	}
	,set_layer: function(v) {
		if(v <= 0) v = 1;
		if(this.m_layer == v) return v;
		var ll = this.m_layer;
		this.m_layer = v;
		haxor.context.EngineContext.OnEntiyLayerChange(this,ll,this.m_layer);
		return this.m_layer;
	}
	,AddComponent: function(p_type) {
		if(this.m_destroyed) return null;
		if(this.m_transform != null) {
			if(p_type == haxor.component.Transform) return this.m_transform;
		}
		var c = Type.createInstance(p_type,[]);
		c.m_entity = this;
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
			if(js.Boot.__instanceof(this.m_components[i],p_type)) return this.m_components[i];
		}
		return null;
	}
	,GetComponents: function(p_type) {
		var res = [];
		var _g1 = 0;
		var _g = this.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(js.Boot.__instanceof(this.m_components[i],p_type)) res.push(this.m_components[i]);
		}
		return res;
	}
	,GetComponentInChildren: function(p_type) {
		var res = [];
		var res1 = null;
		this.m_transform.Traverse(function(t) {
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
		this.m_transform.Traverse(function(t) {
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
haxor.graphics.PixelFormat = { __ename__ : true, __constructs__ : ["Alpha8","Luminance","RGB8","RGBA8","Half","Half3","Half4","Float","Float3","Float4","Depth"] };
haxor.graphics.PixelFormat.Alpha8 = ["Alpha8",0];
haxor.graphics.PixelFormat.Alpha8.__enum__ = haxor.graphics.PixelFormat;
haxor.graphics.PixelFormat.Luminance = ["Luminance",1];
haxor.graphics.PixelFormat.Luminance.__enum__ = haxor.graphics.PixelFormat;
haxor.graphics.PixelFormat.RGB8 = ["RGB8",2];
haxor.graphics.PixelFormat.RGB8.__enum__ = haxor.graphics.PixelFormat;
haxor.graphics.PixelFormat.RGBA8 = ["RGBA8",3];
haxor.graphics.PixelFormat.RGBA8.__enum__ = haxor.graphics.PixelFormat;
haxor.graphics.PixelFormat.Half = ["Half",4];
haxor.graphics.PixelFormat.Half.__enum__ = haxor.graphics.PixelFormat;
haxor.graphics.PixelFormat.Half3 = ["Half3",5];
haxor.graphics.PixelFormat.Half3.__enum__ = haxor.graphics.PixelFormat;
haxor.graphics.PixelFormat.Half4 = ["Half4",6];
haxor.graphics.PixelFormat.Half4.__enum__ = haxor.graphics.PixelFormat;
haxor.graphics.PixelFormat.Float = ["Float",7];
haxor.graphics.PixelFormat.Float.__enum__ = haxor.graphics.PixelFormat;
haxor.graphics.PixelFormat.Float3 = ["Float3",8];
haxor.graphics.PixelFormat.Float3.__enum__ = haxor.graphics.PixelFormat;
haxor.graphics.PixelFormat.Float4 = ["Float4",9];
haxor.graphics.PixelFormat.Float4.__enum__ = haxor.graphics.PixelFormat;
haxor.graphics.PixelFormat.Depth = ["Depth",10];
haxor.graphics.PixelFormat.Depth.__enum__ = haxor.graphics.PixelFormat;
haxor.graphics.TextureFilter = { __ename__ : true, __constructs__ : ["Nearest","Linear","NearestMipmapNearest","NearestMipmapLinear","LinearMipmapNearest","LinearMipmapLinear","Trilinear"] };
haxor.graphics.TextureFilter.Nearest = ["Nearest",0];
haxor.graphics.TextureFilter.Nearest.__enum__ = haxor.graphics.TextureFilter;
haxor.graphics.TextureFilter.Linear = ["Linear",1];
haxor.graphics.TextureFilter.Linear.__enum__ = haxor.graphics.TextureFilter;
haxor.graphics.TextureFilter.NearestMipmapNearest = ["NearestMipmapNearest",2];
haxor.graphics.TextureFilter.NearestMipmapNearest.__enum__ = haxor.graphics.TextureFilter;
haxor.graphics.TextureFilter.NearestMipmapLinear = ["NearestMipmapLinear",3];
haxor.graphics.TextureFilter.NearestMipmapLinear.__enum__ = haxor.graphics.TextureFilter;
haxor.graphics.TextureFilter.LinearMipmapNearest = ["LinearMipmapNearest",4];
haxor.graphics.TextureFilter.LinearMipmapNearest.__enum__ = haxor.graphics.TextureFilter;
haxor.graphics.TextureFilter.LinearMipmapLinear = ["LinearMipmapLinear",5];
haxor.graphics.TextureFilter.LinearMipmapLinear.__enum__ = haxor.graphics.TextureFilter;
haxor.graphics.TextureFilter.Trilinear = ["Trilinear",6];
haxor.graphics.TextureFilter.Trilinear.__enum__ = haxor.graphics.TextureFilter;
haxor.graphics.TextureWrap = function() { };
$hxClasses["haxor.graphics.TextureWrap"] = haxor.graphics.TextureWrap;
haxor.graphics.TextureWrap.__name__ = ["haxor","graphics","TextureWrap"];
haxor.graphics.TextureType = { __ename__ : true, __constructs__ : ["None","Texture2D","TextureCube","RenderTexture"] };
haxor.graphics.TextureType.None = ["None",0];
haxor.graphics.TextureType.None.__enum__ = haxor.graphics.TextureType;
haxor.graphics.TextureType.Texture2D = ["Texture2D",1];
haxor.graphics.TextureType.Texture2D.__enum__ = haxor.graphics.TextureType;
haxor.graphics.TextureType.TextureCube = ["TextureCube",2];
haxor.graphics.TextureType.TextureCube.__enum__ = haxor.graphics.TextureType;
haxor.graphics.TextureType.RenderTexture = ["RenderTexture",3];
haxor.graphics.TextureType.RenderTexture.__enum__ = haxor.graphics.TextureType;
haxor.graphics.ClearFlag = function() { };
$hxClasses["haxor.graphics.ClearFlag"] = haxor.graphics.ClearFlag;
haxor.graphics.ClearFlag.__name__ = ["haxor","graphics","ClearFlag"];
haxor.graphics.GL = function() { };
$hxClasses["haxor.graphics.GL"] = haxor.graphics.GL;
haxor.graphics.GL.__name__ = ["haxor","graphics","GL"];
haxor.graphics.GL.get_api = function() {
	return haxor.graphics.GL.m_gl.get_api();
};
haxor.graphics.GL.Initialize = function(p_application) {
	haxor.graphics.GL.m_gl = new haxor.platform.html.graphics.WebGL(p_application);
};
haxor.graphics.GL.Resize = function() {
	haxor.graphics.GL.m_gl.Resize();
};
haxor.graphics.GL.BindBuffer = function(p_target,p_id) {
	haxor.graphics.GL.m_gl.BindBuffer(p_target,p_id);
};
haxor.graphics.GL.BufferData = function(p_target,p_data,p_mode) {
	haxor.graphics.GL.m_gl.BufferData(p_target,p_data,p_mode);
};
haxor.graphics.GL.BufferSubData = function(p_target,p_offset,p_data) {
	haxor.graphics.GL.m_gl.BufferSubData(p_target,p_offset,p_data);
};
haxor.graphics.GL.CreateBuffer = function() {
	return haxor.graphics.GL.m_gl.CreateBuffer();
};
haxor.graphics.GL.DrawArrays = function(p_primitive,p_start,p_count) {
	haxor.graphics.GL.m_gl.DrawArrays(p_primitive,p_start,p_count);
};
haxor.graphics.GL.DrawElements = function(p_primitive,p_count,p_type,p_offset) {
	haxor.graphics.GL.m_gl.DrawElements(p_primitive,p_count,p_type,p_offset);
};
haxor.graphics.GL.DeleteBuffer = function(p_id) {
	haxor.graphics.GL.m_gl.DeleteBuffer(p_id);
};
haxor.graphics.GL.DisableVertexAttrib = function(p_location) {
	haxor.graphics.GL.m_gl.DisableVertexAttrib(p_location);
};
haxor.graphics.GL.EnableVertexAttrib = function(p_location) {
	haxor.graphics.GL.m_gl.EnableVertexAttrib(p_location);
};
haxor.graphics.GL.VertexAttrib3f = function(p_location,p_x,p_y,p_z) {
	haxor.graphics.GL.m_gl.VertexAttrib3f(p_location,p_x,p_y,p_z);
};
haxor.graphics.GL.VertexAttrib4f = function(p_location,p_x,p_y,p_z,p_w) {
	haxor.graphics.GL.m_gl.VertexAttrib4f(p_location,p_x,p_y,p_z,p_w);
};
haxor.graphics.GL.VertexAttribPointer = function(p_location,p_components_size,p_type,p_normalized,p_stride,p_offset) {
	haxor.graphics.GL.m_gl.VertexAttribPointer(p_location,p_components_size,p_type,p_normalized,p_stride,p_offset);
};
haxor.graphics.GL.CompileShader = function(p_shader) {
	haxor.graphics.GL.m_gl.CompileShader(p_shader);
};
haxor.graphics.GL.CreateShader = function(p_type) {
	return haxor.graphics.GL.m_gl.CreateShader(p_type);
};
haxor.graphics.GL.DetachShader = function(p_program,p_shader) {
	haxor.graphics.GL.m_gl.DetachShader(p_program,p_shader);
};
haxor.graphics.GL.DeleteShader = function(p_shader) {
	haxor.graphics.GL.m_gl.DeleteShader(p_shader);
};
haxor.graphics.GL.GetShaderInfoLog = function(p_shader) {
	return haxor.graphics.GL.m_gl.GetShaderInfoLog(p_shader);
};
haxor.graphics.GL.GetShaderParameter = function(p_shader,p_parameter) {
	return haxor.graphics.GL.m_gl.GetShaderParameter(p_shader,p_parameter);
};
haxor.graphics.GL.ShaderSource = function(p_shader,p_source) {
	haxor.graphics.GL.m_gl.ShaderSource(p_shader,p_source);
};
haxor.graphics.GL.AttachShader = function(p_program,p_shader) {
	haxor.graphics.GL.m_gl.AttachShader(p_program,p_shader);
};
haxor.graphics.GL.BindAttribLocation = function(p_program,p_location,p_name) {
	haxor.graphics.GL.m_gl.BindAttribLocation(p_program,p_location,p_name);
};
haxor.graphics.GL.CreateProgram = function() {
	return haxor.graphics.GL.m_gl.CreateProgram();
};
haxor.graphics.GL.DeleteProgram = function(p_program) {
	haxor.graphics.GL.m_gl.DeleteProgram(p_program);
};
haxor.graphics.GL.GetAttribLocation = function(p_program,p_name) {
	return haxor.graphics.GL.m_gl.GetAttribLocation(p_program,p_name);
};
haxor.graphics.GL.GetUniformLocation = function(p_program,p_name) {
	return haxor.graphics.GL.m_gl.GetUniformLocation(p_program,p_name);
};
haxor.graphics.GL.GetProgramInfoLog = function(p_program) {
	return haxor.graphics.GL.m_gl.GetProgramInfoLog(p_program);
};
haxor.graphics.GL.GetProgramParameter = function(p_program,p_parameter) {
	return haxor.graphics.GL.m_gl.GetProgramParameter(p_program,p_parameter);
};
haxor.graphics.GL.LinkProgram = function(p_program) {
	haxor.graphics.GL.m_gl.LinkProgram(p_program);
};
haxor.graphics.GL.UseProgram = function(p_program) {
	haxor.graphics.GL.m_gl.UseProgram(p_program);
};
haxor.graphics.GL.ActiveTexture = function(p_slot) {
	haxor.graphics.GL.m_gl.ActiveTexture(p_slot);
};
haxor.graphics.GL.BindFramebuffer = function(p_target,p_id) {
	haxor.graphics.GL.m_gl.BindFramebuffer(p_target,p_id);
};
haxor.graphics.GL.BindRenderbuffer = function(p_target,p_id) {
	haxor.graphics.GL.m_gl.BindRenderbuffer(p_target,p_id);
};
haxor.graphics.GL.BindTexture = function(p_target,p_id) {
	haxor.graphics.GL.m_gl.BindTexture(p_target,p_id);
};
haxor.graphics.GL.CreateFramebuffer = function() {
	return haxor.graphics.GL.m_gl.CreateFramebuffer();
};
haxor.graphics.GL.CreateRenderbuffer = function() {
	return haxor.graphics.GL.m_gl.CreateRenderbuffer();
};
haxor.graphics.GL.CreateTexture = function() {
	return haxor.graphics.GL.m_gl.CreateTexture();
};
haxor.graphics.GL.DeleteFramebuffer = function(p_id) {
	haxor.graphics.GL.m_gl.DeleteFramebuffer(p_id);
};
haxor.graphics.GL.DeleteRenderbuffer = function(p_id) {
	haxor.graphics.GL.m_gl.DeleteRenderbuffer(p_id);
};
haxor.graphics.GL.DeleteTexture = function(p_id) {
	haxor.graphics.GL.m_gl.DeleteTexture(p_id);
};
haxor.graphics.GL.FramebufferRenderbuffer = function(p_target,p_attachment,p_renderbuffer_target,p_renderbuffer_id) {
	haxor.graphics.GL.m_gl.FramebufferRenderbuffer(p_target,p_attachment,p_renderbuffer_target,p_renderbuffer_id);
};
haxor.graphics.GL.FramebufferTexture2D = function(p_target,p_attachment,p_texture_target,p_texture_id,p_miplevel) {
	haxor.graphics.GL.m_gl.FramebufferTexture2D(p_target,p_attachment,p_texture_target,p_texture_id,p_miplevel);
};
haxor.graphics.GL.GenerateMipmap = function(p_target) {
	haxor.graphics.GL.m_gl.GenerateMipmap(p_target);
};
haxor.graphics.GL.PixelStorei = function(p_parameter,p_value) {
	haxor.graphics.GL.m_gl.PixelStorei(p_parameter,p_value);
};
haxor.graphics.GL.RenderbufferStorage = function(p_target,p_format,p_width,p_height) {
	haxor.graphics.GL.m_gl.RenderbufferStorage(p_target,p_format,p_width,p_height);
};
haxor.graphics.GL.TexImage2D = function(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type,p_data) {
	haxor.graphics.GL.m_gl.TexImage2D(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type,p_data);
};
haxor.graphics.GL.TexImage2DAlloc = function(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type) {
	haxor.graphics.GL.m_gl.TexImage2DAlloc(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type);
};
haxor.graphics.GL.TexSubImage2D = function(p_target,p_level,p_x,p_y,p_width,p_height,p_format,p_channel_type,p_data) {
	haxor.graphics.GL.m_gl.TexSubImage2D(p_target,p_level,p_x,p_y,p_width,p_height,p_format,p_channel_type,p_data);
};
haxor.graphics.GL.TexStorage2D = function(p_target,p_num_mipmaps,p_channels,p_width,p_height) {
	haxor.graphics.GL.m_gl.TexStorage2D(p_target,p_num_mipmaps,p_channels,p_width,p_height);
};
haxor.graphics.GL.TexParameterf = function(p_target,p_parameter,p_value) {
	haxor.graphics.GL.m_gl.TexParameterf(p_target,p_parameter,p_value);
};
haxor.graphics.GL.TexParameteri = function(p_target,p_parameter,p_value) {
	haxor.graphics.GL.m_gl.TexParameteri(p_target,p_parameter,p_value);
};
haxor.graphics.GL.Uniform1f = function(p_location,p_x) {
	haxor.graphics.GL.m_gl.Uniform1f(p_location,p_x);
};
haxor.graphics.GL.Uniform2f = function(p_location,p_x,p_y) {
	haxor.graphics.GL.m_gl.Uniform2f(p_location,p_x,p_y);
};
haxor.graphics.GL.Uniform3f = function(p_location,p_x,p_y,p_z) {
	haxor.graphics.GL.m_gl.Uniform3f(p_location,p_x,p_y,p_z);
};
haxor.graphics.GL.Uniform4f = function(p_location,p_x,p_y,p_z,p_w) {
	haxor.graphics.GL.m_gl.Uniform4f(p_location,p_x,p_y,p_z,p_w);
};
haxor.graphics.GL.Uniform1i = function(p_location,p_x) {
	haxor.graphics.GL.m_gl.Uniform1i(p_location,p_x);
};
haxor.graphics.GL.Uniform2i = function(p_location,p_x,p_y) {
	haxor.graphics.GL.m_gl.Uniform2i(p_location,p_x,p_y);
};
haxor.graphics.GL.Uniform3i = function(p_location,p_x,p_y,p_z) {
	haxor.graphics.GL.m_gl.Uniform3i(p_location,p_x,p_y,p_z);
};
haxor.graphics.GL.Uniform4i = function(p_location,p_x,p_y,p_z,p_w) {
	haxor.graphics.GL.m_gl.Uniform4i(p_location,p_x,p_y,p_z,p_w);
};
haxor.graphics.GL.Uniform1fv = function(p_location,p_v) {
	haxor.graphics.GL.m_gl.Uniform1fv(p_location,p_v);
};
haxor.graphics.GL.Uniform2fv = function(p_location,p_v) {
	haxor.graphics.GL.m_gl.Uniform2fv(p_location,p_v);
};
haxor.graphics.GL.Uniform3fv = function(p_location,p_v) {
	haxor.graphics.GL.m_gl.Uniform3fv(p_location,p_v);
};
haxor.graphics.GL.Uniform4fv = function(p_location,p_v) {
	haxor.graphics.GL.m_gl.Uniform4fv(p_location,p_v);
};
haxor.graphics.GL.Uniform1iv = function(p_location,p_v) {
	haxor.graphics.GL.m_gl.Uniform1iv(p_location,p_v);
};
haxor.graphics.GL.Uniform2iv = function(p_location,p_v) {
	haxor.graphics.GL.m_gl.Uniform2iv(p_location,p_v);
};
haxor.graphics.GL.Uniform3iv = function(p_location,p_v) {
	haxor.graphics.GL.m_gl.Uniform3iv(p_location,p_v);
};
haxor.graphics.GL.Uniform4iv = function(p_location,p_v) {
	haxor.graphics.GL.m_gl.Uniform4iv(p_location,p_v);
};
haxor.graphics.GL.UniformMatrix2fv = function(p_location,p_transpose,p_v) {
	haxor.graphics.GL.m_gl.UniformMatrix2fv(p_location,p_transpose,p_v);
};
haxor.graphics.GL.UniformMatrix3fv = function(p_location,p_transpose,p_v) {
	haxor.graphics.GL.m_gl.UniformMatrix3fv(p_location,p_transpose,p_v);
};
haxor.graphics.GL.UniformMatrix4fv = function(p_location,p_transpose,p_v) {
	haxor.graphics.GL.m_gl.UniformMatrix4fv(p_location,p_transpose,p_v);
};
haxor.graphics.GL.BlendFunc = function(p_src,p_dst) {
	haxor.graphics.GL.m_gl.BlendFunc(p_src,p_dst);
};
haxor.graphics.GL.Disable = function(p_flag) {
	haxor.graphics.GL.m_gl.Disable(p_flag);
};
haxor.graphics.GL.Enable = function(p_flag) {
	haxor.graphics.GL.m_gl.Enable(p_flag);
};
haxor.graphics.GL.DepthMask = function(p_flag) {
	haxor.graphics.GL.m_gl.DepthMask(p_flag);
};
haxor.graphics.GL.DepthFunc = function(p_flag) {
	haxor.graphics.GL.m_gl.DepthFunc(p_flag);
};
haxor.graphics.GL.CullFace = function(p_face) {
	haxor.graphics.GL.m_gl.CullFace(p_face);
};
haxor.graphics.GL.FrontFace = function(p_face) {
	haxor.graphics.GL.m_gl.FrontFace(p_face);
};
haxor.graphics.GL.Clear = function(p_flag) {
	haxor.graphics.GL.m_gl.Clear(p_flag);
};
haxor.graphics.GL.ClearDepth = function(p_value) {
	haxor.graphics.GL.m_gl.ClearDepth(p_value);
};
haxor.graphics.GL.ClearColor = function(p_r,p_g,p_b,p_a) {
	haxor.graphics.GL.m_gl.ClearColor(p_r,p_g,p_b,p_a);
};
haxor.graphics.GL.Viewport = function(p_x,p_y,p_width,p_height) {
	haxor.graphics.GL.m_gl.Viewport(p_x,p_y,p_width,p_height);
};
haxor.graphics.GL.Scissor = function(p_x,p_y,p_width,p_height) {
	haxor.graphics.GL.m_gl.Scissor(p_x,p_y,p_width,p_height);
};
haxor.graphics.GL.ReadPixels = function(p_x,p_y,p_width,p_height,p_format,p_type,p_pixels) {
	haxor.graphics.GL.m_gl.ReadPixels(p_x,p_y,p_width,p_height,p_format,p_type,p_pixels);
};
haxor.graphics.GL.GetError = function() {
	return haxor.graphics.GL.m_gl.GetError();
};
haxor.graphics.GL.GetErrorCode = function() {
	return haxor.graphics.GL.m_gl.GetErrorCode();
};
haxor.graphics.GL.GetErrorString = function(p_code) {
	return haxor.graphics.GL.m_gl.GetErrorString(p_code);
};
haxor.graphics.GL.LogError = function() {
	haxor.graphics.GL.m_gl.LogError();
};
haxor.graphics.GL.Assert = function(p_log) {
};
haxor.graphics.GL.Flush = function() {
	haxor.graphics.GL.m_gl.Flush();
};
haxor.graphics.GL.Focus = function() {
	haxor.graphics.GL.m_gl.Focus();
};
haxor.graphics.GraphicAPI = { __ename__ : true, __constructs__ : ["None","OpenGL","OpenGLES","WebGL"] };
haxor.graphics.GraphicAPI.None = ["None",0];
haxor.graphics.GraphicAPI.None.__enum__ = haxor.graphics.GraphicAPI;
haxor.graphics.GraphicAPI.OpenGL = ["OpenGL",1];
haxor.graphics.GraphicAPI.OpenGL.__enum__ = haxor.graphics.GraphicAPI;
haxor.graphics.GraphicAPI.OpenGLES = ["OpenGLES",2];
haxor.graphics.GraphicAPI.OpenGLES.__enum__ = haxor.graphics.GraphicAPI;
haxor.graphics.GraphicAPI.WebGL = ["WebGL",3];
haxor.graphics.GraphicAPI.WebGL.__enum__ = haxor.graphics.GraphicAPI;
haxor.graphics.GraphicContext = function(p_application) {
	this.m_api = haxor.graphics.GraphicAPI.None;
	this.m_application = p_application;
};
$hxClasses["haxor.graphics.GraphicContext"] = haxor.graphics.GraphicContext;
haxor.graphics.GraphicContext.__name__ = ["haxor","graphics","GraphicContext"];
haxor.graphics.GraphicContext.prototype = {
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
		return haxor.graphics.GL.INVALID;
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
		return haxor.graphics.GL.INVALID;
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
		return haxor.graphics.GL.INVALID;
	}
	,DeleteProgram: function(p_program) {
	}
	,GetAttribLocation: function(p_program,p_name) {
		return -1;
	}
	,GetUniformLocation: function(p_program,p_name) {
		return haxor.graphics.GL.INVALID;
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
		return haxor.graphics.GL.INVALID;
	}
	,CreateRenderbuffer: function() {
		return haxor.graphics.GL.INVALID;
	}
	,CreateTexture: function() {
		return haxor.graphics.GL.INVALID;
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
		haxor.core.Console.Log(this.GetError());
	}
	,__class__: haxor.graphics.GraphicContext
};
haxor.math.AABB2 = function(p_x,p_y,p_width,p_height) {
	if(p_height == null) p_height = 0;
	if(p_width == null) p_width = 0;
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.SetXYWH(p_x,p_y,p_width,p_height);
};
$hxClasses["haxor.math.AABB2"] = haxor.math.AABB2;
haxor.math.AABB2.__name__ = ["haxor","math","AABB2"];
haxor.math.AABB2.get_temp = function() {
	return haxor.context.EngineContext.data.get_aabb2();
};
haxor.math.AABB2.FromMinMax = function(p_xmin,p_xmax,p_ymin,p_ymax) {
	var b = new haxor.math.AABB2();
	b.set_xMin(p_xmin);
	b.set_xMax(p_xmax);
	b.set_yMin(p_ymin);
	b.set_yMax(p_ymax);
	return b;
};
haxor.math.AABB2.get_empty = function() {
	return new haxor.math.AABB2();
};
haxor.math.AABB2.prototype = {
	get_clone: function() {
		return haxor.math.AABB2.FromMinMax(this.get_xMin(),this.get_xMax(),this.get_yMin(),this.get_yMax());
	}
	,get_min: function() {
		return new haxor.math.Vector2(this.m_xMin,this.m_yMin);
	}
	,set_min: function(v) {
		this.set_xMin(v.x);
		this.set_yMin(v.y);
		return v;
	}
	,get_max: function() {
		return new haxor.math.Vector2(this.m_xMax,this.m_yMax);
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
		return new haxor.math.Vector2(this.get_xMin() + (this.get_xMax() - this.get_xMin()) * 0.5,this.get_yMin() + (this.get_yMax() - this.get_yMin()) * 0.5);
	}
	,set_center: function(v) {
		var hw = haxor.math.Mathf.Abs(this.get_xMax() - this.get_xMin()) * 0.5;
		var hh = haxor.math.Mathf.Abs(this.get_yMax() - this.get_yMin()) * 0.5;
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
		return haxor.math.Mathf.Abs(this.get_xMax() - this.get_xMin());
	}
	,set_width: function(v) {
		this.set_xMax(this.get_xMin() + v);
		return v;
	}
	,get_height: function() {
		return haxor.math.Mathf.Abs(this.get_yMax() - this.get_yMin());
	}
	,set_height: function(v) {
		this.set_yMax(this.get_yMin() + v);
		return v;
	}
	,get_size: function() {
		return new haxor.math.Vector2(haxor.math.Mathf.Abs(this.get_xMax() - this.get_xMin()),haxor.math.Mathf.Abs(this.get_yMax() - this.get_yMin()));
	}
	,set_size: function(v) {
		this.set_width(v.x);
		this.set_height(v.y);
		return v;
	}
	,Validate: function() {
		var x0 = this.m_xMin;
		var x1 = this.m_xMax;
		var y0 = this.m_yMin;
		var y1 = this.m_yMax;
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
		this.set_xMin(haxor.math.Mathf.Min(p_point.x,this.get_xMin()));
		this.set_xMax(haxor.math.Mathf.Max(p_point.x,this.get_xMax()));
		this.set_yMin(haxor.math.Mathf.Min(p_point.y,this.get_yMin()));
		this.set_yMax(haxor.math.Mathf.Max(p_point.y,this.get_yMax()));
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
		var s0 = haxor.math.Mathf.RoundPlaces(this.m_xMin,p_places) + "";
		var s1 = haxor.math.Mathf.RoundPlaces(this.m_xMax,p_places) + "";
		var s2 = haxor.math.Mathf.RoundPlaces(this.m_yMin,p_places) + "";
		var s3 = haxor.math.Mathf.RoundPlaces(this.m_yMax,p_places) + "";
		return "[" + s0 + "," + s1 + "|" + s2 + "," + s3 + "]";
	}
	,__class__: haxor.math.AABB2
};
haxor.graphics.Graphics = function() { };
$hxClasses["haxor.graphics.Graphics"] = haxor.graphics.Graphics;
haxor.graphics.Graphics.__name__ = ["haxor","graphics","Graphics"];
haxor.graphics.Graphics.Viewport = function(p_viewport) {
	var vp = p_viewport;
	var dirty = false;
	if(haxor.math.Mathf.Abs(vp.get_xMin() - haxor.graphics.Graphics.m_last_viewport.get_xMin()) > 0.0) dirty = true; else if(haxor.math.Mathf.Abs(vp.get_yMin() - haxor.graphics.Graphics.m_last_viewport.get_yMin()) > 0.0) dirty = true; else if(haxor.math.Mathf.Abs(haxor.math.Mathf.Abs(vp.get_xMax() - vp.get_xMin()) - haxor.graphics.Graphics.m_last_viewport.get_width()) > 0.0) dirty = true; else if(haxor.math.Mathf.Abs(haxor.math.Mathf.Abs(vp.get_yMax() - vp.get_yMin()) - haxor.graphics.Graphics.m_last_viewport.get_height()) > 0.0) dirty = true;
	if(dirty) {
		haxor.graphics.Graphics.m_last_viewport.SetAABB2(vp);
		haxor.graphics.GL.Viewport(vp.get_xMin(),vp.get_yMin(),haxor.math.Mathf.Abs(vp.get_xMax() - vp.get_xMin()),haxor.math.Mathf.Abs(vp.get_yMax() - vp.get_yMin()));
		haxor.graphics.GL.Scissor(vp.get_xMin(),vp.get_yMin(),haxor.math.Mathf.Abs(vp.get_xMax() - vp.get_xMin()),haxor.math.Mathf.Abs(vp.get_yMax() - vp.get_yMin()));
	}
};
haxor.graphics.Graphics.Clear = function(p_camera) {
	var c = p_camera;
	haxor.graphics.Graphics.Viewport(p_camera.m_pixelViewport);
	if(c.clear != haxor.graphics.ClearFlag.None) {
		var flag = 0;
		if((c.clear & haxor.graphics.ClearFlag.Color) != 0) flag |= 16384;
		if((c.clear & haxor.graphics.ClearFlag.Skybox) != 0) flag |= 16384;
		if((c.clear & haxor.graphics.ClearFlag.Depth) != 0) flag |= 256;
		haxor.graphics.GL.m_gl.ClearColor(c.background.r,c.background.g,c.background.b,c.background.a);
		haxor.graphics.GL.m_gl.ClearDepth(1.0);
		haxor.graphics.GL.m_gl.Clear(flag);
	}
};
haxor.graphics.Graphics.RenderMesh = function(p_mesh,p_material) {
	haxor.context.EngineContext.material.Bind(p_material);
	haxor.context.EngineContext.mesh.Bind(p_mesh);
	if(p_mesh.m_indexed) {
		haxor.graphics.GL.m_gl.DrawElements(p_mesh.primitive,p_mesh.m_topology_attrib.data.m_length,5123,0);
		null;
	} else {
		haxor.graphics.GL.m_gl.DrawArrays(p_mesh.primitive,0,p_mesh.m_vcount);
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
haxor.graphics.Screen.Initialize = function(p_application) {
	haxor.graphics.Screen.m_application = p_application;
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
	if(p_name == null) p_name = "";
	this.grab = false;
	haxor.core.Resource.call(this,p_name);
	this.__cid = haxor.context.EngineContext.material.mid.get_id();
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
	haxor.context.EngineContext.material.InitializeMaterial(this);
};
$hxClasses["haxor.graphics.material.Material"] = haxor.graphics.material.Material;
haxor.graphics.material.Material.__name__ = ["haxor","graphics","material","Material"];
haxor.graphics.material.Material.Transparent = function(p_texture,p_ztest,p_zwrite,p_double_sided) {
	if(p_double_sided == null) p_double_sided = false;
	if(p_zwrite == null) p_zwrite = true;
	if(p_ztest == null) p_ztest = true;
	var m = new haxor.graphics.material.Material();
	if(p_double_sided) m.cull = 0;
	m.SetBlending(770,771);
	m.set_shader(p_texture == null?haxor.graphics.material.Shader.m_flat_texture_shader == null?haxor.graphics.material.Shader.m_flat_texture_shader = new haxor.graphics.material.Shader(haxor.context.ShaderContext.flat_texture_source):haxor.graphics.material.Shader.m_flat_texture_shader:haxor.graphics.material.Shader.m_flat_shader == null?haxor.graphics.material.Shader.m_flat_shader = new haxor.graphics.material.Shader(haxor.context.ShaderContext.flat_source):haxor.graphics.material.Shader.m_flat_shader);
	m.queue = 2000;
	m.ztest = p_ztest;
	m.zwrite = p_zwrite;
	m.blend = true;
	if(p_texture != null) m.SetTexture("DiffuseTexture",p_texture);
	return m;
};
haxor.graphics.material.Material.AdditiveAlpha = function(p_texture,p_ztest,p_zwrite,p_double_sided) {
	if(p_double_sided == null) p_double_sided = false;
	if(p_zwrite == null) p_zwrite = true;
	if(p_ztest == null) p_ztest = true;
	var m = haxor.graphics.material.Material.Transparent(null,p_ztest,p_zwrite,p_double_sided);
	m.SetBlending(770,1);
	return m;
};
haxor.graphics.material.Material.Additive = function(p_texture,p_ztest,p_zwrite,p_double_sided) {
	if(p_double_sided == null) p_double_sided = false;
	if(p_zwrite == null) p_zwrite = true;
	if(p_ztest == null) p_ztest = true;
	var m = haxor.graphics.material.Material.Transparent(null,p_ztest,p_zwrite,p_double_sided);
	m.SetBlending(1,1);
	return m;
};
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
		this.blendSrc = p_src;
		this.blendDst = p_dst;
	}
	,SetTexture: function(p_name,p_texture) {
		if(p_texture == null) {
			this.RemoveUniform(p_name);
			return;
		}
		var u = this.FetchUniform(p_name,false,1,1,true);
		var b = u.data;
		b.Set(0,p_texture.__slot);
		u.texture = p_texture;
	}
	,SetMatrix4: function(p_name,p_matrix4) {
		var u = this.FetchUniform(p_name,true,16,16,true);
		var b = u.data;
		var l = haxor.context.EngineContext.data.Matrix4ToArray(p_matrix4);
		var _g = 0;
		while(_g < 16) {
			var i = _g++;
			b.Set(i,l[i]);
		}
	}
	,SetColor: function(p_name,p_color) {
		this.SetFloat4(p_name,p_color.r,p_color.g,p_color.b,p_color.a);
	}
	,SetVector4: function(p_name,p_v) {
		this.SetFloat4(p_name,p_v.x,p_v.y,p_v.z,p_v.w);
	}
	,SetVector3: function(p_name,p_v) {
		this.SetFloat3(p_name,p_v.x,p_v.y,p_v.z);
	}
	,SetVector2: function(p_name,p_v) {
		this.SetFloat2(p_name,p_v.x,p_v.y);
	}
	,SetFloat: function(p_name,p_v) {
		var u = this.FetchUniform(p_name,true,1,1,true);
		var b = u.data;
		b.Set(0,p_v);
	}
	,SetFloat4: function(p_name,p_x,p_y,p_z,p_w) {
		var u = this.FetchUniform(p_name,true,4,4,true);
		var b = u.data;
		b.Set(0,p_x);
		b.Set(1,p_y);
		b.Set(2,p_z);
		b.Set(3,p_w);
	}
	,SetFloat3: function(p_name,p_x,p_y,p_z) {
		var u = this.FetchUniform(p_name,true,3,3,true);
		var b = u.data;
		b.Set(0,p_x);
		b.Set(1,p_y);
		b.Set(2,p_z);
	}
	,SetFloat2: function(p_name,p_x,p_y) {
		var u = this.FetchUniform(p_name,true,2,2,true);
		var b = u.data;
		b.Set(0,p_x);
		b.Set(1,p_y);
	}
	,SetFloatArray: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,true,p_list.length,1,true);
		var b = u.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetFloat2Array: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,true,p_list.length,2,true);
		var b = u.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetFloat3Array: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,true,p_list.length,3,true);
		var b = u.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetFloat4Array: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,true,p_list.length,4,true);
		var b = u.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetInt: function(p_name,p_v) {
		var u = this.FetchUniform(p_name,false,1,1,true);
		var b = u.data;
		b.Set(0,p_v);
	}
	,SetInt4: function(p_name,p_x,p_y,p_z,p_w) {
		var u = this.FetchUniform(p_name,false,4,4,true);
		var b = u.data;
		b.Set(0,p_x);
		b.Set(1,p_y);
		b.Set(2,p_z);
		b.Set(3,p_w);
	}
	,SetInt3: function(p_name,p_x,p_y,p_z) {
		var u = this.FetchUniform(p_name,false,3,3,true);
		var b = u.data;
		b.Set(0,p_x);
		b.Set(1,p_y);
		b.Set(2,p_z);
	}
	,SetInt2: function(p_name,p_x,p_y) {
		var u = this.FetchUniform(p_name,false,2,2,true);
		var b = u.data;
		b.Set(0,p_x);
		b.Set(1,p_y);
	}
	,SetIntArray: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,false,p_list.length,1,true);
		var b = u.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetInt2Array: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,false,p_list.length,2,true);
		var b = u.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetInt3Array: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,false,p_list.length,3,true);
		var b = u.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
	}
	,SetInt4Array: function(p_name,p_list) {
		var u = this.FetchUniform(p_name,false,p_list.length,4,true);
		var b = u.data;
		var _g1 = 0;
		var _g = p_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.Set(i,p_list[i]);
		}
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
			haxor.context.EngineContext.material.DestroyUniform(this,u);
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
						if(u.data.m_length == p_length) u.__d = true;
						return u;
					}
				}
			}
		}
		if(p_create) {
			u = new haxor.graphics.material.MaterialUniform(p_name,p_is_float,p_length,p_offset);
			haxor.context.EngineContext.material.CreateUniform(this,u);
			this.m_uniforms.push(u);
		}
		return u;
	}
	,OnDestroy: function() {
		haxor.context.EngineContext.material.DestroyMaterial(this);
	}
	,__class__: haxor.graphics.material.Material
});
haxor.graphics.material.MaterialUniform = function(p_name,p_is_float,p_length,p_offset) {
	this.__cid = haxor.context.EngineContext.material.uid.get_id();
	this.__d = true;
	this.name = p_name;
	this.isFloat = p_is_float;
	this.offset = p_offset;
	if(p_is_float) this.data = new haxor.io.FloatArray(p_length); else this.data = new haxor.io.Int32Array(p_length);
};
$hxClasses["haxor.graphics.material.MaterialUniform"] = haxor.graphics.material.MaterialUniform;
haxor.graphics.material.MaterialUniform.__name__ = ["haxor","graphics","material","MaterialUniform"];
haxor.graphics.material.MaterialUniform.prototype = {
	__class__: haxor.graphics.material.MaterialUniform
};
haxor.graphics.material.Shader = function(p_source) {
	haxor.core.Resource.call(this);
	this.__cid = haxor.context.EngineContext.material.sid.get_id();
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
	haxor.context.EngineContext.material.InitializeShader(this);
};
$hxClasses["haxor.graphics.material.Shader"] = haxor.graphics.material.Shader;
haxor.graphics.material.Shader.__name__ = ["haxor","graphics","material","Shader"];
haxor.graphics.material.Shader.get_Flat = function() {
	if(haxor.graphics.material.Shader.m_flat_shader == null) return haxor.graphics.material.Shader.m_flat_shader = new haxor.graphics.material.Shader(haxor.context.ShaderContext.flat_source); else return haxor.graphics.material.Shader.m_flat_shader;
};
haxor.graphics.material.Shader.get_FlatTexture = function() {
	if(haxor.graphics.material.Shader.m_flat_texture_shader == null) return haxor.graphics.material.Shader.m_flat_texture_shader = new haxor.graphics.material.Shader(haxor.context.ShaderContext.flat_texture_source); else return haxor.graphics.material.Shader.m_flat_texture_shader;
};
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
haxor.graphics.mesh.Mesh = function(p_name) {
	if(p_name == null) p_name = "";
	haxor.core.Resource.call(this,p_name);
	this.__cid = haxor.context.EngineContext.mesh.mid.get_id();
	this.m_attribs = [];
	this.m_indexed = false;
	this.m_vcount = 0;
	this.m_bounds = haxor.math.AABB3.get_empty();
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
		if(p_offset == null) p_offset = 0;
		if(p_data == null) {
			haxor.core.Console.Log("Mesh> [" + this.get_name() + "] tried to set null array.",1);
			return null;
		}
		var a = this.GetAttribute(p_name);
		if(a == null) {
			a = new haxor.graphics.mesh.MeshAttrib();
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
		haxor.context.EngineContext.mesh.UpdateAttrib(a,this.m_mode,false);
		return a;
	}
	,GenerateAttribBounds: function(p_attrib,p_result) {
		var b;
		if(p_result == null) b = haxor.math.AABB3.get_empty(); else b = p_result;
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
		haxor.context.EngineContext.mesh.mid.set_id(this.__cid);
	}
	,__class__: haxor.graphics.mesh.Mesh
});
haxor.graphics.mesh.MeshAttrib = function() {
	this.__cid = haxor.context.EngineContext.mesh.aid.get_id();
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
haxor.graphics.mesh.MeshLayout = function(p_name) {
	if(p_name == null) p_name = "";
	haxor.graphics.mesh.Mesh.call(this,p_name);
	this.m_vertex = [];
	this.m_normal = [];
	this.m_color = [];
	this.m_uv0 = [];
	this.m_uv1 = [];
	this.m_tangent = [];
	this.m_binormal = [];
};
$hxClasses["haxor.graphics.mesh.MeshLayout"] = haxor.graphics.mesh.MeshLayout;
haxor.graphics.mesh.MeshLayout.__name__ = ["haxor","graphics","mesh","MeshLayout"];
haxor.graphics.mesh.MeshLayout.__super__ = haxor.graphics.mesh.Mesh;
haxor.graphics.mesh.MeshLayout.prototype = $extend(haxor.graphics.mesh.Mesh.prototype,{
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
		if(js.Boot.__instanceof(p_list[0],haxor.math.Vector2)) off = 2;
		if(js.Boot.__instanceof(p_list[0],haxor.math.Vector3)) off = 3;
		if(js.Boot.__instanceof(p_list[0],haxor.math.Vector4)) off = 4;
		if(js.Boot.__instanceof(p_list[0],haxor.math.Color)) off = 4;
		if(a == null) a = this.Set(p_name,new haxor.io.FloatArray(1),off);
		var p = 0;
		var f = a.data = new haxor.io.FloatArray(p_list.length * off);
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
		return p_list;
	}
	,__class__: haxor.graphics.mesh.MeshLayout
});
haxor.graphics.mesh.Mesh3 = function(p_name) {
	haxor.graphics.mesh.MeshLayout.call(this,p_name);
};
$hxClasses["haxor.graphics.mesh.Mesh3"] = haxor.graphics.mesh.Mesh3;
haxor.graphics.mesh.Mesh3.__name__ = ["haxor","graphics","mesh","Mesh3"];
haxor.graphics.mesh.Mesh3.__super__ = haxor.graphics.mesh.MeshLayout;
haxor.graphics.mesh.Mesh3.prototype = $extend(haxor.graphics.mesh.MeshLayout.prototype,{
	__class__: haxor.graphics.mesh.Mesh3
});
haxor.graphics.mesh.SkinnedMesh3 = function(p_name) {
	haxor.graphics.mesh.Mesh3.call(this,p_name);
};
$hxClasses["haxor.graphics.mesh.SkinnedMesh3"] = haxor.graphics.mesh.SkinnedMesh3;
haxor.graphics.mesh.SkinnedMesh3.__name__ = ["haxor","graphics","mesh","SkinnedMesh3"];
haxor.graphics.mesh.SkinnedMesh3.__super__ = haxor.graphics.mesh.Mesh3;
haxor.graphics.mesh.SkinnedMesh3.prototype = $extend(haxor.graphics.mesh.Mesh3.prototype,{
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
	,__class__: haxor.graphics.mesh.SkinnedMesh3
});
haxor.graphics.mesh.Mesh2D = function(p_name) {
	haxor.graphics.mesh.MeshLayout.call(this,p_name);
};
$hxClasses["haxor.graphics.mesh.Mesh2D"] = haxor.graphics.mesh.Mesh2D;
haxor.graphics.mesh.Mesh2D.__name__ = ["haxor","graphics","mesh","Mesh2D"];
haxor.graphics.mesh.Mesh2D.__super__ = haxor.graphics.mesh.MeshLayout;
haxor.graphics.mesh.Mesh2D.prototype = $extend(haxor.graphics.mesh.MeshLayout.prototype,{
	__class__: haxor.graphics.mesh.Mesh2D
});
haxor.graphics.mesh.Mesh23 = function(p_name) {
	haxor.graphics.mesh.MeshLayout.call(this,p_name);
};
$hxClasses["haxor.graphics.mesh.Mesh23"] = haxor.graphics.mesh.Mesh23;
haxor.graphics.mesh.Mesh23.__name__ = ["haxor","graphics","mesh","Mesh23"];
haxor.graphics.mesh.Mesh23.__super__ = haxor.graphics.mesh.MeshLayout;
haxor.graphics.mesh.Mesh23.prototype = $extend(haxor.graphics.mesh.MeshLayout.prototype,{
	__class__: haxor.graphics.mesh.Mesh23
});
haxor.graphics.mesh.Mesh2 = function(p_name) {
	haxor.graphics.mesh.MeshLayout.call(this,p_name);
};
$hxClasses["haxor.graphics.mesh.Mesh2"] = haxor.graphics.mesh.Mesh2;
haxor.graphics.mesh.Mesh2.__name__ = ["haxor","graphics","mesh","Mesh2"];
haxor.graphics.mesh.Mesh2.__super__ = haxor.graphics.mesh.MeshLayout;
haxor.graphics.mesh.Mesh2.prototype = $extend(haxor.graphics.mesh.MeshLayout.prototype,{
	__class__: haxor.graphics.mesh.Mesh2
});
haxor.graphics.mesh.Mesh4 = function(p_name) {
	haxor.graphics.mesh.MeshLayout.call(this,p_name);
};
$hxClasses["haxor.graphics.mesh.Mesh4"] = haxor.graphics.mesh.Mesh4;
haxor.graphics.mesh.Mesh4.__name__ = ["haxor","graphics","mesh","Mesh4"];
haxor.graphics.mesh.Mesh4.__super__ = haxor.graphics.mesh.MeshLayout;
haxor.graphics.mesh.Mesh4.prototype = $extend(haxor.graphics.mesh.MeshLayout.prototype,{
	__class__: haxor.graphics.mesh.Mesh4
});
haxor.graphics.mesh.Model = function() { };
$hxClasses["haxor.graphics.mesh.Model"] = haxor.graphics.mesh.Model;
haxor.graphics.mesh.Model.__name__ = ["haxor","graphics","mesh","Model"];
haxor.graphics.mesh.Model.get_screen = function() {
	if(haxor.graphics.mesh.Model.m_screen != null) return haxor.graphics.mesh.Model.m_screen;
	var m = new haxor.graphics.mesh.Mesh("$ModelScreen");
	var s = 1.0;
	var v = haxor.io.FloatArray.Alloc([-s,-s,0.5,s,-s,0.5,s,s,0.5,-s,s,0.5]);
	var uv = haxor.io.FloatArray.Alloc([0.0,0.0,0.0,1.0,0.0,0.0,1.0,1.0,0.0,0.0,1.0,0.0]);
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.set_topology(haxor.io.UInt16Array.Alloc([0,1,2,0,2,3]));
	return haxor.graphics.mesh.Model.m_screen = m;
};
haxor.graphics.mesh.Model.get_planeXY = function() {
	if(haxor.graphics.mesh.Model.m_planeXY != null) return haxor.graphics.mesh.Model.m_planeXY;
	var m = new haxor.graphics.mesh.Mesh("$ModelPlaneXY");
	var s = 0.5;
	var v = haxor.io.FloatArray.Alloc([-s,-s,0.0,s,-s,0.0,s,s,0.0,-s,s,0.0]);
	var uv = haxor.io.FloatArray.Alloc([0.0,0.0,0.0,1.0,0.0,0.0,1.0,1.0,0.0,0.0,1.0,0.0]);
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.set_topology(haxor.io.UInt16Array.Alloc([0,1,2,0,2,3]));
	return haxor.graphics.mesh.Model.m_planeXY = m;
};
haxor.graphics.mesh.Model.get_planeXZ = function() {
	if(haxor.graphics.mesh.Model.m_planeXZ != null) return haxor.graphics.mesh.Model.m_planeXZ;
	var m = new haxor.graphics.mesh.Mesh("$ModelPlaneXZ");
	var s = 0.5;
	var v = haxor.io.FloatArray.Alloc([-s,0.0,-s,s,0.0,-s,s,0.0,s,-s,0.0,s]);
	var uv = haxor.io.FloatArray.Alloc([0.0,0.0,0.0,1.0,0.0,0.0,1.0,1.0,0.0,0.0,1.0,0.0]);
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.set_topology(haxor.io.UInt16Array.Alloc([0,1,2,0,2,3]));
	return haxor.graphics.mesh.Model.m_planeXZ = m;
};
haxor.graphics.mesh.Model.get_planeYZ = function() {
	if(haxor.graphics.mesh.Model.m_planeYZ != null) return haxor.graphics.mesh.Model.m_planeYZ;
	var m = new haxor.graphics.mesh.Mesh("$ModelPlaneYZ");
	var s = 0.5;
	var v = haxor.io.FloatArray.Alloc([0.0,-s,-s,0.0,s,-s,0.0,s,s,0.0,-s,s]);
	var uv = haxor.io.FloatArray.Alloc([0.0,0.0,0.0,1.0,0.0,0.0,1.0,1.0,0.0,0.0,1.0,0.0]);
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.set_topology(haxor.io.UInt16Array.Alloc([0,1,2,0,2,3]));
	return haxor.graphics.mesh.Model.m_planeYZ = m;
};
haxor.graphics.mesh.Model.get_cube = function() {
	if(haxor.graphics.mesh.Model.m_cube != null) return haxor.graphics.mesh.Model.m_cube;
	var m = new haxor.graphics.mesh.Mesh("$ModelCube");
	var v = haxor.io.FloatArray.FromBase64("AAAAvwAAAL8AAAC/AAAAvwAAAD8AAAC/AAAAPwAAAD8AAAC/AAAAPwAAAD8AAAC/AAAAPwAAAL8AAAC/AAAAvwAAAL8AAAC/AAAAvwAAAL8AAAA/AAAAPwAAAL8AAAA/AAAAPwAAAD8AAAA/AAAAPwAAAD8AAAA/AAAAvwAAAD8AAAA/AAAAvwAAAL8AAAA/AAAAvwAAAL8AAAC/AAAAPwAAAL8AAAC/AAAAPwAAAL8AAAA/AAAAPwAAAL8AAAA/AAAAvwAAAL8AAAA/AAAAvwAAAL8AAAC/AAAAPwAAAL8AAAC/AAAAPwAAAD8AAAC/AAAAPwAAAD8AAAA/AAAAPwAAAD8AAAA/AAAAPwAAAL8AAAA/AAAAPwAAAL8AAAC/AAAAPwAAAD8AAAC/AAAAvwAAAD8AAAC/AAAAvwAAAD8AAAA/AAAAvwAAAD8AAAA/AAAAPwAAAD8AAAA/AAAAPwAAAD8AAAC/AAAAvwAAAD8AAAC/AAAAvwAAAL8AAAC/AAAAvwAAAL8AAAA/AAAAvwAAAL8AAAA/AAAAvwAAAD8AAAA/AAAAvwAAAD8AAAC/");
	var uv = haxor.io.FloatArray.FromBase64("AACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAgD8AAAAAAACAPwAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAAAAAAAAA");
	var n = haxor.io.FloatArray.FromBase64("AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAAAAAAIA/AAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAAAAAAAAgL8AAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAAAAAAAAgD8AAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAAAACAvwAAAAAAAAAA");
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.Set("normal",n,3);
	return haxor.graphics.mesh.Model.m_cube = m;
};
haxor.graphics.mesh.Model.get_tetrahedron = function() {
	if(haxor.graphics.mesh.Model.m_tetrahedron != null) return haxor.graphics.mesh.Model.m_tetrahedron;
	var m = new haxor.graphics.mesh.Mesh("$ModelTetrahedron");
	var v = haxor.io.FloatArray.FromBase64("AAAAAAAAAAAAAAAAsb+cvpm/Bz8AAAAAsb8cPwAAAAAAAAAAAAAAAAAAAAAAAAAArr+cvpu/B78AAAAAsb+cvpm/Bz8AAAAAAAAAAAAAAAAAAAAAsb8cPwAAAAAAAAAArr+cvpu/B78AAAAAsb8cPwAAAAAAAAAAAAAAAAAAAACX/1A/AAAAAAAAAACX/1A/sb8cPwAAAAAAAAAAsb+cvpm/Bz8AAAAAAAAAAAAAAACX/1A/sb+cvpm/Bz8AAAAAAAAAAAAAAACX/1A/AAAAAAAAAACX/1A/sb+cvpm/Bz8AAAAArr+cvpu/B78AAAAAAAAAAAAAAACX/1A/rr+cvpu/B78AAAAAAAAAAAAAAACX/1A/AAAAAAAAAACX/1A/rr+cvpu/B78AAAAAsb8cPwAAAAAAAAAAAAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/AAAAAAAAAACX/1A/");
	var uv = haxor.io.FloatArray.FromBase64("AAAAPwAAAAAAAAAAraqqPQAAAAAAAIA/AACAvgAAAAAAAIA/AAAAPwAAAAAAAAAAVlXVPgAAAAD+/38/raqqPQAAAAAAAIA/AAAAPwAAAAAAAAAAAABAPwAAAAAAAIA/VlXVPgAAAAD+/38/AABAPwAAAAAAAIA/AAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAACAvgAAAAAAAIA/raqqPQAAAAAAAIA/AAAAPwAAgD8AAAAAraqqPQAAAAAAAIA/AAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAraqqPQAAAAAAAIA/VlXVPgAAAAD+/38/AAAAPwAAgD8AAAAAVlXVPgAAAAD+/38/AAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAVlXVPgAAAAD+/38/AABAPwAAAAAAAIA/AAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAAAAAAPwAAgD8AAAAA");
	var n = haxor.io.FloatArray.FromBase64("AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AAAAAAAAAAAAAIC/AACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAQrPvPiWWTz9yxrM+QrPvPiWWTz9yxrM+QrPvPiWWTz9yxrM+AACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAARbNvv4aDqbNyxrM+RbNvv4aDqbN2xrM+RLNvv4aDqbNyxrM+AACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAARbPvPiWWT792xrM+SbPvPiWWT792xrM+RbPvPiWWT792xrM+AACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAAAACAPwAAAAAAAAAA");
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.Set("normal",n,3);
	return haxor.graphics.mesh.Model.m_tetrahedron = m;
};
haxor.graphics.mesh.Model.get_sphere = function() {
	if(haxor.graphics.mesh.Model.m_sphere != null) return haxor.graphics.mesh.Model.m_sphere;
	var m = new haxor.graphics.mesh.Mesh("$ModelSphere");
	var v = haxor.io.FloatArray.FromBase64("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");
	var uv = haxor.io.FloatArray.FromBase64("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");
	var n = haxor.io.FloatArray.FromBase64("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");
	m.Set("vertex",v,3);
	m.Set("uv0",uv,3);
	m.Set("normal",n,3);
	return haxor.graphics.mesh.Model.m_sphere = m;
};
haxor.graphics.texture = {};
haxor.graphics.texture.Bitmap = function(p_width,p_height,p_format) {
	haxor.core.Resource.call(this);
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
	if(this.m_float) this.m_buffer = new haxor.io.FloatArray(len); else this.m_buffer = new haxor.io.Buffer(len);
};
$hxClasses["haxor.graphics.texture.Bitmap"] = haxor.graphics.texture.Bitmap;
haxor.graphics.texture.Bitmap.__name__ = ["haxor","graphics","texture","Bitmap"];
haxor.graphics.texture.Bitmap.__super__ = haxor.core.Resource;
haxor.graphics.texture.Bitmap.prototype = $extend(haxor.core.Resource.prototype,{
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
		if(p_x < 0) return new haxor.math.Color();
		if(p_y < 0) return new haxor.math.Color();
		if(p_x >= this.m_width) return new haxor.math.Color();
		if(p_y >= this.m_height) return new haxor.math.Color();
		var cc = this.m_channels;
		var pos = (p_x + p_y * this.m_width) * cc;
		if(this.m_float) {
			var c = new haxor.math.Color();
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
		return haxor.math.Color.FromBytes(rb,gb,bb,ab);
	}
	,SetPixel: function(p_x,p_y,p_color) {
		if(p_x < 0) return;
		if(p_y < 0) return;
		if(p_x >= this.m_width) return;
		if(p_y >= this.m_height) return;
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
	,__class__: haxor.graphics.texture.Bitmap
});
haxor.graphics.texture.Texture = function() {
	haxor.core.Resource.call(this);
	this.m_mipmaps = false;
	this.m_format = haxor.graphics.PixelFormat.RGBA8;
	this.m_minFilter = haxor.graphics.TextureFilter.Linear;
	this.m_magFilter = haxor.graphics.TextureFilter.Linear;
	this.m_wrap = haxor.graphics.TextureWrap.ClampX | haxor.graphics.TextureWrap.ClampY | haxor.graphics.TextureWrap.ClampZ;
	this.m_width = 0;
	this.m_height = 0;
	this.m_aniso = 0;
	this.__cid = haxor.context.EngineContext.texture.tid.get_id();
};
$hxClasses["haxor.graphics.texture.Texture"] = haxor.graphics.texture.Texture;
haxor.graphics.texture.Texture.__name__ = ["haxor","graphics","texture","Texture"];
haxor.graphics.texture.Texture.__super__ = haxor.core.Resource;
haxor.graphics.texture.Texture.prototype = $extend(haxor.core.Resource.prototype,{
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
		haxor.context.EngineContext.texture.UpdateParameters(this);
		return v;
	}
	,get_aniso: function() {
		return this.m_aniso;
	}
	,set_aniso: function(v) {
		if(this.m_aniso == v) return v;
		this.m_aniso = v;
		haxor.context.EngineContext.texture.UpdateParameters(this);
		return v;
	}
	,get_minFilter: function() {
		return this.m_minFilter;
	}
	,set_minFilter: function(v) {
		if(this.m_minFilter == v) return v;
		this.m_minFilter = v;
		haxor.context.EngineContext.texture.UpdateParameters(this);
		return v;
	}
	,get_magFilter: function() {
		return this.m_magFilter;
	}
	,set_magFilter: function(v) {
		if(this.m_magFilter == v) return v;
		this.m_magFilter = v;
		haxor.context.EngineContext.texture.UpdateParameters(this);
		return v;
	}
	,get_mipmaps: function() {
		return this.m_mipmaps;
	}
	,get_type: function() {
		return haxor.graphics.TextureType.None;
	}
	,Apply: function() {
		haxor.context.EngineContext.texture.Update(this);
	}
	,GenerateMipmaps: function() {
		if(this.m_mipmaps) return;
		this.m_mipmaps = true;
		haxor.context.EngineContext.texture.UpdateMipmaps(this);
	}
	,OnDestroy: function() {
		haxor.core.Resource.prototype.OnDestroy.call(this);
		haxor.context.EngineContext.texture.Destroy(this);
	}
	,__class__: haxor.graphics.texture.Texture
});
haxor.graphics.texture.Texture2D = function(p_width,p_height,p_format) {
	haxor.graphics.texture.Texture.call(this);
	this.m_format = p_format;
	this.m_width = p_width;
	this.m_height = p_height;
	if(p_width <= 0) return;
	if(p_height <= 0) return;
	this.m_data = new haxor.graphics.texture.Bitmap(p_width,p_height,p_format);
	haxor.context.EngineContext.texture.Create(this);
};
$hxClasses["haxor.graphics.texture.Texture2D"] = haxor.graphics.texture.Texture2D;
haxor.graphics.texture.Texture2D.__name__ = ["haxor","graphics","texture","Texture2D"];
haxor.graphics.texture.Texture2D.get_white = function() {
	if(haxor.graphics.texture.Texture2D.m_white != null) return haxor.graphics.texture.Texture2D.m_white;
	haxor.graphics.texture.Texture2D.m_white = new haxor.graphics.texture.Texture2D(1,1,haxor.graphics.PixelFormat.RGB8);
	haxor.graphics.texture.Texture2D.m_white.m_data.Fill(new haxor.math.Color(1,1,1,1));
	haxor.graphics.texture.Texture2D.m_white.Apply();
	return haxor.graphics.texture.Texture2D.m_white;
};
haxor.graphics.texture.Texture2D.get_red = function() {
	if(haxor.graphics.texture.Texture2D.m_red != null) return haxor.graphics.texture.Texture2D.m_red;
	haxor.graphics.texture.Texture2D.m_red = new haxor.graphics.texture.Texture2D(1,1,haxor.graphics.PixelFormat.RGB8);
	haxor.graphics.texture.Texture2D.m_red.m_data.Fill(new haxor.math.Color(1.0,0,0,1));
	haxor.graphics.texture.Texture2D.m_red.Apply();
	return haxor.graphics.texture.Texture2D.m_red;
};
haxor.graphics.texture.Texture2D.get_random = function() {
	if(haxor.graphics.texture.Texture2D.m_random != null) return haxor.graphics.texture.Texture2D.m_random;
	haxor.graphics.texture.Texture2D.m_random = new haxor.graphics.texture.Texture2D(512,512,haxor.graphics.PixelFormat.Float4);
	haxor.graphics.texture.Texture2D.m_random.set_wrap(haxor.graphics.TextureWrap.RepeatX | haxor.graphics.TextureWrap.RepeatY);
	var _g1 = 0;
	var _g = haxor.graphics.texture.Texture2D.m_random.m_width;
	while(_g1 < _g) {
		var i = _g1++;
		var _g3 = 0;
		var _g2 = haxor.graphics.texture.Texture2D.m_random.m_height;
		while(_g3 < _g2) {
			var j = _g3++;
			haxor.graphics.texture.Texture2D.m_random.m_data.Set(j,i,Math.random(),Math.random(),Math.random(),Math.random());
		}
	}
	haxor.graphics.texture.Texture2D.m_random.Upload(10);
	return haxor.graphics.texture.Texture2D.m_random;
};
haxor.graphics.texture.Texture2D.FromBitmap = function(p_bitmap,p_apply) {
	if(p_apply == null) p_apply = true;
	var t = new haxor.graphics.texture.Texture2D(0,0,p_bitmap.m_format);
	t.m_data = p_bitmap;
	t.m_width = p_bitmap.m_width;
	t.m_height = p_bitmap.m_height;
	haxor.context.EngineContext.texture.Create(t);
	t.Apply();
	return t;
};
haxor.graphics.texture.Texture2D.__super__ = haxor.graphics.texture.Texture;
haxor.graphics.texture.Texture2D.prototype = $extend(haxor.graphics.texture.Texture.prototype,{
	get_data: function() {
		return this.m_data;
	}
	,get_type: function() {
		return haxor.graphics.TextureType.Texture2D;
	}
	,Upload: function(p_steps,p_on_complete) {
		if(p_steps == null) p_steps = 200;
		haxor.context.EngineContext.texture.UploadTexture(this,0,0,this.m_width,this.m_height,p_steps,p_on_complete);
	}
	,__class__: haxor.graphics.texture.Texture2D
});
haxor.graphics.texture.ComputeTexture = function(p_width,p_height,p_format) {
	haxor.graphics.texture.Texture2D.call(this,p_width,p_height,p_format);
	this.set_minFilter(haxor.graphics.TextureFilter.Nearest);
	this.set_magFilter(haxor.graphics.TextureFilter.Nearest);
	this.m_lock = false;
	this.m_dirty = false;
};
$hxClasses["haxor.graphics.texture.ComputeTexture"] = haxor.graphics.texture.ComputeTexture;
haxor.graphics.texture.ComputeTexture.__name__ = ["haxor","graphics","texture","ComputeTexture"];
haxor.graphics.texture.ComputeTexture.__super__ = haxor.graphics.texture.Texture2D;
haxor.graphics.texture.ComputeTexture.prototype = $extend(haxor.graphics.texture.Texture2D.prototype,{
	WriteRange: function(p_values,p_x,p_y,p_width,p_height) {
		if(p_height == null) p_height = -1;
		if(p_width == null) p_width = -1;
		if(p_y == null) p_y = 0;
		if(p_x == null) p_x = 0;
		var w;
		if(p_width < 0) w = this.m_width; else w = p_width;
		var h;
		if(p_height < 0) h = this.m_height; else h = p_height;
		this.m_data.SetRange(p_x,p_y,w,h,p_values);
		this.Refresh();
		this.m_dirty = true;
	}
	,Refresh: function() {
		if(this.m_lock) return;
		this.m_lock = true;
		this.Upload(10,$bind(this,this.OnUploadComplete));
	}
	,OnUploadComplete: function() {
		this.m_lock = false;
		if(this.m_dirty) this.Refresh();
		this.m_dirty = false;
	}
	,__class__: haxor.graphics.texture.ComputeTexture
});
haxor.graphics.texture.RenderTexture = function(p_width,p_height,p_format,p_store_depth) {
	if(p_store_depth == null) p_store_depth = false;
	haxor.graphics.texture.Texture.call(this);
	this.m_format = p_format;
	this.m_width = p_width | 0;
	this.m_height = p_height | 0;
	var store_depth = p_store_depth && haxor.graphics.GL.TEXTURE_DEPTH_ENABLED;
	if(store_depth) this.m_depth = new haxor.graphics.texture.Texture2D(this.m_width,this.m_height,haxor.graphics.PixelFormat.Depth);
	haxor.context.EngineContext.texture.Create(this);
};
$hxClasses["haxor.graphics.texture.RenderTexture"] = haxor.graphics.texture.RenderTexture;
haxor.graphics.texture.RenderTexture.__name__ = ["haxor","graphics","texture","RenderTexture"];
haxor.graphics.texture.RenderTexture.__super__ = haxor.graphics.texture.Texture;
haxor.graphics.texture.RenderTexture.prototype = $extend(haxor.graphics.texture.Texture.prototype,{
	get_depth: function() {
		return this.m_depth;
	}
	,get_type: function() {
		return haxor.graphics.TextureType.RenderTexture;
	}
	,__class__: haxor.graphics.texture.RenderTexture
});
haxor.graphics.texture.TextureCube = function() {
	this.m_faces = [null,null,null,null,null,null];
	this.m_is_cross = false;
	haxor.graphics.texture.Texture.call(this);
	haxor.context.EngineContext.texture.Create(this);
};
$hxClasses["haxor.graphics.texture.TextureCube"] = haxor.graphics.texture.TextureCube;
haxor.graphics.texture.TextureCube.__name__ = ["haxor","graphics","texture","TextureCube"];
haxor.graphics.texture.TextureCube.FromCrossTexture = function(p_texture) {
	return null;
};
haxor.graphics.texture.TextureCube.__super__ = haxor.graphics.texture.Texture;
haxor.graphics.texture.TextureCube.prototype = $extend(haxor.graphics.texture.Texture.prototype,{
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
		haxor.graphics.texture.Texture.prototype.OnDestroy.call(this);
		var _g1 = 0;
		var _g = this.m_faces.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.m_faces[i] != null) haxor.core.Resource.Destroy(this.m_faces[i]);
		}
	}
	,InvalidateCross: function() {
		if(!this.m_is_cross) return;
		var _g1 = 0;
		var _g = this.m_faces.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.m_faces[i] != null) haxor.core.Resource.Destroy(this.m_faces[i]);
		}
	}
	,__class__: haxor.graphics.texture.TextureCube
});
haxor.io = {};
haxor.io.Buffer = function(p_length) {
	this.Resize(p_length);
};
$hxClasses["haxor.io.Buffer"] = haxor.io.Buffer;
haxor.io.Buffer.__name__ = ["haxor","io","Buffer"];
haxor.io.Buffer.FromString = function(p_string) {
	var b = new haxor.io.Buffer(p_string.length);
	b.SetString(p_string);
	return b;
};
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
		var b = haxe.io.Bytes.alloc(this.m_length * this.get_bytesPerElement());
		var _g1 = 0;
		var _g = b.length;
		while(_g1 < _g) {
			var i = _g1++;
			b.set(i,this.GetByte(i));
		}
		var res = haxe.crypto.Base64.encode(b);
		var new_len = Std["int"](res.length / this.get_bytesPerElement());
		this.Resize(new_len);
		this.SetString(res);
		return res;
	}
	,DecodeBase64: function() {
		var b64 = this.GetString();
		var b = haxe.crypto.Base64.decode(b64);
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
	,__class__: haxor.io.Buffer
};
haxor.io.FloatArray = function(p_length) {
	haxor.io.Buffer.call(this,p_length);
};
$hxClasses["haxor.io.FloatArray"] = haxor.io.FloatArray;
haxor.io.FloatArray.__name__ = ["haxor","io","FloatArray"];
haxor.io.FloatArray.Alloc = function(p_data) {
	var b = new haxor.io.FloatArray(p_data.length);
	b.SetRange(p_data);
	return b;
};
haxor.io.FloatArray.FromBase64 = function(p_data) {
	var b = new haxor.io.FloatArray(p_data.length / 4 | 0);
	b.SetString(p_data);
	b.DecodeBase64();
	return b;
};
haxor.io.FloatArray.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	var res = new haxor.io.FloatArray(tk.length);
	var _g1 = 0;
	var _g = tk.length;
	while(_g1 < _g) {
		var i = _g1++;
		res.Set(i,Std.parseFloat(StringTools.trim(tk[i])));
	}
	return res;
};
haxor.io.FloatArray.__super__ = haxor.io.Buffer;
haxor.io.FloatArray.prototype = $extend(haxor.io.Buffer.prototype,{
	get_bytesPerElement: function() {
		return 4;
	}
	,Resize: function(p_length) {
		haxor.io.Buffer.prototype.Resize.call(this,p_length);
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
		haxor.io.Buffer.prototype.SetViewSlice.call(this,p_start,p_length);
		var i0 = p_start;
		var i1 = i0 + p_length;
		var f32 = this.aux;
		this.aux = f32.subarray(i0,i1);
	}
	,__class__: haxor.io.FloatArray
});
haxor.io.Int32Array = function(p_length) {
	haxor.io.Buffer.call(this,p_length);
};
$hxClasses["haxor.io.Int32Array"] = haxor.io.Int32Array;
haxor.io.Int32Array.__name__ = ["haxor","io","Int32Array"];
haxor.io.Int32Array.Alloc = function(p_data) {
	var b = new haxor.io.Int32Array(p_data.length);
	b.SetRange(p_data);
	return b;
};
haxor.io.Int32Array.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	var res = new haxor.io.Int32Array(tk.length);
	var _g1 = 0;
	var _g = tk.length;
	while(_g1 < _g) {
		var i = _g1++;
		res.Set(i,Std.parseInt(StringTools.trim(tk[i])));
	}
	return res;
};
haxor.io.Int32Array.__super__ = haxor.io.Buffer;
haxor.io.Int32Array.prototype = $extend(haxor.io.Buffer.prototype,{
	get_bytesPerElement: function() {
		return 4;
	}
	,Resize: function(p_length) {
		haxor.io.Buffer.prototype.Resize.call(this,p_length);
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
		haxor.io.Buffer.prototype.SetViewSlice.call(this,p_start,p_length);
		var i0 = p_start;
		var i1 = i0 + p_length;
		var i32 = this.aux;
		this.aux = i32.subarray(i0,i1);
	}
	,__class__: haxor.io.Int32Array
});
haxor.io.UInt16Array = function(p_length) {
	haxor.io.Buffer.call(this,p_length);
};
$hxClasses["haxor.io.UInt16Array"] = haxor.io.UInt16Array;
haxor.io.UInt16Array.__name__ = ["haxor","io","UInt16Array"];
haxor.io.UInt16Array.Alloc = function(p_data) {
	var b = new haxor.io.UInt16Array(p_data.length);
	b.SetRange(p_data);
	return b;
};
haxor.io.UInt16Array.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	var res = new haxor.io.UInt16Array(tk.length);
	var _g1 = 0;
	var _g = tk.length;
	while(_g1 < _g) {
		var i = _g1++;
		res.Set(i,Std.parseInt(StringTools.trim(tk[i])));
	}
	return res;
};
haxor.io.UInt16Array.__super__ = haxor.io.Buffer;
haxor.io.UInt16Array.prototype = $extend(haxor.io.Buffer.prototype,{
	get_bytesPerElement: function() {
		return 2;
	}
	,Resize: function(p_length) {
		haxor.io.Buffer.prototype.Resize.call(this,p_length);
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
		haxor.io.Buffer.prototype.SetViewSlice.call(this,p_start,p_length);
		var i0 = p_start;
		var i1 = i0 + p_length;
		var i16 = this.aux;
		this.aux = i16.subarray(i0,i1);
	}
	,__class__: haxor.io.UInt16Array
});
haxor.io.file = {};
haxor.io.file.AssetFile = function(p_name) {
	haxor.core.Resource.call(this,p_name);
};
$hxClasses["haxor.io.file.AssetFile"] = haxor.io.file.AssetFile;
haxor.io.file.AssetFile.__name__ = ["haxor","io","file","AssetFile"];
haxor.io.file.AssetFile.__super__ = haxor.core.Resource;
haxor.io.file.AssetFile.prototype = $extend(haxor.core.Resource.prototype,{
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
	,__class__: haxor.io.file.AssetFile
});
haxor.io.file.AssetXML = function(p_name,p_src) {
	haxor.io.file.AssetFile.call(this,p_name);
	this.x = Xml.parse(p_src);
	this.TraverseStep(this.x.firstElement());
};
$hxClasses["haxor.io.file.AssetXML"] = haxor.io.file.AssetXML;
haxor.io.file.AssetXML.__name__ = ["haxor","io","file","AssetXML"];
haxor.io.file.AssetXML.__super__ = haxor.io.file.AssetFile;
haxor.io.file.AssetXML.prototype = $extend(haxor.io.file.AssetFile.prototype,{
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
	,__class__: haxor.io.file.AssetXML
});
haxor.io.file.ColladaFile = function(p_name,p_src) {
	this.xmlns = "";
	this.version = "";
	this.data = new haxor.io.file.ColladaAssetData();
	this.geometries = [];
	this.images = [];
	this.controllers = [];
	this.materials = [];
	this.animations = [];
	this.lights = [];
	this.scene = null;
	this.m_id = Std["int"](Math.random() * 16777215);
	haxor.io.file.AssetXML.call(this,p_name,p_src);
};
$hxClasses["haxor.io.file.ColladaFile"] = haxor.io.file.ColladaFile;
haxor.io.file.ColladaFile.__name__ = ["haxor","io","file","ColladaFile"];
haxor.io.file.ColladaFile.GenerateTriangles = function(p_type,p_indexes,p_vcount) {
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
			var tris = haxor.io.file.ColladaFile.TriangulatePolygon(p_indexes[i],p_indexes[i].length);
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
			var tris1 = haxor.io.file.ColladaFile.TriangulatePolygon(p_indexes[0],o,k);
			while(tris1.length > 0) triangles.push(tris1.shift());
			k += o;
		}
		break;
	}
	return triangles;
};
haxor.io.file.ColladaFile.TriangulatePolygon = function(t,c,o) {
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
haxor.io.file.ColladaFile.__super__ = haxor.io.file.AssetXML;
haxor.io.file.ColladaFile.prototype = $extend(haxor.io.file.AssetXML.prototype,{
	get_asset: function() {
		var _g3 = this;
		var re = new haxor.core.Entity();
		re.set_name("collada_asset");
		if(this.scene == null) {
			haxor.core.Console.LogError("ColladaFile> Trying to get asset of NULL scene.");
			return re;
		}
		if(this.scene.name != "") re.set_name(this.scene.name); else if(this.scene.id != "") re.set_name(this.scene.id);
		var hm = new haxe.ds.ObjectMap();
		var cm = new haxe.ds.ObjectMap();
		var mm = new haxe.ds.ObjectMap();
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
			var mat = haxor.core.Resource.Get(mn);
			if(mat == null) {
				mat = new haxor.graphics.material.Material();
				mat.set_name(mn);
				mat.set_shader(haxor.core.Resource.Get("haxor/unlit/FlatTexture"));
				haxor.core.Resource.Add(mn,mat);
			}
			mm.set(m,mat);
		}
		this.scene.Traverse(function(n) {
			var pe;
			if(n.parent == null) pe = re; else if(hm.h.__keys__[n.parent.__id__] != null) pe = hm.h[n.parent.__id__]; else pe = re;
			var ne = null;
			if(n.name == "EnvironmentAmbientLight") return;
			ne = new haxor.core.Entity();
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
				var ad = ne.AddComponent(haxor.component.DataComponent);
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
						var pl = ne.AddComponent(haxor.component.PointLight);
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
						mr = _g3.CreateMeshRenderer(ne,cg_target,cg.mesh.primitives[i3],cc == null?haxor.component.MeshRenderer:haxor.component.SkinnedMeshRenderer,cc);
						if(cc != null) skinned_meshes.push(mr);
						if(cmat != null) mr.set_material(mm.h.__keys__[cmat.__id__] != null?mm.h[cmat.__id__]:mr.m_material); else {
							var _g5 = 0;
							while(_g5 < 10) {
								var i4 = _g5++;
								mn1 = StringTools.replace(mn1,"_" + i4,"");
							}
							mn1 = StringTools.replace(mn1,"_","/");
							var mat1 = haxor.core.Resource.Get(mn1);
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
		if(this.data.axis == "z_up") re.m_transform.set_rotation(haxor.math.Quaternion.FromAxisAngle(new haxor.math.Vector3(1,0,0),-90.0));
		return re;
	}
	,AddAnimations: function(p_entity,p_exact) {
		if(p_exact == null) p_exact = true;
	}
	,CreateMeshRenderer: function(e,msh,cp,t,cc) {
		var r = e.AddComponent(t);
		var mid = msh + "_" + this.m_id;
		var m = haxor.core.Resource.Get(mid);
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
		var is_skinned = js.Boot.__instanceof(r,haxor.component.SkinnedMeshRenderer);
		if(is_skinned) m = new haxor.graphics.mesh.SkinnedMesh3(); else m = new haxor.graphics.mesh.Mesh3();
		m.set_name(mid);
		haxor.core.Resource.Add(mid,m);
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
			l = new haxor.io.file.ColladaLight();
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
			var ca = new haxor.io.file.ColladaAnimation();
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
				var cch = new haxor.io.file.ColladaAnimationChannel();
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
						var kf = new haxor.io.file.ColladaAnimationKeyFrame();
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
				var mat = new haxor.io.file.ColladaMaterial();
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
		this.scene = new haxor.io.file.ColladaVisualScene();
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
		var cn = new haxor.io.file.ColladaNode();
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
				ni = new haxor.io.file.ColladaInstance();
				ni.type = "geometry";
				var _this = this._a(nin,"url","");
				ni.target = HxOverrides.substr(_this,1,null);
				break;
			case "instance_controller":
				ni = new haxor.io.file.ColladaInstance();
				ni.type = "controller";
				var _this1 = this._a(nin,"url","");
				ni.target = HxOverrides.substr(_this1,1,null);
				break;
			case "instance_light":
				ni = new haxor.io.file.ColladaInstance();
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
			c = new haxor.io.file.ColladaController();
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
			img = new haxor.io.file.ColladaImage();
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
			g = new haxor.io.file.ColladaGeometry();
			g.id = this._a(n,"id","none");
			g.name = this._a(n,"name","none");
			this.ParseGeometry(g,n);
			this.geometries.push(g);
		}
	}
	,ParseGeometry: function(g,n) {
		n = n.firstElement();
		if(n == null) return;
		g.mesh = new haxor.io.file.ColladaMesh();
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
			var cp = new haxor.io.file.ColladaPrimitive();
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
			var ci = new haxor.io.file.ColladaInput();
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
			ci.stride = Std["int"](this._p(sn,"technique_common.accessor.@stride","0"));
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
	,__class__: haxor.io.file.ColladaFile
});
haxor.io.file.ColladaAssetData = function() {
	this.axis = "y_up";
	this.unitValue = 0.0;
	this.unitName = "";
	this.modification = "";
	this.creation = "";
	this.source = "";
	this.tool = "";
	this.author = "";
};
$hxClasses["haxor.io.file.ColladaAssetData"] = haxor.io.file.ColladaAssetData;
haxor.io.file.ColladaAssetData.__name__ = ["haxor","io","file","ColladaAssetData"];
haxor.io.file.ColladaAssetData.prototype = {
	__class__: haxor.io.file.ColladaAssetData
};
haxor.io.file.ColladaGeometry = function() {
	this.mesh = null;
	this.name = "";
	this.id = "";
};
$hxClasses["haxor.io.file.ColladaGeometry"] = haxor.io.file.ColladaGeometry;
haxor.io.file.ColladaGeometry.__name__ = ["haxor","io","file","ColladaGeometry"];
haxor.io.file.ColladaGeometry.prototype = {
	__class__: haxor.io.file.ColladaGeometry
};
haxor.io.file.ColladaMesh = function() {
	this.primitives = null;
	this.type = "";
	this.primitives = [];
};
$hxClasses["haxor.io.file.ColladaMesh"] = haxor.io.file.ColladaMesh;
haxor.io.file.ColladaMesh.__name__ = ["haxor","io","file","ColladaMesh"];
haxor.io.file.ColladaMesh.prototype = {
	__class__: haxor.io.file.ColladaMesh
};
haxor.io.file.ColladaPrimitive = function() {
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
$hxClasses["haxor.io.file.ColladaPrimitive"] = haxor.io.file.ColladaPrimitive;
haxor.io.file.ColladaPrimitive.__name__ = ["haxor","io","file","ColladaPrimitive"];
haxor.io.file.ColladaPrimitive.prototype = {
	get_triangles: function() {
		if(this.m_triangles != null) return this.m_triangles;
		this.m_triangles = haxor.io.file.ColladaFile.GenerateTriangles(this.type,this.indexes,this.vcount);
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
	,__class__: haxor.io.file.ColladaPrimitive
};
haxor.io.file.ColladaInput = function() {
	this.stride = 0;
	this.values = null;
	this.set = -1;
	this.offset = 0;
	this.semantic = "";
	this.values = [];
};
$hxClasses["haxor.io.file.ColladaInput"] = haxor.io.file.ColladaInput;
haxor.io.file.ColladaInput.__name__ = ["haxor","io","file","ColladaInput"];
haxor.io.file.ColladaInput.prototype = {
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
				v = new haxor.math.Vector2(this.values[i],this.values[i + 1]);
				break;
			case 3:
				if(this.semantic == "color") v = new haxor.math.Color(this.values[i],this.values[i + 1],this.values[i + 2]); else v = new haxor.math.Vector3(this.values[i],this.values[i + 1],this.values[i + 2]);
				break;
			case 4:
				if(this.semantic == "color") v = new haxor.math.Color(this.values[i],this.values[i + 1],this.values[i + 2],this.values[i + 3]); else v = new haxor.math.Vector4(this.values[i],this.values[i + 1],this.values[i + 2],this.values[i + 3]);
				break;
			}
			if(v == null) continue;
			res.push(v);
			i += this.stride;
		}
		return res;
	}
	,__class__: haxor.io.file.ColladaInput
};
haxor.io.file.ColladaImage = function() {
	this.data = null;
	this.depth = 0;
	this.height = 0;
	this.width = 0;
	this.source = "";
	this.format = "";
	this.name = "";
	this.id = "";
};
$hxClasses["haxor.io.file.ColladaImage"] = haxor.io.file.ColladaImage;
haxor.io.file.ColladaImage.__name__ = ["haxor","io","file","ColladaImage"];
haxor.io.file.ColladaImage.prototype = {
	__class__: haxor.io.file.ColladaImage
};
haxor.io.file.ColladaController = function() {
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
$hxClasses["haxor.io.file.ColladaController"] = haxor.io.file.ColladaController;
haxor.io.file.ColladaController.__name__ = ["haxor","io","file","ColladaController"];
haxor.io.file.ColladaController.prototype = {
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
		var mtx = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
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
			var mtx = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
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
			var wv4 = new haxor.math.Vector4();
			var bv4 = new haxor.math.Vector4();
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
	,__class__: haxor.io.file.ColladaController
};
haxor.io.file.ColladaVisualScene = function() {
	this.children = null;
	this.name = "";
	this.id = "";
	this.type = "";
	this.children = [];
};
$hxClasses["haxor.io.file.ColladaVisualScene"] = haxor.io.file.ColladaVisualScene;
haxor.io.file.ColladaVisualScene.__name__ = ["haxor","io","file","ColladaVisualScene"];
haxor.io.file.ColladaVisualScene.prototype = {
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
	,__class__: haxor.io.file.ColladaVisualScene
};
haxor.io.file.ColladaNode = function() {
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
	this.position = new haxor.math.Vector3(0,0,0);
	this.rotation = new haxor.math.Quaternion(0,0,0,1.0);
	this.scale = new haxor.math.Vector3(1,1,1);
};
$hxClasses["haxor.io.file.ColladaNode"] = haxor.io.file.ColladaNode;
haxor.io.file.ColladaNode.__name__ = ["haxor","io","file","ColladaNode"];
haxor.io.file.ColladaNode.prototype = {
	get_world: function() {
		if(this.m_world != null) return this.m_world;
		this.m_world = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
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
		var mtx = this.local = haxor.math.Matrix4.FromArray(this.matrix);
		this.position = new haxor.math.Matrix4(1,0,0,mtx.m03,0,1,0,mtx.m13,0,0,1,mtx.m23,0,0,0,1).GetColumn(3,null).get_xyz();
		this.rotation = haxor.math.Quaternion.FromMatrix(haxor.context.EngineContext.data.get_m4().SetMatrix4(mtx).ToRotation());
		this.scale = mtx.get_scale().get_diagonalLR().get_xyz();
	}
	,__class__: haxor.io.file.ColladaNode
};
haxor.io.file.ColladaInstance = function() {
	this.target = "";
	this.type = "";
	this.materials = [];
};
$hxClasses["haxor.io.file.ColladaInstance"] = haxor.io.file.ColladaInstance;
haxor.io.file.ColladaInstance.__name__ = ["haxor","io","file","ColladaInstance"];
haxor.io.file.ColladaInstance.prototype = {
	__class__: haxor.io.file.ColladaInstance
};
haxor.io.file.ColladaMaterial = function() {
	this.name = "";
	this.id = "";
};
$hxClasses["haxor.io.file.ColladaMaterial"] = haxor.io.file.ColladaMaterial;
haxor.io.file.ColladaMaterial.__name__ = ["haxor","io","file","ColladaMaterial"];
haxor.io.file.ColladaMaterial.prototype = {
	__class__: haxor.io.file.ColladaMaterial
};
haxor.io.file.ColladaAnimation = function() {
	this.name = "";
	this.id = "";
	this.channels = [];
};
$hxClasses["haxor.io.file.ColladaAnimation"] = haxor.io.file.ColladaAnimation;
haxor.io.file.ColladaAnimation.__name__ = ["haxor","io","file","ColladaAnimation"];
haxor.io.file.ColladaAnimation.prototype = {
	__class__: haxor.io.file.ColladaAnimation
};
haxor.io.file.ColladaAnimationChannel = function() {
	this.target = "";
	this.source = "";
	this.keyframes = [];
};
$hxClasses["haxor.io.file.ColladaAnimationChannel"] = haxor.io.file.ColladaAnimationChannel;
haxor.io.file.ColladaAnimationChannel.__name__ = ["haxor","io","file","ColladaAnimationChannel"];
haxor.io.file.ColladaAnimationChannel.prototype = {
	__class__: haxor.io.file.ColladaAnimationChannel
};
haxor.io.file.ColladaAnimationKeyFrame = function() {
	this.time = 0.0;
	this.values = [];
};
$hxClasses["haxor.io.file.ColladaAnimationKeyFrame"] = haxor.io.file.ColladaAnimationKeyFrame;
haxor.io.file.ColladaAnimationKeyFrame.__name__ = ["haxor","io","file","ColladaAnimationKeyFrame"];
haxor.io.file.ColladaAnimationKeyFrame.prototype = {
	__class__: haxor.io.file.ColladaAnimationKeyFrame
};
haxor.io.file.ColladaLight = function() {
	this.id = "";
	this.name = "";
	this.type = "";
	this.color = new haxor.math.Color(1,1,1,1);
	this.radius = 0.0;
	this.intensity = 0.0;
	this.atten = 0.0;
};
$hxClasses["haxor.io.file.ColladaLight"] = haxor.io.file.ColladaLight;
haxor.io.file.ColladaLight.__name__ = ["haxor","io","file","ColladaLight"];
haxor.io.file.ColladaLight.prototype = {
	__class__: haxor.io.file.ColladaLight
};
haxor.math.AABB3 = function(p_x,p_y,p_z,p_width,p_height,p_depth) {
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
$hxClasses["haxor.math.AABB3"] = haxor.math.AABB3;
haxor.math.AABB3.__name__ = ["haxor","math","AABB3"];
haxor.math.AABB3.get_temp = function() {
	return haxor.context.EngineContext.data.get_aabb3();
};
haxor.math.AABB3.FromMinMax = function(p_xmin,p_xmax,p_ymin,p_ymax,p_zmin,p_zmax) {
	var b = new haxor.math.AABB3();
	b.set_xMin(p_xmin);
	b.set_xMax(p_xmax);
	b.set_yMin(p_ymin);
	b.set_yMax(p_ymax);
	b.set_zMin(p_zmin);
	b.set_zMax(p_zmax);
	return b;
};
haxor.math.AABB3.FromCenter = function(p_x,p_y,p_z,p_width,p_height,p_depth) {
	var b = new haxor.math.AABB3();
	b.set_xMax(b.m_xMin + p_width);
	p_width;
	b.set_yMax(b.m_yMin + p_height);
	p_height;
	b.set_zMax(b.m_zMin + p_depth);
	p_depth;
	b.set_center(new haxor.math.Vector3(p_x,p_y,p_z));
	return b;
};
haxor.math.AABB3.get_empty = function() {
	return new haxor.math.AABB3();
};
haxor.math.AABB3.prototype = {
	get_clone: function() {
		return haxor.math.AABB3.FromMinMax(this.m_xMin,this.m_xMax,this.m_yMin,this.m_yMax,this.m_zMin,this.m_zMax);
	}
	,get_min: function() {
		return new haxor.math.Vector3(this.m_xMin,this.m_yMin);
	}
	,set_min: function(v) {
		this.set_xMin(v.x);
		this.set_yMin(v.y);
		return v;
	}
	,get_max: function() {
		return new haxor.math.Vector3(this.m_xMax,this.m_yMax);
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
		return new haxor.math.Vector3(0,0,0).Set(this.m_xMin + (this.m_xMax - this.m_xMin) * 0.5,this.m_yMin + (this.m_yMax - this.m_yMin) * 0.5,this.m_zMin + (this.m_zMax - this.m_zMin) * 0.5);
	}
	,set_center: function(v) {
		var hw = haxor.math.Mathf.Abs(this.m_xMax - this.m_xMin) * 0.5;
		var hh = haxor.math.Mathf.Abs(this.m_yMax - this.m_yMin) * 0.5;
		var hd = haxor.math.Mathf.Abs(this.m_zMax - this.m_zMin) * 0.5;
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
		return haxor.math.Mathf.Abs(this.m_xMax - this.m_xMin);
	}
	,set_width: function(v) {
		this.set_xMax(this.m_xMin + v);
		return v;
	}
	,get_height: function() {
		return haxor.math.Mathf.Abs(this.m_yMax - this.m_yMin);
	}
	,set_height: function(v) {
		this.set_yMax(this.m_yMin + v);
		return v;
	}
	,get_depth: function() {
		return haxor.math.Mathf.Abs(this.m_zMax - this.m_zMin);
	}
	,set_depth: function(v) {
		this.set_zMax(this.m_zMin + v);
		return v;
	}
	,get_size: function() {
		return new haxor.math.Vector3(0,0,0).Set(haxor.math.Mathf.Abs(this.m_xMax - this.m_xMin),haxor.math.Mathf.Abs(this.m_yMax - this.m_yMin),haxor.math.Mathf.Abs(this.m_zMax - this.m_zMin));
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
		var s0 = haxor.math.Mathf.RoundPlaces(this.m_xMin,p_places) + "";
		var s1 = haxor.math.Mathf.RoundPlaces(this.m_xMax,p_places) + "";
		var s2 = haxor.math.Mathf.RoundPlaces(this.m_yMin,p_places) + "";
		var s3 = haxor.math.Mathf.RoundPlaces(this.m_yMax,p_places) + "";
		var s4 = haxor.math.Mathf.RoundPlaces(this.m_zMin,p_places) + "";
		var s5 = haxor.math.Mathf.RoundPlaces(this.m_zMax,p_places) + "";
		return "[" + s0 + "," + s1 + "|" + s2 + "," + s3 + "|" + s4 + "," + s5 + "]";
	}
	,__class__: haxor.math.AABB3
};
haxor.math.Mathf = function() { };
$hxClasses["haxor.math.Mathf"] = haxor.math.Mathf;
haxor.math.Mathf.__name__ = ["haxor","math","Mathf"];
haxor.math.Mathf.IsPOT = function(p_v) {
	return p_v > 0 && (p_v & p_v - 1) == 0;
};
haxor.math.Mathf.NextPOT = function(p_v) {
	--p_v;
	p_v |= p_v >> 1;
	p_v |= p_v >> 2;
	p_v |= p_v >> 4;
	p_v |= p_v >> 8;
	p_v |= p_v >> 16;
	return ++p_v;
};
haxor.math.Mathf.Sign = function(p_a) {
	if(p_a < 0) return -1.0; else return 1.0;
};
haxor.math.Mathf.SignInt = function(p_a) {
	if(p_a < 0) return -1; else return 1;
};
haxor.math.Mathf.Abs = function(p_a) {
	if(p_a < 0) return -p_a; else return p_a;
};
haxor.math.Mathf.AbsInt = function(p_a) {
	if(p_a < 0) return -p_a; else return p_a;
};
haxor.math.Mathf.Clamp = function(p_v,p_min,p_max) {
	if(p_v <= p_min) return p_min; else if(p_v >= p_max) return p_max; else return p_v;
};
haxor.math.Mathf.Clamp01 = function(p_v) {
	if(p_v <= 0.0) return 0.0; else if(p_v >= 1.0) return 1.0; else return p_v;
};
haxor.math.Mathf.ClampInt = function(p_v,p_min,p_max) {
	return (p_v <= p_min?p_min:p_v >= p_max?p_max:p_v) | 0;
};
haxor.math.Mathf.Min = function(a,b) {
	return Math.min(a,b);
};
haxor.math.Mathf.MinRange = function(v) {
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
haxor.math.Mathf.Max = function(a,b) {
	return Math.max(a,b);
};
haxor.math.Mathf.MaxRange = function(v) {
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
haxor.math.Mathf.MinInt = function(a,b) {
	return Math.min(a,b);
};
haxor.math.Mathf.MaxInt = function(a,b) {
	return Math.max(a,b);
};
haxor.math.Mathf.Sin = function(v) {
	return Math.sin(v);
};
haxor.math.Mathf.Cos = function(v) {
	return Math.cos(v);
};
haxor.math.Mathf.ASin = function(v) {
	return Math.asin(v);
};
haxor.math.Mathf.ACos = function(v) {
	return Math.acos(v);
};
haxor.math.Mathf.Tan = function(v) {
	return Math.tan(v);
};
haxor.math.Mathf.ATan = function(v) {
	return Math.atan(v);
};
haxor.math.Mathf.ATan2 = function(y,x) {
	return Math.atan2(y,x);
};
haxor.math.Mathf.Sqrt = function(v) {
	return Math.sqrt(v);
};
haxor.math.Mathf.Pow = function(b,exp) {
	return Math.pow(b,exp);
};
haxor.math.Mathf.Floor = function(p_v) {
	return p_v | 0;
};
haxor.math.Mathf.Ceil = function(p_v) {
	return p_v + (p_v < 0?-0.9999999:0.9999999) | 0;
};
haxor.math.Mathf.Round = function(p_v) {
	return p_v + (p_v < 0?-0.5:0.5) | 0;
};
haxor.math.Mathf.RoundPlaces = function(p_v,p_decimal_places) {
	if(p_decimal_places == null) p_decimal_places = 2;
	var d = Math.pow(10,p_decimal_places);
	return haxor.math.Mathf.Round(p_v * d) / d;
};
haxor.math.Mathf.Lerp = function(p_a,p_b,p_ratio) {
	return p_a + (p_b - p_a) * p_ratio;
};
haxor.math.Mathf.LerpInt = function(p_a,p_b,p_ratio) {
	return Std["int"](haxor.math.Mathf.Lerp(p_a,p_b,p_ratio));
};
haxor.math.Mathf.Frac = function(p_v) {
	return p_v - Math.floor(p_v);
};
haxor.math.Mathf.Loop = function(p_v,p_v0,p_v1) {
	var vv0 = Math.min(p_v0,p_v1);
	var vv1 = Math.max(p_v0,p_v1);
	var dv = vv1 - vv0;
	if(dv <= 0) return vv0;
	var n = (p_v - p_v0) / dv;
	var r;
	if(p_v < 0) r = 1.0 - haxor.math.Mathf.Frac(n < 0?-n:n); else r = n - Math.floor(n);
	return p_v0 + (p_v1 - p_v0) * r;
};
haxor.math.Mathf.Linear2Gamma = function(p_v) {
	return Math.pow(p_v,2.2);
};
haxor.math.Mathf.Oscilate = function(p_v,p_v0,p_v1) {
	var w = -haxor.math.Mathf.Abs(haxor.math.Mathf.Loop(p_v - 1.0,-1.0,1.0)) + 1.0;
	return w + (p_v0 - w) * p_v1;
};
haxor.math.Mathf.WrapAngle = function(p_angle) {
	if(p_angle < 360.0) {
		if(p_angle > -360.0) return p_angle;
	}
	return haxor.math.Mathf.Frac((p_angle < 0?-p_angle:p_angle) / 360.0) * 360.0;
};
haxor.math.Matrix4 = function(p_m00,p_m01,p_m02,p_m03,p_m10,p_m11,p_m12,p_m13,p_m20,p_m21,p_m22,p_m23,p_m30,p_m31,p_m32,p_m33) {
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
$hxClasses["haxor.math.Matrix4"] = haxor.math.Matrix4;
haxor.math.Matrix4.__name__ = ["haxor","math","Matrix4"];
haxor.math.Matrix4.get_temp = function() {
	return haxor.context.EngineContext.data.get_m4();
};
haxor.math.Matrix4.get_identity = function() {
	return new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
};
haxor.math.Matrix4.FromQuaternion = function(p_quaternion,p_result) {
	var m;
	if(p_result == null) m = new haxor.math.Matrix4(); else m = p_result;
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
haxor.math.Matrix4.FromArray = function(p_array,p_result) {
	var res;
	if(p_result == null) res = new haxor.math.Matrix4(); else res = p_result;
	var _g1 = 0;
	var _g = p_array.length;
	while(_g1 < _g) {
		var i = _g1++;
		res.SetIndex(i,p_array[i]);
	}
	return res;
};
haxor.math.Matrix4.TRS = function(p_position,p_rotation,p_scale,p_result) {
	var sx;
	if(p_scale == null) sx = 1.0; else sx = p_scale.x;
	var sy;
	if(p_scale == null) sy = 1.0; else sy = p_scale.y;
	var sz;
	if(p_scale == null) sz = 1.0; else sz = p_scale.z;
	var px = p_position.x;
	var py = p_position.y;
	var pz = p_position.z;
	var r = haxor.context.EngineContext.data.get_m4();
	haxor.math.Matrix4.FromQuaternion(p_rotation,r);
	var l;
	if(p_result == null) l = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1); else l = p_result;
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
haxor.math.Matrix4.Frustum = function(p_left,p_right,p_top,p_bottom,p_near,p_far,p_result) {
	var m;
	if(p_result == null) m = new haxor.math.Matrix4(); else m = p_result;
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
haxor.math.Matrix4.FrustumInverse = function(p_left,p_right,p_top,p_bottom,p_near,p_far,p_result) {
	var m;
	if(p_result == null) m = new haxor.math.Matrix4(); else m = p_result;
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
haxor.math.Matrix4.Ortho = function(p_left,p_right,p_top,p_bottom,p_near,p_far,p_result) {
	var m;
	if(p_result == null) m = new haxor.math.Matrix4(); else m = p_result;
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
haxor.math.Matrix4.OrthoInverse = function(p_left,p_right,p_top,p_bottom,p_near,p_far,p_result) {
	var m = haxor.context.EngineContext.data.get_m4().SetOrtho(p_left,p_right,p_top,p_bottom,p_near,p_far);
	return haxor.math.Matrix4.GetInverseTransform(m,p_result);
};
haxor.math.Matrix4.Perspective = function(p_fov,p_aspect,p_near,p_far,p_result) {
	var t = Math.tan(p_fov * 0.5 * 0.01745329251994329576923690768489) * p_near;
	var b = -t;
	var l = p_aspect * b;
	var r = p_aspect * t;
	return haxor.math.Matrix4.Frustum(l,r,t,b,p_near,p_far,p_result);
};
haxor.math.Matrix4.PerspectiveInverse = function(p_fov,p_aspect,p_near,p_far,p_result) {
	var t = Math.tan(p_fov * 0.5 * 0.01745329251994329576923690768489) * p_near;
	var b = -t;
	var l = p_aspect * b;
	var r = p_aspect * t;
	return haxor.math.Matrix4.FrustumInverse(l,r,t,b,p_near,p_far,p_result);
};
haxor.math.Matrix4.GetRotation = function(p_matrix4,p_result) {
	var m;
	if(p_result == null) m = new haxor.math.Matrix4(); else m = p_result;
	var tmp = haxor.context.EngineContext.data.get_v3();
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
haxor.math.Matrix4.GetInverseTransform = function(p_matrix,p_result) {
	var result;
	if(p_result == null) result = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1); else result = p_result;
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
haxor.math.Matrix4.LookRotation = function(p_forward,p_up,p_result) {
	return haxor.math.Matrix4.LookAt(haxor.context.EngineContext.data.get_v3().Set(0,0,0),p_forward,p_up,p_result);
};
haxor.math.Matrix4.LookAt = function(p_eye,p_at,p_up,p_result) {
	if(p_result == null) p_result = new haxor.math.Matrix4(); else p_result = p_result;
	if(p_up == null) p_up = haxor.context.EngineContext.data.get_v3().Set(0,1,0); else p_up = p_up;
	var at = haxor.context.EngineContext.data.get_v3().Set3(p_at);
	var vz = at.Sub(p_eye).Normalize();
	var vx = haxor.context.EngineContext.data.get_v3();
	var vy = haxor.context.EngineContext.data.get_v3();
	haxor.math.Vector3.Cross(vz,p_up,vx).Normalize();
	haxor.math.Vector3.Cross(vx,vz,vy);
	return p_result.Set(vx.x,vy.x,vz.x,-(vx.x * p_eye.x + vx.y * p_eye.y + vx.z * p_eye.z),vx.y,vy.y,vz.y,-(vy.x * p_eye.x + vy.y * p_eye.y + vy.z * p_eye.z),vx.z,vy.z,vz.z,-(vz.x * p_eye.x + vz.y * p_eye.y + vz.z * p_eye.z),0,0,0,1);
};
haxor.math.Matrix4.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	var res = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	var _g1 = 0;
	var _g = tk.length;
	while(_g1 < _g) {
		var i = _g1++;
		var n = Std.parseFloat(StringTools.trim(tk[i]));
		res.SetIndex(i,n);
	}
	return res;
};
haxor.math.Matrix4.prototype = {
	get_clone: function() {
		return new haxor.math.Matrix4(this.m00,this.m01,this.m02,this.m03,this.m10,this.m11,this.m12,this.m13,this.m20,this.m21,this.m22,this.m23,this.m30,this.m31,this.m32,this.m33);
	}
	,get_quaternion: function() {
		return haxor.math.Quaternion.FromMatrix(haxor.context.EngineContext.data.get_m4().SetMatrix4(this).ToRotation());
	}
	,set_quaternion: function(v) {
		haxor.math.Matrix4.FromQuaternion(v,this);
		return v;
	}
	,get_trace: function() {
		return this.m00 + this.m11 + this.m22 + this.m33;
	}
	,get_rotation: function() {
		return new haxor.math.Matrix4(this.m00,this.m01,this.m02,this.m03,this.m10,this.m11,this.m12,this.m13,this.m20,this.m21,this.m22,this.m23,this.m30,this.m31,this.m32,this.m33).ToRotation();
	}
	,get_scale: function() {
		var d0 = Math.sqrt(this.m00 * this.m00 + this.m10 * this.m10 + this.m20 * this.m20);
		var d1 = Math.sqrt(this.m01 * this.m01 + this.m11 * this.m11 + this.m21 * this.m21);
		var d2 = Math.sqrt(this.m02 * this.m02 + this.m12 * this.m12 + this.m22 * this.m22);
		return new haxor.math.Matrix4(d0,0,0,0,0,d1,0,0,0,0,d2,0,0,0,0,1);
	}
	,get_translation: function() {
		return new haxor.math.Matrix4(1,0,0,this.m03,0,1,0,this.m13,0,0,1,this.m23,0,0,0,1);
	}
	,get_inverseTransform: function() {
		var result = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		var l0 = new haxor.math.Vector3(this.m00,this.m01,this.m02);
		var l1 = new haxor.math.Vector3(this.m10,this.m11,this.m12);
		var l2 = new haxor.math.Vector3(this.m20,this.m21,this.m22);
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
		return new haxor.math.Matrix4(this.m00,this.m10,this.m20,this.m30,this.m01,this.m11,this.m21,this.m31,this.m02,this.m12,this.m22,this.m32,this.m03,this.m13,this.m23,this.m33);
	}
	,ToRowMajor: function() {
		return [this.m00,this.m01,this.m02,this.m03,this.m10,this.m11,this.m12,this.m13,this.m20,this.m21,this.m22,this.m23,this.m30,this.m31,this.m32,this.m33];
	}
	,ToColumnMajor: function() {
		return [this.m00,this.m10,this.m20,this.m30,this.m01,this.m11,this.m21,this.m31,this.m02,this.m12,this.m22,this.m32,this.m03,this.m13,this.m23,this.m33];
	}
	,GetLine: function(p_index,p_result) {
		if(p_result == null) p_result = new haxor.math.Vector4(); else p_result = p_result;
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
		if(p_result == null) p_result = new haxor.math.Vector4(); else p_result = p_result;
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
		return new haxor.math.Vector4(this.m00,this.m11,this.m22,this.m33);
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
		var tmp = haxor.context.EngineContext.data.get_v3();
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
		var tmp = haxor.context.EngineContext.data.get_v3();
		tmp.Set(this.m00,this.m01,this.m02).Normalize();
		p_vector.x = tmp.x * p_vector.x + tmp.y * p_vector.y + tmp.z * p_vector.z;
		tmp.Set(this.m10,this.m11,this.m12).Normalize();
		p_vector.y = tmp.x * p_vector.x + tmp.y * p_vector.y + tmp.z * p_vector.z;
		tmp.Set(this.m20,this.m21,this.m22).Normalize();
		p_vector.z = tmp.x * p_vector.x + tmp.y * p_vector.y + tmp.z * p_vector.z;
		return p_vector;
	}
	,SetTRS: function(p_position,p_rotation,p_scale) {
		return haxor.math.Matrix4.TRS(p_position,p_rotation,p_scale,this);
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
		return haxor.math.Matrix4.LookAt(p_eye,p_at,p_up,this);
	}
	,SetFrustum: function(p_left,p_right,p_top,p_bottom,p_near,p_far) {
		return haxor.math.Matrix4.Frustum(p_left,p_right,p_top,p_bottom,p_near,p_far,this);
	}
	,SetFrustumInverse: function(p_left,p_right,p_top,p_bottom,p_near,p_far) {
		return haxor.math.Matrix4.FrustumInverse(p_left,p_right,p_top,p_bottom,p_near,p_far,this);
	}
	,SetOrtho: function(p_left,p_right,p_top,p_bottom,p_near,p_far) {
		return haxor.math.Matrix4.Ortho(p_left,p_right,p_top,p_bottom,p_near,p_far,this);
	}
	,SetPerspective: function(p_fov,p_aspect,p_near,p_far) {
		return haxor.math.Matrix4.Perspective(p_fov,p_aspect,p_near,p_far,this);
	}
	,SetPerspectiveInverse: function(p_fov,p_aspect,p_near,p_far) {
		return haxor.math.Matrix4.PerspectiveInverse(p_fov,p_aspect,p_near,p_far,this);
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
			a[i] = haxor.math.Mathf.RoundPlaces(a[i],p_places);
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
	,__class__: haxor.math.Matrix4
};
haxor.math.Quaternion = function(p_x,p_y,p_z,p_w) {
	if(p_w == null) p_w = 1.0;
	if(p_z == null) p_z = 0;
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.x = p_x;
	this.y = p_y;
	this.z = p_z;
	this.w = p_w;
};
$hxClasses["haxor.math.Quaternion"] = haxor.math.Quaternion;
haxor.math.Quaternion.__name__ = ["haxor","math","Quaternion"];
haxor.math.Quaternion.get_temp = function() {
	return haxor.context.EngineContext.data.get_q();
};
haxor.math.Quaternion.get_identity = function() {
	return new haxor.math.Quaternion(0,0,0,1.0);
};
haxor.math.Quaternion.FromEuler = function(p_euler,p_result) {
	var r;
	if(p_result == null) r = new haxor.math.Quaternion(); else r = p_result;
	var c = haxor.context.EngineContext.data.get_v3();
	var s = haxor.context.EngineContext.data.get_v3();
	var k = 0.0087266462599716477;
	var e = haxor.context.EngineContext.data.get_v3().Set(p_euler.x * k,p_euler.y * k,p_euler.z * k);
	c.Set(Math.cos(e.x),Math.cos(e.y),Math.cos(e.z));
	s.Set(Math.sin(e.x),Math.sin(e.y),Math.sin(e.z));
	r.x = s.x * c.y * c.z - c.x * s.y * s.z;
	r.y = c.x * s.y * c.z + s.x * c.y * s.z;
	r.z = c.x * c.y * s.z - s.x * s.y * c.z;
	r.w = c.x * c.y * c.z + s.x * s.y * s.z;
	return r;
};
haxor.math.Quaternion.ToEuler = function(p_quaternion,p_result) {
	var q = p_quaternion;
	var r;
	if(p_result == null) r = new haxor.math.Vector3(); else r = p_result;
	return r.Set(Math.atan2(2.0 * (q.y * q.z + q.w * q.x),q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z) * 57.295779513082320876798154814105,Math.asin(-2. * (q.x * q.z - q.w * q.y)) * 57.295779513082320876798154814105,Math.atan2(2.0 * (q.x * q.y + q.w * q.z),q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z) * 57.295779513082320876798154814105);
};
haxor.math.Quaternion.FromMatrix = function(p_matrix,p_result) {
	var r;
	if(p_result == null) r = new haxor.math.Quaternion(); else r = p_result;
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
haxor.math.Quaternion.Dot = function(p_a,p_b) {
	return p_a.x * p_b.x + p_a.y * p_b.y + p_a.z * p_b.z + p_a.w * p_b.w;
};
haxor.math.Quaternion.DeltaRotation = function(p_a,p_b,p_result) {
	var r;
	if(p_result == null) r = new haxor.math.Quaternion(); else r = p_result;
	haxor.math.Quaternion.Inverse(p_a,r);
	r.Multiply(p_b);
	return r;
};
haxor.math.Quaternion.Inverse = function(p_q,p_result) {
	var d = 1.0 / (p_q.x * p_q.x + p_q.y * p_q.y + p_q.z * p_q.z + p_q.w * p_q.w);
	var r;
	if(p_result == null) r = new haxor.math.Quaternion(); else r = p_result;
	return r.Set(-p_q.x * d,-p_q.y * d,-p_q.z * d,p_q.w * d);
};
haxor.math.Quaternion.Lerp = function(p_a,p_b,p_ratio,p_result) {
	var c;
	if(p_result == null) c = new haxor.math.Quaternion(); else c = p_result;
	var ca = new haxor.math.Quaternion(p_a.x,p_a.y,p_a.z,p_a.w);
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
haxor.math.Quaternion.Slerp = function(p_a,p_b,p_ratio) {
	var qm = new haxor.math.Quaternion();
	var z = haxor.context.EngineContext.data.get_q().SetQuaternion(p_b);
	var cosTheta = p_a.x * p_b.x + p_a.y * p_b.y + p_a.z * p_b.z + p_a.w * p_b.w;
	if(cosTheta < 0.0) {
		z.Invert();
		cosTheta = -cosTheta;
	}
	if(cosTheta > 0.9999) qm.Set(haxor.math.Mathf.Lerp(p_a.x,z.x,p_ratio),haxor.math.Mathf.Lerp(p_a.y,z.y,p_ratio),haxor.math.Mathf.Lerp(p_a.z,z.z,p_ratio),haxor.math.Mathf.Lerp(p_a.w,z.w,p_ratio)); else {
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
haxor.math.Quaternion.FromAxisAngle = function(p_axis,p_angle) {
	p_angle = p_angle * 0.5 * 0.01745329251994329576923690768489;
	var l = Math.sqrt(p_axis.x * p_axis.x + p_axis.y * p_axis.y + p_axis.z * p_axis.z);
	if(haxor.math.Mathf.Abs(l - 1.0) > 0.0001) p_axis.Normalize();
	var s = Math.sin(p_angle);
	return new haxor.math.Quaternion(p_axis.x * s,p_axis.y * s,p_axis.z * s,Math.cos(p_angle));
};
haxor.math.Quaternion.LookAt = function(p_from,p_at,p_up,p_result) {
	return haxor.math.Quaternion.FromMatrix(haxor.math.Matrix4.LookAt(p_from,p_at,p_up,haxor.context.EngineContext.data.get_m4()),p_result);
};
haxor.math.Quaternion.LookRotation = function(p_forward,p_up) {
	return haxor.math.Matrix4.LookRotation(p_forward,p_up,haxor.context.EngineContext.data.get_m4()).get_quaternion();
};
haxor.math.Quaternion.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	return new haxor.math.Quaternion(0,0,0,1.0).Set(Std.parseFloat(StringTools.trim(tk[0])),Std.parseFloat(StringTools.trim(tk[1])),Std.parseFloat(StringTools.trim(tk[2])),Std.parseFloat(StringTools.trim(tk[3])));
};
haxor.math.Quaternion.prototype = {
	get_matrix: function() {
		return haxor.math.Matrix4.FromQuaternion(this);
	}
	,set_matrix: function(v) {
		haxor.math.Quaternion.FromMatrix(v,this);
		return v;
	}
	,get_euler: function() {
		return haxor.math.Quaternion.ToEuler(this);
	}
	,set_euler: function(v) {
		haxor.math.Quaternion.FromEuler(v,this);
		return v;
	}
	,get_clone: function() {
		return new haxor.math.Quaternion(this.x,this.y,this.z,this.w);
	}
	,get_xyzw: function() {
		return new haxor.math.Vector4(this.x,this.y,this.z,this.w);
	}
	,get_length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
	}
	,get_normalized: function() {
		return new haxor.math.Quaternion(this.x,this.y,this.z,this.w).Normalize();
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
		return new haxor.math.Quaternion(-this.x,-this.y,-this.z,this.w);
	}
	,get_inverse: function() {
		return haxor.math.Quaternion.Inverse(this);
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
	,Rotate: function(p_v) {
		var l = Math.sqrt(p_v.x * p_v.x + p_v.y * p_v.y + p_v.z * p_v.z);
		var nl;
		if(l <= 0.0) nl = 0.0; else nl = 1.0 / l;
		p_v.x *= nl;
		p_v.y *= nl;
		p_v.z *= nl;
		var qv = haxor.context.EngineContext.data.get_q().Set(p_v.x,p_v.y,p_v.z,0);
		var a = haxor.context.EngineContext.data.get_q().SetQuaternion(this);
		var c = haxor.context.EngineContext.data.get_q().Set(-this.x,-this.y,-this.z,this.w);
		a.Multiply(qv.Multiply(c));
		p_v.x = a.x * l;
		p_v.y = a.y * l;
		p_v.z = a.z * l;
		return p_v;
	}
	,Delta: function(p_q) {
		return this.SetQuaternion(haxor.math.Quaternion.DeltaRotation(this,p_q,haxor.context.EngineContext.data.get_q()));
	}
	,SetAxisAngle: function(p_axis,p_angle) {
		p_angle = p_angle * 0.5 * 0.01745329251994329576923690768489;
		var l = Math.sqrt(p_axis.x * p_axis.x + p_axis.y * p_axis.y + p_axis.z * p_axis.z);
		if(haxor.math.Mathf.Abs(l - 1.0) > 0.0001) p_axis.Normalize();
		var s = Math.sin(p_angle);
		return this.Set(p_axis.x * s,p_axis.y * s,p_axis.z * s,Math.cos(p_angle));
	}
	,ToArray: function() {
		return [this.x,this.y,this.z,this.w];
	}
	,ToString: function(p_places) {
		if(p_places == null) p_places = 2;
		return "[" + haxor.math.Mathf.RoundPlaces(this.x,p_places) + "," + haxor.math.Mathf.RoundPlaces(this.y,p_places) + "," + haxor.math.Mathf.RoundPlaces(this.z,p_places) + "," + haxor.math.Mathf.RoundPlaces(this.w,p_places) + "]";
	}
	,__class__: haxor.math.Quaternion
};
haxor.math.Random = function() { };
$hxClasses["haxor.math.Random"] = haxor.math.Random;
haxor.math.Random.__name__ = ["haxor","math","Random"];
haxor.math.Random.get_value = function() {
	return Math.random();
};
haxor.math.Random.get_interval = function() {
	return (Math.random() - 0.499995) * 2.0;
};
haxor.math.Random.get_rotation = function() {
	return haxor.math.Quaternion.FromAxisAngle(new haxor.math.Vector3((Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0).Normalize().Scale(Math.random()),(Math.random() - 0.499995) * 2.0 * 180.0);
};
haxor.math.Random.get_box = function() {
	return new haxor.math.Vector3((Math.random() - 0.499995) * 2.0 * 0.5,(Math.random() - 0.499995) * 2.0 * 0.5,(Math.random() - 0.499995) * 2.0 * 0.5);
};
haxor.math.Random.get_onBox = function() {
	var p = new haxor.math.Vector3((Math.random() - 0.499995) * 2.0 * 0.5,(Math.random() - 0.499995) * 2.0 * 0.5,(Math.random() - 0.499995) * 2.0 * 0.5);
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
haxor.math.Random.get_square = function() {
	return new haxor.math.Vector2((Math.random() - 0.499995) * 2.0 * 0.5,(Math.random() - 0.499995) * 2.0 * 0.5);
};
haxor.math.Random.get_onSquare = function() {
	var p = new haxor.math.Vector2((Math.random() - 0.499995) * 2.0 * 0.5,(Math.random() - 0.499995) * 2.0 * 0.5);
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
haxor.math.Random.get_sphere = function() {
	return new haxor.math.Vector3((Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0).Normalize().Scale(Math.random());
};
haxor.math.Random.get_onSphere = function() {
	return new haxor.math.Vector3((Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0).Normalize();
};
haxor.math.Random.get_circle = function() {
	return new haxor.math.Vector2((Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0).Normalize().Scale(Math.random());
};
haxor.math.Random.get_onCircle = function() {
	return new haxor.math.Vector2((Math.random() - 0.499995) * 2.0,(Math.random() - 0.499995) * 2.0).Normalize();
};
haxor.math.Random.Length = function(v) {
	return (v + 1) * Math.random();
};
haxor.math.Random.Range = function(p_min,p_max) {
	return haxor.math.Mathf.Lerp(p_min,p_max,Math.random());
};
haxor.math.Random.RangeInt = function(p_min,p_max) {
	return haxor.math.Mathf.LerpInt(p_min,p_max + 1,Math.random());
};
haxor.math.Random.Item = function(p_list) {
	return p_list[p_list.length * Math.random()];
};
haxor.math.Random.Shuffle = function(p_list) {
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
haxor.math.Vector2 = function(p_x,p_y) {
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.x = p_x;
	this.y = p_y;
};
$hxClasses["haxor.math.Vector2"] = haxor.math.Vector2;
haxor.math.Vector2.__name__ = ["haxor","math","Vector2"];
haxor.math.Vector2.get_temp = function() {
	return haxor.context.EngineContext.data.get_v2();
};
haxor.math.Vector2.get_zero = function() {
	return new haxor.math.Vector2(0,0);
};
haxor.math.Vector2.get_one = function() {
	return new haxor.math.Vector2(1,1);
};
haxor.math.Vector2.get_right = function() {
	return new haxor.math.Vector2(1,0);
};
haxor.math.Vector2.get_up = function() {
	return new haxor.math.Vector2(0,1);
};
haxor.math.Vector2.Dot = function(p_a,p_b) {
	return p_a.x * p_b.x + p_a.y * p_b.y;
};
haxor.math.Vector2.Lerp = function(p_a,p_b,p_r) {
	return new haxor.math.Vector2(p_a.x + (p_b.x - p_a.x) * p_r,p_a.y + (p_b.y - p_a.y) * p_r);
};
haxor.math.Vector2.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	return new haxor.math.Vector2(0,0).Set(Std.parseFloat(StringTools.trim(tk[0])),Std.parseFloat(StringTools.trim(tk[1])));
};
haxor.math.Vector2.prototype = {
	get_clone: function() {
		return new haxor.math.Vector2(this.x,this.y);
	}
	,get_xy: function() {
		return new haxor.math.Vector2(this.x,this.y);
	}
	,get_yx: function() {
		return new haxor.math.Vector2(this.y,this.x);
	}
	,get_length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y);
	}
	,get_lengthSqr: function() {
		return this.x * this.x + this.y * this.y;
	}
	,get_normalized: function() {
		return new haxor.math.Vector2(this.x,this.y).Normalize();
	}
	,get_inverse: function() {
		return new haxor.math.Vector2(this.x,this.y).Invert();
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
		return "[" + haxor.math.Mathf.RoundPlaces(this.x,p_places) + "," + haxor.math.Mathf.RoundPlaces(this.y,p_places) + "]";
	}
	,__class__: haxor.math.Vector2
};
haxor.math.Vector3 = function(p_x,p_y,p_z) {
	if(p_z == null) p_z = 0;
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.x = p_x;
	this.y = p_y;
	this.z = p_z;
};
$hxClasses["haxor.math.Vector3"] = haxor.math.Vector3;
haxor.math.Vector3.__name__ = ["haxor","math","Vector3"];
haxor.math.Vector3.get_temp = function() {
	return haxor.context.EngineContext.data.get_v3();
};
haxor.math.Vector3.get_zero = function() {
	return new haxor.math.Vector3(0,0,0);
};
haxor.math.Vector3.get_one = function() {
	return new haxor.math.Vector3(1,1,1);
};
haxor.math.Vector3.get_right = function() {
	return new haxor.math.Vector3(1,0,0);
};
haxor.math.Vector3.get_up = function() {
	return new haxor.math.Vector3(0,1,0);
};
haxor.math.Vector3.get_forward = function() {
	return new haxor.math.Vector3(0,0,1);
};
haxor.math.Vector3.Dot = function(p_a,p_b) {
	return p_a.x * p_b.x + p_a.y * p_b.y + p_a.z * p_b.z;
};
haxor.math.Vector3.Distance = function(p_a,p_b) {
	var dx = p_a.x - p_b.x;
	var dy = p_a.y - p_b.y;
	var dz = p_a.z - p_b.z;
	return Math.sqrt(dx * dx + dy * dy + dz * dz);
};
haxor.math.Vector3.Cross = function(p_a,p_b,p_result) {
	if(p_result == null) p_result = new haxor.math.Vector3(); else p_result = p_result;
	return p_result.Set(p_a.y * p_b.z - p_a.z * p_b.y,p_a.z * p_b.x - p_a.x * p_b.z,p_a.x * p_b.y - p_a.y * p_b.x);
};
haxor.math.Vector3.Lerp = function(p_a,p_b,p_r,p_result) {
	if(p_result == null) p_result = new haxor.math.Vector3(); else p_result = p_result;
	return p_result.Set(p_a.x + (p_b.x - p_a.x) * p_r,p_a.y + (p_b.y - p_a.y) * p_r,p_a.z + (p_b.z - p_a.z) * p_r);
};
haxor.math.Vector3.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	return new haxor.math.Vector3(0,0,0).Set(Std.parseFloat(StringTools.trim(tk[0])),Std.parseFloat(StringTools.trim(tk[1])),Std.parseFloat(StringTools.trim(tk[2])));
};
haxor.math.Vector3.prototype = {
	get_clone: function() {
		return new haxor.math.Vector3(this.x,this.y,this.z);
	}
	,get_color: function() {
		return new haxor.math.Color(this.x,this.y,this.z);
	}
	,get_xzy: function() {
		return new haxor.math.Vector3(this.x,this.z,this.y);
	}
	,get_yxz: function() {
		return new haxor.math.Vector3(this.y,this.z,this.x);
	}
	,get_yzx: function() {
		return new haxor.math.Vector3(this.y,this.z,this.x);
	}
	,get_zxy: function() {
		return new haxor.math.Vector3(this.z,this.x,this.y);
	}
	,get_zyx: function() {
		return new haxor.math.Vector3(this.z,this.y,this.x);
	}
	,get_xy: function() {
		return new haxor.math.Vector2(this.x,this.y);
	}
	,get_xz: function() {
		return new haxor.math.Vector2(this.x,this.z);
	}
	,get_yx: function() {
		return new haxor.math.Vector2(this.y,this.x);
	}
	,get_yz: function() {
		return new haxor.math.Vector2(this.y,this.z);
	}
	,get_zx: function() {
		return new haxor.math.Vector2(this.z,this.x);
	}
	,get_zy: function() {
		return new haxor.math.Vector2(this.z,this.y);
	}
	,get_length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
	}
	,get_lengthSqr: function() {
		return this.x * this.x + this.y * this.y + this.z * this.z;
	}
	,get_normalized: function() {
		return new haxor.math.Vector3(this.x,this.y,this.z).Normalize();
	}
	,get_inverse: function() {
		return new haxor.math.Vector3(this.x,this.y,this.z).Invert();
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
		return "[" + haxor.math.Mathf.RoundPlaces(this.x,p_places) + "," + haxor.math.Mathf.RoundPlaces(this.y,p_places) + "," + haxor.math.Mathf.RoundPlaces(this.z,p_places) + "]";
	}
	,__class__: haxor.math.Vector3
};
haxor.math.Vector4 = function(p_x,p_y,p_z,p_w) {
	if(p_w == null) p_w = 0;
	if(p_z == null) p_z = 0;
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.x = p_x;
	this.y = p_y;
	this.z = p_z;
	this.w = p_w;
};
$hxClasses["haxor.math.Vector4"] = haxor.math.Vector4;
haxor.math.Vector4.__name__ = ["haxor","math","Vector4"];
haxor.math.Vector4.get_temp = function() {
	return haxor.context.EngineContext.data.get_v4();
};
haxor.math.Vector4.get_zero = function() {
	return new haxor.math.Vector4(0,0,0,0);
};
haxor.math.Vector4.get_one = function() {
	return new haxor.math.Vector4(1,1,1,1);
};
haxor.math.Vector4.get_W = function() {
	return new haxor.math.Vector4(0,0,0,1);
};
haxor.math.Vector4.Lerp = function(p_a,p_b,p_r) {
	return new haxor.math.Vector4(p_a.x + (p_b.x - p_a.x) * p_r,p_a.y + (p_b.y - p_a.y) * p_r,p_a.z + (p_b.z - p_a.z) * p_r,p_a.w + (p_b.w - p_a.w) * p_r);
};
haxor.math.Vector4.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	return new haxor.math.Vector4(0,0,0,0).Set(Std.parseFloat(StringTools.trim(tk[0])),Std.parseFloat(StringTools.trim(tk[1])),Std.parseFloat(StringTools.trim(tk[2])),Std.parseFloat(StringTools.trim(tk[3])));
};
haxor.math.Vector4.prototype = {
	get_clone: function() {
		return new haxor.math.Vector4(this.x,this.y,this.z,this.w);
	}
	,get_rgba: function() {
		return new haxor.math.Color(this.x,this.y,this.z,this.w);
	}
	,get_rgb: function() {
		return new haxor.math.Color(this.x,this.y,this.z);
	}
	,get_xyz: function() {
		return new haxor.math.Vector3(this.x,this.y,this.z);
	}
	,get_xy: function() {
		return new haxor.math.Vector2(this.x,this.y);
	}
	,get_length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w);
	}
	,get_lengthSqr: function() {
		return this.x * this.x + this.y * this.y + this.z * this.z + this.w * this.w;
	}
	,get_normalized: function() {
		return new haxor.math.Vector4(this.x,this.y,this.z,this.w).Normalize();
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
		return "[" + haxor.math.Mathf.RoundPlaces(this.x,p_places) + "," + haxor.math.Mathf.RoundPlaces(this.y,p_places) + "," + haxor.math.Mathf.RoundPlaces(this.z,p_places) + "," + haxor.math.Mathf.RoundPlaces(this.w,p_places) + "]";
	}
	,__class__: haxor.math.Vector4
};
haxor.thread = {};
haxor.thread.Activity = function(p_callback,p_threaded,p_graphics_context) {
	if(p_graphics_context == null) p_graphics_context = false;
	if(p_threaded == null) p_threaded = false;
	haxor.core.Resource.call(this);
	if(p_callback == null) return;
	this.m_time_start = haxor.core.Time.m_elapsed;
	this.m_elapsed = 0.0;
	this.m_callback = p_callback;
	this.m_cancelled = false;
	p_threaded = false;
	if(p_graphics_context) p_threaded = false;
	if(!p_threaded) {
		if(p_graphics_context) haxor.context.EngineContext.render.Add(this); else haxor.context.EngineContext.update.Add(this);
	} else {
	}
};
$hxClasses["haxor.thread.Activity"] = haxor.thread.Activity;
haxor.thread.Activity.__name__ = ["haxor","thread","Activity"];
haxor.thread.Activity.__interfaces__ = [haxor.core.IRenderable,haxor.core.IUpdateable];
haxor.thread.Activity.Iterate = function(p_offset,p_length,p_callback,p_step,p_threaded,p_graphics_context) {
	if(p_graphics_context == null) p_graphics_context = false;
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
	},p_threaded,p_graphics_context);
};
haxor.thread.Activity.Delay = function(p_time,p_callback,p_threaded,p_graphics_context) {
	if(p_graphics_context == null) p_graphics_context = false;
	if(p_threaded == null) p_threaded = false;
	return new haxor.thread.Activity(function(t) {
		if(t >= p_time) {
			p_callback();
			return false;
		}
		return true;
	},p_threaded,p_graphics_context);
};
haxor.thread.Activity.Run = function(p_callback,p_threaded,p_graphics_context) {
	if(p_graphics_context == null) p_graphics_context = false;
	if(p_threaded == null) p_threaded = false;
	return new haxor.thread.Activity(p_callback,p_threaded,p_graphics_context);
};
haxor.thread.Activity.RunOnce = function(p_callback,p_threaded,p_graphics_context) {
	if(p_graphics_context == null) p_graphics_context = false;
	if(p_threaded == null) p_threaded = false;
	return new haxor.thread.Activity(function(t) {
		p_callback();
		return false;
	},p_threaded,p_graphics_context);
};
haxor.thread.Activity.__super__ = haxor.core.Resource;
haxor.thread.Activity.prototype = $extend(haxor.core.Resource.prototype,{
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
			haxor.core.Resource.Destroy(this);
			return;
		}
		this.m_elapsed = haxor.core.Time.m_elapsed - this.m_time_start;
		if(!this.m_callback(this.m_elapsed)) haxor.core.Resource.Destroy(this);
	}
	,__class__: haxor.thread.Activity
});
haxor.thread.Task = function(p_threaded,p_callback) {
	if(p_threaded == null) p_threaded = false;
	var cb = p_callback;
	if(cb == null) cb = $bind(this,this.OnExecute);
	haxor.thread.Activity.call(this,cb,p_threaded);
	this.m_active = false;
	this.m_progress = 0.0;
	this.m_has_progress = false;
};
$hxClasses["haxor.thread.Task"] = haxor.thread.Task;
haxor.thread.Task.__name__ = ["haxor","thread","Task"];
haxor.thread.Task.__super__ = haxor.thread.Activity;
haxor.thread.Task.prototype = $extend(haxor.thread.Activity.prototype,{
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
	,__class__: haxor.thread.Task
});
haxor.net = {};
haxor.net.HTTPRequestTask = function(p_url,p_method,p_binary,p_data) {
	haxor.thread.Task.call(this);
	if(p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url,"./",haxor.net.Web.root);
	this.url = p_url;
	this.binary = p_binary;
	this.method = p_method;
	this.data = p_data;
	this.bytesLoaded = 0;
	this.bytesTotal = 0;
	this.error = "";
	haxor.core.Console.Log("HTTPRequest> " + this.url,4);
};
$hxClasses["haxor.net.HTTPRequestTask"] = haxor.net.HTTPRequestTask;
haxor.net.HTTPRequestTask.__name__ = ["haxor","net","HTTPRequestTask"];
haxor.net.HTTPRequestTask.__super__ = haxor.thread.Task;
haxor.net.HTTPRequestTask.prototype = $extend(haxor.thread.Task.prototype,{
	OnStart: function() {
	}
	,OnError: function() {
		haxor.core.Console.LogError("HTTPRequest> Error [" + this.error + "]");
	}
	,__class__: haxor.net.HTTPRequestTask
});
haxor.platform.html.net = {};
haxor.platform.html.net.HTTPRequest = function(p_url,p_method,p_binary,p_data) {
	var _g = this;
	haxor.net.HTTPRequestTask.call(this,p_url,p_method,p_binary,p_data);
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
$hxClasses["haxor.platform.html.net.HTTPRequest"] = haxor.platform.html.net.HTTPRequest;
haxor.platform.html.net.HTTPRequest.__name__ = ["haxor","platform","html","net","HTTPRequest"];
haxor.platform.html.net.HTTPRequest.__super__ = haxor.net.HTTPRequestTask;
haxor.platform.html.net.HTTPRequest.prototype = $extend(haxor.net.HTTPRequestTask.prototype,{
	OnStart: function() {
		if(this.data == null) this.request.send(); else this.request.send(this.data);
	}
	,__class__: haxor.platform.html.net.HTTPRequest
});
haxor.platform.html.net.HTTPLoader = function(p_url,p_binary,p_callback) {
	haxor.platform.html.net.HTTPRequest.call(this,p_url,"get",p_binary);
	this.callback = p_callback;
};
$hxClasses["haxor.platform.html.net.HTTPLoader"] = haxor.platform.html.net.HTTPLoader;
haxor.platform.html.net.HTTPLoader.__name__ = ["haxor","platform","html","net","HTTPLoader"];
haxor.platform.html.net.HTTPLoader.__super__ = haxor.platform.html.net.HTTPRequest;
haxor.platform.html.net.HTTPLoader.prototype = $extend(haxor.platform.html.net.HTTPRequest.prototype,{
	OnStart: function() {
		haxor.platform.html.net.HTTPRequest.prototype.OnStart.call(this);
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
	,__class__: haxor.platform.html.net.HTTPLoader
});
haxor.platform.html.net.BitmapLoader = function(p_url,p_callback) {
	haxor.platform.html.net.HTTPLoader.call(this,p_url,true,$bind(this,this.OnBufferCallback));
	this.m_bitmap_callback = p_callback;
	this.request.responseType = "blob";
};
$hxClasses["haxor.platform.html.net.BitmapLoader"] = haxor.platform.html.net.BitmapLoader;
haxor.platform.html.net.BitmapLoader.__name__ = ["haxor","platform","html","net","BitmapLoader"];
haxor.platform.html.net.BitmapLoader.__super__ = haxor.platform.html.net.HTTPLoader;
haxor.platform.html.net.BitmapLoader.prototype = $extend(haxor.platform.html.net.HTTPLoader.prototype,{
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
				g.drawImage(img,0,0);
				var data = g.getImageData(0,0,g.canvas.width,g.canvas.height);
				var w = data.width;
				var h = data.height;
				var cc = data.data.byteLength / (w * h) | 0;
				var fmt = haxor.graphics.PixelFormat.RGBA8;
				switch(cc) {
				case 1:
					fmt = haxor.graphics.PixelFormat.Alpha8;
					break;
				case 3:
					fmt = haxor.graphics.PixelFormat.RGB8;
					break;
				}
				var b = new haxor.graphics.texture.Bitmap(w,h,fmt);
				b.get_buffer().m_buffer.set(data.data);
				if(_g.m_bitmap_callback != null) _g.m_bitmap_callback(b,1.0);
			};
			img.src = URL.createObjectURL(this.request.response);
		}
	}
	,OnError: function() {
		if(this.m_bitmap_callback != null) this.m_bitmap_callback(null,1.0);
	}
	,__class__: haxor.platform.html.net.BitmapLoader
});
haxor.net.Texture2DLoader = function(p_url,p_apply,p_callback) {
	haxor.platform.html.net.BitmapLoader.call(this,p_url,$bind(this,this.OnBitmapCallback));
	this.m_t2d_callback = p_callback;
	this.m_apply = p_apply;
};
$hxClasses["haxor.net.Texture2DLoader"] = haxor.net.Texture2DLoader;
haxor.net.Texture2DLoader.__name__ = ["haxor","net","Texture2DLoader"];
haxor.net.Texture2DLoader.__super__ = haxor.platform.html.net.BitmapLoader;
haxor.net.Texture2DLoader.prototype = $extend(haxor.platform.html.net.BitmapLoader.prototype,{
	OnBitmapCallback: function(p_data,p_progress) {
		var _g = this;
		if(this.m_progress < 1.0) {
			if(this.m_t2d_callback != null) this.m_t2d_callback(null,this.m_progress);
		} else {
			if(p_data == null) return;
			haxor.thread.Activity.RunOnce(function() {
				var t = haxor.graphics.texture.Texture2D.FromBitmap(p_data,_g.m_apply);
				_g.m_t2d_callback(t,1.0);
			},false,true);
		}
	}
	,OnError: function() {
		haxor.platform.html.net.BitmapLoader.prototype.OnError.call(this);
		if(this.m_t2d_callback != null) this.m_bitmap_callback(null,1.0);
	}
	,__class__: haxor.net.Texture2DLoader
});
haxor.net.Web = function() { };
$hxClasses["haxor.net.Web"] = haxor.net.Web;
haxor.net.Web.__name__ = ["haxor","net","Web"];
haxor.net.Web.Load = function(p_url,p_callback) {
	var ld = new haxor.platform.html.net.HTTPLoader(p_url,false,p_callback);
};
haxor.net.Web.LoadImg = function(p_url,p_callback) {
	var ld = new haxor.platform.html.net.BitmapLoader(p_url,p_callback);
};
haxor.net.Web.LoadTexture2D = function(p_url,p_apply,p_callback) {
	var ld = new haxor.net.Texture2DLoader(p_url,p_apply,p_callback);
};
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
	haxor.graphics.GL.Initialize(haxor.platform.html.Entry.m_application);
	haxor.graphics.GL.m_gl.Initialize(app_container_id);
	haxor.graphics.GL.m_gl.CheckExtensions();
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
haxor.platform.html.graphics = {};
haxor.platform.html.graphics.WebGL = function(p_application) {
	haxor.graphics.GraphicContext.call(this,p_application);
	this.m_api = haxor.graphics.GraphicAPI.WebGL;
};
$hxClasses["haxor.platform.html.graphics.WebGL"] = haxor.platform.html.graphics.WebGL;
haxor.platform.html.graphics.WebGL.__name__ = ["haxor","platform","html","graphics","WebGL"];
haxor.platform.html.graphics.WebGL.__super__ = haxor.graphics.GraphicContext;
haxor.platform.html.graphics.WebGL.prototype = $extend(haxor.graphics.GraphicContext.prototype,{
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
			if(extensions[i].indexOf("WEBKIT_") >= 0) continue;
			var ext = this.c.getExtension(extensions[i]);
			haxor.core.Console.Log("\t" + extensions[i],1);
			var _g2 = extensions[i];
			switch(_g2) {
			case "OES_vertex_array_object":
				haxor.graphics.GL.VERTEX_ARRAY_OBJECT = true;
				break;
			case "OES_texture_half_float":
				haxor.graphics.GL.HALF_FLOAT = 36193;
				haxor.graphics.GL.TEXTURE_HALF = true;
				break;
			case "OES_texture_half_float_linear":
				haxor.graphics.GL.TEXTURE_HALF_LINEAR = true;
				break;
			case "EXT_texture_filter_anisotropic":case "WEBKIT_EXT_texture_filter_anisotropic":
				haxor.graphics.GL.TEXTURE_ANISOTROPY = ext.TEXTURE_MAX_ANISOTROPY_EXT;
				haxor.graphics.GL.MAX_TEXTURE_ANISOTROPY = this.c.getParameter(ext.MAX_TEXTURE_MAX_ANISOTROPY_EXT);
				haxor.graphics.GL.TEXTURE_ANISOTROPY_ENABLED = true;
				haxor.core.Console.Log("\t\tMax Aniso: " + haxor.graphics.GL.MAX_TEXTURE_ANISOTROPY);
				break;
			case "OES_texture_float":
				haxor.graphics.GL.TEXTURE_FLOAT = true;
				break;
			case "OES_depth_texture":
				haxor.graphics.GL.TEXTURE_DEPTH_ENABLED = true;
				break;
			}
		}
		haxor.graphics.GL.MAX_ACTIVE_TEXTURE = this.c.getParameter(34930);
		haxor.core.Console.Log("\tMax Active Textures: " + haxor.graphics.GL.MAX_ACTIVE_TEXTURE);
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
	,GetErrorCode: function() {
		return this.c.getError();
	}
	,__class__: haxor.platform.html.graphics.WebGL
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
js.Boot.__cast = function(o,t) {
	if(js.Boot.__instanceof(o,t)) return o; else throw "Cannot cast " + Std.string(o) + " to " + Std.string(t);
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
haxor.core.Resource.m_database = new haxe.ds.StringMap();
haxe.crypto.Base64.CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
haxe.crypto.Base64.BYTES = haxe.io.Bytes.ofString(haxe.crypto.Base64.CHARS);
haxe.ds.ObjectMap.count = 0;
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
haxor.component.Light.ambient = new haxor.math.Color(0.0,0.0,0.0,1.0);
haxor.component.Light.max = 8;
haxor.component.Light.m_list = [];
haxor.context.DataContext.MAX_TEMP = 128;
haxor.context.EngineContext.uid = 0;
haxor.context.EngineContext.maxNodes = 1000;
haxor.context.EngineContext.collectRate = 10;
haxor.context.BaseProcess.m_cid = 0;
haxor.context.ShaderContext.flat_source = "\r\n\t<shader id=\"haxor/unlit/Flat\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\t\t\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\tv_color = color * Tint;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) { gl_FragColor = v_color; }\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
haxor.context.ShaderContext.flat_texture_source = "\r\n\t<shader id=\"haxor/unlit/FlatTexture\">\t\r\n\t\t<vertex>\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\t\r\n\t\tattribute vec4 color;\r\n\t\tattribute vec3 uv0;\t\t\r\n\t\tvarying vec3 v_uv0;\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\tv_uv0   = uv0;\r\n\t\t\tv_color = color;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\r\n\t\t\tvarying vec3 v_uv0;\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tuniform sampler2D DiffuseTexture;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);\t\t\t\t\r\n\t\t\t\tgl_FragColor.xyz = tex_diffuse.xyz * v_color.xyz;\r\n\t\t\t\tgl_FragColor.a \t = tex_diffuse.a * v_color.a;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t";
haxor.context.ShaderContext.gizmo_grid_source = "\r\n\t<shader id=\"haxor/gizmo/Grid\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\r\n\t\tuniform float Area;\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\tgl_Position = ((vec4(vertex*Area, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\tv_color = color * Tint;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) { gl_FragColor = v_color; }\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
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
haxor.graphics.TextureWrap.ClampX = 1;
haxor.graphics.TextureWrap.RepeatX = 2;
haxor.graphics.TextureWrap.ClampY = 4;
haxor.graphics.TextureWrap.RepeatY = 8;
haxor.graphics.TextureWrap.ClampZ = 16;
haxor.graphics.TextureWrap.RepeatZ = 32;
haxor.graphics.ClearFlag.None = 0;
haxor.graphics.ClearFlag.Color = 1;
haxor.graphics.ClearFlag.Depth = 2;
haxor.graphics.ClearFlag.Skybox = 4;
haxor.graphics.ClearFlag.ColorDepth = 3;
haxor.graphics.ClearFlag.SkyboxDepth = 6;
haxor.graphics.GL.ACTIVE_ATTRIBUTES = 35721;
haxor.graphics.GL.ACTIVE_TEXTURE = 34016;
haxor.graphics.GL.ACTIVE_UNIFORMS = 35718;
haxor.graphics.GL.ALIASED_LINE_WIDTH_RANGE = 33902;
haxor.graphics.GL.ALIASED_POINT_SIZE_RANGE = 33901;
haxor.graphics.GL.ALPHA = 6406;
haxor.graphics.GL.ALPHA_BITS = 3413;
haxor.graphics.GL.ALWAYS = 519;
haxor.graphics.GL.ARRAY_BUFFER = 34962;
haxor.graphics.GL.ARRAY_BUFFER_BINDING = 34964;
haxor.graphics.GL.ATTACHED_SHADERS = 35717;
haxor.graphics.GL.BACK = 1029;
haxor.graphics.GL.BLEND = 3042;
haxor.graphics.GL.BLEND_COLOR = 32773;
haxor.graphics.GL.BLEND_DST_ALPHA = 32970;
haxor.graphics.GL.BLEND_DST_RGB = 32968;
haxor.graphics.GL.BLEND_EQUATION = 32777;
haxor.graphics.GL.BLEND_EQUATION_ALPHA = 34877;
haxor.graphics.GL.BLEND_EQUATION_RGB = 32777;
haxor.graphics.GL.BLEND_SRC_ALPHA = 32971;
haxor.graphics.GL.BLEND_SRC_RGB = 32969;
haxor.graphics.GL.BLUE_BITS = 3412;
haxor.graphics.GL.BOOL = 35670;
haxor.graphics.GL.BOOL_VEC2 = 35671;
haxor.graphics.GL.BOOL_VEC3 = 35672;
haxor.graphics.GL.BOOL_VEC4 = 35673;
haxor.graphics.GL.BROWSER_DEFAULT_WEBGL = 37444;
haxor.graphics.GL.BUFFER_SIZE = 34660;
haxor.graphics.GL.BUFFER_USAGE = 34661;
haxor.graphics.GL.BYTE = 5120;
haxor.graphics.GL.CCW = 2305;
haxor.graphics.GL.CLAMP_TO_EDGE = 33071;
haxor.graphics.GL.COLOR_ATTACHMENT0 = 36064;
haxor.graphics.GL.COLOR_BUFFER_BIT = 16384;
haxor.graphics.GL.COLOR_CLEAR_VALUE = 3106;
haxor.graphics.GL.COLOR_WRITEMASK = 3107;
haxor.graphics.GL.COMPILE_STATUS = 35713;
haxor.graphics.GL.COMPRESSED_TEXTURE_FORMATS = 34467;
haxor.graphics.GL.CONSTANT_ALPHA = 32771;
haxor.graphics.GL.CONSTANT_COLOR = 32769;
haxor.graphics.GL.CONTEXT_LOST_WEBGL = 37442;
haxor.graphics.GL.CULL_FACE = 2884;
haxor.graphics.GL.CULL_FACE_MODE = 2885;
haxor.graphics.GL.CURRENT_PROGRAM = 35725;
haxor.graphics.GL.CURRENT_VERTEX_ATTRIB = 34342;
haxor.graphics.GL.CW = 2304;
haxor.graphics.GL.DECR = 7683;
haxor.graphics.GL.DECR_WRAP = 34056;
haxor.graphics.GL.DELETE_STATUS = 35712;
haxor.graphics.GL.DEPTH_ATTACHMENT = 36096;
haxor.graphics.GL.DEPTH_BITS = 3414;
haxor.graphics.GL.DEPTH_BUFFER_BIT = 256;
haxor.graphics.GL.DEPTH_CLEAR_VALUE = 2931;
haxor.graphics.GL.DEPTH_COMPONENT = 6402;
haxor.graphics.GL.DEPTH_COMPONENT16 = 33189;
haxor.graphics.GL.DEPTH_FUNC = 2932;
haxor.graphics.GL.DEPTH_RANGE = 2928;
haxor.graphics.GL.DEPTH_STENCIL = 34041;
haxor.graphics.GL.DEPTH_STENCIL_ATTACHMENT = 33306;
haxor.graphics.GL.DEPTH_TEST = 2929;
haxor.graphics.GL.DEPTH_WRITEMASK = 2930;
haxor.graphics.GL.DITHER = 3024;
haxor.graphics.GL.DONT_CARE = 4352;
haxor.graphics.GL.DST_ALPHA = 772;
haxor.graphics.GL.DST_COLOR = 774;
haxor.graphics.GL.DYNAMIC_DRAW = 35048;
haxor.graphics.GL.ELEMENT_ARRAY_BUFFER = 34963;
haxor.graphics.GL.ELEMENT_ARRAY_BUFFER_BINDING = 34965;
haxor.graphics.GL.EQUAL = 514;
haxor.graphics.GL.FASTEST = 4353;
haxor.graphics.GL.FLOAT = 5126;
haxor.graphics.GL.FLOAT_MAT2 = 35674;
haxor.graphics.GL.FLOAT_MAT3 = 35675;
haxor.graphics.GL.FLOAT_MAT4 = 35676;
haxor.graphics.GL.FLOAT_VEC2 = 35664;
haxor.graphics.GL.FLOAT_VEC3 = 35665;
haxor.graphics.GL.FLOAT_VEC4 = 35666;
haxor.graphics.GL.FRAGMENT_SHADER = 35632;
haxor.graphics.GL.FRAMEBUFFER = 36160;
haxor.graphics.GL.FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 36049;
haxor.graphics.GL.FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 36048;
haxor.graphics.GL.FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 36051;
haxor.graphics.GL.FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 36050;
haxor.graphics.GL.FRAMEBUFFER_BINDING = 36006;
haxor.graphics.GL.FRAMEBUFFER_COMPLETE = 36053;
haxor.graphics.GL.FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 36054;
haxor.graphics.GL.FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 36057;
haxor.graphics.GL.FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 36055;
haxor.graphics.GL.FRAMEBUFFER_UNSUPPORTED = 36061;
haxor.graphics.GL.FRONT = 1028;
haxor.graphics.GL.FRONT_AND_BACK = 1032;
haxor.graphics.GL.FRONT_FACE = 2886;
haxor.graphics.GL.FUNC_ADD = 32774;
haxor.graphics.GL.FUNC_REVERSE_SUBTRACT = 32779;
haxor.graphics.GL.FUNC_SUBTRACT = 32778;
haxor.graphics.GL.GENERATE_MIPMAP_HINT = 33170;
haxor.graphics.GL.GEQUAL = 518;
haxor.graphics.GL.GREATER = 516;
haxor.graphics.GL.GREEN_BITS = 3411;
haxor.graphics.GL.HIGH_FLOAT = 36338;
haxor.graphics.GL.HIGH_INT = 36341;
haxor.graphics.GL.INCR = 7682;
haxor.graphics.GL.INCR_WRAP = 34055;
haxor.graphics.GL.INT = 5124;
haxor.graphics.GL.INT_VEC2 = 35667;
haxor.graphics.GL.INT_VEC3 = 35668;
haxor.graphics.GL.INT_VEC4 = 35669;
haxor.graphics.GL.INVALID_ENUM = 1280;
haxor.graphics.GL.INVALID_FRAMEBUFFER_OPERATION = 1286;
haxor.graphics.GL.INVALID_OPERATION = 1282;
haxor.graphics.GL.INVALID_VALUE = 1281;
haxor.graphics.GL.INVERT = 5386;
haxor.graphics.GL.KEEP = 7680;
haxor.graphics.GL.LEQUAL = 515;
haxor.graphics.GL.LESS = 513;
haxor.graphics.GL.LINEAR = 9729;
haxor.graphics.GL.LINEAR_MIPMAP_LINEAR = 9987;
haxor.graphics.GL.LINEAR_MIPMAP_NEAREST = 9985;
haxor.graphics.GL.LINES = 1;
haxor.graphics.GL.LINE_LOOP = 2;
haxor.graphics.GL.LINE_STRIP = 3;
haxor.graphics.GL.LINE_WIDTH = 2849;
haxor.graphics.GL.LINK_STATUS = 35714;
haxor.graphics.GL.LOW_FLOAT = 36336;
haxor.graphics.GL.LOW_INT = 36339;
haxor.graphics.GL.LUMINANCE = 6409;
haxor.graphics.GL.LUMINANCE_ALPHA = 6410;
haxor.graphics.GL.MAX_COMBINED_TEXTURE_IMAGE_UNITS = 35661;
haxor.graphics.GL.MAX_CUBE_MAP_TEXTURE_SIZE = 34076;
haxor.graphics.GL.MAX_FRAGMENT_UNIFORM_VECTORS = 36349;
haxor.graphics.GL.MAX_RENDERBUFFER_SIZE = 34024;
haxor.graphics.GL.MAX_TEXTURE_IMAGE_UNITS = 34930;
haxor.graphics.GL.MAX_TEXTURE_SIZE = 3379;
haxor.graphics.GL.MAX_VARYING_VECTORS = 36348;
haxor.graphics.GL.MAX_VERTEX_ATTRIBS = 34921;
haxor.graphics.GL.MAX_VERTEX_TEXTURE_IMAGE_UNITS = 35660;
haxor.graphics.GL.MAX_VERTEX_UNIFORM_VECTORS = 36347;
haxor.graphics.GL.MAX_VIEWPORT_DIMS = 3386;
haxor.graphics.GL.MEDIUM_FLOAT = 36337;
haxor.graphics.GL.MEDIUM_INT = 36340;
haxor.graphics.GL.MIRRORED_REPEAT = 33648;
haxor.graphics.GL.NEAREST = 9728;
haxor.graphics.GL.NEAREST_MIPMAP_LINEAR = 9986;
haxor.graphics.GL.NEAREST_MIPMAP_NEAREST = 9984;
haxor.graphics.GL.NEVER = 512;
haxor.graphics.GL.NICEST = 4354;
haxor.graphics.GL.NONE = 0;
haxor.graphics.GL.NOTEQUAL = 517;
haxor.graphics.GL.NO_ERROR_GL = 0;
haxor.graphics.GL.ONE = 1;
haxor.graphics.GL.ONE_MINUS_CONSTANT_ALPHA = 32772;
haxor.graphics.GL.ONE_MINUS_CONSTANT_COLOR = 32770;
haxor.graphics.GL.ONE_MINUS_DST_ALPHA = 773;
haxor.graphics.GL.ONE_MINUS_DST_COLOR = 775;
haxor.graphics.GL.ONE_MINUS_SRC_ALPHA = 771;
haxor.graphics.GL.ONE_MINUS_SRC_COLOR = 769;
haxor.graphics.GL.OUT_OF_MEMORY = 1285;
haxor.graphics.GL.PACK_ALIGNMENT = 3333;
haxor.graphics.GL.POINTS = 0;
haxor.graphics.GL.POLYGON_OFFSET_FACTOR = 32824;
haxor.graphics.GL.POLYGON_OFFSET_FILL = 32823;
haxor.graphics.GL.POLYGON_OFFSET_UNITS = 10752;
haxor.graphics.GL.RED_BITS = 3410;
haxor.graphics.GL.RENDERBUFFER = 36161;
haxor.graphics.GL.RENDERBUFFER_ALPHA_SIZE = 36179;
haxor.graphics.GL.RENDERBUFFER_BINDING = 36007;
haxor.graphics.GL.RENDERBUFFER_BLUE_SIZE = 36178;
haxor.graphics.GL.RENDERBUFFER_DEPTH_SIZE = 36180;
haxor.graphics.GL.RENDERBUFFER_GREEN_SIZE = 36177;
haxor.graphics.GL.RENDERBUFFER_HEIGHT = 36163;
haxor.graphics.GL.RENDERBUFFER_INTERNAL_FORMAT = 36164;
haxor.graphics.GL.RENDERBUFFER_RED_SIZE = 36176;
haxor.graphics.GL.RENDERBUFFER_STENCIL_SIZE = 36181;
haxor.graphics.GL.RENDERBUFFER_WIDTH = 36162;
haxor.graphics.GL.RENDERER = 7937;
haxor.graphics.GL.REPEAT = 10497;
haxor.graphics.GL.REPLACE = 7681;
haxor.graphics.GL.RGB = 6407;
haxor.graphics.GL.RGB565 = 36194;
haxor.graphics.GL.RGB5_A1 = 32855;
haxor.graphics.GL.RGBA = 6408;
haxor.graphics.GL.RGBA4 = 32854;
haxor.graphics.GL.SAMPLER_2D = 35678;
haxor.graphics.GL.SAMPLER_CUBE = 35680;
haxor.graphics.GL.SAMPLES = 32937;
haxor.graphics.GL.SAMPLE_ALPHA_TO_COVERAGE = 32926;
haxor.graphics.GL.SAMPLE_BUFFERS = 32936;
haxor.graphics.GL.SAMPLE_COVERAGE = 32928;
haxor.graphics.GL.SAMPLE_COVERAGE_INVERT = 32939;
haxor.graphics.GL.SAMPLE_COVERAGE_VALUE = 32938;
haxor.graphics.GL.SCISSOR_BOX = 3088;
haxor.graphics.GL.SCISSOR_TEST = 3089;
haxor.graphics.GL.SHADER_TYPE = 35663;
haxor.graphics.GL.SHADING_LANGUAGE_VERSION = 35724;
haxor.graphics.GL.SHORT = 5122;
haxor.graphics.GL.SRC_ALPHA = 770;
haxor.graphics.GL.SRC_ALPHA_SATURATE = 776;
haxor.graphics.GL.SRC_COLOR = 768;
haxor.graphics.GL.STATIC_DRAW = 35044;
haxor.graphics.GL.STENCIL_ATTACHMENT = 36128;
haxor.graphics.GL.STENCIL_BACK_FAIL = 34817;
haxor.graphics.GL.STENCIL_BACK_FUNC = 34816;
haxor.graphics.GL.STENCIL_BACK_PASS_DEPTH_FAIL = 34818;
haxor.graphics.GL.STENCIL_BACK_PASS_DEPTH_PASS = 34819;
haxor.graphics.GL.STENCIL_BACK_REF = 36003;
haxor.graphics.GL.STENCIL_BACK_VALUE_MASK = 36004;
haxor.graphics.GL.STENCIL_BACK_WRITEMASK = 36005;
haxor.graphics.GL.STENCIL_BITS = 3415;
haxor.graphics.GL.STENCIL_BUFFER_BIT = 1024;
haxor.graphics.GL.STENCIL_CLEAR_VALUE = 2961;
haxor.graphics.GL.STENCIL_FAIL = 2964;
haxor.graphics.GL.STENCIL_FUNC = 2962;
haxor.graphics.GL.STENCIL_INDEX = 6401;
haxor.graphics.GL.STENCIL_INDEX8 = 36168;
haxor.graphics.GL.STENCIL_PASS_DEPTH_FAIL = 2965;
haxor.graphics.GL.STENCIL_PASS_DEPTH_PASS = 2966;
haxor.graphics.GL.STENCIL_REF = 2967;
haxor.graphics.GL.STENCIL_TEST = 2960;
haxor.graphics.GL.STENCIL_VALUE_MASK = 2963;
haxor.graphics.GL.STENCIL_WRITEMASK = 2968;
haxor.graphics.GL.STREAM_DRAW = 35040;
haxor.graphics.GL.SUBPIXEL_BITS = 3408;
haxor.graphics.GL.TEXTURE = 5890;
haxor.graphics.GL.TEXTURE0 = 33984;
haxor.graphics.GL.TEXTURE1 = 33985;
haxor.graphics.GL.TEXTURE10 = 33994;
haxor.graphics.GL.TEXTURE11 = 33995;
haxor.graphics.GL.TEXTURE12 = 33996;
haxor.graphics.GL.TEXTURE13 = 33997;
haxor.graphics.GL.TEXTURE14 = 33998;
haxor.graphics.GL.TEXTURE15 = 33999;
haxor.graphics.GL.TEXTURE16 = 34000;
haxor.graphics.GL.TEXTURE17 = 34001;
haxor.graphics.GL.TEXTURE18 = 34002;
haxor.graphics.GL.TEXTURE19 = 34003;
haxor.graphics.GL.TEXTURE2 = 33986;
haxor.graphics.GL.TEXTURE20 = 34004;
haxor.graphics.GL.TEXTURE21 = 34005;
haxor.graphics.GL.TEXTURE22 = 34006;
haxor.graphics.GL.TEXTURE23 = 34007;
haxor.graphics.GL.TEXTURE24 = 34008;
haxor.graphics.GL.TEXTURE25 = 34009;
haxor.graphics.GL.TEXTURE26 = 34010;
haxor.graphics.GL.TEXTURE27 = 34011;
haxor.graphics.GL.TEXTURE28 = 34012;
haxor.graphics.GL.TEXTURE29 = 34013;
haxor.graphics.GL.TEXTURE3 = 33987;
haxor.graphics.GL.TEXTURE30 = 34014;
haxor.graphics.GL.TEXTURE31 = 34015;
haxor.graphics.GL.TEXTURE4 = 33988;
haxor.graphics.GL.TEXTURE5 = 33989;
haxor.graphics.GL.TEXTURE6 = 33990;
haxor.graphics.GL.TEXTURE7 = 33991;
haxor.graphics.GL.TEXTURE8 = 33992;
haxor.graphics.GL.TEXTURE9 = 33993;
haxor.graphics.GL.TEXTURE_2D = 3553;
haxor.graphics.GL.TEXTURE_BINDING_2D = 32873;
haxor.graphics.GL.TEXTURE_BINDING_CUBE_MAP = 34068;
haxor.graphics.GL.TEXTURE_CUBE_MAP = 34067;
haxor.graphics.GL.TEXTURE_CUBE_MAP_NEGATIVE_X = 34070;
haxor.graphics.GL.TEXTURE_CUBE_MAP_NEGATIVE_Y = 34072;
haxor.graphics.GL.TEXTURE_CUBE_MAP_NEGATIVE_Z = 34074;
haxor.graphics.GL.TEXTURE_CUBE_MAP_POSITIVE_X = 34069;
haxor.graphics.GL.TEXTURE_CUBE_MAP_POSITIVE_Y = 34071;
haxor.graphics.GL.TEXTURE_CUBE_MAP_POSITIVE_Z = 34073;
haxor.graphics.GL.TEXTURE_MAG_FILTER = 10240;
haxor.graphics.GL.TEXTURE_MIN_FILTER = 10241;
haxor.graphics.GL.TEXTURE_WRAP_S = 10242;
haxor.graphics.GL.TEXTURE_WRAP_T = 10243;
haxor.graphics.GL.TRIANGLES = 4;
haxor.graphics.GL.TRIANGLE_FAN = 6;
haxor.graphics.GL.TRIANGLE_STRIP = 5;
haxor.graphics.GL.UNPACK_ALIGNMENT = 3317;
haxor.graphics.GL.UNPACK_COLORSPACE_CONVERSION_WEBGL = 37443;
haxor.graphics.GL.UNPACK_FLIP_Y_WEBGL = 37440;
haxor.graphics.GL.UNPACK_PREMULTIPLY_ALPHA_WEBGL = 37441;
haxor.graphics.GL.UNSIGNED_BYTE = 5121;
haxor.graphics.GL.UNSIGNED_INT = 5125;
haxor.graphics.GL.UNSIGNED_SHORT = 5123;
haxor.graphics.GL.UNSIGNED_SHORT_4_4_4_4 = 32819;
haxor.graphics.GL.UNSIGNED_SHORT_5_5_5_1 = 32820;
haxor.graphics.GL.UNSIGNED_SHORT_5_6_5 = 33635;
haxor.graphics.GL.VALIDATE_STATUS = 35715;
haxor.graphics.GL.VENDOR = 7936;
haxor.graphics.GL.VERSION = 7938;
haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 34975;
haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_ENABLED = 34338;
haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_NORMALIZED = 34922;
haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_POINTER = 34373;
haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_SIZE = 34339;
haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_STRIDE = 34340;
haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_TYPE = 34341;
haxor.graphics.GL.VERTEX_SHADER = 35633;
haxor.graphics.GL.VIEWPORT = 2978;
haxor.graphics.GL.ZERO = 0;
haxor.graphics.GL.VERTEX_ARRAY_OBJECT = false;
haxor.graphics.GL.HALF_FLOAT = 5126;
haxor.graphics.GL.TEXTURE_HALF = false;
haxor.graphics.GL.TEXTURE_HALF_LINEAR = false;
haxor.graphics.GL.TEXTURE_ANISOTROPY = -1;
haxor.graphics.GL.TEXTURE_ANISOTROPY_ENABLED = false;
haxor.graphics.GL.MAX_TEXTURE_ANISOTROPY = 1;
haxor.graphics.GL.TEXTURE_FLOAT = false;
haxor.graphics.GL.TEXTURE_FLOAT_LINEAR = false;
haxor.graphics.GL.TEXTURE_DEPTH_ENABLED = false;
haxor.graphics.GL.MAX_ACTIVE_TEXTURE = 8;
haxor.graphics.Graphics.m_last_viewport = haxor.math.AABB2.get_empty();
haxor.math.Mathf.Epsilon = 0.0001;
haxor.math.Mathf.NaN = Math.NaN;
haxor.math.Mathf.Infinity = Math.POSITIVE_INFINITY;
haxor.math.Mathf.NegativeInfinity = Math.NEGATIVE_INFINITY;
haxor.math.Mathf.E = 2.7182818284590452353602874713527;
haxor.math.Mathf.PI = 3.1415926535897932384626433832795028841971693993751058;
haxor.math.Mathf.HalfPI = 1.5707963267948966192313216916398;
haxor.math.Mathf.PI2 = 6.283185307179586476925286766559;
haxor.math.Mathf.PI4 = 12.566370614359172953850573533118;
haxor.math.Mathf.InvPI = 0.31830988618379067153776752674503;
haxor.math.Mathf.Rad2Deg = 57.295779513082320876798154814105;
haxor.math.Mathf.Deg2Rad = 0.01745329251994329576923690768489;
haxor.math.Mathf.Px2Em = 0.063;
haxor.math.Mathf.Em2Px = 15.87301587301587;
haxor.math.Mathf.Byte2Float = 0.00392156863;
haxor.math.Mathf.Short2Float = 0.0000152587890625;
haxor.math.Mathf.Long2Float = 0.00000000023283064365386962890625;
haxor.math.Mathf.Float2Byte = 255.0;
haxor.math.Mathf.Float2Short = 65536.0;
haxor.math.Mathf.Float2Long = 4294967296.0;
haxor.net.Web.root = "";
Main.main();
})();
