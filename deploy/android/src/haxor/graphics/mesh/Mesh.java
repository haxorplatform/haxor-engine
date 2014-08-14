package haxor.graphics.mesh;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Mesh extends haxor.core.Resource
{
	public    Mesh(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Mesh()
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.graphics.mesh.Mesh.__hx_ctor_haxor_graphics_mesh_Mesh(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_mesh_Mesh(haxor.graphics.mesh.Mesh __temp_me21760)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me21760, null);
		__temp_me21760._cid_ = haxor.context.EngineContext.mesh.mid++;
		__temp_me21760.m_attribs = new haxe.root.Array<haxor.graphics.mesh.MeshAttrib>(new haxor.graphics.mesh.MeshAttrib[]{});
		__temp_me21760.m_indexed = false;
		__temp_me21760.m_vcount = 0;
		__temp_me21760.m_mode = 35048;
		__temp_me21760.primitive = 4;
		__temp_me21760.m_topology_attrib = new haxor.graphics.mesh.MeshAttrib();
		__temp_me21760.m_topology_attrib.m_name = "$topology";
		__temp_me21760.m_topology_attrib.offset = 1;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.mesh.Mesh(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.mesh.Mesh();
	}
	
	
	
	
	public   haxor.io.UInt16Array get_topology()
	{
		if (( this.m_topology_attrib.data == null )) 
		{
			return new haxor.io.UInt16Array(((int) (0) ));
		}
		
		return ((haxor.io.UInt16Array) (this.m_topology_attrib.data) );
	}
	
	
	public   haxor.io.UInt16Array set_topology(haxor.io.UInt16Array v)
	{
		if (( v == null )) 
		{
			this.m_topology_attrib.data = null;
			this.m_indexed = false;
			haxor.context.EngineContext.mesh.RemoveAttrib(this.m_topology_attrib);
		}
		 else 
		{
			this.m_topology_attrib.data = v;
			this.m_indexed = true;
			haxor.context.EngineContext.mesh.UpdateAttrib(this.m_topology_attrib, this.m_mode, true);
		}
		
		return v;
	}
	
	
	public  haxor.graphics.mesh.MeshAttrib m_topology_attrib;
	
	
	
	public final   boolean get_indexed()
	{
		return this.m_indexed;
	}
	
	
	public  boolean m_indexed;
	
	
	
	public final   int get_mode()
	{
		return this.m_mode;
	}
	
	
	public   int set_mode(int v)
	{
		if (( this.m_mode == v )) 
		{
			return v;
		}
		
		this.m_mode = v;
		if (this.m_indexed) 
		{
			haxor.context.EngineContext.mesh.UpdateAttrib(this.m_topology_attrib, this.m_mode, true);
		}
		
		{
			int _g1 = 0;
			int _g = this.m_attribs.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.context.EngineContext.mesh.UpdateAttrib(this.m_attribs.__get(i), this.m_mode, false);
			}
			
		}
		
		return v;
	}
	
	
	public  int m_mode;
	
	public  int primitive;
	
	public  haxe.root.Array<java.lang.String> attribs;
	
	public   haxe.root.Array<java.lang.String> get_attribs()
	{
		haxe.root.Array<java.lang.String> l = new haxe.root.Array<java.lang.String>(new java.lang.String[]{});
		{
			int _g1 = 0;
			int _g = this.m_attribs.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				l.push(this.m_attribs.__get(i).m_name);
			}
			
		}
		
		return l;
	}
	
	
	public  haxe.root.Array<haxor.graphics.mesh.MeshAttrib> m_attribs;
	
	
	
	public final   int get_vcount()
	{
		return this.m_vcount;
	}
	
	
	public  int m_vcount;
	
	public   void Clear(java.lang.Object p_from_gpu)
	{
		boolean __temp_p_from_gpu21758 = ( (( p_from_gpu == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_from_gpu)) );
		{
			int _g1 = 0;
			int _g = this.m_attribs.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				this.m_attribs.__get(i).data = null;
				this.m_attribs.__get(i).m_name = "";
				if (__temp_p_from_gpu21758) 
				{
					haxor.context.EngineContext.mesh.RemoveAttrib(this.m_attribs.__get(i));
				}
				
			}
			
		}
		
		this.m_vcount = 0;
		if (__temp_p_from_gpu21758) 
		{
			this.set_topology(null);
		}
		 else 
		{
			this.m_topology_attrib.data = null;
		}
		
	}
	
	
	public   boolean Exists(java.lang.String p_name)
	{
		return ( this.GetAttribute(p_name) != null );
	}
	
	
	public  <T> T Get(java.lang.String p_name)
	{
		haxor.graphics.mesh.MeshAttrib a = this.GetAttribute(p_name);
		if (( a == null )) 
		{
			return null;
		}
		 else 
		{
			return ((T) (((java.lang.Object) (a.data) )) );
		}
		
	}
	
	
	public   haxor.graphics.mesh.MeshAttrib GetAttribute(java.lang.String p_name)
	{
		{
			int _g1 = 0;
			int _g = this.m_attribs.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(this.m_attribs.__get(i).m_name, p_name)) 
				{
					return this.m_attribs.__get(i);
				}
				
			}
			
		}
		
		return null;
	}
	
	
	public   void Remove(java.lang.String p_name)
	{
		haxor.graphics.mesh.MeshAttrib a = this.GetAttribute(p_name);
		if (( a == null )) 
		{
			return ;
		}
		
		this.m_attribs.remove(a);
		haxor.context.EngineContext.mesh.RemoveAttrib(a);
	}
	
	
	public   void Set(java.lang.String p_name, haxor.io.Buffer p_data, java.lang.Object p_offset)
	{
		int __temp_p_offset21759 = ( (( p_offset == null )) ? (((int) (3) )) : (((int) (haxe.lang.Runtime.toInt(p_offset)) )) );
		if (( p_data == null )) 
		{
			haxor.core.Console.Log(( ( "Mesh> [" + this.get_name() ) + "] tried to set null array." ), 1);
			return ;
		}
		
		if (( p_data.m_length <= 0 )) 
		{
			haxor.core.Console.Log(( ( "Mesh> [" + this.get_name() ) + "] tried to set empty array." ), 1);
			return ;
		}
		
		haxor.graphics.mesh.MeshAttrib a = this.GetAttribute(p_name);
		if (( a == null )) 
		{
			a = new haxor.graphics.mesh.MeshAttrib();
			a.m_name = p_name;
			this.m_attribs.push(a);
		}
		
		a.offset = __temp_p_offset21759;
		a.data = p_data;
		this.m_vcount = this.m_attribs.__get(0).get_count();
		{
			int _g1 = 1;
			int _g = this.m_attribs.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				int c = this.m_attribs.__get(i).get_count();
				if (( this.m_vcount < c )) 
				{
					this.m_vcount = this.m_vcount;
				}
				 else 
				{
					this.m_vcount = c;
				}
				
			}
			
		}
		
		haxor.context.EngineContext.mesh.UpdateAttrib(a, this.m_mode, false);
	}
	
	
	@Override public   void OnDestroy()
	{
		this.Clear(null);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef21921 = true;
			switch (field.hashCode())
			{
				case -1420606869:
				{
					if (field.equals("m_vcount")) 
					{
						__temp_executeDef21921 = false;
						this.m_vcount = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3357091:
				{
					if (field.equals("mode")) 
					{
						__temp_executeDef21921 = false;
						this.set_mode(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1834808089:
				{
					if (field.equals("primitive")) 
					{
						__temp_executeDef21921 = false;
						this.primitive = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1083298251:
				{
					if (field.equals("m_mode")) 
					{
						__temp_executeDef21921 = false;
						this.m_mode = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21921) 
			{
				return super.__hx_setField_f(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef21922 = true;
			switch (field.hashCode())
			{
				case -1420606869:
				{
					if (field.equals("m_vcount")) 
					{
						__temp_executeDef21922 = false;
						this.m_vcount = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -951467409:
				{
					if (field.equals("topology")) 
					{
						__temp_executeDef21922 = false;
						this.set_topology(((haxor.io.UInt16Array) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -2055629545:
				{
					if (field.equals("m_attribs")) 
					{
						__temp_executeDef21922 = false;
						this.m_attribs = ((haxe.root.Array<haxor.graphics.mesh.MeshAttrib>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 775846600:
				{
					if (field.equals("m_topology_attrib")) 
					{
						__temp_executeDef21922 = false;
						this.m_topology_attrib = ((haxor.graphics.mesh.MeshAttrib) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -674845975:
				{
					if (field.equals("attribs")) 
					{
						__temp_executeDef21922 = false;
						this.attribs = ((haxe.root.Array<java.lang.String>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 562508575:
				{
					if (field.equals("m_indexed")) 
					{
						__temp_executeDef21922 = false;
						this.m_indexed = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1834808089:
				{
					if (field.equals("primitive")) 
					{
						__temp_executeDef21922 = false;
						this.primitive = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3357091:
				{
					if (field.equals("mode")) 
					{
						__temp_executeDef21922 = false;
						this.set_mode(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -1083298251:
				{
					if (field.equals("m_mode")) 
					{
						__temp_executeDef21922 = false;
						this.m_mode = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21922) 
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
			boolean __temp_executeDef21923 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case -951467409:
				{
					if (field.equals("topology")) 
					{
						__temp_executeDef21923 = false;
						return this.get_topology();
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 1420444984:
				{
					if (field.equals("get_topology")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_topology"))) );
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Remove"))) );
					}
					
					break;
				}
				
				
				case -1325529684:
				{
					if (field.equals("set_topology")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_topology"))) );
					}
					
					break;
				}
				
				
				case 167800838:
				{
					if (field.equals("GetAttribute")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetAttribute"))) );
					}
					
					break;
				}
				
				
				case 775846600:
				{
					if (field.equals("m_topology_attrib")) 
					{
						__temp_executeDef21923 = false;
						return this.m_topology_attrib;
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Get"))) );
					}
					
					break;
				}
				
				
				case 1943292145:
				{
					if (field.equals("indexed")) 
					{
						__temp_executeDef21923 = false;
						return this.get_indexed();
					}
					
					break;
				}
				
				
				case 2089476220:
				{
					if (field.equals("Exists")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Exists"))) );
					}
					
					break;
				}
				
				
				case 2019805448:
				{
					if (field.equals("get_indexed")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_indexed"))) );
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case 562508575:
				{
					if (field.equals("m_indexed")) 
					{
						__temp_executeDef21923 = false;
						return this.m_indexed;
					}
					
					break;
				}
				
				
				case -1420606869:
				{
					if (field.equals("m_vcount")) 
					{
						__temp_executeDef21923 = false;
						return this.m_vcount;
					}
					
					break;
				}
				
				
				case 3357091:
				{
					if (field.equals("mode")) 
					{
						__temp_executeDef21923 = false;
						return this.get_mode();
					}
					
					break;
				}
				
				
				case 1258802018:
				{
					if (field.equals("get_vcount")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_vcount"))) );
					}
					
					break;
				}
				
				
				case 1976469740:
				{
					if (field.equals("get_mode")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_mode"))) );
					}
					
					break;
				}
				
				
				case -821876135:
				{
					if (field.equals("vcount")) 
					{
						__temp_executeDef21923 = false;
						return this.get_vcount();
					}
					
					break;
				}
				
				
				case 1415357280:
				{
					if (field.equals("set_mode")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_mode"))) );
					}
					
					break;
				}
				
				
				case -2055629545:
				{
					if (field.equals("m_attribs")) 
					{
						__temp_executeDef21923 = false;
						return this.m_attribs;
					}
					
					break;
				}
				
				
				case -1083298251:
				{
					if (field.equals("m_mode")) 
					{
						__temp_executeDef21923 = false;
						return this.m_mode;
					}
					
					break;
				}
				
				
				case -598332672:
				{
					if (field.equals("get_attribs")) 
					{
						__temp_executeDef21923 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_attribs"))) );
					}
					
					break;
				}
				
				
				case -1834808089:
				{
					if (field.equals("primitive")) 
					{
						__temp_executeDef21923 = false;
						return this.primitive;
					}
					
					break;
				}
				
				
				case -674845975:
				{
					if (field.equals("attribs")) 
					{
						__temp_executeDef21923 = false;
						if (handleProperties) 
						{
							return this.get_attribs();
						}
						 else 
						{
							return this.attribs;
						}
						
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21923) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef21924 = true;
			switch (field.hashCode())
			{
				case -1420606869:
				{
					if (field.equals("m_vcount")) 
					{
						__temp_executeDef21924 = false;
						return ((double) (this.m_vcount) );
					}
					
					break;
				}
				
				
				case 3357091:
				{
					if (field.equals("mode")) 
					{
						__temp_executeDef21924 = false;
						return ((double) (this.get_mode()) );
					}
					
					break;
				}
				
				
				case -821876135:
				{
					if (field.equals("vcount")) 
					{
						__temp_executeDef21924 = false;
						return ((double) (this.get_vcount()) );
					}
					
					break;
				}
				
				
				case -1083298251:
				{
					if (field.equals("m_mode")) 
					{
						__temp_executeDef21924 = false;
						return ((double) (this.m_mode) );
					}
					
					break;
				}
				
				
				case -1834808089:
				{
					if (field.equals("primitive")) 
					{
						__temp_executeDef21924 = false;
						return ((double) (this.primitive) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21924) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
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
			boolean __temp_executeDef21925 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef21925 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1420444984:
				{
					if (field.equals("get_topology")) 
					{
						__temp_executeDef21925 = false;
						return this.get_topology();
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef21925 = false;
						this.Set(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxor.io.Buffer) (dynargs.__get(1)) ), dynargs.__get(2));
					}
					
					break;
				}
				
				
				case -1325529684:
				{
					if (field.equals("set_topology")) 
					{
						__temp_executeDef21925 = false;
						return this.set_topology(((haxor.io.UInt16Array) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef21925 = false;
						this.Remove(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 2019805448:
				{
					if (field.equals("get_indexed")) 
					{
						__temp_executeDef21925 = false;
						return this.get_indexed();
					}
					
					break;
				}
				
				
				case 167800838:
				{
					if (field.equals("GetAttribute")) 
					{
						__temp_executeDef21925 = false;
						return this.GetAttribute(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1976469740:
				{
					if (field.equals("get_mode")) 
					{
						__temp_executeDef21925 = false;
						return this.get_mode();
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef21925 = false;
						return this.Get(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1415357280:
				{
					if (field.equals("set_mode")) 
					{
						__temp_executeDef21925 = false;
						return this.set_mode(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 2089476220:
				{
					if (field.equals("Exists")) 
					{
						__temp_executeDef21925 = false;
						return this.Exists(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -598332672:
				{
					if (field.equals("get_attribs")) 
					{
						__temp_executeDef21925 = false;
						return this.get_attribs();
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef21925 = false;
						this.Clear(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case 1258802018:
				{
					if (field.equals("get_vcount")) 
					{
						__temp_executeDef21925 = false;
						return this.get_vcount();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21925) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_vcount");
		baseArr.push("vcount");
		baseArr.push("m_attribs");
		baseArr.push("attribs");
		baseArr.push("primitive");
		baseArr.push("m_mode");
		baseArr.push("mode");
		baseArr.push("m_indexed");
		baseArr.push("indexed");
		baseArr.push("m_topology_attrib");
		baseArr.push("topology");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


