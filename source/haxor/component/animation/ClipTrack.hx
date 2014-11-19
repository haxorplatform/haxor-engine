package haxor.component.animation;
import haxor.component.animation.KeyFrame.FloatKeyFrame;
import haxor.component.animation.KeyFrame.QuaternionKeyFrame;
import haxor.component.animation.KeyFrame.Vector3KeyFrame;
import haxor.math.Mathf;
import haxor.math.Quaternion;
import haxor.math.Vector3;
import haxor.platform.Types.Float32;

/**
 * Class that represents a single property animation inside an AnimationClip.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class ClipTrack
{
	/**
	 * Target object.
	 */
	public var target : Dynamic;
	
	/**
	 * Target's property to be animated.
	 */
	public var property : String;
	
	/**
	 * Keyframes containing the time and values in each frame.
	 */
	public var keyframes : Array<KeyFrame>;
		
	/**
	 * Length in seconds of this track.
	 */
	public var length(get_length, never):Float32;
	private function get_length():Float32 { return m_length; }
	private var m_length : Float32;
	
	private var m_head : Int;
	
	/**
	 * Creates a new ClipTrack.
	 */
	public function new()
	{
		target    = null;
		keyframes = [];		
		property  = "";
		m_head 	  = 0;
		m_length  = 0;
	}
	
	/**
	 * Adds a keyframe in a given time with the desired value.
	 * @param	p_time
	 * @param	p_value
	 * @return
	 */
	public function Add(p_time : Float32, p_value : Dynamic):KeyFrame 
	{
		var k : KeyFrame = null;
		if (Std.is(p_value, Float32))  	 { var nk : FloatKeyFrame 		= cast (k = new FloatKeyFrame()); 		nk.time = p_time; nk.value = p_value; } else
		if (Std.is(p_value, Vector3)) 	 { var nk : Vector3KeyFrame 	= cast (k = new Vector3KeyFrame()); 	nk.time = p_time; nk.value = p_value; } else
		if (Std.is(p_value, Quaternion)) { var nk : QuaternionKeyFrame  = cast (k = new QuaternionKeyFrame());  nk.time = p_time; nk.value = p_value; }
		
		if (k != null)
		{
			keyframes.push(k);			
			m_length = Mathf.Max(k.time, m_length);			
		}
		
		return k;
	}
	
	/**
	 * Samples the value of a keyframe in the specified time and applies to this track's target.
	 * @param	p_time
	 * @param	p_weight
	 * @return
	 */
	public function Sample(p_time : Float32,p_weight:Float32=1.0):Int
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
			
			var dt : Float32 = (k1.time - k0.time);
			var r : Float32  = dt <= 0 ? 0.0 : ((p_time - k0.time) / dt);
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
	
	/**
	 * Generates a nw ClipTrack with the desired interval.
	 * @param	p_start
	 * @param	p_end
	 * @return
	 */
	public function Split(p_start : Int, p_end : Int):ClipTrack
	{
		var nct : ClipTrack = new ClipTrack();
		nct.target   = target;
		nct.property = property;
		var i0 : Int = Mathf.MinInt(p_start, keyframes.length-1);
		var i1 : Int = Mathf.MinInt(p_end, keyframes.length - 1);
		var kf : KeyFrame = keyframes[i0];
		if (kf == null) return nct;
		var t0 : Float32 = kf.time;
		for (i in i0...i1)
		{			
			kf = keyframes[i];
			if (kf != null)	nct.Add(kf.time-t0,kf.Sample());
		}	
		return nct;
	}
	
	/**
	 * Removes all keyframes.
	 */
	public function Clear():Void
	{
		keyframes = [];
		m_length  = 0;
	}
}