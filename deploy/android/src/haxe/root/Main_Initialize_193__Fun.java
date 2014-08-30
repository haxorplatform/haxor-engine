package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Main_Initialize_193__Fun extends haxe.lang.Function
{
	public    Main_Initialize_193__Fun(haxe.root.Array<java.lang.Object> px, haxe.root.Array<java.lang.Object> l, haxe.root.Array<haxe.root.Main> _g, haxe.root.Array<java.lang.Object> pz, haxe.root.Array<java.lang.Object> py)
	{
		super(1, 0);
		this.px = px;
		this.l = l;
		this._g = _g;
		this.pz = pz;
		this.py = py;
	}
	
	
	@Override public   java.lang.Object __hx_invoke1_o(double __fn_float1, java.lang.Object __fn_dyn1)
	{
		int i = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((int) (__fn_float1) )) : (((int) (haxe.lang.Runtime.toInt(__fn_dyn1)) )) );
		this._g.__get(0).mr = ((haxor.component.MeshRenderer) (new haxor.core.Entity(haxe.lang.Runtime.toString(( "cube" + i ))).AddComponent(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.MeshRenderer.class) )) ))) );
		this._g.__get(0).mr.m_entity.m_transform.set_localScale(new haxor.math.Vector3(((java.lang.Object) (0.1) ), ((java.lang.Object) (0.1) ), ((java.lang.Object) (0.1) )));
		this._g.__get(0).mr.m_entity.m_transform.set_parent(this._g.__get(0).container);
		this._g.__get(0).mr.m_entity.m_transform.set_position(new haxor.math.Vector3(((double) (haxe.lang.Runtime.toDouble(this.px.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(this.py.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(this.pz.__get(0))) )));
		this._g.__get(0).mr.set_mesh(haxor.graphics.mesh.Model.get_cube());
		this._g.__get(0).mr.set_material(this._g.__get(0).mat);
		{
			int __temp_index151603 = 0;
			this.px.__set(__temp_index151603, ( ((double) (haxe.lang.Runtime.toDouble(this.px.__get(__temp_index151603))) ) + 0.12 ));
		}
		
		if (( ((double) (haxe.lang.Runtime.toDouble(this.px.__get(0))) ) >= ((double) (haxe.lang.Runtime.toDouble(this.l.__get(0))) ) )) 
		{
			this.px.__set(0, 0.0);
			{
				int __temp_index151604 = 0;
				this.pz.__set(__temp_index151604, ( ((double) (haxe.lang.Runtime.toDouble(this.pz.__get(__temp_index151604))) ) + 0.12 ));
			}
			
			if (( ((double) (haxe.lang.Runtime.toDouble(this.pz.__get(0))) ) >= ((double) (haxe.lang.Runtime.toDouble(this.l.__get(0))) ) )) 
			{
				this.pz.__set(0, 0.0);
				{
					int __temp_index151605 = 0;
					this.py.__set(__temp_index151605, ( ((double) (haxe.lang.Runtime.toDouble(this.py.__get(__temp_index151605))) ) + 0.12 ));
				}
				
			}
			
		}
		
		return true;
	}
	
	
	public  haxe.root.Array<java.lang.Object> px;
	
	public  haxe.root.Array<java.lang.Object> l;
	
	public  haxe.root.Array<haxe.root.Main> _g;
	
	public  haxe.root.Array<java.lang.Object> pz;
	
	public  haxe.root.Array<java.lang.Object> py;
	
}


