"use strict";
//package
var haxor = haxor == null ? {} : haxor;

/**
Version of the Animation module.
//*/
haxor.ANIMATION_VERSION = "1.0.0";


/**
Class that handles the execution of Animations nodes.
//*/
haxor.Animation = 
{	
	//private:
	m_list:				[],
	
	/**
	Initialize all data and callbacks.
	//*/
	Init: function(){ },
	
	/**
	Adds an Animation to the execution loop.
	//*/
	Add: function(p_target,p_property,p_value,p_duration,p_delay,p_easing,p_run_on_background) 
	{  
		var a 		   = haxor.Activity;
		var fn 		   = p_easing == null ? function(r){return r;} : p_easing;
		var dl 		   = p_delay == null ? 0.0 : p_delay;
		var d  		   = p_duration == null ? 0.3 : p_duration;
		var has_start  = false;
		var has_finish = false;
		var v0		   = null;		
		var l		   = haxor.Animation.m_list;
		var is_string  = typeof(p_target[p_property]) == "string";
		var is_number  = typeof(p_target[p_property]) == "number";
		var is_object  = typeof(p_target[p_property]) == "object";
		var vf		   = is_string ? (p_value+"") : p_value;
		var unit       = "";
		var is_color   = false;
		var c		   = {r:0,g:0,b:0};
		if(is_string)
		{
			var v = vf.toLowerCase();
			unit  = v.indexOf("px") >= 0 ? "px" : (v.indexOf("%") >= 0 ? "%" : "");
			is_color = (v.indexOf("rgb") >= 0) ? true : false;			
			if(!is_color)
			{
				if(v.indexOf("#")>=0)
				{
					v = v.replace("#","");
					var cr = parseInt(v.length >= 6 ? v.substr(0,2) : v.substr(0,1)+v.substr(0,1),16);
					var cg = parseInt(v.length >= 6 ? v.substr(2,2) : v.substr(1,1)+v.substr(1,1),16);
					var cb = parseInt(v.length >= 6 ? v.substr(4,2) : v.substr(2,1)+v.substr(2,1),16);
					vf = "rgb("+cr+","+cg+","+cb+")";
					is_color = true;
				}
			}
		}
		
		var res = a.Run(function(n)
		{
			if(!has_start)
			{
				haxor.Animation.Clear(p_target,p_property,[n]);				
				v0 = p_target[p_property];				
				if(is_string)
				{					
					if(is_color)
					{
						if(v0 == "") v0 = "rgb(255,255,255)";						
						v0 = v0.replace("rgb","").replace("(","").replace(")","").split(",");									
						vf = vf.replace("rgb","").replace("(","").replace(")","").split(",");						
						v0 = {r: parseInt(v0[0]), g: parseInt(v0[1]), b: parseInt(v0[2])};
						vf = {r: parseInt(vf[0]), g: parseInt(vf[1]), b: parseInt(vf[2])};
					}
					else
					{
						if(v0 == "") v0 = p_property == "opacity" ? "1.0" : "0.0";
						v0 = v0.replace(unit,"");
						v0 = unit == "" ? parseFloat(v0) : parseInt(v0);					
						vf = vf.replace(unit,"");
						vf = unit == "" ? parseFloat(vf) : parseInt(vf);
					}					
				}										
				has_start = true;				
			}
			
			var v1 = null;
			
			if(is_string)
			{
				if(is_color)
				{
					c.r = Math.floor(v0.r + (vf.r-v0.r) * fn(n.progress));
					c.g = Math.floor(v0.g + (vf.g-v0.g) * fn(n.progress));
					c.b = Math.floor(v0.b + (vf.b-v0.b) * fn(n.progress));
					v1 = "rgb("+c.r+","+c.g+","+c.b+")";
				}
				else
				{
					var res = v0 + (vf-v0) * fn(n.progress);
					if(unit!="") res = Math.floor(res);
					v1 = res+""+unit;
				}
			}
			else
			{
				v1 = v0 + (vf-v0) * fn(n.progress);
			}			
			p_target[p_property] = v1;
			
			if(n.progress >= 1.0)
			{
				if(!has_finish) 
				{ 
					if(n.OnComplete != null) n.OnComplete(); 
					has_finish=true; 
					var idx = l.indexOf(n);
					if(idx>=0) l.splice(idx,1);					
				}
			}			
		},d,dl,p_run_on_background);
		res.target   = p_target;
		res.property = p_property;
		l.push(res);
		return res;
	},
	
	/**
	Removes the Animations that matches the specified criteria.
	//*/
	Clear: function(p_target,p_property,p_ignore_list)
	{		
		var l  	   = haxor.Animation.m_list;
		var il 	   = p_ignore_list == null ? [] : p_ignore_list;
		p_property = p_property == null ? "" : p_property;
		for(var i=0;i<l.length;i++)
		{
			var match_target = p_target == null ? true : (l[i].target == p_target);
			if(match_target)
			{
				var match_property = (l[i].property == p_property) || (p_property == "");
				if(match_property)
				{
					if(il.indexOf(l[i])<0)
					{
						haxor.Activity.Remove(l[i]);
						l.splice(i--,1);
					}
				}
			}
		}
	},	
};

//Initialize the Animation class.
haxor.Animation.Init();

//Globalize
if(haxor.global)
{
	window.Animation = haxor.Animation;	
}



