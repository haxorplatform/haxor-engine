package haxe.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ObjectMap_iterator_387__Fun<V, K> extends haxe.lang.Function
{
	public    ObjectMap_iterator_387__Fun(haxe.root.Array<java.lang.Object> i, haxe.root.Array<java.lang.Object> len, haxe.root.Array<haxe.ds.ObjectMap> _g1)
	{
		super(0, 0);
		this.i = i;
		this.len = len;
		this._g1 = _g1;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		{
			int _g = ((int) (haxe.lang.Runtime.toInt(this.i.__get(0))) );
			while (( _g < ((int) (haxe.lang.Runtime.toInt(this.len.__get(0))) ) ))
			{
				int j = _g++;
				if ( ! ((( (( ((haxe.ds.ObjectMap<K, V>) (((haxe.ds.ObjectMap) (this._g1.__get(0)) )) ).hashes[j] & -2 )) == 0 ))) ) 
				{
					this.i.__set(0, j);
					return true;
				}
				
			}
			
		}
		
		return false;
	}
	
	
	public  haxe.root.Array<java.lang.Object> i;
	
	public  haxe.root.Array<java.lang.Object> len;
	
	public  haxe.root.Array<haxe.ds.ObjectMap> _g1;
	
}


