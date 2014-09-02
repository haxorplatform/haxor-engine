package haxe.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class EnumValueMap<K, V> extends haxe.ds.BalancedTree<K, V> implements haxe.root.IMap<K, V>
{
	public    EnumValueMap(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    EnumValueMap()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxe.ds.EnumValueMap.__hx_ctor_haxe_ds_EnumValueMap(this);
	}
	
	
	public static  <K_c, V_c> void __hx_ctor_haxe_ds_EnumValueMap(haxe.ds.EnumValueMap<K_c, V_c> __temp_me160395)
	{
		haxe.ds.BalancedTree.__hx_ctor_haxe_ds_BalancedTree(__temp_me160395);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.ds.EnumValueMap<java.lang.Object, java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.ds.EnumValueMap<java.lang.Object, java.lang.Object>();
	}
	
	
	@Override public   int compare(K __temp_k1160396, K __temp_k2160397)
	{
		java.lang.Object k2 = ((java.lang.Object) (__temp_k2160397) );
		java.lang.Object k1 = ((java.lang.Object) (__temp_k1160396) );
		int d = ( haxe.root.Type.enumIndex(k1) - haxe.root.Type.enumIndex(k2) );
		if (( d != 0 )) 
		{
			return d;
		}
		
		haxe.root.Array p1 = haxe.root.Type.enumParameters(k1);
		haxe.root.Array p2 = haxe.root.Type.enumParameters(k2);
		if (( ( p1.length == 0 ) && ( p2.length == 0 ) )) 
		{
			return 0;
		}
		
		return this.compareArgs(p1, p2);
	}
	
	
	public   int compareArgs(haxe.root.Array a1, haxe.root.Array a2)
	{
		int ld = ( a1.length - a2.length );
		if (( ld != 0 )) 
		{
			return ld;
		}
		
		{
			int _g1 = 0;
			int _g = a1.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				int d = this.compareArg(a1.__get(i), a2.__get(i));
				if (( d != 0 )) 
				{
					return d;
				}
				
			}
			
		}
		
		return 0;
	}
	
	
	public   int compareArg(java.lang.Object v1, java.lang.Object v2)
	{
		if (( haxe.root.Reflect.isEnumValue(v1) && haxe.root.Reflect.isEnumValue(v2) )) 
		{
			return this.compare(((K) (v1) ), ((K) (v2) ));
		}
		 else 
		{
			if (( ( v1 instanceof haxe.root.Array ) && ( v2 instanceof haxe.root.Array ) )) 
			{
				return this.compareArgs(((haxe.root.Array) (v1) ), ((haxe.root.Array) (v2) ));
			}
			 else 
			{
				return haxe.root.Reflect.compare(v1, v2);
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef160851 = true;
			switch (field.hashCode())
			{
				case -844603599:
				{
					if (field.equals("compareArg")) 
					{
						__temp_executeDef160851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("compareArg"))) );
					}
					
					break;
				}
				
				
				case 950484197:
				{
					if (field.equals("compare")) 
					{
						__temp_executeDef160851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("compare"))) );
					}
					
					break;
				}
				
				
				case -412907678:
				{
					if (field.equals("compareArgs")) 
					{
						__temp_executeDef160851 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("compareArgs"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160851) 
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
			boolean __temp_executeDef160852 = true;
			switch (field.hashCode())
			{
				case 950484197:
				{
					if (field.equals("compare")) 
					{
						__temp_executeDef160852 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -412907678:
				{
					if (field.equals("compareArgs")) 
					{
						__temp_executeDef160852 = false;
						return this.compareArgs(((haxe.root.Array) (dynargs.__get(0)) ), ((haxe.root.Array) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -844603599:
				{
					if (field.equals("compareArg")) 
					{
						__temp_executeDef160852 = false;
						return this.compareArg(dynargs.__get(0), dynargs.__get(1));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160852) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
}


