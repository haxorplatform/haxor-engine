package haxor.platform;



#if html

typedef BitmapFile		= js.html.Image;
typedef ArrayBuffer		= js.html.Uint8ClampedArray;
typedef MeshBufferId    = js.html.webgl.Buffer;
typedef TextureId    	= js.html.webgl.Texture;
typedef ShaderId		= js.html.webgl.Shader;
typedef ProgramId		= js.html.webgl.Program;

#end


#if android

#if gles3
typedef GLES = android.opengl.GLES30;
#else
typedef GLES = android.opengl.GLES20;
#end

typedef BitmapFile		= haxor.io.Buffer;

typedef ArrayBuffer		= java.nio.ByteBuffer;
typedef MeshBufferId    = Int;
typedef TextureId    	= Int;
typedef ShaderId		= Int;
typedef ProgramId		= Int;

#end

#if ios

#end


#if (windows || osx || linux)

typedef BitmapFile		= haxor.io.Buffer;

typedef ArrayBuffer		= haxe.io.Bytes;
typedef MeshBufferId    = Int;
typedef TextureId    	= Int;
typedef ShaderId		= Int;
typedef ProgramId		= Int;

#end