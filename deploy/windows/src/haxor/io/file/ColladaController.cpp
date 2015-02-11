#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_ColladaController
#include <haxor/io/file/ColladaController.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaInput
#include <haxor/io/file/ColladaInput.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaPrimitive
#include <haxor/io/file/ColladaPrimitive.h>
#endif
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
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

Void ColladaController_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaController","new",0x66ccc56a,"haxor.io.file.ColladaController.new","haxor/io/file/ColladaFile.hx",1253,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1268)
	this->bones = null();
	HX_STACK_LINE(1266)
	this->weights = null();
	HX_STACK_LINE(1264)
	this->indexes = null();
	HX_STACK_LINE(1263)
	this->vcount = null();
	HX_STACK_LINE(1262)
	this->inputs = null();
	HX_STACK_LINE(1261)
	this->joints = null();
	HX_STACK_LINE(1260)
	this->binds = null();
	HX_STACK_LINE(1259)
	this->matrix = null();
	HX_STACK_LINE(1258)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(1257)
	this->id = HX_CSTRING("");
	HX_STACK_LINE(1256)
	this->source = HX_CSTRING("");
	HX_STACK_LINE(1255)
	this->type = HX_CSTRING("");
	HX_STACK_LINE(1275)
	this->matrix = Array_obj< Float >::__new();
	HX_STACK_LINE(1276)
	this->binds = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(1277)
	this->inputs = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(1278)
	this->joints = Array_obj< ::String >::__new();
	HX_STACK_LINE(1279)
	this->vcount = Array_obj< int >::__new();
	HX_STACK_LINE(1280)
	this->indexes = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

//ColladaController_obj::~ColladaController_obj() { }

Dynamic ColladaController_obj::__CreateEmpty() { return  new ColladaController_obj; }
hx::ObjectPtr< ColladaController_obj > ColladaController_obj::__new()
{  hx::ObjectPtr< ColladaController_obj > result = new ColladaController_obj();
	result->__construct();
	return result;}

Dynamic ColladaController_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaController_obj > result = new ColladaController_obj();
	result->__construct();
	return result;}

int ColladaController_obj::get_offset( ){
	HX_STACK_FRAME("haxor.io.file.ColladaController","get_offset",0xac7f2792,"haxor.io.file.ColladaController.get_offset","haxor/io/file/ColladaFile.hx",1271,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1271)
	int mo = (int)0;		HX_STACK_VAR(mo,"mo");
	HX_STACK_LINE(1271)
	{
		HX_STACK_LINE(1271)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1271)
		int _g = this->inputs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1271)
		while((true)){
			HX_STACK_LINE(1271)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1271)
				break;
			}
			HX_STACK_LINE(1271)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1271)
			int _g2 = ::Math_obj::max(mo,(this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->offset + (int)1));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1271)
			mo = _g2;
		}
	}
	HX_STACK_LINE(1271)
	return mo;
}


HX_DEFINE_DYNAMIC_FUNC0(ColladaController_obj,get_offset,return )

::haxor::math::Matrix4 ColladaController_obj::GetBSM( ){
	HX_STACK_FRAME("haxor.io.file.ColladaController","GetBSM",0xc4189fdc,"haxor.io.file.ColladaController.GetBSM","haxor/io/file/ColladaFile.hx",1284,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1285)
	::haxor::math::Matrix4 mtx = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(mtx,"mtx");
	HX_STACK_LINE(1287)
	{
		HX_STACK_LINE(1287)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1287)
		int _g = this->matrix->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1287)
		while((true)){
			HX_STACK_LINE(1287)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1287)
				break;
			}
			HX_STACK_LINE(1287)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1287)
			mtx->SetIndex(i,this->matrix->__get(i));
		}
	}
	HX_STACK_LINE(1288)
	return mtx;
}


HX_DEFINE_DYNAMIC_FUNC0(ColladaController_obj,GetBSM,return )

int ColladaController_obj::GetJointIndex( ::String p_joint){
	HX_STACK_FRAME("haxor.io.file.ColladaController","GetJointIndex",0xd243f708,"haxor.io.file.ColladaController.GetJointIndex","haxor/io/file/ColladaFile.hx",1292,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_joint,"p_joint")
	HX_STACK_LINE(1293)
	{
		HX_STACK_LINE(1293)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1293)
		int _g = this->joints->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1293)
		while((true)){
			HX_STACK_LINE(1293)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1293)
				break;
			}
			HX_STACK_LINE(1293)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1293)
			if (((p_joint == this->joints->__get(i)))){
				HX_STACK_LINE(1293)
				return i;
			}
		}
	}
	HX_STACK_LINE(1294)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaController_obj,GetJointIndex,return )

