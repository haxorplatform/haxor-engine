package haxor.ds;
import haxor.math.Mathf;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class PairTable<T>
{
	/**
	 * 
	 */
	public var mirror(get_mirror, never):Bool;
	private function get_mirror():Bool { return m_mirror; }
	private var m_mirror : Bool;
	
	/**
	 * 
	 */
	public var rows(get_rows, never):Int;
	private function get_rows():Int { return m_table.length; }
	
	/**
	 * 
	 */
	public var cols(get_cols, never):Int;
	private function get_cols():Int { return m_table.length; }
	
	/**
	 * 
	 */
	private var m_table : Array<Array<T>>;

	/**
	 * 
	 * @param	p_count
	 */
	public function new(p_count : Int,p_default : T,p_mirror:Bool=false) 
	{
		m_mirror = p_mirror;
		m_table  = [];
		
		var lc : Int = p_mirror ? 0 : p_count;
		for (i in 0...p_count)
		{
			var l : Array<T> = [];
			m_table.push(l);
			for (j in 0...lc)
			{
				l.push(p_default);
			}
			if (p_mirror) lc++;
		}
	}
	
	/**
	 * 
	 * @param	p_x
	 * @param	p_y
	 * @return
	 */
	public function Get(p_x : Int, p_y : Int) : T 
	{		
		if (mirror) 
		return m_table[Mathf.MaxInt(p_x, p_y)][Mathf.MinInt(p_x, p_y)];		
		return m_table[p_x][p_y]; 
	}
	
	/**
	 * 
	 * @param	p_x
	 * @param	p_y
	 * @param	p_value
	 */
	public function Set(p_x : Int, p_y : Int, p_value : T):Void
	{
		if (mirror)		
		{ m_table[Mathf.MaxInt(p_x, p_y)][Mathf.MinInt(p_x, p_y)] = p_value; return; }		
		m_table[p_x][p_y] = p_value;
	}
	
	/**
	 * 
	 * @param	p_index
	 * @return
	 */
	public function Line(p_index : Int):Array<T> { return m_table[p_index]; }
	
	
	/**
	 * 
	 * @param	p_callback
	 */
	public function Iterate(p_callback : Int -> Int -> T -> Void):Void
	{
		for (i in 0...m_table.length)
		{
			var l : Array<T> = m_table[i];
			for (j in 0...l.length)
			{
				p_callback(j, i, l[j]);
			}
		}
	}
	
}