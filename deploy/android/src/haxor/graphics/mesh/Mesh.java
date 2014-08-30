package haxor.graphics.mesh;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Mesh extends haxor.core.Resource
{
	public    Mesh(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Mesh(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.graphics.mesh.Mesh.__hx_ctor_haxor_graphics_mesh_Mesh(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_mesh_Mesh(haxor.graphics.mesh.Mesh __temp_me151396, java.lang.String p_name)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me151396, ( (( p_name == null )) ? (haxe.lang.Runtime.toString("")) : (p_name) ));
		if (( p_name == null )) 
		{
			p_name = "";
		}
		
		{
			haxor.context.UID _this = haxor.context.EngineContext.mesh.mid;
			if (( _this.m_cache.length <= 0 )) 
			{
				__temp_me151396.__cid = _this.m_id++;
			}
			 else 
			{
				__temp_me151396.__cid = ((int) (haxe.lang.Runtime.toInt(_this.m_cache.shift())) );
			}
			
		}
		
		__temp_me151396.m_attribs = new haxe.root.Array<haxor.graphics.mesh.MeshAttrib>(new haxor.graphics.mesh.MeshAttrib[]{});
		__temp_me151396.m_indexed = false;
		__temp_me151396.m_vcount = 0;
		__temp_me151396.m_bounds = haxor.math.AABB3.get_empty();
		__temp_me151396.m_mode = 35044;
		__temp_me151396.primitive = 4;
		__temp_me151396.m_topology_attrib = new haxor.graphics.mesh.MeshAttrib();
		__temp_me151396.m_topology_attrib.m_name = "$topology";
		__temp_me151396.m_topology_attrib.offset = 1;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.mesh.Mesh(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.mesh.Mesh(haxe.lang.Runtime.toString(arr.__get(0)));
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
	
	
	
	public   haxor.math.AABB3 get_bounds()
	{
		return this.m_bounds;
	}
	
	
	public   haxor.math.AABB3 set_bounds(haxor.math.AABB3 v)
	{
		return this.m_bounds.SetAABB3(v);
	}
	
	
	public  haxor.math.AABB3 m_bounds;
	
	public   void Clear(java.lang.Object p_from_gpu)
	{
		boolean __temp_p_from_gpu151394 = ( (( p_from_gpu == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_from_gpu)) );
		{
			int _g1 = 0;
			int _g = this.m_attribs.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				this.m_attribs.__get(i).data = null;
				this.m_attribs.__get(i).m_name = "";
				if (__temp_p_from_gpu151394) 
				{
					haxor.context.EngineContext.mesh.RemoveAttrib(this.m_attribs.__get(i));
				}
				
			}
			
		}
		
		this.m_vcount = 0;
		if (__temp_p_from_gpu151394) 
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
	
	
	public   haxor.graphics.mesh.MeshAttrib Set(java.lang.String p_name, haxor.io.Buffer p_data, java.lang.Object p_offset)
	{
		int __temp_p_offset151395 = ( (( p_offset == null )) ? (((int) (0) )) : (((int) (haxe.lang.Runtime.toInt(p_offset)) )) );
		if (( p_data == null )) 
		{
			haxor.core.Console.Log(( ( "Mesh> [" + this.get_name() ) + "] tried to set null array." ), 1);
			return null;
		}
		
		haxor.graphics.mesh.MeshAttrib a = this.GetAttribute(p_name);
		if (( a == null )) 
		{
			a = new haxor.graphics.mesh.MeshAttrib();
			a.m_name = p_name;
			this.m_attribs.push(a);
		}
		
		if (( __temp_p_offset151395 > 0 )) 
		{
			a.offset = __temp_p_offset151395;
		}
		
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
		return a;
	}
	
	
	public   haxor.math.AABB3 GenerateAttribBounds(java.lang.String p_attrib, haxor.math.AABB3 p_result)
	{
		haxor.math.AABB3 b = null;
		if (( p_result == null )) 
		{
			b = haxor.math.AABB3.get_empty();
		}
		 else 
		{
			b = p_result;
		}
		
		haxor.graphics.mesh.MeshAttrib a = this.GetAttribute(p_attrib);
		if (( a == null )) 
		{
			return b.Set(((double) (0) ), ((double) (0) ), ((double) (0) ), ((double) (0) ), ((double) (0) ), ((double) (0) ));
		}
		
		int step = a.offset;
		if (( step <= 0 )) 
		{
			return b.Set(((double) (0) ), ((double) (0) ), ((double) (0) ), ((double) (0) ), ((double) (0) ), ((double) (0) ));
		}
		
		int i = step;
		haxor.io.FloatArray f = ((haxor.io.FloatArray) (a.data) );
		double vx = 0.0;
		if (( step > 0 )) 
		{
			vx = f.Get(0);
		}
		 else 
		{
			vx = ((double) (0) );
		}
		
		double vy = 0.0;
		if (( step > 1 )) 
		{
			vy = f.Get(1);
		}
		 else 
		{
			vy = ((double) (0) );
		}
		
		double vz = 0.0;
		if (( step > 2 )) 
		{
			vz = f.Get(2);
		}
		 else 
		{
			vz = ((double) (0) );
		}
		
		b.Set(vx, vx, vy, vy, vz, vz);
		while (( i < f.m_length ))
		{
			if (( step > 0 )) 
			{
				vx = f.Get(i);
			}
			 else 
			{
				vx = ((double) (0) );
			}
			
			if (( step > 1 )) 
			{
				vy = f.Get(( i + 1 ));
			}
			 else 
			{
				vy = ((double) (0) );
			}
			
			if (( step > 2 )) 
			{
				vz = f.Get(( i + 2 ));
			}
			 else 
			{
				vz = ((double) (0) );
			}
			
			b.Encapsulate3(vx, vy, vz);
			i += step;
		}
		
		return b;
	}
	
	
	@Override public   void OnDestroy()
	{
		this.Clear(null);
		{
			int v = this.__cid;
			haxor.context.EngineContext.mesh.mid.m_cache.push(v);
			int __temp_expr152151 = v;
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152152 = true;
			switch (field.hashCode())
			{
				case -1420606869:
				{
					if (field.equals("m_vcount")) 
					{
						__temp_executeDef152152 = false;
						this.m_vcount = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3357091:
				{
					if (field.equals("mode")) 
					{
						__temp_executeDef152152 = false;
						this.set_mode(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1834808089:
				{
					if (field.equals("primitive")) 
					{
						__temp_executeDef152152 = false;
						this.primitive = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1083298251:
				{
					if (field.equals("m_mode")) 
					{
						__temp_executeDef152152 = false;
						this.m_mode = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152152) 
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
			boolean __temp_executeDef152153 = true;
			switch (field.hashCode())
			{
				case -1981935929:
				{
					if (field.equals("m_bounds")) 
					{
						__temp_executeDef152153 = false;
						this.m_bounds = ((haxor.math.AABB3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -951467409:
				{
					if (field.equals("topology")) 
					{
						__temp_executeDef152153 = false;
						this.set_topology(((haxor.io.UInt16Array) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1383205195:
				{
					if (field.equals("bounds")) 
					{
						__temp_executeDef152153 = false;
						this.set_bounds(((haxor.math.AABB3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 775846600:
				{
					if (field.equals("m_topology_attrib")) 
					{
						__temp_executeDef152153 = false;
						this.m_topology_attrib = ((haxor.graphics.mesh.MeshAttrib) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1420606869:
				{
					if (field.equals("m_vcount")) 
					{
						__temp_executeDef152153 = false;
						this.m_vcount = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 562508575:
				{
					if (field.equals("m_indexed")) 
					{
						__temp_executeDef152153 = false;
						this.m_indexed = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -2055629545:
				{
					if (field.equals("m_attribs")) 
					{
						__temp_executeDef152153 = false;
						this.m_attribs = ((haxe.root.Array<haxor.graphics.mesh.MeshAttrib>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3357091:
				{
					if (field.equals("mode")) 
					{
						__temp_executeDef152153 = false;
						this.set_mode(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -674845975:
				{
					if (field.equals("attribs")) 
					{
						__temp_executeDef152153 = false;
						this.attribs = ((haxe.root.Array<java.lang.String>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1083298251:
				{
					if (field.equals("m_mode")) 
					{
						__temp_executeDef152153 = false;
						this.m_mode = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1834808089:
				{
					if (field.equals("primitive")) 
					{
						__temp_executeDef152153 = false;
						this.primitive = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152153) 
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
			boolean __temp_executeDef152154 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case -951467409:
				{
					if (field.equals("topology")) 
					{
						__temp_executeDef152154 = false;
						return this.get_topology();
					}
					
					break;
				}
				
				
				case 319121492:
				{
					if (field.equals("GenerateAttribBounds")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GenerateAttribBounds"))) );
					}
					
					break;
				}
				
				
				case 1420444984:
				{
					if (field.equals("get_topology")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_topology"))) );
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case -1325529684:
				{
					if (field.equals("set_topology")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_topology"))) );
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Remove"))) );
					}
					
					break;
				}
				
				
				case 775846600:
				{
					if (field.equals("m_topology_attrib")) 
					{
						__temp_executeDef152154 = false;
						return this.m_topology_attrib;
					}
					
					break;
				}
				
				
				case 167800838:
				{
					if (field.equals("GetAttribute")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetAttribute"))) );
					}
					
					break;
				}
				
				
				case 1943292145:
				{
					if (field.equals("indexed")) 
					{
						__temp_executeDef152154 = false;
						return this.get_indexed();
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Get"))) );
					}
					
					break;
				}
				
				
				case 2019805448:
				{
					if (field.equals("get_indexed")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_indexed"))) );
					}
					
					break;
				}
				
				
				case 2089476220:
				{
					if (field.equals("Exists")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Exists"))) );
					}
					
					break;
				}
				
				
				case 562508575:
				{
					if (field.equals("m_indexed")) 
					{
						__temp_executeDef152154 = false;
						return this.m_indexed;
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case 3357091:
				{
					if (field.equals("mode")) 
					{
						__temp_executeDef152154 = false;
						return this.get_mode();
					}
					
					break;
				}
				
				
				case -1981935929:
				{
					if (field.equals("m_bounds")) 
					{
						__temp_executeDef152154 = false;
						return this.m_bounds;
					}
					
					break;
				}
				
				
				case 1976469740:
				{
					if (field.equals("get_mode")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_mode"))) );
					}
					
					break;
				}
				
				
				case -1660689102:
				{
					if (field.equals("set_bounds")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_bounds"))) );
					}
					
					break;
				}
				
				
				case 1415357280:
				{
					if (field.equals("set_mode")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_mode"))) );
					}
					
					break;
				}
				
				
				case 697472958:
				{
					if (field.equals("get_bounds")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_bounds"))) );
					}
					
					break;
				}
				
				
				case -1083298251:
				{
					if (field.equals("m_mode")) 
					{
						__temp_executeDef152154 = false;
						return this.m_mode;
					}
					
					break;
				}
				
				
				case -1383205195:
				{
					if (field.equals("bounds")) 
					{
						__temp_executeDef152154 = false;
						return this.get_bounds();
					}
					
					break;
				}
				
				
				case -1834808089:
				{
					if (field.equals("primitive")) 
					{
						__temp_executeDef152154 = false;
						return this.primitive;
					}
					
					break;
				}
				
				
				case -1420606869:
				{
					if (field.equals("m_vcount")) 
					{
						__temp_executeDef152154 = false;
						return this.m_vcount;
					}
					
					break;
				}
				
				
				case -674845975:
				{
					if (field.equals("attribs")) 
					{
						__temp_executeDef152154 = false;
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
				
				
				case 1258802018:
				{
					if (field.equals("get_vcount")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_vcount"))) );
					}
					
					break;
				}
				
				
				case -598332672:
				{
					if (field.equals("get_attribs")) 
					{
						__temp_executeDef152154 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_attribs"))) );
					}
					
					break;
				}
				
				
				case -821876135:
				{
					if (field.equals("vcount")) 
					{
						__temp_executeDef152154 = false;
						return this.get_vcount();
					}
					
					break;
				}
				
				
				case -2055629545:
				{
					if (field.equals("m_attribs")) 
					{
						__temp_executeDef152154 = false;
						return this.m_attribs;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152154) 
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
			boolean __temp_executeDef152155 = true;
			switch (field.hashCode())
			{
				case -1420606869:
				{
					if (field.equals("m_vcount")) 
					{
						__temp_executeDef152155 = false;
						return ((double) (this.m_vcount) );
					}
					
					break;
				}
				
				
				case 3357091:
				{
					if (field.equals("mode")) 
					{
						__temp_executeDef152155 = false;
						return ((double) (this.get_mode()) );
					}
					
					break;
				}
				
				
				case -821876135:
				{
					if (field.equals("vcount")) 
					{
						__temp_executeDef152155 = false;
						return ((double) (this.get_vcount()) );
					}
					
					break;
				}
				
				
				case -1083298251:
				{
					if (field.equals("m_mode")) 
					{
						__temp_executeDef152155 = false;
						return ((double) (this.m_mode) );
					}
					
					break;
				}
				
				
				case -1834808089:
				{
					if (field.equals("primitive")) 
					{
						__temp_executeDef152155 = false;
						return ((double) (this.primitive) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152155) 
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
			boolean __temp_executeDef152156 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef152156 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1420444984:
				{
					if (field.equals("get_topology")) 
					{
						__temp_executeDef152156 = false;
						return this.get_topology();
					}
					
					break;
				}
				
				
				case 319121492:
				{
					if (field.equals("GenerateAttribBounds")) 
					{
						__temp_executeDef152156 = false;
						return this.GenerateAttribBounds(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxor.math.AABB3) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -1325529684:
				{
					if (field.equals("set_topology")) 
					{
						__temp_executeDef152156 = false;
						return this.set_topology(((haxor.io.UInt16Array) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef152156 = false;
						return this.Set(haxe.lang.Runtime.toString(dynargs.__get(0)), ((haxor.io.Buffer) (dynargs.__get(1)) ), dynargs.__get(2));
					}
					
					break;
				}
				
				
				case 2019805448:
				{
					if (field.equals("get_indexed")) 
					{
						__temp_executeDef152156 = false;
						return this.get_indexed();
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef152156 = false;
						this.Remove(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1976469740:
				{
					if (field.equals("get_mode")) 
					{
						__temp_executeDef152156 = false;
						return this.get_mode();
					}
					
					break;
				}
				
				
				case 167800838:
				{
					if (field.equals("GetAttribute")) 
					{
						__temp_executeDef152156 = false;
						return this.GetAttribute(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1415357280:
				{
					if (field.equals("set_mode")) 
					{
						__temp_executeDef152156 = false;
						return this.set_mode(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef152156 = false;
						return this.Get(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -598332672:
				{
					if (field.equals("get_attribs")) 
					{
						__temp_executeDef152156 = false;
						return this.get_attribs();
					}
					
					break;
				}
				
				
				case 2089476220:
				{
					if (field.equals("Exists")) 
					{
						__temp_executeDef152156 = false;
						return this.Exists(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1258802018:
				{
					if (field.equals("get_vcount")) 
					{
						__temp_executeDef152156 = false;
						return this.get_vcount();
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef152156 = false;
						this.Clear(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case 697472958:
				{
					if (field.equals("get_bounds")) 
					{
						__temp_executeDef152156 = false;
						return this.get_bounds();
					}
					
					break;
				}
				
				
				case -1660689102:
				{
					if (field.equals("set_bounds")) 
					{
						__temp_executeDef152156 = false;
						return this.set_bounds(((haxor.math.AABB3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152156) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_bounds");
		baseArr.push("bounds");
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


