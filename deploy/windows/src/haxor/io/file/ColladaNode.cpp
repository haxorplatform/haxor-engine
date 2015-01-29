#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaInstance
#include <haxor/io/file/ColladaInstance.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaNode
#include <haxor/io/file/ColladaNode.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaVisualScene
#include <haxor/io/file/ColladaVisualScene.h>
#endif
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Quaternion
#include <haxor/math/Quaternion.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaNode_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaNode","new",0xa111d4d0,"haxor.io.file.ColladaNode.new","haxor/io/file/ColladaFile.hx",1396,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1438)
	this->instances = null();
	HX_STACK_LINE(1411)
	this->local = null();
	HX_STACK_LINE(1409)
	this->data = HX_CSTRING("");
	HX_STACK_LINE(1407)
	this->children = null();
	HX_STACK_LINE(1406)
	this->parent = null();
	HX_STACK_LINE(1405)
	this->scene = null();
	HX_STACK_LINE(1403)
	this->matrix = null();
	HX_STACK_LINE(1401)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(1400)
	this->sid = HX_CSTRING("");
	HX_STACK_LINE(1399)
	this->id = HX_CSTRING("");
	HX_STACK_LINE(1398)
	this->type = HX_CSTRING("");
	HX_STACK_LINE(1442)
	this->children = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(1443)
	this->instances = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(1444)
	this->matrix = Array_obj< Float >::__new().Add((int)1).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1);
	HX_STACK_LINE(1445)
	::haxor::math::Vector3 _g = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1445)
	this->position = _g;
	HX_STACK_LINE(1446)
	::haxor::math::Quaternion _g1 = ::haxor::math::Quaternion_obj::__new((int)0,(int)0,(int)0,1.0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(1446)
	this->rotation = _g1;
	HX_STACK_LINE(1447)
	::haxor::math::Vector3 _g2 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(1447)
	this->scale = _g2;
}
;
	return null();
}

//ColladaNode_obj::~ColladaNode_obj() { }

Dynamic ColladaNode_obj::__CreateEmpty() { return  new ColladaNode_obj; }
hx::ObjectPtr< ColladaNode_obj > ColladaNode_obj::__new()
{  hx::ObjectPtr< ColladaNode_obj > result = new ColladaNode_obj();
	result->__construct();
	return result;}

Dynamic ColladaNode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaNode_obj > result = new ColladaNode_obj();
	result->__construct();
	return result;}

::haxor::math::Matrix4 ColladaNode_obj::get_world( ){
	HX_STACK_FRAME("haxor.io.file.ColladaNode","get_world",0x5c8aeb19,"haxor.io.file.ColladaNode.get_world","haxor/io/file/ColladaFile.hx",1415,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1416)
	if (((this->m_world != null()))){
		HX_STACK_LINE(1416)
		return this->m_world;
	}
	HX_STACK_LINE(1417)
	::haxor::math::Matrix4 _g = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1417)
	this->m_world = _g;
	HX_STACK_LINE(1418)
	::haxor::io::file::ColladaNode it = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(1419)
	Array< ::Dynamic > h = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(1420)
	while((true)){
		HX_STACK_LINE(1420)
		if ((!(((it != null()))))){
			HX_STACK_LINE(1420)
			break;
		}
		HX_STACK_LINE(1422)
		h->push(it);
		HX_STACK_LINE(1423)
		it = it->parent;
	}
	HX_STACK_LINE(1425)
	h->reverse();
	HX_STACK_LINE(1426)
	{
		HX_STACK_LINE(1426)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1426)
		int _g2 = h->length;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(1426)
		while((true)){
			HX_STACK_LINE(1426)
			if ((!(((_g1 < _g2))))){
				HX_STACK_LINE(1426)
				break;
			}
			HX_STACK_LINE(1426)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1428)
			this->m_world->MultiplyTransform(h->__get(i).StaticCast< ::haxor::io::file::ColladaNode >()->local);
		}
	}
	HX_STACK_LINE(1430)
	return this->m_world;
}


HX_DEFINE_DYNAMIC_FUNC0(ColladaNode_obj,get_world,return )

