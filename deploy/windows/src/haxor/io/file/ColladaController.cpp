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
HX_STACK_FRAME("haxor.io.file.ColladaController","new",0x66ccc56a,"haxor.io.file.ColladaController.new","haxor/io/file/ColladaFile.hx",1243,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1258)
	this->bones = null();
	HX_STACK_LINE(1256)
	this->weights = null();
	HX_STACK_LINE(1254)
	this->indexes = null();
	HX_STACK_LINE(1253)
	this->vcount = null();
	HX_STACK_LINE(1252)
	this->inputs = null();
	HX_STACK_LINE(1251)
	this->joints = null();
	HX_STACK_LINE(1250)
	this->binds = null();
	HX_STACK_LINE(1249)
	this->matrix = null();
	HX_STACK_LINE(1248)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(1247)
	this->id = HX_CSTRING("");
	HX_STACK_LINE(1246)
	this->source = HX_CSTRING("");
	HX_STACK_LINE(1245)
	this->type = HX_CSTRING("");
	HX_STACK_LINE(1265)
	this->matrix = Array_obj< Float >::__new();
	HX_STACK_LINE(1266)
	this->binds = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(1267)
	this->inputs = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(1268)
	this->joints = Array_obj< ::String >::__new();
	HX_STACK_LINE(1269)
	this->vcount = Array_obj< int >::__new();
	HX_STACK_LINE(1270)
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
	HX_STACK_FRAME("haxor.io.file.ColladaController","get_offset",0xac7f2792,"haxor.io.file.ColladaController.get_offset","haxor/io/file/ColladaFile.hx",1261,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1261)
	int mo = (int)0;		HX_STACK_VAR(mo,"mo");
	HX_STACK_LINE(1261)
	{
		HX_STACK_LINE(1261)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1261)
		int _g = this->inputs->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1261)
		while((true)){
			HX_STACK_LINE(1261)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1261)
				break;
			}
			HX_STACK_LINE(1261)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1261)
			int _g2 = ::Math_obj::max(mo,(this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->offset + (int)1));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1261)
			mo = _g2;
		}
	}
	HX_STACK_LINE(1261)
	return mo;
}


HX_DEFINE_DYNAMIC_FUNC0(ColladaController_obj,get_offset,return )

::haxor::math::Matrix4 ColladaController_obj::GetBSM( ){
	HX_STACK_FRAME("haxor.io.file.ColladaController","GetBSM",0xc4189fdc,"haxor.io.file.ColladaController.GetBSM","haxor/io/file/ColladaFile.hx",1274,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1275)
	::haxor::math::Matrix4 mtx = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(mtx,"mtx");
	HX_STACK_LINE(1277)
	{
		HX_STACK_LINE(1277)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1277)
		int _g = this->matrix->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1277)
		while((true)){
			HX_STACK_LINE(1277)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1277)
				break;
			}
			HX_STACK_LINE(1277)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1277)
			mtx->SetIndex(i,this->matrix->__get(i));
		}
	}
	HX_STACK_LINE(1278)
	return mtx;
}


HX_DEFINE_DYNAMIC_FUNC0(ColladaController_obj,GetBSM,return )

int ColladaController_obj::GetJointIndex( ::String p_joint){
	HX_STACK_FRAME("haxor.io.file.ColladaController","GetJointIndex",0xd243f708,"haxor.io.file.ColladaController.GetJointIndex","haxor/io/file/ColladaFile.hx",1282,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_joint,"p_joint")
	HX_STACK_LINE(1283)
	{
		HX_STACK_LINE(1283)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1283)
		int _g = this->joints->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1283)
		while((true)){
			HX_STACK_LINE(1283)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1283)
				break;
			}
			HX_STACK_LINE(1283)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1283)
			if (((p_joint == this->joints->__get(i)))){
				HX_STACK_LINE(1283)
				return i;
			}
		}
	}
	HX_STACK_LINE(1284)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaController_obj,GetJointIndex,return )

