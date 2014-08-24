package haxor.context;

/**
 * Class that handles the creation and management of unique ids.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class UID
{
	/**
	 * Gets a new Id. If there is any cached it will use the cache, otherwise the counter will incremented with a new id.
	 * The id can be returned so it can be used again.
	 */
	public var id(get_id, set_id):Int;
	private inline function get_id():Int { return (m_cache.length <= 0 ? (m_id++) : m_cache.shift()); }
	private inline function set_id(v:Int):Int { m_cache.push(v); return v; }	
	private var m_id :Int;
	private var m_cache : Array<Int>;

	public function new() 
	{
		m_id 	= 0;
		m_cache = [];
	}
	
}