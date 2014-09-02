package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MeshRenderer extends haxor.component.Renderer
{
	public    MeshRenderer(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    MeshRenderer(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.MeshRenderer.__hx_ctor_haxor_component_MeshRenderer(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_component_MeshRenderer(haxor.component.MeshRenderer __temp_me160436, java.lang.String p_name)
	{
		haxor.component.Renderer.__hx_ctor_haxor_component_Renderer(__temp_me160436, p_name);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.MeshRenderer(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.MeshRenderer(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	
	
	public final   haxor.graphics.mesh.Mesh get_mesh()
	{
		return this.m_mesh;
	}
	
	
	public   haxor.graphics.mesh.Mesh set_mesh(haxor.graphics.mesh.Mesh v)
	{
		if (( this.m_mesh == v )) 
		{
			return v;
		}
		
		this.m_mesh = v;
		return v;
	}
	
	
	public  haxor.graphics.mesh.Mesh m_mesh;
	
	
	
	public final   boolean get_visible()
	{
		return this.IsVisible(haxor.component.Camera.m_main);
	}
	
	
	@Override public   void OnBuild()
	{
		super.OnBuild();
		this.m_has_mesh = true;
	}
	
	
	public   boolean IsVisible(haxor.component.Camera p_camera)
	{
		if (( p_camera == null )) 
		{
			return false;
		}
		
		return true;
	}
	
	
	public   boolean CheckCulling()
	{
		return true;
	}
	
	
	@Override public   void OnRender()
	{
		super.OnRender();
		if (( this.m_mesh == null )) 
		{
			return ;
		}
		
		haxor.graphics.Graphics.Render(this.m_mesh, this.m_material, this.m_entity.m_transform, haxor.component.Camera.m_current);
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161088 = true;
			switch (field.hashCode())
			{
				case -1083307393:
				{
					if (field.equals("m_mesh")) 
					{
						__temp_executeDef161088 = false;
						this.m_mesh = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef161088 = false;
						this.set_mesh(((haxor.graphics.mesh.Mesh) (value) ));
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161088) 
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
			boolean __temp_executeDef161089 = true;
			switch (field.hashCode())
			{
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef161089 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef161089 = false;
						return this.get_mesh();
					}
					
					break;
				}
				
				
				case 1224889128:
				{
					if (field.equals("CheckCulling")) 
					{
						__temp_executeDef161089 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CheckCulling"))) );
					}
					
					break;
				}
				
				
				case 1976460598:
				{
					if (field.equals("get_mesh")) 
					{
						__temp_executeDef161089 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_mesh"))) );
					}
					
					break;
				}
				
				
				case 1890932680:
				{
					if (field.equals("IsVisible")) 
					{
						__temp_executeDef161089 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("IsVisible"))) );
					}
					
					break;
				}
				
				
				case 1415348138:
				{
					if (field.equals("set_mesh")) 
					{
						__temp_executeDef161089 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_mesh"))) );
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef161089 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
				case -1083307393:
				{
					if (field.equals("m_mesh")) 
					{
						__temp_executeDef161089 = false;
						return this.m_mesh;
					}
					
					break;
				}
				
				
				case 543256713:
				{
					if (field.equals("get_visible")) 
					{
						__temp_executeDef161089 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_visible"))) );
					}
					
					break;
				}
				
				
				case 466743410:
				{
					if (field.equals("visible")) 
					{
						__temp_executeDef161089 = false;
						return this.get_visible();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161089) 
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
			int __temp_hash161091 = field.hashCode();
			boolean __temp_executeDef161090 = true;
			switch (__temp_hash161091)
			{
				case 1528462453:case 312095663:
				{
					if (( (( ( __temp_hash161091 == 1528462453 ) && field.equals("OnRender") )) || field.equals("OnBuild") )) 
					{
						__temp_executeDef161090 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1976460598:
				{
					if (field.equals("get_mesh")) 
					{
						__temp_executeDef161090 = false;
						return this.get_mesh();
					}
					
					break;
				}
				
				
				case 1224889128:
				{
					if (field.equals("CheckCulling")) 
					{
						__temp_executeDef161090 = false;
						return this.CheckCulling();
					}
					
					break;
				}
				
				
				case 1415348138:
				{
					if (field.equals("set_mesh")) 
					{
						__temp_executeDef161090 = false;
						return this.set_mesh(((haxor.graphics.mesh.Mesh) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1890932680:
				{
					if (field.equals("IsVisible")) 
					{
						__temp_executeDef161090 = false;
						return this.IsVisible(((haxor.component.Camera) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 543256713:
				{
					if (field.equals("get_visible")) 
					{
						__temp_executeDef161090 = false;
						return this.get_visible();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161090) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("visible");
		baseArr.push("m_mesh");
		baseArr.push("mesh");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