Array< ::Dynamic > ColladaController_obj::GetBinds( ){
	HX_STACK_FRAME("haxor.io.file.ColladaController","GetBinds",0x82096276,"haxor.io.file.ColladaController.GetBinds","haxor/io/file/ColladaFile.hx",1288,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1289)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(1290)
	{
		HX_STACK_LINE(1290)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1290)
		int _g = this->binds->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1290)
		while((true)){
			HX_STACK_LINE(1290)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1290)
				break;
			}
			HX_STACK_LINE(1290)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1292)
			::haxor::math::Matrix4 mtx = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(mtx,"mtx");
			HX_STACK_LINE(1294)
			{
				HX_STACK_LINE(1294)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(1294)
				int _g2 = this->binds->__get(i).StaticCast< Array< Float > >()->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(1294)
				while((true)){
					HX_STACK_LINE(1294)
					if ((!(((_g3 < _g2))))){
						HX_STACK_LINE(1294)
						break;
					}
					HX_STACK_LINE(1294)
					int j = (_g3)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(1294)
					mtx->SetIndex(j,this->binds->__get(i).StaticCast< Array< Float > >()->__get(j));
				}
			}
			HX_STACK_LINE(1295)
			res->push(mtx);
		}
	}
	HX_STACK_LINE(1297)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC0(ColladaController_obj,GetBinds,return )

Array< ::Dynamic > ColladaController_obj::GetTriangulatedWeights( ::haxor::io::file::ColladaPrimitive cp){
	HX_STACK_FRAME("haxor.io.file.ColladaController","GetTriangulatedWeights",0x87dbbf83,"haxor.io.file.ColladaController.GetTriangulatedWeights","haxor/io/file/ColladaFile.hx",1301,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cp,"cp")
	HX_STACK_LINE(1302)
	int v_off = cp->GetInput(HX_CSTRING("vertex"),null())->offset;		HX_STACK_VAR(v_off,"v_off");
	HX_STACK_LINE(1303)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(1304)
	{
		HX_STACK_LINE(1304)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1304)
		int _g = cp->get_triangles()->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1304)
		while((true)){
			HX_STACK_LINE(1304)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1304)
				break;
			}
			HX_STACK_LINE(1304)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1306)
			Array< ::Dynamic > _g2 = cp->get_triangles();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1306)
			Array< int > _g11 = _g2->__get(i).StaticCast< Array< int > >();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(1306)
			int idx = _g11->__get(v_off);		HX_STACK_VAR(idx,"idx");
			HX_STACK_LINE(1307)
			res->push(this->weights->__get(idx).StaticCast< ::haxor::math::Vector4 >());
		}
	}
	HX_STACK_LINE(1309)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaController_obj,GetTriangulatedWeights,return )

Array< ::Dynamic > ColladaController_obj::GetTriangulatedBones( ::haxor::io::file::ColladaPrimitive cp){
	HX_STACK_FRAME("haxor.io.file.ColladaController","GetTriangulatedBones",0x69a7ce37,"haxor.io.file.ColladaController.GetTriangulatedBones","haxor/io/file/ColladaFile.hx",1313,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cp,"cp")
	HX_STACK_LINE(1314)
	int v_off = cp->GetInput(HX_CSTRING("vertex"),null())->offset;		HX_STACK_VAR(v_off,"v_off");
	HX_STACK_LINE(1315)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(1316)
	{
		HX_STACK_LINE(1316)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(1316)
		int _g = cp->get_triangles()->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1316)
		while((true)){
			HX_STACK_LINE(1316)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(1316)
				break;
			}
			HX_STACK_LINE(1316)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1318)
			Array< ::Dynamic > _g2 = cp->get_triangles();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1318)
			Array< int > _g11 = _g2->__get(i).StaticCast< Array< int > >();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(1318)
			int idx = _g11->__get(v_off);		HX_STACK_VAR(idx,"idx");
			HX_STACK_LINE(1319)
			res->push(this->bones->__get(idx).StaticCast< ::haxor::math::Vector4 >());
		}
	}
	HX_STACK_LINE(1321)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC1(ColladaController_obj,GetTriangulatedBones,return )

