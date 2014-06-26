/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.core;

interface IStaticArrayItem
{
	public function GetIds() : Array<Int>;
}

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class StaticArray 
{
	
	static public var MAX_ARRAYS : Int = 32;
	
	static private var m_nextId : Int = 0;
	
	private var m_list : Array<IStaticArrayItem>;
	
	private var m_iterator : Int;
	
	private var m_id : Int;
	
	private var m_next:Int;
	
	public var count(get_count, never):Int;
	private function get_count():Int { return m_count; }
	private var m_count : Int;
	
	public var length(get_length, never):Int;
	private function get_length():Int { return m_length; }
	private var m_length : Int;
	
	public function new(p_length : Int) 
	{
		m_id = m_nextId++;
		m_iterator = 0;
		m_count = 0;	
		m_next = 0;
		m_length = p_length;
		m_list = [];
		for (i in 0...m_length) m_list.push(null);
	}
	
	public function Add(p_item : IStaticArrayItem) : Void
	{		
		var it : IStaticArrayItem = cast p_item;		
		var ids : Array<Int> = it.GetIds();
		//if (ids.length < MAX_ARRAYS) for (i in 0...MAX_ARRAYS) ids.push( -1);
		if (ids[m_id] >= 0) return;		
		m_list[m_next] = p_item;
		ids[m_id] = m_next++;
		m_count++;
	}
	
	public function Remove(p_item : IStaticArrayItem) : Void
	{		
		var it : IStaticArrayItem = cast p_item;
		var ids : Array<Int> = it.GetIds();
		//if (ids.length < MAX_ARRAYS) for (i in 0...MAX_ARRAYS) ids.push( -1);
		if (ids[m_id] < 0) return;
		var pos :Int = ids[m_id];		
		m_list[pos] = null;
		ids[m_id] = -1;
		m_count--;		
		if (m_count > 0)
		{
			if (pos >= (m_next-1)) { m_next--; return; }
			m_list[pos] = m_list[m_next-1];
			m_list[pos].GetIds()[m_id] = pos;
			m_next--;
		}
	}	
	
	public function Get(p_index:Int):IStaticArrayItem { return m_list[p_index]; }
	
	public function Reset():Void
	{
		m_iterator = 0;		
	}
	
	public function Next() : IStaticArrayItem
	{		
		if (m_iterator < m_next) return m_list[m_iterator++];
		//var it : IStaticArrayItem =  m_list[m_iterator];		
		return null;
		/*
		if (it != null) { m_iterator++; return it; }		
		var tail : IStaticArrayItem = cast m_list[--m_next];
		while (tail == null) 
		{ 
			if (m_next <= 0) 		   return null; 
			if (m_iterator >= m_next) return null;	
			m_next--; 
			tail = cast m_list[m_next]; 
		}		
		m_list[m_iterator] = tail;
		var ids : Array<Int> = tail.GetIds();
		ids[m_id] = m_iterator;			
		m_list[m_next] = null;
		m_iterator++;
		return tail;	
		//*/
	}
	
}