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
var IMap = function() { };
$hxClasses["IMap"] = IMap;
IMap.__name__ = ["IMap"];
Math.__name__ = ["Math"];
var Reflect = function() { };
$hxClasses["Reflect"] = Reflect;
Reflect.__name__ = ["Reflect"];
Reflect.field = function(o,field) {
	try {
		return o[field];
	} catch( e ) {
		return null;
	}
};
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
var ValueType = { __ename__ : true, __constructs__ : ["TNull","TInt","TFloat","TBool","TObject","TFunction","TClass","TEnum","TUnknown"] };
ValueType.TNull = ["TNull",0];
ValueType.TNull.__enum__ = ValueType;
ValueType.TInt = ["TInt",1];
ValueType.TInt.__enum__ = ValueType;
ValueType.TFloat = ["TFloat",2];
ValueType.TFloat.__enum__ = ValueType;
ValueType.TBool = ["TBool",3];
ValueType.TBool.__enum__ = ValueType;
ValueType.TObject = ["TObject",4];
ValueType.TObject.__enum__ = ValueType;
ValueType.TFunction = ["TFunction",5];
ValueType.TFunction.__enum__ = ValueType;
ValueType.TClass = function(c) { var $x = ["TClass",6,c]; $x.__enum__ = ValueType; return $x; };
ValueType.TEnum = function(e) { var $x = ["TEnum",7,e]; $x.__enum__ = ValueType; return $x; };
ValueType.TUnknown = ["TUnknown",8];
ValueType.TUnknown.__enum__ = ValueType;
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
Type["typeof"] = function(v) {
	var _g = typeof(v);
	switch(_g) {
	case "boolean":
		return ValueType.TBool;
	case "string":
		return ValueType.TClass(String);
	case "number":
		if(Math.ceil(v) == v % 2147483648.0) return ValueType.TInt;
		return ValueType.TFloat;
	case "object":
		if(v == null) return ValueType.TNull;
		var e = v.__enum__;
		if(e != null) return ValueType.TEnum(e);
		var c;
		if((v instanceof Array) && v.__enum__ == null) c = Array; else c = v.__class__;
		if(c != null) return ValueType.TClass(c);
		return ValueType.TObject;
	case "function":
		if(v.__name__ || v.__ename__) return ValueType.TObject;
		return ValueType.TFunction;
	case "undefined":
		return ValueType.TNull;
	default:
		return ValueType.TUnknown;
	}
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
	,get_parent: function() {
		return this._parent;
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
	,__properties__: {get_parent:"get_parent",set_nodeValue:"set_nodeValue",get_nodeValue:"get_nodeValue",set_nodeName:"set_nodeName",get_nodeName:"get_nodeName"}
};
var haxe = {};
haxe.Timer = function(time_ms) {
	var me = this;
	this.id = setInterval(function() {
		me.run();
	},time_ms);
};
$hxClasses["haxe.Timer"] = haxe.Timer;
haxe.Timer.__name__ = ["haxe","Timer"];
haxe.Timer.delay = function(f,time_ms) {
	var t = new haxe.Timer(time_ms);
	t.run = function() {
		t.stop();
		f();
	};
	return t;
};
haxe.Timer.stamp = function() {
	return new Date().getTime() / 1000;
};
haxe.Timer.prototype = {
	stop: function() {
		if(this.id == null) return;
		clearInterval(this.id);
		this.id = null;
	}
	,run: function() {
	}
	,__class__: haxe.Timer
};
haxe.ds = {};
haxe.ds.IntMap = function() {
	this.h = { };
};
$hxClasses["haxe.ds.IntMap"] = haxe.ds.IntMap;
haxe.ds.IntMap.__name__ = ["haxe","ds","IntMap"];
haxe.ds.IntMap.__interfaces__ = [IMap];
haxe.ds.IntMap.prototype = {
	set: function(key,value) {
		this.h[key] = value;
	}
	,get: function(key) {
		return this.h[key];
	}
	,exists: function(key) {
		return this.h.hasOwnProperty(key);
	}
	,__class__: haxe.ds.IntMap
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
	,get: function(key) {
		return this.h[key.__id__];
	}
	,exists: function(key) {
		return this.h.__keys__[key.__id__] != null;
	}
	,keys: function() {
		var a = [];
		for( var key in this.h.__keys__ ) {
		if(this.h.hasOwnProperty(key)) a.push(this.h.__keys__[key]);
		}
		return HxOverrides.iter(a);
	}
	,iterator: function() {
		return { ref : this.h, it : this.keys(), hasNext : function() {
			return this.it.hasNext();
		}, next : function() {
			var i = this.it.next();
			return this.ref[i.__id__];
		}};
	}
	,__class__: haxe.ds.ObjectMap
};
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
haxe.io = {};
haxe.io.Eof = function() { };
$hxClasses["haxe.io.Eof"] = haxe.io.Eof;
haxe.io.Eof.__name__ = ["haxe","io","Eof"];
haxe.io.Eof.prototype = {
	toString: function() {
		return "Eof";
	}
	,__class__: haxe.io.Eof
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
var haxor = {};
haxor.core = {};
haxor.core.IDisposable = function() { };
$hxClasses["haxor.core.IDisposable"] = haxor.core.IDisposable;
haxor.core.IDisposable.__name__ = ["haxor","core","IDisposable"];
haxor.core.IDisposable.prototype = {
	__class__: haxor.core.IDisposable
};
haxor.core.Resource = function() {
	this.m_id = haxor.core.Resource.m_hashCode++;
	this.m_destroyed = false;
	var nt = Type.getClassName(Type.getClass(this)).split(".");
	nt.reverse();
	this.m_name = nt[0] + StringTools.hex(this.m_id);
	this.m_typeFullName = Type.getClassName(Type.getClass(this));
	this.m_typeName = nt[0];
	this.m_typeClass = Type.getClass(this);
};
$hxClasses["haxor.core.Resource"] = haxor.core.Resource;
haxor.core.Resource.__name__ = ["haxor","core","Resource"];
haxor.core.Resource.__interfaces__ = [haxor.core.IDisposable];
haxor.core.Resource.Instantiate = function(p_target) {
	return p_target.Clone();
};
haxor.core.Resource.Destroy = function(p_target) {
	if(p_target == null) {
		if(haxor.core.Console.get__console() != null) haxor.core.Console.get__console().error("Haxor> Trying to Destroy NULL object!");
		return;
	}
	if(js.Boot.__instanceof(p_target,haxor.component.Transform)) {
		if(haxor.core.Console.get__console() != null) haxor.core.Console.get__console().error("Haxor> Removing an Entity transform is not allowed.");
		return;
	}
	haxor.core.Engine.AddDisposable(p_target);
};
haxor.core.Resource.prototype = {
	get_name: function() {
		return this.m_name;
	}
	,set_name: function(v) {
		this.m_name = v;
		return this.m_name;
	}
	,get_id: function() {
		return this.m_id;
	}
	,get_application: function() {
		return haxor.core.Engine.get_application();
	}
	,get_destroyed: function() {
		return this.m_destroyed;
	}
	,GetType: function() {
		return this.m_typeClass;
	}
	,GetTypeFullName: function() {
		return this.m_typeFullName;
	}
	,GetTypeName: function() {
		return this.m_typeName;
	}
	,Clone: function() {
		return null;
	}
	,OnDestroy: function() {
	}
	,__class__: haxor.core.Resource
	,__properties__: {get_destroyed:"get_destroyed",get_application:"get_application",get_id:"get_id",set_name:"set_name",get_name:"get_name"}
};
haxor.core.Entity = function() {
	haxor.core.Resource.call(this);
	this.layer = 1;
	this.m_enabled = true;
	this.m_components = new Array();
	this.m_transform = this.AddComponent(haxor.component.Transform);
};
$hxClasses["haxor.core.Entity"] = haxor.core.Entity;
haxor.core.Entity.__name__ = ["haxor","core","Entity"];
haxor.core.Entity.__super__ = haxor.core.Resource;
haxor.core.Entity.prototype = $extend(haxor.core.Resource.prototype,{
	get_transform: function() {
		return this.m_transform;
	}
	,get_camera: function() {
		return this.GetComponent(haxor.component.Camera);
	}
	,get_data: function() {
		return this.GetComponent(haxor.component.AssetData);
	}
	,get_animation: function() {
		return this.GetComponent(haxor.component.Animation);
	}
	,get_renderer: function() {
		return this.GetComponent(haxor.component.Renderer);
	}
	,get_rigidbody: function() {
		if(this.m_rigidbody != null) {
			if(!this.m_rigidbody.get_destroyed()) return this.m_rigidbody;
		}
		this.m_rigidbody = this.GetComponent(haxor.component.RigidBody);
		return this.m_rigidbody;
	}
	,get_enabled: function() {
		return this.m_enabled;
	}
	,set_enabled: function(v) {
		if(this.m_enabled == v) return v;
		this.m_enabled = v;
		var _g1 = 0;
		var _g = this.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(js.Boot.__instanceof(this.m_components[i],haxor.component.Behaviour)) Reflect.field(this.m_components[i],"CheckEnabled");
		}
		this.RecursiveEnableStep(v,this.get_transform());
		return v;
	}
	,RecursiveEnableStep: function(p_flag,p_transform) {
		var _g1 = 0;
		var _g = p_transform.get_childCount();
		while(_g1 < _g) {
			var i = _g1++;
			p_transform.get_entity().set_enabled(p_flag);
		}
	}
	,get_bounds: function() {
		var b = new haxor.math.AABB3();
		var cl;
		var mr;
		cl = this.GetComponents(haxor.component.MeshRenderer);
		var _g1 = 0;
		var _g = cl.length;
		while(_g1 < _g) {
			var i = _g1++;
			mr = cl[i];
			if(mr.get_mesh() != null) b.Add(mr.get_mesh().get_bounds());
		}
		cl = this.GetComponentsInChildren(haxor.component.MeshRenderer);
		var _g11 = 0;
		var _g2 = cl.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			mr = cl[i1];
			if(mr.get_mesh() != null) b.Add(mr.get_mesh().get_bounds());
		}
		return b;
	}
	,AddComponent: function(p_type) {
		var c = Type.createInstance(p_type,[this]);
		if(js.Boot.__instanceof(c,haxor.component.Behaviour)) {
			var b = c;
			b.set_enabled(this.get_enabled());
		}
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
		this.get_transform().Traverse(function(t) {
			if(res1 != null) return true;
			var l = t.get_entity().GetComponents(p_type);
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
		this.get_transform().Traverse(function(t) {
			var l = t.get_entity().GetComponents(p_type);
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
			haxor.core.Resource.Destroy(this.m_components[i]);
			this.m_components[i] = null;
		}
		var _g11 = 0;
		var _g2 = this.m_transform.get_childCount();
		while(_g11 < _g2) {
			var i1 = _g11++;
			haxor.core.Resource.Destroy(this.m_transform.GetChild(i1).get_entity());
		}
	}
	,__class__: haxor.core.Entity
	,__properties__: $extend(haxor.core.Resource.prototype.__properties__,{get_bounds:"get_bounds",set_enabled:"set_enabled",get_enabled:"get_enabled",get_rigidbody:"get_rigidbody",get_renderer:"get_renderer",get_animation:"get_animation",get_data:"get_data",get_camera:"get_camera",get_transform:"get_transform"})
});
haxor.core.Application = function() {
	haxor.core.Entity.call(this);
	this.set_name("application");
	this.fps = 45;
	haxor.component.Transform.m_root = this.get_transform();
	this.Build();
};
$hxClasses["haxor.core.Application"] = haxor.core.Application;
haxor.core.Application.__name__ = ["haxor","core","Application"];
haxor.core.Application.__properties__ = {get_vendor:"get_vendor",get_protocol:"get_protocol"}
haxor.core.Application.get_protocol = function() {
	if(window.location.protocol == "file:") return haxor.core.ApplicationProtocol.File;
	if(window.location.protocol == "http:") return haxor.core.ApplicationProtocol.HTTP;
	if(window.location.protocol == "https:") return haxor.core.ApplicationProtocol.HTTPS;
	return haxor.core.ApplicationProtocol.Unknown;
};
haxor.core.Application.get_vendor = function() {
	if(haxor.core.Application.m_vendor != null) return haxor.core.Application.m_vendor;
	var vdr = "";
	if(window.msRequestAnimationFrame != null) 		vdr = "-ms-";
	if(window.oRequestAnimationFrame != null)  		vdr = "-o-";
	if(window.webkitRequestAnimationFrame != null)  vdr = "-webkit-";
	if(window.mozRequestAnimationFrame != null)  	vdr = "-moz-";
	return haxor.core.Application.m_vendor = vdr;
};
haxor.core.Application.TraverseDOM = function(p_callback) {
	haxor.core.Application.TraverseDOMStep(window.document.body,p_callback);
};
haxor.core.Application.TraverseDOMStep = function(p_node,p_callback) {
	if(p_node == null) return;
	var l = p_node.childNodes;
	if(l == null) return;
	var _g1 = 0;
	var _g = l.length;
	while(_g1 < _g) {
		var i = _g1++;
		var res = true;
		if(p_callback != null) res = p_callback(l.item(i));
		if(!res) return;
		haxor.core.Application.TraverseDOMStep(l.item(i),p_callback);
	}
};
haxor.core.Application.__super__ = haxor.core.Entity;
haxor.core.Application.prototype = $extend(haxor.core.Entity.prototype,{
	get_stage: function() {
		return this.m_stage;
	}
	,get_loader: function() {
		return this.m_loader;
	}
	,set_loader: function(v) {
		if(this.m_loader != null) return this.m_loader;
		if(v == null) return this.m_loader;
		this.m_loader = v;
		this.get_stage().AddChildAt(v,this.get_stage().get_childCount());
		return this.m_loader;
	}
	,Build: function() {
	}
	,Initialize: function() {
	}
	,Load: function() {
	}
	,LoadStandardFilters: function() {
		haxor.core.Asset.LoadShader("haxor/filter/Blur","./shader/filter/Blur.shader");
		haxor.core.Asset.LoadShader("haxor/filter/Bloom","./shader/filter/Bloom.shader");
		haxor.core.Asset.LoadShader("haxor/filter/FXAA","./shader/filter/FXAA.shader");
		haxor.core.Asset.LoadShader("haxor/filter/Fog","./shader/filter/Fog.shader");
	}
	,LoadPrimitives: function() {
		haxor.core.Asset.LoadCollada("haxor/primitive/cube","./primitive/cube.DAE");
		haxor.core.Asset.LoadCollada("haxor/primitive/sphere","./primitive/sphere.DAE");
		haxor.core.Asset.LoadCollada("haxor/primitive/teapot","./primitive/teapot.DAE");
		haxor.core.Asset.LoadCollada("haxor/primitive/torus","./primitive/torus.DAE");
	}
	,LoadStandardLib: function() {
		haxor.net.Web.root = "http://haxor.thelaborat.org/resources/";
		this.LoadPrimitives();
		haxor.core.Asset.LoadTextureHTML("haxor/texture/logo","./texture/misc/haxor.png");
		haxor.core.Asset.LoadTextureHTML("haxor/skybox/dark_top","./texture/skybox/gradient/dark_top.jpg");
		haxor.core.Asset.LoadTextureHTML("haxor/skybox/dark_sides","./texture/skybox/gradient/dark_sides.jpg");
		haxor.core.Asset.LoadTextureHTML("haxor/skybox/dark_bottom","./texture/skybox/gradient/dark_bottom.jpg");
		haxor.core.Asset.LoadShader("haxor/unlit/FlatTexture","./shader/unlit/FlatTexture.shader");
		haxor.core.Asset.LoadShader("haxor/unlit/FlatTextureSkin","./shader/unlit/FlatTextureSkin.shader");
		haxor.core.Asset.LoadShader("haxor/unlit/FlatSkin","./shader/unlit/FlatSkin.shader");
		haxor.core.Asset.LoadShader("haxor/unlit/Flat","./shader/unlit/Flat.shader");
		haxor.core.Asset.LoadShader("haxor/lightmap/FlatTexture","./shader/lightmap/FlatTexture.shader");
		haxor.core.Asset.LoadShader("haxor/unlit/Particle","./shader/unlit/Particle.shader");
		haxor.core.Asset.LoadShader("haxor/diffuse/DiffuseSkin","./shader/diffuse/DiffuseSkin.shader");
		haxor.core.Asset.LoadShader("haxor/diffuse/ToonSkin","./shader/diffuse/ToonSkin.shader");
		haxor.core.Asset.LoadShader("haxor/diffuse/ToonSkinFalloff","./shader/diffuse/ToonSkinFalloff.shader");
		haxor.core.Asset.LoadShader("haxor/screen/Displacement","./shader/screen/Displacement.shader");
		haxor.core.Asset.LoadMaterial("haxor/material/opaque/unlit/Flat","./material/opaque/unlit/Flat.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/opaque/unlit/FlatTexture","./material/opaque/unlit/FlatTexture.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/opaque/unlit/FlatTextureSkin","./material/opaque/unlit/FlatTextureSkin.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/opaque/lightmap/FlatTexture","./material/opaque/lightmap/FlatTexture.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/opaque/diffuse/DiffuseSkin","./material/opaque/diffuse/DiffuseSkin.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/opaque/diffuse/ToonSkin","./material/opaque/diffuse/ToonSkin.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/transparent/unlit/Flat","./material/transparent/unlit/Flat.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/transparent/unlit/FlatTexture","./material/transparent/unlit/FlatTexture.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/transparent/unlit/FlatTextureSkin","./material/transparent/unlit/FlatTextureSkin.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/transparent/unlit/ParticleAdditive","./material/transparent/unlit/ParticleAdditive.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/transparent/unlit/ParticleAlpha","./material/transparent/unlit/ParticleAlpha.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/opaque/diffuse/Diffuse","./material/opaque/diffuse/Diffuse.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/opaque/diffuse/Flat","./material/opaque/diffuse/Flat.mat");
		haxor.core.Asset.LoadMaterial("haxor/material/screen/Displacement","./material/screen/Displacement.mat");
		this.LoadStandardFilters();
		haxor.core.Asset.LoadTextureHTML("haxor/texture/particle","./texture/particle/particle.png");
		haxor.net.Web.root = "./";
	}
	,OnDependenceLoad: function(p_id) {
	}
	,OnDependenceProgress: function(p_id,p_progress) {
	}
	,OnProgress: function(p_progress) {
	}
	,__class__: haxor.core.Application
	,__properties__: $extend(haxor.core.Entity.prototype.__properties__,{set_loader:"set_loader",get_loader:"get_loader",get_stage:"get_stage"})
});
haxor.Main = function() {
	haxor.core.Application.call(this);
};
$hxClasses["haxor.Main"] = haxor.Main;
haxor.Main.__name__ = ["haxor","Main"];
haxor.Main.main = function() {
};
haxor.Main.__super__ = haxor.core.Application;
haxor.Main.prototype = $extend(haxor.core.Application.prototype,{
	Load: function() {
		this.set_loader(new haxor.ui.HaxorLoader());
		haxor.net.Web.root = "http://haxor.thelaborat.org/resources/";
		haxor.core.Asset.LoadCollada("haxor/primitive/cube","./primitive/cube.DAE");
		haxor.core.Asset.LoadTextureHTML("haxor/texture/logo","./texture/misc/haxor.png");
		haxor.core.Asset.LoadTextureHTML("haxor/skybox/dark_top","./texture/skybox/gradient/dark_top.jpg");
		haxor.core.Asset.LoadTextureHTML("haxor/skybox/dark_sides","./texture/skybox/gradient/dark_sides.jpg");
		haxor.core.Asset.LoadTextureHTML("haxor/skybox/dark_bottom","./texture/skybox/gradient/dark_bottom.jpg");
		haxor.core.Asset.LoadShader("haxor/internal/Skybox","./shader/internal/Skybox.shader");
		haxor.core.Asset.LoadShader("haxor/unlit/FlatTexture","./shader/unlit/FlatTexture.shader");
		haxor.core.Asset.LoadMaterial("haxor/material/opaque/unlit/FlatTexture","./material/opaque/unlit/FlatTexture.mat");
	}
	,Initialize: function() {
		var camera_orbit = haxor.component.CameraOrbit.Create(1.0,45,-30);
		camera_orbit.smooth = 5.0;
		var camera = camera_orbit.get_camera();
		camera.background = haxor.math.Color.FromHex("0x333333");
		var skybox = new haxor.texture.TextureCube();
		skybox.set_px(haxor.core.Asset.Get("haxor/skybox/dark_sides"));
		skybox.set_pz(haxor.core.Asset.Get("haxor/skybox/dark_sides"));
		skybox.set_py(haxor.core.Asset.Get("haxor/skybox/dark_top"));
		skybox.set_nx(haxor.core.Asset.Get("haxor/skybox/dark_sides"));
		skybox.set_nz(haxor.core.Asset.Get("haxor/skybox/dark_sides"));
		skybox.set_ny(haxor.core.Asset.Get("haxor/skybox/dark_bottom"));
		skybox.Apply();
		camera.skybox = skybox;
		camera.clear = haxor.component.ClearFlag.SkyboxDepth;
		var orbit_input = camera_orbit.AddComponent(haxor.component.CameraOrbitInput);
		orbit_input.zoomSpeed = 0.5;
		var cube = haxor.core.Asset.Get("haxor/primitive/cube").GetAsset();
		var cube_renderer = cube.GetComponentInChildren(haxor.component.MeshRenderer);
		cube_renderer.material = haxor.core.Resource.Instantiate(haxor.core.Asset.Get("haxor/material/opaque/unlit/FlatTexture"));
		cube_renderer.material.SetUniform("DiffuseTexture",haxor.core.Asset.Get("haxor/texture/logo"));
		var cube_data = cube.GetComponentInChildren(haxor.component.AssetData);
		haxor.core.Console.LogWarning("cube.asset.description = " + Std.string(cube_data.content.asset.description));
		haxor.core.Console.LogWarning("cube.readme = " + Std.string(cube_data.content.readme));
		haxor.core.Console.LogWarning("cube.number = " + Std.string(cube_data.content.number));
		haxor.core.Console.LogWarning("cube.boolean = " + Std.string(cube_data.content["boolean"]));
		this.fps = 60;
		debugger;
		haxe.Timer.delay(function() {
			console.log(haxor.component.Transform.get_root().OutputHierarchy());
		},1000);
	}
	,__class__: haxor.Main
});
haxor.api = {};
haxor.api.BufferAPI = function() { };
$hxClasses["haxor.api.BufferAPI"] = haxor.api.BufferAPI;
haxor.api.BufferAPI.__name__ = ["haxor","api","BufferAPI"];
haxor.api.BufferAPI.__properties__ = {get_gui:"get_gui",get_screen:"get_screen",get_skybox:"get_skybox"}
haxor.api.BufferAPI.get_skybox = function() {
	if(haxor.api.BufferAPI.m_skybox != null) return haxor.api.BufferAPI.m_skybox;
	haxor.api.BufferAPI.m_skybox = new haxor.graphics.Mesh3();
	haxor.api.BufferAPI.m_skybox.set_name("$Skybox");
	haxor.api.BufferAPI.m_skybox.set_vertex([new haxor.math.Vector3(-1,1,1),new haxor.math.Vector3(-1,-1,1),new haxor.math.Vector3(1,-1,1),new haxor.math.Vector3(-1,1,1),new haxor.math.Vector3(1,-1,1),new haxor.math.Vector3(1,1,1)]);
	return haxor.api.BufferAPI.m_skybox;
};
haxor.api.BufferAPI.get_screen = function() {
	if(haxor.api.BufferAPI.m_screen != null) return haxor.api.BufferAPI.m_screen;
	haxor.api.BufferAPI.m_screen = new haxor.graphics.Mesh3();
	haxor.api.BufferAPI.m_screen.set_name("$Screen");
	haxor.api.BufferAPI.m_screen.set_vertex([new haxor.math.Vector3(-1,1,1),new haxor.math.Vector3(-1,-1,1),new haxor.math.Vector3(1,-1,1),new haxor.math.Vector3(-1,1,1),new haxor.math.Vector3(1,-1,1),new haxor.math.Vector3(1,1,1)]);
	return haxor.api.BufferAPI.m_screen;
};
haxor.api.BufferAPI.get_gui = function() {
	if(haxor.api.BufferAPI.m_gui != null) return haxor.api.BufferAPI.m_gui;
	haxor.api.BufferAPI.m_gui = new haxor.graphics.Mesh3();
	haxor.api.BufferAPI.m_gui.set_name("$GUIMesh");
	haxor.api.BufferAPI.m_gui.set_vertex([new haxor.math.Vector3(0.0,1.0,1),new haxor.math.Vector3(0.0,0.0,1),new haxor.math.Vector3(1.0,0.0,1),new haxor.math.Vector3(0.0,1.0,1),new haxor.math.Vector3(1.0,0.0,1),new haxor.math.Vector3(1.0,1.0,1)]);
	return haxor.api.BufferAPI.m_gui;
};
haxor.api.BufferAPI.Initialize = function(p_context) {
	haxor.api.BufferAPI.c = p_context;
	haxor.api.BufferAPI.m_buffers = new haxe.ds.StringMap();
	haxor.api.BufferAPI.m_boundBuffers = new haxe.ds.ObjectMap();
	haxor.api.BufferAPI.m_enabledAttribs = [];
	haxor.api.BufferAPI.m_active = -1;
	var _g = 0;
	while(_g < 256) {
		var i = _g++;
		haxor.api.BufferAPI.m_enabledAttribs.push(false);
	}
	haxor.api.BufferAPI.m_junk = haxor.api.BufferAPI.c.createBuffer();
	haxor.api.BufferAPI.c.bindBuffer(34962,haxor.api.BufferAPI.m_junk);
	var jb = new Float32Array(400000);
	var _g1 = 0;
	var _g2 = jb.length;
	while(_g1 < _g2) {
		var i1 = _g1++;
		jb[i1] = 1.0;
	}
	haxor.api.BufferAPI.c.bufferData(34962,jb,35044);
};
haxor.api.BufferAPI.Create = function(p_mesh,p_buffer) {
	var b = haxor.api.BufferAPI.c.createBuffer();
	var key = p_buffer + p_mesh.get_id();
	haxor.api.BufferAPI.m_buffers.set(key,b);
	return b;
};
haxor.api.BufferAPI.Apply = function(p_mesh,p_buffer) {
	var t = p_mesh.get_topology();
	if(t == null) return;
	var mf = haxor.api.BufferAPI.ModeFlag(p_mesh.get_mode());
	var ist = p_buffer == "$topology";
	var b = haxor.api.BufferAPI.Get(p_mesh,p_buffer);
	if(b != null) {
		haxor.api.BufferAPI.c.deleteBuffer(b);
		b = null;
	}
	if(b == null) b = haxor.api.BufferAPI.Create(p_mesh,p_buffer);
	var d = p_mesh.Get(p_buffer);
	haxor.api.BufferAPI.c.bindBuffer(ist?34963:34962,b);
	haxor.api.BufferAPI.c.bufferData(ist?34963:34962,ist?t:d,mf);
};
haxor.api.BufferAPI.Destroy = function(p_mesh,p_buffer) {
	var b = haxor.api.BufferAPI.Get(p_mesh,p_buffer);
	if(b != null) haxor.api.BufferAPI.c.deleteBuffer(b);
};
haxor.api.BufferAPI.GetAttribLocation = function(p,a,m) {
	if(m.m_locations.exists(a)) return m.m_locations.get(a);
	var loc = haxor.api.BufferAPI.c.getAttribLocation(p,a);
	m.m_locations.set(a,loc);
	return loc;
};
haxor.api.BufferAPI.BindArrayBuffer = function(p_buffer) {
};
haxor.api.BufferAPI.Bind = function(p_mesh,p_program) {
	if(haxor.api.BufferAPI.m_current != p_mesh) haxor.api.BufferAPI.Finish();
	haxor.api.BufferAPI.m_current = p_mesh;
	var al = p_mesh.get_attribs();
	var b;
	var _g1 = 0;
	var _g = al.length;
	while(_g1 < _g) {
		var i = _g1++;
		var a = al[i];
		var mb = haxor.api.BufferAPI.Get(p_mesh,a);
		if(mb == null) b = haxor.api.BufferAPI.m_junk; else b = mb;
		var es;
		if(mb == null) es = 4; else es = p_mesh.ElementSize(a);
		if(es <= 0) continue;
		var loc = haxor.api.ShaderAPI.GetAttribute(a);
		if(loc < 0) continue;
		var type = 5126;
		haxor.api.BufferAPI.c.bindBuffer(34962,b);
		if(!haxor.api.BufferAPI.m_enabledAttribs[loc]) {
			haxor.api.BufferAPI.c.enableVertexAttribArray(loc);
			haxor.api.BufferAPI.m_enabledAttribs[loc] = true;
			haxor.api.BufferAPI.m_active = Math.max(haxor.api.BufferAPI.m_active,loc);
		}
		haxor.api.BufferAPI.c.vertexAttribPointer(loc,es,type,false,0,0);
	}
	if(p_mesh.get_indexed()) {
		b = haxor.api.BufferAPI.Get(p_mesh,"$topology");
		if(b != null) haxor.api.BufferAPI.c.bindBuffer(34963,b);
	}
};
haxor.api.BufferAPI.Finish = function() {
	var _g = 0;
	while(_g < 6) {
		var i = _g++;
		haxor.api.BufferAPI.c.disableVertexAttribArray(i);
		haxor.api.BufferAPI.m_enabledAttribs[i] = false;
	}
	haxor.api.BufferAPI.m_active = 0;
};
haxor.api.BufferAPI.Draw = function(p_mesh) {
	var pf = haxor.api.BufferAPI.PrimitiveFlag(p_mesh.get_primitive());
	if(p_mesh.get_indexed()) haxor.api.BufferAPI.c.drawElements(pf,p_mesh.get_topology().length,5123,0); else haxor.api.BufferAPI.c.drawArrays(pf,0,p_mesh.get_vertexCount());
};
haxor.api.BufferAPI.Get = function(m,a) {
	var k = a + m.get_id();
	if(haxor.api.BufferAPI.m_buffers.exists(k)) return haxor.api.BufferAPI.m_buffers.get(k); else return null;
};
haxor.api.BufferAPI.PrimitiveFlag = function(f) {
	switch(f[1]) {
	case 0:
		return 0;
	case 4:
		return 1;
	case 5:
		return 2;
	case 6:
		return 3;
	case 1:
		return 4;
	case 3:
		return 6;
	case 2:
		return 5;
	}
	return 4;
};
haxor.api.BufferAPI.ModeFlag = function(f) {
	return 35048;
	switch(f[1]) {
	case 2:
		return 35048;
	case 1:
		return 35040;
	case 0:
		return 35044;
	}
	return 35044;
};
haxor.api.MaterialAPI = function() { };
$hxClasses["haxor.api.MaterialAPI"] = haxor.api.MaterialAPI;
haxor.api.MaterialAPI.__name__ = ["haxor","api","MaterialAPI"];
haxor.api.MaterialAPI.Initialize = function(p_context) {
	haxor.api.MaterialAPI.c = p_context;
	haxor.api.MaterialAPI.m_globals = ["ViewMatrix","ProjectionMatrix","WorldMatrix","Time","RandomSeed","RandomTexture","ScreenTexture","ScreenDepth","Ambient","WSCameraPosition","ProjectionMatrixInverse","ViewMatrixInverse"];
	haxor.api.MaterialAPI.Reset();
};
haxor.api.MaterialAPI.Reset = function() {
	haxor.api.MaterialAPI.m_current = null;
	haxor.api.MaterialAPI.m_camera = null;
	haxor.api.MaterialAPI.m_zTest = haxor.graphics.DepthTest.LessEqual;
	haxor.api.MaterialAPI.m_zTestEnabled = true;
	haxor.api.MaterialAPI.m_srcBlend = haxor.graphics.BlendMode.One;
	haxor.api.MaterialAPI.m_dstBlend = haxor.graphics.BlendMode.Zero;
	haxor.api.MaterialAPI.m_blendEnabled = false;
	haxor.api.MaterialAPI.m_zWriteEnabled = true;
	haxor.api.MaterialAPI.m_cull = haxor.graphics.CullMode.Back;
	haxor.api.MaterialAPI.m_invertFace = false;
	haxor.api.MaterialAPI.c.enable(2929);
	haxor.api.MaterialAPI.c.depthMask(true);
	haxor.api.MaterialAPI.c.depthFunc(haxor.api.MaterialAPI.m_zTest);
	haxor.api.MaterialAPI.c.disable(3042);
	haxor.api.MaterialAPI.c.blendFunc(haxor.api.MaterialAPI.m_srcBlend,haxor.api.MaterialAPI.m_dstBlend);
	haxor.api.MaterialAPI.c.enable(2884);
	haxor.api.MaterialAPI.c.cullFace(1029);
	haxor.api.MaterialAPI.c.frontFace(2305);
};
haxor.api.MaterialAPI.Bind = function(p_material) {
	haxor.api.MaterialAPI.SetFlags(p_material);
};
haxor.api.MaterialAPI.GetUniformLocation = function(p,u,m) {
	var sid = m.get_shader().get_id() + "";
	var k = u + sid;
	if(m.m_locations.exists(k)) return m.m_locations.get(k);
	var loc = haxor.api.MaterialAPI.c.getUniformLocation(p,u);
	m.m_locations.set(k,loc);
	return loc;
};
haxor.api.MaterialAPI.SetLights = function(p_transform,p_material,p_mesh) {
	var m = p_material;
	var ll = haxor.component.Light.m_list;
	if(ll.length <= 0) return;
	if(!m.lighting) return;
	var b = p_mesh.get_bounds();
	var c = p_transform.get_WorldMatrix().Transform3x4(haxor.math.Vector3.get_zero());
	var k = 0;
	var b1 = haxor.component.Light.m_buffer;
	var _g1 = 0;
	var _g = ll.length;
	while(_g1 < _g) {
		var i = _g1++;
		var l = ll[i];
		if(!l.get_enabled()) continue;
		if(js.Boot.__instanceof(l,haxor.component.PointLight)) {
			var pl = l;
			var p = l.get_transform().get_WorldMatrix().Transform3x4(haxor.math.Vector3.get_zero());
			if(haxor.math.Vector3.Distance(c,p) > pl.radius * 0.9) continue;
			haxor.component.Light.SetLightData(k,0.0,pl.intensity,pl.radius,pl.atten,p.x,p.y,p.z,pl.color.r,pl.color.g,pl.color.b,pl.color.a);
			k++;
		} else if(js.Boot.__instanceof(l,haxor.component.DirectionalLight)) {
			var p1 = l.get_transform().get_forward();
			haxor.component.Light.SetLightData(k,1.0,l.intensity,0.0,0.0,p1.x,p1.y,p1.z,l.color.r,l.color.g,l.color.b,l.color.a);
			k++;
		}
	}
	while(k < haxor.component.Light.max) {
		haxor.component.Light.SetLightData(k,-1.0,0,0,0,0,0,0,0,0,0,0);
		k++;
	}
	m.SetUniform("Lights",b1);
};
haxor.api.MaterialAPI.SetUniforms = function(p_camera,p_transform,p_material) {
	var camera_change = p_camera != null;
	var transform_change = haxor.api.MaterialAPI.m_transform != p_transform && p_transform != null;
	haxor.api.MaterialAPI.m_transform = p_transform;
	haxor.api.MaterialAPI.m_camera = p_camera;
	var loc = null;
	var m = p_material;
	var prog = m.get_shader().get_gid();
	var k;
	var hc;
	var hl;
	var has_flush = false;
	var _g1 = 0;
	var _g = haxor.api.MaterialAPI.m_globals.length;
	while(_g1 < _g) {
		var i = _g1++;
		k = haxor.api.MaterialAPI.m_globals[i];
		loc = haxor.api.MaterialAPI.GetUniformLocation(prog,k,m);
		if(loc == null) continue;
		switch(k) {
		case "Ambient":
			haxor.api.MaterialAPI.c.uniform4f(loc,haxor.component.Light.ambient.r,haxor.component.Light.ambient.g,haxor.component.Light.ambient.b,haxor.component.Light.ambient.a);
			break;
		case "Time":
			haxor.api.MaterialAPI.c.uniform1f(loc,haxor.core.Time.get_elapsed());
			break;
		case "RandomSeed":
			haxor.api.MaterialAPI.c.uniform1f(loc,Math.random());
			break;
		case "RandomTexture":
			m.SetUniform("RandomTexture",haxor.core.Asset.Get("haxor/texture/random"));
			break;
		case "ScreenTexture":
			if(m.grab) m.SetUniform("ScreenTexture",m.screen);
			break;
		case "ScreenDepth":
			m.SetUniform("ScreenDepth",p_camera.m_grab.get_depth());
			break;
		case "WorldMatrix":
			if(transform_change) haxor.api.MaterialAPI.c.uniformMatrix4fv(loc,false,p_transform.m_worldMatrix.ToBuffer());
			break;
		case "WorldMatrixInverse":
			if(transform_change) haxor.api.MaterialAPI.c.uniformMatrix4fv(loc,false,p_transform.m_worldMatrixInverse.ToBuffer());
			break;
		case "ViewMatrix":
			if(camera_change) haxor.api.MaterialAPI.c.uniformMatrix4fv(loc,false,p_camera.get_WorldToCamera().ToBuffer());
			break;
		case "ViewMatrixInverse":
			if(camera_change) haxor.api.MaterialAPI.c.uniformMatrix4fv(loc,false,p_camera.get_CameraToWorld().ToBuffer());
			break;
		case "ProjectionMatrix":
			if(camera_change) haxor.api.MaterialAPI.c.uniformMatrix4fv(loc,false,p_camera.get_ProjectionMatrix().ToBuffer());
			break;
		case "ProjectionMatrixInverse":
			if(camera_change) haxor.api.MaterialAPI.c.uniformMatrix4fv(loc,false,p_camera.get_ProjectionMatrixInverse().ToBuffer());
			break;
		case "WSCameraPosition":
			if(camera_change) haxor.api.MaterialAPI.c.uniform3f(loc,p_camera.get_CameraToWorld().m03,p_camera.get_CameraToWorld().m13,p_camera.get_CameraToWorld().m23);
			break;
		}
	}
	var u = m.get_uniforms();
	var tex_count = 0;
	while(u.hasNext()) {
		k = u.next();
		var d = m.GetUniform(k);
		loc = haxor.api.MaterialAPI.GetUniformLocation(prog,k,m);
		if(loc == null) continue;
		var has_change = true;
		if(js.Boot.__instanceof(d,haxor.texture.Texture)) {
			haxor.api.TextureAPI.Activate(d,tex_count);
			if(has_change) haxor.api.MaterialAPI.c.uniform1i(loc,tex_count);
			tex_count++;
			continue;
		}
		var tn;
		var e = Type["typeof"](d);
		tn = e[0];
		if(tn == "TFloat") haxor.api.MaterialAPI.c.uniform1f(loc,d); else if(js.Boot.__instanceof(d,Float32Array)) {
			var v = d;
			haxor.api.MaterialAPI.c.uniform4fv(loc,v);
		} else if(js.Boot.__instanceof(d,haxor.math.Vector2)) {
			var v1 = d;
			haxor.api.MaterialAPI.c.uniform2f(loc,v1.x,v1.y);
		} else if(js.Boot.__instanceof(d,haxor.math.Vector3)) {
			var v2 = d;
			haxor.api.MaterialAPI.c.uniform3f(loc,v2.x,v2.y,v2.z);
		} else if(js.Boot.__instanceof(d,haxor.math.Vector4)) {
			var v3 = d;
			haxor.api.MaterialAPI.c.uniform4f(loc,v3.x,v3.y,v3.z,v3.w);
		} else if(js.Boot.__instanceof(d,haxor.math.Color)) {
			var v4 = d;
			haxor.api.MaterialAPI.c.uniform4f(loc,v4.r,v4.g,v4.b,v4.a);
		} else if(js.Boot.__instanceof(d,haxor.math.Matrix4)) {
			var v5 = d;
			haxor.api.MaterialAPI.c.uniformMatrix4fv(loc,false,v5.ToBuffer());
		} else if(tn == "TInt") haxor.api.MaterialAPI.c.uniform1i(loc,d);
	}
};
haxor.api.MaterialAPI.SetFlags = function(p_material) {
	if(p_material.ztest) {
		if(!haxor.api.MaterialAPI.m_zTestEnabled) {
			haxor.api.MaterialAPI.c.enable(2929);
			haxor.api.MaterialAPI.m_zTestEnabled = true;
		}
	} else if(haxor.api.MaterialAPI.m_zTestEnabled) {
		haxor.api.MaterialAPI.c.disable(2929);
		haxor.api.MaterialAPI.m_zTestEnabled = false;
	}
	if(haxor.api.MaterialAPI.m_zWriteEnabled != p_material.zwrite) {
		haxor.api.MaterialAPI.c.depthMask(p_material.zwrite);
		haxor.api.MaterialAPI.m_zWriteEnabled = p_material.zwrite;
	}
	if(haxor.api.MaterialAPI.m_zTest != p_material.zfunc) {
		haxor.api.MaterialAPI.c.depthFunc(p_material.zfunc);
		haxor.api.MaterialAPI.m_zTest = p_material.zfunc;
	}
	if(p_material.blend) {
		if(!haxor.api.MaterialAPI.m_blendEnabled) {
			haxor.api.MaterialAPI.c.enable(3042);
			haxor.api.MaterialAPI.m_blendEnabled = true;
		}
	} else if(haxor.api.MaterialAPI.m_blendEnabled) {
		haxor.api.MaterialAPI.c.disable(3042);
		haxor.api.MaterialAPI.m_blendEnabled = false;
	}
	if(haxor.api.MaterialAPI.m_srcBlend != p_material.blendSrc) {
		haxor.api.MaterialAPI.c.blendFunc(p_material.blendSrc,p_material.blendDst);
		haxor.api.MaterialAPI.m_srcBlend = p_material.blendSrc;
	} else if(haxor.api.MaterialAPI.m_dstBlend != p_material.blendDst) {
		haxor.api.MaterialAPI.c.blendFunc(p_material.blendSrc,p_material.blendDst);
		haxor.api.MaterialAPI.m_dstBlend = p_material.blendDst;
	}
	if(p_material.cull != haxor.api.MaterialAPI.m_cull) {
		if(p_material.cull == haxor.graphics.CullMode.None) haxor.api.MaterialAPI.c.disable(2884); else {
			haxor.api.MaterialAPI.c.enable(2884);
			haxor.api.MaterialAPI.c.cullFace(p_material.cull == haxor.graphics.CullMode.Front?1028:1029);
		}
		haxor.api.MaterialAPI.m_cull = p_material.cull;
	}
	if(haxor.api.MaterialAPI.m_invertFace != p_material.invert) {
		haxor.api.MaterialAPI.c.frontFace(p_material.invert?2304:2305);
		haxor.api.MaterialAPI.m_invertFace = p_material.invert;
	}
};
haxor.api.ShaderAPI = function() { };
$hxClasses["haxor.api.ShaderAPI"] = haxor.api.ShaderAPI;
haxor.api.ShaderAPI.__name__ = ["haxor","api","ShaderAPI"];
haxor.api.ShaderAPI.Initialize = function(p_context) {
	haxor.api.ShaderAPI.c = p_context;
	haxor.api.ShaderAPI.m_currentProgram = null;
};
haxor.api.ShaderAPI.Bind = function(p_shader) {
	var p = p_shader.get_gid();
	if(p == haxor.api.ShaderAPI.m_currentProgram) return;
	haxor.api.ShaderAPI.m_currentProgram = p;
	haxor.api.ShaderAPI.current = p_shader;
	haxor.api.ShaderAPI.c.useProgram(p);
};
haxor.api.ShaderAPI.Create = function(p_shader) {
	if(haxor.api.ShaderAPI.c == null) return;
	var key;
	var src;
	var vs = null;
	var fs = null;
	src = Reflect.field(p_shader,"m_vertexShaderSource");
	if(src != "") {
		vs = haxor.api.ShaderAPI.c.createShader(35633);
		p_shader.m_vertexShaderId = vs;
		haxor.api.ShaderAPI.c.shaderSource(vs,src);
		haxor.api.ShaderAPI.c.compileShader(vs);
		if(!haxor.api.ShaderAPI.c.getShaderParameter(vs,35713)) {
			p_shader.m_hasError = true;
			haxor.core.Console.LogError("Shader> Compile Error @ Vertex[" + p_shader.get_name() + "]\n" + haxor.api.ShaderAPI.c.getShaderInfoLog(vs));
		}
	}
	src = Reflect.field(p_shader,"m_fragmentShaderSource");
	if(src != "") {
		fs = haxor.api.ShaderAPI.c.createShader(35632);
		p_shader.m_fragmentShaderId = fs;
		haxor.api.ShaderAPI.c.shaderSource(fs,src);
		haxor.api.ShaderAPI.c.compileShader(fs);
		if(!haxor.api.ShaderAPI.c.getShaderParameter(fs,35713)) {
			p_shader.m_hasError = true;
			haxor.core.Console.LogError("Shader> Compile Error @ Fragment[" + p_shader.get_name() + "]\n" + haxor.api.ShaderAPI.c.getShaderInfoLog(vs));
		}
	}
	var p = haxor.api.ShaderAPI.c.createProgram();
	if(p == null) {
		haxor.core.Console.LogError("Shader> Error! Could not create program @ " + p_shader.get_name());
		return;
	}
	if(vs != null) haxor.api.ShaderAPI.c.attachShader(p,vs);
	if(fs != null) haxor.api.ShaderAPI.c.attachShader(p,fs);
	var _g1 = 0;
	var _g = haxor.api.ShaderAPI.m_attribs.length;
	while(_g1 < _g) {
		var i = _g1++;
		haxor.api.ShaderAPI.c.bindAttribLocation(p,i,haxor.api.ShaderAPI.m_attribs[i]);
	}
	haxor.api.ShaderAPI.c.linkProgram(p);
	if(!haxor.api.ShaderAPI.c.getProgramParameter(p,35714)) {
		p_shader.m_hasError = true;
		haxor.core.Console.LogError("Shader> Link Error @ [" + p_shader.get_name() + "]\n[" + haxor.api.ShaderAPI.c.getProgramInfoLog(p) + "]");
	}
	p_shader.m_gid = p;
};
haxor.api.ShaderAPI.GetAttribute = function(p_attribute,p_shader) {
	var shd;
	if(p_shader == null) shd = haxor.api.ShaderAPI.current; else shd = p_shader;
	var cache = shd.m_locations;
	if(cache.exists(p_attribute)) return cache.get(p_attribute);
	var loc = haxor.api.ShaderAPI.c.getAttribLocation(shd.get_gid(),p_attribute);
	cache.set(p_attribute,loc);
	return loc;
};
haxor.api.ShaderAPI.Destroy = function(p_shader) {
	var vs = Reflect.getProperty(p_shader,"m_vertexShaderId");
	var fs = Reflect.getProperty(p_shader,"m_fragmentShaderId");
	if(vs != null) haxor.api.ShaderAPI.c.deleteShader(vs);
	if(fs != null) haxor.api.ShaderAPI.c.deleteShader(fs);
	if(p_shader.get_gid() != null) {
		haxor.api.ShaderAPI.c.deleteProgram(p_shader.get_gid());
		if(p_shader.get_gid() == haxor.api.ShaderAPI.m_currentProgram) haxor.api.ShaderAPI.m_currentProgram = null;
	}
};
haxor.api.SoundAPI = function() {
	var snd;
	var audio;
};
$hxClasses["haxor.api.SoundAPI"] = haxor.api.SoundAPI;
haxor.api.SoundAPI.__name__ = ["haxor","api","SoundAPI"];
haxor.api.SoundAPI.Initialize = function() {
	console.log("Haxor> SoundAPI Initialize");
	haxor.media.Sound.m_list = [];
	haxor.media.Sound.m_main = 1.0;
};
haxor.api.SoundAPI.SetMainVolume = function(p_v) {
};
haxor.api.SoundAPI.prototype = {
	__class__: haxor.api.SoundAPI
};
haxor.api.TextureAPI = function() { };
$hxClasses["haxor.api.TextureAPI"] = haxor.api.TextureAPI;
haxor.api.TextureAPI.__name__ = ["haxor","api","TextureAPI"];
haxor.api.TextureAPI.Initialize = function(p_context) {
	haxor.api.TextureAPI.c = p_context;
	haxor.api.TextureAPI.m_active = -1;
	haxor.api.TextureAPI.m_slots = [];
	haxor.api.TextureAPI.m_actives = [];
	haxor.api.TextureAPI.m_buffer = null;
	var _g = 0;
	while(_g < 256) {
		var i = _g++;
		haxor.api.TextureAPI.m_slots.push(null);
		haxor.api.TextureAPI.m_actives.push(false);
	}
};
haxor.api.TextureAPI.SetParameters = function(p_texture) {
	var flag = p_texture.get_type();
	haxor.api.TextureAPI.Bind(p_texture);
	haxor.api.TextureAPI.c.texParameteri(flag,10242,(p_texture.get_wrap() & haxor.texture.TextureWrap.ClampX) != 0?33071:10497);
	haxor.api.TextureAPI.c.texParameteri(flag,10243,(p_texture.get_wrap() & haxor.texture.TextureWrap.ClampY) != 0?33071:10497);
	if(haxor.api.TextureAPI.TEXTURE_MAX_ANISOTROPY_EXT > 0) haxor.api.TextureAPI.c.texParameterf(flag,haxor.api.TextureAPI.TEXTURE_MAX_ANISOTROPY_EXT,Math.max(1,p_texture.get_aniso()));
	var minf = p_texture.get_minFilter();
	var magf = p_texture.get_magFilter();
	if(p_texture.get_format() == haxor.texture.TextureFormat.Half) {
		if(!haxor.api.TextureAPI.HALF_FLOAT_LINEAR) {
			minf = haxor.texture.TextureFilter.Nearest;
			magf = haxor.texture.TextureFilter.Nearest;
		}
	}
	switch(minf[1]) {
	case 0:
		haxor.api.TextureAPI.c.texParameteri(flag,10241,9728);
		break;
	case 3:
		haxor.api.TextureAPI.c.texParameteri(flag,10241,9986);
		break;
	case 2:
		haxor.api.TextureAPI.c.texParameteri(flag,10241,9984);
		break;
	case 1:
		haxor.api.TextureAPI.c.texParameteri(flag,10241,9729);
		break;
	case 5:
		haxor.api.TextureAPI.c.texParameteri(flag,10241,9987);
		break;
	case 6:
		haxor.api.TextureAPI.c.texParameteri(flag,10241,9987);
		break;
	case 4:
		haxor.api.TextureAPI.c.texParameteri(flag,10241,9985);
		break;
	}
	switch(magf[1]) {
	case 0:
		haxor.api.TextureAPI.c.texParameteri(flag,10240,9728);
		break;
	case 3:
		haxor.api.TextureAPI.c.texParameteri(flag,10240,9728);
		break;
	case 2:
		haxor.api.TextureAPI.c.texParameteri(flag,10240,9728);
		break;
	case 1:
		haxor.api.TextureAPI.c.texParameteri(flag,10240,9729);
		break;
	case 5:
		haxor.api.TextureAPI.c.texParameteri(flag,10240,9729);
		break;
	case 6:
		haxor.api.TextureAPI.c.texParameteri(flag,10240,9729);
		break;
	case 4:
		haxor.api.TextureAPI.c.texParameteri(flag,10240,9729);
		break;
	}
};
haxor.api.TextureAPI.Create = function(p_texture) {
	var id = haxor.api.TextureAPI.c.createTexture();
	if(js.Boot.__instanceof(p_texture,haxor.texture.TextureCube)) p_texture.m_type = 34067; else p_texture.m_type = 3553;
	p_texture.m_gid = id;
	haxor.api.TextureAPI.SetParameters(p_texture);
	if(js.Boot.__instanceof(p_texture,haxor.texture.RenderTexture)) {
		var rt = p_texture;
		rt.m_fid = haxor.api.TextureAPI.c.createFramebuffer();
		haxor.api.TextureAPI.c.bindFramebuffer(36160,rt.m_fid);
		haxor.api.TextureAPI.Alloc(rt);
		haxor.api.TextureAPI.c.framebufferTexture2D(36160,36064,3553,rt.get_gid(),0);
		if(rt.get_depth() != null) haxor.api.TextureAPI.c.framebufferTexture2D(36160,36096,3553,rt.get_depth().m_gid,0); else {
			rt.m_rid = haxor.api.TextureAPI.c.createRenderbuffer();
			haxor.api.TextureAPI.c.bindRenderbuffer(36161,rt.m_rid);
			haxor.api.TextureAPI.c.renderbufferStorage(36161,33189,rt.get_width(),rt.get_height());
			haxor.api.TextureAPI.c.framebufferRenderbuffer(36160,36096,36161,rt.m_rid);
		}
		haxor.api.TextureAPI.c.bindFramebuffer(36160,null);
		haxor.api.TextureAPI.c.bindRenderbuffer(36161,null);
		haxor.api.TextureAPI.Unbind(rt);
	}
};
haxor.api.TextureAPI.Apply = function(p_texture) {
	var id;
	if(p_texture.get_gid() == null) haxor.api.TextureAPI.Create(p_texture);
	id = p_texture.get_gid();
	var flag = p_texture.get_type();
	haxor.api.TextureAPI.c.bindTexture(flag,id);
	if(flag == 34067) {
		var tc = p_texture;
		if(tc.get_px() != null) haxor.api.TextureAPI.WriteTexture(34069,tc.get_px());
		if(tc.get_nx() != null) haxor.api.TextureAPI.WriteTexture(34070,tc.get_nx());
		if(tc.get_py() != null) haxor.api.TextureAPI.WriteTexture(34071,tc.get_py());
		if(tc.get_ny() != null) haxor.api.TextureAPI.WriteTexture(34072,tc.get_ny());
		if(tc.get_pz() != null) haxor.api.TextureAPI.WriteTexture(34073,tc.get_pz());
		if(tc.get_nz() != null) haxor.api.TextureAPI.WriteTexture(34074,tc.get_nz());
	} else haxor.api.TextureAPI.WriteTexture(flag,p_texture);
};
haxor.api.TextureAPI.WritePixels = function(p_texture,p_x,p_y,p_pixels,p_width,p_height) {
	if(p_height == null) p_height = -1;
	if(p_width == null) p_width = -1;
	haxor.api.TextureAPI.Bind(p_texture);
	var w;
	if(p_width < 0) w = p_texture.get_width(); else w = p_width;
	var h;
	if(p_height < 0) h = p_texture.get_height(); else h = p_height;
	var chn_fmt = haxor.api.TextureAPI.ChannelLayout(p_texture);
	var chn_bit = haxor.api.TextureAPI.ChannelBits(p_texture);
	var chn_type = haxor.api.TextureAPI.ChannelType(p_texture);
	if(p_height < 0 || p_width < 0) haxor.api.TextureAPI.c.texImage2D(3553,0,chn_fmt,w,h,0,chn_bit,chn_type,p_pixels); else haxor.api.TextureAPI.c.texSubImage2D(3553,0,p_x,p_y,w,h,chn_fmt,chn_type,p_pixels);
};
haxor.api.TextureAPI.Alloc = function(p_texture,p_invert_y) {
	if(p_invert_y == null) p_invert_y = false;
	var w = p_texture.get_width();
	var h = p_texture.get_height();
	var chn_fmt = haxor.api.TextureAPI.ChannelLayout(p_texture);
	var chn_bit = haxor.api.TextureAPI.ChannelBits(p_texture);
	var chn_type = haxor.api.TextureAPI.ChannelType(p_texture);
	haxor.api.TextureAPI.Bind(p_texture);
	if(p_invert_y) haxor.api.TextureAPI.c.pixelStorei(37440,1);
	haxor.api.TextureAPI.c.texImage2D(p_texture.get_type(),0,chn_fmt,w,h,0,chn_bit,chn_type,null);
};
haxor.api.TextureAPI.WriteTexture = function(p_flag,p_texture,p_flip_y) {
	if(p_flip_y == null) p_flip_y = false;
	var d = p_texture.get_data();
	if(d == null) {
		haxor.api.TextureAPI.c.texImage2D(p_flag,0,6407,1,1,0,6407,5121,new Uint8Array([128,64,64]));
		return;
	}
	var w = p_texture.get_width();
	var h = p_texture.get_height();
	var chn_fmt = haxor.api.TextureAPI.ChannelLayout(p_texture);
	var chn_bit = haxor.api.TextureAPI.ChannelBits(p_texture);
	var chn_type = haxor.api.TextureAPI.ChannelType(p_texture);
	var is_element = p_texture.get_html();
	haxor.api.TextureAPI.c.pixelStorei(37440,p_flip_y?1:0);
	if(is_element) {
		if(p_flag == 3553) haxor.api.TextureAPI.c.pixelStorei(37440,p_flip_y?0:1);
		haxor.api.TextureAPI.c.texImage2D(p_flag,0,chn_fmt,chn_bit,chn_type,d);
	} else {
		if(p_texture.get_format() == haxor.texture.TextureFormat.Depth) d = null;
		haxor.api.TextureAPI.c.texImage2D(p_flag,0,chn_fmt,w,h,0,chn_bit,chn_type,d);
	}
};
haxor.api.TextureAPI.Activate = function(p_texture,p_slot) {
	if(haxor.api.TextureAPI.m_active < 0) haxor.api.TextureAPI.m_active = 1; else haxor.api.TextureAPI.m_active = haxor.math.Mathf.Max([haxor.api.TextureAPI.m_active,p_slot]);
	haxor.api.TextureAPI.c.activeTexture(33984 + p_slot);
	haxor.api.TextureAPI.Bind(p_texture);
	return;
	if(!haxor.api.TextureAPI.m_actives[p_slot]) {
		haxor.api.TextureAPI.c.activeTexture(33984 + p_slot);
		haxor.api.TextureAPI.m_actives[p_slot] = true;
	}
	if(haxor.api.TextureAPI.m_active < 0) haxor.api.TextureAPI.m_active = 1; else haxor.api.TextureAPI.m_active = haxor.math.Mathf.Max([haxor.api.TextureAPI.m_active,p_slot]);
	if(haxor.api.TextureAPI.m_slots[p_slot] != p_texture) {
		haxor.api.TextureAPI.Bind(p_texture);
		haxor.api.TextureAPI.m_slots[p_slot] = p_texture;
	}
	if(p_texture.get_html()) {
		var etex = p_texture;
		if(etex.get_video()) haxor.api.TextureAPI.WriteTexture(p_texture.get_type(),p_texture);
	}
};
haxor.api.TextureAPI.BindRT = function(p_render_texture) {
	if(p_render_texture == null) {
		if(haxor.api.TextureAPI.m_buffer != p_render_texture) {
			haxor.api.TextureAPI.c.bindFramebuffer(36160,null);
			haxor.api.TextureAPI.c.bindRenderbuffer(36161,null);
			haxor.api.TextureAPI.m_buffer = null;
		}
	} else if(haxor.api.TextureAPI.m_buffer != p_render_texture) {
		haxor.api.TextureAPI.c.bindFramebuffer(36160,p_render_texture.m_fid);
		if(p_render_texture.get_depth() == null) haxor.api.TextureAPI.c.bindRenderbuffer(36161,p_render_texture.m_rid);
		haxor.api.TextureAPI.m_buffer = p_render_texture;
	}
};
haxor.api.TextureAPI.Bind = function(p_texture) {
	haxor.api.TextureAPI.c.bindTexture(p_texture.get_type(),p_texture.get_gid());
};
haxor.api.TextureAPI.Unbind = function(p_texture) {
	haxor.api.TextureAPI.c.bindTexture(p_texture.get_type(),null);
};
haxor.api.TextureAPI.Finish = function() {
	var _g1 = 0;
	var _g = haxor.api.TextureAPI.m_active;
	while(_g1 < _g) {
		var i = _g1++;
		haxor.api.TextureAPI.c.activeTexture(33984 + i);
		haxor.api.TextureAPI.c.bindTexture(3553,null);
		haxor.api.TextureAPI.c.bindTexture(34067,null);
	}
	haxor.api.TextureAPI.m_active = -1;
};
haxor.api.TextureAPI.ChannelType = function(p_texture) {
	if(p_texture.get_format() == haxor.texture.TextureFormat.Half) return haxor.api.TextureAPI.HALF_FLOAT_OES;
	if(p_texture.get_format() == haxor.texture.TextureFormat.Half3) return haxor.api.TextureAPI.HALF_FLOAT_OES;
	if(p_texture.get_format() == haxor.texture.TextureFormat.Half4) return haxor.api.TextureAPI.HALF_FLOAT_OES;
	if(p_texture.get_format() == haxor.texture.TextureFormat.Float) return 5126;
	if(p_texture.get_format() == haxor.texture.TextureFormat.Float3) return 5126;
	if(p_texture.get_format() == haxor.texture.TextureFormat.Float4) return 5126;
	if(p_texture.get_format() == haxor.texture.TextureFormat.Depth) return 5123;
	return 5121;
};
haxor.api.TextureAPI.ChannelLayout = function(p_texture) {
	var _g = p_texture.get_format();
	switch(_g[1]) {
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
haxor.api.TextureAPI.ChannelBits = function(p_texture) {
	var _g = p_texture.get_format();
	switch(_g[1]) {
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
haxor.api.TextureAPI.BuildMipmaps = function(p_texture) {
	var id = p_texture.get_gid();
	var flag = p_texture.get_type();
	haxor.api.TextureAPI.c.bindTexture(flag,id);
	haxor.api.TextureAPI.c.generateMipmap(flag);
};
haxor.api.TextureAPI.Destroy = function(p_texture) {
	if(p_texture.get_gid() != null) haxor.api.TextureAPI.c.deleteTexture(p_texture.get_gid());
	if(js.Boot.__instanceof(p_texture,haxor.texture.RenderTexture)) {
		var rt = p_texture;
		if(rt.m_fid != null) haxor.api.TextureAPI.c.deleteFramebuffer(rt.m_fid);
		if(rt.m_rid != null) haxor.api.TextureAPI.c.deleteRenderbuffer(rt.m_rid);
	}
};
haxor.component = {};
haxor.component.Component = function(p_entity) {
	haxor.core.Resource.call(this);
	this.m_entity = p_entity;
};
$hxClasses["haxor.component.Component"] = haxor.component.Component;
haxor.component.Component.__name__ = ["haxor","component","Component"];
haxor.component.Component.__super__ = haxor.core.Resource;
haxor.component.Component.prototype = $extend(haxor.core.Resource.prototype,{
	get_entity: function() {
		return this.m_entity;
	}
	,get_transform: function() {
		return this.m_entity.get_transform();
	}
	,get_camera: function() {
		return this.m_entity.get_camera();
	}
	,get_renderer: function() {
		return this.m_entity.get_renderer();
	}
	,get_rigidbody: function() {
		return this.m_entity.get_rigidbody();
	}
	,get_layer: function() {
		return this.get_entity().layer;
	}
	,set_layer: function(v) {
		this.get_entity().layer = v;
		return v;
	}
	,set_name: function(v) {
		haxor.core.Resource.prototype.set_name.call(this,this.m_entity.set_name(v));
		return v;
	}
	,get_name: function() {
		return this.m_entity.get_name();
	}
	,AddComponent: function(p_type) {
		return this.get_entity().AddComponent(p_type);
	}
	,GetComponent: function(p_type) {
		return this.get_entity().GetComponent(p_type);
	}
	,GetComponents: function(p_type) {
		return this.get_entity().GetComponents(p_type);
	}
	,GetComponentInChildren: function(p_type) {
		return this.get_entity().GetComponentInChildren(p_type);
	}
	,GetComponentsInChildren: function(p_type) {
		return this.get_entity().GetComponentsInChildren(p_type);
	}
	,OnTransformUpdate: function() {
	}
	,__class__: haxor.component.Component
	,__properties__: $extend(haxor.core.Resource.prototype.__properties__,{set_layer:"set_layer",get_layer:"get_layer",get_rigidbody:"get_rigidbody",get_renderer:"get_renderer",get_camera:"get_camera",get_transform:"get_transform",get_entity:"get_entity"})
});
haxor.component.Behaviour = function(p_entity) {
	haxor.component.Component.call(this,p_entity);
	this.set_enabled(true);
	haxor.core.Engine.AddAwakeBehaviour(this);
	haxor.core.Engine.AddStartBehaviour(this);
	this.OnBuild();
};
$hxClasses["haxor.component.Behaviour"] = haxor.component.Behaviour;
haxor.component.Behaviour.__name__ = ["haxor","component","Behaviour"];
haxor.component.Behaviour.__super__ = haxor.component.Component;
haxor.component.Behaviour.prototype = $extend(haxor.component.Component.prototype,{
	get_enabled: function() {
		return this.m_enabled;
	}
	,set_enabled: function(v) {
		this.m_enabled = v;
		this.CheckEnabled();
		return v;
	}
	,OnBuild: function() {
	}
	,OnAwake: function() {
	}
	,OnStart: function() {
	}
	,CheckEnabled: function() {
		if(this.m_enabled && this.get_entity().get_enabled()) haxor.core.Engine.EnableBehaviour(this); else haxor.core.Engine.DisableBehaviour(this);
	}
	,__class__: haxor.component.Behaviour
	,__properties__: $extend(haxor.component.Component.prototype.__properties__,{set_enabled:"set_enabled",get_enabled:"get_enabled"})
});
haxor.component.Animation = function(p_entity) {
	haxor.component.Behaviour.call(this,p_entity);
	haxor.component.Animation.m_list.push(this);
	this.clips = [];
	this.m_time = 0;
	this.reverse = false;
	this.m_clock = haxor.core.Time.get_elapsed();
	this.m_fade_elapsed = 0.0;
	this.m_fade_duration = 0.0;
};
$hxClasses["haxor.component.Animation"] = haxor.component.Animation;
haxor.component.Animation.__name__ = ["haxor","component","Animation"];
haxor.component.Animation.Update = function() {
	if(haxor.component.Animation.m_list.length > 0) {
		var steps = Std["int"](Math.max(haxor.component.Animation.m_list.length / 2,1));
		var _g = 0;
		while(_g < steps) {
			var i = _g++;
			haxor.component.Animation.m_list[haxor.component.Animation.m_iterator].Animate();
			haxor.component.Animation.m_iterator = (haxor.component.Animation.m_iterator + 1) % haxor.component.Animation.m_list.length;
		}
	}
};
haxor.component.Animation.Initialize = function() {
	haxor.component.Animation.m_list = [];
	haxor.component.Animation.m_iterator = 0;
};
haxor.component.Animation.__super__ = haxor.component.Behaviour;
haxor.component.Animation.prototype = $extend(haxor.component.Behaviour.prototype,{
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
		this.get_transform().Lock();
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
		this.get_transform().Unlock();
		this.get_transform().Concat();
		var dt = haxor.core.Time.get_elapsed() - this.m_clock;
		this.m_clock = haxor.core.Time.get_elapsed();
		if(is_playing) {
			this.m_time += (this.reverse?-dt:dt) * spd;
			this.m_fade_elapsed += dt;
		}
	}
	,__class__: haxor.component.Animation
	,__properties__: $extend(haxor.component.Behaviour.prototype.__properties__,{get_playing:"get_playing",set_time:"set_time",get_time:"get_time"})
});
haxor.component.AnimationWrap = { __ename__ : true, __constructs__ : ["Clamp","Loop","Oscilate"] };
haxor.component.AnimationWrap.Clamp = ["Clamp",0];
haxor.component.AnimationWrap.Clamp.__enum__ = haxor.component.AnimationWrap;
haxor.component.AnimationWrap.Loop = ["Loop",1];
haxor.component.AnimationWrap.Loop.__enum__ = haxor.component.AnimationWrap;
haxor.component.AnimationWrap.Oscilate = ["Oscilate",2];
haxor.component.AnimationWrap.Oscilate.__enum__ = haxor.component.AnimationWrap;
haxor.component.AnimationEvent = function(p_frame,p_listener,p_repeat,p_args) {
	if(p_repeat == null) p_repeat = 0;
	this.frame = p_frame;
	this.listener = p_listener;
	if(p_args == null) this.args = []; else this.args = p_args;
	this.repeat = p_repeat;
};
$hxClasses["haxor.component.AnimationEvent"] = haxor.component.AnimationEvent;
haxor.component.AnimationEvent.__name__ = ["haxor","component","AnimationEvent"];
haxor.component.AnimationEvent.prototype = {
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
	,__class__: haxor.component.AnimationEvent
};
haxor.component.AnimationClip = function() {
	haxor.core.Resource.call(this);
	this.tracks = [];
	this.speed = 1.0;
	this.playing = false;
	this.m_length = 0;
	this.wrap = haxor.component.AnimationWrap.Clamp;
	this.m_events = [];
	this.m_last_frame = 0;
};
$hxClasses["haxor.component.AnimationClip"] = haxor.component.AnimationClip;
haxor.component.AnimationClip.__name__ = ["haxor","component","AnimationClip"];
haxor.component.AnimationClip.__super__ = haxor.core.Resource;
haxor.component.AnimationClip.prototype = $extend(haxor.core.Resource.prototype,{
	get_length: function() {
		return this.m_length;
	}
	,AddEvent: function(p_frame,p_listener,p_repeat,p_args) {
		if(p_repeat == null) p_repeat = 0;
		var e = new haxor.component.AnimationEvent(p_frame,p_listener,p_repeat,p_args);
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
		var ct = new haxor.component.ClipTrack();
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
	,UpdateLength: function() {
		this.m_length = 0;
		var _g1 = 0;
		var _g = this.tracks.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_length = Math.max(this.tracks[i].get_length(),this.m_length);
		}
	}
	,Sample: function(p_time,p_weight) {
		if(p_weight == null) p_weight = 1.0;
		if(!this.playing) return;
		var spd = Math.max(0,this.speed);
		var t = p_time;
		var _g = this.wrap;
		switch(_g[1]) {
		case 0:
			t = Math.min(Math.max(t,0),this.get_length());
			break;
		case 1:
			t = haxor.math.Mathf.Loop(t,0,this.get_length());
			break;
		case 2:
			t = haxor.math.Mathf.Oscilate(t,0,this.get_length());
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
		var nc = new haxor.component.AnimationClip();
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
	,__class__: haxor.component.AnimationClip
	,__properties__: $extend(haxor.core.Resource.prototype.__properties__,{get_length:"get_length"})
});
haxor.component.ClipTrack = function() {
	this.target = null;
	this.keyframes = [];
	this.property = "";
	this.m_head = 0;
	this.m_length = 0;
};
$hxClasses["haxor.component.ClipTrack"] = haxor.component.ClipTrack;
haxor.component.ClipTrack.__name__ = ["haxor","component","ClipTrack"];
haxor.component.ClipTrack.prototype = {
	get_length: function() {
		return this.m_length;
	}
	,Add: function(p_time,p_value) {
		var k = null;
		if(typeof(p_value) == "number") {
			var nk = k = new haxor.component.FloatKeyFrame();
			nk.time = p_time;
			nk.value = p_value;
		} else if(js.Boot.__instanceof(p_value,haxor.math.Vector3)) {
			var nk1 = k = new haxor.component.Vector3KeyFrame();
			nk1.time = p_time;
			nk1.value = p_value;
		} else if(js.Boot.__instanceof(p_value,haxor.math.Quaternion)) {
			var nk2 = k = new haxor.component.QuaternionKeyFrame();
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
			i0 = haxor.math.Mathf.ClampInt(mid,0,this.keyframes.length - 1);
			var i1 = haxor.math.Mathf.ClampInt(mid + 1,0,this.keyframes.length - 1);
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
		var nct = new haxor.component.ClipTrack();
		nct.target = this.target;
		nct.property = this.property;
		var i0 = haxor.math.Mathf.MinInt([p_start,this.keyframes.length - 1]);
		var i1 = haxor.math.Mathf.MinInt([p_end,this.keyframes.length - 1]);
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
	,__class__: haxor.component.ClipTrack
	,__properties__: {get_length:"get_length"}
};
haxor.component.KeyFrame = function() {
	this.time = 0;
	this.changed = false;
};
$hxClasses["haxor.component.KeyFrame"] = haxor.component.KeyFrame;
haxor.component.KeyFrame.__name__ = ["haxor","component","KeyFrame"];
haxor.component.KeyFrame.prototype = {
	Blend: function(b,r) {
		return null;
	}
	,Sample: function(v,w) {
		if(w == null) w = 1.0;
		return null;
	}
	,__class__: haxor.component.KeyFrame
};
haxor.component.FloatKeyFrame = function() {
	haxor.component.KeyFrame.call(this);
	this.value = 0;
};
$hxClasses["haxor.component.FloatKeyFrame"] = haxor.component.FloatKeyFrame;
haxor.component.FloatKeyFrame.__name__ = ["haxor","component","FloatKeyFrame"];
haxor.component.FloatKeyFrame.__super__ = haxor.component.KeyFrame;
haxor.component.FloatKeyFrame.prototype = $extend(haxor.component.KeyFrame.prototype,{
	Blend: function(b,r) {
		this.changed = false;
		var ka = this;
		var kb = b;
		var va = ka.value;
		var vb = kb.value;
		if(Math.abs(va - vb) < haxor.math.Mathf.Epsilon) return ka;
		var k = haxor.component.FloatKeyFrame.m_temp;
		k.value = haxor.math.Mathf.Lerp(ka.value,kb.value,r);
		k.changed = true;
		return k;
	}
	,Sample: function(v,w) {
		if(w == null) w = 1.0;
		if(v == null) return this.value; else return haxor.math.Mathf.Lerp(v,this.value,w);
	}
	,__class__: haxor.component.FloatKeyFrame
});
haxor.math = {};
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
haxor.math.Vector3.__properties__ = {get_forward:"get_forward",get_up:"get_up",get_right:"get_right",get_one:"get_one",get_zero:"get_zero",get_temp:"get_temp"}
haxor.math.Vector3.get_temp = function() {
	if(haxor.math.Vector3.m_temp == null) {
		haxor.math.Vector3.m_temp = [];
		haxor.math.Vector3.m_nexttemp = 0;
		var _g = 0;
		while(_g < 50000) {
			var i = _g++;
			haxor.math.Vector3.m_temp.push(haxor.math.Vector3.get_zero());
		}
	}
	var t = haxor.math.Vector3.m_temp[haxor.math.Vector3.m_nexttemp];
	haxor.math.Vector3.m_nexttemp = (haxor.math.Vector3.m_nexttemp + 1) % haxor.math.Vector3.m_temp.length;
	return t;
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
	return haxor.math.Mathf.Sqrt(dx * dx + dy * dy + dz * dz);
};
haxor.math.Vector3.Cross = function(p_a,p_b) {
	return new haxor.math.Vector3(p_a.y * p_b.z - p_a.z * p_b.y,p_a.z * p_b.x - p_a.x * p_b.z,p_a.x * p_b.y - p_a.y * p_b.x);
};
haxor.math.Vector3.Lerp = function(p_a,p_b,p_r) {
	return new haxor.math.Vector3(p_a.x + (p_b.x - p_a.x) * p_r,p_a.y + (p_b.y - p_a.y) * p_r,p_a.z + (p_b.z - p_a.z) * p_r);
};
haxor.math.Vector3.prototype = {
	get_clone: function() {
		return new haxor.math.Vector3(this.x,this.y,this.z);
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
	,get_normalized: function() {
		return this.get_clone().Normalize();
	}
	,get_inverse: function() {
		return this.get_clone().Invert();
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
	,Set3: function(v) {
		this.x = v.x;
		this.y = v.y;
		this.z = v.z;
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
	,Reflect: function(p_normal) {
		var d = Math.min(0.0,haxor.math.Vector3.Dot(p_normal,this));
		this.x += -p_normal.x * d * 2;
		this.y += -p_normal.y * d * 2;
		this.z += -p_normal.z * d * 2;
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
		var l = this.get_length();
		if(l <= 0) return this;
		this.x *= l = 1.0 / l;
		this.y *= l;
		this.z *= l;
		return this;
	}
	,ToArray: function() {
		return [this.x,this.y,this.z];
	}
	,ToString: function() {
		var a = this.ToArray();
		var s = [];
		var _g1 = 0;
		var _g = a.length;
		while(_g1 < _g) {
			var i = _g1++;
			a[i] = (a[i] * 100.0 | 0) / 100;
			s.push(a[i] >= 0?" " + a[i]:a[i] + "");
		}
		var res = "[";
		var _g11 = 0;
		var _g2 = a.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			res += s[i1] + (i1 < a.length - 1?",":"]");
		}
		return res;
	}
	,__class__: haxor.math.Vector3
	,__properties__: {get_inverse:"get_inverse",get_normalized:"get_normalized",get_length:"get_length",get_zy:"get_zy",get_zx:"get_zx",get_yz:"get_yz",get_yx:"get_yx",get_xz:"get_xz",get_xy:"get_xy",get_zyx:"get_zyx",get_zxy:"get_zxy",get_yzx:"get_yzx",get_yxz:"get_yxz",get_xzy:"get_xzy",get_clone:"get_clone"}
};
haxor.component.Vector3KeyFrame = function() {
	haxor.component.KeyFrame.call(this);
	this.value = new haxor.math.Vector3();
};
$hxClasses["haxor.component.Vector3KeyFrame"] = haxor.component.Vector3KeyFrame;
haxor.component.Vector3KeyFrame.__name__ = ["haxor","component","Vector3KeyFrame"];
haxor.component.Vector3KeyFrame.__super__ = haxor.component.KeyFrame;
haxor.component.Vector3KeyFrame.prototype = $extend(haxor.component.KeyFrame.prototype,{
	Blend: function(b,r) {
		this.changed = false;
		var ka = this;
		var kb = b;
		var va = ka.value;
		var vb = kb.value;
		if(Math.abs(va.x - vb.x) < haxor.math.Mathf.Epsilon) {
			if(Math.abs(va.y - vb.y) < haxor.math.Mathf.Epsilon) {
				if(Math.abs(va.z - vb.z) < haxor.math.Mathf.Epsilon) return ka;
			}
		}
		var k = haxor.component.Vector3KeyFrame.m_temp;
		k.value = haxor.math.Vector3.Lerp(va,vb,r);
		k.changed = true;
		return k;
	}
	,Sample: function(v,w) {
		if(w == null) w = 1.0;
		if(v == null) return this.value; else return haxor.math.Vector3.Lerp(v,this.value,w);
	}
	,__class__: haxor.component.Vector3KeyFrame
});
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
haxor.math.Quaternion.__properties__ = {get_identity:"get_identity",get_temp:"get_temp"}
haxor.math.Quaternion.get_temp = function() {
	if(haxor.math.Quaternion.m_temp == null) {
		haxor.math.Quaternion.m_temp = [];
		haxor.math.Quaternion.m_nexttemp = 0;
		var _g = 0;
		while(_g < 50000) {
			var i = _g++;
			haxor.math.Quaternion.m_temp.push(haxor.math.Quaternion.get_identity());
		}
	}
	var t = haxor.math.Quaternion.m_temp[haxor.math.Quaternion.m_nexttemp];
	haxor.math.Quaternion.m_nexttemp = (haxor.math.Quaternion.m_nexttemp + 1) % haxor.math.Quaternion.m_temp.length;
	return t;
};
haxor.math.Quaternion.get_identity = function() {
	return new haxor.math.Quaternion(0,0,0,1.0);
};
haxor.math.Quaternion.Lerp = function(p_a,p_b,p_ratio) {
	var c = new haxor.math.Quaternion();
	var ca = p_a.get_clone();
	var dot = p_a.Dot(p_b);
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
	var cosHalfTheta = p_a.w * p_b.w + p_a.x * p_b.x + p_a.y * p_b.y + p_a.z * p_b.z;
	if(Math.abs(cosHalfTheta) >= 1.0) {
		qm.w = p_a.w;
		qm.x = p_a.x;
		qm.y = p_a.y;
		qm.z = p_a.z;
		return qm;
	}
	var halfTheta = Math.acos(cosHalfTheta);
	var sinHalfTheta = Math.sqrt(1.0 - cosHalfTheta * cosHalfTheta);
	if(Math.abs(sinHalfTheta) < 0.001) {
		qm.w = p_a.w * 0.5 + p_b.w * 0.5;
		qm.x = p_a.x * 0.5 + p_b.x * 0.5;
		qm.y = p_a.y * 0.5 + p_b.y * 0.5;
		qm.z = p_a.z * 0.5 + p_b.z * 0.5;
		return qm;
	}
	var ratioA = Math.sin((1.0 - p_ratio) * halfTheta) / sinHalfTheta;
	var ratioB = Math.sin(p_ratio * halfTheta) / sinHalfTheta;
	qm.w = p_a.w * ratioA + p_b.w * ratioB;
	qm.x = p_a.x * ratioA + p_b.x * ratioB;
	qm.y = p_a.y * ratioA + p_b.y * ratioB;
	qm.z = p_a.z * ratioA + p_b.z * ratioB;
	return qm;
};
haxor.math.Quaternion.FromAxisAngle = function(p_axis,p_angle) {
	p_angle = p_angle * 0.5 * haxor.math.Mathf.Deg2Rad;
	var l = p_axis.get_length();
	if(haxor.math.Mathf.Abs(l - 1.0) > haxor.math.Mathf.Epsilon) p_axis.Normalize();
	var s = haxor.math.Mathf.Sin(p_angle);
	return new haxor.math.Quaternion(p_axis.x * s,p_axis.y * s,p_axis.z * s,haxor.math.Mathf.Cos(p_angle));
};
haxor.math.Quaternion.FromEuler = function(p_euler) {
	var q = new haxor.math.Quaternion();
	var ax = p_euler.x * haxor.math.Mathf.Rad2Deg;
	var ay = p_euler.y * haxor.math.Mathf.Rad2Deg;
	var az = p_euler.z * haxor.math.Mathf.Rad2Deg;
	var c1 = haxor.math.Mathf.Cos(ax * 0.5);
	var s1 = haxor.math.Mathf.Sin(ax * 0.5);
	var c2 = haxor.math.Mathf.Cos(ay * 0.5);
	var s2 = haxor.math.Mathf.Sin(ay * 0.5);
	var c3 = haxor.math.Mathf.Cos(az * 0.5);
	var s3 = haxor.math.Mathf.Sin(az * 0.5);
	var c1c2 = c1 * c2;
	var s1s2 = s1 * s2;
	q.w = c1c2 * c3 - s1s2 * s3;
	q.x = c1c2 * s3 + s1s2 * c3;
	q.y = s1 * c2 * c3 + c1 * s2 * s3;
	q.z = c1 * s2 * c3 - s1 * c2 * s3;
	q.Normalize();
	return q;
};
haxor.math.Quaternion.LookAt = function(p_from,p_at,p_up) {
	return haxor.math.Matrix4.LookAt(p_from,p_at,p_up).get_quaternion();
};
haxor.math.Quaternion.LookRotation = function(p_forward,p_up) {
	return haxor.math.Matrix4.LookRotation(p_forward,p_up).get_quaternion();
};
haxor.math.Quaternion.prototype = {
	get_matrix: function() {
		this.Normalize();
		var m = haxor.math.Matrix4.get_temp();
		var x2 = this.x * this.x;
		var y2 = this.y * this.y;
		var z2 = this.z * this.z;
		var xy = this.x * this.y;
		var xz = this.x * this.z;
		var yz = this.y * this.z;
		var xw = this.w * this.x;
		var yw = this.w * this.y;
		var zw = this.w * this.z;
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
	}
	,get_euler: function() {
		this.Normalize();
		var test = this.x * this.y + this.z * this.w;
		var a = new haxor.math.Vector3();
		if(test > 0.499) {
			a.x = 2.0 * haxor.math.Mathf.Atan2(this.x,this.w) * haxor.math.Mathf.Rad2Deg;
			a.y = haxor.math.Mathf.HalfPI * haxor.math.Mathf.Rad2Deg;
			a.z = 0;
			return a;
		}
		if(test < -0.499) {
			a.x = -2. * haxor.math.Mathf.Atan2(this.x,this.w) * haxor.math.Mathf.Rad2Deg;
			a.y = -haxor.math.Mathf.HalfPI * haxor.math.Mathf.Rad2Deg;
			a.z = 0;
			return a;
		}
		var sqx = this.x * this.x;
		var sqy = this.y * this.y;
		var sqz = this.z * this.z;
		a.x = haxor.math.Mathf.Atan2(2.0 * this.y * this.w - 2.0 * this.x * this.z,1.0 - 2.0 * sqy - 2.0 * sqz) * haxor.math.Mathf.Rad2Deg;
		a.y = haxor.math.Mathf.Asin(2.0 * test) * haxor.math.Mathf.Rad2Deg;
		a.z = haxor.math.Mathf.Atan2(2.0 * this.x * this.w - 2.0 * this.y * this.z,1.0 - 2.0 * sqx - 2.0 * sqz) * haxor.math.Mathf.Rad2Deg;
		return a;
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
		return this.get_clone().Normalize();
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
	,Dot: function(p_v) {
		return this.x * p_v.x + this.y * p_v.y + this.z * p_v.z + this.w * p_v.w;
	}
	,Normalize: function() {
		var l = this.get_length();
		if(l <= 0) {
			this.x = this.y = this.z = this.w = 0.0;
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
		p_v.Normalize();
		var qv = new haxor.math.Quaternion(p_v.x,p_v.y,p_v.z,0);
		var a = this.get_clone();
		a.Multiply(qv.Multiply(this.get_conjugate()));
		p_v.x = a.x;
		p_v.y = a.y;
		p_v.z = a.z;
		return p_v;
	}
	,SetAxisAngle: function(p_axis,p_angle) {
		p_angle = p_angle * 0.5 * haxor.math.Mathf.Deg2Rad;
		var l = p_axis.get_length();
		if(haxor.math.Mathf.Abs(l - 1.0) > haxor.math.Mathf.Epsilon) p_axis.Normalize();
		var s = haxor.math.Mathf.Sin(p_angle);
		this.Set(p_axis.x * s,p_axis.y * s,p_axis.z * s,haxor.math.Mathf.Cos(p_angle));
		return this;
	}
	,ToArray: function() {
		return [this.x,this.y,this.z,this.w];
	}
	,ToString: function() {
		var a = this.ToArray();
		var s = [];
		var _g1 = 0;
		var _g = a.length;
		while(_g1 < _g) {
			var i = _g1++;
			a[i] = haxor.math.Mathf.RoundPlaces(a[i],4);
			s.push(a[i] >= 0?" " + a[i]:a[i] + "");
		}
		var res = "[";
		var _g11 = 0;
		var _g2 = a.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			res += s[i1] + (i1 < a.length - 1?",":"]");
		}
		return res;
	}
	,__class__: haxor.math.Quaternion
	,__properties__: {get_conjugate:"get_conjugate",get_normalized:"get_normalized",get_length:"get_length",get_xyzw:"get_xyzw",get_clone:"get_clone",get_euler:"get_euler",get_matrix:"get_matrix"}
};
haxor.component.QuaternionKeyFrame = function() {
	haxor.component.KeyFrame.call(this);
	this.value = haxor.math.Quaternion.get_identity();
};
$hxClasses["haxor.component.QuaternionKeyFrame"] = haxor.component.QuaternionKeyFrame;
haxor.component.QuaternionKeyFrame.__name__ = ["haxor","component","QuaternionKeyFrame"];
haxor.component.QuaternionKeyFrame.__super__ = haxor.component.KeyFrame;
haxor.component.QuaternionKeyFrame.prototype = $extend(haxor.component.KeyFrame.prototype,{
	Blend: function(b,r) {
		this.changed = true;
		var ka = this;
		var kb = b;
		var va = ka.value;
		var vb = kb.value;
		if(Math.abs(va.x - vb.x) < haxor.math.Mathf.Epsilon) {
			if(Math.abs(va.y - vb.y) < haxor.math.Mathf.Epsilon) {
				if(Math.abs(va.z - vb.z) < haxor.math.Mathf.Epsilon) {
					if(Math.abs(va.w - vb.w) < haxor.math.Mathf.Epsilon) return ka;
				}
			}
		}
		var k = haxor.component.QuaternionKeyFrame.m_temp;
		k.value = haxor.math.Quaternion.Lerp(va,vb,r);
		k.changed = true;
		return k;
	}
	,Sample: function(v,w) {
		if(w == null) w = 1.0;
		if(v == null) return this.value; else return haxor.math.Quaternion.Lerp(v,this.value,w);
	}
	,__class__: haxor.component.QuaternionKeyFrame
});
haxor.component.AssetData = function(e) {
	haxor.component.Component.call(this,e);
	this.content = { };
};
$hxClasses["haxor.component.AssetData"] = haxor.component.AssetData;
haxor.component.AssetData.__name__ = ["haxor","component","AssetData"];
haxor.component.AssetData.__super__ = haxor.component.Component;
haxor.component.AssetData.prototype = $extend(haxor.component.Component.prototype,{
	__class__: haxor.component.AssetData
});
haxor.component.ClearFlag = function() { };
$hxClasses["haxor.component.ClearFlag"] = haxor.component.ClearFlag;
haxor.component.ClearFlag.__name__ = ["haxor","component","ClearFlag"];
haxor.core.IResizeable = function() { };
$hxClasses["haxor.core.IResizeable"] = haxor.core.IResizeable;
haxor.core.IResizeable.__name__ = ["haxor","core","IResizeable"];
haxor.core.IResizeable.prototype = {
	__class__: haxor.core.IResizeable
};
haxor.component.Camera = function(p_entity) {
	haxor.component.Behaviour.call(this,p_entity);
	if(haxor.component.Camera.m_list == null) haxor.component.Camera.m_list = new Array();
	this.m_depth = 0;
	this.m_pixelViewport = haxor.math.AABB2.get_empty();
	this.m_viewport = haxor.math.AABB2.get_empty();
	this.m_worldToCamera = haxor.math.Matrix4.get_identity();
	this.m_cameraToWorld = haxor.math.Matrix4.get_identity();
	this.m_projectionMatrix = haxor.math.Matrix4.get_identity();
	this.m_projectionMatrixInverse = haxor.math.Matrix4.get_identity();
	this.m_skyboxProjection = haxor.math.Matrix4.get_identity();
	this.m_skyboxProjectionInverse = haxor.math.Matrix4.get_identity();
	this.m_fov = 60;
	this.m_near = 0.1;
	this.m_far = 500;
	this.m_filters = [];
	this.background = new haxor.math.Color(0,0,0,1);
	this.clear = haxor.component.ClearFlag.ColorDepth;
	this.mask = 1;
	haxor.component.Camera.m_list.push(this);
	haxor.component.Camera.SortCameraList();
	this.set_viewport(new haxor.math.AABB2(0,0,1,1));
};
$hxClasses["haxor.component.Camera"] = haxor.component.Camera;
haxor.component.Camera.__name__ = ["haxor","component","Camera"];
haxor.component.Camera.__interfaces__ = [haxor.core.IResizeable];
haxor.component.Camera.__properties__ = {get_list:"get_list"}
haxor.component.Camera.get_list = function() {
	var l = new Array();
	if(haxor.component.Camera.m_list == null) return l;
	var i = 0;
	while(i < haxor.component.Camera.m_list.length) {
		l.push(haxor.component.Camera.m_list[i]);
		i++;
	}
	return l;
};
haxor.component.Camera.SortCameraList = function() {
	haxor.component.Camera.m_list.sort(function(a,b) {
		if(a.get_depth() == b.get_depth()) {
			if(a.get_entity().get_name() < b.get_entity().get_name()) return -1; else return 1;
		} else if(a.get_depth() < b.get_depth()) return -1; else return 1;
	});
};
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
	,get_depth: function() {
		return this.m_depth;
	}
	,set_depth: function(v) {
		this.m_depth = v;
		haxor.component.Camera.SortCameraList();
		return this.m_depth;
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
		this.OnResize(haxor.graphics.Screen.get_width(),haxor.graphics.Screen.get_height());
		return v;
	}
	,get_CameraToWorld: function() {
		return this.m_cameraToWorld;
	}
	,get_WorldToCamera: function() {
		return this.m_worldToCamera;
	}
	,get_ProjectionMatrix: function() {
		return this.m_projectionMatrix;
	}
	,get_ProjectionMatrixInverse: function() {
		return this.m_projectionMatrixInverse;
	}
	,get_target: function() {
		return this.m_target;
	}
	,set_target: function(v) {
		this.m_target = v;
		if(v != null) this.OnResize(v.get_width(),v.get_height());
		return v;
	}
	,get_filters: function() {
		return this.m_filters;
	}
	,set_filters: function(v) {
		if(v == null) this.m_filters = []; else this.m_filters = v;
		return this.m_filters;
	}
	,OnResize: function(w,h) {
		var vx = Std["int"](this.m_viewport.get_x() * w);
		var vy = Std["int"](this.m_viewport.get_y() * h);
		var aw = this.m_viewport.get_width() * w;
		var ah = this.m_viewport.get_height() * h;
		if(this.m_target != null) {
			aw = this.m_target.get_width();
			ah = this.m_target.get_height();
		}
		this.m_pixelViewport.set_x(vx);
		this.m_pixelViewport.set_y(h - ah - vy);
		this.m_pixelViewport.set_width(aw);
		this.m_pixelViewport.set_height(ah);
		this.m_aspect = aw / ah;
		var tw = aw;
		var th = ah;
		if(this.m_srcRT != null) {
			if(tw != this.m_srcRT.get_width()) {
				haxor.core.Resource.Destroy(this.m_srcRT);
				haxor.core.Resource.Destroy(this.m_dstRT);
				haxor.core.Resource.Destroy(this.m_g0);
				haxor.core.Resource.Destroy(this.m_g1);
				this.m_g0 = this.m_g1 = this.m_dstRT = this.m_srcRT = null;
			} else if(th != this.m_srcRT.get_height()) {
				haxor.core.Resource.Destroy(this.m_srcRT);
				haxor.core.Resource.Destroy(this.m_dstRT);
				haxor.core.Resource.Destroy(this.m_g0);
				haxor.core.Resource.Destroy(this.m_g1);
				this.m_g0 = this.m_g1 = this.m_dstRT = this.m_srcRT = null;
			}
		}
		if(this.m_srcRT == null) {
			this.m_srcRT = new haxor.texture.RenderTexture(aw,ah,haxor.texture.TextureFormat.RGBA8,true);
			this.m_dstRT = new haxor.texture.RenderTexture(aw,ah,haxor.texture.TextureFormat.RGBA8,true);
			this.m_g0 = new haxor.texture.RenderTexture(aw,ah,haxor.texture.TextureFormat.RGBA8,true);
			this.m_g1 = new haxor.texture.RenderTexture(aw,ah,haxor.texture.TextureFormat.RGBA8,true);
			this.m_g0.set_name(this.m_g1.set_name("ScreenBufferTexture"));
			this.m_grab = this.m_g0;
			this.m_back = this.m_g1;
		}
		this.UpdateProjection();
	}
	,WorldToProjection: function(p_world_point) {
		var p = haxor.math.Vector4.get_temp();
		p.w = 1.0;
		p.x = p_world_point.x;
		p.y = p_world_point.y;
		p.z = p_world_point.z;
		this.m_worldToCamera.Transform4x4(p);
		this.m_projectionMatrix.Transform4x4(p);
		return p;
	}
	,IsCulled: function(p_world_point) {
		return this.WorldToProjection(p_world_point).IsCulled();
	}
	,LookAt: function(p_at,p_up) {
		this.get_transform().set_rotation(haxor.math.Quaternion.LookAt(this.get_transform().get_position(),p_at));
	}
	,UpdateProjection: function() {
		this.m_projectionMatrix.SetPerspective(this.m_fov,this.m_aspect,this.m_near,this.m_far);
		this.m_projectionMatrixInverse.SetPerspectiveInverse(this.m_fov,this.m_aspect,this.m_near,this.m_far);
		this.m_skyboxProjection.SetPerspective(this.m_fov,this.m_aspect,0.1,100000.0);
		this.m_skyboxProjectionInverse.SetPerspectiveInverse(this.m_fov,this.m_aspect,0.1,100000.0);
	}
	,OnTransformUpdate: function() {
		this.m_worldToCamera.SetIdentity();
		var wm = this.get_entity().get_transform().get_WorldMatrix();
		var m = haxor.math.Matrix4.get_temp();
		m.Set(wm.m00,wm.m01,wm.m02,wm.m03,wm.m10,wm.m11,wm.m12,wm.m13,wm.m20,wm.m21,wm.m22,wm.m23,0,0,0,1);
		var ex = m.m03;
		var ey = m.m13;
		var ez = m.m23;
		var r = m.ToRotation();
		var vxx = r.m00;
		var vxy = r.m01;
		var vxz = r.m02;
		var vyx = r.m10;
		var vyy = r.m11;
		var vyz = r.m12;
		var vzx = r.m20;
		var vzy = r.m21;
		var vzz = r.m22;
		this.m_worldToCamera.m00 = vxx;
		this.m_worldToCamera.m01 = vyx;
		this.m_worldToCamera.m02 = vzx;
		this.m_worldToCamera.m10 = vxy;
		this.m_worldToCamera.m11 = vyy;
		this.m_worldToCamera.m12 = vzy;
		this.m_worldToCamera.m20 = vxz;
		this.m_worldToCamera.m21 = vyz;
		this.m_worldToCamera.m22 = vzz;
		this.m_worldToCamera.m03 = -(ex * this.m_worldToCamera.m00 + ey * this.m_worldToCamera.m01 + ez * this.m_worldToCamera.m02);
		this.m_worldToCamera.m13 = -(ex * this.m_worldToCamera.m10 + ey * this.m_worldToCamera.m11 + ez * this.m_worldToCamera.m12);
		this.m_worldToCamera.m23 = -(ex * this.m_worldToCamera.m20 + ey * this.m_worldToCamera.m21 + ez * this.m_worldToCamera.m22);
		haxor.math.Matrix4.GetInverseTransform(this.m_worldToCamera,this.m_cameraToWorld);
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
	,__class__: haxor.component.Camera
	,__properties__: $extend(haxor.component.Behaviour.prototype.__properties__,{set_filters:"set_filters",get_filters:"get_filters",get_ProjectionMatrixInverse:"get_ProjectionMatrixInverse",get_ProjectionMatrix:"get_ProjectionMatrix",get_WorldToCamera:"get_WorldToCamera",get_CameraToWorld:"get_CameraToWorld",set_viewport:"set_viewport",get_viewport:"get_viewport",get_pixelViewport:"get_pixelViewport",set_depth:"set_depth",get_depth:"get_depth",set_far:"set_far",get_far:"get_far",set_near:"set_near",get_near:"get_near",set_fov:"set_fov",get_fov:"get_fov"})
});
haxor.core.IUpdateable = function() { };
$hxClasses["haxor.core.IUpdateable"] = haxor.core.IUpdateable;
haxor.core.IUpdateable.__name__ = ["haxor","core","IUpdateable"];
haxor.core.IUpdateable.prototype = {
	__class__: haxor.core.IUpdateable
};
haxor.component.CameraOrbit = function(p_entity) {
	haxor.component.Behaviour.call(this,p_entity);
};
$hxClasses["haxor.component.CameraOrbit"] = haxor.component.CameraOrbit;
haxor.component.CameraOrbit.__name__ = ["haxor","component","CameraOrbit"];
haxor.component.CameraOrbit.__interfaces__ = [haxor.core.IUpdateable];
haxor.component.CameraOrbit.Create = function(p_distance,p_angle_x,p_angle_y) {
	if(p_angle_y == null) p_angle_y = 0;
	if(p_angle_x == null) p_angle_x = 0;
	if(p_distance == null) p_distance = 1;
	var e = new haxor.core.Entity();
	e.set_name("camera_orbit");
	var c = e.AddComponent(haxor.component.Camera);
	c.background = haxor.math.Color.get_black();
	var orbit = e.AddComponent(haxor.component.CameraOrbit);
	orbit.distance = p_distance;
	orbit.smooth = 0;
	orbit.angle = new haxor.math.Vector2(p_angle_x,p_angle_y);
	return orbit;
};
haxor.component.CameraOrbit.__super__ = haxor.component.Behaviour;
haxor.component.CameraOrbit.prototype = $extend(haxor.component.Behaviour.prototype,{
	get_pivot: function() {
		if(this.m_pivot == null) {
			var e = new haxor.core.Entity();
			this.m_pivot = e.get_transform();
			this.m_pivot.set_name("camera_orbit");
			this.m_pivot.set_parent(this.get_entity().get_transform().get_parent());
			this.get_entity().get_transform().set_parent(this.m_pivot);
			this.m_pivot.set_position(this.get_entity().get_transform().get_position());
		}
		return this.m_pivot;
	}
	,OnAwake: function() {
		this.m_pivot = this.get_pivot();
	}
	,OnStart: function() {
		if(this.distance == null) this.m_distance = 1.0; else this.m_distance = this.distance;
		if(this.angle == null) this.m_angle = haxor.math.Vector2.get_zero(); else this.m_angle = this.angle.get_clone();
		this.m_rotation = haxor.math.Quaternion.get_identity();
	}
	,OnUpdate: function() {
		var blend;
		if(this.smooth <= 0) blend = 1.0; else blend = haxor.core.Time.get_frameDeltaTime() * this.smooth;
		this.m_angle.x = haxor.math.Mathf.Lerp(this.m_angle.x,this.angle.x,blend);
		this.m_angle.y = haxor.math.Mathf.Lerp(this.m_angle.y,this.angle.y,blend);
		this.m_distance = haxor.math.Mathf.Lerp(this.m_distance,this.distance,blend);
		var p = haxor.math.Vector3.get_temp();
		p.Set(0,0,this.m_distance);
		this.get_entity().get_transform().set_position(p);
		var q = haxor.math.Quaternion.get_temp();
		q.SetAxisAngle(haxor.math.Vector3.get_up(),this.m_angle.x);
		q.Multiply(haxor.math.Quaternion.get_temp().SetAxisAngle(haxor.math.Vector3.get_right(),this.m_angle.y));
		this.get_pivot().set_rotation(q);
		if(this.target != null) {
			var p1 = this.get_pivot().get_position();
			p1 = haxor.math.Vector3.Lerp(p1,this.target.get_position(),haxor.core.Time.get_deltaTime() * this.smooth);
			this.get_pivot().set_position(p1);
		}
	}
	,__class__: haxor.component.CameraOrbit
	,__properties__: $extend(haxor.component.Behaviour.prototype.__properties__,{get_pivot:"get_pivot"})
});
haxor.component.CameraOrbitInput = function(p_entity) {
	this.rotateSpeed = 0.8;
	this.zoomSpeed = 2.0;
	this.zoom = true;
	this.rotate = true;
	haxor.component.Behaviour.call(this,p_entity);
};
$hxClasses["haxor.component.CameraOrbitInput"] = haxor.component.CameraOrbitInput;
haxor.component.CameraOrbitInput.__name__ = ["haxor","component","CameraOrbitInput"];
haxor.component.CameraOrbitInput.__interfaces__ = [haxor.core.IUpdateable];
haxor.component.CameraOrbitInput.__super__ = haxor.component.Behaviour;
haxor.component.CameraOrbitInput.prototype = $extend(haxor.component.Behaviour.prototype,{
	OnStart: function() {
		this.m_orbit = this.GetComponent(haxor.component.CameraOrbit);
	}
	,OnUpdate: function() {
		var dx;
		if(haxor.input.Input.get_touch().length == 1) dx = haxor.input.Input.get_touch()[0].delta.x; else dx = haxor.input.Input.deltaMouse.x;
		var dy;
		if(haxor.input.Input.get_touch().length == 1) dy = haxor.input.Input.get_touch()[0].delta.y; else dy = haxor.input.Input.deltaMouse.y;
		if(this.rotate) {
			var is_rotate = haxor.input.Input.GetInputState(haxor.input.KeyCode.Mouse0) == haxor.input.InputState.Hold || haxor.input.Input.get_touch().length == 1;
			if(is_rotate) {
				this.m_orbit.angle.x += -dx * this.rotateSpeed;
				this.m_orbit.angle.y += -dy * this.rotateSpeed;
			}
		}
		if(this.zoom) {
			if(Math.abs(haxor.input.Input.wheel) > 0) if(haxor.input.Input.wheel < 0) this.m_orbit.distance += this.zoomSpeed; else this.m_orbit.distance += -this.zoomSpeed;
			if(haxor.input.Input.get_touch().length == 2) this.m_orbit.distance -= haxor.input.Input.get_touch()[0].delta.y * this.zoomSpeed * 0.05;
		}
	}
	,__class__: haxor.component.CameraOrbitInput
});
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
haxor.math.Color.__properties__ = {get_gray90:"get_gray90",get_gray75:"get_gray75",get_gray50:"get_gray50",get_gray25:"get_gray25",get_gray10:"get_gray10",get_empty:"get_empty",get_white:"get_white",get_black:"get_black",get_magenta:"get_magenta",get_blue:"get_blue",get_cyan:"get_cyan",get_green:"get_green",get_yellow:"get_yellow",get_red:"get_red",get_temp:"get_temp"}
haxor.math.Color.get_temp = function() {
	if(haxor.math.Color.m_temp == null) {
		haxor.math.Color.m_temp = [];
		haxor.math.Color.m_nexttemp = 0;
		var _g = 0;
		while(_g < 50000) {
			var i = _g++;
			haxor.math.Color.m_temp.push(new haxor.math.Color(0,0,0,1));
		}
	}
	var t = haxor.math.Color.m_temp[haxor.math.Color.m_nexttemp];
	haxor.math.Color.m_nexttemp = (haxor.math.Color.m_nexttemp + 1) % haxor.math.Color.m_temp.length;
	return t;
};
haxor.math.Color.get_red = function() {
	return haxor.math.Color.get_temp().Set(1.0,0,0,1);
};
haxor.math.Color.get_yellow = function() {
	return haxor.math.Color.get_temp().Set(1,1,0,1);
};
haxor.math.Color.get_green = function() {
	return haxor.math.Color.get_temp().Set(0,1,0,1);
};
haxor.math.Color.get_cyan = function() {
	return haxor.math.Color.get_temp().Set(0,1,1,1);
};
haxor.math.Color.get_blue = function() {
	return haxor.math.Color.get_temp().Set(0,0,1,1);
};
haxor.math.Color.get_magenta = function() {
	return haxor.math.Color.get_temp().Set(1,0,1,1);
};
haxor.math.Color.get_black = function() {
	return haxor.math.Color.get_temp().Set(0,0,0,1);
};
haxor.math.Color.get_white = function() {
	return haxor.math.Color.get_temp().Set(1,1,1,1);
};
haxor.math.Color.get_empty = function() {
	return haxor.math.Color.get_temp().Set(0,0,0,0);
};
haxor.math.Color.get_gray10 = function() {
	return haxor.math.Color.get_temp().Set(0.1,0.1,0.1,1);
};
haxor.math.Color.get_gray25 = function() {
	return haxor.math.Color.get_temp().Set(0.25,0.25,0.25,1);
};
haxor.math.Color.get_gray50 = function() {
	return haxor.math.Color.get_temp().Set(0.5,0.5,0.5,1);
};
haxor.math.Color.get_gray75 = function() {
	return haxor.math.Color.get_temp().Set(0.75,0.75,0.75,1);
};
haxor.math.Color.get_gray90 = function() {
	return haxor.math.Color.get_temp().Set(0.9,0.9,0.9,1);
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
	return new haxor.math.Color(p_r * haxor.math.Mathf.Byte2Float,p_g * haxor.math.Mathf.Byte2Float,p_b * haxor.math.Mathf.Byte2Float,p_a * haxor.math.Mathf.Byte2Float);
};
haxor.math.Color.Lerp = function(a,b,r) {
	return new haxor.math.Color(haxor.math.Mathf.Lerp(a.r,b.r,r),haxor.math.Mathf.Lerp(a.g,b.g,r),haxor.math.Mathf.Lerp(a.b,b.b,r),haxor.math.Mathf.Lerp(a.a,b.a,r));
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
		var rb = this.r * haxor.math.Mathf.Float2Byte;
		var gb = this.g * haxor.math.Mathf.Float2Byte;
		var bb = this.b * haxor.math.Mathf.Float2Byte;
		var ab = this.a * haxor.math.Mathf.Float2Byte;
		return ab << 24 | rb << 16 | gb << 8 | bb;
	}
	,set_argb: function(v) {
		this.a = (v >> 24 & 255) * haxor.math.Mathf.Byte2Float;
		this.g = (v >> 16 & 255) * haxor.math.Mathf.Byte2Float;
		this.b = (v >> 8 & 255) * haxor.math.Mathf.Byte2Float;
		this.r = (v & 255) * haxor.math.Mathf.Byte2Float;
		return v;
	}
	,get_css: function() {
		return "rgba(" + (this.r * 255 | 0) + "," + (this.g * 255 | 0) + "," + (this.b * 255 | 0) + "," + this.a + ")";
	}
	,get_rgba: function() {
		var rb = this.r * haxor.math.Mathf.Float2Byte;
		var gb = this.g * haxor.math.Mathf.Float2Byte;
		var bb = this.b * haxor.math.Mathf.Float2Byte;
		var ab = this.a * haxor.math.Mathf.Float2Byte;
		return rb << 24 | gb << 16 | bb << 8 | ab;
	}
	,set_rgba: function(v) {
		this.r = (v >> 24 & 255) * haxor.math.Mathf.Byte2Float;
		this.g = (v >> 16 & 255) * haxor.math.Mathf.Byte2Float;
		this.b = (v >> 8 & 255) * haxor.math.Mathf.Byte2Float;
		this.a = (v & 255) * haxor.math.Mathf.Byte2Float;
		return v;
	}
	,get_rgb: function() {
		var rb = this.r * haxor.math.Mathf.Float2Byte;
		var gb = this.g * haxor.math.Mathf.Float2Byte;
		var bb = this.b * haxor.math.Mathf.Float2Byte;
		return rb << 16 | gb << 8 | bb;
	}
	,set_rgb: function(v) {
		this.r = (v >> 16 & 255) * haxor.math.Mathf.Byte2Float;
		this.g = (v >> 8 & 255) * haxor.math.Mathf.Byte2Float;
		this.b = (v & 255) * haxor.math.Mathf.Byte2Float;
		return v;
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
	,Set4: function(p_color) {
		if(p_color == null) this.r = 0.0; else this.r = p_color.r;
		if(p_color == null) this.g = 0.0; else this.g = p_color.g;
		if(p_color == null) this.b = 0.0; else this.b = p_color.b;
		if(p_color == null) this.a = 1.0; else this.a = p_color.a;
		return this;
	}
	,ToArray: function() {
		return [this.r,this.g,this.b,this.a];
	}
	,ToString: function() {
		var a = this.ToArray();
		var s = [];
		var _g1 = 0;
		var _g = a.length;
		while(_g1 < _g) {
			var i = _g1++;
			a[i] = (a[i] * 100.0 | 0) / 100;
			s.push(a[i] >= 0?" " + a[i]:a[i] + "");
		}
		var res = "[";
		var _g11 = 0;
		var _g2 = a.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			res += s[i1] + (i1 < a.length - 1?",":"]");
		}
		return res;
	}
	,__class__: haxor.math.Color
	,__properties__: {set_rgb:"set_rgb",get_rgb:"get_rgb",set_rgba:"set_rgba",get_rgba:"get_rgba",get_css:"get_css",set_argb:"set_argb",get_argb:"get_argb",get_xyzw:"get_xyzw",get_xyz:"get_xyz",get_clone:"get_clone"}
};
haxor.component.Light = function(p_entity) {
	if(haxor.component.Light.m_list == null) haxor.component.Light.m_list = [];
	if(haxor.component.Light.m_buffer == null) haxor.component.Light.m_buffer = new Float32Array(12 * haxor.component.Light.max);
	haxor.component.Light.m_list.push(this);
	haxor.component.Behaviour.call(this,p_entity);
	this.color = haxor.math.Color.get_white();
	this.intensity = 1.0;
};
$hxClasses["haxor.component.Light"] = haxor.component.Light;
haxor.component.Light.__name__ = ["haxor","component","Light"];
haxor.component.Light.__properties__ = {get_list:"get_list"}
haxor.component.Light.SetLightData = function(p_id,p_type,p_intensity,p_radius,p_atten,p_x,p_y,p_z,p_r,p_g,p_b,p_a) {
	var pos = p_id * 12;
	haxor.component.Light.m_buffer[pos] = p_type;
	haxor.component.Light.m_buffer[pos + 1] = p_intensity;
	haxor.component.Light.m_buffer[pos + 2] = p_radius;
	haxor.component.Light.m_buffer[pos + 3] = p_atten;
	haxor.component.Light.m_buffer[pos + 4] = p_x;
	haxor.component.Light.m_buffer[pos + 5] = p_y;
	haxor.component.Light.m_buffer[pos + 6] = p_z;
	haxor.component.Light.m_buffer[pos + 8] = p_r;
	haxor.component.Light.m_buffer[pos + 9] = p_g;
	haxor.component.Light.m_buffer[pos + 10] = p_b;
	haxor.component.Light.m_buffer[pos + 11] = p_a;
};
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
haxor.component.Light.__super__ = haxor.component.Behaviour;
haxor.component.Light.prototype = $extend(haxor.component.Behaviour.prototype,{
	OnDestroy: function() {
		haxor.component.Behaviour.prototype.OnDestroy.call(this);
		HxOverrides.remove(haxor.component.Light.m_list,this);
	}
	,__class__: haxor.component.Light
});
haxor.component.DirectionalLight = function(p_entity) {
	haxor.component.Light.call(this,p_entity);
};
$hxClasses["haxor.component.DirectionalLight"] = haxor.component.DirectionalLight;
haxor.component.DirectionalLight.__name__ = ["haxor","component","DirectionalLight"];
haxor.component.DirectionalLight.__super__ = haxor.component.Light;
haxor.component.DirectionalLight.prototype = $extend(haxor.component.Light.prototype,{
	__class__: haxor.component.DirectionalLight
});
haxor.core.IQueueRenderable = function() { };
$hxClasses["haxor.core.IQueueRenderable"] = haxor.core.IQueueRenderable;
haxor.core.IQueueRenderable.__name__ = ["haxor","core","IQueueRenderable"];
haxor.core.IQueueRenderable.prototype = {
	__class__: haxor.core.IQueueRenderable
};
haxor.component.Renderer = function(p_entity) {
	haxor.component.Behaviour.call(this,p_entity);
};
$hxClasses["haxor.component.Renderer"] = haxor.component.Renderer;
haxor.component.Renderer.__name__ = ["haxor","component","Renderer"];
haxor.component.Renderer.__interfaces__ = [haxor.core.IQueueRenderable];
haxor.component.Renderer.__super__ = haxor.component.Behaviour;
haxor.component.Renderer.prototype = $extend(haxor.component.Behaviour.prototype,{
	GetQueue: function() {
		if(this.material == null) return 9999; else return this.material.queue;
	}
	,OnRender: function() {
	}
	,__class__: haxor.component.Renderer
});
haxor.component.MeshRenderer = function(p_entity) {
	haxor.component.Renderer.call(this,p_entity);
	haxor.component.MeshRenderer.get_list().push(this);
	this.m_culled = new haxe.ds.ObjectMap();
	this.visible = true;
};
$hxClasses["haxor.component.MeshRenderer"] = haxor.component.MeshRenderer;
haxor.component.MeshRenderer.__name__ = ["haxor","component","MeshRenderer"];
haxor.component.MeshRenderer.__properties__ = {get_list:"get_list"}
haxor.component.MeshRenderer.get_list = function() {
	if(haxor.component.MeshRenderer.m_list == null) return haxor.component.MeshRenderer.m_list = []; else return haxor.component.MeshRenderer.m_list;
};
haxor.component.MeshRenderer.__super__ = haxor.component.Renderer;
haxor.component.MeshRenderer.prototype = $extend(haxor.component.Renderer.prototype,{
	get_mesh: function() {
		return this.m_mesh;
	}
	,set_mesh: function(v) {
		this.m_mesh = v;
		return v;
	}
	,CheckCulling: function() {
		if(this.m_mesh == null) return false;
		var c = haxor.component.Camera.current;
		var b = this.m_mesh.get_bounds();
		var p = haxor.math.Vector3.get_temp();
		var ic;
		if(this.m_culled.h.__keys__[c.__id__] != null) ic = this.m_culled.h[c.__id__]; else ic = true;
		var wm = this.get_transform().m_worldMatrix;
		var p0;
		var p1;
		var p2;
		var p3;
		var p4;
		var p5;
		var p6;
		var p7;
		p.x = b.get_xMin();
		p.y = b.get_yMin();
		p.z = b.get_zMin();
		wm.Transform3x4(p);
		p0 = c.WorldToProjection(p);
		p.x = b.get_xMax();
		p.y = b.get_yMin();
		p.z = b.get_zMin();
		wm.Transform3x4(p);
		p1 = c.WorldToProjection(p);
		p.x = b.get_xMin();
		p.y = b.get_yMax();
		p.z = b.get_zMin();
		wm.Transform3x4(p);
		p2 = c.WorldToProjection(p);
		p.x = b.get_xMax();
		p.y = b.get_yMax();
		p.z = b.get_zMin();
		wm.Transform3x4(p);
		p3 = c.WorldToProjection(p);
		p.x = b.get_xMin();
		p.y = b.get_yMin();
		p.z = b.get_zMax();
		wm.Transform3x4(p);
		p4 = c.WorldToProjection(p);
		p.x = b.get_xMax();
		p.y = b.get_yMin();
		p.z = b.get_zMax();
		wm.Transform3x4(p);
		p5 = c.WorldToProjection(p);
		p.x = b.get_xMin();
		p.y = b.get_yMax();
		p.z = b.get_zMax();
		wm.Transform3x4(p);
		p6 = c.WorldToProjection(p);
		p.x = b.get_xMax();
		p.y = b.get_yMax();
		p.z = b.get_zMax();
		wm.Transform3x4(p);
		p7 = c.WorldToProjection(p);
		var iw0 = 1.0 / haxor.math.Mathf.Abs(p0.w);
		var iw1 = 1.0 / haxor.math.Mathf.Abs(p1.w);
		var iw2 = 1.0 / haxor.math.Mathf.Abs(p2.w);
		var iw3 = 1.0 / haxor.math.Mathf.Abs(p3.w);
		var iw4 = 1.0 / haxor.math.Mathf.Abs(p4.w);
		var iw5 = 1.0 / haxor.math.Mathf.Abs(p5.w);
		var iw6 = 1.0 / haxor.math.Mathf.Abs(p6.w);
		var iw7 = 1.0 / haxor.math.Mathf.Abs(p7.w);
		var v;
		v = haxor.math.Mathf.Max([p0.z * iw0,p1.z * iw1,p2.z * iw2,p3.z * iw3,p4.z * iw4,p5.z * iw5,p6.z * iw6,p7.z * iw7]);
		if(v < -1.0) return this.visible = false;
		v = haxor.math.Mathf.Min([p0.x * iw0,p1.x * iw1,p2.x * iw2,p3.x * iw3,p4.x * iw4,p5.x * iw5,p6.x * iw6,p7.x * iw7]);
		if(v > 1.0) return this.visible = false;
		v = haxor.math.Mathf.Max([p0.x * iw0,p1.x * iw1,p2.x * iw2,p3.x * iw3,p4.x * iw4,p5.x * iw5,p6.x * iw6,p7.x * iw7]);
		if(v < -1.0) return this.visible = false;
		v = haxor.math.Mathf.Min([p0.y * iw0,p1.y * iw1,p2.y * iw2,p3.y * iw3,p4.y * iw4,p5.y * iw5,p6.y * iw6,p7.y * iw7]);
		if(v > 1.0) return this.visible = false;
		v = haxor.math.Mathf.Max([p0.y * iw0,p1.y * iw1,p2.y * iw2,p3.y * iw3,p4.y * iw4,p5.y * iw5,p6.y * iw6,p7.y * iw7]);
		if(v < -1.0) return this.visible = false;
		v = haxor.math.Mathf.Min([p0.z * iw0,p1.z * iw1,p2.z * iw2,p3.z * iw3,p4.z * iw4,p5.z * iw5,p6.z * iw6,p7.z * iw7]);
		if(v > 1.0) return this.visible = false;
		return this.visible = true;
		if(!ic) this.CallOnInvisible();
		this.visible = false;
		return false;
	}
	,CallOnVisible: function() {
		var c = haxor.component.Camera.current;
		this.m_culled.set(c,false);
	}
	,CallOnInvisible: function() {
		var c = haxor.component.Camera.current;
		this.m_culled.set(c,true);
	}
	,CanBeCulled: function(p_a,p_b) {
		var a;
		var b;
		var iwa;
		if(p_a.w <= 0.0) iwa = -100.0; else iwa = 1.0 / p_a.w;
		var iwb;
		if(p_b.w <= 0.0) iwb = -100.0; else iwb = 1.0 / p_b.w;
		var va;
		var vb;
		va = p_a.x * iwa;
		vb = p_b.x * iwb;
		a = haxor.math.Mathf.Min([va,vb]);
		b = haxor.math.Mathf.Max([va,vb]);
		if(b < -1) return true;
		if(a > 1) return true;
		va = p_a.y * iwa;
		vb = p_b.y * iwb;
		a = haxor.math.Mathf.Min([va,vb]);
		b = haxor.math.Mathf.Max([va,vb]);
		if(b < -1) return true;
		if(a > 1) return true;
		va = p_a.z * iwa;
		vb = p_b.z * iwb;
		a = haxor.math.Mathf.Min([va,vb]);
		b = haxor.math.Mathf.Max([va,vb]);
		if(b < -1) return true;
		if(a > 1) return true;
		return false;
	}
	,OnRender: function() {
		var m = this.get_mesh();
		if(m == null) return;
		haxor.graphics.Graphics.Render(haxor.component.Camera.current,this.get_entity().get_transform(),this.get_mesh(),this.material);
	}
	,__class__: haxor.component.MeshRenderer
	,__properties__: $extend(haxor.component.Renderer.prototype.__properties__,{set_mesh:"set_mesh",get_mesh:"get_mesh"})
});
haxor.component.ParticleAttribute = function(p_start,p_end,p_curve,p_random) {
	if(p_random == null) p_random = false;
	if(p_curve == null) p_curve = 1.0;
	this.start = p_start;
	this.end = p_end;
	this.curve = p_curve;
	this.random = p_random;
};
$hxClasses["haxor.component.ParticleAttribute"] = haxor.component.ParticleAttribute;
haxor.component.ParticleAttribute.__name__ = ["haxor","component","ParticleAttribute"];
haxor.component.ParticleAttribute.prototype = {
	__class__: haxor.component.ParticleAttribute
};
haxor.component.ParticleStart = function() {
	this.life = new haxor.component.ParticleAttribute(1.0,1.0);
	this.speed = new haxor.component.ParticleAttribute(1.0,1.0);
	this.size = new haxor.component.ParticleAttribute(haxor.math.Vector3.get_one(),haxor.math.Vector3.get_one());
	this.rotation = new haxor.component.ParticleAttribute(haxor.math.Vector3.get_zero(),haxor.math.Vector3.get_zero());
	this.color = haxor.texture.Texture2D.get_white();
};
$hxClasses["haxor.component.ParticleStart"] = haxor.component.ParticleStart;
haxor.component.ParticleStart.__name__ = ["haxor","component","ParticleStart"];
haxor.component.ParticleStart.prototype = {
	__class__: haxor.component.ParticleStart
};
haxor.component.ParticleLife = function() {
	this.speed = new haxor.component.ParticleAttribute(1.0,1.0);
	this.motion = new haxor.component.ParticleAttribute(haxor.math.Vector3.get_one(),haxor.math.Vector3.get_one());
	this.size = new haxor.component.ParticleAttribute(haxor.math.Vector3.get_one(),haxor.math.Vector3.get_one());
	this.rotation = new haxor.component.ParticleAttribute(haxor.math.Vector3.get_zero(),haxor.math.Vector3.get_zero());
	this.color = haxor.texture.Texture2D.get_white();
};
$hxClasses["haxor.component.ParticleLife"] = haxor.component.ParticleLife;
haxor.component.ParticleLife.__name__ = ["haxor","component","ParticleLife"];
haxor.component.ParticleLife.prototype = {
	__class__: haxor.component.ParticleLife
};
haxor.component.ParticleSheet = function() {
	this.width = 0.0;
	this.height = 0.0;
	this.length = 0;
	this.fps = 60.0;
	this.frame = new haxor.component.ParticleAttribute(0.0,0.0);
	this.wrap = haxor.component.AnimationWrap.Clamp;
	this.reverse = false;
};
$hxClasses["haxor.component.ParticleSheet"] = haxor.component.ParticleSheet;
haxor.component.ParticleSheet.__name__ = ["haxor","component","ParticleSheet"];
haxor.component.ParticleSheet.prototype = {
	__class__: haxor.component.ParticleSheet
};
haxor.component.ParticleSystemState = { __ename__ : true, __constructs__ : ["None","Reset","Update"] };
haxor.component.ParticleSystemState.None = ["None",0];
haxor.component.ParticleSystemState.None.__enum__ = haxor.component.ParticleSystemState;
haxor.component.ParticleSystemState.Reset = ["Reset",1];
haxor.component.ParticleSystemState.Reset.__enum__ = haxor.component.ParticleSystemState;
haxor.component.ParticleSystemState.Update = ["Update",2];
haxor.component.ParticleSystemState.Update.__enum__ = haxor.component.ParticleSystemState;
haxor.component.ParticleRenderer = function(p_entity) {
	this.m_particles = new haxor.graphics.Mesh3();
	this.m_particles.set_name("ParticleMesh" + this.get_id());
	this.m_mesh = this.m_particles;
	this.m_mesh.set_bounds(haxor.math.AABB3.FromCenter(0,0,0,1,1,1));
	this.m_state = haxor.component.ParticleSystemState.Reset;
	this.m_kernel = new haxor.thread.ParticleKernel(this);
	this.elapsed = 0.0;
	this.m_playing = false;
	this.m_emitted_count = 0.0;
	this.m_emitted_start = 0.0;
	this.set_count(10);
	this.duration = 1.0;
	this.emitter = new haxor.component.SphereEmitter(1.0);
	this.sheet = new haxor.component.ParticleSheet();
	this.local = true;
	this.loop = true;
	this.billboard = true;
	this.start = new haxor.component.ParticleStart();
	this.life = new haxor.component.ParticleLife();
	this.rate = new haxor.component.ParticleAttribute(1.0,1.0);
	this.force = new haxor.math.Vector3();
	haxor.component.MeshRenderer.call(this,p_entity);
};
$hxClasses["haxor.component.ParticleRenderer"] = haxor.component.ParticleRenderer;
haxor.component.ParticleRenderer.__name__ = ["haxor","component","ParticleRenderer"];
haxor.component.ParticleRenderer.__interfaces__ = [haxor.core.IUpdateable];
haxor.component.ParticleRenderer.__super__ = haxor.component.MeshRenderer;
haxor.component.ParticleRenderer.prototype = $extend(haxor.component.MeshRenderer.prototype,{
	get_emitted: function() {
		return this.m_emitted_count;
	}
	,get_playing: function() {
		return this.m_playing;
	}
	,get_bounds: function() {
		return this.m_mesh.get_bounds();
	}
	,set_bounds: function(v) {
		this.m_mesh.set_bounds(v);
		return v;
	}
	,get_count: function() {
		return this.m_count;
	}
	,set_count: function(v) {
		this.m_count = v;
		this.Reset();
		this.UpdateMesh();
		return v;
	}
	,Emit: function(p_emit_count) {
		if(p_emit_count == null) p_emit_count = 1.0;
		var remain = this.get_count() - this.get_emitted();
		var c = haxor.math.Mathf.Min([p_emit_count,remain]);
		var d = p_emit_count - c;
		if(this.loop) this.m_emitted_start += d;
		this.m_emitted_count += c;
		this.m_playing = true;
	}
	,Play: function() {
		this.m_playing = true;
	}
	,Pause: function() {
		this.m_playing = false;
	}
	,Reset: function() {
		this.elapsed = 0.0;
		this.m_emitted_count = 0.0;
		this.m_emitted_start = 0.0;
	}
	,Stop: function() {
		this.elapsed = 0.0;
		this.m_emitted_count = 0.0;
		this.m_emitted_start = 0.0;
		this.m_state = haxor.component.ParticleSystemState.Reset;
		this.m_playing = false;
	}
	,Simulate: function() {
		var _g = this.m_state;
		switch(_g[1]) {
		case 0:
			if(this.m_playing) this.m_state = haxor.component.ParticleSystemState.Update;
			break;
		case 1:
			this.m_kernel.Execute();
			if(this.m_playing) this.m_state = haxor.component.ParticleSystemState.Update; else this.m_state = haxor.component.ParticleSystemState.None;
			break;
		case 2:
			if(!this.m_playing) {
				this.m_state = haxor.component.ParticleSystemState.None;
				return;
			}
			this.m_kernel.Execute();
			var max_life = haxor.math.Mathf.Max([this.start.life.start,this.start.life.end]);
			if(this.elapsed >= this.duration + max_life) {
				if(!this.loop) return;
			}
			var dt = haxor.core.Time.get_deltaTime();
			var r = haxor.math.Mathf.Clamp01(this.elapsed / this.duration);
			this.elapsed += dt;
			if(this.elapsed >= this.duration + max_life) this.elapsed = this.duration + max_life;
			var er = dt * haxor.math.Mathf.Lerp(this.rate.start,this.rate.end,this.rate.random?Math.random():haxor.math.Mathf.Pow(r,this.rate.curve));
			this.Emit(er);
			break;
		}
	}
	,OnUpdate: function() {
		this.Simulate();
	}
	,OnRender: function() {
		haxor.component.MeshRenderer.prototype.OnRender.call(this);
	}
	,UpdateMesh: function() {
		this.m_particles.Clear();
		var vl = [];
		var cl = [];
		var plane = [new haxor.math.Vector3(-0.5,0.5,0),new haxor.math.Vector3(-0.5,-0.5,0),new haxor.math.Vector3(0.5,-0.5,0),new haxor.math.Vector3(-0.5,0.5,0),new haxor.math.Vector3(0.5,-0.5,0),new haxor.math.Vector3(0.5,0.5,0)];
		var wc = haxor.math.Color.get_white();
		var _g1 = 0;
		var _g = this.get_count();
		while(_g1 < _g) {
			var i = _g1++;
			var _g3 = 0;
			var _g2 = plane.length;
			while(_g3 < _g2) {
				var j = _g3++;
				var v = plane[j].get_clone();
				v.z = i;
				vl.push(v);
				cl.push(wc);
			}
		}
		this.m_particles.set_vertex(vl);
		this.m_particles.set_color(cl);
	}
	,__class__: haxor.component.ParticleRenderer
	,__properties__: $extend(haxor.component.MeshRenderer.prototype.__properties__,{set_count:"set_count",get_count:"get_count",set_bounds:"set_bounds",get_bounds:"get_bounds",get_playing:"get_playing",get_emitted:"get_emitted"})
});
haxor.component.ParticleEmitter = function() {
	this.m_data = new Float32Array(7);
	this.set_surface(false);
	this.set_random(false);
	this.ranges = [-1000,1000,-1000,1000,-1000,1000];
};
$hxClasses["haxor.component.ParticleEmitter"] = haxor.component.ParticleEmitter;
haxor.component.ParticleEmitter.__name__ = ["haxor","component","ParticleEmitter"];
haxor.component.ParticleEmitter.prototype = {
	get_surface: function() {
		return this.m_data[1] > 0.0;
	}
	,set_surface: function(v) {
		if(v) this.m_data[1] = 1.0; else this.m_data[1] = 0.0;
		return v;
	}
	,get_random: function() {
		return this.m_data[2] > 0.0;
	}
	,set_random: function(v) {
		if(v) this.m_data[2] = 1.0; else this.m_data[2] = 0.0;
		return v;
	}
	,__class__: haxor.component.ParticleEmitter
	,__properties__: {set_random:"set_random",get_random:"get_random",set_surface:"set_surface",get_surface:"get_surface"}
};
haxor.component.SphereEmitter = function(p_radius) {
	if(p_radius == null) p_radius = 1.0;
	haxor.component.ParticleEmitter.call(this);
	this.m_data[0] = 0.0;
	this.set_radius(p_radius);
};
$hxClasses["haxor.component.SphereEmitter"] = haxor.component.SphereEmitter;
haxor.component.SphereEmitter.__name__ = ["haxor","component","SphereEmitter"];
haxor.component.SphereEmitter.__super__ = haxor.component.ParticleEmitter;
haxor.component.SphereEmitter.prototype = $extend(haxor.component.ParticleEmitter.prototype,{
	get_radius: function() {
		return this.m_data[3];
	}
	,set_radius: function(v) {
		this.m_data[3] = v;
		return v;
	}
	,__class__: haxor.component.SphereEmitter
	,__properties__: $extend(haxor.component.ParticleEmitter.prototype.__properties__,{set_radius:"set_radius",get_radius:"get_radius"})
});
haxor.component.BoxEmitter = function(p_width,p_height,p_depth) {
	if(p_depth == null) p_depth = 1.0;
	if(p_height == null) p_height = 1.0;
	if(p_width == null) p_width = 1.0;
	haxor.component.ParticleEmitter.call(this);
	this.m_data[0] = 1.0;
	this.set_width(p_width);
	this.set_height(p_height);
	this.set_depth(p_depth);
};
$hxClasses["haxor.component.BoxEmitter"] = haxor.component.BoxEmitter;
haxor.component.BoxEmitter.__name__ = ["haxor","component","BoxEmitter"];
haxor.component.BoxEmitter.__super__ = haxor.component.ParticleEmitter;
haxor.component.BoxEmitter.prototype = $extend(haxor.component.ParticleEmitter.prototype,{
	get_width: function() {
		return this.m_data[3];
	}
	,set_width: function(v) {
		this.m_data[3] = v;
		return v;
	}
	,get_height: function() {
		return this.m_data[4];
	}
	,set_height: function(v) {
		this.m_data[4] = v;
		return v;
	}
	,get_depth: function() {
		return this.m_data[5];
	}
	,set_depth: function(v) {
		this.m_data[5] = v;
		return v;
	}
	,__class__: haxor.component.BoxEmitter
	,__properties__: $extend(haxor.component.ParticleEmitter.prototype.__properties__,{set_depth:"set_depth",get_depth:"get_depth",set_height:"set_height",get_height:"get_height",set_width:"set_width",get_width:"get_width"})
});
haxor.component.ConeEmitter = function(p_angle,p_height) {
	if(p_height == null) p_height = 1.0;
	if(p_angle == null) p_angle = 45.0;
	haxor.component.ParticleEmitter.call(this);
	this.m_data[0] = 2.0;
	this.set_angle(p_angle);
	this.set_height(p_height);
};
$hxClasses["haxor.component.ConeEmitter"] = haxor.component.ConeEmitter;
haxor.component.ConeEmitter.__name__ = ["haxor","component","ConeEmitter"];
haxor.component.ConeEmitter.__super__ = haxor.component.ParticleEmitter;
haxor.component.ConeEmitter.prototype = $extend(haxor.component.ParticleEmitter.prototype,{
	get_angle: function() {
		return this.m_data[3];
	}
	,set_angle: function(v) {
		this.m_data[3] = v;
		return v;
	}
	,get_height: function() {
		return this.m_data[4];
	}
	,set_height: function(v) {
		this.m_data[4] = v;
		return v;
	}
	,__class__: haxor.component.ConeEmitter
	,__properties__: $extend(haxor.component.ParticleEmitter.prototype.__properties__,{set_height:"set_height",get_height:"get_height",set_angle:"set_angle",get_angle:"get_angle"})
});
haxor.component.CylinderEmitter = function(p_radius,p_height) {
	if(p_height == null) p_height = 1.0;
	if(p_radius == null) p_radius = 1.0;
	haxor.component.ParticleEmitter.call(this);
	this.m_data[0] = 3.0;
	this.set_radius(p_radius);
	this.set_height(p_height);
};
$hxClasses["haxor.component.CylinderEmitter"] = haxor.component.CylinderEmitter;
haxor.component.CylinderEmitter.__name__ = ["haxor","component","CylinderEmitter"];
haxor.component.CylinderEmitter.__super__ = haxor.component.ParticleEmitter;
haxor.component.CylinderEmitter.prototype = $extend(haxor.component.ParticleEmitter.prototype,{
	get_radius: function() {
		return this.m_data[3];
	}
	,set_radius: function(v) {
		this.m_data[3] = v;
		return v;
	}
	,get_height: function() {
		return this.m_data[4];
	}
	,set_height: function(v) {
		this.m_data[4] = v;
		return v;
	}
	,__class__: haxor.component.CylinderEmitter
	,__properties__: $extend(haxor.component.ParticleEmitter.prototype.__properties__,{set_height:"set_height",get_height:"get_height",set_radius:"set_radius",get_radius:"get_radius"})
});
haxor.component.PointLight = function(p_entity) {
	haxor.component.Light.call(this,p_entity);
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
haxor.component.ForceMode = { __ename__ : true, __constructs__ : ["Acceleration","Force","Impulse","Velocity"] };
haxor.component.ForceMode.Acceleration = ["Acceleration",0];
haxor.component.ForceMode.Acceleration.__enum__ = haxor.component.ForceMode;
haxor.component.ForceMode.Force = ["Force",1];
haxor.component.ForceMode.Force.__enum__ = haxor.component.ForceMode;
haxor.component.ForceMode.Impulse = ["Impulse",2];
haxor.component.ForceMode.Impulse.__enum__ = haxor.component.ForceMode;
haxor.component.ForceMode.Velocity = ["Velocity",3];
haxor.component.ForceMode.Velocity.__enum__ = haxor.component.ForceMode;
haxor.component.RigidBody = function(p_entity) {
	haxor.component.Behaviour.call(this,p_entity);
	haxor.component.RigidBody.list.push(this);
	this.m_velocity = haxor.math.Vector3.get_zero();
	this.m_dragForce = haxor.math.Vector3.get_zero();
	this.m_direction = haxor.math.Vector3.get_zero();
	this.m_speed = 0.0;
	this.m_avq = new haxor.math.Quaternion();
	this.m_angularVelocity = haxor.math.Vector3.get_zero();
	this.m_dragTorque = haxor.math.Vector3.get_zero();
	this.m_angularDirection = haxor.math.Vector3.get_zero();
	this.m_angularSpeed = 0.0;
	this.m_accel = haxor.math.Vector3.get_zero();
	this.m_torque = haxor.math.Vector3.get_zero();
	this.m_hasForce = false;
	this.m_hasTorque = false;
	this.kinematic = false;
	this.set_mass(1.0);
	this.set_drag(0.0);
	this.set_angularDrag(0.0);
	this.gravity = true;
	this.centerOfMass = haxor.math.Vector3.get_zero();
	var cl = p_entity.GetComponents(haxor.physics.Collider);
	var _g1 = 0;
	var _g = cl.length;
	while(_g1 < _g) {
		var i = _g1++;
		var c = cl[i];
		c.m_rigidbody = this;
	}
};
$hxClasses["haxor.component.RigidBody"] = haxor.component.RigidBody;
haxor.component.RigidBody.__name__ = ["haxor","component","RigidBody"];
haxor.component.RigidBody.Initialize = function() {
	haxor.component.RigidBody.list = [];
};
haxor.component.RigidBody.__super__ = haxor.component.Behaviour;
haxor.component.RigidBody.prototype = $extend(haxor.component.Behaviour.prototype,{
	get_velocity: function() {
		return haxor.math.Vector3.get_temp().Set(this.m_velocity.x,this.m_velocity.y,this.m_velocity.z);
	}
	,set_velocity: function(v) {
		this.m_speed = v.get_length();
		var ispd;
		if(this.m_speed <= 0.0) ispd = 0.0; else ispd = 1.0 / this.m_speed;
		this.m_velocity.x = this.m_direction.x = v.x;
		this.m_velocity.y = this.m_direction.y = v.y;
		this.m_velocity.z = this.m_direction.z = v.z;
		this.m_direction.x *= ispd;
		this.m_direction.y *= ispd;
		this.m_direction.z *= ispd;
		return v;
	}
	,get_angularVelocity: function() {
		return haxor.math.Vector3.get_temp().Set(this.m_angularVelocity.x,this.m_angularVelocity.y,this.m_angularVelocity.z);
	}
	,set_angularVelocity: function(v) {
		this.m_angularSpeed = v.get_length();
		var ispd;
		if(this.m_angularSpeed <= 0.0) ispd = 0.0; else ispd = 1.0 / this.m_angularSpeed;
		this.m_angularVelocity.x = this.m_angularDirection.x = v.x;
		this.m_angularVelocity.y = this.m_angularDirection.y = v.y;
		this.m_angularVelocity.z = this.m_angularDirection.z = v.z;
		this.m_angularDirection.x *= ispd;
		this.m_angularDirection.y *= ispd;
		this.m_angularDirection.z *= ispd;
		return v;
	}
	,get_drag: function() {
		return this.m_drag;
	}
	,set_drag: function(v) {
		this.m_drag = Math.max(0,v);
		return this.m_drag;
	}
	,get_angularDrag: function() {
		return this.m_angularDrag;
	}
	,set_angularDrag: function(v) {
		this.m_angularDrag = Math.max(0,v);
		return this.m_angularDrag;
	}
	,get_mass: function() {
		return this.m_mass;
	}
	,set_mass: function(v) {
		this.m_mass = Math.max(0,v);
		if(this.m_mass <= 0.0) this.m_imass = 0.0; else this.m_imass = 1.0 / this.m_mass;
		return this.m_mass;
	}
	,AddTorque: function(p_torque,p_mode) {
		var m;
		if(p_mode == null) m = haxor.component.ForceMode.Force; else m = p_mode;
		var mdt = 1.0;
		var dt = 1.0;
		var v;
		if(p_mode == haxor.component.ForceMode.Velocity) v = this.get_angularVelocity(); else v = this.m_torque;
		switch(m[1]) {
		case 3:
			break;
		case 1:
			mdt = this.m_imass;
			break;
		case 0:
			break;
		case 2:
			mdt = this.m_imass;
			break;
		}
		v.x += p_torque.x * mdt;
		v.y += p_torque.y * mdt;
		v.z += p_torque.z * mdt;
		this.m_hasTorque = p_mode != haxor.component.ForceMode.Velocity;
	}
	,AddForce: function(p_force,p_mode) {
		var m;
		if(p_mode == null) m = haxor.component.ForceMode.Force; else m = p_mode;
		var mdt = 1.0;
		var dt = haxor.core.Time.get_fixedDeltaTime();
		var v;
		if(p_mode == haxor.component.ForceMode.Velocity) v = this.get_velocity(); else v = this.m_accel;
		switch(m[1]) {
		case 3:
			mdt = dt;
			break;
		case 1:
			mdt = this.m_imass * dt * dt;
			break;
		case 0:
			mdt = dt * dt;
			break;
		case 2:
			mdt = this.m_imass * dt;
			break;
		}
		v.x += p_force.x * mdt;
		v.y += p_force.y * mdt;
		v.z += p_force.z * mdt;
		if(p_mode == haxor.component.ForceMode.Velocity) this.set_velocity(v);
		this.m_hasForce = p_mode != haxor.component.ForceMode.Velocity;
	}
	,OnDestroy: function() {
		var cl = this.get_entity().GetComponents(haxor.physics.Collider);
		var _g1 = 0;
		var _g = cl.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = cl[i];
			c.m_rigidbody = null;
		}
	}
	,ComputeForces: function() {
		if(this.gravity) this.AddForce(haxor.physics.Physics.gravity,haxor.component.ForceMode.Velocity);
		if(this.get_drag() > 0.0) {
			if(this.m_speed > 0.0) {
				this.m_dragForce.x = -this.m_velocity.x * this.get_drag();
				this.m_dragForce.y = -this.m_velocity.y * this.get_drag();
				this.m_dragForce.z = -this.m_velocity.z * this.get_drag();
				if(Math.abs(this.m_dragForce.x) >= haxor.math.Mathf.Epsilon) {
					this.m_accel.x += this.m_dragForce.x;
					this.m_hasForce = true;
				}
				if(Math.abs(this.m_dragForce.y) >= haxor.math.Mathf.Epsilon) {
					this.m_accel.y += this.m_dragForce.y;
					this.m_hasForce = true;
				}
				if(Math.abs(this.m_dragForce.z) >= haxor.math.Mathf.Epsilon) {
					this.m_accel.z += this.m_dragForce.z;
					this.m_hasForce = true;
				}
			}
		}
		if(this.get_angularDrag() > 0.0) {
			if(this.m_angularSpeed > 0.0) {
				this.m_dragTorque.x = -this.m_angularVelocity.x * this.get_angularDrag();
				this.m_dragTorque.y = -this.m_angularVelocity.y * this.get_angularDrag();
				this.m_dragTorque.z = -this.m_angularVelocity.z * this.get_angularDrag();
				if(Math.abs(this.m_dragTorque.x) >= haxor.math.Mathf.Epsilon) {
					this.m_torque.x += this.m_dragTorque.x;
					this.m_hasTorque = true;
				}
				if(Math.abs(this.m_dragTorque.y) >= haxor.math.Mathf.Epsilon) {
					this.m_torque.y += this.m_dragTorque.y;
					this.m_hasTorque = true;
				}
				if(Math.abs(this.m_dragTorque.z) >= haxor.math.Mathf.Epsilon) {
					this.m_torque.z += this.m_dragTorque.z;
					this.m_hasTorque = true;
				}
			}
		}
	}
	,IntegrateVelocity: function(p_dt) {
		if(this.kinematic) return;
		var dt = p_dt;
		if(this.m_hasForce) {
			var v = this.get_velocity();
			v.x += this.m_accel.x * dt;
			v.y += this.m_accel.y * dt;
			v.z += this.m_accel.z * dt;
			this.set_velocity(v);
		}
		if(!this.m_hasForce) {
			if(this.m_speed <= 0.14) {
			}
		}
		if(this.m_hasTorque) {
			var v1 = this.get_angularVelocity();
			v1.x += this.m_torque.x * dt;
			v1.y += this.m_torque.y * dt;
			v1.z += this.m_torque.z * dt;
			this.set_angularVelocity(v1);
		}
		if(!this.m_hasTorque) {
			if(this.m_angularSpeed <= 0.14 * haxor.math.Mathf.Deg2Rad) {
			}
		}
	}
	,IntegratePosition: function(p_dt) {
		var integrate_position = true;
		var dt = p_dt;
		if(Math.abs(this.m_velocity.x) < haxor.math.Mathf.Epsilon) {
			if(Math.abs(this.m_velocity.y) < haxor.math.Mathf.Epsilon) {
				if(Math.abs(this.m_velocity.z) < haxor.math.Mathf.Epsilon) integrate_position = false;
			}
		}
		if(integrate_position) {
			var p = this.get_transform().get_position();
			p.x += this.m_velocity.x * dt;
			p.y += this.m_velocity.y * dt;
			p.z += this.m_velocity.z * dt;
			this.get_transform().set_position(p);
		}
		var integrate_rotation = false;
		if(Math.abs(this.m_angularVelocity.x) < haxor.math.Mathf.Epsilon) {
			if(Math.abs(this.m_angularVelocity.y) < haxor.math.Mathf.Epsilon) {
				if(Math.abs(this.m_angularVelocity.z) < haxor.math.Mathf.Epsilon) integrate_rotation = false;
			}
		}
		if(integrate_rotation) {
			var r = this.get_transform().get_rotation();
			this.m_avq.Set(this.m_angularVelocity.x,this.m_angularVelocity.y,this.m_angularVelocity.z,0.0);
			this.m_avq.Multiply(r,false);
			this.m_avq.Scale(0.25);
			r.x += this.m_avq.x * dt;
			r.y += this.m_avq.y * dt;
			r.z += this.m_avq.z * dt;
			r.w += this.m_avq.w * dt;
			r.Normalize();
			this.get_transform().set_rotation(r);
		}
	}
	,ResetForces: function() {
		this.m_accel.x = 0;
		this.m_accel.y = 0;
		this.m_accel.z = 0;
		this.m_hasForce = false;
		this.m_torque.x = 0;
		this.m_torque.y = 0;
		this.m_torque.z = 0;
		this.m_hasTorque = false;
	}
	,__class__: haxor.component.RigidBody
	,__properties__: $extend(haxor.component.Behaviour.prototype.__properties__,{set_mass:"set_mass",get_mass:"get_mass",set_angularDrag:"set_angularDrag",get_angularDrag:"get_angularDrag",set_drag:"set_drag",get_drag:"get_drag",set_angularVelocity:"set_angularVelocity",get_angularVelocity:"get_angularVelocity",set_velocity:"set_velocity",get_velocity:"get_velocity"})
});
haxor.component.SkinnedMeshRenderer = function(p_entity) {
	this.m_joints = [];
	this.m_buffer = new Float32Array(8192);
	this.m_sampler = new haxor.texture.KernelTexture(1,2048,haxor.texture.TextureFormat.Float4);
	this.m_sampler.set_name("SkinningTexture" + this.get_id());
	haxor.component.MeshRenderer.call(this,p_entity);
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
		if(this.material != null) {
			var skm = this.get_mesh();
			var k = 0;
			var jm;
			var bm;
			var _g1 = 0;
			var _g = this.m_joints.length;
			while(_g1 < _g) {
				var i = _g1++;
				jm = this.m_joints[i].m_worldMatrix;
				bm = skm.get_binds()[i];
				var _g2 = 0;
				while(_g2 < 12) {
					var j = _g2++;
					this.m_buffer[k] = jm.GetIndex(j);
					this.m_buffer[k + 4096] = bm.GetIndex(j);
					k++;
				}
			}
			this.m_sampler.WriteRange(this.m_buffer);
			this.material.SetUniform("Skinning",this.m_sampler);
		}
		haxor.component.MeshRenderer.prototype.OnRender.call(this);
	}
	,__class__: haxor.component.SkinnedMeshRenderer
	,__properties__: $extend(haxor.component.MeshRenderer.prototype.__properties__,{set_joints:"set_joints",get_joints:"get_joints"})
});
haxor.component.Transform = function(p_entity) {
	haxor.component.Component.call(this,p_entity);
	if(haxor.component.Transform.m_list == null) haxor.component.Transform.m_list = [];
	if(haxor.component.Transform.m_indexes == null) haxor.component.Transform.m_indexes = [];
	this.m_position = haxor.math.Vector3.get_zero();
	this.m_rotation = haxor.math.Quaternion.get_identity();
	this.m_scale = haxor.math.Vector3.get_one();
	this.m_localMatrix = haxor.math.Matrix4.get_identity();
	this.m_worldMatrixInverse = haxor.math.Matrix4.get_identity();
	this.m_worldMatrix = haxor.math.Matrix4.get_identity();
	this.m_tm0 = haxor.math.Matrix4.get_identity();
	this.m_tm1 = haxor.math.Matrix4.get_identity();
	var tid;
	if(haxor.component.Transform.m_indexes.length > 0) tid = haxor.component.Transform.m_indexes.shift(); else tid = haxor.component.Transform.m_list.length;
	this.m_tid = tid;
	if(tid >= haxor.component.Transform.m_list.length) haxor.component.Transform.m_list.push(this); else haxor.component.Transform.m_list[tid] = this;
	this.m_depth = 0;
	this.m_hierarchy = new Array();
	this.m_dirty = true;
	this.m_concat = true;
	if(haxor.component.Transform.m_root != null) this.set_parent(null);
	if(haxor.component.Transform.m_threaded) haxor.component.Transform.m_kernel.Init(this);
};
$hxClasses["haxor.component.Transform"] = haxor.component.Transform;
haxor.component.Transform.__name__ = ["haxor","component","Transform"];
haxor.component.Transform.__properties__ = {get_root:"get_root"}
haxor.component.Transform.get_root = function() {
	return haxor.component.Transform.m_root;
};
haxor.component.Transform.Initialize = function() {
	haxor.component.Transform.m_threaded = haxor.api.TextureAPI.TEXTURE_FLOAT;
	if(window.navigator.userAgent.toLowerCase().indexOf("chrome") < 0) haxor.component.Transform.m_threaded = false;
	if(window.navigator.userAgent.toLowerCase().indexOf("android") >= 0) haxor.component.Transform.m_threaded = false;
	if(window.navigator.userAgent.toLowerCase().indexOf("iphone") >= 0) haxor.component.Transform.m_threaded = false;
	if(window.navigator.userAgent.toLowerCase().indexOf("ipad") >= 0) haxor.component.Transform.m_threaded = false;
	haxor.component.Transform.m_threaded = false;
	if(haxor.component.Transform.m_threaded) {
		haxor.component.Transform.m_kernel = new haxor.thread.TransformKernel();
		haxor.component.Transform.m_kernel.Init(haxor.component.Transform.m_root);
		haxor.component.Transform.m_sync_iterator = 0;
		haxor.component.Transform.m_boot = 8;
	}
	console.log("Haxor> Transform Initialize Threaded[" + Std.string(haxor.component.Transform.m_threaded) + "]");
};
haxor.component.Transform.Update = function(p_sync) {
	if(haxor.component.Transform.m_threaded) {
		if(haxor.component.Transform.m_boot > 0) {
			haxor.component.Transform.get_root().Concat();
			haxor.component.Transform.m_boot--;
		}
		if(p_sync) {
			var _g1 = 0;
			var _g = haxor.component.Transform.m_list.length;
			while(_g1 < _g) {
				var i = _g1++;
				haxor.component.Transform.m_list[haxor.component.Transform.m_sync_iterator].KernelSync();
				haxor.component.Transform.m_sync_iterator = (haxor.component.Transform.m_sync_iterator + 1) % haxor.component.Transform.m_list.length;
			}
		} else haxor.component.Transform.m_kernel.Execute();
	}
};
haxor.component.Transform.__super__ = haxor.component.Component;
haxor.component.Transform.prototype = $extend(haxor.component.Component.prototype,{
	get_right: function() {
		var wm = this.m_worldMatrix;
		return haxor.math.Vector3.get_temp().Set(wm.m00,wm.m10,wm.m20);
	}
	,set_right: function(v) {
		return v;
	}
	,get_up: function() {
		var wm = this.m_worldMatrix;
		return haxor.math.Vector3.get_temp().Set(wm.m01,wm.m11,wm.m21);
	}
	,set_up: function(v) {
		return v;
	}
	,get_forward: function() {
		var wm = this.m_worldMatrix;
		return haxor.math.Vector3.get_temp().Set(wm.m02,wm.m12,wm.m22);
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
		if(haxor.component.Transform.m_threaded) {
			haxor.component.Transform.m_kernel.SetParent(this);
			haxor.component.Transform.m_kernel.SetConcat(this,true);
		}
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
		return haxor.math.Vector3.get_temp().Set(this.m_position.x,this.m_position.y,this.m_position.z);
	}
	,set_position: function(v) {
		var tx = this.m_position.x;
		if(Math.abs(tx - v.x) < haxor.math.Mathf.Epsilon) {
			var ty = this.m_position.y;
			if(Math.abs(ty - v.y) < haxor.math.Mathf.Epsilon) {
				var tz = this.m_position.z;
				if(Math.abs(tz - v.z) < haxor.math.Mathf.Epsilon) return v;
			}
		}
		this.m_position.x = v.x;
		this.m_position.y = v.y;
		this.m_position.z = v.z;
		if(haxor.component.Transform.m_threaded) {
			haxor.component.Transform.m_kernel.SetPosition(this);
			haxor.component.Transform.m_kernel.SetDirty(this,true);
		}
		this.m_dirty = true;
		this.Concat();
		return v;
	}
	,get_rotation: function() {
		return haxor.math.Quaternion.get_temp().Set(this.m_rotation.x,this.m_rotation.y,this.m_rotation.z,this.m_rotation.w);
	}
	,set_rotation: function(v) {
		var tx = this.m_rotation.x;
		if(Math.abs(tx - v.x) < haxor.math.Mathf.Epsilon) {
			var ty = this.m_rotation.y;
			if(Math.abs(ty - v.y) < haxor.math.Mathf.Epsilon) {
				var tz = this.m_rotation.z;
				if(Math.abs(tz - v.z) < haxor.math.Mathf.Epsilon) {
					var tw = this.m_rotation.w;
					if(Math.abs(tw - v.w) < haxor.math.Mathf.Epsilon) return v;
				}
			}
		}
		this.m_rotation.x = v.x;
		this.m_rotation.y = v.y;
		this.m_rotation.z = v.z;
		this.m_rotation.w = v.w;
		if(haxor.component.Transform.m_threaded) {
			haxor.component.Transform.m_kernel.SetRotation(this);
			haxor.component.Transform.m_kernel.SetDirty(this,true);
		}
		this.m_dirty = true;
		this.Concat();
		return v;
	}
	,get_scale: function() {
		return haxor.math.Vector3.get_temp().Set(this.m_scale.x,this.m_scale.y,this.m_scale.z);
	}
	,set_scale: function(v) {
		var tx = this.m_scale.x;
		if(Math.abs(tx - v.x) < haxor.math.Mathf.Epsilon) {
			var ty = this.m_scale.y;
			if(Math.abs(ty - v.y) < haxor.math.Mathf.Epsilon) {
				var tz = this.m_scale.z;
				if(Math.abs(tz - v.z) < haxor.math.Mathf.Epsilon) return v;
			}
		}
		this.m_scale.x = v.x;
		this.m_scale.y = v.y;
		this.m_scale.z = v.z;
		if(haxor.component.Transform.m_threaded) {
			haxor.component.Transform.m_kernel.SetScale(this);
			haxor.component.Transform.m_kernel.SetDirty(this,true);
		}
		this.m_dirty = true;
		this.Concat();
		return v;
	}
	,set_LocalMatrix: function(v) {
		var m = this.m_localMatrix;
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
	}
	,get_LocalMatrix: function() {
		if(haxor.component.Transform.m_threaded) {
			haxor.component.Transform.m_kernel.GetLocalMatrix(this);
			this.m_dirty = false;
		} else if(this.m_dirty) {
			this.SetLocalTRS();
			this.m_dirty = false;
		}
		var m = this.m_tm0;
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
		m.m30 = m.m31 = m.m32 = 0.0;
		m.m33 = 1.0;
		return m;
	}
	,set_WorldMatrix: function(v) {
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
	}
	,get_WorldMatrix: function() {
		var m = haxor.math.Matrix4.get_temp();
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
	,set_WorldMatrixInverse: function(v) {
		var m = this.m_worldMatrixInverse;
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
	}
	,get_WorldMatrixInverse: function() {
		var m = haxor.math.Matrix4.get_temp();
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
	,WMToF32: function() {
		if(haxor.component.Transform.m_threaded) return haxor.component.Transform.m_kernel.GetWorldMatrix(this).ToBuffer();
		return this.m_worldMatrix.ToBuffer();
	}
	,WMIToF32: function() {
		if(haxor.component.Transform.m_threaded) return haxor.component.Transform.m_kernel.GetWorldMatrixInverse(this).ToBuffer();
		return this.m_worldMatrixInverse.ToBuffer();
	}
	,Concat: function() {
		if(this.m_lock) return;
		this.m_concat = true;
		if(haxor.component.Transform.m_threaded) {
			haxor.component.Transform.m_kernel.SetConcat(this,true);
			var _g1 = 0;
			var _g = this.m_hierarchy.length;
			while(_g1 < _g) {
				var i = _g1++;
				this.m_hierarchy[i].Concat();
			}
		} else {
			var v = this.get_parent().m_worldMatrix;
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
			var _g11 = 0;
			var _g2 = this.m_hierarchy.length;
			while(_g11 < _g2) {
				var i1 = _g11++;
				this.m_hierarchy[i1].Concat();
			}
		}
	}
	,KernelSync: function() {
		if(this.m_dirty) {
			haxor.component.Transform.m_kernel.GetLocalMatrix(this);
			this.m_dirty = false;
			haxor.component.Transform.m_kernel.SetDirty(this,false);
		}
		if(this.m_concat) {
			haxor.component.Transform.m_kernel.GetWorldMatrix(this);
			haxor.component.Transform.m_kernel.GetWorldMatrixInverse(this);
			this.UpdateComponents();
			this.m_concat = false;
			haxor.component.Transform.m_kernel.SetConcat(this,false);
		}
	}
	,UpdateComponents: function() {
		var _g1 = 0;
		var _g = this.get_entity().m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.get_entity().m_components[i].OnTransformUpdate();
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
		var r = this.m_tm1;
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
		var tid = this.m_tid;
		haxor.component.Transform.m_list[tid] = null;
		haxor.component.Transform.m_indexes.push(tid);
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
		var p = this.get_parent();
		var res = [];
		while(p != null) {
			res.push(p);
			p = p.get_parent();
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
			var d = haxor.math.Mathf.MaxInt([0,td - d0]);
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
	,__properties__: $extend(haxor.component.Component.prototype.__properties__,{get_childCount:"get_childCount",get_WorldMatrixInverse:"get_WorldMatrixInverse",get_WorldMatrix:"get_WorldMatrix",get_LocalMatrix:"get_LocalMatrix",set_scale:"set_scale",get_scale:"get_scale",set_rotation:"set_rotation",get_rotation:"get_rotation",set_position:"set_position",get_position:"get_position",set_parent:"set_parent",get_parent:"get_parent",get_forward:"get_forward",get_up:"get_up",get_right:"get_right"})
});
haxor.core.ApplicationProtocol = { __ename__ : true, __constructs__ : ["Unknown","File","HTTP","HTTPS"] };
haxor.core.ApplicationProtocol.Unknown = ["Unknown",0];
haxor.core.ApplicationProtocol.Unknown.__enum__ = haxor.core.ApplicationProtocol;
haxor.core.ApplicationProtocol.File = ["File",1];
haxor.core.ApplicationProtocol.File.__enum__ = haxor.core.ApplicationProtocol;
haxor.core.ApplicationProtocol.HTTP = ["HTTP",2];
haxor.core.ApplicationProtocol.HTTP.__enum__ = haxor.core.ApplicationProtocol;
haxor.core.ApplicationProtocol.HTTPS = ["HTTPS",3];
haxor.core.ApplicationProtocol.HTTPS.__enum__ = haxor.core.ApplicationProtocol;
haxor.core.Asset = function() { };
$hxClasses["haxor.core.Asset"] = haxor.core.Asset;
haxor.core.Asset.__name__ = ["haxor","core","Asset"];
haxor.core.Asset.__properties__ = {get_m_dependenceProgress:"get_m_dependenceProgress",get_dependenceCount:"get_dependenceCount"}
haxor.core.Asset.get_dependenceCount = function() {
	return haxor.core.Asset.m_dependences.length;
};
haxor.core.Asset.get_m_dependenceProgress = function() {
	if(haxor.core.Asset.m_dependences.length <= 0) return 1.0;
	var p = 0;
	var t = haxor.core.Asset.m_dependences.length;
	var _g1 = 0;
	var _g = haxor.core.Asset.m_dependences.length;
	while(_g1 < _g) {
		var i = _g1++;
		p += haxor.core.Asset.GetProgress(haxor.core.Asset.m_dependences[i]);
	}
	return p / t;
};
haxor.core.Asset.Get = function(p_id) {
	if(haxor.core.Asset.m_database.exists(p_id)) return haxor.core.Asset.m_database.get(p_id); else return null;
};
haxor.core.Asset.Add = function(p_id,p_asset) {
	var value = p_asset;
	haxor.core.Asset.m_database.set(p_id,value);
};
haxor.core.Asset.GetURL = function(p_id) {
	if(haxor.core.Asset.m_url.exists(p_id)) return haxor.core.Asset.m_url.get(p_id); else return "";
};
haxor.core.Asset.GetProgress = function(p_id) {
	if(haxor.core.Asset.m_progress.exists(p_id)) return haxor.core.Asset.m_progress.get(p_id); else return 0.0;
};
haxor.core.Asset.LoadShader = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadShader(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.LoadXML = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadXML(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.LoadJSON = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadJSON(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.Load = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.Load(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.LoadTextureHTML = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadTextureHTML(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.LoadTexture2D = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadTexture2D(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.LoadImage = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadImage(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.LoadAudio = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadAudio(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.LoadSound = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadSound(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.LoadImageData = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadImageData(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.LoadTextureCube = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadTexture2D(p_url,function(d,p) {
		var c;
		if(p < 1.0) c = null; else c = haxor.texture.TextureCube.FromCrossTexture(d);
		if(p >= 1.0) haxor.core.Resource.Destroy(d);
		haxor.core.Asset.AssetProgress(p_id,c,p);
	});
};
haxor.core.Asset.LoadUISkin = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadXML(p_url,function(d,p) {
		if(p < 1.0) haxor.core.Asset.AssetProgress(p_id,null,p); else {
			haxor.core.Asset.BeginDependences();
			var skn = new haxor.ui.UISkin(d);
			haxor.core.Asset.EndDependences();
			haxor.core.Asset.AssetProgress(p_id,skn,p);
		}
	});
};
haxor.core.Asset.LoadVideoHTML = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadVideoHTML(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.LoadCollada = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	return haxor.net.Web.LoadCollada(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.LoadMaterial = function(p_id,p_url) {
	haxor.core.Asset.AssetInit(p_id,p_url);
	haxor.core.Asset.m_materials.push(p_id);
	return haxor.net.Web.LoadMaterial(p_url,function(d,p) {
		haxor.core.Asset.AssetProgress(p_id,d,p);
	});
};
haxor.core.Asset.AssetInit = function(p_id,p_url) {
	if(haxor.core.Asset.m_dependenceEnabled) haxor.core.Asset.m_dependences.push(p_id);
	haxor.core.Asset.m_isdependence.set(p_id,haxor.core.Asset.m_dependenceEnabled);
	haxor.core.Asset.m_progress.set(p_id,0);
	haxor.core.Asset.m_url.set(p_id,p_url);
};
haxor.core.Asset.AssetProgress = function(p_id,p_asset,p_progress) {
	var p;
	if(p_progress >= 1.0) p = 1.0; else p = p_progress;
	haxor.core.Asset.m_progress.set(p_id,p);
	if(p >= 1.0) {
		var value = p_asset;
		haxor.core.Asset.m_database.set(p_id,value);
	}
	if(haxor.core.Asset.m_isdependence.get(p_id)) {
		var a = haxor.core.Engine.get_application();
		if(a.get_loader() != null) {
			a.get_loader().OnElementProgress(p_id,p);
			a.get_loader().OnProgress(haxor.core.Asset.get_m_dependenceProgress());
			if(p >= 1.0) a.get_loader().OnElementComplete(p_id);
		}
		a.OnDependenceProgress(p_id,p);
		a.OnProgress(haxor.core.Asset.get_m_dependenceProgress());
		if(p >= 1.0) a.OnDependenceLoad(p_id);
	}
};
haxor.core.Asset.Create = function() {
	var _g1 = 0;
	var _g = haxor.core.Asset.m_materials.length;
	while(_g1 < _g) {
		var i = _g1++;
		var mf = haxor.core.Asset.Get(haxor.core.Asset.m_materials[i]);
		if(mf == null) continue;
		haxor.core.Asset.Add(haxor.core.Asset.m_materials[i],mf.GetAsset());
	}
	if(haxor.graphics.Graphics.get_c3d() != null) {
		var rf32 = new Float32Array(1048576);
		var _g11 = 0;
		var _g2 = rf32.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			rf32[i1] = Math.random();
		}
		var random_texture = new haxor.texture.KernelTexture(512,512,haxor.texture.TextureFormat.Float4);
		random_texture.set_wrap(haxor.texture.TextureWrap.RepeatX | haxor.texture.TextureWrap.RepeatY);
		random_texture.WriteRange(rf32);
		haxor.core.Asset.Add("haxor/texture/random",random_texture);
	}
};
haxor.core.Asset.BeginDependences = function() {
	haxor.core.Asset.m_dependenceEnabled = true;
	haxor.net.Web.m_autoload = true;
};
haxor.core.Asset.EndDependences = function() {
	haxor.core.Asset.m_dependenceEnabled = false;
	haxor.net.Web.m_autoload = true;
};
haxor.core.ByteArray = function(p_length,p_element_size) {
	var es;
	if(p_element_size == null) es = 1; else if(((p_element_size | 0) === p_element_size)) es = p_element_size; else es = haxor.core.ByteArray.SizeOf(p_element_size);
	this.m_data = new Uint8Array(p_length * es);
	this.position = 0;
	this.m_locked = false;
	if(haxor.core.ByteArray.m_lzma == null) {
		var c = null;
		c = new LZMA('./assets/plugins/lzma_worker.js');
		haxor.core.ByteArray.m_lzma = c;
	}
};
$hxClasses["haxor.core.ByteArray"] = haxor.core.ByteArray;
haxor.core.ByteArray.__name__ = ["haxor","core","ByteArray"];
haxor.core.ByteArray.FromLayout = function(v) {
	return new haxor.core.ByteArray(haxor.core.ByteArray.SizeOfLayout(v));
};
haxor.core.ByteArray.SizeOfLayout = function(v) {
	var len = 0;
	var _g1 = 0;
	var _g = v.length;
	while(_g1 < _g) {
		var i = _g1++;
		len += haxor.core.ByteArray.SizeOf(v[i]);
	}
	return len;
};
haxor.core.ByteArray.SizeOf = function(v,p) {
	if(p == null) p = 32;
	if(v == Int) return p / 4;
	if(v == Float) return 4;
	if(v == haxor.math.Vector2) return 8;
	if(v == haxor.math.Vector3) return 12;
	if(v == haxor.math.Vector4) return 16;
	if(v == haxor.math.Quaternion) return 16;
	if(v == haxor.math.Matrix4) return 64;
	if(v == haxor.math.Color) return p / 4;
	if(v == haxor.component.Transform) return 40;
	if(((v | 0) === v)) return p / 4;
	if(typeof(v) == "number") return 4;
	if(js.Boot.__instanceof(v,haxor.math.Vector2)) return 8;
	if(js.Boot.__instanceof(v,haxor.math.Vector3)) return 12;
	if(js.Boot.__instanceof(v,haxor.math.Vector4)) return 16;
	if(js.Boot.__instanceof(v,haxor.math.Quaternion)) return 16;
	if(js.Boot.__instanceof(v,haxor.math.Matrix4)) return 64;
	if(js.Boot.__instanceof(v,haxor.math.Color)) return p / 4;
	if(js.Boot.__instanceof(v,haxor.component.Transform)) return 40;
	if(js.Boot.__instanceof(v,ArrayBuffer)) {
		var a = v;
		return a.byteLength;
	}
	return -1;
};
haxor.core.ByteArray.SerializeString = function(v) {
	var res = new Uint8Array(v.length);
	var _g1 = 0;
	var _g = v.length;
	while(_g1 < _g) {
		var i = _g1++;
		res[i] = HxOverrides.cca(v,i);
	}
	return res;
};
haxor.core.ByteArray.UnserializeString = function(v) {
	var res = "";
	var _g1 = 0;
	var _g = v.length;
	while(_g1 < _g) {
		var i = _g1++;
		res += String.fromCharCode(v[i]);
	}
	return res;
};
haxor.core.ByteArray.SerializeInt32 = function(v) {
	return new Uint8Array([v >> 24 & 255,v >> 16 & 255,v >> 8 & 255,v & 255]);
};
haxor.core.ByteArray.UnserializeInt32 = function(v) {
	return v[0] << 24 | v[1] << 16 | v[2] << 8 | v[3];
};
haxor.core.ByteArray.SerializeFloat = function(v) {
	var buf = new ArrayBuffer(4);
	new Float32Array(buf)[0] = v;
	return haxor.core.ByteArray.SerializeInt32(new Uint32Array(buf)[0]);
};
haxor.core.ByteArray.UnserializeFloat = function(v) {
	var buf = new ArrayBuffer(4);
	new Uint32Array(buf)[0] = haxor.core.ByteArray.UnserializeInt32(v);
	return new Float32Array(buf)[0];
};
haxor.core.ByteArray.prototype = {
	get_length: function() {
		return this.m_data.byteLength;
	}
	,get_data: function() {
		return this.m_data;
	}
	,set_data: function(v) {
		this.m_data = v;
		this.position = 0;
		this.m_locked = false;
		return v;
	}
	,Reset: function() {
		this.position = 0;
	}
	,WriteBytes: function(v) {
		var _g1 = 0;
		var _g = v.byteLength;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_data[this.position++] = v[i];
		}
	}
	,WriteByteArray: function(v) {
		var _g1 = 0;
		var _g = v.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_data[this.position++] = v[i];
		}
	}
	,WriteInt8: function(v) {
		this.m_data[this.position++] = v;
	}
	,WriteInt16: function(v) {
		this.m_data[this.position++] = v >> 8 & 255;
		this.m_data[this.position++] = v & 255;
	}
	,WriteInt24: function(v) {
		this.m_data[this.position++] = v >> 16 & 255;
		this.m_data[this.position++] = v >> 8 & 255;
		this.m_data[this.position++] = v & 255;
	}
	,WriteInt32: function(v) {
		this.m_data[this.position++] = v >> 24 & 255;
		this.m_data[this.position++] = v >> 16 & 255;
		this.m_data[this.position++] = v >> 8 & 255;
		this.m_data[this.position++] = v & 255;
	}
	,WriteFloat: function(v) {
		this.WriteBytes(haxor.core.ByteArray.SerializeFloat(v));
	}
	,WriteVector2: function(v) {
		this.WriteFloat(v.x);
		this.WriteFloat(v.y);
	}
	,WriteVector3: function(v) {
		this.WriteFloat(v.x);
		this.WriteFloat(v.y);
		this.WriteFloat(v.z);
	}
	,WriteVector4: function(v) {
		this.WriteFloat(v.x);
		this.WriteFloat(v.y);
		this.WriteFloat(v.z);
		this.WriteFloat(v.w);
	}
	,WriteColorRGBA: function(v) {
		this.WriteInt32(v.get_rgba());
	}
	,WriteColorARGB: function(v) {
		this.WriteInt32(v.get_argb());
	}
	,WriteColorRGB: function(v) {
		this.WriteInt24(v.get_rgb());
	}
	,WriteQuaternion: function(v) {
		this.WriteFloat(v.x);
		this.WriteFloat(v.y);
		this.WriteFloat(v.z);
		this.WriteFloat(v.w);
	}
	,WriteMatrix4: function(v) {
		this.WriteFloat(v.m00);
		this.WriteFloat(v.m01);
		this.WriteFloat(v.m02);
		this.WriteFloat(v.m03);
		this.WriteFloat(v.m10);
		this.WriteFloat(v.m11);
		this.WriteFloat(v.m12);
		this.WriteFloat(v.m13);
		this.WriteFloat(v.m20);
		this.WriteFloat(v.m21);
		this.WriteFloat(v.m22);
		this.WriteFloat(v.m23);
		this.WriteFloat(v.m30);
		this.WriteFloat(v.m31);
		this.WriteFloat(v.m32);
		this.WriteFloat(v.m33);
	}
	,WriteTransform: function(v) {
		this.WriteVector3(v.get_position());
		this.WriteQuaternion(v.get_rotation());
		this.WriteVector3(v.get_scale());
	}
	,WriteString: function(v) {
		var _g1 = 0;
		var _g = v.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_data[this.position++] = HxOverrides.cca(v,i);
		}
	}
	,ReadBytes: function(p_offset,p_length) {
		if(p_length == null) p_length = 0;
		if(p_offset == null) p_offset = 0;
		var len;
		if(p_length <= 0) len = this.get_length(); else len = p_length;
		var res = new Uint8Array(len);
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			res[i] = this.m_data[this.position + p_offset + i];
		}
		return res;
	}
	,ReadInt8: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var o = this.position + p_offset;
		return this.m_data[o];
	}
	,ReadInt16: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var o = this.position + p_offset;
		return this.m_data[o] << 8 | this.m_data[o + 1];
	}
	,ReadInt24: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var o = this.position + p_offset;
		return this.m_data[o] << 16 | this.m_data[o + 1] << 8 | this.m_data[o + 2];
	}
	,ReadInt32: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var o = this.position + p_offset;
		return this.m_data[o] << 24 | this.m_data[o + 1] << 16 | this.m_data[o + 2] << 8 | this.m_data[o + 3];
	}
	,ReadFloat: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var o = p_offset;
		return haxor.core.ByteArray.UnserializeFloat(this.ReadBytes(o,4));
	}
	,ReadVector2: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var v = new haxor.math.Vector2(this.ReadFloat(p_offset),this.ReadFloat(p_offset + 4));
		return v;
	}
	,ReadVector3: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var v = new haxor.math.Vector3(this.ReadFloat(p_offset),this.ReadFloat(p_offset + 4),this.ReadFloat(p_offset + 8));
		return v;
	}
	,ReadVector4: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var v = new haxor.math.Vector4(this.ReadFloat(p_offset),this.ReadFloat(p_offset + 4),this.ReadFloat(p_offset + 8),this.ReadFloat(p_offset + 12));
		return v;
	}
	,ReadColorRGBA: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var v = new haxor.math.Color();
		v.set_rgba(this.ReadInt32(p_offset));
		return v;
	}
	,ReadColorARGB: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var v = new haxor.math.Color();
		v.set_argb(this.ReadInt32(p_offset));
		return v;
	}
	,ReadColorRGB: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var v = new haxor.math.Color();
		v.set_rgb(this.ReadInt24(p_offset));
		return v;
	}
	,ReadQuaternion: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var v = new haxor.math.Quaternion(this.ReadFloat(p_offset),this.ReadFloat(p_offset + 4),this.ReadFloat(p_offset + 8),this.ReadFloat(p_offset + 12));
		return v;
	}
	,ReadMatrix4: function(p_offset) {
		if(p_offset == null) p_offset = 0;
		var v = new haxor.math.Matrix4();
		var o = p_offset;
		v.m00 = this.ReadFloat(o);
		v.m01 = this.ReadFloat(o + 4);
		v.m02 = this.ReadFloat(o + 8);
		v.m03 = this.ReadFloat(o + 12);
		v.m10 = this.ReadFloat(o + 16);
		v.m11 = this.ReadFloat(o + 20);
		v.m12 = this.ReadFloat(o + 24);
		v.m13 = this.ReadFloat(o + 28);
		v.m20 = this.ReadFloat(o + 32);
		v.m21 = this.ReadFloat(o + 36);
		v.m22 = this.ReadFloat(o + 40);
		v.m23 = this.ReadFloat(o + 44);
		v.m30 = this.ReadFloat(o + 48);
		v.m31 = this.ReadFloat(o + 52);
		v.m32 = this.ReadFloat(o + 56);
		v.m33 = this.ReadFloat(o + 60);
		return v;
	}
	,ReadTransform: function(p_transform,p_offset) {
		if(p_offset == null) p_offset = 0;
		p_transform.set_position(this.ReadVector3(p_offset));
		p_transform.set_rotation(this.ReadQuaternion(p_offset + 12));
		p_transform.set_scale(this.ReadVector3(p_offset + 28));
	}
	,ReadFloatArray: function() {
		var len = this.get_length() - this.position;
		len = len / 4;
		var res = new Float32Array(len);
		var p = this.position;
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			res[i] = this.ReadFloat();
			this.position += 4;
		}
		p = this.position;
		return res;
	}
	,ReadString: function(p_length) {
		if(p_length == null) p_length = 0;
		var len;
		if(p_length <= 0) len = this.get_length() - this.position; else len = p_length;
		var s = "";
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			s += String.fromCharCode(this.m_data[this.position + i]);
		}
		return s;
	}
	,EncodeBase64: function() {
		var len = this.get_length();
		if(len <= 0) return "";
		var flen = len / 3.0 + 0.7 | 0;
		var base64_length = flen * 4 | 0;
		if(base64_length < 4) base64_length = 4; else base64_length = base64_length;
		var rest = this.get_length() * 8 % 6;
		var map = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		var res = new haxor.core.ByteArray(base64_length);
		var wl = base64_length - 4;
		var i = 0;
		var rt0 = rest != 2;
		var rt1 = rest != 2 && rest != 4;
		while(i < len) {
			var b0 = this.m_data[i];
			var b1;
			if(i < len - 1) b1 = this.m_data[i + 1]; else b1 = 0;
			var b2;
			if(i < len - 2) b2 = this.m_data[i + 2]; else b2 = 0;
			var b60 = b0 >> 2 & 63;
			var b61 = (b0 & 3) << 4 | b1 >> 4 & 15;
			var b62 = (b1 & 15) << 2 | b2 >> 6 & 3;
			var b63 = b2 & 63;
			var s0 = map.charAt(b60);
			var s1 = map.charAt(b61);
			var s2;
			if(res.position < wl || rt0) s2 = map.charAt(b62); else s2 = "=";
			var s3;
			if(res.position < wl || rt1) s3 = map.charAt(b63); else s3 = "=";
			res.WriteString(s0);
			res.WriteString(s1);
			res.WriteString(s2);
			res.WriteString(s3);
			i += 3;
		}
		res.position = 0;
		this.m_data = res.m_data;
		this.position = 0;
		return res.ReadString();
	}
	,DecodeBase64: function() {
		var map = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
		var unmap = new Uint8Array(255);
		var _g1 = 0;
		var _g = map.length;
		while(_g1 < _g) {
			var i = _g1++;
			unmap[HxOverrides.cca(map,i)] = i;
		}
		var data_len = this.get_length();
		var i1 = 0;
		var res = [];
		var eqc = HxOverrides.cca("=",0);
		while(i1 < data_len) {
			var b60 = unmap[this.m_data[i1]] & 63;
			var b61 = unmap[this.m_data[i1 + 1]] & 63;
			var b62 = unmap[this.m_data[i1 + 2]] & 63;
			var b63 = unmap[this.m_data[i1 + 3]] & 63;
			var b0 = b60 << 2 | b61 >> 4;
			var b1 = (b61 & 15) << 4 | b62 >> 2;
			var b2 = (b62 & 3) << 6 | b63 & 63;
			res.push(b0);
			if(this.m_data[i1 + 2] != eqc) {
				if(this.m_data[i1 + 3] != eqc) res.push(b1);
			}
			if(this.m_data[i1 + 3] != eqc) res.push(b2);
			i1 += 4;
		}
		this.m_data = new Uint8Array(res.length);
		this.position = 0;
		this.WriteByteArray(res);
		this.position = 0;
		return this.ReadString();
	}
	,Compress: function(p_mode,p_complete) {
		var _g = this;
		if(this.m_locked) return;
		this.m_locked = true;
		this.position = 0;
		var ds = this.ReadString();
		var oc = function(v) {
			var len = v.length;
			_g.m_data = new Uint8Array(len);
			var _g1 = 0;
			while(_g1 < len) {
				var i = _g1++;
				_g.WriteInt8(v[i]);
			}
			_g.position = 0;
			_g.m_locked = false;
			if(p_complete != null) p_complete();
		};
		var c = haxor.core.ByteArray.m_lzma;
		c.compress(ds, p_mode,oc, function op(v) { } );
	}
	,CompressWeb: function(p_mode,p_complete) {
		var _g = this;
		if(this.m_locked) return;
		this.Compress(p_mode,function() {
			_g.EncodeBase64();
			if(p_complete != null) p_complete();
		});
	}
	,Decompress: function(p_complete) {
		var _g = this;
		if(this.m_locked) return;
		this.m_locked = true;
		this.position = 0;
		var oc = function(v) {
			var len = v.length;
			_g.m_data = new Uint8Array(len);
			var _g1 = 0;
			while(_g1 < len) {
				var i = _g1++;
				_g.WriteInt8(HxOverrides.cca(v,i));
			}
			_g.position = 0;
			_g.m_locked = false;
			if(p_complete != null) p_complete();
		};
		var c = haxor.core.ByteArray.m_lzma;
		var d = this.m_data;
		c.decompress(d,oc, function op(v) { } );
	}
	,DecompressWeb: function(p_complete) {
		if(this.m_locked) return;
		this.DecodeBase64();
		this.Decompress(p_complete);
	}
	,__class__: haxor.core.ByteArray
	,__properties__: {set_data:"set_data",get_data:"get_data",get_length:"get_length"}
};
haxor.core.Console = function() { };
$hxClasses["haxor.core.Console"] = haxor.core.Console;
haxor.core.Console.__name__ = ["haxor","core","Console"];
haxor.core.Console.__properties__ = {get__console:"get__console"}
haxor.core.Console.get__console = function() {
	return haxor.core.Console.m_console;
};
haxor.core.Console.SetStyle = function(p_size,p_color,p_background,p_font) {
	if(p_font == null) p_font = "'Lucida Console', Monaco, monospace";
	if(p_size == null) p_size = "12px";
	if(p_color == null) p_color = haxor.math.Color.get_black(); else p_color = p_color;
	if(p_background == null) p_background = haxor.math.Color.get_empty(); else p_background = p_background;
	haxor.core.Console.m_style = "background-color: " + p_background.get_css() + "; font-size: " + p_size + "; color: " + p_color.get_css() + "; font-family: " + p_font + ";";
};
haxor.core.Console.LogImage = function(p_url,p_height) {
	var s = "background: transparent url(" + p_url + ") no-repeat; font-size: " + (p_height - 3) + "px;";
	haxor.core.Console.get__console().log("%c                                                                                                                                                            ",s);
};
haxor.core.Console.ClearStyle = function() {
	haxor.core.Console.m_style = "";
};
haxor.core.Console.Clear = function() {
	if(haxor.core.Console.get__console() == null) return;
	haxor.core.Console.get__console().clear();
};
haxor.core.Console.ProfileStart = function(p_msg) {
	if(haxor.core.Console.get__console() == null) return;
	haxor.core.Console.get__console().profile(p_msg);
};
haxor.core.Console.ProfileEnd = function(p_msg) {
	if(haxor.core.Console.get__console() == null) return;
	haxor.core.Console.get__console().profileEnd(p_msg);
};
haxor.core.Console.Log = function(p_msg,p_obj) {
	if(haxor.core.Console.get__console() == null) return;
	if(p_obj == null) p_obj = [];
	var s = haxor.core.Console.m_style;
	p_msg = "%c" + p_msg;
	var _g = p_obj.length;
	switch(_g) {
	case 0:
		haxor.core.Console.get__console().log(p_msg,s);
		break;
	case 1:
		haxor.core.Console.get__console().log(p_msg,p_obj[0],s);
		break;
	case 2:
		haxor.core.Console.get__console().log(p_msg,p_obj[0],p_obj[1],s);
		break;
	case 3:
		haxor.core.Console.get__console().log(p_msg,p_obj[0],p_obj[1],p_obj[2],s);
		break;
	case 4:
		haxor.core.Console.get__console().log(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3],s);
		break;
	case 5:
		haxor.core.Console.get__console().log(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3],p_obj[4],s);
		break;
	}
};
haxor.core.Console.LogWarning = function(p_msg,p_obj) {
	if(haxor.core.Console.get__console() == null) return;
	if(p_obj == null) p_obj = [];
	var _g = p_obj.length;
	switch(_g) {
	case 0:
		haxor.core.Console.get__console().warn(p_msg);
		break;
	case 1:
		haxor.core.Console.get__console().warn(p_msg,p_obj[0]);
		break;
	case 2:
		haxor.core.Console.get__console().warn(p_msg,p_obj[0],p_obj[1]);
		break;
	case 3:
		haxor.core.Console.get__console().warn(p_msg,p_obj[0],p_obj[1],p_obj[2]);
		break;
	case 4:
		haxor.core.Console.get__console().warn(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3]);
		break;
	case 5:
		haxor.core.Console.get__console().warn(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3],p_obj[4]);
		break;
	}
};
haxor.core.Console.LogError = function(p_msg) {
	if(haxor.core.Console.get__console() != null) haxor.core.Console.get__console().error(p_msg);
};
haxor.core.Console.StackTrace = function() {
	if(haxor.core.Console.get__console() != null) haxor.core.Console.get__console().trace();
};
haxor.core.Console.Breakpoint = function() {
	debugger;
};
haxor.core.EngineState = { __ename__ : true, __constructs__ : ["Load","Run","Dispose"] };
haxor.core.EngineState.Load = ["Load",0];
haxor.core.EngineState.Load.__enum__ = haxor.core.EngineState;
haxor.core.EngineState.Run = ["Run",1];
haxor.core.EngineState.Run.__enum__ = haxor.core.EngineState;
haxor.core.EngineState.Dispose = ["Dispose",2];
haxor.core.EngineState.Dispose.__enum__ = haxor.core.EngineState;
haxor.core.Engine = function() { };
$hxClasses["haxor.core.Engine"] = haxor.core.Engine;
haxor.core.Engine.__name__ = ["haxor","core","Engine"];
haxor.core.Engine.__properties__ = {get_canvas:"get_canvas",get_application:"get_application"}
haxor.core.Engine.get_application = function() {
	return haxor.core.Engine.m_application;
};
haxor.core.Engine.get_canvas = function() {
	return haxor.core.Engine.m_canvas;
};
haxor.core.Engine.AddDisposable = function(p_object) {
	if(p_object.get_destroyed()) return;
	p_object.m_destroyed = true;
	if(js.Boot.__instanceof(p_object,haxor.component.Behaviour)) haxor.core.Engine.DisableBehaviour(p_object);
	haxor.core.Engine.m_garbageList.push(p_object);
};
haxor.core.Engine.AddAwakeBehaviour = function(p_behaviour) {
	haxor.core.Engine.m_awakeList.push(p_behaviour);
};
haxor.core.Engine.AddStartBehaviour = function(p_behaviour) {
	haxor.core.Engine.m_startList.push(p_behaviour);
};
haxor.core.Engine.Add = function(p_node) {
	var c = [haxor.core.IUpdateable,haxor.core.ILateUpdateable,haxor.core.IFixedUpdateable,haxor.core.IRenderable,haxor.core.IResizeable,haxor.core.IQueueRenderable,haxor.editor.IGizmoRenderer];
	var l = [haxor.core.Engine.m_updateList,haxor.core.Engine.m_lateUpdateList,haxor.core.Engine.m_fixedUpdateList,haxor.core.Engine.m_onrenderList,haxor.core.Engine.m_resizeList,haxor.core.Engine.m_onrenderQueueList,haxor.editor.Gizmo.m_handlers];
	var _g1 = 0;
	var _g = c.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(js.Boot.__instanceof(p_node,c[i])) {
			var found = false;
			var _g3 = 0;
			var _g2 = l[i].length;
			while(_g3 < _g2) {
				var k = _g3++;
				if(l[i][k] == p_node) found = true;
			}
			if(found) continue;
			l[i].push(p_node);
			if(l[i] == haxor.core.Engine.m_onrenderQueueList) {
				haxor.core.Engine.m_onrenderQueueMap.set(p_node,-1);
				haxor.core.Engine.SortRenderQueue();
			}
		}
	}
};
haxor.core.Engine.Remove = function(p_node) {
	var b = p_node;
	if(js.Boot.__instanceof(b,haxor.core.IUpdateable)) HxOverrides.remove(haxor.core.Engine.m_updateList,b);
	if(js.Boot.__instanceof(b,haxor.core.ILateUpdateable)) HxOverrides.remove(haxor.core.Engine.m_lateUpdateList,b);
	if(js.Boot.__instanceof(b,haxor.core.IFixedUpdateable)) HxOverrides.remove(haxor.core.Engine.m_fixedUpdateList,b);
	if(js.Boot.__instanceof(b,haxor.core.IRenderable)) HxOverrides.remove(haxor.core.Engine.m_onrenderList,b);
	if(js.Boot.__instanceof(b,haxor.core.IResizeable)) HxOverrides.remove(haxor.core.Engine.m_resizeList,b);
	if(js.Boot.__instanceof(b,haxor.core.IQueueRenderable)) HxOverrides.remove(haxor.core.Engine.m_onrenderQueueList,b);
	if(js.Boot.__instanceof(b,haxor.editor.IGizmoRenderer)) HxOverrides.remove(haxor.editor.Gizmo.m_handlers,b);
};
haxor.core.Engine.EnableBehaviour = function(p_behaviour) {
	var b = p_behaviour;
	if(b.get_destroyed()) return;
	haxor.core.Engine.Add(p_behaviour);
};
haxor.core.Engine.DisableBehaviour = function(p_behaviour) {
	if(p_behaviour == null) return;
	var b = p_behaviour;
	haxor.core.Engine.Remove(b);
};
haxor.core.Engine.StartBehaviour = function() {
	var l = haxor.core.Engine.m_startList;
	haxor.core.Engine.m_startList = [];
	var _g1 = 0;
	var _g = l.length;
	while(_g1 < _g) {
		var i = _g1++;
		var b = l[i];
		if(b.get_destroyed()) continue;
		b.OnStart();
		if(!b.get_destroyed()) {
			if(js.Boot.__instanceof(b,haxor.core.IResizeable)) {
				var r = b;
				r.OnResize(haxor.graphics.Screen.get_width(),haxor.graphics.Screen.get_height());
			}
		}
	}
};
haxor.core.Engine.AwakeBehaviour = function() {
	var l = haxor.core.Engine.m_awakeList;
	haxor.core.Engine.m_awakeList = [];
	var _g1 = 0;
	var _g = l.length;
	while(_g1 < _g) {
		var i = _g1++;
		var b = l[i];
		if(b.get_destroyed()) continue;
		b.OnAwake();
	}
};
haxor.core.Engine.CallUpdate = function() {
	var _g1 = 0;
	var _g = haxor.core.Engine.m_updateList.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(haxor.core.Engine.m_updateList[i] != null) haxor.core.Engine.m_updateList[i].OnUpdate();
	}
};
haxor.core.Engine.CallLateUpdate = function() {
	var _g1 = 0;
	var _g = haxor.core.Engine.m_lateUpdateList.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(haxor.core.Engine.m_lateUpdateList[i] != null) haxor.core.Engine.m_lateUpdateList[i].OnLateUpdate();
	}
};
haxor.core.Engine.CallFixedUpdate = function() {
	haxor.core.Engine.fixedUpdateMs = haxor.core.Time.get_ms();
	var k = 0;
	var fdt = haxor.core.Time.m_fixedDeltaTime;
	var dt = fdt;
	while(haxor.core.Time.m_simulationTimeSlice >= haxor.core.Time.get_fixedDeltaTime()) {
		var _g1 = 0;
		var _g = haxor.core.Engine.m_fixedUpdateList.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(haxor.core.Engine.m_fixedUpdateList[i] != null) haxor.core.Engine.m_fixedUpdateList[i].OnFixedUpdate();
		}
		haxor.physics.Physics.Update();
		haxor.core.Time.m_simulationTimeSlice -= dt;
	}
	haxor.physics.Physics.UpdateCollisionState();
	haxor.core.Time.set_fixedDeltaTime(fdt);
	haxor.core.Engine.fixedUpdateMs = haxor.core.Time.get_ms() - haxor.core.Engine.fixedUpdateMs;
};
haxor.core.Engine.Render = function() {
	var _g1 = 0;
	var _g = haxor.core.Engine.m_onrenderList.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(haxor.core.Engine.m_onrenderList[i] != null) haxor.core.Engine.m_onrenderList[i].OnRender();
	}
};
haxor.core.Engine.Render3D = function() {
	var cl = haxor.component.Camera.get_list();
	var rql;
	var sort_queue = false;
	haxor.core.Engine.renderMs = haxor.core.Time.get_ms();
	haxor.core.Stats.renderCount = 0;
	haxor.core.Stats.visibleCount = 0;
	haxor.core.Stats.invisibleCount = 0;
	var _g1 = 0;
	var _g = cl.length;
	while(_g1 < _g) {
		var i = _g1++;
		var c = cl[i];
		if(!c.get_enabled()) continue;
		haxor.component.Camera.current = c;
		haxor.api.TextureAPI.BindRT(c.m_grab);
		haxor.graphics.Graphics.Clear(c);
		rql = haxor.core.Engine.m_onrenderQueueList;
		var k = 5;
		var cc = 250;
		var _g3 = 0;
		var _g2 = rql.length;
		while(_g3 < _g2) {
			var j = _g3++;
			var it = rql[j];
			if(it == null) continue;
			while(k > 0) {
				if(haxor.core.Engine.m_nextCompare < rql.length - 1) {
					if(haxor.core.Engine.NeedQueueSort(rql[haxor.core.Engine.m_nextCompare],rql[haxor.core.Engine.m_nextCompare + 1])) sort_queue = true;
				}
				k--;
				haxor.core.Engine.m_nextCompare = (haxor.core.Engine.m_nextCompare + 1) % haxor.core.Engine.m_onrenderQueueList.length;
			}
			if(js.Boot.__instanceof(it,haxor.component.Renderer)) {
				var rn = it;
				if((rn.get_layer() & c.mask) != 0) {
					if(js.Boot.__instanceof(it,haxor.component.MeshRenderer)) {
						var mr = it;
						if(mr.visible) haxor.core.Stats.visibleCount++; else haxor.core.Stats.invisibleCount++;
						if(mr.visible) {
							if(mr.material != null) {
								if(mr.material.grab) {
									var rt = c.m_grab;
									if(mr.material.screen == null) mr.material.screen = new haxor.texture.RenderTexture(rt.get_width(),rt.get_height(),haxor.texture.TextureFormat.RGBA8); else {
										if(rt.get_width() != mr.material.screen.get_width()) {
											haxor.core.Resource.Destroy(mr.material.screen);
											mr.material.screen = null;
										} else if(rt.get_height() != mr.material.screen.get_height()) {
											haxor.core.Resource.Destroy(mr.material.screen);
											mr.material.screen = null;
										}
										if(mr.material.screen == null) mr.material.screen = new haxor.texture.RenderTexture(rt.get_width(),rt.get_height(),haxor.texture.TextureFormat.RGBA8);
									}
									haxor.graphics.Graphics.Blit(rt,mr.material.screen);
									haxor.api.TextureAPI.BindRT(rt);
								}
							}
							haxor.core.Stats.renderCount++;
							it.OnRender();
						}
					} else {
						haxor.core.Stats.renderCount++;
						it.OnRender();
					}
				}
			} else it.OnRender();
		}
		if(c.get_filters().length > 0) {
			var depth_texture = c.m_grab.get_depth();
			haxor.graphics.Graphics.Blit(c.m_grab,c.m_srcRT);
			var lastRT = c.m_srcRT;
			var srcRT = c.m_srcRT;
			var dstRT = c.m_dstRT;
			var _g31 = 0;
			var _g21 = c.get_filters().length;
			while(_g31 < _g21) {
				var k1 = _g31++;
				if(c.get_filters()[k1].enabled) {
					c.get_filters()[k1].depth = depth_texture;
					c.get_filters()[k1].OnRender(c.m_srcRT,c.m_dstRT);
					c.get_filters()[k1].depth = null;
				} else haxor.graphics.Graphics.Blit(c.m_srcRT,c.m_dstRT);
				lastRT = c.m_dstRT;
				c.m_dstRT = c.m_srcRT;
				c.m_srcRT = lastRT;
			}
			haxor.graphics.Graphics.Blit(lastRT,c.m_target);
			c.m_srcRT = srcRT;
			c.m_dstRT = dstRT;
		} else haxor.graphics.Graphics.Blit(c.m_grab,c.m_target);
		c.SwapBuffer();
		haxor.api.TextureAPI.BindRT(null);
		haxor.editor.Gizmo.Render();
	}
	haxor.core.Engine.Render();
	if(sort_queue) haxor.core.Engine.SortRenderQueue();
	haxor.core.Engine.renderMs = haxor.core.Time.get_ms() - haxor.core.Engine.renderMs;
};
haxor.core.Engine.NeedQueueSort = function(a,b) {
	var ia = a.GetQueue();
	var ib = b.GetQueue();
	if(ia > ib) return true;
	if(!js.Boot.__instanceof(a,haxor.component.MeshRenderer)) return false;
	if(!js.Boot.__instanceof(b,haxor.component.MeshRenderer)) return false;
	var mra = a;
	var mrb = b;
	if(mra.get_mesh() == null) {
		if(mrb.get_mesh() == null) return false;
	}
	if(mra.get_mesh() == null) return true;
	if(mrb.get_mesh() == null) return true;
	ia = mra.get_mesh().get_id();
	ib = mrb.get_mesh().get_id();
	if(ia > ib) return true;
	if(mra.material == null) {
		if(mrb.material == null) return false;
	}
	if(mra.material == null) return true;
	if(mrb.material == null) return true;
	if(mra.material.get_shader() == null) {
		if(mrb.material.get_shader() == null) return false;
	}
	if(mra.material.get_shader() == null) return true;
	if(mrb.material.get_shader() == null) return true;
	ia = mra.material.get_shader().get_id();
	ib = mrb.material.get_shader().get_id();
	if(ia > ib) return true;
	return false;
};
haxor.core.Engine.CompareQueueRenderer = function(a,b) {
	var ia = a.GetQueue();
	var ib = b.GetQueue();
	if(ia != ib) if(ia < ib) return -1; else return 1;
	if(!js.Boot.__instanceof(a,haxor.component.MeshRenderer)) {
		if(!js.Boot.__instanceof(b,haxor.component.MeshRenderer)) return 0;
	}
	if(!js.Boot.__instanceof(a,haxor.component.MeshRenderer)) return 1;
	if(!js.Boot.__instanceof(b,haxor.component.MeshRenderer)) return -1;
	var mra = a;
	var mrb = b;
	if(mra.material == null) {
		if(mrb.material == null) return 0;
	}
	if(mra.material == null) return 1;
	if(mrb.material == null) return -1;
	ia = mra.material.get_id();
	ib = mrb.material.get_id();
	if(ia != ib) if(ia < ib) return -1; else return 1;
	if(mra.get_mesh() == null) {
		if(mrb.get_mesh() == null) return 0;
	}
	if(mra.get_mesh() == null) return 1;
	if(mrb.get_mesh() == null) return -1;
	ia = mra.get_mesh().get_id();
	ib = mrb.get_mesh().get_id();
	if(ia != ib) if(ia < ib) return -1; else return 1;
	ia = mra.get_transform().get_id();
	ib = mrb.get_transform().get_id();
	if(ia != ib) if(ia < ib) return -1; else return 1;
	return 0;
};
haxor.core.Engine.SortRenderQueue = function() {
	haxor.core.Engine.m_onrenderQueueList.sort(function(a,b) {
		return haxor.core.Engine.CompareQueueRenderer(a,b);
	});
};
haxor.core.Engine.CollectDisposable = function() {
	var count = Math.min(haxor.core.Engine.m_garbageCollectRate,haxor.core.Engine.m_garbageList.length);
	var _g = 0;
	while(_g < count) {
		var i = _g++;
		var d = haxor.core.Engine.m_garbageList.pop();
		if(js.Boot.__instanceof(d,haxor.core.Resource)) d.OnDestroy();
	}
};
haxor.core.Engine.Run = function() {
	console.log("Haxor Engine v" + haxor.core.Engine.version);
	console.log("Haxor> Workers [" + Std.string(haxor.thread.Thread.get_available()) + "]");
	console.log("Haxor> OS      [" + window.navigator.platform + "]");
	console.log("Haxor> UA      [" + window.navigator.userAgent + "]");
	console.log("Haxor> Vendor  [" + haxor.core.Application.get_vendor() + "]");
	var script_element = null;
	var application_class_name = "";
	if(haxor.core.Application.get_protocol() == haxor.core.ApplicationProtocol.File || window.location.href.toLowerCase().indexOf("localhost") >= 0) {
		(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)  })(window,document,'script','http://www.google-analytics.com/analytics.js','ga');  ga('create', 'UA-50135074-1', 'auto');  ga('send', 'pageview');;
	}
	haxor.component.Animation.Initialize();
	haxor.core.Application.TraverseDOM(function(n) {
		if(n.nodeName.toLowerCase() == "script") {
			var e = n;
			if(e.hasAttribute("application")) {
				application_class_name = e.getAttribute("application");
				script_element = e;
				return false;
			} else if(e.hasAttribute("data-application")) {
				application_class_name = e.getAttribute("data-application");
				script_element = e;
				return false;
			}
		}
		return true;
	});
	if(application_class_name == "") {
		throw "Haxor> Application class NOT found!";
		return;
	}
	var application_class = Type.resolveClass(application_class_name);
	console.log("Haxor> Application [" + application_class_name + "]");
	if(application_class == null) throw "Haxor> Application class is NULL."; else {
		haxor.core.Engine.m_application = Type.createInstance(application_class,[]);
		if(!js.Boot.__instanceof(haxor.core.Engine.m_application,haxor.core.Application)) throw "Haxor> Application class does not extends 'Application' base class!"; else {
			var mode;
			if(script_element.getAttribute("mode") == null) mode = "ui"; else mode = script_element.getAttribute("mode");
			var ui;
			if(script_element.getAttribute("ui") == null) ui = "false"; else ui = script_element.getAttribute("ui");
			console.log("Haxor> Initialize mode[" + mode + "] ui[" + ui + "]");
			haxor.core.Engine.Initialize(mode,ui == "true");
		}
	}
};
haxor.core.Engine.Initialize = function(p_mode,p_ui) {
	haxor.core.Time.Initialize();
	haxor.core.Engine.m_mode = p_mode;
	haxor.core.Engine.m_ui = p_ui;
	haxor.core.Engine.m_onrenderTime = 0;
	haxor.core.Engine.m_lastResizeWidth = 0;
	haxor.core.Engine.m_lastResizeHeight = 0;
	haxor.core.Engine.m_garbageList = [];
	haxor.core.Engine.m_entityList = [];
	haxor.core.Engine.m_startList = [];
	haxor.core.Engine.m_awakeList = [];
	haxor.core.Engine.m_updateList = [];
	haxor.core.Engine.m_lateUpdateList = [];
	haxor.core.Engine.m_fixedUpdateList = [];
	haxor.core.Engine.m_onrenderList = [];
	haxor.core.Engine.m_resizeList = [];
	haxor.core.Engine.m_onrenderQueueList = [];
	haxor.core.Engine.m_onrenderQueueMap = new haxe.ds.ObjectMap();
	if(p_ui) haxor.core.Engine.m_application.m_stage = new haxor.ui.Stage();
	var target_element = null;
	haxor.api.SoundAPI.Initialize();
	switch(p_mode) {
	case "3d":
		haxor.core.Application.TraverseDOM(function(it) {
			if(js.Boot.__instanceof(it,Element)) {
				var e = it;
				if(e.id == "haxor") {
					if(js.Boot.__instanceof(e,HTMLCanvasElement)) {
						target_element = e;
						return false;
					}
				}
			}
			return true;
		});
		if(target_element == null) console.log("Haxor> Canvas 3d not found. Creating default.");
		haxor.core.Engine.m_canvas = new haxor.ui.HaxorCanvas(target_element);
		target_element = haxor.core.Engine.m_canvas.get_element();
		haxor.core.Engine.m_onrender = haxor.core.Engine.RenderCallback3D;
		haxor.graphics.Graphics.Initialize(haxor.core.Engine.m_canvas.get_element());
		haxor.editor.Gizmo.Initialize();
		break;
	case "2d":
		break;
	case "ui":
		haxor.core.Engine.m_onrender = haxor.core.Engine.RenderCallbackUI;
		break;
	}
	var input_element;
	if(p_ui) input_element = haxor.core.Engine.get_application().get_stage().get_element(); else input_element = haxor.core.Engine.m_canvas.get_element();
	var screen_element;
	if(p_ui) screen_element = haxor.core.Engine.get_application().get_stage().get_element(); else screen_element = haxor.core.Engine.m_canvas.get_element();
	haxor.physics.Collider.Initialize();
	haxor.physics.Physics.Initialize();
	haxor.component.Transform.Initialize();
	haxor.component.RigidBody.Initialize();
	haxor.input.Input.Initialize(input_element);
	haxor.graphics.Screen.m_target = screen_element;
	window.setInterval(haxor.core.Engine.Update,0);
	haxor.core.Engine.m_state = haxor.core.EngineState.Load;
	haxor.core.Asset.BeginDependences();
	if(p_mode == "3d") {
		haxor.net.Web.root = "http://haxor.thelaborat.org/resources/";
		haxor.core.Asset.LoadShader("haxor/internal/Skybox","./shader/internal/Skybox.shader");
		haxor.core.Asset.LoadShader("haxor/internal/Error","./shader/internal/Error.shader");
		haxor.core.Asset.LoadShader("haxor/internal/Gizmo","./shader/internal/Gizmo.shader");
		haxor.core.Asset.LoadShader("haxor/internal/GUI","./shader/internal/GUI.shader");
		haxor.core.Asset.LoadShader("haxor/kernel/ParticleKernel","./shader/kernel/ParticleKernel.shader");
		haxor.net.Web.root = "./";
	}
	haxor.core.Engine.get_application().Load();
};
haxor.core.Engine.Update = function() {
	var _g = haxor.core.Engine.m_state;
	switch(_g[1]) {
	case 0:
		var p = haxor.core.Asset.get_m_dependenceProgress();
		haxor.core.Time.Update();
		haxor.input.Input.Update();
		haxor.core.Engine.CallUpdate();
		haxor.core.Engine.ResizeCallback();
		if(p >= 1) {
			var is_load_complete;
			if(haxor.core.Engine.get_application().get_loader() == null) is_load_complete = true; else is_load_complete = haxor.core.Engine.get_application().get_loader().m_finished;
			if(haxor.core.Engine.get_application().get_loader() != null) {
				if(!haxor.core.Engine.get_application().get_loader().m_complete) {
					haxor.core.Engine.get_application().get_loader().m_complete = true;
					haxor.core.Engine.get_application().get_loader().OnProgress(1);
					haxor.core.Engine.get_application().OnProgress(1.0);
					haxor.core.Engine.get_application().get_loader().OnComplete();
				}
			}
			if(is_load_complete) {
				haxor.core.Asset.EndDependences();
				haxor.core.Asset.Create();
				haxor.core.Engine.m_state = haxor.core.EngineState.Run;
				haxor.core.Time.m_simulationTimeSlice = 0.0;
				haxor.core.Engine.get_application().Initialize();
				return;
			}
		}
		break;
	case 1:
		haxor.core.Time.Update();
		haxor.core.Engine.inputMs = haxor.core.Time.get_ms();
		haxor.input.Input.Update();
		if(haxor.input.Input.IsDown(haxor.input.KeyCode.ControlKey)) {
			if(haxor.input.Input.IsDown(haxor.input.KeyCode.Alt)) {
				if(haxor.input.Input.Hit(haxor.input.KeyCode.P)) haxor.core.Engine.pause = !haxor.core.Engine.pause;
			}
		}
		if(haxor.core.Engine.pause) return;
		haxor.core.Engine.inputMs = haxor.core.Time.get_ms() - haxor.core.Engine.inputMs;
		var t = haxor.core.Time.get_ms();
		if(haxor.core.Engine.m_awakeList.length > 0) haxor.core.Engine.AwakeBehaviour();
		if(haxor.core.Engine.m_startList.length > 0) haxor.core.Engine.StartBehaviour();
		haxor.core.Engine.CallUpdate();
		haxor.core.Engine.CallLateUpdate();
		haxor.core.Engine.updateMs = haxor.core.Time.get_ms() - t;
		haxor.core.Engine.transformMs = haxor.core.Time.get_ms();
		haxor.component.Transform.Update(false);
		haxor.component.Transform.Update(true);
		haxor.core.Engine.transformMs = haxor.core.Time.get_ms() - haxor.core.Engine.transformMs;
		haxor.component.Animation.Update();
		haxor.core.Engine.CallFixedUpdate();
		if(haxor.graphics.Graphics.get_c3d() != null) {
			if(haxor.component.Camera.m_list != null) {
				haxor.core.Stats.cullTests = 0;
				var rql = haxor.core.Engine.m_onrenderQueueList;
				var fcc = 20;
				var _g1 = 0;
				while(_g1 < fcc) {
					var cc = _g1++;
					if(haxor.component.Camera.m_list.length > 0) {
						haxor.component.Camera.current = haxor.component.Camera.m_list[0];
						var fcid = haxor.component.MeshRenderer.m_next_cull_test;
						var fcr = rql[fcid];
						if(js.Boot.__instanceof(fcr,haxor.component.MeshRenderer)) {
							var fcmr = fcr;
							fcmr.CheckCulling();
							haxor.core.Stats.cullTests++;
						}
						haxor.component.MeshRenderer.m_next_cull_test = (haxor.component.MeshRenderer.m_next_cull_test + 1) % rql.length;
					}
				}
			}
		}
		haxor.core.Engine.m_onrenderTime += haxor.core.Time.get_frameDeltaTime();
		var spf = 1.0 / haxor.core.Engine.get_application().fps;
		if(haxor.core.Engine.m_onrenderTime >= spf) {
			haxor.core.Time.frame++;
			haxor.core.Engine.m_onrenderTime -= spf;
			window.requestAnimationFrame(haxor.core.Engine.m_onrender);
		}
		if(haxor.core.Engine.m_garbageList.length > 0) haxor.core.Engine.CollectDisposable();
		break;
	case 2:
		break;
	}
};
haxor.core.Engine.ResizeCallback = function() {
	if(haxor.core.Engine.m_ui) {
		haxor.graphics.Screen.m_width = haxor.core.Engine.get_application().get_stage().get_width();
		haxor.graphics.Screen.m_height = haxor.core.Engine.get_application().get_stage().get_height();
	} else if(haxor.core.Engine.m_canvas != null) {
		haxor.graphics.Screen.m_width = haxor.core.Engine.m_canvas.get_element().width;
		haxor.graphics.Screen.m_height = haxor.core.Engine.m_canvas.get_element().height;
	}
	var sw = haxor.graphics.Screen.get_width();
	var sh = haxor.graphics.Screen.get_height();
	if(haxor.core.Engine.m_lastResizeWidth != sw) {
		var it = HxOverrides.iter(haxor.core.Engine.m_resizeList);
		while(it.hasNext()) it.next().OnResize(haxor.graphics.Screen.m_width,haxor.graphics.Screen.m_height);
		haxor.core.Engine.m_lastResizeWidth = sw;
	} else if(haxor.core.Engine.m_lastResizeHeight != sh) {
		var it1 = HxOverrides.iter(haxor.core.Engine.m_resizeList);
		while(it1.hasNext()) it1.next().OnResize(haxor.graphics.Screen.m_width,haxor.graphics.Screen.m_height);
		haxor.core.Engine.m_lastResizeHeight = sh;
	}
};
haxor.core.Engine.RenderCallback3D = function(p_time) {
	haxor.core.Engine.ResizeCallback();
	haxor.core.Engine.Render3D();
	haxor.graphics.Graphics.Flush();
	return true;
};
haxor.core.Engine.RenderCallbackUI = function(p_time) {
	haxor.core.Engine.ResizeCallback();
	haxor.core.Engine.Render();
	return true;
};
haxor.core.ICollidable = function() { };
$hxClasses["haxor.core.ICollidable"] = haxor.core.ICollidable;
haxor.core.ICollidable.__name__ = ["haxor","core","ICollidable"];
haxor.core.ICollidable.prototype = {
	__class__: haxor.core.ICollidable
};
haxor.core.IFixedUpdateable = function() { };
$hxClasses["haxor.core.IFixedUpdateable"] = haxor.core.IFixedUpdateable;
haxor.core.IFixedUpdateable.__name__ = ["haxor","core","IFixedUpdateable"];
haxor.core.IFixedUpdateable.prototype = {
	__class__: haxor.core.IFixedUpdateable
};
haxor.core.ILateUpdateable = function() { };
$hxClasses["haxor.core.ILateUpdateable"] = haxor.core.ILateUpdateable;
haxor.core.ILateUpdateable.__name__ = ["haxor","core","ILateUpdateable"];
haxor.core.ILateUpdateable.prototype = {
	__class__: haxor.core.ILateUpdateable
};
haxor.core.IRenderable = function() { };
$hxClasses["haxor.core.IRenderable"] = haxor.core.IRenderable;
haxor.core.IRenderable.__name__ = ["haxor","core","IRenderable"];
haxor.core.IRenderable.prototype = {
	__class__: haxor.core.IRenderable
};
haxor.core.ITriggerable = function() { };
$hxClasses["haxor.core.ITriggerable"] = haxor.core.ITriggerable;
haxor.core.ITriggerable.__name__ = ["haxor","core","ITriggerable"];
haxor.core.ITriggerable.prototype = {
	__class__: haxor.core.ITriggerable
};
haxor.core.JSON = function() { };
$hxClasses["haxor.core.JSON"] = haxor.core.JSON;
haxor.core.JSON.__name__ = ["haxor","core","JSON"];
haxor.core.JSON.FromJSON = function(d) {
	var res = null;
	try {
		res = JSON.parse(d);
	} catch( err ) {
		return null;
	}
	return res;
};
haxor.core.JSON.ToJSON = function(d) {
	try {
		var cache = [];
		var res = JSON.stringify(d,function(key,value) {
			var is_obj = typeof value === 'object' && value !== null;
			if(is_obj) {
				var _g1 = 0;
				var _g = cache.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(cache[i] == value) return null;
				}
				cache.push(value);
			}
			return value;
		});
		return res;
	} catch( err ) {
		return "";
	}
	return "";
};
haxor.core.Stats = function() {
};
$hxClasses["haxor.core.Stats"] = haxor.core.Stats;
haxor.core.Stats.__name__ = ["haxor","core","Stats"];
haxor.core.Stats.prototype = {
	__class__: haxor.core.Stats
};
haxor.core.Time = function() { };
$hxClasses["haxor.core.Time"] = haxor.core.Time;
haxor.core.Time.__name__ = ["haxor","core","Time"];
haxor.core.Time.__properties__ = {get_ms:"get_ms",set_fixedDeltaTime:"set_fixedDeltaTime",get_fixedDeltaTime:"get_fixedDeltaTime",get_deltaTime:"get_deltaTime",get_frameDeltaTime:"get_frameDeltaTime",get_elapsed:"get_elapsed"}
haxor.core.Time.get_elapsed = function() {
	return haxor.core.Time.m_elapsed;
};
haxor.core.Time.get_frameDeltaTime = function() {
	return haxor.core.Time.m_frameDeltaTime;
};
haxor.core.Time.get_deltaTime = function() {
	return haxor.core.Time.m_frameDeltaTime * haxor.core.Time.scale;
};
haxor.core.Time.get_fixedDeltaTime = function() {
	return haxor.core.Time.m_fixedDeltaTime;
};
haxor.core.Time.set_fixedDeltaTime = function(v) {
	haxor.core.Time.m_fixedDeltaTime = v;
	return v;
};
haxor.core.Time.get_ms = function() {
	return haxor.core.Time.m_ms_func() * haxor.core.Time.m_ms_convert;
};
haxor.core.Time.Initialize = function() {
	haxor.core.Time.scale = 1;
	haxor.core.Time.m_frameDeltaTime = 0;
	haxor.core.Time.m_elapsed = 0;
	haxor.core.Time.frame = 0;
	haxor.core.Time.fps = 0;
	haxor.core.Time.m_fpsCounter = 0;
	haxor.core.Time.m_fpsElapsed = 0;
	haxor.core.Time.m_simulationTimeSlice = 0;
	haxor.core.Time.m_clock = -1;
	haxor.core.Time.m_fixedDeltaTime = 0.01;
	haxor.core.Time.m_timeScaleMap = new haxe.ds.StringMap();
	if(($_=window.performance,$bind($_,$_.now)) != null) {
		haxor.core.Time.m_ms_convert = 1.0;
		haxor.core.Time.m_ms_func = ($_=window.performance,$bind($_,$_.now));
	} else {
		haxor.core.Time.m_ms_func = haxe.Timer.stamp;
		haxor.core.Time.m_ms_convert = 0.001;
	}
};
haxor.core.Time.GetTimeScale = function(p_alias) {
	if(!haxor.core.Time.m_timeScaleMap.exists(p_alias)) haxor.core.Time.m_timeScaleMap.set(p_alias,1);
	return haxor.core.Time.m_frameDeltaTime * haxor.core.Time.m_timeScaleMap.get(p_alias) * haxor.core.Time.scale;
};
haxor.core.Time.SetTimeScale = function(p_alias,p_scale) {
	haxor.core.Time.m_timeScaleMap.set(p_alias,p_scale);
};
haxor.core.Time.Update = function() {
	if(haxor.core.Time.m_clock < 0) haxor.core.Time.m_clock = haxor.core.Time.get_ms();
	var dt = (haxor.core.Time.get_ms() - haxor.core.Time.m_clock) * 0.001;
	if(dt >= 0.1) dt = 0.1;
	haxor.core.Time.m_clock = haxor.core.Time.get_ms();
	haxor.core.Time.m_elapsed += dt;
	haxor.core.Time.m_frameDeltaTime = dt;
	haxor.core.Time.m_simulationTimeSlice += dt * haxor.core.Time.scale;
	haxor.core.Time.m_fpsElapsed += dt;
	haxor.core.Time.m_fpsCounter++;
	if(haxor.core.Time.m_fpsElapsed >= 0.5) {
		haxor.core.Time.m_fpsElapsed -= 0.5;
		haxor.core.Time.fps = haxor.core.Time.m_fpsCounter * 2;
		haxor.core.Time.m_fpsCounter = 0;
	}
};
haxor.core.Tween = function(p_target,p_property,p_value,p_duration,p_delay,p_easing) {
	if(p_delay == null) p_delay = 0;
	if(p_duration == null) p_duration = 0.3;
	haxor.core.Resource.call(this);
	if(haxor.core.Tween.m_table == null) haxor.core.Tween.m_table = new haxe.ds.ObjectMap();
	this.m_target = p_target;
	this.m_property = p_property;
	this.m_value = p_value;
	this.m_delay = p_delay;
	if(this.m_delay > 0) this.m_elapsed = -this.m_delay; else this.m_elapsed = 0;
	this.m_duration = p_duration;
	this.m_active = false;
	this.m_added = false;
	if(p_easing == null) this.m_easing = function(v) {
		return v;
	}; else this.m_easing = p_easing;
	if(!haxor.core.Tween.m_table.exists(this.m_target)) haxor.core.Tween.m_table.set(this.m_target,[]);
};
$hxClasses["haxor.core.Tween"] = haxor.core.Tween;
haxor.core.Tween.__name__ = ["haxor","core","Tween"];
haxor.core.Tween.__interfaces__ = [haxor.core.IUpdateable];
haxor.core.Tween.Add = function(p_target,p_property,p_value,p_duration,p_delay,p_easing) {
	if(p_delay == null) p_delay = 0;
	if(p_duration == null) p_duration = 0.3;
	var t = new haxor.core.Tween(p_target,p_property,p_value,p_duration,p_delay,p_easing);
	t.Run();
	return t;
};
haxor.core.Tween.Cancel = function(p_target,p_property) {
	if(p_property == null) p_property = "";
	if(!haxor.core.Tween.m_table.exists(p_target)) return;
	var il = haxor.core.Tween.m_table.get(p_target);
	var _g1 = 0;
	var _g = il.length;
	while(_g1 < _g) {
		var i = _g1++;
		var t = il[i];
		if(p_property != "") {
			if(t.m_property != p_property) continue;
		}
		t.Remove();
	}
};
haxor.core.Tween.GetTweens = function(p_target,p_property,p_active_only) {
	if(p_active_only == null) p_active_only = false;
	if(p_property == null) p_property = "";
	var l = [];
	if(p_target == null) {
		var it = haxor.core.Tween.m_table.iterator();
		while(it.hasNext()) {
			var il = it.next();
			var _g1 = 0;
			var _g = il.length;
			while(_g1 < _g) {
				var i = _g1++;
				l.push(il[i]);
			}
		}
	} else {
		if(!haxor.core.Tween.m_table.exists(p_target)) return [];
		var il1 = haxor.core.Tween.m_table.get(p_target);
		var _g11 = 0;
		var _g2 = il1.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			var t = il1[i1];
			if(p_target != null) {
				if(t.m_target != p_target) continue;
			}
			if(p_property != "") {
				if(t.m_property != p_property) continue;
			}
			if(p_active_only) {
				if(t.m_elapsed < 0) continue;
			}
			l.push(t);
		}
	}
	return l;
};
haxor.core.Tween.__super__ = haxor.core.Resource;
haxor.core.Tween.prototype = $extend(haxor.core.Resource.prototype,{
	Run: function() {
		this.m_active = true;
		if(!this.m_added) {
			haxor.core.Engine.Add(this);
			this.m_added = true;
			haxor.core.Tween.m_table.get(this.m_target).push(this);
		}
	}
	,Pause: function() {
		this.m_active = false;
	}
	,Stop: function() {
		this.m_elapsed = -this.m_delay;
		this.m_active = false;
	}
	,Remove: function() {
		if(this.m_added) {
			haxor.core.Engine.Remove(this);
			this.m_added = false;
		}
		this.m_active = false;
		var l = haxor.core.Tween.m_table.get(this.m_target);
		HxOverrides.remove(l,this);
	}
	,OnUpdate: function() {
		if(!this.m_active) return;
		if(this.m_elapsed <= 0) {
			this.m_elapsed += haxor.core.Time.get_deltaTime();
			if(this.m_elapsed >= 0) {
				var l = haxor.core.Tween.GetTweens(this.m_target,this.m_property,true);
				var _g1 = 0;
				var _g = l.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(l[i] != this) l[i].Remove();
				}
				this.m_start = Reflect.getProperty(this.m_target,this.m_property);
			}
			return;
		}
		var r = haxor.math.Mathf.Clamp01(this.m_duration <= 0?1.0:this.m_elapsed / this.m_duration);
		this.Sample(r);
		this.m_elapsed += haxor.core.Time.get_deltaTime();
		if(this.m_elapsed >= this.m_duration) {
			this.Sample(1.0);
			if(this.oncomplete != null) this.oncomplete();
			this.Remove();
		}
	}
	,Sample: function(p_r) {
		p_r = this.m_easing(p_r);
		if(typeof(this.m_value) == "number") Reflect.setProperty(this.m_target,this.m_property,haxor.math.Mathf.Lerp(this.m_start,this.m_value,p_r)); else if(js.Boot.__instanceof(this.m_value,haxor.math.Color)) Reflect.setProperty(this.m_target,this.m_property,haxor.math.Color.Lerp(this.m_start,this.m_value,p_r)); else if(js.Boot.__instanceof(this.m_value,haxor.math.Quaternion)) Reflect.setProperty(this.m_target,this.m_property,haxor.math.Quaternion.Lerp(this.m_start,this.m_value,p_r)); else if(js.Boot.__instanceof(this.m_value,Int)) Reflect.setProperty(this.m_target,this.m_property,haxor.math.Mathf.LerpInt(this.m_start,this.m_value,p_r)); else if(js.Boot.__instanceof(this.m_value,haxor.math.Vector2)) Reflect.setProperty(this.m_target,this.m_property,haxor.math.Vector2.Lerp(this.m_start,this.m_value,p_r)); else if(js.Boot.__instanceof(this.m_value,haxor.math.Vector3)) Reflect.setProperty(this.m_target,this.m_property,haxor.math.Vector3.Lerp(this.m_start,this.m_value,p_r)); else if(js.Boot.__instanceof(this.m_value,haxor.math.Vector4)) Reflect.setProperty(this.m_target,this.m_property,haxor.math.Vector4.Lerp(this.m_start,this.m_value,p_r));
	}
	,__class__: haxor.core.Tween
});
haxor.core.Vector = function(p_size) {
	if(p_size == null) p_size = 0;
	this.m_count = 0;
	this.m_list = [];
	var _g = 0;
	while(_g < p_size) {
		var i = _g++;
		this.m_list.push(null);
	}
};
$hxClasses["haxor.core.Vector"] = haxor.core.Vector;
haxor.core.Vector.__name__ = ["haxor","core","Vector"];
haxor.core.Vector.prototype = {
	get_count: function() {
		return this.m_count;
	}
	,Add: function(p_item) {
		if(this.m_count >= this.m_list.length) {
			this.m_list.push(p_item);
			this.m_count++;
			return this.m_count - 1;
		}
		this.m_list[this.m_count++] = p_item;
		return this.m_count - 1;
	}
	,IndexOf: function(p_item) {
		var _g1 = 0;
		var _g = this.m_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.m_list[i] == p_item) return i;
		}
		return -1;
	}
	,Remove: function(p_item) {
		var p = this.IndexOf(p_item);
		if(p >= 0) return this.RemoveAt(p);
		return null;
	}
	,Delete: function(p_item) {
		if(HxOverrides.remove(this.m_list,p_item)) {
			this.m_count--;
			return p_item;
		}
		return null;
	}
	,RemoveAt: function(p_index) {
		if(this.m_count <= 0) return null;
		if(p_index >= this.m_count - 1) {
			this.m_count--;
			return null;
		}
		var r = this.m_list[this.m_count - 1];
		this.m_list[p_index] = this.m_list[this.m_count - 1];
		this.m_count--;
		return r;
	}
	,Get: function(p_index) {
		return this.m_list[p_index];
	}
	,Peek: function() {
		if(this.m_count >= this.m_list.length) return null; else return this.m_list[this.m_count];
	}
	,Clear: function() {
		this.m_count = 0;
	}
	,__class__: haxor.core.Vector
	,__properties__: {get_count:"get_count"}
};
haxor.editor = {};
haxor.editor.Gizmo = function() { };
$hxClasses["haxor.editor.Gizmo"] = haxor.editor.Gizmo;
haxor.editor.Gizmo.__name__ = ["haxor","editor","Gizmo"];
haxor.editor.Gizmo.Initialize = function() {
	haxor.editor.Gizmo.m_handlers = [];
	haxor.editor.Gizmo.m_wireframes = new haxe.ds.ObjectMap();
	haxor.editor.Gizmo.selection = [];
	haxor.editor.Gizmo.m_gizmo_point = new haxor.editor.PointGizmo();
	haxor.editor.Gizmo.m_gizmo_line = new haxor.editor.LineGizmo();
	haxor.editor.Gizmo.m_gizmo_transform = new haxor.editor.TransformGizmo();
	haxor.editor.Gizmo.m_gizmo_cube_wire = new haxor.editor.WireCubeGizmo();
	haxor.editor.Gizmo.m_gizmo_sphere_wire = new haxor.editor.WireSphereGizmo();
};
haxor.editor.Gizmo.Render = function() {
	var fp = haxor.component.Camera.current.get_far();
	haxor.component.Camera.current.set_far(200000);
	var _g1 = 0;
	var _g = haxor.editor.Gizmo.m_handlers.length;
	while(_g1 < _g) {
		var i = _g1++;
		haxor.editor.Gizmo.m_handlers[i].OnGizmoRender();
	}
	var _g11 = 0;
	var _g2 = haxor.editor.Gizmo.selection.length;
	while(_g11 < _g2) {
		var i1 = _g11++;
		haxor.editor.Gizmo.RenderEntity(haxor.editor.Gizmo.selection[i1],true);
	}
	haxor.editor.Gizmo.RenderColliders();
	if(haxor.editor.Gizmo.transforms) haxor.editor.Gizmo.RenderTransforms();
	if(haxor.editor.Gizmo.lights) haxor.editor.Gizmo.RenderLights();
	if(haxor.editor.Gizmo.meshes) haxor.editor.Gizmo.RenderMeshes();
	if(haxor.editor.Gizmo.particles) haxor.editor.Gizmo.RenderParticles();
	haxor.component.Camera.current.set_far(fp);
};
haxor.editor.Gizmo.RenderMeshes = function() {
	var l = haxor.component.MeshRenderer.get_list();
	var _g1 = 0;
	var _g = l.length;
	while(_g1 < _g) {
		var i = _g1++;
		var mr = l[i];
		if(mr.get_mesh() == null) continue;
		if(mr.visible) haxor.editor.Gizmo.m_color_mesh.a = 1.0; else haxor.editor.Gizmo.m_color_mesh.a = 0.0;
		var mb = mr.get_mesh().get_bounds();
		haxor.editor.Gizmo.WireCube(mb.get_center(),mb.get_size(),haxor.editor.Gizmo.m_color_mesh,mr.get_transform());
	}
};
haxor.editor.Gizmo.RenderParticles = function() {
	var l = haxor.component.MeshRenderer.get_list();
	var _g1 = 0;
	var _g = l.length;
	while(_g1 < _g) {
		var i = _g1++;
		var mr = l[i];
		if(mr.get_mesh() == null) continue;
		if(!js.Boot.__instanceof(mr,haxor.component.ParticleRenderer)) continue;
		var pr = mr;
		if(mr.visible) haxor.editor.Gizmo.m_color_particle.a = 1.0; else haxor.editor.Gizmo.m_color_particle.a = 0.0;
		var pe = pr.emitter;
		if(js.Boot.__instanceof(pe,haxor.component.SphereEmitter)) {
			var e = pe;
			haxor.editor.Gizmo.WireSphere(haxor.math.Vector3.get_zero(),e.get_radius(),haxor.editor.Gizmo.m_color_particle,pr.get_transform());
		}
		if(js.Boot.__instanceof(pe,haxor.component.BoxEmitter)) {
			var e1 = pe;
			haxor.editor.Gizmo.WireCube(haxor.math.Vector3.get_zero(),new haxor.math.Vector3(e1.get_width(),e1.get_height(),e1.get_depth()),haxor.editor.Gizmo.m_color_particle,pr.get_transform());
		}
		if(js.Boot.__instanceof(pe,haxor.component.ConeEmitter)) {
		}
		if(js.Boot.__instanceof(pe,haxor.component.CylinderEmitter)) {
		}
	}
};
haxor.editor.Gizmo.RenderColliders = function() {
	var l = haxor.physics.Collider.get_list();
	var _g1 = 0;
	var _g = l.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(haxor.editor.Gizmo.colliders) haxor.editor.Gizmo.RenderCollider(l[i]);
		if(haxor.editor.Gizmo.sphereBounds) haxor.editor.Gizmo.RenderSphereBound(l[i]);
		if(haxor.editor.Gizmo.AABBBounds) haxor.editor.Gizmo.RenderAABBBound(l[i]);
	}
};
haxor.editor.Gizmo.RenderLights = function() {
	var l = haxor.component.Light.m_list;
	var _g1 = 0;
	var _g = l.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(js.Boot.__instanceof(l[i],haxor.component.PointLight)) {
			var pl = l[i];
			var p = pl.get_transform().get_WorldMatrix().Transform3x4(haxor.math.Vector3.get_zero());
			if(pl.get_enabled()) haxor.editor.Gizmo.m_color_light.a = 1.0; else haxor.editor.Gizmo.m_color_light.a = 0.2;
			haxor.editor.Gizmo.WireSphere(p,pl.radius,haxor.editor.Gizmo.m_color_light);
		}
	}
};
haxor.editor.Gizmo.RenderSphereBound = function(c) {
	var b = c.get_boundSphere();
	haxor.editor.Gizmo.WireSphere(haxor.math.Vector3.get_temp().Set(b.x,b.y,b.z),b.w,haxor.editor.Gizmo.m_color_bounds);
};
haxor.editor.Gizmo.RenderAABBBound = function(c) {
	var b = c.get_boundAABB();
	haxor.editor.Gizmo.WireCube(b.get_center(),b.get_size(),haxor.editor.Gizmo.m_color_bounds);
};
haxor.editor.Gizmo.RenderTransforms = function() {
	var l = haxor.component.Transform.m_list;
	var _g1 = 0;
	var _g = l.length;
	while(_g1 < _g) {
		var i = _g1++;
		haxor.editor.Gizmo.WireAxis(l[i]);
	}
};
haxor.editor.Gizmo.RenderEntity = function(e,all) {
	if(all == null) all = false;
	var cl = e.GetComponents(haxor.component.Component);
	var _g1 = 0;
	var _g = cl.length;
	while(_g1 < _g) {
		var i = _g1++;
		haxor.editor.Gizmo.RenderComponent(cl[i]);
	}
	if(all) e.get_transform().Traverse(function(it) {
		haxor.editor.Gizmo.RenderEntity(it.get_entity(),false);
		return true;
	});
};
haxor.editor.Gizmo.RenderComponent = function(c) {
	if(js.Boot.__instanceof(c,haxor.physics.Collider)) haxor.editor.Gizmo.RenderCollider(c); else if(js.Boot.__instanceof(c,haxor.component.Transform)) haxor.editor.Gizmo.WireAxis(c);
};
haxor.editor.Gizmo.RenderCollider = function(c) {
	if(js.Boot.__instanceof(c,haxor.physics.BoxCollider)) haxor.editor.Gizmo.RenderBoxCollider(c); else if(js.Boot.__instanceof(c,haxor.physics.SphereCollider)) haxor.editor.Gizmo.RenderSphereCollider(c);
};
haxor.editor.Gizmo.RenderBoxCollider = function(c) {
	var cl;
	if(c.trigger) cl = haxor.editor.Gizmo.m_color_trigger; else cl = haxor.editor.Gizmo.m_color_collider;
	if(c.get_enabled()) cl.a = 1.0; else cl.a = 0.2;
	haxor.editor.Gizmo.WireCube(c.get_center(),c.get_size(),cl,c.get_transform());
};
haxor.editor.Gizmo.RenderSphereCollider = function(c) {
	var cl;
	if(c.trigger) cl = haxor.editor.Gizmo.m_color_trigger; else cl = haxor.editor.Gizmo.m_color_collider;
	if(c.get_enabled()) cl.a = 1.0; else cl.a = 0.2;
	if(c.get_enabled()) cl.a = 1.0; else cl.a = 0.2;
	haxor.editor.Gizmo.WireSphere(c.get_center(),c.get_radius(),cl,c.get_transform());
};
haxor.editor.Gizmo.WireAxis = function(p_transform,p_size) {
	var s = 0.025;
	haxor.editor.Gizmo.m_gizmo_transform.size.Set(p_size == null?s:p_size.x,p_size == null?s:p_size.y,p_size == null?s:p_size.z);
	haxor.editor.Gizmo.m_gizmo_transform.Render(p_transform,null);
};
haxor.editor.Gizmo.WireCube = function(p_center,p_size,p_color,p_cs) {
	haxor.editor.Gizmo.m_gizmo_cube_wire.center.Set(p_center.x,p_center.y,p_center.z);
	haxor.editor.Gizmo.m_gizmo_cube_wire.size.Set(p_size.x,p_size.y,p_size.z);
	haxor.editor.Gizmo.m_gizmo_cube_wire.Render(p_cs,p_color);
};
haxor.editor.Gizmo.WireSphere = function(p_center,p_radius,p_color,p_cs) {
	haxor.editor.Gizmo.m_gizmo_sphere_wire.center.Set(p_center.x,p_center.y,p_center.z);
	haxor.editor.Gizmo.m_gizmo_sphere_wire.radius = p_radius;
	haxor.editor.Gizmo.m_gizmo_sphere_wire.Render(p_cs,p_color);
};
haxor.editor.Gizmo.Point = function(p_position,p_radius,p_color,p_cs) {
	if(p_radius == null) p_radius = 1.0;
	haxor.editor.Gizmo.m_gizmo_point.center.Set(p_position.x,p_position.y,p_position.z);
	haxor.editor.Gizmo.m_gizmo_point.radius = p_radius;
	haxor.editor.Gizmo.m_gizmo_point.Render(p_cs,p_color);
};
haxor.editor.Gizmo.Line = function(p_from,p_to,p_color,p_cs) {
	haxor.editor.Gizmo.m_gizmo_line.p0.Set(p_from.x,p_from.y,p_from.z);
	haxor.editor.Gizmo.m_gizmo_line.p1.Set(p_to.x,p_to.y,p_to.z);
	haxor.editor.Gizmo.m_gizmo_line.Render(p_cs,p_color);
};
haxor.editor.GizmoRenderer = function() {
	this.type = -1;
	this.material = new haxor.graphics.Material();
	this.material.set_name("$Material" + Type.getClassName(Type.getClass(this)));
	this.material.blend = true;
	this.material.cull = haxor.graphics.CullMode.None;
	this.material.blendSrc = haxor.graphics.BlendMode.SrcAlpha;
	this.material.blendDst = haxor.graphics.BlendMode.OneMinusSrcAlpha;
	this.material.ztest = false;
	this.color = haxor.math.Color.get_white();
	this.transform = haxor.component.Transform.get_root();
};
$hxClasses["haxor.editor.GizmoRenderer"] = haxor.editor.GizmoRenderer;
haxor.editor.GizmoRenderer.__name__ = ["haxor","editor","GizmoRenderer"];
haxor.editor.GizmoRenderer.prototype = {
	Render: function(p_cs,p_color) {
		if(this.material.get_shader() == null) {
			this.material.set_shader(haxor.core.Asset.Get("haxor/internal/Gizmo"));
			return;
		}
		if(p_cs == null) this.transform = haxor.component.Transform.get_root(); else this.transform = p_cs;
		if(p_color == null) this.color = this.color.Set(1,1,1,1); else this.color = this.color.Set(p_color.r,p_color.g,p_color.b,p_color.a);
		this.material.SetUniform("Type",this.type + 0.00001);
		this.material.SetUniform("Tint",this.color);
		this.OnRender();
		haxor.api.MaterialAPI.m_current = null;
	}
	,OnRender: function() {
	}
	,__class__: haxor.editor.GizmoRenderer
};
haxor.editor.PointGizmo = function() {
	haxor.editor.GizmoRenderer.call(this);
	this.type = haxor.editor.Gizmo.GIZMO_POINT;
	this.center = haxor.math.Vector3.get_zero();
	this.radius = 1.0;
	this.m_mesh = new haxor.graphics.Mesh3();
	this.m_mesh.set_name("$PointMesh");
	this.m_mesh.set_primitive(haxor.graphics.MeshPrimitive.Points);
	var p = [haxor.math.Vector3.get_zero()];
	this.m_mesh.set_vertex(p);
	this.m_mesh.set_color([haxor.math.Color.get_white()]);
};
$hxClasses["haxor.editor.PointGizmo"] = haxor.editor.PointGizmo;
haxor.editor.PointGizmo.__name__ = ["haxor","editor","PointGizmo"];
haxor.editor.PointGizmo.__super__ = haxor.editor.GizmoRenderer;
haxor.editor.PointGizmo.prototype = $extend(haxor.editor.GizmoRenderer.prototype,{
	OnRender: function() {
		this.material.SetUniform("Center",this.center);
		this.material.SetUniform("Radius",this.radius + 0.00000001);
		haxor.graphics.Graphics.Render(haxor.component.Camera.current,this.transform,this.m_mesh,this.material);
	}
	,__class__: haxor.editor.PointGizmo
});
haxor.editor.LineGizmo = function() {
	haxor.editor.GizmoRenderer.call(this);
	this.type = haxor.editor.Gizmo.GIZMO_LINE;
	this.p0 = haxor.math.Vector3.get_zero();
	this.p1 = haxor.math.Vector3.get_zero();
	this.m_mesh = new haxor.graphics.Mesh3();
	this.m_mesh.set_name("$LineMesh");
	this.m_mesh.set_primitive(haxor.graphics.MeshPrimitive.Lines);
	var p = [haxor.math.Vector3.get_zero(),haxor.math.Vector3.get_one()];
	this.m_mesh.set_vertex(p);
	this.m_mesh.set_color([haxor.math.Color.get_white(),haxor.math.Color.get_white()]);
};
$hxClasses["haxor.editor.LineGizmo"] = haxor.editor.LineGizmo;
haxor.editor.LineGizmo.__name__ = ["haxor","editor","LineGizmo"];
haxor.editor.LineGizmo.__super__ = haxor.editor.GizmoRenderer;
haxor.editor.LineGizmo.prototype = $extend(haxor.editor.GizmoRenderer.prototype,{
	OnRender: function() {
		this.material.SetUniform("P0",this.p0);
		this.material.SetUniform("P1",this.p1);
		haxor.graphics.Graphics.Render(haxor.component.Camera.current,this.transform,this.m_mesh,this.material);
	}
	,__class__: haxor.editor.LineGizmo
});
haxor.editor.WireCubeGizmo = function() {
	haxor.editor.GizmoRenderer.call(this);
	this.type = haxor.editor.Gizmo.GIZMO_BOX;
	this.center = haxor.math.Vector3.get_zero();
	this.size = haxor.math.Vector3.get_one();
	this.m_mesh = new haxor.graphics.Mesh3();
	this.m_mesh.set_name("$WireCubeMesh");
	this.m_mesh.set_primitive(haxor.graphics.MeshPrimitive.Lines);
	var a = -0.5;
	var b = 0.5;
	var p_0 = new haxor.math.Vector3(a,a,a);
	var p_1 = new haxor.math.Vector3(a,a,b);
	var p_2 = new haxor.math.Vector3(b,a,b);
	var p_3 = new haxor.math.Vector3(b,a,a);
	var p_4 = new haxor.math.Vector3(a,b,a);
	var p_5 = new haxor.math.Vector3(a,b,b);
	var p_6 = new haxor.math.Vector3(b,b,b);
	var p_7 = new haxor.math.Vector3(b,b,a);
	this.m_mesh.set_vertex([p_0,p_1,p_1,p_2,p_2,p_3,p_3,p_0,p_4,p_5,p_5,p_6,p_6,p_7,p_7,p_4,p_0,p_1,p_1,p_5,p_5,p_4,p_4,p_0,p_3,p_2,p_2,p_6,p_6,p_7,p_7,p_3,p_0,p_3,p_3,p_7,p_7,p_4,p_4,p_0,p_1,p_5,p_5,p_6,p_6,p_2,p_2,p_1]);
	var cl = [];
	var _g1 = 0;
	var _g = this.m_mesh.get_vertexCount();
	while(_g1 < _g) {
		var i = _g1++;
		cl.push(haxor.math.Color.get_white());
	}
	this.m_mesh.set_color(cl);
};
$hxClasses["haxor.editor.WireCubeGizmo"] = haxor.editor.WireCubeGizmo;
haxor.editor.WireCubeGizmo.__name__ = ["haxor","editor","WireCubeGizmo"];
haxor.editor.WireCubeGizmo.__super__ = haxor.editor.GizmoRenderer;
haxor.editor.WireCubeGizmo.prototype = $extend(haxor.editor.GizmoRenderer.prototype,{
	OnRender: function() {
		this.material.SetUniform("Center",this.center);
		this.material.SetUniform("Size",this.size);
		haxor.graphics.Graphics.Render(haxor.component.Camera.current,this.transform,this.m_mesh,this.material);
	}
	,__class__: haxor.editor.WireCubeGizmo
});
haxor.editor.WireSphereGizmo = function() {
	haxor.editor.GizmoRenderer.call(this);
	this.type = haxor.editor.Gizmo.GIZMO_SPHERE;
	this.center = haxor.math.Vector3.get_zero();
	this.radius = 1.0;
	this.m_mesh = new haxor.graphics.Mesh3();
	this.m_mesh.set_name("$WireSphereMesh");
	this.m_mesh.set_primitive(haxor.graphics.MeshPrimitive.Lines);
	var r = this.radius;
	var v;
	var steps = 720;
	var p = [];
	var _g = 0;
	while(_g < steps) {
		var i = _g++;
		var astp = 1.0 / (steps - 1);
		var a;
		a = 360 * i * astp;
		var sv0 = haxor.math.Mathf.Sin(a * haxor.math.Mathf.Deg2Rad) * r * 0.5;
		var cv0 = haxor.math.Mathf.Cos(a * haxor.math.Mathf.Deg2Rad) * r * 0.5;
		a = 360 * (i + 1) * astp;
		var sv1 = haxor.math.Mathf.Sin(a * haxor.math.Mathf.Deg2Rad) * r * 0.5;
		var cv1 = haxor.math.Mathf.Cos(a * haxor.math.Mathf.Deg2Rad) * r * 0.5;
		var v0;
		var v1;
		v0 = new haxor.math.Vector3(cv0,0.0,sv0);
		v1 = new haxor.math.Vector3(cv1,0.0,sv1);
		p.push(v0);
		p.push(v1);
		v0 = new haxor.math.Vector3(0.0,cv0,sv0);
		v1 = new haxor.math.Vector3(0.0,cv1,sv1);
		p.push(v0);
		p.push(v1);
		v0 = new haxor.math.Vector3(cv0,sv0,0.0);
		v1 = new haxor.math.Vector3(cv1,sv1,0.0);
		p.push(v0);
		p.push(v1);
	}
	this.m_mesh.set_vertex(p);
	var cl = [];
	var _g1 = 0;
	var _g2 = this.m_mesh.get_vertexCount();
	while(_g1 < _g2) {
		var i1 = _g1++;
		cl.push(haxor.math.Color.get_white());
	}
	this.m_mesh.set_color(cl);
};
$hxClasses["haxor.editor.WireSphereGizmo"] = haxor.editor.WireSphereGizmo;
haxor.editor.WireSphereGizmo.__name__ = ["haxor","editor","WireSphereGizmo"];
haxor.editor.WireSphereGizmo.__super__ = haxor.editor.GizmoRenderer;
haxor.editor.WireSphereGizmo.prototype = $extend(haxor.editor.GizmoRenderer.prototype,{
	OnRender: function() {
		this.material.SetUniform("Radius",this.radius + 0.00000001);
		this.material.SetUniform("Center",this.center);
		haxor.graphics.Graphics.Render(haxor.component.Camera.current,this.transform,this.m_mesh,this.material);
	}
	,__class__: haxor.editor.WireSphereGizmo
});
haxor.editor.TransformGizmo = function() {
	haxor.editor.GizmoRenderer.call(this);
	this.type = haxor.editor.Gizmo.GIZMO_TRANSFORM;
	this.size = haxor.math.Vector3.get_one();
	this.m_mesh = new haxor.graphics.Mesh3();
	this.m_mesh.set_name("$TransformMesh");
	this.m_mesh.set_primitive(haxor.graphics.MeshPrimitive.Lines);
	this.m_mesh.set_vertex([new haxor.math.Vector3(0,0,0),new haxor.math.Vector3(1,0,0),new haxor.math.Vector3(0,0,0),new haxor.math.Vector3(0,1,0),new haxor.math.Vector3(0,0,0),new haxor.math.Vector3(0,0,1)]);
	this.m_mesh.set_color([haxor.editor.Gizmo.m_color_x,haxor.editor.Gizmo.m_color_x,haxor.editor.Gizmo.m_color_y,haxor.editor.Gizmo.m_color_y,haxor.editor.Gizmo.m_color_z,haxor.editor.Gizmo.m_color_z]);
};
$hxClasses["haxor.editor.TransformGizmo"] = haxor.editor.TransformGizmo;
haxor.editor.TransformGizmo.__name__ = ["haxor","editor","TransformGizmo"];
haxor.editor.TransformGizmo.__super__ = haxor.editor.GizmoRenderer;
haxor.editor.TransformGizmo.prototype = $extend(haxor.editor.GizmoRenderer.prototype,{
	OnRender: function() {
		this.material.SetUniform("Size",this.size);
		haxor.graphics.Graphics.Render(haxor.component.Camera.current,this.transform,this.m_mesh,this.material);
	}
	,__class__: haxor.editor.TransformGizmo
});
haxor.editor.MeshGizmo = function() {
	this.m = new haxor.graphics.Mesh3();
	this.m.set_name("$MeshGizmoMesh");
	this.m.set_primitive(haxor.graphics.MeshPrimitive.Lines);
	this.cx = 0.0;
	this.cy = 0.0;
	this.cz = 0.0;
	this.fc = new haxor.math.Color(1,1,1,1);
	this.Resize(1.0,1.0,1.0);
};
$hxClasses["haxor.editor.MeshGizmo"] = haxor.editor.MeshGizmo;
haxor.editor.MeshGizmo.__name__ = ["haxor","editor","MeshGizmo"];
haxor.editor.MeshGizmo.prototype = {
	Resize: function(x,y,z) {
		if(haxor.math.Mathf.Abs(x - this.cx) < 0.001) {
			if(haxor.math.Mathf.Abs(y - this.cy) < 0.001) {
				if(haxor.math.Mathf.Abs(z - this.cz) < 0.001) return;
			}
		}
		this.cx = x;
		this.cy = y;
		this.cz = z;
		var a = -0.5;
		var b = 0.5;
		this.p = [new haxor.math.Vector3(a * x,a * y,a * z),new haxor.math.Vector3(a * x,a * y,b * z),new haxor.math.Vector3(b * x,a * y,b * z),new haxor.math.Vector3(b * x,a * y,a * z),new haxor.math.Vector3(a * x,b * y,a * z),new haxor.math.Vector3(a * x,b * y,b * z),new haxor.math.Vector3(b * x,b * y,b * z),new haxor.math.Vector3(b * x,b * y,a * z)];
		this.m.set_vertex([this.p[0],this.p[1],this.p[1],this.p[2],this.p[2],this.p[3],this.p[3],this.p[0],this.p[4],this.p[5],this.p[5],this.p[6],this.p[6],this.p[7],this.p[7],this.p[4],this.p[0],this.p[1],this.p[1],this.p[5],this.p[5],this.p[4],this.p[4],this.p[0],this.p[3],this.p[2],this.p[2],this.p[6],this.p[6],this.p[7],this.p[7],this.p[3],this.p[0],this.p[3],this.p[3],this.p[7],this.p[7],this.p[4],this.p[4],this.p[0],this.p[1],this.p[5],this.p[5],this.p[6],this.p[6],this.p[2],this.p[2],this.p[1]]);
		var c = haxor.editor.Gizmo.m_color_mesh;
		var cl = [];
		var _g1 = 0;
		var _g = this.m.get_vertexCount();
		while(_g1 < _g) {
			var i = _g1++;
			cl.push(c);
		}
		this.m.set_color(cl);
		var uv = haxor.math.Vector3.get_up().Invert();
		var dv = uv.get_inverse();
		var fv = haxor.math.Vector3.get_forward().Invert();
		var bv = fv.get_inverse();
		var rv = haxor.math.Vector3.get_right();
		var lv = rv.get_inverse();
		this.m.set_normal([uv,uv,uv,uv,uv,uv,uv,uv,dv,dv,dv,dv,dv,dv,dv,dv,lv,lv,lv,lv,lv,lv,lv,lv,rv,rv,rv,rv,rv,rv,rv,rv,fv,fv,fv,fv,fv,fv,fv,fv,bv,bv,bv,bv,bv,bv,bv,bv]);
	}
	,Render: function(c) {
		var b = c.get_mesh().m_bounds;
		var gm = null;
		gm.SetUniform("Size",b.get_size());
		gm.SetUniform("Center",b.get_center());
		gm.SetUniform("Tint",this.fc);
		haxor.graphics.Graphics.Render(haxor.component.Camera.current,c.get_transform(),this.m,gm);
		haxor.api.MaterialAPI.m_current = null;
	}
	,__class__: haxor.editor.MeshGizmo
};
haxor.editor.IGizmoRenderer = function() { };
$hxClasses["haxor.editor.IGizmoRenderer"] = haxor.editor.IGizmoRenderer;
haxor.editor.IGizmoRenderer.__name__ = ["haxor","editor","IGizmoRenderer"];
haxor.editor.IGizmoRenderer.prototype = {
	__class__: haxor.editor.IGizmoRenderer
};
haxor.graphics = {};
haxor.graphics.BlendMode = function() { };
$hxClasses["haxor.graphics.BlendMode"] = haxor.graphics.BlendMode;
haxor.graphics.BlendMode.__name__ = ["haxor","graphics","BlendMode"];
haxor.graphics.CullMode = function() { };
$hxClasses["haxor.graphics.CullMode"] = haxor.graphics.CullMode;
haxor.graphics.CullMode.__name__ = ["haxor","graphics","CullMode"];
haxor.graphics.DepthTest = function() { };
$hxClasses["haxor.graphics.DepthTest"] = haxor.graphics.DepthTest;
haxor.graphics.DepthTest.__name__ = ["haxor","graphics","DepthTest"];
haxor.graphics.Graphics = function() { };
$hxClasses["haxor.graphics.Graphics"] = haxor.graphics.Graphics;
haxor.graphics.Graphics.__name__ = ["haxor","graphics","Graphics"];
haxor.graphics.Graphics.__properties__ = {get_c3d:"get_c3d",get_c2d:"get_c2d"}
haxor.graphics.Graphics.get_c2d = function() {
	return haxor.graphics.Graphics.g2;
};
haxor.graphics.Graphics.get_c3d = function() {
	return haxor.graphics.Graphics.g3;
};
haxor.graphics.Graphics.Initialize = function(p_canvas) {
	var success = true;
	var mode;
	if(p_canvas.getAttribute("mode") == null) mode = ""; else mode = p_canvas.getAttribute("mode").toLowerCase();
	var attrib3 = { };
	console.log("Haxor> Canvas [" + p_canvas.id + "] Config");
	var attrib3_list = ["alpha","antialias","depth","stencil","premultipliedAlpha","preserveDrawingBuffer"];
	var attrib3_default = [false,true,true,false,true,false];
	var _g1 = 0;
	var _g = attrib3_list.length;
	while(_g1 < _g) {
		var i = _g1++;
		var a = attrib3_list[i];
		var ca = p_canvas.getAttribute(attrib3_list[i]);
		var flag;
		if(ca == null) flag = attrib3_default[i]; else flag = ca == "true";
		console.log("\t" + attrib3_list[i] + ": " + (flag == null?"null":"" + flag));
		attrib3[a]=flag;
	}
	try {
		haxor.graphics.Graphics.c = p_canvas;
		haxor.graphics.Graphics.c.width = haxor.graphics.Graphics.c.clientWidth;
		haxor.graphics.Graphics.c.height = haxor.graphics.Graphics.c.clientHeight;
		if(mode == "3d") {
			var attribs = attrib3;
			haxor.graphics.Graphics.g3 = js.html._CanvasElement.CanvasUtil.getContextWebGL(haxor.graphics.Graphics.c,attribs);
		} else if(mode == "2d") haxor.graphics.Graphics.g2 = haxor.graphics.Graphics.c.getContext("2d");
	} catch( e ) {
	}
	if(mode == "3d") {
		if(haxor.graphics.Graphics.g3 == null) {
			success = false;
			if(haxor.core.Console.get__console() != null) haxor.core.Console.get__console().error("Haxor> GL class could not initialise Rendering Context 3D.");
		}
	}
	if(mode == "2d") {
		if(haxor.graphics.Graphics.g2 == null) {
			success = false;
			if(haxor.core.Console.get__console() != null) haxor.core.Console.get__console().error("Haxor> GL class could not initialise Rendering Context 2D.");
		}
	}
	if(success) {
		console.log("Haxor> Graphics wrapper initialized in mode [" + mode + "]");
		if(mode == "3d") {
			haxor.api.TextureAPI.Initialize(haxor.graphics.Graphics.g3);
			haxor.api.ShaderAPI.Initialize(haxor.graphics.Graphics.g3);
			haxor.api.BufferAPI.Initialize(haxor.graphics.Graphics.g3);
			haxor.api.MaterialAPI.Initialize(haxor.graphics.Graphics.g3);
			console.log("Haxor> WebGL extensions:");
			var extensions;
			if(haxor.graphics.Graphics.g3 == null) extensions = []; else extensions = haxor.graphics.Graphics.g3.getSupportedExtensions();
			var _g11 = 0;
			var _g2 = extensions.length;
			while(_g11 < _g2) {
				var i1 = _g11++;
				if(extensions[i1].indexOf("MOZ_") >= 0) continue;
				var ext = haxor.graphics.Graphics.g3.getExtension(extensions[i1]);
				console.log("\t" + extensions[i1]);
				var _g21 = extensions[i1];
				switch(_g21) {
				case "OES_texture_half_float":
					haxor.api.TextureAPI.HALF_FLOAT_OES = 36193;
					break;
				case "OES_texture_half_float_linear":
					haxor.api.TextureAPI.HALF_FLOAT_LINEAR = true;
					break;
				case "EXT_texture_filter_anisotropic":case "WEBKIT_EXT_texture_filter_anisotropic":
					haxor.api.TextureAPI.TEXTURE_MAX_ANISOTROPY_EXT = ext.TEXTURE_MAX_ANISOTROPY_EXT;
					console.log("\t\tMAX_TEXTURE_MAX_ANISOTROPY: " + Std.string(haxor.graphics.Graphics.g3.getParameter(ext.MAX_TEXTURE_MAX_ANISOTROPY_EXT)));
					break;
				case "OES_texture_float":
					haxor.api.TextureAPI.TEXTURE_FLOAT = true;
					break;
				case "WEBGL_depth_texture":
					haxor.api.TextureAPI.TEXTURE_DEPTH = true;
					break;
				}
			}
		}
	}
	return success;
};
haxor.graphics.Graphics.ClearBuffer = function(p_r,p_g,p_b,p_a,p_depth) {
	if(p_depth == null) p_depth = 1;
	haxor.graphics.Graphics.g3.clearDepth(p_depth);
	haxor.graphics.Graphics.g3.clearColor(p_r,p_g,p_b,p_a);
	haxor.graphics.Graphics.g3.clear(16640);
};
haxor.graphics.Graphics.Viewport = function(p_x,p_y,p_width,p_height) {
	var vpx = p_x;
	var vpy = p_y;
	var vpw = p_width;
	var vph = p_height;
	if(vpx != haxor.graphics.Graphics.m_vpx) haxor.graphics.Graphics.g3.viewport(haxor.graphics.Graphics.m_vpx = vpx,haxor.graphics.Graphics.m_vpy = vpy,haxor.graphics.Graphics.m_vpw = vpw,haxor.graphics.Graphics.m_vph = vph); else if(vpy != haxor.graphics.Graphics.m_vpy) haxor.graphics.Graphics.g3.viewport(haxor.graphics.Graphics.m_vpx = vpx,haxor.graphics.Graphics.m_vpy = vpy,haxor.graphics.Graphics.m_vpw = vpw,haxor.graphics.Graphics.m_vph = vph); else if(vpw != haxor.graphics.Graphics.m_vpw) haxor.graphics.Graphics.g3.viewport(haxor.graphics.Graphics.m_vpx = vpx,haxor.graphics.Graphics.m_vpy = vpy,haxor.graphics.Graphics.m_vpw = vpw,haxor.graphics.Graphics.m_vph = vph); else if(vph != haxor.graphics.Graphics.m_vph) haxor.graphics.Graphics.g3.viewport(haxor.graphics.Graphics.m_vpx = vpx,haxor.graphics.Graphics.m_vpy = vpy,haxor.graphics.Graphics.m_vpw = vpw,haxor.graphics.Graphics.m_vph = vph);
};
haxor.graphics.Graphics.ClearDepth = function() {
	haxor.graphics.Graphics.g3.clearDepth(1.0);
	haxor.graphics.Graphics.g3.clear(256);
};
haxor.graphics.Graphics.Clear = function(p_camera) {
	var c = p_camera;
	var vp = p_camera.m_pixelViewport;
	haxor.graphics.Graphics.Viewport(vp.get_x(),vp.get_y(),vp.get_width(),vp.get_height());
	if(c.clear != haxor.component.ClearFlag.None) {
		var flag = 0;
		if((c.clear & haxor.component.ClearFlag.Color) != 0) flag |= 16384;
		if((c.clear & haxor.component.ClearFlag.Skybox) != 0) flag |= 16384;
		if((c.clear & haxor.component.ClearFlag.Depth) != 0) flag |= 256;
		haxor.graphics.Graphics.g3.clearDepth(1.0);
		haxor.graphics.Graphics.g3.clearColor(c.background.r,c.background.g,c.background.b,c.background.a);
		haxor.graphics.Graphics.g3.clear(flag);
		if((c.clear & haxor.component.ClearFlag.Skybox) != 0) {
			if(p_camera.skybox != null) {
				haxor.graphics.Material.get_skybox().SetUniform("SkyboxTexture",p_camera.skybox);
				haxor.graphics.Material.get_skybox().SetUniform("SkyboxProjectionMatrixInverse",p_camera.m_skyboxProjectionInverse);
				haxor.graphics.Graphics.Render(p_camera,null,haxor.api.BufferAPI.get_skybox(),haxor.graphics.Material.get_skybox());
			}
		}
	}
};
haxor.graphics.Graphics.Flush = function() {
	haxor.api.BufferAPI.m_current = null;
	haxor.api.MaterialAPI.m_camera = null;
	haxor.api.MaterialAPI.m_transform = null;
	haxor.graphics.Graphics.g3.flush();
};
haxor.graphics.Graphics.Blit = function(p_source,p_destination,p_material) {
	haxor.api.TextureAPI.BindRT(p_destination);
	var m;
	if(p_material == null) m = haxor.graphics.Material.get_blit(); else m = p_material;
	var w;
	if(p_destination == null) w = haxor.graphics.Screen.get_width(); else w = p_destination.get_width();
	var h;
	if(p_destination == null) h = haxor.graphics.Screen.get_height(); else h = p_destination.get_height();
	haxor.graphics.Graphics.Viewport(0,0,w,h);
	m.SetUniform("Texture",p_source);
	haxor.graphics.Graphics.Render(null,null,haxor.api.BufferAPI.get_screen(),m);
	if(haxor.graphics.Material.get_blit() == haxor.api.MaterialAPI.m_current) haxor.api.MaterialAPI.m_current = null;
};
haxor.graphics.Graphics.Render = function(p_camera,p_transform,p_mesh,p_material) {
	var m;
	if(p_material == null) m = haxor.graphics.Material.get_error(); else m = p_material;
	var s;
	if(m.get_shader().get_hasError()) s = haxor.graphics.Material.get_error().get_shader(); else s = m.get_shader();
	var t;
	if(p_transform == null) t = haxor.component.Transform.get_root(); else t = p_transform;
	haxor.api.ShaderAPI.Bind(s);
	haxor.api.MaterialAPI.Bind(m);
	haxor.api.MaterialAPI.SetLights(t,m,p_mesh);
	haxor.api.MaterialAPI.SetUniforms(p_camera,t,m);
	haxor.api.BufferAPI.Bind(p_mesh,s.get_gid());
	haxor.api.BufferAPI.Draw(p_mesh);
	if(haxor.api.MaterialAPI.m_current != m) {
		haxor.api.MaterialAPI.m_camera = null;
		haxor.api.MaterialAPI.m_transform = null;
	}
	haxor.api.MaterialAPI.m_current = m;
};
haxor.graphics.Graphics.RenderTexture = function(p_texture,p_x,p_y,p_width,p_height,p_color) {
	if(p_height == null) p_height = -1;
	if(p_width == null) p_width = -1;
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	if(p_texture == null) return;
	var c;
	if(p_color == null) c = haxor.math.Color.get_white(); else c = p_color;
	var mat = haxor.graphics.Material.get_gui();
	if(mat.get_shader() == null) {
		mat.set_shader(haxor.core.Asset.Get("haxor/internal/GUI"));
		return;
	}
	var tw;
	if(p_width < 0) tw = p_texture.get_width(); else tw = p_width;
	var th;
	if(p_height < 0) th = p_texture.get_height(); else th = p_height;
	mat.SetUniform("Texture",p_texture);
	mat.SetUniform("Position",new haxor.math.Vector2(p_x,p_y));
	mat.SetUniform("Size",new haxor.math.Vector2(tw,th));
	mat.SetUniform("Screen",new haxor.math.Vector2(haxor.graphics.Screen.get_width(),haxor.graphics.Screen.get_height()));
	mat.SetUniform("Color",c);
	haxor.graphics.Graphics.Viewport(0,0,haxor.graphics.Screen.get_width(),haxor.graphics.Screen.get_height());
	haxor.graphics.Graphics.Render(null,null,haxor.api.BufferAPI.get_gui(),mat);
	haxor.api.MaterialAPI.m_current = null;
};
haxor.graphics.Graphics.ReadPixels = function(p_x,p_y,p_width,p_height,p_buffer) {
	haxor.graphics.Graphics.g3.readPixels(p_x,p_y,p_width,p_height,6408,5121,p_buffer);
};
haxor.graphics.Material = function() {
	this.grab = false;
	haxor.core.Resource.call(this);
	this.queue = haxor.graphics.RenderQueue.Geometry;
	this.zfunc = haxor.graphics.DepthTest.LessEqual;
	this.ztest = true;
	this.zwrite = true;
	this.blend = false;
	this.blendSrc = haxor.graphics.BlendMode.One;
	this.blendDst = haxor.graphics.BlendMode.Zero;
	this.invert = false;
	this.lighting = false;
	this.grab = false;
	this.cull = haxor.graphics.CullMode.Back;
	this.m_uniforms = new haxe.ds.StringMap();
	this.m_locations = new haxe.ds.StringMap();
	this.m_changed = new haxe.ds.StringMap();
};
$hxClasses["haxor.graphics.Material"] = haxor.graphics.Material;
haxor.graphics.Material.__name__ = ["haxor","graphics","Material"];
haxor.graphics.Material.__properties__ = {get_skybox:"get_skybox",get_gui:"get_gui",get_blit:"get_blit",get_error:"get_error"}
haxor.graphics.Material.get_error = function() {
	if(haxor.graphics.Material.m_error != null) return haxor.graphics.Material.m_error;
	haxor.graphics.Material.m_error = new haxor.graphics.Material();
	haxor.graphics.Material.m_error.queue = haxor.graphics.RenderQueue.Background;
	haxor.graphics.Material.m_error.cull = haxor.graphics.CullMode.None;
	haxor.graphics.Material.m_error.set_name("$MaterialError");
	haxor.graphics.Material.m_error.set_shader(haxor.graphics.Shader.get_error());
	return haxor.graphics.Material.m_error;
};
haxor.graphics.Material.get_blit = function() {
	if(haxor.graphics.Material.m_blit != null) return haxor.graphics.Material.m_blit;
	haxor.graphics.Material.m_blit = new haxor.graphics.Material();
	haxor.graphics.Material.m_blit.queue = haxor.graphics.RenderQueue.Background;
	haxor.graphics.Material.m_blit.cull = haxor.graphics.CullMode.None;
	haxor.graphics.Material.m_blit.set_name("$MaterialBlit");
	haxor.graphics.Material.m_blit.set_shader(haxor.graphics.Shader.get_blit());
	return haxor.graphics.Material.m_blit;
};
haxor.graphics.Material.get_gui = function() {
	if(haxor.graphics.Material.m_gui != null) return haxor.graphics.Material.m_gui;
	haxor.graphics.Material.m_gui = new haxor.graphics.Material();
	haxor.graphics.Material.m_gui.queue = haxor.graphics.RenderQueue.Background;
	haxor.graphics.Material.m_gui.cull = haxor.graphics.CullMode.None;
	haxor.graphics.Material.m_gui.set_name("$MaterialGUI");
	haxor.graphics.Material.m_gui.ztest = false;
	return haxor.graphics.Material.m_gui;
};
haxor.graphics.Material.get_skybox = function() {
	if(haxor.graphics.Material.m_skybox != null) return haxor.graphics.Material.m_skybox;
	haxor.graphics.Material.m_skybox = new haxor.graphics.Material();
	haxor.graphics.Material.m_skybox.set_name("$SkyboxMaterial");
	haxor.graphics.Material.m_skybox.blend = true;
	haxor.graphics.Material.m_skybox.ztest = false;
	haxor.graphics.Material.m_skybox.zwrite = false;
	haxor.graphics.Material.m_skybox.blendSrc = haxor.graphics.BlendMode.SrcAlpha;
	haxor.graphics.Material.m_skybox.blendDst = haxor.graphics.BlendMode.OneMinusSrcAlpha;
	haxor.graphics.Material.m_skybox.set_shader(haxor.graphics.Shader.get_skybox());
	return haxor.graphics.Material.m_skybox;
};
haxor.graphics.Material.__super__ = haxor.core.Resource;
haxor.graphics.Material.prototype = $extend(haxor.core.Resource.prototype,{
	get_shader: function() {
		return this.m_shader;
	}
	,set_shader: function(v) {
		if(this.m_shader == v) return v;
		this.m_shader = v;
		if(haxor.api.MaterialAPI.m_current == this) haxor.api.MaterialAPI.m_current = null;
		return v;
	}
	,get_uniforms: function() {
		return this.m_uniforms.keys();
	}
	,SetBlending: function(p_src,p_dst) {
		this.blend = !(p_src == haxor.graphics.BlendMode.One && p_dst == haxor.graphics.BlendMode.Zero);
		this.blendSrc = p_src;
		this.blendDst = p_dst;
	}
	,SetUniform: function(p_name,p_value) {
		if(p_value == null) this.m_uniforms.remove(p_name); else {
			var value = p_value;
			this.m_uniforms.set(p_name,value);
			var k;
			if(this.get_shader() == null) k = p_name; else k = p_name + this.get_shader().get_id();
			this.m_changed.set(k,true);
		}
	}
	,GetUniform: function(p_name) {
		return this.m_uniforms.get(p_name);
	}
	,Clone: function() {
		var m = new haxor.graphics.Material();
		m.set_name(this.get_name() + "Copy");
		m.set_shader(this.get_shader());
		m.queue = this.queue;
		m.zfunc = this.zfunc;
		m.ztest = this.ztest;
		m.zwrite = this.zwrite;
		m.blend = this.blend;
		m.blendSrc = this.blendSrc;
		m.blendDst = this.blendDst;
		m.invert = this.invert;
		m.cull = this.cull;
		m.lighting = this.lighting;
		m.grab = this.grab;
		var ul = this.get_uniforms();
		while(ul.hasNext()) {
			var u = ul.next();
			m.SetUniform(u,this.GetUniform(u));
		}
		return m;
	}
	,__class__: haxor.graphics.Material
	,__properties__: $extend(haxor.core.Resource.prototype.__properties__,{get_uniforms:"get_uniforms",set_shader:"set_shader",get_shader:"get_shader"})
});
haxor.graphics.MeshMode = { __ename__ : true, __constructs__ : ["Static","Stream","Dynamic"] };
haxor.graphics.MeshMode.Static = ["Static",0];
haxor.graphics.MeshMode.Static.__enum__ = haxor.graphics.MeshMode;
haxor.graphics.MeshMode.Stream = ["Stream",1];
haxor.graphics.MeshMode.Stream.__enum__ = haxor.graphics.MeshMode;
haxor.graphics.MeshMode.Dynamic = ["Dynamic",2];
haxor.graphics.MeshMode.Dynamic.__enum__ = haxor.graphics.MeshMode;
haxor.graphics.MeshPrimitive = { __ename__ : true, __constructs__ : ["Points","Triangles","TriangleStrip","TriangleFan","Lines","LineLoop","LineStrip"] };
haxor.graphics.MeshPrimitive.Points = ["Points",0];
haxor.graphics.MeshPrimitive.Points.__enum__ = haxor.graphics.MeshPrimitive;
haxor.graphics.MeshPrimitive.Triangles = ["Triangles",1];
haxor.graphics.MeshPrimitive.Triangles.__enum__ = haxor.graphics.MeshPrimitive;
haxor.graphics.MeshPrimitive.TriangleStrip = ["TriangleStrip",2];
haxor.graphics.MeshPrimitive.TriangleStrip.__enum__ = haxor.graphics.MeshPrimitive;
haxor.graphics.MeshPrimitive.TriangleFan = ["TriangleFan",3];
haxor.graphics.MeshPrimitive.TriangleFan.__enum__ = haxor.graphics.MeshPrimitive;
haxor.graphics.MeshPrimitive.Lines = ["Lines",4];
haxor.graphics.MeshPrimitive.Lines.__enum__ = haxor.graphics.MeshPrimitive;
haxor.graphics.MeshPrimitive.LineLoop = ["LineLoop",5];
haxor.graphics.MeshPrimitive.LineLoop.__enum__ = haxor.graphics.MeshPrimitive;
haxor.graphics.MeshPrimitive.LineStrip = ["LineStrip",6];
haxor.graphics.MeshPrimitive.LineStrip.__enum__ = haxor.graphics.MeshPrimitive;
haxor.graphics.Mesh = function() {
	haxor.core.Resource.call(this);
	this.m_buffers = new haxe.ds.StringMap();
	this.m_sizes = new haxe.ds.StringMap();
	this.m_locations = new haxe.ds.StringMap();
	this.m_attribs = [];
	this.m_vertexCount = 0;
	this.m_topology = new Uint16Array([]);
	this.m_primitive = haxor.graphics.MeshPrimitive.Triangles;
	this.m_mode = haxor.graphics.MeshMode.Static;
	this.m_bounds = haxor.math.AABB3.get_empty();
	this.m_indexed = false;
};
$hxClasses["haxor.graphics.Mesh"] = haxor.graphics.Mesh;
haxor.graphics.Mesh.__name__ = ["haxor","graphics","Mesh"];
haxor.graphics.Mesh.__super__ = haxor.core.Resource;
haxor.graphics.Mesh.prototype = $extend(haxor.core.Resource.prototype,{
	get_mode: function() {
		return this.m_mode;
	}
	,set_mode: function(v) {
		if(this.m_mode == v) return v;
		this.m_mode = v;
		return v;
	}
	,get_primitive: function() {
		return this.m_primitive;
	}
	,set_primitive: function(v) {
		if(this.m_primitive == v) return v;
		this.m_primitive = v;
		return v;
	}
	,get_topology: function() {
		return this.m_topology;
	}
	,set_topology: function(v) {
		if(v == null) this.m_topology = new Uint16Array([]); else this.m_topology = v.subarray(0);
		this.m_indexed = this.m_topology.length > 0;
		haxor.api.BufferAPI.Apply(this,"$topology");
		return this.m_topology;
	}
	,get_indexed: function() {
		return this.m_indexed;
	}
	,get_attribs: function() {
		return this.m_attribs.slice();
	}
	,get_vertexCount: function() {
		return this.m_vertexCount;
	}
	,get_bounds: function() {
		return this.m_bounds;
	}
	,set_bounds: function(v) {
		this.m_bounds.set_xMin(v.get_xMin());
		this.m_bounds.set_xMax(v.get_xMax());
		this.m_bounds.set_yMin(v.get_yMin());
		this.m_bounds.set_yMax(v.get_yMax());
		this.m_bounds.set_zMin(v.get_zMin());
		this.m_bounds.set_zMax(v.get_zMax());
		return this.m_bounds;
	}
	,GenerateBounds: function() {
		this.m_bounds = haxor.math.AABB3.get_empty();
	}
	,Update: function(p_attrib) {
		haxor.api.BufferAPI.Apply(this,p_attrib);
	}
	,Set: function(p_attrib,p_data,p_element_size) {
		if(p_element_size == null) p_element_size = 0;
		this.Remove(p_attrib);
		if(p_data.length <= 0) return;
		if(p_data == null) return;
		var f = null;
		if(js.Boot.__instanceof(p_data,Float32Array)) {
			f = p_data;
			f = f.subarray(0);
		} else if((p_data instanceof Array) && p_data.__enum__ == null) {
			var d = p_data[0];
			if(typeof(d) == "number") {
				f = this.FToF32(p_data);
				p_element_size = 1;
			} else if(js.Boot.__instanceof(d,haxor.math.Vector2)) {
				f = this.V2ToF32(p_data);
				p_element_size = 2;
			} else if(js.Boot.__instanceof(d,haxor.math.Vector3)) {
				f = this.V3ToF32(p_data);
				p_element_size = 3;
			} else if(js.Boot.__instanceof(d,haxor.math.Vector4)) {
				f = this.V4ToF32(p_data);
				p_element_size = 4;
			} else if(js.Boot.__instanceof(d,haxor.math.Color)) {
				f = this.CToF32(p_data);
				p_element_size = 4;
			}
		}
		if(f == null) {
			haxor.core.Console.LogWarning("Mesh> Float32Array is null @ attrib[" + p_attrib + "]");
			return;
		}
		var v;
		if(p_element_size <= 0) v = 3; else v = p_element_size;
		this.m_sizes.set(p_attrib,v);
		v;
		this.m_buffers.set(p_attrib,f);
		this.m_attribs.push(p_attrib);
		this.m_vertexCount = -1;
		var _g1 = 0;
		var _g = this.m_attribs.length;
		while(_g1 < _g) {
			var i = _g1++;
			var f1 = this.m_buffers.get(this.m_attribs[i]);
			var len = f1.length;
			var vc = len / this.m_sizes.get(this.m_attribs[i]);
			if(this.m_vertexCount < 0) this.m_vertexCount = vc; else this.m_vertexCount = haxor.math.Mathf.MinInt([vc,this.m_vertexCount]);
		}
		this.Update(p_attrib);
	}
	,ElementSize: function(p_attrib) {
		if(this.m_sizes.exists(p_attrib)) return this.m_sizes.get(p_attrib); else return 0;
	}
	,Get: function(p_attrib) {
		if(this.m_buffers.exists(p_attrib)) return this.m_buffers.get(p_attrib); else return null;
	}
	,Remove: function(p_attrib) {
		if(!this.m_buffers.exists(p_attrib)) return;
		this.m_sizes.set(p_attrib,0);
		0;
		this.m_buffers.set(p_attrib,null);
		null;
		HxOverrides.remove(this.m_attribs,p_attrib);
		haxor.api.BufferAPI.Destroy(this,p_attrib);
		if(this.m_attribs.length <= 0) this.m_vertexCount = 0; else this.m_vertexCount = -1;
		var _g1 = 0;
		var _g = this.m_attribs.length;
		while(_g1 < _g) {
			var i = _g1++;
			var f = this.m_buffers.get(this.m_attribs[i]);
			var len = f.length;
			var vc = len / this.m_sizes.get(this.m_attribs[i]);
			if(this.m_vertexCount < 0) this.m_vertexCount = vc; else this.m_vertexCount = haxor.math.Mathf.MinInt([vc,this.m_vertexCount]);
		}
	}
	,Clear: function() {
		var _g = 0;
		var _g1 = this.m_attribs;
		while(_g < _g1.length) {
			var a = _g1[_g];
			++_g;
			this.Remove(a);
		}
		this.m_attribs = [];
	}
	,OnDestroy: function() {
		this.Clear();
	}
	,VToF32: function(a) {
		if(a == null) return new Float32Array([]);
		var d = a[0];
		if(typeof(d) == "number") return this.FToF32(a); else if(js.Boot.__instanceof(d,haxor.math.Vector2)) return this.V2ToF32(a); else if(js.Boot.__instanceof(d,haxor.math.Vector3)) return this.V3ToF32(a); else if(js.Boot.__instanceof(d,haxor.math.Vector4)) return this.V4ToF32(a); else if(js.Boot.__instanceof(d,haxor.math.Color)) return this.CToF32(a);
		return new Float32Array([]);
	}
	,F32ToV: function(a,s) {
		if(a == null) return [];
		if(s == 1) return this.F32ToF(a); else if(s == 2) return this.F32ToV2(a); else if(s == 3) return this.F32ToV3(a); else if(s == 4) return this.F32ToV4(a);
		return [];
	}
	,F32ToF: function(f) {
		if(f == null) return [];
		var i = 0;
		var v;
		var a = [];
		while(i < f.length) {
			v = f[i];
			i++;
			a.push(v);
		}
		return a;
	}
	,F32ToV2: function(f) {
		if(f == null) return [];
		var i = 0;
		var v;
		var a = [];
		while(i < f.length) {
			v = new haxor.math.Vector2(f[i],f[i + 1]);
			i += 2;
			a.push(v);
		}
		return a;
	}
	,F32ToV3: function(f) {
		if(f == null) return [];
		var i = 0;
		var v;
		var a = [];
		while(i < f.length) {
			v = new haxor.math.Vector3(f[i],f[i + 1],f[i + 2]);
			i += 3;
			a.push(v);
		}
		return a;
	}
	,F32ToV4: function(f) {
		if(f == null) return [];
		var i = 0;
		var v;
		var a = [];
		while(i < f.length) {
			v = new haxor.math.Vector4(f[i],f[i + 1],f[i + 2],f[i + 3]);
			i += 4;
			a.push(v);
		}
		return a;
	}
	,F32ToC: function(f) {
		if(f == null) return [];
		var i = 0;
		var v;
		var a = [];
		while(i < f.length) {
			v = new haxor.math.Color(f[i],f[i + 1],f[i + 2],f[i + 3]);
			i += 4;
			a.push(v);
		}
		return a;
	}
	,FToF32: function(a) {
		var i = 0;
		var k = 0;
		var f = new Float32Array(a.length);
		while(i < a.length) f[k++] = a[i++];
		return f;
	}
	,V2ToF32: function(a) {
		var i = 0;
		var k = 0;
		var f = new Float32Array(a.length * 2);
		while(i < a.length) {
			f[k++] = a[i].x;
			f[k++] = a[i++].y;
		}
		return f;
	}
	,V3ToF32: function(a) {
		var i = 0;
		var k = 0;
		var f = new Float32Array(a.length * 3);
		while(i < a.length) {
			f[k++] = a[i].x;
			f[k++] = a[i].y;
			f[k++] = a[i++].z;
		}
		return f;
	}
	,V4ToF32: function(a) {
		var i = 0;
		var k = 0;
		var f = new Float32Array(a.length * 4);
		while(i < a.length) {
			f[k++] = a[i].x;
			f[k++] = a[i].y;
			f[k++] = a[i].z;
			f[k++] = a[i++].w;
		}
		return f;
	}
	,CToF32: function(a) {
		var i = 0;
		var k = 0;
		var f = new Float32Array(a.length * 4);
		while(i < a.length) {
			f[k++] = a[i].r;
			f[k++] = a[i].g;
			f[k++] = a[i].b;
			f[k++] = a[i++].a;
		}
		return f;
	}
	,__class__: haxor.graphics.Mesh
	,__properties__: $extend(haxor.core.Resource.prototype.__properties__,{set_bounds:"set_bounds",get_bounds:"get_bounds",get_vertexCount:"get_vertexCount",get_attribs:"get_attribs",get_indexed:"get_indexed",set_topology:"set_topology",get_topology:"get_topology",set_primitive:"set_primitive",get_primitive:"get_primitive",set_mode:"set_mode",get_mode:"get_mode"})
});
haxor.graphics.MeshTemplate = function() {
	haxor.graphics.Mesh.call(this);
};
$hxClasses["haxor.graphics.MeshTemplate"] = haxor.graphics.MeshTemplate;
haxor.graphics.MeshTemplate.__name__ = ["haxor","graphics","MeshTemplate"];
haxor.graphics.MeshTemplate.__super__ = haxor.graphics.Mesh;
haxor.graphics.MeshTemplate.prototype = $extend(haxor.graphics.Mesh.prototype,{
	get_vertex: function() {
		var s = this.ElementSize("vertex");
		if(s <= 0) return [];
		return this.F32ToV(this.Get("vertex"),s);
	}
	,set_vertex: function(v) {
		this.Set("vertex",v);
		return v;
	}
	,get_normal: function() {
		var s = this.ElementSize("normal");
		if(s <= 0) return [];
		return this.F32ToV(this.Get("normal"),s);
	}
	,set_normal: function(v) {
		this.Set("normal",v);
		return v;
	}
	,get_color: function() {
		return this.F32ToC(this.Get("color"));
	}
	,set_color: function(v) {
		this.Set("color",v);
		return v;
	}
	,get_uv0: function() {
		var s = this.ElementSize("uv0");
		if(s <= 0) return [];
		return this.F32ToV(this.Get("uv0"),s);
	}
	,set_uv0: function(v) {
		this.Set("uv0",v);
		return v;
	}
	,get_uv1: function() {
		var s = this.ElementSize("uv1");
		if(s <= 0) return [];
		return this.F32ToV(this.Get("uv1"),s);
	}
	,set_uv1: function(v) {
		this.Set("uv1",v);
		return v;
	}
	,get_tangent: function() {
		var s = this.ElementSize("tangent");
		if(s <= 0) return [];
		return this.F32ToV(this.Get("tangent"),s);
	}
	,set_tangent: function(v) {
		this.Set("tangent",v);
		return v;
	}
	,get_binormal: function() {
		var s = this.ElementSize("binormal");
		if(s <= 0) return [];
		return this.F32ToV(this.Get("binormal"),s);
	}
	,set_binormal: function(v) {
		this.Set("binormal",v);
		return v;
	}
	,GenerateBounds: function() {
		var f = this.Get("vertex");
		if(f == null) return;
		var step = this.ElementSize("vertex");
		if(step <= 0) return;
		var b = haxor.math.AABB3.get_empty();
		var i = step;
		var vx;
		if(step > 0) vx = f[0]; else vx = 0;
		var vy;
		if(step > 1) vy = f[1]; else vy = 0;
		var vz;
		if(step > 2) vz = f[2]; else vz = 0;
		b.set_xMin(b.set_xMax(vx));
		b.set_yMin(b.set_yMax(vy));
		b.set_zMin(b.set_zMax(vz));
		while(i < f.length) {
			if(step > 0) vx = f[i]; else vx = 0;
			if(step > 1) vy = f[i + 1]; else vy = 0;
			if(step > 2) vz = f[i + 2]; else vz = 0;
			b.Encapsulate3(vx,vy,vz);
			i += step;
		}
		this.m_bounds = b;
	}
	,__class__: haxor.graphics.MeshTemplate
	,__properties__: $extend(haxor.graphics.Mesh.prototype.__properties__,{set_binormal:"set_binormal",get_binormal:"get_binormal",set_tangent:"set_tangent",get_tangent:"get_tangent",set_uv1:"set_uv1",get_uv1:"get_uv1",set_uv0:"set_uv0",get_uv0:"get_uv0",set_color:"set_color",get_color:"get_color",set_normal:"set_normal",get_normal:"get_normal",set_vertex:"set_vertex",get_vertex:"get_vertex"})
});
haxor.graphics.Mesh3 = function() {
	haxor.graphics.MeshTemplate.call(this);
};
$hxClasses["haxor.graphics.Mesh3"] = haxor.graphics.Mesh3;
haxor.graphics.Mesh3.__name__ = ["haxor","graphics","Mesh3"];
haxor.graphics.Mesh3.__super__ = haxor.graphics.MeshTemplate;
haxor.graphics.Mesh3.prototype = $extend(haxor.graphics.MeshTemplate.prototype,{
	__class__: haxor.graphics.Mesh3
});
haxor.graphics.SkinnedMesh3 = function() {
	haxor.graphics.Mesh3.call(this);
};
$hxClasses["haxor.graphics.SkinnedMesh3"] = haxor.graphics.SkinnedMesh3;
haxor.graphics.SkinnedMesh3.__name__ = ["haxor","graphics","SkinnedMesh3"];
haxor.graphics.SkinnedMesh3.__super__ = haxor.graphics.Mesh3;
haxor.graphics.SkinnedMesh3.prototype = $extend(haxor.graphics.Mesh3.prototype,{
	get_binds: function() {
		return this.m_binds;
	}
	,set_binds: function(v) {
		this.m_binds = v.slice();
		return v;
	}
	,get_bone: function() {
		return this.F32ToV4(this.Get("bone"));
	}
	,set_bone: function(v) {
		this.Set("bone",v);
		return v;
	}
	,get_weight: function() {
		return this.F32ToV4(this.Get("weight"));
	}
	,set_weight: function(v) {
		this.Set("weight",v);
		return v;
	}
	,__class__: haxor.graphics.SkinnedMesh3
	,__properties__: $extend(haxor.graphics.Mesh3.prototype.__properties__,{set_weight:"set_weight",get_weight:"get_weight",set_bone:"set_bone",get_bone:"get_bone",set_binds:"set_binds",get_binds:"get_binds"})
});
haxor.graphics.Mesh2D = function() {
	haxor.graphics.MeshTemplate.call(this);
};
$hxClasses["haxor.graphics.Mesh2D"] = haxor.graphics.Mesh2D;
haxor.graphics.Mesh2D.__name__ = ["haxor","graphics","Mesh2D"];
haxor.graphics.Mesh2D.__super__ = haxor.graphics.MeshTemplate;
haxor.graphics.Mesh2D.prototype = $extend(haxor.graphics.MeshTemplate.prototype,{
	__class__: haxor.graphics.Mesh2D
});
haxor.graphics.Mesh23 = function() {
	haxor.graphics.MeshTemplate.call(this);
};
$hxClasses["haxor.graphics.Mesh23"] = haxor.graphics.Mesh23;
haxor.graphics.Mesh23.__name__ = ["haxor","graphics","Mesh23"];
haxor.graphics.Mesh23.__super__ = haxor.graphics.MeshTemplate;
haxor.graphics.Mesh23.prototype = $extend(haxor.graphics.MeshTemplate.prototype,{
	__class__: haxor.graphics.Mesh23
});
haxor.graphics.Mesh2 = function() {
	haxor.graphics.MeshTemplate.call(this);
};
$hxClasses["haxor.graphics.Mesh2"] = haxor.graphics.Mesh2;
haxor.graphics.Mesh2.__name__ = ["haxor","graphics","Mesh2"];
haxor.graphics.Mesh2.__super__ = haxor.graphics.MeshTemplate;
haxor.graphics.Mesh2.prototype = $extend(haxor.graphics.MeshTemplate.prototype,{
	__class__: haxor.graphics.Mesh2
});
haxor.graphics.Mesh4 = function() {
	haxor.graphics.MeshTemplate.call(this);
};
$hxClasses["haxor.graphics.Mesh4"] = haxor.graphics.Mesh4;
haxor.graphics.Mesh4.__name__ = ["haxor","graphics","Mesh4"];
haxor.graphics.Mesh4.__super__ = haxor.graphics.MeshTemplate;
haxor.graphics.Mesh4.prototype = $extend(haxor.graphics.MeshTemplate.prototype,{
	__class__: haxor.graphics.Mesh4
});
haxor.graphics.RenderQueue = function() { };
$hxClasses["haxor.graphics.RenderQueue"] = haxor.graphics.RenderQueue;
haxor.graphics.RenderQueue.__name__ = ["haxor","graphics","RenderQueue"];
haxor.graphics.Screen = function() { };
$hxClasses["haxor.graphics.Screen"] = haxor.graphics.Screen;
haxor.graphics.Screen.__name__ = ["haxor","graphics","Screen"];
haxor.graphics.Screen.__properties__ = {set_fullscreen:"set_fullscreen",get_fullscreen:"get_fullscreen",get_height:"get_height",get_width:"get_width"}
haxor.graphics.Screen.get_width = function() {
	return haxor.graphics.Screen.m_width;
};
haxor.graphics.Screen.get_height = function() {
	return haxor.graphics.Screen.m_height;
};
haxor.graphics.Screen.IsFullscreen = function(p_element) {
	if(p_element == null) return false;
	var d = window.document;
	if(d.fullscreenElement != null) return p_element == d.fullscreenElement;
	if(d.mozFullScreenElement != null) return p_element == d.mozFullScreenElement;
	if(d.msFullScreenElement != null) return p_element == d.msFullScreenElement;
	if(d.oFullScreenElement != null) return p_element == d.oFullScreenElement;
	if(d.webkitCurrentFullScreenElement != null) return p_element == d.webkitCurrentFullScreenElement;
	return false;
};
haxor.graphics.Screen.SetFullscreen = function(p_element,p_flag,p_keyboard) {
	if(p_keyboard == null) p_keyboard = true;
	if(p_element == null) return;
	var is_fs = haxor.graphics.Screen.IsFullscreen(p_element);
	if(is_fs == p_flag) return;
	var c = p_element;
	var d = window.document;
	if(p_flag) {
		if(c.requestFullScreen != null) {
			if(p_keyboard) c.requestFullScreen(1); else c.requestFullScreen();
		} else if(c.mozRequestFullScreen != null) {
			if(p_keyboard) c.mozRequestFullScreen(1); else c.mozRequestFullScreen();
		} else if(c.msRequestFullScreen != null) {
			if(p_keyboard) c.msRequestFullScreen(1); else c.msRequestFullScreen();
		} else if(c.oRequestFullScreen != null) {
			if(p_keyboard) c.oRequestFullScreen(1); else c.oRequestFullScreen();
		} else if(c.webkitRequestFullScreen != null) {
			if(p_keyboard) c.webkitRequestFullScreen(1); else c.webkitRequestFullScreen();
		}
	} else if(d.cancelFullScreen) d.cancelFullScreen(); else if(d.mozCancelFullScreen) d.mozCancelFullScreen(); else if(d.msCancelFullScreen) d.msCancelFullScreen(); else if(d.oCancelFullScreen) d.oCancelFullScreen(); else if(d.webkitCancelFullScreen) d.webkitCancelFullScreen();
};
haxor.graphics.Screen.get_fullscreen = function() {
	return haxor.graphics.Screen.IsFullscreen(haxor.graphics.Screen.m_target);
};
haxor.graphics.Screen.set_fullscreen = function(v) {
	haxor.graphics.Screen.SetFullscreen(haxor.graphics.Screen.m_target,v);
	return v;
};
haxor.graphics.Shader = function(p_source) {
	haxor.core.Resource.call(this);
	this.m_locations = new haxe.ds.StringMap();
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
	var shader = Xml.parse(p_source);
	shader = shader.firstElement();
	this.set_name(shader.get("id"));
	if(this.get_name() == null || this.get_name() == "") this.set_name("shader");
	if(shader.elementsNamed("lighting").hasNext()) {
	}
	var vs = shader.elementsNamed("vertex").next();
	var fs = shader.elementsNamed("fragment").next();
	if(vs != null) {
		var src = vs.firstChild().get_nodeValue().toString();
		var prec = (vs.get("precision") == null?"medium":vs.get("precision")).toLowerCase();
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
		this.m_vertexShaderSource = prec + src;
	}
	if(fs != null) {
		var src1 = fs.firstChild().get_nodeValue().toString();
		var prec1 = (fs.get("precision") == null?"medium":fs.get("precision")).toLowerCase();
		switch(prec1) {
		case "low":
			prec1 = "precision lowp float;";
			break;
		case "medium":
			prec1 = "precision mediump float;";
			break;
		case "high":
			prec1 = "precision highp float;";
			break;
		}
		this.m_fragmentShaderSource = prec1 + src1;
	}
	this.m_hasError = false;
	haxor.api.ShaderAPI.Create(this);
};
$hxClasses["haxor.graphics.Shader"] = haxor.graphics.Shader;
haxor.graphics.Shader.__name__ = ["haxor","graphics","Shader"];
haxor.graphics.Shader.__properties__ = {get_skybox:"get_skybox",get_blit:"get_blit",get_texture:"get_texture",get_error:"get_error"}
haxor.graphics.Shader.get_error = function() {
	if(haxor.graphics.Shader.m_error != null) return haxor.graphics.Shader.m_error;
	haxor.graphics.Shader.m_error = haxor.core.Asset.Get("haxor/internal/Error");
	if(haxor.graphics.Shader.m_error != null) return haxor.graphics.Shader.m_error;
	var src = "";
	src += "<shader id='haxor/internal/Error'>";
	src += "<vertex>";
	src += "uniform mat4 WorldMatrix;";
	src += "uniform mat4 ViewMatrix;";
	src += "uniform mat4 ProjectionMatrix;";
	src += "attribute vec3 vertex;";
	src += "attribute vec3 normal;";
	src += "varying vec3 onormal;";
	src += "void main(void) { gl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix; onormal = normal * mat3(WorldMatrix);}";
	src += "</vertex>";
	src += "<fragment>";
	src += "precision mediump float;";
	src += "varying vec3 onormal;";
	src += "void main(void) { float diff = dot(normalize(onormal),normalize(vec3(1.0,1.0,1.0))); gl_FragColor = vec4(1.0, 0.0, 1, 1.0) * clamp(diff,0.3,1.0); }";
	src += "</fragment>";
	src += "</shader>";
	haxor.graphics.Shader.m_error = new haxor.graphics.Shader(src);
	haxor.graphics.Shader.m_error.set_name("haxor/$Error");
	return haxor.graphics.Shader.m_error;
};
haxor.graphics.Shader.get_texture = function() {
	if(haxor.graphics.Shader.m_texture != null) return haxor.graphics.Shader.m_texture;
	haxor.graphics.Shader.m_texture = haxor.core.Asset.Get("haxor/internal/Texture");
	if(haxor.graphics.Shader.m_texture != null) return haxor.graphics.Shader.m_texture;
	var src = "";
	src += "<shader id='haxor/internal/Texture'>";
	src += "<vertex>";
	src += "attribute vec3 vertex;";
	src += "attribute vec3 uv0;";
	src += "varying vec3 _uv0;";
	src += "void main(void) { gl_Position = vec4(vertex,1.0); _uv0 = uv0; }";
	src += "</vertex>";
	src += "<fragment>";
	src += "precision mediump float;";
	src += "uniform sampler2D  Texture;";
	src += "varying vec3 _uv0;";
	src += "void main(void) { gl_FragColor = texture2D(Texture, _uv0.xy); }";
	src += "</fragment>";
	src += "</shader>";
	haxor.graphics.Shader.m_texture = new haxor.graphics.Shader(src);
	haxor.graphics.Shader.m_texture.set_name("haxor/$Texture");
	return haxor.graphics.Shader.m_texture;
};
haxor.graphics.Shader.get_blit = function() {
	if(haxor.graphics.Shader.m_blit != null) return haxor.graphics.Shader.m_blit;
	haxor.graphics.Shader.m_blit = haxor.core.Asset.Get("haxor/internal/Blit");
	if(haxor.graphics.Shader.m_blit != null) return haxor.graphics.Shader.m_blit;
	var src = "";
	src += "<shader id='haxor/internal/Blit'>";
	src += "<vertex>";
	src += "attribute vec3 vertex;";
	src += "varying vec2 uv;";
	src += "void main(void) { gl_Position = vec4(vertex,1.0); uv = vec2((vertex.x+1.0)*0.5,(vertex.y+1.0)*0.5); }";
	src += "</vertex>";
	src += "<fragment>";
	src += "precision lowp float;";
	src += "uniform sampler2D  Texture;";
	src += "varying vec2 uv;";
	src += "void main(void) { gl_FragColor = texture2D(Texture, uv.xy); }";
	src += "</fragment>";
	src += "</shader>";
	haxor.graphics.Shader.m_blit = new haxor.graphics.Shader(src);
	haxor.graphics.Shader.m_blit.set_name("haxor/internal/Blit");
	return haxor.graphics.Shader.m_blit;
};
haxor.graphics.Shader.get_skybox = function() {
	if(haxor.graphics.Shader.m_skybox != null) return haxor.graphics.Shader.m_skybox;
	haxor.graphics.Shader.m_skybox = haxor.core.Asset.Get("haxor/internal/Skybox");
	if(haxor.graphics.Shader.m_skybox != null) return haxor.graphics.Shader.m_skybox;
	var src = "";
	src += "<shader id='haxor/internal/Skybox'>";
	src += "<vertex>";
	src += "precision mediump float;";
	src += "uniform mat4 ViewMatrixInverse;";
	src += "uniform mat4 SkyboxProjectionMatrixInverse;";
	src += "uniform vec3 WSCameraPosition;";
	src += "varying vec3 WSView;";
	src += "attribute vec3 vertex;";
	src += "void main()";
	src += "{";
	src += "\tvec4 v = vec4(vertex,1.0);";
	src += "\tvec4 ws_vertex = v * SkyboxProjectionMatrixInverse;";
	src += "\tws_vertex /= ws_vertex.w;";
	src += "\tws_vertex = ws_vertex * ViewMatrixInverse;";
	src += "\tWSView = ws_vertex.xyz - WSCameraPosition;";
	src += "\tgl_Position = v;";
	src += "}";
	src += "</vertex>";
	src += "<fragment>";
	src += "precision mediump float;";
	src += "uniform samplerCube  SkyboxTexture;";
	src += "varying vec3 WSView;";
	src += "void main() { gl_FragColor = textureCube(SkyboxTexture,normalize(WSView)); }";
	src += "</fragment>";
	src += "</shader>";
	haxor.graphics.Shader.m_skybox = new haxor.graphics.Shader(src);
	haxor.graphics.Shader.m_skybox.set_name("haxor/internal/Skybox");
	return haxor.graphics.Shader.m_skybox;
};
haxor.graphics.Shader.FromFile = function(p_path) {
	var loader = new XMLHttpRequest();
	loader.open("GET",p_path,false);
	loader.send(null);
	if(loader.status == 200) return new haxor.graphics.Shader(loader.responseText); else return null;
};
haxor.graphics.Shader.FromHTML = function(p_id) {
	var e = window.document.getElementById(p_id);
	var src = e.innerText;
	var shd = new haxor.graphics.Shader(src);
	return shd;
};
haxor.graphics.Shader.__super__ = haxor.core.Resource;
haxor.graphics.Shader.prototype = $extend(haxor.core.Resource.prototype,{
	get_hasError: function() {
		return this.m_hasError;
	}
	,get_gid: function() {
		return this.m_gid;
	}
	,OnDestroy: function() {
		haxor.core.Resource.prototype.OnDestroy.call(this);
		haxor.api.ShaderAPI.Destroy(this);
	}
	,__class__: haxor.graphics.Shader
	,__properties__: $extend(haxor.core.Resource.prototype.__properties__,{get_gid:"get_gid",get_hasError:"get_hasError"})
});
haxor.graphics.filters = {};
haxor.graphics.filters.RenderFX = function() {
	haxor.graphics.Material.call(this);
	this.enabled = true;
};
$hxClasses["haxor.graphics.filters.RenderFX"] = haxor.graphics.filters.RenderFX;
haxor.graphics.filters.RenderFX.__name__ = ["haxor","graphics","filters","RenderFX"];
haxor.graphics.filters.RenderFX.__super__ = haxor.graphics.Material;
haxor.graphics.filters.RenderFX.prototype = $extend(haxor.graphics.Material.prototype,{
	OnRender: function(p_source,p_destination) {
	}
	,__class__: haxor.graphics.filters.RenderFX
});
haxor.graphics.filters.BlurFX = function() {
	haxor.graphics.filters.RenderFX.call(this);
	this.iterations = 0;
	this.strength = 0.0;
};
$hxClasses["haxor.graphics.filters.BlurFX"] = haxor.graphics.filters.BlurFX;
haxor.graphics.filters.BlurFX.__name__ = ["haxor","graphics","filters","BlurFX"];
haxor.graphics.filters.BlurFX.__super__ = haxor.graphics.filters.RenderFX;
haxor.graphics.filters.BlurFX.prototype = $extend(haxor.graphics.filters.RenderFX.prototype,{
	OnRender: function(p_source,p_destination) {
		if(this.get_shader() == null) this.set_shader(haxor.core.Asset.Get("haxor/filter/Blur"));
		if(this.get_shader() == null) return;
		if(this.iterations <= 0) {
			this.iterations = 0;
			haxor.graphics.Graphics.Blit(p_source,p_destination);
			return;
		}
		this.SetUniform("Strength",this.strength + 0.00001);
		if(this.m_b0 == null) {
			this.m_b0 = new haxor.texture.RenderTexture(p_source.get_width(),p_source.get_height(),haxor.texture.TextureFormat.RGBA8);
			this.m_b0.set_name("B0");
			this.m_b1 = new haxor.texture.RenderTexture(p_source.get_width(),p_source.get_height(),haxor.texture.TextureFormat.RGBA8);
			this.m_b1.set_name("B1");
		}
		var last = this.m_b0;
		haxor.graphics.Graphics.Blit(p_source,this.m_b0,this);
		var _g1 = 0;
		var _g = this.iterations - 1;
		while(_g1 < _g) {
			var i = _g1++;
			var tmp = this.m_b0;
			this.m_b0 = this.m_b1;
			this.m_b1 = tmp;
			haxor.graphics.Graphics.Blit(this.m_b1,this.m_b0,this);
			last = this.m_b0;
		}
		haxor.graphics.Graphics.Blit(last,p_destination);
	}
	,__class__: haxor.graphics.filters.BlurFX
});
haxor.importer = {};
haxor.importer.AssetFile = function(p_src) {
	this.x = Xml.parse(p_src);
	this.TraverseStep(this.x.firstElement());
};
$hxClasses["haxor.importer.AssetFile"] = haxor.importer.AssetFile;
haxor.importer.AssetFile.__name__ = ["haxor","importer","AssetFile"];
haxor.importer.AssetFile.prototype = {
	GetAsset: function() {
		return null;
	}
	,Parse: function(n) {
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
	,__class__: haxor.importer.AssetFile
};
haxor.importer.ColladaFile = function(p_src) {
	this.x = Xml.parse(p_src);
	this.xmlns = "";
	this.version = "";
	this.asset = new haxor.importer.ColladaAsset();
	this.geometries = [];
	this.images = [];
	this.controllers = [];
	this.materials = [];
	this.animations = [];
	this.lights = [];
	this.scene = null;
	this.m_id = Std["int"](Math.random() * 16777215);
	this.TraverseStep(this.x.firstElement());
};
$hxClasses["haxor.importer.ColladaFile"] = haxor.importer.ColladaFile;
haxor.importer.ColladaFile.__name__ = ["haxor","importer","ColladaFile"];
haxor.importer.ColladaFile.GenerateTriangles = function(p_type,p_indexes,p_vcount) {
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
			var tris = haxor.importer.ColladaFile.TriangulatePolygon(p_indexes[i],p_indexes[i].length);
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
			var tris1 = haxor.importer.ColladaFile.TriangulatePolygon(p_indexes[0],o,k);
			while(tris1.length > 0) triangles.push(tris1.shift());
			k += o;
		}
		break;
	}
	return triangles;
};
haxor.importer.ColladaFile.TriangulatePolygon = function(t,c,o) {
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
haxor.importer.ColladaFile.prototype = {
	GetAsset: function() {
		var _g3 = this;
		var re = new haxor.core.Entity();
		re.set_name("collada_asset");
		if(this.scene == null) {
			if(haxor.core.Console.get__console() != null) haxor.core.Console.get__console().error("ColladaFile> Trying to get asset of NULL scene.");
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
			var mat = haxor.core.Asset.Get(mn);
			if(mat == null) {
				mat = new haxor.graphics.Material();
				mat.set_name(mn);
				mat.set_shader(haxor.core.Asset.Get("haxor/unlit/FlatTexture"));
				haxor.core.Asset.Add(mn,mat);
			}
			mm.set(m,mat);
		}
		this.scene.Traverse(function(n) {
			var pe;
			if(n.parent == null) pe = re; else if(hm.h.__keys__[n.parent.__id__] != null) pe = hm.h[n.parent.__id__]; else pe = re;
			var ne = null;
			if(n.name == "EnvironmentAmbientLight") return;
			ne = new haxor.core.Entity();
			ne.set_name("node" + ne.get_id());
			if(n.sid != "") ne.set_name(n.sid); else if(n.id != "") ne.set_name(n.id); else if(n.name != "") ne.set_name(n.name);
			if(n.type == "joint") {
				joint_transforms.push(ne.get_transform());
				joint_nodes.push(n);
			}
			ne.get_transform().set_parent(pe.get_transform());
			ne.get_transform().set_position(n.position);
			ne.get_transform().set_rotation(n.rotation);
			ne.get_transform().set_scale(n.scale);
			if(n.data != "") {
				var ad = ne.AddComponent(haxor.component.AssetData);
				var tk = n.data.split(";");
				var _g11 = 0;
				var _g4 = tk.length;
				while(_g11 < _g4) {
					var i2 = _g11++;
					var dp = StringTools.trim(tk[i2]).split("=");
					if(dp.length != 2) continue;
					var adk = StringTools.trim(dp[0]);
					var adv = StringTools.trim(dp[1]);
					var ktk = adk.split(".");
					var o = ad.content;
					var _g31 = 0;
					var _g21 = ktk.length;
					while(_g31 < _g21) {
						var i3 = _g31++;
						var prop = StringTools.trim(ktk[i3]);
						if(i3 == ktk.length - 1) {
							Reflect.setProperty(o,prop,adv);
							if(adv == "true") Reflect.setProperty(o,prop,true); else if(adv == "false") Reflect.setProperty(o,prop,false); else {
								var nchar = "0123456789., ";
								var is_number = true;
								var _g5 = 0;
								var _g41 = adv.length;
								while(_g5 < _g41) {
									var i4 = _g5++;
									if(nchar.indexOf(adv.charAt(i4)) < 0) {
										is_number = false;
										break;
									}
								}
								if(is_number) {
									var n1 = Std.parseFloat(adv);
									Reflect.setProperty(o,prop,n1);
								} else Reflect.setProperty(o,prop,adv);
							}
						} else {
							var nprop = o[prop];
							if(nprop == null) {
								o[prop] = {}
							}
							o = o[prop];
						}
					}
				}
			}
			hm.set(n,ne);
			var _g12 = 0;
			var _g6 = n.instances.length;
			while(_g12 < _g6) {
				var i5 = _g12++;
				var ci = n.instances[i5];
				var mr = null;
				var cmat = null;
				var cg = null;
				var cc = null;
				var cg_target = "";
				var _g22 = ci.type;
				switch(_g22) {
				case "light":
					var cl = _g3.FindLightById(ci.target);
					if(cl == null) continue;
					var _g42 = cl.type;
					switch(_g42) {
					case "ambient":
						break;
					case "point":
						var pl = ne.AddComponent(haxor.component.PointLight);
						pl.color.Set4(cl.color);
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
						var key = ne.get_transform();
						cm.set(key,cc);
						cg_target = cc.source;
					}
					break;
				}
				cg = _g3.FindGeometryById(cg_target);
				if(cg != null) {
					var _g43 = 0;
					var _g23 = cg.mesh.primitives.length;
					while(_g43 < _g23) {
						var i6 = _g43++;
						var mn1 = cg.mesh.primitives[i6].material;
						cmat = _g3.FindMaterialById(mn1);
						mr = _g3.CreateMeshRenderer(ne,cg_target,cg.mesh.primitives[i6],cc == null?haxor.component.MeshRenderer:haxor.component.SkinnedMeshRenderer,cc);
						if(cc != null) skinned_meshes.push(mr);
						if(cmat != null) if(mm.h.__keys__[cmat.__id__] != null) mr.material = mm.h[cmat.__id__]; else mr.material = mr.material; else {
							var _g51 = 0;
							while(_g51 < 10) {
								var i7 = _g51++;
								mn1 = StringTools.replace(mn1,"_" + i7,"");
							}
							mn1 = StringTools.replace(mn1,"_","/");
							var mat1 = haxor.core.Asset.Get(mn1);
							mr.material = mat1;
						}
					}
				}
			}
		});
		var _g13 = 0;
		var _g7 = skinned_meshes.length;
		while(_g13 < _g7) {
			var i8 = _g13++;
			var skr = skinned_meshes[i8];
			var cc1;
			if((function($this) {
				var $r;
				var key1 = skr.get_transform();
				$r = cm.h.__keys__[key1.__id__] != null;
				return $r;
			}(this))) {
				var key2 = skr.get_transform();
				cc1 = cm.h[key2.__id__];
			} else cc1 = null;
			if(cc1 == null) continue;
			skr.set_joints([]);
			var _g32 = 0;
			var _g24 = cc1.joints.length;
			while(_g32 < _g24) {
				var j = _g32++;
				var _g52 = 0;
				var _g44 = joint_transforms.length;
				while(_g52 < _g44) {
					var k = _g52++;
					if(joint_transforms[k].get_name() == cc1.joints[j]) skr.get_joints().push(joint_transforms[k]);
				}
			}
		}
		var nit = hm.keys();
		while(nit.hasNext()) {
			var n2 = nit.next();
			var e = hm.h[n2.__id__];
			if(e == re) continue;
			e.set_name(n2.name);
		}
		this.AddAnimations(re);
		if(this.asset.axis == "z_up") re.get_transform().set_rotation(haxor.math.Quaternion.FromAxisAngle(haxor.math.Vector3.get_right(),-90.0));
		return re;
	}
	,AddAnimations: function(p_entity,p_exact) {
		if(p_exact == null) p_exact = true;
		if(this.animations.length <= 0) return;
		var re = p_entity;
		var a = re.get_animation();
		if(a == null) a = re.AddComponent(haxor.component.Animation);
		var _g1 = 0;
		var _g = this.animations.length;
		while(_g1 < _g) {
			var i = _g1++;
			var ca = this.animations[i];
			var clip = new haxor.component.AnimationClip();
			clip.set_name(ca.id == ""?ca.name == ""?"clip" + i:ca.name:ca.id);
			var _g3 = 0;
			var _g2 = ca.channels.length;
			while(_g3 < _g2) {
				var j = _g3++;
				var cch = ca.channels[j];
				var src_node = cch.target.split("/")[0];
				src_node = StringTools.replace(src_node,"node-","");
				var src_target = cch.target.split("/")[1];
				var nt = re.get_transform().Search(src_node,p_exact);
				if(nt == null) continue;
				var n = nt.get_entity();
				switch(src_target) {
				case "matrix":
					var position_track = clip.Add(n.get_transform(),"position");
					var rotation_track = clip.Add(n.get_transform(),"rotation");
					var _g5 = 0;
					var _g4 = cch.keyframes.length;
					while(_g5 < _g4) {
						var k = _g5++;
						var kf = cch.keyframes[k];
						var m = haxor.math.Matrix4.FromArray(kf.values);
						var td = m.get_transform();
						position_track.Add(kf.time,td[0]);
						rotation_track.Add(kf.time,td[1]);
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
		var m = haxor.core.Asset.Get(mid);
		if(m != null) {
			r.set_mesh(m);
			return r;
		}
		var mv = cp.GetTriangulatedVectorArray("vertex");
		var mn = cp.GetTriangulatedVectorArray("normal");
		var mc = cp.GetTriangulatedVectorArray("color");
		var cw = haxor.math.Color.get_white();
		if(mc.length <= 0) {
			var _g1 = 0;
			var _g = mv.length;
			while(_g1 < _g) {
				var i = _g1++;
				mc.push(cw);
			}
		}
		var muv0 = cp.GetTriangulatedVectorArray("texcoord",0);
		var muv1 = cp.GetTriangulatedVectorArray("texcoord",1);
		var mbn = cp.GetTriangulatedVectorArray("texbinormal");
		var mtg = cp.GetTriangulatedVectorArray("textangent");
		var is_skinned = js.Boot.__instanceof(r,haxor.component.SkinnedMeshRenderer);
		if(is_skinned) m = new haxor.graphics.SkinnedMesh3(); else m = new haxor.graphics.Mesh3();
		m.set_name(mid);
		haxor.core.Asset.Add(mid,m);
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
				var _g11 = 0;
				var _g2 = mv.length;
				while(_g11 < _g2) {
					var i1 = _g11++;
					mv[i1] = bsm.Transform3x4(mv[i1].get_clone());
				}
				var _g12 = 0;
				var _g3 = mn.length;
				while(_g12 < _g3) {
					var i2 = _g12++;
					mn[i2] = bsm.Transform3x3(mn[i2].get_clone());
				}
				var _g13 = 0;
				var _g4 = mbn.length;
				while(_g13 < _g4) {
					var i3 = _g13++;
					mbn[i3] = bsm.Transform3x3(mbn[i3].get_clone());
				}
				var _g14 = 0;
				var _g5 = mtg.length;
				while(_g14 < _g5) {
					var i4 = _g14++;
					mtg[i4] = bsm.Transform3x3(mtg[i4].get_clone());
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
			this.asset.author = this._p(n,"contributor.author.$text","none");
			this.asset.tool = this._p(n,"contributor.authoring_tool.$text","none");
			this.asset.source = this._p(n,"contributor.source_data.$text","none");
			this.asset.axis = this._p(n,"up_axis.$text","y_up").toLowerCase();
			this.asset.creation = this._p(n,"created.$text","00/00/00");
			this.asset.modification = this._p(n,"modified.$text","00/00/00");
			this.asset.unitName = this._p(n,"unit.@name","none");
			this.asset.unitValue = Std.parseFloat(this._p(n,"unit.@meter","0.0"));
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
			l = new haxor.importer.ColladaLight();
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
			var ca = new haxor.importer.ColladaAnimation();
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
				var cch = new haxor.importer.ColladaAnimationChannel();
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
						var kf = new haxor.importer.ColladaAnimationKeyFrame();
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
				var mat = new haxor.importer.ColladaMaterial();
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
		this.scene = new haxor.importer.ColladaVisualScene();
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
		var cn = new haxor.importer.ColladaNode();
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
				ni = new haxor.importer.ColladaInstance();
				ni.type = "geometry";
				var _this = this._a(nin,"url","");
				ni.target = HxOverrides.substr(_this,1,null);
				break;
			case "instance_controller":
				ni = new haxor.importer.ColladaInstance();
				ni.type = "controller";
				var _this1 = this._a(nin,"url","");
				ni.target = HxOverrides.substr(_this1,1,null);
				break;
			case "instance_light":
				ni = new haxor.importer.ColladaInstance();
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
			c = new haxor.importer.ColladaController();
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
			img = new haxor.importer.ColladaImage();
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
			g = new haxor.importer.ColladaGeometry();
			g.id = this._a(n,"id","none");
			g.name = this._a(n,"name","none");
			this.ParseGeometry(g,n);
			this.geometries.push(g);
		}
	}
	,ParseGeometry: function(g,n) {
		n = n.firstElement();
		if(n == null) return;
		g.mesh = new haxor.importer.ColladaMesh();
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
			var cp = new haxor.importer.ColladaPrimitive();
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
			var ci = new haxor.importer.ColladaInput();
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
	,_a: function(n,a,v) {
		if(n.exists(a)) return n.get(a); else return v;
	}
	,_p: function(n,p,v) {
		var l = p.split(".");
		var it = n;
		var _g1 = 0;
		var _g = l.length;
		while(_g1 < _g) {
			var i = _g1++;
			var tk = l[i];
			switch(tk) {
			case "$text":
				if(it.firstChild() == null) return v; else return it.firstChild().toString();
				break;
			default:
				if(tk.charAt(0) == "@") return this._a(it,HxOverrides.substr(tk,1,null),v);
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
	,__class__: haxor.importer.ColladaFile
};
haxor.importer.ColladaAsset = function() {
	this.axis = "y_up";
	this.unitValue = 0.0;
	this.unitName = "";
	this.modification = "";
	this.creation = "";
	this.source = "";
	this.tool = "";
	this.author = "";
};
$hxClasses["haxor.importer.ColladaAsset"] = haxor.importer.ColladaAsset;
haxor.importer.ColladaAsset.__name__ = ["haxor","importer","ColladaAsset"];
haxor.importer.ColladaAsset.prototype = {
	__class__: haxor.importer.ColladaAsset
};
haxor.importer.ColladaGeometry = function() {
	this.mesh = null;
	this.name = "";
	this.id = "";
};
$hxClasses["haxor.importer.ColladaGeometry"] = haxor.importer.ColladaGeometry;
haxor.importer.ColladaGeometry.__name__ = ["haxor","importer","ColladaGeometry"];
haxor.importer.ColladaGeometry.prototype = {
	__class__: haxor.importer.ColladaGeometry
};
haxor.importer.ColladaMesh = function() {
	this.primitives = null;
	this.type = "";
	this.primitives = [];
};
$hxClasses["haxor.importer.ColladaMesh"] = haxor.importer.ColladaMesh;
haxor.importer.ColladaMesh.__name__ = ["haxor","importer","ColladaMesh"];
haxor.importer.ColladaMesh.prototype = {
	__class__: haxor.importer.ColladaMesh
};
haxor.importer.ColladaPrimitive = function() {
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
$hxClasses["haxor.importer.ColladaPrimitive"] = haxor.importer.ColladaPrimitive;
haxor.importer.ColladaPrimitive.__name__ = ["haxor","importer","ColladaPrimitive"];
haxor.importer.ColladaPrimitive.prototype = {
	get_triangles: function() {
		if(this.m_triangles != null) return this.m_triangles;
		this.m_triangles = haxor.importer.ColladaFile.GenerateTriangles(this.type,this.indexes,this.vcount);
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
	,__class__: haxor.importer.ColladaPrimitive
	,__properties__: {get_offset:"get_offset",get_triangles:"get_triangles"}
};
haxor.importer.ColladaInput = function() {
	this.stride = 0;
	this.values = null;
	this.set = -1;
	this.offset = 0;
	this.semantic = "";
	this.values = [];
};
$hxClasses["haxor.importer.ColladaInput"] = haxor.importer.ColladaInput;
haxor.importer.ColladaInput.__name__ = ["haxor","importer","ColladaInput"];
haxor.importer.ColladaInput.prototype = {
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
	,__class__: haxor.importer.ColladaInput
};
haxor.importer.ColladaImage = function() {
	this.data = null;
	this.depth = 0;
	this.height = 0;
	this.width = 0;
	this.source = "";
	this.format = "";
	this.name = "";
	this.id = "";
};
$hxClasses["haxor.importer.ColladaImage"] = haxor.importer.ColladaImage;
haxor.importer.ColladaImage.__name__ = ["haxor","importer","ColladaImage"];
haxor.importer.ColladaImage.prototype = {
	__class__: haxor.importer.ColladaImage
};
haxor.importer.ColladaController = function() {
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
$hxClasses["haxor.importer.ColladaController"] = haxor.importer.ColladaController;
haxor.importer.ColladaController.__name__ = ["haxor","importer","ColladaController"];
haxor.importer.ColladaController.prototype = {
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
		var mtx = haxor.math.Matrix4.get_identity();
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
			var mtx = haxor.math.Matrix4.get_identity();
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
	,__class__: haxor.importer.ColladaController
	,__properties__: {get_offset:"get_offset"}
};
haxor.importer.ColladaVisualScene = function() {
	this.children = null;
	this.name = "";
	this.id = "";
	this.type = "";
	this.children = [];
};
$hxClasses["haxor.importer.ColladaVisualScene"] = haxor.importer.ColladaVisualScene;
haxor.importer.ColladaVisualScene.__name__ = ["haxor","importer","ColladaVisualScene"];
haxor.importer.ColladaVisualScene.prototype = {
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
	,__class__: haxor.importer.ColladaVisualScene
};
haxor.importer.ColladaNode = function() {
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
	this.position = haxor.math.Vector3.get_zero();
	this.rotation = haxor.math.Quaternion.get_identity();
	this.scale = haxor.math.Vector3.get_one();
};
$hxClasses["haxor.importer.ColladaNode"] = haxor.importer.ColladaNode;
haxor.importer.ColladaNode.__name__ = ["haxor","importer","ColladaNode"];
haxor.importer.ColladaNode.prototype = {
	get_world: function() {
		if(this.m_world != null) return this.m_world;
		this.m_world = haxor.math.Matrix4.get_identity();
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
		this.position = mtx.get_translation().GetColumn(3).get_xyz();
		this.rotation = mtx.get_quaternion();
		this.scale = mtx.get_scale().get_diagonalLR().get_xyz();
	}
	,__class__: haxor.importer.ColladaNode
	,__properties__: {get_world:"get_world"}
};
haxor.importer.ColladaInstance = function() {
	this.target = "";
	this.type = "";
	this.materials = [];
};
$hxClasses["haxor.importer.ColladaInstance"] = haxor.importer.ColladaInstance;
haxor.importer.ColladaInstance.__name__ = ["haxor","importer","ColladaInstance"];
haxor.importer.ColladaInstance.prototype = {
	__class__: haxor.importer.ColladaInstance
};
haxor.importer.ColladaMaterial = function() {
	this.name = "";
	this.id = "";
};
$hxClasses["haxor.importer.ColladaMaterial"] = haxor.importer.ColladaMaterial;
haxor.importer.ColladaMaterial.__name__ = ["haxor","importer","ColladaMaterial"];
haxor.importer.ColladaMaterial.prototype = {
	__class__: haxor.importer.ColladaMaterial
};
haxor.importer.ColladaAnimation = function() {
	this.name = "";
	this.id = "";
	this.channels = [];
};
$hxClasses["haxor.importer.ColladaAnimation"] = haxor.importer.ColladaAnimation;
haxor.importer.ColladaAnimation.__name__ = ["haxor","importer","ColladaAnimation"];
haxor.importer.ColladaAnimation.prototype = {
	__class__: haxor.importer.ColladaAnimation
};
haxor.importer.ColladaAnimationChannel = function() {
	this.target = "";
	this.source = "";
	this.keyframes = [];
};
$hxClasses["haxor.importer.ColladaAnimationChannel"] = haxor.importer.ColladaAnimationChannel;
haxor.importer.ColladaAnimationChannel.__name__ = ["haxor","importer","ColladaAnimationChannel"];
haxor.importer.ColladaAnimationChannel.prototype = {
	__class__: haxor.importer.ColladaAnimationChannel
};
haxor.importer.ColladaAnimationKeyFrame = function() {
	this.time = 0.0;
	this.values = [];
};
$hxClasses["haxor.importer.ColladaAnimationKeyFrame"] = haxor.importer.ColladaAnimationKeyFrame;
haxor.importer.ColladaAnimationKeyFrame.__name__ = ["haxor","importer","ColladaAnimationKeyFrame"];
haxor.importer.ColladaAnimationKeyFrame.prototype = {
	__class__: haxor.importer.ColladaAnimationKeyFrame
};
haxor.importer.ColladaLight = function() {
	this.id = "";
	this.name = "";
	this.type = "";
	this.color = haxor.math.Color.get_white();
	this.radius = 0.0;
	this.intensity = 0.0;
	this.atten = 0.0;
};
$hxClasses["haxor.importer.ColladaLight"] = haxor.importer.ColladaLight;
haxor.importer.ColladaLight.__name__ = ["haxor","importer","ColladaLight"];
haxor.importer.ColladaLight.prototype = {
	__class__: haxor.importer.ColladaLight
};
haxor.importer.MaterialFile = function(p_src) {
	this.id = "";
	this.name = "";
	this.queue = "geometry";
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
	haxor.importer.AssetFile.call(this,p_src);
};
$hxClasses["haxor.importer.MaterialFile"] = haxor.importer.MaterialFile;
haxor.importer.MaterialFile.__name__ = ["haxor","importer","MaterialFile"];
haxor.importer.MaterialFile.__super__ = haxor.importer.AssetFile;
haxor.importer.MaterialFile.prototype = $extend(haxor.importer.AssetFile.prototype,{
	GetAsset: function() {
		var m = new haxor.graphics.Material();
		m.set_name(this.name);
		var _g = this.queue;
		switch(_g) {
		case "background":
			m.queue = haxor.graphics.RenderQueue.Background;
			break;
		case "opaque":
			m.queue = haxor.graphics.RenderQueue.Opaque;
			break;
		case "geometry":
			m.queue = haxor.graphics.RenderQueue.Geometry;
			break;
		case "transparent":
			m.queue = haxor.graphics.RenderQueue.Transparent;
			break;
		case "overlay":
			m.queue = haxor.graphics.RenderQueue.Overlay;
			break;
		case "interface":
			m.queue = haxor.graphics.RenderQueue.Interface;
			break;
		}
		m.queue += this.offset;
		m.set_shader(haxor.core.Asset.Get(this.shader));
		m.ztest = this.ztest;
		m.zfunc = haxor.graphics.DepthTest.LessEqual;
		var _g1 = this.zfunc;
		switch(_g1) {
		case "never":
			m.zfunc = haxor.graphics.DepthTest.Never;
			break;
		case "always":
			m.zfunc = haxor.graphics.DepthTest.Always;
			break;
		case "notequal":
			m.zfunc = haxor.graphics.DepthTest.NotEqual;
			break;
		case "equal":
			m.zfunc = haxor.graphics.DepthTest.Equal;
			break;
		case "less":
			m.zfunc = haxor.graphics.DepthTest.Less;
			break;
		case "lessequal":
			m.zfunc = haxor.graphics.DepthTest.LessEqual;
			break;
		case "greater":
			m.zfunc = haxor.graphics.DepthTest.Greater;
			break;
		case "greaterequal":
			m.zfunc = haxor.graphics.DepthTest.GreaterEqual;
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
			m.cull = haxor.graphics.CullMode.None;
			break;
		case "front":
			m.cull = haxor.graphics.CullMode.Front;
			break;
		case "back":
			m.cull = haxor.graphics.CullMode.Back;
			break;
		}
		var _g11 = 0;
		var _g3 = this.uniforms.length;
		while(_g11 < _g3) {
			var i = _g11++;
			var u = this.uniforms[i];
			var a = this._f32a(u.value);
			var _g21 = u.type;
			switch(_g21) {
			case "float":
				var f32a = new Float32Array(a);
				m.SetUniform(u.name,f32a.length == 1?f32a[0] + 0.00001:f32a);
				break;
			case "int":
				m.SetUniform(u.name,Std.parseInt(u.value));
				break;
			case "vec2":
				m.SetUniform(u.name,new haxor.math.Vector2(a[0],a[1]));
				break;
			case "vec3":
				m.SetUniform(u.name,new haxor.math.Vector3(a[0],a[1],a[2]));
				break;
			case "vec4":
				m.SetUniform(u.name,new haxor.math.Vector4(a[0],a[1],a[2],a[3]));
				break;
			case "mat4":
				m.SetUniform(u.name,haxor.math.Matrix4.FromArray(a));
				break;
			case "color":
				m.SetUniform(u.name,new haxor.math.Color(a[0],a[1],a[2],a[3]));
				break;
			case "texture":
				m.SetUniform(u.name,haxor.core.Asset.Get(u.value));
				break;
			}
		}
		return m;
	}
	,Parse: function(n) {
		var _g = n.get_nodeName();
		switch(_g) {
		case "material":
			this.id = this._a(n,"id","");
			this.name = this._a(n,"name","");
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
			var u = new haxor.importer.MaterialFileUniform();
			u.type = n.get_nodeName().toLowerCase();
			u.name = this._a(n,"name","");
			u.value = this._p(n,"$text","",true);
			this.uniforms.push(u);
		}
	}
	,BlendModeNameToEnum: function(b) {
		switch(b) {
		case "zero":
			return haxor.graphics.BlendMode.Zero;
		case "one":
			return haxor.graphics.BlendMode.One;
		case "srccolor":
			return haxor.graphics.BlendMode.SrcColor;
		case "oneminussrccolor":
			return haxor.graphics.BlendMode.OneMinusSrcColor;
		case "srcalpha":
			return haxor.graphics.BlendMode.SrcAlpha;
		case "oneminussrcalpha":
			return haxor.graphics.BlendMode.OneMinusSrcAlpha;
		case "dstalpha":
			return haxor.graphics.BlendMode.DstAlpha;
		case "oneminusdstalpha":
			return haxor.graphics.BlendMode.OneMinusDstAlpha;
		case "dstcolor":
			return haxor.graphics.BlendMode.DstColor;
		case "oneminusdstcolor":
			return haxor.graphics.BlendMode.OneMinusDstColor;
		case "srcalphasaturate":
			return haxor.graphics.BlendMode.SrcAlphaSaturate;
		}
		return haxor.graphics.BlendMode.Zero;
	}
	,__class__: haxor.importer.MaterialFile
});
haxor.importer.MaterialFileUniform = function() {
	this.type = "";
	this.name = "";
	this.value = "";
};
$hxClasses["haxor.importer.MaterialFileUniform"] = haxor.importer.MaterialFileUniform;
haxor.importer.MaterialFileUniform.__name__ = ["haxor","importer","MaterialFileUniform"];
haxor.importer.MaterialFileUniform.prototype = {
	__class__: haxor.importer.MaterialFileUniform
};
haxor.input = {};
haxor.input.InputState = { __ename__ : true, __constructs__ : ["None","Down","Up","Hold"] };
haxor.input.InputState.None = ["None",0];
haxor.input.InputState.None.__enum__ = haxor.input.InputState;
haxor.input.InputState.Down = ["Down",1];
haxor.input.InputState.Down.__enum__ = haxor.input.InputState;
haxor.input.InputState.Up = ["Up",2];
haxor.input.InputState.Up.__enum__ = haxor.input.InputState;
haxor.input.InputState.Hold = ["Hold",3];
haxor.input.InputState.Hold.__enum__ = haxor.input.InputState;
haxor.input.Joystick = function() {
	this.name = "";
	this.id = -1;
	this.button = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
	var st = haxor.input.InputState.None;
	this.state = [st,st,st,st,st,st,st,st,st,st,st,st,st,st,st,st,st,st,st,st];
	this.hold = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
	this.analog = [0,0,0,0,0,0,0,0];
	this.analogLeft = new haxor.math.Vector3();
	this.analogRight = new haxor.math.Vector3();
	this.triggerLeft = 0.0;
	this.triggerRight = 0.0;
};
$hxClasses["haxor.input.Joystick"] = haxor.input.Joystick;
haxor.input.Joystick.__name__ = ["haxor","input","Joystick"];
haxor.input.Joystick.prototype = {
	IsDown: function(p_button) {
		return this.state[p_button] == haxor.input.InputState.Hold || this.state[p_button] == haxor.input.InputState.Down;
	}
	,Hit: function(p_button) {
		return this.state[p_button] == haxor.input.InputState.Up;
	}
	,__class__: haxor.input.Joystick
};
haxor.input.Touch = function() {
	this.state = haxor.input.InputState.None;
	this.id = -1;
	this.position = new haxor.math.Vector2();
	this.delta = new haxor.math.Vector2();
	this.relativePosition = new haxor.math.Vector2();
	this.pressure = 0;
	this.hold = 0;
	this.angle = 0;
	this.radius = new haxor.math.Vector2();
	this.m_isDown = false;
};
$hxClasses["haxor.input.Touch"] = haxor.input.Touch;
haxor.input.Touch.__name__ = ["haxor","input","Touch"];
haxor.input.Touch.prototype = {
	__class__: haxor.input.Touch
};
haxor.input.Input = function() { };
$hxClasses["haxor.input.Input"] = haxor.input.Input;
haxor.input.Input.__name__ = ["haxor","input","Input"];
haxor.input.Input.__properties__ = {get_multitouch:"get_multitouch",get_joystick:"get_joystick",get_touch:"get_touch"}
haxor.input.Input.get_touch = function() {
	return haxor.input.Input.m_touchList.slice();
};
haxor.input.Input.get_joystick = function() {
	return haxor.input.Input.m_joysticks;
};
haxor.input.Input.get_multitouch = function() {
	return haxor.input.Input.m_isMultiTouch;
};
haxor.input.Input.GetInputState = function(p_code) {
	return haxor.input.Input.m_inputStateMap.get(p_code);
};
haxor.input.Input.IsDown = function(p_code) {
	var s = haxor.input.Input.GetInputState(p_code);
	return s == haxor.input.InputState.Down || s == haxor.input.InputState.Hold;
};
haxor.input.Input.Hit = function(p_code) {
	var s = haxor.input.Input.GetInputState(p_code);
	return s == haxor.input.InputState.Up;
};
haxor.input.Input.GetHoldTime = function(p_code) {
	return haxor.input.Input.m_inputHoldMap.get(p_code);
};
haxor.input.Input.Update = function() {
	haxor.input.Input.wheel = 0;
	haxor.input.Input.deltaMouse.x = 0;
	haxor.input.Input.deltaMouse.y = 0;
	if(haxor.input.Input.m_hasActiveTouches) haxor.input.Input.ProcessTouch();
	haxor.input.Input.ProcessJoystick();
	if(haxor.input.Input.m_eventStack.length > 0) while(haxor.input.Input.m_eventStack.length > 0) haxor.input.Input.ProcessInput(haxor.input.Input.m_eventStack.shift());
	var _g1 = 0;
	var _g = haxor.input.Input.m_activeInput.length;
	while(_g1 < _g) {
		var i = _g1++;
		haxor.input.Input.UpdateInputState(haxor.input.Input.m_activeInput[i],haxor.input.Input.m_isDownList[haxor.input.Input.m_activeInput[i]]);
	}
};
haxor.input.Input.Initialize = function(p_target) {
	var t = haxor.input.Input.m_target = p_target;
	var nav = haxor.input.Input.m_navigator = window.navigator;
	haxor.input.Joystick.available = !(!nav.webkitGetGamepads) || !(!nav.webkitGamepads) || nav.userAgent.indexOf("Firefox/") != -1;
	haxor.input.Input.m_joysticks = [];
	haxor.input.Input.m_joystickList = [];
	var _g = 0;
	while(_g < 10) {
		var i = _g++;
		haxor.input.Input.m_joystickList.push(new haxor.input.Joystick());
	}
	p_target.onmousedown = haxor.input.Input.OnInput;
	window.document.onmousemove = haxor.input.Input.OnInput;
	p_target.onmouseover = haxor.input.Input.OnInput;
	window.document.onmouseup = haxor.input.Input.OnInput;
	p_target.onmousewheel = haxor.input.Input.OnInput;
	if(t.addEventListener) t.addEventListener("DOMMouseScroll",haxor.input.Input.OnInput);
	window.document.onkeydown = haxor.input.Input.OnInput;
	window.document.onkeyup = haxor.input.Input.OnInput;
	try {
		haxor.input.Input.m_isMultiTouch = TouchEvent != null;
	} catch( ex ) {
		haxor.input.Input.m_isMultiTouch = false;
	}
	haxor.input.Input.m_eventTouchList = null;
	p_target.ontouchstart = haxor.input.Input.OnTouch;
	window.document.ontouchmove = haxor.input.Input.OnTouch;
	window.document.ontouchcancel = haxor.input.Input.OnTouch;
	window.document.ontouchend = haxor.input.Input.OnTouch;
	haxor.input.Input.m_inputStateMap = new haxe.ds.IntMap();
	haxor.input.Input.m_inputHoldMap = new haxe.ds.IntMap();
	haxor.input.Input.m_activeInput = new Array();
	haxor.input.Input.m_isDownList = new Array();
	haxor.input.Input.m_eventStack = new Array();
	haxor.input.Input.m_touchList = [];
	var _g1 = 0;
	while(_g1 < 256) {
		var i1 = _g1++;
		haxor.input.Input.m_inputStateMap.set(i1,haxor.input.InputState.None);
		haxor.input.Input.m_inputHoldMap.set(i1,0);
		haxor.input.Input.m_isDownList.push(false);
	}
	haxor.input.Input.mouse = new haxor.math.Vector2();
	haxor.input.Input.deltaMouse = new haxor.math.Vector2();
	haxor.input.Input.relativeMouse = new haxor.math.Vector2();
	haxor.input.Input.m_hasActiveTouches = false;
	var w = window;
	console.log("Haxor> Input initialize - Target[" + haxor.input.Input.m_target.getAttribute("name") + "] MultiTouch[" + Std.string(haxor.input.Input.m_isMultiTouch) + "] Joystick[" + Std.string(haxor.input.Joystick.available) + "]");
};
haxor.input.Input.ProcessJoystick = function() {
	if(!haxor.input.Joystick.available) return;
	var nav = haxor.input.Input.m_navigator;
	var l = null;
	if(nav.webkitGetGamepads != null) l = nav.webkitGetGamepads(); else if(nav.webkitGamepads != null) l = nav.webkitGamepads();
	if(l == null) return;
	haxor.input.Input.m_joysticks = [];
	if(l.length <= 0) return;
	var _g1 = 0;
	var _g = l.length;
	while(_g1 < _g) {
		var i = _g1++;
		var gp = l.item(i);
		if(gp == null) continue;
		var jid = gp.index;
		var js = haxor.input.Input.m_joystickList[jid];
		js.id = gp.index;
		js.name = gp.id;
		var _g3 = 0;
		var _g2 = gp.buttons.length;
		while(_g3 < _g2) {
			var i1 = _g3++;
			js.button[i1] = gp.buttons[i1];
			js.state[i1] = haxor.input.Input.InputStateFSM(js.state[i1],js.button[i1] >= haxor.input.Joystick.buttonBias);
			if(js.state[i1] == haxor.input.InputState.Hold) js.hold[i1] += haxor.core.Time.get_frameDeltaTime();
			if(js.state[i1] == haxor.input.InputState.None) js.hold[i1] = 0.0;
		}
		var _g31 = 0;
		var _g21 = gp.axes.length;
		while(_g31 < _g21) {
			var i2 = _g31++;
			js.analog[i2] = gp.axes[i2];
		}
		var b0 = haxor.input.Joystick.analogBias[0];
		var b1 = haxor.input.Joystick.analogBias[1];
		var s = 1.0;
		var v;
		v = js.analogLeft;
		v.x = gp.axes[haxor.input.Joystick.LEFT_ANALOGUE_HOR];
		if(v.x < 0.0) s = -1.0; else s = 1.0;
		v.x = haxor.math.Mathf.Clamp01((haxor.math.Mathf.Abs(v.x) - b0) / (b1 - b0));
		v.x = s * (v.x * 100.0 | 0) * 0.01;
		v.y = gp.axes[haxor.input.Joystick.LEFT_ANALOGUE_VERT];
		if(v.y < 0.0) s = -1.0; else s = 1.0;
		v.y = haxor.math.Mathf.Clamp01((haxor.math.Mathf.Abs(v.y) - b0) / (b1 - b0));
		v.y = -s * (v.y * 100.0 | 0) * 0.01;
		if(gp.buttons[haxor.input.Joystick.LEFT_ANALOGUE_STICK] >= haxor.input.Joystick.buttonBias) v.z = 1.0; else v.z = 0.0;
		v = js.analogRight;
		v.x = gp.axes[haxor.input.Joystick.RIGHT_ANALOGUE_HOR];
		if(v.x < 0.0) s = -1.0; else s = 1.0;
		v.x = haxor.math.Mathf.Clamp01((haxor.math.Mathf.Abs(v.x) - b0) / (b1 - b0));
		v.x = s * (v.x * 100.0 | 0) * 0.01;
		v.y = gp.axes[haxor.input.Joystick.RIGHT_ANALOGUE_VERT];
		if(v.y < 0.0) s = -1.0; else s = 1.0;
		v.y = haxor.math.Mathf.Clamp01((haxor.math.Mathf.Abs(v.y) - b0) / (b1 - b0));
		v.y = -s * (v.y * 100.0 | 0) * 0.01;
		if(gp.buttons[haxor.input.Joystick.RIGHT_ANALOGUE_STICK] >= haxor.input.Joystick.buttonBias) v.z = 1.0; else v.z = 0.0;
		js.triggerLeft = gp.buttons[haxor.input.Joystick.LEFT_SHOULDER_BOTTOM];
		js.triggerLeft = haxor.math.Mathf.Clamp01((js.triggerLeft - b0) / (b1 - b0));
		js.triggerRight = gp.buttons[haxor.input.Joystick.RIGHT_SHOULDER_BOTTOM];
		js.triggerRight = haxor.math.Mathf.Clamp01((js.triggerRight - b0) / (b1 - b0));
		haxor.input.Input.m_joysticks.push(js);
	}
};
haxor.input.Input.ProcessTouch = function() {
	var l = haxor.input.Input.m_eventTouchList;
	var _g1 = 0;
	var _g = haxor.input.Input.m_touchList.length;
	while(_g1 < _g) {
		var j = _g1++;
		haxor.input.Input.m_touchList[j].m_isDown = false;
	}
	if(l != null) {
		var _g11 = 0;
		var _g2 = l.length;
		while(_g11 < _g2) {
			var i = _g11++;
			var et = l[i];
			var exists = false;
			var p = haxor.input.Input.GetAbsolutePosition(haxor.input.Input.m_target,et.pageX,et.pageY);
			var _g3 = 0;
			var _g21 = haxor.input.Input.m_touchList.length;
			while(_g3 < _g21) {
				var j1 = _g3++;
				var t = haxor.input.Input.m_touchList[j1];
				if(t.id == et.identifier) {
					exists = true;
					t.m_isDown = true;
					haxor.input.Input.UpdateTouch(t,et,p);
				}
			}
			if(!exists) {
				var nt = new haxor.input.Touch();
				haxor.input.Input.UpdateTouch(nt,et,p);
				nt.m_isDown = true;
				haxor.input.Input.m_touchList.push(nt);
			}
		}
	}
	var _g12 = 0;
	var _g4 = haxor.input.Input.m_touchList.length;
	while(_g12 < _g4) {
		var j2 = _g12++;
		haxor.input.Input.UpdateTouchState(haxor.input.Input.m_touchList[j2]);
	}
	if(haxor.input.Input.m_touchList.length <= 0) haxor.input.Input.m_hasActiveTouches = false;
};
haxor.input.Input.UpdateTouch = function(t,d,p) {
	if(t.id >= 0) {
		t.delta.x = p.x - t.position.x;
		t.delta.y = p.y - t.position.y;
	}
	t.id = d.identifier;
	t.position.x = p.x;
	t.position.y = p.y;
	t.relativePosition.x = t.position.x / haxor.graphics.Screen.get_width();
	t.relativePosition.y = t.position.y / haxor.graphics.Screen.get_height();
	t.pressure = d.force;
	t.radius.x = d.radiusX;
	t.radius.y = d.radiusY;
	t.angle = d.rotationAngle;
};
haxor.input.Input.UpdateTouchState = function(t) {
	if(t == null) return;
	var current = t.state;
	var d = Reflect.field(t,"m_isDown");
	if(current == haxor.input.InputState.Up) HxOverrides.remove(haxor.input.Input.m_touchList,t);
	if(current == haxor.input.InputState.Hold) t.hold += haxor.core.Time.get_frameDeltaTime();
	t.state = haxor.input.Input.InputStateFSM(current,d);
};
haxor.input.Input.GetAbsolutePosition = function(p_element,p_x,p_y) {
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
	return new haxor.math.Vector2(px,py);
};
haxor.input.Input.ProcessInput = function(p_event) {
	var me = p_event;
	var ke = p_event;
	haxor.input.Input.wheel = 0;
	haxor.input.Input.deltaMouse.x = 0;
	haxor.input.Input.deltaMouse.y = 0;
	var element = p_event.target;
	var _g = p_event.type;
	switch(_g) {
	case "wheel":case "mousewheel":case "DOMMouseScroll":
		var we = p_event;
		var dw;
		if(we.wheelDeltaY == null) dw = we.detail * 40; else dw = we.wheelDeltaY;
		haxor.input.Input.wheel = dw / 100.0;
		break;
	case "mousemove":
		var p = haxor.input.Input.GetAbsolutePosition(haxor.input.Input.m_target,me.pageX,me.pageY);
		haxor.input.Input.deltaMouse.x = p.x - haxor.input.Input.mouse.x;
		haxor.input.Input.deltaMouse.y = p.y - haxor.input.Input.mouse.y;
		haxor.input.Input.mouse.x = p.x;
		haxor.input.Input.mouse.y = p.y;
		haxor.input.Input.relativeMouse.x = haxor.input.Input.mouse.x / haxor.graphics.Screen.get_width();
		haxor.input.Input.relativeMouse.y = haxor.input.Input.mouse.y / haxor.graphics.Screen.get_height();
		break;
	case "mouseup":
		var _g1 = me.button;
		switch(_g1) {
		case 0:
			haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse0,false);
			break;
		case 1:
			haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse1,false);
			break;
		case 2:
			haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse2,false);
			break;
		case 3:
			haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse3,false);
			break;
		case 4:
			haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse4,false);
			break;
		}
		break;
	case "mousedown":
		var _g11 = me.button;
		switch(_g11) {
		case 0:
			haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse0,true);
			break;
		case 1:
			haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse1,true);
			break;
		case 2:
			haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse2,true);
			break;
		case 3:
			haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse3,true);
			break;
		case 4:
			haxor.input.Input.UpdateInputState(haxor.input.KeyCode.Mouse4,true);
			break;
		}
		break;
	case "keyup":
		haxor.input.Input.UpdateInputState(ke.keyCode,false);
		break;
	case "keydown":
		haxor.input.Input.UpdateInputState(ke.keyCode,true);
		break;
	}
};
haxor.input.Input.OnInput = function(p_event) {
	haxor.input.Input.m_eventStack.push(p_event);
	var is_mousedown = p_event.type == "mousedown";
	var is_mousewheel = p_event.type == "mousewheel" || p_event.type == "wheel";
	var prevent = (is_mousedown || is_mousewheel) && js.Boot.__instanceof(haxor.input.Input.m_target,HTMLCanvasElement);
	if(haxor.input.Input.scroll) prevent = false;
	if(prevent) {
		if(haxor.input.Input.relativeMouse.x >= 0) {
			if(haxor.input.Input.relativeMouse.x <= 1) {
				if(haxor.input.Input.relativeMouse.y >= 0) {
					if(haxor.input.Input.relativeMouse.y <= 1) p_event.preventDefault();
				}
			}
		}
	}
};
haxor.input.Input.OnTouch = function(p_event) {
	var te = p_event;
	var _g = p_event.type;
	switch(_g) {
	case "touchstart":
		haxor.input.Input.m_hasActiveTouches = true;
		haxor.input.Input.m_eventTouchList = te.touches;
		break;
	case "touchmove":
		haxor.input.Input.m_eventTouchList = te.touches;
		break;
	case "touchcancel":
		haxor.input.Input.m_eventTouchList = te.touches;
		break;
	case "touchend":
		haxor.input.Input.m_eventTouchList = te.touches;
		break;
	}
	if(haxor.input.Input.m_hasActiveTouches) {
		if(!haxor.input.Input.scroll) p_event.preventDefault();
	}
};
haxor.input.Input.InputStateFSM = function(p_current,p_is_down) {
	var current = p_current;
	var next = current;
	var d = p_is_down;
	switch(current[1]) {
	case 0:
		if(d) next = haxor.input.InputState.Down;
		break;
	case 1:
		if(!d) next = haxor.input.InputState.Up;
		next = haxor.input.InputState.Hold;
		break;
	case 2:
		next = haxor.input.InputState.None;
		break;
	case 3:
		if(!d) next = haxor.input.InputState.Up;
		break;
	}
	return next;
};
haxor.input.Input.UpdateInputState = function(p_code,p_is_down) {
	var current = haxor.input.Input.m_inputStateMap.get(p_code);
	if(current == null) current = haxor.input.InputState.None;
	var next = current;
	var d0 = haxor.input.Input.m_isDownList[p_code];
	var d = haxor.input.Input.m_isDownList[p_code] = p_is_down;
	if(!d0) {
		if(d) haxor.input.Input.m_activeInput.push(p_code);
	}
	if(!d) {
		if(d0) return;
	}
	if(current == haxor.input.InputState.Up) {
		haxor.input.Input.m_inputHoldMap.set(p_code,0);
		HxOverrides.remove(haxor.input.Input.m_activeInput,p_code);
	}
	if(current == haxor.input.InputState.Hold) {
		var h = haxor.input.Input.m_inputHoldMap.get(p_code);
		var value = h + haxor.core.Time.get_frameDeltaTime();
		haxor.input.Input.m_inputHoldMap.set(p_code,value);
	}
	next = haxor.input.Input.InputStateFSM(current,d);
	if(current != next) haxor.input.Input.m_inputStateMap.set(p_code,next);
};
haxor.input.Input.prototype = {
	OnInputEvent: function(p_event) {
		haxor.input.Input.m_eventStack.push(p_event);
		var prevent = p_event.type == "mousedown" || p_event.type == "mousewheel";
		if(prevent) {
			if(haxor.input.Input.relativeMouse.x >= 0) {
				if(haxor.input.Input.relativeMouse.x <= 1) {
					if(haxor.input.Input.relativeMouse.y >= 0) {
						if(haxor.input.Input.relativeMouse.y <= 1) p_event.preventDefault();
					}
				}
			}
		}
	}
	,__class__: haxor.input.Input
};
haxor.input.KeyCode = function() { };
$hxClasses["haxor.input.KeyCode"] = haxor.input.KeyCode;
haxor.input.KeyCode.__name__ = ["haxor","input","KeyCode"];
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
haxor.math.AABB2.__properties__ = {get_empty:"get_empty"}
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
		this.set_xMin(haxor.math.Mathf.Min([p_point.x,this.get_xMin()]));
		this.set_xMax(haxor.math.Mathf.Max([p_point.x,this.get_xMax()]));
		this.set_yMin(haxor.math.Mathf.Min([p_point.y,this.get_yMin()]));
		this.set_yMax(haxor.math.Mathf.Max([p_point.y,this.get_yMax()]));
	}
	,ToString: function() {
		var s0 = haxor.math.Mathf.RoundPlaces(this.m_xMin,null) + "";
		var s1 = haxor.math.Mathf.RoundPlaces(this.m_xMax,null) + "";
		var s2 = haxor.math.Mathf.RoundPlaces(this.m_yMin,null) + "";
		var s3 = haxor.math.Mathf.RoundPlaces(this.m_yMax,null) + "";
		return "[" + s0 + "," + s1 + "|" + s2 + "," + s3 + "]";
	}
	,__class__: haxor.math.AABB2
	,__properties__: {set_size:"set_size",get_size:"get_size",set_height:"set_height",get_height:"get_height",set_width:"set_width",get_width:"get_width",set_y:"set_y",get_y:"get_y",set_x:"set_x",get_x:"get_x",set_center:"set_center",get_center:"get_center",set_yMax:"set_yMax",get_yMax:"get_yMax",set_xMax:"set_xMax",get_xMax:"get_xMax",set_yMin:"set_yMin",get_yMin:"get_yMin",set_xMin:"set_xMin",get_xMin:"get_xMin",set_max:"set_max",get_max:"get_max",set_min:"set_min",get_min:"get_min",get_clone:"get_clone"}
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
haxor.math.AABB3.__properties__ = {get_empty:"get_empty"}
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
	b.set_width(p_width);
	b.set_height(p_height);
	b.set_depth(p_depth);
	b.set_center(new haxor.math.Vector3(p_x,p_y,p_z));
	return b;
};
haxor.math.AABB3.get_empty = function() {
	return new haxor.math.AABB3();
};
haxor.math.AABB3.prototype = {
	get_clone: function() {
		return haxor.math.AABB3.FromMinMax(this.get_xMin(),this.get_xMax(),this.get_yMin(),this.get_yMax(),this.get_zMin(),this.get_zMax());
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
		return haxor.math.Vector3.get_temp().Set(this.get_xMin() + (this.get_xMax() - this.get_xMin()) * 0.5,this.get_yMin() + (this.get_yMax() - this.get_yMin()) * 0.5,this.get_zMin() + (this.get_zMax() - this.get_zMin()) * 0.5);
	}
	,set_center: function(v) {
		var hw = this.get_width() * 0.5;
		var hh = this.get_height() * 0.5;
		var hd = this.get_depth() * 0.5;
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
	,get_z: function() {
		return this.get_zMin();
	}
	,set_z: function(v) {
		this.set_zMin(v);
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
	,get_depth: function() {
		return haxor.math.Mathf.Abs(this.get_zMax() - this.get_zMin());
	}
	,set_depth: function(v) {
		this.set_zMax(this.get_zMin() + v);
		return v;
	}
	,get_size: function() {
		return haxor.math.Vector3.get_temp().Set(this.get_width(),this.get_height(),this.get_depth());
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
	,Encapsulate: function(p_point) {
		this.Encapsulate3(p_point.x,p_point.y,p_point.z);
	}
	,Add: function(p_v) {
		this.m_xMax = haxor.math.Mathf.Max([p_v.m_xMax,this.m_xMax]);
		this.m_xMin = haxor.math.Mathf.Min([p_v.m_xMin,this.m_xMin]);
		this.m_yMax = haxor.math.Mathf.Max([p_v.m_yMax,this.m_yMax]);
		this.m_yMin = haxor.math.Mathf.Min([p_v.m_yMin,this.m_yMin]);
		this.m_zMax = haxor.math.Mathf.Max([p_v.m_zMax,this.m_zMax]);
		this.m_zMin = haxor.math.Mathf.Min([p_v.m_zMin,this.m_zMin]);
		return this;
	}
	,Encapsulate3: function(p_x,p_y,p_z) {
		if(p_z == null) p_z = 0;
		if(p_y == null) p_y = 0;
		if(p_x == null) p_x = 0;
		this.set_xMin(haxor.math.Mathf.Min([p_x,this.get_xMin()]));
		this.set_xMax(haxor.math.Mathf.Max([p_x,this.get_xMax()]));
		this.set_yMin(haxor.math.Mathf.Min([p_y,this.get_yMin()]));
		this.set_yMax(haxor.math.Mathf.Max([p_y,this.get_yMax()]));
		this.set_zMin(haxor.math.Mathf.Min([p_z,this.get_zMin()]));
		this.set_zMax(haxor.math.Mathf.Max([p_z,this.get_zMax()]));
	}
	,ToString: function() {
		var s0 = haxor.math.Mathf.RoundPlaces(this.m_xMin,4) + "";
		var s1 = haxor.math.Mathf.RoundPlaces(this.m_xMax,4) + "";
		var s2 = haxor.math.Mathf.RoundPlaces(this.m_yMin,4) + "";
		var s3 = haxor.math.Mathf.RoundPlaces(this.m_yMax,4) + "";
		var s4 = haxor.math.Mathf.RoundPlaces(this.m_zMin,4) + "";
		var s5 = haxor.math.Mathf.RoundPlaces(this.m_zMax,4) + "";
		return "[" + s0 + "," + s1 + "|" + s2 + "," + s3 + "|" + s4 + "," + s5 + "]";
	}
	,toString: function() {
		return this.ToString();
	}
	,__class__: haxor.math.AABB3
	,__properties__: {set_size:"set_size",get_size:"get_size",set_depth:"set_depth",get_depth:"get_depth",set_height:"set_height",get_height:"get_height",set_width:"set_width",get_width:"get_width",set_z:"set_z",get_z:"get_z",set_y:"set_y",get_y:"get_y",set_x:"set_x",get_x:"get_x",set_center:"set_center",get_center:"get_center",set_zMax:"set_zMax",get_zMax:"get_zMax",set_yMax:"set_yMax",get_yMax:"get_yMax",set_xMax:"set_xMax",get_xMax:"get_xMax",set_zMin:"set_zMin",get_zMin:"get_zMin",set_yMin:"set_yMin",get_yMin:"get_yMin",set_xMin:"set_xMin",get_xMin:"get_xMin",set_max:"set_max",get_max:"get_max",set_min:"set_min",get_min:"get_min",get_clone:"get_clone"}
};
haxor.math.Easing = function() { };
$hxClasses["haxor.math.Easing"] = haxor.math.Easing;
haxor.math.Easing.__name__ = ["haxor","math","Easing"];
haxor.math.Trig = function() { };
$hxClasses["haxor.math.Trig"] = haxor.math.Trig;
haxor.math.Trig.__name__ = ["haxor","math","Trig"];
haxor.math.Trig.Acos = function(v) {
	return haxor.math.Mathf.Acos(-2 * v + 1.0) * haxor.math.Mathf.InvPI;
};
haxor.math.Trig.AcosQuad = function(v) {
	return haxor.math.Mathf.Pow(haxor.math.Trig.Acos(v),2.0);
};
haxor.math.Trig.AcosRad = function(v) {
	return haxor.math.Mathf.Pow(haxor.math.Trig.Acos(v),0.5);
};
haxor.math.Trig.Cos = function(v) {
	return (-haxor.math.Mathf.Cos(v * haxor.math.Mathf.PI) + 1.0) * 0.5;
};
haxor.math.Cubic = function() { };
$hxClasses["haxor.math.Cubic"] = haxor.math.Cubic;
haxor.math.Cubic.__name__ = ["haxor","math","Cubic"];
haxor.math.Cubic.In = function(p_r) {
	return p_r * p_r * p_r;
};
haxor.math.Cubic.Out = function(p_r) {
	return p_r * (p_r * (p_r - 3) + 3);
};
haxor.math.Cubic.InOut = function(p_r) {
	return -2 * p_r * (p_r * (p_r - 1.5));
};
haxor.math.Cubic.OutIn = function(p_r) {
	return p_r * (p_r * (4 * p_r - 6) + 3);
};
haxor.math.Cubic.BackIn = function(p_r) {
	return p_r * (p_r * (4 * p_r - 3));
};
haxor.math.Cubic.OutBack = function(p_r) {
	return p_r * (p_r * (4 * p_r - 9) + 6);
};
haxor.math.Elastic = function() { };
$hxClasses["haxor.math.Elastic"] = haxor.math.Elastic;
haxor.math.Elastic.__name__ = ["haxor","math","Elastic"];
haxor.math.Elastic.OutBig = function(p_r) {
	return p_r * (p_r * (p_r * (p_r * (56 * p_r + -175) + 200) + -100) + 20);
};
haxor.math.Elastic.OutSmall = function(p_r) {
	return p_r * (p_r * (p_r * (p_r * (33 * p_r + -106) + 126) + -67) + 15);
};
haxor.math.Elastic.InBig = function(p_r) {
	return p_r * (p_r * (p_r * (p_r * (33 * p_r + -59) + 32) + -5));
};
haxor.math.Elastic.InSmall = function(p_r) {
	return p_r * (p_r * (p_r * (p_r * (56 * p_r + -105) + 60) + -10));
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
haxor.math.Mathf.Min = function(p_v) {
	if(p_v.length <= 0) return 0;
	if(p_v.length <= 1) return p_v[0];
	var m = p_v[0];
	var i = 0;
	var _g1 = 1;
	var _g = p_v.length;
	while(_g1 < _g) {
		var i1 = _g1++;
		if(m > p_v[i1]) m = p_v[i1]; else m = m;
	}
	return m;
};
haxor.math.Mathf.MinInt = function(p_v) {
	if(p_v.length <= 0) return 0;
	if(p_v.length <= 1) return p_v[0];
	var m = p_v[0];
	var i = 0;
	var _g1 = 1;
	var _g = p_v.length;
	while(_g1 < _g) {
		var i1 = _g1++;
		if(m > p_v[i1]) m = p_v[i1]; else m = m;
	}
	return m | 0;
};
haxor.math.Mathf.MinMax = function(p_v) {
	if(p_v.length <= 0) return [];
	if(p_v.length <= 1) return [p_v[0],p_v[0]];
	var m0 = p_v[0];
	var m1 = p_v[0];
	var i = 0;
	var _g1 = 1;
	var _g = p_v.length;
	while(_g1 < _g) {
		var i1 = _g1++;
		if(m0 < p_v[i1]) m0 = p_v[i1]; else m0 = m0;
		if(m1 > p_v[i1]) m1 = p_v[i1]; else m1 = m1;
	}
	return [m0,m1];
};
haxor.math.Mathf.Max = function(p_v) {
	if(p_v.length <= 0) return 0;
	if(p_v.length <= 1) return p_v[0];
	var m = p_v[0];
	var i = 0;
	var _g1 = 1;
	var _g = p_v.length;
	while(_g1 < _g) {
		var i1 = _g1++;
		if(m < p_v[i1]) m = p_v[i1]; else m = m;
	}
	return m;
};
haxor.math.Mathf.MaxInt = function(p_v) {
	if(p_v.length <= 0) return 0;
	if(p_v.length <= 1) return p_v[0];
	var m = p_v[0];
	var i = 0;
	var _g1 = 1;
	var _g = p_v.length;
	while(_g1 < _g) {
		var i1 = _g1++;
		if(m < p_v[i1]) m = p_v[i1]; else m = m;
	}
	return m | 0;
};
haxor.math.Mathf.SinDeg = function(p_v) {
	return haxor.math.Mathf.Sin(p_v * haxor.math.Mathf.Deg2Rad);
};
haxor.math.Mathf.CosDeg = function(p_v) {
	return haxor.math.Mathf.Cos(p_v * haxor.math.Mathf.Deg2Rad);
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
	var d = haxor.math.Mathf.Pow(10,p_decimal_places);
	return haxor.math.Mathf.Round(p_v * d) / d;
};
haxor.math.Mathf.Lerp = function(p_a,p_b,p_ratio) {
	return p_a + (p_b - p_a) * p_ratio;
};
haxor.math.Mathf.LerpInt = function(p_a,p_b,p_ratio) {
	return js.Boot.__cast(haxor.math.Mathf.Lerp(js.Boot.__cast(p_a , Float),js.Boot.__cast(p_b , Float),p_ratio) , Int);
};
haxor.math.Mathf.Frac = function(p_v) {
	return p_v - (p_v | 0);
};
haxor.math.Mathf.Loop = function(p_v,p_v0,p_v1) {
	var vv0 = Math.min(p_v0,p_v1);
	var vv1 = Math.max(p_v0,p_v1);
	var dv = vv1 - vv0;
	if(dv <= 0) return vv0;
	var n = (p_v - p_v0) / dv;
	var r;
	if(p_v < 0) r = 1.0 - haxor.math.Mathf.Frac(n < 0?-n:n); else r = n - (n | 0);
	return p_v0 + (p_v1 - p_v0) * r;
};
haxor.math.Mathf.Linear2Gamma = function(p_v) {
	return haxor.math.Mathf.Pow(p_v,2.2);
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
	this.m = new Float32Array(16);
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
haxor.math.Matrix4.__properties__ = {get_identity:"get_identity",get_temp:"get_temp"}
haxor.math.Matrix4.get_temp = function() {
	if(haxor.math.Matrix4.m_temp == null) {
		haxor.math.Matrix4.m_temp = [];
		haxor.math.Matrix4.m_nexttemp = 0;
		var _g = 0;
		while(_g < 150000) {
			var i = _g++;
			haxor.math.Matrix4.m_temp.push(haxor.math.Matrix4.get_identity());
		}
	}
	var m = haxor.math.Matrix4.m_temp[haxor.math.Matrix4.m_nexttemp];
	haxor.math.Matrix4.m_nexttemp = (haxor.math.Matrix4.m_nexttemp + 1) % haxor.math.Matrix4.m_temp.length;
	return m;
};
haxor.math.Matrix4.get_identity = function() {
	return new haxor.math.Matrix4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
};
haxor.math.Matrix4.Parse = function(p_data,p_delimiter) {
	if(p_delimiter == null) p_delimiter = " ";
	var tk = p_data.split(p_delimiter);
	var res = haxor.math.Matrix4.get_identity();
	var _g1 = 0;
	var _g = tk.length;
	while(_g1 < _g) {
		var i = _g1++;
		var n = Std.parseFloat(StringTools.trim(tk[i]));
		res.SetIndex(i,n);
	}
	return res;
};
haxor.math.Matrix4.FromArray = function(p_array) {
	var res = new haxor.math.Matrix4();
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
	var r = p_rotation.get_matrix();
	var l;
	if(p_result == null) l = haxor.math.Matrix4.get_identity(); else l = p_result;
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
haxor.math.Matrix4.GetInverseTransform = function(p_matrix,p_result) {
	var result;
	if(p_result == null) result = haxor.math.Matrix4.get_identity(); else result = p_result;
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
haxor.math.Matrix4.LookRotation = function(p_forward,p_up) {
	return haxor.math.Matrix4.LookAt(haxor.math.Vector3.get_zero(),p_forward,p_up);
};
haxor.math.Matrix4.LookAt = function(p_from,p_at,p_up) {
	if(p_up == null) p_up = haxor.math.Vector3.get_up(); else p_up = p_up;
	var vz = p_at.get_clone().Sub(p_from).Normalize().Invert();
	var vx = haxor.math.Vector3.Cross(p_up,vz).Normalize();
	var vy = haxor.math.Vector3.Cross(vz,vx);
	var m = new haxor.math.Matrix4();
	m.Set(vx.x,vy.x,vz.x,-haxor.math.Vector3.Dot(vx,p_from),vx.y,vy.y,vz.y,-haxor.math.Vector3.Dot(vy,p_from),vx.z,vy.z,vz.z,-haxor.math.Vector3.Dot(vz,p_from),0,0,0,1);
	return m;
};
haxor.math.Matrix4.prototype = {
	get_clone: function() {
		return new haxor.math.Matrix4(this.m00,this.m01,this.m02,this.m03,this.m10,this.m11,this.m12,this.m13,this.m20,this.m21,this.m22,this.m23,this.m30,this.m31,this.m32,this.m33);
	}
	,get_euler: function() {
		var m = this.get_rotation();
		var e = haxor.math.Vector3.get_zero();
		e.x = haxor.math.Mathf.Atan2(m.m12,m.m22);
		var c2 = haxor.math.Mathf.Sqrt(m.m00 * m.m00 + m.m01 * m.m01);
		e.y = haxor.math.Mathf.Atan2(-m.m02,c2);
		var s1 = haxor.math.Mathf.Sin(e.x);
		var c1 = haxor.math.Mathf.Cos(e.x);
		e.z = haxor.math.Mathf.Atan2(s1 * m.m20 - c1 * m.m10,c1 * m.m11 - s1 * m.m21);
		e.x = e.x * haxor.math.Mathf.Rad2Deg;
		e.y = e.y * haxor.math.Mathf.Rad2Deg;
		e.z = e.z * haxor.math.Mathf.Rad2Deg;
		return e;
	}
	,get_quaternion: function() {
		var b = this.ToBuffer();
		var m = this.ToRotation();
		var q = new haxor.math.Quaternion();
		var diag = m.m00 + m.m11 + m.m22 + 1.0;
		var e = 0;
		if(diag > e) {
			q.w = haxor.math.Mathf.Sqrt(diag) / 2.0;
			var w4 = 4.0 * q.w;
			q.x = (m.m21 - m.m12) / w4;
			q.y = (m.m02 - m.m20) / w4;
			q.z = (m.m10 - m.m01) / w4;
		} else {
			var d01 = m.m00 - m.m11;
			var d02 = m.m00 - m.m22;
			var d12 = m.m11 - m.m22;
			if(d01 > e && d02 > e) {
				var scale = haxor.math.Mathf.Sqrt(1.0 + m.m00 - m.m11 - m.m22) * 2.0;
				q.x = 0.25 * scale;
				q.y = (m.m10 + m.m01) / scale;
				q.z = (m.m02 + m.m20) / scale;
				q.w = (m.m12 - m.m21) / scale;
			} else if(d12 > e) {
				var scale1 = haxor.math.Mathf.Sqrt(1.0 + m.m11 - m.m00 - m.m22) * 2.0;
				q.x = (m.m10 + m.m01) / scale1;
				q.y = 0.25 * scale1;
				q.z = (m.m21 + m.m12) / scale1;
				q.w = (m.m20 - m.m02) / scale1;
			} else {
				var scale2 = haxor.math.Mathf.Sqrt(1.0 + m.m22 - m.m00 - m.m11) * 2.0;
				q.x = (m.m20 + m.m02) / scale2;
				q.y = (m.m21 + m.m12) / scale2;
				q.z = 0.25 * scale2;
				q.w = (m.m01 - m.m10) / scale2;
			}
		}
		var _g1 = 0;
		var _g = b.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.SetIndex(i,b[i]);
		}
		q.Normalize();
		return q;
	}
	,get_trace: function() {
		return this.m00 + this.m11 + this.m22 + this.m33;
	}
	,get_rotation: function() {
		var m = this.get_clone();
		return m.ToRotation();
	}
	,get_scale: function() {
		var d0 = Math.sqrt(this.m00 * this.m00 + this.m10 * this.m10 + this.m20 * this.m20);
		var d1 = Math.sqrt(this.m01 * this.m01 + this.m11 * this.m11 + this.m21 * this.m21);
		var d2 = Math.sqrt(this.m02 * this.m02 + this.m12 * this.m12 + this.m22 * this.m22);
		return haxor.math.Matrix4.get_temp().Set(d0,0,0,0,0,d1,0,0,0,0,d2,0,0,0,0,1);
	}
	,get_translation: function() {
		var t0 = this.m03;
		var t1 = this.m13;
		var t2 = this.m23;
		return new haxor.math.Matrix4(1,0,0,t0,0,1,0,t1,0,0,1,t2,0,0,0,1);
	}
	,get_transform: function() {
		return [this.GetColumn(3).get_xyz(),this.get_quaternion(),this.get_diagonalLR()];
	}
	,get_inverseTransform: function() {
		var result = haxor.math.Matrix4.get_identity();
		var l0 = new haxor.math.Vector3(this.m00,this.m01,this.m02);
		var l1 = new haxor.math.Vector3(this.m10,this.m11,this.m12);
		var l2 = new haxor.math.Vector3(this.m20,this.m21,this.m22);
		var vl0 = l0.get_length();
		var vl1 = l1.get_length();
		var vl2 = l2.get_length();
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
	,GetLine: function(p_index) {
		return new haxor.math.Vector4(this.GetRowCol(p_index,0),this.GetRowCol(p_index,1),this.GetRowCol(p_index,2),this.GetRowCol(p_index,3));
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
	,GetColumn: function(p_index) {
		return new haxor.math.Vector4(this.GetRowCol(0,p_index),this.GetRowCol(1,p_index),this.GetRowCol(2,p_index),this.GetRowCol(3,p_index));
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
		this.Set(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
		return this;
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
	}
	,SetRowCol: function(p_row,p_col,p_value) {
		this.SetIndex(p_col + (p_row << 2),p_value);
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
		this.Set(t00,t10,t20,t30,t01,t11,t21,t31,t02,t12,t22,t32,t03,t13,t23,t33);
		return this;
	}
	,ToRotation: function() {
		var tmp = new haxor.math.Vector3();
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
		var tmp = new haxor.math.Vector3();
		tmp.Set(this.m00,this.m01,this.m02).Normalize();
		var vx = tmp.x * p_vector.x + tmp.y * p_vector.y + tmp.z * p_vector.z;
		tmp.Set(this.m10,this.m11,this.m12).Normalize();
		var vy = tmp.x * p_vector.x + tmp.y * p_vector.y + tmp.z * p_vector.z;
		tmp.Set(this.m20,this.m21,this.m22).Normalize();
		var vz = tmp.x * p_vector.x + tmp.y * p_vector.y + tmp.z * p_vector.z;
		p_vector.x = vx;
		p_vector.y = vy;
		p_vector.z = vz;
		return p_vector;
	}
	,SetTRS: function(p_position,p_rotation,p_scale) {
		var sx;
		if(p_scale == null) sx = 1.0; else sx = p_scale.x;
		var sy;
		if(p_scale == null) sy = 1.0; else sy = p_scale.y;
		var sz;
		if(p_scale == null) sz = 1.0; else sz = p_scale.z;
		var px = p_position.x;
		var py = p_position.y;
		var pz = p_position.z;
		var r = p_rotation.get_matrix();
		var l = this;
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
	,SetFrustum: function(p_left,p_right,p_top,p_bottom,p_near,p_far) {
		this.SetIdentity();
		var n2 = p_near * 2.0;
		var rml = 1.0 / (p_right - p_left);
		var tmb = 1.0 / (p_top - p_bottom);
		var fmn = 1.0 / (p_far - p_near);
		this.m00 = n2 * rml;
		this.m02 = (p_right + p_left) * rml;
		this.m11 = n2 * tmb;
		this.m12 = (p_top + p_bottom) * tmb;
		this.m22 = -(p_near + p_far) * fmn;
		this.m23 = -n2 * p_far * fmn;
		this.m32 = -1.0;
		this.m33 = 0;
		return this;
	}
	,SetFrustumInverse: function(p_left,p_right,p_top,p_bottom,p_near,p_far) {
		this.SetIdentity();
		var n2 = p_near * 2.0;
		var rml = p_right - p_left;
		var tmb = p_top - p_bottom;
		var fmn = p_far - p_near;
		this.m00 = rml / n2;
		this.m03 = (p_right + p_left) / n2;
		this.m11 = tmb / n2;
		this.m13 = (p_top + p_bottom) / n2;
		this.m22 = 0.0;
		this.m23 = -1.0;
		this.m32 = fmn / (-n2 * p_far);
		this.m33 = (p_far + p_near) / (n2 * p_far);
		return this;
	}
	,SetOrtho: function(p_left,p_right,p_top,p_bottom,p_near,p_far) {
		this.SetIdentity();
		var n2 = p_near * 2.0;
		var rml = 1.0 / (p_right - p_left);
		var tmb = 1.0 / (p_top - p_bottom);
		var fmn = 1.0 / (p_far - p_near);
		this.m00 = 2.0 * rml;
		this.m03 = -(p_right + p_left) * rml;
		this.m11 = 2.0 * tmb;
		this.m13 = -(p_top + p_bottom) * tmb;
		this.m22 = -2. * fmn;
		this.m23 = -(p_far + p_near) * fmn;
		return this;
	}
	,SetPerspective: function(p_fov,p_aspect,p_near,p_far) {
		var t = haxor.math.Mathf.Tan(p_fov * 0.5 * haxor.math.Mathf.Deg2Rad) * p_near;
		var b = -t;
		var l = p_aspect * b;
		var r = p_aspect * t;
		return this.SetFrustum(l,r,t,b,p_near,p_far);
	}
	,SetPerspectiveInverse: function(p_fov,p_aspect,p_near,p_far) {
		var t = haxor.math.Mathf.Tan(p_fov * 0.5 * haxor.math.Mathf.Deg2Rad) * p_near;
		var b = -t;
		var l = p_aspect * b;
		var r = p_aspect * t;
		return this.SetFrustumInverse(l,r,t,b,p_near,p_far);
	}
	,ToArray: function() {
		return [this.m00,this.m01,this.m02,this.m03,this.m10,this.m11,this.m12,this.m13,this.m20,this.m21,this.m22,this.m23,this.m30,this.m31,this.m32,this.m33];
	}
	,ToBuffer: function() {
		this.m[0] = this.m00;
		this.m[1] = this.m01;
		this.m[2] = this.m02;
		this.m[3] = this.m03;
		this.m[4] = this.m10;
		this.m[5] = this.m11;
		this.m[6] = this.m12;
		this.m[7] = this.m13;
		this.m[8] = this.m20;
		this.m[9] = this.m21;
		this.m[10] = this.m22;
		this.m[11] = this.m23;
		this.m[12] = this.m30;
		this.m[13] = this.m31;
		this.m[14] = this.m32;
		this.m[15] = this.m33;
		return this.m;
	}
	,ToString: function(p_linear) {
		if(p_linear == null) p_linear = true;
		var a = this.ToArray();
		var s = [];
		var _g1 = 0;
		var _g = a.length;
		while(_g1 < _g) {
			var i = _g1++;
			a[i] = (a[i] * 100.0 | 0) / 100;
			s.push(a[i] >= 0?" " + a[i]:a[i] + "");
		}
		var res = "";
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
		return res;
	}
	,__class__: haxor.math.Matrix4
	,__properties__: {set_diagonalLR:"set_diagonalLR",get_diagonalLR:"get_diagonalLR",get_transposed:"get_transposed",get_inverseTransform:"get_inverseTransform",get_transform:"get_transform",get_translation:"get_translation",get_scale:"get_scale",get_rotation:"get_rotation",get_trace:"get_trace",get_quaternion:"get_quaternion",get_euler:"get_euler",get_clone:"get_clone"}
};
haxor.math.Vector2 = function(p_x,p_y) {
	if(p_y == null) p_y = 0;
	if(p_x == null) p_x = 0;
	this.x = p_x;
	this.y = p_y;
};
$hxClasses["haxor.math.Vector2"] = haxor.math.Vector2;
haxor.math.Vector2.__name__ = ["haxor","math","Vector2"];
haxor.math.Vector2.__properties__ = {get_Up:"get_Up",get_Right:"get_Right",get_zero:"get_zero"}
haxor.math.Vector2.get_zero = function() {
	return new haxor.math.Vector2(0,0);
};
haxor.math.Vector2.get_Right = function() {
	return new haxor.math.Vector2(1,0);
};
haxor.math.Vector2.get_Up = function() {
	return new haxor.math.Vector2(0,1);
};
haxor.math.Vector2.Lerp = function(p_a,p_b,p_r) {
	return new haxor.math.Vector2(p_a.x + (p_b.x - p_a.x) * p_r,p_a.y + (p_b.y - p_a.y) * p_r);
};
haxor.math.Vector2.prototype = {
	get_clone: function() {
		return new haxor.math.Vector2(this.x,this.y);
	}
	,get_length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y);
	}
	,get_normalized: function() {
		return this.get_clone().Normalize();
	}
	,Normalize: function() {
		var l = this.get_length();
		if(l <= 0) return this;
		this.x *= l = 1.0 / l;
		this.y *= l;
		return this;
	}
	,ToArray: function() {
		return [this.x,this.y];
	}
	,ToString: function() {
		var a = this.ToArray();
		var s = [];
		var _g1 = 0;
		var _g = a.length;
		while(_g1 < _g) {
			var i = _g1++;
			a[i] = (a[i] * 100.0 | 0) / 100;
			s.push(a[i] >= 0?" " + a[i]:a[i] + "");
		}
		var res = "[";
		var _g11 = 0;
		var _g2 = a.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			res += s[i1] + (i1 < a.length - 1?",":"]");
		}
		return res;
	}
	,__class__: haxor.math.Vector2
	,__properties__: {get_normalized:"get_normalized",get_length:"get_length",get_clone:"get_clone"}
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
haxor.math.Vector4.__properties__ = {get_zero:"get_zero",get_temp:"get_temp"}
haxor.math.Vector4.get_temp = function() {
	if(haxor.math.Vector4.m_temp == null) {
		haxor.math.Vector4.m_temp = [];
		haxor.math.Vector4.m_nexttemp = 0;
		var _g = 0;
		while(_g < 50000) {
			var i = _g++;
			haxor.math.Vector4.m_temp.push(haxor.math.Vector4.get_zero());
		}
	}
	var t = haxor.math.Vector4.m_temp[haxor.math.Vector4.m_nexttemp];
	haxor.math.Vector4.m_nexttemp = (haxor.math.Vector4.m_nexttemp + 1) % haxor.math.Vector4.m_temp.length;
	return t;
};
haxor.math.Vector4.get_zero = function() {
	return new haxor.math.Vector4(0,0,0,0);
};
haxor.math.Vector4.Lerp = function(p_a,p_b,p_r) {
	return new haxor.math.Vector4(p_a.x + (p_b.x - p_a.x) * p_r,p_a.y + (p_b.y - p_a.y) * p_r,p_a.z + (p_b.z - p_a.z) * p_r,p_a.w + (p_b.w - p_a.w) * p_r);
};
haxor.math.Vector4.prototype = {
	get_clone: function() {
		return new haxor.math.Vector4(this.x,this.y,this.z,this.w);
	}
	,get_rgba: function() {
		return new haxor.math.Color(this.x,this.y,this.z,this.w);
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
	,get_normalized: function() {
		return this.get_clone().Normalize();
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
	,Add: function(p_v) {
		this.x += p_v.x;
		this.y += p_v.y;
		this.z += p_v.z;
		this.w += p_v.w;
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
		var l = this.get_length();
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
	,ToString: function() {
		var a = this.ToArray();
		var s = [];
		var _g1 = 0;
		var _g = a.length;
		while(_g1 < _g) {
			var i = _g1++;
			a[i] = (a[i] * 100.0 | 0) / 100;
			s.push(a[i] >= 0?" " + a[i]:a[i] + "");
		}
		var res = "[";
		var _g11 = 0;
		var _g2 = a.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			res += s[i1] + (i1 < a.length - 1?",":"]");
		}
		return res;
	}
	,__class__: haxor.math.Vector4
	,__properties__: {get_normalized:"get_normalized",get_length:"get_length",get_xy:"get_xy",get_xyz:"get_xyz",get_rgba:"get_rgba",get_clone:"get_clone"}
};
haxor.media = {};
haxor.media.Sound = function(p_clip) {
	haxor.core.Resource.call(this);
	if(haxor.media.Sound.m_list == null) haxor.media.Sound.m_list = [];
	this.m_clip = p_clip;
	if(this.m_clip != null) {
		this.set_name(this.m_clip.id);
		this.m_volume = this.m_clip.volume;
		this.m_loop = this.m_clip.loop;
		this.m_clip.addEventListener("ended",$bind(this,this.OnSoundEnd));
		this.m_clip.addEventListener("timeupdate",$bind(this,this.OnSoundUpdate));
		this.m_clip.loop = false;
	}
	this.repeat = 0;
	this.m_repeat_count = 0;
	haxor.media.Sound.m_list.push(this);
};
$hxClasses["haxor.media.Sound"] = haxor.media.Sound;
haxor.media.Sound.__name__ = ["haxor","media","Sound"];
haxor.media.Sound.__properties__ = {set_main:"set_main",get_main:"get_main"}
haxor.media.Sound.get_main = function() {
	return haxor.media.Sound.m_main;
};
haxor.media.Sound.set_main = function(v) {
	haxor.media.Sound.m_main = v;
	if(haxor.media.Sound.m_list != null) {
		var _g1 = 0;
		var _g = haxor.media.Sound.m_list.length;
		while(_g1 < _g) {
			var i = _g1++;
			haxor.media.Sound.m_list[i].UpdateVolume();
		}
	}
	return haxor.media.Sound.m_main;
};
haxor.media.Sound.__super__ = haxor.core.Resource;
haxor.media.Sound.prototype = $extend(haxor.core.Resource.prototype,{
	get_volume: function() {
		return this.m_volume;
	}
	,set_volume: function(v) {
		this.m_volume = v;
		this.UpdateVolume();
		return v;
	}
	,get_time: function() {
		if(this.m_clip == null) return 0.0; else return this.m_clip.currentTime;
	}
	,set_time: function(v) {
		if(this.m_clip == null) return 0.0; else return this.m_clip.currentTime = haxor.math.Mathf.Max([v,this.m_clip.startTime]);
	}
	,get_loop: function() {
		return this.m_loop;
	}
	,set_loop: function(v) {
		this.m_loop = v;
		return v;
	}
	,get_clip: function() {
		return this.m_clip;
	}
	,Play: function(p_time) {
		if(p_time == null) p_time = 0.0;
		if(this.m_clip == null) return;
		this.set_time(p_time);
		this.m_clip.play();
		this.UpdateVolume();
	}
	,Pause: function() {
		if(this.m_clip == null) return;
		if(this.m_clip.paused) this.m_clip.play(); else this.m_clip.pause();
	}
	,Stop: function() {
		if(this.m_clip == null) return;
		this.set_time(0.0);
		this.m_repeat_count = 0;
		this.m_clip.pause();
	}
	,UpdateVolume: function() {
		if(this.m_clip == null) return;
		this.m_clip.volume = this.m_volume * haxor.media.Sound.m_main;
	}
	,OnSoundEnd: function(e) {
	}
	,OnSoundUpdate: function(e) {
		if(this.m_loop) {
			if(this.m_clip.duration - this.m_clip.currentTime <= 0.1) {
				if(this.repeat > 0) {
					this.m_repeat_count++;
					if(this.m_repeat_count <= this.repeat) {
						console.log(this.m_repeat_count);
						this.Play();
					} else {
						this.m_repeat_count = 0;
						this.Stop();
					}
				} else this.Play();
			}
		}
	}
	,OnDestroy: function() {
		haxor.core.Resource.prototype.OnDestroy.call(this);
		this.Stop();
		if(this.m_clip != null) {
			this.m_clip.parentElement.removeChild(this.m_clip);
			this.m_clip = null;
		}
	}
	,__class__: haxor.media.Sound
	,__properties__: $extend(haxor.core.Resource.prototype.__properties__,{get_clip:"get_clip",set_loop:"set_loop",get_loop:"get_loop",set_time:"set_time",get_time:"get_time",set_volume:"set_volume",get_volume:"get_volume"})
});
haxor.net = {};
haxor.net.Web = function() { };
$hxClasses["haxor.net.Web"] = haxor.net.Web;
haxor.net.Web.__name__ = ["haxor","net","Web"];
haxor.net.Web.InternalLoad = function(p_url,p_binary) {
	if(p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url,"./",haxor.net.Web.root);
	var req = new XMLHttpRequest();
	if(req.withCredentials) req.withCredentials = false;
	if($bind(req,req.overrideMimeType) != null) req.overrideMimeType(p_binary?"application/octet-stream":"text/plain");
	req.open("get",p_url,true);
	return req;
};
haxor.net.Web.Load = function(p_url,p_callback) {
	var req = haxor.net.Web.InternalLoad(p_url,false);
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
	if(haxor.net.Web.m_autoload) req.send();
	return req;
};
haxor.net.Web.LoadBinary = function(p_url,p_callback) {
	var req = haxor.net.Web.InternalLoad(p_url,true);
	req.onprogress = function(e) {
		var f;
		if(e.total <= 0) f = 0; else f = e.loaded / (e.total + 5);
		p_callback(null,f);
	};
	req.onload = function(e1) {
		var a;
		if(req.response == null) a = null; else a = new Uint8Array(req.response);
		p_callback(a,1.0);
	};
	req.onerror = function(e2) {
		p_callback(null,1.0);
	};
	if(haxor.net.Web.m_autoload) req.send();
	return req;
};
haxor.net.Web.LoadXML = function(p_url,p_callback) {
	var res;
	var req;
	req = haxor.net.Web.Load(p_url,function(d,p) {
		if(p >= 1.0) {
			if(d == null) res = null; else res = Xml.parse(d);
		} else res = null;
		p_callback(res,p);
	});
	return req;
};
haxor.net.Web.LoadCollada = function(p_url,p_callback) {
	var res;
	var req;
	req = haxor.net.Web.Load(p_url,function(d,p) {
		if(p >= 1.0) {
			if(d == null) res = null; else res = new haxor.importer.ColladaFile(d);
		} else res = null;
		p_callback(res,p);
	});
	return req;
};
haxor.net.Web.LoadMaterial = function(p_url,p_callback) {
	var res;
	var req;
	req = haxor.net.Web.Load(p_url,function(d,p) {
		if(p >= 1.0) {
			if(d == null) res = null; else res = new haxor.importer.MaterialFile(d);
		} else res = null;
		p_callback(res,p);
	});
	return req;
};
haxor.net.Web.LoadJSON = function(p_url,p_callback) {
	var res;
	var req;
	req = haxor.net.Web.Load(p_url,function(d,p) {
		if(p >= 1.0) {
			if(d == null) res = null; else res = haxor.core.JSON.FromJSON(d);
		} else res = null;
		p_callback(res,p);
	});
	return req;
};
haxor.net.Web.LoadShader = function(p_url,p_callback) {
	var res;
	var req;
	req = haxor.net.Web.Load(p_url,function(d,p) {
		if(p >= 1.0) {
			if(d == null) res = haxor.graphics.Shader.get_error(); else res = new haxor.graphics.Shader(d);
		} else res = null;
		p_callback(res,p);
	});
	return req;
};
haxor.net.Web.LoadTextureHTML = function(p_url,p_callback) {
	var img = new Image();
	if(p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url,"./",haxor.net.Web.root);
	img.onload = function(e) {
		var tex = new haxor.texture.TextureHTML(img);
		p_callback(tex,1);
	};
	img.onerror = function(e1) {
		p_callback(null,1.0);
	};
	img.crossOrigin = "anonymous";
	if(haxor.net.Web.m_autoload) {
		img.src = p_url;
		p_callback(null,0);
	}
	return img;
};
haxor.net.Web.LoadVideoHTML = function(p_url,p_callback) {
	if(p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url,"./",haxor.net.Web.root);
	var vid;
	var _this = window.document;
	vid = _this.createElement("video");
	vid.style.display = "none";
	window.document.body.appendChild(vid);
	vid.onload = function(e) {
	};
	vid.onerror = function(e1) {
		p_callback(null,1.0);
	};
	vid.addEventListener("canplaythrough",function(e2) {
		if(vid == null) return;
		vid.play();
		var tex = new haxor.texture.TextureHTML(vid);
		p_callback(tex,1);
		vid = null;
	},true);
	vid.autoplay = true;
	vid.preload = "auto";
	if(haxor.net.Web.m_autoload) {
		vid.src = p_url;
		p_callback(null,0);
	}
	return vid;
};
haxor.net.Web.LoadTexture2D = function(p_url,p_callback) {
	p_callback(null,0.0);
	return haxor.net.Web.LoadImageData(p_url,function(d,p) {
		var cc;
		if(p < 1.0) cc = 0; else cc = d.data.byteLength / (d.width * d.height);
		var tex;
		if(p < 1.0) tex = null; else tex = haxor.texture.Texture2D.FromByteArray(d.width,d.height,cc == 4?haxor.texture.TextureFormat.RGBA8:haxor.texture.TextureFormat.RGB8,cc,d.data,true);
		p_callback(tex,p);
	});
};
haxor.net.Web.LoadAudio = function(p_url,p_callback) {
	if(p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url,"./",haxor.net.Web.root);
	var a = null;
	if(window.navigator.userAgent.indexOf("Chrome") < 0) {
		a = window.document.createElement("video");
		window.document.body.appendChild(a);
	} else {
		a = window.document.createElement("audio");
		window.document.body.appendChild(a);
	}
	a.style.display = "none";
	a.preload = "auto";
	a.addEventListener("canplaythrough",function(e) {
		if(a == null) return;
		p_callback(a,1.0);
		a = null;
	},false);
	a.onerror = function(e1) {
		p_callback(null,1.0);
	};
	a.controls = false;
	if(haxor.net.Web.m_autoload) {
		a.src = p_url;
		a.load();
		p_callback(null,0);
	}
	return a;
};
haxor.net.Web.LoadSound = function(p_url,p_callback) {
	if(p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url,"./",haxor.net.Web.root);
	var a = null;
	if(window.navigator.userAgent.indexOf("Chrome") < 0) {
		a = window.document.createElement("video");
		window.document.body.appendChild(a);
	} else {
		a = window.document.createElement("audio");
		window.document.body.appendChild(a);
	}
	a.style.display = "none";
	a.controls = false;
	a.preload = "auto";
	a.addEventListener("canplaythrough",function(e) {
		if(a == null) return;
		var snd = new haxor.media.Sound(a);
		p_callback(snd,1);
		a = null;
	},false);
	a.onerror = function(e1) {
		p_callback(null,1.0);
	};
	if(haxor.net.Web.m_autoload) {
		a.src = p_url;
		a.load();
		p_callback(null,0);
	}
	return a;
};
haxor.net.Web.LoadImage = function(p_url,p_callback) {
	if(p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url,"./",haxor.net.Web.root);
	var img = new Image();
	img.onload = function(e) {
		p_callback(img,1.0);
	};
	img.onerror = function(e1) {
		p_callback(null,1.0);
	};
	img.crossOrigin = "Anonymous";
	if(haxor.net.Web.m_autoload) {
		img.src = p_url;
		p_callback(null,0);
	}
	return img;
};
haxor.net.Web.LoadImageData = function(p_url,p_callback) {
	if(p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url,"./",haxor.net.Web.root);
	var img = new Image();
	img.onload = function(e) {
		var canvas;
		var _this = window.document;
		canvas = _this.createElement("canvas");
		canvas.width = img.width;
		canvas.height = img.height;
		var ctx = canvas.getContext("2d");
		ctx.drawImage(img,0,0,img.width,img.height);
		var d = ctx.getImageData(0,0,img.width,img.height);
		p_callback(d,1.0);
	};
	img.onerror = function(e1) {
		p_callback(null,1.0);
	};
	img.crossOrigin = "Anonymous";
	if(haxor.net.Web.m_autoload) {
		img.src = p_url;
		p_callback(null,0.0);
	}
	return img;
};
haxor.physics = {};
haxor.physics.Collider = function(p_entity) {
	this.trigger = false;
	var cid;
	if(haxor.physics.Collider.m_indexes.length > 0) cid = haxor.physics.Collider.m_indexes.shift(); else cid = haxor.physics.Collider.m_list.length;
	this.m_cid = cid;
	this.m_sid = -1;
	if(cid >= haxor.physics.Collider.m_list.length) haxor.physics.Collider.m_list.push(this); else haxor.physics.Collider.m_list[cid] = this;
	this.m_boundAABB = new haxor.math.AABB3();
	this.m_boundSphere = new haxor.math.Vector4();
	this.m_query = new haxor.core.Vector();
	this.m_aabb_refresh = true;
	this.m_sphere_refresh = true;
	haxor.component.Behaviour.call(this,p_entity);
	haxor.core.Engine.Add(this);
	this.m_init = false;
	this.m_rigidbody = p_entity.get_rigidbody();
};
$hxClasses["haxor.physics.Collider"] = haxor.physics.Collider;
haxor.physics.Collider.__name__ = ["haxor","physics","Collider"];
haxor.physics.Collider.__properties__ = {get_list:"get_list"}
haxor.physics.Collider.get_list = function() {
	return haxor.physics.Collider.m_list;
};
haxor.physics.Collider.Initialize = function() {
	haxor.physics.Collider.m_list = [];
	haxor.physics.Collider.m_indexes = [];
};
haxor.physics.Collider.__super__ = haxor.component.Behaviour;
haxor.physics.Collider.prototype = $extend(haxor.component.Behaviour.prototype,{
	get_boundSphere: function() {
		if(this.m_sphere_refresh) this.GenerateBoundSphere();
		return this.m_boundSphere;
	}
	,GenerateBoundSphere: function() {
	}
	,get_boundAABB: function() {
		if(this.m_aabb_refresh) this.GenerateBoundAABB();
		return this.m_boundAABB;
	}
	,GenerateBoundAABB: function() {
	}
	,get_primitive: function() {
		return this.m_primitive;
	}
	,OnAwake: function() {
		this.m_init = true;
		this.Refresh();
	}
	,Refresh: function() {
		this.m_sphere_refresh = true;
		this.m_aabb_refresh = true;
		if(this.m_init) haxor.physics.Physics.get_broadphase().SetDirty(this);
	}
	,OnUpdate: function() {
	}
	,OnDestroy: function() {
		haxor.component.Behaviour.prototype.OnDestroy.call(this);
		var cid = this.m_cid;
		haxor.physics.Collider.m_list[cid] = null;
		haxor.physics.Collider.m_indexes.push(cid);
		haxor.physics.Physics.get_broadphase().RemoveCollider(this);
	}
	,OnTransformUpdate: function() {
		this.Refresh();
		this.GenerateBoundAABB();
		this.GenerateBoundSphere();
	}
	,NotifyEnter: function(c,p_rev) {
		var cl = this.get_entity().m_components;
		var from = c.from;
		var to = c.to;
		var c0;
		if(!p_rev) c0 = c.from; else c0 = c.to;
		var c1;
		if(!p_rev) c1 = c.to; else c1 = c.from;
		var _g1 = 0;
		var _g = cl.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(js.Boot.__instanceof(cl[i],haxor.core.ITriggerable)) {
				if(!c0.trigger) {
					if(!c1.trigger) continue;
				}
				var l = cl[i];
				l.OnTriggerEnter(c1);
			}
			if(js.Boot.__instanceof(cl[i],haxor.core.ICollidable)) {
				if(c0.trigger) {
					if(c1.trigger) continue;
				}
				var l1 = cl[i];
				if(p_rev) c.Invert();
				c.from = c1;
				c.to = c0;
				l1.OnCollisionEnter(c);
				if(p_rev) c.Invert();
				c.from = from;
				c.to = to;
			}
		}
	}
	,NotifyStay: function(c,p_rev) {
		var cl = this.get_entity().m_components;
		var from = c.from;
		var to = c.to;
		var c0;
		if(!p_rev) c0 = c.from; else c0 = c.to;
		var c1;
		if(!p_rev) c1 = c.to; else c1 = c.from;
		var _g1 = 0;
		var _g = cl.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(js.Boot.__instanceof(cl[i],haxor.core.ITriggerable)) {
				if(!c0.trigger) {
					if(!c1.trigger) continue;
				}
				var l = cl[i];
				l.OnTriggerStay(c1);
			}
			if(js.Boot.__instanceof(cl[i],haxor.core.ICollidable)) {
				if(c0.trigger) {
					if(c1.trigger) continue;
				}
				var l1 = cl[i];
				if(p_rev) c.Invert();
				c.from = c1;
				c.to = c0;
				l1.OnCollisionStay(c);
				if(p_rev) c.Invert();
				c.from = from;
				c.to = to;
			}
		}
	}
	,NotifyExit: function(c,p_rev) {
		var cl = this.get_entity().m_components;
		var from = c.from;
		var to = c.to;
		var c0;
		if(!p_rev) c0 = c.from; else c0 = c.to;
		var c1;
		if(!p_rev) c1 = c.to; else c1 = c.from;
		var _g1 = 0;
		var _g = cl.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(js.Boot.__instanceof(cl[i],haxor.core.ITriggerable)) {
				if(!c0.trigger) {
					if(!c1.trigger) continue;
				}
				var l = cl[i];
				l.OnTriggerExit(c1);
			}
			if(js.Boot.__instanceof(cl[i],haxor.core.ICollidable)) {
				if(c0.trigger) {
					if(c1.trigger) continue;
				}
				var l1 = cl[i];
				if(p_rev) c.Invert();
				c.from = c1;
				c.to = c0;
				l1.OnCollisionExit(c);
				if(p_rev) c.Invert();
				c.from = from;
				c.to = to;
			}
		}
	}
	,__class__: haxor.physics.Collider
	,__properties__: $extend(haxor.component.Behaviour.prototype.__properties__,{get_primitive:"get_primitive",get_boundAABB:"get_boundAABB",get_boundSphere:"get_boundSphere"})
});
haxor.physics.BoxCollider = function(p_entity) {
	this.m_center = haxor.math.Vector3.get_zero();
	this.m_size = haxor.math.Vector3.get_one();
	haxor.physics.Collider.call(this,p_entity);
	this.m_primitive = haxor.physics.ColliderPrimitive.Box;
};
$hxClasses["haxor.physics.BoxCollider"] = haxor.physics.BoxCollider;
haxor.physics.BoxCollider.__name__ = ["haxor","physics","BoxCollider"];
haxor.physics.BoxCollider.__super__ = haxor.physics.Collider;
haxor.physics.BoxCollider.prototype = $extend(haxor.physics.Collider.prototype,{
	get_center: function() {
		return haxor.math.Vector3.get_temp().Set(this.m_center.x,this.m_center.y,this.m_center.z);
	}
	,set_center: function(v) {
		this.m_center.Set(v.x,v.y,v.z);
		this.Refresh();
		return v;
	}
	,get_size: function() {
		return haxor.math.Vector3.get_temp().Set(this.m_size.x,this.m_size.y,this.m_size.z);
	}
	,set_size: function(v) {
		this.m_size.Set(v.x,v.y,v.z);
		this.Refresh();
		return v;
	}
	,GenerateBoundSphere: function() {
		var v = this.m_boundSphere;
		var wm = this.get_transform().m_worldMatrix;
		var c = haxor.math.Vector3.get_temp().Set(this.m_center.x,this.m_center.y,this.m_center.z);
		wm.Transform3x4(c);
		v.x = c.x;
		v.y = c.y;
		v.z = c.z;
		wm = wm.get_scale();
		v.w = Math.max(wm.m00,Math.max(wm.m11,wm.m22)) * this.m_size.get_length();
	}
	,GenerateBoundAABB: function() {
		var b = this.m_boundAABB;
		var wm = this.get_transform().m_worldMatrix;
		var c = haxor.math.Vector3.get_temp().Set(this.m_center.x,this.m_center.y,this.m_center.z);
		var hx = this.m_size.x * 0.5;
		var hy = this.m_size.y * 0.5;
		var hz = this.m_size.z * 0.5;
		var vx = haxor.math.Vector3.get_temp().Set(hx * wm.m00,hx * wm.m10,hx * wm.m20);
		var vy = haxor.math.Vector3.get_temp().Set(hy * wm.m01,hy * wm.m11,hy * wm.m21);
		var vz = haxor.math.Vector3.get_temp().Set(hz * wm.m02,hz * wm.m12,hz * wm.m22);
		wm.Transform3x4(c);
		b.set_xMin(b.set_xMax(c.x));
		b.set_yMin(b.set_yMax(c.y));
		b.set_zMin(b.set_zMax(c.z));
		b.Encapsulate3(c.x + vx.x + vy.x + vz.x,c.y + vx.y + vy.y + vz.y,c.z + vx.z + vy.z + vz.z);
		b.Encapsulate3(c.x - vx.x + vy.x + vz.x,c.y - vx.y + vy.y + vz.y,c.z - vx.z + vy.z + vz.z);
		b.Encapsulate3(c.x + vx.x - vy.x + vz.x,c.y + vx.y - vy.y + vz.y,c.z + vx.z - vy.z + vz.z);
		b.Encapsulate3(c.x - vx.x - vy.x + vz.x,c.y - vx.y - vy.y + vz.y,c.z - vx.z - vy.z + vz.z);
		b.Encapsulate3(c.x + vx.x + vy.x - vz.x,c.y + vx.y + vy.y - vz.y,c.z + vx.z + vy.z - vz.z);
		b.Encapsulate3(c.x - vx.x + vy.x - vz.x,c.y - vx.y + vy.y - vz.y,c.z - vx.z + vy.z - vz.z);
		b.Encapsulate3(c.x + vx.x - vy.x - vz.x,c.y + vx.y - vy.y - vz.y,c.z + vx.z - vy.z - vz.z);
		b.Encapsulate3(c.x - vx.x - vy.x - vz.x,c.y - vx.y - vy.y - vz.y,c.z - vx.z - vy.z - vz.z);
	}
	,__class__: haxor.physics.BoxCollider
	,__properties__: $extend(haxor.physics.Collider.prototype.__properties__,{set_size:"set_size",get_size:"get_size",set_center:"set_center",get_center:"get_center"})
});
haxor.physics.ColliderPrimitive = { __ename__ : true, __constructs__ : ["Point","Plane","Box","Sphere","Capsule","Mesh"] };
haxor.physics.ColliderPrimitive.Point = ["Point",0];
haxor.physics.ColliderPrimitive.Point.__enum__ = haxor.physics.ColliderPrimitive;
haxor.physics.ColliderPrimitive.Plane = ["Plane",1];
haxor.physics.ColliderPrimitive.Plane.__enum__ = haxor.physics.ColliderPrimitive;
haxor.physics.ColliderPrimitive.Box = ["Box",2];
haxor.physics.ColliderPrimitive.Box.__enum__ = haxor.physics.ColliderPrimitive;
haxor.physics.ColliderPrimitive.Sphere = ["Sphere",3];
haxor.physics.ColliderPrimitive.Sphere.__enum__ = haxor.physics.ColliderPrimitive;
haxor.physics.ColliderPrimitive.Capsule = ["Capsule",4];
haxor.physics.ColliderPrimitive.Capsule.__enum__ = haxor.physics.ColliderPrimitive;
haxor.physics.ColliderPrimitive.Mesh = ["Mesh",5];
haxor.physics.ColliderPrimitive.Mesh.__enum__ = haxor.physics.ColliderPrimitive;
haxor.physics.Collision = function() {
	this.normal = haxor.math.Vector3.get_zero();
	this.point = haxor.math.Vector3.get_zero();
	this.depth = 0.0;
	this.speed = 0.0;
	this.m_id = -1;
	this.m_active = false;
	this.m_destroyed = false;
};
$hxClasses["haxor.physics.Collision"] = haxor.physics.Collision;
haxor.physics.Collision.__name__ = ["haxor","physics","Collision"];
haxor.physics.Collision.__properties__ = {get_temp:"get_temp"}
haxor.physics.Collision.get_temp = function() {
	if(haxor.physics.Collision.m_temp == null) {
		haxor.physics.Collision.m_temp = [];
		haxor.physics.Collision.m_nexttemp = 0;
		var _g = 0;
		while(_g < 50000) {
			var i = _g++;
			haxor.physics.Collision.m_temp.push(new haxor.physics.Collision());
		}
	}
	var t = haxor.physics.Collision.m_temp[haxor.physics.Collision.m_nexttemp];
	haxor.physics.Collision.m_nexttemp = (haxor.physics.Collision.m_nexttemp + 1) % haxor.physics.Collision.m_temp.length;
	return t;
};
haxor.physics.Collision.prototype = {
	Invert: function() {
		this.normal.Invert();
		return this;
	}
	,Update: function() {
		if(!this.m_active) {
			if(this.depth < 0.0) {
				this.m_active = true;
				this.from.NotifyEnter(this,false);
				this.to.NotifyEnter(this,true);
			}
		} else if(this.depth < 0.0) {
			this.from.NotifyStay(this,false);
			this.to.NotifyStay(this,true);
		} else {
			this.from.NotifyExit(this,false);
			this.to.NotifyExit(this,true);
			this.m_active = false;
		}
		return true;
	}
	,__class__: haxor.physics.Collision
};
haxor.physics.Physics = function() { };
$hxClasses["haxor.physics.Physics"] = haxor.physics.Physics;
haxor.physics.Physics.__name__ = ["haxor","physics","Physics"];
haxor.physics.Physics.__properties__ = {set_broadphase:"set_broadphase",get_broadphase:"get_broadphase"}
haxor.physics.Physics.get_broadphase = function() {
	return haxor.physics.Physics.m_broadphase;
};
haxor.physics.Physics.set_broadphase = function(v) {
	if(v == null) return haxor.physics.Physics.m_broadphase;
	haxor.physics.Physics.m_broadphase = v;
	haxor.physics.Physics.m_broadphase.Initialize();
	return haxor.physics.Physics.m_broadphase;
};
haxor.physics.Physics.Initialize = function() {
	haxor.physics.Physics.m_interaction = new haxe.ds.IntMap();
	var _g = 0;
	while(_g < 32) {
		var i = _g++;
		var _g1 = 0;
		while(_g1 < 32) {
			var j = _g1++;
			haxor.physics.Physics.SetInteraction(1 << i,1 << j,false);
		}
	}
	haxor.physics.Physics.SetInteraction(1,1,true);
	haxor.physics.Physics.gravity = new haxor.math.Vector3(0.0,-9.81,0.0);
	haxor.physics.Physics.set_broadphase(new haxor.physics.broadphase.SAPBroadPhase());
	haxor.physics.Physics.m_garbage = new haxor.core.Vector();
};
haxor.physics.Physics.SetInteraction = function(p_layer_a,p_layer_b,p_flag) {
	var f = p_layer_a | p_layer_b;
	haxor.physics.Physics.m_interaction.set(f,p_flag);
};
haxor.physics.Physics.GetCollision = function(p_a,p_b,p_result) {
	var pa = p_a.get_primitive();
	var pb = p_b.get_primitive();
	var c;
	if(p_result == null) c = haxor.physics.Collision.get_temp(); else c = p_result;
	if(pa == haxor.physics.ColliderPrimitive.Box) {
		if(pb == haxor.physics.ColliderPrimitive.Box) c = haxor.physics.Physics.GetCollisionBoxBox(p_a,p_b,c);
	}
	if(pa == haxor.physics.ColliderPrimitive.Sphere) {
		if(pb == haxor.physics.ColliderPrimitive.Box) c = haxor.physics.Physics.GetCollisionSphereBox(p_a,p_b,c);
	}
	if(pa == haxor.physics.ColliderPrimitive.Box) {
		if(pb == haxor.physics.ColliderPrimitive.Sphere) {
			c = haxor.physics.Physics.GetCollisionSphereBox(p_b,p_a,c);
			if(c != null) c.Invert();
		}
	}
	if(pa == haxor.physics.ColliderPrimitive.Sphere) {
		if(pb == haxor.physics.ColliderPrimitive.Sphere) c = haxor.physics.Physics.GetCollisionSphereSphere(p_a,p_b,c);
	}
	return c;
};
haxor.physics.Physics.CanInteract = function(p_a,p_b) {
	var k = p_a | p_b;
	if(haxor.physics.Physics.m_interaction.exists(k)) return haxor.physics.Physics.m_interaction.get(k); else return false;
};
haxor.physics.Physics.Update = function() {
	haxor.physics.Physics.get_broadphase().Update();
	var l = haxor.component.RigidBody.list;
	var _g1 = 0;
	var _g = l.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(l[i].get_enabled()) {
			if(!l[i].kinematic) {
				l[i].ComputeForces();
				l[i].IntegrateVelocity(haxor.core.Time.get_fixedDeltaTime());
			}
		}
	}
	var _g11 = 0;
	var _g2 = haxor.physics.Physics.iterations;
	while(_g11 < _g2) {
		var k = _g11++;
		var _g3 = 0;
		var _g21 = haxor.physics.Physics.get_broadphase().pairs.get_count();
		while(_g3 < _g21) {
			var j = _g3++;
			var c = haxor.physics.Physics.get_broadphase().pairs.Get(j);
			haxor.physics.Physics.ProcessCollision(c);
		}
	}
	var _g12 = 0;
	var _g4 = l.length;
	while(_g12 < _g4) {
		var i1 = _g12++;
		if(l[i1].get_enabled()) {
			if(!l[i1].kinematic) l[i1].IntegratePosition(haxor.core.Time.get_fixedDeltaTime());
		}
		l[i1].ResetForces();
	}
};
haxor.physics.Physics.UpdateCollisionState = function() {
	var i = 0;
	var k = 0;
	while(i < haxor.physics.Physics.get_broadphase().pairs.get_count()) {
		var c = haxor.physics.Physics.get_broadphase().pairs.Get(i);
		c.Update();
		i++;
	}
	var _g1 = 0;
	var _g = haxor.physics.Physics.m_garbage.get_count();
	while(_g1 < _g) {
		var i1 = _g1++;
		var c1 = haxor.physics.Physics.m_garbage.Get(i1);
		haxor.physics.Physics.get_broadphase().RemovePair(c1.from,c1.to);
	}
	haxor.physics.Physics.m_garbage.Clear();
};
haxor.physics.Physics.ProcessCollision = function(p_collision) {
	var c = haxor.physics.Physics.GetCollision(p_collision.from,p_collision.to,p_collision);
	if(c == null) return;
	var rba = c.from.m_rigidbody;
	var rbb = c.to.m_rigidbody;
	var ma;
	if(rba == null) ma = 0.0; else ma = rba.get_mass();
	var mb;
	if(rbb == null) mb = 0.0; else mb = rbb.get_mass();
	var sum = ma + mb;
	var ra;
	if(rba == null) ra = 0.0; else ra = ma / sum;
	var rb;
	if(rbb == null) rb = 0.0; else rb = mb / sum;
	var p;
	haxor.physics.Physics.ApplyCollision(c,rba,ra,c.to.trigger);
	c.Invert();
	haxor.physics.Physics.ApplyCollision(c,rbb,rb,c.from.trigger);
	c.Invert();
};
haxor.physics.Physics.ApplyCollision = function(p_collision,p_target,p_ratio,p_is_trigger) {
	var r = p_target;
	if(r == null) return;
	var c = p_collision;
	var rv = haxor.math.Vector3.Dot(c.normal,r.get_velocity());
	c.speed = rv;
	if(!r.kinematic) {
		if(!p_is_trigger) {
			if(c.depth < 0.0) {
				var m0 = p_collision.from.material;
				if(m0 == null) m0 = haxor.physics.PhysicsMaterial.get_empty(); else m0 = m0;
				var m1 = p_collision.to.material;
				if(m1 == null) m1 = haxor.physics.PhysicsMaterial.get_empty(); else m1 = m1;
				var bf = (m0.bounce + m1.bounce) * 0.5;
				var restitution = bf;
				if(rv < 0.0) {
					var impulse_v = -(1.0 + restitution) * haxor.math.Vector3.Dot(r.get_velocity(),c.normal);
					var v = r.get_velocity();
					v.x += c.normal.x * impulse_v;
					v.y += c.normal.y * impulse_v;
					v.z += c.normal.z * impulse_v;
					r.set_velocity(v);
					var correction = c.depth * -0.8 * haxor.core.Time.get_fixedDeltaTime();
					var cm = r.get_transform().get_position();
					cm.x += c.normal.x * correction;
					cm.y += c.normal.y * correction;
					cm.z += c.normal.z * correction;
					r.get_transform().set_position(cm);
				}
			}
		}
	}
	if(c.depth > 0.0) {
		if(rv > 0.0) haxor.physics.Physics.m_garbage.Add(p_collision);
	}
};
haxor.physics.Physics.GetCollisionBoxBox = function(p_a,p_b,c) {
	return null;
};
haxor.physics.Physics.GetCollisionSphereSphere = function(p_a,p_b,c) {
	var wma = p_a.get_transform().m_worldMatrix;
	var wmb = p_b.get_transform().m_worldMatrix;
	var c0 = haxor.math.Vector3.get_temp().Set3(p_a.m_center);
	wma.Transform3x4(c0);
	var rv0 = haxor.math.Vector3.get_temp().Set(0,0,p_a.get_radius());
	wma.Transform3x3(rv0);
	var r0 = rv0.get_length();
	var c1 = haxor.math.Vector3.get_temp().Set3(p_b.m_center);
	wmb.Transform3x4(c1);
	var rv1 = haxor.math.Vector3.get_temp().Set(0,0,p_b.get_radius());
	wmb.Transform3x3(rv1);
	var r1 = rv1.get_length();
	var d = haxor.math.Vector3.Distance(c0,c1) * 2.0;
	if(c == null) {
		c = haxor.physics.Collision.get_temp();
		c.from = p_a;
		c.to = p_b;
	}
	c.depth = d - (r0 + r1);
	if(c.depth >= 0.0) return null;
	if(c.depth < 0.0) {
		c.normal.x = c0.x - c1.x;
		c.normal.y = c0.y - c1.y;
		c.normal.z = c0.z - c1.z;
		c.normal.Normalize();
	}
	return c;
};
haxor.physics.Physics.GetCollisionSphereBox = function(p_a,p_b,c) {
	var wma = p_a.get_transform().get_WorldMatrix();
	var wmb = p_b.get_transform().get_WorldMatrix();
	var wmib = p_b.get_transform().get_WorldMatrixInverse();
	var c0 = haxor.math.Vector3.get_temp().Set3(p_a.m_center);
	wma.Transform3x4(c0);
	wmib.Transform3x4(c0);
	var rv0 = haxor.math.Vector3.get_temp().Set(0,0,p_a.get_radius());
	wma.Transform3x3(rv0);
	var c1 = haxor.math.Vector3.get_temp().Set3(p_b.m_center);
	var s1 = haxor.math.Vector3.get_temp().Set3(p_b.get_size());
	var hx = s1.x * 0.5;
	var xmin0 = c1.x - hx;
	var xmax1 = c0.x + rv0.x;
	var xmin1 = c0.x - rv0.x;
	var xmax0 = c1.x + hx;
	var hy = s1.y * 0.5;
	var ymin0 = c1.y - hy;
	var ymax1 = c0.y + rv0.y;
	var ymin1 = c0.y - rv0.y;
	var ymax0 = c1.y + hy;
	var hz = s1.z * 0.5;
	var zmin0 = c1.z - hz;
	var zmax1 = c0.z + rv0.z;
	var zmin1 = c0.z - rv0.z;
	var zmax0 = c1.z + hz;
	var cp = haxor.math.Vector3.get_temp();
	cp.x = Math.max(xmin0,Math.min(xmax0,c0.x));
	cp.y = Math.max(ymin0,Math.min(ymax0,c0.y));
	cp.z = Math.max(zmin0,Math.min(zmax0,c0.z));
	wmb.Transform3x4(cp);
	wmb.Transform3x4(c0);
	var r = rv0.get_length() * 0.5;
	var d = haxor.math.Vector3.Distance(cp,c0);
	if(c == null) {
		c = haxor.physics.Collision.get_temp();
		c.from = p_a;
		c.to = p_b;
	}
	c.depth = d - r;
	if(c.depth >= 0.0) return null;
	if(c.depth < 0.0) {
		c.point.Set3(cp);
		c.normal.x = c0.x - cp.x;
		c.normal.y = c0.y - cp.y;
		c.normal.z = c0.z - cp.z;
		c.normal.Normalize();
	}
	return c;
};
haxor.physics.PhysicsMaterial = function() {
	haxor.core.Resource.call(this);
	this.bounce = 0.0;
	this.friction = 0.0;
};
$hxClasses["haxor.physics.PhysicsMaterial"] = haxor.physics.PhysicsMaterial;
haxor.physics.PhysicsMaterial.__name__ = ["haxor","physics","PhysicsMaterial"];
haxor.physics.PhysicsMaterial.__properties__ = {get_empty:"get_empty"}
haxor.physics.PhysicsMaterial.get_empty = function() {
	if(haxor.physics.PhysicsMaterial.m_empty != null) return haxor.physics.PhysicsMaterial.m_empty;
	haxor.physics.PhysicsMaterial.m_empty = new haxor.physics.PhysicsMaterial();
	haxor.physics.PhysicsMaterial.m_empty.set_name("$DefaultPhysicsMaterial");
	return haxor.physics.PhysicsMaterial.m_empty;
};
haxor.physics.PhysicsMaterial.__super__ = haxor.core.Resource;
haxor.physics.PhysicsMaterial.prototype = $extend(haxor.core.Resource.prototype,{
	__class__: haxor.physics.PhysicsMaterial
});
haxor.physics.SphereCollider = function(p_entity) {
	this.m_center = haxor.math.Vector3.get_zero();
	this.m_radius = 1.0;
	haxor.physics.Collider.call(this,p_entity);
	this.m_primitive = haxor.physics.ColliderPrimitive.Sphere;
};
$hxClasses["haxor.physics.SphereCollider"] = haxor.physics.SphereCollider;
haxor.physics.SphereCollider.__name__ = ["haxor","physics","SphereCollider"];
haxor.physics.SphereCollider.__super__ = haxor.physics.Collider;
haxor.physics.SphereCollider.prototype = $extend(haxor.physics.Collider.prototype,{
	get_center: function() {
		return haxor.math.Vector3.get_temp().Set(this.m_center.x,this.m_center.y,this.m_center.z);
	}
	,set_center: function(v) {
		this.m_center.Set(v.x,v.y,v.z);
		this.Refresh();
		return v;
	}
	,get_radius: function() {
		return this.m_radius;
	}
	,set_radius: function(v) {
		this.m_radius = v;
		this.Refresh();
		return v;
	}
	,get_boundSphere: function() {
		var v = haxor.physics.Collider.prototype.get_boundSphere.call(this);
		var wm = this.get_transform().m_worldMatrix;
		var c = haxor.math.Vector3.get_temp().Set(this.m_center.x,this.m_center.y,this.m_center.z);
		wm.Transform3x4(c);
		v.x = c.x;
		v.y = c.y;
		v.z = c.z;
		wm = wm.get_scale();
		v.w = Math.max(wm.m00,Math.max(wm.m11,wm.m22)) * this.m_radius;
		return v;
	}
	,get_boundAABB: function() {
		var b = haxor.physics.Collider.prototype.get_boundAABB.call(this);
		var wm = this.get_transform().m_worldMatrix;
		var c = haxor.math.Vector3.get_temp().Set(0,0,this.get_radius());
		wm.Transform3x3(c);
		c.y = c.z = c.x = c.get_length();
		b.set_size(c);
		c.Set3(this.m_center);
		wm.Transform3x4(c);
		b.set_center(c);
		return b;
	}
	,__class__: haxor.physics.SphereCollider
	,__properties__: $extend(haxor.physics.Collider.prototype.__properties__,{set_radius:"set_radius",get_radius:"get_radius",set_center:"set_center",get_center:"get_center"})
});
haxor.physics.broadphase = {};
haxor.physics.broadphase.BroadPhase = function() {
	this.m_indexes = [];
	this.m_update = [];
	this.m_next_update = 0;
	this.m_dirty = [];
	this.queries = 0;
	this.m_pair_lookup = [];
	var _g = 0;
	while(_g < 4096) {
		var i = _g++;
		this.m_dirty.push(false);
		this.m_update.push(null);
		var l = [];
		var _g1 = 0;
		while(_g1 < 4096) {
			var j = _g1++;
			l.push(-1);
		}
		this.m_pair_lookup.push(l);
	}
	this.queryMs = 0;
	this.pairs = new haxor.core.Vector();
	this.m_query = new haxor.core.Vector();
	this.m_buffer = new haxor.core.Vector();
};
$hxClasses["haxor.physics.broadphase.BroadPhase"] = haxor.physics.broadphase.BroadPhase;
haxor.physics.broadphase.BroadPhase.__name__ = ["haxor","physics","broadphase","BroadPhase"];
haxor.physics.broadphase.BroadPhase.prototype = {
	Initialize: function() {
		this.queries = 0;
		this.m_pair_lookup = [];
		var _g = 0;
		while(_g < 4096) {
			var i = _g++;
			var l = [];
			var _g1 = 0;
			while(_g1 < 4096) {
				var j = _g1++;
				l.push(-1);
			}
			this.m_pair_lookup.push(l);
		}
		var l1 = haxor.physics.Collider.get_list();
		this.m_query.Clear();
		var _g11 = 0;
		var _g2 = l1.length;
		while(_g11 < _g2) {
			var i1 = _g11++;
			l1[i1].NotifyExit(null,false);
			this.UpdateCollider(l1[i1]);
		}
	}
	,SetDirty: function(p_collider) {
		if(this.m_dirty[p_collider.m_cid]) return;
		this.m_dirty[p_collider.m_cid] = true;
		this.m_update[this.m_next_update++] = p_collider;
	}
	,Update: function() {
		this.queries = 0;
		this.queryMs = haxor.core.Time.get_ms();
		var _g1 = 0;
		var _g = this.m_next_update;
		while(_g1 < _g) {
			var i = _g1++;
			var c = this.m_update[i];
			this.UpdateCollider(c);
			this.m_dirty[c.m_cid] = false;
		}
		this.queryMs = haxor.core.Time.get_ms() - this.queryMs;
		this.m_next_update = 0;
	}
	,UpdateCollider: function(p_collider) {
		this.m_query.Clear();
		this.GetQuery(p_collider);
		this.queries += this.m_query.get_count();
		this.SearchPairs(p_collider);
	}
	,RemoveCollider: function(p_collider) {
		var _g1 = 0;
		var _g = this.pairs.get_count();
		while(_g1 < _g) {
			var i = _g1++;
			var p = this.pairs.Get(i);
			if(p.from == p_collider) {
				this.RemovePair(p.from,p.to);
				continue;
			}
			if(p.to == p_collider) {
				this.RemovePair(p.from,p.to);
				continue;
			}
		}
	}
	,AddQuery: function(p_collider) {
		this.m_query.Add(p_collider);
	}
	,AddPair: function(p_a,p_b) {
		var bpp = this.SamplePair(p_a,p_b);
		if(bpp != null) return bpp;
		if(!this.BroadCheck(p_a,p_b)) return null;
		var bpp1 = null;
		var idx = -1;
		bpp1 = this.pairs.Peek();
		if(bpp1 == null) bpp1 = new haxor.physics.Collision();
		idx = this.pairs.Add(bpp1);
		this.CachePair(p_a,p_b,idx);
		bpp1.m_destroyed = false;
		bpp1.m_active = false;
		bpp1.from = p_a;
		bpp1.to = p_b;
		bpp1.m_id = idx;
		return bpp1;
	}
	,DestroyPair: function(p_a,p_b) {
		var bpp = this.SamplePair(p_a,p_b);
		if(bpp == null) return;
		bpp.m_destroyed = true;
	}
	,RemovePair: function(p_a,p_b) {
		var bpp = this.SamplePair(p_a,p_b);
		if(bpp == null) return;
		var idx = bpp.m_id;
		this.CachePair(p_a,p_b,-1);
		bpp = this.pairs.RemoveAt(idx);
		if(bpp != null) bpp.m_id = idx;
	}
	,CachePair: function(p_a,p_b,p_index) {
		var cid_a = p_a.m_cid;
		var cid_b = p_b.m_cid;
		this.m_pair_lookup[cid_a][cid_b] = p_index;
		this.m_pair_lookup[cid_b][cid_a] = p_index;
	}
	,SamplePair: function(p_a,p_b) {
		var idx = this.m_pair_lookup[p_a.m_cid][p_b.m_cid];
		if(idx < 0) return null;
		return this.pairs.Get(idx);
	}
	,Exists: function(p_a,p_b) {
		var cid_a = p_a.m_cid;
		var cid_b = p_b.m_cid;
		if(this.m_pair_lookup[cid_a][cid_b] >= 0) return true;
		if(this.m_pair_lookup[cid_b][cid_a] >= 0) return true;
		return false;
	}
	,SearchPairs: function(p_collider) {
		var c = p_collider;
		var q0 = c.m_query;
		var q1 = this.m_query;
		this.m_buffer.Clear();
		var _g1 = 0;
		var _g = q1.get_count();
		while(_g1 < _g) {
			var i = _g1++;
			var f = false;
			var a = q1.Get(i);
			if(a == p_collider) continue;
			var _g3 = 0;
			var _g2 = q0.get_count();
			while(_g3 < _g2) {
				var j = _g3++;
				var b = q0.Get(j);
				if(a == b) f = true;
			}
			if(!f) this.m_buffer.Add(a);
		}
		var _g11 = 0;
		var _g4 = this.m_buffer.get_count();
		while(_g11 < _g4) {
			var i1 = _g11++;
			this.AddPair(p_collider,this.m_buffer.Get(i1));
		}
		q0.Clear();
		var _g12 = 0;
		var _g5 = q1.get_count();
		while(_g12 < _g5) {
			var i2 = _g12++;
			q0.Add(q1.Get(i2));
		}
	}
	,GetQuery: function(p_collider) {
		var _g1 = 0;
		var _g = haxor.physics.Collider.get_list().length;
		while(_g1 < _g) {
			var i = _g1++;
			this.AddQuery(haxor.physics.Collider.get_list()[i]);
		}
	}
	,BroadCheck: function(p_a,p_b) {
		if(!p_a.get_enabled()) return false;
		if(!p_b.get_enabled()) return false;
		var can_interact = haxor.physics.Physics.CanInteract(p_a.get_entity().layer,p_b.get_entity().layer);
		if(!can_interact) return false;
		if(p_a.m_rigidbody == null) {
			if(p_b.m_rigidbody == null) return false;
		}
		return true;
	}
	,__class__: haxor.physics.broadphase.BroadPhase
};
haxor.physics.broadphase.SAPBroadPhase = function() {
	haxor.physics.broadphase.BroadPhase.call(this);
	this.m_intervals_x = [];
	this.m_intervals_y = [];
	this.m_intervals_z = [];
	var _g = 0;
	while(_g < 4096) {
		var i = _g++;
		this.m_intervals_x.push(new haxor.physics.broadphase.SAPInterval());
		this.m_intervals_y.push(new haxor.physics.broadphase.SAPInterval());
		this.m_intervals_z.push(new haxor.physics.broadphase.SAPInterval());
	}
};
$hxClasses["haxor.physics.broadphase.SAPBroadPhase"] = haxor.physics.broadphase.SAPBroadPhase;
haxor.physics.broadphase.SAPBroadPhase.__name__ = ["haxor","physics","broadphase","SAPBroadPhase"];
haxor.physics.broadphase.SAPBroadPhase.__super__ = haxor.physics.broadphase.BroadPhase;
haxor.physics.broadphase.SAPBroadPhase.prototype = $extend(haxor.physics.broadphase.BroadPhase.prototype,{
	RemoveCollider: function(p_collider) {
		haxor.physics.broadphase.BroadPhase.prototype.RemoveCollider.call(this,p_collider);
		var cid = p_collider.m_cid;
		this.RemoveInterval(this.m_intervals_x[cid]);
		this.RemoveInterval(this.m_intervals_y[cid]);
		this.RemoveInterval(this.m_intervals_z[cid]);
	}
	,UpdateCollider: function(p_collider) {
		var cid = p_collider.m_cid;
		var b = p_collider.get_boundAABB();
		var itvx;
		var itvy;
		var itvz;
		itvx = this.m_intervals_x[cid];
		itvx.Set(b.get_xMin(),b.get_xMax());
		itvx.collider = p_collider;
		itvy = this.m_intervals_y[cid];
		itvy.Set(b.get_yMin(),b.get_yMax());
		itvy.collider = p_collider;
		itvz = this.m_intervals_z[cid];
		itvz.Set(b.get_zMin(),b.get_zMax());
		itvz.collider = p_collider;
		if(this.m_x == null) this.m_x = itvx; else this.UpdateInterval(itvx,this.m_x);
		if(this.m_y == null) this.m_y = itvy; else this.UpdateInterval(itvy,this.m_y);
		if(this.m_z == null) this.m_z = itvz; else this.UpdateInterval(itvz,this.m_z);
		haxor.physics.broadphase.BroadPhase.prototype.UpdateCollider.call(this,p_collider);
	}
	,GetQuery: function(p_collider) {
		var cid = p_collider.m_cid;
		var ix;
		var iy;
		var iz;
		var itx;
		var ity;
		var itz;
		ix = this.m_intervals_x[cid];
		iy = this.m_intervals_y[cid];
		iz = this.m_intervals_z[cid];
		var sc = p_collider;
		itx = ix.next;
		while(itx != null) {
			var c = itx.collider;
			if(itx.Overlap(ix)) {
				ity = this.GetIntervalY(c);
				if(ity.Overlap(iy)) {
					itz = this.GetIntervalZ(c);
					if(itz.Overlap(iz)) this.AddQuery(c);
				}
			}
			itx = itx.next;
		}
		itx = ix.prev;
		while(itx != null) {
			var c1 = itx.collider;
			if(itx.Overlap(ix)) {
				ity = this.GetIntervalY(c1);
				if(ity.Overlap(iy)) {
					itz = this.GetIntervalZ(c1);
					if(itz.Overlap(iz)) this.AddQuery(c1);
				}
			}
			itx = itx.prev;
		}
	}
	,GetIntervalX: function(p_collider) {
		var cid = p_collider.m_cid;
		return this.m_intervals_x[cid];
	}
	,GetIntervalY: function(p_collider) {
		var cid = p_collider.m_cid;
		return this.m_intervals_y[cid];
	}
	,GetIntervalZ: function(p_collider) {
		var cid = p_collider.m_cid;
		return this.m_intervals_z[cid];
	}
	,UpdateInterval: function(p_itv,p_start) {
		if(p_itv.prev == null) {
			if(p_itv.next == null) {
				this.AddIntervalSorted(p_itv,p_start);
				return;
			}
		}
		var it = p_itv;
		var nav = 0;
		var target = null;
		while(it != null) {
			var n = it.next;
			var p = it.prev;
			if(n == null) {
				if(p == null) break;
			}
			if(p != null) {
				if(p_itv.min < p.min) {
					nav = -1;
					target = p;
				}
			}
			if(n != null) {
				if(p_itv.min > n.min) {
					nav = 1;
					target = n;
				}
			}
			if(nav == 0) break;
			if(nav < 0) it = p; else it = n;
			nav = 0;
		}
		if(target != null) {
			this.RemoveInterval(p_itv);
			this.AddIntervalAtSorted(p_itv,target);
		}
	}
	,RemoveInterval: function(p_itv) {
		var p = p_itv.prev;
		var n = p_itv.next;
		if(p != null) p.next = n;
		if(n != null) n.prev = p;
		p_itv.next = p_itv.prev = null;
		if(p_itv == this.m_x) this.m_x = n;
		if(p_itv == this.m_y) this.m_y = n;
		if(p_itv == this.m_z) this.m_z = n;
	}
	,AddIntervalSorted: function(p_itv,p_start) {
		if(p_itv == p_start) return;
		var it = p_start;
		while(it != null) if(p_itv.min > it.min) {
			if(it.next == null) {
				p_itv.next = null;
				p_itv.prev = it;
				it.next = p_itv;
				return;
			}
			it = it.next;
		} else {
			this.AddIntervalAtSorted(p_itv,it);
			return;
		}
	}
	,AddIntervalAtSorted: function(p_itv,p_at) {
		if(p_itv == p_at) return;
		if(p_itv.min > p_at.min) {
			p_itv.next = p_at.next;
			p_itv.prev = p_at;
			p_at.next = p_itv;
			if(p_itv.next != null) p_itv.next.prev = p_itv;
		} else {
			p_itv.next = p_at;
			p_itv.prev = p_at.prev;
			p_at.prev = p_itv;
			if(p_itv.prev != null) p_itv.prev.next = p_itv;
			if(p_at == this.m_x) this.m_x = p_itv;
			if(p_at == this.m_y) this.m_y = p_itv;
			if(p_at == this.m_z) this.m_z = p_itv;
		}
	}
	,Iterate: function(p_start,p_callback) {
		var it = p_start;
		while(it != null) {
			p_callback(it);
			it = it.next;
		}
	}
	,__class__: haxor.physics.broadphase.SAPBroadPhase
});
haxor.physics.broadphase.SAPInterval = function() {
	this.min = this.max = 0.0;
};
$hxClasses["haxor.physics.broadphase.SAPInterval"] = haxor.physics.broadphase.SAPInterval;
haxor.physics.broadphase.SAPInterval.__name__ = ["haxor","physics","broadphase","SAPInterval"];
haxor.physics.broadphase.SAPInterval.prototype = {
	Set: function(p_min,p_max) {
		this.min = p_min;
		this.max = p_max;
	}
	,Overlap: function(p_interval) {
		if(p_interval.min > this.min) return p_interval.min <= this.max;
		return p_interval.max >= this.min;
	}
	,ToString: function() {
		return "[" + haxor.math.Mathf.RoundPlaces(this.min,2) + "|" + this.collider.get_name() + "|" + haxor.math.Mathf.RoundPlaces(this.max,2) + "]";
	}
	,__class__: haxor.physics.broadphase.SAPInterval
};
haxor.texture = {};
haxor.texture.Texture = function() {
	haxor.core.Resource.call(this);
	this.m_data = null;
	this.m_mipmaps = false;
	this.m_format = haxor.texture.TextureFormat.RGBA8;
	this.m_minFilter = haxor.texture.TextureFilter.Linear;
	this.m_magFilter = haxor.texture.TextureFilter.Linear;
	this.m_wrap = haxor.texture.TextureWrap.ClampX | haxor.texture.TextureWrap.ClampY | haxor.texture.TextureWrap.ClampZ;
	this.m_width = this.m_height = 0;
	this.m_gid = null;
	this.m_type = 0;
	this.m_aniso = 0;
	this.m_html = false;
};
$hxClasses["haxor.texture.Texture"] = haxor.texture.Texture;
haxor.texture.Texture.__name__ = ["haxor","texture","Texture"];
haxor.texture.Texture.DecodePixels = function(p_bytes,p_channels,p_format) {
	var cc = p_channels;
	var p = 0;
	var b = p_bytes;
	var res = [];
	while(p < p_bytes.length) {
		var v0 = b[p];
		var v1;
		if(cc > 1) v1 = b[p + 1]; else v1 = 0;
		var v2;
		if(cc > 2) v2 = b[p + 2]; else v2 = 0;
		var v3;
		if(cc > 3) v3 = b[p + 3]; else v3 = 0;
		var c = haxor.texture.Texture.DecodePixel([v0,v1,v2,v3],cc,p_format);
		res.push(c);
		p += cc;
	}
	return res;
};
haxor.texture.Texture.DecodePixel = function(p_bytes,p_channels,p_format) {
	var v0 = p_bytes[0];
	var v1;
	if(p_channels > 1) v1 = p_bytes[1]; else v1 = 0;
	var v2;
	if(p_channels > 2) v2 = p_bytes[2]; else v2 = 0;
	var v3;
	if(p_channels > 3) v3 = p_bytes[3]; else v3 = 0;
	var c = new haxor.math.Color();
	if(p_format == haxor.texture.TextureFormat.Alpha8) {
		c.r = c.g = c.b = 0.0;
		c.a = v0 / 255.0;
	} else if(p_format == haxor.texture.TextureFormat.Luminance) {
		c.r = c.g = c.b = v0 / 255.0;
		c.a = 1.0;
	} else {
		c.r = v0 / 255.0;
		c.g = v1 / 255.0;
		c.b = v2 / 255.0;
		if(p_channels <= 3) c.a = 1.0; else c.a = v3 / 255.0;
	}
	return c;
};
haxor.texture.Texture.EncodePixels = function(p_pixels,p_format) {
	var res = [];
	var _g1 = 0;
	var _g = p_pixels.length;
	while(_g1 < _g) {
		var i = _g1++;
		var c = p_pixels[i];
		var pix = haxor.texture.Texture.EncodePixel(c,p_format);
		var _g3 = 0;
		var _g2 = pix.length;
		while(_g3 < _g2) {
			var j = _g3++;
			res.push(pix[j]);
		}
	}
	return new Uint8ClampedArray(res);
};
haxor.texture.Texture.EncodePixel = function(p_pixel,p_format) {
	var v0 = Math.round(haxor.math.Mathf.Clamp01(p_pixel.r) * 255.0);
	var v1 = Math.round(haxor.math.Mathf.Clamp01(p_pixel.g) * 255.0);
	var v2 = Math.round(haxor.math.Mathf.Clamp01(p_pixel.b) * 255.0);
	var v3 = Math.round(haxor.math.Mathf.Clamp01(p_pixel.a) * 255.0);
	switch(p_format[1]) {
	case 1:
		return new Uint8ClampedArray([v0,v1,v2,255]);
	case 7:case 4:case 0:
		return new Uint8ClampedArray([v3]);
	case 2:
		return new Uint8ClampedArray([v0,v1,v2]);
	case 3:
		return new Uint8ClampedArray([v0,v1,v2,v3]);
	case 8:
		return new Uint8ClampedArray([v0,v1,v2]);
	case 9:
		return new Uint8ClampedArray([v0,v1,v2,v3]);
	case 5:
		return new Uint8ClampedArray([v0,v1,v2]);
	case 6:
		return new Uint8ClampedArray([v0,v1,v2,v3]);
	case 10:
		return new Uint8ClampedArray([0,0,0,0]);
	}
	return new Uint8ClampedArray([0,0,0,0]);
};
haxor.texture.Texture.__super__ = haxor.core.Resource;
haxor.texture.Texture.prototype = $extend(haxor.core.Resource.prototype,{
	get_data: function() {
		return this.m_data;
	}
	,get_width: function() {
		return this.m_width;
	}
	,get_height: function() {
		return this.m_height;
	}
	,get_html: function() {
		return this.m_html;
	}
	,get_format: function() {
		return this.m_format;
	}
	,get_wrap: function() {
		return this.m_wrap;
	}
	,set_wrap: function(v) {
		this.m_wrap = v;
		haxor.api.TextureAPI.SetParameters(this);
		return this.m_wrap;
	}
	,get_aniso: function() {
		return this.m_aniso;
	}
	,set_aniso: function(v) {
		this.m_wrap = v;
		haxor.api.TextureAPI.SetParameters(this);
		return this.m_aniso;
	}
	,get_minFilter: function() {
		return this.m_minFilter;
	}
	,set_minFilter: function(v) {
		this.m_minFilter = v;
		haxor.api.TextureAPI.SetParameters(this);
		return this.m_minFilter;
	}
	,get_magFilter: function() {
		return this.m_magFilter;
	}
	,set_magFilter: function(v) {
		this.m_magFilter = v;
		haxor.api.TextureAPI.SetParameters(this);
		return this.m_magFilter;
	}
	,get_gid: function() {
		return this.m_gid;
	}
	,get_type: function() {
		return this.m_type;
	}
	,get_mipmaps: function() {
		return this.m_mipmaps;
	}
	,Apply: function() {
		haxor.api.TextureAPI.Apply(this);
	}
	,OnDestroy: function() {
		haxor.core.Resource.prototype.OnDestroy.call(this);
		haxor.api.TextureAPI.Destroy(this);
	}
	,BuildMipmaps: function() {
		haxor.api.TextureAPI.BuildMipmaps(this);
		this.m_mipmaps = true;
	}
	,OnBind: function() {
	}
	,__class__: haxor.texture.Texture
	,__properties__: $extend(haxor.core.Resource.prototype.__properties__,{get_mipmaps:"get_mipmaps",get_type:"get_type",get_gid:"get_gid",set_magFilter:"set_magFilter",get_magFilter:"get_magFilter",set_minFilter:"set_minFilter",get_minFilter:"get_minFilter",set_aniso:"set_aniso",get_aniso:"get_aniso",set_wrap:"set_wrap",get_wrap:"get_wrap",get_format:"get_format",get_html:"get_html",get_height:"get_height",get_width:"get_width",get_data:"get_data"})
});
haxor.texture.KernelTexture = function(p_width,p_height,p_format) {
	haxor.texture.Texture.call(this);
	this.m_format = p_format;
	this.m_width = p_width;
	this.m_height = p_height;
	this.m_minFilter = haxor.texture.TextureFilter.Nearest;
	this.m_magFilter = haxor.texture.TextureFilter.Nearest;
	var is_float = p_format == haxor.texture.TextureFormat.Float || p_format == haxor.texture.TextureFormat.Float3 || p_format == haxor.texture.TextureFormat.Float4 || p_format == haxor.texture.TextureFormat.Half || p_format == haxor.texture.TextureFormat.Half3 || p_format == haxor.texture.TextureFormat.Half4;
	if(is_float) this.m_buffer = new Float32Array(4); else this.m_buffer = new Uint8Array(4);
	haxor.api.TextureAPI.Create(this);
};
$hxClasses["haxor.texture.KernelTexture"] = haxor.texture.KernelTexture;
haxor.texture.KernelTexture.__name__ = ["haxor","texture","KernelTexture"];
haxor.texture.KernelTexture.__super__ = haxor.texture.Texture;
haxor.texture.KernelTexture.prototype = $extend(haxor.texture.Texture.prototype,{
	Write: function(p_x,p_y,p_v0,p_v1,p_v2,p_v3) {
		if(p_v3 == null) p_v3 = 0;
		if(p_v2 == null) p_v2 = 0;
		if(p_v1 == null) p_v1 = 0;
		if(p_v0 == null) p_v0 = 0;
		var b = this.m_buffer;
		b[0] = p_v0;
		b[1] = p_v1;
		b[2] = p_v2;
		b[3] = p_v3;
		haxor.api.TextureAPI.WritePixels(this,p_x,p_y,this.m_buffer,1,1);
	}
	,WriteRange: function(p_values,p_x,p_y,p_width,p_height) {
		if(p_height == null) p_height = -1;
		if(p_width == null) p_width = -1;
		if(p_y == null) p_y = 0;
		if(p_x == null) p_x = 0;
		haxor.api.TextureAPI.WritePixels(this,p_x,p_y,p_values,p_width,p_height);
	}
	,__class__: haxor.texture.KernelTexture
});
haxor.texture.RenderTexture = function(p_width,p_height,p_format,p_store_depth) {
	if(p_store_depth == null) p_store_depth = false;
	haxor.texture.Texture.call(this);
	this.m_width = Math.floor(p_width);
	this.m_height = Math.floor(p_height);
	this.m_format = p_format;
	if(p_store_depth && haxor.api.TextureAPI.TEXTURE_DEPTH) this.m_depth = new haxor.texture.Texture2D(this.m_width,this.m_height,haxor.texture.TextureFormat.Depth);
	haxor.api.TextureAPI.Create(this);
};
$hxClasses["haxor.texture.RenderTexture"] = haxor.texture.RenderTexture;
haxor.texture.RenderTexture.__name__ = ["haxor","texture","RenderTexture"];
haxor.texture.RenderTexture.__super__ = haxor.texture.Texture;
haxor.texture.RenderTexture.prototype = $extend(haxor.texture.Texture.prototype,{
	get_depth: function() {
		return this.m_depth;
	}
	,__class__: haxor.texture.RenderTexture
	,__properties__: $extend(haxor.texture.Texture.prototype.__properties__,{get_depth:"get_depth"})
});
haxor.texture.TextureFilter = { __ename__ : true, __constructs__ : ["Nearest","Linear","NearestMipmapNearest","NearestMipmapLinear","LinearMipmapNearest","LinearMipmapLinear","Trilinear"] };
haxor.texture.TextureFilter.Nearest = ["Nearest",0];
haxor.texture.TextureFilter.Nearest.__enum__ = haxor.texture.TextureFilter;
haxor.texture.TextureFilter.Linear = ["Linear",1];
haxor.texture.TextureFilter.Linear.__enum__ = haxor.texture.TextureFilter;
haxor.texture.TextureFilter.NearestMipmapNearest = ["NearestMipmapNearest",2];
haxor.texture.TextureFilter.NearestMipmapNearest.__enum__ = haxor.texture.TextureFilter;
haxor.texture.TextureFilter.NearestMipmapLinear = ["NearestMipmapLinear",3];
haxor.texture.TextureFilter.NearestMipmapLinear.__enum__ = haxor.texture.TextureFilter;
haxor.texture.TextureFilter.LinearMipmapNearest = ["LinearMipmapNearest",4];
haxor.texture.TextureFilter.LinearMipmapNearest.__enum__ = haxor.texture.TextureFilter;
haxor.texture.TextureFilter.LinearMipmapLinear = ["LinearMipmapLinear",5];
haxor.texture.TextureFilter.LinearMipmapLinear.__enum__ = haxor.texture.TextureFilter;
haxor.texture.TextureFilter.Trilinear = ["Trilinear",6];
haxor.texture.TextureFilter.Trilinear.__enum__ = haxor.texture.TextureFilter;
haxor.texture.TextureWrap = function() { };
$hxClasses["haxor.texture.TextureWrap"] = haxor.texture.TextureWrap;
haxor.texture.TextureWrap.__name__ = ["haxor","texture","TextureWrap"];
haxor.texture.TextureFormat = { __ename__ : true, __constructs__ : ["Alpha8","Luminance","RGB8","RGBA8","Half","Half3","Half4","Float","Float3","Float4","Depth"] };
haxor.texture.TextureFormat.Alpha8 = ["Alpha8",0];
haxor.texture.TextureFormat.Alpha8.__enum__ = haxor.texture.TextureFormat;
haxor.texture.TextureFormat.Luminance = ["Luminance",1];
haxor.texture.TextureFormat.Luminance.__enum__ = haxor.texture.TextureFormat;
haxor.texture.TextureFormat.RGB8 = ["RGB8",2];
haxor.texture.TextureFormat.RGB8.__enum__ = haxor.texture.TextureFormat;
haxor.texture.TextureFormat.RGBA8 = ["RGBA8",3];
haxor.texture.TextureFormat.RGBA8.__enum__ = haxor.texture.TextureFormat;
haxor.texture.TextureFormat.Half = ["Half",4];
haxor.texture.TextureFormat.Half.__enum__ = haxor.texture.TextureFormat;
haxor.texture.TextureFormat.Half3 = ["Half3",5];
haxor.texture.TextureFormat.Half3.__enum__ = haxor.texture.TextureFormat;
haxor.texture.TextureFormat.Half4 = ["Half4",6];
haxor.texture.TextureFormat.Half4.__enum__ = haxor.texture.TextureFormat;
haxor.texture.TextureFormat.Float = ["Float",7];
haxor.texture.TextureFormat.Float.__enum__ = haxor.texture.TextureFormat;
haxor.texture.TextureFormat.Float3 = ["Float3",8];
haxor.texture.TextureFormat.Float3.__enum__ = haxor.texture.TextureFormat;
haxor.texture.TextureFormat.Float4 = ["Float4",9];
haxor.texture.TextureFormat.Float4.__enum__ = haxor.texture.TextureFormat;
haxor.texture.TextureFormat.Depth = ["Depth",10];
haxor.texture.TextureFormat.Depth.__enum__ = haxor.texture.TextureFormat;
haxor.texture.Texture2D = function(p_width,p_height,p_format,p_mipmaps) {
	if(p_mipmaps == null) p_mipmaps = false;
	haxor.texture.Texture.call(this);
	this.m_mipmaps = p_mipmaps;
	this.m_width = p_width;
	this.m_height = p_height;
	this.m_format = p_format;
	var cc = this.get_channels();
	var len = p_width * p_height * cc;
	if(p_format == haxor.texture.TextureFormat.Float || p_format == haxor.texture.TextureFormat.Float3 || p_format == haxor.texture.TextureFormat.Float4) {
		var tmp = [];
		var _g = 0;
		while(_g < len) {
			var i = _g++;
			tmp.push(0.0);
		}
		this.m_data = new Float32Array(tmp);
	} else {
		var tmp1 = [];
		var _g1 = 0;
		while(_g1 < len) {
			var i1 = _g1++;
			tmp1.push(255);
		}
		this.m_data = new Uint8Array(tmp1);
	}
	this.Apply();
};
$hxClasses["haxor.texture.Texture2D"] = haxor.texture.Texture2D;
haxor.texture.Texture2D.__name__ = ["haxor","texture","Texture2D"];
haxor.texture.Texture2D.__properties__ = {get_red:"get_red",get_white:"get_white"}
haxor.texture.Texture2D.get_white = function() {
	if(haxor.texture.Texture2D.m_white != null) return haxor.texture.Texture2D.m_white;
	haxor.texture.Texture2D.m_white = new haxor.texture.Texture2D(1,1,haxor.texture.TextureFormat.RGB8);
	haxor.texture.Texture2D.m_white.Fill(haxor.math.Color.get_white());
	haxor.texture.Texture2D.m_white.Apply();
	return haxor.texture.Texture2D.m_white;
};
haxor.texture.Texture2D.get_red = function() {
	if(haxor.texture.Texture2D.m_red != null) return haxor.texture.Texture2D.m_red;
	haxor.texture.Texture2D.m_red = new haxor.texture.Texture2D(1,1,haxor.texture.TextureFormat.RGB8);
	haxor.texture.Texture2D.m_red.Fill(haxor.math.Color.get_red());
	haxor.texture.Texture2D.m_red.Apply();
	return haxor.texture.Texture2D.m_red;
};
haxor.texture.Texture2D.FromByteArray = function(p_width,p_height,p_format,p_channel,p_data,p_mipmaps,p_reverse_y) {
	if(p_reverse_y == null) p_reverse_y = false;
	if(p_mipmaps == null) p_mipmaps = false;
	var tex = new haxor.texture.Texture2D(p_width,p_height,p_format,p_mipmaps);
	var c = haxor.texture.Texture.DecodePixels(p_data,p_channel,p_format);
	var p = 0;
	var _g = 0;
	while(_g < p_height) {
		var py = _g++;
		var _g1 = 0;
		while(_g1 < p_width) {
			var px = _g1++;
			tex.SetPixel(px,p_reverse_y?p_height - 1 - py:py,c[p++]);
		}
	}
	tex.Apply();
	return tex;
};
haxor.texture.Texture2D.__super__ = haxor.texture.Texture;
haxor.texture.Texture2D.prototype = $extend(haxor.texture.Texture.prototype,{
	get_channels: function() {
		var cc = 1;
		var _g = this.m_format;
		switch(_g[1]) {
		case 0:
			cc = 1;
			break;
		case 10:
			cc = 1;
			break;
		case 4:
			cc = 1;
			break;
		case 5:
			cc = 3;
			break;
		case 6:
			cc = 4;
			break;
		case 7:
			cc = 1;
			break;
		case 8:
			cc = 3;
			break;
		case 9:
			cc = 4;
			break;
		case 1:
			cc = 3;
			break;
		case 2:
			cc = 3;
			break;
		case 3:
			cc = 4;
			break;
		}
		return cc;
	}
	,GetPixel: function(p_x,p_y) {
		var c = new haxor.math.Color();
		if(p_x >= this.m_width) return c;
		if(p_x < 0) return c;
		if(p_y >= this.m_height) return c;
		if(p_y < 0) return c;
		var cc = this.get_channels();
		var pos = (p_x + p_y * this.m_width) * cc;
		if(this.m_format == haxor.texture.TextureFormat.Float) {
			var d = this.m_data;
			c.r = d[pos];
			c.g = d[pos];
			c.b = d[pos];
			c.a = 1.0;
			return c;
		}
		if(this.m_format == haxor.texture.TextureFormat.Float3) {
			var d1 = this.m_data;
			c.r = d1[pos];
			c.g = d1[pos + 1];
			c.b = d1[pos + 2];
			c.a = 1.0;
			return c;
		}
		if(this.m_format == haxor.texture.TextureFormat.Float4) {
			var d2 = this.m_data;
			c.r = d2[pos];
			c.g = d2[pos + 1];
			c.b = d2[pos + 2];
			c.a = d2[pos + 3];
			return c;
		}
		var d3 = this.m_data;
		var pix = [];
		var _g = 0;
		while(_g < cc) {
			var i = _g++;
			pix.push(d3[pos + i]);
		}
		c = haxor.texture.Texture.DecodePixel(pix,cc,this.m_format);
		return c;
	}
	,SetPixel: function(p_x,p_y,p_color) {
		if(p_x >= this.m_width) return;
		if(p_x < 0) return;
		if(p_y >= this.m_height) return;
		if(p_y < 0) return;
		var cc = this.get_channels();
		var pos = (p_x + p_y * this.m_width) * cc;
		if(this.m_format == haxor.texture.TextureFormat.Float) {
			var d = this.m_data;
			d[pos] = p_color.r;
			return;
		}
		if(this.m_format == haxor.texture.TextureFormat.Float3) {
			var d1 = this.m_data;
			d1[pos] = p_color.r;
			d1[pos + 1] = p_color.g;
			d1[pos + 2] = p_color.b;
			return;
		}
		if(this.m_format == haxor.texture.TextureFormat.Float4) {
			var d2 = this.m_data;
			d2[pos] = p_color.r;
			d2[pos + 1] = p_color.g;
			d2[pos + 2] = p_color.b;
			d2[pos + 3] = p_color.a;
			return;
		}
		var db = this.m_data;
		var pix = haxor.texture.Texture.EncodePixel(p_color,this.m_format);
		var _g1 = 0;
		var _g = pix.length;
		while(_g1 < _g) {
			var i = _g1++;
			db[pos + i] = pix[i];
		}
	}
	,GetPixelsRect: function(p_x,p_y,p_width,p_height) {
		var res = [];
		var cc = this.get_channels();
		var pix = 0;
		var _g1 = p_y;
		var _g = p_y + p_height;
		while(_g1 < _g) {
			var py = _g1++;
			var _g3 = p_x;
			var _g2 = p_x + p_width;
			while(_g3 < _g2) {
				var px = _g3++;
				res.push(this.GetPixel(px,py));
			}
		}
		return res;
	}
	,GetPixels: function() {
		return this.GetPixelsRect(0,0,this.m_width,this.m_height);
	}
	,SetPixelsRect: function(p_x,p_y,p_width,p_height,p_color) {
		var cc = this.get_channels();
		var pix = 0;
		var _g1 = p_y;
		var _g = p_y + p_height;
		while(_g1 < _g) {
			var py = _g1++;
			if(py >= this.m_height) break;
			if(py < 0) continue;
			var _g3 = p_x;
			var _g2 = p_x + p_width;
			while(_g3 < _g2) {
				var px = _g3++;
				if(px >= this.m_width) {
					pix++;
					break;
				}
				if(px < 0) {
					pix++;
					continue;
				}
				var pos = (px + py * this.m_width) * cc;
				this.SetPixel(px,py,p_color[pix]);
				pix++;
			}
		}
	}
	,SetPixels: function(p_color) {
		this.SetPixelsRect(0,0,this.m_width,this.m_height,p_color);
	}
	,FillRect: function(p_color,p_x,p_y,p_width,p_height) {
		var cl = [];
		var _g1 = 0;
		var _g = p_width * p_height;
		while(_g1 < _g) {
			var i = _g1++;
			cl.push(p_color);
		}
		this.SetPixelsRect(p_x,p_y,p_width,p_height,cl);
	}
	,Fill: function(p_color) {
		this.FillRect(p_color,0,0,this.m_width,this.m_height);
	}
	,__class__: haxor.texture.Texture2D
	,__properties__: $extend(haxor.texture.Texture.prototype.__properties__,{get_channels:"get_channels"})
});
haxor.texture.TextureCube = function() {
	this.m_faces = [null,null,null,null,null,null];
	this.m_is_cross = false;
	haxor.texture.Texture.call(this);
	haxor.api.TextureAPI.Create(this);
};
$hxClasses["haxor.texture.TextureCube"] = haxor.texture.TextureCube;
haxor.texture.TextureCube.__name__ = ["haxor","texture","TextureCube"];
haxor.texture.TextureCube.FromCrossTexture = function(p_texture) {
	var res = new haxor.texture.TextureCube();
	var cw = p_texture.get_width() / 4;
	var ch = cw;
	var _g = 0;
	while(_g < 3) {
		var ih = _g++;
		var _g1 = 0;
		while(_g1 < 4) {
			var iw = _g1++;
			if(ih == 0) {
				if(iw != 1) continue;
			}
			if(ih == 2) {
				if(iw != 1) continue;
			}
			var px = iw * cw;
			var py = ih * ch;
			var cpix = p_texture.GetPixelsRect(px,py,cw,ch);
			var side = new haxor.texture.Texture2D(cw,ch,p_texture.get_format());
			side.SetPixels(cpix);
			if(ih == 2) {
				if(iw == 1) res.set_ny(side);
			}
			if(ih == 1) {
				if(iw == 0) res.set_nx(side);
			}
			if(ih == 1) {
				if(iw == 1) res.set_pz(side);
			}
			if(ih == 1) {
				if(iw == 2) res.set_px(side);
			}
			if(ih == 1) {
				if(iw == 3) res.set_nz(side);
			}
			if(ih == 0) {
				if(iw == 1) res.set_py(side);
			}
		}
	}
	res.Apply();
	res.m_is_cross = true;
	return res;
};
haxor.texture.TextureCube.__super__ = haxor.texture.Texture;
haxor.texture.TextureCube.prototype = $extend(haxor.texture.Texture.prototype,{
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
		haxor.texture.Texture.prototype.OnDestroy.call(this);
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
	,__class__: haxor.texture.TextureCube
	,__properties__: $extend(haxor.texture.Texture.prototype.__properties__,{set_nz:"set_nz",get_nz:"get_nz",set_pz:"set_pz",get_pz:"get_pz",set_ny:"set_ny",get_ny:"get_ny",set_py:"set_py",get_py:"get_py",set_nx:"set_nx",get_nx:"get_nx",set_px:"set_px",get_px:"get_px"})
});
haxor.texture.TextureHTML = function(p_element) {
	haxor.texture.Texture.call(this);
	this.m_video = false;
	this.m_html = true;
	if(p_element == null) {
		this.m_width = 0;
		this.m_height = 0;
	} else if(js.Boot.__instanceof(p_element,Image)) {
		var d = p_element;
		this.m_width = d.naturalWidth;
		this.m_height = d.naturalHeight;
	} else if(js.Boot.__instanceof(p_element,HTMLVideoElement)) {
		this.m_video = true;
		var d1 = p_element;
		this.m_width = d1.videoWidth;
		this.m_height = d1.videoHeight;
	} else {
		this.m_width = p_element.clientWidth;
		this.m_height = p_element.clientHeight;
	}
	this.m_data = p_element;
	this.m_format = haxor.texture.TextureFormat.RGBA8;
	this.Apply();
};
$hxClasses["haxor.texture.TextureHTML"] = haxor.texture.TextureHTML;
haxor.texture.TextureHTML.__name__ = ["haxor","texture","TextureHTML"];
haxor.texture.TextureHTML.__super__ = haxor.texture.Texture;
haxor.texture.TextureHTML.prototype = $extend(haxor.texture.Texture.prototype,{
	get_video: function() {
		return this.m_video;
	}
	,__class__: haxor.texture.TextureHTML
	,__properties__: $extend(haxor.texture.Texture.prototype.__properties__,{get_video:"get_video"})
});
haxor.thread = {};
haxor.thread.Kernel = function(p_width,p_height,p_readable,p_format) {
	if(p_readable == null) p_readable = true;
	haxor.graphics.Material.call(this);
	this.enabled = true;
	this.m_plane = new haxor.graphics.Mesh3();
	this.m_plane.set_vertex([new haxor.math.Vector3(-1,1,1),new haxor.math.Vector3(-1,-1,1),new haxor.math.Vector3(1,-1,1),new haxor.math.Vector3(-1,1,1),new haxor.math.Vector3(1,-1,1),new haxor.math.Vector3(1,1,1)]);
	this.m_output = new haxor.texture.RenderTexture(p_width,p_height,p_format == null?haxor.texture.TextureFormat.RGBA8:p_format);
	this.m_output.set_minFilter(this.m_output.set_magFilter(haxor.texture.TextureFilter.Nearest));
	this.m_output.set_name("Kernel" + this.get_id() + "Output");
	if(p_readable) this.m_result = new Uint8Array(p_width * p_height * 4); else this.m_result = null;
	var w = p_width;
	w += 0.00000001;
	var h = p_height;
	h += 0.00000001;
	this.SetUniform("width",w);
	this.SetUniform("height",h);
};
$hxClasses["haxor.thread.Kernel"] = haxor.thread.Kernel;
haxor.thread.Kernel.__name__ = ["haxor","thread","Kernel"];
haxor.thread.Kernel.__super__ = haxor.graphics.Material;
haxor.thread.Kernel.prototype = $extend(haxor.graphics.Material.prototype,{
	get_result: function() {
		return this.m_result;
	}
	,get_output: function() {
		return this.m_output;
	}
	,Resize: function(p_width,p_height) {
		if(p_height == null) p_height = -1;
		if(p_width == null) p_width = -1;
		var ow = this.m_output.get_width();
		var oh = this.m_output.get_height();
		var w;
		if(p_width < 0) w = ow; else w = p_width;
		var h;
		if(p_height < 0) h = oh; else h = p_height;
		w = -1 + 2 * (w / ow);
		h = -1 + 2 * (h / oh);
		this.m_plane.set_vertex([new haxor.math.Vector3(-1,h,1),new haxor.math.Vector3(-1,-1,1),new haxor.math.Vector3(w,-1,1),new haxor.math.Vector3(-1,h,1),new haxor.math.Vector3(w,-1,1),new haxor.math.Vector3(w,h,1)]);
	}
	,Execute: function() {
		if(!this.enabled) return;
		haxor.api.TextureAPI.BindRT(this.m_output);
		haxor.graphics.Graphics.Viewport(0,0,this.m_output.get_width(),this.m_output.get_height());
		haxor.graphics.Graphics.Render(null,null,this.m_plane,this);
		haxor.api.TextureAPI.BindRT(null);
	}
	,Update: function(p_x,p_y,p_width,p_height) {
		if(p_height == null) p_height = -1;
		if(p_width == null) p_width = -1;
		if(p_y == null) p_y = 0;
		if(p_x == null) p_x = 0;
		if(!this.enabled) return;
		if(this.m_result == null) return;
		var w;
		if(p_width <= 0) w = this.m_output.get_width(); else w = p_width;
		var h;
		if(p_height <= 0) h = this.m_output.get_height(); else h = p_height;
		haxor.api.TextureAPI.BindRT(this.m_output);
		haxor.graphics.Graphics.ReadPixels(p_x,p_y,w,h,this.m_result);
		haxor.api.TextureAPI.BindRT(null);
	}
	,OnDestroy: function() {
		haxor.graphics.Material.prototype.OnDestroy.call(this);
		haxor.core.Resource.Destroy(this.m_output);
		haxor.core.Resource.Destroy(this.m_plane);
	}
	,__class__: haxor.thread.Kernel
	,__properties__: $extend(haxor.graphics.Material.prototype.__properties__,{get_output:"get_output",get_result:"get_result"})
});
haxor.thread.KernelUint8 = function(p_width,p_height,p_readable,p_format) {
	haxor.thread.Kernel.call(this,p_width,p_height,p_readable,p_format);
};
$hxClasses["haxor.thread.KernelUint8"] = haxor.thread.KernelUint8;
haxor.thread.KernelUint8.__name__ = ["haxor","thread","KernelUint8"];
haxor.thread.KernelUint8.__super__ = haxor.thread.Kernel;
haxor.thread.KernelUint8.prototype = $extend(haxor.thread.Kernel.prototype,{
	__class__: haxor.thread.KernelUint8
});
haxor.thread.KernelFloat = function(p_width,p_height,p_readable,p_format) {
	if(p_readable == null) p_readable = true;
	haxor.thread.Kernel.call(this,p_width,p_height,p_readable,p_format);
};
$hxClasses["haxor.thread.KernelFloat"] = haxor.thread.KernelFloat;
haxor.thread.KernelFloat.__name__ = ["haxor","thread","KernelFloat"];
haxor.thread.KernelFloat.__super__ = haxor.thread.Kernel;
haxor.thread.KernelFloat.prototype = $extend(haxor.thread.Kernel.prototype,{
	get_result: function() {
		if(this.m_result == null) return null;
		var bb = this.m_result;
		return new Float32Array(bb.buffer);
	}
	,__class__: haxor.thread.KernelFloat
});
haxor.thread.ParticleKernel = function(p_renderer) {
	haxor.thread.KernelFloat.call(this,haxor.thread.ParticleKernel.DATA_SIZE,haxor.thread.ParticleKernel.DATA_SIZE,false,haxor.texture.TextureFormat.Float4);
	this.set_name("ParticleKernel" + p_renderer.get_id());
	this.m_back = new haxor.texture.RenderTexture(haxor.thread.ParticleKernel.DATA_SIZE,haxor.thread.ParticleKernel.DATA_SIZE,haxor.texture.TextureFormat.Float4);
	this.m_back.set_minFilter(haxor.texture.TextureFilter.Nearest);
	this.m_back.set_magFilter(haxor.texture.TextureFilter.Nearest);
	this.m_back.set_name("ParticleKernelData0");
	this.m_output.set_name("ParticleKernelData1");
	this.m_renderer = p_renderer;
	this.m_time = haxor.core.Time.get_elapsed();
	this.m_dt = 0.0;
	this.m_resize = false;
	this.m_kernel = this.set_shader(haxor.core.Asset.Get("haxor/kernel/ParticleKernel"));
	this.m_system = new Float32Array([0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]);
	this.SetUniform("Data",this.m_back);
	this.SetUniform("System",this.m_system);
};
$hxClasses["haxor.thread.ParticleKernel"] = haxor.thread.ParticleKernel;
haxor.thread.ParticleKernel.__name__ = ["haxor","thread","ParticleKernel"];
haxor.thread.ParticleKernel.__super__ = haxor.thread.KernelFloat;
haxor.thread.ParticleKernel.prototype = $extend(haxor.thread.KernelFloat.prototype,{
	Execute: function() {
		if(this.m_resize) this.m_resize = false;
		var s = this.m_system;
		var r = this.m_renderer;
		var af;
		var af3;
		var k = 0;
		s[k++] = r.emitter.m_data[0];
		s[k++] = r.emitter.m_data[3];
		s[k++] = r.emitter.m_data[4];
		s[k++] = r.emitter.m_data[5];
		s[k++] = r.emitter.m_data[1];
		s[k++] = r.emitter.m_data[2];
		if(r.local) s[k++] = 1.0; else s[k++] = 0.0;
		if(r.loop) s[k++] = 1.0; else s[k++] = 0.0;
		if(r.m_state == haxor.component.ParticleSystemState.None) s[k++] = 0.0; else if(r.m_state == haxor.component.ParticleSystemState.Reset) s[k++] = 1.0; else if(r.m_state == haxor.component.ParticleSystemState.Update) s[k++] = 2.0; else s[k++] = 0.0;
		s[k++] = haxor.math.Mathf.Clamp01(r.elapsed / r.duration);
		s[k++] = 0.0;
		s[k++] = haxor.core.Time.get_deltaTime();
		af = r.start.speed;
		s[k++] = af.start;
		s[k++] = af.end;
		s[k++] = af.curve;
		if(af.random) s[k++] = 1.0; else s[k++] = 0.0;
		af3 = r.start.size;
		s[k++] = af3.start.x;
		s[k++] = af3.start.y;
		s[k++] = af3.start.z;
		s[k++] = af3.curve;
		s[k++] = af3.end.x;
		s[k++] = af3.end.y;
		s[k++] = af3.end.z;
		if(af3.random) s[k++] = 1.0; else s[k++] = 0.0;
		af = r.start.life;
		s[k++] = af.start;
		s[k++] = af.end;
		s[k++] = af.curve;
		if(af.random) s[k++] = 1.0; else s[k++] = 0.0;
		af3 = r.start.rotation;
		s[k++] = af3.start.x;
		s[k++] = af3.start.y;
		s[k++] = af3.start.z;
		s[k++] = af3.curve;
		s[k++] = af3.end.x;
		s[k++] = af3.end.y;
		s[k++] = af3.end.z;
		if(af3.random) s[k++] = 1.0; else s[k++] = 0.0;
		af = r.life.speed;
		s[k++] = af.start;
		s[k++] = af.end;
		s[k++] = af.curve;
		if(af.random) s[k++] = 1.0; else s[k++] = 0.0;
		af3 = r.life.motion;
		s[k++] = af3.start.x;
		s[k++] = af3.start.y;
		s[k++] = af3.start.z;
		s[k++] = af3.curve;
		s[k++] = af3.end.x;
		s[k++] = af3.end.y;
		s[k++] = af3.end.z;
		if(af3.random) s[k++] = 1.0; else s[k++] = 0.0;
		af3 = r.life.size;
		s[k++] = af3.start.x;
		s[k++] = af3.start.y;
		s[k++] = af3.start.z;
		s[k++] = af3.curve;
		s[k++] = af3.end.x;
		s[k++] = af3.end.y;
		s[k++] = af3.end.z;
		if(af3.random) s[k++] = 1.0; else s[k++] = 0.0;
		af3 = r.life.rotation;
		s[k++] = af3.start.x;
		s[k++] = af3.start.y;
		s[k++] = af3.start.z;
		s[k++] = af3.curve;
		s[k++] = af3.end.x;
		s[k++] = af3.end.y;
		s[k++] = af3.end.z;
		if(af3.random) s[k++] = 1.0; else s[k++] = 0.0;
		s[k++] = r.force.x;
		s[k++] = r.force.y;
		s[k++] = r.force.z;
		s[k++] = 0.0;
		var wm = this.m_renderer.get_transform().m_worldMatrix;
		s[k++] = wm.m00;
		s[k++] = wm.m01;
		s[k++] = wm.m02;
		s[k++] = wm.m03;
		s[k++] = wm.m10;
		s[k++] = wm.m11;
		s[k++] = wm.m12;
		s[k++] = wm.m13;
		s[k++] = wm.m20;
		s[k++] = wm.m21;
		s[k++] = wm.m22;
		s[k++] = wm.m23;
		af = r.sheet.frame;
		s[k++] = af.start;
		s[k++] = af.end;
		s[k++] = af.curve;
		if(af.random) s[k++] = 1.0; else s[k++] = 0.0;
		s[k++] = r.sheet.width;
		s[k++] = r.sheet.height;
		if(r.sheet.reverse) s[k++] = -this.m_renderer.sheet.fps; else s[k++] = this.m_renderer.sheet.fps;
		if(r.sheet.wrap == haxor.component.AnimationWrap.Clamp) s[k++] = 0.0; else if(this.m_renderer.sheet.wrap == haxor.component.AnimationWrap.Loop) s[k++] = 1.0; else s[k++] = 2.0;
		s[k++] = r.sheet.length;
		s[k++] = r.emitter.ranges[0];
		s[k++] = r.emitter.ranges[1];
		s[k++] = 0.0;
		s[k++] = r.emitter.ranges[2];
		s[k++] = r.emitter.ranges[3];
		s[k++] = r.emitter.ranges[4];
		s[k++] = r.emitter.ranges[5];
		s[k++] = r.m_emitted_start;
		s[k++] = r.m_emitted_count;
		s[k++] = 0.0;
		s[k++] = 0.0;
		this.SetUniform("StartColor",r.start.color == null?haxor.texture.Texture2D.get_white():r.start.color);
		this.SetUniform("Color",r.life.color == null?haxor.texture.Texture2D.get_white():r.life.color);
		if(r.material != null) {
			r.material.SetUniform("System",this.m_system);
			r.material.SetUniform("Data",this.m_back);
			r.material.SetUniform("DataWidth",this.m_back.get_width() + 0.00001);
			r.material.SetUniform("DataHeight",this.m_back.get_height() + 0.00001);
			var tex = r.material.GetUniform("Texture");
			if(tex != null) {
				r.material.SetUniform("TextureWidth",tex.get_width() + 0.00001);
				r.material.SetUniform("TextureHeight",tex.get_height() + 0.00001);
			}
		}
		haxor.thread.KernelFloat.prototype.Execute.call(this);
		var tmp = this.m_back;
		this.m_back = this.m_output;
		this.m_output = tmp;
		this.SetUniform("Data",this.m_back);
	}
	,__class__: haxor.thread.ParticleKernel
});
haxor.thread.Thread = function(p_script) {
	var w = null;
	var otm = $bind(this,this.InternalOnThreadMessage);
	w = new Worker(p_script);
	w.onmessage = otm;;
	this.thread = w;
};
$hxClasses["haxor.thread.Thread"] = haxor.thread.Thread;
haxor.thread.Thread.__name__ = ["haxor","thread","Thread"];
haxor.thread.Thread.__properties__ = {get_available:"get_available"}
haxor.thread.Thread.get_available = function() {
	return typeof(Worker)!=='undefined';
};
haxor.thread.Thread.prototype = {
	get_onmessage: function() {
		return this.m_onmessage;
	}
	,set_onmessage: function(v) {
		this.m_onmessage = v;
		return v;
	}
	,send: function(p_data,p_transfer) {
		if(p_transfer == null) p_transfer = false;
		if(p_transfer) this.thread.postMessage(p_data,[p_data]); else this.thread.postMessage(p_data);
	}
	,OnThreadMessage: function(p_event) {
	}
	,InternalOnThreadMessage: function(p_event) {
		this.OnThreadMessage(p_event);
		if(this.m_onmessage != null) this.m_onmessage(p_event);
	}
	,__class__: haxor.thread.Thread
	,__properties__: {set_onmessage:"set_onmessage",get_onmessage:"get_onmessage"}
};
haxor.thread.TransformKernel = function() {
	haxor.thread.KernelFloat.call(this,64,haxor.thread.TransformKernel.MAX_TRANSFORM);
	this.m_input = new haxor.texture.KernelTexture(haxor.thread.TransformKernel.TRANSFORM_FLOAT_LENGTH / 4,haxor.thread.TransformKernel.MAX_TRANSFORM,haxor.texture.TextureFormat.Float4);
	this.m_input.set_name("$TransformKernelInput");
	this.m_ib = new Float32Array(haxor.thread.TransformKernel.TRANSFORM_FLOAT_LENGTH * haxor.thread.TransformKernel.MAX_TRANSFORM);
	this.m_matrix = new Float32Array(haxor.thread.TransformKernel.MATRIX_FLOAT_LENGTH * haxor.thread.TransformKernel.MAX_TRANSFORM);
	var _g1 = 0;
	var _g = this.m_ib.length;
	while(_g1 < _g) {
		var i = _g1++;
		this.m_ib[i] = 0.0;
	}
	this.m_input.WriteRange(this.m_ib);
	this.SetUniform("Transform",this.m_input);
	this.SetUniform("Output",this.m_output);
	this.set_name("TransformKernel");
};
$hxClasses["haxor.thread.TransformKernel"] = haxor.thread.TransformKernel;
haxor.thread.TransformKernel.__name__ = ["haxor","thread","TransformKernel"];
haxor.thread.TransformKernel.__super__ = haxor.thread.KernelFloat;
haxor.thread.TransformKernel.prototype = $extend(haxor.thread.KernelFloat.prototype,{
	Init: function(p_transform) {
		this.SetDirty(p_transform,true);
		this.SetConcat(p_transform,true);
		this.SetPosition(p_transform);
		this.SetRotation(p_transform);
		this.SetScale(p_transform);
		this.SetParent(p_transform);
		this.m_resize = true;
	}
	,SetParent: function(p_transform) {
		var o = p_transform.m_tid * haxor.thread.TransformKernel.TRANSFORM_FLOAT_LENGTH;
		if(p_transform.get_parent() == null) this.m_ib[o + haxor.thread.TransformKernel.PID_OFFSET] = -1.0; else this.m_ib[o + haxor.thread.TransformKernel.PID_OFFSET] = p_transform.get_parent().m_tid;
		this.m_ib[o + haxor.thread.TransformKernel.PID_OFFSET + 3] = 1.0;
	}
	,SetDirty: function(p_transform,p_flag) {
		var o = p_transform.m_tid * haxor.thread.TransformKernel.TRANSFORM_FLOAT_LENGTH;
		if(p_flag) this.m_ib[o + haxor.thread.TransformKernel.DIRTY_OFFSET] = 1.0; else this.m_ib[o + haxor.thread.TransformKernel.DIRTY_OFFSET] = 0.0;
	}
	,SetConcat: function(p_transform,p_flag) {
		var o = p_transform.m_tid * haxor.thread.TransformKernel.TRANSFORM_FLOAT_LENGTH;
		if(p_flag) this.m_ib[o + haxor.thread.TransformKernel.CONCAT_OFFSET] = 1.0; else this.m_ib[o + haxor.thread.TransformKernel.CONCAT_OFFSET] = 0.0;
	}
	,SetPosition: function(p_transform) {
		var o = p_transform.m_tid * haxor.thread.TransformKernel.TRANSFORM_FLOAT_LENGTH;
		this.m_ib[o + haxor.thread.TransformKernel.POSITION_OFFSET] = p_transform.m_position.x;
		this.m_ib[o + haxor.thread.TransformKernel.POSITION_OFFSET + 1] = p_transform.m_position.y;
		this.m_ib[o + haxor.thread.TransformKernel.POSITION_OFFSET + 2] = p_transform.m_position.z;
	}
	,GetPosition: function(p_transform) {
		var o = p_transform.m_tid * haxor.thread.TransformKernel.TRANSFORM_FLOAT_LENGTH;
		var v = p_transform.m_position;
		v.x = this.m_ib[o + haxor.thread.TransformKernel.POSITION_OFFSET];
		v.y = this.m_ib[o + haxor.thread.TransformKernel.POSITION_OFFSET + 1];
		v.z = this.m_ib[o + haxor.thread.TransformKernel.POSITION_OFFSET + 2];
		p_transform.set_position(v);
	}
	,SetRotation: function(p_transform) {
		var o = p_transform.m_tid * haxor.thread.TransformKernel.TRANSFORM_FLOAT_LENGTH;
		this.m_ib[o + haxor.thread.TransformKernel.ROTATION_OFFSET] = p_transform.m_rotation.x;
		this.m_ib[o + haxor.thread.TransformKernel.ROTATION_OFFSET + 1] = p_transform.m_rotation.y;
		this.m_ib[o + haxor.thread.TransformKernel.ROTATION_OFFSET + 2] = p_transform.m_rotation.z;
		this.m_ib[o + haxor.thread.TransformKernel.ROTATION_OFFSET + 3] = p_transform.m_rotation.w;
	}
	,GetRotation: function(p_transform) {
		var o = p_transform.m_tid * haxor.thread.TransformKernel.TRANSFORM_FLOAT_LENGTH;
		var v = p_transform.m_rotation;
		v.x = this.m_ib[o + haxor.thread.TransformKernel.ROTATION_OFFSET];
		v.y = this.m_ib[o + haxor.thread.TransformKernel.ROTATION_OFFSET + 1];
		v.z = this.m_ib[o + haxor.thread.TransformKernel.ROTATION_OFFSET + 2];
		v.w = this.m_ib[o + haxor.thread.TransformKernel.ROTATION_OFFSET + 3];
	}
	,SetScale: function(p_transform) {
		var o = p_transform.m_tid * haxor.thread.TransformKernel.TRANSFORM_FLOAT_LENGTH;
		this.m_ib[o + haxor.thread.TransformKernel.SCALE_OFFSET] = p_transform.m_scale.x;
		this.m_ib[o + haxor.thread.TransformKernel.SCALE_OFFSET + 1] = p_transform.m_scale.y;
		this.m_ib[o + haxor.thread.TransformKernel.SCALE_OFFSET + 2] = p_transform.m_scale.z;
	}
	,GetScale: function(p_transform) {
		var o = p_transform.m_tid * haxor.thread.TransformKernel.TRANSFORM_FLOAT_LENGTH;
		var v = p_transform.m_scale;
		v.x = this.m_ib[o + haxor.thread.TransformKernel.SCALE_OFFSET];
		v.y = this.m_ib[o + haxor.thread.TransformKernel.SCALE_OFFSET + 1];
		v.z = this.m_ib[o + haxor.thread.TransformKernel.SCALE_OFFSET + 2];
	}
	,GetLocalMatrix: function(p_transform) {
		var tid = p_transform.m_tid;
		var o = tid * haxor.thread.TransformKernel.MATRIX_FLOAT_LENGTH;
		var m = p_transform.m_localMatrix;
		var _g = 0;
		while(_g < 12) {
			var i = _g++;
			m.SetIndex(i,this.m_matrix[o + haxor.thread.TransformKernel.LM_OFFSET + i]);
		}
		return m;
	}
	,GetWorldMatrix: function(p_transform) {
		var tid = p_transform.m_tid;
		var o = tid * haxor.thread.TransformKernel.MATRIX_FLOAT_LENGTH;
		var m = p_transform.m_worldMatrix;
		var _g = 0;
		while(_g < 12) {
			var i = _g++;
			m.SetIndex(i,this.m_matrix[o + haxor.thread.TransformKernel.WM_OFFSET + i]);
		}
		return m;
	}
	,GetWorldMatrixInverse: function(p_transform) {
		var tid = p_transform.m_tid;
		var o = tid * haxor.thread.TransformKernel.MATRIX_FLOAT_LENGTH;
		var m = p_transform.m_worldMatrixInverse;
		var _g = 0;
		while(_g < 12) {
			var i = _g++;
			m.SetIndex(i,this.m_matrix[o + haxor.thread.TransformKernel.WMI_OFFSET + i]);
		}
		return m;
	}
	,Execute: function() {
		if(this.m_kernel == null) {
			this.m_kernel = this.set_shader(haxor.core.Asset.Get("haxor/kernel/TransformKernel"));
			return;
		}
		this.m_input.WriteRange(this.m_ib);
		if(this.m_resize) {
			this.Resize(36,haxor.component.Transform.m_list.length);
			this.m_resize = false;
		}
		haxor.thread.KernelFloat.prototype.Execute.call(this);
		this.Update(0,0,36,haxor.component.Transform.m_list.length);
		this.m_matrix = this.get_result();
	}
	,__class__: haxor.thread.TransformKernel
});
haxor.ui = {};
haxor.ui.ISkinnable = function() { };
$hxClasses["haxor.ui.ISkinnable"] = haxor.ui.ISkinnable;
haxor.ui.ISkinnable.__name__ = ["haxor","ui","ISkinnable"];
haxor.ui.ISkinnable.prototype = {
	__class__: haxor.ui.ISkinnable
};
haxor.ui.UIEntity = function() {
	haxor.core.Resource.call(this);
	this.m_components = [];
	if(this.m_element != null) {
		var e = this.m_element;
		e.style.position = "absolute";
		e.style.zIndex = "auto";
		this.m_layout = new haxor.ui.Layout(this);
	}
	this.set_name(this.GetTypeName() + this.get_id());
	this.m_filters = new haxor.ui.UIFilter(this.m_element);
	this.m_element.setAttribute("script",Type.getClassName(Type.getClass(this)));
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
	this.set_selectable(false);
	this.m_alpha = 1;
	this.m_globalAlpha = 1;
	this.m_globalVisible = true;
	this.m_visible = true;
	this.m_parent = null;
	this.set_skin(this.m_skin == null?"":this.m_skin);
	this.m_added_stage = false;
	this.UpdateTransform();
};
$hxClasses["haxor.ui.UIEntity"] = haxor.ui.UIEntity;
haxor.ui.UIEntity.__name__ = ["haxor","ui","UIEntity"];
haxor.ui.UIEntity.__interfaces__ = [haxor.ui.ISkinnable];
haxor.ui.UIEntity.__super__ = haxor.core.Resource;
haxor.ui.UIEntity.prototype = $extend(haxor.core.Resource.prototype,{
	set_name: function(v) {
		haxor.core.Resource.prototype.set_name.call(this,v);
		this.m_element.setAttribute("name",v);
		return v;
	}
	,get_skin: function() {
		return this.m_skin;
	}
	,set_skin: function(v) {
		if(this.m_skin == null) this.m_skin = "";
		if(this.m_skin == "") {
			if(v != "") haxor.ui.UISkin.Add(this);
		}
		if(this.m_skin != "") {
			if(v == "") haxor.ui.UISkin.Remove(this);
		}
		this.m_skin = v;
		if(v != "") {
			if(haxor.ui.UISkin.get_current() != null) {
				var fs = haxor.ui.UISkin.get_current().Get(v + ".filter");
				if(this.get_filters() != null) {
					if(fs == null) this.get_filters().Reset(); else this.get_filters().Set(fs.filter);
				}
				this.OnSkinChange(haxor.ui.UISkin.get_current());
			}
		}
		return v;
	}
	,get_x: function() {
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
		this.m_width = haxor.math.Mathf.Max([0,v]);
		this.UpdateRect();
		return this.m_width;
	}
	,get_height: function() {
		return this.m_height;
	}
	,set_height: function(v) {
		this.m_height = haxor.math.Mathf.Max([0,v]);
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
	,get_rect: function() {
		var m = this.get_layout().get_margin();
		return new haxor.math.AABB2(Std["int"](this.m_x - this.m_px + m.get_xMin()),Std["int"](this.m_y - this.m_py + m.get_yMin()),Std["int"](this.m_width - (m.get_xMin() + m.get_xMax())),Std["int"](this.m_height - (m.get_yMin() + m.get_yMax())));
	}
	,get_alpha: function() {
		return this.m_alpha;
	}
	,set_alpha: function(v) {
		this.m_alpha = v;
		this.UpdateMaterial();
		return v;
	}
	,get_filters: function() {
		return this.m_filters;
	}
	,get_visible: function() {
		return this.m_visible;
	}
	,set_visible: function(v) {
		this.m_visible = v;
		this.UpdateMaterial();
		return v;
	}
	,get_selectable: function() {
		return this.m_selectable;
	}
	,set_selectable: function(v) {
		this.m_selectable = v;
		this.m_element.style.setProperty(haxor.core.Application.get_vendor() + "user-select",v?"text":"none","");
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
	,get_mouseX: function() {
		if(this.get_parent() == null) return this.get_stage().get_mouseX(); else return this.get_parent().get_mouseX() - this.get_x();
	}
	,get_mouseY: function() {
		if(this.get_parent() == null) return this.get_stage().get_mouseY(); else return this.get_parent().get_mouseY() - this.get_y();
	}
	,get_graphics: function() {
		if(this.m_graphics != null) return this.m_graphics;
		var cc;
		var _this = this.get_stage().get_document();
		cc = _this.createElement("div");
		cc.style.overflow = "hidden";
		cc.style.width = "100%";
		cc.style.height = "100%";
		var c;
		var _this1 = this.get_stage().get_document();
		c = _this1.createElement("canvas");
		c.style.zIndex = "auto";
		this.m_graphics = c.getContext("2d");
		c.width = 1920;
		c.height = 1920;
		cc.appendChild(c);
		var fc = this.m_element.firstElementChild;
		if(fc == null) this.m_element.appendChild(cc); else this.m_element.insertBefore(cc,fc);
		return this.m_graphics;
	}
	,get_layout: function() {
		return this.m_layout;
	}
	,get_parent: function() {
		return this.m_parent;
	}
	,get_stage: function() {
		if(this.m_stage != null) return this.m_stage;
		var it = this.get_parent();
		while(it != null) {
			if(js.Boot.__instanceof(it,haxor.ui.Stage)) {
				this.m_stage = it;
				return this.m_stage;
			}
			it = it.get_parent();
		}
		return null;
	}
	,get_appended: function() {
		var it = this.m_element;
		while(it != null) {
			if(js.Boot.__instanceof(it,HTMLBodyElement)) return true;
			it = it.parentElement;
		}
		return false;
	}
	,get_overflow: function() {
		return this.m_element.style.overflow;
	}
	,set_overflow: function(v) {
		this.m_element.style.overflow = v;
		return v;
	}
	,ClearGraphics: function() {
		this.m_graphics.canvas.width = 1920;
		this.m_graphics.canvas.height = 1920;
	}
	,UpdateMaterial: function() {
		var pa;
		if(this.get_parent() == null) pa = 1.0; else pa = this.get_parent().m_globalAlpha;
		var pv;
		if(this.get_parent() == null) pv = true; else pv = this.get_parent().m_globalVisible;
		var e = this.m_element;
		var is_negative = pa < 0 || this.m_alpha < 0;
		this.m_globalAlpha = haxor.math.Mathf.Clamp01(this.m_alpha) * haxor.math.Mathf.Clamp01(this.m_alpha);
		if(is_negative) this.m_globalAlpha = -this.m_globalAlpha;
		this.m_globalVisible = this.m_visible && pv && !is_negative;
		e.style.opacity = this.m_globalAlpha + "";
		if(this.m_globalVisible) e.style.display = "block"; else e.style.display = "none";
		var _g1 = 0;
		var _g = this.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_components[i].OnMaterialUpdate();
		}
	}
	,UpdateRect: function() {
		var e = this.m_element;
		var m = this.get_layout().get_margin();
		this.get_layout().Update();
		e.style.width = Std["int"](this.m_width - (m.get_xMin() + m.get_xMax())) + "px";
		e.style.height = Std["int"](this.m_height - (m.get_yMin() + m.get_yMax())) + "px";
		var _g1 = 0;
		var _g = this.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_components[i].OnRectUpdate();
		}
		this.OnRepaint();
	}
	,UpdateTransform: function() {
		var e = this.m_element;
		var m = this.get_layout().get_margin();
		this.get_layout().Update();
		var px = haxor.math.Mathf.Floor(this.m_x - this.m_px + m.get_xMin());
		var py = haxor.math.Mathf.Floor(this.m_y - this.m_py + m.get_yMin());
		var ox = px + this.m_px;
		var oy = py + this.m_py;
		var tov = e.style.getPropertyValue(haxor.core.Application.get_vendor() + "transform-origin");
		if(tov != "" && tov != null) e.style.removeProperty(haxor.core.Application.get_vendor() + "transform-origin");
		e.style.cssText = e.style.cssText + " " + haxor.core.Application.get_vendor() + "transform-origin: " + ox + "px " + oy + "px;";
		e.style.setProperty(haxor.core.Application.get_vendor() + "transform","scale3d(" + this.m_sx + "," + this.m_sy + ",1.0) rotate3d(0,0,1," + this.m_rotation + "deg) translate3d(" + px + "px," + py + "px,0px)","");
		var _g1 = 0;
		var _g = this.m_components.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_components[i].OnTransformUpdate();
		}
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
			var _g1 = 0;
			var _g = this.m_components.length;
			while(_g1 < _g) {
				var i = _g1++;
				this.m_components[i].OnAddedToStage();
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
		l = haxor.math.Mathf.Min([l,w1 / 2]);
		var r;
		if(p_slices.length <= 0) r = 0; else if(p_slices.length <= 1) r = p_slices[0]; else r = p_slices[1];
		r = haxor.math.Mathf.Min([r,w1 / 2]);
		var t;
		if(p_slices.length <= 0) t = 0; else if(p_slices.length <= 1) t = p_slices[0]; else t = p_slices[2];
		t = haxor.math.Mathf.Min([t,h1 / 2]);
		var b;
		if(p_slices.length <= 0) b = 0; else if(p_slices.length <= 1) b = p_slices[0]; else b = p_slices[3];
		b = haxor.math.Mathf.Min([b,h1 / 2]);
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
	,OnSkinChange: function(p_skin) {
	}
	,AddComponent: function(p_type) {
		var c = Type.createInstance(p_type,[this]);
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
		var res = null;
		if(!js.Boot.__instanceof(this,haxor.ui.Container)) return res;
		var c = this;
		c.Traverse(function(d,t) {
			var l = t.GetComponents(p_type);
			if(l.length > 0) {
				res = l[0];
				return false;
			}
			return true;
		});
		return res;
	}
	,GetComponentsInChildren: function(p_type) {
		var res = [];
		if(!js.Boot.__instanceof(this,haxor.ui.Container)) return res;
		var c = this;
		c.Traverse(function(d,t) {
			var l = t.GetComponents(p_type);
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
	,ToFront: function() {
		if(this.get_parent() != null) this.get_parent().SetChildIndex(this,10000);
	}
	,StepFront: function() {
		if(this.get_parent() != null) this.get_parent().SetChildIndex(this,this.get_parent().GetChildIndex(this) + 1);
	}
	,ToBack: function() {
		if(this.get_parent() != null) this.get_parent().SetChildIndex(this,0);
	}
	,StepBack: function() {
		if(this.get_parent() != null) this.get_parent().SetChildIndex(this,this.get_parent().GetChildIndex(this) - 1);
	}
	,__class__: haxor.ui.UIEntity
	,__properties__: $extend(haxor.core.Resource.prototype.__properties__,{set_overflow:"set_overflow",get_overflow:"get_overflow",get_appended:"get_appended",get_stage:"get_stage",get_parent:"get_parent",get_layout:"get_layout",get_graphics:"get_graphics",get_mouseY:"get_mouseY",get_mouseX:"get_mouseX",set_mouseEnabled:"set_mouseEnabled",get_mouseEnabled:"get_mouseEnabled",set_selectable:"set_selectable",get_selectable:"get_selectable",set_visible:"set_visible",get_visible:"get_visible",get_filters:"get_filters",set_alpha:"set_alpha",get_alpha:"get_alpha",get_rect:"get_rect",set_rotation:"set_rotation",get_rotation:"get_rotation",set_sy:"set_sy",get_sy:"get_sy",set_sx:"set_sx",get_sx:"get_sx",set_height:"set_height",get_height:"get_height",set_width:"set_width",get_width:"get_width",set_py:"set_py",get_py:"get_py",set_px:"set_px",get_px:"get_px",set_y:"set_y",get_y:"get_y",set_x:"set_x",get_x:"get_x",set_skin:"set_skin",get_skin:"get_skin"})
});
haxor.ui.Container = function() {
	var _this = window.document;
	this.m_element = _this.createElement("div");
	this.m_children = [];
	haxor.ui.UIEntity.call(this);
};
$hxClasses["haxor.ui.Container"] = haxor.ui.Container;
haxor.ui.Container.__name__ = ["haxor","ui","Container"];
haxor.ui.Container.Path = function(p_element) {
	var p = [];
	var it = p_element;
	while(it != null) {
		if(it.hasAttribute("script")) {
			if(it.getAttribute("script") == "haxor.ui.Stage") break;
			p.push(it.getAttribute("name"));
		}
		it = it.parentElement;
	}
	p.reverse();
	return p.join(".");
};
haxor.ui.Container.__super__ = haxor.ui.UIEntity;
haxor.ui.Container.prototype = $extend(haxor.ui.UIEntity.prototype,{
	get_element: function() {
		return this.m_element;
	}
	,get_childCount: function() {
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
		if(this.get_stage() != null || js.Boot.__instanceof(this,haxor.ui.Stage)) this.AddedToStage();
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
		var p = haxor.math.Mathf.ClampInt(p_index,0,this.m_children.length - 1);
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
			if(!js.Boot.__instanceof(it,haxor.ui.Container)) {
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
		if(js.Boot.__instanceof(it,haxor.ui.Container)) {
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
		haxor.ui.UIEntity.prototype.UpdateMaterial.call(this);
		var _g1 = 0;
		var _g = this.m_children.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_children[i].UpdateMaterial();
		}
	}
	,UpdateTransform: function() {
		haxor.ui.UIEntity.prototype.UpdateTransform.call(this);
		var _g1 = 0;
		var _g = this.m_children.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_children[i].UpdateTransform();
		}
	}
	,UpdateRect: function() {
		haxor.ui.UIEntity.prototype.UpdateRect.call(this);
		var _g1 = 0;
		var _g = this.m_children.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_children[i].UpdateRect();
		}
	}
	,AddedToStage: function() {
		haxor.ui.UIEntity.prototype.AddedToStage.call(this);
		var _g1 = 0;
		var _g = this.m_children.length;
		while(_g1 < _g) {
			var i = _g1++;
			this.m_children[i].AddedToStage();
		}
	}
	,__class__: haxor.ui.Container
	,__properties__: $extend(haxor.ui.UIEntity.prototype.__properties__,{get_childCount:"get_childCount",get_element:"get_element"})
});
haxor.ui.HaxorCanvas = function(p_element,p_alpha,p_antialias,p_depth,p_stencil,p_premultiplied_alpha,p_preserve_buffer) {
	if(p_preserve_buffer == null) p_preserve_buffer = false;
	if(p_premultiplied_alpha == null) p_premultiplied_alpha = false;
	if(p_stencil == null) p_stencil = false;
	if(p_depth == null) p_depth = true;
	if(p_antialias == null) p_antialias = false;
	if(p_alpha == null) p_alpha = true;
	if(p_element == null) {
		var _this = window.document;
		this.m_element = _this.createElement("canvas");
	} else this.m_element = p_element;
	haxor.ui.UIEntity.call(this);
	this.set_name("haxor");
	this.m_element.id = "haxor";
	this.m_element.style.cursor = "default";
	if(p_element == null) {
		this.m_element.setAttribute("alpha",(p_alpha == null?"null":"" + p_alpha) + "");
		this.m_element.setAttribute("depth",(p_depth == null?"null":"" + p_depth) + "");
		this.m_element.setAttribute("antialias",(p_antialias == null?"null":"" + p_antialias) + "");
		this.m_element.setAttribute("stencil",(p_stencil == null?"null":"" + p_stencil) + "");
		this.m_element.setAttribute("premultipliedAlpha",(p_premultiplied_alpha == null?"null":"" + p_premultiplied_alpha) + "");
		this.m_element.setAttribute("preserveDrawingBuffer",(p_preserve_buffer == null?"null":"" + p_preserve_buffer) + "");
		this.m_element.setAttribute("mode","3d");
	}
	if(p_element == null) {
		this.get_layout().set_flag(haxor.ui.LayoutFlag.SizeXY);
		this.get_layout().set_width(this.get_layout().set_height(1.0));
		if(this.get_application().get_stage() != null) this.get_application().get_stage().AddChildAt(this,0);
	}
};
$hxClasses["haxor.ui.HaxorCanvas"] = haxor.ui.HaxorCanvas;
haxor.ui.HaxorCanvas.__name__ = ["haxor","ui","HaxorCanvas"];
haxor.ui.HaxorCanvas.__super__ = haxor.ui.UIEntity;
haxor.ui.HaxorCanvas.prototype = $extend(haxor.ui.UIEntity.prototype,{
	get_element: function() {
		return this.m_element;
	}
	,get_hasAlpha: function() {
		return this.m_element.getAttribute("alpha") == "true";
	}
	,get_hasAntialias: function() {
		return this.m_element.getAttribute("antialias") == "true";
	}
	,get_hasDepth: function() {
		return this.m_element.getAttribute("depth") == "true";
	}
	,get_hasStencil: function() {
		return this.m_element.getAttribute("depth") == "true";
	}
	,get_hasPremultipliedAlpha: function() {
		return this.m_element.getAttribute("premultipliedAlpha") == "true";
	}
	,get_preserveBuffer: function() {
		return this.m_element.getAttribute("preserveDrawingBuffer") == "true";
	}
	,UpdateRect: function() {
		haxor.ui.UIEntity.prototype.UpdateRect.call(this);
		var r = this.get_rect();
		this.get_element().width = r.get_width();
		this.get_element().height = r.get_height();
	}
	,__class__: haxor.ui.HaxorCanvas
	,__properties__: $extend(haxor.ui.UIEntity.prototype.__properties__,{get_preserveBuffer:"get_preserveBuffer",get_hasPremultipliedAlpha:"get_hasPremultipliedAlpha",get_hasStencil:"get_hasStencil",get_hasDepth:"get_hasDepth",get_hasAntialias:"get_hasAntialias",get_hasAlpha:"get_hasAlpha",get_element:"get_element"})
});
haxor.ui.UILoader = function() {
	haxor.ui.Container.call(this);
	this.get_layout().set_flag(haxor.ui.LayoutFlag.SizeXY);
	this.get_layout().set_width(this.get_layout().set_height(1.0));
	this.m_complete = false;
	this.m_finished = false;
};
$hxClasses["haxor.ui.UILoader"] = haxor.ui.UILoader;
haxor.ui.UILoader.__name__ = ["haxor","ui","UILoader"];
haxor.ui.UILoader.__super__ = haxor.ui.Container;
haxor.ui.UILoader.prototype = $extend(haxor.ui.Container.prototype,{
	OnElementProgress: function(p_id,p_float) {
	}
	,OnElementComplete: function(p_id) {
	}
	,OnProgress: function(p_float) {
	}
	,OnComplete: function() {
		this.Finish();
	}
	,Finish: function() {
		this.Remove();
		this.m_finished = true;
	}
	,Remove: function() {
		this.get_parent().RemoveChild(this);
	}
	,__class__: haxor.ui.UILoader
});
haxor.ui.HaxorLoader = function() {
	haxor.ui.UILoader.call(this);
	this.set_name("haxor_loader");
	this.m_fill = new haxor.ui.Sprite();
};
$hxClasses["haxor.ui.HaxorLoader"] = haxor.ui.HaxorLoader;
haxor.ui.HaxorLoader.__name__ = ["haxor","ui","HaxorLoader"];
haxor.ui.HaxorLoader.__super__ = haxor.ui.UILoader;
haxor.ui.HaxorLoader.prototype = $extend(haxor.ui.UILoader.prototype,{
	OnAddedToStage: function() {
		this.set_alpha(0);
		var bcg = new haxor.ui.Sprite();
		bcg.set_name("background");
		bcg.get_layout().set_flag(haxor.ui.LayoutFlag.SizeXY);
		bcg.set_width(bcg.set_height(1));
		bcg.set_image(this.get_stage().get_document().getElementById("hxp_background"));
		var pattern = new haxor.ui.Sprite();
		pattern.set_name("pattern");
		pattern.get_layout().set_flag(haxor.ui.LayoutFlag.SizeXY);
		pattern.set_width(pattern.set_height(1));
		pattern.set_pattern(true);
		pattern.set_image(this.get_stage().get_document().getElementById("hxp_pattern"));
		this.m_fill.set_name("fill");
		this.m_fill.set_image(window.document.getElementById("hxp_fill"));
		this.m_fill.get_layout().set_flag(haxor.ui.LayoutFlag.SizeX);
		this.m_fill.get_layout().set_width(0);
		this.m_fill.set_height(this.m_fill.get_image().naturalHeight);
		this.m_fill.set_slices([7,7,0,0]);
		var bar = this.m_bar = new haxor.ui.Sprite();
		bar.set_name("bar");
		bar.set_image(this.get_stage().get_document().getElementById("hxp_bar"));
		bar.get_layout().Set(haxor.ui.LayoutFlag.PivotX | haxor.ui.LayoutFlag.PositionXY,0.5,0,0.5,0.5);
		bar.set_width(0);
		bar.set_height(bar.get_image().naturalHeight);
		bar.set_slices([6,6,0,0]);
		bar.AddChild(this.m_fill);
		var logo = this.m_logo = new haxor.ui.Sprite();
		logo.set_name("logo");
		logo.set_image(this.get_stage().get_document().getElementById("hxp_logo"));
		logo.set_width(logo.get_image().naturalWidth);
		logo.set_height(logo.get_image().naturalHeight);
		logo.get_layout().Set(haxor.ui.LayoutFlag.PivotX | haxor.ui.LayoutFlag.PositionXY,0.5,0,0.5,0.5);
		logo.set_py(logo.get_image().naturalHeight * 0.44);
		this.AddChild(bcg);
		this.AddChild(pattern);
		this.AddChild(bar);
		this.AddChild(logo);
		haxor.core.Tween.Add(this,"alpha",1,0.6,0.2,haxor.math.Cubic.Out);
		haxor.core.Tween.Add(bar,"width",270,0.4,0.8,haxor.math.Cubic.Out);
		haxor.core.Tween.Add(logo,"py",logo.get_py() + 60,0.5,0.8,haxor.math.Cubic.Out);
	}
	,OnProgress: function(p_progress) {
		haxor.core.Tween.Add(this.m_fill.get_layout(),"width",p_progress,haxor.core.Asset.get_dependenceCount() <= 0?0:0.8,0,haxor.math.Cubic.Out);
	}
	,OnComplete: function() {
		var _g = this;
		haxe.Timer.delay(function() {
			haxor.core.Tween.Add(_g.m_bar,"width",0,0.4,0.1,haxor.math.Cubic.Out);
			haxor.core.Tween.Add(_g.m_bar,"alpha",0,0.4,0.1,haxor.math.Cubic.Out);
			haxor.core.Tween.Add(_g.m_logo,"py",_g.m_logo.get_py() - 60,0.5,0.3,haxor.math.Cubic.Out);
			haxor.core.Tween.Add(_g,"alpha",-0.1,1,0.9,haxor.math.Cubic.Out).oncomplete = function() {
				_g.Finish();
			};
		},1000);
	}
	,__class__: haxor.ui.HaxorLoader
});
haxor.ui.Layout = function(p_element) {
	this.m_element = p_element;
	this.m_lock = false;
	this.m_margin = haxor.math.AABB2.get_empty();
	this.m_x = this.m_y = 0;
	this.m_width = 1;
	this.m_height = 1;
	this.m_px = 0;
	this.m_py = 0;
};
$hxClasses["haxor.ui.Layout"] = haxor.ui.Layout;
haxor.ui.Layout.__name__ = ["haxor","ui","Layout"];
haxor.ui.Layout.prototype = {
	get_px: function() {
		return this.m_px;
	}
	,set_px: function(v) {
		this.m_px = v;
		if((this.m_flag & haxor.ui.LayoutFlag.PivotX) != 0) this.Update();
		return v;
	}
	,get_py: function() {
		return this.m_py;
	}
	,set_py: function(v) {
		this.m_py = v;
		if((this.m_flag & haxor.ui.LayoutFlag.PivotY) != 0) this.Update();
		return v;
	}
	,get_x: function() {
		return this.m_x;
	}
	,set_x: function(v) {
		this.m_x = v;
		if((this.m_flag & haxor.ui.LayoutFlag.PositionX) != 0) this.Update();
		return v;
	}
	,get_y: function() {
		return this.m_y;
	}
	,set_y: function(v) {
		this.m_y = v;
		if((this.m_flag & haxor.ui.LayoutFlag.PositionY) != 0) this.Update();
		return v;
	}
	,get_width: function() {
		return this.m_width;
	}
	,set_width: function(v) {
		this.m_width = v;
		if((this.m_flag & haxor.ui.LayoutFlag.SizeX) != 0) this.Update();
		return v;
	}
	,get_height: function() {
		return this.m_height;
	}
	,set_height: function(v) {
		this.m_height = v;
		if((this.m_flag & haxor.ui.LayoutFlag.SizeY) != 0) this.Update();
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
		this.m_margin = v.get_clone();
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
		this.set_flag(haxor.ui.LayoutFlag.SizeXY);
	}
	,FitWidth: function() {
		this.set_width(1);
		this.set_flag(this.get_flag() | haxor.ui.LayoutFlag.SizeX);
	}
	,FitHeight: function() {
		this.set_height(1);
		this.set_flag(this.get_flag() | haxor.ui.LayoutFlag.SizeY);
	}
	,Update: function() {
		if(this.m_lock) return;
		this.m_lock = true;
		var p = this.m_element.get_parent();
		var pw;
		if(p == null) pw = 0; else pw = p.get_width() - p.get_layout().get_margin().get_xMin() - p.get_layout().get_margin().get_xMax();
		var ph;
		if(p == null) ph = 0; else ph = p.get_height() - p.get_layout().get_margin().get_yMin() - p.get_layout().get_margin().get_yMax();
		if((this.m_flag & haxor.ui.LayoutFlag.PositionX) != 0) this.m_element.set_x(pw * this.get_x());
		if((this.m_flag & haxor.ui.LayoutFlag.PositionY) != 0) this.m_element.set_y(ph * this.get_y());
		if((this.m_flag & haxor.ui.LayoutFlag.PivotX) != 0) this.m_element.set_px(this.m_element.get_width() * this.get_px());
		if((this.m_flag & haxor.ui.LayoutFlag.PivotY) != 0) this.m_element.set_py(this.m_element.get_height() * this.get_py());
		if((this.m_flag & haxor.ui.LayoutFlag.SizeX) != 0) this.m_element.set_width(pw * this.get_width());
		if((this.m_flag & haxor.ui.LayoutFlag.SizeY) != 0) this.m_element.set_height(ph * this.get_height());
		this.m_lock = false;
	}
	,__class__: haxor.ui.Layout
	,__properties__: {set_margin:"set_margin",get_margin:"get_margin",set_flag:"set_flag",get_flag:"get_flag",set_height:"set_height",get_height:"get_height",set_width:"set_width",get_width:"get_width",set_y:"set_y",get_y:"get_y",set_x:"set_x",get_x:"get_x",set_py:"set_py",get_py:"get_py",set_px:"set_px",get_px:"get_px"}
};
haxor.ui.LayoutFlag = function() { };
$hxClasses["haxor.ui.LayoutFlag"] = haxor.ui.LayoutFlag;
haxor.ui.LayoutFlag.__name__ = ["haxor","ui","LayoutFlag"];
haxor.ui.Sprite = function(p_use_canvas,p_src) {
	if(p_src == null) p_src = "";
	if(p_use_canvas == null) p_use_canvas = true;
	var _g = this;
	haxor.ui.Container.call(this);
	if(p_use_canvas) {
		var c;
		var _this = window.document;
		c = _this.createElement("canvas");
		c.style.setProperty("pointer-events","none","");
		c.style.zIndex = "auto";
		c.style.position = "absolute";
		this.m_buffer = c.getContext("2d");
		this.m_element.appendChild(c);
	}
	this.m_slices = [];
	this.m_pattern = false;
	if(p_src != "") {
		var img = new Image();
		img.style.setProperty("pointer-events","none","");
		img.src = p_src;
		img.onload = function(e) {
			_g.set_image(img);
		};
	}
};
$hxClasses["haxor.ui.Sprite"] = haxor.ui.Sprite;
haxor.ui.Sprite.__name__ = ["haxor","ui","Sprite"];
haxor.ui.Sprite.__super__ = haxor.ui.Container;
haxor.ui.Sprite.prototype = $extend(haxor.ui.Container.prototype,{
	get_slices: function() {
		return this.m_slices.slice();
	}
	,set_slices: function(v) {
		if(v == null) this.m_slices = v = []; else this.m_slices = v.slice();
		this.OnRepaint();
		return v;
	}
	,set_pattern: function(v) {
		this.m_pattern = v;
		this.OnRepaint();
		return v;
	}
	,get_pattern: function() {
		return this.m_pattern;
	}
	,get_image: function() {
		return this.m_image;
	}
	,set_image: function(v) {
		if(this.m_buffer == null) {
			if(this.m_image != null) {
				if(this.m_element == this.m_image.parentElement) this.m_element.removeChild(this.m_image);
			}
		}
		if(this.m_image == null) {
			if(v != null) {
				this.set_width(this.get_width() <= 0?v.naturalWidth:this.get_width());
				this.set_height(this.get_height() <= 0?v.naturalHeight:this.get_height());
			}
		}
		this.m_image = v;
		if(this.m_buffer == null) {
			if(this.m_image != null) {
				this.m_image.style.position = "absolute";
				this.m_image.style.width = "100%";
				this.m_image.style.height = "100%";
				this.m_image.style.display = "inline";
				this.m_element.appendChild(this.m_image);
			}
		}
		this.OnRepaint();
		return v;
	}
	,OnRepaint: function() {
		haxor.ui.Container.prototype.OnRepaint.call(this);
		if(this.m_buffer != null) {
			this.m_buffer.canvas.width = this.m_width - (this.get_layout().get_margin().get_xMin() + this.get_layout().get_margin().get_xMax());
			this.m_buffer.canvas.height = this.m_height - (this.get_layout().get_margin().get_yMin() + this.get_layout().get_margin().get_yMax());
			if(this.m_image != null) {
				if(!this.m_pattern) this.DrawSlicedImage(this.m_buffer,this.m_image,this.m_buffer.canvas.width,this.m_buffer.canvas.height,this.m_slices); else {
					var p = this.m_buffer.createPattern(this.m_image,"repeat");
					this.m_buffer.rect(0,0,this.m_buffer.canvas.width,this.m_buffer.canvas.height);
					this.m_buffer.fillStyle = p;
					this.m_buffer.fill();
				}
			}
		} else if(this.m_image != null) {
			if(this.m_pattern) this.m_image.style.display = "none"; else this.m_image.style.display = "block";
			if(this.m_pattern) this.m_element.style.backgroundImage = "url(" + this.m_image.src + ")"; else this.m_element.style.backgroundImage = "";
			if(this.m_pattern) this.m_element.style.backgroundRepeat = "repeat"; else this.m_element.style.backgroundRepeat = "";
		}
	}
	,OnSkinChange: function(p_skin) {
		var img_skin = p_skin.Get(this.m_skin);
		if(img_skin != null) {
			this.set_image(img_skin.image);
			this.set_slices(img_skin.slices);
		}
	}
	,__class__: haxor.ui.Sprite
	,__properties__: $extend(haxor.ui.Container.prototype.__properties__,{set_image:"set_image",get_image:"get_image",set_pattern:"set_pattern",get_pattern:"get_pattern",set_slices:"set_slices",get_slices:"get_slices"})
});
haxor.ui.Stage = function() {
	haxor.ui.Container.call(this);
	this.m_mouseX = 0;
	this.m_mouseY = 0;
	this.set_x(this.set_y(0));
	this.get_body().insertBefore(this.m_element,this.get_body().firstChild);
	this.get_body().addEventListener("mousemove",$bind(this,this.OnMouseMove));
	haxor.core.Engine.Add(this);
	this.set_name("stage");
};
$hxClasses["haxor.ui.Stage"] = haxor.ui.Stage;
haxor.ui.Stage.__name__ = ["haxor","ui","Stage"];
haxor.ui.Stage.__interfaces__ = [haxor.core.IResizeable];
haxor.ui.Stage.__properties__ = {get_scrollWidth:"get_scrollWidth"}
haxor.ui.Stage.get_scrollWidth = function() {
	if(haxor.ui.Stage.m_scrollWidth > 0) return haxor.ui.Stage.m_scrollWidth;
	var outer = window.document.createElement("div");
	outer.style.visibility = "hidden";
	outer.style.width = "100px";
	outer.style.msOverflowStyle = "scrollbar";
	window.document.body.appendChild(outer);
	var widthNoScroll = outer.offsetWidth;
	outer.style.overflow = "scroll";
	var inner = window.document.createElement("div");
	inner.style.width = "100%";
	outer.appendChild(inner);
	var widthWithScroll = inner.offsetWidth;
	outer.parentNode.removeChild(outer);
	return haxor.ui.Stage.m_scrollWidth = widthNoScroll - widthWithScroll;
};
haxor.ui.Stage.__super__ = haxor.ui.Container;
haxor.ui.Stage.prototype = $extend(haxor.ui.Container.prototype,{
	get_body: function() {
		return window.document.body;
	}
	,get_document: function() {
		return window.document;
	}
	,get_window: function() {
		return window;
	}
	,set_width: function(v) {
		return v;
	}
	,get_width: function() {
		var bo = this.get_body().style.overflow;
		var v = this.get_window().innerWidth;
		return v;
	}
	,set_height: function(v) {
		return v;
	}
	,get_height: function() {
		var bo = this.get_body().style.overflow;
		var v = this.get_window().innerHeight;
		return v;
	}
	,get_mouseX: function() {
		return this.m_mouseX;
	}
	,get_mouseY: function() {
		return this.m_mouseY;
	}
	,get_needScroll: function() {
		return this.get_element().scrollHeight > this.get_element().clientHeight;
	}
	,OnMouseMove: function(p_event) {
		this.m_mouseX = p_event.clientX;
		this.m_mouseY = p_event.clientY;
	}
	,OnResize: function(p_width,p_height) {
		this.m_width = this.get_width();
		this.m_height = this.get_height();
		this.UpdateRect();
	}
	,__class__: haxor.ui.Stage
	,__properties__: $extend(haxor.ui.Container.prototype.__properties__,{get_needScroll:"get_needScroll",get_window:"get_window",get_document:"get_document",get_body:"get_body"})
});
haxor.ui.TextStyle = { __ename__ : true, __constructs__ : ["Regular","Italic","Bold","BoldItalic"] };
haxor.ui.TextStyle.Regular = ["Regular",0];
haxor.ui.TextStyle.Regular.__enum__ = haxor.ui.TextStyle;
haxor.ui.TextStyle.Italic = ["Italic",1];
haxor.ui.TextStyle.Italic.__enum__ = haxor.ui.TextStyle;
haxor.ui.TextStyle.Bold = ["Bold",2];
haxor.ui.TextStyle.Bold.__enum__ = haxor.ui.TextStyle;
haxor.ui.TextStyle.BoldItalic = ["BoldItalic",3];
haxor.ui.TextStyle.BoldItalic.__enum__ = haxor.ui.TextStyle;
haxor.ui.TextAligment = { __ename__ : true, __constructs__ : ["Left","Center","Right","Justify","MiddleLeft","MiddleCenter","MiddleRight","BottomLeft","BottomCenter","BottomRight"] };
haxor.ui.TextAligment.Left = ["Left",0];
haxor.ui.TextAligment.Left.__enum__ = haxor.ui.TextAligment;
haxor.ui.TextAligment.Center = ["Center",1];
haxor.ui.TextAligment.Center.__enum__ = haxor.ui.TextAligment;
haxor.ui.TextAligment.Right = ["Right",2];
haxor.ui.TextAligment.Right.__enum__ = haxor.ui.TextAligment;
haxor.ui.TextAligment.Justify = ["Justify",3];
haxor.ui.TextAligment.Justify.__enum__ = haxor.ui.TextAligment;
haxor.ui.TextAligment.MiddleLeft = ["MiddleLeft",4];
haxor.ui.TextAligment.MiddleLeft.__enum__ = haxor.ui.TextAligment;
haxor.ui.TextAligment.MiddleCenter = ["MiddleCenter",5];
haxor.ui.TextAligment.MiddleCenter.__enum__ = haxor.ui.TextAligment;
haxor.ui.TextAligment.MiddleRight = ["MiddleRight",6];
haxor.ui.TextAligment.MiddleRight.__enum__ = haxor.ui.TextAligment;
haxor.ui.TextAligment.BottomLeft = ["BottomLeft",7];
haxor.ui.TextAligment.BottomLeft.__enum__ = haxor.ui.TextAligment;
haxor.ui.TextAligment.BottomCenter = ["BottomCenter",8];
haxor.ui.TextAligment.BottomCenter.__enum__ = haxor.ui.TextAligment;
haxor.ui.TextAligment.BottomRight = ["BottomRight",9];
haxor.ui.TextAligment.BottomRight.__enum__ = haxor.ui.TextAligment;
haxor.ui.TextField = function(p_tag) {
	if(p_tag == null) p_tag = "span";
	var _g = this;
	var _this = window.document;
	this.m_element = _this.createElement("div");
	this.m_field = window.document.createElement(p_tag);
	this.m_field.style.position = "absolute";
	if(p_tag == "input" || p_tag == "textarea") {
		var ie = this.m_field;
		if(ie != null) ie.type = "text";
		this.m_field.style.background = "none";
		this.m_field.style.backgroundColor = "rgba(0,0,0,0)";
		this.m_field.style.border = "none";
		this.m_field.style.outline = "none";
		this.m_field.style.height = "100%";
		this.m_field.style.setProperty("-webkit-user-select","all","");
		this.m_field.style.setProperty("-moz-user-select","all","");
		this.m_field.style.setProperty("-o-user-select","all","");
		this.m_field.style.setProperty("-ms-user-select","all","");
		this.m_field.addEventListener("input",function(e) {
			_g.UpdateRect();
		});
	}
	this.m_element.appendChild(this.m_field);
	this.m_aligment = haxor.ui.TextAligment.Left;
	this.m_fontStyle = haxor.ui.TextStyle.Regular;
	this.m_text = "";
	this.m_html = false;
	this.m_fontSize = 12;
	this.m_font = "'Trebuchet MS','Lucida Sans Unicode', 'Lucida Grande', sans-serif";
	this.set_overflow("hidden");
	this.m_element.style.wordWrap = "break-word";
	this.m_field.style.wordWrap = "break-word";
	this.m_wordwrap = false;
	this.m_field.style.textAlign = "left";
	this.m_field.style.fontWeight = "normal";
	this.m_field.style.fontStyle = "normal";
	this.m_field.style.fontSize = "12pt";
	this.m_field.style.fontFamily = this.m_font;
	this.m_element.style.whiteSpace = "nowrap";
	this.m_field.style.width = "";
	this.set_color(haxor.math.Color.get_black());
	this.m_skin = "default";
	haxor.ui.UIEntity.call(this);
	this.set_selectable(true);
	this.m_filters.target = this.m_field;
	if(this.get_input()) {
		this.m_element.onclick = function(e1) {
			_g.m_field.focus();
		};
		if(js.Boot.__instanceof(this.m_field,HTMLTextAreaElement)) this.m_tacb = window.setInterval(function() {
			var fsw = Std.parseInt(StringTools.replace(_g.m_field.style.width,"px",""));
			var fsh = Std.parseInt(StringTools.replace(_g.m_field.style.height,"px",""));
			var dw = fsw - _g.m_taw;
			var dh = fsh - _g.m_tah;
			if((dw < 0?-dw:dw) <= 0) {
				if((dh < 0?-dh:dh) <= 0) return;
			}
			if(_g.onarearesize != null) _g.onarearesize(dw,dh);
		},30);
	}
};
$hxClasses["haxor.ui.TextField"] = haxor.ui.TextField;
haxor.ui.TextField.__name__ = ["haxor","ui","TextField"];
haxor.ui.TextField.__super__ = haxor.ui.UIEntity;
haxor.ui.TextField.prototype = $extend(haxor.ui.UIEntity.prototype,{
	set_name: function(v) {
		haxor.ui.UIEntity.prototype.set_name.call(this,v);
		this.m_field.setAttribute("name",v);
		return v;
	}
	,get_element: function() {
		return this.m_element;
	}
	,get_field: function() {
		return this.m_field;
	}
	,get_font: function() {
		return this.m_font;
	}
	,set_font: function(v) {
		this.m_font = v;
		this.m_field.style.fontFamily = v;
		this.UpdateRect();
		return v;
	}
	,get_fontSize: function() {
		return this.m_fontSize;
	}
	,set_fontSize: function(v) {
		this.m_fontSize = v;
		this.m_field.style.fontSize = v + "pt";
		this.UpdateRect();
		return v;
	}
	,get_fontStyle: function() {
		return this.m_fontStyle;
	}
	,set_fontStyle: function(v) {
		this.m_fontStyle = v;
		switch(v[1]) {
		case 0:
			this.m_field.style.fontWeight = "normal";
			this.m_field.style.fontStyle = "normal";
			break;
		case 2:
			this.m_field.style.fontWeight = "bold";
			break;
		case 3:
			this.m_field.style.fontWeight = "bold";
			this.m_field.style.fontStyle = "italic";
			break;
		case 1:
			this.m_field.style.fontWeight = "normal";
			this.m_field.style.fontStyle = "italic";
			break;
		}
		this.UpdateRect();
		return v;
	}
	,get_aligment: function() {
		return this.m_aligment;
	}
	,set_aligment: function(v) {
		this.m_aligment = v;
		switch(v[1]) {
		case 0:
			this.m_field.style.textAlign = "left";
			break;
		case 1:
			this.m_field.style.textAlign = "center";
			break;
		case 2:
			this.m_field.style.textAlign = "right";
			break;
		case 3:
			this.m_field.style.textAlign = "justify";
			break;
		case 4:
			this.m_field.style.textAlign = "left";
			break;
		case 5:
			this.m_field.style.textAlign = "center";
			break;
		case 6:
			this.m_field.style.textAlign = "right";
			break;
		case 7:
			this.m_field.style.textAlign = "left";
			break;
		case 8:
			this.m_field.style.textAlign = "center";
			break;
		case 9:
			this.m_field.style.textAlign = "right";
			break;
		}
		this.UpdateRect();
		return v;
	}
	,get_text: function() {
		var f = this.m_field;
		if(js.Boot.__instanceof(f,HTMLInputElement)) return f.value;
		return this.m_text;
	}
	,set_text: function(v) {
		this.m_text = v;
		var f = this.m_field;
		if(js.Boot.__instanceof(f,HTMLInputElement)) f.value = v; else if(this.m_html) f.innerHTML = v; else f.textContent = v;
		this.UpdateRect();
		return v;
	}
	,get_color: function() {
		return this.m_color.get_clone();
	}
	,set_color: function(v) {
		this.m_color = v.get_clone();
		this.m_field.style.color = v.get_css();
		return v;
	}
	,get_textWidth: function() {
		if(this.get_appended()) return this.m_field.clientWidth;
		var cp = this.m_element.cloneNode(true);
		window.document.body.appendChild(cp);
		var len = cp.firstElementChild.clientWidth;
		window.document.body.removeChild(cp);
		return len;
	}
	,get_textHeight: function() {
		if(this.get_appended()) return this.m_field.clientHeight;
		var cp = this.m_element.cloneNode(true);
		window.document.body.appendChild(cp);
		var len = cp.firstElementChild.clientHeight;
		window.document.body.removeChild(cp);
		return len;
	}
	,get_lineHeight: function() {
		var len = 0;
		var f = this.m_field.cloneNode(true);
		window.document.body.appendChild(f);
		var t;
		if(js.Boot.__instanceof(f,HTMLInputElement)) t = f.value; else t = f.innerHTML;
		if(js.Boot.__instanceof(f,HTMLInputElement)) f.value = "W"; else f.innerHTML = "W";
		len = f.clientHeight;
		window.document.body.removeChild(f);
		return len;
	}
	,get_wordwrap: function() {
		return this.m_wordwrap;
	}
	,set_wordwrap: function(v) {
		this.m_wordwrap = v;
		if(v) this.m_element.style.whiteSpace = "normal"; else this.m_element.style.whiteSpace = "nowrap";
		if(v) this.m_field.style.width = "100%"; else this.m_field.style.width = "";
		this.UpdateRect();
		return v;
	}
	,get_html: function() {
		return this.m_html;
	}
	,set_html: function(v) {
		this.m_html = v;
		this.set_text(this.m_text);
		return v;
	}
	,get_password: function() {
		if(this.get_input()) {
			var ie = this.m_field;
			return ie.type == "password";
		} else return false;
	}
	,set_password: function(v) {
		if(this.get_input()) {
			var ie = this.m_field;
			if(v) ie.type = "password"; else ie.type = "text";
		}
		return v;
	}
	,get_caption: function() {
		if(this.get_input()) {
			var ie = this.m_field;
			return ie.placeholder;
		} else return "";
	}
	,set_caption: function(v) {
		if(this.get_input()) {
			var ie = this.m_field;
			ie.placeholder = v;
		}
		return v;
	}
	,get_maxchar: function() {
		if(this.get_input()) {
			var ie = this.m_field;
			return ie.maxLength;
		} else return 0;
	}
	,set_maxchar: function(v) {
		if(this.get_input()) {
			var ie = this.m_field;
			ie.maxLength = v;
		}
		return v;
	}
	,get_input: function() {
		return js.Boot.__instanceof(this.m_field,HTMLInputElement) || js.Boot.__instanceof(this.m_field,HTMLTextAreaElement);
	}
	,UpdateRect: function() {
		haxor.ui.UIEntity.prototype.UpdateRect.call(this);
		var r = this.get_rect();
		var rw = r.get_width();
		var rh = r.get_height();
		var tx = 0;
		var ty = 0;
		var tw;
		if(this.get_wordwrap()) tw = rw; else tw = this.get_textWidth();
		var th = this.get_textHeight() + 2;
		var _g = this.m_aligment;
		switch(_g[1]) {
		case 0:
			tx = 0.0;
			ty = 0.0;
			break;
		case 1:
			tx = 0.5;
			ty = 0.0;
			break;
		case 2:
			tx = 1.0;
			ty = 0.0;
			break;
		case 3:
			tx = 0.0;
			ty = 0.0;
			break;
		case 4:
			tx = 0.0;
			ty = 0.5;
			break;
		case 5:
			tx = 0.5;
			ty = 0.5;
			break;
		case 6:
			tx = 1.0;
			ty = 0.5;
			break;
		case 7:
			tx = 0.0;
			ty = 1.0;
			break;
		case 8:
			tx = 0.5;
			ty = 1.0;
			break;
		case 9:
			tx = 1.0;
			ty = 1.0;
			break;
		}
		this.m_field.style.left = (rw - tw) * tx + "px";
		this.m_field.style.top = (rh - th) * ty + "px";
		if(js.Boot.__instanceof(this.m_field,HTMLTextAreaElement)) {
			var ta = this.m_field;
			ta.style.width = (this.m_taw = rw - 4) + "px";
			ta.style.height = (this.m_tah = rh - 4 - 8) + "px";
			ta.style.top = "4px";
		}
	}
	,OnSkinChange: function(p_skin) {
		var s = p_skin.Get(this.m_skin);
		if(s != null) {
			this.set_font(s.font);
			this.set_fontSize(s.size);
			this.set_fontStyle(s.style);
			this.set_color(s.color);
			this.set_aligment(s.aligment);
		}
	}
	,__class__: haxor.ui.TextField
	,__properties__: $extend(haxor.ui.UIEntity.prototype.__properties__,{get_input:"get_input",set_maxchar:"set_maxchar",get_maxchar:"get_maxchar",set_caption:"set_caption",get_caption:"get_caption",set_password:"set_password",get_password:"get_password",set_html:"set_html",get_html:"get_html",set_wordwrap:"set_wordwrap",get_wordwrap:"get_wordwrap",get_lineHeight:"get_lineHeight",get_textHeight:"get_textHeight",get_textWidth:"get_textWidth",set_color:"set_color",get_color:"get_color",set_text:"set_text",get_text:"get_text",set_aligment:"set_aligment",get_aligment:"get_aligment",set_fontStyle:"set_fontStyle",get_fontStyle:"get_fontStyle",set_fontSize:"set_fontSize",get_fontSize:"get_fontSize",set_font:"set_font",get_font:"get_font",get_field:"get_field",get_element:"get_element"})
});
haxor.ui.StrokeFilter = function(p_filter) {
	this.m_filter = p_filter;
	this.m_width = 0;
	this.m_color = haxor.math.Color.get_black();
};
$hxClasses["haxor.ui.StrokeFilter"] = haxor.ui.StrokeFilter;
haxor.ui.StrokeFilter.__name__ = ["haxor","ui","StrokeFilter"];
haxor.ui.StrokeFilter.prototype = {
	get_width: function() {
		return this.m_width;
	}
	,set_width: function(v) {
		this.m_width = v;
		this.m_filter.Update();
		return v;
	}
	,get_color: function() {
		return this.m_color.get_clone();
	}
	,set_color: function(v) {
		this.m_color = v.get_clone();
		this.m_filter.Update();
		return v;
	}
	,__class__: haxor.ui.StrokeFilter
	,__properties__: {set_color:"set_color",get_color:"get_color",set_width:"set_width",get_width:"get_width"}
};
haxor.ui.ShadowFilter = function(p_filter) {
	this.m_filter = p_filter;
	this.m_x = 0;
	this.m_y = 0;
	this.m_blur = 0;
	this.m_color = haxor.math.Color.get_black();
};
$hxClasses["haxor.ui.ShadowFilter"] = haxor.ui.ShadowFilter;
haxor.ui.ShadowFilter.__name__ = ["haxor","ui","ShadowFilter"];
haxor.ui.ShadowFilter.prototype = {
	get_x: function() {
		return this.m_x;
	}
	,set_x: function(v) {
		this.m_x = v;
		this.m_filter.Update();
		return v;
	}
	,get_y: function() {
		return this.m_y;
	}
	,set_y: function(v) {
		this.m_y = v;
		this.m_filter.Update();
		return v;
	}
	,get_blur: function() {
		return this.m_blur;
	}
	,set_blur: function(v) {
		this.m_blur = v;
		this.m_filter.Update();
		return v;
	}
	,get_color: function() {
		return this.m_color.get_clone();
	}
	,set_color: function(v) {
		this.m_color = v.get_clone();
		this.m_filter.Update();
		return v;
	}
	,__class__: haxor.ui.ShadowFilter
	,__properties__: {set_color:"set_color",get_color:"get_color",set_blur:"set_blur",get_blur:"get_blur",set_y:"set_y",get_y:"get_y",set_x:"set_x",get_x:"get_x"}
};
haxor.ui.UIFilter = function(p_target) {
	this.target = p_target;
	this.Reset();
};
$hxClasses["haxor.ui.UIFilter"] = haxor.ui.UIFilter;
haxor.ui.UIFilter.__name__ = ["haxor","ui","UIFilter"];
haxor.ui.UIFilter.prototype = {
	get_blur: function() {
		return this.m_blur;
	}
	,set_blur: function(v) {
		this.m_blur = v;
		this.Update();
		return v;
	}
	,get_hue: function() {
		return this.m_hue;
	}
	,set_hue: function(v) {
		this.m_hue = v;
		this.Update();
		return v;
	}
	,get_shadow: function() {
		return this.m_shadow;
	}
	,get_textShadow: function() {
		return this.m_textShadow;
	}
	,get_textStroke: function() {
		return this.m_textStroke;
	}
	,get_boxShadow: function() {
		return this.m_boxShadow;
	}
	,get_sepia: function() {
		return this.m_sepia;
	}
	,set_sepia: function(v) {
		this.m_sepia = v;
		this.Update();
		return v;
	}
	,get_grayscale: function() {
		return this.m_grayscale;
	}
	,set_grayscale: function(v) {
		this.m_grayscale = v;
		this.Update();
		return v;
	}
	,get_brightness: function() {
		return this.m_brightness;
	}
	,set_brightness: function(v) {
		this.m_brightness = v;
		this.Update();
		return v;
	}
	,get_contrast: function() {
		return this.m_contrast;
	}
	,set_contrast: function(v) {
		this.m_contrast = v;
		this.Update();
		return v;
	}
	,get_invert: function() {
		return this.m_invert;
	}
	,set_invert: function(v) {
		this.m_invert = v;
		this.Update();
		return v;
	}
	,get_saturate: function() {
		return this.m_saturate;
	}
	,set_saturate: function(v) {
		this.m_saturate = v;
		this.Update();
		return v;
	}
	,Reset: function() {
		this.m_blur = 0;
		this.m_grayscale = 0;
		this.m_sepia = 0;
		this.m_brightness = 1;
		this.m_contrast = 1;
		this.m_hue = 0;
		this.m_invert = 0;
		this.m_saturate = 1;
		this.m_shadow = new haxor.ui.ShadowFilter(this);
		this.m_textShadow = new haxor.ui.ShadowFilter(this);
		this.m_boxShadow = new haxor.ui.ShadowFilter(this);
		this.m_textStroke = new haxor.ui.StrokeFilter(this);
		this.Update();
	}
	,Set: function(p_filter) {
		var f = p_filter;
		this.m_blur = f.m_blur;
		this.m_grayscale = f.m_grayscale;
		this.m_sepia = f.m_sepia;
		this.m_brightness = f.m_brightness;
		this.m_contrast = f.m_contrast;
		this.m_hue = f.m_hue;
		this.m_invert = f.m_invert;
		this.m_saturate = f.m_saturate;
		var sf0;
		var sf1;
		sf0 = this.m_shadow;
		sf1 = f.m_shadow;
		sf0.m_x = sf1.m_x;
		sf0.m_y = sf1.m_y;
		sf0.m_color = sf1.m_color.get_clone();
		sf0.m_blur = sf1.m_blur;
		sf0 = this.m_textShadow;
		sf1 = f.m_textShadow;
		sf0.m_x = sf1.m_x;
		sf0.m_y = sf1.m_y;
		sf0.m_color = sf1.m_color.get_clone();
		sf0.m_blur = sf1.m_blur;
		sf0 = this.m_boxShadow;
		sf1 = f.m_boxShadow;
		sf0.m_x = sf1.m_x;
		sf0.m_y = sf1.m_y;
		sf0.m_color = sf1.m_color.get_clone();
		sf0.m_blur = sf1.m_blur;
		this.m_textStroke.set_color(f.m_textStroke.get_color().get_clone());
		this.m_textStroke.m_width = f.m_textStroke.m_width;
		this.Update();
	}
	,Update: function() {
		if(this.target == null) return;
		var s = "";
		if(this.m_blur > 0) s += "blur(" + this.m_blur + "px) ";
		if(this.m_hue > 0) s += "hue-rotate(" + this.m_hue + "deg) ";
		if(haxor.math.Mathf.Abs(this.m_sepia) > haxor.math.Mathf.Epsilon) s += "sepia(" + this.m_sepia + ") ";
		if(haxor.math.Mathf.Abs(this.m_grayscale) > haxor.math.Mathf.Epsilon) s += "grayscale(" + this.m_grayscale + ") ";
		if(haxor.math.Mathf.Abs(this.m_brightness - 1.0) > haxor.math.Mathf.Epsilon) s += "brightness(" + this.m_brightness + ") ";
		if(haxor.math.Mathf.Abs(this.m_contrast - 1.0) > haxor.math.Mathf.Epsilon) s += "contrast(" + this.m_contrast + ") ";
		if(haxor.math.Mathf.Abs(this.m_invert) > haxor.math.Mathf.Epsilon) s += "invert(" + this.m_invert + ") ";
		if(haxor.math.Mathf.Abs(this.m_saturate - 1.0) > haxor.math.Mathf.Epsilon) s += "saturate(" + this.m_saturate + ") ";
		var shd;
		var stk;
		shd = this.m_shadow;
		if(shd.get_x() > 0 || shd.get_y() > 0 || shd.get_blur() > 0) s += "drop-shadow(" + shd.get_x() + "px " + shd.get_y() + "px " + shd.get_blur() + "px " + shd.get_color().get_css() + ") ";
		if(s == "") {
			this.target.style.removeProperty("-webkit-filter");
			this.target.style.removeProperty("-moz-filter");
		} else {
			this.target.style.setProperty("-webkit-filter",s,"");
			this.target.style.setProperty("-moz-filter",s,"");
		}
		shd = this.m_textShadow;
		if(shd.get_x() > 0 || shd.get_y() > 0 || shd.get_blur() > 0) this.target.style.textShadow = shd.get_x() + "px " + shd.get_y() + "px " + shd.get_blur() + "px " + shd.get_color().get_css(); else this.target.style.textShadow = "";
		shd = this.m_boxShadow;
		if(shd.get_x() > 0 || shd.get_y() > 0 || shd.get_blur() > 0) this.target.style.boxShadow = shd.get_x() + "px " + shd.get_y() + "px " + shd.get_blur() + "px " + shd.get_color().get_css(); else this.target.style.boxShadow = "";
		stk = this.m_textStroke;
		if(stk.get_width() > 0) {
			this.target.style.setProperty("-webkit-text-stroke",stk.get_width() + "px " + stk.get_color().get_css(),"");
			this.target.style.setProperty("-moz-text-stroke",stk.get_width() + "px " + stk.get_color().get_css(),"");
		} else {
			this.target.style.removeProperty("-webkit-text-stroke");
			this.target.style.removeProperty("-moz-text-stroke");
		}
	}
	,__class__: haxor.ui.UIFilter
	,__properties__: {set_saturate:"set_saturate",get_saturate:"get_saturate",set_invert:"set_invert",get_invert:"get_invert",set_contrast:"set_contrast",get_contrast:"get_contrast",set_brightness:"set_brightness",get_brightness:"get_brightness",set_grayscale:"set_grayscale",get_grayscale:"get_grayscale",set_sepia:"set_sepia",get_sepia:"get_sepia",get_boxShadow:"get_boxShadow",get_textStroke:"get_textStroke",get_textShadow:"get_textShadow",get_shadow:"get_shadow",set_hue:"set_hue",get_hue:"get_hue",set_blur:"set_blur",get_blur:"get_blur"}
};
haxor.ui.UISkin = function(p_data) {
	haxor.core.Resource.call(this);
	this.m_skins = [];
	this.m_table = new haxe.ds.StringMap();
	this.m_is_dependence = haxor.core.Asset.m_dependenceEnabled;
	var elements = p_data.elementsNamed("skin");
	var n = elements.next();
	this.set_name(n.exists("id")?n.get("id"):"default");
	if(n.exists("root")) this.m_root = n.get("root"); else this.m_root = "";
	elements = n.elements();
	while( elements.hasNext() ) {
		var it = elements.next();
		this.TraverseSkinStep(it);
	}
	haxor.ui.UISkin.list.push(this);
	if(haxor.ui.UISkin.list.length == 1) haxor.ui.UISkin.set_current(this);
};
$hxClasses["haxor.ui.UISkin"] = haxor.ui.UISkin;
haxor.ui.UISkin.__name__ = ["haxor","ui","UISkin"];
haxor.ui.UISkin.__properties__ = {set_current:"set_current",get_current:"get_current"}
haxor.ui.UISkin.Add = function(p_node) {
	haxor.ui.UISkin.m_nodes.push(p_node);
};
haxor.ui.UISkin.Remove = function(p_node) {
	HxOverrides.remove(haxor.ui.UISkin.m_nodes,p_node);
};
haxor.ui.UISkin.get_current = function() {
	return haxor.ui.UISkin.m_current;
};
haxor.ui.UISkin.set_current = function(v) {
	if(haxor.ui.UISkin.m_current == v) return v;
	haxor.ui.UISkin.m_current = v;
	if(v != null) {
		var _g1 = 0;
		var _g = haxor.ui.UISkin.m_nodes.length;
		while(_g1 < _g) {
			var i = _g1++;
			haxor.ui.UISkin.m_nodes[i].OnSkinChange(v);
		}
	}
	return v;
};
haxor.ui.UISkin.__super__ = haxor.core.Resource;
haxor.ui.UISkin.prototype = $extend(haxor.core.Resource.prototype,{
	get_skins: function() {
		return this.m_skins.slice();
	}
	,Get: function(p_skin) {
		if(this.m_table.exists(p_skin)) return this.m_table.get(p_skin); else return null;
	}
	,ParseSkinNode: function(n) {
		var _g = n.get_nodeName();
		switch(_g) {
		case "image":
			this.CreateImageSkin(n);
			break;
		case "filter":
			this.CreateFilterSkin(n);
			break;
		case "text":
			this.CreateTextSkin(n);
			break;
		case "skin":
			var s = new haxor.ui.BaseSkin();
			if(n.exists("id")) s.id = n.get("id"); else s.id = "default";
			s.xml = n;
			this.m_table.set(s.id,s);
			break;
		}
	}
	,CreateImageSkin: function(p_node) {
		var src;
		var img;
		var n = p_node;
		var nid;
		if(n.exists("id")) nid = n.get("id"); else nid = "default";
		var s = new haxor.ui.ImageSkin();
		s.xml = p_node;
		s.src = src = this.m_root + (n.exists("src")?n.get("src"):"");
		if(src != "") if(this.m_is_dependence) s.image = haxor.core.Asset.LoadImage(nid,src); else s.image = haxor.net.Web.LoadImage(src,function(d,p) {
		});
		var sstr;
		if(n.exists("slices")) sstr = n.get("slices"); else sstr = "";
		var stk = sstr.split(" ");
		s.slices = [];
		var _g1 = 0;
		var _g = stk.length;
		while(_g1 < _g) {
			var i = _g1++;
			s.slices.push(Std.parseInt(stk[i]));
		}
		this.m_table.set(nid,s);
	}
	,CreateTextSkin: function(p_node) {
		var n = p_node;
		var nid;
		if(n.exists("id")) nid = n.get("id"); else nid = "default";
		var s = new haxor.ui.TextSkin();
		s.xml = p_node;
		if(n.exists("font")) s.font = n.get("font"); else s.font = "Arial, sans serif";
		if(n.exists("size")) s.size = Std.parseInt(n.get("size")); else s.size = 12;
		s.color = haxor.math.Color.FromHex(n.exists("color")?n.get("color"):"0x0");
		var ta = (n.exists("aligment")?n.get("aligment"):"l").toLowerCase();
		s.aligment = haxor.ui.TextAligment.Left;
		switch(ta) {
		case "l":
			s.aligment = haxor.ui.TextAligment.Left;
			break;
		case "c":
			s.aligment = haxor.ui.TextAligment.Center;
			break;
		case "r":
			s.aligment = haxor.ui.TextAligment.Right;
			break;
		case "ml":
			s.aligment = haxor.ui.TextAligment.MiddleLeft;
			break;
		case "mc":
			s.aligment = haxor.ui.TextAligment.MiddleCenter;
			break;
		case "mr":
			s.aligment = haxor.ui.TextAligment.MiddleRight;
			break;
		case "bl":
			s.aligment = haxor.ui.TextAligment.BottomLeft;
			break;
		case "bc":
			s.aligment = haxor.ui.TextAligment.BottomCenter;
			break;
		case "br":
			s.aligment = haxor.ui.TextAligment.BottomRight;
			break;
		case "j":
			s.aligment = haxor.ui.TextAligment.Justify;
			break;
		}
		var ts = (n.exists("style")?n.get("style"):"regular").toLowerCase();
		s.style = haxor.ui.TextStyle.Regular;
		switch(ts) {
		case "regular":
			s.style = haxor.ui.TextStyle.Regular;
			break;
		case "bold":
			s.style = haxor.ui.TextStyle.Bold;
			break;
		case "italic":
			s.style = haxor.ui.TextStyle.Italic;
			break;
		case "bold italic":
			s.style = haxor.ui.TextStyle.BoldItalic;
			break;
		}
		this.m_table.set(nid,s);
	}
	,CreateFilterSkin: function(p_node) {
		var n = p_node;
		var nid;
		if(n.exists("id")) nid = n.get("id"); else nid = "default";
		var type;
		if(n.exists("type")) type = n.get("type"); else type = "";
		var s = new haxor.ui.BaseSkin();
		s.xml = p_node;
		var a = "";
		s.id = nid;
		var elements = p_node.elements();
		while( elements.hasNext() ) {
			var it = elements.next();
			var fn = it.get_nodeName();
			switch(fn) {
			case "blur":
				s.filter.set_blur(Std.parseInt(it.firstChild().toString() == ""?"1":it.firstChild().toString()));
				break;
			case "shadow":
				s.filter.get_shadow().set_x(Std.parseInt(it.exists("x")?it.get("x"):"0"));
				s.filter.get_shadow().set_y(Std.parseInt(it.exists("y")?it.get("y"):"0"));
				s.filter.get_shadow().set_color(haxor.math.Color.FromHex(it.exists("color")?it.get("color"):"0x0"));
				s.filter.get_shadow().set_blur(Std.parseInt(it.exists("blur")?it.get("blur"):"0"));
				break;
			case "text_shadow":
				s.filter.get_textShadow().set_x(Std.parseInt(it.exists("x")?it.get("x"):"0"));
				s.filter.get_textShadow().set_y(Std.parseInt(it.exists("y")?it.get("y"):"0"));
				s.filter.get_textShadow().set_color(haxor.math.Color.FromHex(it.exists("color")?it.get("color"):"0x0"));
				s.filter.get_textShadow().set_blur(Std.parseInt(it.exists("blur")?it.get("blur"):"0"));
				break;
			case "box_shadow":
				s.filter.get_boxShadow().set_x(Std.parseInt(it.exists("x")?it.get("x"):"0"));
				s.filter.get_boxShadow().set_y(Std.parseInt(it.exists("y")?it.get("y"):"0"));
				s.filter.get_boxShadow().set_color(haxor.math.Color.FromHex(it.exists("color")?it.get("color"):"0x0"));
				s.filter.get_boxShadow().set_blur(Std.parseInt(it.exists("blur")?it.get("blur"):"0"));
				break;
			case "text_stroke":
				s.filter.get_textStroke().set_color(haxor.math.Color.FromHex(it.exists("color")?it.get("color"):"0x0"));
				s.filter.get_textStroke().set_width(Std.parseInt(it.exists("width")?it.get("width"):"0"));
				break;
			case "brightness":
				s.filter.set_brightness(Std.parseFloat(it.firstChild().toString() == ""?"1":it.firstChild().toString()));
				break;
			case "contrast":
				s.filter.set_contrast(Std.parseFloat(it.firstChild().toString() == ""?"1":it.firstChild().toString()));
				break;
			case "grayscale":
				s.filter.set_grayscale(Std.parseFloat(it.firstChild().toString() == ""?"0":it.firstChild().toString()));
				break;
			case "hue":
				s.filter.set_hue(Std.parseInt(it.firstChild().toString() == ""?"0":it.firstChild().toString()));
				break;
			case "invert":
				s.filter.set_invert(Std.parseFloat(it.firstChild().toString() == ""?"0":it.firstChild().toString()));
				break;
			case "sepia":
				s.filter.set_sepia(Std.parseFloat(it.firstChild().toString() == ""?"0":it.firstChild().toString()));
				break;
			case "saturate":
				s.filter.set_saturate(Std.parseFloat(it.firstChild().toString() == ""?"1":it.firstChild().toString()));
				break;
			}
		}
		this.m_table.set(nid,s);
	}
	,TraverseSkinStep: function(p_node) {
		if(p_node.get_parent() != null) {
			if(p_node.get_parent().get_nodeName() == "filter") return;
		}
		this.ParseSkinNode(p_node);
		var elements = p_node.iterator();
		while( elements.hasNext() ) {
			var it = elements.next();
			this.TraverseSkinStep(it);
		}
	}
	,__class__: haxor.ui.UISkin
	,__properties__: $extend(haxor.core.Resource.prototype.__properties__,{get_skins:"get_skins"})
});
haxor.ui.BaseSkin = function() {
	this.filter = new haxor.ui.UIFilter();
	this.id = "";
};
$hxClasses["haxor.ui.BaseSkin"] = haxor.ui.BaseSkin;
haxor.ui.BaseSkin.__name__ = ["haxor","ui","BaseSkin"];
haxor.ui.BaseSkin.prototype = {
	__class__: haxor.ui.BaseSkin
};
haxor.ui.TextSkin = function() {
	haxor.ui.BaseSkin.call(this);
	this.font = "'Trebuchet MS','Lucida Sans Unicode', 'Lucida Grande', sans-serif";
	this.size = 12;
	this.color = haxor.math.Color.get_black();
	this.style = haxor.ui.TextStyle.Regular;
	this.aligment = haxor.ui.TextAligment.Left;
};
$hxClasses["haxor.ui.TextSkin"] = haxor.ui.TextSkin;
haxor.ui.TextSkin.__name__ = ["haxor","ui","TextSkin"];
haxor.ui.TextSkin.__super__ = haxor.ui.BaseSkin;
haxor.ui.TextSkin.prototype = $extend(haxor.ui.BaseSkin.prototype,{
	__class__: haxor.ui.TextSkin
});
haxor.ui.ImageSkin = function() {
	haxor.ui.BaseSkin.call(this);
	this.src = "";
	this.slices = [];
};
$hxClasses["haxor.ui.ImageSkin"] = haxor.ui.ImageSkin;
haxor.ui.ImageSkin.__name__ = ["haxor","ui","ImageSkin"];
haxor.ui.ImageSkin.__super__ = haxor.ui.BaseSkin;
haxor.ui.ImageSkin.prototype = $extend(haxor.ui.BaseSkin.prototype,{
	__class__: haxor.ui.ImageSkin
});
haxor.ui.component = {};
haxor.ui.component.UIComponent = function(p_entity) {
	haxor.core.Resource.call(this);
	this.m_entity = p_entity;
};
$hxClasses["haxor.ui.component.UIComponent"] = haxor.ui.component.UIComponent;
haxor.ui.component.UIComponent.__name__ = ["haxor","ui","component","UIComponent"];
haxor.ui.component.UIComponent.__super__ = haxor.core.Resource;
haxor.ui.component.UIComponent.prototype = $extend(haxor.core.Resource.prototype,{
	get_entity: function() {
		return this.m_entity;
	}
	,get_element: function() {
		return this.m_entity.m_element;
	}
	,set_name: function(v) {
		haxor.core.Resource.prototype.set_name.call(this,this.m_entity.set_name(v));
		return v;
	}
	,get_name: function() {
		return this.m_entity.get_name();
	}
	,AddComponent: function(p_type) {
		return this.get_entity().AddComponent(p_type);
	}
	,GetComponent: function(p_type) {
		return this.get_entity().GetComponent(p_type);
	}
	,GetComponents: function(p_type) {
		return this.get_entity().GetComponents(p_type);
	}
	,GetComponentInChildren: function(p_type) {
		return this.get_entity().GetComponentInChildren(p_type);
	}
	,GetComponentsInChildren: function(p_type) {
		return this.get_entity().GetComponentsInChildren(p_type);
	}
	,OnAddedToStage: function() {
	}
	,OnTransformUpdate: function() {
	}
	,OnRectUpdate: function() {
	}
	,OnMaterialUpdate: function() {
	}
	,__class__: haxor.ui.component.UIComponent
	,__properties__: $extend(haxor.core.Resource.prototype.__properties__,{get_element:"get_element",get_entity:"get_entity"})
});
haxor.ui.form = {};
haxor.ui.form.FPSCounter = function(p_refresh_rate) {
	if(p_refresh_rate == null) p_refresh_rate = 1.0;
	haxor.ui.TextField.call(this);
	this.m_rate = p_refresh_rate;
	this.m_elapsed = 0;
	this.m_frames = 0;
	this.m_samples = [];
	this.set_text("0fps");
	this.get_layout().set_x(1);
	this.set_fontSize(18);
	this.get_layout().set_flag(haxor.ui.LayoutFlag.PositionX);
	this.set_y(0);
	this.set_px(205);
	this.set_width(200);
	this.set_height(this.get_textHeight());
	this.set_aligment(haxor.ui.TextAligment.Right);
	this.set_color(haxor.math.Color.get_yellow());
	this.get_filters().get_textShadow().set_color(haxor.math.Color.get_black());
	this.get_filters().get_textShadow().set_y(2);
	this.set_wordwrap(false);
	this.set_mouseEnabled(false);
	this.m_element.onselect = function(e) {
		e.preventDefault();
	};
	haxor.core.Engine.Add(this);
};
$hxClasses["haxor.ui.form.FPSCounter"] = haxor.ui.form.FPSCounter;
haxor.ui.form.FPSCounter.__name__ = ["haxor","ui","form","FPSCounter"];
haxor.ui.form.FPSCounter.__interfaces__ = [haxor.core.IUpdateable];
haxor.ui.form.FPSCounter.__super__ = haxor.ui.TextField;
haxor.ui.form.FPSCounter.prototype = $extend(haxor.ui.TextField.prototype,{
	OnUpdate: function() {
		this.m_elapsed += haxor.core.Time.get_frameDeltaTime();
		if(this.m_elapsed >= this.m_rate) {
			this.m_elapsed -= this.m_rate;
			this.m_samples.push(this.m_frames / this.m_rate);
			var avg = 0.0;
			var _g1 = 0;
			var _g = this.m_samples.length;
			while(_g1 < _g) {
				var i = _g1++;
				avg += this.m_samples[i] / this.m_samples.length;
			}
			if(this.m_samples.length > 1) this.m_samples.shift();
			this.set_text((avg | 0) + "fps " + Std.string(haxor.component.Transform.m_threaded));
			this.m_frames = 0;
			return;
		}
		this.m_frames += 1;
	}
	,__class__: haxor.ui.form.FPSCounter
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
function $iterator(o) { if( o instanceof Array ) return function() { return HxOverrides.iter(o); }; return typeof(o.iterator) == 'function' ? $bind(o,o.iterator) : o.iterator; }
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
setTimeout(function(){ haxor.core.Engine.Run();  },1);
var q = window.jQuery;
js.JQuery = q;
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
haxor.core.Resource.m_hashCode = 0;
haxor.api.ShaderAPI.m_attribs = ["vertex","normal","uv0","uv1","color","weight","index"];
haxor.api.TextureAPI.HALF_FLOAT_LINEAR = false;
haxor.api.TextureAPI.HALF_FLOAT_OES = -1;
haxor.api.TextureAPI.TEXTURE_MAX_ANISOTROPY_EXT = -1;
haxor.api.TextureAPI.TEXTURE_FLOAT = false;
haxor.api.TextureAPI.TEXTURE_DEPTH = false;
haxor.component.FloatKeyFrame.m_temp = new haxor.component.FloatKeyFrame();
haxor.component.Vector3KeyFrame.m_temp = new haxor.component.Vector3KeyFrame();
haxor.component.QuaternionKeyFrame.m_temp = new haxor.component.QuaternionKeyFrame();
haxor.component.ClearFlag.None = 0;
haxor.component.ClearFlag.Color = 1;
haxor.component.ClearFlag.Depth = 2;
haxor.component.ClearFlag.Skybox = 4;
haxor.component.ClearFlag.ColorDepth = 3;
haxor.component.ClearFlag.SkyboxDepth = 6;
haxor.component.Light.ambient = new haxor.math.Color(0.0,0.0,0.0,1.0);
haxor.component.Light.max = 8;
haxor.component.Light.m_list = [];
haxor.component.MeshRenderer.m_next_cull_test = 0;
haxor.component.MeshRenderer.log = "";
haxor.core.Asset.m_database = new haxe.ds.StringMap();
haxor.core.Asset.m_url = new haxe.ds.StringMap();
haxor.core.Asset.m_progress = new haxe.ds.StringMap();
haxor.core.Asset.m_materials = [];
haxor.core.Asset.m_dependences = [];
haxor.core.Asset.m_isdependence = new haxe.ds.StringMap();
haxor.core.Asset.m_dependenceEnabled = false;
haxor.core.Console.m_console = console;
haxor.core.Console.m_style = "";
haxor.core.Engine.VERSION_MAJOR = 0;
haxor.core.Engine.VERSION_MINOR = 5;
haxor.core.Engine.VERSION_BUILD = 5;
haxor.core.Engine.version = haxor.core.Engine.VERSION_MAJOR + "." + haxor.core.Engine.VERSION_MINOR + "." + haxor.core.Engine.VERSION_BUILD;
haxor.core.Engine.pause = false;
haxor.core.Engine.m_garbageCollectRate = 10;
haxor.core.Engine.rqid = 0;
haxor.core.Engine.rqdbg = "";
haxor.core.Engine.m_nextCompare = 0;
haxor.core.Stats.renderCount = 0;
haxor.core.Stats.visibleCount = 0;
haxor.core.Stats.invisibleCount = 0;
haxor.core.Stats.cullTests = 0;
haxor.core.Time.scale = 1.0;
haxor.editor.Gizmo.GIZMO_POINT = 0.0;
haxor.editor.Gizmo.GIZMO_LINE = 1.0;
haxor.editor.Gizmo.GIZMO_TRANSFORM = 2.0;
haxor.editor.Gizmo.GIZMO_BOX = 3.0;
haxor.editor.Gizmo.GIZMO_SPHERE = 4.0;
haxor.editor.Gizmo.colliders = false;
haxor.editor.Gizmo.lights = false;
haxor.editor.Gizmo.sphereBounds = false;
haxor.editor.Gizmo.AABBBounds = false;
haxor.editor.Gizmo.meshes = false;
haxor.editor.Gizmo.particles = false;
haxor.editor.Gizmo.transforms = false;
haxor.editor.Gizmo.m_color_collider = new haxor.math.Color(0.5,0.9,0.5);
haxor.editor.Gizmo.m_color_trigger = new haxor.math.Color(0.9,0.5,0.5);
haxor.editor.Gizmo.m_color_light = new haxor.math.Color(1.0,1.0,0.5);
haxor.editor.Gizmo.m_color_bounds = new haxor.math.Color(0.95,0.95,0.5);
haxor.editor.Gizmo.m_color_mesh = new haxor.math.Color(0.6,0.6,0.95);
haxor.editor.Gizmo.m_color_particle = new haxor.math.Color(0.95,0.6,0.95);
haxor.editor.Gizmo.m_color_x = new haxor.math.Color(0.9,0.3,0.3);
haxor.editor.Gizmo.m_color_y = new haxor.math.Color(0.3,0.9,0.3);
haxor.editor.Gizmo.m_color_z = new haxor.math.Color(0.3,0.3,0.9);
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
haxor.graphics.RenderQueue.Background = 0;
haxor.graphics.RenderQueue.Opaque = 1000;
haxor.graphics.RenderQueue.Geometry = 2000;
haxor.graphics.RenderQueue.Transparent = 3000;
haxor.graphics.RenderQueue.Overlay = 4000;
haxor.graphics.RenderQueue.Interface = 5000;
haxor.graphics.Screen.m_width = 0;
haxor.graphics.Screen.m_height = 0;
haxor.input.Joystick.analogBias = [0.1,0.9];
haxor.input.Joystick.buttonBias = 0.9;
haxor.input.Joystick.available = false;
haxor.input.Joystick.FACE_1 = 0;
haxor.input.Joystick.FACE_2 = 1;
haxor.input.Joystick.FACE_3 = 2;
haxor.input.Joystick.FACE_4 = 3;
haxor.input.Joystick.LEFT_SHOULDER = 4;
haxor.input.Joystick.RIGHT_SHOULDER = 5;
haxor.input.Joystick.LEFT_SHOULDER_BOTTOM = 6;
haxor.input.Joystick.RIGHT_SHOULDER_BOTTOM = 7;
haxor.input.Joystick.SELECT = 8;
haxor.input.Joystick.START = 9;
haxor.input.Joystick.LEFT_ANALOGUE_STICK = 10;
haxor.input.Joystick.RIGHT_ANALOGUE_STICK = 11;
haxor.input.Joystick.PAD_TOP = 12;
haxor.input.Joystick.PAD_BOTTOM = 13;
haxor.input.Joystick.PAD_LEFT = 14;
haxor.input.Joystick.PAD_RIGHT = 15;
haxor.input.Joystick.LEFT_ANALOGUE_HOR = 0;
haxor.input.Joystick.LEFT_ANALOGUE_VERT = 1;
haxor.input.Joystick.RIGHT_ANALOGUE_HOR = 2;
haxor.input.Joystick.RIGHT_ANALOGUE_VERT = 3;
haxor.input.Input.scroll = false;
haxor.input.KeyCode.Modifiers = -65536;
haxor.input.KeyCode.None = 0;
haxor.input.KeyCode.Mouse0 = 1;
haxor.input.KeyCode.Mouse1 = 2;
haxor.input.KeyCode.Cancel = 3;
haxor.input.KeyCode.Mouse2 = 4;
haxor.input.KeyCode.Mouse3 = 5;
haxor.input.KeyCode.Mouse4 = 6;
haxor.input.KeyCode.Back = 8;
haxor.input.KeyCode.Tab = 9;
haxor.input.KeyCode.LineFeed = 10;
haxor.input.KeyCode.Clear = 12;
haxor.input.KeyCode.Enter = 13;
haxor.input.KeyCode.Return = 13;
haxor.input.KeyCode.ShiftKey = 16;
haxor.input.KeyCode.ControlKey = 17;
haxor.input.KeyCode.Alt = 18;
haxor.input.KeyCode.Pause = 19;
haxor.input.KeyCode.CapsLock = 20;
haxor.input.KeyCode.Capital = 20;
haxor.input.KeyCode.KanaMode = 21;
haxor.input.KeyCode.HanguelMode = 21;
haxor.input.KeyCode.HangulMode = 21;
haxor.input.KeyCode.JunjaMode = 23;
haxor.input.KeyCode.FinalMode = 24;
haxor.input.KeyCode.KanjiMode = 25;
haxor.input.KeyCode.HanjaMode = 25;
haxor.input.KeyCode.Escape = 27;
haxor.input.KeyCode.IMEConvert = 28;
haxor.input.KeyCode.IMENonconvert = 29;
haxor.input.KeyCode.IMEAceept = 30;
haxor.input.KeyCode.IMEAccept = 30;
haxor.input.KeyCode.IMEModeChange = 31;
haxor.input.KeyCode.Space = 32;
haxor.input.KeyCode.Prior = 33;
haxor.input.KeyCode.PageUp = 33;
haxor.input.KeyCode.Next = 34;
haxor.input.KeyCode.PageDown = 34;
haxor.input.KeyCode.End = 35;
haxor.input.KeyCode.Home = 36;
haxor.input.KeyCode.Left = 37;
haxor.input.KeyCode.Up = 38;
haxor.input.KeyCode.Right = 39;
haxor.input.KeyCode.Down = 40;
haxor.input.KeyCode.Select = 41;
haxor.input.KeyCode.Print = 42;
haxor.input.KeyCode.Execute = 43;
haxor.input.KeyCode.PrintScreen = 44;
haxor.input.KeyCode.Snapshot = 44;
haxor.input.KeyCode.Insert = 45;
haxor.input.KeyCode.Delete = 46;
haxor.input.KeyCode.Help = 47;
haxor.input.KeyCode.D0 = 48;
haxor.input.KeyCode.D1 = 49;
haxor.input.KeyCode.D2 = 50;
haxor.input.KeyCode.D3 = 51;
haxor.input.KeyCode.D4 = 52;
haxor.input.KeyCode.D5 = 53;
haxor.input.KeyCode.D6 = 54;
haxor.input.KeyCode.D7 = 55;
haxor.input.KeyCode.D8 = 56;
haxor.input.KeyCode.D9 = 57;
haxor.input.KeyCode.A = 65;
haxor.input.KeyCode.B = 66;
haxor.input.KeyCode.C = 67;
haxor.input.KeyCode.D = 68;
haxor.input.KeyCode.E = 69;
haxor.input.KeyCode.F = 70;
haxor.input.KeyCode.G = 71;
haxor.input.KeyCode.H = 72;
haxor.input.KeyCode.I = 73;
haxor.input.KeyCode.J = 74;
haxor.input.KeyCode.K = 75;
haxor.input.KeyCode.L = 76;
haxor.input.KeyCode.M = 77;
haxor.input.KeyCode.N = 78;
haxor.input.KeyCode.O = 79;
haxor.input.KeyCode.P = 80;
haxor.input.KeyCode.Q = 81;
haxor.input.KeyCode.R = 82;
haxor.input.KeyCode.S = 83;
haxor.input.KeyCode.T = 84;
haxor.input.KeyCode.U = 85;
haxor.input.KeyCode.V = 86;
haxor.input.KeyCode.W = 87;
haxor.input.KeyCode.X = 88;
haxor.input.KeyCode.Y = 89;
haxor.input.KeyCode.Z = 90;
haxor.input.KeyCode.LWin = 91;
haxor.input.KeyCode.RWin = 92;
haxor.input.KeyCode.Apps = 93;
haxor.input.KeyCode.Sleep = 95;
haxor.input.KeyCode.NumPad0 = 96;
haxor.input.KeyCode.NumPad1 = 97;
haxor.input.KeyCode.NumPad2 = 98;
haxor.input.KeyCode.NumPad3 = 99;
haxor.input.KeyCode.NumPad4 = 100;
haxor.input.KeyCode.NumPad5 = 101;
haxor.input.KeyCode.NumPad6 = 102;
haxor.input.KeyCode.NumPad7 = 103;
haxor.input.KeyCode.NumPad8 = 104;
haxor.input.KeyCode.NumPad9 = 105;
haxor.input.KeyCode.Multiply = 106;
haxor.input.KeyCode.Add = 107;
haxor.input.KeyCode.Separator = 108;
haxor.input.KeyCode.Subtract = 109;
haxor.input.KeyCode.Decimal = 110;
haxor.input.KeyCode.Divide = 111;
haxor.input.KeyCode.F1 = 112;
haxor.input.KeyCode.F2 = 113;
haxor.input.KeyCode.F3 = 114;
haxor.input.KeyCode.F4 = 115;
haxor.input.KeyCode.F5 = 116;
haxor.input.KeyCode.F6 = 117;
haxor.input.KeyCode.F7 = 118;
haxor.input.KeyCode.F8 = 119;
haxor.input.KeyCode.F9 = 120;
haxor.input.KeyCode.F10 = 121;
haxor.input.KeyCode.F11 = 122;
haxor.input.KeyCode.F12 = 123;
haxor.input.KeyCode.F13 = 124;
haxor.input.KeyCode.F14 = 125;
haxor.input.KeyCode.F15 = 126;
haxor.input.KeyCode.F16 = 127;
haxor.input.KeyCode.F17 = 128;
haxor.input.KeyCode.F18 = 129;
haxor.input.KeyCode.F19 = 130;
haxor.input.KeyCode.F20 = 131;
haxor.input.KeyCode.F21 = 132;
haxor.input.KeyCode.F22 = 133;
haxor.input.KeyCode.F23 = 134;
haxor.input.KeyCode.F24 = 135;
haxor.input.KeyCode.NumLock = 144;
haxor.input.KeyCode.Scroll = 145;
haxor.input.KeyCode.LShiftKey = 160;
haxor.input.KeyCode.RShiftKey = 161;
haxor.input.KeyCode.LControlKey = 162;
haxor.input.KeyCode.RControlKey = 163;
haxor.input.KeyCode.LAlt = 164;
haxor.input.KeyCode.RAlt = 165;
haxor.input.KeyCode.BrowserBack = 166;
haxor.input.KeyCode.BrowserForward = 167;
haxor.input.KeyCode.BrowserRefresh = 168;
haxor.input.KeyCode.BrowserStop = 169;
haxor.input.KeyCode.BrowserSearch = 170;
haxor.input.KeyCode.BrowserFavorites = 171;
haxor.input.KeyCode.BrowserHome = 172;
haxor.input.KeyCode.VolumeMute = 173;
haxor.input.KeyCode.VolumeDown = 174;
haxor.input.KeyCode.VolumeUp = 175;
haxor.input.KeyCode.MediaNextTrack = 176;
haxor.input.KeyCode.MediaPreviousTrack = 177;
haxor.input.KeyCode.MediaStop = 178;
haxor.input.KeyCode.MediaPlayPause = 179;
haxor.input.KeyCode.LaunchMail = 180;
haxor.input.KeyCode.SelectMedia = 181;
haxor.input.KeyCode.LaunchApplication1 = 182;
haxor.input.KeyCode.LaunchApplication2 = 183;
haxor.input.KeyCode.Oem1 = 186;
haxor.input.KeyCode.OemSemicolon = 186;
haxor.input.KeyCode.Oemplus = 187;
haxor.input.KeyCode.Oemcomma = 188;
haxor.input.KeyCode.OemMinus = 189;
haxor.input.KeyCode.OemPeriod = 190;
haxor.input.KeyCode.OemQuestion = 191;
haxor.input.KeyCode.Oem2 = 191;
haxor.input.KeyCode.Oemtilde = 192;
haxor.input.KeyCode.Oem3 = 192;
haxor.input.KeyCode.Oem4 = 219;
haxor.input.KeyCode.OemOpenBrackets = 219;
haxor.input.KeyCode.OemPipe = 220;
haxor.input.KeyCode.Oem5 = 220;
haxor.input.KeyCode.Oem6 = 221;
haxor.input.KeyCode.OemCloseBrackets = 221;
haxor.input.KeyCode.Oem7 = 222;
haxor.input.KeyCode.OemQuotes = 222;
haxor.input.KeyCode.Oem8 = 223;
haxor.input.KeyCode.Oem102 = 226;
haxor.input.KeyCode.OemBackslash = 226;
haxor.input.KeyCode.ProcessKey = 229;
haxor.input.KeyCode.Packet = 231;
haxor.input.KeyCode.Attn = 246;
haxor.input.KeyCode.Crsel = 247;
haxor.input.KeyCode.Exsel = 248;
haxor.input.KeyCode.EraseEof = 249;
haxor.input.KeyCode.Play = 250;
haxor.input.KeyCode.Zoom = 251;
haxor.input.KeyCode.NoName = 252;
haxor.input.KeyCode.Pa1 = 253;
haxor.input.KeyCode.OemClear = 254;
haxor.input.KeyCode.KeyCodeMask = 65535;
haxor.input.KeyCode.ShiftModifier = 65536;
haxor.input.KeyCode.ControlModifier = 131072;
haxor.input.KeyCode.AltModifier = 262144;
haxor.math.Mathf.Epsilon = 1e-005;
haxor.math.Mathf.NaN = Math.NaN;
haxor.math.Mathf.Infinity = Math.POSITIVE_INFINITY;
haxor.math.Mathf.NegativeInfinity = Math.NEGATIVE_INFINITY;
haxor.math.Mathf.E = 2.7182818284590452353602874713527;
haxor.math.Mathf.PI = 3.1415926535897932384626433832795028841971693993751058;
haxor.math.Mathf.HalfPI = haxor.math.Mathf.PI * 0.5;
haxor.math.Mathf.PI2 = haxor.math.Mathf.PI * 2.0;
haxor.math.Mathf.PI4 = haxor.math.Mathf.PI * 4.0;
haxor.math.Mathf.InvPI = 0.31830988618379067153776752674503;
haxor.math.Mathf.Rad2Deg = 180.0 / haxor.math.Mathf.PI;
haxor.math.Mathf.Deg2Rad = haxor.math.Mathf.PI / 180.0;
haxor.math.Mathf.Px2Em = 0.063;
haxor.math.Mathf.Em2Px = 15.873015873015873;
haxor.math.Mathf.Byte2Float = 0.00392156863;
haxor.math.Mathf.Short2Float = 0.0000152587890625;
haxor.math.Mathf.Long2Float = 0.00000000023283064365386962890625;
haxor.math.Mathf.Float2Byte = 255.0;
haxor.math.Mathf.Float2Short = 65536.0;
haxor.math.Mathf.Float2Long = 4294967296.0;
haxor.math.Mathf.Sin = Math.sin;
haxor.math.Mathf.Cos = Math.cos;
haxor.math.Mathf.Asin = Math.asin;
haxor.math.Mathf.Acos = Math.acos;
haxor.math.Mathf.Tan = Math.tan;
haxor.math.Mathf.Atan = Math.atan;
haxor.math.Mathf.Atan2 = Math.atan2;
haxor.math.Mathf.Sqrt = Math.sqrt;
haxor.math.Mathf.Pow = Math.pow;
haxor.net.Web.m_autoload = true;
haxor.net.Web.root = "";
haxor.physics.Physics.iterations = 10;
haxor.texture.TextureWrap.ClampX = 1;
haxor.texture.TextureWrap.RepeatX = 2;
haxor.texture.TextureWrap.ClampY = 4;
haxor.texture.TextureWrap.RepeatY = 8;
haxor.texture.TextureWrap.ClampZ = 16;
haxor.texture.TextureWrap.RepeatZ = 32;
haxor.thread.ParticleKernel.DATA_SIZE = 128;
haxor.thread.TransformKernel.MAX_TRANSFORM = 2048;
haxor.thread.TransformKernel.TRANSFORM_FLOAT_LENGTH = 16;
haxor.thread.TransformKernel.MATRIX_FLOAT_LENGTH = 36;
haxor.thread.TransformKernel.FLAGS_OFFSET = 0;
haxor.thread.TransformKernel.PID_OFFSET = 0;
haxor.thread.TransformKernel.DIRTY_OFFSET = 1;
haxor.thread.TransformKernel.CONCAT_OFFSET = 2;
haxor.thread.TransformKernel.POSITION_OFFSET = 4;
haxor.thread.TransformKernel.ROTATION_OFFSET = 8;
haxor.thread.TransformKernel.SCALE_OFFSET = 12;
haxor.thread.TransformKernel.LM_OFFSET = 0;
haxor.thread.TransformKernel.WM_OFFSET = 12;
haxor.thread.TransformKernel.WMI_OFFSET = 24;
haxor.ui.LayoutFlag.PivotX = 1;
haxor.ui.LayoutFlag.PivotY = 2;
haxor.ui.LayoutFlag.PivotXY = 3;
haxor.ui.LayoutFlag.PositionX = 4;
haxor.ui.LayoutFlag.PositionY = 8;
haxor.ui.LayoutFlag.PositionXY = 12;
haxor.ui.LayoutFlag.SizeX = 16;
haxor.ui.LayoutFlag.SizeY = 32;
haxor.ui.LayoutFlag.SizeXY = 48;
haxor.ui.Stage.m_scrollWidth = -1;
haxor.ui.UISkin.m_nodes = [];
haxor.ui.UISkin.list = [];
haxor.Main.main();
})();
