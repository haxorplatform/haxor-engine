package haxor.component.animation;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Vector3KeyFrame extends haxor.component.animation.KeyFrame
{
	static 
	{
		haxor.component.animation.Vector3KeyFrame.m_temp = new haxor.component.animation.Vector3KeyFrame();
	}
	public    Vector3KeyFrame(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Vector3KeyFrame()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.component.animation.Vector3KeyFrame.__hx_ctor_haxor_component_animation_Vector3KeyFrame(this);
	}
	
	
	public static   void __hx_ctor_haxor_component_animation_Vector3KeyFrame(haxor.component.animation.Vector3KeyFrame __temp_me73)
	{
		haxor.component.animation.KeyFrame.__hx_ctor_haxor_component_animation_KeyFrame(__temp_me73);
		__temp_me73.value = new haxor.math.Vector3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
	}
	
	
	public static  haxor.component.animation.Vector3KeyFrame m_temp;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.animation.Vector3KeyFrame(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.animation.Vector3KeyFrame();
	}
	
	
	public  haxor.math.Vector3 value;
	
	@Override public   haxor.component.animation.KeyFrame Blend(haxor.component.animation.KeyFrame b, double r)
	{
		this.changed = false;
		haxor.component.animation.Vector3KeyFrame ka = this;
		haxor.component.animation.Vector3KeyFrame kb = ((haxor.component.animation.Vector3KeyFrame) (b) );
		haxor.math.Vector3 va = ka.value;
		haxor.math.Vector3 vb = kb.value;
		if (( java.lang.Math.abs(( va.x - vb.x )) < 0.0001 )) 
		{
			if (( java.lang.Math.abs(( va.y - vb.y )) < 0.0001 )) 
			{
				if (( java.lang.Math.abs(( va.z - vb.z )) < 0.0001 )) 
				{
					return ka;
				}
				
			}
			
		}
		
		haxor.component.animation.Vector3KeyFrame k = haxor.component.animation.Vector3KeyFrame.m_temp;
		k.value = haxor.math.Vector3.Lerp(va, vb, r, k.value);
		k.changed = true;
		return k;
	}
	
	
	@Override public   java.lang.Object Sample(java.lang.Object v, java.lang.Object w)
	{
		double __temp_w72 = ( (( w == null )) ? (((double) (1.0) )) : (((double) (haxe.lang.Runtime.toDouble(w)) )) );
		if (( v == null )) 
		{
			return this.value;
		}
		 else 
		{
			haxor.math.Vector3 __temp_stmt724 = null;
			{
				haxor.context.DataContext _this = haxor.context.EngineContext.data;
				__temp_stmt724 = _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
			}
			
			return haxor.math.Vector3.Lerp(((haxor.math.Vector3) (v) ), this.value, __temp_w72, __temp_stmt724);
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef725 = true;
			switch (field.hashCode())
			{
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef725 = false;
						this.value = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef725) 
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
			boolean __temp_executeDef726 = true;
			switch (field.hashCode())
			{
				case -1825807926:
				{
					if (field.equals("Sample")) 
					{
						__temp_executeDef726 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Sample"))) );
					}
					
					break;
				}
				
				
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef726 = false;
						return this.value;
					}
					
					break;
				}
				
				
				case 64270385:
				{
					if (field.equals("Blend")) 
					{
						__temp_executeDef726 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Blend"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef726) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("value");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