Void ColladaNode_obj::GenerateTranform( ){
{
		HX_STACK_FRAME("haxor.io.file.ColladaNode","GenerateTranform",0x74c172b4,"haxor.io.file.ColladaNode.GenerateTranform","haxor/io/file/ColladaFile.hx",1451,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_LINE(1452)
		::haxor::math::Matrix4 _g = ::haxor::math::Matrix4_obj::FromArray(this->matrix,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1452)
		::haxor::math::Matrix4 mtx = this->local = _g;		HX_STACK_VAR(mtx,"mtx");
		HX_STACK_LINE(1453)
		::haxor::math::Vector3 _g6;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(1453)
		{
			HX_STACK_LINE(1453)
			::haxor::math::Vector4 _this;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(1453)
			{
				HX_STACK_LINE(1453)
				::haxor::math::Matrix4 _this1 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,mtx->m03,(int)0,(int)1,(int)0,mtx->m13,(int)0,(int)0,(int)1,mtx->m23,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_this1,"_this1");
				HX_STACK_LINE(1453)
				::haxor::math::Vector4 p_result = null();		HX_STACK_VAR(p_result,"p_result");
				HX_STACK_LINE(1453)
				::haxor::math::Vector4 _g1;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(1453)
				if (((p_result == null()))){
					HX_STACK_LINE(1453)
					_g1 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());
				}
				else{
					HX_STACK_LINE(1453)
					_g1 = p_result;
				}
				HX_STACK_LINE(1453)
				p_result = _g1;
				HX_STACK_LINE(1453)
				Float _g2 = _this1->GetRowCol((int)0,(int)3);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(1453)
				Float _g3 = _this1->GetRowCol((int)1,(int)3);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(1453)
				Float _g4 = _this1->GetRowCol((int)2,(int)3);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(1453)
				Float _g5 = _this1->GetRowCol((int)3,(int)3);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(1453)
				_this = p_result->Set(_g2,_g3,_g4,_g5);
			}
			HX_STACK_LINE(1453)
			_g6 = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
		}
		HX_STACK_LINE(1453)
		this->position = _g6;
		struct _Function_1_1{
			inline static ::haxor::math::Matrix4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/io/file/ColladaFile.hx",1454,0xa1888587)
				{
					HX_STACK_LINE(1454)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(1454)
					int _g7 = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(1454)
					return _this->m_m4->__get(_g7).StaticCast< ::haxor::math::Matrix4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(1454)
		::haxor::math::Matrix4 _g8 = (_Function_1_1::Block())->SetMatrix4(mtx)->ToRotation();		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(1454)
		::haxor::math::Quaternion _g9 = ::haxor::math::Quaternion_obj::FromMatrix4(_g8,null());		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(1454)
		this->rotation = _g9;
		HX_STACK_LINE(1455)
		::haxor::math::Vector3 _g10;		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(1455)
		{
			HX_STACK_LINE(1455)
			::haxor::math::Vector4 _this;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(1455)
			{
				HX_STACK_LINE(1455)
				::haxor::math::Matrix4 _this1;		HX_STACK_VAR(_this1,"_this1");
				HX_STACK_LINE(1455)
				{
					HX_STACK_LINE(1455)
					Float d0 = ::Math_obj::sqrt((((mtx->m00 * mtx->m00) + (mtx->m10 * mtx->m10)) + (mtx->m20 * mtx->m20)));		HX_STACK_VAR(d0,"d0");
					HX_STACK_LINE(1455)
					Float d1 = ::Math_obj::sqrt((((mtx->m01 * mtx->m01) + (mtx->m11 * mtx->m11)) + (mtx->m21 * mtx->m21)));		HX_STACK_VAR(d1,"d1");
					HX_STACK_LINE(1455)
					Float d2 = ::Math_obj::sqrt((((mtx->m02 * mtx->m02) + (mtx->m12 * mtx->m12)) + (mtx->m22 * mtx->m22)));		HX_STACK_VAR(d2,"d2");
					HX_STACK_LINE(1455)
					_this1 = ::haxor::math::Matrix4_obj::__new(d0,(int)0,(int)0,(int)0,(int)0,d1,(int)0,(int)0,(int)0,(int)0,d2,(int)0,(int)0,(int)0,(int)0,(int)1);
				}
				HX_STACK_LINE(1455)
				_this = ::haxor::math::Vector4_obj::__new(_this1->m00,_this1->m11,_this1->m22,_this1->m33);
			}
			HX_STACK_LINE(1455)
			_g10 = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
		}
		HX_STACK_LINE(1455)
		this->scale = _g10;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ColladaNode_obj,GenerateTranform,(void))


ColladaNode_obj::ColladaNode_obj()
{
}

void ColladaNode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaNode);
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(sid,"sid");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(matrix,"matrix");
	HX_MARK_MEMBER_NAME(scene,"scene");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(children,"children");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(local,"local");
	HX_MARK_MEMBER_NAME(m_world,"m_world");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(instances,"instances");
	HX_MARK_END_CLASS();
}

