package haxor.context;
import haxor.core.Resource;


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Process<T>
{
	/**
	 * Class related id.
	 */
	static private var m_cid : Int = 0;
	
	/**
	 * Process name.
	 */
	public var name : String;
	
	/**
	 * List of elements of this process.
	 */
	public var list : Array<T>;
	
	/**
	 * Returns the length of the process list.
	 */
	public var length(get_length, null):Int;
	private function get_length():Int { return m_length; }	
	private var m_length : Int;
		
	/**
	 * Class related id.
	 */
	private var _cid_ : Int;
	
	/**
	 * Queue for async element removal.
	 */
	private var m_remove_queue : Array<T>;
	
	
	/**
	 * Creates a new process with a given name and size.
	 * @param	p_name
	 * @param	p_size
	 */
	public function new(p_name : String,p_size : Int) 
	{
		name     		= p_name;
		_cid_    		= m_cid++;
		list     		= [];		
		m_length 		= 0;		
		for (i in 0...p_size)
		{
			list.push(null);					
		}
	}
	
	
	/**
	 * Adds an element to the process.
	 * @param	p_item
	 */
	public function Add(p_item : Resource):Void
	{	
		var iid : Int = p_item.m_pid[_cid_];
		if (iid >= 0) return;		
		list[m_length] = cast p_item;
		p_item.m_pid[_cid_] = m_length++;		
		trace(name+" " + m_length);
	}
	
	/**
	 * Removes the element from the process.
	 * @param	p_item
	 */
	public function Remove(p_item : Resource):Resource
	{	
		
		var iid : Int = p_item.m_pid[_cid_];
		if (iid < 0) return p_item;
		p_item.m_pid[_cid_] = -1;
		m_length--;
		if (m_length <= 0) return p_item;
		list[iid] = list[m_length];
		p_item = cast list[iid];
		p_item.m_pid[_cid_] = iid;
		return p_item;
	}
	
	/**
	 * Mark all elements for collections.
	 */
	public function Clear():Void
	{
		m_length 	= 0;
		list 		= [];
	}
	
}