#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_ShaderContext
#include <haxor/context/ShaderContext.h>
#endif
namespace haxor{
namespace context{

Void ShaderContext_obj::__construct()
{
	return null();
}

//ShaderContext_obj::~ShaderContext_obj() { }

Dynamic ShaderContext_obj::__CreateEmpty() { return  new ShaderContext_obj; }
hx::ObjectPtr< ShaderContext_obj > ShaderContext_obj::__new()
{  hx::ObjectPtr< ShaderContext_obj > result = new ShaderContext_obj();
	result->__construct();
	return result;}

Dynamic ShaderContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ShaderContext_obj > result = new ShaderContext_obj();
	result->__construct();
	return result;}

::String ShaderContext_obj::flat_source;

::String ShaderContext_obj::flat_texture_source;

::String ShaderContext_obj::gizmo_source;


ShaderContext_obj::ShaderContext_obj()
{
}

Dynamic ShaderContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"flat_source") ) { return flat_source; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"gizmo_source") ) { return gizmo_source; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"flat_texture_source") ) { return flat_texture_source; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ShaderContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"flat_source") ) { flat_source=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"gizmo_source") ) { gizmo_source=inValue.Cast< ::String >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"flat_texture_source") ) { flat_texture_source=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ShaderContext_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("flat_source"),
	HX_CSTRING("flat_texture_source"),
	HX_CSTRING("gizmo_source"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ShaderContext_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ShaderContext_obj::flat_source,"flat_source");
	HX_MARK_MEMBER_NAME(ShaderContext_obj::flat_texture_source,"flat_texture_source");
	HX_MARK_MEMBER_NAME(ShaderContext_obj::gizmo_source,"gizmo_source");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::flat_source,"flat_source");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::flat_texture_source,"flat_texture_source");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::gizmo_source,"gizmo_source");
};

#endif

Class ShaderContext_obj::__mClass;

void ShaderContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.ShaderContext"), hx::TCanCast< ShaderContext_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void ShaderContext_obj::__boot()
{
	flat_source= HX_CSTRING("\r\n\t<shader id=\"haxor/unlit/Flat\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\t\t\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\tv_color = color * Tint;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) { gl_FragColor = v_color; }\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t");
	flat_texture_source= HX_CSTRING("\r\n\t<shader id=\"haxor/unlit/FlatTexture\">\t\r\n\t\t<vertex>\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\t\r\n\t\tattribute vec4 color;\r\n\t\tattribute vec3 uv0;\t\t\r\n\t\tvarying vec3 v_uv0;\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\tv_uv0   = uv0;\r\n\t\t\tv_color = color;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\r\n\t\t\tvarying vec3 v_uv0;\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tuniform sampler2D DiffuseTexture;\r\n\t\t\tuniform sampler2D Tex0;\t\t\t\r\n\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy*0.1);\t\t\t\r\n\t\t\t\tif (length(tex_diffuse.xyz) < 0.01) discard;\t\t\t\t\r\n\t\t\t\tgl_FragColor.xyz = (tex_diffuse.xyz * v_color.xyz) + texture2D(Tex0, v_uv0.xy).xyz*0.5;\r\n\t\t\t\t\r\n\t\t\t\tgl_FragColor.a \t = tex_diffuse.a * v_color.a*0.5;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t");
	gizmo_source= HX_CSTRING("\r\n\t<shader id=\"haxor/gizmo/Grid\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\r\n\t\tuniform float Area;\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\tgl_Position = ((vec4(vertex*Area, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\tv_color = color * Tint;\t\t\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\r\n\t\t\t\tgl_FragColor = v_color;\r\n\t\t\t}\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t");
}

} // end namespace haxor
} // end namespace context
