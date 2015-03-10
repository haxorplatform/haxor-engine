package haxor.core;
import haxe.ds.ObjectMap;
import haxor.context.EngineContext;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Quaternion;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.math.Vector4;

/**
 * Class that implements a time based property interpolator.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Tween extends Resource implements IUpdateable
{
	static private var m_table : ObjectMap<Dynamic, Array<Tween> >;
	
	/**
	 * Adds a new tween to the execution queue.
	 * @param	p_target
	 * @param	p_property
	 * @param	p_value
	 * @param	p_duration
	 * @param	p_delay
	 * @param	p_easing
	 * @return
	 */
	static public function Add(p_target : Dynamic, p_property : String, p_value : Dynamic, p_duration : Float = 0.3, p_delay:Float = 0, p_easing : Float -> Float = null) : Tween
	{
		var t : Tween = new Tween(p_target, p_property, p_value, p_duration, p_delay, p_easing);
		t.Run();
		return t;
	}
	
	/**
	 * Kills an executing tween.
	 * @param	p_target
	 * @param	p_property
	 */
	static public function Cancel(p_target : Dynamic, p_property : String = ""):Void
	{
		if (!m_table.exists(p_target)) return;
		var il : Array<Tween> = m_table.get(p_target);
		for (i in 0...il.length)
		{
			var t : Tween = il[i];			
			if (p_property != "") if (t.m_property != p_property) { continue; }
			t.Remove();			
		}			
	}
	
	/**
	 * Returns an array of executing tweens.
	 * @param	p_target
	 * @param	p_property
	 * @param	p_active_only
	 * @return
	 */
	static public function GetTweens(p_target : Dynamic=null, p_property : String="",p_active_only:Bool=false):Array<Tween>
	{
		var l : Array<Tween> = [];
		if (p_target == null)
		{			
			var it : Iterator< Array<Tween> > = m_table.iterator();
			while (it.hasNext())
			{
				var il : Array<Tween> = it.next();
				for (i in 0...il.length) l.push(il[i]);
			}			
		}
		else
		{
			if (!m_table.exists(p_target)) return [];
			var il : Array<Tween> = m_table.get(p_target);
			for (i in 0...il.length)
			{
				var t : Tween = il[i];
				if (p_target != null) if (t.m_target != p_target) { continue; }
				if (p_property != "") if (t.m_property != p_property) { continue; }
				if (p_active_only) if (t.m_elapsed < 0) { continue; }
				l.push(t);
			}			
		}
		return l;
	}
	
	private var m_target : Dynamic;
	
	private var m_property : String;
	
	private var m_value : Dynamic;
	
	private var m_start : Dynamic;
	
	private var m_delay : Float;
	
	private var m_duration : Float;
	
	private var m_elapsed : Float;
	
	private var m_active : Bool;
	
	private var m_easing : Float -> Float;
	
	private var m_added : Bool;

	public var oncomplete : Void -> Void;
	
	/**
	 * Creates a new Tween.
	 * @param	p_target
	 * @param	p_property
	 * @param	p_value
	 * @param	p_duration
	 * @param	p_delay
	 * @param	p_easing
	 */
	public function new(p_target : Dynamic,p_property : String,p_value : Dynamic,p_duration : Float=0.3,p_delay:Float=0,p_easing : Float -> Float=null) 
	{
		super();		
		if (m_table == null) m_table = new ObjectMap < Dynamic, Array<Tween> > ();
		m_target   = p_target;
		m_property = p_property;
		m_value    = p_value;
		m_delay    = p_delay;
		m_elapsed  = m_delay > 0 ? -m_delay : 0;
		m_duration = p_duration;		
		m_active   = false;
		m_added    = false;
		m_easing   = p_easing == null ? (function(v:Float):Float { return v; } ) : p_easing;		
		if (!m_table.exists(m_target)) m_table.set(m_target, []);
	}
	
	/**
	 * Starts executing the tween.
	 */
	public function Run():Void
	{				
		m_active  = true;		
		if (!m_added) 
		{			
			EngineContext.update.Add(this);			
			m_added = true; 
			m_table.get(m_target).push(this); 
		}		
	}
	
	/**
	 * Pauses the tween.
	 */
	public function Pause():Void
	{
		m_active = false;
	}
	
	/**
	 * Stops and reset the tween.
	 */
	public function Stop():Void
	{		
		m_elapsed = -m_delay;
		m_active  = false;		
	}
	
	/**
	 * Stops and removes the tween from the execution pool.
	 */
	public function Remove():Void
	{
		if (m_added) { EngineContext.update.Remove(this); m_added = false; }		
		m_active = false;
		var l : Array<Tween> = m_table.get(m_target);
		l.remove(this);
	}
	
	/**
	 * Tween update loop.
	 */
	public function OnUpdate():Void
	{		
		if (!m_active) return;		
		
		if (m_elapsed <= 0) 
		{			
			m_elapsed += Time.delta; 
			if (m_elapsed >= 0)
			{
				var l : Array<Tween> = GetTweens(m_target, m_property, true);
				for (i in 0...l.length) if (l[i] != this) { l[i].Remove(); }				
				m_start = Reflect.getProperty(m_target, m_property);				
			}			
			return; 
		}
		var r : Float = Mathf.Clamp01(m_duration <= 0 ? 1.0 : (m_elapsed / m_duration)); 
		//if(m_property=="alpha")trace("tween: " +  m_value+" "+r);
		Sample(r);
				
		m_elapsed += Time.delta; 
		
		if (m_elapsed >= m_duration)
		{
			Sample(1.0);
			if (oncomplete != null) oncomplete();
			Remove();
		}
	}
	
	private function Sample(p_r : Float):Void
	{
		p_r = m_easing(p_r);		
		if (Std.is(m_value, Float)) 		Reflect.setProperty(m_target, m_property, Mathf.Lerp(m_start, m_value, p_r));  	else 
		if (Std.is(m_value, Color)) 		Reflect.setProperty(m_target,m_property,Color.Lerp(m_start, m_value, p_r)); 		else
		if (Std.is(m_value, Quaternion)) 	Reflect.setProperty(m_target,m_property,Quaternion.Lerp(m_start, m_value, p_r));	else		
		if (Std.is(m_value, Int)) 			Reflect.setProperty(m_target,m_property,Mathf.LerpInt(m_start, m_value, p_r));	else
		if (Std.is(m_value, Vector2)) 		Reflect.setProperty(m_target,m_property,Vector2.Lerp(m_start, m_value, p_r)); 	else
		if (Std.is(m_value, Vector3)) 		Reflect.setProperty(m_target,m_property,Vector3.Lerp(m_start, m_value, p_r));		else
		if (Std.is(m_value, Vector4)) 		Reflect.setProperty(m_target,m_property,Vector4.Lerp(m_start, m_value, p_r));
	}
}