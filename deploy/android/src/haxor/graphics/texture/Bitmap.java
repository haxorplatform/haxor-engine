package haxor.graphics.texture;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Bitmap extends haxor.core.Resource
{
	public    Bitmap(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Bitmap(int p_width, int p_height, haxor.core.PixelFormat p_format)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.graphics.texture.Bitmap.__hx_ctor_haxor_graphics_texture_Bitmap(this, p_width, p_height, p_format);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_texture_Bitmap(haxor.graphics.texture.Bitmap __temp_me160518, int p_width, int p_height, haxor.core.PixelFormat p_format)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me160518, null);
		__temp_me160518.m_width = p_width;
		__temp_me160518.m_height = p_height;
		__temp_me160518.m_format = p_format;
		__temp_me160518.m_float = false;
		__temp_me160518.m_channels = 1;
		switch (haxe.root.Type.enumIndex(p_format))
		{
			case 1:
			{
				__temp_me160518.m_channels = 1;
				break;
			}
			
			
			case 0:
			{
				__temp_me160518.m_channels = 1;
				break;
			}
			
			
			case 2:
			{
				__temp_me160518.m_channels = 3;
				break;
			}
			
			
			case 3:
			{
				__temp_me160518.m_channels = 4;
				break;
			}
			
			
			case 10:
			{
				__temp_me160518.m_channels = 1;
				__temp_me160518.m_float = true;
				break;
			}
			
			
			case 7:
			{
				__temp_me160518.m_channels = 1;
				__temp_me160518.m_float = true;
				break;
			}
			
			
			case 4:
			{
				__temp_me160518.m_channels = 1;
				__temp_me160518.m_float = true;
				break;
			}
			
			
			case 8:
			{
				__temp_me160518.m_channels = 3;
				__temp_me160518.m_float = true;
				break;
			}
			
			
			case 5:
			{
				__temp_me160518.m_channels = 3;
				__temp_me160518.m_float = true;
				break;
			}
			
			
			case 9:
			{
				__temp_me160518.m_channels = 4;
				__temp_me160518.m_float = true;
				break;
			}
			
			
			case 6:
			{
				__temp_me160518.m_channels = 4;
				__temp_me160518.m_float = true;
				break;
			}
			
			
		}
		
		int len = ( ( __temp_me160518.m_width * __temp_me160518.m_height ) * __temp_me160518.m_channels );
		if (__temp_me160518.m_float) 
		{
			__temp_me160518.m_buffer = new haxor.io.FloatArray(((int) (len) ));
		}
		 else 
		{
			__temp_me160518.m_buffer = new haxor.io.Buffer(((int) (len) ));
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.texture.Bitmap(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.texture.Bitmap(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(1))) ), ((haxor.core.PixelFormat) (arr.__get(2)) ));
	}
	
	
	public  haxor.io.Buffer buffer;
	
	public   haxor.io.Buffer get_buffer()
	{
		return this.m_buffer;
	}
	
	
	public  haxor.io.Buffer m_buffer;
	
	public  boolean _float;
	
	public final   boolean get_float()
	{
		return this.m_float;
	}
	
	
	public  boolean m_float;
	
	public  int width;
	
	public final   int get_width()
	{
		return this.m_width;
	}
	
	
	public  int m_width;
	
	public  int height;
	
	public final   int get_height()
	{
		return this.m_height;
	}
	
	
	public  int m_height;
	
	public  int channels;
	
	public final   int get_channels()
	{
		return this.m_channels;
	}
	
	
	public  int m_channels;
	
	public  haxor.core.PixelFormat format;
	
	public final   haxor.core.PixelFormat get_format()
	{
		return this.m_format;
	}
	
	
	public  haxor.core.PixelFormat m_format;
	
	public   haxor.math.Color GetPixel(int p_x, int p_y)
	{
		if (( p_x < 0 )) 
		{
			return new haxor.math.Color(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		
		if (( p_y < 0 )) 
		{
			return new haxor.math.Color(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		
		if (( p_x >= this.m_width )) 
		{
			return new haxor.math.Color(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		
		if (( p_y >= this.m_height )) 
		{
			return new haxor.math.Color(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		
		int cc = this.m_channels;
		int pos = ( (( p_x + ( p_y * this.m_width ) )) * cc );
		if (this.m_float) 
		{
			haxor.math.Color c = new haxor.math.Color(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
			haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.m_buffer) );
			switch (cc)
			{
				case 1:
				{
					c.r = b.Get(pos);
					c.g = c.r;
					c.b = c.r;
					c.a = 1.0;
					break;
				}
				
				
				case 2:
				{
					c.r = b.Get(pos);
					c.g = b.Get(( pos + 1 ));
					c.b = c.r;
					c.a = 1.0;
					break;
				}
				
				
				case 3:
				{
					c.r = b.Get(pos);
					c.g = b.Get(( pos + 1 ));
					c.b = b.Get(( pos + 2 ));
					c.a = 1.0;
					break;
				}
				
				
				case 4:
				{
					c.r = b.Get(pos);
					c.g = b.Get(( pos + 1 ));
					c.b = b.Get(( pos + 2 ));
					c.a = b.Get(( pos + 3 ));
					break;
				}
				
				
			}
			
			return c;
		}
		
		haxor.io.Buffer b1 = this.m_buffer;
		int rb = b1.GetByte(pos);
		int gb = 0;
		if (( cc >= 2 )) 
		{
			gb = b1.GetByte(( pos + 1 ));
		}
		 else 
		{
			gb = rb;
		}
		
		int bb = 0;
		if (( cc >= 3 )) 
		{
			bb = b1.GetByte(( pos + 2 ));
		}
		 else 
		{
			bb = rb;
		}
		
		int ab = 0;
		if (( cc >= 4 )) 
		{
			ab = b1.GetByte(( pos + 3 ));
		}
		 else 
		{
			ab = rb;
		}
		
		return haxor.math.Color.FromBytes(rb, gb, bb, ab);
	}
	
	
	public   void SetPixel(int p_x, int p_y, haxor.math.Color p_color)
	{
		if (( p_x < 0 )) 
		{
			return ;
		}
		
		if (( p_y < 0 )) 
		{
			return ;
		}
		
		if (( p_x >= this.m_width )) 
		{
			return ;
		}
		
		if (( p_y >= this.m_height )) 
		{
			return ;
		}
		
		int cc = this.m_channels;
		int pos = ( (( p_x + ( p_y * this.m_width ) )) * cc );
		if (this.m_float) 
		{
			haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.m_buffer) );
			b.Set(pos, p_color.r);
			if (( cc >= 2 )) 
			{
				b.Set(( pos + 1 ), p_color.g);
			}
			
			if (( cc >= 3 )) 
			{
				b.Set(( pos + 2 ), p_color.b);
			}
			
			if (( cc >= 4 )) 
			{
				b.Set(( pos + 3 ), p_color.a);
			}
			
			return ;
		}
		
		haxor.io.Buffer b1 = ((haxor.io.Buffer) (this.m_buffer) );
		b1.SetByte(pos, ((int) (( p_color.r * 255.0 )) ));
		if (( cc >= 2 )) 
		{
			b1.SetByte(( pos + 1 ), ((int) (( p_color.g * 255.0 )) ));
		}
		
		if (( cc >= 3 )) 
		{
			b1.SetByte(( pos + 2 ), ((int) (( p_color.b * 255.0 )) ));
		}
		
		if (( cc >= 4 )) 
		{
			b1.SetByte(( pos + 3 ), ((int) (( p_color.a * 255.0 )) ));
		}
		
	}
	
	
	public   void Fill(haxor.math.Color p_color)
	{
		int _g1 = 0;
		int _g = this.m_width;
		while (( _g1 < _g ))
		{
			int ix = _g1++;
			int _g3 = 0;
			int _g2 = this.m_height;
			while (( _g3 < _g2 ))
			{
				int iy = _g3++;
				this.SetPixel(ix, iy, p_color);
			}
			
		}
		
	}
	
	
	public   void Set(int p_x, int p_y, java.lang.Object p_v0, java.lang.Object p_v1, java.lang.Object p_v2, java.lang.Object p_v3)
	{
		double __temp_p_v3160516 = ( (( p_v3 == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_v3)) )) );
		double __temp_p_v2160515 = ( (( p_v2 == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_v2)) )) );
		double __temp_p_v1160514 = ( (( p_v1 == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_v1)) )) );
		double __temp_p_v0160513 = ( (( p_v0 == null )) ? (((double) (0.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_v0)) )) );
		int cc = this.m_channels;
		int pos = ( (( p_x + ( p_y * this.m_width ) )) * cc );
		if (this.m_float) 
		{
			haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.m_buffer) );
			b.Set(pos, __temp_p_v0160513);
			if (( cc >= 2 )) 
			{
				b.Set(( pos + 1 ), __temp_p_v1160514);
			}
			
			if (( cc >= 3 )) 
			{
				b.Set(( pos + 2 ), __temp_p_v2160515);
			}
			
			if (( cc >= 4 )) 
			{
				b.Set(( pos + 3 ), __temp_p_v3160516);
			}
			
			return ;
		}
		
		haxor.io.Buffer b1 = ((haxor.io.Buffer) (this.m_buffer) );
		b1.SetByte(pos, ((int) (( __temp_p_v0160513 * 255.0 )) ));
		if (( cc >= 2 )) 
		{
			b1.SetByte(( pos + 1 ), ((int) (( __temp_p_v1160514 * 255.0 )) ));
		}
		
		if (( cc >= 3 )) 
		{
			b1.SetByte(( pos + 2 ), ((int) (( __temp_p_v2160515 * 255.0 )) ));
		}
		
		if (( cc >= 4 )) 
		{
			b1.SetByte(( pos + 3 ), ((int) (( __temp_p_v3160516 * 255.0 )) ));
		}
		
	}
	
	
	public   void SetRange(int p_x, int p_y, int p_width, int p_height, haxe.root.Array<java.lang.Object> p_values, java.lang.Object p_length)
	{
		int __temp_p_length160517 = ( (( p_length == null )) ? (((int) (-1) )) : (((int) (haxe.lang.Runtime.toInt(p_length)) )) );
		int cc = this.m_channels;
		int len = 0;
		if (( __temp_p_length160517 < 0 )) 
		{
			len = p_values.length;
		}
		 else 
		{
			len = __temp_p_length160517;
		}
		
		int k = 0;
		int px = p_x;
		int py = p_y;
		double v0 = 0.0;
		double v1 = 0.0;
		double v2 = 0.0;
		double v3 = 0.0;
		{
			int _g = 0;
			while (( _g < len ))
			{
				int i = _g++;
				int pos = ( (( px + ( py * this.m_width ) )) * cc );
				px++;
				if (( px >= p_width )) 
				{
					px = p_x;
					py++;
				}
				
				v0 = ((double) (haxe.lang.Runtime.toDouble(p_values.__get(k++))) );
				if (( cc >= 2 )) 
				{
					v1 = ((double) (haxe.lang.Runtime.toDouble(p_values.__get(k++))) );
				}
				
				if (( cc >= 3 )) 
				{
					v2 = ((double) (haxe.lang.Runtime.toDouble(p_values.__get(k++))) );
				}
				
				if (( cc >= 4 )) 
				{
					v3 = ((double) (haxe.lang.Runtime.toDouble(p_values.__get(k++))) );
				}
				
				if (this.m_float) 
				{
					haxor.io.FloatArray b = ((haxor.io.FloatArray) (this.m_buffer) );
					b.Set(pos, v0);
					if (( cc >= 2 )) 
					{
						b.Set(( pos + 1 ), v1);
					}
					
					if (( cc >= 3 )) 
					{
						b.Set(( pos + 2 ), v2);
					}
					
					if (( cc >= 4 )) 
					{
						b.Set(( pos + 3 ), v3);
					}
					
					continue;
				}
				
				haxor.io.Buffer b1 = ((haxor.io.Buffer) (this.m_buffer) );
				b1.SetByte(pos, ((int) (( v0 * 255.0 )) ));
				if (( cc >= 2 )) 
				{
					b1.SetByte(( pos + 1 ), ((int) (( v1 * 255.0 )) ));
				}
				
				if (( cc >= 3 )) 
				{
					b1.SetByte(( pos + 2 ), ((int) (( v2 * 255.0 )) ));
				}
				
				if (( cc >= 4 )) 
				{
					b1.SetByte(( pos + 3 ), ((int) (( v3 * 255.0 )) ));
				}
				
			}
			
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161275 = true;
			switch (field.hashCode())
			{
				case 1578008418:
				{
					if (field.equals("m_channels")) 
					{
						__temp_executeDef161275 = false;
						this.m_channels = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef161275 = false;
						this.width = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1432626128:
				{
					if (field.equals("channels")) 
					{
						__temp_executeDef161275 = false;
						this.channels = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 786549620:
				{
					if (field.equals("m_width")) 
					{
						__temp_executeDef161275 = false;
						this.m_width = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1819760327:
				{
					if (field.equals("m_height")) 
					{
						__temp_executeDef161275 = false;
						this.m_height = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef161275 = false;
						this.height = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161275) 
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
			boolean __temp_executeDef161276 = true;
			switch (field.hashCode())
			{
				case -1867509751:
				{
					if (field.equals("m_format")) 
					{
						__temp_executeDef161276 = false;
						this.m_format = ((haxor.core.PixelFormat) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1378118592:
				{
					if (field.equals("buffer")) 
					{
						__temp_executeDef161276 = false;
						this.buffer = ((haxor.io.Buffer) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1268779017:
				{
					if (field.equals("format")) 
					{
						__temp_executeDef161276 = false;
						this.format = ((haxor.core.PixelFormat) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1976849326:
				{
					if (field.equals("m_buffer")) 
					{
						__temp_executeDef161276 = false;
						this.m_buffer = ((haxor.io.Buffer) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1578008418:
				{
					if (field.equals("m_channels")) 
					{
						__temp_executeDef161276 = false;
						this.m_channels = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 97526364:
				{
					if (field.equals("float")) 
					{
						__temp_executeDef161276 = false;
						this._float = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 1432626128:
				{
					if (field.equals("channels")) 
					{
						__temp_executeDef161276 = false;
						this.channels = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 770949130:
				{
					if (field.equals("m_float")) 
					{
						__temp_executeDef161276 = false;
						this.m_float = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1819760327:
				{
					if (field.equals("m_height")) 
					{
						__temp_executeDef161276 = false;
						this.m_height = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef161276 = false;
						this.width = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef161276 = false;
						this.height = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 786549620:
				{
					if (field.equals("m_width")) 
					{
						__temp_executeDef161276 = false;
						this.m_width = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161276) 
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
			boolean __temp_executeDef161277 = true;
			switch (field.hashCode())
			{
				case 1467637275:
				{
					if (field.equals("SetRange")) 
					{
						__temp_executeDef161277 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetRange"))) );
					}
					
					break;
				}
				
				
				case -1378118592:
				{
					if (field.equals("buffer")) 
					{
						__temp_executeDef161277 = false;
						if (handleProperties) 
						{
							return this.get_buffer();
						}
						 else 
						{
							return this.buffer;
						}
						
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef161277 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 702559561:
				{
					if (field.equals("get_buffer")) 
					{
						__temp_executeDef161277 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_buffer"))) );
					}
					
					break;
				}
				
				
				case 2189731:
				{
					if (field.equals("Fill")) 
					{
						__temp_executeDef161277 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Fill"))) );
					}
					
					break;
				}
				
				
				case -1976849326:
				{
					if (field.equals("m_buffer")) 
					{
						__temp_executeDef161277 = false;
						return this.m_buffer;
					}
					
					break;
				}
				
				
				case 1466038116:
				{
					if (field.equals("SetPixel")) 
					{
						__temp_executeDef161277 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetPixel"))) );
					}
					
					break;
				}
				
				
				case 97526364:
				{
					if (field.equals("float")) 
					{
						__temp_executeDef161277 = false;
						if (handleProperties) 
						{
							return this.get_float();
						}
						 else 
						{
							return this._float;
						}
						
					}
					
					break;
				}
				
				
				case 2027150576:
				{
					if (field.equals("GetPixel")) 
					{
						__temp_executeDef161277 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetPixel"))) );
					}
					
					break;
				}
				
				
				case 1134476339:
				{
					if (field.equals("get_float")) 
					{
						__temp_executeDef161277 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_float"))) );
					}
					
					break;
				}
				
				
				case -1867509751:
				{
					if (field.equals("m_format")) 
					{
						__temp_executeDef161277 = false;
						return this.m_format;
					}
					
					break;
				}
				
				
				case 770949130:
				{
					if (field.equals("m_float")) 
					{
						__temp_executeDef161277 = false;
						return this.m_float;
					}
					
					break;
				}
				
				
				case 811899136:
				{
					if (field.equals("get_format")) 
					{
						__temp_executeDef161277 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_format"))) );
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef161277 = false;
						if (handleProperties) 
						{
							return this.get_width();
						}
						 else 
						{
							return this.width;
						}
						
					}
					
					break;
				}
				
				
				case -1268779017:
				{
					if (field.equals("format")) 
					{
						__temp_executeDef161277 = false;
						if (handleProperties) 
						{
							return this.get_format();
						}
						 else 
						{
							return this.format;
						}
						
					}
					
					break;
				}
				
				
				case 1150076829:
				{
					if (field.equals("get_width")) 
					{
						__temp_executeDef161277 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_width"))) );
					}
					
					break;
				}
				
				
				case 1578008418:
				{
					if (field.equals("m_channels")) 
					{
						__temp_executeDef161277 = false;
						return this.m_channels;
					}
					
					break;
				}
				
				
				case 786549620:
				{
					if (field.equals("m_width")) 
					{
						__temp_executeDef161277 = false;
						return this.m_width;
					}
					
					break;
				}
				
				
				case -490428775:
				{
					if (field.equals("get_channels")) 
					{
						__temp_executeDef161277 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_channels"))) );
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef161277 = false;
						if (handleProperties) 
						{
							return this.get_height();
						}
						 else 
						{
							return this.height;
						}
						
					}
					
					break;
				}
				
				
				case 1432626128:
				{
					if (field.equals("channels")) 
					{
						__temp_executeDef161277 = false;
						if (handleProperties) 
						{
							return this.get_channels();
						}
						 else 
						{
							return this.channels;
						}
						
					}
					
					break;
				}
				
				
				case 859648560:
				{
					if (field.equals("get_height")) 
					{
						__temp_executeDef161277 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_height"))) );
					}
					
					break;
				}
				
				
				case -1819760327:
				{
					if (field.equals("m_height")) 
					{
						__temp_executeDef161277 = false;
						return this.m_height;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161277) 
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
			boolean __temp_executeDef161278 = true;
			switch (field.hashCode())
			{
				case 1578008418:
				{
					if (field.equals("m_channels")) 
					{
						__temp_executeDef161278 = false;
						return ((double) (this.m_channels) );
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef161278 = false;
						if (handleProperties) 
						{
							return ((double) (this.get_width()) );
						}
						 else 
						{
							return ((double) (this.width) );
						}
						
					}
					
					break;
				}
				
				
				case 1432626128:
				{
					if (field.equals("channels")) 
					{
						__temp_executeDef161278 = false;
						if (handleProperties) 
						{
							return ((double) (this.get_channels()) );
						}
						 else 
						{
							return ((double) (this.channels) );
						}
						
					}
					
					break;
				}
				
				
				case 786549620:
				{
					if (field.equals("m_width")) 
					{
						__temp_executeDef161278 = false;
						return ((double) (this.m_width) );
					}
					
					break;
				}
				
				
				case -1819760327:
				{
					if (field.equals("m_height")) 
					{
						__temp_executeDef161278 = false;
						return ((double) (this.m_height) );
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef161278 = false;
						if (handleProperties) 
						{
							return ((double) (this.get_height()) );
						}
						 else 
						{
							return ((double) (this.height) );
						}
						
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161278) 
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
			boolean __temp_executeDef161279 = true;
			switch (field.hashCode())
			{
				case 1467637275:
				{
					if (field.equals("SetRange")) 
					{
						__temp_executeDef161279 = false;
						this.SetRange(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(4)) ), dynargs.__get(5));
					}
					
					break;
				}
				
				
				case 702559561:
				{
					if (field.equals("get_buffer")) 
					{
						__temp_executeDef161279 = false;
						return this.get_buffer();
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef161279 = false;
						this.Set(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), dynargs.__get(2), dynargs.__get(3), dynargs.__get(4), dynargs.__get(5));
					}
					
					break;
				}
				
				
				case 1134476339:
				{
					if (field.equals("get_float")) 
					{
						__temp_executeDef161279 = false;
						return this.get_float();
					}
					
					break;
				}
				
				
				case 2189731:
				{
					if (field.equals("Fill")) 
					{
						__temp_executeDef161279 = false;
						this.Fill(((haxor.math.Color) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1150076829:
				{
					if (field.equals("get_width")) 
					{
						__temp_executeDef161279 = false;
						return this.get_width();
					}
					
					break;
				}
				
				
				case 1466038116:
				{
					if (field.equals("SetPixel")) 
					{
						__temp_executeDef161279 = false;
						this.SetPixel(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((haxor.math.Color) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case 859648560:
				{
					if (field.equals("get_height")) 
					{
						__temp_executeDef161279 = false;
						return this.get_height();
					}
					
					break;
				}
				
				
				case 2027150576:
				{
					if (field.equals("GetPixel")) 
					{
						__temp_executeDef161279 = false;
						return this.GetPixel(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -490428775:
				{
					if (field.equals("get_channels")) 
					{
						__temp_executeDef161279 = false;
						return this.get_channels();
					}
					
					break;
				}
				
				
				case 811899136:
				{
					if (field.equals("get_format")) 
					{
						__temp_executeDef161279 = false;
						return this.get_format();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161279) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_format");
		baseArr.push("format");
		baseArr.push("m_channels");
		baseArr.push("channels");
		baseArr.push("m_height");
		baseArr.push("height");
		baseArr.push("m_width");
		baseArr.push("width");
		baseArr.push("m_float");
		baseArr.push("float");
		baseArr.push("m_buffer");
		baseArr.push("buffer");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


