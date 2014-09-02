package haxe.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class TreeNode<K, V> extends haxe.lang.HxObject
{
	public    TreeNode(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    TreeNode(haxe.ds.TreeNode<K, V> l, K k, V v, haxe.ds.TreeNode<K, V> r, java.lang.Object h)
	{
		haxe.ds.TreeNode.__hx_ctor_haxe_ds_TreeNode(this, l, k, v, r, h);
	}
	
	
	public static  <K_c, V_c> void __hx_ctor_haxe_ds_TreeNode(haxe.ds.TreeNode<K_c, V_c> __temp_me160394, haxe.ds.TreeNode<K_c, V_c> l, K_c k, V_c v, haxe.ds.TreeNode<K_c, V_c> r, java.lang.Object h)
	{
		int __temp_h160393 = ( (( h == null )) ? (((int) (-1) )) : (((int) (haxe.lang.Runtime.toInt(h)) )) );
		__temp_me160394.left = l;
		__temp_me160394.key = k;
		__temp_me160394.value = v;
		__temp_me160394.right = r;
		if (( __temp_h160393 == -1 )) 
		{
			int __temp_stmt160848 = 0;
			int __temp_stmt160849 = 0;
			{
				haxe.ds.TreeNode<K_c, V_c> _this = __temp_me160394.left;
				__temp_stmt160849 = ( (( _this == null )) ? (0) : (_this._height) );
			}
			
			int __temp_stmt160850 = 0;
			{
				haxe.ds.TreeNode<K_c, V_c> _this1 = __temp_me160394.right;
				__temp_stmt160850 = ( (( _this1 == null )) ? (0) : (_this1._height) );
			}
			
			if (( __temp_stmt160849 > __temp_stmt160850 )) 
			{
				haxe.ds.TreeNode<K_c, V_c> _this2 = __temp_me160394.left;
				__temp_stmt160848 = ( (( _this2 == null )) ? (0) : (_this2._height) );
			}
			 else 
			{
				haxe.ds.TreeNode<K_c, V_c> _this3 = __temp_me160394.right;
				__temp_stmt160848 = ( (( _this3 == null )) ? (0) : (_this3._height) );
			}
			
			__temp_me160394._height = ( __temp_stmt160848 + 1 );
		}
		 else 
		{
			__temp_me160394._height = __temp_h160393;
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.ds.TreeNode<java.lang.Object, java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.ds.TreeNode<java.lang.Object, java.lang.Object>(((haxe.ds.TreeNode<java.lang.Object, java.lang.Object>) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ), ((java.lang.Object) (arr.__get(2)) ), ((haxe.ds.TreeNode<java.lang.Object, java.lang.Object>) (arr.__get(3)) ), ((java.lang.Object) (arr.__get(4)) ));
	}
	
	
	public  haxe.ds.TreeNode<K, V> left;
	
	public  haxe.ds.TreeNode<K, V> right;
	
	public  K key;
	
	public  V value;
	
	public  int _height;
	
	@Override public   java.lang.String toString()
	{
		return ( ( (( (( this.left == null )) ? ("") : (( this.left.toString() + ", " )) )) + (( ( ( "" + haxe.root.Std.string(this.key) ) + "=" ) + haxe.root.Std.string(this.value) )) ) + (( (( this.right == null )) ? ("") : (( ", " + this.right.toString() )) )) );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef160843 = true;
			switch (field.hashCode())
			{
				case 1487441478:
				{
					if (field.equals("_height")) 
					{
						__temp_executeDef160843 = false;
						this._height = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106079:
				{
					if (field.equals("key")) 
					{
						__temp_executeDef160843 = false;
						this.key = ((K) (((java.lang.Object) (value) )) );
						return ((double) (haxe.lang.Runtime.toDouble(((java.lang.Object) (value) ))) );
					}
					
					break;
				}
				
				
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef160843 = false;
						this.value = ((V) (((java.lang.Object) (value) )) );
						return ((double) (haxe.lang.Runtime.toDouble(((java.lang.Object) (value) ))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160843) 
			{
				return super.__hx_setField_f(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef160844 = true;
			switch (field.hashCode())
			{
				case 1487441478:
				{
					if (field.equals("_height")) 
					{
						__temp_executeDef160844 = false;
						this._height = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3317767:
				{
					if (field.equals("left")) 
					{
						__temp_executeDef160844 = false;
						this.left = ((haxe.ds.TreeNode<K, V>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef160844 = false;
						this.value = ((V) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 108511772:
				{
					if (field.equals("right")) 
					{
						__temp_executeDef160844 = false;
						this.right = ((haxe.ds.TreeNode<K, V>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106079:
				{
					if (field.equals("key")) 
					{
						__temp_executeDef160844 = false;
						this.key = ((K) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160844) 
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
			boolean __temp_executeDef160845 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef160845 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("toString"))) );
					}
					
					break;
				}
				
				
				case 3317767:
				{
					if (field.equals("left")) 
					{
						__temp_executeDef160845 = false;
						return this.left;
					}
					
					break;
				}
				
				
				case 1487441478:
				{
					if (field.equals("_height")) 
					{
						__temp_executeDef160845 = false;
						return this._height;
					}
					
					break;
				}
				
				
				case 108511772:
				{
					if (field.equals("right")) 
					{
						__temp_executeDef160845 = false;
						return this.right;
					}
					
					break;
				}
				
				
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef160845 = false;
						return this.value;
					}
					
					break;
				}
				
				
				case 106079:
				{
					if (field.equals("key")) 
					{
						__temp_executeDef160845 = false;
						return this.key;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160845) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef160846 = true;
			switch (field.hashCode())
			{
				case 1487441478:
				{
					if (field.equals("_height")) 
					{
						__temp_executeDef160846 = false;
						return ((double) (this._height) );
					}
					
					break;
				}
				
				
				case 106079:
				{
					if (field.equals("key")) 
					{
						__temp_executeDef160846 = false;
						return ((double) (haxe.lang.Runtime.toDouble(((java.lang.Object) (this.key) ))) );
					}
					
					break;
				}
				
				
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef160846 = false;
						return ((double) (haxe.lang.Runtime.toDouble(((java.lang.Object) (this.value) ))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160846) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
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
			boolean __temp_executeDef160847 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef160847 = false;
						return this.toString();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160847) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("_height");
		baseArr.push("value");
		baseArr.push("key");
		baseArr.push("right");
		baseArr.push("left");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


