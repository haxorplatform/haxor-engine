/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.api;
import js.html.Audio;
import js.html.audio.AudioContext;
import js.html.audio.GainNode;
import js.html.AudioElement;
import haxor.media.Sound;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class SoundAPI
{
	
	static public function Initialize():Void
	{
		trace("Haxor> SoundAPI Initialize");		
		Sound.m_list = [];
		Sound.m_main = 1.0;
		
	}
	
	static public function SetMainVolume(p_v : Float):Void
	{
		
	}
		
	public function new() 
	{
		//oncanplay
		//oncanplaythrough
		//onloadeddata
		
		var snd : AudioElement;
		
		var audio : Audio;
		
		
		
		/*
		snd = cast Browser.document.createElement("audio");									
		snd.addEventListener("canplay",function(e : Event)
		{
			trace("sound loaded");
			snd.play();
		},true);		
		snd.preload = "auto";		
		snd.src = "chime.mp3";		
		snd.load();
		//*/
		
	}
	
}