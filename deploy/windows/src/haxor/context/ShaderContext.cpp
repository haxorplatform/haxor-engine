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

::String ShaderContext_obj::flat_texture_skin_source;

::String ShaderContext_obj::gizmo_source;

::String ShaderContext_obj::texture_source;


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
	case 14:
		if (HX_FIELD_EQ(inName,"texture_source") ) { return texture_source; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"flat_texture_source") ) { return flat_texture_source; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"flat_texture_skin_source") ) { return flat_texture_skin_source; }
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
	case 14:
		if (HX_FIELD_EQ(inName,"texture_source") ) { texture_source=inValue.Cast< ::String >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"flat_texture_source") ) { flat_texture_source=inValue.Cast< ::String >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"flat_texture_skin_source") ) { flat_texture_skin_source=inValue.Cast< ::String >(); return inValue; }
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
	HX_CSTRING("flat_texture_skin_source"),
	HX_CSTRING("gizmo_source"),
	HX_CSTRING("texture_source"),
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
	HX_MARK_MEMBER_NAME(ShaderContext_obj::flat_texture_skin_source,"flat_texture_skin_source");
	HX_MARK_MEMBER_NAME(ShaderContext_obj::gizmo_source,"gizmo_source");
	HX_MARK_MEMBER_NAME(ShaderContext_obj::texture_source,"texture_source");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::flat_source,"flat_source");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::flat_texture_source,"flat_texture_source");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::flat_texture_skin_source,"flat_texture_skin_source");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::gizmo_source,"gizmo_source");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::texture_source,"texture_source");
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
	flat_texture_source= HX_CSTRING("\r\n\t<shader id=\"haxor/unlit/FlatTexture\">\t\r\n\t\t<vertex>\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\t\r\n\t\tattribute vec4 color;\r\n\t\tattribute vec3 uv0;\t\t\r\n\t\tvarying vec3 v_uv0;\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\tv_uv0   = uv0;\r\n\t\t\tv_color = color;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\r\n\t\t\tvarying vec3 v_uv0;\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tuniform sampler2D DiffuseTexture;\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);\t\r\n\t\t\t\tgl_FragColor.xyz = (tex_diffuse.xyz * v_color.xyz);\r\n\t\t\t\tgl_FragColor.a \t = tex_diffuse.a * v_color.a;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t");
	flat_texture_skin_source= HX_CSTRING("\r\n\t<shader id=\"haxor/unlit/FlatTextureSkin\">\t\r\n\t\t<vertex precision=\"high\">\r\n\t\t\r\n\t\t#define SKINNING_TEXTURE_SIZE 2048.0\r\n\t\t#define BINDS_OFFSET\t\t  1024.0\r\n\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  WorldMatrixIT;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\r\n\t\tuniform vec3  WSCameraPosition;\t\t\r\n\t\t\r\n\t\t//uniform vec4  Skinning[MAX_BONES];\r\n\t\t\r\n\t\tuniform sampler2D Skinning;\r\n\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\t\r\n\t\tattribute vec4 color;\r\n\t\tattribute vec3 normal;\r\n\t\tattribute vec3 uv0;\r\n\t\tattribute vec4 bone;\r\n\t\tattribute vec4 weight;\r\n\t\t\r\n\t\tvarying vec3 v_uv0;\r\n\t\tvarying vec3 v_normal;\r\n\t\tvarying vec4 v_color;\r\n\t\tvarying vec4 v_wsVertex;\r\n\t\tvarying vec3 v_wsView;\t\r\n\t\t\r\n\t\tvec4 SkinningRead(float id)\r\n\t\t{\r\n\t\t\treturn texture2D(Skinning, vec2(0.0,(id/(SKINNING_TEXTURE_SIZE-1.0))));\r\n\t\t}\r\n\t\t\r\n\t\tmat4 GetSkinMatrix(float b,float o)\r\n\t\t{\r\n\t\t\tvec4 l0, l1, l2;\t\t\t\t\t\t\r\n\t\t\tl0 = SkinningRead(b+o); l1 = SkinningRead(b+1.0+o); l2 = SkinningRead(b+2.0+o);\r\n\t\t\treturn mat4(l0.x, l0.y, l0.z, l0.w, l1.x, l1.y, l1.z, l1.w, l2.x, l2.y, l2.z, l2.w, 0, 0, 0, 1);\t\t\t\r\n\t\t}\r\n\t\t\r\n\t\tmat4 SkinWorldMatrix()\r\n\t\t{\r\n\t\t\tvec4 b = bone * 3.0;\r\n\t\t\tvec4 w = weight;\r\n\t\t\tfloat ivs = 1.0 / (weight.x + weight.y + weight.z + weight.w);\r\n\t\t\tw *= ivs;\r\n\t\t\tmat4 j0 = GetSkinMatrix(b[0],0.0);\r\n\t\t\tmat4 b0 = GetSkinMatrix(b[0],BINDS_OFFSET);\r\n\t\t\tmat4 j1 = GetSkinMatrix(b[1],0.0);\r\n\t\t\tmat4 b1 = GetSkinMatrix(b[1],BINDS_OFFSET);\r\n\t\t\tmat4 j2 = GetSkinMatrix(b[2],0.0);\r\n\t\t\tmat4 b2 = GetSkinMatrix(b[2],BINDS_OFFSET);\r\n\t\t\tmat4 j3 = GetSkinMatrix(b[3],0.0);\r\n\t\t\tmat4 b3 = GetSkinMatrix(b[3],BINDS_OFFSET);\r\n\t\t\t\r\n\t\t\treturn    ((b0 * j0) * w[0])+\r\n\t\t\t          ((b1 * j1) * w[1])+\r\n\t\t\t          ((b2 * j2) * w[2])+\r\n\t\t\t          ((b3 * j3) * w[3]);\r\n\t\t\t\r\n\t\t\t\r\n\t\t}\r\n\t\t\t\t\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\r\n\t\t\tvec4 lv = vec4(vertex,1.0);\r\n\t\t\tvec3 ln = vec3(normal);\r\n\t\t\tmat4 swm = SkinWorldMatrix();\r\n\t\t\tmat4 wm;\t\t\t\t\t\r\n\t\t\twm = swm;\r\n\t\t\twm = WorldMatrix;\r\n\t\t\t\r\n\t\t\tv_uv0   = uv0;\r\n\t\t\tv_color = color;\t\t\t\r\n\t\t\tv_normal = ln * mat3(WorldMatrixIT);\t\t\t\r\n\t\t\tgl_Position = ((lv * wm) * ViewMatrix) * ProjectionMatrix;\r\n\t\t}\t\t\r\n\t\t</vertex>\r\n\t\t\r\n\t\t<fragment precision=\"high\">\r\n\t\t\t\t\t\r\n\t\t\tuniform sampler2D DiffuseTexture;\t\t\t\r\n\t\t\t\r\n\t\t\tuniform sampler2D Skinning;\r\n\t\t\t\r\n\t\t\tvarying vec3 v_uv0;\r\n\t\t\tvarying vec4 v_color;\r\n\t\t\tvarying vec3 v_normal;\r\n\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);\r\n\t\t\t\tgl_FragColor.xyz = v_color.xyz;// tex_diffuse.xyz * v_color.xyz;\r\n\t\t\t\tgl_FragColor.a \t = 1.0;// tex_diffuse.a * v_color.a;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t");
	gizmo_source= HX_CSTRING("\r\n\t<shader id=\"haxor/gizmo/Grid\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\r\n\t\tuniform float Area;\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\tgl_Position = ((vec4(vertex*Area, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\tv_color = color * Tint;\t\t\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\r\n\t\t\t\tgl_FragColor = v_color;\r\n\t\t\t}\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t");
	texture_source= HX_CSTRING("\r\n\t<shader id=\"haxor/gizmo/Texture\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform vec2  Screen;\r\n\t\tuniform vec4  Rect;\r\n\t\tuniform vec4  Tint;\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\r\n\t\tvarying vec4 v_color;\r\n\t\tvarying vec2 v_uv0;\r\n\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tvec4 p = vec4(vertex, 1);\r\n\t\t\tfloat sw = Screen.x * 0.5;\r\n\t\t\tfloat sh = Screen.y * 0.5;\r\n\t\t\tp.x *= Rect.z / sw;\r\n\t\t\tp.y *= Rect.w / sh;\r\n\t\t\tp.x += Rect.x / sw;\r\n\t\t\tp.y -= Rect.y / sh;\t\t\t\r\n\t\t\tp.x -= 1.0;\r\n\t\t\tp.y += 1.0;\t\t\t\r\n\t\t\tp.z = 0.001;\r\n\t\t\tgl_Position = p;\r\n\t\t\tv_color = Tint;\t\t\r\n\t\t\tv_uv0   = vec2(vertex.x,1.0+vertex.y);\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\r\n\t\t\tvarying vec2 v_uv0;\r\n\t\t\tuniform sampler2D Texture;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\r\n\t\t\t\tgl_FragColor = texture2D(Texture, v_uv0) * v_color;\r\n\t\t\t}\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t");
}

} // end namespace haxor
} // end namespace context
