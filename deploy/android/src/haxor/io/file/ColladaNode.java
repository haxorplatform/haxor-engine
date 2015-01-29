package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaNode extends haxe.lang.HxObject
{
	public    ColladaNode(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaNode()
	{
		haxor.io.file.ColladaNode.__hx_ctor_haxor_io_file_ColladaNode(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaNode(haxor.io.file.ColladaNode __temp_me305)
	{
		__temp_me305.instances = null;
		__temp_me305.local = null;
		__temp_me305.data = "";
		__temp_me305.children = null;
		__temp_me305.parent = null;
		__temp_me305.scene = null;
		__temp_me305.matrix = null;
		__temp_me305.name = "";
		__temp_me305.sid = "";
		__temp_me305.id = "";
		__temp_me305.type = "";
		__temp_me305.children = new haxe.root.Array<haxor.io.file.ColladaNode>(new haxor.io.file.ColladaNode[]{});
		__temp_me305.instances = new haxe.root.Array<haxor.io.file.ColladaInstance>(new haxor.io.file.ColladaInstance[]{});
		__temp_me305.matrix = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) )});
		__temp_me305.position = new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
		__temp_me305.rotation = new haxor.math.Quaternion(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1.0) ));
		__temp_me305.scale = new haxor.math.Vector3(((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaNode(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaNode();
	}
	
	
	public  java.lang.String type;
	
	public  java.lang.String id;
	
	public  java.lang.String sid;
	
	public  java.lang.String name;
	
	public  haxe.root.Array<java.lang.Object> matrix;
	
	public  haxor.io.file.ColladaVisualScene scene;
	
	public  haxor.io.file.ColladaNode parent;
	
	public  haxe.root.Array<haxor.io.file.ColladaNode> children;
	
	public  java.lang.String data;
	
	public  haxor.math.Matrix4 local;
	
	
	
	public   haxor.math.Matrix4 get_world()
	{
		if (( this.m_world != null )) 
		{
			return this.m_world;
		}
		
		this.m_world = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		haxor.io.file.ColladaNode it = this;
		haxe.root.Array<haxor.io.file.ColladaNode> h = new haxe.root.Array<haxor.io.file.ColladaNode>(new haxor.io.file.ColladaNode[]{});
		while (( it != null ))
		{
			h.push(it);
			it = it.parent;
		}
		
		h.reverse();
		{
			int _g1 = 0;
			int _g = h.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				this.m_world.MultiplyTransform(h.__get(i).local);
			}
			
		}
		
		return this.m_world;
	}
	
	
	public  haxor.math.Matrix4 m_world;
	
	public  haxor.math.Vector3 position;
	
	public  haxor.math.Quaternion rotation;
	
	public  haxor.math.Vector3 scale;
	
	public  haxe.root.Array<haxor.io.file.ColladaInstance> instances;
	
	public   void GenerateTranform()
	{
		haxor.math.Matrix4 mtx = this.local = haxor.math.Matrix4.FromArray(this.matrix, null);
		{
			haxor.math.Vector4 _this = null;
			{
				haxor.math.Matrix4 _this1 = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (mtx.m03) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (mtx.m13) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (mtx.m23) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
				haxor.math.Vector4 p_result = null;
				if (( p_result == null )) 
				{
					p_result = new haxor.math.Vector4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
				}
				 else 
				{
					p_result = p_result;
				}
				
				_this = p_result.Set(_this1.GetRowCol(0, 3), _this1.GetRowCol(1, 3), _this1.GetRowCol(2, 3), _this1.GetRowCol(3, 3));
			}
			
			this.position = new haxor.math.Vector3(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ), ((java.lang.Object) (_this.z) ));
		}
		
		haxor.math.Matrix4 __temp_stmt1194 = null;
		{
			haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
			__temp_stmt1194 = _this2.m_m4.__get(_this2.m_nq = ( (( _this2.m_nm4 + 1 )) % _this2.m_m4.length ));
		}
		
		haxor.math.Matrix4 __temp_stmt1193 = __temp_stmt1194.SetMatrix4(mtx);
		haxor.math.Matrix4 __temp_stmt1192 = __temp_stmt1193.ToRotation();
		this.rotation = haxor.math.Quaternion.FromMatrix4(__temp_stmt1192, null);
		{
			haxor.math.Vector4 _this3 = null;
			{
				haxor.math.Matrix4 _this4 = null;
				{
					double d0 = java.lang.Math.sqrt(( ( ( mtx.m00 * mtx.m00 ) + ( mtx.m10 * mtx.m10 ) ) + ( mtx.m20 * mtx.m20 ) ));
					double d1 = java.lang.Math.sqrt(( ( ( mtx.m01 * mtx.m01 ) + ( mtx.m11 * mtx.m11 ) ) + ( mtx.m21 * mtx.m21 ) ));
					double d2 = java.lang.Math.sqrt(( ( ( mtx.m02 * mtx.m02 ) + ( mtx.m12 * mtx.m12 ) ) + ( mtx.m22 * mtx.m22 ) ));
					_this4 = new haxor.math.Matrix4(((java.lang.Object) (d0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (d1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (d2) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
				}
				
				_this3 = new haxor.math.Vector4(((java.lang.Object) (_this4.m00) ), ((java.lang.Object) (_this4.m11) ), ((java.lang.Object) (_this4.m22) ), ((java.lang.Object) (_this4.m33) ));
			}
			
			this.scale = new haxor.math.Vector3(((java.lang.Object) (_this3.x) ), ((java.lang.Object) (_this3.y) ), ((java.lang.Object) (_this3.z) ));
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef1195 = true;
			switch (field.hashCode())
			{
				case 29097598:
				{
					if (field.equals("instances")) 
					{
						__temp_executeDef1195 = false;
						this.instances = ((haxe.root.Array<haxor.io.file.ColladaInstance>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef1195 = false;
						this.type = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 109250890:
				{
					if (field.equals("scale")) 
					{
						__temp_executeDef1195 = false;
						this.scale = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef1195 = false;
						this.id = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -40300674:
				{
					if (field.equals("rotation")) 
					{
						__temp_executeDef1195 = false;
						this.rotation = ((haxor.math.Quaternion) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 113870:
				{
					if (field.equals("sid")) 
					{
						__temp_executeDef1195 = false;
						this.sid = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 747804969:
				{
					if (field.equals("position")) 
					{
						__temp_executeDef1195 = false;
						this.position = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef1195 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 786741568:
				{
					if (field.equals("m_world")) 
					{
						__temp_executeDef1195 = false;
						this.m_world = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1081239615:
				{
					if (field.equals("matrix")) 
					{
						__temp_executeDef1195 = false;
						this.matrix = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103145323:
				{
					if (field.equals("local")) 
					{
						__temp_executeDef1195 = false;
						this.local = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 109254796:
				{
					if (field.equals("scene")) 
					{
						__temp_executeDef1195 = false;
						this.scene = ((haxor.io.file.ColladaVisualScene) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef1195 = false;
						this.data = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -995424086:
				{
					if (field.equals("parent")) 
					{
						__temp_executeDef1195 = false;
						this.parent = ((haxor.io.file.ColladaNode) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1659526655:
				{
					if (field.equals("children")) 
					{
						__temp_executeDef1195 = false;
						this.children = ((haxe.root.Array<haxor.io.file.ColladaNode>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1195) 
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
			boolean __temp_executeDef1196 = true;
			switch (field.hashCode())
			{
				case -2110035164:
				{
					if (field.equals("GenerateTranform")) 
					{
						__temp_executeDef1196 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GenerateTranform"))) );
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef1196 = false;
						return this.type;
					}
					
					break;
				}
				
				
				case 29097598:
				{
					if (field.equals("instances")) 
					{
						__temp_executeDef1196 = false;
						return this.instances;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef1196 = false;
						return this.id;
					}
					
					break;
				}
				
				
				case 109250890:
				{
					if (field.equals("scale")) 
					{
						__temp_executeDef1196 = false;
						return this.scale;
					}
					
					break;
				}
				
				
				case 113870:
				{
					if (field.equals("sid")) 
					{
						__temp_executeDef1196 = false;
						return this.sid;
					}
					
					break;
				}
				
				
				case -40300674:
				{
					if (field.equals("rotation")) 
					{
						__temp_executeDef1196 = false;
						return this.rotation;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef1196 = false;
						return this.name;
					}
					
					break;
				}
				
				
				case 747804969:
				{
					if (field.equals("position")) 
					{
						__temp_executeDef1196 = false;
						return this.position;
					}
					
					break;
				}
				
				
				case -1081239615:
				{
					if (field.equals("matrix")) 
					{
						__temp_executeDef1196 = false;
						return this.matrix;
					}
					
					break;
				}
				
				
				case 786741568:
				{
					if (field.equals("m_world")) 
					{
						__temp_executeDef1196 = false;
						return this.m_world;
					}
					
					break;
				}
				
				
				case 109254796:
				{
					if (field.equals("scene")) 
					{
						__temp_executeDef1196 = false;
						return this.scene;
					}
					
					break;
				}
				
				
				case 1150268777:
				{
					if (field.equals("get_world")) 
					{
						__temp_executeDef1196 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_world"))) );
					}
					
					break;
				}
				
				
				case -995424086:
				{
					if (field.equals("parent")) 
					{
						__temp_executeDef1196 = false;
						return this.parent;
					}
					
					break;
				}
				
				
				case 113318802:
				{
					if (field.equals("world")) 
					{
						__temp_executeDef1196 = false;
						return this.get_world();
					}
					
					break;
				}
				
				
				case 1659526655:
				{
					if (field.equals("children")) 
					{
						__temp_executeDef1196 = false;
						return this.children;
					}
					
					break;
				}
				
				
				case 103145323:
				{
					if (field.equals("local")) 
					{
						__temp_executeDef1196 = false;
						return this.local;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef1196 = false;
						return this.data;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1196) 
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
			boolean __temp_executeDef1197 = true;
			switch (field.hashCode())
			{
				case -2110035164:
				{
					if (field.equals("GenerateTranform")) 
					{
						__temp_executeDef1197 = false;
						this.GenerateTranform();
					}
					
					break;
				}
				
				
				case 1150268777:
				{
					if (field.equals("get_world")) 
					{
						__temp_executeDef1197 = false;
						return this.get_world();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1197) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("instances");
		baseArr.push("scale");
		baseArr.push("rotation");
		baseArr.push("position");
		baseArr.push("m_world");
		baseArr.push("world");
		baseArr.push("local");
		baseArr.push("data");
		baseArr.push("children");
		baseArr.push("parent");
		baseArr.push("scene");
		baseArr.push("matrix");
		baseArr.push("name");
		baseArr.push("sid");
		baseArr.push("id");
		baseArr.push("type");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


