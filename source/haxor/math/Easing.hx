package haxor.math;


/**
 * 
 */
class Easing { }

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Trig
{
	
	static public function Acos(v : Float32):Float32{ return Mathf.Acos((-2 * v) + 1.0) * Mathf.InvPI; }
	
	static public function AcosQuad(v : Float32):Float32{ return Mathf.Pow(Acos(v), 2.0); }
	
	static public function AcosRad(v : Float32):Float32{ return Mathf.Pow(Acos(v), 0.5); }
	
	static public function Cos(v:Float32):Float32{ return ( -Mathf.Cos(v * Mathf.PI) + 1.0) * 0.5; }
	
}



/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Cubic
{
	/**
	 * Easing equation: 'y = x*x*x'.
	 * @param	p_r
	 * @return
	 */
	static public function In(p_r : Float32) : Float32 { return p_r * p_r * p_r; }
	
	/**
	 * Easing equation: 'y = x*(x*(x-3)+3)'.
	 * @param	p_r
	 * @return
	 */
	static public function Out(p_r : Float32) : Float32 { return p_r * (p_r * (p_r - 3) + 3); }
	
	
	
	/**
	 * Easing equation: 'y = -2*x*(x*(x-1.5))'.
	 * @param	p_r
	 * @return
	 */
	static public function InOut(p_r : Float32) : Float32 { return -2 * p_r * (p_r * (p_r - 1.5)); }
	
	
	/**
	 * Easing equation: 'y = x*(x*(4*x -6)+3)'.
	 * @param	p_r
	 * @return
	 */
	static public function OutIn(p_r : Float32) : Float32 { return p_r * (p_r * (4 * p_r - 6) + 3); }
	
	
	/**
	 * Easing equation: 'y = x*(x*(4*x-3))'.
	 * @param	p_r
	 * @return
	 */
	static public function BackIn(p_r : Float32) : Float32 { return p_r * (p_r * (4 * p_r - 3)); }
	
	
	/**
	 * Easing equation: 'y = x*(x*(4*x -9) +6)'.
	 * @param	p_r
	 * @return
	 */
	static public function OutBack(p_r : Float32) : Float32 { return p_r * (p_r * (4 * p_r - 9) + 6); }
}


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Elastic
{	
	/**
	 * Easing equation: 'y = x*(x*(x*(x*(56*x -175) + 200) -100) + 20)'.
	 * @param	p_r
	 * @return
	 */
	static public function OutBig  (p_r : Float32) : Float32 { return p_r * (p_r * (p_r * (p_r * ((56) * p_r + ( -175)) + (200)) + ( -100)) + (20)); }	
	
	/**
	 * Easing equation: 'y = x*(x*(x*(x*(33*x -106) + 126) -67) + 15)'.
	 * @param	p_r
	 * @return
	 */
	static public function OutSmall(p_r : Float32) : Float32 { return p_r * (p_r * (p_r * (p_r * ((33) * p_r + ( -106)) + (126)) + ( -67)) + (15)); }	
	
	/**
	 * Easing equation: 'y = x*(x*(x*(x*(33*x -59)+32)-5))'.
	 * @param	p_r
	 * @return
	 */
	static public function InBig   (p_r : Float32) : Float32 { return p_r * (p_r * (p_r * (p_r * ((33) * p_r + ( -59)) + ( 32)) + (  -5))); }		
	
	/**
	 * Easing equation: 'y = x*(x*(x*(x*(56*x-105)+60)-10))'.
	 * @param	p_r
	 * @return
	 */
	static public function InSmall (p_r : Float32) : Float32 { return p_r * (p_r * (p_r * (p_r * ((56) * p_r + (-105)) + ( 60)) + ( -10))); }
	
}