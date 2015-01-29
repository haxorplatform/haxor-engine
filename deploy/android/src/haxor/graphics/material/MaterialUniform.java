package haxor.graphics.material;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MaterialUniform extends haxe.lang.HxObject
{
	public    MaterialUniform(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    MaterialUniform(java.lang.String p_name, boolean p_is_float, int p_length, int p_offset)
	{
		haxor.graphics.material.MaterialUniform.__hx_ctor_haxor_graphics_material_MaterialUniform(this, p_name, p_is_float, p_length, p_offset);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_material_MaterialUniform(haxor.graphics.material.MaterialUniform __temp_me221, java.lang.String p_name, boolean p_is_float, int p_length, int p_offset)
	{
		{
			haxor.context.UID _this = haxor.context.EngineContext.material.uid;
			if (( _this.m_cache.length <= 0 )) 
			{
				__temp_me221.__cid = _this.m_id++;
			}
			 else 
			{
				__temp_me221.__cid = ((int) (haxe.lang.Runtime.toInt(_this.m_cache.shift())) );
			}
			
		}
		
		__temp_me221.__d = true;
		__temp_me221.name = p_name;
		__temp_me221.isFloat = p_is_float;
		__temp_me221.offset = p_offset;
		__temp_me221.exists = false;
		if (p_is_float) 
		{
			__temp_me221.data = new haxor.io.FloatArray(((int) (p_length) ));
		}
		 else 
		{
			__temp_me221.data = new haxor.io.Int32Array(((int) (p_length) ));
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.material.MaterialUniform(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.material.MaterialUniform(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toBool(arr.__get(1)), ((int) (haxe.lang.Runtime.toInt(arr.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(3))) ));
	}
	
	
	public  int __cid;
	
	public  boolean __d;
	
	public  java.lang.String name;
	
	public  haxor.io.Buffer data;
	
	public  int offset;
	
	public  haxor.graphics.texture.Texture texture;
	
	public  boolean isFloat;
	
	public  boolean exists;
	
	public   void SetFloat(double p_v)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.data) );
		b.Set(0, p_v);
	}
	
	
	public   void SetFloat2(double p_x, double p_y)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.data) );
		b.Set(0, p_x);
		b.Set(1, p_y);
	}
	
	
	public   void SetFloat3(double p_x, double p_y, double p_z)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.data) );
		b.Set(0, p_x);
		b.Set(1, p_y);
		b.Set(2, p_z);
	}
	
	
	public   void SetFloat4(double p_x, double p_y, double p_z, double p_w)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.data) );
		b.Set(0, p_x);
		b.Set(1, p_y);
		b.Set(2, p_z);
		b.Set(3, p_w);
	}
	
	
	public   void SetFloatArray(haxe.root.Array<java.lang.Object> p_list)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.data) );
		{
			int _g1 = 0;
			int _g = p_list.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				b.Set(i, ((double) (haxe.lang.Runtime.toDouble(p_list.__get(i))) ));
			}
			
		}
		
	}
	
	
	public   void SetFloat2Array(haxe.root.Array<java.lang.Object> p_list)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.data) );
		{
			int _g1 = 0;
			int _g = p_list.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				b.Set(i, ((double) (haxe.lang.Runtime.toDouble(p_list.__get(i))) ));
			}
			
		}
		
	}
	
	
	public   void SetFloat3Array(haxe.root.Array<java.lang.Object> p_list)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.data) );
		{
			int _g1 = 0;
			int _g = p_list.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				b.Set(i, ((double) (haxe.lang.Runtime.toDouble(p_list.__get(i))) ));
			}
			
		}
		
	}
	
	
	public   void SetFloat4Array(haxe.root.Array<java.lang.Object> p_list)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.data) );
		{
			int _g1 = 0;
			int _g = p_list.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				b.Set(i, ((double) (haxe.lang.Runtime.toDouble(p_list.__get(i))) ));
			}
			
		}
		
	}
	
	
	public   void SetInt(int p_v)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.Int32Array b = ((haxor.io.Int32Array) (this.data) );
		b.Set(0, p_v);
	}
	
	
	public   void SetInt2(int p_x, int p_y)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.Int32Array b = ((haxor.io.Int32Array) (this.data) );
		b.Set(0, p_x);
		b.Set(1, p_y);
	}
	
	
	public   void SetInt3(int p_x, int p_y, int p_z)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.Int32Array b = ((haxor.io.Int32Array) (this.data) );
		b.Set(0, p_x);
		b.Set(1, p_y);
		b.Set(2, p_z);
	}
	
	
	public   void SetInt4(int p_x, int p_y, int p_z, int p_w)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.Int32Array b = ((haxor.io.Int32Array) (this.data) );
		b.Set(0, p_x);
		b.Set(1, p_y);
		b.Set(2, p_z);
		b.Set(3, p_w);
	}
	
	
	public   void SetIntArray(haxe.root.Array<java.lang.Object> p_list)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.Int32Array b = ((haxor.io.Int32Array) (this.data) );
		{
			int _g1 = 0;
			int _g = p_list.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				b.Set(i, ((int) (haxe.lang.Runtime.toInt(p_list.__get(i))) ));
			}
			
		}
		
	}
	
	
	public   void SetInt2Array(haxe.root.Array<java.lang.Object> p_list)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.Int32Array b = ((haxor.io.Int32Array) (this.data) );
		{
			int _g1 = 0;
			int _g = p_list.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				b.Set(i, ((int) (haxe.lang.Runtime.toInt(p_list.__get(i))) ));
			}
			
		}
		
	}
	
	
	public   void SetInt3Array(haxe.root.Array<java.lang.Object> p_list)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.Int32Array b = ((haxor.io.Int32Array) (this.data) );
		{
			int _g1 = 0;
			int _g = p_list.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				b.Set(i, ((int) (haxe.lang.Runtime.toInt(p_list.__get(i))) ));
			}
			
		}
		
	}
	
	
	public   void SetInt4Array(haxe.root.Array<java.lang.Object> p_list)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.Int32Array b = ((haxor.io.Int32Array) (this.data) );
		{
			int _g1 = 0;
			int _g = p_list.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				b.Set(i, ((int) (haxe.lang.Runtime.toInt(p_list.__get(i))) ));
			}
			
		}
		
	}
	
	
	public   void SetTexture(haxor.graphics.texture.Texture p_texture)
	{
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.Int32Array b = ((haxor.io.Int32Array) (this.data) );
		b.Set(0, p_texture.__slot);
		this.texture = p_texture;
	}
	
	
	public   void SetMatrix4(haxor.math.Matrix4 m, java.lang.Object t)
	{
		boolean __temp_t220 = ( (( t == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(t)) );
		if ( ! (this.exists) ) 
		{
			return ;
		}
		
		this.__d = true;
		haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.data) );
		if ( ! (__temp_t220) ) 
		{
			b.Set(0, m.m00);
			b.Set(1, m.m01);
			b.Set(2, m.m02);
			b.Set(3, m.m03);
			b.Set(4, m.m10);
			b.Set(5, m.m11);
			b.Set(6, m.m12);
			b.Set(7, m.m13);
			b.Set(8, m.m20);
			b.Set(9, m.m21);
			b.Set(10, m.m22);
			b.Set(11, m.m23);
			b.Set(12, m.m30);
			b.Set(13, m.m31);
			b.Set(14, m.m32);
			b.Set(15, m.m33);
		}
		 else 
		{
			b.Set(0, m.m00);
			b.Set(1, m.m10);
			b.Set(2, m.m20);
			b.Set(3, m.m30);
			b.Set(4, m.m01);
			b.Set(5, m.m11);
			b.Set(6, m.m21);
			b.Set(7, m.m31);
			b.Set(8, m.m02);
			b.Set(9, m.m12);
			b.Set(10, m.m22);
			b.Set(11, m.m32);
			b.Set(12, m.m03);
			b.Set(13, m.m13);
			b.Set(14, m.m23);
			b.Set(15, m.m33);
		}
		
	}
	
	
	public final   void SetVector2(haxor.math.Vector2 p_v)
	{
		this.SetFloat2(p_v.x, p_v.y);
	}
	
	
	public final   void SetVector3(haxor.math.Vector3 p_v)
	{
		this.SetFloat3(p_v.x, p_v.y, p_v.z);
	}
	
	
	public final   void SetVector4(haxor.math.Vector4 p_v)
	{
		this.SetFloat4(p_v.x, p_v.y, p_v.z, p_v.w);
	}
	
	
	public final   void SetColor(haxor.math.Color p_color)
	{
		this.SetFloat4(p_color.r, p_color.g, p_color.b, p_color.a);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef1007 = true;
			switch (field.hashCode())
			{
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef1007 = false;
						this.offset = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef1007 = false;
						this.__cid = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1007) 
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
			boolean __temp_executeDef1008 = true;
			switch (field.hashCode())
			{
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef1008 = false;
						this.exists = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef1008 = false;
						this.__cid = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 2058932050:
				{
					if (field.equals("isFloat")) 
					{
						__temp_executeDef1008 = false;
						this.isFloat = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 94340:
				{
					if (field.equals("__d")) 
					{
						__temp_executeDef1008 = false;
						this.__d = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1417816805:
				{
					if (field.equals("texture")) 
					{
						__temp_executeDef1008 = false;
						this.texture = ((haxor.graphics.texture.Texture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef1008 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef1008 = false;
						this.offset = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef1008 = false;
						this.data = ((haxor.io.Buffer) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1008) 
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
			boolean __temp_executeDef1009 = true;
			switch (field.hashCode())
			{
				case 1454199873:
				{
					if (field.equals("SetColor")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetColor"))) );
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef1009 = false;
						return this.__cid;
					}
					
					break;
				}
				
				
				case 1009953967:
				{
					if (field.equals("SetVector4")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetVector4"))) );
					}
					
					break;
				}
				
				
				case 94340:
				{
					if (field.equals("__d")) 
					{
						__temp_executeDef1009 = false;
						return this.__d;
					}
					
					break;
				}
				
				
				case 1009953966:
				{
					if (field.equals("SetVector3")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetVector3"))) );
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef1009 = false;
						return this.name;
					}
					
					break;
				}
				
				
				case 1009953965:
				{
					if (field.equals("SetVector2")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetVector2"))) );
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef1009 = false;
						return this.data;
					}
					
					break;
				}
				
				
				case 1513473521:
				{
					if (field.equals("SetMatrix4")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetMatrix4"))) );
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef1009 = false;
						return this.offset;
					}
					
					break;
				}
				
				
				case -745653639:
				{
					if (field.equals("SetTexture")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetTexture"))) );
					}
					
					break;
				}
				
				
				case -1417816805:
				{
					if (field.equals("texture")) 
					{
						__temp_executeDef1009 = false;
						return this.texture;
					}
					
					break;
				}
				
				
				case 758624530:
				{
					if (field.equals("SetInt4Array")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt4Array"))) );
					}
					
					break;
				}
				
				
				case 2058932050:
				{
					if (field.equals("isFloat")) 
					{
						__temp_executeDef1009 = false;
						return this.isFloat;
					}
					
					break;
				}
				
				
				case 729995379:
				{
					if (field.equals("SetInt3Array")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt3Array"))) );
					}
					
					break;
				}
				
				
				case -1289358244:
				{
					if (field.equals("exists")) 
					{
						__temp_executeDef1009 = false;
						return this.exists;
					}
					
					break;
				}
				
				
				case 701366228:
				{
					if (field.equals("SetInt2Array")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt2Array"))) );
					}
					
					break;
				}
				
				
				case 1456883514:
				{
					if (field.equals("SetFloat")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat"))) );
					}
					
					break;
				}
				
				
				case -100610548:
				{
					if (field.equals("SetIntArray")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetIntArray"))) );
					}
					
					break;
				}
				
				
				case -2081251272:
				{
					if (field.equals("SetFloat2")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat2"))) );
					}
					
					break;
				}
				
				
				case -645649017:
				{
					if (field.equals("SetInt4")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt4"))) );
					}
					
					break;
				}
				
				
				case -2081251271:
				{
					if (field.equals("SetFloat3")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat3"))) );
					}
					
					break;
				}
				
				
				case -645649018:
				{
					if (field.equals("SetInt3")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt3"))) );
					}
					
					break;
				}
				
				
				case -2081251270:
				{
					if (field.equals("SetFloat4")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat4"))) );
					}
					
					break;
				}
				
				
				case -645649019:
				{
					if (field.equals("SetInt2")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt2"))) );
					}
					
					break;
				}
				
				
				case 230731583:
				{
					if (field.equals("SetFloatArray")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloatArray"))) );
					}
					
					break;
				}
				
				
				case -1821942707:
				{
					if (field.equals("SetInt")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetInt"))) );
					}
					
					break;
				}
				
				
				case -1911929599:
				{
					if (field.equals("SetFloat2Array")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat2Array"))) );
					}
					
					break;
				}
				
				
				case -1854671297:
				{
					if (field.equals("SetFloat4Array")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat4Array"))) );
					}
					
					break;
				}
				
				
				case -1883300448:
				{
					if (field.equals("SetFloat3Array")) 
					{
						__temp_executeDef1009 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFloat3Array"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1009) 
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
			boolean __temp_executeDef1010 = true;
			switch (field.hashCode())
			{
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef1010 = false;
						return ((double) (this.offset) );
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef1010 = false;
						return ((double) (this.__cid) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1010) 
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
			boolean __temp_executeDef1011 = true;
			switch (field.hashCode())
			{
				case 1454199873:
				{
					if (field.equals("SetColor")) 
					{
						__temp_executeDef1011 = false;
						this.SetColor(((haxor.math.Color) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1456883514:
				{
					if (field.equals("SetFloat")) 
					{
						__temp_executeDef1011 = false;
						this.SetFloat(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1009953967:
				{
					if (field.equals("SetVector4")) 
					{
						__temp_executeDef1011 = false;
						this.SetVector4(((haxor.math.Vector4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -2081251272:
				{
					if (field.equals("SetFloat2")) 
					{
						__temp_executeDef1011 = false;
						this.SetFloat2(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 1009953966:
				{
					if (field.equals("SetVector3")) 
					{
						__temp_executeDef1011 = false;
						this.SetVector3(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -2081251271:
				{
					if (field.equals("SetFloat3")) 
					{
						__temp_executeDef1011 = false;
						this.SetFloat3(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case 1009953965:
				{
					if (field.equals("SetVector2")) 
					{
						__temp_executeDef1011 = false;
						this.SetVector2(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -2081251270:
				{
					if (field.equals("SetFloat4")) 
					{
						__temp_executeDef1011 = false;
						this.SetFloat4(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case 1513473521:
				{
					if (field.equals("SetMatrix4")) 
					{
						__temp_executeDef1011 = false;
						this.SetMatrix4(((haxor.math.Matrix4) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 230731583:
				{
					if (field.equals("SetFloatArray")) 
					{
						__temp_executeDef1011 = false;
						this.SetFloatArray(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -745653639:
				{
					if (field.equals("SetTexture")) 
					{
						__temp_executeDef1011 = false;
						this.SetTexture(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1911929599:
				{
					if (field.equals("SetFloat2Array")) 
					{
						__temp_executeDef1011 = false;
						this.SetFloat2Array(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 758624530:
				{
					if (field.equals("SetInt4Array")) 
					{
						__temp_executeDef1011 = false;
						this.SetInt4Array(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1883300448:
				{
					if (field.equals("SetFloat3Array")) 
					{
						__temp_executeDef1011 = false;
						this.SetFloat3Array(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 729995379:
				{
					if (field.equals("SetInt3Array")) 
					{
						__temp_executeDef1011 = false;
						this.SetInt3Array(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1854671297:
				{
					if (field.equals("SetFloat4Array")) 
					{
						__temp_executeDef1011 = false;
						this.SetFloat4Array(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 701366228:
				{
					if (field.equals("SetInt2Array")) 
					{
						__temp_executeDef1011 = false;
						this.SetInt2Array(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1821942707:
				{
					if (field.equals("SetInt")) 
					{
						__temp_executeDef1011 = false;
						this.SetInt(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -100610548:
				{
					if (field.equals("SetIntArray")) 
					{
						__temp_executeDef1011 = false;
						this.SetIntArray(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -645649019:
				{
					if (field.equals("SetInt2")) 
					{
						__temp_executeDef1011 = false;
						this.SetInt2(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -645649017:
				{
					if (field.equals("SetInt4")) 
					{
						__temp_executeDef1011 = false;
						this.SetInt4(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case -645649018:
				{
					if (field.equals("SetInt3")) 
					{
						__temp_executeDef1011 = false;
						this.SetInt3(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1011) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("exists");
		baseArr.push("isFloat");
		baseArr.push("texture");
		baseArr.push("offset");
		baseArr.push("data");
		baseArr.push("name");
		baseArr.push("__d");
		baseArr.push("__cid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


