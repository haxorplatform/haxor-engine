/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */

package haxor.component;

import js.html.Float32Array;
import haxor.core.Application;
import haxor.core.Asset;
import haxor.core.Engine;
import haxor.core.Entity;
import haxor.core.IQueueRenderable;
import haxor.core.IUpdateable;
import haxor.core.Time;
import haxor.component.Animation;
import haxor.component.AnimationClip;
import haxor.graphics.Graphics;
import haxor.graphics.Material;
import haxor.graphics.Mesh;
import haxor.graphics.MeshTemplate.Mesh3;
import haxor.graphics.Screen;
import haxor.input.Input;
import haxor.input.KeyCode;
import haxor.math.AABB2;
import haxor.math.AABB3;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Vector3;
import haxor.math.Vector4;
import haxor.texture.Texture;
import haxor.texture.Texture2D;
import haxor.thread.ParticleKernel;

class ParticleAttribute<T>
{
	public var start  : T;	
	public var end    : T;	
	public var curve  : Float;	
	public var random : Bool;	
	public function new(p_start:T,p_end:T,p_curve:Float=1.0,p_random:Bool=false)
	{
		start 	= p_start;
		end  	= p_end;
		curve 	= p_curve;		
		random  = p_random;
	}
	
}

class ParticleStart
{
	public var life 		: ParticleAttribute<Float>;	
	public var speed 		: ParticleAttribute<Float>;	
	public var size     	: ParticleAttribute<Vector3>;	
	public var rotation 	: ParticleAttribute<Vector3>;	
	public var color 		: Texture;	
	
	public function new()
	{
		life     = new ParticleAttribute<Float>(1.0,1.0);
		speed    = new ParticleAttribute<Float>(1.0, 1.0);
		size     = new ParticleAttribute<Vector3>(Vector3.one,Vector3.one);
		rotation = new ParticleAttribute<Vector3>(Vector3.zero,Vector3.zero);
		color    = Texture2D.white;
	}
	
}

class ParticleLife
{
	public var speed 	: ParticleAttribute<Float>;	
	public var motion 	: ParticleAttribute<Vector3>;	
	public var size 	: ParticleAttribute<Vector3>;	
	public var rotation : ParticleAttribute<Vector3>;	
	public var color 	: Texture;
	
	public function new()
	{		
		speed    = new ParticleAttribute<Float>(1.0, 1.0);
		motion   = new ParticleAttribute<Vector3>(Vector3.one, Vector3.one);
		size     = new ParticleAttribute<Vector3>(Vector3.one,Vector3.one);
		rotation = new ParticleAttribute<Vector3>(Vector3.zero,Vector3.zero);
		color    = Texture2D.white;
	}
	
}

class ParticleSheet
{
	public var width  : Float;
	public var height : Float;
	public var length : Int;
	public var fps    : Float;
	public var frame  : ParticleAttribute<Float>;
	public var wrap	  : AnimationWrap;
	public var reverse:Bool;
	
	public function new()
	{
		
		width   = 0.0;
		height  = 0.0;
		length  = 0;
		fps     = 60.0;
		frame   = new ParticleAttribute<Float>(0.0, 0.0);
		wrap    = AnimationWrap.Clamp;
		reverse = false;
	}
}

