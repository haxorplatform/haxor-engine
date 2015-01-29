package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaFile_get_asset_188__Fun extends haxe.lang.Function
{
	public    ColladaFile_get_asset_188__Fun(haxe.root.Array<haxe.root.Array> skinned_meshes, haxe.root.Array<haxor.io.file.ColladaFile> _g3, haxe.root.Array<haxe.ds.ObjectMap> hm, haxe.root.Array<haxe.ds.ObjectMap> cm, haxe.root.Array<haxe.root.Array> joint_transforms, haxe.root.Array<haxe.ds.ObjectMap> mm, haxe.root.Array<haxor.core.Entity> re, haxe.root.Array<haxe.root.Array> joint_nodes)
	{
		super(1, 0);
		this.skinned_meshes = skinned_meshes;
		this._g3 = _g3;
		this.hm = hm;
		this.cm = cm;
		this.joint_transforms = joint_transforms;
		this.mm = mm;
		this.re = re;
		this.joint_nodes = joint_nodes;
	}
	
	
	@Override public   java.lang.Object __hx_invoke1_o(double __fn_float1, java.lang.Object __fn_dyn1)
	{
		haxor.io.file.ColladaNode n = ( (( __fn_dyn1 == haxe.lang.Runtime.undefined )) ? (((haxor.io.file.ColladaNode) (((java.lang.Object) (__fn_float1) )) )) : (((haxor.io.file.ColladaNode) (__fn_dyn1) )) );
		haxor.core.Entity pe = null;
		if (( n.parent == null )) 
		{
			pe = this.re.__get(0);
		}
		 else 
		{
			if (((haxe.ds.ObjectMap<haxor.io.file.ColladaNode, haxor.core.Entity>) (((haxe.ds.ObjectMap) (this.hm.__get(0)) )) ).exists(n.parent)) 
			{
				pe = ((haxe.ds.ObjectMap<haxor.io.file.ColladaNode, haxor.core.Entity>) (((haxe.ds.ObjectMap) (this.hm.__get(0)) )) ).get(n.parent);
			}
			 else 
			{
				pe = this.re.__get(0);
			}
			
		}
		
		haxor.core.Entity ne = null;
		if (haxe.lang.Runtime.valEq(n.name, "EnvironmentAmbientLight")) 
		{
			return null;
		}
		
		ne = new haxor.core.Entity(haxe.lang.Runtime.toString(null));
		ne.set_name(( "node" + ne.get_uid() ));
		if ( ! (haxe.lang.Runtime.valEq(n.sid, "")) ) 
		{
			ne.set_name(n.sid);
		}
		 else 
		{
			if ( ! (haxe.lang.Runtime.valEq(n.id, "")) ) 
			{
				ne.set_name(n.id);
			}
			 else 
			{
				if ( ! (haxe.lang.Runtime.valEq(n.name, "")) ) 
				{
					ne.set_name(n.name);
				}
				
			}
			
		}
		
		if (haxe.lang.Runtime.valEq(n.type, "joint")) 
		{
			((haxe.root.Array<haxor.component.Transform>) (((haxe.root.Array) (this.joint_transforms.__get(0)) )) ).push(ne.m_transform);
			((haxe.root.Array<haxor.io.file.ColladaNode>) (((haxe.root.Array) (this.joint_nodes.__get(0)) )) ).push(n);
		}
		
		ne.m_transform.set_parent(pe.m_transform);
		ne.m_transform.set_localPosition(n.position);
		ne.m_transform.set_localRotation(n.rotation);
		ne.m_transform.set_localScale(n.scale);
		if ( ! (haxe.lang.Runtime.valEq(n.data, "")) ) 
		{
			haxor.component.DataComponent ad = ((haxor.component.DataComponent) (ne.AddComponent(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.DataComponent.class) )) ))) );
			try 
			{
				ad.data = new haxe.format.JsonParser(haxe.lang.Runtime.toString(n.data)).parseRec();
			}
			catch (java.lang.Throwable __temp_catchallException1158)
			{
				java.lang.Object __temp_catchall1159 = __temp_catchallException1158;
				if (( __temp_catchall1159 instanceof haxe.lang.HaxeException )) 
				{
					__temp_catchall1159 = ((haxe.lang.HaxeException) (__temp_catchallException1158) ).obj;
				}
				
				{
					java.lang.Object err = __temp_catchall1159;
					{
					}
					
				}
				
			}
			
			
		}
		
		((haxe.ds.ObjectMap<haxor.io.file.ColladaNode, haxor.core.Entity>) (((haxe.ds.ObjectMap) (this.hm.__get(0)) )) ).set(n, ne);
		{
			int _g11 = 0;
			int _g4 = n.instances.length;
			while (( _g11 < _g4 ))
			{
				int i2 = _g11++;
				haxor.io.file.ColladaInstance ci = n.instances.__get(i2);
				haxor.component.MeshRenderer mr = null;
				haxor.io.file.ColladaMaterial cmat = null;
				haxor.io.file.ColladaGeometry cg = null;
				haxor.io.file.ColladaController cc = null;
				java.lang.String cg_target = "";
				{
					java.lang.String _g21 = ci.type;
					{
						java.lang.String __temp_svar1162 = (_g21);
						switch (__temp_svar1162.hashCode())
						{
							case 102970646:
							{
								if (__temp_svar1162.equals("light")) 
								{
									haxor.io.file.ColladaLight cl = this._g3.__get(0).FindLightById(ci.target);
									if (( cl == null )) 
									{
										continue;
									}
									
									{
										java.lang.String _g41 = cl.type;
										{
											java.lang.String __temp_svar1160 = (_g41);
											switch (__temp_svar1160.hashCode())
											{
												case -892145000:
												{
													if (__temp_svar1160.equals("ambient")) 
													{
														{
														}
														
													}
													
													break;
												}
												
												
												case -1631834134:
												{
													if (__temp_svar1160.equals("directional")) 
													{
														{
														}
														
													}
													
													break;
												}
												
												
												case 106845584:
												{
													if (__temp_svar1160.equals("point")) 
													{
														haxor.component.light.PointLight pl = ((haxor.component.light.PointLight) (ne.AddComponent(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.light.PointLight.class) )) ))) );
														pl.color.SetColor(cl.color);
														pl.intensity = cl.intensity;
														pl.radius = ( cl.radius * 2.0 );
														pl.atten = cl.atten;
													}
													
													break;
												}
												
												
											}
											
										}
										
									}
									
									continue;
								}
								
								break;
							}
							
							
							case 637428636:
							{
								if (__temp_svar1162.equals("controller")) 
								{
									cc = this._g3.__get(0).FindControllerById(ci.target);
									if (( cc != null )) 
									{
										((haxe.ds.ObjectMap<haxor.component.Transform, haxor.io.file.ColladaController>) (((haxe.ds.ObjectMap) (this.cm.__get(0)) )) ).set(ne.m_transform, cc);
										cg_target = cc.source;
									}
									
								}
								
								break;
							}
							
							
							case 1846020210:
							{
								if (__temp_svar1162.equals("geometry")) 
								{
									cg_target = ci.target;
								}
								
								break;
							}
							
							
						}
						
					}
					
				}
				
				cg = this._g3.__get(0).FindGeometryById(cg_target);
				if (( cg != null )) 
				{
					int _g42 = 0;
					int _g22 = cg.mesh.primitives.length;
					while (( _g42 < _g22 ))
					{
						int i3 = _g42++;
						java.lang.String mn1 = cg.mesh.primitives.__get(i3).material;
						cmat = this._g3.__get(0).FindMaterialById(mn1);
						mr = this._g3.__get(0).CreateMeshRenderer(ne, cg_target, cg.mesh.primitives.__get(i3), ( (( cc == null )) ? (((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.MeshRenderer.class) )) )) : (((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.SkinnedMeshRenderer.class) )) )) ), cc);
						if (( cc != null )) 
						{
							((haxe.root.Array<haxor.component.SkinnedMeshRenderer>) (((haxe.root.Array) (this.skinned_meshes.__get(0)) )) ).push(((haxor.component.SkinnedMeshRenderer) (mr) ));
						}
						
						if (( cmat != null )) 
						{
							mr.set_material(( (((haxe.ds.ObjectMap<haxor.io.file.ColladaMaterial, haxor.graphics.material.Material>) (((haxe.ds.ObjectMap) (this.mm.__get(0)) )) ).exists(cmat)) ? (((haxe.ds.ObjectMap<haxor.io.file.ColladaMaterial, haxor.graphics.material.Material>) (((haxe.ds.ObjectMap) (this.mm.__get(0)) )) ).get(cmat)) : (mr.m_material) ));
						}
						 else 
						{
							{
								int _g5 = 0;
								while (( _g5 < 10 ))
								{
									int i4 = _g5++;
									mn1 = haxe.root.StringTools.replace(mn1, ( "_" + i4 ), "");
								}
								
							}
							
							mn1 = haxe.root.StringTools.replace(mn1, "_", "/");
							haxor.graphics.material.Material mat1 = ((haxor.graphics.material.Material) (haxor.io.file.Asset.Get(mn1)) );
							mr.set_material(mat1);
						}
						
					}
					
				}
				
			}
			
		}
		
		return null;
	}
	
	
	public  haxe.root.Array<haxe.root.Array> skinned_meshes;
	
	public  haxe.root.Array<haxor.io.file.ColladaFile> _g3;
	
	public  haxe.root.Array<haxe.ds.ObjectMap> hm;
	
	public  haxe.root.Array<haxe.ds.ObjectMap> cm;
	
	public  haxe.root.Array<haxe.root.Array> joint_transforms;
	
	public  haxe.root.Array<haxe.ds.ObjectMap> mm;
	
	public  haxe.root.Array<haxor.core.Entity> re;
	
	public  haxe.root.Array<haxe.root.Array> joint_nodes;
	
}


