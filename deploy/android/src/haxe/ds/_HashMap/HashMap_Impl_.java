package haxe.ds._HashMap;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public final class HashMap_Impl_
{
	public static  <V, K, V1> java.lang.Object _new()
	{
		{
			haxe.ds.IntMap<K> __temp_odecl160853 = new haxe.ds.IntMap<K>();
			haxe.ds.IntMap<V1> __temp_odecl160854 = new haxe.ds.IntMap<V1>();
			return new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"keys", "values"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl160853, __temp_odecl160854}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		}
		
	}
	
	
	public static  <V, K, V1> void set(java.lang.Object this1, K k, V1 v)
	{
		((haxe.ds.IntMap<K>) (haxe.lang.Runtime.getField(this1, "keys", true)) ).set(((int) (k.hashCode()) ), ((K) (k) ));
		((haxe.ds.IntMap<V1>) (haxe.lang.Runtime.getField(this1, "values", true)) ).set(((int) (k.hashCode()) ), ((V1) (v) ));
	}
	
	
	public static  <V, K, V1> V1 get(java.lang.Object this1, K k)
	{
		return ((haxe.ds.IntMap<V1>) (haxe.lang.Runtime.getField(this1, "values", true)) ).get(((int) (k.hashCode()) ));
	}
	
	
	public static  <V, K, V1> boolean exists(java.lang.Object this1, K k)
	{
		return ((haxe.ds.IntMap<V1>) (haxe.lang.Runtime.getField(this1, "values", true)) ).exists(((int) (k.hashCode()) ));
	}
	
	
	public static  <V, K, V1> boolean remove(java.lang.Object this1, K k)
	{
		((haxe.ds.IntMap<V1>) (haxe.lang.Runtime.getField(this1, "values", true)) ).remove(((int) (k.hashCode()) ));
		return ((haxe.ds.IntMap<K>) (haxe.lang.Runtime.getField(this1, "keys", true)) ).remove(((int) (k.hashCode()) ));
	}
	
	
	public static  <V, K, V1> java.lang.Object keys(java.lang.Object this1)
	{
		return ((haxe.ds.IntMap<K>) (haxe.lang.Runtime.getField(this1, "keys", true)) ).iterator();
	}
	
	
	public static  <V, K, V1> java.lang.Object iterator(java.lang.Object this1)
	{
		return ((haxe.ds.IntMap<V1>) (haxe.lang.Runtime.getField(this1, "values", true)) ).iterator();
	}
	
	
}


