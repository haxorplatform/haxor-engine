package haxor.platform;



#if (html||nodejs)

#if ie8
typedef ArrayBuffer		= Dynamic;
#else
typedef ArrayBuffer		= js.html.Uint8Array;
#end

typedef MeshBufferId    = js.html.webgl.Buffer;
typedef VAOId    		= Dynamic;
typedef TextureId    	= js.html.webgl.Texture;
typedef FrameBufferId  	= js.html.webgl.Framebuffer;
typedef RenderBufferId  = js.html.webgl.Renderbuffer;
typedef ShaderId		= js.html.webgl.Shader;
typedef ProgramId		= js.html.webgl.Program;
typedef UniformLocation = js.html.webgl.UniformLocation;
typedef Float32			= Float;
typedef Float64			= Float;

#end


#if android

#if gles3
typedef GLES = android.opengl.GLES30;
#else
typedef GLES = android.opengl.GLES20;
#end

typedef ArrayBuffer		= java.nio.ByteBuffer;
typedef MeshBufferId    = Int;
typedef VAOId    		= Int;
typedef TextureId    	= Int;
typedef FrameBufferId  	= Int;
typedef RenderBufferId  = Int;
typedef ShaderId		= Int;
typedef ProgramId		= Int;
typedef UniformLocation = Int;
typedef Float32			= Float;
typedef Float64			= Float;
#end

#if ios

#end



#if (windows || osx || linux)

typedef ArrayBuffer		= haxe.io.Bytes;
typedef MeshBufferId    = Int;
typedef VAOId    		= Int;
typedef TextureId    	= Int;
typedef FrameBufferId  	= Int;
typedef RenderBufferId  = Int;
typedef ShaderId		= Int;
typedef ProgramId		= Int;
typedef UniformLocation = Int;
typedef Float32			= Float;
typedef Float64			= Float;
#end