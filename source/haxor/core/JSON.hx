/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.core;
import haxe.Json;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class JSON
{
	static public function FromJSON(d : String):Dynamic	
	{
		var res : Dynamic = null;		
		try
		{
			res = Json.parse(d);
		}
		catch (err : Dynamic)
		{
			return null;		
		}
		return res;
	}
	
	static public function ToJSON(d : Dynamic):String
	{
		try
		{
			var cache:Array<Dynamic> = [];		
			var res:String = Json.stringify(d, function(key : Dynamic, value : Dynamic) : Dynamic
			{
				var is_obj : Bool = untyped __js__("typeof value === 'object' && value !== null");
				if (is_obj) 
				{
					for (i in 0...cache.length) if (cache[i] == value) return null;
					// Store value in our collection
					cache.push(value);
				}
				return value;
			});
			return res;
		}
		catch (err : Dynamic)
		{
			return "";
		}
		return "";
	}
	
	
}