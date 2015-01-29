package haxor.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class SAPList extends haxe.lang.HxObject
{
	public    SAPList(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    SAPList(java.lang.Object p_bias, java.lang.Object p_has_query)
	{
		haxor.ds.SAPList.__hx_ctor_haxor_ds_SAPList(this, p_bias, p_has_query);
	}
	
	
	public static   void __hx_ctor_haxor_ds_SAPList(haxor.ds.SAPList __temp_me183, java.lang.Object p_bias, java.lang.Object p_has_query)
	{
		boolean __temp_p_has_query182 = ( (( p_has_query == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_has_query)) );
		double __temp_p_bias181 = ( (( p_bias == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_bias)) )) );
		__temp_me183.list = new haxe.root.Array<haxor.ds.SAPInterval>(new haxor.ds.SAPInterval[]{});
		{
			int _g = 0;
			while (( _g < 5000 ))
			{
				int i = _g++;
				__temp_me183.list.push(null);
			}
			
		}
		
		__temp_me183.m_has_query = __temp_p_has_query182;
		__temp_me183.m_bias = __temp_p_bias181;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.ds.SAPList(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.ds.SAPList(((java.lang.Object) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ));
	}
	
	
	public  haxor.ds.SAPInterval start;
	
	public  haxe.root.Array<haxor.ds.SAPInterval> list;
	
	public  boolean m_has_query;
	
	public  double m_bias;
	
	public   void Create(int p_id)
	{
		while (( this.list.length <= p_id ))
		{
			this.list.push(null);
		}
		
		if (( this.list.__get(p_id) == null )) 
		{
			this.list.__set(p_id, new haxor.ds.SAPInterval());
		}
		
	}
	
	
	public   void Update(int p_id, java.lang.Object p_data, double p_min, double p_max)
	{
		this.list.__get(p_id).id = p_id;
		this.list.__get(p_id).data = p_data;
		double d = ( ( (( p_max - p_min )) * this.m_bias ) * 0.5 );
		this.list.__get(p_id).Set(( p_min - d ), ( p_max + d ));
		if (this.m_has_query) 
		{
			this.Relocate(this.list.__get(p_id));
		}
		
	}
	
	
	public   void Add(haxor.ds.SAPInterval p_item)
	{
		if (( this.start == null )) 
		{
			this.start = p_item;
			p_item.next = p_item.prev = null;
			return ;
		}
		
		if (( p_item == this.start )) 
		{
			return ;
		}
		
		haxor.ds.SAPInterval it = this.start;
		while (( it != null ))
		{
			if (( p_item.min < it.min )) 
			{
				this.Insert(p_item, it);
				return ;
			}
			
			if (( it.next == null )) 
			{
				this.Insert(p_item, it);
				return ;
			}
			
			it = it.next;
		}
		
	}
	
	
	public   void Insert(haxor.ds.SAPInterval p_item, haxor.ds.SAPInterval p_at)
	{
		if (( p_item == p_at )) 
		{
			return ;
		}
		
		if (( p_item.min > p_at.min )) 
		{
			p_item.next = p_at.next;
			p_item.prev = p_at;
			p_at.next = p_item;
			if (( p_item.next != null )) 
			{
				p_item.next.prev = p_item;
			}
			
		}
		 else 
		{
			p_item.next = p_at;
			p_item.prev = p_at.prev;
			p_at.prev = p_item;
			if (( p_item.prev != null )) 
			{
				p_item.prev.next = p_item;
			}
			
			if (( p_at == this.start )) 
			{
				this.start = p_item;
			}
			
		}
		
	}
	
	
	public   void Relocate(haxor.ds.SAPInterval p_item)
	{
		if (( p_item.prev == null )) 
		{
			if (( p_item.next == null )) 
			{
				this.Add(p_item);
				return ;
			}
			
		}
		
		haxor.ds.SAPInterval it = p_item;
		int nav = 0;
		haxor.ds.SAPInterval location = null;
		while (( it != null ))
		{
			haxor.ds.SAPInterval n = it.next;
			haxor.ds.SAPInterval p = it.prev;
			if (( n == null )) 
			{
				if (( p == null )) 
				{
					break;
				}
				
			}
			
			if (( p != null )) 
			{
				if (( p_item.min < p.min )) 
				{
					nav = -1;
					location = p;
				}
				
			}
			
			if (( n != null )) 
			{
				if (( p_item.min > n.min )) 
				{
					nav = 1;
					location = n;
				}
				
			}
			
			if (( nav == 0 )) 
			{
				break;
			}
			
			if (( nav < 0 )) 
			{
				it = p;
			}
			 else 
			{
				it = n;
			}
			
			nav = 0;
		}
		
		if (( location != null )) 
		{
			this.Remove(p_item);
			this.Insert(p_item, location);
		}
		
	}
	
	
	public final   void RemoveById(int p_id)
	{
		this.Remove(this.list.__get(p_id));
	}
	
	
	public   void Remove(haxor.ds.SAPInterval p_item)
	{
		if ( ! (this.m_has_query) ) 
		{
			return ;
		}
		
		haxor.ds.SAPInterval p = p_item.prev;
		haxor.ds.SAPInterval n = p_item.next;
		if (( p != null )) 
		{
			p.next = n;
		}
		
		if (( n != null )) 
		{
			n.prev = p;
		}
		
		p_item.next = p_item.prev = null;
		if (( p_item == this.start )) 
		{
			this.start = n;
		}
		
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_places)
	{
		int __temp_p_places180 = ( (( p_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_places)) )) );
		java.lang.String s = "";
		if (this.m_has_query) 
		{
			haxor.ds.SAPInterval it = this.start;
			while (( it != null ))
			{
				s += it.ToString(__temp_p_places180);
				it = it.next;
			}
			
		}
		 else 
		{
			int _g1 = 0;
			int _g = this.list.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				s += this.list.__get(i).ToString(__temp_p_places180);
			}
			
		}
		
		return s;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef949 = true;
			switch (field.hashCode())
			{
				case -1083631797:
				{
					if (field.equals("m_bias")) 
					{
						__temp_executeDef949 = false;
						this.m_bias = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef949) 
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
			boolean __temp_executeDef950 = true;
			switch (field.hashCode())
			{
				case -1083631797:
				{
					if (field.equals("m_bias")) 
					{
						__temp_executeDef950 = false;
						this.m_bias = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 109757538:
				{
					if (field.equals("start")) 
					{
						__temp_executeDef950 = false;
						this.start = ((haxor.ds.SAPInterval) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 280512913:
				{
					if (field.equals("m_has_query")) 
					{
						__temp_executeDef950 = false;
						this.m_has_query = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 3322014:
				{
					if (field.equals("list")) 
					{
						__temp_executeDef950 = false;
						this.list = ((haxe.root.Array<haxor.ds.SAPInterval>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef950) 
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
			boolean __temp_executeDef951 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef951 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 109757538:
				{
					if (field.equals("start")) 
					{
						__temp_executeDef951 = false;
						return this.start;
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef951 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Remove"))) );
					}
					
					break;
				}
				
				
				case 3322014:
				{
					if (field.equals("list")) 
					{
						__temp_executeDef951 = false;
						return this.list;
					}
					
					break;
				}
				
				
				case -1203453290:
				{
					if (field.equals("RemoveById")) 
					{
						__temp_executeDef951 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("RemoveById"))) );
					}
					
					break;
				}
				
				
				case 280512913:
				{
					if (field.equals("m_has_query")) 
					{
						__temp_executeDef951 = false;
						return this.m_has_query;
					}
					
					break;
				}
				
				
				case -477376667:
				{
					if (field.equals("Relocate")) 
					{
						__temp_executeDef951 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Relocate"))) );
					}
					
					break;
				}
				
				
				case -1083631797:
				{
					if (field.equals("m_bias")) 
					{
						__temp_executeDef951 = false;
						return this.m_bias;
					}
					
					break;
				}
				
				
				case -2099925287:
				{
					if (field.equals("Insert")) 
					{
						__temp_executeDef951 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Insert"))) );
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef951 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Create"))) );
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef951 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef951 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Update"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef951) 
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
			boolean __temp_executeDef952 = true;
			switch (field.hashCode())
			{
				case -1083631797:
				{
					if (field.equals("m_bias")) 
					{
						__temp_executeDef952 = false;
						return this.m_bias;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef952) 
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
			boolean __temp_executeDef953 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef953 = false;
						return this.ToString(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef953 = false;
						this.Create(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef953 = false;
						this.Remove(((haxor.ds.SAPInterval) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef953 = false;
						this.Update(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), dynargs.__get(1), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case -1203453290:
				{
					if (field.equals("RemoveById")) 
					{
						__temp_executeDef953 = false;
						this.RemoveById(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef953 = false;
						this.Add(((haxor.ds.SAPInterval) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -477376667:
				{
					if (field.equals("Relocate")) 
					{
						__temp_executeDef953 = false;
						this.Relocate(((haxor.ds.SAPInterval) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -2099925287:
				{
					if (field.equals("Insert")) 
					{
						__temp_executeDef953 = false;
						this.Insert(((haxor.ds.SAPInterval) (dynargs.__get(0)) ), ((haxor.ds.SAPInterval) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef953) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_bias");
		baseArr.push("m_has_query");
		baseArr.push("list");
		baseArr.push("start");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


