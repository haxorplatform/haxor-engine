/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class ParticleKernel extends KernelFloat
{
	static var DATA_SIZE : Int = 128;
	
	public var m_back : RenderTexture;
		
	private var m_kernel : Shader;
	
	private var m_time : Float;
	
	private var m_dt : Float;
	
	private var m_renderer : ParticleRenderer;
	
	private var m_resize : Bool;
	
	private var m_system : Float32Array;
	
	public function new(p_renderer : ParticleRenderer) 
	{
		super(DATA_SIZE, DATA_SIZE,false,PixelFormat.Float4);
		
		name = "ParticleKernel"+p_renderer.id;
		
		m_back  	= new RenderTexture(DATA_SIZE, DATA_SIZE, PixelFormat.Float4);
		m_back.minFilter = TextureFilter.Nearest;
		m_back.magFilter = TextureFilter.Nearest;
		m_back.name		= "ParticleKernelData0";
		m_output.name 	= "ParticleKernelData1";
		m_renderer  = p_renderer;
		
		m_time   = Time.elapsed;
		m_dt     = 0.0;
		m_resize = false;
		
		m_kernel = shader = Asset.Get("haxor/kernel/ParticleKernel");
		
		m_system = new Float32Array(
		[
		0, 0, 0, 0,	//0  Emitter Type & Dimensions  [type][x][y][z]
		0, 0, 0, 0,	//1  Renderer & Emitter Flags 	[surface][billboard][local][loop]
		0, 0, 0, 0, //2  Renderer Flags 			[state][progress][][delta_time]
		0, 0, 0, 0, //3  Renderer Start Speed		[start][end][curve][random]
		0, 0, 0, 0, //4  Renderer Start Size		[sx][sy][sz][curve]
		0, 0, 0, 0, //5  Renderer Start Size		[ex][ey][ez][random]
		0, 0, 0, 0, //6  Renderer Start Life		[start][end][curve][random]		
		0, 0, 0, 0, //7  Renderer Start Rotation	[sx][sy][sz][curve]
		0, 0, 0, 0, //8  Renderer Start Rotation	[ex][ey][ez][random]		
		0, 0, 0, 0, //9  Renderer Life Speed		[start][end][curve][random]
		0, 0, 0, 0, //10 Renderer Life Motion		[sx][sy][sz][curve]
		0, 0, 0, 0, //11 Renderer Life Motion		[ex][ey][ez][random]
		0, 0, 0, 0, //12 Renderer Life Size			[sx][sy][sz][curve]
		0, 0, 0, 0, //13 Renderer Life Size			[ex][ey][ez][random]
		0, 0, 0, 0, //14 Renderer Life Rotation		[sx][sy][sz][curve]
		0, 0, 0, 0, //15 Renderer Life Rotation		[ex][ey][ez][random]
		0, 0, 0, 0,	//16 Renderer Attributes  	 	[fx,fy,fz]		
		0, 0, 0, 0,	//17 Renderer Attributes  	 	wm0  wm1  wm2  wm3
		0, 0, 0, 0,	//18 Renderer Attributes  	 	wm4  wm5  wm6  wm7
		0, 0, 0, 0,	//19 Renderer Attributes  	 	wm8  wm9  wm10 wm11v
		0, 0, 0, 0,	//20 Renderer Start Frame 		[start][end][curve][random]
		0, 0, 0, 0,	//21 Renderer Sheet 	 		[w][h][fps][wrap]
		0, 0, 0, 0, //22 Renderer Sheet / Ranges	[count][vxmin][vxmax]
		0, 0, 0, 0, //23 Emitter Ranges	            [vymin][vymax][vzmin][vzmax]		
		0, 0, 0, 0  //24 Renderer Emission          [start][count][][]
		]);
		
		
		SetUniform("Data",   m_back);
		SetUniform("System", m_system);
	}
	
	override public function Execute():Void 
	{		
		if (m_resize)
		{
			m_resize = false;
		}
		
		var s  : Float32Array     = m_system;
		var r  : ParticleRenderer = m_renderer ;
		var af : ParticleAttribute<Float>;
		var af3: ParticleAttribute<Vector3>;
		var k  : Int = 0;
		
		
		s[k++]  = r.emitter.m_data[0]; 					 //emitter type
		s[k++]  = r.emitter.m_data[3]; 					 //emitter vx
		s[k++]  = r.emitter.m_data[4]; 					 //emitter vy
		s[k++]  = r.emitter.m_data[5]; 					 //emitter vz		
		s[k++]  = r.emitter.m_data[1]; 					 //emitter surface flag
		s[k++]  = r.emitter.m_data[2]; 					 //emitter random direction flag
		
		s[k++]  = r.local ? 1.0 : 0.0; 					 //system local
		s[k++]  = r.loop  ? 1.0 : 0.0; 					 //system loop
		s[k++]  = r.m_state == ParticleSystemState.None ? 0.0 : (r.m_state == ParticleSystemState.Reset ? 1.0 : (r.m_state == ParticleSystemState.Update ? 2.0 : 0.0)); //system state
		s[k++]  = Mathf.Clamp01(r.elapsed / r.duration); //system progress
		s[k++]  = 0.0;// Mathf.Floor(r.emitted);		   		 //system emitted
		s[k++]  = Time.deltaTime;						 //system delta time
		
		af = r.start.speed;								 //particle start speed
		s[k++] = af.start; 
		s[k++] = af.end;
		s[k++] = af.curve;
		s[k++] = af.random ? 1.0 : 0.0;
		
		af3 = r.start.size;							  //particle start size
		s[k++] = af3.start.x;
		s[k++] = af3.start.y;
		s[k++] = af3.start.z;
		s[k++] = af3.curve;
		s[k++] = af3.end.x;
		s[k++] = af3.end.y;
		s[k++] = af3.end.z;
		s[k++] = af3.random ? 1.0 : 0.0;
		
		af = r.start.life;								 //particle start life
		s[k++] = af.start; 
		s[k++] = af.end;
		s[k++] = af.curve;
		s[k++] = af.random ? 1.0 : 0.0;
		
		af3 = r.start.rotation;							  //particle start rotation
		s[k++] = af3.start.x;
		s[k++] = af3.start.y;
		s[k++] = af3.start.z;
		s[k++] = af3.curve;
		s[k++] = af3.end.x;
		s[k++] = af3.end.y;
		s[k++] = af3.end.z;
		s[k++] = af3.random ? 1.0 : 0.0;
		
		af = r.life.speed;								 //particle speed over life
		s[k++] = af.start; 
		s[k++] = af.end;
		s[k++] = af.curve;
		s[k++] = af.random ? 1.0 : 0.0;
		
		af3 = r.life.motion;							  //particle motion over life
		s[k++] = af3.start.x;
		s[k++] = af3.start.y;
		s[k++] = af3.start.z;
		s[k++] = af3.curve;
		s[k++] = af3.end.x;
		s[k++] = af3.end.y;
		s[k++] = af3.end.z;
		s[k++] = af3.random ? 1.0 : 0.0;
		
		af3 = r.life.size;							  //particle size over life
		s[k++] = af3.start.x;
		s[k++] = af3.start.y;
		s[k++] = af3.start.z;
		s[k++] = af3.curve;
		s[k++] = af3.end.x;
		s[k++] = af3.end.y;
		s[k++] = af3.end.z;
		s[k++] = af3.random ? 1.0 : 0.0;
		
		af3 = r.life.rotation;							  //particle rotation over life
		s[k++] = af3.start.x;
		s[k++] = af3.start.y;
		s[k++] = af3.start.z;
		s[k++] = af3.curve;
		s[k++] = af3.end.x;
		s[k++] = af3.end.y;
		s[k++] = af3.end.z;
		s[k++] = af3.random ? 1.0 : 0.0;
		
				
		s[k++] = r.force.x;								  //system force 
		s[k++] = r.force.y;
		s[k++] = r.force.z;
		s[k++] = 0.0;
		
		var wm : Matrix4 = m_renderer.transform.m_worldMatrix;				//system WorldMatrix
		s[k++] = wm.m00; s[k++] = wm.m01; s[k++] = wm.m02; s[k++] = wm.m03;
		s[k++] = wm.m10; s[k++] = wm.m11; s[k++] = wm.m12; s[k++] = wm.m13;
		s[k++] = wm.m20; s[k++] = wm.m21; s[k++] = wm.m22; s[k++] = wm.m23;
		
		af = r.sheet.frame;								 //particle start sheet frame
		s[k++] = af.start; 
		s[k++] = af.end;
		s[k++] = af.curve;
		s[k++] = af.random ? 1.0 : 0.0;
		
		s[k++] = r.sheet.width;
		s[k++] = r.sheet.height;		
		s[k++] = r.sheet.reverse ? -m_renderer.sheet.fps : m_renderer.sheet.fps;
		s[k++] = r.sheet.wrap == AnimationWrap.Clamp ? 0.0 : (m_renderer.sheet.wrap == AnimationWrap.Loop ? 1.0 : 2.0);
		s[k++] = r.sheet.length;
		
		s[k++] = r.emitter.ranges[0];
		s[k++] = r.emitter.ranges[1];
		s[k++] = 0.0;
		
		s[k++] = r.emitter.ranges[2];
		s[k++] = r.emitter.ranges[3];
		s[k++] = r.emitter.ranges[4];
		s[k++] = r.emitter.ranges[5];
		
		s[k++]  = r.m_emitted_start;		   		 //system emitted start
		s[k++]  = r.m_emitted_count;		   		 //system emitted start
		s[k++]  = 0.0;
		s[k++]  = 0.0;
				
		SetUniform("StartColor",  r.start.color == null ? Texture2D.white : r.start.color);
		SetUniform("Color",  	  r.life.color == null ?  Texture2D.white : r.life.color);
		
		if (r.material != null)
		{
			r.material.SetUniform("System", m_system);
			r.material.SetUniform("Data", m_back);
			r.material.SetUniform("DataWidth",  m_back.width+0.00001);
			r.material.SetUniform("DataHeight", m_back.height + 0.00001);
			var tex : Texture = r.material.GetUniform("Texture");
			if (tex != null)
			{
				r.material.SetUniform("TextureWidth",  tex.width+0.00001);
				r.material.SetUniform("TextureHeight", tex.height + 0.00001);
			}
		}
		
		super.Execute();
		
		//PingPong buffers for next usage
		var tmp : RenderTexture = m_back;
		m_back   = m_output;
		m_output = tmp;
		
		SetUniform("Data", m_back);	
		
	}
	
}