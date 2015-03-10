package haxor.ds;

/**
 * Simple resource pool class.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Pool<T>
{
	
	/**
	 * 
	 */
	private var m_list : Array<T>;
	
	/**
	 * 
	 */
	private var m_top : Int;
	
	/**
	 * 
	 */
	private var m_type : Class<T>;

	/**
	 * 
	 * @param	p_count
	 */
	public function new(p_type : Class<T>,p_count : Int=0)
	{
		m_type = p_type;
		m_top  = 0;
		m_list = [];
		for (i in 0...p_count) Generate();
	}
	
	/**
	 * 
	 * @return
	 */
	public function Get():T { if (m_top <= 0) Generate(); return m_list[--m_top]; }
	
	/**
	 * 
	 * @param	v
	 */
	public function Put(v:T):Void { m_list[m_top++] = v; }
	
	/**
	 * 
	 * @return
	 */
	private function Generate():Void
	{ 
		var d : T = cast Type.createInstance(m_type, []);
		m_list.unshift(d);
		m_top++;
	}
	
}