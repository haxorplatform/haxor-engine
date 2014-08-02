/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.component;
import js.html.StorageInfo;
import haxor.component.AnimationClip.KeyFrame;
import haxor.core.Console;
import haxor.core.Resource;
import haxor.math.Mathf;
import haxor.math.Quaternion;
import haxor.math.Vector3;

/**
 * 
 */
enum AnimationWrap
{            
	Clamp; 			   
	Loop; 				 	          
	Oscilate;	
}

class AnimationEvent
{
	public var frame : Int;
	
	public var args : Array<Dynamic>;
	
	public var listener : AnimationEvent -> Void;
	
	public var repeat : Int;
	
	
	
	public function new(p_frame : Int, p_listener : AnimationEvent -> Void,p_repeat : Int=0, p_args : Array<Dynamic> = null)
	{
		frame 	 = p_frame;
		listener = p_listener;
		args     = p_args == null ? [] : p_args;
		repeat   = p_repeat;
	}
	
	public function Dispatch():Bool
	{
		if (listener != null)
		{
			listener(this);
			if (repeat <= 0) return true;
			repeat--;
			if (repeat <= 0) return false;			
			return true;
		}
		return false;
	}
}

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class AnimationClip extends Resource
{
	
	public var tracks : Array<ClipTrack>;
	
	public var speed : Float;
	
	public var playing : Bool;
	
	public var wrap : AnimationWrap;
	
	public var length(get_length, never):Float;
	private function get_length():Float { return m_length; }
	private var m_length : Float;
	
	private var m_events : Array<AnimationEvent>;
	
	private var m_last_frame : Int;
	
	public function new() 
	{
		super();
		tracks   = [];
		speed    = 1.0;
		playing  = false;
		m_length = 0;
		wrap     = AnimationWrap.Clamp;
		m_events = [];
		m_last_frame = 0;
		
	}
	
	public function AddEvent(p_frame : Int, p_listener : AnimationEvent -> Void,p_repeat:Int=0, p_args : Array<Dynamic> = null):Void
	{
		var e : AnimationEvent = new AnimationEvent(p_frame, p_listener, p_repeat, p_args);
		m_events.push(e);
		m_events.sort(function(a : AnimationEvent, b : AnimationEvent):Int
		{
			return a.frame < b.frame ? -1 : 1;
		});
	}
	
	public function RemoveEvent(p_frame:Int=-1):Void
	{
		var i : Int = 0;
		while(i < m_events.length)
		{			
			if ((m_events[i].frame == p_frame) || (p_frame < 0)) m_events.remove(m_events[i--]);
			i++;
		}
	}
	
	public function Add(p_target : Dynamic, p_property : String) : ClipTrack
	{
		var ct : ClipTrack = new ClipTrack();
		ct.target 	= p_target;
		ct.property = p_property;		
		
		tracks.push(ct);
		UpdateLength();
		return ct;
	}
	
	public function Remove(p_target : Dynamic, p_property:String = ""):Void
	{
		for (i in 0...tracks.length)
		{
			if (tracks[i].target == p_target)
			{
				if (p_property == "") 			{ tracks.remove(tracks[i]); }
				else
				if (p_property == p_property) 	{ tracks.remove(tracks[i]); }
			}
		}
		UpdateLength();
	}
	
	private function UpdateLength():Void
	{
		m_length = 0;		
		for (i in 0...tracks.length) m_length = Math.max(tracks[i].length, m_length);
	}
	
	public function Sample(p_time : Float,p_weight:Float=1.0):Void
	{		
		if (!playing) return;	
		
		//trace("Clip> " + name + " " + p_time+"/"+length);
		var spd : Float = Math.max(0, speed);
		var t : Float = p_time;// * spd;
		switch(wrap)
		{
			case AnimationWrap.Clamp: 	 t = Math.min(Math.max(t,0), length);
			case AnimationWrap.Loop:  	 t = Mathf.Loop(t, 0, length);
			case AnimationWrap.Oscilate: t = Mathf.Oscilate(t, 0, length);
		}
		
		var frame : Int = -1;
		for (i in 0...tracks.length)
		{
			frame = tracks[i].Sample(t,p_weight);
		}
		
		if (frame >= 0)
		{
			var i : Int = 0;
			if (m_last_frame != frame)
			{
				while(i < m_events.length)
				{
					var ev : AnimationEvent = m_events[i];
					var ef : Int = ev.frame;
					if (ef >= m_last_frame)
					if (ef <= frame)
					{
						if (!ev.Dispatch()) 
						{
							m_events.remove(ev); i--; 
						}
					}
					i++;
				}			
				m_last_frame = frame;
			}
		}
		
	}
	
	public function Split(p_start : Int, p_end : Int):AnimationClip
	{
		var nc : AnimationClip = new AnimationClip();
		nc.speed 	= speed;
		nc.wrap  	= wrap;
		nc.playing  = playing;
		
		for (i in 0...tracks.length)
		{
			var ct : ClipTrack = tracks[i];
			var nct : ClipTrack = ct.Split(p_start, p_end);
			nc.tracks.push(nct);
		}
		nc.UpdateLength();		
		return nc;
	}
	
	
}

