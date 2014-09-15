package haxe.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class StringMap<T> extends haxe.lang.HxObject implements haxe.root.IMap<java.lang.String, T>
{
	public    StringMap(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    StringMap()
	{
		haxe.ds.StringMap.__hx_ctor_haxe_ds_StringMap(this);
	}
	
	
	public static  <T_c> void __hx_ctor_haxe_ds_StringMap(haxe.ds.StringMap<T_c> __temp_me255338)
	{
		__temp_me255338.cachedIndex = -1;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.ds.StringMap<java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.ds.StringMap<java.lang.Object>();
	}
	
	
	public  int[] hashes;
	
	public  java.lang.String[] _keys;
	
	public  T[] vals;
	
	public  int nBuckets;
	
	public  int size;
	
	public  int nOccupied;
	
	public  int upperBound;
	
	public  java.lang.String cachedKey;
	
	public  int cachedIndex;
	
	public   void set(java.lang.String key, T value)
	{
		int x = 0;
		int k = 0;
		if (( this.nOccupied >= this.upperBound )) 
		{
			if (( this.nBuckets > ( this.size << 1 ) )) 
			{
				this.resize(( this.nBuckets - 1 ));
			}
			 else 
			{
				this.resize(( this.nBuckets + 2 ));
			}
			
		}
		
		int[] hashes = this.hashes;
		java.lang.String[] keys = this._keys;
		int[] hashes1 = hashes;
		{
			int mask = 0;
			if (( this.nBuckets == 0 )) 
			{
				mask = 0;
			}
			 else 
			{
				mask = ( this.nBuckets - 1 );
			}
			
			int site = x = this.nBuckets;
			{
				int k1 = key.hashCode();
				k1 = ( ( k1 + 2127912214 ) + (( k1 << 12 )) );
				k1 = ( ( k1 ^ -949894596 ) ^ ( k1 >> 19 ) );
				k1 = ( ( k1 + 374761393 ) + (( k1 << 5 )) );
				k1 = ( ( k1 + -744332180 ) ^ ( k1 << 9 ) );
				k1 = ( ( k1 + -42973499 ) + (( k1 << 3 )) );
				k1 = ( ( k1 ^ -1252372727 ) ^ ( k1 >> 16 ) );
				int ret = k1;
				if (( (( ret & -2 )) == 0 )) 
				{
					if (( ret == 0 )) 
					{
						ret = 2;
					}
					 else 
					{
						ret = -1;
					}
					
				}
				
				k = ret;
			}
			
			int i = ( k & mask );
			int nProbes = 0;
			if (( (( hashes1[i] & -2 )) == 0 )) 
			{
				x = i;
			}
			 else 
			{
				int last = i;
				int flag = 0;
				do 
				{
					boolean __temp_stmt255778 = false;
					{
						int v = flag = hashes1[i];
						__temp_stmt255778 = ( (( v & -2 )) == 0 );
					}
					
					boolean __temp_boolv255779 = false;
					if ( ! (__temp_stmt255778) ) 
					{
						__temp_boolv255779 = ( ( flag == k ) && haxe.lang.Runtime.valEq(this._keys[i], key) );
					}
					
					boolean __temp_stmt255777 = ( __temp_stmt255778 || __temp_boolv255779 );
					if ( ! ((__temp_stmt255777)) ) 
					{
						i = ( ( i +  ++ nProbes ) & mask );
					}
					 else 
					{
						break;
					}
					
				}
				while (true);
				x = i;
			}
			
		}
		
		int flag1 = hashes1[x];
		if (( flag1 == 0 )) 
		{
			keys[x] = key;
			this.vals[x] = value;
			hashes1[x] = k;
			this.size++;
			this.nOccupied++;
		}
		 else 
		{
			if (( flag1 == 1 )) 
			{
				keys[x] = key;
				this.vals[x] = value;
				hashes1[x] = k;
				this.size++;
			}
			 else 
			{
				this.vals[x] = value;
			}
			
		}
		
		this.cachedIndex = x;
		this.cachedKey = key;
	}
	
	
	public   int lookup(java.lang.String key)
	{
		if (( this.nBuckets != 0 )) 
		{
			int[] hashes = this.hashes;
			java.lang.String[] keys = this._keys;
			int mask = ( this.nBuckets - 1 );
			int hash = 0;
			{
				int k = key.hashCode();
				k = ( ( k + 2127912214 ) + (( k << 12 )) );
				k = ( ( k ^ -949894596 ) ^ ( k >> 19 ) );
				k = ( ( k + 374761393 ) + (( k << 5 )) );
				k = ( ( k + -744332180 ) ^ ( k << 9 ) );
				k = ( ( k + -42973499 ) + (( k << 3 )) );
				k = ( ( k ^ -1252372727 ) ^ ( k >> 16 ) );
				int ret = k;
				if (( (( ret & -2 )) == 0 )) 
				{
					if (( ret == 0 )) 
					{
						ret = 2;
					}
					 else 
					{
						ret = -1;
					}
					
				}
				
				hash = ret;
			}
			
			int k1 = hash;
			int nProbes = 0;
			int i = ( k1 & mask );
			int last = i;
			int flag = 0;
			do 
			{
				boolean __temp_stmt255783 = false;
				{
					int v = flag = hashes[i];
					__temp_stmt255783 = ( v == 0 );
				}
				
				boolean __temp_boolv255782 =  ! (__temp_stmt255783) ;
				boolean __temp_boolv255781 = false;
				if (__temp_boolv255782) 
				{
					__temp_boolv255781 = (( ( ( flag == 1 ) || ( flag != k1 ) ) ||  ! (haxe.lang.Runtime.valEq(keys[i], key))  ));
				}
				
				boolean __temp_stmt255780 = ( __temp_boolv255782 && __temp_boolv255781 );
				if (__temp_stmt255780) 
				{
					i = ( ( i +  ++ nProbes ) & mask );
				}
				 else 
				{
					break;
				}
				
			}
			while (true);
			if (( (( flag & -2 )) == 0 )) 
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
	
	
	public   void resize(int newNBuckets)
	{
		int[] newHash = null;
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
			
			if (( this.size >= ( ( newNBuckets * 0.77 ) + 0.5 ) )) 
			{
				j = 0;
			}
			 else 
			{
				int nfSize = newNBuckets;
				newHash = new int[((int) (nfSize) )];
				if (( this.nBuckets < newNBuckets )) 
				{
					java.lang.String[] k = new java.lang.String[((int) (newNBuckets) )];
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
			this.cachedKey = null;
			this.cachedIndex = -1;
			j = -1;
			int nBuckets = this.nBuckets;
			java.lang.String[] _keys = this._keys;
			T[] vals = this.vals;
			int[] hashes = this.hashes;
			int newMask = ( newNBuckets - 1 );
			while ((  ++ j < nBuckets ))
			{
				int k1 = 0;
				boolean __temp_stmt255784 = false;
				{
					int v1 = k1 = hashes[j];
					__temp_stmt255784 = ( (( v1 & -2 )) == 0 );
				}
				
				if ( ! (__temp_stmt255784) ) 
				{
					java.lang.String key = _keys[j];
					T val = vals[j];
					hashes[j] = 1;
					while (true)
					{
						int nProbes = 0;
						int i = ( k1 & newMask );
						while ( ! ((( newHash[i] == 0 ))) )
						{
							i = ( ( i +  ++ nProbes ) & newMask );
						}
						
						newHash[i] = k1;
						boolean __temp_boolv255787 = ( i < nBuckets );
						boolean __temp_boolv255786 = false;
						if (__temp_boolv255787) 
						{
							boolean __temp_stmt255788 = false;
							{
								int v2 = k1 = hashes[i];
								__temp_stmt255788 = ( (( v2 & -2 )) == 0 );
							}
							
							__temp_boolv255786 =  ! (__temp_stmt255788) ;
						}
						
						boolean __temp_stmt255785 = ( __temp_boolv255787 && __temp_boolv255786 );
						if (__temp_stmt255785) 
						{
							{
								java.lang.String tmp = _keys[i];
								_keys[i] = key;
								key = tmp;
							}
							
							{
								T tmp1 = vals[i];
								vals[i] = val;
								val = tmp1;
							}
							
							hashes[i] = 1;
						}
						 else 
						{
							_keys[i] = key;
							vals[i] = val;
							break;
						}
						
					}
					
				}
				
			}
			
			if (( nBuckets > newNBuckets )) 
			{
				{
					java.lang.String[] k2 = new java.lang.String[((int) (newNBuckets) )];
					java.lang.System.arraycopy(((java.lang.Object) (_keys) ), ((int) (0) ), ((java.lang.Object) (k2) ), ((int) (0) ), ((int) (newNBuckets) ));
					this._keys = k2;
				}
				
				{
					T[] v3 = ((T[]) (((java.lang.Object) (new java.lang.Object[((int) (newNBuckets) )]) )) );
					java.lang.System.arraycopy(((java.lang.Object) (vals) ), ((int) (0) ), ((java.lang.Object) (v3) ), ((int) (0) ), ((int) (newNBuckets) ));
					this.vals = v3;
				}
				
			}
			
			this.hashes = newHash;
			this.nBuckets = newNBuckets;
			this.nOccupied = this.size;
			this.upperBound = ((int) (( ( newNBuckets * 0.77 ) + .5 )) );
		}
		
	}
	
	
	public   T get(java.lang.String key)
	{
		int idx = -1;
		if (( haxe.lang.Runtime.valEq(this.cachedKey, key) && ( (idx = this.cachedIndex) != -1 ) )) 
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
	
	
	public   boolean exists(java.lang.String key)
	{
		int idx = -1;
		if (( haxe.lang.Runtime.valEq(this.cachedKey, key) && ( (idx = this.cachedIndex) != -1 ) )) 
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
	
	
	public   boolean remove(java.lang.String key)
	{
		int idx = -1;
		if ( ! ((( haxe.lang.Runtime.valEq(this.cachedKey, key) && ( (idx = this.cachedIndex) != -1 ) ))) ) 
		{
			idx = this.lookup(key);
		}
		
		if (( idx == -1 )) 
		{
			return false;
		}
		 else 
		{
			if (haxe.lang.Runtime.valEq(this.cachedKey, key)) 
			{
				this.cachedIndex = -1;
			}
			
			this.hashes[idx] = 1;
			this._keys[idx] = null;
			this.vals[idx] = null;
			 -- this.size;
			return true;
		}
		
	}
	
	
	public   java.lang.Object keys()
	{
		haxe.root.Array<haxe.ds.StringMap> _g1 = new haxe.root.Array<haxe.ds.StringMap>(new haxe.ds.StringMap[]{((haxe.ds.StringMap) (this) )});
		haxe.root.Array<java.lang.Object> i = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0});
		haxe.root.Array<java.lang.Object> len = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{this.nBuckets});
		{
			haxe.lang.Function __temp_odecl255789 = new haxe.ds.StringMap_keys_356__Fun<T>(((haxe.root.Array<haxe.ds.StringMap>) (_g1) ), ((haxe.root.Array<java.lang.Object>) (len) ), ((haxe.root.Array<java.lang.Object>) (i) ));
			haxe.lang.Function __temp_odecl255790 = new haxe.ds.StringMap_keys_367__Fun<T>(((haxe.root.Array<haxe.ds.StringMap>) (_g1) ), ((haxe.root.Array<java.lang.Object>) (i) ));
			return new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"hasNext", "next"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl255789, __temp_odecl255790}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef255791 = true;
			switch (field.hashCode())
			{
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef255791 = false;
						this.cachedIndex = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef255791 = false;
						this.nBuckets = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef255791 = false;
						this.upperBound = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef255791 = false;
						this.size = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef255791 = false;
						this.nOccupied = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255791) 
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
			boolean __temp_executeDef255792 = true;
			switch (field.hashCode())
			{
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef255792 = false;
						this.cachedIndex = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1224424900:
				{
					if (field.equals("hashes")) 
					{
						__temp_executeDef255792 = false;
						this.hashes = ((int[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -553141795:
				{
					if (field.equals("cachedKey")) 
					{
						__temp_executeDef255792 = false;
						this.cachedKey = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 91023059:
				{
					if (field.equals("_keys")) 
					{
						__temp_executeDef255792 = false;
						this._keys = ((java.lang.String[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef255792 = false;
						this.upperBound = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3612018:
				{
					if (field.equals("vals")) 
					{
						__temp_executeDef255792 = false;
						this.vals = ((T[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef255792 = false;
						this.nOccupied = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef255792 = false;
						this.nBuckets = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef255792 = false;
						this.size = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255792) 
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
			boolean __temp_executeDef255793 = true;
			switch (field.hashCode())
			{
				case 3288564:
				{
					if (field.equals("keys")) 
					{
						__temp_executeDef255793 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("keys"))) );
					}
					
					break;
				}
				
				
				case -1224424900:
				{
					if (field.equals("hashes")) 
					{
						__temp_executeDef255793 = false;
						return this.hashes;
					}
					
					break;
				}
				
				
				case -934610812:
				{
					if (field.equals("remove")) 
					{
						__temp_executeDef255793 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("remove"))) );
					}
					
					break;
				}
				
				
				case 91023059:
				{
					if (field.equals("_keys")) 
					{
						__temp_executeDef255793 = false;
						return this._keys;
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef255793 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("exists"))) );
					}
					
					break;
				}
				
				
				case 3612018:
				{
					if (field.equals("vals")) 
					{
						__temp_executeDef255793 = false;
						return this.vals;
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef255793 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get"))) );
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef255793 = false;
						return this.nBuckets;
					}
					
					break;
				}
				
				
				case -934437708:
				{
					if (field.equals("resize")) 
					{
						__temp_executeDef255793 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("resize"))) );
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef255793 = false;
						return this.size;
					}
					
					break;
				}
				
				
				case -1097094790:
				{
					if (field.equals("lookup")) 
					{
						__temp_executeDef255793 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("lookup"))) );
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef255793 = false;
						return this.nOccupied;
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef255793 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set"))) );
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef255793 = false;
						return this.upperBound;
					}
					
					break;
				}
				
				
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef255793 = false;
						return this.cachedIndex;
					}
					
					break;
				}
				
				
				case -553141795:
				{
					if (field.equals("cachedKey")) 
					{
						__temp_executeDef255793 = false;
						return this.cachedKey;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255793) 
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
			boolean __temp_executeDef255794 = true;
			switch (field.hashCode())
			{
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef255794 = false;
						return ((double) (this.cachedIndex) );
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef255794 = false;
						return ((double) (this.nBuckets) );
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef255794 = false;
						return ((double) (this.upperBound) );
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef255794 = false;
						return ((double) (this.size) );
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef255794 = false;
						return ((double) (this.nOccupied) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255794) 
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
			boolean __temp_executeDef255795 = true;
			switch (field.hashCode())
			{
				case 3288564:
				{
					if (field.equals("keys")) 
					{
						__temp_executeDef255795 = false;
						return this.keys();
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef255795 = false;
						this.set(haxe.lang.Runtime.toString(dynargs.__get(0)), ((T) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -934610812:
				{
					if (field.equals("remove")) 
					{
						__temp_executeDef255795 = false;
						return this.remove(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1097094790:
				{
					if (field.equals("lookup")) 
					{
						__temp_executeDef255795 = false;
						return this.lookup(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef255795 = false;
						return this.exists(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -934437708:
				{
					if (field.equals("resize")) 
					{
						__temp_executeDef255795 = false;
						this.resize(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef255795 = false;
						return this.get(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255795) 
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
		baseArr.push("hashes");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


