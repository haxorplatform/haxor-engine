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
	
	
	public static   void __hx_ctor_haxor_graphics_mesh_Mesh(haxor.graphics.mesh.Mesh __temp_me26100)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me26100, null);
		__temp_me26100.m_attribs = new haxe.root.Array<haxor.graphics.mesh.MeshAttrib>(new haxor.graphics.mesh.MeshAttrib[]{});
		__temp_me26100.m_indexed = false;
		__temp_me26100.m_vcount = 0;
		__temp_me26100.m_topology_attrib = new haxor.graphics.mesh.MeshAttrib();
		__temp_me26100.m_topology_attrib.name = "$topology";
		__temp_me26100.m_topology_attrib.offset = 1;
		__temp_me26100.m_topology_attrib.type = "int";
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
		}
		 else 
		{
			this.m_topology_attrib.data = v;
			this.m_indexed = true;
		}
		
		return v;
	}
	
	
	public  haxor.graphics.mesh.MeshAttrib m_topology_attrib;
	
	
	
	public   boolean get_indexed()
	{
		return this.m_indexed;
	}
	
	
	public  boolean m_indexed;
	
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
				l.push(this.m_attribs.__get(i).name);
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
	
	public   void Clear()
	{
		{
			int _g1 = 0;
			int _g = this.m_attribs.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
			}
			
		}
		
		this.m_attribs = new haxe.root.Array<haxor.graphics.mesh.MeshAttrib>(new haxor.graphics.mesh.MeshAttrib[]{});
		this.m_vcount = 0;
		this.set_topology(null);
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
				if (haxe.lang.Runtime.valEq(this.m_attribs.__get(i).name, p_name)) 
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
	}
	
	
	public   void Set(java.lang.String p_name, haxor.io.BaseArray p_data, java.lang.Object p_offset)
	{
		int __temp_p_offset26099 = ( (( p_offset == null )) ? (((int) (3) )) : (((int) (haxe.lang.Runtime.toInt(p_offset)) )) );
		if (( p_data == null )) 
		{
			haxor.core.Console.Log(( ( "Mesh> [" + this.get_name() ) + "] tried to set null array." ), 1);
			return ;
		}
		
		if (( p_data.get_length() <= 0 )) 
		{
			haxor.core.Console.Log(( ( "Mesh> [" + this.get_name() ) + "] tried to set empty array." ), 1);
			return ;
		}
		
		haxor.graphics.mesh.MeshAttrib a = this.GetAttribute(p_name);
		if (( a == null )) 
		{
			a = new haxor.graphics.mesh.MeshAttrib();
			a.name = p_name;
			this.m_attribs.push(a);
		}
		
		a.offset = __temp_p_offset26099;
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
		
		int bid = haxor.platform.graphics.GL.CreateBuffer();
		haxor.core.Console.Log(( ">>> " + bid ), null);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef26185 = true;
			switch (field.hashCode())
			{
				case -1420606869:
				{
					if (field.equals("m_vcount")) 
					{
						__temp_executeDef26185 = false;
						this.m_vcount = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26185) 
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
			boolean __temp_executeDef26186 = true;
			switch (field.hashCode())
			{
				case -1420606869:
				{
					if (field.equals("m_vcount")) 
					{
						__temp_executeDef26186 = false;
						this.m_vcount = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -951467409:
				{
					if (field.equals("topology")) 
					{
						__temp_executeDef26186 = false;
						this.set_topology(((haxor.io.UInt16Array) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -2055629545:
				{
					if (field.equals("m_attribs")) 
					{
						__temp_executeDef26186 = false;
						this.m_attribs = ((haxe.root.Array<haxor.graphics.mesh.MeshAttrib>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 775846600:
				{
					if (field.equals("m_topology_attrib")) 
					{
						__temp_executeDef26186 = false;
						this.m_topology_attrib = ((haxor.graphics.mesh.MeshAttrib) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -674845975:
				{
					if (field.equals("attribs")) 
					{
						__temp_executeDef26186 = false;
						this.attribs = ((haxe.root.Array<java.lang.String>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 562508575:
				{
					if (field.equals("m_indexed")) 
					{
						__temp_executeDef26186 = false;
						this.m_indexed = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26186) 
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
			boolean __temp_executeDef26187 = true;
			switch (field.hashCode())
			{
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef26187 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case -951467409:
				{
					if (field.equals("topology")) 
					{
						__temp_executeDef26187 = false;
						return this.get_topology();
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef26187 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Remove"))) );
					}
					
					break;
				}
				
				
				case 1420444984:
				{
					if (field.equals("get_topology")) 
					{
						__temp_executeDef26187 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_topology"))) );
					}
					
					break;
				}
				
				
				case 167800838:
				{
					if (field.equals("GetAttribute")) 
					{
						__temp_executeDef26187 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetAttribute"))) );
					}
					
					break;
				}
				
				
				case -1325529684:
				{
					if (field.equals("set_topology")) 
					{
						__temp_executeDef26187 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_topology"))) );
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef26187 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Get"))) );
					}
					
					break;
				}
				
				
				case 775846600:
				{
					if (field.equals("m_topology_attrib")) 
					{
						__temp_executeDef26187 = false;
						return this.m_topology_attrib;
					}
					
					break;
				}
				
				
				case 2089476220:
				{
					if (field.equals("Exists")) 
					{
						__temp_executeDef26187 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Exists"))) );
					}
					
					break;
				}
				
				
				case 1943292145:
				{
					if (field.equals("indexed")) 
					{
						__temp_executeDef26187 = false;
						return this.get_indexed();
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef26187 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case 2019805448:
				{
					if (field.equals("get_indexed")) 
					{
						__temp_executeDef26187 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_indexed"))) );
					}
					
					break;
				}
				
				
				case -1420606869:
				{
					if (field.equals("m_vcount")) 
					{
						__temp_executeDef26187 = false;
						return this.m_vcount;
					}
					
					break;
				}
				
				
				case 562508575:
				{
					if (field.equals("m_indexed")) 
					{
						__temp_executeDef26187 = false;
						return this.m_indexed;
					}
					
					break;
				}
				
				
				case 1258802018:
				{
					if (field.equals("get_vcount")) 
					{
						__temp_executeDef26187 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_vcount"))) );
					}
					
					break;
				}
				
				
				case -674845975:
				{
					if (field.equals("attribs")) 
					{
						__temp_executeDef26187 = false;
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
				
				
				case -821876135:
				{
					if (field.equals("vcount")) 
					{
						__temp_executeDef26187 = false;
						return this.get_vcount();
					}
					
					break;
				}
				
				
				case -598332672:
				{
					if (field.equals("get_attribs")) 
					{
						__temp_executeDef26187 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_attribs"))) );
					}
					
					break;
				}
				
				
				case -2055629545:
				{
					if (field.equals("m_attribs")) 
					{
						__temp_executeDef26187 = false;
						return this.m_attribs;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26187) 
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
			boolean __temp_executeDef26188 = true;
			switch (field.hashCode())
			{
				case -1420606869:
				{
					if (field.equals("m_vcount")) 
					{
						__temp_executeDef26188 = false;
						return ((double) (this.m_vcount) );
					}
					
					break;
				}
				
				
				case -821876135:
				{
					if (field.equals("vcount")) 
					{
						__temp_executeDef26188 = false;
						return ((double) (this.get_vcount()) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26188) 
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
			boolean __temp_executeDef26189 = true;
			switch (field.hashCode())
			{
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef26189 = false;
						this.Set(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxor.io.BaseArray) (dynargs.__get(1)) ), dynargs.__get(2));
					}
					
					break;
				}
				
				
				case 1420444984:
				{
					if (field.equals("get_topology")) 
					{
						__temp_executeDef26189 = false;
						return this.get_topology();
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef26189 = false;
						this.Remove(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1325529684:
				{
					if (field.equals("set_topology")) 
					{
						__temp_executeDef26189 = false;
						return this.set_topology(((haxor.io.UInt16Array) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 167800838:
				{
					if (field.equals("GetAttribute")) 
					{
						__temp_executeDef26189 = false;
						return this.GetAttribute(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 2019805448:
				{
					if (field.equals("get_indexed")) 
					{
						__temp_executeDef26189 = false;
						return this.get_indexed();
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef26189 = false;
						return this.Get(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -598332672:
				{
					if (field.equals("get_attribs")) 
					{
						__temp_executeDef26189 = false;
						return this.get_attribs();
					}
					
					break;
				}
				
				
				case 2089476220:
				{
					if (field.equals("Exists")) 
					{
						__temp_executeDef26189 = false;
						return this.Exists(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1258802018:
				{
					if (field.equals("get_vcount")) 
					{
						__temp_executeDef26189 = false;
						return this.get_vcount();
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef26189 = false;
						this.Clear();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26189) 
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
		baseArr.push("m_indexed");
		baseArr.push("indexed");
		baseArr.push("m_topology_attrib");
		baseArr.push("topology");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


