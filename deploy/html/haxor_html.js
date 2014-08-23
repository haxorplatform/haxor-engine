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
	this.__cid = 0;
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
	,OnTransformUpdate: function() {
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
		var s = 0.8;
		var vl = haxor.io.FloatArray.Alloc([-s,-s,0.5,s,-s,0.5,s,s,0.5,-s,s,0.5]);
		var uvl = haxor.io.FloatArray.Alloc([0.0,0.0,1.0,0.0,1.0,1.0,0.0,1.0]);
		var cl = haxor.io.FloatArray.Alloc([1.0,0.0,0.0,1.0,0.0,1.0,0.0,1.0,0.0,0.0,1.0,1.0,1.0,1.0,0.0,1.0]);
		var il = haxor.io.UInt16Array.Alloc([0,1,2,0,2,3]);
		var m = this.mesh = new haxor.graphics.mesh.Mesh();
		m.Set("vertex",vl,3);
		m.Set("uv0",uvl,2);
		m.Set("color",cl,4);
		m.set_topology(il);
		if(this.ss == null) this.ss = "\r\n\t\t\t<shader id=\"haxor/debug\">\r\n\t\t\t\t<vertex>\t\t\t\r\n\t\t\t\tattribute vec3 vertex;\r\n\t\t\t\tattribute vec2 uv0;\r\n\t\t\t\tattribute vec4 color;\t\t\t\r\n\t\t\t\tuniform float Size;\r\n\t\t\t\tuniform float Time;\r\n\t\t\t\tuniform mat4 ViewMatrix;\r\n\t\t\t\tvarying vec4 v_color;\t\t\r\n\t\t\t\tvarying vec2 v_uv0;\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tv_color = color;\r\n\t\t\t\t\tv_uv0.x = vertex.x / (Size);\r\n\t\t\t\t\tv_uv0.y = -vertex.y / (Size);\r\n\t\t\t\t\tv_uv0.x = (v_uv0.x + 1.0) * 0.5;\r\n\t\t\t\t\tv_uv0.y = (v_uv0.y + 1.0) * 0.5;\r\n\t\t\t\t\t//v_uv0 = uv0;\r\n\t\t\t\t\tvec4 v = vec4(vertex,1.0);\r\n\t\t\t\t\tv.x = v.x * sin(Time);\r\n\t\t\t\t\tv_color = ViewMatrix[3];\r\n\t\t\t\t\tgl_Position = vec4(v);\t\t\t\t\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</vertex>\t\t\t\r\n\t\t\t\t<fragment>\t\t\t\r\n\t\t\t\tuniform sampler2D Texture;\r\n\t\t\t\tuniform vec4 Tint[2];\r\n\t\t\t\tvarying vec4 v_color;\t\r\n\t\t\t\tvarying vec2 v_uv0;\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tvec4 c = texture2D(Texture, v_uv0);\r\n\t\t\t\t\t//gl_FragColor = vec4(v_uv0.x,v_uv0.y,0.0,1.0);\r\n\t\t\t\t\tgl_FragColor = v_color;\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</fragment>\r\n\t\t\t</shader>\r\n\t\t\t";
		if(this.bmp != null) {
			this.tex = haxor.graphics.texture.Texture2D.FromBitmap(this.bmp,false);
			this.tex.Upload(100);
		}
		var shd = new haxor.graphics.material.Shader(this.ss);
		this.mat = haxor.graphics.material.Material.Transparent(null,null,null);
		this.mat.set_shader(shd);
		this.mat.SetFloat("Size",s);
		this.mat.SetTexture("Texture",this.tex);
		this.mat.SetFloat4Array("Tint",[0.0,1.0,0.0,0.3,1.0,0.0,0.0,0.3]);
		var cam;
		var trf;
	}
	,OnUpdate: function() {
	}
	,OnRender: function() {
		haxor.graphics.GL.m_gl.Viewport(0,0,haxor.graphics.Screen.m_width,haxor.graphics.Screen.m_height);
		haxor.graphics.GL.m_gl.Scissor(0,0,haxor.graphics.Screen.m_width,haxor.graphics.Screen.m_height);
		haxor.graphics.GL.m_gl.ClearColor(0.7,0.3,1.0,1.0);
		haxor.graphics.GL.m_gl.ClearDepth(1.0);
		haxor.graphics.GL.m_gl.Clear(16640);
		if(this.mesh == null) return;
		if(this.mat == null) return;
		this.mat.SetFloat("Time",haxor.core.Time.m_elapsed);
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
	,addSub: function(s,pos,len) {
		if(len == null) this.b += HxOverrides.substr(s,pos,null); else this.b += HxOverrides.substr(s,pos,len);
	}
	,__class__: StringBuf
};
var StringTools = function() { };
$hxClasses["StringTools"] = StringTools;
StringTools.__name__ = ["StringTools"];
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
haxor.component.Camera = function() {
	haxor.component.Behaviour.call(this);
	this.__cid = haxor.context.EngineContext.camera.cid++;
	this.m_order = 0;
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
	this.background = new haxor.math.Color(0,0,0,1);
	this.clear = haxor.graphics.ClearFlag.ColorDepth;
	this.mask = 1;
	this.set_viewport(new haxor.math.AABB2(0,0,1,1));
	haxor.context.EngineContext.camera.Create(this);
};
$hxClasses["haxor.component.Camera"] = haxor.component.Camera;
haxor.component.Camera.__name__ = ["haxor","component","Camera"];
haxor.component.Camera.__super__ = haxor.component.Behaviour;
haxor.component.Camera.prototype = $extend(haxor.component.Behaviour.prototype,{
	get_fov: function() {
		return this.m_fov;
	}
	,set_fov: function(v) {
		this.m_fov = v;
		this.UpdateProjection();
		return v;
	}
	,get_near: function() {
		return this.m_near;
	}
	,set_near: function(v) {
		this.m_near = v;
		this.UpdateProjection();
		return v;
	}
	,get_far: function() {
		return this.m_far;
	}
	,set_far: function(v) {
		this.m_far = v;
		this.UpdateProjection();
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
		this.m_viewport.set_xMin(v.get_xMin());
		this.m_viewport.set_xMax(v.get_xMax());
		this.m_viewport.set_yMin(v.get_yMin());
		this.m_viewport.set_yMax(v.get_yMax());
		this.OnResize(haxor.graphics.Screen.m_width,haxor.graphics.Screen.m_height);
		return this.m_viewport;
	}
	,get_CameraToWorld: function() {
		return this.m_cameraToWorld.get_clone();
	}
	,get_WorldToCamera: function() {
		return this.m_worldToCamera;
	}
	,get_ProjectionMatrix: function() {
		return this.m_projectionMatrix.get_clone();
	}
	,get_ProjectionMatrixInverse: function() {
		return this.m_projectionMatrixInverse.get_clone();
	}
	,get_target: function() {
		return this.m_target;
	}
	,set_target: function(v) {
		this.m_target = v;
		if(v != null) this.OnResize(v.m_width,v.m_height);
		return v;
	}
	,OnResize: function(w,h) {
		var vx = Std["int"](this.m_viewport.get_x() * w);
		var vy = Std["int"](this.m_viewport.get_y() * h);
		var aw = this.m_viewport.get_width() * w;
		var ah = this.m_viewport.get_height() * h;
		if(this.m_target != null) {
			aw = this.m_target.m_width;
			ah = this.m_target.m_height;
		}
		this.m_pixelViewport.set_x(vx);
		this.m_pixelViewport.set_y(h - ah - vy);
		this.m_pixelViewport.set_width(aw);
		this.m_pixelViewport.set_height(ah);
		this.m_aspect = aw / ah;
		var tw = aw;
		var th = ah;
		if(this.m_srcRT != null) {
			if(tw != this.m_srcRT.m_width) {
				haxor.core.Resource.Destroy(this.m_srcRT);
				haxor.core.Resource.Destroy(this.m_dstRT);
				haxor.core.Resource.Destroy(this.m_g0);
				haxor.core.Resource.Destroy(this.m_g1);
				this.m_g0 = this.m_g1 = this.m_dstRT = this.m_srcRT = null;
			} else if(th != this.m_srcRT.m_height) {
				haxor.core.Resource.Destroy(this.m_srcRT);
				haxor.core.Resource.Destroy(this.m_dstRT);
				haxor.core.Resource.Destroy(this.m_g0);
				haxor.core.Resource.Destroy(this.m_g1);
				this.m_g0 = this.m_g1 = this.m_dstRT = this.m_srcRT = null;
			}
		}
		if(this.m_srcRT == null) {
			this.m_srcRT = new haxor.graphics.texture.RenderTexture(aw,ah,haxor.graphics.PixelFormat.RGBA8,true);
			this.m_dstRT = new haxor.graphics.texture.RenderTexture(aw,ah,haxor.graphics.PixelFormat.RGBA8,true);
			this.m_g0 = new haxor.graphics.texture.RenderTexture(aw,ah,haxor.graphics.PixelFormat.RGBA8,true);
			this.m_g1 = new haxor.graphics.texture.RenderTexture(aw,ah,haxor.graphics.PixelFormat.RGBA8,true);
			this.m_g0.set_name(this.m_g1.set_name("ScreenBufferTexture"));
			this.m_grab = this.m_g0;
			this.m_back = this.m_g1;
		}
		this.UpdateProjection();
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
	,LookAt: function(p_at,p_up,p_smooth) {
		if(p_smooth == null) p_smooth = 0.0;
		var p = null;
		var r = null;
		var q = haxor.math.Quaternion.LookAt(p,p_at,p_up,haxor.context.EngineContext.data.get_q());
		if(p_smooth > 0) r = haxor.math.Quaternion.Lerp(r,q,p_smooth * haxor.core.Time.m_delta,haxor.context.EngineContext.data.get_q()); else r = q;
	}
	,UpdateProjection: function() {
		haxor.math.Matrix4.Perspective(this.m_fov,this.m_aspect,this.m_near,this.m_far,this.m_projectionMatrix);
		haxor.math.Matrix4.PerspectiveInverse(this.m_fov,this.m_aspect,this.m_near,this.m_far,this.m_projectionMatrixInverse);
		haxor.math.Matrix4.Perspective(this.m_fov,this.m_aspect,0.1,100000.0,this.m_skyboxProjection);
		haxor.math.Matrix4.PerspectiveInverse(this.m_fov,this.m_aspect,0.1,100000.0,this.m_skyboxProjectionInverse);
	}
	,SwapBuffer: function() {
		if(this.m_grab == this.m_g0) {
			this.m_grab = this.m_g1;
			this.m_back = this.m_g0;
		} else if(this.m_grab == this.m_g1) {
			this.m_grab = this.m_g0;
			this.m_back = this.m_g1;
		}
	}
	,OnDestroy: function() {
		haxor.context.EngineContext.camera.Destroy(this);
	}
	,__class__: haxor.component.Camera
});
haxor.component.Transform = function() {
	haxor.component.Component.call(this);
	this.m_position = new haxor.math.Vector3(0,0,0);
	this.m_rotation = new haxor.math.Quaternion(0,0,0,1.0);
	this.m_scale = new haxor.math.Vector3(1,1,1);
	this.m_localMatrix = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	this.m_worldMatrixInverse = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	this.m_worldMatrix = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
	this.m_depth = 0;
	this.m_hierarchy = new Array();
	this.m_dirty = true;
	this.m_concat = true;
	if(haxor.component.Transform.m_root != null) this.set_parent(null);
};
$hxClasses["haxor.component.Transform"] = haxor.component.Transform;
haxor.component.Transform.__name__ = ["haxor","component","Transform"];
haxor.component.Transform.get_root = function() {
	return haxor.component.Transform.m_root;
};
haxor.component.Transform.__super__ = haxor.component.Component;
haxor.component.Transform.prototype = $extend(haxor.component.Component.prototype,{
	get_right: function() {
		return new haxor.math.Vector3(0,0,0).Set(this.m_worldMatrix.m00,this.m_worldMatrix.m10,this.m_worldMatrix.m20);
	}
	,set_right: function(v) {
		return v;
	}
	,get_up: function() {
		return new haxor.math.Vector3(0,0,0).Set(this.m_worldMatrix.m01,this.m_worldMatrix.m11,this.m_worldMatrix.m21);
	}
	,set_up: function(v) {
		return v;
	}
	,get_forward: function() {
		return new haxor.math.Vector3(0,0,0).Set(this.m_worldMatrix.m02,this.m_worldMatrix.m12,this.m_worldMatrix.m22);
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
		this.m_dirty = true;
		this.UpdateDepth();
		this.Concat();
		return this;
	}
	,UpdateDepth: function() {
		if(this.m_parent == null) this.m_depth = 0; else this.m_depth = this.m_parent.m_depth + 1;
		var _g1 = 0;
		var _g = this.m_hierarchy.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_hierarchy[i].UpdateDepth();
		}
	}
	,get_position: function() {
		return new haxor.math.Vector3(0,0,0).Set(this.m_position.x,this.m_position.y,this.m_position.z);
	}
	,set_position: function(v) {
		if(Math.abs(this.m_position.x - v.x) < 0.0001) {
			if(Math.abs(this.m_position.y - v.y) < 0.0001) {
				if(Math.abs(this.m_position.z - v.z) < 0.0001) return v;
			}
		}
		this.m_position.x = v.x;
		this.m_position.y = v.y;
		this.m_position.z = v.z;
		this.m_dirty = true;
		this.Concat();
		return v;
	}
	,get_rotation: function() {
		return new haxor.math.Quaternion(0,0,0,1.0).Set(this.m_rotation.x,this.m_rotation.y,this.m_rotation.z,this.m_rotation.w);
	}
	,set_rotation: function(v) {
		if(Math.abs(this.m_rotation.x - v.x) < 0.0001) {
			if(Math.abs(this.m_rotation.y - v.y) < 0.0001) {
				if(Math.abs(this.m_rotation.z - v.z) < 0.0001) {
					if(Math.abs(this.m_rotation.w - v.w) < 0.0001) return v;
				}
			}
		}
		this.m_rotation.x = v.x;
		this.m_rotation.y = v.y;
		this.m_rotation.z = v.z;
		this.m_rotation.w = v.w;
		this.m_dirty = true;
		this.Concat();
		return v;
	}
	,get_scale: function() {
		return new haxor.math.Vector3(0,0,0).Set(this.m_scale.x,this.m_scale.y,this.m_scale.z);
	}
	,set_scale: function(v) {
		if(Math.abs(this.m_scale.x - v.x) < 0.0001) {
			if(Math.abs(this.m_scale.y - v.y) < 0.0001) {
				if(Math.abs(this.m_scale.z - v.z) < 0.0001) return v;
			}
		}
		this.m_scale.x = v.x;
		this.m_scale.y = v.y;
		this.m_scale.z = v.z;
		this.m_dirty = true;
		this.Concat();
		return v;
	}
	,get_LocalMatrix: function() {
		if(this.m_dirty) {
			this.SetLocalTRS();
			this.m_dirty = false;
		}
		var m = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		var v = this.m_localMatrix;
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
		return m;
	}
	,get_WorldMatrix: function() {
		var m = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		var v = this.m_worldMatrix;
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
		return m;
	}
	,get_WorldMatrixInverse: function() {
		var m = new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		var v = this.m_worldMatrixInverse;
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
		m.m30 = m.m31 = m.m32 = 0.0;
		m.m33 = 1.0;
		return m;
	}
	,Concat: function() {
		var v = this.m_parent.m_worldMatrix;
		var m = this.m_worldMatrix;
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
		m.MultiplyTransform(this.get_LocalMatrix());
		haxor.math.Matrix4.GetInverseTransform(m,this.m_worldMatrixInverse);
		this.UpdateComponents();
		var _g1 = 0;
		var _g = this.m_hierarchy.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_hierarchy[i].Concat();
		}
	}
	,UpdateComponents: function() {
		var _g1 = 0;
		var _g = this.m_entity.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_entity.m_components[i].OnTransformUpdate();
		}
	}
	,SetLocalTRS: function() {
		var sx = this.m_scale.x;
		var sy = this.m_scale.y;
		var sz = this.m_scale.z;
		var px = this.m_position.x;
		var py = this.m_position.y;
		var pz = this.m_position.z;
		var rx = this.m_rotation.x;
		var ry = this.m_rotation.y;
		var rz = this.m_rotation.z;
		var rw = this.m_rotation.w;
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
		var l = this.m_localMatrix;
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
	}
	,get_childCount: function() {
		return this.m_hierarchy.length;
	}
	,OnDestroy: function() {
		haxor.component.Component.prototype.OnDestroy.call(this);
	}
	,Lock: function() {
		this.m_lock = true;
		var _g1 = 0;
		var _g = this.m_hierarchy.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_hierarchy[i].Lock();
		}
	}
	,Unlock: function() {
		this.m_lock = false;
		var _g1 = 0;
		var _g = this.m_hierarchy.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_hierarchy[i].Unlock();
		}
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
		var d0 = this.m_depth;
		var hs = "";
		this.Traverse(function(t) {
			var tab = "";
			var td = t.m_depth;
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
		var go_deep = p_callback(p_child);
		if(go_deep) {
			var _g1 = 0;
			var _g = p_child.get_childCount();
			while(_g1 < _g) {
				var i = _g1++;
				this.TraverseStep(p_child.GetChild(i),p_callback);
			}
		}
	}
	,__class__: haxor.component.Transform
});
haxor.context = {};
haxor.context.CameraContext = function() {
	this.cid = 0;
	this.list = [];
};
$hxClasses["haxor.context.CameraContext"] = haxor.context.CameraContext;
haxor.context.CameraContext.__name__ = ["haxor","context","CameraContext"];
haxor.context.CameraContext.prototype = {
	Create: function(p_camera) {
		this.list.push(p_camera);
		this.SortCameraList();
	}
	,Destroy: function(p_camera) {
		HxOverrides.remove(this.list,p_camera);
		this.SortCameraList();
	}
	,Resize: function() {
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
	this.m_nv2 = 0;
	this.m_nv3 = 0;
	this.m_nv4 = 0;
	this.m_nc = 0;
	this.m_nq = 0;
	this.m_nm4 = 0;
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
	haxor.context.EngineContext.list = [haxor.context.EngineContext.update,haxor.context.EngineContext.render,haxor.context.EngineContext.resize,haxor.context.EngineContext.resources,haxor.context.EngineContext.disposables];
	haxor.context.EngineContext.mesh = new haxor.context.MeshContext();
	haxor.context.EngineContext.material = new haxor.context.MaterialContext();
	haxor.context.EngineContext.texture = new haxor.context.TextureContext();
	haxor.context.EngineContext.data = new haxor.context.DataContext();
	haxor.context.EngineContext.gizmo = new haxor.context.GizmoContext();
};
haxor.context.EngineContext.Build = function() {
	haxor.context.EngineContext.mesh.Initialize();
	haxor.context.EngineContext.material.Initialize();
	haxor.context.EngineContext.texture.Initialize();
	haxor.context.EngineContext.gizmo.Initialize();
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
	this.mid = 0;
	this.sid = 0;
	this.uid = 0;
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
		haxor.core.Console.Log("MaterialContext> Initialize.",3);
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
		haxor.core.Console.Log("Material> id[" + Std.string(this.programs[m.__cid]) + "]",4);
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
		haxor.core.Console.Log("Material> [" + m.get_name() + "] @ [" + Std.string(p) + "] uniform[" + u.name + "] loc[" + Std.string(loc) + "]");
		this.uniforms[m.__cid][u.__cid] = loc;
		u.__d = true;
	}
	,DestroyUniform: function(m,u) {
		var p = this.programs[m.__cid];
		var loc = haxor.graphics.GL.m_gl.GetUniformLocation(p,u.name);
		this.uniforms[m.__cid][u.__cid] = haxor.graphics.GL.INVALID;
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
	}
	,DestroyShader: function(s) {
		haxor.graphics.GL.m_gl.DeleteShader(this.vertex_shaders[s.__cid]);
		haxor.graphics.GL.m_gl.DeleteShader(this.fragment_shaders[s.__cid]);
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
haxor.context.BaseProcess = function(p_name) {
	this.name = p_name;
	haxor.core.Console.Log("\tProcess [" + p_name + "] created.",4);
	this.__cid = haxor.context.BaseProcess.m_cid++;
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
		var iid = p_item.m_pid[this.__cid];
		if(iid >= 0) return;
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
	this.tid = 0;
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
	,UploadTexture: function(p_texture,p_steps,p_on_complete) {
		var _g = this;
		var b = p_texture.m_data;
		var py = -180;
		var chn_fmt = haxor.context.TextureContext.FormatToChannelLayout(p_texture.m_format);
		var chn_bit = haxor.context.TextureContext.FormatToChannelBits(p_texture.m_format);
		var chn_type = haxor.context.TextureContext.FormatToChannelType(p_texture.m_format);
		var steps = p_texture.m_height / p_steps | 0;
		if(steps <= 1) steps = 1;
		var ua = new haxor.thread.Activity(function(t) {
			if(py >= b.m_height) {
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
				var pos = py * b.m_width * b.m_channels;
				var len = b.m_width * b.m_channels;
				b.get_buffer().SetViewSlice(pos,len);
				haxor.graphics.GL.TexSubImage2D(3553,0,0,py,b.m_width,1,chn_fmt,chn_type,b.get_buffer());
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
	}
	,__class__: haxor.context.TextureContext
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
haxor.graphics.Graphics = function() { };
$hxClasses["haxor.graphics.Graphics"] = haxor.graphics.Graphics;
haxor.graphics.Graphics.__name__ = ["haxor","graphics","Graphics"];
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
	this.__cid = haxor.context.EngineContext.material.mid++;
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
haxor.graphics.material.Material.Transparent = function(p_ztest,p_zwrite,p_double_sided) {
	if(p_double_sided == null) p_double_sided = false;
	if(p_zwrite == null) p_zwrite = true;
	if(p_ztest == null) p_ztest = true;
	var m = new haxor.graphics.material.Material();
	if(p_double_sided) m.cull = 0;
	m.SetBlending(770,771);
	m.queue = 2000;
	m.ztest = p_ztest;
	m.zwrite = p_zwrite;
	m.blend = true;
	return m;
};
haxor.graphics.material.Material.AdditiveAlpha = function(p_ztest,p_zwrite,p_double_sided) {
	if(p_double_sided == null) p_double_sided = false;
	if(p_zwrite == null) p_zwrite = true;
	if(p_ztest == null) p_ztest = true;
	var m = haxor.graphics.material.Material.Transparent(p_ztest,p_zwrite,p_double_sided);
	m.SetBlending(770,1);
	return m;
};
haxor.graphics.material.Material.Additive = function(p_ztest,p_zwrite,p_double_sided) {
	if(p_double_sided == null) p_double_sided = false;
	if(p_zwrite == null) p_zwrite = true;
	if(p_ztest == null) p_ztest = true;
	var m = haxor.graphics.material.Material.Transparent(p_ztest,p_zwrite,p_double_sided);
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
	this.__cid = haxor.context.EngineContext.material.uid++;
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
	this.__cid = haxor.context.EngineContext.material.sid++;
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
	this.__cid = haxor.context.EngineContext.mesh.mid++;
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
	this.__cid = haxor.context.EngineContext.mesh.aid++;
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
	this.__cid = haxor.context.EngineContext.texture.tid++;
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
		haxor.context.EngineContext.texture.UploadTexture(this,p_steps,p_on_complete);
	}
	,__class__: haxor.graphics.texture.Texture2D
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
	this.m_length = p_length;
	var len = this.m_length * this.get_bytesPerElement();
	this.m_offset = 0;
	this.m_buffer = new Uint8Array(len);
	this.aux = this.m_buffer;
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
	this.aux = new Float32Array(this.m_buffer.buffer);
};
$hxClasses["haxor.io.FloatArray"] = haxor.io.FloatArray;
haxor.io.FloatArray.__name__ = ["haxor","io","FloatArray"];
haxor.io.FloatArray.Alloc = function(p_data) {
	var b = new haxor.io.FloatArray(p_data.length);
	b.SetRange(p_data);
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
	this.aux = new Int32Array(this.m_buffer.buffer);
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
	this.aux = new Uint16Array(this.m_buffer.buffer);
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
haxor.math = {};
haxor.math.AABB2 = function(p_x,p_y,p_width,p_height) {
	if(p_height == null) p_height = 0;
	if(p_width == null) p_width = 0;
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.m_xMin = p_x;
	this.m_yMin = p_y;
	this.m_xMax = this.m_xMin + p_width;
	this.m_yMax = this.m_yMin + p_height;
};
$hxClasses["haxor.math.AABB2"] = haxor.math.AABB2;
haxor.math.AABB2.__name__ = ["haxor","math","AABB2"];
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
		var hw = this.get_width() * 0.5;
		var hh = this.get_height() * 0.5;
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
		return new haxor.math.Vector2(this.get_width(),this.get_height());
	}
	,set_size: function(v) {
		this.set_width(v.x);
		this.set_height(v.y);
		return v;
	}
	,Validate: function() {
	}
	,Encapsulate: function(p_point) {
		this.set_xMin(haxor.math.Mathf.Min(p_point.x,this.get_xMin()));
		this.set_xMax(haxor.math.Mathf.Max(p_point.x,this.get_xMax()));
		this.set_yMin(haxor.math.Mathf.Min(p_point.y,this.get_yMin()));
		this.set_yMax(haxor.math.Mathf.Max(p_point.y,this.get_yMax()));
	}
	,ToString: function() {
		var s0 = haxor.math.Mathf.RoundPlaces(this.m_xMin,null) + "";
		var s1 = haxor.math.Mathf.RoundPlaces(this.m_xMax,null) + "";
		var s2 = haxor.math.Mathf.RoundPlaces(this.m_yMin,null) + "";
		var s3 = haxor.math.Mathf.RoundPlaces(this.m_yMax,null) + "";
		return "[" + s0 + "," + s1 + "|" + s2 + "," + s3 + "]";
	}
	,__class__: haxor.math.AABB2
};
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
		return haxor.math.Quaternion.FromMatrix(haxor.context.EngineContext.data.get_m4().Set44(this).ToRotation());
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
	,Set44: function(p_matrix) {
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
		return new haxor.math.Vector3(Math.atan2(2.0 * (this.y * this.z + this.w * this.x),this.w * this.w - this.x * this.x - this.y * this.y + this.z * this.z) * 57.295779513082320876798154814105,Math.asin(-2. * (this.x * this.z - this.w * this.y)) * 57.295779513082320876798154814105,Math.atan2(2.0 * (this.x * this.y + this.w * this.z),this.w * this.w + this.x * this.x - this.y * this.y - this.z * this.z) * 57.295779513082320876798154814105);
	}
	,set_euler: function(v) {
		var c = haxor.context.EngineContext.data.get_v3();
		var s = haxor.context.EngineContext.data.get_v3();
		var k = 0.0087266462599716477;
		var e = haxor.context.EngineContext.data.get_v3().Set(v.x * k,v.y * k,v.z * k);
		c.Set(Math.cos(e.x),Math.cos(e.y),Math.cos(e.z));
		s.Set(Math.sin(e.x),Math.sin(e.y),Math.sin(e.z));
		this.x = s.x * c.y * c.z - c.x * s.y * s.z;
		this.y = c.x * s.y * c.z + s.x * c.y * s.z;
		this.z = c.x * c.y * s.z - s.x * s.y * c.z;
		this.w = c.x * c.y * c.z + s.x * s.y * s.z;
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
		if(p_normalize == null) p_normalize = true;
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
	,Multiply3: function(p_v) {
		var l = Math.sqrt(p_v.x * p_v.x + p_v.y * p_v.y + p_v.z * p_v.z);
		var nl = 1.0 / l;
		p_v.x *= nl;
		p_v.y *= nl;
		p_v.z *= nl;
		var qv = new haxor.math.Quaternion(p_v.x,p_v.y,p_v.z,0);
		var a = new haxor.math.Quaternion(this.x,this.y,this.z,this.w);
		a.Multiply(qv.Multiply(new haxor.math.Quaternion(-this.x,-this.y,-this.z,this.w)));
		p_v.x = a.x * l;
		p_v.y = a.y * l;
		p_v.z = a.z * l;
		return p_v;
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
