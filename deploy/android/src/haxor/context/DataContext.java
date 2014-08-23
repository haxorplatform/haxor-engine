package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class DataContext extends haxe.lang.HxObject
{
	static 
	{
		haxor.context.DataContext.MAX_TEMP = 128;
	}
	public    DataContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    DataContext()
	{
		haxor.context.DataContext.__hx_ctor_haxor_context_DataContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_DataContext(haxor.context.DataContext __temp_me56080)
	{
		__temp_me56080.i = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me56080.v = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me56080.m_v2 = new haxe.root.Array<haxor.math.Vector2>(new haxor.math.Vector2[]{});
		__temp_me56080.m_v3 = new haxe.root.Array<haxor.math.Vector3>(new haxor.math.Vector3[]{});
		__temp_me56080.m_v4 = new haxe.root.Array<haxor.math.Vector4>(new haxor.math.Vector4[]{});
		__temp_me56080.m_c = new haxe.root.Array<haxor.math.Color>(new haxor.math.Color[]{});
		__temp_me56080.m_q = new haxe.root.Array<haxor.math.Quaternion>(new haxor.math.Quaternion[]{});
		__temp_me56080.m_m4 = new haxe.root.Array<haxor.math.Matrix4>(new haxor.math.Matrix4[]{});
		__temp_me56080.m_nv2 = 0;
		__temp_me56080.m_nv3 = 0;
		__temp_me56080.m_nv4 = 0;
		__temp_me56080.m_nc = 0;
		__temp_me56080.m_nq = 0;
		__temp_me56080.m_nm4 = 0;
		{
			int _g1 = 0;
			int _g = ((int) (haxor.context.DataContext.MAX_TEMP) );
			while (( _g1 < _g ))
			{
				int k = _g1++;
				__temp_me56080.i.push(0);
				__temp_me56080.v.push(0.0);
				__temp_me56080.m_v2.push(new haxor.math.Vector2(((java.lang.Object) (0) ), ((java.lang.Object) (0) )));
				__temp_me56080.m_v3.push(new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )));
				__temp_me56080.m_v4.push(new haxor.math.Vector4(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )));
				__temp_me56080.m_c.push(new haxor.math.Color(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) )));
				__temp_me56080.m_q.push(new haxor.math.Quaternion(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1.0) )));
				__temp_me56080.m_m4.push(new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) )));
			}
			
		}
		
	}
	
	
	public static  int MAX_TEMP;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.DataContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.DataContext();
	}
	
	
	public  haxe.root.Array<java.lang.Object> i;
	
	public  haxe.root.Array<java.lang.Object> v;
	
	public  haxor.math.Vector2 v2;
	
	public final   haxor.math.Vector2 get_v2()
	{
		return this.m_v2.__get(this.m_nv2 = ( (( this.m_nv2 + 1 )) % this.m_v2.length ));
	}
	
	
	public  haxe.root.Array<haxor.math.Vector2> m_v2;
	
	public  int m_nv2;
	
	public  haxor.math.Vector3 v3;
	
	public final   haxor.math.Vector3 get_v3()
	{
		return this.m_v3.__get(this.m_nv3 = ( (( this.m_nv3 + 1 )) % this.m_v3.length ));
	}
	
	
	public  haxe.root.Array<haxor.math.Vector3> m_v3;
	
	public  int m_nv3;
	
	public  haxor.math.Vector4 v4;
	
	public final   haxor.math.Vector4 get_v4()
	{
		return this.m_v4.__get(this.m_nv4 = ( (( this.m_nv4 + 1 )) % this.m_v4.length ));
	}
	
	
	public  haxe.root.Array<haxor.math.Vector4> m_v4;
	
	public  int m_nv4;
	
	public  haxor.math.Color c;
	
	public final   haxor.math.Color get_c()
	{
		return this.m_c.__get(this.m_nc = ( (( this.m_nc + 1 )) % this.m_c.length ));
	}
	
	
	public  haxe.root.Array<haxor.math.Color> m_c;
	
	public  int m_nc;
	
	public  haxor.math.Quaternion q;
	
	public final   haxor.math.Quaternion get_q()
	{
		return this.m_q.__get(this.m_nq = ( (( this.m_nq + 1 )) % this.m_q.length ));
	}
	
	
	public  haxe.root.Array<haxor.math.Quaternion> m_q;
	
	public  int m_nq;
	
	public  haxor.math.Matrix4 m4;
	
	public final   haxor.math.Matrix4 get_m4()
	{
		return this.m_m4.__get(this.m_nq = ( (( this.m_nm4 + 1 )) % this.m_m4.length ));
	}
	
	
	public  haxe.root.Array<haxor.math.Matrix4> m_m4;
	
	public  int m_nm4;
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef56362 = true;
			switch (field.hashCode())
			{
				case 103603075:
				{
					if (field.equals("m_nm4")) 
					{
						__temp_executeDef56362 = false;
						this.m_nm4 = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103603352:
				{
					if (field.equals("m_nv2")) 
					{
						__temp_executeDef56362 = false;
						this.m_nv2 = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3342037:
				{
					if (field.equals("m_nq")) 
					{
						__temp_executeDef56362 = false;
						this.m_nq = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103603353:
				{
					if (field.equals("m_nv3")) 
					{
						__temp_executeDef56362 = false;
						this.m_nv3 = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3342023:
				{
					if (field.equals("m_nc")) 
					{
						__temp_executeDef56362 = false;
						this.m_nc = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103603354:
				{
					if (field.equals("m_nv4")) 
					{
						__temp_executeDef56362 = false;
						this.m_nv4 = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56362) 
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
			boolean __temp_executeDef56363 = true;
			switch (field.hashCode())
			{
				case 103603075:
				{
					if (field.equals("m_nm4")) 
					{
						__temp_executeDef56363 = false;
						this.m_nm4 = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 105:
				{
					if (field.equals("i")) 
					{
						__temp_executeDef56363 = false;
						this.i = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3341945:
				{
					if (field.equals("m_m4")) 
					{
						__temp_executeDef56363 = false;
						this.m_m4 = ((haxe.root.Array<haxor.math.Matrix4>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 118:
				{
					if (field.equals("v")) 
					{
						__temp_executeDef56363 = false;
						this.v = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3431:
				{
					if (field.equals("m4")) 
					{
						__temp_executeDef56363 = false;
						this.m4 = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3708:
				{
					if (field.equals("v2")) 
					{
						__temp_executeDef56363 = false;
						this.v2 = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3342037:
				{
					if (field.equals("m_nq")) 
					{
						__temp_executeDef56363 = false;
						this.m_nq = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3342222:
				{
					if (field.equals("m_v2")) 
					{
						__temp_executeDef56363 = false;
						this.m_v2 = ((haxe.root.Array<haxor.math.Vector2>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107807:
				{
					if (field.equals("m_q")) 
					{
						__temp_executeDef56363 = false;
						this.m_q = ((haxe.root.Array<haxor.math.Quaternion>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103603352:
				{
					if (field.equals("m_nv2")) 
					{
						__temp_executeDef56363 = false;
						this.m_nv2 = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 113:
				{
					if (field.equals("q")) 
					{
						__temp_executeDef56363 = false;
						this.q = ((haxor.math.Quaternion) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3709:
				{
					if (field.equals("v3")) 
					{
						__temp_executeDef56363 = false;
						this.v3 = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3342023:
				{
					if (field.equals("m_nc")) 
					{
						__temp_executeDef56363 = false;
						this.m_nc = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3342223:
				{
					if (field.equals("m_v3")) 
					{
						__temp_executeDef56363 = false;
						this.m_v3 = ((haxe.root.Array<haxor.math.Vector3>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107793:
				{
					if (field.equals("m_c")) 
					{
						__temp_executeDef56363 = false;
						this.m_c = ((haxe.root.Array<haxor.math.Color>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103603353:
				{
					if (field.equals("m_nv3")) 
					{
						__temp_executeDef56363 = false;
						this.m_nv3 = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 99:
				{
					if (field.equals("c")) 
					{
						__temp_executeDef56363 = false;
						this.c = ((haxor.math.Color) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3710:
				{
					if (field.equals("v4")) 
					{
						__temp_executeDef56363 = false;
						this.v4 = ((haxor.math.Vector4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103603354:
				{
					if (field.equals("m_nv4")) 
					{
						__temp_executeDef56363 = false;
						this.m_nv4 = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3342224:
				{
					if (field.equals("m_v4")) 
					{
						__temp_executeDef56363 = false;
						this.m_v4 = ((haxe.root.Array<haxor.math.Vector4>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56363) 
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
			boolean __temp_executeDef56364 = true;
			switch (field.hashCode())
			{
				case 103603075:
				{
					if (field.equals("m_nm4")) 
					{
						__temp_executeDef56364 = false;
						return this.m_nm4;
					}
					
					break;
				}
				
				
				case 105:
				{
					if (field.equals("i")) 
					{
						__temp_executeDef56364 = false;
						return this.i;
					}
					
					break;
				}
				
				
				case 3341945:
				{
					if (field.equals("m_m4")) 
					{
						__temp_executeDef56364 = false;
						return this.m_m4;
					}
					
					break;
				}
				
				
				case 118:
				{
					if (field.equals("v")) 
					{
						__temp_executeDef56364 = false;
						return this.v;
					}
					
					break;
				}
				
				
				case -1249338640:
				{
					if (field.equals("get_m4")) 
					{
						__temp_executeDef56364 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_m4"))) );
					}
					
					break;
				}
				
				
				case 3708:
				{
					if (field.equals("v2")) 
					{
						__temp_executeDef56364 = false;
						if (handleProperties) 
						{
							return this.get_v2();
						}
						 else 
						{
							return this.v2;
						}
						
					}
					
					break;
				}
				
				
				case 3431:
				{
					if (field.equals("m4")) 
					{
						__temp_executeDef56364 = false;
						if (handleProperties) 
						{
							return this.get_m4();
						}
						 else 
						{
							return this.m4;
						}
						
					}
					
					break;
				}
				
				
				case -1249338363:
				{
					if (field.equals("get_v2")) 
					{
						__temp_executeDef56364 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_v2"))) );
					}
					
					break;
				}
				
				
				case 3342037:
				{
					if (field.equals("m_nq")) 
					{
						__temp_executeDef56364 = false;
						return this.m_nq;
					}
					
					break;
				}
				
				
				case 3342222:
				{
					if (field.equals("m_v2")) 
					{
						__temp_executeDef56364 = false;
						return this.m_v2;
					}
					
					break;
				}
				
				
				case 107807:
				{
					if (field.equals("m_q")) 
					{
						__temp_executeDef56364 = false;
						return this.m_q;
					}
					
					break;
				}
				
				
				case 103603352:
				{
					if (field.equals("m_nv2")) 
					{
						__temp_executeDef56364 = false;
						return this.m_nv2;
					}
					
					break;
				}
				
				
				case 98246088:
				{
					if (field.equals("get_q")) 
					{
						__temp_executeDef56364 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_q"))) );
					}
					
					break;
				}
				
				
				case 3709:
				{
					if (field.equals("v3")) 
					{
						__temp_executeDef56364 = false;
						if (handleProperties) 
						{
							return this.get_v3();
						}
						 else 
						{
							return this.v3;
						}
						
					}
					
					break;
				}
				
				
				case 113:
				{
					if (field.equals("q")) 
					{
						__temp_executeDef56364 = false;
						if (handleProperties) 
						{
							return this.get_q();
						}
						 else 
						{
							return this.q;
						}
						
					}
					
					break;
				}
				
				
				case -1249338362:
				{
					if (field.equals("get_v3")) 
					{
						__temp_executeDef56364 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_v3"))) );
					}
					
					break;
				}
				
				
				case 3342023:
				{
					if (field.equals("m_nc")) 
					{
						__temp_executeDef56364 = false;
						return this.m_nc;
					}
					
					break;
				}
				
				
				case 3342223:
				{
					if (field.equals("m_v3")) 
					{
						__temp_executeDef56364 = false;
						return this.m_v3;
					}
					
					break;
				}
				
				
				case 107793:
				{
					if (field.equals("m_c")) 
					{
						__temp_executeDef56364 = false;
						return this.m_c;
					}
					
					break;
				}
				
				
				case 103603353:
				{
					if (field.equals("m_nv3")) 
					{
						__temp_executeDef56364 = false;
						return this.m_nv3;
					}
					
					break;
				}
				
				
				case 98246074:
				{
					if (field.equals("get_c")) 
					{
						__temp_executeDef56364 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_c"))) );
					}
					
					break;
				}
				
				
				case 3710:
				{
					if (field.equals("v4")) 
					{
						__temp_executeDef56364 = false;
						if (handleProperties) 
						{
							return this.get_v4();
						}
						 else 
						{
							return this.v4;
						}
						
					}
					
					break;
				}
				
				
				case 99:
				{
					if (field.equals("c")) 
					{
						__temp_executeDef56364 = false;
						if (handleProperties) 
						{
							return this.get_c();
						}
						 else 
						{
							return this.c;
						}
						
					}
					
					break;
				}
				
				
				case -1249338361:
				{
					if (field.equals("get_v4")) 
					{
						__temp_executeDef56364 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_v4"))) );
					}
					
					break;
				}
				
				
				case 103603354:
				{
					if (field.equals("m_nv4")) 
					{
						__temp_executeDef56364 = false;
						return this.m_nv4;
					}
					
					break;
				}
				
				
				case 3342224:
				{
					if (field.equals("m_v4")) 
					{
						__temp_executeDef56364 = false;
						return this.m_v4;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56364) 
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
			boolean __temp_executeDef56365 = true;
			switch (field.hashCode())
			{
				case 103603075:
				{
					if (field.equals("m_nm4")) 
					{
						__temp_executeDef56365 = false;
						return ((double) (this.m_nm4) );
					}
					
					break;
				}
				
				
				case 103603352:
				{
					if (field.equals("m_nv2")) 
					{
						__temp_executeDef56365 = false;
						return ((double) (this.m_nv2) );
					}
					
					break;
				}
				
				
				case 3342037:
				{
					if (field.equals("m_nq")) 
					{
						__temp_executeDef56365 = false;
						return ((double) (this.m_nq) );
					}
					
					break;
				}
				
				
				case 103603353:
				{
					if (field.equals("m_nv3")) 
					{
						__temp_executeDef56365 = false;
						return ((double) (this.m_nv3) );
					}
					
					break;
				}
				
				
				case 3342023:
				{
					if (field.equals("m_nc")) 
					{
						__temp_executeDef56365 = false;
						return ((double) (this.m_nc) );
					}
					
					break;
				}
				
				
				case 103603354:
				{
					if (field.equals("m_nv4")) 
					{
						__temp_executeDef56365 = false;
						return ((double) (this.m_nv4) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56365) 
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
			boolean __temp_executeDef56366 = true;
			switch (field.hashCode())
			{
				case -1249338640:
				{
					if (field.equals("get_m4")) 
					{
						__temp_executeDef56366 = false;
						return this.get_m4();
					}
					
					break;
				}
				
				
				case -1249338363:
				{
					if (field.equals("get_v2")) 
					{
						__temp_executeDef56366 = false;
						return this.get_v2();
					}
					
					break;
				}
				
				
				case 98246088:
				{
					if (field.equals("get_q")) 
					{
						__temp_executeDef56366 = false;
						return this.get_q();
					}
					
					break;
				}
				
				
				case -1249338362:
				{
					if (field.equals("get_v3")) 
					{
						__temp_executeDef56366 = false;
						return this.get_v3();
					}
					
					break;
				}
				
				
				case 98246074:
				{
					if (field.equals("get_c")) 
					{
						__temp_executeDef56366 = false;
						return this.get_c();
					}
					
					break;
				}
				
				
				case -1249338361:
				{
					if (field.equals("get_v4")) 
					{
						__temp_executeDef56366 = false;
						return this.get_v4();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56366) 
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
		baseArr.push("m_nm4");
		baseArr.push("m_m4");
		baseArr.push("m4");
		baseArr.push("m_nq");
		baseArr.push("m_q");
		baseArr.push("q");
		baseArr.push("m_nc");
		baseArr.push("m_c");
		baseArr.push("c");
		baseArr.push("m_nv4");
		baseArr.push("m_v4");
		baseArr.push("v4");
		baseArr.push("m_nv3");
		baseArr.push("m_v3");
		baseArr.push("v3");
		baseArr.push("m_nv2");
		baseArr.push("m_v2");
		baseArr.push("v2");
		baseArr.push("v");
		baseArr.push("i");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


