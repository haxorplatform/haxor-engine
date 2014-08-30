package haxe.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class WeakMap_keys_407__Fun<K> extends haxe.lang.Function
{
	public    WeakMap_keys_407__Fun(haxe.root.Array<java.lang.Object> i, haxe.root.Array<K> lastKey)
	{
		super(0, 0);
		this.i = i;
		this.lastKey = lastKey;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		this.i.__set(0, ( ((int) (haxe.lang.Runtime.toInt(this.i.__get(0))) ) + 1 ));
		return this.lastKey.__get(0);
	}
	
	
	public  haxe.root.Array<java.lang.Object> i;
	
	public  haxe.root.Array<K> lastKey;
	
}


