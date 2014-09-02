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
	
	
	public static   void __hx_ctor__Xml(haxe.root.Xml __temp_me160383)
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
	
	
	
	
	
	public  haxe.root.Xml parent;
	
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
	
	
	public   haxe.root.Xml get_parent()
	{
		return this._parent;
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
	
	
	public   void remove(java.lang.String att)
	{
		if (( this.nodeType != haxe.root.Xml.Element )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodeType");
		}
		
		this._attributes.remove(att);
	}
	
	
	public   boolean exists(java.lang.String att)
	{
		if (( this.nodeType != haxe.root.Xml.Element )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodeType");
		}
		
		return this._attributes.exists(att);
	}
	
	
	public   java.lang.Object attributes()
	{
		if (( this.nodeType != haxe.root.Xml.Element )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodeType");
		}
		
		return this._attributes.keys();
	}
	
	
	public   java.lang.Object iterator()
	{
		if (( this._children == null )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodetype");
		}
		
		haxe.root.Array<java.lang.Object> cur = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0});
		haxe.root.Array<haxe.root.Array> x = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{((haxe.root.Array) (this._children) )});
		{
			haxe.lang.Function __temp_odecl160801 = new haxe.root.Xml_iterator_178__Fun(((haxe.root.Array<haxe.root.Array>) (x) ), ((haxe.root.Array<java.lang.Object>) (cur) ));
			haxe.lang.Function __temp_odecl160802 = new haxe.root.Xml_iterator_181__Fun(((haxe.root.Array<haxe.root.Array>) (x) ), ((haxe.root.Array<java.lang.Object>) (cur) ));
			return new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"hasNext", "next"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl160801, __temp_odecl160802}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		}
		
	}
	
	
	public   java.lang.Object elements()
	{
		if (( this._children == null )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodetype");
		}
		
		haxe.root.Array<java.lang.Object> cur = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0});
		haxe.root.Array<haxe.root.Array> x = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{((haxe.root.Array) (this._children) )});
		{
			haxe.lang.Function __temp_odecl160803 = new haxe.root.Xml_elements_192__Fun(((haxe.root.Array<java.lang.Object>) (cur) ), ((haxe.root.Array<haxe.root.Array>) (x) ));
			haxe.lang.Function __temp_odecl160804 = new haxe.root.Xml_elements_203__Fun(((haxe.root.Array<java.lang.Object>) (cur) ), ((haxe.root.Array<haxe.root.Array>) (x) ));
			return new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"hasNext", "next"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl160803, __temp_odecl160804}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		}
		
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
			haxe.lang.Function __temp_odecl160805 = new haxe.root.Xml_elementsNamed_226__Fun(((haxe.root.Array<haxe.root.Array>) (x) ), ((haxe.root.Array<java.lang.String>) (name1) ), ((haxe.root.Array<java.lang.Object>) (cur) ));
			haxe.lang.Function __temp_odecl160806 = new haxe.root.Xml_elementsNamed_238__Fun(((haxe.root.Array<haxe.root.Array>) (x) ), ((haxe.root.Array<java.lang.String>) (name1) ), ((haxe.root.Array<java.lang.Object>) (cur) ));
			return new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"hasNext", "next", "x"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl160805, __temp_odecl160806, this._children}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"cur"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (0) )) )}));
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
	
	
	public   boolean removeChild(haxe.root.Xml x)
	{
		if (( this._children == null )) 
		{
			throw haxe.lang.HaxeException.wrap("bad nodetype");
		}
		
		boolean b = this._children.remove(x);
		if (b) 
		{
			x._parent = null;
		}
		
		return b;
	}
	
	
	public   void insertChild(haxe.root.Xml x, int pos)
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
		this._children.insert(pos, x);
	}
	
	
	@Override public   java.lang.String toString()
	{
		if (( this.nodeType == haxe.root.Xml.PCData )) 
		{
			return haxe.root.StringTools.htmlEscape(this._nodeValue, null);
		}
		
		if (( this.nodeType == haxe.root.Xml.CData )) 
		{
			return ( ( "<![CDATA[" + this._nodeValue ) + "]]>" );
		}
		
		if (( this.nodeType == haxe.root.Xml.Comment )) 
		{
			return ( ( "<!--" + this._nodeValue ) + "-->" );
		}
		
		if (( this.nodeType == haxe.root.Xml.DocType )) 
		{
			return ( ( "<!DOCTYPE " + this._nodeValue ) + ">" );
		}
		
		if (( this.nodeType == haxe.root.Xml.ProcessingInstruction )) 
		{
			return ( ( "<?" + this._nodeValue ) + "?>" );
		}
		
		haxe.root.StringBuf s = new haxe.root.StringBuf();
		if (( this.nodeType == haxe.root.Xml.Element )) 
		{
			s.add("<");
			s.add(this._nodeName);
			{
				java.lang.Object __temp_iterator160722 = this._attributes.keys();
				while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(__temp_iterator160722, "hasNext", null)))
				{
					java.lang.String k = haxe.lang.Runtime.toString(haxe.lang.Runtime.callField(__temp_iterator160722, "next", null));
					s.add(" ");
					s.add(k);
					s.add("=\"");
					s.add(this._attributes.get(k));
					s.add("\"");
				}
				
			}
			
			if (( this._children.length == 0 )) 
			{
				s.add("/>");
				return s.toString();
			}
			
			s.add(">");
		}
		
		{
			java.lang.Object __temp_iterator160723 = this.iterator();
			while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(__temp_iterator160723, "hasNext", null)))
			{
				haxe.root.Xml x = ((haxe.root.Xml) (haxe.lang.Runtime.callField(__temp_iterator160723, "next", null)) );
				s.add(x.toString());
			}
			
		}
		
		if (( this.nodeType == haxe.root.Xml.Element )) 
		{
			s.add("</");
			s.add(this._nodeName);
			s.add(">");
		}
		
		return s.toString();
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef160807 = true;
			switch (field.hashCode())
			{
				case 1713046985:
				{
					if (field.equals("_parent")) 
					{
						__temp_executeDef160807 = false;
						this._parent = ((haxe.root.Xml) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1123082332:
				{
					if (field.equals("nodeType")) 
					{
						__temp_executeDef160807 = false;
						this.nodeType = ((_Xml.RealXmlType) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1750044510:
				{
					if (field.equals("_children")) 
					{
						__temp_executeDef160807 = false;
						this._children = ((haxe.root.Array<haxe.root.Xml>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1122880429:
				{
					if (field.equals("nodeName")) 
					{
						__temp_executeDef160807 = false;
						this.set_nodeName(haxe.lang.Runtime.toString(value));
						return value;
					}
					
					break;
				}
				
				
				case 1493958390:
				{
					if (field.equals("_attributes")) 
					{
						__temp_executeDef160807 = false;
						this._attributes = ((haxe.ds.StringMap<java.lang.String>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 456942735:
				{
					if (field.equals("nodeValue")) 
					{
						__temp_executeDef160807 = false;
						this.set_nodeValue(haxe.lang.Runtime.toString(value));
						return value;
					}
					
					break;
				}
				
				
				case -1031971056:
				{
					if (field.equals("_nodeValue")) 
					{
						__temp_executeDef160807 = false;
						this._nodeValue = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -995424086:
				{
					if (field.equals("parent")) 
					{
						__temp_executeDef160807 = false;
						this.parent = ((haxe.root.Xml) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1213398284:
				{
					if (field.equals("_nodeName")) 
					{
						__temp_executeDef160807 = false;
						this._nodeName = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160807) 
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
			boolean __temp_executeDef160808 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("toString"))) );
					}
					
					break;
				}
				
				
				case 1123082332:
				{
					if (field.equals("nodeType")) 
					{
						__temp_executeDef160808 = false;
						return this.nodeType;
					}
					
					break;
				}
				
				
				case -129364509:
				{
					if (field.equals("insertChild")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("insertChild"))) );
					}
					
					break;
				}
				
				
				case 1122880429:
				{
					if (field.equals("nodeName")) 
					{
						__temp_executeDef160808 = false;
						return this.get_nodeName();
					}
					
					break;
				}
				
				
				case -319766792:
				{
					if (field.equals("removeChild")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("removeChild"))) );
					}
					
					break;
				}
				
				
				case 456942735:
				{
					if (field.equals("nodeValue")) 
					{
						__temp_executeDef160808 = false;
						return this.get_nodeValue();
					}
					
					break;
				}
				
				
				case -1262040837:
				{
					if (field.equals("addChild")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("addChild"))) );
					}
					
					break;
				}
				
				
				case -995424086:
				{
					if (field.equals("parent")) 
					{
						__temp_executeDef160808 = false;
						if (handleProperties) 
						{
							return this.get_parent();
						}
						 else 
						{
							return this.parent;
						}
						
					}
					
					break;
				}
				
				
				case -1741980116:
				{
					if (field.equals("firstElement")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("firstElement"))) );
					}
					
					break;
				}
				
				
				case 1213398284:
				{
					if (field.equals("_nodeName")) 
					{
						__temp_executeDef160808 = false;
						return this._nodeName;
					}
					
					break;
				}
				
				
				case -187015092:
				{
					if (field.equals("firstChild")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("firstChild"))) );
					}
					
					break;
				}
				
				
				case -1031971056:
				{
					if (field.equals("_nodeValue")) 
					{
						__temp_executeDef160808 = false;
						return this._nodeValue;
					}
					
					break;
				}
				
				
				case -51566462:
				{
					if (field.equals("elementsNamed")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("elementsNamed"))) );
					}
					
					break;
				}
				
				
				case 1493958390:
				{
					if (field.equals("_attributes")) 
					{
						__temp_executeDef160808 = false;
						return this._attributes;
					}
					
					break;
				}
				
				
				case -8339209:
				{
					if (field.equals("elements")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("elements"))) );
					}
					
					break;
				}
				
				
				case 1750044510:
				{
					if (field.equals("_children")) 
					{
						__temp_executeDef160808 = false;
						return this._children;
					}
					
					break;
				}
				
				
				case 1182533742:
				{
					if (field.equals("iterator")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("iterator"))) );
					}
					
					break;
				}
				
				
				case 1713046985:
				{
					if (field.equals("_parent")) 
					{
						__temp_executeDef160808 = false;
						return this._parent;
					}
					
					break;
				}
				
				
				case 405645655:
				{
					if (field.equals("attributes")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("attributes"))) );
					}
					
					break;
				}
				
				
				case -800174474:
				{
					if (field.equals("get_nodeName")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_nodeName"))) );
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("exists"))) );
					}
					
					break;
				}
				
				
				case 748818154:
				{
					if (field.equals("set_nodeName")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_nodeName"))) );
					}
					
					break;
				}
				
				
				case -934610812:
				{
					if (field.equals("remove")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("remove"))) );
					}
					
					break;
				}
				
				
				case 971782886:
				{
					if (field.equals("get_nodeValue")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_nodeValue"))) );
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set"))) );
					}
					
					break;
				}
				
				
				case 1745914098:
				{
					if (field.equals("set_nodeValue")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_nodeValue"))) );
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get"))) );
					}
					
					break;
				}
				
				
				case 1085254067:
				{
					if (field.equals("get_parent")) 
					{
						__temp_executeDef160808 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_parent"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160808) 
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
			boolean __temp_executeDef160809 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef160809 = false;
						return this.toString();
					}
					
					break;
				}
				
				
				case -800174474:
				{
					if (field.equals("get_nodeName")) 
					{
						__temp_executeDef160809 = false;
						return this.get_nodeName();
					}
					
					break;
				}
				
				
				case -129364509:
				{
					if (field.equals("insertChild")) 
					{
						__temp_executeDef160809 = false;
						this.insertChild(((haxe.root.Xml) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 748818154:
				{
					if (field.equals("set_nodeName")) 
					{
						__temp_executeDef160809 = false;
						return this.set_nodeName(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -319766792:
				{
					if (field.equals("removeChild")) 
					{
						__temp_executeDef160809 = false;
						return this.removeChild(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 971782886:
				{
					if (field.equals("get_nodeValue")) 
					{
						__temp_executeDef160809 = false;
						return this.get_nodeValue();
					}
					
					break;
				}
				
				
				case -1262040837:
				{
					if (field.equals("addChild")) 
					{
						__temp_executeDef160809 = false;
						this.addChild(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1745914098:
				{
					if (field.equals("set_nodeValue")) 
					{
						__temp_executeDef160809 = false;
						return this.set_nodeValue(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1741980116:
				{
					if (field.equals("firstElement")) 
					{
						__temp_executeDef160809 = false;
						return this.firstElement();
					}
					
					break;
				}
				
				
				case 1085254067:
				{
					if (field.equals("get_parent")) 
					{
						__temp_executeDef160809 = false;
						return this.get_parent();
					}
					
					break;
				}
				
				
				case -187015092:
				{
					if (field.equals("firstChild")) 
					{
						__temp_executeDef160809 = false;
						return this.firstChild();
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef160809 = false;
						return this.get(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -51566462:
				{
					if (field.equals("elementsNamed")) 
					{
						__temp_executeDef160809 = false;
						return this.elementsNamed(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef160809 = false;
						this.set(haxe.lang.Runtime.toString(dynargs.__get(0)), haxe.lang.Runtime.toString(dynargs.__get(1)));
					}
					
					break;
				}
				
				
				case -8339209:
				{
					if (field.equals("elements")) 
					{
						__temp_executeDef160809 = false;
						return this.elements();
					}
					
					break;
				}
				
				
				case -934610812:
				{
					if (field.equals("remove")) 
					{
						__temp_executeDef160809 = false;
						this.remove(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1182533742:
				{
					if (field.equals("iterator")) 
					{
						__temp_executeDef160809 = false;
						return this.iterator();
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef160809 = false;
						return this.exists(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 405645655:
				{
					if (field.equals("attributes")) 
					{
						__temp_executeDef160809 = false;
						return this.attributes();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160809) 
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
		baseArr.push("parent");
		baseArr.push("nodeValue");
		baseArr.push("nodeName");
		baseArr.push("nodeType");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


