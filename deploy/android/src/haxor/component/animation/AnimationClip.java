package haxor.component.animation;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class AnimationClip extends haxor.core.Resource
{
	public    AnimationClip(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    AnimationClip()
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.animation.AnimationClip.__hx_ctor_haxor_component_animation_AnimationClip(this);
	}
	
	
	public static   void __hx_ctor_haxor_component_animation_AnimationClip(haxor.component.animation.AnimationClip __temp_me55)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me55, null);
		__temp_me55.tracks = new haxe.root.Array<haxor.component.animation.ClipTrack>(new haxor.component.animation.ClipTrack[]{});
		__temp_me55.speed = 1.0;
		__temp_me55.playing = false;
		__temp_me55.m_length = ((double) (0) );
		__temp_me55.wrap = haxor.core.AnimationWrap.Clamp;
		__temp_me55.m_events = new haxe.root.Array<haxor.component.animation.AnimationEvent>(new haxor.component.animation.AnimationEvent[]{});
		__temp_me55.m_last_frame = 0;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.animation.AnimationClip(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.animation.AnimationClip();
	}
	
	
	public  haxe.root.Array<haxor.component.animation.ClipTrack> tracks;
	
	public  double speed;
	
	public  boolean playing;
	
	public  haxor.core.AnimationWrap wrap;
	
	
	
	public   double get_length()
	{
		return this.m_length;
	}
	
	
	public  double m_length;
	
	public  haxe.root.Array<haxor.component.animation.AnimationEvent> m_events;
	
	public  int m_last_frame;
	
	public   void AddEvent(int p_frame, haxe.lang.Function p_listener, java.lang.Object p_repeat, haxe.root.Array p_args)
	{
		int __temp_p_repeat52 = ( (( p_repeat == null )) ? (((int) (0) )) : (((int) (haxe.lang.Runtime.toInt(p_repeat)) )) );
		haxor.component.animation.AnimationEvent e = new haxor.component.animation.AnimationEvent(((int) (p_frame) ), ((haxe.lang.Function) (p_listener) ), ((java.lang.Object) (__temp_p_repeat52) ), ((haxe.root.Array) (p_args) ));
		this.m_events.push(e);
		this.m_events.sort(( (( haxor.component.animation.AnimationClip_AddEvent_71__Fun.__hx_current != null )) ? (haxor.component.animation.AnimationClip_AddEvent_71__Fun.__hx_current) : (haxor.component.animation.AnimationClip_AddEvent_71__Fun.__hx_current = ((haxor.component.animation.AnimationClip_AddEvent_71__Fun) (new haxor.component.animation.AnimationClip_AddEvent_71__Fun()) )) ));
	}
	
	
	public   void RemoveEvent(java.lang.Object p_frame)
	{
		int __temp_p_frame53 = ( (( p_frame == null )) ? (((int) (-1) )) : (((int) (haxe.lang.Runtime.toInt(p_frame)) )) );
		int i = 0;
		while (( i < this.m_events.length ))
		{
			if (( ( this.m_events.__get(i).frame == __temp_p_frame53 ) || ( __temp_p_frame53 < 0 ) )) 
			{
				this.m_events.remove(this.m_events.__get(i--));
			}
			
			i++;
		}
		
	}
	
	
	public   haxor.component.animation.ClipTrack Add(java.lang.Object p_target, java.lang.String p_property)
	{
		haxor.component.animation.ClipTrack ct = new haxor.component.animation.ClipTrack();
		ct.target = p_target;
		ct.property = p_property;
		this.tracks.push(ct);
		this.UpdateLength();
		return ct;
	}
	
	
	public   void Remove(java.lang.Object p_target, java.lang.String p_property)
	{
		if (( p_property == null )) 
		{
			p_property = "";
		}
		
		{
			int _g1 = 0;
			int _g = this.tracks.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.eq(this.tracks.__get(i).target, p_target)) 
				{
					if (haxe.lang.Runtime.valEq(p_property, "")) 
					{
						this.tracks.remove(this.tracks.__get(i));
					}
					 else 
					{
						if (haxe.lang.Runtime.valEq(p_property, p_property)) 
						{
							this.tracks.remove(this.tracks.__get(i));
						}
						
					}
					
				}
				
			}
			
		}
		
		this.UpdateLength();
	}
	
	
	public   void Sample(double p_time, java.lang.Object p_weight)
	{
		double __temp_p_weight54 = ( (( p_weight == null )) ? (((double) (1.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_weight)) )) );
		if ( ! (this.playing) ) 
		{
			return ;
		}
		
		double spd = java.lang.Math.max(((double) (0) ), this.speed);
		double t = p_time;
		{
			haxor.core.AnimationWrap _g = this.wrap;
			switch (haxe.root.Type.enumIndex(_g))
			{
				case 0:
				{
					double a = java.lang.Math.max(t, ((double) (0) ));
					double b = this.get_length();
					t = java.lang.Math.min(a, b);
					break;
				}
				
				
				case 1:
				{
					t = haxor.math.Mathf.Loop(t, ((double) (0) ), this.get_length());
					break;
				}
				
				
				case 2:
				{
					double p_v1 = this.get_length();
					double __temp_stmt688 = 0.0;
					{
						double p_a = haxor.math.Mathf.Loop(( t - 1.0 ), -1.0, 1.0);
						__temp_stmt688 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
					}
					
					double w = (  - (__temp_stmt688)  + 1.0 );
					t = ( w + ( (( 0 - w )) * p_v1 ) );
					break;
				}
				
				
			}
			
		}
		
		int frame = -1;
		{
			int _g1 = 0;
			int _g2 = this.tracks.length;
			while (( _g1 < _g2 ))
			{
				int i = _g1++;
				frame = this.tracks.__get(i).Sample(t, __temp_p_weight54);
			}
			
		}
		
		if (( frame >= 0 )) 
		{
			int i1 = 0;
			if (( this.m_last_frame != frame )) 
			{
				while (( i1 < this.m_events.length ))
				{
					haxor.component.animation.AnimationEvent ev = this.m_events.__get(i1);
					int ef = ev.frame;
					if (( ef >= this.m_last_frame )) 
					{
						if (( ef <= frame )) 
						{
							if ( ! (ev.Dispatch()) ) 
							{
								this.m_events.remove(ev);
								i1--;
							}
							
						}
						
					}
					
					i1++;
				}
				
				this.m_last_frame = frame;
			}
			
		}
		
	}
	
	
	public   haxor.component.animation.AnimationClip Split(int p_start, int p_end)
	{
		haxor.component.animation.AnimationClip nc = new haxor.component.animation.AnimationClip();
		nc.speed = this.speed;
		nc.wrap = this.wrap;
		nc.playing = this.playing;
		{
			int _g1 = 0;
			int _g = this.tracks.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.component.animation.ClipTrack ct = this.tracks.__get(i);
				haxor.component.animation.ClipTrack nct = ct.Split(p_start, p_end);
				nc.tracks.push(nct);
			}
			
		}
		
		nc.UpdateLength();
		return nc;
	}
	
	
	public   void UpdateLength()
	{
		this.m_length = ((double) (0) );
		{
			int _g1 = 0;
			int _g = this.tracks.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				this.m_length = java.lang.Math.max(this.tracks.__get(i).get_length(), this.m_length);
			}
			
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef689 = true;
			switch (field.hashCode())
			{
				case 248812950:
				{
					if (field.equals("m_last_frame")) 
					{
						__temp_executeDef689 = false;
						this.m_last_frame = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 109641799:
				{
					if (field.equals("speed")) 
					{
						__temp_executeDef689 = false;
						this.speed = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef689 = false;
						this.m_length = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef689) 
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
			boolean __temp_executeDef690 = true;
			switch (field.hashCode())
			{
				case 248812950:
				{
					if (field.equals("m_last_frame")) 
					{
						__temp_executeDef690 = false;
						this.m_last_frame = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -865716088:
				{
					if (field.equals("tracks")) 
					{
						__temp_executeDef690 = false;
						this.tracks = ((haxe.root.Array<haxor.component.animation.ClipTrack>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1890059989:
				{
					if (field.equals("m_events")) 
					{
						__temp_executeDef690 = false;
						this.m_events = ((haxe.root.Array<haxor.component.animation.AnimationEvent>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 109641799:
				{
					if (field.equals("speed")) 
					{
						__temp_executeDef690 = false;
						this.speed = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef690 = false;
						this.m_length = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -493563858:
				{
					if (field.equals("playing")) 
					{
						__temp_executeDef690 = false;
						this.playing = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 3657802:
				{
					if (field.equals("wrap")) 
					{
						__temp_executeDef690 = false;
						this.wrap = ((haxor.core.AnimationWrap) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef690) 
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
			boolean __temp_executeDef691 = true;
			switch (field.hashCode())
			{
				case -990299857:
				{
					if (field.equals("UpdateLength")) 
					{
						__temp_executeDef691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateLength"))) );
					}
					
					break;
				}
				
				
				case -865716088:
				{
					if (field.equals("tracks")) 
					{
						__temp_executeDef691 = false;
						return this.tracks;
					}
					
					break;
				}
				
				
				case 80095994:
				{
					if (field.equals("Split")) 
					{
						__temp_executeDef691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Split"))) );
					}
					
					break;
				}
				
				
				case 109641799:
				{
					if (field.equals("speed")) 
					{
						__temp_executeDef691 = false;
						return this.speed;
					}
					
					break;
				}
				
				
				case -1825807926:
				{
					if (field.equals("Sample")) 
					{
						__temp_executeDef691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Sample"))) );
					}
					
					break;
				}
				
				
				case -493563858:
				{
					if (field.equals("playing")) 
					{
						__temp_executeDef691 = false;
						return this.playing;
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Remove"))) );
					}
					
					break;
				}
				
				
				case 3657802:
				{
					if (field.equals("wrap")) 
					{
						__temp_executeDef691 = false;
						return this.wrap;
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef691 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case 1350362198:
				{
					if (field.equals("RemoveEvent")) 
					{
						__temp_executeDef691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("RemoveEvent"))) );
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case -1195136359:
				{
					if (field.equals("AddEvent")) 
					{
						__temp_executeDef691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("AddEvent"))) );
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef691 = false;
						return this.m_length;
					}
					
					break;
				}
				
				
				case 248812950:
				{
					if (field.equals("m_last_frame")) 
					{
						__temp_executeDef691 = false;
						return this.m_last_frame;
					}
					
					break;
				}
				
				
				case -1890059989:
				{
					if (field.equals("m_events")) 
					{
						__temp_executeDef691 = false;
						return this.m_events;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef691) 
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
			boolean __temp_executeDef692 = true;
			switch (field.hashCode())
			{
				case 248812950:
				{
					if (field.equals("m_last_frame")) 
					{
						__temp_executeDef692 = false;
						return ((double) (this.m_last_frame) );
					}
					
					break;
				}
				
				
				case 109641799:
				{
					if (field.equals("speed")) 
					{
						__temp_executeDef692 = false;
						return this.speed;
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef692 = false;
						return this.m_length;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef692 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef692) 
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
			boolean __temp_executeDef693 = true;
			switch (field.hashCode())
			{
				case -990299857:
				{
					if (field.equals("UpdateLength")) 
					{
						__temp_executeDef693 = false;
						this.UpdateLength();
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef693 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case 80095994:
				{
					if (field.equals("Split")) 
					{
						__temp_executeDef693 = false;
						return this.Split(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -1195136359:
				{
					if (field.equals("AddEvent")) 
					{
						__temp_executeDef693 = false;
						this.AddEvent(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxe.lang.Function) (dynargs.__get(1)) ), dynargs.__get(2), ((haxe.root.Array) (dynargs.__get(3)) ));
					}
					
					break;
				}
				
				
				case -1825807926:
				{
					if (field.equals("Sample")) 
					{
						__temp_executeDef693 = false;
						this.Sample(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 1350362198:
				{
					if (field.equals("RemoveEvent")) 
					{
						__temp_executeDef693 = false;
						this.RemoveEvent(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef693 = false;
						this.Remove(dynargs.__get(0), haxe.lang.Runtime.toString(dynargs.__get(1)));
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef693 = false;
						return this.Add(dynargs.__get(0), haxe.lang.Runtime.toString(dynargs.__get(1)));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef693) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_last_frame");
		baseArr.push("m_events");
		baseArr.push("m_length");
		baseArr.push("length");
		baseArr.push("wrap");
		baseArr.push("playing");
		baseArr.push("speed");
		baseArr.push("tracks");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