enum ParticleSystemState
{
	None;
	Reset;
	Update;
}

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class ParticleRenderer extends MeshRenderer implements IUpdateable
{
	
	public var emitted (get_emitted, never) : Float;	
	function get_emitted():Float 		
	{
		return m_emitted_count; 
	}	
	private var m_emitted_start : Float;
	private var m_emitted_count : Float;
	
	public var playing (get_playing, never) : Bool;	
	function get_playing():Bool 		{ return m_playing; }
	private var m_playing : Bool;
	
	public var bounds (get_bounds, set_bounds) : AABB3;	
	function get_bounds():AABB3 		{ return m_mesh.bounds; }
	function set_bounds(v:AABB3):AABB3 		{ m_mesh.bounds = v; return v; }
	
	
	
	/**
	 * 
	 */
	public var count (get_count, set_count) : Int;	
	function get_count():Int 		{ return m_count; }
	function set_count(v:Int):Int 	{ m_count = v; Reset(); UpdateMesh(); return v; }
	private var m_count : Int;
	
	public var elapsed 	: Float;	
	public var duration : Float;
	public var billboard: Bool;
	public var local 	: Bool;	
	public var loop 	: Bool;	
	public var emitter 	: ParticleEmitter;	
	
	public var start	: ParticleStart;
	
	public var life		: ParticleLife;
	
	public var sheet	: ParticleSheet;
	
	public var rate 	: ParticleAttribute<Float>;
	public var force 	: Vector3;
	
	private var m_particles : Mesh3;
	
	private var m_state : ParticleSystemState;
	
	private var m_kernel : ParticleKernel;
	
	function new(p_entity : Entity) 
	{
		m_particles		 = new Mesh3();
		m_particles.name = "ParticleMesh" + id;
		m_mesh 			 = m_particles;
		m_mesh.bounds	 = AABB3.FromCenter(0, 0, 0, 1, 1, 1);
		
		m_state 		 = ParticleSystemState.Reset;
		m_kernel 		 = new ParticleKernel(this);
		elapsed			 = 0.0;
		m_playing		 = false;
		m_emitted_count  = 0.0;
		m_emitted_start  = 0.0;
		
		count 			 = 10;
		
		duration 		 = 1.0;
				
		emitter			 = new SphereEmitter(1.0);
		
		sheet			 = new ParticleSheet();
		
		local 			 = true;		
		loop			 = true;
		billboard        = true;
				
		start			 = new ParticleStart();
		life			 = new ParticleLife();
		
		rate			 = new ParticleAttribute<Float>(1.0, 1.0);
		
		force			 = new Vector3();
		
		super(p_entity);	
		
	}
	
	
	public function Emit(p_emit_count : Float=1.0):Void
	{
		var remain  : Float = count - emitted;
		var c 		: Float = Mathf.Min([p_emit_count, remain]);
		var d		: Float = p_emit_count - c;				
		if (loop) m_emitted_start += d;			
		m_emitted_count += c;				
		m_playing = true;
	}
	
	public function Play():Void
	{	
		m_playing = true;
	}
	
	public function Pause():Void
	{		
		m_playing = false;
	}
	
	public function Reset():Void
	{		
		//m_state   = ParticleSystemState.Reset;
		elapsed = 0.0;
		m_emitted_count = 0.0;
		m_emitted_start = 0.0;
	}
	
	public function Stop():Void
	{
		elapsed = 0.0;
		m_emitted_count = 0.0;
		m_emitted_start = 0.0;
		m_state   = ParticleSystemState.Reset;
		m_playing = false;
	}
	
	private function Simulate():Void
	{
		switch(m_state)
		{
			case ParticleSystemState.None:
				
				if (m_playing) m_state = ParticleSystemState.Update;
			
				
			case ParticleSystemState.Reset:
				m_kernel.Execute();
				m_state = m_playing ? ParticleSystemState.Update : ParticleSystemState.None;
						
			case ParticleSystemState.Update:
				
				if (!m_playing) { m_state = ParticleSystemState.None; return; }
				
				m_kernel.Execute();
				
				var max_life : Float = Mathf.Max([start.life.start, start.life.end]);
				if (elapsed >= (duration+max_life)) if(!loop) return;
				var dt : Float = Time.deltaTime;
				var r  : Float = Mathf.Clamp01(elapsed / duration);
				
				
				elapsed += dt;
				if (elapsed >= (duration+max_life)) elapsed = (duration+max_life);
				
				var er : Float = dt * Mathf.Lerp(rate.start,rate.end,rate.random ? Math.random() : Mathf.Pow(r,rate.curve));		
				Emit(er);
				
				//if((Time.frame % 30)==0) trace(m_emitted_start + " " + m_emitted_count);
				
		}
	}
	
	public function OnUpdate():Void
	{	
		/*
		if (Input.Hit(KeyCode.Q)) Play();
		if (Input.Hit(KeyCode.W)) Pause();
		if (Input.Hit(KeyCode.E)) Reset();
		if (Input.Hit(KeyCode.R)) Emit();		
		if (Input.IsDown(KeyCode.T)) Emit(Time.deltaTime * 5.0);
		if (Input.IsDown(KeyCode.Y)) Emit(Time.deltaTime * 300.0);
		if (Input.Hit(KeyCode.U)) Emit(500.0);
		if (Input.Hit(KeyCode.I)) Emit(2000.0);
		if (Input.Hit(KeyCode.P)) Emit(10000.0);
		if (Input.Hit(KeyCode.O)) local = !local;
		//*/
		
		Simulate();
		//*/
	}
	
	/**
	 * 
	 */
	override public function OnRender() : Void 
	{			
		
		//trace(">> "+name);
		//Graphics.RenderTexture(m_kernel.m_back, 0, Screen.height-512-10, 512, 512);
		
		//if(m_playing)m_kernel.Execute();
		
		super.OnRender();		
		
	}
	
	private function UpdateMesh():Void
	{
		m_particles.Clear();
		var vl : Array<Vector3> = [];						
		var cl : Array<Color>   = [];
		var plane : Array<Vector3> = 
		[
			new Vector3(-0.5,  0.5, 0),
			new Vector3(-0.5, -0.5, 0),						
			new Vector3( 0.5, -0.5, 0),			
			new Vector3(-0.5,  0.5, 0),
			new Vector3( 0.5, -0.5, 0),			
			new Vector3( 0.5,  0.5, 0)			
		];		
		var wc:Color = Color.white;
		for (i in 0...count)
		{
			for (j in 0...plane.length)
			{
				var v : Vector3 = plane[j].clone; 
				v.z = i;
				vl.push(v);
				cl.push(wc);
			}
		}
		m_particles.vertex = vl;
		m_particles.color  = cl;
		
	}
	
}

