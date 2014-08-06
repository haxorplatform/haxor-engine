package haxor.platform;





#if html


typedef ArrayBuffer		= js.html.ArrayBufferView;
typedef Float32Buffer 	= js.html.Float32Array;
typedef Floa64Buffer 	= js.html.Float64Array;
typedef Int16Buffer		= js.html.Int16Array;
typedef Int32Buffer		= js.html.Int32Array;
typedef UInt16Buffer	= js.html.Uint16Array;
typedef UInt32Buffer	= js.html.Uint32Array;


typedef MeshBufferId    = js.html.webgl.Buffer;
typedef TextureId    	= js.html.webgl.Texture;

#end


#if android

typedef ArrayBuffer		= java.nio.ByteBuffer;
typedef Float32Buffer	= java.nio.FloatBuffer;
typedef Floa64Buffer 	= java.nio.DoubleBuffer;
typedef Int16Buffer 	= java.nio.ShortBuffer;
typedef Int32Buffer 	= java.nio.IntBuffer;
typedef UInt16Buffer	= java.nio.ShortBuffer;
typedef UInt32Buffer	= java.nio.IntBuffer;

typedef MeshBufferId    = Int;

typedef TextureId    	= Int;

#end


#if windows

typedef ArrayBuffer		= cpp.Pointer<Void>;
typedef Float32Buffer	= cpp.Pointer<Float>;
typedef Floa64Buffer 	= cpp.Pointer<Float>;
typedef Int16Buffer 	= cpp.Pointer<Int>;
typedef Int32Buffer 	= cpp.Pointer<Int>;
typedef UInt16Buffer	= cpp.Pointer<UInt>;
typedef UInt32Buffer	= cpp.Pointer<UInt>;
//*/
typedef MeshBufferId    = Int;

typedef TextureId    	= Int;

#end