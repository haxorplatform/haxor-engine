package haxor.math;

/**
 * Class that handles different random data generation.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Random
{
	/**
	 * Returns a random value in the [0.0,0.99999] range.
	 */
	static public var value(get_value, null):Float;
	static private inline function get_value():Float { return Math.random(); }
	
	/**
	 * Returns a random value inside the [-0.9999,0.9999] range.
	 */
	static public var interval(get_interval, null):Float;
	static private inline function get_interval():Float { return (value-0.499995)*2.0; }
	
	/**
	 * Returns a random rotation quaternion.
	 */
	static public var rotation(get_rotation, null):Quaternion;
	static private inline function get_rotation():Quaternion { return Quaternion.FromAxisAngle(sphere, interval*180.0); }
	
	/**
	 * Returns a random point inside a size 1.0 box.
	 */
	static public var box(get_box, null):Vector3;
	static private inline function get_box():Vector3 { return (new Vector3(interval * 0.5, interval * 0.5, interval * 0.5)); }
	
	/**
	 * Returns a random point on a size 1.0 box.
	 */
	static public var onBox(get_onBox, null):Vector3;
	static private inline function get_onBox():Vector3 
	{
		var p : Vector3 = box;
		var i : Int = cast((value * 3) + 0.5);
		switch(i)
		{
			case 0: p.x = p.x < 0.0 ? -0.5 : 0.5;
			case 1: p.y = p.y < 0.0 ? -0.5 : 0.5;
			case 2: p.z = p.z < 0.0 ? -0.5 : 0.5;
		}		
		return p;
	}
	
	/**
	 * Returns a random point inside a size 1.0 square.
	 */
	static public var square(get_square, null):Vector2;
	static private inline function get_square():Vector2 { return (new Vector2(interval*0.5, interval*0.5)); }
	
	/**
	 * Returns a random point on a size 1.0 square.
	 */
	static public var onSquare(get_onSquare, null):Vector2;
	static private inline function get_onSquare():Vector2 
	{
		var p : Vector2 = square;
		var i : Int = cast((value * 2) + 0.5);
		switch(i)
		{
			case 0: p.x = p.x < 0.0 ? -0.5 : 0.5;
			case 1: p.y = p.y < 0.0 ? -0.5 : 0.5;			
		}		
		return p;
	}
	
	/**
	 * Returns a random normalized vector inside a radius 1.0 sphere.
	 */
	static public var sphere(get_sphere, null):Vector3;
	static private inline function get_sphere():Vector3 { return (new Vector3(interval, interval, interval)).Normalize().Scale(value); }
		
	/**
	 * Returns a random normalized vector on a radius 1.0 sphere.
	 */
	static public var onSphere(get_onSphere, null):Vector3;
	static private inline function get_onSphere():Vector3 { return (new Vector3(interval, interval, interval)).Normalize(); }
	
	/**
	 * Returns a random normalized vector inside a radius 1.0 circle.
	 */
	static public var circle(get_circle, null):Vector2;
	static private inline function get_circle():Vector2 { return (new Vector2(interval, interval)).Normalize().Scale(value); }
	
	/**
	 * Returns a random normalized vector on a radius 1.0 circle.
	 */
	static public var onCircle(get_onCircle, null):Vector2;
	static private inline function get_onCircle():Vector2 { return (new Vector2(interval, interval)).Normalize(); }
	
	/**
	 * Returns an integer from [0;v].
	 */
	static public function Length(v:Int):Int { return cast ((v + 1) * value); }
	
	/**
	 * Returns a float inside the interval min/max.
	 * @param	p_min
	 * @param	p_max
	 * @return
	 */
	static public function Range(p_min:Float, p_max:Float):Float { return Mathf.Lerp(p_min, p_max, value); }
	
	/**
	 * Returns an int inside the interval min/max.
	 * @param	p_min
	 * @param	p_max
	 * @return
	 */
	static public function RangeInt(p_min:Int, p_max:Int):Float { return Mathf.LerpInt(p_min, p_max+1, value); }
	
	/**
	 * Returns a random element from this list.
	 */
	static public function Item<T>(p_list : Array<T>): T { return p_list[cast (p_list.length * value)]; }
	
	/**
	 * Fisher–Yates Shuffle
	 * @param	p_list
	 */
	static public function Shuffle<T>(p_list : Array<T>) : Void 
	{
		var m : Int = p_list.length;
		var t : T;
		var i : Int;
		// While there remain elements to shuffle…
		while (m>0) 
		{
			// Pick a remaining element…
			i = Math.floor(value * (m--));
			// And swap it with the current element.
			t = p_list[m];
			p_list[m] = p_list[i];
			p_list[i] = t;			
		}
	}
}