package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaFile_FindNodeById_512__Fun extends haxe.lang.Function
{
	public    ColladaFile_FindNodeById_512__Fun(haxe.root.Array<java.lang.String> p_id1, haxe.root.Array<haxor.io.file.ColladaNode> res)
	{
		super(1, 0);
		this.p_id1 = p_id1;
		this.res = res;
	}
	
	
	@Override public   java.lang.Object __hx_invoke1_o(double __fn_float1, java.lang.Object __fn_dyn1)
	{
		haxor.io.file.ColladaNode it = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxor.io.file.ColladaNode) (((java.lang.Object) (__fn_float1) )) )) : (((haxor.io.file.ColladaNode) (__fn_dyn1) )) );
		if (haxe.lang.Runtime.valEq(it.id, this.p_id1.__get(0))) 
		{
			this.res.__set(0, it);
		}
		
		return null;
	}
	
	
	public  haxe.root.Array<java.lang.String> p_id1;
	
	public  haxe.root.Array<haxor.io.file.ColladaNode> res;
	
}