@:allow(haxor)
class ParticleEmitter
{
	
	public var surface(get_surface,set_surface) : Bool;
	private function get_surface():Bool { return m_data[1] > 0.0; }
	private function set_surface(v:Bool):Bool { m_data[1] = v ? 1.0 : 0.0; return v; }
	
	public var random(get_random,set_random) : Bool;
	private function get_random():Bool { return m_data[2] > 0.0; }
	private function set_random(v:Bool):Bool { m_data[2] = v ? 1.0 : 0.0; return v; }
	
	public var ranges : Array<Float>;
	
	private var m_data : Float32Array;
	
	public function new()
	{
		m_data = new Float32Array(7);
		surface = false;
		random  = false;
		ranges  = [ -1000, 1000, -1000, 1000, -1000, 1000];
	}
}

class SphereEmitter extends ParticleEmitter
{
	public var radius(get_radius, set_radius):Float;
	private function get_radius():Float { return m_data[3]; }
	private function set_radius(v:Float):Float { m_data[3] = v; return v; }
	
	public function new(p_radius : Float=1.0)
	{
		super();
		m_data[0] = 0.0;
		radius 	  = p_radius;
	}
}

class BoxEmitter extends ParticleEmitter
{
	public var width(get_width, set_width):Float;
	private function get_width():Float { return m_data[3]; }
	private function set_width(v:Float):Float { m_data[3] = v; return v; }
	
	public var height(get_height, set_height):Float;
	private function  get_height():Float { return m_data[4]; }
	private function  set_height(v:Float):Float { m_data[4] = v; return v; }
	
	public var depth (get_depth, set_depth):Float;
	private function  get_depth():Float { return m_data[5]; }
	private function  set_depth(v:Float):Float { m_data[5] = v; return v; }
	
	public function new(p_width : Float=1.0,p_height:Float=1.0,p_depth:Float=1.0)
	{
		super();
		m_data[0] = 1.0;
		width  = p_width;
		height = p_height;
		depth  = p_depth;
	}
}

class ConeEmitter extends ParticleEmitter
{
	public var angle(get_angle, set_angle):Float;
	private function get_angle():Float { return m_data[3]; }
	private function set_angle(v:Float):Float { m_data[3] = v; return v; }
	
	public var height(get_height, set_height):Float;
	private function  get_height():Float { return m_data[4]; }
	private function  set_height(v:Float):Float { m_data[4] = v; return v; }
	
	public function new(p_angle : Float=45.0,p_height:Float=1.0)
	{
		super();
		m_data[0] = 2.0;
		angle  = p_angle;
		height = p_height;
	}
}

class CylinderEmitter extends ParticleEmitter
{
	public var radius(get_radius, set_radius):Float;
	private function get_radius():Float { return m_data[3]; }
	private function set_radius(v:Float):Float { m_data[3] = v; return v; }
	
	public var height(get_height, set_height):Float;
	private function  get_height():Float { return m_data[4]; }
	private function  set_height(v:Float):Float { m_data[4] = v; return v; }
	
	public function new(p_radius : Float=1.0,p_height:Float=1.0)
	{
		super();
		m_data[0] = 3.0;
		radius  = p_radius;
		height  = p_height;
	}
}