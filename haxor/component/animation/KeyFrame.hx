package haxor.component.animation;
import haxor.math.Mathf;
import haxor.math.Quaternion;
import haxor.math.Vector3;
import haxor.platform.Types.Float32;

/**
 * Base class that describes a KeyFrame which will interpolate a property value.
 */
class KeyFrame
{
	/**
	 * Keyframe time in seconds.
	 */
	public var time : Float32;	
	
	/**
	 * Flag that indicates some value changed during blending.
	 */
	public var changed : Bool;
	
	/**
	 * Creates a new KeyFrame.
	 */
	public function new() { time = 0; changed = false; }	
	
	/**
	 * Method that will blend the keyframe with another one and returns the weighted result of them.
	 * @param	b
	 * @param	r
	 * @return
	 */
	public function Blend(b : KeyFrame, r : Float32) : KeyFrame { return null; }	
	
	/**
	 * Returns a sample of this keyframe value using the informed ratio.
	 * @param	v
	 * @param	w
	 * @return
	 */
	public function Sample(v:Dynamic=null,w:Float32=1.0):Dynamic { return null; }
}

/**
 * Keyframe to interpolate Floats.
 */
class FloatKeyFrame extends KeyFrame
{
	static private var m_temp : FloatKeyFrame = new FloatKeyFrame();
	
	/**
	 * Keyframe value.
	 */
	public var value : Float32;	
	
	/**
	 * Creates a new Keyframe.
	 */
	public function new() { super(); value = 0;	}	
	
	/**
	 * Method that will blend the keyframe with another one and returns the weighted result of them.
	 * @param	b
	 * @param	r
	 * @return
	 */
	override public function Blend(b:KeyFrame, r:Float32):KeyFrame 
	{
		changed = false;
		var ka : FloatKeyFrame = this;
		var kb : FloatKeyFrame = cast b;
		var va : Float32 = ka.value;
		var vb : Float32 = kb.value;
		if (Math.abs(va - vb) < Mathf.Epsilon) { return ka;}
		var k  : FloatKeyFrame = m_temp;
		k.value = Mathf.Lerp(ka.value, kb.value, r);
		k.changed = true;
		return k;
	}
	
	/**
	 * Returns a sample of this keyframe value using the informed ratio.
	 * @param	v
	 * @param	w
	 * @return
	 */
	override public function Sample(v:Dynamic=null,w:Float=1.0):Dynamic { return v==null ? value : Mathf.Lerp(v,value,w);	}
}

/**
 * Keyframe to interpolate Vector3 instances.
 */
class Vector3KeyFrame extends KeyFrame
{
	static private var m_temp : Vector3KeyFrame = new Vector3KeyFrame();
	
	/**
	 * Keyframe value.
	 */
	public var value : Vector3;	
	
	/**
	 * Creates a new keyframe.
	 */
	public function new() { super(); value = new Vector3();	}	
	
	/**
	 * Method that will blend the keyframe with another one and returns the weighted result of them.
	 * @param	b
	 * @param	r
	 * @return
	 */
	override public function Blend(b:KeyFrame, r:Float32):KeyFrame 
	{
		changed = false;
		var ka : Vector3KeyFrame = this;
		var kb : Vector3KeyFrame = cast b;		
		var va : Vector3 = ka.value;
		var vb : Vector3 = kb.value;		
		if (Math.abs(va.x - vb.x) < Mathf.Epsilon)
		if (Math.abs(va.y - vb.y) < Mathf.Epsilon)
		if (Math.abs(va.z - vb.z) < Mathf.Epsilon) { return ka; }
		var k  : Vector3KeyFrame = m_temp;
		k.value = Vector3.Lerp(va, vb, r,k.value);
		//k.value = r < 0.5 ? ka.value : kb.value;
		k.changed = true;		
		return k;
	}
	
	/**
	 * Returns a sample of this keyframe value using the informed ratio.
	 * @param	v
	 * @param	w
	 * @return
	 */
	override public function Sample(v:Dynamic=null,w:Float32=1.0):Dynamic { return  v==null ? value : Vector3.Lerp(v,value,w,Vector3.temp); }
}

/**
 * Keyframe to interpolate Quaternion instances.
 */
class QuaternionKeyFrame extends KeyFrame
{
	
	static private var m_temp : QuaternionKeyFrame = new QuaternionKeyFrame();
	
	/**
	 * Keyframe value.
	 */
	public var value : Quaternion;	
	
	/**
	 * Creates a new keyframe.
	 */
	public function new() { super(); value = Quaternion.identity;	}	
	
	/**
	 * Method that will blend the keyframe with another one and returns the weighted result of them.
	 * @param	b
	 * @param	r
	 * @return
	 */
	override public function Blend(b:KeyFrame, r:Float32):KeyFrame 
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
		var k  : QuaternionKeyFrame = m_temp;
		k.value = Quaternion.Lerp(va, vb, r, k.value);
		//k.value = r < 0.5 ? ka.value : kb.value;
		k.changed = true;		
		return k;
	}
	
	/**
	 * Returns a sample of this keyframe value using the informed ratio.
	 * @param	v
	 * @param	w
	 * @return
	 */
	override public function Sample(v:Dynamic=null,w:Float32=1.0):Dynamic { return v==null ? value : Quaternion.Lerp(v,value,w,Quaternion.temp);	}
}