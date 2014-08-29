package haxe.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class BalancedTree<K, V> extends haxe.lang.HxObject
{
	public    BalancedTree(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    BalancedTree()
	{
		haxe.ds.BalancedTree.__hx_ctor_haxe_ds_BalancedTree(this);
	}
	
	
	public static  <K_c, V_c> void __hx_ctor_haxe_ds_BalancedTree(haxe.ds.BalancedTree<K_c, V_c> __temp_me80546)
	{
		{
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.ds.BalancedTree<java.lang.Object, java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.ds.BalancedTree<java.lang.Object, java.lang.Object>();
	}
	
	
	public  haxe.ds.TreeNode<K, V> root;
	
	public   void set(K key, V value)
	{
		this.root = this.setLoop(key, value, this.root);
	}
	
	
	public   V get(K key)
	{
		haxe.ds.TreeNode<K, V> node = this.root;
		while (( node != null ))
		{
			int c = this.compare(key, node.key);
			if (( c == 0 )) 
			{
				return node.value;
			}
			
			if (( c < 0 )) 
			{
				node = node.left;
			}
			 else 
			{
				node = node.right;
			}
			
		}
		
		return null;
	}
	
	
	public   boolean remove(K key)
	{
		try 
		{
			this.root = this.removeLoop(key, this.root);
			return true;
		}
		catch (java.lang.Throwable __temp_catchallException80968)
		{
			java.lang.Object __temp_catchall80969 = __temp_catchallException80968;
			if (( __temp_catchall80969 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall80969 = ((haxe.lang.HaxeException) (__temp_catchallException80968) ).obj;
			}
			
			if (( __temp_catchall80969 instanceof java.lang.String )) 
			{
				java.lang.String e = haxe.lang.Runtime.toString(__temp_catchall80969);
				{
					return false;
				}
				
			}
			 else 
			{
				throw haxe.lang.HaxeException.wrap(__temp_catchallException80968);
			}
			
		}
		
		
	}
	
	
	public   boolean exists(K key)
	{
		haxe.ds.TreeNode<K, V> node = this.root;
		while (( node != null ))
		{
			int c = this.compare(key, node.key);
			if (( c == 0 )) 
			{
				return true;
			}
			 else 
			{
				if (( c < 0 )) 
				{
					node = node.left;
				}
				 else 
				{
					node = node.right;
				}
				
			}
			
		}
		
		return false;
	}
	
	
	public   java.lang.Object iterator()
	{
		haxe.root.Array<V> ret = new haxe.root.Array<V>(( (V[]) (new java.lang.Object[] {}) ));
		this.iteratorLoop(this.root, ret);
		return ((java.lang.Object) (new _Array.ArrayIterator<V>(((haxe.root.Array<V>) (ret) ))) );
	}
	
	
	public   java.lang.Object keys()
	{
		haxe.root.Array<K> ret = new haxe.root.Array<K>(( (K[]) (new java.lang.Object[] {}) ));
		this.keysLoop(this.root, ret);
		return ((java.lang.Object) (new _Array.ArrayIterator<K>(((haxe.root.Array<K>) (ret) ))) );
	}
	
	
	public   haxe.ds.TreeNode<K, V> setLoop(K k, V v, haxe.ds.TreeNode<K, V> node)
	{
		if (( node == null )) 
		{
			return new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (null) ), ((K) (k) ), ((V) (v) ), ((haxe.ds.TreeNode<K, V>) (null) ), ((java.lang.Object) (null) ));
		}
		
		int c = this.compare(k, node.key);
		if (( c == 0 )) 
		{
			return new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (node.left) ), ((K) (k) ), ((V) (v) ), ((haxe.ds.TreeNode<K, V>) (node.right) ), ((java.lang.Object) (( (( node == null )) ? (0) : (node._height) )) ));
		}
		 else 
		{
			if (( c < 0 )) 
			{
				haxe.ds.TreeNode<K, V> nl = this.setLoop(k, v, node.left);
				return this.balance(nl, node.key, node.value, node.right);
			}
			 else 
			{
				haxe.ds.TreeNode<K, V> nr = this.setLoop(k, v, node.right);
				return this.balance(node.left, node.key, node.value, nr);
			}
			
		}
		
	}
	
	
	public   haxe.ds.TreeNode<K, V> removeLoop(K k, haxe.ds.TreeNode<K, V> node)
	{
		if (( node == null )) 
		{
			throw haxe.lang.HaxeException.wrap("Not_found");
		}
		
		int c = this.compare(k, node.key);
		if (( c == 0 )) 
		{
			return this.merge(node.left, node.right);
		}
		 else 
		{
			if (( c < 0 )) 
			{
				return this.balance(this.removeLoop(k, node.left), node.key, node.value, node.right);
			}
			 else 
			{
				return this.balance(node.left, node.key, node.value, this.removeLoop(k, node.right));
			}
			
		}
		
	}
	
	
	public   void iteratorLoop(haxe.ds.TreeNode<K, V> node, haxe.root.Array<V> acc)
	{
		if (( node != null )) 
		{
			this.iteratorLoop(node.left, acc);
			acc.push(node.value);
			this.iteratorLoop(node.right, acc);
		}
		
	}
	
	
	public   void keysLoop(haxe.ds.TreeNode<K, V> node, haxe.root.Array<K> acc)
	{
		if (( node != null )) 
		{
			this.keysLoop(node.left, acc);
			acc.push(node.key);
			this.keysLoop(node.right, acc);
		}
		
	}
	
	
	public   haxe.ds.TreeNode<K, V> merge(haxe.ds.TreeNode<K, V> t1, haxe.ds.TreeNode<K, V> t2)
	{
		if (( t1 == null )) 
		{
			return t2;
		}
		
		if (( t2 == null )) 
		{
			return t1;
		}
		
		haxe.ds.TreeNode<K, V> t = this.minBinding(t2);
		return this.balance(t1, t.key, t.value, this.removeMinBinding(t2));
	}
	
	
	public   haxe.ds.TreeNode<K, V> minBinding(haxe.ds.TreeNode<K, V> t)
	{
		if (( t == null )) 
		{
			throw haxe.lang.HaxeException.wrap("Not_found");
		}
		 else 
		{
			if (( t.left == null )) 
			{
				return t;
			}
			 else 
			{
				return this.minBinding(t.left);
			}
			
		}
		
	}
	
	
	public   haxe.ds.TreeNode<K, V> removeMinBinding(haxe.ds.TreeNode<K, V> t)
	{
		if (( t.left == null )) 
		{
			return t.right;
		}
		 else 
		{
			return this.balance(this.removeMinBinding(t.left), t.key, t.value, t.right);
		}
		
	}
	
	
	public   haxe.ds.TreeNode<K, V> balance(haxe.ds.TreeNode<K, V> l, K k, V v, haxe.ds.TreeNode<K, V> r)
	{
		int hl = 0;
		if (( l == null )) 
		{
			hl = 0;
		}
		 else 
		{
			hl = l._height;
		}
		
		int hr = 0;
		if (( r == null )) 
		{
			hr = 0;
		}
		 else 
		{
			hr = r._height;
		}
		
		if (( hl > ( hr + 2 ) )) 
		{
			int __temp_stmt80972 = 0;
			{
				haxe.ds.TreeNode<K, V> _this = l.left;
				__temp_stmt80972 = ( (( _this == null )) ? (0) : (_this._height) );
			}
			
			int __temp_stmt80973 = 0;
			{
				haxe.ds.TreeNode<K, V> _this1 = l.right;
				__temp_stmt80973 = ( (( _this1 == null )) ? (0) : (_this1._height) );
			}
			
			if (( __temp_stmt80972 >= __temp_stmt80973 )) 
			{
				return new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (l.left) ), ((K) (l.key) ), ((V) (l.value) ), ((haxe.ds.TreeNode<K, V>) (new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (l.right) ), ((K) (k) ), ((V) (v) ), ((haxe.ds.TreeNode<K, V>) (r) ), ((java.lang.Object) (null) ))) ), ((java.lang.Object) (null) ));
			}
			 else 
			{
				return new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (l.left) ), ((K) (l.key) ), ((V) (l.value) ), ((haxe.ds.TreeNode<K, V>) (l.right.left) ), ((java.lang.Object) (null) ))) ), ((K) (l.right.key) ), ((V) (l.right.value) ), ((haxe.ds.TreeNode<K, V>) (new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (l.right.right) ), ((K) (k) ), ((V) (v) ), ((haxe.ds.TreeNode<K, V>) (r) ), ((java.lang.Object) (null) ))) ), ((java.lang.Object) (null) ));
			}
			
		}
		 else 
		{
			if (( hr > ( hl + 2 ) )) 
			{
				int __temp_stmt80970 = 0;
				{
					haxe.ds.TreeNode<K, V> _this2 = r.right;
					__temp_stmt80970 = ( (( _this2 == null )) ? (0) : (_this2._height) );
				}
				
				int __temp_stmt80971 = 0;
				{
					haxe.ds.TreeNode<K, V> _this3 = r.left;
					__temp_stmt80971 = ( (( _this3 == null )) ? (0) : (_this3._height) );
				}
				
				if (( __temp_stmt80970 > __temp_stmt80971 )) 
				{
					return new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (l) ), ((K) (k) ), ((V) (v) ), ((haxe.ds.TreeNode<K, V>) (r.left) ), ((java.lang.Object) (null) ))) ), ((K) (r.key) ), ((V) (r.value) ), ((haxe.ds.TreeNode<K, V>) (r.right) ), ((java.lang.Object) (null) ));
				}
				 else 
				{
					return new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (l) ), ((K) (k) ), ((V) (v) ), ((haxe.ds.TreeNode<K, V>) (r.left.left) ), ((java.lang.Object) (null) ))) ), ((K) (r.left.key) ), ((V) (r.left.value) ), ((haxe.ds.TreeNode<K, V>) (new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (r.left.right) ), ((K) (r.key) ), ((V) (r.value) ), ((haxe.ds.TreeNode<K, V>) (r.right) ), ((java.lang.Object) (null) ))) ), ((java.lang.Object) (null) ));
				}
				
			}
			 else 
			{
				return new haxe.ds.TreeNode<K, V>(((haxe.ds.TreeNode<K, V>) (l) ), ((K) (k) ), ((V) (v) ), ((haxe.ds.TreeNode<K, V>) (r) ), ((java.lang.Object) (( (( (( hl > hr )) ? (hl) : (hr) )) + 1 )) ));
			}
			
		}
		
	}
	
	
	public   int compare(K k1, K k2)
	{
		return haxe.root.Reflect.compare(k1, k2);
	}
	
	
	@Override public   java.lang.String toString()
	{
		return ( ( "{" + this.root.toString() ) + "}" );
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef80974 = true;
			switch (field.hashCode())
			{
				case 3506402:
				{
					if (field.equals("root")) 
					{
						__temp_executeDef80974 = false;
						this.root = ((haxe.ds.TreeNode<K, V>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef80974) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef80975 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("toString"))) );
					}
					
					break;
				}
				
				
				case 3506402:
				{
					if (field.equals("root")) 
					{
						__temp_executeDef80975 = false;
						return this.root;
					}
					
					break;
				}
				
				
				case 950484197:
				{
					if (field.equals("compare")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("compare"))) );
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set"))) );
					}
					
					break;
				}
				
				
				case -339185956:
				{
					if (field.equals("balance")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("balance"))) );
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get"))) );
					}
					
					break;
				}
				
				
				case 277888887:
				{
					if (field.equals("removeMinBinding")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("removeMinBinding"))) );
					}
					
					break;
				}
				
				
				case -934610812:
				{
					if (field.equals("remove")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("remove"))) );
					}
					
					break;
				}
				
				
				case -757252141:
				{
					if (field.equals("minBinding")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("minBinding"))) );
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("exists"))) );
					}
					
					break;
				}
				
				
				case 103785528:
				{
					if (field.equals("merge")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("merge"))) );
					}
					
					break;
				}
				
				
				case 1182533742:
				{
					if (field.equals("iterator")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("iterator"))) );
					}
					
					break;
				}
				
				
				case 518409912:
				{
					if (field.equals("keysLoop")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("keysLoop"))) );
					}
					
					break;
				}
				
				
				case 3288564:
				{
					if (field.equals("keys")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("keys"))) );
					}
					
					break;
				}
				
				
				case 527064114:
				{
					if (field.equals("iteratorLoop")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("iteratorLoop"))) );
					}
					
					break;
				}
				
				
				case 1984755238:
				{
					if (field.equals("setLoop")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setLoop"))) );
					}
					
					break;
				}
				
				
				case 1098338632:
				{
					if (field.equals("removeLoop")) 
					{
						__temp_executeDef80975 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("removeLoop"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef80975) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			boolean __temp_executeDef80976 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef80976 = false;
						return this.toString();
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef80976 = false;
						this.set(((K) (dynargs.__get(0)) ), ((V) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 950484197:
				{
					if (field.equals("compare")) 
					{
						__temp_executeDef80976 = false;
						return this.compare(((K) (dynargs.__get(0)) ), ((K) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef80976 = false;
						return this.get(((K) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -339185956:
				{
					if (field.equals("balance")) 
					{
						__temp_executeDef80976 = false;
						return this.balance(((haxe.ds.TreeNode<K, V>) (dynargs.__get(0)) ), ((K) (dynargs.__get(1)) ), ((V) (dynargs.__get(2)) ), ((haxe.ds.TreeNode<K, V>) (dynargs.__get(3)) ));
					}
					
					break;
				}
				
				
				case -934610812:
				{
					if (field.equals("remove")) 
					{
						__temp_executeDef80976 = false;
						return this.remove(((K) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 277888887:
				{
					if (field.equals("removeMinBinding")) 
					{
						__temp_executeDef80976 = false;
						return this.removeMinBinding(((haxe.ds.TreeNode<K, V>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef80976 = false;
						return this.exists(((K) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -757252141:
				{
					if (field.equals("minBinding")) 
					{
						__temp_executeDef80976 = false;
						return this.minBinding(((haxe.ds.TreeNode<K, V>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1182533742:
				{
					if (field.equals("iterator")) 
					{
						__temp_executeDef80976 = false;
						return this.iterator();
					}
					
					break;
				}
				
				
				case 103785528:
				{
					if (field.equals("merge")) 
					{
						__temp_executeDef80976 = false;
						return this.merge(((haxe.ds.TreeNode<K, V>) (dynargs.__get(0)) ), ((haxe.ds.TreeNode<K, V>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 3288564:
				{
					if (field.equals("keys")) 
					{
						__temp_executeDef80976 = false;
						return this.keys();
					}
					
					break;
				}
				
				
				case 518409912:
				{
					if (field.equals("keysLoop")) 
					{
						__temp_executeDef80976 = false;
						this.keysLoop(((haxe.ds.TreeNode<K, V>) (dynargs.__get(0)) ), ((haxe.root.Array<K>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1984755238:
				{
					if (field.equals("setLoop")) 
					{
						__temp_executeDef80976 = false;
						return this.setLoop(((K) (dynargs.__get(0)) ), ((V) (dynargs.__get(1)) ), ((haxe.ds.TreeNode<K, V>) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case 527064114:
				{
					if (field.equals("iteratorLoop")) 
					{
						__temp_executeDef80976 = false;
						this.iteratorLoop(((haxe.ds.TreeNode<K, V>) (dynargs.__get(0)) ), ((haxe.root.Array<V>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1098338632:
				{
					if (field.equals("removeLoop")) 
					{
						__temp_executeDef80976 = false;
						return this.removeLoop(((K) (dynargs.__get(0)) ), ((haxe.ds.TreeNode<K, V>) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef80976) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("root");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


