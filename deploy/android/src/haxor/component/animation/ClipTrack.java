package haxor.component.animation;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ClipTrack extends haxe.lang.HxObject
{
	public    ClipTrack(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ClipTrack()
	{
		haxor.component.animation.ClipTrack.__hx_ctor_haxor_component_animation_ClipTrack(this);
	}
	
	
	public static   void __hx_ctor_haxor_component_animation_ClipTrack(haxor.component.animation.ClipTrack __temp_me59)
	{
		__temp_me59.target = null;
		__temp_me59.keyframes = new haxe.root.Array<haxor.component.animation.KeyFrame>(new haxor.component.animation.KeyFrame[]{});
		__temp_me59.property = "";
		__temp_me59.m_head = 0;
		__temp_me59.m_length = ((double) (0) );
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.animation.ClipTrack(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.animation.ClipTrack();
	}
	
	
	public  java.lang.Object target;
	
	public  java.lang.String property;
	
	public  haxe.root.Array<haxor.component.animation.KeyFrame> keyframes;
	
	
	
	public   double get_length()
	{
		return this.m_length;
	}
	
	
	public  double m_length;
	
	public  int m_head;
	
	public   haxor.component.animation.KeyFrame Add(double p_time, java.lang.Object p_value)
	{
		haxor.component.animation.KeyFrame k = null;
		if (haxe.lang.Runtime.isDouble(p_value)) 
		{
			haxor.component.animation.FloatKeyFrame nk = ((haxor.component.animation.FloatKeyFrame) (k = new haxor.component.animation.FloatKeyFrame()) );
			nk.time = p_time;
			nk.value = ((double) (haxe.lang.Runtime.toDouble(p_value)) );
		}
		 else 
		{
			if (( p_value instanceof haxor.math.Vector3 )) 
			{
				haxor.component.animation.Vector3KeyFrame nk1 = ((haxor.component.animation.Vector3KeyFrame) (k = new haxor.component.animation.Vector3KeyFrame()) );
				nk1.time = p_time;
				nk1.value = ((haxor.math.Vector3) (p_value) );
			}
			 else 
			{
				if (( p_value instanceof haxor.math.Quaternion )) 
				{
					haxor.component.animation.QuaternionKeyFrame nk2 = ((haxor.component.animation.QuaternionKeyFrame) (k = new haxor.component.animation.QuaternionKeyFrame()) );
					nk2.time = p_time;
					nk2.value = ((haxor.math.Quaternion) (p_value) );
				}
				
			}
			
		}
		
		if (( k != null )) 
		{
			this.keyframes.push(k);
			this.m_length = java.lang.Math.max(k.time, this.m_length);
		}
		
		return k;
	}
	
	
	public   int Sample(double p_time, java.lang.Object p_weight)
	{
		double __temp_p_weight58 = ( (( p_weight == null )) ? (((double) (1.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_weight)) )) );
		if (( this.keyframes.length <= 0 )) 
		{
			return 0;
		}
		
		if (( this.keyframes.length <= 1 )) 
		{
			haxe.root.Reflect.setProperty(this.target, this.property, this.keyframes.__get(0).Sample(null, null));
			return 0;
		}
		
		int mid = ( this.keyframes.length / 2 );
		int step = ( this.keyframes.length / 2 );
		int i0 = -1;
		{
			int _g1 = 0;
			int _g = this.keyframes.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				{
					int p_max = ( this.keyframes.length - 1 );
					i0 = ((int) (( (( mid <= 0 )) ? (((double) (0) )) : (( (( mid >= p_max )) ? (((double) (p_max) )) : (((double) (mid) )) )) )) );
				}
				
				int i1 = 0;
				{
					int p_v = ( mid + 1 );
					int p_max1 = ( this.keyframes.length - 1 );
					i1 = ((int) (( (( p_v <= 0 )) ? (((double) (0) )) : (( (( p_v >= p_max1 )) ? (((double) (p_max1) )) : (((double) (p_v) )) )) )) );
				}
				
				haxor.component.animation.KeyFrame k0 = this.keyframes.__get(i0);
				haxor.component.animation.KeyFrame k1 = this.keyframes.__get(i1);
				if (( p_time < k0.time )) 
				{
					step = ( step / 2 );
					mid -= step;
					continue;
				}
				
				if (( p_time > k1.time )) 
				{
					step = ( step / 2 );
					mid += step;
					continue;
				}
				
				double dt = ( k1.time - k0.time );
				double r = 0.0;
				if (( dt <= 0 )) 
				{
					r = 0.0;
				}
				 else 
				{
					r = ( (( p_time - k0.time )) / dt );
				}
				
				if (( r <= 0.0 )) 
				{
					r = 0.0;
				}
				 else 
				{
					if (( r >= 1.0 )) 
					{
						r = 1.0;
					}
					 else 
					{
						r = r;
					}
					
				}
				
				haxor.component.animation.KeyFrame nk = k0.Blend(k1, r);
				if (nk.changed) 
				{
					java.lang.Object v = haxe.root.Reflect.getProperty(this.target, this.property);
					haxe.root.Reflect.setProperty(this.target, this.property, nk.Sample(v, __temp_p_weight58));
				}
				
				break;
			}
			
		}
		
		return i0;
	}
	
	
	public   haxor.component.animation.ClipTrack Split(int p_start, int p_end)
	{
		haxor.component.animation.ClipTrack nct = new haxor.component.animation.ClipTrack();
		nct.target = this.target;
		nct.property = this.property;
		int i0 = ((int) (java.lang.Math.min(((double) (p_start) ), ((double) (( this.keyframes.length - 1 )) ))) );
		int i1 = ((int) (java.lang.Math.min(((double) (p_end) ), ((double) (( this.keyframes.length - 1 )) ))) );
		haxor.component.animation.KeyFrame kf = this.keyframes.__get(i0);
		if (( kf == null )) 
		{
			return nct;
		}
		
		double t0 = kf.time;
		{
			int _g = i0;
			while (( _g < i1 ))
			{
				int i = _g++;
				kf = this.keyframes.__get(i);
				if (( kf != null )) 
				{
					nct.Add(( kf.time - t0 ), kf.Sample(null, null));
				}
				
			}
			
		}
		
		return nct;
	}
	
	
	public   void Clear()
	{
		this.keyframes = new haxe.root.Array<haxor.component.animation.KeyFrame>(new haxor.component.animation.KeyFrame[]{});
		this.m_length = ((double) (0) );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef699 = true;
			switch (field.hashCode())
			{
				case -1083456910:
				{
					if (field.equals("m_head")) 
					{
						__temp_executeDef699 = false;
						this.m_head = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef699 = false;
						this.target = ((java.lang.Object) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef699 = false;
						this.m_length = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef699) 
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
			boolean __temp_executeDef700 = true;
			switch (field.hashCode())
			{
				case -1083456910:
				{
					if (field.equals("m_head")) 
					{
						__temp_executeDef700 = false;
						this.m_head = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef700 = false;
						this.target = ((java.lang.Object) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef700 = false;
						this.m_length = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -993141291:
				{
					if (field.equals("property")) 
					{
						__temp_executeDef700 = false;
						this.property = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -1446666299:
				{
					if (field.equals("keyframes")) 
					{
						__temp_executeDef700 = false;
						this.keyframes = ((haxe.root.Array<haxor.component.animation.KeyFrame>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef700) 
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
			boolean __temp_executeDef701 = true;
			switch (field.hashCode())
			{
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef701 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef701 = false;
						return this.target;
					}
					
					break;
				}
				
				
				case 80095994:
				{
					if (field.equals("Split")) 
					{
						__temp_executeDef701 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Split"))) );
					}
					
					break;
				}
				
				
				case -993141291:
				{
					if (field.equals("property")) 
					{
						__temp_executeDef701 = false;
						return this.property;
					}
					
					break;
				}
				
				
				case -1825807926:
				{
					if (field.equals("Sample")) 
					{
						__temp_executeDef701 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Sample"))) );
					}
					
					break;
				}
				
				
				case -1446666299:
				{
					if (field.equals("keyframes")) 
					{
						__temp_executeDef701 = false;
						return this.keyframes;
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef701 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef701 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case -1083456910:
				{
					if (field.equals("m_head")) 
					{
						__temp_executeDef701 = false;
						return this.m_head;
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef701 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef701 = false;
						return this.m_length;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef701) 
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
			boolean __temp_executeDef702 = true;
			switch (field.hashCode())
			{
				case -1083456910:
				{
					if (field.equals("m_head")) 
					{
						__temp_executeDef702 = false;
						return ((double) (this.m_head) );
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef702 = false;
						return ((double) (haxe.lang.Runtime.toDouble(this.target)) );
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef702 = false;
						return this.m_length;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef702 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef702) 
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
			boolean __temp_executeDef703 = true;
			switch (field.hashCode())
			{
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef703 = false;
						this.Clear();
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef703 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case 80095994:
				{
					if (field.equals("Split")) 
					{
						__temp_executeDef703 = false;
						return this.Split(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef703 = false;
						return this.Add(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case -1825807926:
				{
					if (field.equals("Sample")) 
					{
						__temp_executeDef703 = false;
						return this.Sample(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef703) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_head");
		baseArr.push("m_length");
		baseArr.push("length");
		baseArr.push("keyframes");
		baseArr.push("property");
		baseArr.push("target");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


