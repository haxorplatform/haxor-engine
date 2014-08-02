/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.thread;
import js.html.Float32Array;
import js.html.Uint8Array;
import haxor.component.Transform;
import haxor.core.Asset;
import haxor.core.Console;
import haxor.core.Time;
import haxor.graphics.Shader;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Quaternion;
import haxor.math.Vector3;
import haxor.texture.KernelTexture;
import haxor.texture.Texture.TextureFormat;
import haxor.thread.Kernel;

/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class TransformKernel extends KernelFloat
{
	static private var MAX_TRANSFORM : Int 		= 2048;
	
	static private var TRANSFORM_FLOAT_LENGTH : Int = 16;
	
	static private var MATRIX_FLOAT_LENGTH 	  : Int = 36;

	static private var FLAGS_OFFSET    : Int = 0;
	static private var PID_OFFSET      : Int = 0;
	static private var DIRTY_OFFSET    : Int = 1;
	static private var CONCAT_OFFSET   : Int = 2;
	static private var POSITION_OFFSET : Int = 4;
	static private var ROTATION_OFFSET : Int = 8;
	static private var SCALE_OFFSET    : Int = 12;
	
	static private var LM_OFFSET      : Int = 0;
	static private var WM_OFFSET 	  : Int = 12;
	static private var WMI_OFFSET 	  : Int = 24;
	
	
	public var m_input : KernelTexture;
	
	private var m_matrix : Float32Array;
	
	private var m_ib : Float32Array;
	
	private var m_kernel : Shader;
	
	private var m_resize : Bool;
	
	public function new() 
	{
		super(64, MAX_TRANSFORM);		
		m_input  = new KernelTexture(cast (TRANSFORM_FLOAT_LENGTH / 4), MAX_TRANSFORM, TextureFormat.Float4);
		m_input.name = "$TransformKernelInput";
		m_ib 	 = new Float32Array(TRANSFORM_FLOAT_LENGTH * MAX_TRANSFORM);
		m_matrix = new Float32Array(MATRIX_FLOAT_LENGTH  * MAX_TRANSFORM);
		
		for (i in 0...m_ib.length) m_ib[i] = 0.0;
		m_input.WriteRange(m_ib);
		
		
		SetUniform("Transform", m_input);
		SetUniform("Output", m_output);
		name = "TransformKernel";		
	}
	
	public function Init(p_transform:Transform):Void
	{
		
		SetDirty(p_transform, true);
		SetConcat(p_transform, true);
		SetPosition(p_transform);
		SetRotation(p_transform);
		SetScale(p_transform);
		SetParent(p_transform);
		
		
		m_resize = true;
		
		//SetUniform("count", Transform.m_list.length + 0.00001);
		
	}
	
	public function SetParent(p_transform:Transform):Void
	{		
		var o : Int = p_transform.m_tid * TRANSFORM_FLOAT_LENGTH;
		m_ib[o + PID_OFFSET] = p_transform.parent == null ? -1.0 : p_transform.parent.m_tid;
		m_ib[o + PID_OFFSET + 3] = 1.0;		
	}
	
	public function SetDirty(p_transform:Transform,p_flag : Bool):Void
	{		
		var o : Int = p_transform.m_tid * TRANSFORM_FLOAT_LENGTH;
		m_ib[o + DIRTY_OFFSET] = p_flag ? 1.0 : 0.0;		
	}
	
	public function SetConcat(p_transform:Transform,p_flag : Bool):Void
	{		
		var o : Int = p_transform.m_tid * TRANSFORM_FLOAT_LENGTH;
		m_ib[o + CONCAT_OFFSET] = p_flag ? 1.0 : 0.0;		
	}
	
	public function SetPosition(p_transform:Transform):Void
	{
		var o : Int = p_transform.m_tid * TRANSFORM_FLOAT_LENGTH;
		
		m_ib[o + POSITION_OFFSET]   = p_transform.m_position.x;
		m_ib[o + POSITION_OFFSET+1] = p_transform.m_position.y;
		m_ib[o + POSITION_OFFSET+2] = p_transform.m_position.z;
		//*/
		//m_ib[o + POSITION_OFFSET+3] = 1.0;
	}
	
	public function GetPosition(p_transform:Transform):Void
	{
		var o : Int = p_transform.m_tid * TRANSFORM_FLOAT_LENGTH;
		var v : Vector3 = p_transform.m_position;
		v.x = m_ib[o + POSITION_OFFSET];
		v.y = m_ib[o + POSITION_OFFSET + 1];
		v.z = m_ib[o + POSITION_OFFSET + 2];
		p_transform.position = v;
	}
	
	public function SetRotation(p_transform:Transform):Void
	{
		var o : Int = p_transform.m_tid * TRANSFORM_FLOAT_LENGTH;
		
		m_ib[o + ROTATION_OFFSET]   = p_transform.m_rotation.x;
		m_ib[o + ROTATION_OFFSET+1] = p_transform.m_rotation.y;
		m_ib[o + ROTATION_OFFSET+2] = p_transform.m_rotation.z;
		m_ib[o + ROTATION_OFFSET+3] = p_transform.m_rotation.w;
		//*/		
	}
	
	public function GetRotation(p_transform:Transform):Void
	{
		var o : Int = p_transform.m_tid * TRANSFORM_FLOAT_LENGTH;
		var v : Quaternion = p_transform.m_rotation;
		v.x = m_ib[o + ROTATION_OFFSET];
		v.y = m_ib[o + ROTATION_OFFSET + 1];
		v.z = m_ib[o + ROTATION_OFFSET + 2];
		v.w = m_ib[o + ROTATION_OFFSET + 3];
	}
	
	public function SetScale(p_transform:Transform):Void
	{
		var o : Int = p_transform.m_tid * TRANSFORM_FLOAT_LENGTH;		
		m_ib[o + SCALE_OFFSET]     = p_transform.m_scale.x;
		m_ib[o + SCALE_OFFSET+1]   = p_transform.m_scale.y;
		m_ib[o + SCALE_OFFSET+2]   = p_transform.m_scale.z;		
	}
	
	public function GetScale(p_transform:Transform):Void
	{
		var o : Int = p_transform.m_tid * TRANSFORM_FLOAT_LENGTH;
		var v : Vector3 = p_transform.m_scale;
		v.x = m_ib[o + SCALE_OFFSET];
		v.y = m_ib[o + SCALE_OFFSET + 1];
		v.z = m_ib[o + SCALE_OFFSET + 2];
	}
	
	public function GetLocalMatrix(p_transform : Transform):Matrix4
	{
		var tid : Int = p_transform.m_tid;
		var o : Int = tid * MATRIX_FLOAT_LENGTH;
		var m : Matrix4 = p_transform.m_localMatrix;
		for (i in 0...12) m.SetIndex(i, m_matrix[o + LM_OFFSET + i]);
		return m;
	}
	
	public function GetWorldMatrix(p_transform : Transform):Matrix4
	{
		var tid : Int = p_transform.m_tid;
		var o : Int = tid * MATRIX_FLOAT_LENGTH;
		var m : Matrix4 = p_transform.m_worldMatrix;
		for (i in 0...12) m.SetIndex(i, m_matrix[o + WM_OFFSET + i]);
		return m;
	}
	
	public function GetWorldMatrixInverse(p_transform : Transform):Matrix4
	{
		var tid : Int = p_transform.m_tid;
		var o : Int = tid * MATRIX_FLOAT_LENGTH;
		var m : Matrix4 = p_transform.m_worldMatrixInverse;
		for (i in 0...12) m.SetIndex(i, m_matrix[o + WMI_OFFSET + i]);
		return m;
	}
	
	override public function Execute():Void 
	{
		
		if (m_kernel == null) { m_kernel = shader = Asset.Get("haxor/kernel/TransformKernel"); return; }
		
		m_input.WriteRange(m_ib);
		
		if (m_resize)
		{
			Resize(36,Transform.m_list.length);
			m_resize = false;
		}
		
		super.Execute();
		
		Update(0,0,36,Transform.m_list.length);
		
		m_matrix = result;
		
	}
	
}