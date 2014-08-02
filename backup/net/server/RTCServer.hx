/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.net.server;
import nodejs.NodeJS;

/**
 * Class that describes a RTCServer that will run on a nodejs context.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class RTCServer
{
	public var port(get_port, never):Int;
	private function get_port():Int { return m_port; }
	private var m_port : Int;
	
	private var m_ssl : Dynamic;
	
	private var _s : Dynamic;

	public function new(p_port : Int,p_debug:Bool=false,p_ssl_key:String="",p_ssl_certificate:String="") 
	{		
		m_port = p_port;
		var args : Dynamic = { port: p_port };
		if (p_ssl_key != "") if (p_ssl_certificate != "") args.ssl = { key: p_ssl_key, certificate: p_ssl_certificate };		
		var c : Class<Dynamic> = NodeJS.require("peer").PeerServer;
		_s = Type.createInstance(c, [args] );		
		trace("RTC> Running @ "+port);
	}
	
}