Array< ::Dynamic > ColladaController_obj::GetBinds( ){
	HX_STACK_FRAME("haxor.io.file.ColladaController","GetBinds",0x82096276,"haxor.io.file.ColladaController.GetBinds","haxor/io/file/ColladaFile.hx",1298,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1299)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(1300)
	{
		HX_STACK_LINE(1300)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1300)
		int _g = this->binds->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1300)
		while((true)){
			HX_STACK_LINE(1300)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1300)
				break;
			}
			HX_STACK_LINE(1300)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1302)
			::haxor::math::Matrix4 mtx = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(mtx,"mtx");
			HX_STACK_LINE(1304)
			{
				HX_STACK_LINE(1304)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(1304)
				int _g2 = this->binds->__get(i).StaticCast< Array< Float > >()->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(1304)
				while((true)){
					HX_STACK_LINE(1304)
					if ((!(((_g3 < _g2))))){
						HX_STACK_LINE(1304)
						break;
					}
					HX_STACK_LINE(1304)
					int j = (_g3)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(1304)
					mtx->SetIndex(j,this->binds->__get(i).StaticCast< Array< Float > >()->__get(j));
				}
			}
			HX_STACK_LINE(1305)
			res->push(mtx);
		}
	}
	HX_STACK_LINE(1307)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC0(ColladaController_obj,GetBinds,return )

Array< ::Dynamic > ColladaController_obj::GetTriangulatedWeights( ::haxor::io::file::ColladaPrimitive cp){
	HX_STACK_FRAME("haxor.io.file.ColladaController","GetTriangulatedWeights",0x87dbbf83,"haxor.io.file.ColladaController.GetTriangulatedWeights","haxor/io/file/ColladaFile.hx",1311,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cp,"cp")
	HX_STACK_LINE(1312)
	int v_off = cp->GetInput(HX_CSTRING("vertex"),null())->offset;		HX_STACK_VAR(v_off,"v_off");
	HX_STACK_LINE(1313)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(1314)
	{
		HX_STACK_LINE(1314)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1314)
		int _g = cp->get_triangles()->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1314)
		while((true)){
			HX_STACK_LINE(1314)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1314)
				break;
			}
			HX_STACK_LINE(1314)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1316)
			Array< ::Dynamic > _g2 = cp->get_triangles();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1316)
			Array< int > _g11 = _g2->__get(i).StaticCast< Array< int > >();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(1316)
			int idx = _g11->__get(v_off);		HX_STACK_VAR(idx,"idx");
			HX_STACK_LINE(1317)
			res->push(this->weights->__get(idx).StaticCast< ::haxor::math::Vector4 >());
		}
	}
	HX_STACK_LINE(1319)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaController_obj,GetTriangulatedWeights,return )

Array< ::Dynamic > ColladaController_obj::GetTriangulatedBones( ::haxor::io::file::ColladaPrimitive cp){
	HX_STACK_FRAME("haxor.io.file.ColladaController","GetTriangulatedBones",0x69a7ce37,"haxor.io.file.ColladaController.GetTriangulatedBones","haxor/io/file/ColladaFile.hx",1323,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cp,"cp")
	HX_STACK_LINE(1324)
	int v_off = cp->GetInput(HX_CSTRING("vertex"),null())->offset;		HX_STACK_VAR(v_off,"v_off");
	HX_STACK_LINE(1325)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(1326)
	{
		HX_STACK_LINE(1326)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1326)
		int _g = cp->get_triangles()->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1326)
		while((true)){
			HX_STACK_LINE(1326)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1326)
				break;
			}
			HX_STACK_LINE(1326)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1328)
			Array< ::Dynamic > _g2 = cp->get_triangles();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1328)
			Array< int > _g11 = _g2->__get(i).StaticCast< Array< int > >();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(1328)
			int idx = _g11->__get(v_off);		HX_STACK_VAR(idx,"idx");
			HX_STACK_LINE(1329)
			res->push(this->bones->__get(idx).StaticCast< ::haxor::math::Vector4 >());
		}
	}
	HX_STACK_LINE(1331)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaController_obj,GetTriangulatedBones,return )

