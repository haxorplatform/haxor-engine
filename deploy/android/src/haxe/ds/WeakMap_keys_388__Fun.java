package haxe.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class WeakMap_keys_388__Fun<V, K> extends haxe.lang.Function
{
	public    WeakMap_keys_388__Fun(haxe.root.Array<K> lastKey, haxe.root.Array<haxe.ds.WeakMap> _g1, haxe.root.Array<java.lang.Object> i, haxe.root.Array<java.lang.Object> len)
	{
		super(0, 0);
		this.lastKey = lastKey;
		this._g1 = _g1;
		this.i = i;
		this.len = len;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		{
			int _g = ((int) (haxe.lang.Runtime.toInt(this.i.__get(0))) );
			while (( _g < ((int) (haxe.lang.Runtime.toInt(this.len.__get(0))) ) ))
			{
				int j = _g++;
				if ( ! ((( (( ((haxe.ds.WeakMap<K, V>) (((haxe.ds.WeakMap) (this._g1.__get(0)) )) ).hashes[j] & -2 )) == 0 ))) ) 
				{
					haxe.ds._WeakMap.Entry<K, V> entry = ((haxe.ds.WeakMap<K, V>) (((haxe.ds.WeakMap) (this._g1.__get(0)) )) ).entries[((int) (haxe.lang.Runtime.toInt(this.i.__get(0))) )];
					K last = entry.get();
					if (( ! (( last == null )) )) 
					{
						this.lastKey.__set(0, last);
						((haxe.ds.WeakMap<K, V>) (((haxe.ds.WeakMap) (this._g1.__get(0)) )) ).cachedIndex = ((int) (haxe.lang.Runtime.toInt(this.i.__get(0))) );
						((haxe.ds.WeakMap<K, V>) (((haxe.ds.WeakMap) (this._g1.__get(0)) )) ).cachedEntry = entry;
						this.i.__set(0, j);
						return true;
					}
					
				}
				
			}
			
		}
		
		return false;
	}
	
	
	public  haxe.root.Array<K> lastKey;
	
	public  haxe.root.Array<haxe.ds.WeakMap> _g1;
	
	public  haxe.root.Array<java.lang.Object> i;
	
	public  haxe.root.Array<java.lang.Object> len;
	
}


