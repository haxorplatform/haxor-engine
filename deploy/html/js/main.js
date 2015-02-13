'use strict'

/* ----------------------------------------------------------------------------------------------------------- */
/* -------------------------------------------------- LOADER ------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------------------- */

var Loader = 
{
	init:function()
	{
		//Utils
		Utils.browser();
	}
}

/* ----------------------------------------------------------------------------------------------------------- */
/* -------------------------------------------------- UTILS -------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------------------- */

var Utils =
{
	browser:function() 
	{
		var name = bowser.name.toLowerCase();
		$('html').addClass(name); 

		var version = String(name + Math.floor(bowser.version)).toLowerCase();
		$('html').addClass(version);

		Modernizr.animate = ((bowser.msie && bowser.version <= 9) || (bowser.mobile || bowser.tablet)) ? false : true;
		var animate = Modernizr.animate ? 'animate' : 'no-animate';
		$('html').addClass(animate);

		Modernizr.mobile = bowser.mobile == true || bowser.tablet == true;
		var mobile = Modernizr.mobile ? 'mobile' : 'no-mobile';
		$('html').addClass(mobile);
	}
}


/* ----------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------------ INITIALIZE ----------------------------------------------- */
/* ----------------------------------------------------------------------------------------------------------- */

$(document).ready(Loader.init);