Void ColladaController_obj::GenerateBonesAndWeights( ){
{
		HX_STACK_FRAME("haxor.io.file.ColladaController","GenerateBonesAndWeights",0x799635a8,"haxor.io.file.ColladaController.GenerateBonesAndWeights","haxor/io/file/ColladaFile.hx",1335,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_LINE(1336)
		this->weights = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(1337)
		this->bones = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(1339)
		int off = this->get_offset();		HX_STACK_VAR(off,"off");
		HX_STACK_LINE(1340)
		::haxor::io::file::ColladaInput wi = null();		HX_STACK_VAR(wi,"wi");
		HX_STACK_LINE(1341)
		int wo = (int)0;		HX_STACK_VAR(wo,"wo");
		HX_STACK_LINE(1342)
		int bo = (int)0;		HX_STACK_VAR(bo,"bo");
		HX_STACK_LINE(1344)
		{
			HX_STACK_LINE(1344)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1344)
			int _g = this->inputs->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1344)
			while((true)){
				HX_STACK_LINE(1344)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1344)
					break;
				}
				HX_STACK_LINE(1344)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1346)
				if (((this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->semantic == HX_CSTRING("weight")))){
					HX_STACK_LINE(1346)
					wi = this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >();
					HX_STACK_LINE(1346)
					wo = wi->offset;
				}
				HX_STACK_LINE(1347)
				if (((this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->semantic == HX_CSTRING("joint")))){
					HX_STACK_LINE(1347)
					bo = this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->offset;
				}
			}
		}
		HX_STACK_LINE(1350)
		int k = (int)0;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(1351)
		{
			HX_STACK_LINE(1351)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1351)
			int _g = this->vcount->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1351)
			while((true)){
				HX_STACK_LINE(1351)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1351)
					break;
				}
				HX_STACK_LINE(1351)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1353)
				int n = this->vcount->__get(i);		HX_STACK_VAR(n,"n");
				HX_STACK_LINE(1354)
				::haxor::math::Vector4 wv4 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(wv4,"wv4");
				HX_STACK_LINE(1355)
				::haxor::math::Vector4 bv4 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(bv4,"bv4");
				HX_STACK_LINE(1356)
				{
					HX_STACK_LINE(1356)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(1356)
					while((true)){
						HX_STACK_LINE(1356)
						if ((!(((_g2 < n))))){
							HX_STACK_LINE(1356)
							break;
						}
						HX_STACK_LINE(1356)
						int j = (_g2)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(1358)
						int bi = this->indexes->__get(k).StaticCast< Array< int > >()->__get(bo);		HX_STACK_VAR(bi,"bi");
						HX_STACK_LINE(1359)
						Float wv = wi->values->__GetItem(this->indexes->__get(k).StaticCast< Array< int > >()->__get(wo));		HX_STACK_VAR(wv,"wv");
						HX_STACK_LINE(1361)
						if (((j == (int)0))){
							HX_STACK_LINE(1361)
							wv4->x = wv;
							HX_STACK_LINE(1361)
							bv4->x = bi;
						}
						else{
							HX_STACK_LINE(1362)
							if (((j == (int)1))){
								HX_STACK_LINE(1362)
								wv4->y = wv;
								HX_STACK_LINE(1362)
								bv4->y = bi;
							}
							else{
								HX_STACK_LINE(1363)
								if (((j == (int)2))){
									HX_STACK_LINE(1363)
									wv4->z = wv;
									HX_STACK_LINE(1363)
									bv4->z = bi;
								}
								else{
									HX_STACK_LINE(1364)
									if (((j == (int)3))){
										HX_STACK_LINE(1364)
										wv4->w = wv;
										HX_STACK_LINE(1364)
										bv4->w = bi;
									}
								}
							}
						}
						HX_STACK_LINE(1365)
						(k)++;
					}
				}
				HX_STACK_LINE(1368)
				Float sum = (((wv4->x + wv4->y) + wv4->z) + wv4->w);		HX_STACK_VAR(sum,"sum");
				HX_STACK_LINE(1369)
				if (((sum <= (int)0))){
					HX_STACK_LINE(1369)
					sum = 0.0;
				}
				else{
					HX_STACK_LINE(1369)
					sum = (Float(1.0) / Float(sum));
				}
				HX_STACK_LINE(1370)
				wv4->Scale(sum);
				HX_STACK_LINE(1371)
				this->weights->push(wv4);
				HX_STACK_LINE(1373)
				this->bones->push(bv4);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ColladaController_obj,GenerateBonesAndWeights,(void))


ColladaController_obj::ColladaController_obj()
{
}

void ColladaController_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaController);
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(source,"source");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(matrix,"matrix");
	HX_MARK_MEMBER_NAME(binds,"binds");
	HX_MARK_MEMBER_NAME(joints,"joints");
	HX_MARK_MEMBER_NAME(inputs,"inputs");
	HX_MARK_MEMBER_NAME(vcount,"vcount");
	HX_MARK_MEMBER_NAME(indexes,"indexes");
	HX_MARK_MEMBER_NAME(weights,"weights");
	HX_MARK_MEMBER_NAME(bones,"bones");
	HX_MARK_END_CLASS();
}

