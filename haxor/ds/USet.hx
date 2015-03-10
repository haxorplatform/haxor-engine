package haxor.ds;

/**
 * Interface that describes how an USet item must be implemented.
 */
interface IUSetItem
{	
	var usid : Int;
}

/**
 * Class that describes an unordered set that allows fast iteration, insertion and removal, considering that the order isn't necessarely a condition.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class USet<T : IUSetItem>
{
	
	/**
	 * 
	 */
	public var length(get_length, never):Int;
	private function get_length():Int { return m_length; }
	private var m_length:Int;
	 
	/**
	 * 
	 */
	private var m_list : Array<T>;

	
	
	/**
	 * 
	 */
	public function new() 
	{
		m_list   = [];
		m_length = 0;
	}
	
	/**
	 * 
	 * @param	p_item
	 */
	public function Add(p_item : T):Void
	{
		if (p_item.usid >= 0) return;
		
		if (m_length >= m_list.length)
		{			
			m_list.push(p_item);			
		}
		else
		{
			m_list[m_length] = p_item;
		}
		p_item.usid = m_length++;
	}
	
	/**
	 * 
	 * @param	p_item
	 */
	public function Remove(p_item : T):Void
	{
		var oid : Int = p_item.usid;
		if (oid < 0) return;
		if (m_length <= 0 ) return;
		var last : T  = m_list[m_length - 1];		
		m_list[oid] = last;
		last.usid   = oid;
		p_item.usid = -1;
		m_length--;
	}
	
	/**
	 * 
	 * @param	p_index
	 * @return
	 */
	public function Get(p_index : Int):T { return m_list[p_index]; }
	
	/**
	 * 
	 */
	public function Clear():Void { m_length = 0; }
}