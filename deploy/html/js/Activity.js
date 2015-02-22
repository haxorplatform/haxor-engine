"use strict";
//package
var haxor = haxor == null ? {} : haxor;

/**
Version of the Activity module.
//*/
haxor.ACTIVITY_VERSION = "1.0.0";

/**
Static class with Time information.
//*/
haxor.Time =
{		
	//public
	elapsed: 0.0,
	delta:   0.0,	
	
	//private
	m_last: -1.0,
	
	/**
	Updates Time information.
	//*/
	Update: function(t)
	{
		t *= 0.001;		
		if(this.m_last < 0.0) this.m_last = t;
		this.delta  = Math.max(0.01,t - this.m_last);
		this.m_last = t;
		this.elapsed += this.delta;
	}
};

/**
Class that handles the execution of Activity nodes.
//*/
haxor.Activity = 
{
	//public
	hasReqAnimFrame: false,
	hasPerfTime:     false,
	RAFId:              -1,
	ItvId:				-1,
	
	//private:
	m_step_clock:     -1.0,
	m_raf_offset:      0.0,
	m_itv_offset:      0.0,
	m_list:				[],
	m_perf_offset:	   0.0,
	
	
	/**
	Initialize all data and callbacks.
	//*/
	Init: function()
	{
		var a = haxor.Activity;
		if (!Date.now) { Date.now = function now() { return new Date().getTime(); } }; 
		a.hasReqAnimFrame = window.requestAnimationFrame != null;		
		a.hasPerfTime     = window.performance != null;
	},
	
	/**
	Starts the execution loops.
	//*/
	Start: function() 
	{  
		var a = haxor.Activity;
		a.Stop();				
		
		a.m_step_clock = -1.0;		
		
		a.m_itv_offset_clock = a.hasPerfTime ? window.performance.now() : Date.now();
		a.ItvId = window.setInterval(a.ItvLoop, 16);		
		
		a.m_raf_offset_clock = a.hasPerfTime ? window.performance.now() : 0.0;				
		if (a.hasReqAnimFrame) a.RAFId = window.requestAnimationFrame(a.RAFLoop);		
	},
	
	/**
	Stops all loops.
	//*/
	Stop: function() { var a = haxor.Activity; a.CancelItv(); if (a.hasReqAnimFrame) a.CancelRAF(); },
	
	/**
	Clears the execution list.
	//*/
	Clear: function() { var a = haxor.Activity; a.m_list = []; },
	
	/**
	Adds a Node to the execution pool.
	//*/
	Add: function(p_node,p_run_on_background)
	{
		var a = haxor.Activity;
		if(a.m_list.indexOf(p_node)>=0) return;
		p_node.runOnBackground = p_run_on_background != null ? p_run_on_background : true;
		a.m_list.push(p_node);
		//Starts when first element is inserted
		if(a.m_list.length == 1) a.Start();
	},
	
	/**
	Removes a Node of the execution pool.
	//*/
	Remove: function(p_node)
	{
		var a = haxor.Activity;
		var idx = a.m_list.indexOf(p_node);		
		if(idx < 0) return null;
		var n = a.m_list.splice(idx,1);		
		return n;
	},
	
	/**
	Executes a callback waiting 'delay' and during 'duration' in seconds.
	//*/
	Run:function(p_callback,p_duration,p_delay,p_run_on_background)
	{
		var n = {};		
		n.progress = 0.0;
		n.duration = p_duration != null ? p_duration : 0xffffff;
		n.elapsed  = p_delay != null ? -p_delay : 0.0;
		n.OnUpdate = function()
		{	
			if(n.elapsed >= 0.0) p_callback(n);
			n.elapsed  = Math.min(n.duration,n.elapsed + haxor.Time.delta);			
			n.progress = Math.min(1.0,n.duration <= 0.0 ? 1.0 : (n.elapsed / n.duration));
			if(n.elapsed >= n.duration) { p_callback(n); haxor.Activity.Remove(n); return;	}
		};
		haxor.Activity.Add(n,p_run_on_background);
		return n;
	},
	
	/**
	Waits 'delay' seconds and then Executes the callback.
	//*/
	Delay: function(p_callback,p_delay,p_run_on_background)
	{		
		var al = [];
		for(var i=3;i<arguments.length;i++) al.push(arguments[i]);
		return haxor.Activity.Run(function(n) 
		{			
			p_callback.apply(window,al); 
		},0.0,p_delay ? p_delay : 0.0,p_run_on_background);	
	},
	
	/**
	Waits 'delay' seconds and then sets the 'property' to the specified value.
	//*/
	Set: function(p_target,p_property,p_value,p_delay,p_run_on_background)
	{
		return haxor.Activity.Run(function(n) 
		{
			p_target[p_property] = p_value;
		},0.0,p_delay ? p_delay : 0.0,p_run_on_background);	
	},
	
	/**
	Iterates a list in a thread-like routine.
	//*/
	Iterate: function(p_callback,p_list,p_step,p_timeout,p_run_on_background)
	{
		var k = 0;
		var d = p_timeout != null ? p_timeout : 0xffffff;
		return haxor.Activity.Run(function(n) 
		{
			for(var i=0;i<p_step;i++)
			{
				if(k>=p_list.length) { haxor.Activity.Remove(n); break; }
				p_callback(p_list[k],k,p_list.length);
				k++;
			}			
		},d,0.0,p_run_on_background);
	},
	
	/**
	Main execution loop.
	//*/
	Step: function(p_time,p_visible)
	{			
		var a = haxor.Activity;		
		if (a.m_step_clock < 0) a.m_step_clock = p_time;		
		var t    		 = p_time;		
		var dt   		 = Math.max(1.0,t - a.m_step_clock); //in ms
		a.m_step_clock 	 = t;				
		var steps        = p_visible ? 1 : Math.min(62,Math.max(1,Math.floor(dt / 16)));		
		for (var i=0; i<steps;i++)
		{
			haxor.Time.Update(t);
			
			//Update all stuff.
			for(var j=0; j<a.m_list.length;j++)
			{				
				var enabled = p_visible ? true : a.m_list[j].runOnBackground;
				if(enabled) a.m_list[j].OnUpdate();
			}
			//*/
			if(!a.hasPerfTime) t += 1000.0/60.0;
		}
		
		//Stops when execution list is empty.
		if(a.m_list.length <= 0) a.Stop();
	},
	
	
	/**
	RequestAnimationFrame execution loop.
	//*/
	RAFLoop: function(p_time)
	{	
		var a = haxor.Activity;
		a.RAFId = window.requestAnimationFrame(a.RAFLoop);		
		var t  = a.hasPerfTime ? window.performance.now() : p_time;								
		a.Step(t - a.m_raf_offset_clock,true);		
		return true;
	},
	
	/**
	SetIntervalLoop
	//*/
	ItvLoop: function()
	{	
		var a = haxor.Activity;		
		var v = document.visibilityState != null ? (document.visibilityState != "hidden") : true;
		if(a.hasReqAnimFrame) if(v) return;				
		var t = a.hasPerfTime ? window.performance.now() : Date.now();
		a.Step(t - a.m_itv_offset_clock, v);
	},
	
	/**
	Cancels the RequestAnimationFrame loop.
	//*/
	CancelRAF: function() { var a = haxor.Activity; if (a.RAFId >= 0) window.cancelAnimationFrame(a.RAFId); a.RAFId = -1; },
	
	/**
	Cancels the setIntervalLoop.
	//*/
	CancelItv: function() { var a = haxor.Activity; if (a.ItvId >= 0) window.clearInterval(a.ItvId); a.ItvId = -1; },
};

//Initialize the Activity class.
haxor.Activity.Init();

//Globalize
if(haxor.global)
{
	window.Activity = haxor.Activity;
	window.Time     = haxor.Time;
}



