package _Map;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public final class Map_Impl_
{
	
	
	public static  <V, K, K1, V2> void set(haxe.root.IMap<K1, V2> this1, K1 key, V2 value)
	{
		this1.set(key, value);
	}
	
	
	public static  <V, K, K1, V2> V2 get(haxe.root.IMap<K1, V2> this1, K1 key)
	{
		return this1.get(key);
	}
	
	
	public static  <V, K, K1, V2> boolean exists(haxe.root.IMap<K1, V2> this1, K1 key)
	{
		return this1.exists(key);
	}
	
	
	public static  <V, K, K1, V2> boolean remove(haxe.root.IMap<K1, V2> this1, K1 key)
	{
		return this1.remove(key);
	}
	
	
	public static  <V, K, K1, V2> java.lang.Object keys(haxe.root.IMap<K1, V2> this1)
	{
		return this1.keys();
	}
	
	
	public static  <V, K, K1, V2> java.lang.Object iterator(haxe.root.IMap<K1, V2> this1)
	{
		return this1.iterator();
	}
	
	
	public static  <V, K, K1, V2> java.lang.String toString(haxe.root.IMap<K1, V2> this1)
	{
		return this1.toString();
	}
	
	
	public static  <V, K, K1, V2> V2 arrayWrite(haxe.root.IMap<K1, V2> this1, K1 k, V2 v)
	{
		this1.set(k, v);
		return v;
	}
	
	
	public static  <V, K, K1, V2> haxe.ds.StringMap<V2> toStringMap(haxe.root.IMap<java.lang.String, V2> t)
	{
		return new haxe.ds.StringMap<V2>();
	}
	
	
	public static  <V, K, K1, V2> haxe.ds.IntMap<V2> toIntMap(haxe.root.IMap<java.lang.Object, V2> t)
	{
		return new haxe.ds.IntMap<V2>();
	}
	
	
	public static  <V, K, K1, V2> haxe.ds.EnumValueMap<K, V2> toEnumValueMapMap(haxe.root.IMap<K, V2> t)
	{
		return new haxe.ds.EnumValueMap<K, V2>();
	}
	
	
	public static  <V, K, K1, V2> haxe.ds.ObjectMap<K, V2> toObjectMap(haxe.root.IMap<K, V2> t)
	{
		return new haxe.ds.ObjectMap<K, V2>();
	}
	
	
	public static  <K, V> haxe.root.IMap<java.lang.String, V> fromStringMap(haxe.ds.StringMap<V> map)
	{
		return map;
	}
	
	
	public static  <K, V> haxe.root.IMap<java.lang.Object, V> fromIntMap(haxe.ds.IntMap<V> map)
	{
		return map;
	}
	
	
	public static  <K, V> haxe.root.IMap<K, V> fromObjectMap(haxe.ds.ObjectMap<K, V> map)
	{
		return map;
	}
	
	
}