class ClipTrack
{
	
	public var target : Dynamic;
	
	public var property : String;
	
	public var keyframes : Array<KeyFrame>;
		
	public var length(get_length, never):Float;
	private function get_length():Float { return m_length; }
	private var m_length : Float;
	
	private var m_head : Int;
	
	public function new()
	{
		target    = null;
		keyframes = [];		
		property  = "";
		m_head 	  = 0;
		m_length  = 0;
	}
	
	public function Add(p_time : Float, p_value : Dynamic):KeyFrame 
	{
		var k : KeyFrame = null;
		if (Std.is(p_value, Float))   	 { var nk : FloatKeyFrame 		= cast (k = new FloatKeyFrame()); 		nk.time = p_time; nk.value = p_value; } else
		if (Std.is(p_value, Vector3)) 	 { var nk : Vector3KeyFrame 	= cast (k = new Vector3KeyFrame()); 	nk.time = p_time; nk.value = p_value; } else
		if (Std.is(p_value, Quaternion)) { var nk : QuaternionKeyFrame  = cast (k = new QuaternionKeyFrame());  nk.time = p_time; nk.value = p_value; }
		
		if (k != null)
		{
			keyframes.push(k);			
			m_length = Math.max(k.time, m_length);			
		}
		
		return k;
	}
	
	public function Sample(p_time : Float,p_weight:Float=1.0):Int
	{
		if (keyframes.length <= 0) return 0;
		if (keyframes.length <= 1) { Reflect.setProperty(target, property, keyframes[0].Sample()); return 0; }
		
		var mid  : Int = Std.int(keyframes.length/2);
		var step : Int = Std.int(keyframes.length/2);
		var i0 : Int = -1;
		//var i0 : Int = m_head;
		//var i1 : Int = Mathf.MinInt([m_head + 1, keyframes.length - 1]);
		for (i in 0...keyframes.length)
		//for (i in 1...keyframes.length)
		{			
			i0 = Mathf.ClampInt(mid,0,keyframes.length-1);
			var i1 : Int = Mathf.ClampInt(mid+1,0,keyframes.length-1);
			var k0 : KeyFrame = keyframes[i0];
			var k1 : KeyFrame = keyframes[i1];
			
			if (p_time < k0.time) {	step = cast (step / 2); mid -= step; continue; }			
			if (p_time > k1.time) {	step = cast (step / 2);	mid += step; continue; }
			
			var dt : Float = (k1.time - k0.time);
			var r : Float  = dt <= 0 ? 0.0 : ((p_time - k0.time) / dt);
			r = Mathf.Clamp01(r);
			var nk : KeyFrame = k0.Blend(k1, r);
			if (nk.changed)
			{
				var v : Dynamic = Reflect.getProperty(target, property);
				Reflect.setProperty(target, property, nk.Sample(v,p_weight));
			}
			break;
		}
		return i0;
	}
	