Void ColladaController_obj::GenerateBonesAndWeights( ){
{
		HX_STACK_FRAME("haxor.io.file.ColladaController","GenerateBonesAndWeights",0x799635a8,"haxor.io.file.ColladaController.GenerateBonesAndWeights","haxor/io/file/ColladaFile.hx",1325,0xa1888587)
		HX_STACK_THIS(this)
		HX_STACK_LINE(1326)
		this->weights = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(1327)
		this->bones = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(1329)
		int off = this->get_offset();		HX_STACK_VAR(off,"off");
		HX_STACK_LINE(1330)
		::haxor::io::file::ColladaInput wi = null();		HX_STACK_VAR(wi,"wi");
		HX_STACK_LINE(1331)
		int wo = (int)0;		HX_STACK_VAR(wo,"wo");
		HX_STACK_LINE(1332)
		int bo = (int)0;		HX_STACK_VAR(bo,"bo");
		HX_STACK_LINE(1334)
		{
			HX_STACK_LINE(1334)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1334)
			int _g = this->inputs->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1334)
			while((true)){
				HX_STACK_LINE(1334)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1334)
					break;
				}
				HX_STACK_LINE(1334)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1336)
				if (((this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->semantic == HX_CSTRING("weight")))){
					HX_STACK_LINE(1336)
					wi = this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >();
					HX_STACK_LINE(1336)
					wo = wi->offset;
				}
				HX_STACK_LINE(1337)
				if (((this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->semantic == HX_CSTRING("joint")))){
					HX_STACK_LINE(1337)
					bo = this->inputs->__get(i).StaticCast< ::haxor::io::file::ColladaInput >()->offset;
				}
			}
		}
		HX_STACK_LINE(1340)
		int k = (int)0;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(1341)
		{
			HX_STACK_LINE(1341)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1341)
			int _g = this->vcount->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1341)
			while((true)){
				HX_STACK_LINE(1341)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1341)
					break;
				}
				HX_STACK_LINE(1341)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1343)
				int n = this->vcount->__get(i);		HX_STACK_VAR(n,"n");
				HX_STACK_LINE(1344)
				::haxor::math::Vector4 wv4 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(wv4,"wv4");
				HX_STACK_LINE(1345)
				::haxor::math::Vector4 bv4 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(bv4,"bv4");
				HX_STACK_LINE(1346)
				{
					HX_STACK_LINE(1346)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(1346)
					while((true)){
						HX_STACK_LINE(1346)
						if ((!(((_g2 < n))))){
							HX_STACK_LINE(1346)
							break;
						}
						HX_STACK_LINE(1346)
						int j = (_g2)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(1348)
						int bi = this->indexes->__get(k).StaticCast< Array< int > >()->__get(bo);		HX_STACK_VAR(bi,"bi");
						HX_STACK_LINE(1349)
						Float wv = wi->values->__GetItem(this->indexes->__get(k).StaticCast< Array< int > >()->__get(wo));		HX_STACK_VAR(wv,"wv");
						HX_STACK_LINE(1351)
						if (((j == (int)0))){
							HX_STACK_LINE(1351)
							wv4->x = wv;
							HX_STACK_LINE(1351)
							bv4->x = bi;
						}
						else{
							HX_STACK_LINE(1352)
							if (((j == (int)1))){
								HX_STACK_LINE(1352)
								wv4->y = wv;
								HX_STACK_LINE(1352)
								bv4->y = bi;
							}
							else{
								HX_STACK_LINE(1353)
								if (((j == (int)2))){
									HX_STACK_LINE(1353)
									wv4->z = wv;
									HX_STACK_LINE(1353)
									bv4->z = bi;
								}
								else{
									HX_STACK_LINE(1354)
									if (((j == (int)3))){
										HX_STACK_LINE(1354)
										wv4->w = wv;
										HX_STACK_LINE(1354)
										bv4->w = bi;
									}
								}
							}
						}
						HX_STACK_LINE(1355)
						(k)++;
					}
				}
				HX_STACK_LINE(1358)
				Float sum = (((wv4->x + wv4->y) + wv4->z) + wv4->w);		HX_STACK_VAR(sum,"sum");
				HX_STACK_LINE(1359)
				if (((sum <= (int)0))){
					HX_STACK_LINE(1359)
					sum = 0.0;
				}
				else{
					HX_STACK_LINE(1359)
					sum = (Float(1.0) / Float(sum));
				}
				HX_STACK_LINE(1360)
				wv4->Scale(sum);
				HX_STACK_LINE(1361)
				this->weights->push(wv4);
				HX_STACK_LINE(1363)
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
