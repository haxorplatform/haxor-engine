package haxe.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class WeakMap<K, V> extends haxe.lang.HxObject implements haxe.root.IMap<K, V>
{
	public    WeakMap(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    WeakMap()
	{
		haxe.ds.WeakMap.__hx_ctor_haxe_ds_WeakMap(this);
	}
	
	
	public static  <K_c, V_c> void __hx_ctor_haxe_ds_WeakMap(haxe.ds.WeakMap<K_c, V_c> __temp_me80555)
	{
		__temp_me80555.cachedIndex = -1;
		__temp_me80555.queue = new java.lang.ref.ReferenceQueue<K_c>();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.ds.WeakMap<java.lang.Object, java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.ds.WeakMap<java.lang.Object, java.lang.Object>();
	}
	
	
	public  int[] hashes;
	
	public  haxe.ds._WeakMap.Entry<K, V>[] entries;
	
	public  java.lang.ref.ReferenceQueue<K> queue;
	
	public  int nBuckets;
	
	public  int size;
	
	public  int nOccupied;
	
	public  int upperBound;
	
	public  haxe.ds._WeakMap.Entry<K, V> cachedEntry;
	
	public  int cachedIndex;
	
	public   void cleanupRefs()
	{
		java.lang.Object x = null;
		int nOccupied = this.nOccupied;
		while (( ! (( (x = this.queue.poll()) == null )) ))
		{
			haxe.ds._WeakMap.Entry<K, V> x1 = ((haxe.ds._WeakMap.Entry<K, V>) (x) );
			x1.value = null;
			if (( nOccupied != 0 )) 
			{
				int mask = ( this.nBuckets - 1 );
				int hash = x1.hash;
				int nProbes = 0;
				int i = ( hash & mask );
				int last = i;
				int flag = 0;
				do 
				{
					boolean __temp_stmt81043 = false;
					{
						int v = flag = this.hashes[i];
						__temp_stmt81043 = ( v == 0 );
					}
					
					boolean __temp_boolv81042 =  ! (__temp_stmt81043) ;
					boolean __temp_boolv81041 = false;
					if (__temp_boolv81042) 
					{
						__temp_boolv81041 = (( ( ( flag == 1 ) || ( flag != hash ) ) || ( this.entries[i] != x1 ) ));
					}
					
					boolean __temp_stmt81040 = ( __temp_boolv81042 && __temp_boolv81041 );
					if (__temp_stmt81040) 
					{
						i = ( ( i +  ++ nProbes ) & mask );
					}
					 else 
					{
						break;
					}
					
				}
				while (true);
				if (( this.entries[i] == x1 )) 
				{
					if (( this.cachedIndex == i )) 
					{
						this.cachedIndex = -1;
						this.cachedEntry = null;
					}
					
					this.entries[i] = null;
					this.hashes[i] = 1;
					 -- this.size;
				}
				
			}
			
		}
		
	}
	
	
	public   void set(K key, V value)
	{
		this.cleanupRefs();
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
		
		int[] hashes = this.hashes;
		haxe.ds._WeakMap.Entry<K, V>[] entries = this.entries;
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
			int i = ( k & mask );
			int nProbes = 0;
			if (( (( hashes[i] & -2 )) == 0 )) 
			{
				x = i;
			}
			 else 
			{
				int last = i;
				int flag = 0;
				do 
				{
					boolean __temp_stmt81045 = false;
					{
						int v = flag = hashes[i];
						__temp_stmt81045 = ( (( v & -2 )) == 0 );
					}
					
					boolean __temp_boolv81046 = false;
					if ( ! (__temp_stmt81045) ) 
					{
						__temp_boolv81046 = ( ( flag == k ) && (( ( ! (( key == null )) ) && key.equals(entries[i].get()) )) );
					}
					
					boolean __temp_stmt81044 = ( __temp_stmt81045 || __temp_boolv81046 );
					if ( ! ((__temp_stmt81044)) ) 
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
		
		int flag1 = hashes[x];
		haxe.ds._WeakMap.Entry<K, V> entry = new haxe.ds._WeakMap.Entry<K, V>(((K) (key) ), ((V) (value) ), ((int) (k) ), ((java.lang.ref.ReferenceQueue<K>) (this.queue) ));
		if (( flag1 == 0 )) 
		{
			entries[x] = entry;
			hashes[x] = k;
			this.size++;
			this.nOccupied++;
		}
		 else 
		{
			if (( flag1 == 1 )) 
			{
				entries[x] = entry;
				hashes[x] = k;
				this.size++;
			}
			 else 
			{
				{
					boolean x1 = ( ( ! (( key == null )) ) && key.equals(entries[x].get()) );
					java.lang.Object __temp_expr81047 = null;
				}
				
				entries[x] = entry;
			}
			
		}
		
		this.cachedIndex = x;
		this.cachedEntry = entry;
	}
	
	
	public   int lookup(K key)
	{
		if (( this.nBuckets != 0 )) 
		{
			int[] hashes = this.hashes;
			haxe.ds._WeakMap.Entry<K, V>[] entries = this.entries;
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
				boolean __temp_stmt81051 = false;
				{
					int v = flag = hashes[i];
					__temp_stmt81051 = ( v == 0 );
				}
				
				boolean __temp_boolv81050 =  ! (__temp_stmt81051) ;
				boolean __temp_boolv81049 = false;
				if (__temp_boolv81050) 
				{
					__temp_boolv81049 = (( ( ( flag == 1 ) || ( flag != k1 ) ) ||  ! ((( ( ! (( key == null )) ) && key.equals(entries[i].get()) )))  ));
				}
				
				boolean __temp_stmt81048 = ( __temp_boolv81050 && __temp_boolv81049 );
				if (__temp_stmt81048) 
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
					haxe.ds._WeakMap.Entry<K, V>[] e = new haxe.ds._WeakMap.Entry[((int) (newNBuckets) )];
					if (( this.entries != null )) 
					{
						java.lang.System.arraycopy(((java.lang.Object) (this.entries) ), ((int) (0) ), ((java.lang.Object) (e) ), ((int) (0) ), ((int) (this.nBuckets) ));
					}
					
					this.entries = e;
				}
				
			}
			
		}
		
		if (( j != 0 )) 
		{
			this.cachedEntry = null;
			this.cachedIndex = -1;
			j = -1;
			int nBuckets = this.nBuckets;
			haxe.ds._WeakMap.Entry<K, V>[] entries = this.entries;
			int[] hashes = this.hashes;
			int newMask = ( newNBuckets - 1 );
			while ((  ++ j < nBuckets ))
			{
				int k = 0;
				boolean __temp_stmt81052 = false;
				{
					int v = k = hashes[j];
					__temp_stmt81052 = ( (( v & -2 )) == 0 );
				}
				
				if ( ! (__temp_stmt81052) ) 
				{
					haxe.ds._WeakMap.Entry<K, V> entry = entries[j];
					hashes[j] = 1;
					while (true)
					{
						int nProbes = 0;
						int i = ( k & newMask );
						while ( ! ((( newHash[i] == 0 ))) )
						{
							i = ( ( i +  ++ nProbes ) & newMask );
						}
						
						newHash[i] = k;
						boolean __temp_boolv81055 = ( i < nBuckets );
						boolean __temp_boolv81054 = false;
						if (__temp_boolv81055) 
						{
							boolean __temp_stmt81056 = false;
							{
								int v1 = k = hashes[i];
								__temp_stmt81056 = ( (( v1 & -2 )) == 0 );
							}
							
							__temp_boolv81054 =  ! (__temp_stmt81056) ;
						}
						
						boolean __temp_stmt81053 = ( __temp_boolv81055 && __temp_boolv81054 );
						if (__temp_stmt81053) 
						{
							{
								haxe.ds._WeakMap.Entry<K, V> tmp = entries[i];
								entries[i] = entry;
								entry = tmp;
							}
							
							hashes[i] = 1;
						}
						 else 
						{
							entries[i] = entry;
							break;
						}
						
					}
					
				}
				
			}
			
			if (( nBuckets > newNBuckets )) 
			{
				haxe.ds._WeakMap.Entry<K, V>[] e1 = new haxe.ds._WeakMap.Entry[((int) (newNBuckets) )];
				java.lang.System.arraycopy(((java.lang.Object) (entries) ), ((int) (0) ), ((java.lang.Object) (e1) ), ((int) (0) ), ((int) (newNBuckets) ));
				this.entries = e1;
			}
			
			this.hashes = newHash;
			this.nBuckets = newNBuckets;
			this.nOccupied = this.size;
			this.upperBound = ((int) (( ( newNBuckets * 0.77 ) + .5 )) );
		}
		
	}
	
	
	public   V get(K key)
	{
		this.cleanupRefs();
		int idx = -1;
		if (( ( ( this.cachedEntry != null ) && (( ( ! (( key == null )) ) && key.equals(this.cachedEntry.get()) )) ) && ( (idx = this.cachedIndex) != -1 ) )) 
		{
			return this.cachedEntry.value;
		}
		
		idx = this.lookup(key);
		if (( idx != -1 )) 
		{
			haxe.ds._WeakMap.Entry<K, V> entry = this.entries[idx];
			this.cachedEntry = entry;
			this.cachedIndex = idx;
			return entry.value;
		}
		
		return null;
	}
	
	
	public   V getDefault(K key, V def)
	{
		this.cleanupRefs();
		int idx = -1;
		if (( ( ( this.cachedEntry != null ) && (( ( ! (( key == null )) ) && key.equals(this.cachedEntry.get()) )) ) && ( (idx = this.cachedIndex) != -1 ) )) 
		{
			return this.cachedEntry.value;
		}
		
		idx = this.lookup(key);
		if (( idx != -1 )) 
		{
			haxe.ds._WeakMap.Entry<K, V> entry = this.entries[idx];
			this.cachedEntry = entry;
			this.cachedIndex = idx;
			return entry.value;
		}
		
		return def;
	}
	
	
	public   boolean exists(K key)
	{
		this.cleanupRefs();
		int idx = -1;
		if (( ( ( this.cachedEntry != null ) && (( ( ! (( key == null )) ) && key.equals(this.cachedEntry.get()) )) ) && ( (idx = this.cachedIndex) != -1 ) )) 
		{
			return true;
		}
		
		idx = this.lookup(key);
		if (( idx != -1 )) 
		{
			haxe.ds._WeakMap.Entry<K, V> entry = this.entries[idx];
			this.cachedEntry = entry;
			this.cachedIndex = idx;
			return true;
		}
		
		return false;
	}
	
	
	public   boolean remove(K key)
	{
		this.cleanupRefs();
		int idx = -1;
		if ( ! ((( ( ( this.cachedEntry != null ) && (( ( ! (( key == null )) ) && key.equals(this.cachedEntry.get()) )) ) && ( (idx = this.cachedIndex) != -1 ) ))) ) 
		{
			idx = this.lookup(key);
		}
		
		if (( idx == -1 )) 
		{
			return false;
		}
		 else 
		{
			if (( ( this.cachedEntry != null ) && (( ( ! (( key == null )) ) && key.equals(this.cachedEntry.get()) )) )) 
			{
				this.cachedIndex = -1;
				this.cachedEntry = null;
			}
			
			this.hashes[idx] = 1;
			this.entries[idx] = null;
			 -- this.size;
			return true;
		}
		
	}
	
	
	public   java.lang.Object keys()
	{
		haxe.root.Array<haxe.ds.WeakMap> _g1 = new haxe.root.Array<haxe.ds.WeakMap>(new haxe.ds.WeakMap[]{((haxe.ds.WeakMap) (this) )});
		this.cleanupRefs();
		haxe.root.Array<java.lang.Object> i = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0});
		haxe.root.Array<java.lang.Object> len = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{this.nBuckets});
		haxe.root.Array<K> lastKey = new haxe.root.Array<K>(( (K[]) (new java.lang.Object[] {null}) ));
		{
			haxe.lang.Function __temp_odecl81057 = new haxe.ds.WeakMap_keys_388__Fun<V, K>(((haxe.root.Array<java.lang.Object>) (len) ), ((haxe.root.Array<haxe.ds.WeakMap>) (_g1) ), ((haxe.root.Array<K>) (lastKey) ), ((haxe.root.Array<java.lang.Object>) (i) ));
			haxe.lang.Function __temp_odecl81058 = new haxe.ds.WeakMap_keys_407__Fun<K>(((haxe.root.Array<K>) (lastKey) ), ((haxe.root.Array<java.lang.Object>) (i) ));
			return new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"hasNext", "next"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl81057, __temp_odecl81058}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		}
		
	}
	
	
	public   java.lang.Object iterator()
	{
		haxe.root.Array<haxe.ds.WeakMap> _g1 = new haxe.root.Array<haxe.ds.WeakMap>(new haxe.ds.WeakMap[]{((haxe.ds.WeakMap) (this) )});
		this.cleanupRefs();
		haxe.root.Array<java.lang.Object> i = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0});
		haxe.root.Array<java.lang.Object> len = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{this.nBuckets});
		{
			haxe.lang.Function __temp_odecl81059 = new haxe.ds.WeakMap_iterator_424__Fun<V, K>(((haxe.root.Array<java.lang.Object>) (len) ), ((haxe.root.Array<haxe.ds.WeakMap>) (_g1) ), ((haxe.root.Array<java.lang.Object>) (i) ));
			haxe.lang.Function __temp_odecl81060 = new haxe.ds.WeakMap_iterator_435__Fun<K, V>(((haxe.root.Array<haxe.ds.WeakMap>) (_g1) ), ((haxe.root.Array<java.lang.Object>) (i) ));
			return new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"hasNext", "next"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl81059, __temp_odecl81060}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
		}
		
	}
	
	
	@Override public   java.lang.String toString()
	{
		haxe.root.StringBuf s = new haxe.root.StringBuf();
		s.add("{");
		java.lang.Object it = this.keys();
		{
			java.lang.Object __temp_iterator80862 = it;
			while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(__temp_iterator80862, "hasNext", null)))
			{
				K i = ((K) (haxe.lang.Runtime.callField(__temp_iterator80862, "next", null)) );
				s.add(haxe.root.Std.string(i));
				s.add(" => ");
				s.add(haxe.root.Std.string(this.get(i)));
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
			boolean __temp_executeDef81061 = true;
			switch (field.hashCode())
			{
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef81061 = false;
						this.cachedIndex = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef81061 = false;
						this.nBuckets = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef81061 = false;
						this.upperBound = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef81061 = false;
						this.size = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef81061 = false;
						this.nOccupied = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81061) 
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
			boolean __temp_executeDef81062 = true;
			switch (field.hashCode())
			{
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef81062 = false;
						this.cachedIndex = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1224424900:
				{
					if (field.equals("hashes")) 
					{
						__temp_executeDef81062 = false;
						this.hashes = ((int[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1001405552:
				{
					if (field.equals("cachedEntry")) 
					{
						__temp_executeDef81062 = false;
						this.cachedEntry = ((haxe.ds._WeakMap.Entry<K, V>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1591573360:
				{
					if (field.equals("entries")) 
					{
						__temp_executeDef81062 = false;
						this.entries = ((haxe.ds._WeakMap.Entry<K, V>[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef81062 = false;
						this.upperBound = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef81062 = false;
						this.queue = ((java.lang.ref.ReferenceQueue<K>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef81062 = false;
						this.nOccupied = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef81062 = false;
						this.nBuckets = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef81062 = false;
						this.size = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81062) 
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
			boolean __temp_executeDef81063 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef81063 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("toString"))) );
					}
					
					break;
				}
				
				
				case -1224424900:
				{
					if (field.equals("hashes")) 
					{
						__temp_executeDef81063 = false;
						return this.hashes;
					}
					
					break;
				}
				
				
				case 1182533742:
				{
					if (field.equals("iterator")) 
					{
						__temp_executeDef81063 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("iterator"))) );
					}
					
					break;
				}
				
				
				case -1591573360:
				{
					if (field.equals("entries")) 
					{
						__temp_executeDef81063 = false;
						return this.entries;
					}
					
					break;
				}
				
				
				case 3288564:
				{
					if (field.equals("keys")) 
					{
						__temp_executeDef81063 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("keys"))) );
					}
					
					break;
				}
				
				
				case 107944209:
				{
					if (field.equals("queue")) 
					{
						__temp_executeDef81063 = false;
						return this.queue;
					}
					
					break;
				}
				
				
				case -934610812:
				{
					if (field.equals("remove")) 
					{
						__temp_executeDef81063 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("remove"))) );
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef81063 = false;
						return this.nBuckets;
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef81063 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("exists"))) );
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef81063 = false;
						return this.size;
					}
					
					break;
				}
				
				
				case -1713303029:
				{
					if (field.equals("getDefault")) 
					{
						__temp_executeDef81063 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getDefault"))) );
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef81063 = false;
						return this.nOccupied;
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef81063 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get"))) );
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef81063 = false;
						return this.upperBound;
					}
					
					break;
				}
				
				
				case -934437708:
				{
					if (field.equals("resize")) 
					{
						__temp_executeDef81063 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("resize"))) );
					}
					
					break;
				}
				
				
				case 1001405552:
				{
					if (field.equals("cachedEntry")) 
					{
						__temp_executeDef81063 = false;
						return this.cachedEntry;
					}
					
					break;
				}
				
				
				case -1097094790:
				{
					if (field.equals("lookup")) 
					{
						__temp_executeDef81063 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("lookup"))) );
					}
					
					break;
				}
				
				
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef81063 = false;
						return this.cachedIndex;
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef81063 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set"))) );
					}
					
					break;
				}
				
				
				case 128201476:
				{
					if (field.equals("cleanupRefs")) 
					{
						__temp_executeDef81063 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("cleanupRefs"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81063) 
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
			boolean __temp_executeDef81064 = true;
			switch (field.hashCode())
			{
				case 1005083856:
				{
					if (field.equals("cachedIndex")) 
					{
						__temp_executeDef81064 = false;
						return ((double) (this.cachedIndex) );
					}
					
					break;
				}
				
				
				case 325636987:
				{
					if (field.equals("nBuckets")) 
					{
						__temp_executeDef81064 = false;
						return ((double) (this.nBuckets) );
					}
					
					break;
				}
				
				
				case -1690761732:
				{
					if (field.equals("upperBound")) 
					{
						__temp_executeDef81064 = false;
						return ((double) (this.upperBound) );
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef81064 = false;
						return ((double) (this.size) );
					}
					
					break;
				}
				
				
				case -394102484:
				{
					if (field.equals("nOccupied")) 
					{
						__temp_executeDef81064 = false;
						return ((double) (this.nOccupied) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81064) 
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
			boolean __temp_executeDef81065 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef81065 = false;
						return this.toString();
					}
					
					break;
				}
				
				
				case 128201476:
				{
					if (field.equals("cleanupRefs")) 
					{
						__temp_executeDef81065 = false;
						this.cleanupRefs();
					}
					
					break;
				}
				
				
				case 1182533742:
				{
					if (field.equals("iterator")) 
					{
						__temp_executeDef81065 = false;
						return this.iterator();
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef81065 = false;
						this.set(((K) (dynargs.__get(0)) ), ((V) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 3288564:
				{
					if (field.equals("keys")) 
					{
						__temp_executeDef81065 = false;
						return this.keys();
					}
					
					break;
				}
				
				
				case -1097094790:
				{
					if (field.equals("lookup")) 
					{
						__temp_executeDef81065 = false;
						return this.lookup(((K) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -934610812:
				{
					if (field.equals("remove")) 
					{
						__temp_executeDef81065 = false;
						return this.remove(((K) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -934437708:
				{
					if (field.equals("resize")) 
					{
						__temp_executeDef81065 = false;
						this.resize(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef81065 = false;
						return this.exists(((K) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef81065 = false;
						return this.get(((K) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1713303029:
				{
					if (field.equals("getDefault")) 
					{
						__temp_executeDef81065 = false;
						return this.getDefault(((K) (dynargs.__get(0)) ), ((V) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81065) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("cachedIndex");
		baseArr.push("cachedEntry");
		baseArr.push("upperBound");
		baseArr.push("nOccupied");
		baseArr.push("size");
		baseArr.push("nBuckets");
		baseArr.push("queue");
		baseArr.push("entries");
		baseArr.push("hashes");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


