/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

 
package haxor.core;

class Vector<T>
{
	
	public var count(get_count, never):Int;
	private var m_count : Int;
	private function get_count():Int { return m_count; }
		
	private var m_list : Array<T>;
	
	public function new(p_size:Int=0)
	{
		m_count = 0;
		m_list 	= [];
		for (i in 0...p_size) m_list.push(null);
	}
	 
	public function Add(p_item : T):Int
	{
		if (m_count >= m_list.length) { m_list.push(p_item); m_count++; return m_count-1; }
		m_list[m_count++] = p_item;
		return m_count - 1;
	}
	
	public function IndexOf(p_item : T) : Int { for (i in 0...m_list.length) if (m_list[i] == p_item) return i; return -1; }
	
	public function Remove(p_item : T):T
	{
		var p : Int = IndexOf(p_item);
		if (p >= 0) return RemoveAt(p);
		return null;
	}
	
	public function Delete(p_item:T):T
	{
		if (m_list.remove(p_item))
		{
			m_count--;
			return p_item;
		}
		return null;		
	}
	
	public function RemoveAt(p_index : Int):T
	{
		if (m_count <= 0) return null;		
		if (p_index >= (m_count - 1)) { m_count--; return null; }
		var r : T = m_list[m_count - 1];
		m_list[p_index] = m_list[m_count - 1];
		m_count--;
		return r;
	}
	
	public function Get(p_index : Int):T { return m_list[p_index]; }
	
	public function Peek():T { return m_count>= m_list.length ? null : m_list[m_count]; }
	
	public function Clear():Void
	{
		m_count = 0;
	}
}
