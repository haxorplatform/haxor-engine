package haxe.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class IntMap_iterator_374__Fun<T> extends haxe.lang.Function
{
	public    IntMap_iterator_374__Fun(haxe.root.Array<java.lang.Object> i, haxe.root.Array<haxe.ds.IntMap> _g1)
	{
		super(0, 0);
		this.i = i;
		this._g1 = _g1;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		T ret = ((haxe.ds.IntMap<T>) (((haxe.ds.IntMap) (this._g1.__get(0)) )) ).vals[((int) (haxe.lang.Runtime.toInt(this.i.__get(0))) )];
		this.i.__set(0, ( ((int) (haxe.lang.Runtime.toInt(this.i.__get(0))) ) + 1 ));
		return ret;
	}
	
	
	public  haxe.root.Array<java.lang.Object> i;
	
	public  haxe.root.Array<haxe.ds.IntMap> _g1;
	
}


