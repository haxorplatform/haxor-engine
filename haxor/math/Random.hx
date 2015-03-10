package haxor.math;
import haxor.core.Enums.MeshPrimitive;
import haxor.graphics.mesh.Mesh;
import haxor.io.FloatArray;
import haxor.io.UInt16Array;
import haxor.platform.Types.Float32;

/**
 * Class that handles different random data generation.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Random
{
	/**
	 * Returns a random value in the [0.0,0.99999] range.
	 */
	static public var value(get_value, null):Float32;
	static private inline function get_value():Float32{ return Math.random(); }
	
	/**
	 * Returns a random value inside the [-0.9999,0.9999] range.
	 */
	static public var interval(get_interval, null):Float32;
	static private inline function get_interval():Float32{ return (value-0.499995)*2.0; }
	
	/**
	 * Returns a random rotation quaternion.
	 */
	static public var rotation(get_rotation, null):Quaternion;
	static private inline function get_rotation():Quaternion { return GetRotation(); }
	
	/**
	 * Returns a random point inside a size 1.0 box.
	 */
	static public var box(get_box, null):Vector3;
	static private inline function get_box():Vector3 { return GetBox(); }
	
	/**
	 * Returns a random point on a size 1.0 box.
	 */
	static public var onBox(get_onBox, null):Vector3;
	static private inline function get_onBox():Vector3 { return GetOnBox(); }
		
	/**
	 * Returns a random point inside a size 1.0 square.
	 */
	static public var square(get_square, null):Vector2;
	static private inline function get_square():Vector2 { return GetSquare(); }
	
	/**
	 * Returns a random point on a size 1.0 square.
	 */
	static public var onSquare(get_onSquare, null):Vector2;
	static private inline function get_onSquare():Vector2 { return GetOnSquare(); }
	
	/**
	 * Returns a random point inside a diameter 1.0 sphere.
	 */
	static public var sphere(get_sphere, null):Vector3;
	static private inline function get_sphere():Vector3 { return GetSphere(); }
		
	/**
	 * Returns a random point on the surface of a diameter 1.0 sphere.
	 */
	static public var onSphere(get_onSphere, null):Vector3;
	static private inline function get_onSphere():Vector3 { return GetOnSphere(); }
	
	/**
	 * Returns a random point inside a radius 1.0 circle.
	 */
	static public var circle(get_circle, null):Vector2;
	static private inline function get_circle():Vector2 { return GetCircle(); }
	
	/**
	 * Returns a random point on a radius 1.0 circle.
	 */
	static public var onCircle(get_onCircle, null):Vector2;
	static private inline function get_onCircle():Vector2 { return GetOnCircle(); }
	
	/**
	 * Returns an integer from [0;v].
	 */
	static public function Length(v:Int):Int { return cast ((v + 1) * value); }
	
	/**
	 * Returns a float inside the interval min/max.
	 * @param	p_min
	 * @param	p_max
	 * @return
	 */
	static public function Range(p_min:Float32, p_max:Float32):Float32{ return Mathf.Lerp(p_min, p_max, value); }
	
	/**
	 * Returns an int inside the interval min/max.
	 * @param	p_min
	 * @param	p_max
	 * @return
	 */
	static public function RangeInt(p_min:Int, p_max:Int):Int{ return Mathf.LerpInt(p_min, p_max+1, value); }
	
	/**
	 * Returns a random element from this list.
	 */
	static public function Item<T>(p_list : Array<T>): T { return p_list[cast (p_list.length * value)]; }
	
	/**
	 * Fisher–Yates Shuffle
	 * @param	p_list
	 */
	static public function Shuffle<T>(p_list : Array<T>) : Void 
	{
		var m : Int = p_list.length;
		var t : T;
		var i : Int;
		// While there remain elements to shuffle…
		while (m>0) 
		{
			// Pick a remaining element…
			i = Math.floor(value * (m--));
			// And swap it with the current element.
			t = p_list[m];
			p_list[m] = p_list[i];
			p_list[i] = t;			
		}
	}
	
	/**
	 * Returns a random rotation quaternion.
	 * @param	p_result
	 * @return
	 */
	static public function GetRotation(p_result:Quaternion=null):Quaternion
	{
		var r : Quaternion = p_result == null ? Quaternion.FromAxisAngle(GetSphere(Vector3.temp), interval * 180.0) : p_result.SetAxisAngle(GetSphere(Vector3.temp), interval * 180.0);
		return r;
	}
	
	/**
	 * Returns a random point inside a size 1.0 box.
	 * @param	p_result
	 * @return
	 */
	static public function GetBox(p_result : Vector3 = null):Vector3
	{
		var p : Vector3 = p_result == null ? (new Vector3(interval * 0.5, interval * 0.5, interval * 0.5)) : (p_result.Set(interval * 0.5, interval * 0.5, interval * 0.5));
		return p;
	}
	
	/**
	 * Returns a random point on a size 1.0 box face.
	 * @param	p_result
	 * @return
	 */
	static public function GetOnBox(p_result : Vector3 = null):Vector3
	{
		var p : Vector3 = GetBox(p_result);
		var i : Int = cast((value * 3) + 0.5);
		switch(i)
		{
			case 0: p.x = p.x < 0.0 ? -0.5 : 0.5;
			case 1: p.y = p.y < 0.0 ? -0.5 : 0.5;			
			case 2: p.z = p.z < 0.0 ? -0.5 : 0.5;			
		}
		return p;
	}
	
	/**
	 * Returns a random point inside a size 1.0 square.
	 * @param	p_result
	 * @return
	 */
	static public function GetSquare(p_result : Vector2 = null):Vector2
	{
		var p : Vector2 = p_result == null ? (new Vector2(interval * 0.5, interval * 0.5)) : (p_result.Set(interval * 0.5, interval * 0.5));
		return p;
	}
	
	/**
	 * Returns a random point on a size 1.0 square side.
	 * @param	p_result
	 * @return
	 */
	static public function GetOnSquare(p_result : Vector2 = null):Vector2
	{
		var p : Vector2 = GetSquare(p_result);
		var i : Int = cast((value * 2) + 0.5);
		switch(i)
		{
			case 0: p.x = p.x < 0.0 ? -0.5 : 0.5;
			case 1: p.y = p.y < 0.0 ? -0.5 : 0.5;						
		}
		return p;
	}
	
	/**
	 * Returns a random point on the surface of a diameter 1.0 sphere.
	 * @param	p_result
	 * @return
	 */
	static public function GetOnSphere(p_result:Vector3 = null):Vector3 
	{ 
		var p : Vector3 = p_result == null ? new Vector3(interval*0.5, interval*0.5, interval*0.5) : p_result.Set(interval*0.5, interval*0.5, interval*0.5);
		return p.Normalize();
	}
	
	/**
	 * Returns a random point inside a diameter 1.0 sphere.
	 * @param	p_result
	 * @return
	 */
	static public function GetSphere(p_result:Vector3 = null):Vector3 
	{ 
		var p : Vector3 = GetOnSphere(p_result);
		return p.Scale(value);
	}
	
	/**
	 * Returns a random point on the surface of a diameter 1.0 circle.
	 * @param	p_result
	 * @return
	 */
	static public function GetOnCircle(p_result:Vector2 = null):Vector2
	{ 
		var p : Vector2 = p_result == null ? new Vector2(interval*0.5, interval*0.5) : p_result.Set(interval*0.5, interval*0.5);
		return p.Normalize();
	}
	
	/**
	 * Returns a random point inside a diameter 1.0 circle.
	 * @param	p_result
	 * @return
	 */
	static public function GetCircle(p_result:Vector2 = null):Vector2
	{ 
		var p : Vector2 = GetOnCircle(p_result);
		return p.Scale(value);
	}
	
	/**
	 * Returns a random point on the surface of a Cone with a given height and apperture angle. The Cone has its vertice on the origin and grows alongside the Z axis.
	 * @param	p_result
	 * @return
	 */
	static public function GetOnCone(p_result : Vector3 = null, p_height:Float = 1.0,p_angle:Float32=45.0):Vector3
	{	
		var p   : Vector3 = p_result == null ? new Vector3() : p_result.Set();				
		var h   : Float32 = p_height;
		var tan : Float32 = Mathf.Tan(p_angle * Mathf.Deg2Rad * 0.5);		
		var tp  : Vector2 = Vector2.temp;		
		if (Random.value > 0.5) //cap
		{
			tp = GetCircle(tp);
		}
		else //surface
		{
			h  = Random.value * p_height;			
			tp = GetOnCircle(tp);
		}		
		tp.Scale(h*tan);
		return p.Set(tp.x, tp.y, h);
	}
	
	/**
	 * Returns a random point inside the volume of a Cone with a given height and appertura angle.  The Cone has its vertice on the origin and grows alongside the Z axis.
	 */
	static public function GetCone(p_result : Vector3 = null, p_height:Float = 1.0, p_angle:Float32 = 45.0):Vector3
	{
		var p : Vector3 = GetOnCone(p_result, p_height, p_angle);
		var r : Float32 = Random.value;
		p.x *= r;
		p.y *= r;
		return p;
	}
	
	/**
	 * Returns a random point on the surface of a Cylinder with a given height and radius. The Cylinder circle cross section belongs to the XY plane and it grows alongside the Z axis.
	 * @param	p_result
	 * @param	p_height
	 * @param	p_radius
	 * @return
	 */
	static public function GetOnCylinder(p_result : Vector3 = null, p_height:Float = 1.0,p_radius:Float32=1.0):Vector3
	{	
		var p   : Vector3 = p_result == null ? new Vector3() : p_result.Set();				
		var h   : Float32 = p_height;		
		var tp  : Vector2 = Vector2.temp;		
		if (Random.value > 0.5) //caps
		{
			h = Random.value < 0.5 ? 0.0 : p_height;
			tp = GetCircle(tp);
		}
		else //surface
		{
			h  = Random.value * p_height;			
			tp = GetOnCircle(tp);
		}		
		tp.Scale(p_radius);
		return p.Set(tp.x, tp.y, h);
	}
	
	/**
	 * Returns a random point inside the volume of a Cylinder with a given height and radius.  The Cylinder circle cross section belongs to the XY plane and it grows alongside the Z axis.
	 * @param	p_result
	 * @param	p_height
	 * @param	p_radius
	 * @return
	 */
	static public function GetCylinder(p_result : Vector3 = null, p_height:Float = 1.0,p_radius:Float32=1.0):Vector3
	{	
		var p   : Vector3 = p_result == null ? new Vector3() : p_result.Set();						
		var tp  : Vector2 = GetCircle(Vector2.temp).Scale(p_radius * Random.value);		
		return p.Set(tp.x, tp.y, Random.value * p_height);
	}
	
	/**
	 * Returns a random attribute of a mesh. Defaults to 'vertex'
	 * @param	p_mesh
	 * @param	p_result
	 * @param	p_attrib
	 * @return
	 */
	static public function GetMeshAttrib(p_mesh : Mesh,p_result:Vector4=null, p_attrib : String = "vertex"):Vector4
	{
		var p : Vector4 = p_result == null ? (new Vector4()) : p_result;
		var ma : MeshAttrib = p_mesh.GetAttribute(p_attrib);
		if (ma == null) return p;
		var f32 : FloatArray = cast ma.data;
		var vp  : Int = Length(ma.count) * ma.offset;
		if (ma.offset >= 1) p.x = f32.Get(vp);
		if (ma.offset >= 2) p.y = f32.Get(vp + 1);
		if (ma.offset >= 3) p.z = f32.Get(vp + 2);
		if (ma.offset >= 4) p.w = f32.Get(vp + 3);
		return p;
	}
	
	/**
	 * Returns a random primitive of a given mesh. It can be a point, line or triangle.
	 * @param	p_mesh
	 * @param	p_v0
	 * @param	p_v1
	 * @param	p_v2
	 * @param	p_attrib
	 * @return
	 */
	static public function GetMeshPrimitive(p_mesh : Mesh, p_v0:Vector4, p_v1:Vector4, p_v2:Vector4, p_attrib : String = "vertex"):Int
	{
		var ma : MeshAttrib = p_mesh.GetAttribute(p_attrib);
		if (ma == null) return 0;
		var f32 : FloatArray = cast ma.data;		
		var i16 : UInt16Array;
		var step : Int = 3;		
		switch(p_mesh.primitive)
		{
			case MeshPrimitive.Points: step = 1;
			case MeshPrimitive.Lines:
			case MeshPrimitive.LineStrip:
			case MeshPrimitive.LineLoop: step = 2;
		}
		
		var p0 : Vector4 = p_v0;
		var p1 : Vector4 = p_v1;
		var p2 : Vector4 = p_v2;
		var i0 : Int=0;
		var i1 : Int=0;
		var i2 : Int=0;
		var vp  : Int=0;
		var off : Int = ma.offset;
		
		if (p_mesh.indexed)
		{		
			i16 = p_mesh.topology;
			vp = Length(cast (i16.length / step));
			if(step>=1) i0 = i16.Get(vp)*off;
			if(step>=2) i1 = i16.Get(vp+1)*off;
			if(step>=3) i2 = i16.Get(vp+2)*off;
		}
		else
		{
			if(step>=1) i0 = Length(ma.count) * off;
			if(step>=2) i1 = (i0 + off);
			if(step>=3) i2 = (i1 + off);
		}		
		if (ma.offset >= 1) { p0.x = f32.Get(i0);   p1.x = f32.Get(i1);   p2.x = f32.Get(i2); }
		if (ma.offset >= 2) { p0.y = f32.Get(i0+1); p1.y = f32.Get(i1+1); p2.y = f32.Get(i2+1); }
		if (ma.offset >= 3) { p0.z = f32.Get(i0+2); p1.z = f32.Get(i1+2); p2.z = f32.Get(i2+2); }
		if (ma.offset >= 4) { p0.w = f32.Get(i0+3); p1.w = f32.Get(i1+3); p2.w = f32.Get(i2+3); }

		return step;		
	}
	
	/**
	 * Returns a random attribute on the mesh surface.
	 * @param	p_mesh
	 * @param	p_result
	 * @param	p_attrib
	 * @return
	 */
	static public function GetAttribOnMesh(p_mesh : Mesh, p_result:Vector4 = null, p_attrib : String = "vertex"):Vector4
	{		
		var p : Vector4 = p_result == null ? (new Vector4()) : p_result;
		p.Set();
		
		var p0 : Vector4 = Vector4.temp;
		var p1 : Vector4 = Vector4.temp;
		var p2 : Vector4 = Vector4.temp;
		
		var step : Int = GetMeshPrimitive(p_mesh, p0, p1, p2, p_attrib);
		
		var w : Vector3 = Vector3.temp.Set();
		var sum : Float32 = 0.0;
		if(step>=1) { w.x = Random.value; sum += w.x; }
		if(step>=2) { w.y = Random.value; sum += w.y; }
		if(step>=3) { w.z = Random.value; sum += w.z; }		
		w.Scale(sum <= 0.0 ? 0.0 : (1.0 / sum));
		
		p.x += (p0.x * w.x) + (p1.x * w.y) + (p2.x * w.z);
		p.y += (p0.y * w.x) + (p1.y * w.y) + (p2.y * w.z);
		p.z += (p0.z * w.x) + (p1.z * w.y) + (p2.z * w.z);		
		return p;
	}

}