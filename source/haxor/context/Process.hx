package haxor.context;
import haxor.core.Console;
import haxor.core.IDisposable;
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
	public function new(p_name : String,p_size : Int,p_update_cid:Bool=true) 
	{
		super(p_name,p_update_cid);
		list     		= [];		
		m_length 		= 0;
		
		for (i in 0...p_size)
		{
			list.push(null);					
		}
		//*/
	}
	
	
	/**
	 * Adds an element to the process.
	 * @param	p_item
	 */
	override public function Add(p_item : Resource):Void
	{	
		var iid : Int = p_item.__pid[__cid];
		
		if (iid >= 0)
		{
			Console.Log("Process " + name+"> Failed to Add ["+p_item.name+"@"+p_item.GetTypeName()+"]",7);
			return;
		}		
		if (m_length >= list.length) { list.push(null); }
		list[m_length] = cast p_item;
		p_item.__pid[__cid] = m_length;		
		m_length++;		
		//trace("added " + p_item.name+"["+p_item.__pid[__cid]+"]["+length+"/"+list.length+"]");
	}
	
	/**
	 * Removes the element from the process.
	 * @param	p_item
	 */
	override public function Remove(p_item : Resource):Void
	{	
		var iid : Int = p_item.__pid[__cid];
		if (iid < 0)
		{
			Console.Log("Process " + name+"> Failed to Remove ["+p_item.name+"@"+p_item.GetTypeName()+"]",7);
			return;		
		}		
		var old_item : Resource = p_item;
		var new_item : Resource = cast list[m_length - 1];				
		new_item.__pid[__cid] = old_item.__pid[__cid];
		old_item.__pid[__cid] = -1;		
		list[iid]          = cast new_item;
		list[m_length - 1] = cast old_item;		
		m_length--;		
		//trace("removed " + old_item.name+"["+iid+"]["+length+"/"+list.length+"] curr["+new_item.name+"]["+new_item.__pid[__cid]+"]");
	}
	
	/**
	 * Swap elements of this process.
	 * @param	p_a
	 * @param	p_b
	 */
	public function Swap(p_a:T, p_b:T,p_index_only:Bool=false):Void 
	{
		var ra : Resource = cast p_a;
		var rb : Resource = cast p_b;
		var ia : Int = ra.__pid[__cid];
		if (ia < 0) return;
		var ib : Int = rb.__pid[__cid];
		if (ib < 0) return;
		
		if (!p_index_only)
		{
			list[ia] = p_b;
			list[ib] = p_a;
		}
		
		rb.__pid[__cid] = ia;
		ra.__pid[__cid] = ib;
	}
	
	/**
	 * Mark all elements for collections.
	 */
	override public function Clear():Void
	{
		m_length 	= 0;
		list 		= [];
	}
	
	/**
	 * Sort this process members taking care of their indexes.
	 * @param	p_method
	 */
	public function Sort(p_method:T->T->Int):Void 
	{
		list.sort(p_method);
		for (i in 0...length) 
		{
			var it:Resource = cast list[i];
			if(it!=null) it.__pid[__cid] = i;
		}
	}
	
	/**
	 * Outputs the nodes of this list and their PID ids.
	 * @return
	 */
	public function ToString():String
	{
		var log : String = "";
		for (i in 0...length)
		{
			var it:Resource = cast list[i];			
			log += "["+it.name+","+it.__pid[__cid]+"]";
		}
		return log;
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
	public function new(p_name : String,p_update_cid:Bool=true) 
	{
		name     		= p_name;		
		__cid    		= m_cid;		
		Console.Log("\tProcess ["+p_name+"]["+__cid+"] created.",8);
		if (p_update_cid) m_cid++;		
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
	public function Remove(p_item : Resource):Void { }
		
	/**
	 * Clears the process list.
	 */
	public function Clear():Void { }
	
}