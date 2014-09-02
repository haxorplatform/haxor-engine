package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class RendererContext extends haxe.lang.HxObject
{
	public    RendererContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    RendererContext()
	{
		haxor.context.RendererContext.__hx_ctor_haxor_context_RendererContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_RendererContext(haxor.context.RendererContext __temp_me164192)
	{
		__temp_me164192.rid = new haxor.context.UID();
		__temp_me164192.fcid = new haxor.context.UID();
		__temp_me164192.sap = new haxor.ds.SAP(((java.lang.Object) (0.01) ), ((java.lang.Object) (false) ));
		__temp_me164192.sap_dirty = false;
		__temp_me164192.deferred_culling = 0;
		__temp_me164192.deferred_offset = 100;
		__temp_me164192.display = new haxe.root.Array<haxor.context.Process>(new haxor.context.Process[]{});
		__temp_me164192.sort = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		{
			int _g = 0;
			while (( _g < 32 ))
			{
				int i = _g++;
				haxor.context.Process<haxor.component.Renderer> p = new haxor.context.Process<haxor.component.Renderer>(haxe.lang.Runtime.toString("process.renderers"), ((int) (haxor.context.EngineContext.maxNodes) ), ((java.lang.Object) (( i == 31 )) ));
				__temp_me164192.display.push(((haxor.context.Process) (p) ));
				__temp_me164192.sort.push(false);
			}
			
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.RendererContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.RendererContext();
	}
	
	
	public  haxor.context.UID rid;
	
	public  haxor.context.UID fcid;
	
	public  haxe.root.Array<haxor.context.Process> display;
	
	public  haxor.ds.SAP sap;
	
	public  boolean sap_dirty;
	
	public  haxe.root.Array<java.lang.Object> sort;
	
	public  haxor.graphics.texture.ComputeTexture skinning;
	
	public  int deferred_culling;
	
	public  int deferred_offset;
	
	public   void Initialize()
	{
		this.skinning = new haxor.graphics.texture.ComputeTexture(((int) (512) ), ((int) (512) ), ((haxor.core.PixelFormat) (haxor.core.PixelFormat.Float4) ));
	}
	
	
	public   void Create(haxor.component.Renderer r)
	{
		{
			haxor.context.UID _this = this.rid;
			if (( _this.m_cache.length <= 0 )) 
			{
				r.__cid = _this.m_id++;
			}
			 else 
			{
				r.__cid = ((int) (haxe.lang.Runtime.toInt(_this.m_cache.shift())) );
			}
			
		}
		
		if (r.m_has_mesh) 
		{
			haxor.component.MeshRenderer mr = ((haxor.component.MeshRenderer) (r) );
			{
				haxor.context.UID _this1 = this.fcid;
				if (( _this1.m_cache.length <= 0 )) 
				{
					mr.__fcid = _this1.m_id++;
				}
				 else 
				{
					mr.__fcid = ((int) (haxe.lang.Runtime.toInt(_this1.m_cache.shift())) );
				}
				
			}
			
			this.sap.Create(mr.__fcid);
		}
		
	}
	
	
	public   void AddCamera(haxor.component.Camera c)
	{
		{
			haxor.context.UID _this = this.fcid;
			if (( _this.m_cache.length <= 0 )) 
			{
				c.__fcid = _this.m_id++;
			}
			 else 
			{
				c.__fcid = ((int) (haxe.lang.Runtime.toInt(_this.m_cache.shift())) );
			}
			
		}
		
		this.sap.Create(c.__fcid);
	}
	
	
	public   void RemoveCamera(haxor.component.Camera c)
	{
		{
			int v = c.__fcid;
			this.fcid.m_cache.push(v);
			int __temp_expr164845 = v;
		}
		
		this.sap.Remove(c.__fcid);
	}
	
	
	public   void OnMaterialChange(haxor.component.Renderer r)
	{
		int l = r.m_entity.m_layer;
		this.sort.__set(l, true);
	}
	
	
	public   void OnMeshChange(haxor.component.Renderer r)
	{
		int l = r.m_entity.m_layer;
		this.sort.__set(l, true);
	}
	
	
	public   void OnVisibilityChange(haxor.component.Renderer r, boolean f)
	{
		haxe.root.Array<haxor.component.Component> cl = r.m_entity.m_components;
		{
			int _g1 = 0;
			int _g = cl.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				cl.__get(i).OnVisibilityChange(f);
			}
			
		}
		
	}
	
	
	public   boolean DeferredCulling(haxor.component.Renderer r)
	{
		return false;
	}
	
	
	public   void OnLayerChange(haxor.component.Renderer r, int from, int to)
	{
		this.sort.__set(from, true);
		((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(from)) )) ).Remove(r);
		if (r.get_enabled()) 
		{
			((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(to)) )) ).Add(r);
			this.sort.__set(to, true);
		}
		
	}
	
	
	public   void UpdateDisplayList(haxor.component.Camera c)
	{
		haxe.root.Array<java.lang.Object> ll = c.m_layers;
		{
			int _g1 = 0;
			int _g = ll.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				int l = ((int) (haxe.lang.Runtime.toInt(ll.__get(i))) );
				haxor.context.Process<haxor.component.Renderer> rl = ((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(l)) )) );
				boolean need_sort = haxe.lang.Runtime.toBool(this.sort.__get(l));
				if (need_sort) 
				{
					this.sort.__set(l, false);
					if (( rl.m_length > 1 )) 
					{
						rl.Sort(((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DisplayListSort"))) ));
					}
					
				}
				
			}
			
		}
		
	}
	
	
	public   void Enable(haxor.component.Renderer r)
	{
		((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(r.m_entity.m_layer)) )) ).Add(r);
		this.sort.__set(r.m_entity.m_layer, true);
		if (r.m_has_mesh) 
		{
			haxor.component.MeshRenderer mr = ((haxor.component.MeshRenderer) (r) );
			mr.m_culling_dirty = true;
		}
		
	}
	
	
	public   void Disable(haxor.component.Renderer r)
	{
		((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(r.m_entity.m_layer)) )) ).Remove(r);
		this.sort.__set(r.m_entity.m_layer, true);
	}
	
	
	public   void UpdateSAP(int p_id, java.lang.Object p_d, haxor.math.Vector3 p_min, haxor.math.Vector3 p_max)
	{
		this.sap_dirty = true;
		this.sap.Update(p_id, p_d, p_min, p_max);
	}
	
	
	public   boolean IsSAPCulled(haxor.component.Renderer r, haxor.component.Camera c)
	{
		if ( ! (r.m_has_mesh) ) 
		{
			return false;
		}
		
		haxor.component.MeshRenderer mr = ((haxor.component.MeshRenderer) (r) );
		return this.sap.Overlap(mr.__fcid, c.__fcid);
	}
	
	
	public   void Destroy(haxor.component.Renderer r)
	{
		((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(r.m_entity.m_layer)) )) ).Remove(r);
		this.sort.__set(r.m_entity.m_layer, true);
		{
			int v = r.__cid;
			this.rid.m_cache.push(v);
			int __temp_expr164847 = v;
		}
		
		if (r.m_has_mesh) 
		{
			haxor.component.MeshRenderer mr = ((haxor.component.MeshRenderer) (r) );
			{
				int v1 = mr.__fcid;
				this.fcid.m_cache.push(v1);
				int __temp_expr164848 = v1;
			}
			
			this.sap.Remove(mr.__fcid);
		}
		
	}
	
	
	public   int DisplayListSort(haxor.component.Renderer a, haxor.component.Renderer b)
	{
		if (( a == null )) 
		{
			if (( b == null )) 
			{
				return 0;
			}
			
		}
		
		if (( a == null )) 
		{
			return 1;
		}
		
		if (( b == null )) 
		{
			return -1;
		}
		
		if (( a.m_material == null )) 
		{
			if (( b.m_material == null )) 
			{
				return 0;
			}
			
		}
		
		if (( a.m_material == null )) 
		{
			return 1;
		}
		
		if (( b.m_material == null )) 
		{
			return -1;
		}
		
		haxor.graphics.material.Material ma = a.m_material;
		haxor.graphics.material.Material mb = b.m_material;
		int ia = ma.queue;
		int ib = mb.queue;
		if (( ia != ib )) 
		{
			if (( ia < ib )) 
			{
				return -1;
			}
			 else 
			{
				return 1;
			}
			
		}
		
		if ( ! (a.m_has_mesh) ) 
		{
			if ( ! (b.m_has_mesh) ) 
			{
				return 0;
			}
			
		}
		
		if ( ! (a.m_has_mesh) ) 
		{
			return 1;
		}
		
		if ( ! (b.m_has_mesh) ) 
		{
			return -1;
		}
		
		haxor.component.MeshRenderer mra = ((haxor.component.MeshRenderer) (a) );
		haxor.component.MeshRenderer mrb = ((haxor.component.MeshRenderer) (b) );
		if (( mra.m_material.get_uid() < mrb.m_material.get_uid() )) 
		{
			return -1;
		}
		
		if (( mra.m_material.get_uid() > mrb.m_material.get_uid() )) 
		{
			return 1;
		}
		
		if (( mra.m_mesh == null )) 
		{
			if (( mrb.m_mesh == null )) 
			{
				return 0;
			}
			
		}
		
		if (( mra.m_mesh == null )) 
		{
			return 1;
		}
		
		if (( mrb.m_mesh == null )) 
		{
			return -1;
		}
		
		if (( mra.m_mesh.get_uid() < mrb.m_mesh.get_uid() )) 
		{
			return -1;
		}
		
		if (( mra.m_mesh.get_uid() > mrb.m_mesh.get_uid() )) 
		{
			return 1;
		}
		
		return 0;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef164849 = true;
			switch (field.hashCode())
			{
				case -710307597:
				{
					if (field.equals("deferred_offset")) 
					{
						__temp_executeDef164849 = false;
						this.deferred_offset = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 2124932304:
				{
					if (field.equals("deferred_culling")) 
					{
						__temp_executeDef164849 = false;
						this.deferred_culling = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164849) 
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
			boolean __temp_executeDef164850 = true;
			switch (field.hashCode())
			{
				case -710307597:
				{
					if (field.equals("deferred_offset")) 
					{
						__temp_executeDef164850 = false;
						this.deferred_offset = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 112909:
				{
					if (field.equals("rid")) 
					{
						__temp_executeDef164850 = false;
						this.rid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 2124932304:
				{
					if (field.equals("deferred_culling")) 
					{
						__temp_executeDef164850 = false;
						this.deferred_culling = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3137176:
				{
					if (field.equals("fcid")) 
					{
						__temp_executeDef164850 = false;
						this.fcid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 2144368561:
				{
					if (field.equals("skinning")) 
					{
						__temp_executeDef164850 = false;
						this.skinning = ((haxor.graphics.texture.ComputeTexture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1671764162:
				{
					if (field.equals("display")) 
					{
						__temp_executeDef164850 = false;
						this.display = ((haxe.root.Array<haxor.context.Process>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3536286:
				{
					if (field.equals("sort")) 
					{
						__temp_executeDef164850 = false;
						this.sort = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 113634:
				{
					if (field.equals("sap")) 
					{
						__temp_executeDef164850 = false;
						this.sap = ((haxor.ds.SAP) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1013395147:
				{
					if (field.equals("sap_dirty")) 
					{
						__temp_executeDef164850 = false;
						this.sap_dirty = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164850) 
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
			boolean __temp_executeDef164851 = true;
			switch (field.hashCode())
			{
				case -846533090:
				{
					if (field.equals("DisplayListSort")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DisplayListSort"))) );
					}
					
					break;
				}
				
				
				case 112909:
				{
					if (field.equals("rid")) 
					{
						__temp_executeDef164851 = false;
						return this.rid;
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Destroy"))) );
					}
					
					break;
				}
				
				
				case 3137176:
				{
					if (field.equals("fcid")) 
					{
						__temp_executeDef164851 = false;
						return this.fcid;
					}
					
					break;
				}
				
				
				case -1518609943:
				{
					if (field.equals("IsSAPCulled")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("IsSAPCulled"))) );
					}
					
					break;
				}
				
				
				case 1671764162:
				{
					if (field.equals("display")) 
					{
						__temp_executeDef164851 = false;
						return this.display;
					}
					
					break;
				}
				
				
				case 54756921:
				{
					if (field.equals("UpdateSAP")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateSAP"))) );
					}
					
					break;
				}
				
				
				case 113634:
				{
					if (field.equals("sap")) 
					{
						__temp_executeDef164851 = false;
						return this.sap;
					}
					
					break;
				}
				
				
				case -959006008:
				{
					if (field.equals("Disable")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Disable"))) );
					}
					
					break;
				}
				
				
				case -1013395147:
				{
					if (field.equals("sap_dirty")) 
					{
						__temp_executeDef164851 = false;
						return this.sap_dirty;
					}
					
					break;
				}
				
				
				case 2079986083:
				{
					if (field.equals("Enable")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Enable"))) );
					}
					
					break;
				}
				
				
				case 3536286:
				{
					if (field.equals("sort")) 
					{
						__temp_executeDef164851 = false;
						return this.sort;
					}
					
					break;
				}
				
				
				case 218141655:
				{
					if (field.equals("UpdateDisplayList")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateDisplayList"))) );
					}
					
					break;
				}
				
				
				case 2144368561:
				{
					if (field.equals("skinning")) 
					{
						__temp_executeDef164851 = false;
						return this.skinning;
					}
					
					break;
				}
				
				
				case -1016165150:
				{
					if (field.equals("OnLayerChange")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnLayerChange"))) );
					}
					
					break;
				}
				
				
				case 2124932304:
				{
					if (field.equals("deferred_culling")) 
					{
						__temp_executeDef164851 = false;
						return this.deferred_culling;
					}
					
					break;
				}
				
				
				case -610139087:
				{
					if (field.equals("DeferredCulling")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeferredCulling"))) );
					}
					
					break;
				}
				
				
				case -710307597:
				{
					if (field.equals("deferred_offset")) 
					{
						__temp_executeDef164851 = false;
						return this.deferred_offset;
					}
					
					break;
				}
				
				
				case -1403863679:
				{
					if (field.equals("OnVisibilityChange")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnVisibilityChange"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case -216472740:
				{
					if (field.equals("OnMeshChange")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMeshChange"))) );
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Create"))) );
					}
					
					break;
				}
				
				
				case -2133551210:
				{
					if (field.equals("OnMaterialChange")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMaterialChange"))) );
					}
					
					break;
				}
				
				
				case 1529056006:
				{
					if (field.equals("AddCamera")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("AddCamera"))) );
					}
					
					break;
				}
				
				
				case -1164867351:
				{
					if (field.equals("RemoveCamera")) 
					{
						__temp_executeDef164851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("RemoveCamera"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164851) 
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
			boolean __temp_executeDef164852 = true;
			switch (field.hashCode())
			{
				case -710307597:
				{
					if (field.equals("deferred_offset")) 
					{
						__temp_executeDef164852 = false;
						return ((double) (this.deferred_offset) );
					}
					
					break;
				}
				
				
				case 2124932304:
				{
					if (field.equals("deferred_culling")) 
					{
						__temp_executeDef164852 = false;
						return ((double) (this.deferred_culling) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164852) 
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
			boolean __temp_executeDef164853 = true;
			switch (field.hashCode())
			{
				case -846533090:
				{
					if (field.equals("DisplayListSort")) 
					{
						__temp_executeDef164853 = false;
						return this.DisplayListSort(((haxor.component.Renderer) (dynargs.__get(0)) ), ((haxor.component.Renderer) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef164853 = false;
						this.Initialize();
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef164853 = false;
						this.Destroy(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef164853 = false;
						this.Create(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1518609943:
				{
					if (field.equals("IsSAPCulled")) 
					{
						__temp_executeDef164853 = false;
						return this.IsSAPCulled(((haxor.component.Renderer) (dynargs.__get(0)) ), ((haxor.component.Camera) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1529056006:
				{
					if (field.equals("AddCamera")) 
					{
						__temp_executeDef164853 = false;
						this.AddCamera(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 54756921:
				{
					if (field.equals("UpdateSAP")) 
					{
						__temp_executeDef164853 = false;
						this.UpdateSAP(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), dynargs.__get(1), ((haxor.math.Vector3) (dynargs.__get(2)) ), ((haxor.math.Vector3) (dynargs.__get(3)) ));
					}
					
					break;
				}
				
				
				case -1164867351:
				{
					if (field.equals("RemoveCamera")) 
					{
						__temp_executeDef164853 = false;
						this.RemoveCamera(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -959006008:
				{
					if (field.equals("Disable")) 
					{
						__temp_executeDef164853 = false;
						this.Disable(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -2133551210:
				{
					if (field.equals("OnMaterialChange")) 
					{
						__temp_executeDef164853 = false;
						this.OnMaterialChange(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2079986083:
				{
					if (field.equals("Enable")) 
					{
						__temp_executeDef164853 = false;
						this.Enable(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -216472740:
				{
					if (field.equals("OnMeshChange")) 
					{
						__temp_executeDef164853 = false;
						this.OnMeshChange(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 218141655:
				{
					if (field.equals("UpdateDisplayList")) 
					{
						__temp_executeDef164853 = false;
						this.UpdateDisplayList(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1403863679:
				{
					if (field.equals("OnVisibilityChange")) 
					{
						__temp_executeDef164853 = false;
						this.OnVisibilityChange(((haxor.component.Renderer) (dynargs.__get(0)) ), haxe.lang.Runtime.toBool(dynargs.__get(1)));
					}
					
					break;
				}
				
				
				case -1016165150:
				{
					if (field.equals("OnLayerChange")) 
					{
						__temp_executeDef164853 = false;
						this.OnLayerChange(((haxor.component.Renderer) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -610139087:
				{
					if (field.equals("DeferredCulling")) 
					{
						__temp_executeDef164853 = false;
						return this.DeferredCulling(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164853) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("deferred_offset");
		baseArr.push("deferred_culling");
		baseArr.push("skinning");
		baseArr.push("sort");
		baseArr.push("sap_dirty");
		baseArr.push("sap");
		baseArr.push("display");
		baseArr.push("fcid");
		baseArr.push("rid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


