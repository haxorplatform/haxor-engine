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
	
	
	public static   void __hx_ctor_haxor_context_RendererContext(haxor.context.RendererContext __temp_me80606)
	{
		__temp_me80606.rid = new haxor.context.UID();
		__temp_me80606.display = new haxe.root.Array<haxor.context.Process>(new haxor.context.Process[]{});
		__temp_me80606.sort = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		{
			int _g = 0;
			while (( _g < 32 ))
			{
				int i = _g++;
				haxor.context.Process<haxor.component.Renderer> p = new haxor.context.Process<haxor.component.Renderer>(haxe.lang.Runtime.toString("process.renderers"), ((int) (haxor.context.EngineContext.maxNodes) ), ((java.lang.Object) (( i == 31 )) ));
				__temp_me80606.display.push(((haxor.context.Process) (p) ));
				__temp_me80606.sort.push(false);
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
	
	public  haxe.root.Array<haxor.context.Process> display;
	
	public  haxe.root.Array<java.lang.Object> sort;
	
	public  haxor.graphics.texture.ComputeTexture skinning;
	
	public   void Initialize()
	{
		this.skinning = new haxor.graphics.texture.ComputeTexture(((int) (512) ), ((int) (512) ), ((haxor.graphics.PixelFormat) (haxor.graphics.PixelFormat.Float4) ));
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
						rl.list.sort(((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DisplayListSort"))) ));
					}
					
				}
				
			}
			
		}
		
	}
	
	
	public   void Enable(haxor.component.Renderer r)
	{
		((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(r.m_entity.m_layer)) )) ).Add(r);
		this.sort.__set(r.m_entity.m_layer, true);
	}
	
	
	public   void Disable(haxor.component.Renderer r)
	{
		((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(r.m_entity.m_layer)) )) ).Remove(r);
		this.sort.__set(r.m_entity.m_layer, true);
	}
	
	
	public   void Destroy(haxor.component.Renderer r)
	{
		((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (this.display.__get(r.m_entity.m_layer)) )) ).Remove(r);
		this.sort.__set(r.m_entity.m_layer, true);
		{
			int v = r.__cid;
			haxor.context.EngineContext.renderer.rid.m_cache.push(v);
			int __temp_expr81304 = v;
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
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef81305 = true;
			switch (field.hashCode())
			{
				case 2144368561:
				{
					if (field.equals("skinning")) 
					{
						__temp_executeDef81305 = false;
						this.skinning = ((haxor.graphics.texture.ComputeTexture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 112909:
				{
					if (field.equals("rid")) 
					{
						__temp_executeDef81305 = false;
						this.rid = ((haxor.context.UID) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3536286:
				{
					if (field.equals("sort")) 
					{
						__temp_executeDef81305 = false;
						this.sort = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1671764162:
				{
					if (field.equals("display")) 
					{
						__temp_executeDef81305 = false;
						this.display = ((haxe.root.Array<haxor.context.Process>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81305) 
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
			boolean __temp_executeDef81306 = true;
			switch (field.hashCode())
			{
				case -846533090:
				{
					if (field.equals("DisplayListSort")) 
					{
						__temp_executeDef81306 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DisplayListSort"))) );
					}
					
					break;
				}
				
				
				case 112909:
				{
					if (field.equals("rid")) 
					{
						__temp_executeDef81306 = false;
						return this.rid;
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef81306 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Destroy"))) );
					}
					
					break;
				}
				
				
				case 1671764162:
				{
					if (field.equals("display")) 
					{
						__temp_executeDef81306 = false;
						return this.display;
					}
					
					break;
				}
				
				
				case -959006008:
				{
					if (field.equals("Disable")) 
					{
						__temp_executeDef81306 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Disable"))) );
					}
					
					break;
				}
				
				
				case 3536286:
				{
					if (field.equals("sort")) 
					{
						__temp_executeDef81306 = false;
						return this.sort;
					}
					
					break;
				}
				
				
				case 2079986083:
				{
					if (field.equals("Enable")) 
					{
						__temp_executeDef81306 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Enable"))) );
					}
					
					break;
				}
				
				
				case 2144368561:
				{
					if (field.equals("skinning")) 
					{
						__temp_executeDef81306 = false;
						return this.skinning;
					}
					
					break;
				}
				
				
				case 218141655:
				{
					if (field.equals("UpdateDisplayList")) 
					{
						__temp_executeDef81306 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateDisplayList"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef81306 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case -1016165150:
				{
					if (field.equals("OnLayerChange")) 
					{
						__temp_executeDef81306 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnLayerChange"))) );
					}
					
					break;
				}
				
				
				case -2133551210:
				{
					if (field.equals("OnMaterialChange")) 
					{
						__temp_executeDef81306 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMaterialChange"))) );
					}
					
					break;
				}
				
				
				case -216472740:
				{
					if (field.equals("OnMeshChange")) 
					{
						__temp_executeDef81306 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnMeshChange"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81306) 
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
			boolean __temp_executeDef81307 = true;
			switch (field.hashCode())
			{
				case -846533090:
				{
					if (field.equals("DisplayListSort")) 
					{
						__temp_executeDef81307 = false;
						return this.DisplayListSort(((haxor.component.Renderer) (dynargs.__get(0)) ), ((haxor.component.Renderer) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef81307 = false;
						this.Initialize();
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef81307 = false;
						this.Destroy(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -2133551210:
				{
					if (field.equals("OnMaterialChange")) 
					{
						__temp_executeDef81307 = false;
						this.OnMaterialChange(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -959006008:
				{
					if (field.equals("Disable")) 
					{
						__temp_executeDef81307 = false;
						this.Disable(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -216472740:
				{
					if (field.equals("OnMeshChange")) 
					{
						__temp_executeDef81307 = false;
						this.OnMeshChange(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2079986083:
				{
					if (field.equals("Enable")) 
					{
						__temp_executeDef81307 = false;
						this.Enable(((haxor.component.Renderer) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1016165150:
				{
					if (field.equals("OnLayerChange")) 
					{
						__temp_executeDef81307 = false;
						this.OnLayerChange(((haxor.component.Renderer) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case 218141655:
				{
					if (field.equals("UpdateDisplayList")) 
					{
						__temp_executeDef81307 = false;
						this.UpdateDisplayList(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81307) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("skinning");
		baseArr.push("sort");
		baseArr.push("display");
		baseArr.push("rid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


