/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.math;

/**
 * ...
 * @author Eduardo Pons
 */

class Vector2
{
	
	/**
	 * 
	 */
	static public var zero(get_zero, null):Vector2;	static private function get_zero():Vector2 { return new Vector2(0, 0); }
	
	/**
	 * Returns a new Vector2(1,0)
	 */
	static public var Right(get_Right, null):Vector2;
	static private function get_Right():Vector2 { return new Vector2(1, 0); }
	
	static public var Up(get_Up, null):Vector2;
	static private function get_Up():Vector2 { return new Vector2(0, 1); }
	
	/**
	 * 
	 * @param	p_a
	 * @param	p_b
	 * @param	p_r
	 * @return
	 */
	static public function Lerp(p_a : Vector2, p_b : Vector2, p_r:Float):Vector2
	{
		return new Vector2(
		p_a.x + (p_b.x - p_a.x) * p_r,
		p_a.y + (p_b.y - p_a.y) * p_r		
		);
	}
	
	public var clone(get_clone, null) : Vector2;
	private function get_clone():Vector2 { return new Vector2(x, y); }
	
	public var length(get_length, null) : Float;	
	private function get_length():Float { return Math.sqrt(x * x + y * y); }	
	
	public var normalized(get_normalized, null) : Vector2;	
	private function get_normalized():Vector2 { return clone.Normalize(); }
	
	public var x:Float;	
	
	public var y:Float;
	
	public function new(p_x:Float=0,p_y:Float=0) 
	{
		x = p_x;
		y = p_y;
	}
	
	public function Normalize():Vector2
	{
		var l:Float = length;
		if (l <= 0) return this;
		x *= (l = 1.0 / l);
		y *= l;		
		return this;
	}
	
	/**
	 * 
	 * @return
	 */
	public function ToArray() : Array<Float> { return [x,y]; }
	
	public function ToString():String
	{
		var a : Array<Float> = ToArray();
		var s : Array<String> = [];
		for (i in 0...a.length) { a[i] = Std.int(a[i] * 100.0) / 100; s.push(a[i] >= 0 ? " " + a[i] : a[i] + ""); }
		var res:String = "[";
		for (i in 0...a.length)
		{
			res += s[i] + ((i < (a.length-1)) ? "," : "]");			
		}
		return res;
	}
	
	
	
}