void ColladaNode_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(sid,"sid");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(matrix,"matrix");
	HX_VISIT_MEMBER_NAME(scene,"scene");
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(children,"children");
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(local,"local");
	HX_VISIT_MEMBER_NAME(m_world,"m_world");
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
	HX_VISIT_MEMBER_NAME(scale,"scale");
	HX_VISIT_MEMBER_NAME(instances,"instances");
}

Dynamic ColladaNode_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"sid") ) { return sid; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scene") ) { return scene; }
		if (HX_FIELD_EQ(inName,"local") ) { return local; }
		if (HX_FIELD_EQ(inName,"world") ) { return get_world(); }
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"matrix") ) { return matrix; }
		if (HX_FIELD_EQ(inName,"parent") ) { return parent; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_world") ) { return m_world; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"children") ) { return children; }
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		if (HX_FIELD_EQ(inName,"rotation") ) { return rotation; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_world") ) { return get_world_dyn(); }
		if (HX_FIELD_EQ(inName,"instances") ) { return instances; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"GenerateTranform") ) { return GenerateTranform_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaNode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"sid") ) { sid=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scene") ) { scene=inValue.Cast< ::haxor::io::file::ColladaVisualScene >(); return inValue; }
		if (HX_FIELD_EQ(inName,"local") ) { local=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"matrix") ) { matrix=inValue.Cast< Array< Float > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::haxor::io::file::ColladaNode >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_world") ) { m_world=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"children") ) { children=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"instances") ) { instances=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaNode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("sid"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("matrix"));
	outFields->push(HX_CSTRING("scene"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("children"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("local"));
	outFields->push(HX_CSTRING("world"));
	outFields->push(HX_CSTRING("m_world"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("instances"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaNode_obj,type),HX_CSTRING("type")},
	{hx::fsString,(int)offsetof(ColladaNode_obj,id),HX_CSTRING("id")},
	{hx::fsString,(int)offsetof(ColladaNode_obj,sid),HX_CSTRING("sid")},
	{hx::fsString,(int)offsetof(ColladaNode_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(ColladaNode_obj,matrix),HX_CSTRING("matrix")},
	{hx::fsObject /*::haxor::io::file::ColladaVisualScene*/ ,(int)offsetof(ColladaNode_obj,scene),HX_CSTRING("scene")},
	{hx::fsObject /*::haxor::io::file::ColladaNode*/ ,(int)offsetof(ColladaNode_obj,parent),HX_CSTRING("parent")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaNode_obj,children),HX_CSTRING("children")},
	{hx::fsString,(int)offsetof(ColladaNode_obj,data),HX_CSTRING("data")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(ColladaNode_obj,local),HX_CSTRING("local")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(ColladaNode_obj,m_world),HX_CSTRING("m_world")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(ColladaNode_obj,position),HX_CSTRING("position")},
	{hx::fsObject /*::haxor::math::Quaternion*/ ,(int)offsetof(ColladaNode_obj,rotation),HX_CSTRING("rotation")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(ColladaNode_obj,scale),HX_CSTRING("scale")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaNode_obj,instances),HX_CSTRING("instances")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("type"),
	HX_CSTRING("id"),
	HX_CSTRING("sid"),
	HX_CSTRING("name"),
	HX_CSTRING("matrix"),
	HX_CSTRING("scene"),
	HX_CSTRING("parent"),
	HX_CSTRING("children"),
	HX_CSTRING("data"),
	HX_CSTRING("local"),
	HX_CSTRING("get_world"),
	HX_CSTRING("m_world"),
	HX_CSTRING("position"),
	HX_CSTRING("rotation"),
	HX_CSTRING("scale"),
	HX_CSTRING("instances"),
	HX_CSTRING("GenerateTranform"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaNode_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaNode_obj::__mClass,"__mClass");
};

#endif

Class ColladaNode_obj::__mClass;

void ColladaNode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaNode"), hx::TCanCast< ColladaNode_obj> ,sStaticFields,sMemberFields,
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

void ColladaNode_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
