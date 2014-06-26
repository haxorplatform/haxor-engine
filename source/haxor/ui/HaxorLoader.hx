/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.ui;
import haxe.Timer;
import haxor.core.Asset;
import haxor.core.Tween;
import haxor.math.Easing;
import js.Browser;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class HaxorLoader extends UILoader
{
	
	private var m_dock   : Sprite;
	
	private var m_fill   : Sprite;
	
	private var m_bar : Sprite;
	
	private var m_logo : Sprite;

	public function new() 
	{
		super();
		name = "haxor_loader";		
		
		m_fill = new Sprite();
		
		
	}
	
	override function OnAddedToStage():Void 
	{
		alpha = 0;
		var bcg : Sprite = new Sprite();
		bcg.name = "background";
		bcg.layout.flag = LayoutFlag.SizeXY;
		bcg.width = bcg.height = 1;
		bcg.image = cast stage.document.getElementById("hxp_background");
		
		var pattern : Sprite = new Sprite();
		pattern.name = "pattern";
		pattern.layout.flag = LayoutFlag.SizeXY;
		pattern.width = pattern.height = 1;
		pattern.pattern = true;
		pattern.image = cast stage.document.getElementById("hxp_pattern");
		
		m_fill.name = "fill";
		m_fill.image  = cast Browser.document.getElementById("hxp_fill");
		m_fill.layout.flag = LayoutFlag.SizeX;
		m_fill.layout.width  = 0;// m_fill.image.naturalWidth;
		m_fill.height = m_fill.image.naturalHeight;
		m_fill.slices = [7, 7, 0, 0];
		
		var bar : Sprite = m_bar = new Sprite();
		bar.name = "bar";
		bar.image  = cast stage.document.getElementById("hxp_bar");
		bar.layout.Set(LayoutFlag.PivotX | LayoutFlag.PositionXY, 0.5, 0, 0.5, 0.5);
		bar.width  = 0;
		bar.height = bar.image.naturalHeight;
		bar.slices = [6, 6, 0, 0];		
		bar.AddChild(m_fill);
		
		
		var logo : Sprite = m_logo = new Sprite();
		logo.name = "logo";
		logo.image  = cast stage.document.getElementById("hxp_logo");
		logo.width  = logo.image.naturalWidth;
		logo.height = logo.image.naturalHeight;
		logo.layout.Set(LayoutFlag.PivotX | LayoutFlag.PositionXY, 0.5, 0, 0.5, 0.5);
		logo.py = logo.image.naturalHeight * 0.44;
		
		AddChild(bcg);
		AddChild(pattern);		
		AddChild(bar);
		AddChild(logo);
		
		Tween.Add(this, "alpha", 1, 0.6, 0.2, Cubic.Out);
		Tween.Add(bar, "width", 270, 0.4, 0.8, Cubic.Out);
		Tween.Add(logo, "py", logo.py + 60, 0.5, 0.8, Cubic.Out);
	}
	
	override public function OnProgress(p_progress:Float):Void 
	{	
		Tween.Add(m_fill.layout, "width", p_progress,Asset.dependenceCount <= 0 ? 0 : 0.8,0,Cubic.Out);		
	}
	
	override public function OnComplete():Void 
	{	
		Timer.delay(function():Void
		{
			Tween.Add(m_bar, "width", 0, 0.4, 0.1, Cubic.Out);
			Tween.Add(m_bar, "alpha", 0, 0.4, 0.1, Cubic.Out);
			Tween.Add(m_logo, "py", m_logo.py - 60, 0.5, 0.3, Cubic.Out);
			Tween.Add(this, "alpha", -0.1, 1, 0.9, Cubic.Out).oncomplete = function():Void
			{
				Finish();
			};		
		},1000);
		
	}
	
}