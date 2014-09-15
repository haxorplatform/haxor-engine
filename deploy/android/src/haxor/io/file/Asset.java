package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Asset extends haxe.lang.HxObject
{
	static 
	{
		haxor.io.file.Asset.m_database = new haxe.ds.StringMap();
	}
	public    Asset(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Asset()
	{
		haxor.io.file.Asset.__hx_ctor_haxor_io_file_Asset(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_Asset(haxor.io.file.Asset __temp_me255508)
	{
		{
		}
		
	}
	
	
	public static  haxe.ds.StringMap m_database;
	
	public static   java.lang.Object Get(java.lang.String p_id)
	{
		if (haxor.io.file.Asset.m_database.exists(p_id)) 
		{
			return haxor.io.file.Asset.m_database.get(p_id);
		}
		 else 
		{
			return null;
		}
		
	}
	
	
	public static   java.lang.Object Remove(java.lang.String p_id)
	{
		if (haxor.io.file.Asset.m_database.exists(p_id)) 
		{
			java.lang.Object a = haxor.io.file.Asset.m_database.get(p_id);
			haxor.io.file.Asset.m_database.remove(p_id);
			return a;
		}
		
		return null;
	}
	
	
	public static   void Add(java.lang.String p_id, java.lang.Object p_asset)
	{
		{
			java.lang.Object value = p_asset;
			haxor.io.file.Asset.m_database.set(p_id, value);
		}
		
		if (( p_asset instanceof haxor.core.Resource )) 
		{
			(((haxor.core.Resource) (p_asset) )).__db = p_id;
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.Asset(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.Asset();
	}
	
	
}


