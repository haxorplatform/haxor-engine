package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Xml extends haxe.lang.HxObject
{
	static 
	{
		{
			haxe.root.Xml.Element = ((_Xml.RealXmlType) (((java.lang.Object) (_Xml.RealXmlType.Element) )) );
			haxe.root.Xml.PCData = ((_Xml.RealXmlType) (((java.lang.Object) (_Xml.RealXmlType.PCData) )) );
			haxe.root.Xml.CData = ((_Xml.RealXmlType) (((java.lang.Object) (_Xml.RealXmlType.CData) )) );
			haxe.root.Xml.Comment = ((_Xml.RealXmlType) (((java.lang.Object) (_Xml.RealXmlType.Comment) )) );
			haxe.root.Xml.DocType = ((_Xml.RealXmlType) (((java.lang.Object) (_Xml.RealXmlType.DocType) )) );
			haxe.root.Xml.ProcessingInstruction = ((_Xml.RealXmlType) (((java.lang.Object) (_Xml.RealXmlType.ProcessingInstruction) )) );
			haxe.root.Xml.Document = ((_Xml.RealXmlType) (((java.lang.Object) (_Xml.RealXmlType.Document) )) );
		}
		
	}
	public    Xml(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Xml()
	{
		haxe.root.Xml.__hx_ctor__Xml(this);
	}
	
	
	public static   void __hx_ctor__Xml(haxe.root.Xml __temp_me27875)
	{
		{
		}
		
	}
	
	
	public static  _Xml.RealXmlType Element;
	
	public static  _Xml.RealXmlType PCData;
	
	public static  _Xml.RealXmlType CData;
	
	public static  _Xml.RealXmlType Comment;
	
	public static  _Xml.RealXmlType DocType;
	
	public static  _Xml.RealXmlType ProcessingInstruction;
	
	public static  _Xml.RealXmlType Document;
	
	public static   haxe.root.Xml parse(java.lang.String str)
	{
		return haxe.xml.Parser.parse(str);
	}
	
	
	public static   haxe.root.Xml createElement(java.lang.String name)
	{
		haxe.root.Xml r = new haxe.root.Xml();
		r.nodeType = haxe.root.Xml.Element;
		r._children = new haxe.root.Array<haxe.root.Xml>();
		r._attributes = new haxe.ds.StringMap<java.lang.String>();
		r.set_nodeName(name);
		return r;
	}
	
	
	public static   haxe.root.Xml createPCData(java.lang.String data)
	{
		haxe.root.Xml r = new haxe.root.Xml();
		r.nodeType = haxe.root.Xml.PCData;
		r.set_nodeValue(data);
		return r;
	}
	
	
	public static   haxe.root.Xml createCData(java.lang.String data)
	{
		haxe.root.Xml r = new haxe.root.Xml();
		r.nodeType = haxe.root.Xml.CData;
		r.set_nodeValue(data);
		return r;
	}
	
	
	public static   haxe.root.Xml createComment(java.lang.String data)
	{
		haxe.root.Xml r = new haxe.root.Xml();
		r.nodeType = haxe.root.Xml.Comment;
		r.set_nodeValue(data);
		return r;
	}
	
	
	public static   haxe.root.Xml createDocType(java.lang.String data)
	{
		haxe.root.Xml r = new haxe.root.Xml();
		r.nodeType = haxe.root.Xml.DocType;
		r.set_nodeValue(data);
		return r;
	}
	
	
	public static   haxe.root.Xml createProcessingInstruction(java.lang.String data)
	{
		haxe.root.Xml r = new haxe.root.Xml();
		r.nodeType = haxe.root.Xml.ProcessingInstruction;
		r.set_nodeValue(data);
		return r;
	}
	
	
	public static   haxe.root.Xml createDocument()
	{
		haxe.root.Xml r = new haxe.root.Xml();
		r.nodeType = haxe.root.Xml.Document;
		r._children = new haxe.root.Array<haxe.root.Xml>();
		return r;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.Xml(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.Xml();
	}
	
	
	public  _Xml.RealXmlType nodeType;
	
	public  java.lang.String _nodeName;
	
	public  java.lang.String _nodeValue;
	
	public  haxe.ds.StringMap<java.lang.String> _attributes;
	
	public  haxe.root.Array<haxe.root.Xml> _children;
	
	public  haxe.root.Xml _parent;
	
	public   java.lang.String get_nodeName()
	{
		if (( this.nodeType != haxe.root.Xml.Element )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodeType");
		}
		
		return this._nodeName;
	}
	
	
	public   java.lang.String set_nodeName(java.lang.String n)
	{
		if (( this.nodeType != haxe.root.Xml.Element )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodeType");
		}
		
		return this._nodeName = n;
	}
	
	
	public   java.lang.String get_nodeValue()
	{
		if (( ( this.nodeType == haxe.root.Xml.Element ) || ( this.nodeType == haxe.root.Xml.Document ) )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodeType");
		}
		
		return this._nodeValue;
	}
	
	
	public   java.lang.String set_nodeValue(java.lang.String v)
	{
		if (( ( this.nodeType == haxe.root.Xml.Element ) || ( this.nodeType == haxe.root.Xml.Document ) )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodeType");
		}
		
		return this._nodeValue = v;
	}
	
	
	public   java.lang.String get(java.lang.String att)
	{
		if (( this.nodeType != haxe.root.Xml.Element )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodeType");
		}
		
		return this._attributes.get(att);
	}
	
	
	public   void set(java.lang.String att, java.lang.String value)
	{
		if (( this.nodeType != haxe.root.Xml.Element )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodeType");
		}
		
		this._attributes.set(att, value);
	}
	
	
	public   boolean exists(java.lang.String att)
	{
		if (( this.nodeType != haxe.root.Xml.Element )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodeType");
		}
		
		return this._attributes.exists(att);
	}
	
	
	public   java.lang.Object elementsNamed(java.lang.String name)
	{
		haxe.root.Array<java.lang.String> name1 = new haxe.root.Array<java.lang.String>(new java.lang.String[]{name});
		if (( this._children == null )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodetype");
		}
		
		haxe.root.Array<haxe.root.Array> x = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{((haxe.root.Array) (this._children) )});
		haxe.root.Array<java.lang.Object> cur = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0});
		{
			haxe.lang.Function __temp_odecl27992 = new haxe.root.Xml_elementsNamed_226__Fun(((haxe.root.Array<java.lang.String>) (name1) ), ((haxe.root.Array<java.lang.Object>) (cur) ), ((haxe.root.Array<haxe.root.Array>) (x) ));
			haxe.lang.Function __temp_odecl27993 = new haxe.root.Xml_elementsNamed_238__Fun(((haxe.root.Array<java.lang.String>) (name1) ), ((haxe.root.Array<java.lang.Object>) (cur) ), ((haxe.root.Array<haxe.root.Array>) (x) ));
			return new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"hasNext", "next", "x"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl27992, __temp_odecl27993, this._children}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"cur"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (0) )) )}));
		}
		
	}
	
	
	public   haxe.root.Xml firstChild()
	{
		if (( this._children == null )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodetype");
		}
		
		return this._children.__get(0);
	}
	
	
	public   haxe.root.Xml firstElement()
	{
		if (( this._children == null )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodetype");
		}
		
		int cur = 0;
		int l = this._children.length;
		while (( cur < l ))
		{
			haxe.root.Xml n = this._children.__get(cur);
			if (( n.nodeType == haxe.root.Xml.Element )) 
			{
				return n;
			}
			
			cur++;
		}
		
		return null;
	}
	
	
	public   void addChild(haxe.root.Xml x)
	{
		if (( this._children == null )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodetype");
		}
		
		if (( x._parent != null )) 
		{
			x._parent._children.remove(x);
		}
		
		x._parent = this;
		this._children.push(x);
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef27994 = true;
			switch (field.hashCode())
			{
				case 1713046985:
				{
					if (field.equals("_parent")) 
					{
						__temp_executeDef27994 = false;
						this._parent = ((haxe.root.Xml) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1123082332:
				{
					if (field.equals("nodeType")) 
					{
						__temp_executeDef27994 = false;
						this.nodeType = ((_Xml.RealXmlType) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1750044510:
				{
					if (field.equals("_children")) 
					{
						__temp_executeDef27994 = false;
						this._children = ((haxe.root.Array<haxe.root.Xml>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1213398284:
				{
					if (field.equals("_nodeName")) 
					{
						__temp_executeDef27994 = false;
						this._nodeName = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 1493958390:
				{
					if (field.equals("_attributes")) 
					{
						__temp_executeDef27994 = false;
						this._attributes = ((haxe.ds.StringMap<java.lang.String>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1031971056:
				{
					if (field.equals("_nodeValue")) 
					{
						__temp_executeDef27994 = false;
						this._nodeValue = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef27994) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef27995 = true;
			switch (field.hashCode())
			{
				case -1262040837:
				{
					if (field.equals("addChild")) 
					{
						__temp_executeDef27995 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("addChild"))) );
					}
					
					break;
				}
				
				
				case 1123082332:
				{
					if (field.equals("nodeType")) 
					{
						__temp_executeDef27995 = false;
						return this.nodeType;
					}
					
					break;
				}
				
				
				case -1741980116:
				{
					if (field.equals("firstElement")) 
					{
						__temp_executeDef27995 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("firstElement"))) );
					}
					
					break;
				}
				
				
				case 1213398284:
				{
					if (field.equals("_nodeName")) 
					{
						__temp_executeDef27995 = false;
						return this._nodeName;
					}
					
					break;
				}
				
				
				case -187015092:
				{
					if (field.equals("firstChild")) 
					{
						__temp_executeDef27995 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("firstChild"))) );
					}
					
					break;
				}
				
				
				case -1031971056:
				{
					if (field.equals("_nodeValue")) 
					{
						__temp_executeDef27995 = false;
						return this._nodeValue;
					}
					
					break;
				}
				
				
				case -51566462:
				{
					if (field.equals("elementsNamed")) 
					{
						__temp_executeDef27995 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("elementsNamed"))) );
					}
					
					break;
				}
				
				
				case 1493958390:
				{
					if (field.equals("_attributes")) 
					{
						__temp_executeDef27995 = false;
						return this._attributes;
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef27995 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("exists"))) );
					}
					
					break;
				}
				
				
				case 1750044510:
				{
					if (field.equals("_children")) 
					{
						__temp_executeDef27995 = false;
						return this._children;
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef27995 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set"))) );
					}
					
					break;
				}
				
				
				case 1713046985:
				{
					if (field.equals("_parent")) 
					{
						__temp_executeDef27995 = false;
						return this._parent;
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef27995 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get"))) );
					}
					
					break;
				}
				
				
				case -800174474:
				{
					if (field.equals("get_nodeName")) 
					{
						__temp_executeDef27995 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_nodeName"))) );
					}
					
					break;
				}
				
				
				case 1745914098:
				{
					if (field.equals("set_nodeValue")) 
					{
						__temp_executeDef27995 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_nodeValue"))) );
					}
					
					break;
				}
				
				
				case 748818154:
				{
					if (field.equals("set_nodeName")) 
					{
						__temp_executeDef27995 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_nodeName"))) );
					}
					
					break;
				}
				
				
				case 971782886:
				{
					if (field.equals("get_nodeValue")) 
					{
						__temp_executeDef27995 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_nodeValue"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef27995) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			boolean __temp_executeDef27996 = true;
			switch (field.hashCode())
			{
				case -1262040837:
				{
					if (field.equals("addChild")) 
					{
						__temp_executeDef27996 = false;
						this.addChild(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -800174474:
				{
					if (field.equals("get_nodeName")) 
					{
						__temp_executeDef27996 = false;
						return this.get_nodeName();
					}
					
					break;
				}
				
				
				case -1741980116:
				{
					if (field.equals("firstElement")) 
					{
						__temp_executeDef27996 = false;
						return this.firstElement();
					}
					
					break;
				}
				
				
				case 748818154:
				{
					if (field.equals("set_nodeName")) 
					{
						__temp_executeDef27996 = false;
						return this.set_nodeName(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -187015092:
				{
					if (field.equals("firstChild")) 
					{
						__temp_executeDef27996 = false;
						return this.firstChild();
					}
					
					break;
				}
				
				
				case 971782886:
				{
					if (field.equals("get_nodeValue")) 
					{
						__temp_executeDef27996 = false;
						return this.get_nodeValue();
					}
					
					break;
				}
				
				
				case -51566462:
				{
					if (field.equals("elementsNamed")) 
					{
						__temp_executeDef27996 = false;
						return this.elementsNamed(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1745914098:
				{
					if (field.equals("set_nodeValue")) 
					{
						__temp_executeDef27996 = false;
						return this.set_nodeValue(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef27996 = false;
						return this.exists(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef27996 = false;
						return this.get(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef27996 = false;
						this.set(haxe.lang.Runtime.toString(dynargs.__get(0)), haxe.lang.Runtime.toString(dynargs.__get(1)));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef27996) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("_parent");
		baseArr.push("_children");
		baseArr.push("_attributes");
		baseArr.push("_nodeValue");
		baseArr.push("_nodeName");
		baseArr.push("nodeType");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