void ColladaController_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(source,"source");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(matrix,"matrix");
	HX_VISIT_MEMBER_NAME(binds,"binds");
	HX_VISIT_MEMBER_NAME(joints,"joints");
	HX_VISIT_MEMBER_NAME(inputs,"inputs");
	HX_VISIT_MEMBER_NAME(vcount,"vcount");
	HX_VISIT_MEMBER_NAME(indexes,"indexes");
	HX_VISIT_MEMBER_NAME(weights,"weights");
	HX_VISIT_MEMBER_NAME(bones,"bones");
}

Dynamic ColladaController_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"binds") ) { return binds; }
		if (HX_FIELD_EQ(inName,"bones") ) { return bones; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"source") ) { return source; }
		if (HX_FIELD_EQ(inName,"matrix") ) { return matrix; }
		if (HX_FIELD_EQ(inName,"joints") ) { return joints; }
		if (HX_FIELD_EQ(inName,"inputs") ) { return inputs; }
		if (HX_FIELD_EQ(inName,"vcount") ) { return vcount; }
		if (HX_FIELD_EQ(inName,"offset") ) { return get_offset(); }
		if (HX_FIELD_EQ(inName,"GetBSM") ) { return GetBSM_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indexes") ) { return indexes; }
		if (HX_FIELD_EQ(inName,"weights") ) { return weights; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"GetBinds") ) { return GetBinds_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_offset") ) { return get_offset_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"GetJointIndex") ) { return GetJointIndex_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"GetTriangulatedBones") ) { return GetTriangulatedBones_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"GetTriangulatedWeights") ) { return GetTriangulatedWeights_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"GenerateBonesAndWeights") ) { return GenerateBonesAndWeights_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaController_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"binds") ) { binds=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bones") ) { bones=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"source") ) { source=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"matrix") ) { matrix=inValue.Cast< Array< Float > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"joints") ) { joints=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"inputs") ) { inputs=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vcount") ) { vcount=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indexes") ) { indexes=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"weights") ) { weights=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaController_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("source"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("matrix"));
	outFields->push(HX_CSTRING("binds"));
	outFields->push(HX_CSTRING("joints"));
	outFields->push(HX_CSTRING("inputs"));
	outFields->push(HX_CSTRING("vcount"));
	outFields->push(HX_CSTRING("indexes"));
	outFields->push(HX_CSTRING("weights"));
	outFields->push(HX_CSTRING("bones"));
	outFields->push(HX_CSTRING("offset"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaController_obj,type),HX_CSTRING("type")},
	{hx::fsString,(int)offsetof(ColladaController_obj,source),HX_CSTRING("source")},
	{hx::fsString,(int)offsetof(ColladaController_obj,id),HX_CSTRING("id")},
	{hx::fsString,(int)offsetof(ColladaController_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(ColladaController_obj,matrix),HX_CSTRING("matrix")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaController_obj,binds),HX_CSTRING("binds")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(ColladaController_obj,joints),HX_CSTRING("joints")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaController_obj,inputs),HX_CSTRING("inputs")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(ColladaController_obj,vcount),HX_CSTRING("vcount")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaController_obj,indexes),HX_CSTRING("indexes")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaController_obj,weights),HX_CSTRING("weights")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaController_obj,bones),HX_CSTRING("bones")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("type"),
	HX_CSTRING("source"),
	HX_CSTRING("id"),
	HX_CSTRING("name"),
	HX_CSTRING("matrix"),
	HX_CSTRING("binds"),
	HX_CSTRING("joints"),
	HX_CSTRING("inputs"),
	HX_CSTRING("vcount"),
	HX_CSTRING("indexes"),
	HX_CSTRING("weights"),
	HX_CSTRING("bones"),
	HX_CSTRING("get_offset"),
	HX_CSTRING("GetBSM"),
	HX_CSTRING("GetJointIndex"),
	HX_CSTRING("GetBinds"),
	HX_CSTRING("GetTriangulatedWeights"),
	HX_CSTRING("GetTriangulatedBones"),
	HX_CSTRING("GenerateBonesAndWeights"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaController_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaController_obj::__mClass,"__mClass");
};

#endif

Class ColladaController_obj::__mClass;

void ColladaController_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaController"), hx::TCanCast< ColladaController_obj> ,sStaticFields,sMemberFields,
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

void ColladaController_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
