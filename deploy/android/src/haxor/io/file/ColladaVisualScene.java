package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaVisualScene extends haxe.lang.HxObject
{
	public    ColladaVisualScene(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaVisualScene()
	{
		haxor.io.file.ColladaVisualScene.__hx_ctor_haxor_io_file_ColladaVisualScene(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaVisualScene(haxor.io.file.ColladaVisualScene __temp_me304)
	{
		__temp_me304.children = null;
		__temp_me304.name = "";
		__temp_me304.id = "";
		__temp_me304.type = "";
		__temp_me304.children = new haxe.root.Array<haxor.io.file.ColladaNode>(new haxor.io.file.ColladaNode[]{});
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaVisualScene(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaVisualScene();
	}
	
	
	public  java.lang.String type;
	
	public  java.lang.String id;
	
	public  java.lang.String name;
	
	public  haxe.root.Array<haxor.io.file.ColladaNode> children;
	
	public   void Traverse(haxe.lang.Function p_callback)
	{
		int _g1 = 0;
		int _g = this.children.length;
		while (( _g1 < _g ))
		{
			int i = _g1++;
			this.TraverseStep(this.children.__get(i), p_callback);
		}
		
	}
	
	
	public   void TraverseStep(haxor.io.file.ColladaNode p_node, haxe.lang.Function p_callback)
	{
		if (( p_callback != null )) 
		{
			p_callback.__hx_invoke1_o(0.0, p_node);
		}
		
		{
			int _g1 = 0;
			int _g = p_node.children.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				this.TraverseStep(p_node.children.__get(i), p_callback);
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef1189 = true;
			switch (field.hashCode())
			{
				case 1659526655:
				{
					if (field.equals("children")) 
					{
						__temp_executeDef1189 = false;
						this.children = ((haxe.root.Array<haxor.io.file.ColladaNode>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef1189 = false;
						this.type = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef1189 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef1189 = false;
						this.id = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1189) 
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
			boolean __temp_executeDef1190 = true;
			switch (field.hashCode())
			{
				case 265423742:
				{
					if (field.equals("TraverseStep")) 
					{
						__temp_executeDef1190 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TraverseStep"))) );
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef1190 = false;
						return this.type;
					}
					
					break;
				}
				
				
				case 1352509842:
				{
					if (field.equals("Traverse")) 
					{
						__temp_executeDef1190 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Traverse"))) );
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef1190 = false;
						return this.id;
					}
					
					break;
				}
				
				
				case 1659526655:
				{
					if (field.equals("children")) 
					{
						__temp_executeDef1190 = false;
						return this.children;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef1190 = false;
						return this.name;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1190) 
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
			boolean __temp_executeDef1191 = true;
			switch (field.hashCode())
			{
				case 265423742:
				{
					if (field.equals("TraverseStep")) 
					{
						__temp_executeDef1191 = false;
						this.TraverseStep(((haxor.io.file.ColladaNode) (dynargs.__get(0)) ), ((haxe.lang.Function) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1352509842:
				{
					if (field.equals("Traverse")) 
					{
						__temp_executeDef1191 = false;
						this.Traverse(((haxe.lang.Function) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1191) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("children");
		baseArr.push("name");
		baseArr.push("id");
		baseArr.push("type");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


