package haxor.physics;
import haxor.component.physics.BoxCollider;
import haxor.component.physics.Collider;
import haxor.component.physics.RigidBody;
import haxor.component.physics.SphereCollider;
import haxor.context.EngineContext;
import haxor.context.Process;
import haxor.core.Console;
import haxor.core.Enums.ColliderType;
import haxor.core.IFixedUpdateable;
import haxor.core.Resource;
import haxor.core.Time;
import haxor.math.Color;
import haxor.math.Mathf;
import haxor.math.Matrix4;
import haxor.math.Vector3;
import haxor.physics.broadphase.BroadPhase;
import haxor.physics.broadphase.SAPBroadPhase;


/**
 * Class that handles physics features of the engine.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Physics
{	
	
	
	/**
	 * Gravity force vector.
	 */
	static public var gravity : Vector3;
	
	/**
	 * Broadphase instance.
	 */
	static public var broadphase(get_broadphase,set_broadphase) : BroadPhase;	
	static private function get_broadphase():BroadPhase { return m_broadphase; }
	static private function set_broadphase(v:BroadPhase):BroadPhase 
	{ 
		if (v == null) return m_broadphase;		
		m_broadphase = v;
		m_broadphase.Initialize();
		return m_broadphase;
		
	}
	static private var m_broadphase : BroadPhase;
	
	/**
	 * Collision handling class.
	 */
	static public var solver(get_solver,never) : CollisionSolver;	
	static private function get_solver():CollisionSolver { return m_solver; }	
	static private var m_solver : CollisionSolver;
	
	/**
	 * Interaction table.
	 */
	static private var m_it : Map<Int,Bool>;
	
	/**
	 * Initialize the physics static class.
	 */
	static public function Initialize():Void
	{
		Console.Log("Physics> Initialize",5);
		m_it = new Map<Int,Bool>();
		for (i in 0...32)
		for (j in 0...32)
		{
			SetInteraction((1 << i), (1 << j), false);
		}	
		
		SetInteraction(1,1, true);
		
		gravity 	= new Vector3(0.0, -9.81, 0.0);
		broadphase  = new SAPBroadPhase();		
		m_solver    = new CollisionSolver();
		
		Console.Log("\tSAP Broadphase", 5);
		Console.Log("\tSolver iterations["+m_solver.iterations+"]", 5);		
	}
	
	/**
	 * Sets if 2 layers will interact.
	 * @param	p_layer_a
	 * @param	p_layer_b
	 * @param	p_flag
	 */
	static public function SetInteraction(p_layer_bit_a : Int, p_layer_bit_b : Int, p_flag : Bool):Void
	{
		var f : Int = p_layer_bit_a | p_layer_bit_b;
		m_it.set(f, p_flag);
	}
	
	/**
	 * Returns a flag indicating if 2 elements can physically interact.
	 * @param	p_a
	 * @param	p_b
	 * @return
	 */
	static public function CanInteract(p_layer_bit_a:Int, p_layer_bit_b:Int):Bool
	{
		var k :Int = p_layer_bit_a | p_layer_bit_b;
		return m_it.exists(k) ? m_it.get(k) : false;
	}	
	
}