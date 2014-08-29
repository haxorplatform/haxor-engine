package haxe.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class WeakMap_iterator_435__Fun<K, V> extends haxe.lang.Function
{
	public    WeakMap_iterator_435__Fun(haxe.root.Array<haxe.ds.WeakMap> _g1, haxe.root.Array<java.lang.Object> i)
	{
		super(0, 0);
		this._g1 = _g1;
		this.i = i;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		V ret = ((haxe.ds.WeakMap<K, V>) (((haxe.ds.WeakMap) (this._g1.__get(0)) )) ).entries[((int) (haxe.lang.Runtime.toInt(this.i.__get(0))) )].value;
		this.i.__set(0, ( ((int) (haxe.lang.Runtime.toInt(this.i.__get(0))) ) + 1 ));
		return ret;
	}
	
	
	public  haxe.root.Array<haxe.ds.WeakMap> _g1;
	
	public  haxe.root.Array<java.lang.Object> i;
	
}


