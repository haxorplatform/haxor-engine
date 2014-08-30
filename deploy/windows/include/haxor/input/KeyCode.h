#ifndef INCLUDED_haxor_input_KeyCode
#define INCLUDED_haxor_input_KeyCode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,input,KeyCode)
namespace haxor{
namespace input{


class HXCPP_CLASS_ATTRIBUTES  KeyCode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef KeyCode_obj OBJ_;
		KeyCode_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< KeyCode_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~KeyCode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("KeyCode"); }

		static int Modifiers;
		static int None;
		static int Mouse0;
		static int Mouse1;
		static int Cancel;
		static int Mouse2;
		static int Mouse3;
		static int Mouse4;
		static int Back;
		static int Tab;
		static int LineFeed;
		static int Clear;
		static int Enter;
		static int Return;
		static int ShiftKey;
		static int ControlKey;
		static int Alt;
		static int Pause;
		static int CapsLock;
		static int Capital;
		static int KanaMode;
		static int HanguelMode;
		static int HangulMode;
		static int JunjaMode;
		static int FinalMode;
		static int KanjiMode;
		static int HanjaMode;
		static int Escape;
		static int IMEConvert;
		static int IMENonconvert;
		static int IMEAceept;
		static int IMEAccept;
		static int IMEModeChange;
		static int Space;
		static int Prior;
		static int PageUp;
		static int Next;
		static int PageDown;
		static int End;
		static int Home;
		static int Left;
		static int Up;
		static int Right;
		static int Down;
		static int Select;
		static int Print;
		static int Execute;
		static int PrintScreen;
		static int Snapshot;
		static int Insert;
		static int Delete;
		static int Help;
		static int D0;
		static int D1;
		static int D2;
		static int D3;
		static int D4;
		static int D5;
		static int D6;
		static int D7;
		static int D8;
		static int D9;
		static int A;
		static int B;
		static int C;
		static int D;
		static int E;
		static int F;
		static int G;
		static int H;
		static int I;
		static int J;
		static int K;
		static int L;
		static int M;
		static int N;
		static int O;
		static int P;
		static int Q;
		static int R;
		static int S;
		static int T;
		static int U;
		static int V;
		static int W;
		static int X;
		static int Y;
		static int Z;
		static int LWin;
		static int RWin;
		static int Apps;
		static int Sleep;
		static int NumPad0;
		static int NumPad1;
		static int NumPad2;
		static int NumPad3;
		static int NumPad4;
		static int NumPad5;
		static int NumPad6;
		static int NumPad7;
		static int NumPad8;
		static int NumPad9;
		static int Multiply;
		static int Add;
		static int Separator;
		static int Subtract;
		static int Decimal;
		static int Divide;
		static int F1;
		static int F2;
		static int F3;
		static int F4;
		static int F5;
		static int F6;
		static int F7;
		static int F8;
		static int F9;
		static int F10;
		static int F11;
		static int F12;
		static int F13;
		static int F14;
		static int F15;
		static int F16;
		static int F17;
		static int F18;
		static int F19;
		static int F20;
		static int F21;
		static int F22;
		static int F23;
		static int F24;
		static int NumLock;
		static int Scroll;
		static int LShiftKey;
		static int RShiftKey;
		static int LControlKey;
		static int RControlKey;
		static int LAlt;
		static int RAlt;
		static int BrowserBack;
		static int BrowserForward;
		static int BrowserRefresh;
		static int BrowserStop;
		static int BrowserSearch;
		static int BrowserFavorites;
		static int BrowserHome;
		static int VolumeMute;
		static int VolumeDown;
		static int VolumeUp;
		static int MediaNextTrack;
		static int MediaPreviousTrack;
		static int MediaStop;
		static int MediaPlayPause;
		static int LaunchMail;
		static int SelectMedia;
		static int LaunchApplication1;
		static int LaunchApplication2;
		static int Oem1;
		static int OemSemicolon;
		static int Oemplus;
		static int Oemcomma;
		static int OemMinus;
		static int OemPeriod;
		static int OemQuestion;
		static int Oem2;
		static int Oemtilde;
		static int Oem3;
		static int Oem4;
		static int OemOpenBrackets;
		static int OemPipe;
		static int Oem5;
		static int Oem6;
		static int OemCloseBrackets;
		static int Oem7;
		static int OemQuotes;
		static int Oem8;
		static int Oem102;
		static int OemBackslash;
		static int ProcessKey;
		static int Packet;
		static int Attn;
		static int Crsel;
		static int Exsel;
		static int EraseEof;
		static int Play;
		static int Zoom;
		static int NoName;
		static int Pa1;
		static int OemClear;
		static int KeyCodeMask;
		static int ShiftModifier;
		static int ControlModifier;
		static int AltModifier;
		static int Face1;
		static int Face2;
		static int Face3;
		static int Face4;
		static int ButtonA;
		static int ButtonB;
		static int ButtonX;
		static int ButtonY;
		static int LeftShoulder;
		static int RightShoulder;
		static int LeftShoulderBottom;
		static int RightShoulderBottom;
		static int ButtonSelect;
		static int ButtonStart;
		static int LeftAnalogueStick;
		static int RightAnalogueStick;
		static int PadTop;
		static int PadBottom;
		static int PadLeft;
		static int PadRight;
		static int LeftAnalogueHor;
		static int LeftAnalogueVert;
		static int RightAnalogueHor;
		static int RightAnalogueVert;
};

} // end namespace haxor
} // end namespace input

#endif /* INCLUDED_haxor_input_KeyCode */ 
