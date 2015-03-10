package haxor.math;
import haxor.core.Enums.AnimationWrap;
import haxor.math.Curve.CurveKey;
import haxor.platform.Types.Float32;

/**
 * Curve key point.
 */
@:allow(haxor)
class CurveKey
{
	/**
	 * Id of the key in its list.
	 */
	public var id : Int;
	
	/**
	 * Flag that indicates if this curvekey is being used anywhere.
	 */
	public var valid(get_valid, never):Bool;
	private function get_valid():Bool { return id >= 0; }
	
	
	/**
	 * Key position on X axis.
	 */
	public var key : Float32;
	
	/**
	 * Key value on Y axis.
	 */
	public var value : Float32;
	
	/**
	 * Creates a new key.
	 * @param	k
	 * @param	v
	 */
	private function new(k:Float32, v:Float32):Void { id = -1; key = k; value = v; }
}

/**
 * Class that represents a list of key/values pairs smooth interpolated.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Curve
{
	/**
	 * Number of attributes this curve interpolates.
	 */
	public var offset(get_offset, never):Int;
	private function get_offset():Int { return m_offset; }
	private var m_offset : Int;
	
	/**
	 * List of keys per attribute.
	 */
	public var keys : Array<Array<CurveKey>>;
	
	private var m_wrap_left  : Array<AnimationWrap>;
	private var m_wrap_right : Array<AnimationWrap>;
	
	/**
	 * Creates a new Curve with 
	 * @param	p_offset
	 */
	public function new(p_offset:Int=1) 
	{
		m_offset = Mathf.MaxInt(1, p_offset);		
		m_wrap_left  = [];
		m_wrap_right = [];
		for (i in 0...m_offset) 
		{
			m_wrap_left[i]  = AnimationWrap.Clamp;
			m_wrap_right[i] = AnimationWrap.Clamp;
		}
		Clear();
	}
	
	/**
	 * Adds a new key in the curve at given attribute.
	 * @param	p_key
	 * @param	p_value
	 * @param	p_attrib
	 * @return
	 */
	public function Add(p_key:Float32, p_value:Float32, p_attrib:Int = 0):CurveKey
	{
		var ck : CurveKey 		 = new CurveKey(p_key, p_value);
		var kl : Array<CurveKey> = keys[p_attrib];		
		kl.push(ck);
		kl.sort(CurveKeySort);		
		return ck;
	}
	
	/**
	 * Adds new keys using the vector data.
	 * @param	p_key
	 * @param	p_value
	 * @return
	 */
	public function Add2(p_key:Float32, p_value:Vector2):Array<CurveKey>
	{
		var res:Array<CurveKey> = [];
		res.push(Add(p_key, p_value.x, 0));
		res.push(Add(p_key, p_value.y, 1));
		return res;
	}
	
	/**
	 * Adds new keys using the vector data.
	 * @param	p_key
	 * @param	p_value
	 * @return
	 */
	public function Add3(p_key:Float32, p_value:Vector3):Array<CurveKey>
	{
		var res:Array<CurveKey> = [];
		res.push(Add(p_key, p_value.x, 0));
		res.push(Add(p_key, p_value.y, 1));
		res.push(Add(p_key, p_value.z, 2));
		return res;
	}
	
	/**
	 * Adds new keys using the vector data.
	 * @param	p_key
	 * @param	p_value
	 * @return
	 */
	public function Add4(p_key:Float32, p_value:Vector4):Array<CurveKey>
	{
		var res:Array<CurveKey> = [];
		res.push(Add(p_key, p_value.x, 0));
		res.push(Add(p_key, p_value.y, 1));
		res.push(Add(p_key, p_value.z, 2));
		res.push(Add(p_key, p_value.w, 3));
		return res;
	}
	
	/**
	 * Adds new keys using the vector data.
	 * @param	p_key
	 * @param	p_value
	 * @return
	 */
	public function AddColor(p_key:Float32, p_value:Color):Array<CurveKey>
	{
		var res:Array<CurveKey> = [];
		res.push(Add(p_key, p_value.r, 0));
		res.push(Add(p_key, p_value.g, 1));
		res.push(Add(p_key, p_value.b, 2));
		res.push(Add(p_key, p_value.a, 3));
		return res;
	}
	
	/**
	 * Adds a list of keys and values.
	 * @param	p_keys
	 * @param	p_values
	 * @param	p_attrib
	 * @return
	 */
	public function AddRange(p_keys:Array<Float32>, p_values:Array<Float32>, p_attrib:Int = 0):Array<CurveKey>
	{
		var res : Array<CurveKey> = [];		
		for (i in 0...p_keys.length) res.push(Add(p_keys[i], p_values[i], p_attrib));				
		return res;
	}
	
	/**
	 * Removes a given key.
	 * @param	p_id
	 * @param	p_attrib
	 * @return
	 */
	public function Remove(p_id:Int, p_attrib:Int = 0):CurveKey
	{
		var kl : Array<CurveKey> = keys[p_attrib];
		var ck : CurveKey		 = kl[p_id];
		kl.remove(ck);
		return ck;
	}
	
	/**
	 * Updates a CurveKey in the attribute list.
	 * @param	p_id
	 * @param	p_key
	 * @param	p_value
	 * @return
	 */
	public function Update(p_id:Int, p_key:Float32, p_value:Float32,p_attrib:Int=0):CurveKey
	{
		var kl : Array<CurveKey> = keys[p_attrib];
		var ck : CurveKey		 = kl[p_id];
		ck.key   = p_key;
		ck.value = p_value;		
		return ck;
	}
	
	/**
	 * Samples and inteporlate a given key in the chosen attrib key list.
	 * @param	p_value
	 * @param	p_attrib
	 * @return
	 */
	public function Sample(p_key : Float32, p_attrib:Int = 0):Float32
	{
		var kl : Array<CurveKey> = keys[p_attrib];
		if (kl.length==0)  return 0.0;
		if (kl.length==1)  return kl[0].value;
		var ck0:CurveKey = null;
		var ck1:CurveKey = null;
		var kmin : Float32 = kl[0].key;
		var kmax : Float32 = kl[kl.length-1].key;				
		var k    : Float32 = p_key;
		var wrap : AnimationWrap = AnimationWrap.Clamp;		
		var will_wrap : Bool = false;
		
		if (k < kmin) { wrap = m_wrap_left[p_attrib]; will_wrap = true;  }
		if (k > kmax) { wrap = m_wrap_right[p_attrib]; will_wrap = true; }		
		
		if (will_wrap)
		{
			switch(wrap)
			{
				case AnimationWrap.Clamp:    k = Mathf.Clamp(k, kmin, kmax);
				case AnimationWrap.Loop:     k = Mathf.Loop(k, kmin, kmax);
				case AnimationWrap.Oscilate: k = Mathf.Oscilate(k, kmin, kmax);
			}
		}
		
		for (i in 0...(kl.length-1))
		{
			ck0 = kl[i];
			ck1 = kl[i+1];
			if (i==0)if (k<=ck0.key) break; 	  //if behind first key
			if (k>=ck0.key)if(k<=ck1.key) break;  //if between keys
		}
		var dk : Float32;
		var idk : Float32 = dk = Mathf.Max(0.0, ck1.key - ck0.key);
		idk = idk <= 0.0 ? 0.0 : (1.0 / idk);
		var r  : Float32 = (k - ck0.key) * idk;
		return Mathf.Hermite(ck0.value, ck1.value,0.0*dk,0.0*dk,r);
		
	}
	
	/**
	 * Samples the attribs 0 and 1 lists and returns a Vector2.
	 * @param	p_key
	 * @param	p_result
	 * @return
	 */
	public function Sample2(p_key : Float32, p_result:Vector2 = null):Vector2
	{
		var p : Vector2 = p_result == null ? new Vector2() : p_result;
		p.x = Sample(p_key, 0);
		p.y = Sample(p_key, 1);
		return p;
	}
	
	/**
	 * Samples the attribs 0,1 and 2 lists and returns a Vector3.
	 * @param	p_key
	 * @param	p_result
	 * @return
	 */
	public function Sample3(p_key : Float32, p_result:Vector3 = null):Vector3
	{
		var p : Vector3 = p_result == null ? new Vector3() : p_result;
		p.x = Sample(p_key, 0);
		p.y = Sample(p_key, 1);
		p.z = Sample(p_key, 2);
		return p;
	}
	
	/**
	 * Samples the attribs 0,1,2 and 3 lists and returns a Vector4.
	 * @param	p_key
	 * @param	p_result
	 * @return
	 */
	public function Sample4(p_key : Float32, p_result:Vector4 = null):Vector4
	{
		var p : Vector4 = p_result == null ? new Vector4() : p_result;
		p.x = Sample(p_key, 0);
		p.y = Sample(p_key, 1);
		p.z = Sample(p_key, 2);
		p.w = Sample(p_key, 3);
		return p;
	}
	
	/**
	 * Samples the attribs 0,1,2 and 3 lists and returns a Color.
	 * @param	p_key
	 * @param	p_result
	 * @return
	 */
	public function SampleColor(p_key : Float32, p_result:Color = null):Color
	{
		var c : Color = p_result == null ? new Color() : p_result;
		c.r = Sample(p_key, 0);
		c.g = Sample(p_key, 1);
		c.b = Sample(p_key, 2);
		c.a = Sample(p_key, 3);
		return c;
	}
	
	
	
	/**
	 * Returns the curve bounds.
	 * @param	p_result
	 * @param	p_attrib
	 * @return
	 */
	public function GetBounds(p_attrib:Int = 0,p_result:AABB2=null):AABB2
	{
		var r : AABB2 = p_result == null ? new AABB2() : p_result;		
		var kl : Array<CurveKey> = keys[p_attrib];
		if (kl.length <= 0) return r;
		r.xMin = kl[0].key;
		r.xMax = kl[kl.length - 1].key;
		r.yMax = r.yMin = kl[0].value;		
		for (i in 1...kl.length)
		{
			//r.xMin = Mathf.Min(kl[i].key,r.xMin); r.xMax = Mathf.Max(kl[i].key,r.xMax);
			r.yMin = Mathf.Min(kl[i].value,r.yMin); r.yMax = Mathf.Max(kl[i].value,r.yMax);
		}		
		return r;
	}
	
	/**
	 * Sets the sampling wrap mode.
	 * @param	p_left
	 * @param	p_right
	 * @param	p_attrib
	 */
	public function SetWrap(p_left : AnimationWrap, p_right:AnimationWrap, p_attrib:Int = -1):Void
	{
		if (p_attrib < 0)
		{
			for (i in 0...m_offset) 
			{
				m_wrap_left[i] = p_left;
				m_wrap_right[i] = p_right;
			}
		}
		else
		{
			m_wrap_left[p_attrib]  = p_left;
			m_wrap_right[p_attrib] = p_right;
		}
	}
	
	/**
	 * Removes all keys from all attribs.
	 */
	public function Clear():Void
	{
		if (keys != null)
		{
			for (i in 0...keys.length)
			{
				var kl : Array<CurveKey> = keys[i];
				for (j in 0...kl.length) kl[j].id = -1;
			}
		}
		
		keys = [];
		for (i in 0...m_offset) keys.push([]);
	}
	
	/**
	 * Sort and adjust all ids.
	 * @param	kl
	 */
	public function Refresh(p_attrib:Int=-1):Void
	{
		for (i in 0...keys.length)
		{
			if (p_attrib >= 0) if (i != p_attrib) continue;
			var kl : Array<CurveKey> = keys[i];
			kl.sort(CurveKeySort);
			for (j in 0...kl.length) kl[j].id = i;
		}
	}
	
	/**
	 * Sort the CurveKey list.
	 * @param	a
	 * @param	b
	 * @return
	 */
	static private function CurveKeySort(a:CurveKey, b:CurveKey):Int { return a.key < b.key ? -1 : 1; }
}