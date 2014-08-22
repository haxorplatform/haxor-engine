package haxor.context;
import haxor.core.Console;
import haxor.core.Resource;

/**
 * Class that describes a fast Add/Remove execution list.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Process<T> extends BaseProcess
{
	/**
	 * List of elements of this process.
	 */
	public var list : Array<T>;
	
	/**
	 * Returns the length of the process list.
	 */	
	override private inline function get_length():Int { return m_length; }	
	private var m_length : Int;
	
	/**
	 * Creates a new process with a given name and size.
	 * @param	p_name
	 * @param	p_size
	 */
	public function new(p_name : String,p_size : Int) 
	{
		super(p_name);
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
	override public function Add(p_item : Resource):Void
	{	
		var iid : Int = p_item.m_pid[__cid];
		if (iid >= 0) return;		
		list[m_length] = cast p_item;
		p_item.m_pid[__cid] = m_length++;				
	}
	
	/**
	 * Removes the element from the process.
	 * @param	p_item
	 */
	override public function Remove(p_item : Resource):Resource
	{	
		var iid : Int = p_item.m_pid[__cid];
		if (iid < 0) return p_item;
		p_item.m_pid[__cid] = -1;
		m_length--;
		if (m_length <= 0) return p_item;
		list[iid] = list[m_length];
		p_item = cast list[iid];
		p_item.m_pid[__cid] = iid;
		return p_item;
	}
	
	/**
	 * Mark all elements for collections.
	 */
	override public function Clear():Void
	{
		m_length 	= 0;
		list 		= [];
	}
	
}

/**
 * Base Class for the Engine processes.
 */
@:allow(haxor)
class BaseProcess
{
	/**
	 * Class related id.
	 */
	static private var m_cid : Int = 0;
	
	/**
	 * Class related id.
	 */
	private var __cid : Int;
	
	/**
	 * Process name.
	 */
	public var name : String;
	
	/**
	 * Returns the length of the process list.
	 */
	public var length(get_length, null):Int;
	private function get_length():Int { return 0; }
	
	/**
	 * Creates a new process.
	 * @param	p_name
	 */
	public function new(p_name : String) 
	{
		name     		= p_name;
		Console.Log("\tProcess ["+p_name+"] created.",4);
		__cid    		= m_cid++;		
	}
	
	/**
	 * Adds a new item.
	 * @param	p_item
	 */
	public function Add(p_item : Resource):Void { }
	
	/**
	 * Removes an item.
	 * @param	p_item
	 * @return
	 */
	public function Remove(p_item : Resource):Resource { return null; }
	
	/**
	 * Clears the process list.
	 */
	public function Clear():Void { }
	
}