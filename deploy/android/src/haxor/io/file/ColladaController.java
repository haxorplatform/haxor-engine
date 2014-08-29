package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaController extends haxe.lang.HxObject
{
	public    ColladaController(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaController()
	{
		haxor.io.file.ColladaController.__hx_ctor_haxor_io_file_ColladaController(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaController(haxor.io.file.ColladaController __temp_me80717)
	{
		__temp_me80717.bones = null;
		__temp_me80717.weights = null;
		__temp_me80717.indexes = null;
		__temp_me80717.vcount = null;
		__temp_me80717.inputs = null;
		__temp_me80717.joints = null;
		__temp_me80717.binds = null;
		__temp_me80717.matrix = null;
		__temp_me80717.name = "";
		__temp_me80717.id = "";
		__temp_me80717.source = "";
		__temp_me80717.type = "";
		__temp_me80717.matrix = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me80717.binds = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{});
		__temp_me80717.inputs = new haxe.root.Array<haxor.io.file.ColladaInput>(new haxor.io.file.ColladaInput[]{});
		__temp_me80717.joints = new haxe.root.Array<java.lang.String>(new java.lang.String[]{});
		__temp_me80717.vcount = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me80717.indexes = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{});
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaController(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaController();
	}
	
	
	public  java.lang.String type;
	
	public  java.lang.String source;
	
	public  java.lang.String id;
	
	public  java.lang.String name;
	
	public  haxe.root.Array<java.lang.Object> matrix;
	
	public  haxe.root.Array<haxe.root.Array> binds;
	
	public  haxe.root.Array<java.lang.String> joints;
	
	public  haxe.root.Array<haxor.io.file.ColladaInput> inputs;
	
	public  haxe.root.Array<java.lang.Object> vcount;
	
	public  haxe.root.Array<haxe.root.Array> indexes;
	
	public  haxe.root.Array<haxor.math.Vector4> weights;
	
	public  haxe.root.Array<haxor.math.Vector4> bones;
	
	
	
	public   int get_offset()
	{
		int mo = 0;
		{
			int _g1 = 0;
			int _g = this.inputs.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				mo = ((int) (java.lang.Math.max(((double) (mo) ), ((double) (( this.inputs.__get(i).offset + 1 )) ))) );
			}
			
		}
		
		return mo;
	}
	
	
	public   haxor.math.Matrix4 GetBSM()
	{
		haxor.math.Matrix4 mtx = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		{
			int _g1 = 0;
			int _g = this.matrix.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				mtx.SetIndex(i, ((double) (haxe.lang.Runtime.toDouble(this.matrix.__get(i))) ));
			}
			
		}
		
		return mtx;
	}
	
	
	public   int GetJointIndex(java.lang.String p_joint)
	{
		{
			int _g1 = 0;
			int _g = this.joints.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(p_joint, this.joints.__get(i))) 
				{
					return i;
				}
				
			}
			
		}
		
		return -1;
	}
	
	
	public   haxe.root.Array<haxor.math.Matrix4> GetBinds()
	{
		haxe.root.Array<haxor.math.Matrix4> res = new haxe.root.Array<haxor.math.Matrix4>(new haxor.math.Matrix4[]{});
		{
			int _g1 = 0;
			int _g = this.binds.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.math.Matrix4 mtx = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
				{
					int _g3 = 0;
					int _g2 = ((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.binds.__get(i)) )) ).length;
					while (( _g3 < _g2 ))
					{
						int j = _g3++;
						mtx.SetIndex(j, ((double) (haxe.lang.Runtime.toDouble(((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.binds.__get(i)) )) ).__get(j))) ));
					}
					
				}
				
				res.push(mtx);
			}
			
		}
		
		return res;
	}
	
	
	public   haxe.root.Array<haxor.math.Vector4> GetTriangulatedWeights(haxor.io.file.ColladaPrimitive cp)
	{
		int v_off = cp.GetInput("vertex", null).offset;
		haxe.root.Array<haxor.math.Vector4> res = new haxe.root.Array<haxor.math.Vector4>(new haxor.math.Vector4[]{});
		{
			int _g1 = 0;
			int _g = cp.get_triangles().length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				int idx = ((int) (haxe.lang.Runtime.toInt(((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (cp.get_triangles().__get(i)) )) ).__get(v_off))) );
				res.push(this.weights.__get(idx));
			}
			
		}
		
		return res;
	}
	
	
	public   haxe.root.Array<haxor.math.Vector4> GetTriangulatedBones(haxor.io.file.ColladaPrimitive cp)
	{
		int v_off = cp.GetInput("vertex", null).offset;
		haxe.root.Array<haxor.math.Vector4> res = new haxe.root.Array<haxor.math.Vector4>(new haxor.math.Vector4[]{});
		{
			int _g1 = 0;
			int _g = cp.get_triangles().length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				int idx = ((int) (haxe.lang.Runtime.toInt(((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (cp.get_triangles().__get(i)) )) ).__get(v_off))) );
				res.push(this.bones.__get(idx));
			}
			
		}
		
		return res;
	}
	
	
	public   void GenerateBonesAndWeights()
	{
		this.weights = new haxe.root.Array<haxor.math.Vector4>(new haxor.math.Vector4[]{});
		this.bones = new haxe.root.Array<haxor.math.Vector4>(new haxor.math.Vector4[]{});
		int off = this.get_offset();
		haxor.io.file.ColladaInput wi = null;
		int wo = 0;
		int bo = 0;
		{
			int _g1 = 0;
			int _g = this.inputs.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(this.inputs.__get(i).semantic, "weight")) 
				{
					wi = this.inputs.__get(i);
					wo = wi.offset;
				}
				
				if (haxe.lang.Runtime.valEq(this.inputs.__get(i).semantic, "joint")) 
				{
					bo = this.inputs.__get(i).offset;
				}
				
			}
			
		}
		
		int k = 0;
		{
			int _g11 = 0;
			int _g2 = this.vcount.length;
			while (( _g11 < _g2 ))
			{
				int i1 = _g11++;
				int n = ((int) (haxe.lang.Runtime.toInt(this.vcount.__get(i1))) );
				haxor.math.Vector4 wv4 = new haxor.math.Vector4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
				haxor.math.Vector4 bv4 = new haxor.math.Vector4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
				{
					int _g21 = 0;
					while (( _g21 < n ))
					{
						int j = _g21++;
						int bi = ((int) (haxe.lang.Runtime.toInt(((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.indexes.__get(k)) )) ).__get(bo))) );
						double wv = ((double) (haxe.lang.Runtime.toDouble(wi.values.__get(((int) (haxe.lang.Runtime.toInt(((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (this.indexes.__get(k)) )) ).__get(wo))) )))) );
						if (( j == 0 )) 
						{
							wv4.x = wv;
							bv4.x = ((double) (bi) );
						}
						 else 
						{
							if (( j == 1 )) 
							{
								wv4.y = wv;
								bv4.y = ((double) (bi) );
							}
							 else 
							{
								if (( j == 2 )) 
								{
									wv4.z = wv;
									bv4.z = ((double) (bi) );
								}
								 else 
								{
									if (( j == 3 )) 
									{
										wv4.w = wv;
										bv4.w = ((double) (bi) );
									}
									
								}
								
							}
							
						}
						
						k++;
					}
					
				}
				
				double sum = ( ( ( wv4.x + wv4.y ) + wv4.z ) + wv4.w );
				if (( sum <= 0 )) 
				{
					sum = 0.0;
				}
				 else 
				{
					sum = ( 1.0 / sum );
				}
				
				wv4.Scale(sum);
				this.weights.push(wv4);
				this.bones.push(bv4);
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef81535 = true;
			switch (field.hashCode())
			{
				case 93920815:
				{
					if (field.equals("bones")) 
					{
						__temp_executeDef81535 = false;
						this.bones = ((haxe.root.Array<haxor.math.Vector4>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef81535 = false;
						this.type = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 1230441723:
				{
					if (field.equals("weights")) 
					{
						__temp_executeDef81535 = false;
						this.weights = ((haxe.root.Array<haxor.math.Vector4>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -896505829:
				{
					if (field.equals("source")) 
					{
						__temp_executeDef81535 = false;
						this.source = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 1943292160:
				{
					if (field.equals("indexes")) 
					{
						__temp_executeDef81535 = false;
						this.indexes = ((haxe.root.Array<haxe.root.Array>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef81535 = false;
						this.id = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -821876135:
				{
					if (field.equals("vcount")) 
					{
						__temp_executeDef81535 = false;
						this.vcount = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef81535 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -1183866391:
				{
					if (field.equals("inputs")) 
					{
						__temp_executeDef81535 = false;
						this.inputs = ((haxe.root.Array<haxor.io.file.ColladaInput>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1081239615:
				{
					if (field.equals("matrix")) 
					{
						__temp_executeDef81535 = false;
						this.matrix = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1154528983:
				{
					if (field.equals("joints")) 
					{
						__temp_executeDef81535 = false;
						this.joints = ((haxe.root.Array<java.lang.String>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 93742038:
				{
					if (field.equals("binds")) 
					{
						__temp_executeDef81535 = false;
						this.binds = ((haxe.root.Array<haxe.root.Array>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81535) 
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
			boolean __temp_executeDef81536 = true;
			switch (field.hashCode())
			{
				case -1909438370:
				{
					if (field.equals("GenerateBonesAndWeights")) 
					{
						__temp_executeDef81536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GenerateBonesAndWeights"))) );
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef81536 = false;
						return this.type;
					}
					
					break;
				}
				
				
				case 1283288129:
				{
					if (field.equals("GetTriangulatedBones")) 
					{
						__temp_executeDef81536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetTriangulatedBones"))) );
					}
					
					break;
				}
				
				
				case -896505829:
				{
					if (field.equals("source")) 
					{
						__temp_executeDef81536 = false;
						return this.source;
					}
					
					break;
				}
				
				
				case 1751129741:
				{
					if (field.equals("GetTriangulatedWeights")) 
					{
						__temp_executeDef81536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetTriangulatedWeights"))) );
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef81536 = false;
						return this.id;
					}
					
					break;
				}
				
				
				case 2014211648:
				{
					if (field.equals("GetBinds")) 
					{
						__temp_executeDef81536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetBinds"))) );
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef81536 = false;
						return this.name;
					}
					
					break;
				}
				
				
				case -1368908226:
				{
					if (field.equals("GetJointIndex")) 
					{
						__temp_executeDef81536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetJointIndex"))) );
					}
					
					break;
				}
				
				
				case -1081239615:
				{
					if (field.equals("matrix")) 
					{
						__temp_executeDef81536 = false;
						return this.matrix;
					}
					
					break;
				}
				
				
				case 2129467174:
				{
					if (field.equals("GetBSM")) 
					{
						__temp_executeDef81536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetBSM"))) );
					}
					
					break;
				}
				
				
				case 93742038:
				{
					if (field.equals("binds")) 
					{
						__temp_executeDef81536 = false;
						return this.binds;
					}
					
					break;
				}
				
				
				case 1060898204:
				{
					if (field.equals("get_offset")) 
					{
						__temp_executeDef81536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_offset"))) );
					}
					
					break;
				}
				
				
				case -1154528983:
				{
					if (field.equals("joints")) 
					{
						__temp_executeDef81536 = false;
						return this.joints;
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef81536 = false;
						return this.get_offset();
					}
					
					break;
				}
				
				
				case -1183866391:
				{
					if (field.equals("inputs")) 
					{
						__temp_executeDef81536 = false;
						return this.inputs;
					}
					
					break;
				}
				
				
				case 93920815:
				{
					if (field.equals("bones")) 
					{
						__temp_executeDef81536 = false;
						return this.bones;
					}
					
					break;
				}
				
				
				case -821876135:
				{
					if (field.equals("vcount")) 
					{
						__temp_executeDef81536 = false;
						return this.vcount;
					}
					
					break;
				}
				
				
				case 1230441723:
				{
					if (field.equals("weights")) 
					{
						__temp_executeDef81536 = false;
						return this.weights;
					}
					
					break;
				}
				
				
				case 1943292160:
				{
					if (field.equals("indexes")) 
					{
						__temp_executeDef81536 = false;
						return this.indexes;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81536) 
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
			boolean __temp_executeDef81537 = true;
			switch (field.hashCode())
			{
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef81537 = false;
						return ((double) (this.get_offset()) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81537) 
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
			boolean __temp_executeDef81538 = true;
			switch (field.hashCode())
			{
				case -1909438370:
				{
					if (field.equals("GenerateBonesAndWeights")) 
					{
						__temp_executeDef81538 = false;
						this.GenerateBonesAndWeights();
					}
					
					break;
				}
				
				
				case 1060898204:
				{
					if (field.equals("get_offset")) 
					{
						__temp_executeDef81538 = false;
						return this.get_offset();
					}
					
					break;
				}
				
				
				case 1283288129:
				{
					if (field.equals("GetTriangulatedBones")) 
					{
						__temp_executeDef81538 = false;
						return this.GetTriangulatedBones(((haxor.io.file.ColladaPrimitive) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2129467174:
				{
					if (field.equals("GetBSM")) 
					{
						__temp_executeDef81538 = false;
						return this.GetBSM();
					}
					
					break;
				}
				
				
				case 1751129741:
				{
					if (field.equals("GetTriangulatedWeights")) 
					{
						__temp_executeDef81538 = false;
						return this.GetTriangulatedWeights(((haxor.io.file.ColladaPrimitive) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1368908226:
				{
					if (field.equals("GetJointIndex")) 
					{
						__temp_executeDef81538 = false;
						return this.GetJointIndex(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 2014211648:
				{
					if (field.equals("GetBinds")) 
					{
						__temp_executeDef81538 = false;
						return this.GetBinds();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81538) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("offset");
		baseArr.push("bones");
		baseArr.push("weights");
		baseArr.push("indexes");
		baseArr.push("vcount");
		baseArr.push("inputs");
		baseArr.push("joints");
		baseArr.push("binds");
		baseArr.push("matrix");
		baseArr.push("name");
		baseArr.push("id");
		baseArr.push("source");
		baseArr.push("type");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


