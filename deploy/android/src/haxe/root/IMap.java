package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  interface IMap<K, V> extends haxe.lang.IHxObject
{
	   V get(K k);
	
	   void set(K k, V v);
	
	   boolean exists(K k);
	
	   boolean remove(K k);
	
	   java.lang.Object keys();
	
	   java.lang.Object iterator();
	
	   java.lang.String toString();
	
}


