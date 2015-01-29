package haxor.component.animation;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Animation extends haxor.component.Behaviour
{
	public    Animation(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Animation()
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.animation.Animation.__hx_ctor_haxor_component_animation_Animation(this);
	}
	
	
	public static   void __hx_ctor_haxor_component_animation_Animation(haxor.component.animation.Animation __temp_me51)
	{
		haxor.component.Behaviour.__hx_ctor_haxor_component_Behaviour(__temp_me51, null);
		haxor.component.animation.Animation.m_list.push(__temp_me51);
		__temp_me51.clips = new haxe.root.Array<haxor.component.animation.AnimationClip>(new haxor.component.animation.AnimationClip[]{});
		__temp_me51.m_time = ((double) (0) );
		__temp_me51.reverse = false;
		__temp_me51.m_clock = haxor.core.Time.m_elapsed;
		__temp_me51.m_fade_elapsed = 0.0;
		__temp_me51.m_fade_duration = 0.0;
	}
	
	
	public static  haxe.root.Array<haxor.component.animation.Animation> m_list;
	
	public static  int m_iterator;
	
	public static   void Update()
	{
		if (( haxor.component.animation.Animation.m_list.length > 0 )) 
		{
			int steps = 0;
			{
				double x = java.lang.Math.max(( ((double) (haxor.component.animation.Animation.m_list.length) ) / 2 ), ((double) (1) ));
				steps = ((int) (x) );
			}
			
			{
				int _g = 0;
				while (( _g < steps ))
				{
					int i = _g++;
					haxor.component.animation.Animation.m_list.__get(haxor.component.animation.Animation.m_iterator).Animate();
					haxor.component.animation.Animation.m_iterator = ( (( haxor.component.animation.Animation.m_iterator + 1 )) % haxor.component.animation.Animation.m_list.length );
				}
				
			}
			
		}
		
	}
	
	
	public static   void Initialize()
	{
		haxor.component.animation.Animation.m_list = new haxe.root.Array<haxor.component.animation.Animation>(new haxor.component.animation.Animation[]{});
		haxor.component.animation.Animation.m_iterator = 0;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.animation.Animation(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.animation.Animation();
	}
	
	
	public  haxe.root.Array<haxor.component.animation.AnimationClip> clips;
	
	public  double m_clock;
	
	
	
	public   double get_time()
	{
		return this.m_time;
	}
	
	
	public   double set_time(double v)
	{
		this.m_time = v;
		{
			int _g1 = 0;
			int _g = this.clips.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				this.clips.__get(i).Sample(this.m_time, null);
			}
			
		}
		
		return v;
	}
	
	
	public  double m_time;
	
	
	
	public   boolean get_playing()
	{
		{
			int _g1 = 0;
			int _g = this.clips.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (this.clips.__get(i).playing) 
				{
					return true;
				}
				
			}
			
		}
		
		return false;
	}
	
	
	public  boolean reverse;
	
	public  double m_fade_elapsed;
	
	public  double m_fade_duration;
	
	public  haxor.component.animation.AnimationClip m_fade_clip;
	
	public   boolean Contains(haxor.component.animation.AnimationClip p_clip)
	{
		{
			int _g1 = 0;
			int _g = this.clips.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (( this.clips.__get(i) == p_clip )) 
				{
					return true;
				}
				
			}
			
		}
		
		return false;
	}
	
	
	public   void Add(haxor.component.animation.AnimationClip p_clip)
	{
		if (this.Contains(p_clip)) 
		{
			return ;
		}
		
		this.clips.push(p_clip);
	}
	
	
	public   void Remove(haxor.component.animation.AnimationClip p_clip)
	{
		if ( ! (this.Contains(p_clip)) ) 
		{
			return ;
		}
		
		this.clips.remove(p_clip);
	}
	
	
	public   haxor.component.animation.AnimationClip Get(java.lang.String p_clip_name)
	{
		{
			int _g1 = 0;
			int _g = this.clips.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(this.clips.__get(i).get_name(), p_clip_name)) 
				{
					return this.clips.__get(i);
				}
				
			}
			
		}
		
		return null;
	}
	
	
	public   void Fade(haxor.component.animation.AnimationClip p_clip, java.lang.Object p_time, java.lang.Object p_fade)
	{
		double __temp_p_fade49 = ( (( p_fade == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_fade)) )) );
		double __temp_p_time48 = ( (( p_time == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_time)) )) );
		this.Play(p_clip, __temp_p_time48);
		this.m_fade_elapsed = 0.0;
		this.m_fade_duration = __temp_p_fade49;
		this.m_fade_clip = p_clip;
	}
	
	
	public   void Play(haxor.component.animation.AnimationClip p_clip, java.lang.Object p_time)
	{
		double __temp_p_time50 = ( (( p_time == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_time)) )) );
		if ( ! (this.Contains(p_clip)) ) 
		{
			return ;
		}
		
		this.m_time = __temp_p_time50;
		p_clip.Sample(__temp_p_time50, null);
		p_clip.playing = true;
	}
	
	
	public   void Stop(haxor.component.animation.AnimationClip p_clip)
	{
		if (( p_clip == null )) 
		{
			{
				int _g1 = 0;
				int _g = this.clips.length;
				while (( _g1 < _g ))
				{
					int i = _g1++;
					this.clips.__get(i).playing = false;
				}
				
			}
			
			return ;
		}
		
		if ( ! (this.Contains(p_clip)) ) 
		{
			return ;
		}
		
		p_clip.playing = false;
	}
	
	
	public   void Animate()
	{
		boolean is_playing = false;
		if (( this.m_fade_elapsed >= this.m_fade_duration )) 
		{
			this.m_fade_elapsed = this.m_fade_duration;
		}
		
		double w = 0.0;
		if (( this.m_fade_duration <= 0.0 )) 
		{
			w = 1.0;
		}
		 else 
		{
			w = ( this.m_fade_elapsed / this.m_fade_duration );
		}
		
		double spd = 1.0;
		{
			int _g1 = 0;
			int _g = this.clips.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.component.animation.AnimationClip c = this.clips.__get(i);
				if (c.playing) 
				{
					c.Sample(this.get_time(), w);
					spd = c.speed;
					is_playing = true;
				}
				
			}
			
		}
		
		if (( w >= 1.0 )) 
		{
			this.m_fade_clip = null;
			this.m_fade_duration = this.m_fade_elapsed = 0.0;
		}
		
		double dt = ( haxor.core.Time.m_elapsed - this.m_clock );
		this.m_clock = haxor.core.Time.m_elapsed;
		if (is_playing) 
		{
			this.m_time += ( (( (this.reverse) ? ( - (dt) ) : (dt) )) * spd );
			this.m_fade_elapsed += dt;
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef683 = true;
			switch (field.hashCode())
			{
				case 523715493:
				{
					if (field.equals("m_fade_duration")) 
					{
						__temp_executeDef683 = false;
						this.m_fade_duration = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 768178620:
				{
					if (field.equals("m_clock")) 
					{
						__temp_executeDef683 = false;
						this.m_clock = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1047123275:
				{
					if (field.equals("m_fade_elapsed")) 
					{
						__temp_executeDef683 = false;
						this.m_fade_elapsed = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3560141:
				{
					if (field.equals("time")) 
					{
						__temp_executeDef683 = false;
						this.set_time(value);
						return value;
					}
					
					break;
				}
				
				
				case -1083095201:
				{
					if (field.equals("m_time")) 
					{
						__temp_executeDef683 = false;
						this.m_time = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef683) 
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
			boolean __temp_executeDef684 = true;
			switch (field.hashCode())
			{
				case -672577055:
				{
					if (field.equals("m_fade_clip")) 
					{
						__temp_executeDef684 = false;
						this.m_fade_clip = ((haxor.component.animation.AnimationClip) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 94750499:
				{
					if (field.equals("clips")) 
					{
						__temp_executeDef684 = false;
						this.clips = ((haxe.root.Array<haxor.component.animation.AnimationClip>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 523715493:
				{
					if (field.equals("m_fade_duration")) 
					{
						__temp_executeDef684 = false;
						this.m_fade_duration = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 768178620:
				{
					if (field.equals("m_clock")) 
					{
						__temp_executeDef684 = false;
						this.m_clock = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 1047123275:
				{
					if (field.equals("m_fade_elapsed")) 
					{
						__temp_executeDef684 = false;
						this.m_fade_elapsed = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3560141:
				{
					if (field.equals("time")) 
					{
						__temp_executeDef684 = false;
						this.set_time(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 1099846370:
				{
					if (field.equals("reverse")) 
					{
						__temp_executeDef684 = false;
						this.reverse = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1083095201:
				{
					if (field.equals("m_time")) 
					{
						__temp_executeDef684 = false;
						this.m_time = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef684) 
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
			boolean __temp_executeDef685 = true;
			switch (field.hashCode())
			{
				case 807717569:
				{
					if (field.equals("Animate")) 
					{
						__temp_executeDef685 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Animate"))) );
					}
					
					break;
				}
				
				
				case 94750499:
				{
					if (field.equals("clips")) 
					{
						__temp_executeDef685 = false;
						return this.clips;
					}
					
					break;
				}
				
				
				case 2587682:
				{
					if (field.equals("Stop")) 
					{
						__temp_executeDef685 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Stop"))) );
					}
					
					break;
				}
				
				
				case 768178620:
				{
					if (field.equals("m_clock")) 
					{
						__temp_executeDef685 = false;
						return this.m_clock;
					}
					
					break;
				}
				
				
				case 2490196:
				{
					if (field.equals("Play")) 
					{
						__temp_executeDef685 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Play"))) );
					}
					
					break;
				}
				
				
				case 3560141:
				{
					if (field.equals("time")) 
					{
						__temp_executeDef685 = false;
						return this.get_time();
					}
					
					break;
				}
				
				
				case 2181788:
				{
					if (field.equals("Fade")) 
					{
						__temp_executeDef685 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Fade"))) );
					}
					
					break;
				}
				
				
				case 1976672790:
				{
					if (field.equals("get_time")) 
					{
						__temp_executeDef685 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_time"))) );
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef685 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Get"))) );
					}
					
					break;
				}
				
				
				case 1415560330:
				{
					if (field.equals("set_time")) 
					{
						__temp_executeDef685 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_time"))) );
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef685 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Remove"))) );
					}
					
					break;
				}
				
				
				case -1083095201:
				{
					if (field.equals("m_time")) 
					{
						__temp_executeDef685 = false;
						return this.m_time;
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef685 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case -493563858:
				{
					if (field.equals("playing")) 
					{
						__temp_executeDef685 = false;
						return this.get_playing();
					}
					
					break;
				}
				
				
				case -502801857:
				{
					if (field.equals("Contains")) 
					{
						__temp_executeDef685 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Contains"))) );
					}
					
					break;
				}
				
				
				case -417050555:
				{
					if (field.equals("get_playing")) 
					{
						__temp_executeDef685 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_playing"))) );
					}
					
					break;
				}
				
				
				case -672577055:
				{
					if (field.equals("m_fade_clip")) 
					{
						__temp_executeDef685 = false;
						return this.m_fade_clip;
					}
					
					break;
				}
				
				
				case 1099846370:
				{
					if (field.equals("reverse")) 
					{
						__temp_executeDef685 = false;
						return this.reverse;
					}
					
					break;
				}
				
				
				case 523715493:
				{
					if (field.equals("m_fade_duration")) 
					{
						__temp_executeDef685 = false;
						return this.m_fade_duration;
					}
					
					break;
				}
				
				
				case 1047123275:
				{
					if (field.equals("m_fade_elapsed")) 
					{
						__temp_executeDef685 = false;
						return this.m_fade_elapsed;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef685) 
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
			boolean __temp_executeDef686 = true;
			switch (field.hashCode())
			{
				case 523715493:
				{
					if (field.equals("m_fade_duration")) 
					{
						__temp_executeDef686 = false;
						return this.m_fade_duration;
					}
					
					break;
				}
				
				
				case 768178620:
				{
					if (field.equals("m_clock")) 
					{
						__temp_executeDef686 = false;
						return this.m_clock;
					}
					
					break;
				}
				
				
				case 1047123275:
				{
					if (field.equals("m_fade_elapsed")) 
					{
						__temp_executeDef686 = false;
						return this.m_fade_elapsed;
					}
					
					break;
				}
				
				
				case 3560141:
				{
					if (field.equals("time")) 
					{
						__temp_executeDef686 = false;
						return this.get_time();
					}
					
					break;
				}
				
				
				case -1083095201:
				{
					if (field.equals("m_time")) 
					{
						__temp_executeDef686 = false;
						return this.m_time;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef686) 
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
			boolean __temp_executeDef687 = true;
			switch (field.hashCode())
			{
				case 807717569:
				{
					if (field.equals("Animate")) 
					{
						__temp_executeDef687 = false;
						this.Animate();
					}
					
					break;
				}
				
				
				case 1976672790:
				{
					if (field.equals("get_time")) 
					{
						__temp_executeDef687 = false;
						return this.get_time();
					}
					
					break;
				}
				
				
				case 2587682:
				{
					if (field.equals("Stop")) 
					{
						__temp_executeDef687 = false;
						this.Stop(((haxor.component.animation.AnimationClip) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1415560330:
				{
					if (field.equals("set_time")) 
					{
						__temp_executeDef687 = false;
						return this.set_time(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 2490196:
				{
					if (field.equals("Play")) 
					{
						__temp_executeDef687 = false;
						this.Play(((haxor.component.animation.AnimationClip) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case -417050555:
				{
					if (field.equals("get_playing")) 
					{
						__temp_executeDef687 = false;
						return this.get_playing();
					}
					
					break;
				}
				
				
				case 2181788:
				{
					if (field.equals("Fade")) 
					{
						__temp_executeDef687 = false;
						this.Fade(((haxor.component.animation.AnimationClip) (dynargs.__get(0)) ), dynargs.__get(1), dynargs.__get(2));
					}
					
					break;
				}
				
				
				case -502801857:
				{
					if (field.equals("Contains")) 
					{
						__temp_executeDef687 = false;
						return this.Contains(((haxor.component.animation.AnimationClip) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef687 = false;
						return this.Get(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef687 = false;
						this.Add(((haxor.component.animation.AnimationClip) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef687 = false;
						this.Remove(((haxor.component.animation.AnimationClip) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef687) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_fade_clip");
		baseArr.push("m_fade_duration");
		baseArr.push("m_fade_elapsed");
		baseArr.push("reverse");
		baseArr.push("playing");
		baseArr.push("m_time");
		baseArr.push("time");
		baseArr.push("m_clock");
		baseArr.push("clips");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


