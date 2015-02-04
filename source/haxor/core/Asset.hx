package haxor.core;
import haxor.core.Resource;

/**
 * Class that handles Asset operation and access.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Asset
{
	/**
	 * Database with assets to be stored.
	 */
	static private var m_database : Map<String,Dynamic> = new Map<String,Dynamic>();
	
	/**
	 * Retrieves a Resource from the global database.
	 * @param	p_id
	 * @return
	 */
	static public function Get(p_id : String) : Dynamic { return m_database.exists(p_id) ? (m_database.get(p_id)) : null; }
	
	/**
	 * Removes an entry from the global database.
	 * @param	p_id
	 * @return
	 */
	static public function Remove(p_id:String):Dynamic { if (m_database.exists(p_id)) { var a : Dynamic = m_database.get(p_id);	m_database.remove(p_id); return a; } return null; }
	
	/**
	 * Adds a Resource into the global database.
	 * @param	p_id
	 * @param	p_asset
	 * @return
	 */
	static public function Add(p_id : String, p_asset : Dynamic) : Void { m_database.set(p_id, p_asset); if (Std.is(p_asset, Resource)) { cast(p_asset, Resource).__db = p_id; } }
	
	
}