package haxor.net;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Texture2DLoader_OnBitmapCallback_53__Fun extends haxe.lang.Function
{
	public    Texture2DLoader_OnBitmapCallback_53__Fun(haxe.root.Array<haxor.graphics.texture.Bitmap> p_data1, haxe.root.Array<haxor.net.Texture2DLoader> _g)
	{
		super(0, 0);
		this.p_data1 = p_data1;
		this._g = _g;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		haxor.graphics.texture.Texture2D t = haxor.graphics.texture.Texture2D.FromBitmap(this.p_data1.__get(0), this._g.__get(0).m_apply);
		this._g.__get(0).m_t2d_callback.__hx_invoke2_o(0.0, t, 1.0, haxe.lang.Runtime.undefined);
		return null;
	}
	
	
	public  haxe.root.Array<haxor.graphics.texture.Bitmap> p_data1;
	
	public  haxe.root.Array<haxor.net.Texture2DLoader> _g;
	
}