	public function Split(p_start : Int, p_end : Int):ClipTrack
	{
		var nct : ClipTrack = new ClipTrack();
		nct.target   = target;
		nct.property = property;
		var i0 : Int = Mathf.MinInt([p_start, keyframes.length-1]);
		var i1 : Int = Mathf.MinInt([p_end, keyframes.length - 1]);
		var kf : KeyFrame = keyframes[i0];
		if (kf == null) return nct;
		var t0 : Float = kf.time;
		for (i in i0...i1)
		{			
			kf = keyframes[i];
			if (kf != null)	nct.Add(kf.time-t0,kf.Sample());
		}	
		return nct;
	}
	
	public function Clear():Void
	{
		keyframes = [];
		m_length  = 0;
	}
}

class KeyFrame
{
	public var time : Float;	
	public var changed : Bool;
	public function new() { time = 0; changed = false; }	
	public function Blend(b : KeyFrame, r : Float) : KeyFrame { return null; }	
	public function Sample(v:Dynamic=null,w:Float=1.0):Dynamic { return null; }
}

class FloatKeyFrame extends KeyFrame
{
	static private var m_temp : FloatKeyFrame = new FloatKeyFrame();
	
	public var value : Float;	
	public function new() { super(); value = 0;	}	
	override public function Blend(b:KeyFrame, r:Float):KeyFrame 
	{
		changed = false;
		var ka : FloatKeyFrame = this;
		var kb : FloatKeyFrame = cast b;
		var va : Float = ka.value;
		var vb : Float = kb.value;
		if (Math.abs(va - vb) < Mathf.Epsilon) { return ka;}
		var k  : FloatKeyFrame = m_temp;
		k.value = Mathf.Lerp(ka.value, kb.value, r);
		k.changed = true;
		return k;
	}
	override public function Sample(v:Dynamic=null,w:Float=1.0):Dynamic { return v==null ? value : Mathf.Lerp(v,value,w);	}
}


class Vector3KeyFrame extends KeyFrame
{
	static private var m_temp : Vector3KeyFrame = new Vector3KeyFrame();
	
	public var value : Vector3;	
	public function new() { super(); value = new Vector3();	}	
	override public function Blend(b:KeyFrame, r:Float):KeyFrame 
	{
		changed = false;
		var ka : Vector3KeyFrame = this;
		var kb : Vector3KeyFrame = cast b;		
		var va : Vector3 = ka.value;
		var vb : Vector3 = kb.value;
		
		if (Math.abs(va.x - vb.x) < Mathf.Epsilon)
		if (Math.abs(va.y - vb.y) < Mathf.Epsilon)
		if (Math.abs(va.z - vb.z) < Mathf.Epsilon) { return ka; }
		var k  : Vector3KeyFrame = m_temp;// new Vector3KeyFrame();
		k.value = Vector3.Lerp(va, vb, r);
		//k.value = r < 0.5 ? ka.value : kb.value;
		k.changed = true;
		
		return k;
	}
	override public function Sample(v:Dynamic=null,w:Float=1.0):Dynamic { return  v==null ? value : Vector3.Lerp(v,value,w); }
}

class QuaternionKeyFrame extends KeyFrame
{
	
	static private var m_temp : QuaternionKeyFrame = new QuaternionKeyFrame();
	
	public var value : Quaternion;	
	
	public function new() { super(); value = Quaternion.identity;	}	
	override public function Blend(b:KeyFrame, r:Float):KeyFrame 
	{
		changed = true;
		var ka : QuaternionKeyFrame = this;
		var kb : QuaternionKeyFrame = cast b;
		var va : Quaternion = ka.value;
		var vb : Quaternion = kb.value;
		
		if (Math.abs(va.x - vb.x) < Mathf.Epsilon)
		if (Math.abs(va.y - vb.y) < Mathf.Epsilon)
		if (Math.abs(va.z - vb.z) < Mathf.Epsilon)
		if (Math.abs(va.w - vb.w) < Mathf.Epsilon) { return ka; }
		//*/
		var k  : QuaternionKeyFrame = m_temp;
		k.value = Quaternion.Lerp(va, vb, r);
		//k.value = r < 0.5 ? ka.value : kb.value;
		k.changed = true;		
		return k;
	}
	override public function Sample(v:Dynamic=null,w:Float=1.0):Dynamic { return v==null ? value : Quaternion.Lerp(v,value,w);	}
}