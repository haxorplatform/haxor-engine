package haxe.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class IntMap<T> extends haxe.lang.HxObject implements haxe.root.IMap<java.lang.Object, T>
{
	static 
	{
		haxe.ds.IntMap.HASH_UPPER = 0.7;
	}
	public    IntMap(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    IntMap()
	{
		haxe.ds.IntMap.__hx_ctor_haxe_ds_IntMap(this);
	}
	
	
	public static  <T_c> void __hx_ctor_haxe_ds_IntMap(haxe.ds.IntMap<T_c> __temp_me160398)
	{
		__temp_me160398.cachedIndex = -1;
	}
	
	
	public static  double HASH_UPPER;
	
	public static   void _assert(boolean x)
	{
		{
		}
		
	}
	
	
	public static   int defaultK()
	{
		return 0;
	}
	
	
	public static   void arrayCopy(java.lang.Object sourceArray, int sourceIndex, java.lang.Object destinationArray, int destinationIndex, int length)
	{
		java.lang.System.arraycopy(((java.lang.Object) (sourceArray) ), ((int) (sourceIndex) ), ((java.lang.Object) (destinationArray) ), ((int) (destinationIndex) ), ((int) (length) ));
	}
	
	
	public static   int getInc(int k, int mask)
	{
		return ( (( ( ( k >> 3 ) ^ ( k << 3 ) ) | 1 )) & mask );
	}
	
	
	public static   int hash(int i)
	{
		return i;
	}
	
	
	public static   boolean flagIsEmpty(int[] flag, int i)
	{
		return ( (( ( flag[( i >> 4 )] >>> (( (( i & 15 )) << 1 )) ) & 2 )) != 0 );
	}
	
	
	public static   boolean flagIsDel(int[] flag, int i)
	{
		return ( (( ( flag[( i >> 4 )] >>> (( (( i & 15 )) << 1 )) ) & 1 )) != 0 );
	}
	
	
	public static   boolean isEither(int[] flag, int i)
	{
		return ( (( ( flag[( i >> 4 )] >>> (( (( i & 15 )) << 1 )) ) & 3 )) != 0 );
	}
	
	
	public static   void setIsDelFalse(int[] flag, int i)
	{
		flag[( i >> 4 )] &=  ~ ((( 1 << (( (( i & 15 )) << 1 )) ))) ;
	}
	
	
	public static   void setIsEmptyFalse(int[] flag, int i)
	{
		flag[( i >> 4 )] &=  ~ ((( 2 << (( (( i & 15 )) << 1 )) ))) ;
	}
	
	
	public static   void setIsBothFalse(int[] flag, int i)
	{
		flag[( i >> 4 )] &=  ~ ((( 3 << (( (( i & 15 )) << 1 )) ))) ;
	}
	
	
	public static   void setIsDelTrue(int[] flag, int i)
	{
		flag[( i >> 4 )] |= ( 1 << (( (( i & 15 )) << 1 )) );
	}
	
	
	public static   int roundUp(int x)
	{
		 -- x;
		x |= ( x >>> 1 );
		x |= ( x >>> 2 );
		x |= ( x >>> 4 );
		x |= ( x >>> 8 );
		x |= ( x >>> 16 );
		return  ++ x;
	}
	
	
	public static   int flagsSize(int m)
	{
		if (( m < 16 )) 
		{
			return 1;
		}
		 else 
		{
			return ( m >> 4 );
		}
		
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
	
	public   void set(java.lang.Object k, T v)
	{
		this.set(((int) (haxe.lang.Runtime.toInt(k)) ), ((T) (v) ));
	}
	
	
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
	
	
	public   T get(java.lang.Object k)
	{
		return ((T) (this.get(((int) (haxe.lang.Runtime.toInt(k)) ))) );
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
	
	
	public   T getDefault(int key, T def)
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
		
		return def;
	}
	
	
	public   boolean exists(java.lang.Object k)
	{
		return haxe.lang.Runtime.toBool(this.exists(((int) (haxe.lang.Runtime.toInt(k)) )));
	}
	
	
	public   boolean exists(int key)
	{
		int idx = -1;
		if (( ( this.cachedKey == key ) && ( (idx = this.cachedIndex) != -1 ) )) 
		{
			return true;
		}
		
		idx = this.lookup(key);
		if (( idx != -1 )) 
		{
			this.cachedKey = key;
			this.cachedIndex = idx;
			return true;
		}
		
		return false;
	}
	
	
	public   boolean remove(java.lang.Object k)
	{
		return haxe.lang.Runtime.toBool(this.remove(((int) (haxe.lang.Runtime.toInt(k)) )));
	}
	
	
	public   boolean remove(int key)
	{
		int idx = -1;
		if ( ! ((( ( this.cachedKey == key ) && ( (idx = this.cachedIndex) != -1 ) ))) ) 
		{
			idx = this.lookup(key);
		}
		
		if (( idx == -1 )) 
		{
			return false;
		}
		 else 
		{
			if (( this.cachedKey == key )) 
			{
				this.cachedIndex = -1;
			}
			
			if ( ! ((( (( ( this.flags[( idx >> 4 )] >>> (( (( idx & 15 )) << 1 )) ) & 3 )) != 0 ))) ) 
			{
				this.flags[( idx >> 4 )] |= ( 1 << (( (( idx & 15 )) << 1 )) );
				 -- this.size;
				this.vals[idx] = null;
				this._keys[idx] = 0;
			}
			
			return true;
		}
		
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
	
	
	public   java.lang.Object keys()
	{
		haxe.root.Array<haxe.ds.IntMap> _g1 = new haxe.root.Array<haxe.ds.IntMap>(new haxe.ds.IntMap[]{((haxe.ds.IntMap) (this) )});
		haxe.root.Array<java.lang.Object> i = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0});
		haxe.root.Array<java.lang.Object> len = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{this.nBuckets});
		{
			haxe.lang.Function __temp_odecl160855 = new haxe.ds.IntMap_keys_332__Fun<T>(((haxe.root.Array<java.lang.Object>) (len) ), ((haxe.root.Array<haxe.ds.IntMap>) (_g1) ), ((haxe.root.Array<java.lang.Object>) (i) ));
			haxe.lang.Function __temp_odecl160856 = new haxe.ds.IntMap_keys_343__Fun<T>(((haxe.root.Array<java.lang.Object>) (i) ), ((haxe.root.Array<haxe.ds.IntMap>) (_g1) ));
			return new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"hasNext", "next"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl160855, __temp_odecl160856}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		}
		
	}
	
	
	public   java.lang.Object iterator()
	{
		haxe.root.Array<haxe.ds.IntMap> _g1 = new haxe.root.Array<haxe.ds.IntMap>(new haxe.ds.IntMap[]{((haxe.ds.IntMap) (this) )});
		haxe.root.Array<java.lang.Object> i = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0});
		haxe.root.Array<java.lang.Object> len = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{this.nBuckets});
		{
			haxe.lang.Function __temp_odecl160857 = new haxe.ds.IntMap_iterator_363__Fun<T>(((haxe.root.Array<haxe.ds.IntMap>) (_g1) ), ((haxe.root.Array<java.lang.Object>) (len) ), ((haxe.root.Array<java.lang.Object>) (i) ));
			haxe.lang.Function __temp_odecl160858 = new haxe.ds.IntMap_iterator_374__Fun<T>(((haxe.root.Array<haxe.ds.IntMap>) (_g1) ), ((haxe.root.Array<java.lang.Object>) (i) ));
			return new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"hasNext", "next"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl160857, __temp_odecl160858}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		}
		
	}
	
	
	@Override public   java.lang.String toString()
	{
		haxe.root.StringBuf s = new haxe.root.StringBuf();
		s.add("{");
		java.lang.Object it = this.keys();
		{
			java.lang.Object __temp_iterator160724 = it;
			while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(__temp_iterator160724, "hasNext", null)))
			{
				int i = ((int) (haxe.lang.Runtime.toInt(haxe.lang.Runtime.callField(__temp_iterator160724, "next", null))) );
				s.add(i);
				s.add(" => ");
				s.add(haxe.root.Std.string(this.get(((int) (i) ))));
				if (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(it, "hasNext", null))) 
				{
					s.add(", ");
				}
				
			}
			
		}
		
		s.add("}");
		return s.toString();
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef160859 = true;
			switch (field.hashCode())
			{
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef160859 = false;
						this.cachedIndex = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef160859 = false;
						this.nBuckets = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -553141795:
				{
					if (field.equals("cachedKey")) 
					{
						__temp_executeDef160859 = false;
						this.cachedKey = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef160859 = false;
						this.size = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef160859 = false;
						this.upperBound = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef160859 = false;
						this.nOccupied = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160859) 
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
			boolean __temp_executeDef160860 = true;
			switch (field.hashCode())
			{
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef160860 = false;
						this.cachedIndex = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 97513095:
				{
					if (field.equals("flags")) 
					{
						__temp_executeDef160860 = false;
						this.flags = ((int[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -553141795:
				{
					if (field.equals("cachedKey")) 
					{
						__temp_executeDef160860 = false;
						this.cachedKey = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 91023059:
				{
					if (field.equals("_keys")) 
					{
						__temp_executeDef160860 = false;
						this._keys = ((int[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef160860 = false;
						this.upperBound = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3612018:
				{
					if (field.equals("vals")) 
					{
						__temp_executeDef160860 = false;
						this.vals = ((T[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef160860 = false;
						this.nOccupied = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef160860 = false;
						this.nBuckets = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef160860 = false;
						this.size = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160860) 
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
			boolean __temp_executeDef160861 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef160861 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("toString"))) );
					}
					
					break;
				}
				
				
				case 97513095:
				{
					if (field.equals("flags")) 
					{
						__temp_executeDef160861 = false;
						return this.flags;
					}
					
					break;
				}
				
				
				case 1182533742:
				{
					if (field.equals("iterator")) 
					{
						__temp_executeDef160861 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("iterator"))) );
					}
					
					break;
				}
				
				
				case 91023059:
				{
					if (field.equals("_keys")) 
					{
						__temp_executeDef160861 = false;
						return this._keys;
					}
					
					break;
				}
				
				
				case 3288564:
				{
					if (field.equals("keys")) 
					{
						__temp_executeDef160861 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("keys"))) );
					}
					
					break;
				}
				
				
				case 3612018:
				{
					if (field.equals("vals")) 
					{
						__temp_executeDef160861 = false;
						return this.vals;
					}
					
					break;
				}
				
				
				case -934437708:
				{
					if (field.equals("resize")) 
					{
						__temp_executeDef160861 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("resize"))) );
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef160861 = false;
						return this.nBuckets;
					}
					
					break;
				}
				
				
				case -934610812:
				{
					if (field.equals("remove")) 
					{
						__temp_executeDef160861 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("remove"))) );
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef160861 = false;
						return this.size;
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef160861 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("exists"))) );
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef160861 = false;
						return this.nOccupied;
					}
					
					break;
				}
				
				
				case -1713303029:
				{
					if (field.equals("getDefault")) 
					{
						__temp_executeDef160861 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getDefault"))) );
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef160861 = false;
						return this.upperBound;
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef160861 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get"))) );
					}
					
					break;
				}
				
				
				case -553141795:
				{
					if (field.equals("cachedKey")) 
					{
						__temp_executeDef160861 = false;
						return this.cachedKey;
					}
					
					break;
				}
				
				
				case -1097094790:
				{
					if (field.equals("lookup")) 
					{
						__temp_executeDef160861 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("lookup"))) );
					}
					
					break;
				}
				
				
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef160861 = false;
						return this.cachedIndex;
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef160861 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160861) 
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
			boolean __temp_executeDef160862 = true;
			switch (field.hashCode())
			{
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef160862 = false;
						return ((double) (this.cachedIndex) );
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef160862 = false;
						return ((double) (this.nBuckets) );
					}
					
					break;
				}
				
				
				case -553141795:
				{
					if (field.equals("cachedKey")) 
					{
						__temp_executeDef160862 = false;
						return ((double) (this.cachedKey) );
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef160862 = false;
						return ((double) (this.size) );
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef160862 = false;
						return ((double) (this.upperBound) );
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef160862 = false;
						return ((double) (this.nOccupied) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160862) 
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
			boolean __temp_executeDef160863 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef160863 = false;
						return this.toString();
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef160863 = false;
						this.set(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((T) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1182533742:
				{
					if (field.equals("iterator")) 
					{
						__temp_executeDef160863 = false;
						return this.iterator();
					}
					
					break;
				}
				
				
				case -1097094790:
				{
					if (field.equals("lookup")) 
					{
						__temp_executeDef160863 = false;
						return this.lookup(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 3288564:
				{
					if (field.equals("keys")) 
					{
						__temp_executeDef160863 = false;
						return this.keys();
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef160863 = false;
						return this.get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -934437708:
				{
					if (field.equals("resize")) 
					{
						__temp_executeDef160863 = false;
						this.resize(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1713303029:
				{
					if (field.equals("getDefault")) 
					{
						__temp_executeDef160863 = false;
						return this.getDefault(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((T) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -934610812:
				{
					if (field.equals("remove")) 
					{
						__temp_executeDef160863 = false;
						return this.remove(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef160863 = false;
						return this.exists(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160863) 
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


