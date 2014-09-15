package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaFile extends haxor.io.file.AssetXML
{
	public    ColladaFile(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    ColladaFile(java.lang.String p_name, java.lang.String p_src)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.io.file.ColladaFile.__hx_ctor_haxor_io_file_ColladaFile(this, p_name, p_src);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaFile(haxor.io.file.ColladaFile __temp_me255515, java.lang.String p_name, java.lang.String p_src)
	{
		__temp_me255515.xmlns = "";
		__temp_me255515.version = "";
		__temp_me255515.data = new haxor.io.file.ColladaAssetData();
		__temp_me255515.geometries = new haxe.root.Array<haxor.io.file.ColladaGeometry>(new haxor.io.file.ColladaGeometry[]{});
		__temp_me255515.images = new haxe.root.Array<haxor.io.file.ColladaImage>(new haxor.io.file.ColladaImage[]{});
		__temp_me255515.controllers = new haxe.root.Array<haxor.io.file.ColladaController>(new haxor.io.file.ColladaController[]{});
		__temp_me255515.materials = new haxe.root.Array<haxor.io.file.ColladaMaterial>(new haxor.io.file.ColladaMaterial[]{});
		__temp_me255515.animations = new haxe.root.Array<haxor.io.file.ColladaAnimation>(new haxor.io.file.ColladaAnimation[]{});
		__temp_me255515.lights = new haxe.root.Array<haxor.io.file.ColladaLight>(new haxor.io.file.ColladaLight[]{});
		__temp_me255515.scene = null;
		{
			double x = ( java.lang.Math.random() * 16777215 );
			__temp_me255515.m_id = ((int) (x) );
		}
		
		haxor.io.file.AssetXML.__hx_ctor_haxor_io_file_AssetXML(__temp_me255515, p_name, p_src);
	}
	
	
	public static   haxe.root.Array<haxe.root.Array> GenerateTriangles(java.lang.String p_type, haxe.root.Array<haxe.root.Array> p_indexes, haxe.root.Array<java.lang.Object> p_vcount)
	{
		haxe.root.Array<haxe.root.Array> triangles = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{});
		{
			java.lang.String __temp_svar256284 = (p_type);
			switch (__temp_svar256284.hashCode())
			{
				case -814008469:
				{
					if (__temp_svar256284.equals("triangles")) 
					{
						if (( p_indexes.length <= 0 )) 
						{
							triangles = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{});
						}
						 else 
						{
							triangles = ((haxe.root.Array<haxe.root.Array>) (((haxe.root.Array) (p_indexes.__get(0)) )) );
						}
						
					}
					
					break;
				}
				
				
				case 561939050:
				{
					if (__temp_svar256284.equals("polylist")) 
					{
						int k = 0;
						{
							int _g11 = 0;
							int _g2 = p_vcount.length;
							while (( _g11 < _g2 ))
							{
								int i1 = _g11++;
								int o = ((int) (haxe.lang.Runtime.toInt(p_vcount.__get(i1))) );
								haxe.root.Array<haxe.root.Array> tris1 = haxor.io.file.ColladaFile.TriangulatePolygon(((haxe.root.Array<haxe.root.Array>) (((haxe.root.Array) (p_indexes.__get(0)) )) ), o, k);
								while (( tris1.length > 0 ))
								{
									triangles.push(((haxe.root.Array) (((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (tris1.shift()) )) )) ));
								}
								
								k += o;
							}
							
						}
						
					}
					
					break;
				}
				
				
				case 561795705:
				{
					if (__temp_svar256284.equals("polygons")) 
					{
						int _g1 = 0;
						int _g = p_indexes.length;
						while (( _g1 < _g ))
						{
							int i = _g1++;
							haxe.root.Array<haxe.root.Array> tris = haxor.io.file.ColladaFile.TriangulatePolygon(((haxe.root.Array<haxe.root.Array>) (((haxe.root.Array) (p_indexes.__get(i)) )) ), ((haxe.root.Array<haxe.root.Array>) (((haxe.root.Array) (p_indexes.__get(i)) )) ).length, null);
							while (( tris.length > 0 ))
							{
								triangles.push(((haxe.root.Array) (((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (tris.shift()) )) )) ));
							}
							
						}
						
					}
					
					break;
				}
				
				
			}
			
		}
		
		return triangles;
	}
	
	
	public static   haxe.root.Array<haxe.root.Array> TriangulatePolygon(haxe.root.Array<haxe.root.Array> t, int c, java.lang.Object o)
	{
		int __temp_o255514 = ( (( o == null )) ? (((int) (0) )) : (((int) (haxe.lang.Runtime.toInt(o)) )) );
		int i = 0;
		int i0 = 0;
		int i1 = 1;
		int i2 = 2;
		haxe.root.Array<haxe.root.Array> res = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{});
		while (( i2 < c ))
		{
			res.push(((haxe.root.Array) (((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (t.__get(( i0 + __temp_o255514 ))) )) ).copy()) )) )) ));
			res.push(((haxe.root.Array) (((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (t.__get(( i1 + __temp_o255514 ))) )) ).copy()) )) )) ));
			res.push(((haxe.root.Array) (((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (((haxe.root.Array<java.lang.Object>) (((haxe.root.Array) (t.__get(( i2 + __temp_o255514 ))) )) ).copy()) )) )) ));
			i1++;
			i2++;
		}
		
		return res;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaFile(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaFile(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toString(arr.__get(1)));
	}
	
	
	public  java.lang.String xmlns;
	
	public  java.lang.String version;
	
	public  haxor.io.file.ColladaAssetData data;
	
	public  haxe.root.Array<haxor.io.file.ColladaGeometry> geometries;
	
	public  haxe.root.Array<haxor.io.file.ColladaImage> images;
	
	public  haxe.root.Array<haxor.io.file.ColladaController> controllers;
	
	public  haxe.root.Array<haxor.io.file.ColladaMaterial> materials;
	
	public  haxe.root.Array<haxor.io.file.ColladaLight> lights;
	
	public  haxe.root.Array<haxor.io.file.ColladaAnimation> animations;
	
	public  haxor.io.file.ColladaVisualScene scene;
	
	public  int m_id;
	
	@Override public   java.lang.Object get_asset()
	{
		haxe.root.Array<haxor.io.file.ColladaFile> _g3 = new haxe.root.Array<haxor.io.file.ColladaFile>(new haxor.io.file.ColladaFile[]{this});
		haxe.root.Array<haxor.core.Entity> re = new haxe.root.Array<haxor.core.Entity>(new haxor.core.Entity[]{new haxor.core.Entity(haxe.lang.Runtime.toString(null))});
		re.__get(0).set_name("collada_asset");
		if (( this.scene == null )) 
		{
			haxor.core.Console.LogError("ColladaFile> Trying to get asset of NULL scene.", null);
			return re.__get(0);
		}
		
		if ( ! (haxe.lang.Runtime.valEq(this.scene.name, "")) ) 
		{
			re.__get(0).set_name(this.scene.name);
		}
		 else 
		{
			if ( ! (haxe.lang.Runtime.valEq(this.scene.id, "")) ) 
			{
				re.__get(0).set_name(this.scene.id);
			}
			
		}
		
		haxe.root.Array<haxe.ds.ObjectMap> hm = new haxe.root.Array<haxe.ds.ObjectMap>(new haxe.ds.ObjectMap[]{((haxe.ds.ObjectMap) (new haxe.ds.ObjectMap<haxor.io.file.ColladaNode, haxor.core.Entity>()) )});
		haxe.root.Array<haxe.ds.ObjectMap> cm = new haxe.root.Array<haxe.ds.ObjectMap>(new haxe.ds.ObjectMap[]{((haxe.ds.ObjectMap) (new haxe.ds.ObjectMap<haxor.component.Transform, haxor.io.file.ColladaController>()) )});
		haxe.root.Array<haxe.ds.ObjectMap> mm = new haxe.root.Array<haxe.ds.ObjectMap>(new haxe.ds.ObjectMap[]{((haxe.ds.ObjectMap) (new haxe.ds.ObjectMap<haxor.io.file.ColladaMaterial, haxor.graphics.material.Material>()) )});
		haxe.root.Array<haxe.root.Array> joint_transforms = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{((haxe.root.Array) (new haxe.root.Array<haxor.component.Transform>(new haxor.component.Transform[]{})) )});
		haxe.root.Array<haxe.root.Array> joint_nodes = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{((haxe.root.Array) (new haxe.root.Array<haxor.io.file.ColladaNode>(new haxor.io.file.ColladaNode[]{})) )});
		haxe.root.Array<haxe.root.Array> skinned_meshes = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{((haxe.root.Array) (new haxe.root.Array<haxor.component.SkinnedMeshRenderer>(new haxor.component.SkinnedMeshRenderer[]{})) )});
		{
			int _g1 = 0;
			int _g = this.materials.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.io.file.ColladaMaterial m = this.materials.__get(i);
				java.lang.String mn = m.name;
				{
					int _g2 = 0;
					while (( _g2 < 10 ))
					{
						int i1 = _g2++;
						mn = haxe.root.StringTools.replace(mn, ( "_" + i1 ), "");
					}
					
				}
				
				mn = haxe.root.StringTools.replace(mn, "_", "/");
				haxor.graphics.material.Material mat = ((haxor.graphics.material.Material) (haxor.io.file.Asset.Get(mn)) );
				if (( mat == null )) 
				{
					mat = new haxor.graphics.material.Material(haxe.lang.Runtime.toString(null));
					mat.set_name(mn);
					mat.set_shader(((haxor.graphics.material.Shader) (haxor.io.file.Asset.Get("haxor/unlit/FlatTexture")) ));
					haxor.io.file.Asset.Add(mn, mat);
				}
				
				((haxe.ds.ObjectMap<haxor.io.file.ColladaMaterial, haxor.graphics.material.Material>) (((haxe.ds.ObjectMap) (mm.__get(0)) )) ).set(m, mat);
			}
			
		}
		
		this.scene.Traverse(new haxor.io.file.ColladaFile_get_asset_185__Fun(((haxe.root.Array<haxe.root.Array>) (skinned_meshes) ), ((haxe.root.Array<haxe.root.Array>) (joint_nodes) ), ((haxe.root.Array<haxe.ds.ObjectMap>) (cm) ), ((haxe.root.Array<haxor.core.Entity>) (re) ), ((haxe.root.Array<haxe.ds.ObjectMap>) (mm) ), ((haxe.root.Array<haxe.root.Array>) (joint_transforms) ), ((haxe.root.Array<haxe.ds.ObjectMap>) (hm) ), ((haxe.root.Array<haxor.io.file.ColladaFile>) (_g3) )));
		{
			int _g12 = 0;
			int _g6 = ((haxe.root.Array<haxor.component.SkinnedMeshRenderer>) (((haxe.root.Array) (skinned_meshes.__get(0)) )) ).length;
			while (( _g12 < _g6 ))
			{
				int i5 = _g12++;
				haxor.component.SkinnedMeshRenderer skr = ((haxe.root.Array<haxor.component.SkinnedMeshRenderer>) (((haxe.root.Array) (skinned_meshes.__get(0)) )) ).__get(i5);
				haxor.io.file.ColladaController cc1 = null;
				if (((haxe.ds.ObjectMap<haxor.component.Transform, haxor.io.file.ColladaController>) (((haxe.ds.ObjectMap) (cm.__get(0)) )) ).exists(skr.m_entity.m_transform)) 
				{
					cc1 = ((haxe.ds.ObjectMap<haxor.component.Transform, haxor.io.file.ColladaController>) (((haxe.ds.ObjectMap) (cm.__get(0)) )) ).get(skr.m_entity.m_transform);
				}
				 else 
				{
					cc1 = null;
				}
				
				if (( cc1 == null )) 
				{
					continue;
				}
				
				skr.set_joints(new haxe.root.Array<haxor.component.Transform>(new haxor.component.Transform[]{}));
				{
					int _g31 = 0;
					int _g23 = cc1.joints.length;
					while (( _g31 < _g23 ))
					{
						int j = _g31++;
						int _g51 = 0;
						int _g43 = ((haxe.root.Array<haxor.component.Transform>) (((haxe.root.Array) (joint_transforms.__get(0)) )) ).length;
						while (( _g51 < _g43 ))
						{
							int k = _g51++;
							if (haxe.lang.Runtime.valEq(((haxe.root.Array<haxor.component.Transform>) (((haxe.root.Array) (joint_transforms.__get(0)) )) ).__get(k).get_name(), cc1.joints.__get(j))) 
							{
								skr.m_joints.push(((haxe.root.Array<haxor.component.Transform>) (((haxe.root.Array) (joint_transforms.__get(0)) )) ).__get(k));
							}
							
						}
						
					}
					
				}
				
			}
			
		}
		
		java.lang.Object nit = ((haxe.ds.ObjectMap<haxor.io.file.ColladaNode, haxor.core.Entity>) (((haxe.ds.ObjectMap) (hm.__get(0)) )) ).keys();
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(nit, "hasNext", null)))
		{
			haxor.io.file.ColladaNode n1 = ((haxor.io.file.ColladaNode) (haxe.lang.Runtime.callField(nit, "next", null)) );
			haxor.core.Entity e = ((haxe.ds.ObjectMap<haxor.io.file.ColladaNode, haxor.core.Entity>) (((haxe.ds.ObjectMap) (hm.__get(0)) )) ).get(n1);
			if (( e == re.__get(0) )) 
			{
				continue;
			}
			
			e.set_name(n1.name);
		}
		
		this.AddAnimations(re.__get(0), null);
		if (haxe.lang.Runtime.valEq(this.data.axis, "z_up")) 
		{
			re.__get(0).m_transform.set_rotation(haxor.math.Quaternion.FromAxisAngle(new haxor.math.Vector3(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )), -90.0));
		}
		
		return re.__get(0);
	}
	
	
	public   void AddAnimations(haxor.core.Entity p_entity, java.lang.Object p_exact)
	{
		boolean __temp_p_exact255513 = ( (( p_exact == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_exact)) );
	}
	
	
	public   haxor.component.MeshRenderer CreateMeshRenderer(haxor.core.Entity e, java.lang.String msh, haxor.io.file.ColladaPrimitive cp, java.lang.Class<haxor.component.Component> t, haxor.io.file.ColladaController cc)
	{
		haxor.component.MeshRenderer r = ((haxor.component.MeshRenderer) (e.AddComponent(t)) );
		java.lang.String mid = ( ( msh + "_" ) + this.m_id );
		haxor.graphics.mesh.Mesh3 m = ((haxor.graphics.mesh.Mesh3) (haxor.io.file.Asset.Get(mid)) );
		if (( m != null )) 
		{
			r.set_mesh(m);
			return r;
		}
		
		haxe.root.Array<haxor.math.Vector3> mv = ((haxe.root.Array<haxor.math.Vector3>) (cp.GetTriangulatedVectorArray("vertex", null, null)) );
		haxe.root.Array<haxor.math.Vector3> mn = ((haxe.root.Array<haxor.math.Vector3>) (cp.GetTriangulatedVectorArray("normal", null, null)) );
		haxe.root.Array<haxor.math.Color> mc = ((haxe.root.Array<haxor.math.Color>) (cp.GetTriangulatedVectorArray("color", null, null)) );
		haxe.root.Array<haxor.math.Vector3> muv0 = ((haxe.root.Array<haxor.math.Vector3>) (cp.GetTriangulatedVectorArray("texcoord", 0, null)) );
		haxe.root.Array<haxor.math.Vector3> muv1 = ((haxe.root.Array<haxor.math.Vector3>) (cp.GetTriangulatedVectorArray("texcoord", 1, null)) );
		haxe.root.Array<haxor.math.Vector3> mbn = ((haxe.root.Array<haxor.math.Vector3>) (cp.GetTriangulatedVectorArray("texbinormal", null, null)) );
		haxe.root.Array<haxor.math.Vector3> mtg = ((haxe.root.Array<haxor.math.Vector3>) (cp.GetTriangulatedVectorArray("textangent", null, null)) );
		boolean is_skinned = ( r instanceof haxor.component.SkinnedMeshRenderer );
		if (is_skinned) 
		{
			m = new haxor.graphics.mesh.SkinnedMesh3(haxe.lang.Runtime.toString(null));
		}
		 else 
		{
			m = new haxor.graphics.mesh.Mesh3(haxe.lang.Runtime.toString(null));
		}
		
		m.set_name(mid);
		haxor.io.file.Asset.Add(mid, m);
		if (( mc.length > 0 )) 
		{
			m.set_color(mc);
		}
		
		if (( muv0.length > 0 )) 
		{
			m.set_uv0(muv0);
		}
		
		if (( muv1.length > 0 )) 
		{
			m.set_uv1(muv1);
		}
		
		if (is_skinned) 
		{
			if (( cc != null )) 
			{
				cc.GenerateBonesAndWeights();
				haxor.graphics.mesh.SkinnedMesh3 skm = ((haxor.graphics.mesh.SkinnedMesh3) (m) );
				haxe.root.Array<haxor.math.Vector4> mvw = cc.GetTriangulatedWeights(cp);
				haxe.root.Array<haxor.math.Vector4> mbi = cc.GetTriangulatedBones(cp);
				haxe.root.Array<haxor.math.Matrix4> mbm = cc.GetBinds();
				skm.set_binds(mbm);
				skm.set_weight(mvw);
				skm.set_bone(mbi);
				haxor.math.Matrix4 bsm = cc.GetBSM();
				{
					int _g1 = 0;
					int _g = mv.length;
					while (( _g1 < _g ))
					{
						int i = _g1++;
						{
							haxor.math.Vector3 p_point = null;
							{
								haxor.math.Vector3 _this = mv.__get(i);
								p_point = new haxor.math.Vector3(((java.lang.Object) (_this.x) ), ((java.lang.Object) (_this.y) ), ((java.lang.Object) (_this.z) ));
							}
							
							double vx = ( ( ( ( bsm.m00 * p_point.x ) + ( bsm.m01 * p_point.y ) ) + ( bsm.m02 * p_point.z ) ) + bsm.m03 );
							double vy = ( ( ( ( bsm.m10 * p_point.x ) + ( bsm.m11 * p_point.y ) ) + ( bsm.m12 * p_point.z ) ) + bsm.m13 );
							double vz = ( ( ( ( bsm.m20 * p_point.x ) + ( bsm.m21 * p_point.y ) ) + ( bsm.m22 * p_point.z ) ) + bsm.m23 );
							p_point.x = vx;
							p_point.y = vy;
							p_point.z = vz;
							mv.__set(i, p_point);
						}
						
					}
					
				}
				
				{
					int _g11 = 0;
					int _g2 = mn.length;
					while (( _g11 < _g2 ))
					{
						int i1 = _g11++;
						{
							haxor.math.Vector3 p_point1 = null;
							{
								haxor.math.Vector3 _this1 = mn.__get(i1);
								p_point1 = new haxor.math.Vector3(((java.lang.Object) (_this1.x) ), ((java.lang.Object) (_this1.y) ), ((java.lang.Object) (_this1.z) ));
							}
							
							double vx1 = ( ( ( bsm.m00 * p_point1.x ) + ( bsm.m01 * p_point1.y ) ) + ( bsm.m02 * p_point1.z ) );
							double vy1 = ( ( ( bsm.m10 * p_point1.x ) + ( bsm.m11 * p_point1.y ) ) + ( bsm.m12 * p_point1.z ) );
							double vz1 = ( ( ( bsm.m20 * p_point1.x ) + ( bsm.m21 * p_point1.y ) ) + ( bsm.m22 * p_point1.z ) );
							p_point1.x = vx1;
							p_point1.y = vy1;
							p_point1.z = vz1;
							mn.__set(i1, p_point1);
						}
						
					}
					
				}
				
				{
					int _g12 = 0;
					int _g3 = mbn.length;
					while (( _g12 < _g3 ))
					{
						int i2 = _g12++;
						{
							haxor.math.Vector3 p_point2 = null;
							{
								haxor.math.Vector3 _this2 = mbn.__get(i2);
								p_point2 = new haxor.math.Vector3(((java.lang.Object) (_this2.x) ), ((java.lang.Object) (_this2.y) ), ((java.lang.Object) (_this2.z) ));
							}
							
							double vx2 = ( ( ( bsm.m00 * p_point2.x ) + ( bsm.m01 * p_point2.y ) ) + ( bsm.m02 * p_point2.z ) );
							double vy2 = ( ( ( bsm.m10 * p_point2.x ) + ( bsm.m11 * p_point2.y ) ) + ( bsm.m12 * p_point2.z ) );
							double vz2 = ( ( ( bsm.m20 * p_point2.x ) + ( bsm.m21 * p_point2.y ) ) + ( bsm.m22 * p_point2.z ) );
							p_point2.x = vx2;
							p_point2.y = vy2;
							p_point2.z = vz2;
							mbn.__set(i2, p_point2);
						}
						
					}
					
				}
				
				{
					int _g13 = 0;
					int _g4 = mtg.length;
					while (( _g13 < _g4 ))
					{
						int i3 = _g13++;
						{
							haxor.math.Vector3 p_point3 = null;
							{
								haxor.math.Vector3 _this3 = mtg.__get(i3);
								p_point3 = new haxor.math.Vector3(((java.lang.Object) (_this3.x) ), ((java.lang.Object) (_this3.y) ), ((java.lang.Object) (_this3.z) ));
							}
							
							double vx3 = ( ( ( bsm.m00 * p_point3.x ) + ( bsm.m01 * p_point3.y ) ) + ( bsm.m02 * p_point3.z ) );
							double vy3 = ( ( ( bsm.m10 * p_point3.x ) + ( bsm.m11 * p_point3.y ) ) + ( bsm.m12 * p_point3.z ) );
							double vz3 = ( ( ( bsm.m20 * p_point3.x ) + ( bsm.m21 * p_point3.y ) ) + ( bsm.m22 * p_point3.z ) );
							p_point3.x = vx3;
							p_point3.y = vy3;
							p_point3.z = vz3;
							mtg.__set(i3, p_point3);
						}
						
					}
					
				}
				
			}
			
		}
		
		if (( mv.length > 0 )) 
		{
			m.set_vertex(mv);
		}
		
		if (( mn.length > 0 )) 
		{
			m.set_normal(mn);
		}
		
		if (( mbn.length > 0 )) 
		{
			m.set_binormal(mbn);
		}
		
		if (( mtg.length > 0 )) 
		{
			m.set_tangent(mtg);
		}
		
		m.GenerateBounds();
		r.set_mesh(m);
		return r;
	}
	
	
	public   haxor.io.file.ColladaLight FindLightById(java.lang.String p_id)
	{
		{
			int _g1 = 0;
			int _g = this.lights.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(this.lights.__get(i).id, p_id)) 
				{
					return this.lights.__get(i);
				}
				
			}
			
		}
		
		return null;
	}
	
	
	public   haxor.io.file.ColladaGeometry FindGeometryById(java.lang.String p_id)
	{
		{
			int _g1 = 0;
			int _g = this.geometries.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(this.geometries.__get(i).id, p_id)) 
				{
					return this.geometries.__get(i);
				}
				
			}
			
		}
		
		return null;
	}
	
	
	public   haxor.io.file.ColladaController FindControllerById(java.lang.String p_id)
	{
		{
			int _g1 = 0;
			int _g = this.controllers.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(this.controllers.__get(i).id, p_id)) 
				{
					return this.controllers.__get(i);
				}
				
			}
			
		}
		
		return null;
	}
	
	
	public   haxor.io.file.ColladaNode FindNodeById(java.lang.String p_id)
	{
		haxe.root.Array<java.lang.String> p_id1 = new haxe.root.Array<java.lang.String>(new java.lang.String[]{p_id});
		haxe.root.Array<haxor.io.file.ColladaNode> res = new haxe.root.Array<haxor.io.file.ColladaNode>(new haxor.io.file.ColladaNode[]{null});
		this.scene.Traverse(new haxor.io.file.ColladaFile_FindNodeById_512__Fun(((haxe.root.Array<java.lang.String>) (p_id1) ), ((haxe.root.Array<haxor.io.file.ColladaNode>) (res) )));
		return res.__get(0);
	}
	
	
	public   haxor.io.file.ColladaMaterial FindMaterialById(java.lang.String p_id)
	{
		{
			int _g1 = 0;
			int _g = this.materials.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.lang.Runtime.valEq(this.materials.__get(i).id, p_id)) 
				{
					return this.materials.__get(i);
				}
				 else 
				{
					if (haxe.lang.Runtime.valEq(this.materials.__get(i).name, p_id)) 
					{
						return this.materials.__get(i);
					}
					
				}
				
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void Parse(haxe.root.Xml n)
	{
		java.lang.String _g = n.get_nodeName();
		{
			java.lang.String __temp_svar256253 = (_g);
			switch (__temp_svar256253.hashCode())
			{
				case 1667423762:
				{
					if (__temp_svar256253.equals("COLLADA")) 
					{
						this.xmlns = this._a(n, "xmlns", "");
						this.version = this._a(n, "version", "0.0");
					}
					
					break;
				}
				
				
				case 1821806113:
				{
					if (__temp_svar256253.equals("library_lights")) 
					{
						this.ParseLightLibrary(n);
					}
					
					break;
				}
				
				
				case 93121264:
				{
					if (__temp_svar256253.equals("asset")) 
					{
						this.data.author = haxe.lang.Runtime.toString(this._p(n, "contributor.author.$text", "none", null, null));
						this.data.tool = haxe.lang.Runtime.toString(this._p(n, "contributor.authoring_tool.$text", "none", null, null));
						this.data.source = haxe.lang.Runtime.toString(this._p(n, "contributor.source_data.$text", "none", null, null));
						this.data.axis = haxe.lang.Runtime.toString(((java.lang.Object) (haxe.lang.Runtime.callField(this._p(n, "up_axis.$text", "y_up", null, null), "toLowerCase", null)) ));
						this.data.creation = haxe.lang.Runtime.toString(this._p(n, "created.$text", "00/00/00", null, null));
						this.data.modification = haxe.lang.Runtime.toString(this._p(n, "modified.$text", "00/00/00", null, null));
						this.data.unitName = haxe.lang.Runtime.toString(this._p(n, "unit.@name", "none", null, null));
						this.data.unitValue = haxe.root.Std.parseFloat(haxe.lang.Runtime.toString(this._p(n, "unit.@meter", "0.0", null, null)));
					}
					
					break;
				}
				
				
				case 582210419:
				{
					if (__temp_svar256253.equals("library_animations")) 
					{
						this.ParseAnimationLibrary(n);
					}
					
					break;
				}
				
				
				case -1363060354:
				{
					if (__temp_svar256253.equals("library_effects")) 
					{
						{
						}
						
					}
					
					break;
				}
				
				
				case -264676670:
				{
					if (__temp_svar256253.equals("library_visual_scenes")) 
					{
						this.ParseSceneLibrary(n);
					}
					
					break;
				}
				
				
				case -2081164888:
				{
					if (__temp_svar256253.equals("library_materials")) 
					{
						this.ParseMaterialLibrary(n);
					}
					
					break;
				}
				
				
				case 1739432572:
				{
					if (__temp_svar256253.equals("library_images")) 
					{
						this.ParseImageLibrary(n);
					}
					
					break;
				}
				
				
				case 109254796:
				{
					if (__temp_svar256253.equals("scene")) 
					{
						{
						}
						
					}
					
					break;
				}
				
				
				case -1992142125:
				{
					if (__temp_svar256253.equals("library_controllers")) 
					{
						this.ParseControllerLibrary(n);
					}
					
					break;
				}
				
				
				case 472056468:
				{
					if (__temp_svar256253.equals("library_geometries")) 
					{
						this.ParseGeometryLibrary(n);
					}
					
					break;
				}
				
				
			}
			
		}
		
	}
	
	
	public   void ParseLightLibrary(haxe.root.Xml n)
	{
		java.lang.Object it = n.elementsNamed("light");
		haxor.io.file.ColladaLight l = null;
		java.lang.Object lit = null;
		haxe.root.Xml ln = null;
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(it, "hasNext", null)))
		{
			n = ((haxe.root.Xml) (haxe.lang.Runtime.callField(it, "next", null)) );
			l = new haxor.io.file.ColladaLight();
			l.id = haxe.lang.Runtime.toString(this._p(n, "@id", ( "light" + this.lights.length ), null, null));
			l.name = haxe.lang.Runtime.toString(this._p(n, "@name", l.id, null, null));
			this.lights.push(l);
			lit = n.elementsNamed("technique_common");
			if ( ! (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(lit, "hasNext", null))) ) 
			{
				continue;
			}
			
			lit = ((haxe.root.Xml) (haxe.lang.Runtime.callField(lit, "next", null)) ).elements();
			if ( ! (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(lit, "hasNext", null))) ) 
			{
				continue;
			}
			
			ln = ((haxe.root.Xml) (haxe.lang.Runtime.callField(lit, "next", null)) );
			l.type = ln.get_nodeName().toLowerCase();
			haxe.root.Array<java.lang.Object> ca = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) )});
			{
				java.lang.String _g = l.type;
				{
					java.lang.String __temp_svar256255 = (_g);
					switch (__temp_svar256255.hashCode())
					{
						case 106845584:
						{
							if (__temp_svar256255.equals("point")) 
							{
								ca = this._f32a(haxe.lang.Runtime.toString(this._p(ln, "color.$text", "", null, null)));
							}
							
							break;
						}
						
						
						case -1631834134:
						{
							if (__temp_svar256255.equals("directional")) 
							{
								ca = this._f32a(haxe.lang.Runtime.toString(this._p(ln, "color.$text", "", null, null)));
							}
							
							break;
						}
						
						
						case -892145000:
						{
							if (__temp_svar256255.equals("ambient")) 
							{
								ca = this._f32a(haxe.lang.Runtime.toString(this._p(ln, "color.$text", "", null, null)));
							}
							
							break;
						}
						
						
					}
					
				}
				
			}
			
			l.color.Set(((double) (haxe.lang.Runtime.toDouble(ca.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(ca.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(ca.__get(2))) ), ( (( ca.length >= 4 )) ? (((double) (haxe.lang.Runtime.toDouble(ca.__get(3))) )) : (1.0) ));
			lit = n.elementsNamed("extra");
			if ( ! (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(lit, "hasNext", null))) ) 
			{
				continue;
			}
			
			lit = ((haxe.root.Xml) (haxe.lang.Runtime.callField(lit, "next", null)) ).elementsNamed("technique");
			if ( ! (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(lit, "hasNext", null))) ) 
			{
				continue;
			}
			
			lit = ((haxe.root.Xml) (haxe.lang.Runtime.callField(lit, "next", null)) ).elementsNamed("max_light");
			if ( ! (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(lit, "hasNext", null))) ) 
			{
				continue;
			}
			
			ln = ((haxe.root.Xml) (haxe.lang.Runtime.callField(lit, "next", null)) );
			{
				java.lang.String _g1 = l.type;
				{
					java.lang.String __temp_svar256257 = (_g1);
					switch (__temp_svar256257.hashCode())
					{
						case 106845584:
						{
							if (__temp_svar256257.equals("point")) 
							{
								l.radius = haxe.root.Std.parseFloat(haxe.lang.Runtime.toString(this._p(ln, "decay_radius.$text", "1.0", null, null)));
								l.intensity = haxe.root.Std.parseFloat(haxe.lang.Runtime.toString(this._p(ln, "multiplier.$text", "1.0", null, null)));
								int atten_type = ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(haxe.lang.Runtime.toString(this._p(ln, "decay_type.$text", "1.0", null, null))))) );
								if (( atten_type == 0 )) 
								{
									l.atten = 0.0;
								}
								 else 
								{
									if (( atten_type == 1 )) 
									{
										l.atten = 1.0;
									}
									 else 
									{
										l.atten = 2.0;
									}
									
								}
								
							}
							
							break;
						}
						
						
						case -1631834134:
						{
							if (__temp_svar256257.equals("directional")) 
							{
								l.intensity = haxe.root.Std.parseFloat(haxe.lang.Runtime.toString(this._p(ln, "multiplier.$text", "1.0", null, null)));
							}
							
							break;
						}
						
						
						case -892145000:
						{
							if (__temp_svar256257.equals("ambient")) 
							{
								{
								}
								
							}
							
							break;
						}
						
						
					}
					
				}
				
			}
			
		}
		
	}
	
	
	public   void ParseAnimationLibrary(haxe.root.Xml n)
	{
		java.lang.Object it = n.elementsNamed("animation");
		int anim_id = 0;
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(it, "hasNext", null)))
		{
			n = ((haxe.root.Xml) (haxe.lang.Runtime.callField(it, "next", null)) );
			if (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(n.elementsNamed("animation"), "hasNext", null))) 
			{
				n = ((haxe.root.Xml) (haxe.lang.Runtime.callField(n.elementsNamed("animation"), "next", null)) );
			}
			
			haxor.io.file.ColladaAnimation ca = new haxor.io.file.ColladaAnimation();
			ca.id = this._a(n, "id", "");
			if (haxe.lang.Runtime.valEq(ca.id, "")) 
			{
				ca.id = ( "Clip" + anim_id++ );
			}
			 else 
			{
				ca.id = ca.id;
			}
			
			ca.name = this._a(n, "name", ca.id);
			java.lang.Object source_iterator = n.elementsNamed("source");
			java.lang.Object sampler_iterator = n.elementsNamed("sampler");
			haxe.root.Array<haxe.root.Xml> source_list = new haxe.root.Array<haxe.root.Xml>(new haxe.root.Xml[]{});
			haxe.root.Array<haxe.root.Xml> sampler_list = new haxe.root.Array<haxe.root.Xml>(new haxe.root.Xml[]{});
			while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(source_iterator, "hasNext", null)))
			{
				source_list.push(((haxe.root.Xml) (haxe.lang.Runtime.callField(source_iterator, "next", null)) ));
			}
			
			while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(sampler_iterator, "hasNext", null)))
			{
				sampler_list.push(((haxe.root.Xml) (haxe.lang.Runtime.callField(sampler_iterator, "next", null)) ));
			}
			
			java.lang.Object channel_list = n.elementsNamed("channel");
			while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(channel_list, "hasNext", null)))
			{
				haxe.root.Xml chn = ((haxe.root.Xml) (haxe.lang.Runtime.callField(channel_list, "next", null)) );
				haxor.io.file.ColladaAnimationChannel cch = new haxor.io.file.ColladaAnimationChannel();
				cch.source = haxe.lang.StringExt.substr(this._a(chn, "source", ""), 1, null);
				cch.target = this._a(chn, "target", "");
				{
					int _g1 = 0;
					int _g = sampler_list.length;
					while (( _g1 < _g ))
					{
						int i = _g1++;
						java.lang.String sampler_id = this._a(sampler_list.__get(i), "id", "");
						if ( ! (haxe.lang.Runtime.valEq(sampler_id, cch.source)) ) 
						{
							continue;
						}
						
						java.lang.Object input_iterator = sampler_list.__get(i).elementsNamed("input");
						java.lang.String keyframe_time_source = "";
						java.lang.String keyframe_value_source = "";
						while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(input_iterator, "hasNext", null)))
						{
							haxe.root.Xml chsi = ((haxe.root.Xml) (haxe.lang.Runtime.callField(input_iterator, "next", null)) );
							{
								java.lang.String _g2 = this._a(chsi, "semantic", "").toLowerCase();
								{
									java.lang.String __temp_svar256259 = (_g2);
									switch (__temp_svar256259.hashCode())
									{
										case 100358090:
										{
											if (__temp_svar256259.equals("input")) 
											{
												keyframe_time_source = haxe.lang.StringExt.substr(this._a(chsi, "source", ""), 1, null);
											}
											
											break;
										}
										
										
										case -1005512447:
										{
											if (__temp_svar256259.equals("output")) 
											{
												keyframe_value_source = haxe.lang.StringExt.substr(this._a(chsi, "source", ""), 1, null);
											}
											
											break;
										}
										
										
									}
									
								}
								
							}
							
						}
						
						if (haxe.lang.Runtime.valEq(keyframe_time_source, "")) 
						{
							continue;
						}
						
						if (haxe.lang.Runtime.valEq(keyframe_value_source, "")) 
						{
							continue;
						}
						
						haxe.root.Xml kf_time_node = null;
						haxe.root.Xml kf_value_node = null;
						{
							int _g3 = 0;
							int _g21 = source_list.length;
							while (( _g3 < _g21 ))
							{
								int j = _g3++;
								haxe.root.Xml sn = source_list.__get(j);
								if (haxe.lang.Runtime.valEq(this._a(sn, "id", ""), keyframe_time_source)) 
								{
									kf_time_node = sn;
								}
								
								if (haxe.lang.Runtime.valEq(this._a(sn, "id", ""), keyframe_value_source)) 
								{
									kf_value_node = sn;
								}
								
							}
							
						}
						
						if (( kf_time_node == null )) 
						{
							continue;
						}
						
						if (( kf_value_node == null )) 
						{
							continue;
						}
						
						haxe.root.Array<java.lang.Object> kf_time_buffer = this._f32a(haxe.lang.Runtime.toString(this._p(kf_time_node, "float_array.$text", "", null, null)));
						haxe.root.Array<java.lang.Object> kf_value_buffer = this._f32a(haxe.lang.Runtime.toString(this._p(kf_value_node, "float_array.$text", "", null, null)));
						int kf_value_stride = ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(haxe.lang.Runtime.toString(this._p(kf_value_node, "technique_common.accessor.@stride", "0", null, null))))) );
						{
							int _g31 = 0;
							int _g22 = kf_time_buffer.length;
							while (( _g31 < _g22 ))
							{
								int j1 = _g31++;
								haxor.io.file.ColladaAnimationKeyFrame kf = new haxor.io.file.ColladaAnimationKeyFrame();
								kf.time = ((double) (haxe.lang.Runtime.toDouble(kf_time_buffer.__get(j1))) );
								{
									int _g4 = 0;
									while (( _g4 < kf_value_stride ))
									{
										int k = _g4++;
										kf.values.push(kf_value_buffer.shift());
									}
									
								}
								
								cch.keyframes.push(kf);
							}
							
						}
						
					}
					
				}
				
				ca.channels.push(cch);
			}
			
			this.animations.push(ca);
		}
		
	}
	
	
	public   void ParseMaterialLibrary(haxe.root.Xml n)
	{
		java.lang.Object it = n.elements();
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(it, "hasNext", null)))
		{
			n = ((haxe.root.Xml) (haxe.lang.Runtime.callField(it, "next", null)) );
			{
				java.lang.String _g = n.get_nodeName();
				{
					java.lang.String __temp_svar256261 = (_g);
					switch (__temp_svar256261.hashCode())
					{
						case 299066663:
						{
							if (__temp_svar256261.equals("material")) 
							{
								haxor.io.file.ColladaMaterial mat = new haxor.io.file.ColladaMaterial();
								mat.id = this._a(n, "id", "");
								mat.name = this._a(n, "name", "");
								if (haxe.lang.Runtime.valEq(mat.id, "")) 
								{
									mat.id = mat.name;
								}
								
								this.materials.push(mat);
							}
							
							break;
						}
						
						
					}
					
				}
				
			}
			
		}
		
	}
	
	
	public   void ParseSceneLibrary(haxe.root.Xml n)
	{
		java.lang.Object it = n.elements();
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(it, "hasNext", null)))
		{
			n = ((haxe.root.Xml) (haxe.lang.Runtime.callField(it, "next", null)) );
			{
				java.lang.String _g = n.get_nodeName();
				{
					java.lang.String __temp_svar256263 = (_g);
					switch (__temp_svar256263.hashCode())
					{
						case 1946587853:
						{
							if (__temp_svar256263.equals("visual_scene")) 
							{
								this.ParseVisualScene(n);
							}
							
							break;
						}
						
						
					}
					
				}
				
			}
			
		}
		
	}
	
	
	public   void ParseVisualScene(haxe.root.Xml n)
	{
		if (( this.scene != null )) 
		{
			return ;
		}
		
		this.scene = new haxor.io.file.ColladaVisualScene();
		this.scene.id = this._a(n, "id", "collada_scene");
		this.scene.name = this._a(n, "name", this.scene.id);
		this.scene.type = n.get_nodeName();
		this.TraverseVisualSceneNodes(this.scene, null, n);
	}
	
	
	public   void TraverseVisualSceneNodes(haxor.io.file.ColladaVisualScene scn, haxor.io.file.ColladaNode p, haxe.root.Xml n)
	{
		haxor.io.file.ColladaNode cn = null;
		if (haxe.lang.Runtime.valEq(n.get_nodeName(), "node")) 
		{
			cn = this.ParseVisualSceneNode(scn, p, n);
		}
		
		java.lang.Object cn_it = n.elementsNamed("node");
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(cn_it, "hasNext", null)))
		{
			this.TraverseVisualSceneNodes(scn, cn, ((haxe.root.Xml) (haxe.lang.Runtime.callField(cn_it, "next", null)) ));
		}
		
	}
	
	
	public   haxor.io.file.ColladaNode ParseVisualSceneNode(haxor.io.file.ColladaVisualScene scn, haxor.io.file.ColladaNode p, haxe.root.Xml n)
	{
		haxor.io.file.ColladaNode cn = new haxor.io.file.ColladaNode();
		cn.scene = scn;
		int __temp_stmt256265 = 0;
		{
			double x = ( java.lang.Math.random() * 16777215 );
			__temp_stmt256265 = ((int) (x) );
		}
		
		cn.sid = this._a(n, "sid", ( "node" + __temp_stmt256265 ));
		cn.id = this._a(n, "id", cn.sid);
		cn.name = this._a(n, "name", cn.sid);
		if (haxe.lang.Runtime.valEq(cn.sid, "")) 
		{
			cn.sid = cn.id;
		}
		
		cn.type = this._a(n, "type", "NODE").toLowerCase();
		cn.matrix = this._f32a(haxe.lang.Runtime.toString(this._p(n, "matrix.$text", "1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1", null, null)));
		cn.parent = p;
		cn.GenerateTranform();
		java.lang.Object iit = n.elements();
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(iit, "hasNext", null)))
		{
			haxe.root.Xml nin = ((haxe.root.Xml) (haxe.lang.Runtime.callField(iit, "next", null)) );
			haxor.io.file.ColladaInstance ni = null;
			{
				java.lang.String _g = nin.get_nodeName();
				{
					java.lang.String __temp_svar256266 = (_g);
					switch (__temp_svar256266.hashCode())
					{
						case -818152228:
						{
							if (__temp_svar256266.equals("instance_geometry")) 
							{
								ni = new haxor.io.file.ColladaInstance();
								ni.type = "geometry";
								ni.target = haxe.lang.StringExt.substr(this._a(nin, "url", ""), 1, null);
							}
							
							break;
						}
						
						
						case 96965648:
						{
							if (__temp_svar256266.equals("extra")) 
							{
								cn.data = haxe.lang.Runtime.toString(this._p(nin, "technique.user_properties.$text", "", null, null));
								if (( haxe.lang.StringExt.indexOf(cn.data, ";", null) < 0 )) 
								{
									cn.data = "";
								}
								
							}
							
							break;
						}
						
						
						case 168224134:
						{
							if (__temp_svar256266.equals("instance_controller")) 
							{
								ni = new haxor.io.file.ColladaInstance();
								ni.type = "controller";
								ni.target = haxe.lang.StringExt.substr(this._a(nin, "url", ""), 1, null);
							}
							
							break;
						}
						
						
						case 85436652:
						{
							if (__temp_svar256266.equals("instance_light")) 
							{
								ni = new haxor.io.file.ColladaInstance();
								ni.type = "light";
								ni.target = haxe.lang.StringExt.substr(this._a(nin, "url", ""), 1, null);
							}
							
							break;
						}
						
						
					}
					
				}
				
			}
			
			if (( ni != null )) 
			{
				cn.instances.push(ni);
			}
			
		}
		
		if (( p == null )) 
		{
			scn.children.push(cn);
		}
		 else 
		{
			p.children.push(cn);
		}
		
		return cn;
	}
	
	
	public   void ParseInstanceMaterials(haxor.io.file.ColladaInstance ci, haxe.root.Xml n)
	{
		{
		}
		
	}
	
	
	public   void ParseControllerLibrary(haxe.root.Xml n)
	{
		java.lang.Object it = n.elementsNamed("controller");
		haxor.io.file.ColladaController c = null;
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(it, "hasNext", null)))
		{
			n = ((haxe.root.Xml) (haxe.lang.Runtime.callField(it, "next", null)) );
			c = new haxor.io.file.ColladaController();
			c.id = this._a(n, "id", "none");
			c.name = this._a(n, "name", c.id);
			this.ParseController(c, n);
			this.controllers.push(c);
		}
		
	}
	
	
	public   void ParseController(haxor.io.file.ColladaController c, haxe.root.Xml n)
	{
		n = n.firstElement();
		if (( n == null )) 
		{
			return ;
		}
		
		if (( n.get_nodeName() == null )) 
		{
			c.type = "none";
		}
		 else 
		{
			c.type = n.get_nodeName().toLowerCase();
		}
		
		{
			java.lang.String _g = c.type;
			{
				java.lang.String __temp_svar256268 = (_g);
				switch (__temp_svar256268.hashCode())
				{
					case 3532157:
					{
						if (__temp_svar256268.equals("skin")) 
						{
							this.ParseControllerSkin(c, n);
						}
						
						break;
					}
					
					
					case 104083720:
					{
						if (__temp_svar256268.equals("morph")) 
						{
							{
							}
							
						}
						
						break;
					}
					
					
				}
				
			}
			
		}
		
	}
	
	
	public   void ParseControllerSkin(haxor.io.file.ColladaController c, haxe.root.Xml n)
	{
		c.source = haxe.lang.StringExt.substr(this._a(n, "source", ""), 1, null);
		c.matrix = this._f32a(haxe.lang.Runtime.toString(this._p(n, "bind_shape_matrix.$text", "", null, null)));
		java.lang.String source = "";
		haxe.root.Xml sn = null;
		haxe.root.Xml jn = null;
		if (( this._p(n, "joints", null, null, null) == null )) 
		{
			jn = null;
		}
		 else 
		{
			jn = ((haxe.root.Xml) (((java.lang.Object) (haxe.lang.Runtime.callField(this._p(n, "joints", null, null, null), "next", null)) )) );
		}
		
		if (( jn != null )) 
		{
			java.lang.Object jn_it = jn.elementsNamed("input");
			while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(jn_it, "hasNext", null)))
			{
				haxe.root.Xml jni = ((haxe.root.Xml) (haxe.lang.Runtime.callField(jn_it, "next", null)) );
				source = haxe.lang.StringExt.substr(this._a(jni, "source", ""), 1, null);
				if (haxe.lang.Runtime.valEq(source, "")) 
				{
					continue;
				}
				
				sn = this._f(n, "source", "id", source);
				if (( sn == null )) 
				{
					continue;
				}
				
				{
					java.lang.String _g = this._a(jni, "semantic", "").toLowerCase();
					{
						java.lang.String __temp_svar256271 = (_g);
						switch (__temp_svar256271.hashCode())
						{
							case 101304458:
							{
								if (__temp_svar256271.equals("joint")) 
								{
									java.lang.String __temp_stmt256270 = null;
									{
										java.lang.String s = haxe.root.StringTools.replace(haxe.lang.Runtime.toString(this._p(sn, "Name_array.$text", "", null, null)), "\n", " ");
										__temp_stmt256270 = s.trim();
									}
									
									c.joints = haxe.lang.StringExt.split(__temp_stmt256270, " ");
								}
								
								break;
							}
							
							
							case -1885129035:
							{
								if (__temp_svar256271.equals("inv_bind_matrix")) 
								{
									haxe.root.Array<java.lang.Object> ml = this._f32a(haxe.lang.Runtime.toString(this._p(sn, "float_array.$text", "", null, null)));
									while (( ml.length > 0 ))
									{
										haxe.root.Array<java.lang.Object> mtx = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
										{
											int _g1 = 0;
											while (( _g1 < 16 ))
											{
												int i = _g1++;
												mtx.push(ml.shift());
											}
											
										}
										
										c.binds.push(((haxe.root.Array) (mtx) ));
									}
									
								}
								
								break;
							}
							
							
						}
						
					}
					
				}
				
			}
			
		}
		
		haxe.root.Xml vwn = null;
		if (( this._p(n, "vertex_weights", null, null, null) == null )) 
		{
			vwn = null;
		}
		 else 
		{
			vwn = ((haxe.root.Xml) (((java.lang.Object) (haxe.lang.Runtime.callField(this._p(n, "vertex_weights", null, null, null), "next", null)) )) );
		}
		
		if (( vwn != null )) 
		{
			c.inputs = this.ParseInputList(n, vwn);
			c.vcount = this._i16a(haxe.lang.Runtime.toString(this._p(vwn, "vcount.$text", "", null, null)));
			java.lang.String vwb = haxe.lang.Runtime.toString(this._p(vwn, "v.$text", "", null, null));
			c.indexes = this._i16ta(vwb, c.get_offset());
		}
		
	}
	
	
	public   void ParseImageLibrary(haxe.root.Xml n)
	{
		java.lang.Object it = n.elementsNamed("image");
		haxor.io.file.ColladaImage img = null;
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(it, "hasNext", null)))
		{
			n = ((haxe.root.Xml) (haxe.lang.Runtime.callField(it, "next", null)) );
			img = new haxor.io.file.ColladaImage();
			img.id = this._a(n, "id", "none");
			img.name = this._a(n, "name", img.id);
			img.format = this._a(n, "format", "");
			img.width = ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(this._a(n, "width", "-1")))) );
			img.height = ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(this._a(n, "height", "-1")))) );
			img.depth = ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(this._a(n, "depth", "-1")))) );
			this.images.push(img);
		}
		
	}
	
	
	public   void ParseGeometryLibrary(haxe.root.Xml n)
	{
		java.lang.Object it = n.elementsNamed("geometry");
		haxor.io.file.ColladaGeometry g = null;
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(it, "hasNext", null)))
		{
			n = ((haxe.root.Xml) (haxe.lang.Runtime.callField(it, "next", null)) );
			g = new haxor.io.file.ColladaGeometry();
			g.id = this._a(n, "id", "none");
			g.name = this._a(n, "name", "none");
			this.ParseGeometry(g, n);
			this.geometries.push(g);
		}
		
	}
	
	
	public   void ParseGeometry(haxor.io.file.ColladaGeometry g, haxe.root.Xml n)
	{
		n = n.firstElement();
		if (( n == null )) 
		{
			return ;
		}
		
		g.mesh = new haxor.io.file.ColladaMesh();
		if (( n.get_nodeName() == null )) 
		{
			g.mesh.type = "none";
		}
		 else 
		{
			g.mesh.type = n.get_nodeName().toLowerCase();
		}
		
		{
			java.lang.String _g = g.mesh.type;
			{
				java.lang.String __temp_svar256273 = (_g);
				switch (__temp_svar256273.hashCode())
				{
					case 3347949:
					{
						if (__temp_svar256273.equals("mesh")) 
						{
							this.ParseMesh(g.mesh, n);
						}
						
						break;
					}
					
					
					case -895858735:
					{
						if (__temp_svar256273.equals("spline")) 
						{
							{
							}
							
						}
						
						break;
					}
					
					
					case -930854843:
					{
						if (__temp_svar256273.equals("convex_mesh")) 
						{
							{
							}
							
						}
						
						break;
					}
					
					
				}
				
			}
			
		}
		
	}
	
	
	public   void ParseMesh(haxor.io.file.ColladaMesh m, haxe.root.Xml n)
	{
		java.lang.Object it = n.elements();
		haxe.root.Xml p = n;
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(it, "hasNext", null)))
		{
			n = ((haxe.root.Xml) (haxe.lang.Runtime.callField(it, "next", null)) );
			if (haxe.lang.Runtime.valEq(n.get_nodeName(), "vertices")) 
			{
				continue;
			}
			
			if (haxe.lang.Runtime.valEq(n.get_nodeName(), "source")) 
			{
				continue;
			}
			
			haxor.io.file.ColladaPrimitive cp = new haxor.io.file.ColladaPrimitive();
			cp.type = n.get_nodeName();
			cp.material = this._a(n, "material", "");
			this.ParsePrimitive(cp, p, n);
			m.primitives.push(cp);
		}
		
	}
	
	
	public   void ParsePrimitive(haxor.io.file.ColladaPrimitive cp, haxe.root.Xml p, haxe.root.Xml n)
	{
		cp.inputs = this.ParseInputList(p, n);
		java.lang.Object p_it = n.elementsNamed("p");
		java.lang.Object vc_it = n.elementsNamed("vcount");
		if (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(vc_it, "hasNext", null))) 
		{
			haxe.root.Xml ncitn = ((haxe.root.Xml) (haxe.lang.Runtime.callField(vc_it, "next", null)) ).firstChild();
			if (( ncitn == null )) 
			{
				cp.vcount = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
			}
			 else 
			{
				cp.vcount = this._i16a(ncitn.toString());
			}
			
		}
		
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(p_it, "hasNext", null)))
		{
			haxe.root.Xml vn = ((haxe.root.Xml) (haxe.lang.Runtime.callField(p_it, "next", null)) );
			java.lang.String vb = null;
			if (( vn.firstChild() != null )) 
			{
				vb = vn.firstChild().toString();
			}
			 else 
			{
				vb = "0";
			}
			
			int off = cp.get_offset();
			haxe.root.Array<haxe.root.Array> ti = this._i16ta(vb, off);
			cp.indexes.push(((haxe.root.Array) (ti) ));
		}
		
	}
	
	
	public   haxe.root.Array<haxor.io.file.ColladaInput> ParseInputList(haxe.root.Xml p, haxe.root.Xml n)
	{
		haxe.root.Array<haxor.io.file.ColladaInput> l = new haxe.root.Array<haxor.io.file.ColladaInput>(new haxor.io.file.ColladaInput[]{});
		java.lang.Object it = n.elementsNamed("input");
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(it, "hasNext", null)))
		{
			haxe.root.Xml pi = ((haxe.root.Xml) (haxe.lang.Runtime.callField(it, "next", null)) );
			haxor.io.file.ColladaInput ci = new haxor.io.file.ColladaInput();
			java.lang.String source = this._a(pi, "source", "");
			ci.semantic = this._a(pi, "semantic", "").toLowerCase();
			ci.offset = ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(this._a(pi, "offset", "-1")))) );
			ci.set = ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(this._a(pi, "set", "-1")))) );
			if (haxe.lang.Runtime.valEq(ci.semantic, "joint")) 
			{
				l.push(ci);
				continue;
			}
			
			if (haxe.lang.Runtime.valEq(ci.semantic, "vertex")) 
			{
				source = haxe.lang.Runtime.toString(this._p(p, "vertices.input.@source", "", null, null));
			}
			
			if (haxe.lang.Runtime.valEq(source, "")) 
			{
				continue;
			}
			
			source = haxe.lang.StringExt.substr(source, 1, null);
			haxe.root.Xml sn = this._f(p, "source", "id", source);
			if (( sn == null )) 
			{
				continue;
			}
			
			java.lang.String stride_str = haxe.lang.Runtime.toString(this._p(sn, "technique_common.accessor.@stride", "0", null, null));
			ci.stride = ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(stride_str))) );
			ci.values = ((haxe.root.Array) (this._f32a(haxe.lang.Runtime.toString(this._p(sn, "float_array.$text", "", null, null)))) );
			l.push(ci);
		}
		
		return l;
	}
	
	
	@Override public   void TraverseStep(haxe.root.Xml n)
	{
		this.Parse(n);
		java.lang.Object l = n.elements();
		while (haxe.lang.Runtime.toBool(haxe.lang.Runtime.callField(l, "hasNext", null)))
		{
			this.TraverseStep(((haxe.root.Xml) (haxe.lang.Runtime.callField(l, "next", null)) ));
		}
		
	}
	
	
	public   haxe.root.Array<java.lang.Object> _f32a(java.lang.String v)
	{
		java.lang.String __temp_stmt256275 = null;
		{
			java.lang.String s = haxe.root.StringTools.replace(v, "\n", " ");
			__temp_stmt256275 = s.trim();
		}
		
		haxe.root.Array<java.lang.String> l = haxe.lang.StringExt.split(__temp_stmt256275, " ");
		haxe.root.Array<java.lang.Object> a = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		{
			int _g1 = 0;
			int _g = l.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				a.push(haxe.root.Std.parseFloat(l.__get(i)));
			}
			
		}
		
		return a;
	}
	
	
	public   haxe.root.Array<java.lang.Object> _i16a(java.lang.String v)
	{
		java.lang.String __temp_stmt256276 = null;
		{
			java.lang.String s = haxe.root.StringTools.replace(v, "\n", " ");
			__temp_stmt256276 = s.trim();
		}
		
		haxe.root.Array<java.lang.String> l = haxe.lang.StringExt.split(__temp_stmt256276, " ");
		haxe.root.Array<java.lang.Object> a = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		{
			int _g1 = 0;
			int _g = l.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				a.push(haxe.root.Std.parseInt(l.__get(i)));
			}
			
		}
		
		return a;
	}
	
	
	public   haxe.root.Array<haxe.root.Array> _i16ta(java.lang.String v, int s)
	{
		java.lang.String __temp_stmt256277 = null;
		{
			java.lang.String s1 = haxe.root.StringTools.replace(v, "\n", " ");
			__temp_stmt256277 = s1.trim();
		}
		
		haxe.root.Array<java.lang.String> l = haxe.lang.StringExt.split(__temp_stmt256277, " ");
		java.lang.String tl = "";
		haxe.root.Array<haxe.root.Array> a = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{});
		haxe.root.Array<java.lang.Object> bf = null;
		int k = 0;
		while (( k < l.length ))
		{
			bf = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
			{
				int _g = 0;
				while (( _g < s ))
				{
					int j = _g++;
					bf.push(haxe.root.Std.parseInt(l.__get(k++)));
				}
				
			}
			
			a.push(((haxe.root.Array) (bf) ));
		}
		
		return a;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256278 = true;
			switch (field.hashCode())
			{
				case 3341869:
				{
					if (field.equals("m_id")) 
					{
						__temp_executeDef256278 = false;
						this.m_id = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256278) 
			{
				return super.__hx_setField_f(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256279 = true;
			switch (field.hashCode())
			{
				case 3341869:
				{
					if (field.equals("m_id")) 
					{
						__temp_executeDef256279 = false;
						this.m_id = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 114177052:
				{
					if (field.equals("xmlns")) 
					{
						__temp_executeDef256279 = false;
						this.xmlns = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 109254796:
				{
					if (field.equals("scene")) 
					{
						__temp_executeDef256279 = false;
						this.scene = ((haxor.io.file.ColladaVisualScene) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 351608024:
				{
					if (field.equals("version")) 
					{
						__temp_executeDef256279 = false;
						this.version = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 314070383:
				{
					if (field.equals("animations")) 
					{
						__temp_executeDef256279 = false;
						this.animations = ((haxe.root.Array<haxor.io.file.ColladaAnimation>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef256279 = false;
						this.data = ((haxor.io.file.ColladaAssetData) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1102877155:
				{
					if (field.equals("lights")) 
					{
						__temp_executeDef256279 = false;
						this.lights = ((haxe.root.Array<haxor.io.file.ColladaLight>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 203916432:
				{
					if (field.equals("geometries")) 
					{
						__temp_executeDef256279 = false;
						this.geometries = ((haxe.root.Array<haxor.io.file.ColladaGeometry>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 681132076:
				{
					if (field.equals("materials")) 
					{
						__temp_executeDef256279 = false;
						this.materials = ((haxe.root.Array<haxor.io.file.ColladaMaterial>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1185250696:
				{
					if (field.equals("images")) 
					{
						__temp_executeDef256279 = false;
						this.images = ((haxe.root.Array<haxor.io.file.ColladaImage>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1714548649:
				{
					if (field.equals("controllers")) 
					{
						__temp_executeDef256279 = false;
						this.controllers = ((haxe.root.Array<haxor.io.file.ColladaController>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256279) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256280 = true;
			switch (field.hashCode())
			{
				case -1476712900:
				{
					if (field.equals("_i16ta")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("_i16ta"))) );
					}
					
					break;
				}
				
				
				case 114177052:
				{
					if (field.equals("xmlns")) 
					{
						__temp_executeDef256280 = false;
						return this.xmlns;
					}
					
					break;
				}
				
				
				case 90911410:
				{
					if (field.equals("_i16a")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("_i16a"))) );
					}
					
					break;
				}
				
				
				case 351608024:
				{
					if (field.equals("version")) 
					{
						__temp_executeDef256280 = false;
						return this.version;
					}
					
					break;
				}
				
				
				case 90823835:
				{
					if (field.equals("_f32a")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("_f32a"))) );
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef256280 = false;
						return this.data;
					}
					
					break;
				}
				
				
				case 265423742:
				{
					if (field.equals("TraverseStep")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TraverseStep"))) );
					}
					
					break;
				}
				
				
				case 203916432:
				{
					if (field.equals("geometries")) 
					{
						__temp_executeDef256280 = false;
						return this.geometries;
					}
					
					break;
				}
				
				
				case -2098023883:
				{
					if (field.equals("ParseInputList")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseInputList"))) );
					}
					
					break;
				}
				
				
				case -1185250696:
				{
					if (field.equals("images")) 
					{
						__temp_executeDef256280 = false;
						return this.images;
					}
					
					break;
				}
				
				
				case -1344587884:
				{
					if (field.equals("ParsePrimitive")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParsePrimitive"))) );
					}
					
					break;
				}
				
				
				case -1714548649:
				{
					if (field.equals("controllers")) 
					{
						__temp_executeDef256280 = false;
						return this.controllers;
					}
					
					break;
				}
				
				
				case 170668832:
				{
					if (field.equals("ParseMesh")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseMesh"))) );
					}
					
					break;
				}
				
				
				case 681132076:
				{
					if (field.equals("materials")) 
					{
						__temp_executeDef256280 = false;
						return this.materials;
					}
					
					break;
				}
				
				
				case 1861833765:
				{
					if (field.equals("ParseGeometry")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseGeometry"))) );
					}
					
					break;
				}
				
				
				case -1102877155:
				{
					if (field.equals("lights")) 
					{
						__temp_executeDef256280 = false;
						return this.lights;
					}
					
					break;
				}
				
				
				case -900963114:
				{
					if (field.equals("ParseGeometryLibrary")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseGeometryLibrary"))) );
					}
					
					break;
				}
				
				
				case 314070383:
				{
					if (field.equals("animations")) 
					{
						__temp_executeDef256280 = false;
						return this.animations;
					}
					
					break;
				}
				
				
				case 2025791763:
				{
					if (field.equals("ParseImageLibrary")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseImageLibrary"))) );
					}
					
					break;
				}
				
				
				case 109254796:
				{
					if (field.equals("scene")) 
					{
						__temp_executeDef256280 = false;
						return this.scene;
					}
					
					break;
				}
				
				
				case -1420097364:
				{
					if (field.equals("ParseControllerSkin")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseControllerSkin"))) );
					}
					
					break;
				}
				
				
				case 3341869:
				{
					if (field.equals("m_id")) 
					{
						__temp_executeDef256280 = false;
						return this.m_id;
					}
					
					break;
				}
				
				
				case -1345614193:
				{
					if (field.equals("ParseController")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseController"))) );
					}
					
					break;
				}
				
				
				case 1130071239:
				{
					if (field.equals("get_asset")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_asset"))) );
					}
					
					break;
				}
				
				
				case 1621196588:
				{
					if (field.equals("ParseControllerLibrary")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseControllerLibrary"))) );
					}
					
					break;
				}
				
				
				case 1133069520:
				{
					if (field.equals("AddAnimations")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("AddAnimations"))) );
					}
					
					break;
				}
				
				
				case -846769980:
				{
					if (field.equals("ParseInstanceMaterials")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseInstanceMaterials"))) );
					}
					
					break;
				}
				
				
				case -930900724:
				{
					if (field.equals("CreateMeshRenderer")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateMeshRenderer"))) );
					}
					
					break;
				}
				
				
				case -388724165:
				{
					if (field.equals("ParseVisualSceneNode")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseVisualSceneNode"))) );
					}
					
					break;
				}
				
				
				case 1726891055:
				{
					if (field.equals("FindLightById")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FindLightById"))) );
					}
					
					break;
				}
				
				
				case 1648189079:
				{
					if (field.equals("TraverseVisualSceneNodes")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TraverseVisualSceneNodes"))) );
					}
					
					break;
				}
				
				
				case 1817317341:
				{
					if (field.equals("FindGeometryById")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FindGeometryById"))) );
					}
					
					break;
				}
				
				
				case 1615944857:
				{
					if (field.equals("ParseVisualScene")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseVisualScene"))) );
					}
					
					break;
				}
				
				
				case 319065031:
				{
					if (field.equals("FindControllerById")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FindControllerById"))) );
					}
					
					break;
				}
				
				
				case -742037310:
				{
					if (field.equals("ParseSceneLibrary")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseSceneLibrary"))) );
					}
					
					break;
				}
				
				
				case 1433244141:
				{
					if (field.equals("FindNodeById")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FindNodeById"))) );
					}
					
					break;
				}
				
				
				case -1166654847:
				{
					if (field.equals("ParseMaterialLibrary")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseMaterialLibrary"))) );
					}
					
					break;
				}
				
				
				case 1292241426:
				{
					if (field.equals("FindMaterialById")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FindMaterialById"))) );
					}
					
					break;
				}
				
				
				case 1815891274:
				{
					if (field.equals("ParseAnimationLibrary")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseAnimationLibrary"))) );
					}
					
					break;
				}
				
				
				case 76884627:
				{
					if (field.equals("Parse")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Parse"))) );
					}
					
					break;
				}
				
				
				case -1603273480:
				{
					if (field.equals("ParseLightLibrary")) 
					{
						__temp_executeDef256280 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ParseLightLibrary"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256280) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256281 = true;
			switch (field.hashCode())
			{
				case 3341869:
				{
					if (field.equals("m_id")) 
					{
						__temp_executeDef256281 = false;
						return ((double) (this.m_id) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256281) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			int __temp_hash256283 = field.hashCode();
			boolean __temp_executeDef256282 = true;
			switch (__temp_hash256283)
			{
				case 265423742:case 76884627:case 1130071239:
				{
					if (( (( ( __temp_hash256283 == 265423742 ) && field.equals("TraverseStep") )) || ( (( ( __temp_hash256283 == 76884627 ) && field.equals("Parse") )) || field.equals("get_asset") ) )) 
					{
						__temp_executeDef256282 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1133069520:
				{
					if (field.equals("AddAnimations")) 
					{
						__temp_executeDef256282 = false;
						this.AddAnimations(((haxor.core.Entity) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case -1476712900:
				{
					if (field.equals("_i16ta")) 
					{
						__temp_executeDef256282 = false;
						return this._i16ta(haxe.lang.Runtime.toString(dynargs.__get(0)), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -930900724:
				{
					if (field.equals("CreateMeshRenderer")) 
					{
						__temp_executeDef256282 = false;
						return this.CreateMeshRenderer(((haxor.core.Entity) (dynargs.__get(0)) ), haxe.lang.Runtime.toString(dynargs.__get(1)), ((haxor.io.file.ColladaPrimitive) (dynargs.__get(2)) ), ((java.lang.Class<haxor.component.Component>) (dynargs.__get(3)) ), ((haxor.io.file.ColladaController) (dynargs.__get(4)) ));
					}
					
					break;
				}
				
				
				case 90911410:
				{
					if (field.equals("_i16a")) 
					{
						__temp_executeDef256282 = false;
						return this._i16a(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1726891055:
				{
					if (field.equals("FindLightById")) 
					{
						__temp_executeDef256282 = false;
						return this.FindLightById(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 90823835:
				{
					if (field.equals("_f32a")) 
					{
						__temp_executeDef256282 = false;
						return this._f32a(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1817317341:
				{
					if (field.equals("FindGeometryById")) 
					{
						__temp_executeDef256282 = false;
						return this.FindGeometryById(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -2098023883:
				{
					if (field.equals("ParseInputList")) 
					{
						__temp_executeDef256282 = false;
						return this.ParseInputList(((haxe.root.Xml) (dynargs.__get(0)) ), ((haxe.root.Xml) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 319065031:
				{
					if (field.equals("FindControllerById")) 
					{
						__temp_executeDef256282 = false;
						return this.FindControllerById(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1344587884:
				{
					if (field.equals("ParsePrimitive")) 
					{
						__temp_executeDef256282 = false;
						this.ParsePrimitive(((haxor.io.file.ColladaPrimitive) (dynargs.__get(0)) ), ((haxe.root.Xml) (dynargs.__get(1)) ), ((haxe.root.Xml) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case 1433244141:
				{
					if (field.equals("FindNodeById")) 
					{
						__temp_executeDef256282 = false;
						return this.FindNodeById(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 170668832:
				{
					if (field.equals("ParseMesh")) 
					{
						__temp_executeDef256282 = false;
						this.ParseMesh(((haxor.io.file.ColladaMesh) (dynargs.__get(0)) ), ((haxe.root.Xml) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1292241426:
				{
					if (field.equals("FindMaterialById")) 
					{
						__temp_executeDef256282 = false;
						return this.FindMaterialById(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1861833765:
				{
					if (field.equals("ParseGeometry")) 
					{
						__temp_executeDef256282 = false;
						this.ParseGeometry(((haxor.io.file.ColladaGeometry) (dynargs.__get(0)) ), ((haxe.root.Xml) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -1603273480:
				{
					if (field.equals("ParseLightLibrary")) 
					{
						__temp_executeDef256282 = false;
						this.ParseLightLibrary(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -900963114:
				{
					if (field.equals("ParseGeometryLibrary")) 
					{
						__temp_executeDef256282 = false;
						this.ParseGeometryLibrary(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1815891274:
				{
					if (field.equals("ParseAnimationLibrary")) 
					{
						__temp_executeDef256282 = false;
						this.ParseAnimationLibrary(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2025791763:
				{
					if (field.equals("ParseImageLibrary")) 
					{
						__temp_executeDef256282 = false;
						this.ParseImageLibrary(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1166654847:
				{
					if (field.equals("ParseMaterialLibrary")) 
					{
						__temp_executeDef256282 = false;
						this.ParseMaterialLibrary(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1420097364:
				{
					if (field.equals("ParseControllerSkin")) 
					{
						__temp_executeDef256282 = false;
						this.ParseControllerSkin(((haxor.io.file.ColladaController) (dynargs.__get(0)) ), ((haxe.root.Xml) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -742037310:
				{
					if (field.equals("ParseSceneLibrary")) 
					{
						__temp_executeDef256282 = false;
						this.ParseSceneLibrary(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1345614193:
				{
					if (field.equals("ParseController")) 
					{
						__temp_executeDef256282 = false;
						this.ParseController(((haxor.io.file.ColladaController) (dynargs.__get(0)) ), ((haxe.root.Xml) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1615944857:
				{
					if (field.equals("ParseVisualScene")) 
					{
						__temp_executeDef256282 = false;
						this.ParseVisualScene(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1621196588:
				{
					if (field.equals("ParseControllerLibrary")) 
					{
						__temp_executeDef256282 = false;
						this.ParseControllerLibrary(((haxe.root.Xml) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1648189079:
				{
					if (field.equals("TraverseVisualSceneNodes")) 
					{
						__temp_executeDef256282 = false;
						this.TraverseVisualSceneNodes(((haxor.io.file.ColladaVisualScene) (dynargs.__get(0)) ), ((haxor.io.file.ColladaNode) (dynargs.__get(1)) ), ((haxe.root.Xml) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case -846769980:
				{
					if (field.equals("ParseInstanceMaterials")) 
					{
						__temp_executeDef256282 = false;
						this.ParseInstanceMaterials(((haxor.io.file.ColladaInstance) (dynargs.__get(0)) ), ((haxe.root.Xml) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -388724165:
				{
					if (field.equals("ParseVisualSceneNode")) 
					{
						__temp_executeDef256282 = false;
						return this.ParseVisualSceneNode(((haxor.io.file.ColladaVisualScene) (dynargs.__get(0)) ), ((haxor.io.file.ColladaNode) (dynargs.__get(1)) ), ((haxe.root.Xml) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256282) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_id");
		baseArr.push("scene");
		baseArr.push("animations");
		baseArr.push("lights");
		baseArr.push("materials");
		baseArr.push("controllers");
		baseArr.push("images");
		baseArr.push("geometries");
		baseArr.push("data");
		baseArr.push("version");
		baseArr.push("xmlns");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


