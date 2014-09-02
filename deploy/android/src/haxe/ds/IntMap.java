package haxe.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class IntMap<T> extends haxe.lang.HxObject implements haxe.root.IMap<java.lang.Object, T>
{
	public    IntMap(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    IntMap()
	{
		haxe.ds.IntMap.__hx_ctor_haxe_ds_IntMap(this);
	}
	
	
	public static  <T_c> void __hx_ctor_haxe_ds_IntMap(haxe.ds.IntMap<T_c> __temp_me164141)
	{
		__temp_me164141.cachedIndex = -1;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.ds.IntMap<java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.ds.IntMap<java.lang.Object>();
	}
	
	
	public  int[] flags;
	
	public  int[] _keys;
	
	public  T[] vals;
	
	public  int nBuckets;
	
	public  int size;
	
	public  int nOccupied;
	
	public  int upperBound;
	
	public  int cachedKey;
	
	public  int cachedIndex;
	
	public   void set(int key, T value)
	{
		int x = 0;
		if (( this.nOccupied >= this.upperBound )) 
		{
			if (( this.nBuckets > ( this.size << 1 ) )) 
			{
				this.resize(( this.nBuckets - 1 ));
			}
			 else 
			{
				this.resize(( this.nBuckets + 1 ));
			}
			
		}
		
		int[] flags = this.flags;
		int[] _keys = this._keys;
		{
			int mask = ( this.nBuckets - 1 );
			int site = x = this.nBuckets;
			int k = key;
			int i = ( k & mask );
			if (( (( ( flags[( i >> 4 )] >>> (( (( i & 15 )) << 1 )) ) & 2 )) != 0 )) 
			{
				x = i;
			}
			 else 
			{
				int inc = ( (( ( ( k >> 3 ) ^ ( k << 3 ) ) | 1 )) & mask );
				int last = i;
				while ( ! ((( ( (( ( flags[( i >> 4 )] >>> (( (( i & 15 )) << 1 )) ) & 3 )) != 0 ) || ( _keys[i] == key ) ))) )
				{
					i = ( ( i + inc ) & mask );
				}
				
				x = i;
			}
			
		}
		
		if (( (( ( flags[( x >> 4 )] >>> (( (( x & 15 )) << 1 )) ) & 2 )) != 0 )) 
		{
			_keys[x] = key;
			this.vals[x] = value;
			flags[( x >> 4 )] &=  ~ ((( 3 << (( (( x & 15 )) << 1 )) ))) ;
			this.size++;
			this.nOccupied++;
		}
		 else 
		{
			if (( (( ( flags[( x >> 4 )] >>> (( (( x & 15 )) << 1 )) ) & 1 )) != 0 )) 
			{
				_keys[x] = key;
				this.vals[x] = value;
				flags[( x >> 4 )] &=  ~ ((( 3 << (( (( x & 15 )) << 1 )) ))) ;
				this.size++;
			}
			 else 
			{
				this.vals[x] = value;
			}
			
		}
		
	}
	
	
	public   int lookup(int key)
	{
		if (( this.nBuckets != 0 )) 
		{
			int[] flags = this.flags;
			int[] _keys = this._keys;
			int mask = ( this.nBuckets - 1 );
			int k = key;
			int i = ( k & mask );
			int inc = ( (( ( ( k >> 3 ) ^ ( k << 3 ) ) | 1 )) & mask );
			int last = i;
			while ((  ! ((( (( ( flags[( i >> 4 )] >>> (( (( i & 15 )) << 1 )) ) & 2 )) != 0 )))  && (( ( (( ( flags[( i >> 4 )] >>> (( (( i & 15 )) << 1 )) ) & 1 )) != 0 ) || ( _keys[i] != key ) )) ))
			{
				i = ( ( i + inc ) & mask );
				if (( i == last )) 
				{
					return -1;
				}
				
			}
			
			if (( (( ( flags[( i >> 4 )] >>> (( (( i & 15 )) << 1 )) ) & 3 )) != 0 )) 
			{
				return -1;
			}
			 else 
			{
				return i;
			}
			
		}
		
		return -1;
	}
	
	
	public   T get(int key)
	{
		int idx = -1;
		if (( ( this.cachedKey == key ) && ( (idx = this.cachedIndex) != -1 ) )) 
		{
			return this.vals[idx];
		}
		
		idx = this.lookup(key);
		if (( idx != -1 )) 
		{
			this.cachedKey = key;
			this.cachedIndex = idx;
			return this.vals[idx];
		}
		
		return null;
	}
	
	
	public   void resize(int newNBuckets)
	{
		int[] newFlags = null;
		int j = 1;
		{
			{
				int x = newNBuckets;
				 -- x;
				x |= ( x >>> 1 );
				x |= ( x >>> 2 );
				x |= ( x >>> 4 );
				x |= ( x >>> 8 );
				x |= ( x >>> 16 );
				newNBuckets =  ++ x;
			}
			
			if (( newNBuckets < 4 )) 
			{
				newNBuckets = 4;
			}
			
			if (( this.size >= ( ( newNBuckets * 0.7 ) + 0.5 ) )) 
			{
				j = 0;
			}
			 else 
			{
				int nfSize = 0;
				if (( newNBuckets < 16 )) 
				{
					nfSize = 1;
				}
				 else 
				{
					nfSize = ( newNBuckets >> 4 );
				}
				
				newFlags = new int[((int) (nfSize) )];
				{
					int _g = 0;
					while (( _g < ((int) (nfSize) ) ))
					{
						int i = _g++;
						newFlags[i] = -1431655766;
					}
					
				}
				
				if (( this.nBuckets < newNBuckets )) 
				{
					int[] k = new int[((int) (newNBuckets) )];
					if (( this._keys != null )) 
					{
						java.lang.System.arraycopy(((java.lang.Object) (this._keys) ), ((int) (0) ), ((java.lang.Object) (k) ), ((int) (0) ), ((int) (this.nBuckets) ));
					}
					
					this._keys = k;
					T[] v = ((T[]) (((java.lang.Object) (new java.lang.Object[((int) (newNBuckets) )]) )) );
					if (( this.vals != null )) 
					{
						java.lang.System.arraycopy(((java.lang.Object) (this.vals) ), ((int) (0) ), ((java.lang.Object) (v) ), ((int) (0) ), ((int) (this.nBuckets) ));
					}
					
					this.vals = v;
				}
				
			}
			
		}
		
		if (( j != 0 )) 
		{
			this.cachedKey = 0;
			this.cachedIndex = -1;
			j = -1;
			int nBuckets = this.nBuckets;
			int[] _keys = this._keys;
			T[] vals = this.vals;
			int[] flags = this.flags;
			int newMask = ( newNBuckets - 1 );
			while ((  ++ j < nBuckets ))
			{
				if ( ! ((( (( ( flags[( j >> 4 )] >>> (( (( j & 15 )) << 1 )) ) & 3 )) != 0 ))) ) 
				{
					int key = _keys[j];
					T val = vals[j];
					flags[( j >> 4 )] |= ( 1 << (( (( j & 15 )) << 1 )) );
					while (true)
					{
						int k1 = key;
						int inc = ( (( ( ( k1 >> 3 ) ^ ( k1 << 3 ) ) | 1 )) & newMask );
						int i1 = ( k1 & newMask );
						while ( ! ((( (( ( newFlags[( i1 >> 4 )] >>> (( (( i1 & 15 )) << 1 )) ) & 2 )) != 0 ))) )
						{
							i1 = ( ( i1 + inc ) & newMask );
						}
						
						newFlags[( i1 >> 4 )] &=  ~ ((( 2 << (( (( i1 & 15 )) << 1 )) ))) ;
						if (( ( i1 < nBuckets ) &&  ! ((( (( ( flags[( i1 >> 4 )] >>> (( (( i1 & 15 )) << 1 )) ) & 3 )) != 0 )))  )) 
						{
							{
								int tmp = _keys[i1];
								_keys[i1] = key;
								key = tmp;
							}
							
							{
								T tmp1 = vals[i1];
								vals[i1] = val;
								val = tmp1;
							}
							
							flags[( i1 >> 4 )] |= ( 1 << (( (( i1 & 15 )) << 1 )) );
						}
						 else 
						{
							_keys[i1] = key;
							vals[i1] = val;
							break;
						}
						
					}
					
				}
				
			}
			
			if (( nBuckets > newNBuckets )) 
			{
				{
					int[] k2 = new int[((int) (newNBuckets) )];
					java.lang.System.arraycopy(((java.lang.Object) (_keys) ), ((int) (0) ), ((java.lang.Object) (k2) ), ((int) (0) ), ((int) (newNBuckets) ));
					this._keys = k2;
				}
				
				{
					T[] v1 = ((T[]) (((java.lang.Object) (new java.lang.Object[((int) (newNBuckets) )]) )) );
					java.lang.System.arraycopy(((java.lang.Object) (vals) ), ((int) (0) ), ((java.lang.Object) (v1) ), ((int) (0) ), ((int) (newNBuckets) ));
					this.vals = v1;
				}
				
			}
			
			this.flags = newFlags;
			this.nBuckets = newNBuckets;
			this.nOccupied = this.size;
			this.upperBound = ((int) (( ( newNBuckets * 0.7 ) + .5 )) );
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef164557 = true;
			switch (field.hashCode())
			{
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef164557 = false;
						this.cachedIndex = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef164557 = false;
						this.nBuckets = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -553141795:
				{
					if (field.equals("cachedKey")) 
					{
						__temp_executeDef164557 = false;
						this.cachedKey = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef164557 = false;
						this.size = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef164557 = false;
						this.upperBound = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef164557 = false;
						this.nOccupied = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164557) 
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
			boolean __temp_executeDef164558 = true;
			switch (field.hashCode())
			{
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef164558 = false;
						this.cachedIndex = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 97513095:
				{
					if (field.equals("flags")) 
					{
						__temp_executeDef164558 = false;
						this.flags = ((int[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -553141795:
				{
					if (field.equals("cachedKey")) 
					{
						__temp_executeDef164558 = false;
						this.cachedKey = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 91023059:
				{
					if (field.equals("_keys")) 
					{
						__temp_executeDef164558 = false;
						this._keys = ((int[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef164558 = false;
						this.upperBound = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3612018:
				{
					if (field.equals("vals")) 
					{
						__temp_executeDef164558 = false;
						this.vals = ((T[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef164558 = false;
						this.nOccupied = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef164558 = false;
						this.nBuckets = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef164558 = false;
						this.size = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164558) 
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
			boolean __temp_executeDef164559 = true;
			switch (field.hashCode())
			{
				case -934437708:
				{
					if (field.equals("resize")) 
					{
						__temp_executeDef164559 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("resize"))) );
					}
					
					break;
				}
				
				
				case 97513095:
				{
					if (field.equals("flags")) 
					{
						__temp_executeDef164559 = false;
						return this.flags;
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef164559 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get"))) );
					}
					
					break;
				}
				
				
				case 91023059:
				{
					if (field.equals("_keys")) 
					{
						__temp_executeDef164559 = false;
						return this._keys;
					}
					
					break;
				}
				
				
				case -1097094790:
				{
					if (field.equals("lookup")) 
					{
						__temp_executeDef164559 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("lookup"))) );
					}
					
					break;
				}
				
				
				case 3612018:
				{
					if (field.equals("vals")) 
					{
						__temp_executeDef164559 = false;
						return this.vals;
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef164559 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set"))) );
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef164559 = false;
						return this.nBuckets;
					}
					
					break;
				}
				
				
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef164559 = false;
						return this.cachedIndex;
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef164559 = false;
						return this.size;
					}
					
					break;
				}
				
				
				case -553141795:
				{
					if (field.equals("cachedKey")) 
					{
						__temp_executeDef164559 = false;
						return this.cachedKey;
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef164559 = false;
						return this.nOccupied;
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef164559 = false;
						return this.upperBound;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164559) 
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
			boolean __temp_executeDef164560 = true;
			switch (field.hashCode())
			{
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef164560 = false;
						return ((double) (this.cachedIndex) );
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef164560 = false;
						return ((double) (this.nBuckets) );
					}
					
					break;
				}
				
				
				case -553141795:
				{
					if (field.equals("cachedKey")) 
					{
						__temp_executeDef164560 = false;
						return ((double) (this.cachedKey) );
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef164560 = false;
						return ((double) (this.size) );
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef164560 = false;
						return ((double) (this.upperBound) );
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef164560 = false;
						return ((double) (this.nOccupied) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164560) 
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
			boolean __temp_executeDef164561 = true;
			switch (field.hashCode())
			{
				case -934437708:
				{
					if (field.equals("resize")) 
					{
						__temp_executeDef164561 = false;
						this.resize(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef164561 = false;
						this.set(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((T) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef164561 = false;
						return this.get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1097094790:
				{
					if (field.equals("lookup")) 
					{
						__temp_executeDef164561 = false;
						return this.lookup(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef164561) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("cachedIndex");
		baseArr.push("cachedKey");
		baseArr.push("upperBound");
		baseArr.push("nOccupied");
		baseArr.push("size");
		baseArr.push("nBuckets");
		baseArr.push("vals");
		baseArr.push("_keys");
		baseArr.push("flags");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


