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
	this.m_uid = haxor.context.HaxorContext.uid++;
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
	haxor.context.HaxorContext.resources.Add(this);
};
$hxClasses["haxor.core.Resource"] = haxor.core.Resource;
haxor.core.Resource.__name__ = ["haxor","core","Resource"];
haxor.core.Resource.__interfaces__ = [haxor.core.IDisposable];
haxor.core.Resource.Destroy = function(p_target) {
	if(p_target.m_destroyed) return;
	p_target.m_destroyed = true;
	if(p_target.m_is_behaviour) {
		var b = p_target;
		b.UpdateContextFlag(false);
	}
	haxor.context.HaxorContext.disposables.Add(p_target);
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
			if(p_flag) haxor.context.HaxorContext.update.Add(this); else haxor.context.HaxorContext.update.Remove(this);
		}
		if(this.m_is_renderable) {
			if(p_flag) haxor.context.HaxorContext.render.Add(this); else haxor.context.HaxorContext.render.Remove(this);
		}
		if(this.m_is_resizeable) {
			if(p_flag) haxor.context.HaxorContext.resize.Add(this); else haxor.context.HaxorContext.resize.Remove(this);
		}
	}
	,__class__: haxor.component.Behaviour
});
haxor.core.BaseApplication = function() {
	haxor.component.Behaviour.call(this);
	haxor.core.BaseApplication.m_instance = this;
	this.m_scenes = [];
	haxor.core.Time.Initialize();
	haxor.graphics.Screen.Initialize();
	haxor.graphics.Screen.m_application = this;
	this.set_fps(60);
	this.m_frame_ms = haxor.core.Time.m_clock;
	this.m_platform = haxor.core.Platform.Unknown;
	this.m_graphics = new haxor.platform.graphics.Graphics(this);
	this.m_engine = new haxor.core.Engine(this);
};
$hxClasses["haxor.core.BaseApplication"] = haxor.core.BaseApplication;
haxor.core.BaseApplication.__name__ = ["haxor","core","BaseApplication"];
haxor.core.BaseApplication.__super__ = haxor.component.Behaviour;
haxor.core.BaseApplication.prototype = $extend(haxor.component.Behaviour.prototype,{
	get_protocol: function() {
		if(window.location.protocol.toLowerCase() == "file:") return haxor.core.ApplicationProtocol.File;
		if(window.location.protocol.toLowerCase() == "http:") return haxor.core.ApplicationProtocol.HTTP;
		if(window.location.protocol.toLowerCase() == "https:") return haxor.core.ApplicationProtocol.HTTPS;
		return haxor.core.ApplicationProtocol.Unknown;
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
		this.m_mspf = Math.floor(1.0 / f * 1000.0);
		return v;
	}
	,get_engine: function() {
		return this.m_engine;
	}
	,get_graphics: function() {
		return this.m_graphics;
	}
	,get_platform: function() {
		return this.m_platform;
	}
	,LoadScene: function(p_name,p_clear) {
		if(p_clear == null) p_clear = true;
	}
	,Load: function() {
		return true;
	}
	,Initialize: function() {
	}
	,LoadComplete: function() {
		haxor.core.Console.Log("Application> Initialize.",3);
		this.Initialize();
	}
	,Update: function() {
		haxor.core.Time.Update();
		this.CheckResize();
		this.m_engine.Update();
		this.m_engine.Collect();
	}
	,Render: function() {
		if(haxor.core.Time.m_clock - this.m_frame_ms >= this.m_mspf) {
			this.m_frame_ms = haxor.core.Time.m_clock;
			this.m_graphics.Focus();
			this.m_engine.Render();
			this.m_graphics.Flush();
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
		haxor.core.Console.Log("Application> Resize [" + haxor.graphics.Screen.m_width + "," + haxor.graphics.Screen.m_height + "]",4);
		this.m_graphics.Resize();
		this.m_engine.Resize();
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
};
Main.__super__ = haxor.core.Application;
Main.prototype = $extend(haxor.core.Application.prototype,{
	Load: function() {
		return true;
	}
	,Initialize: function() {
		haxor.core.Console.Log("Initialize!");
	}
	,OnUpdate: function() {
	}
	,OnRender: function() {
		this.m_graphics.Clear(1.0,0.0,1.0);
	}
	,__class__: Main
});
Math.__name__ = ["Math"];
var Std = function() { };
$hxClasses["Std"] = Std;
Std.__name__ = ["Std"];
Std.parseInt = function(x) {
	var v = parseInt(x,10);
	if(v == 0 && (HxOverrides.cca(x,1) == 120 || HxOverrides.cca(x,1) == 88)) v = parseInt(x);
	if(isNaN(v)) return null;
	return v;
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
haxor.context = {};
haxor.context.HaxorContext = function() { };
$hxClasses["haxor.context.HaxorContext"] = haxor.context.HaxorContext;
haxor.context.HaxorContext.__name__ = ["haxor","context","HaxorContext"];
haxor.context.HaxorContext.Initialize = function() {
	haxor.context.HaxorContext.update = new haxor.context.Process("process.update",haxor.context.HaxorContext.maxNodes);
	haxor.context.HaxorContext.render = new haxor.context.Process("process.render",haxor.context.HaxorContext.maxNodes);
	haxor.context.HaxorContext.resize = new haxor.context.Process("process.resize",haxor.context.HaxorContext.maxNodes);
	haxor.context.HaxorContext.resources = new haxor.context.Process("process.resources",haxor.context.HaxorContext.maxNodes);
	haxor.context.HaxorContext.disposables = new haxor.context.Process("process.disposbales",haxor.context.HaxorContext.maxNodes);
};
haxor.context.Process = function(p_name,p_size) {
	this.name = p_name;
	this._cid_ = haxor.context.Process.m_cid++;
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
haxor.context.Process.prototype = {
	get_length: function() {
		return this.m_length;
	}
	,Add: function(p_item) {
		var iid = p_item.m_pid[this._cid_];
		if(iid >= 0) return;
		this.list[this.m_length] = p_item;
		p_item.m_pid[this._cid_] = this.m_length++;
		console.log(this.name + " " + this.m_length);
	}
	,Remove: function(p_item) {
		debugger;
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
};
haxor.core.Platform = { __ename__ : true, __constructs__ : ["Unknown","Windows","Android","MacOS","iOS","HTML","NodeJS"] };
haxor.core.Platform.Unknown = ["Unknown",0];
haxor.core.Platform.Unknown.__enum__ = haxor.core.Platform;
haxor.core.Platform.Windows = ["Windows",1];
haxor.core.Platform.Windows.__enum__ = haxor.core.Platform;
haxor.core.Platform.Android = ["Android",2];
haxor.core.Platform.Android.__enum__ = haxor.core.Platform;
haxor.core.Platform.MacOS = ["MacOS",3];
haxor.core.Platform.MacOS.__enum__ = haxor.core.Platform;
haxor.core.Platform.iOS = ["iOS",4];
haxor.core.Platform.iOS.__enum__ = haxor.core.Platform;
haxor.core.Platform.HTML = ["HTML",5];
haxor.core.Platform.HTML.__enum__ = haxor.core.Platform;
haxor.core.Platform.NodeJS = ["NodeJS",6];
haxor.core.Platform.NodeJS.__enum__ = haxor.core.Platform;
haxor.core.ApplicationProtocol = { __ename__ : true, __constructs__ : ["Unknown","File","HTTP","HTTPS"] };
haxor.core.ApplicationProtocol.Unknown = ["Unknown",0];
haxor.core.ApplicationProtocol.Unknown.__enum__ = haxor.core.ApplicationProtocol;
haxor.core.ApplicationProtocol.File = ["File",1];
haxor.core.ApplicationProtocol.File.__enum__ = haxor.core.ApplicationProtocol;
haxor.core.ApplicationProtocol.HTTP = ["HTTP",2];
haxor.core.ApplicationProtocol.HTTP.__enum__ = haxor.core.ApplicationProtocol;
haxor.core.ApplicationProtocol.HTTPS = ["HTTPS",3];
haxor.core.ApplicationProtocol.HTTPS.__enum__ = haxor.core.ApplicationProtocol;
haxor.core.Console = function() { };
$hxClasses["haxor.core.Console"] = haxor.core.Console;
haxor.core.Console.__name__ = ["haxor","core","Console"];
haxor.core.Console.Log = function(p_msg,p_level) {
	if(p_level == null) p_level = 0;
	if(haxor.core.Console.verbose >= p_level) console.log(p_msg);
};
haxor.core.EngineState = { __ename__ : true, __constructs__ : ["Play","Editor"] };
haxor.core.EngineState.Play = ["Play",0];
haxor.core.EngineState.Play.__enum__ = haxor.core.EngineState;
haxor.core.EngineState.Editor = ["Editor",1];
haxor.core.EngineState.Editor.__enum__ = haxor.core.EngineState;
haxor.core.Engine = function(p_application) {
	this.m_application = p_application;
	this.state = haxor.core.EngineState.Play;
};
$hxClasses["haxor.core.Engine"] = haxor.core.Engine;
haxor.core.Engine.__name__ = ["haxor","core","Engine"];
haxor.core.Engine.prototype = {
	Collect: function() {
		var dispose_p = haxor.context.HaxorContext.disposables;
		var _g1 = 0;
		var _g = haxor.context.HaxorContext.collectRate;
		while(_g1 < _g) {
			var i = _g1++;
			if(dispose_p.get_length() <= 0) break;
			var o = dispose_p.list[0];
			o.OnDestroy();
			dispose_p.Remove(o);
		}
	}
	,Update: function() {
		if(this.state == haxor.core.EngineState.Editor) return;
		var update_p = haxor.context.HaxorContext.update;
		var _g1 = 0;
		var _g = update_p.get_length();
		while(_g1 < _g) {
			var i = _g1++;
			var r = update_p.list[i];
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
			update_p.list[i].OnUpdate();
		}
	}
	,Render: function() {
		var render_p = haxor.context.HaxorContext.render;
		var _g1 = 0;
		var _g = render_p.get_length();
		while(_g1 < _g) {
			var i = _g1++;
			var r = render_p.list[i];
			if(r.m_destroyed) continue;
			render_p.list[i].OnRender();
		}
	}
	,Resize: function() {
		if(this.state == haxor.core.EngineState.Editor) return;
		var resize_p = haxor.context.HaxorContext.resize;
		var _g1 = 0;
		var _g = resize_p.get_length();
		while(_g1 < _g) {
			var i = _g1++;
			var r = resize_p.list[i];
			if(r.m_destroyed) continue;
			resize_p.list[i].OnResize(haxor.graphics.Screen.m_width,haxor.graphics.Screen.m_height);
		}
	}
	,__class__: haxor.core.Engine
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
haxor.core.Time.Initialize = function() {
	haxor.core.Time.m_clock = 0.0;
	haxor.core.Time.m_last_clock = 0.0;
	haxor.core.Time.m_delta = 0.0;
	haxor.core.Time.UpdateClock();
};
haxor.core.Time.Update = function() {
	haxor.core.Time.UpdateClock();
	haxor.core.Time.m_delta = (haxor.core.Time.m_clock - haxor.core.Time.m_last_clock) * 0.001;
	haxor.core.Time.m_last_clock = haxor.core.Time.m_clock;
};
haxor.core.Time.UpdateClock = function() {
};
haxor.graphics = {};
haxor.graphics.CursorMode = { __ename__ : true, __constructs__ : ["Show","Hide","Lock"] };
haxor.graphics.CursorMode.Show = ["Show",0];
haxor.graphics.CursorMode.Show.__enum__ = haxor.graphics.CursorMode;
haxor.graphics.CursorMode.Hide = ["Hide",1];
haxor.graphics.CursorMode.Hide.__enum__ = haxor.graphics.CursorMode;
haxor.graphics.CursorMode.Lock = ["Lock",2];
haxor.graphics.CursorMode.Lock.__enum__ = haxor.graphics.CursorMode;
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
haxor.platform.graphics = {};
haxor.platform.graphics.GraphicAPI = { __ename__ : true, __constructs__ : ["None","OpenGL","OpenGLES","DirectX","WebGL"] };
haxor.platform.graphics.GraphicAPI.None = ["None",0];
haxor.platform.graphics.GraphicAPI.None.__enum__ = haxor.platform.graphics.GraphicAPI;
haxor.platform.graphics.GraphicAPI.OpenGL = ["OpenGL",1];
haxor.platform.graphics.GraphicAPI.OpenGL.__enum__ = haxor.platform.graphics.GraphicAPI;
haxor.platform.graphics.GraphicAPI.OpenGLES = ["OpenGLES",2];
haxor.platform.graphics.GraphicAPI.OpenGLES.__enum__ = haxor.platform.graphics.GraphicAPI;
haxor.platform.graphics.GraphicAPI.DirectX = ["DirectX",3];
haxor.platform.graphics.GraphicAPI.DirectX.__enum__ = haxor.platform.graphics.GraphicAPI;
haxor.platform.graphics.GraphicAPI.WebGL = ["WebGL",4];
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
	,Focus: function() {
	}
	,Flush: function() {
	}
	,Destroy: function() {
	}
	,Resize: function() {
	}
	,Clear: function(p_r,p_g,p_b,p_a,p_depth) {
		if(p_depth == null) p_depth = 1.0;
		if(p_a == null) p_a = 1.0;
	}
	,__class__: haxor.platform.graphics.GraphicContext
};
haxor.platform.graphics.WebGL = function(p_application) {
	haxor.platform.graphics.GraphicContext.call(this,p_application);
	this.api = haxor.platform.graphics.GraphicAPI.WebGL;
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
		console.log("resize!!!");
		this.m_canvas.width = this.m_container.clientWidth;
		this.m_canvas.height = this.m_container.clientHeight;
	}
	,Clear: function(p_r,p_g,p_b,p_a,p_depth) {
		if(p_depth == null) p_depth = 1.0;
		if(p_a == null) p_a = 1.0;
		this.c.clearDepth(p_depth);
		this.c.clearColor(p_r,p_g,p_b,p_a);
		this.c.clear(16640);
	}
	,__class__: haxor.platform.graphics.WebGL
});
haxor.platform.graphics.Graphics = function(p_application) {
	haxor.platform.graphics.WebGL.call(this,p_application);
};
$hxClasses["haxor.platform.graphics.Graphics"] = haxor.platform.graphics.Graphics;
haxor.platform.graphics.Graphics.__name__ = ["haxor","platform","graphics","Graphics"];
haxor.platform.graphics.Graphics.__super__ = haxor.platform.graphics.WebGL;
haxor.platform.graphics.Graphics.prototype = $extend(haxor.platform.graphics.WebGL.prototype,{
	__class__: haxor.platform.graphics.Graphics
});
var js = {};
js.Boot = function() { };
$hxClasses["js.Boot"] = js.Boot;
js.Boot.__name__ = ["js","Boot"];
js.Boot.getClass = function(o) {
	if((o instanceof Array) && o.__enum__ == null) return Array; else return o.__class__;
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
haxor.platform.html.Entry = function() { };
$hxClasses["haxor.platform.html.Entry"] = haxor.platform.html.Entry;
haxor.platform.html.Entry.__name__ = ["haxor","platform","html","Entry"];
haxor.platform.html.Entry.OnWindowLoad = function(p_event) {
	haxor.context.HaxorContext.Initialize();
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
	var e = new haxor.core.Entity("application");
	haxor.platform.html.Entry.m_application = e.AddComponent(app_class);
	if(!js.Boot.__instanceof(haxor.platform.html.Entry.m_application,haxor.core.BaseApplication)) {
		haxor.core.Console.Log("Haxor> Error. Class [" + app_class_type + "] does not extends Application!");
		return;
	}
	haxor.core.Console.Log("Haxor> Application [" + app_class_type + "] created successfully!",1);
	haxor.platform.html.Entry.m_application.m_graphics.Initialize(app_container_id);
	haxor.platform.html.Entry.m_application.m_graphics.CheckExtensions();
	if(($_=window,$bind($_,$_.requestAnimationFrame)) != null) window.requestAnimationFrame(haxor.platform.html.Entry.RequestAnimationCallback);
	if(haxor.platform.html.Entry.m_application.Load()) haxor.platform.html.Entry.m_application.LoadComplete();
};
haxor.platform.html.Entry.RequestAnimationCallback = function(p_time) {
	haxor.core.Time.m_clock = p_time;
	haxor.platform.html.Entry.m_application.Update();
	haxor.platform.html.Entry.m_application.Render();
	window.requestAnimationFrame(haxor.platform.html.Entry.RequestAnimationCallback);
	return true;
};
haxor.platform.html.ApplicationProtocol = { __ename__ : true, __constructs__ : ["Unknown","File","HTTP","HTTPS"] };
haxor.platform.html.ApplicationProtocol.Unknown = ["Unknown",0];
haxor.platform.html.ApplicationProtocol.Unknown.__enum__ = haxor.platform.html.ApplicationProtocol;
haxor.platform.html.ApplicationProtocol.File = ["File",1];
haxor.platform.html.ApplicationProtocol.File.__enum__ = haxor.platform.html.ApplicationProtocol;
haxor.platform.html.ApplicationProtocol.HTTP = ["HTTP",2];
haxor.platform.html.ApplicationProtocol.HTTP.__enum__ = haxor.platform.html.ApplicationProtocol;
haxor.platform.html.ApplicationProtocol.HTTPS = ["HTTPS",3];
haxor.platform.html.ApplicationProtocol.HTTPS.__enum__ = haxor.platform.html.ApplicationProtocol;
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
window.onload = haxor.platform.html.Entry.OnWindowLoad;
haxor.context.HaxorContext.uid = 0;
haxor.context.HaxorContext.maxNodes = 1000;
haxor.context.HaxorContext.collectRate = 10;
haxor.context.Process.m_cid = 0;
haxor.core.Console.verbose = 0;
Main.main();
})();
