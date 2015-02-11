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

::String ShaderContext_obj::grid_source;

::String ShaderContext_obj::texture_source;

::String ShaderContext_obj::gizmo_source;

::String ShaderContext_obj::flat_particle_source;


ShaderContext_obj::ShaderContext_obj()
{
}

Dynamic ShaderContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"flat_source") ) { return flat_source; }
		if (HX_FIELD_EQ(inName,"grid_source") ) { return grid_source; }
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
	case 20:
		if (HX_FIELD_EQ(inName,"flat_particle_source") ) { return flat_particle_source; }
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
		if (HX_FIELD_EQ(inName,"grid_source") ) { grid_source=inValue.Cast< ::String >(); return inValue; }
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
	case 20:
		if (HX_FIELD_EQ(inName,"flat_particle_source") ) { flat_particle_source=inValue.Cast< ::String >(); return inValue; }
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
	HX_CSTRING("grid_source"),
	HX_CSTRING("texture_source"),
	HX_CSTRING("gizmo_source"),
	HX_CSTRING("flat_particle_source"),
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
	HX_MARK_MEMBER_NAME(ShaderContext_obj::grid_source,"grid_source");
	HX_MARK_MEMBER_NAME(ShaderContext_obj::texture_source,"texture_source");
	HX_MARK_MEMBER_NAME(ShaderContext_obj::gizmo_source,"gizmo_source");
	HX_MARK_MEMBER_NAME(ShaderContext_obj::flat_particle_source,"flat_particle_source");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::flat_source,"flat_source");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::flat_texture_source,"flat_texture_source");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::flat_texture_skin_source,"flat_texture_skin_source");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::grid_source,"grid_source");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::texture_source,"texture_source");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::gizmo_source,"gizmo_source");
	HX_VISIT_MEMBER_NAME(ShaderContext_obj::flat_particle_source,"flat_particle_source");
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
	flat_texture_skin_source= HX_CSTRING("\r\n\t<shader id=\"haxor/unlit/FlatTextureSkin\">\t\r\n\t\t<vertex precision=\"low\">\r\n\t\t\r\n\t\t#define SKINNING_TEXTURE_SIZE 2048.0\r\n\t\t#define BINDS_OFFSET\t\t  1024.0\r\n\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  WorldMatrixIT;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\r\n\t\tuniform vec3  WSCameraPosition;\t\t\r\n\t\t\r\n\t\t//uniform vec4  Skinning[MAX_BONES];\r\n\t\t\r\n\t\tuniform sampler2D Skinning;\r\n\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\t\r\n\t\tattribute vec4 color;\r\n\t\tattribute vec3 normal;\r\n\t\tattribute vec3 uv0;\r\n\t\tattribute vec4 bone;\r\n\t\tattribute vec4 weight;\r\n\t\t\r\n\t\tvarying vec3 v_uv0;\r\n\t\tvarying vec3 v_normal;\r\n\t\tvarying vec4 v_color;\r\n\t\tvarying vec4 v_wsVertex;\r\n\t\tvarying vec3 v_wsView;\t\r\n\t\t\r\n\t\tvec4 SkinningRead(float id)\r\n\t\t{\r\n\t\t\treturn texture2D(Skinning, vec2(0.0,(id/(SKINNING_TEXTURE_SIZE-1.0))));\r\n\t\t}\r\n\t\t\r\n\t\tmat4 GetSkinMatrix(float b,float o)\r\n\t\t{\r\n\t\t\tvec4 l0, l1, l2;\t\t\t\t\t\t\r\n\t\t\tl0 = SkinningRead(b+o); l1 = SkinningRead(b+1.0+o); l2 = SkinningRead(b+2.0+o);\r\n\t\t\treturn mat4(l0.x, l0.y, l0.z, l0.w, l1.x, l1.y, l1.z, l1.w, l2.x, l2.y, l2.z, l2.w, 0, 0, 0, 1);\t\t\t\r\n\t\t}\r\n\t\t\r\n\t\tmat4 SkinWorldMatrix()\r\n\t\t{\r\n\t\t\tvec4 b = bone * 3.0;\r\n\t\t\tvec4 w = weight;\r\n\t\t\tfloat ivs = 1.0 / (weight.x + weight.y + weight.z + weight.w);\r\n\t\t\tw *= ivs;\r\n\t\t\tmat4 j0 = GetSkinMatrix(b[0],0.0);\r\n\t\t\tmat4 b0 = GetSkinMatrix(b[0],BINDS_OFFSET);\r\n\t\t\tmat4 j1 = GetSkinMatrix(b[1],0.0);\r\n\t\t\tmat4 b1 = GetSkinMatrix(b[1],BINDS_OFFSET);\r\n\t\t\tmat4 j2 = GetSkinMatrix(b[2],0.0);\r\n\t\t\tmat4 b2 = GetSkinMatrix(b[2],BINDS_OFFSET);\r\n\t\t\tmat4 j3 = GetSkinMatrix(b[3],0.0);\r\n\t\t\tmat4 b3 = GetSkinMatrix(b[3],BINDS_OFFSET);\r\n\t\t\t\r\n\t\t\treturn    ((b0 * j0) * w[0])+\r\n\t\t\t          ((b1 * j1) * w[1])+\r\n\t\t\t          ((b2 * j2) * w[2])+\r\n\t\t\t          ((b3 * j3) * w[3]);\r\n\t\t\t\r\n\t\t\t\r\n\t\t}\r\n\t\t\t\t\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\r\n\t\t\tvec4 lv = vec4(vertex,1.0);\r\n\t\t\tvec3 ln = vec3(normal);\r\n\t\t\tmat4 swm = SkinWorldMatrix();\r\n\t\t\tmat4 wm;\t\t\t\t\t\r\n\t\t\twm = swm;\r\n\t\t\t//wm = WorldMatrix;\r\n\t\t\t\r\n\t\t\tv_uv0   = uv0;\r\n\t\t\tv_color = color;\t\t\t\r\n\t\t\tv_normal = ln * mat3(WorldMatrixIT);\t\t\t\r\n\t\t\tgl_Position = ((lv * wm) * ViewMatrix) * ProjectionMatrix;\r\n\t\t}\t\t\r\n\t\t</vertex>\r\n\t\t\r\n\t\t<fragment precision=\"low\">\r\n\t\t\t\t\t\r\n\t\t\tuniform sampler2D DiffuseTexture;\t\t\t\r\n\t\t\t\r\n\t\t\tuniform sampler2D Skinning;\r\n\t\t\t\r\n\t\t\tvarying vec3 v_uv0;\r\n\t\t\tvarying vec4 v_color;\r\n\t\t\tvarying vec3 v_normal;\r\n\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);\r\n\t\t\t\tgl_FragColor.xyz = tex_diffuse.xyz * v_color.xyz;\r\n\t\t\t\tgl_FragColor.a \t = tex_diffuse.a * v_color.a;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t");
	grid_source= HX_CSTRING("\r\n\t<shader id=\"haxor/gizmo/Grid\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\r\n\t\tuniform float Area;\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\tgl_Position = ((vec4(vertex*Area, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\tv_color = color * Tint;\t\t\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\r\n\t\t\t\tgl_FragColor = v_color;\r\n\t\t\t}\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t");
	texture_source= HX_CSTRING("\r\n\t<shader id=\"haxor/gizmo/Texture\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform vec2  Screen;\r\n\t\tuniform vec4  Rect;\r\n\t\tuniform vec4  Tint;\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\r\n\t\tvarying vec4 v_color;\r\n\t\tvarying vec2 v_uv0;\r\n\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tvec4 p = vec4(vertex, 1);\r\n\t\t\tfloat sw = Screen.x * 0.5;\r\n\t\t\tfloat sh = Screen.y * 0.5;\r\n\t\t\tp.x *= Rect.z / sw;\r\n\t\t\tp.y *= Rect.w / sh;\r\n\t\t\tp.x += Rect.x / sw;\r\n\t\t\tp.y -= Rect.y / sh;\t\t\t\r\n\t\t\tp.x -= 1.0;\r\n\t\t\tp.y += 1.0;\t\t\t\r\n\t\t\tp.z = 0.001;\r\n\t\t\tgl_Position = p;\r\n\t\t\tv_color = Tint;\t\t\r\n\t\t\tv_uv0   = vec2(vertex.x,1.0+vertex.y);\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\r\n\t\t\tvarying vec2 v_uv0;\r\n\t\t\tuniform sampler2D Texture;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\r\n\t\t\t\tgl_FragColor = texture2D(Texture, v_uv0) * v_color;\r\n\t\t\t}\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t");
	gizmo_source= HX_CSTRING("\r\n\t<shader id=\"haxor/gizmo/Gizmo\">\t\r\n\t\t<vertex>\t\r\n\t\t\r\n\t\t#define GIZMO_POINT       0\r\n\t\t#define GIZMO_LINE        1\r\n\t\t#define GIZMO_AXIS        2\r\n\t\t#define GIZMO_WIRE_CUBE   3\r\n\t\t#define GIZMO_WIRE_SPHERE 4\r\n\t\t#define GIZMO_CANVAS\t  10\r\n\t\t\r\n\t\t\r\n\t\t\r\n\t\t\t\tmat4         WorldMatrix;\r\n\t\tuniform mat4  \t\t ViewMatrix;\r\n\t\tuniform mat4  \t\t ProjectionMatrix;\t\t\t\t\r\n\t\tuniform int   \t\t Count;\r\n\t\tuniform int   \t\t Type;\t\t\r\n\t\tuniform sampler2D \t Data;\r\n\t\tuniform int  \t\t DataSize;\t\t\r\n\t\t\t    vec4\t\t DataColor;\r\n\t\t\t\tvec4\t\t DataA;\r\n\t\t\t\tvec4\t\t DataB;\r\n\t\t\r\n\t\tattribute float id;\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\r\n\t\t\r\n\t\tvarying vec4 v_color;\r\n\t\t\r\n\t\tvec4 GetPixel(float p_pix,float p_ds,float p_ids)\r\n\t\t{\t\t\t\r\n\t\t\tfloat px = mod(p_pix, p_ds) * p_ids;\r\n\t\t\tfloat py = (p_pix * p_ids) * p_ids;\r\n\t\t\treturn texture2D(Data, vec2(px,py));\r\n\t\t}\r\n\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\t\t\r\n\t\t\tif (id >= float(Count)) \r\n\t\t\t{\r\n\t\t\t\tgl_Position = vec4( -2.0, 0.0, 0.0, 0.0);\r\n\t\t\t\treturn; \r\n\t\t\t}\t\t\t\r\n\t\t\tfloat p  \t= id * 6.0;\r\n\t\t\tfloat ds\t= float(DataSize);\r\n\t\t\tfloat ids\t= 1.0 / ds;\t\t\t\r\n\t\t\tDataColor \t= GetPixel(p,ds,ids);\r\n\t\t\tDataA \t\t= GetPixel(p + 1.0,ds,ids);\r\n\t\t\tDataB \t\t= GetPixel(p + 2.0,ds,ids);\t\t\t\r\n\t\t\tvec4 l0 \t= GetPixel(p + 3.0,ds,ids);\r\n\t\t\tvec4 l1 \t= GetPixel(p + 4.0,ds,ids);\r\n\t\t\tvec4 l2 \t= GetPixel(p + 5.0,ds,ids);\t\r\n\t\t\tvec4 v\t\t= vec4(vertex, 1.0);\r\n\t\t\tWorldMatrix = mat4(l0.x, l0.y, l0.z, l0.w, l1.x, l1.y, l1.z, l1.w, l2.x, l2.y, l2.z, l2.w, 0, 0, 0, 1);\r\n\t\t\t\r\n\t\t\tif (Type == GIZMO_POINT)\r\n\t\t\t{\t\r\n\t\t\t\tvec4 ncp = ((vec4(DataB.xyz, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\t\tv.xyz += DataB.xyz;\r\n\t\t\t\tfloat pf = (ncp.z / ncp.w);\r\n\t\t\t\tgl_PointSize = pf <= 0.0 ? DataA.x : (DataA.x * pf);\r\n\t\t\t\tgl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\t}\r\n\t\t\telse\r\n\t\t\tif (Type == GIZMO_LINE)\r\n\t\t\t{\r\n\t\t\t\tfloat r = v.x;\r\n\t\t\t\tv.xyz = DataA.xyz + (DataB.xyz - DataA.xyz) * r;\r\n\t\t\t\tgl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\t}\r\n\t\t\telse\r\n\t\t\tif (Type == GIZMO_AXIS)\r\n\t\t\t{\t\t\r\n\t\t\t\tfloat sx   = length(vec3(WorldMatrix[0][0],WorldMatrix[1][0],WorldMatrix[2][0]));\r\n\t\t\t\tfloat sy   = length(vec3(WorldMatrix[0][1],WorldMatrix[1][1],WorldMatrix[2][1]));\r\n\t\t\t\tfloat sz   = length(vec3(WorldMatrix[0][2],WorldMatrix[1][2],WorldMatrix[2][2]));\t\t\t\t\r\n\t\t\t\tvec3 scale = vec3(sx, sy, sz);\t\t\t\t\r\n\t\t\t\tvec4 ncp = ((vec4(DataB.xyz, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\t\tv.xyz *= (DataA.xyz / scale.xyz) * ncp.w * 0.025;\r\n\t\t\t\tv.xyz += DataB.xyz;\r\n\t\t\t\tgl_Position  = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\t}\r\n\t\t\telse\r\n\t\t\tif (Type == GIZMO_WIRE_CUBE)\r\n\t\t\t{\r\n\t\t\t\tv.xyz *= DataA.xyz;\r\n\t\t\t\tv.xyz += DataB.xyz;\r\n\t\t\t\tgl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\t}\r\n\t\t\telse\r\n\t\t\tif (Type == GIZMO_WIRE_SPHERE)\r\n\t\t\t{\r\n\t\t\t\tv.xyz *= DataA.x;\r\n\t\t\t\tv.xyz += DataB.xyz;\r\n\t\t\t\tgl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\t}\r\n\t\t\telse\r\n\t\t\tif (Type == GIZMO_CANVAS)\r\n\t\t\t{\t\t\t\t\r\n\t\t\t\tv.xyz += DataB.xyz;\r\n\t\t\t\tgl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\t\t\t\t\t\r\n\t\t\tv_color = DataColor * color;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) { gl_FragColor = v_color; }\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t");
	flat_particle_source= HX_CSTRING("\r\n\t<shader id=\"haxor/unlit/Particle\">\t\r\n\r\n\t\t<vertex precision=\"low\">\r\n\t\t\r\n\t\t#define IsLocal\t\t\t\t (System[1].z > 0.0)\r\n\t\t#define SheetFrameWidth\t \t System[21].x\r\n\t\t#define SheetFrameHeight \t System[21].y\r\n\t\t#define SheetLength\t\t \t System[22].x\r\n\t\t#define SystemEmissionStart\t System[24].x\r\n\t\t#define SystemEmissionCount\t System[24].y\r\n\t\t\r\n\t\t#define PARTICLE_LENGTH\t\t 7.0\r\n\t\t\r\n\t\t#define PARTICLE_STATUS\t\t 0.0\r\n\t\t#define PARTICLE_POSITION\t 1.0\r\n\t\t#define PARTICLE_ROTATION\t 2.0\r\n\t\t#define PARTICLE_SIZE\t\t 3.0\r\n\t\t#define PARTICLE_VELOCITY\t 4.0\r\n\t\t#define PARTICLE_COLOR\t\t 5.0\r\n\t\t#define PARTICLE_START\t\t 6.0\r\n\t\t\r\n\t\t#define PARTICLE_DISABLED\t 0\r\n\t\t#define PARTICLE_INIT\t\t 1\r\n\t\t#define PARTICLE_ENABLED\t 2\r\n\t\t#define PARTICLE_DEAD\t\t 3\r\n\t\t\r\n\t\tattribute vec3 vertex;\r\n\t\t\t\t\r\n\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ViewMatrixInverse;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\t\r\n\t\tuniform float Time;\r\n\t\t\r\n\t\tuniform sampler2D Data;\r\n\t\t\r\n\t\tuniform float DataWidth;\r\n\t\tuniform float DataHeight;\r\n\t\t\r\n\t\t\r\n\t\tuniform float TextureWidth;\r\n\t\tuniform float TextureHeight;\r\n\t\t\r\n\t\tuniform vec4  System[25];\r\n\t\t\t\t\r\n\t\t\r\n\t\tvarying vec2 v_uv0;\r\n\t\tvarying vec4 v_color;\r\n\t\t\r\n\t\t\r\n\t\tuniform float RandomSeed;\t\t\r\n\t\tuniform sampler2D RandomTexture;\r\n\t\t\r\n\t\tvec4 Random()\r\n\t\t\t{\r\n\t\t\t\tfloat tw   = 0.001953125;\r\n\t\t\t\tfloat seed = RandomSeed * 262144.0;\r\n\t\t\t\tfloat idx  = mod(seed,512.0) * tw;\r\n\t\t\t\tfloat idy  = floor(seed * tw)  * tw;\r\n\t\t\t\tseed      += tw;\r\n\t\t\t\treturn texture2D(RandomTexture, vec2(idx,idy));\r\n\t\t\t}\r\n\t\t//*/\r\n\t\tvec4 ParticleData(float p_id,float p_field)\r\n\t\t{\r\n\t\t\tfloat w   = floor(DataWidth);\r\n\t\t\tfloat h   = floor(DataHeight);\r\n\t\t\tfloat pid = mod(floor(SystemEmissionStart)+p_id,floor(w*h)/PARTICLE_LENGTH);\r\n\t\t\tfloat pix = floor(pid) * PARTICLE_LENGTH;\t\t\t\r\n\t\t\tfloat px  = mod(pix+p_field,w) / (w-1.0);\r\n\t\t\tfloat py  = floor((pix+p_field)/w) / (h-1.0);\r\n\t\t\treturn texture2D(Data,vec2(px,py));\r\n\t\t}\r\n\t\t\r\n\t\tvec4 ParticleStatus()   { return ParticleData(vertex.z,PARTICLE_STATUS); \t}\r\n\t\tvec4 ParticlePosition() { return ParticleData(vertex.z,PARTICLE_POSITION); \t}\r\n\t\tvec4 ParticleRotation() { return ParticleData(vertex.z,PARTICLE_ROTATION); \t}\r\n\t\tvec4 ParticleSize() \t{ return ParticleData(vertex.z,PARTICLE_SIZE); \t\t}\r\n\t\tvec4 ParticleColor() \t{ return ParticleData(vertex.z,PARTICLE_COLOR); \t\t}\r\n\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\t\r\n\t\t\tvec4  status   = ParticleStatus();\r\n\t\t\t\r\n\t\t\tfloat enabled  = int(status.x) == PARTICLE_DEAD ? 0.0 : 1.0;\r\n\t\t\t\r\n\t\t\tvec4  v   = vec4(vertex.xy,0.0,1.0);\r\n\t\t\tv.xyz\t *= enabled;\r\n\t\t\t\r\n\t\t\tif(enabled <= 0.0) { gl_Position = vec4(0,0,0,-1.0); return; }\r\n\t\t\t\r\n\t\t\tvec3 size\t   = ParticleSize().xyz;\t\t\t\r\n\t\t\tvec3 center    = vec3(0,0,0);\r\n\t\t\tvec3 position  = ParticlePosition().xyz;\r\n\t\t\t\t\t\t\r\n\t\t\tv.xyz  *= size;\r\n\t\t\tv.xyz   = v.xyz * mat3(ViewMatrixInverse); //billboard\r\n\t\t\t\r\n\t\t\tv.xyz  += center + position;\r\n\t\t\t\r\n\t\t\tmat4 wm     = IsLocal ? WorldMatrix : mat4(1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1); \r\n\t\t\t\r\n\t\t\tgl_Position = ((v * wm) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\t\r\n\t\t\tfloat frame   = floor(status.w);\t\t\r\n\t\t\t\r\n\t\t\tv_uv0 = (vertex.xy+0.5);\r\n\t\t\t\r\n\t\t\tif(SheetLength > 0.0)\r\n\t\t\t{\t\t\t\r\n\t\t\t\tfloat sw\t  = (SheetFrameWidth);\r\n\t\t\t\tfloat sh\t  = (SheetFrameHeight);\t\t\t\r\n\t\t\t\tfloat tw\t  = floor(TextureWidth);\r\n\t\t\t\tfloat th\t  = floor(TextureHeight);\r\n\t\t\t\tfloat sheet_uvw = sw/tw;\r\n\t\t\t\tfloat sheet_uvh = sh/th;\r\n\t\t\t\tv_uv0   \t*= vec2(sheet_uvw,sheet_uvh);\t\t\t\t\t\r\n\t\t\t\tfloat cx     = floor(TextureWidth/SheetFrameWidth);\r\n\t\t\t\tv_uv0.x\t\t += (mod(frame,cx) * (sheet_uvw));\r\n\t\t\t\tv_uv0.y\t\t += 1.0 - (sheet_uvh) - (floor(frame/cx) * (sheet_uvh));\r\n\t\t\t}\t\t\t\r\n\t\t\t\r\n\t\t\tv_color = ParticleColor();\r\n\t\t}\t\t\r\n\t\t</vertex>\r\n\t\t\r\n\t\t<fragment precision=\"low\">\r\n\t\t\t\r\n\t\t\t\r\n\t\t\tvarying vec2 v_uv0;\r\n\t\t\tvarying vec4 v_color;\r\n\t\t\t\r\n\t\t\tuniform sampler2D Color;\r\n\t\t\t\r\n\t\t\tuniform sampler2D Texture;\r\n\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex\t\t = texture2D(Texture, v_uv0.xy);\r\n\t\t\t\tgl_FragColor.xyz = tex.xyz * v_color.xyz;\r\n\t\t\t\tgl_FragColor.a \t = tex.a * v_color.a;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t");
}

} // end namespace haxor
} // end namespace context
