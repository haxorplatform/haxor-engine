package haxor.component.animation;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class QuaternionKeyFrame extends haxor.component.animation.KeyFrame
{
	static 
	{
		haxor.component.animation.QuaternionKeyFrame.m_temp = new haxor.component.animation.QuaternionKeyFrame();
	}
	public    QuaternionKeyFrame(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    QuaternionKeyFrame()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.component.animation.QuaternionKeyFrame.__hx_ctor_haxor_component_animation_QuaternionKeyFrame(this);
	}
	
	
	public static   void __hx_ctor_haxor_component_animation_QuaternionKeyFrame(haxor.component.animation.QuaternionKeyFrame __temp_me86)
	{
		haxor.component.animation.KeyFrame.__hx_ctor_haxor_component_animation_KeyFrame(__temp_me86);
		__temp_me86.value = new haxor.math.Quaternion(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1.0) ));
	}
	
	
	public static  haxor.component.animation.QuaternionKeyFrame m_temp;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.animation.QuaternionKeyFrame(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.animation.QuaternionKeyFrame();
	}
	
	
	public  haxor.math.Quaternion value;
	
	@Override public   haxor.component.animation.KeyFrame Blend(haxor.component.animation.KeyFrame b, double r)
	{
		this.changed = true;
		haxor.component.animation.QuaternionKeyFrame ka = this;
		haxor.component.animation.QuaternionKeyFrame kb = ((haxor.component.animation.QuaternionKeyFrame) (b) );
		haxor.math.Quaternion va = ka.value;
		haxor.math.Quaternion vb = kb.value;
		if (( java.lang.Math.abs(( va.x - vb.x )) < 0.0001 )) 
		{
			if (( java.lang.Math.abs(( va.y - vb.y )) < 0.0001 )) 
			{
				if (( java.lang.Math.abs(( va.z - vb.z )) < 0.0001 )) 
				{
					if (( java.lang.Math.abs(( va.w - vb.w )) < 0.0001 )) 
					{
						return ka;
					}
					
				}
				
			}
			
		}
		
		haxor.component.animation.QuaternionKeyFrame k = haxor.component.animation.QuaternionKeyFrame.m_temp;
		k.value = haxor.math.Quaternion.Lerp(va, vb, r, k.value);
		k.changed = true;
		return k;
	}
	
	
	@Override public   java.lang.Object Sample(java.lang.Object v, java.lang.Object w)
	{
		double __temp_w85 = ( (( w == null )) ? (((double) (1.0) )) : (((double) (haxe.lang.Runtime.toDouble(w)) )) );
		if (( v == null )) 
		{
			return this.value;
		}
		 else 
		{
			haxor.math.Quaternion __temp_stmt760 = null;
			{
				haxor.context.DataContext _this = haxor.context.EngineContext.data;
				__temp_stmt760 = _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
			}
			
			return haxor.math.Quaternion.Lerp(((haxor.math.Quaternion) (v) ), this.value, __temp_w85, __temp_stmt760);
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef761 = true;
			switch (field.hashCode())
			{
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef761 = false;
						this.value = ((haxor.math.Quaternion) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef761) 
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
			boolean __temp_executeDef762 = true;
			switch (field.hashCode())
			{
				case -1825807926:
				{
					if (field.equals("Sample")) 
					{
						__temp_executeDef762 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Sample"))) );
					}
					
					break;
				}
				
				
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef762 = false;
						return this.value;
					}
					
					break;
				}
				
				
				case 64270385:
				{
					if (field.equals("Blend")) 
					{
						__temp_executeDef762 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Blend"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef762) 
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


