package haxor.ds;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class SAP extends haxe.lang.HxObject
{
	public    SAP(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    SAP(java.lang.Object p_bias, java.lang.Object p_has_query)
	{
		haxor.ds.SAP.__hx_ctor_haxor_ds_SAP(this, p_bias, p_has_query);
	}
	
	
	public static   void __hx_ctor_haxor_ds_SAP(haxor.ds.SAP __temp_me179, java.lang.Object p_bias, java.lang.Object p_has_query)
	{
		boolean __temp_p_has_query178 = ( (( p_has_query == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_has_query)) );
		double __temp_p_bias177 = ( (( p_bias == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_bias)) )) );
		__temp_me179.m_has_query = __temp_p_has_query178;
		__temp_me179.x = new haxor.ds.SAPList(((java.lang.Object) (__temp_p_bias177) ), ((java.lang.Object) (__temp_me179.m_has_query) ));
		__temp_me179.y = new haxor.ds.SAPList(((java.lang.Object) (__temp_p_bias177) ), ((java.lang.Object) (__temp_me179.m_has_query) ));
		__temp_me179.z = new haxor.ds.SAPList(((java.lang.Object) (__temp_p_bias177) ), ((java.lang.Object) (__temp_me179.m_has_query) ));
		__temp_me179.inside = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me179.outside = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me179.countIn = 0;
		__temp_me179.countOut = 0;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.ds.SAP(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.ds.SAP(((java.lang.Object) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ));
	}
	
	
	public  haxe.root.Array<java.lang.Object> inside;
	
	public  haxe.root.Array<java.lang.Object> outside;
	
	public  int countIn;
	
	public  int countOut;
	
	public  haxor.ds.SAPList x;
	
	public  haxor.ds.SAPList y;
	
	public  haxor.ds.SAPList z;
	
	public  boolean m_has_query;
	
	public   void Create(int p_id)
	{
		this.x.Create(p_id);
		this.y.Create(p_id);
		this.z.Create(p_id);
		while (( this.inside.length <= p_id ))
		{
			this.inside.push(-1);
			this.outside.push(-1);
		}
		
	}
	
	
	public   void Update(int p_id, java.lang.Object p_data, haxor.math.Vector3 p_min, haxor.math.Vector3 p_max)
	{
		this.x.Update(p_id, p_data, p_min.x, p_max.x);
		this.y.Update(p_id, p_data, p_min.y, p_max.y);
		this.z.Update(p_id, p_data, p_min.z, p_max.z);
	}
	
	
	public   void Remove(int p_id)
	{
		{
			haxor.ds.SAPList _this = this.x;
			_this.Remove(_this.list.__get(p_id));
		}
		
		{
			haxor.ds.SAPList _this1 = this.y;
			_this1.Remove(_this1.list.__get(p_id));
		}
		
		{
			haxor.ds.SAPList _this2 = this.z;
			_this2.Remove(_this2.list.__get(p_id));
		}
		
	}
	
	
	public   boolean Overlap(int p_a, int p_b)
	{
		haxor.ds.SAPInterval ax = this.x.list.__get(p_a);
		haxor.ds.SAPInterval bx = this.x.list.__get(p_b);
		if ( ! (ax.Overlap(bx)) ) 
		{
			return true;
		}
		
		haxor.ds.SAPInterval ay = this.y.list.__get(p_a);
		haxor.ds.SAPInterval by = this.y.list.__get(p_b);
		if ( ! (ay.Overlap(by)) ) 
		{
			return true;
		}
		
		haxor.ds.SAPInterval az = this.z.list.__get(p_a);
		haxor.ds.SAPInterval bz = this.z.list.__get(p_b);
		if ( ! (az.Overlap(bz)) ) 
		{
			return true;
		}
		
		return false;
	}
	
	
	public   void Query(int p_id, java.lang.Object p_outside)
	{
		boolean __temp_p_outside176 = ( (( p_outside == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_outside)) );
		if ( ! (this.m_has_query) ) 
		{
			return ;
		}
		
		this.countIn = 0;
		this.countOut = 0;
		haxor.ds.SAPInterval tx = null;
		haxor.ds.SAPInterval ty = null;
		haxor.ds.SAPInterval tz = null;
		haxor.ds.SAPInterval it = null;
		haxor.ds.SAPInterval nx = null;
		haxor.ds.SAPInterval ny = null;
		haxor.ds.SAPInterval nz = null;
		tx = this.x.list.__get(p_id);
		ty = this.y.list.__get(p_id);
		tz = this.z.list.__get(p_id);
		it = tx.next;
		while (( it != null ))
		{
			if (it.Overlap(tx)) 
			{
				if (this.y.list.__get(it.id).Overlap(ty)) 
				{
					if (this.z.list.__get(it.id).Overlap(tz)) 
					{
						this.inside.__set(this.countIn++, it.id);
					}
					 else 
					{
						if (__temp_p_outside176) 
						{
							this.outside.__set(this.countOut++, it.id);
						}
						
					}
					
				}
				 else 
				{
					if (__temp_p_outside176) 
					{
						this.outside.__set(this.countOut++, it.id);
					}
					
				}
				
			}
			 else 
			{
				if (__temp_p_outside176) 
				{
					this.outside.__set(this.countOut++, it.id);
				}
				
			}
			
			it = it.next;
		}
		
		it = tx.prev;
		while (( it != null ))
		{
			if (it.Overlap(tx)) 
			{
				if (this.y.list.__get(it.id).Overlap(ty)) 
				{
					if (this.z.list.__get(it.id).Overlap(tz)) 
					{
						this.inside.__set(this.countIn++, it.id);
					}
					 else 
					{
						if (__temp_p_outside176) 
						{
							this.outside.__set(this.countOut++, it.id);
						}
						
					}
					
				}
				 else 
				{
					if (__temp_p_outside176) 
					{
						this.outside.__set(this.countOut++, it.id);
					}
					
				}
				
			}
			 else 
			{
				if (__temp_p_outside176) 
				{
					this.outside.__set(this.countOut++, it.id);
				}
				
			}
			
			it = it.prev;
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef944 = true;
			switch (field.hashCode())
			{
				case -372041793:
				{
					if (field.equals("countOut")) 
					{
						__temp_executeDef944 = false;
						this.countOut = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 957829780:
				{
					if (field.equals("countIn")) 
					{
						__temp_executeDef944 = false;
						this.countIn = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef944) 
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
			boolean __temp_executeDef945 = true;
			switch (field.hashCode())
			{
				case 280512913:
				{
					if (field.equals("m_has_query")) 
					{
						__temp_executeDef945 = false;
						this.m_has_query = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1183789060:
				{
					if (field.equals("inside")) 
					{
						__temp_executeDef945 = false;
						this.inside = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef945 = false;
						this.z = ((haxor.ds.SAPList) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1106037339:
				{
					if (field.equals("outside")) 
					{
						__temp_executeDef945 = false;
						this.outside = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef945 = false;
						this.y = ((haxor.ds.SAPList) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 957829780:
				{
					if (field.equals("countIn")) 
					{
						__temp_executeDef945 = false;
						this.countIn = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef945 = false;
						this.x = ((haxor.ds.SAPList) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -372041793:
				{
					if (field.equals("countOut")) 
					{
						__temp_executeDef945 = false;
						this.countOut = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef945) 
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
			boolean __temp_executeDef946 = true;
			switch (field.hashCode())
			{
				case 78391464:
				{
					if (field.equals("Query")) 
					{
						__temp_executeDef946 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Query"))) );
					}
					
					break;
				}
				
				
				case -1183789060:
				{
					if (field.equals("inside")) 
					{
						__temp_executeDef946 = false;
						return this.inside;
					}
					
					break;
				}
				
				
				case 573365287:
				{
					if (field.equals("Overlap")) 
					{
						__temp_executeDef946 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Overlap"))) );
					}
					
					break;
				}
				
				
				case -1106037339:
				{
					if (field.equals("outside")) 
					{
						__temp_executeDef946 = false;
						return this.outside;
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef946 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Remove"))) );
					}
					
					break;
				}
				
				
				case 957829780:
				{
					if (field.equals("countIn")) 
					{
						__temp_executeDef946 = false;
						return this.countIn;
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef946 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Update"))) );
					}
					
					break;
				}
				
				
				case -372041793:
				{
					if (field.equals("countOut")) 
					{
						__temp_executeDef946 = false;
						return this.countOut;
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef946 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Create"))) );
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef946 = false;
						return this.x;
					}
					
					break;
				}
				
				
				case 280512913:
				{
					if (field.equals("m_has_query")) 
					{
						__temp_executeDef946 = false;
						return this.m_has_query;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef946 = false;
						return this.y;
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef946 = false;
						return this.z;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef946) 
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
			boolean __temp_executeDef947 = true;
			switch (field.hashCode())
			{
				case -372041793:
				{
					if (field.equals("countOut")) 
					{
						__temp_executeDef947 = false;
						return ((double) (this.countOut) );
					}
					
					break;
				}
				
				
				case 957829780:
				{
					if (field.equals("countIn")) 
					{
						__temp_executeDef947 = false;
						return ((double) (this.countIn) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef947) 
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
			boolean __temp_executeDef948 = true;
			switch (field.hashCode())
			{
				case 78391464:
				{
					if (field.equals("Query")) 
					{
						__temp_executeDef948 = false;
						this.Query(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef948 = false;
						this.Create(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 573365287:
				{
					if (field.equals("Overlap")) 
					{
						__temp_executeDef948 = false;
						return this.Overlap(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef948 = false;
						this.Update(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), dynargs.__get(1), ((haxor.math.Vector3) (dynargs.__get(2)) ), ((haxor.math.Vector3) (dynargs.__get(3)) ));
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef948 = false;
						this.Remove(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef948) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_has_query");
		baseArr.push("z");
		baseArr.push("y");
		baseArr.push("x");
		baseArr.push("countOut");
		baseArr.push("countIn");
		baseArr.push("outside");
		baseArr.push("inside");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


