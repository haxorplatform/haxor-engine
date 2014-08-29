#include <hxcpp.h>

#ifndef INCLUDED_haxor_input_KeyCode
#include <haxor/input/KeyCode.h>
#endif
namespace haxor{
namespace input{

Void KeyCode_obj::__construct()
{
	return null();
}

//KeyCode_obj::~KeyCode_obj() { }

Dynamic KeyCode_obj::__CreateEmpty() { return  new KeyCode_obj; }
hx::ObjectPtr< KeyCode_obj > KeyCode_obj::__new()
{  hx::ObjectPtr< KeyCode_obj > result = new KeyCode_obj();
	result->__construct();
	return result;}

Dynamic KeyCode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< KeyCode_obj > result = new KeyCode_obj();
	result->__construct();
	return result;}

int KeyCode_obj::Modifiers;

int KeyCode_obj::None;

int KeyCode_obj::Mouse0;

int KeyCode_obj::Mouse1;

int KeyCode_obj::Cancel;

int KeyCode_obj::Mouse2;

int KeyCode_obj::Mouse3;

int KeyCode_obj::Mouse4;

int KeyCode_obj::Back;

int KeyCode_obj::Tab;

int KeyCode_obj::LineFeed;

int KeyCode_obj::Clear;

int KeyCode_obj::Enter;

int KeyCode_obj::Return;

int KeyCode_obj::ShiftKey;

int KeyCode_obj::ControlKey;

int KeyCode_obj::Alt;

int KeyCode_obj::Pause;

int KeyCode_obj::CapsLock;

int KeyCode_obj::Capital;

int KeyCode_obj::KanaMode;

int KeyCode_obj::HanguelMode;

int KeyCode_obj::HangulMode;

int KeyCode_obj::JunjaMode;

int KeyCode_obj::FinalMode;

int KeyCode_obj::KanjiMode;

int KeyCode_obj::HanjaMode;

int KeyCode_obj::Escape;

int KeyCode_obj::IMEConvert;

int KeyCode_obj::IMENonconvert;

int KeyCode_obj::IMEAceept;

int KeyCode_obj::IMEAccept;

int KeyCode_obj::IMEModeChange;

int KeyCode_obj::Space;

int KeyCode_obj::Prior;

int KeyCode_obj::PageUp;

int KeyCode_obj::Next;

int KeyCode_obj::PageDown;

int KeyCode_obj::End;

int KeyCode_obj::Home;

int KeyCode_obj::Left;

int KeyCode_obj::Up;

int KeyCode_obj::Right;

int KeyCode_obj::Down;

int KeyCode_obj::Select;

int KeyCode_obj::Print;

int KeyCode_obj::Execute;

int KeyCode_obj::PrintScreen;

int KeyCode_obj::Snapshot;

int KeyCode_obj::Insert;

int KeyCode_obj::Delete;

int KeyCode_obj::Help;

int KeyCode_obj::D0;

int KeyCode_obj::D1;

int KeyCode_obj::D2;

int KeyCode_obj::D3;

int KeyCode_obj::D4;

int KeyCode_obj::D5;

int KeyCode_obj::D6;

int KeyCode_obj::D7;

int KeyCode_obj::D8;

int KeyCode_obj::D9;

int KeyCode_obj::A;

int KeyCode_obj::B;

int KeyCode_obj::C;

int KeyCode_obj::D;

int KeyCode_obj::E;

int KeyCode_obj::F;

int KeyCode_obj::G;

int KeyCode_obj::H;

int KeyCode_obj::I;

int KeyCode_obj::J;

int KeyCode_obj::K;

int KeyCode_obj::L;

int KeyCode_obj::M;

int KeyCode_obj::N;

int KeyCode_obj::O;

int KeyCode_obj::P;

int KeyCode_obj::Q;

int KeyCode_obj::R;

int KeyCode_obj::S;

int KeyCode_obj::T;

int KeyCode_obj::U;

int KeyCode_obj::V;

int KeyCode_obj::W;

int KeyCode_obj::X;

int KeyCode_obj::Y;

int KeyCode_obj::Z;

int KeyCode_obj::LWin;

int KeyCode_obj::RWin;

int KeyCode_obj::Apps;

int KeyCode_obj::Sleep;

int KeyCode_obj::NumPad0;

int KeyCode_obj::NumPad1;

int KeyCode_obj::NumPad2;

int KeyCode_obj::NumPad3;

int KeyCode_obj::NumPad4;

int KeyCode_obj::NumPad5;

int KeyCode_obj::NumPad6;

int KeyCode_obj::NumPad7;

int KeyCode_obj::NumPad8;

int KeyCode_obj::NumPad9;

int KeyCode_obj::Multiply;

int KeyCode_obj::Add;

int KeyCode_obj::Separator;

int KeyCode_obj::Subtract;

int KeyCode_obj::Decimal;

int KeyCode_obj::Divide;

int KeyCode_obj::F1;

int KeyCode_obj::F2;

int KeyCode_obj::F3;

int KeyCode_obj::F4;

int KeyCode_obj::F5;

int KeyCode_obj::F6;

int KeyCode_obj::F7;

int KeyCode_obj::F8;

int KeyCode_obj::F9;

int KeyCode_obj::F10;

int KeyCode_obj::F11;

int KeyCode_obj::F12;

int KeyCode_obj::F13;

int KeyCode_obj::F14;

int KeyCode_obj::F15;

int KeyCode_obj::F16;

int KeyCode_obj::F17;

int KeyCode_obj::F18;

int KeyCode_obj::F19;

int KeyCode_obj::F20;

int KeyCode_obj::F21;

int KeyCode_obj::F22;

int KeyCode_obj::F23;

int KeyCode_obj::F24;

int KeyCode_obj::NumLock;

int KeyCode_obj::Scroll;

int KeyCode_obj::LShiftKey;

int KeyCode_obj::RShiftKey;

int KeyCode_obj::LControlKey;

int KeyCode_obj::RControlKey;

int KeyCode_obj::LAlt;

int KeyCode_obj::RAlt;

int KeyCode_obj::BrowserBack;

int KeyCode_obj::BrowserForward;

int KeyCode_obj::BrowserRefresh;

int KeyCode_obj::BrowserStop;

int KeyCode_obj::BrowserSearch;

int KeyCode_obj::BrowserFavorites;

int KeyCode_obj::BrowserHome;

int KeyCode_obj::VolumeMute;

int KeyCode_obj::VolumeDown;

int KeyCode_obj::VolumeUp;

int KeyCode_obj::MediaNextTrack;

int KeyCode_obj::MediaPreviousTrack;

int KeyCode_obj::MediaStop;

int KeyCode_obj::MediaPlayPause;

int KeyCode_obj::LaunchMail;

int KeyCode_obj::SelectMedia;

int KeyCode_obj::LaunchApplication1;

int KeyCode_obj::LaunchApplication2;

int KeyCode_obj::Oem1;

int KeyCode_obj::OemSemicolon;

int KeyCode_obj::Oemplus;

int KeyCode_obj::Oemcomma;

int KeyCode_obj::OemMinus;

int KeyCode_obj::OemPeriod;

int KeyCode_obj::OemQuestion;

int KeyCode_obj::Oem2;

int KeyCode_obj::Oemtilde;

int KeyCode_obj::Oem3;

int KeyCode_obj::Oem4;

int KeyCode_obj::OemOpenBrackets;

int KeyCode_obj::OemPipe;

int KeyCode_obj::Oem5;

int KeyCode_obj::Oem6;

int KeyCode_obj::OemCloseBrackets;

int KeyCode_obj::Oem7;

int KeyCode_obj::OemQuotes;

int KeyCode_obj::Oem8;

int KeyCode_obj::Oem102;

int KeyCode_obj::OemBackslash;

int KeyCode_obj::ProcessKey;

int KeyCode_obj::Packet;

int KeyCode_obj::Attn;

int KeyCode_obj::Crsel;

int KeyCode_obj::Exsel;

int KeyCode_obj::EraseEof;

int KeyCode_obj::Play;

int KeyCode_obj::Zoom;

int KeyCode_obj::NoName;

int KeyCode_obj::Pa1;

int KeyCode_obj::OemClear;

int KeyCode_obj::KeyCodeMask;

int KeyCode_obj::ShiftModifier;

int KeyCode_obj::ControlModifier;

int KeyCode_obj::AltModifier;

int KeyCode_obj::Face1;

int KeyCode_obj::Face2;

int KeyCode_obj::Face3;

int KeyCode_obj::Face4;

int KeyCode_obj::LeftShoulder;

int KeyCode_obj::RightShoulder;

int KeyCode_obj::LeftShoulderBottom;

int KeyCode_obj::RightShoulderBottom;

int KeyCode_obj::ButtonSelect;

int KeyCode_obj::ButtonStart;

int KeyCode_obj::LeftAnalogueStick;

int KeyCode_obj::RightAnalogueStick;

int KeyCode_obj::PadTop;

int KeyCode_obj::PadBottom;

int KeyCode_obj::PadLeft;

int KeyCode_obj::PadRight;

int KeyCode_obj::LeftAnalogueHor;

int KeyCode_obj::LeftAnalogueVert;

int KeyCode_obj::RightAnalogueHor;

int KeyCode_obj::RightAnalogueVert;


KeyCode_obj::KeyCode_obj()
{
}

Dynamic KeyCode_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"A") ) { return A; }
		if (HX_FIELD_EQ(inName,"B") ) { return B; }
		if (HX_FIELD_EQ(inName,"C") ) { return C; }
		if (HX_FIELD_EQ(inName,"D") ) { return D; }
		if (HX_FIELD_EQ(inName,"E") ) { return E; }
		if (HX_FIELD_EQ(inName,"F") ) { return F; }
		if (HX_FIELD_EQ(inName,"G") ) { return G; }
		if (HX_FIELD_EQ(inName,"H") ) { return H; }
		if (HX_FIELD_EQ(inName,"I") ) { return I; }
		if (HX_FIELD_EQ(inName,"J") ) { return J; }
		if (HX_FIELD_EQ(inName,"K") ) { return K; }
		if (HX_FIELD_EQ(inName,"L") ) { return L; }
		if (HX_FIELD_EQ(inName,"M") ) { return M; }
		if (HX_FIELD_EQ(inName,"N") ) { return N; }
		if (HX_FIELD_EQ(inName,"O") ) { return O; }
		if (HX_FIELD_EQ(inName,"P") ) { return P; }
		if (HX_FIELD_EQ(inName,"Q") ) { return Q; }
		if (HX_FIELD_EQ(inName,"R") ) { return R; }
		if (HX_FIELD_EQ(inName,"S") ) { return S; }
		if (HX_FIELD_EQ(inName,"T") ) { return T; }
		if (HX_FIELD_EQ(inName,"U") ) { return U; }
		if (HX_FIELD_EQ(inName,"V") ) { return V; }
		if (HX_FIELD_EQ(inName,"W") ) { return W; }
		if (HX_FIELD_EQ(inName,"X") ) { return X; }
		if (HX_FIELD_EQ(inName,"Y") ) { return Y; }
		if (HX_FIELD_EQ(inName,"Z") ) { return Z; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"Up") ) { return Up; }
		if (HX_FIELD_EQ(inName,"D0") ) { return D0; }
		if (HX_FIELD_EQ(inName,"D1") ) { return D1; }
		if (HX_FIELD_EQ(inName,"D2") ) { return D2; }
		if (HX_FIELD_EQ(inName,"D3") ) { return D3; }
		if (HX_FIELD_EQ(inName,"D4") ) { return D4; }
		if (HX_FIELD_EQ(inName,"D5") ) { return D5; }
		if (HX_FIELD_EQ(inName,"D6") ) { return D6; }
		if (HX_FIELD_EQ(inName,"D7") ) { return D7; }
		if (HX_FIELD_EQ(inName,"D8") ) { return D8; }
		if (HX_FIELD_EQ(inName,"D9") ) { return D9; }
		if (HX_FIELD_EQ(inName,"F1") ) { return F1; }
		if (HX_FIELD_EQ(inName,"F2") ) { return F2; }
		if (HX_FIELD_EQ(inName,"F3") ) { return F3; }
		if (HX_FIELD_EQ(inName,"F4") ) { return F4; }
		if (HX_FIELD_EQ(inName,"F5") ) { return F5; }
		if (HX_FIELD_EQ(inName,"F6") ) { return F6; }
		if (HX_FIELD_EQ(inName,"F7") ) { return F7; }
		if (HX_FIELD_EQ(inName,"F8") ) { return F8; }
		if (HX_FIELD_EQ(inName,"F9") ) { return F9; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"Tab") ) { return Tab; }
		if (HX_FIELD_EQ(inName,"Alt") ) { return Alt; }
		if (HX_FIELD_EQ(inName,"End") ) { return End; }
		if (HX_FIELD_EQ(inName,"Add") ) { return Add; }
		if (HX_FIELD_EQ(inName,"F10") ) { return F10; }
		if (HX_FIELD_EQ(inName,"F11") ) { return F11; }
		if (HX_FIELD_EQ(inName,"F12") ) { return F12; }
		if (HX_FIELD_EQ(inName,"F13") ) { return F13; }
		if (HX_FIELD_EQ(inName,"F14") ) { return F14; }
		if (HX_FIELD_EQ(inName,"F15") ) { return F15; }
		if (HX_FIELD_EQ(inName,"F16") ) { return F16; }
		if (HX_FIELD_EQ(inName,"F17") ) { return F17; }
		if (HX_FIELD_EQ(inName,"F18") ) { return F18; }
		if (HX_FIELD_EQ(inName,"F19") ) { return F19; }
		if (HX_FIELD_EQ(inName,"F20") ) { return F20; }
		if (HX_FIELD_EQ(inName,"F21") ) { return F21; }
		if (HX_FIELD_EQ(inName,"F22") ) { return F22; }
		if (HX_FIELD_EQ(inName,"F23") ) { return F23; }
		if (HX_FIELD_EQ(inName,"F24") ) { return F24; }
		if (HX_FIELD_EQ(inName,"Pa1") ) { return Pa1; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"None") ) { return None; }
		if (HX_FIELD_EQ(inName,"Back") ) { return Back; }
		if (HX_FIELD_EQ(inName,"Next") ) { return Next; }
		if (HX_FIELD_EQ(inName,"Home") ) { return Home; }
		if (HX_FIELD_EQ(inName,"Left") ) { return Left; }
		if (HX_FIELD_EQ(inName,"Down") ) { return Down; }
		if (HX_FIELD_EQ(inName,"Help") ) { return Help; }
		if (HX_FIELD_EQ(inName,"LWin") ) { return LWin; }
		if (HX_FIELD_EQ(inName,"RWin") ) { return RWin; }
		if (HX_FIELD_EQ(inName,"Apps") ) { return Apps; }
		if (HX_FIELD_EQ(inName,"LAlt") ) { return LAlt; }
		if (HX_FIELD_EQ(inName,"RAlt") ) { return RAlt; }
		if (HX_FIELD_EQ(inName,"Oem1") ) { return Oem1; }
		if (HX_FIELD_EQ(inName,"Oem2") ) { return Oem2; }
		if (HX_FIELD_EQ(inName,"Oem3") ) { return Oem3; }
		if (HX_FIELD_EQ(inName,"Oem4") ) { return Oem4; }
		if (HX_FIELD_EQ(inName,"Oem5") ) { return Oem5; }
		if (HX_FIELD_EQ(inName,"Oem6") ) { return Oem6; }
		if (HX_FIELD_EQ(inName,"Oem7") ) { return Oem7; }
		if (HX_FIELD_EQ(inName,"Oem8") ) { return Oem8; }
		if (HX_FIELD_EQ(inName,"Attn") ) { return Attn; }
		if (HX_FIELD_EQ(inName,"Play") ) { return Play; }
		if (HX_FIELD_EQ(inName,"Zoom") ) { return Zoom; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear; }
		if (HX_FIELD_EQ(inName,"Enter") ) { return Enter; }
		if (HX_FIELD_EQ(inName,"Pause") ) { return Pause; }
		if (HX_FIELD_EQ(inName,"Space") ) { return Space; }
		if (HX_FIELD_EQ(inName,"Prior") ) { return Prior; }
		if (HX_FIELD_EQ(inName,"Right") ) { return Right; }
		if (HX_FIELD_EQ(inName,"Print") ) { return Print; }
		if (HX_FIELD_EQ(inName,"Sleep") ) { return Sleep; }
		if (HX_FIELD_EQ(inName,"Crsel") ) { return Crsel; }
		if (HX_FIELD_EQ(inName,"Exsel") ) { return Exsel; }
		if (HX_FIELD_EQ(inName,"Face1") ) { return Face1; }
		if (HX_FIELD_EQ(inName,"Face2") ) { return Face2; }
		if (HX_FIELD_EQ(inName,"Face3") ) { return Face3; }
		if (HX_FIELD_EQ(inName,"Face4") ) { return Face4; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Mouse0") ) { return Mouse0; }
		if (HX_FIELD_EQ(inName,"Mouse1") ) { return Mouse1; }
		if (HX_FIELD_EQ(inName,"Cancel") ) { return Cancel; }
		if (HX_FIELD_EQ(inName,"Mouse2") ) { return Mouse2; }
		if (HX_FIELD_EQ(inName,"Mouse3") ) { return Mouse3; }
		if (HX_FIELD_EQ(inName,"Mouse4") ) { return Mouse4; }
		if (HX_FIELD_EQ(inName,"Return") ) { return Return; }
		if (HX_FIELD_EQ(inName,"Escape") ) { return Escape; }
		if (HX_FIELD_EQ(inName,"PageUp") ) { return PageUp; }
		if (HX_FIELD_EQ(inName,"Select") ) { return Select; }
		if (HX_FIELD_EQ(inName,"Insert") ) { return Insert; }
		if (HX_FIELD_EQ(inName,"Delete") ) { return Delete; }
		if (HX_FIELD_EQ(inName,"Divide") ) { return Divide; }
		if (HX_FIELD_EQ(inName,"Scroll") ) { return Scroll; }
		if (HX_FIELD_EQ(inName,"Oem102") ) { return Oem102; }
		if (HX_FIELD_EQ(inName,"Packet") ) { return Packet; }
		if (HX_FIELD_EQ(inName,"NoName") ) { return NoName; }
		if (HX_FIELD_EQ(inName,"PadTop") ) { return PadTop; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Capital") ) { return Capital; }
		if (HX_FIELD_EQ(inName,"Execute") ) { return Execute; }
		if (HX_FIELD_EQ(inName,"NumPad0") ) { return NumPad0; }
		if (HX_FIELD_EQ(inName,"NumPad1") ) { return NumPad1; }
		if (HX_FIELD_EQ(inName,"NumPad2") ) { return NumPad2; }
		if (HX_FIELD_EQ(inName,"NumPad3") ) { return NumPad3; }
		if (HX_FIELD_EQ(inName,"NumPad4") ) { return NumPad4; }
		if (HX_FIELD_EQ(inName,"NumPad5") ) { return NumPad5; }
		if (HX_FIELD_EQ(inName,"NumPad6") ) { return NumPad6; }
		if (HX_FIELD_EQ(inName,"NumPad7") ) { return NumPad7; }
		if (HX_FIELD_EQ(inName,"NumPad8") ) { return NumPad8; }
		if (HX_FIELD_EQ(inName,"NumPad9") ) { return NumPad9; }
		if (HX_FIELD_EQ(inName,"Decimal") ) { return Decimal; }
		if (HX_FIELD_EQ(inName,"NumLock") ) { return NumLock; }
		if (HX_FIELD_EQ(inName,"Oemplus") ) { return Oemplus; }
		if (HX_FIELD_EQ(inName,"OemPipe") ) { return OemPipe; }
		if (HX_FIELD_EQ(inName,"PadLeft") ) { return PadLeft; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"LineFeed") ) { return LineFeed; }
		if (HX_FIELD_EQ(inName,"ShiftKey") ) { return ShiftKey; }
		if (HX_FIELD_EQ(inName,"CapsLock") ) { return CapsLock; }
		if (HX_FIELD_EQ(inName,"KanaMode") ) { return KanaMode; }
		if (HX_FIELD_EQ(inName,"PageDown") ) { return PageDown; }
		if (HX_FIELD_EQ(inName,"Snapshot") ) { return Snapshot; }
		if (HX_FIELD_EQ(inName,"Multiply") ) { return Multiply; }
		if (HX_FIELD_EQ(inName,"Subtract") ) { return Subtract; }
		if (HX_FIELD_EQ(inName,"VolumeUp") ) { return VolumeUp; }
		if (HX_FIELD_EQ(inName,"Oemcomma") ) { return Oemcomma; }
		if (HX_FIELD_EQ(inName,"OemMinus") ) { return OemMinus; }
		if (HX_FIELD_EQ(inName,"Oemtilde") ) { return Oemtilde; }
		if (HX_FIELD_EQ(inName,"EraseEof") ) { return EraseEof; }
		if (HX_FIELD_EQ(inName,"OemClear") ) { return OemClear; }
		if (HX_FIELD_EQ(inName,"PadRight") ) { return PadRight; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"Modifiers") ) { return Modifiers; }
		if (HX_FIELD_EQ(inName,"JunjaMode") ) { return JunjaMode; }
		if (HX_FIELD_EQ(inName,"FinalMode") ) { return FinalMode; }
		if (HX_FIELD_EQ(inName,"KanjiMode") ) { return KanjiMode; }
		if (HX_FIELD_EQ(inName,"HanjaMode") ) { return HanjaMode; }
		if (HX_FIELD_EQ(inName,"IMEAceept") ) { return IMEAceept; }
		if (HX_FIELD_EQ(inName,"IMEAccept") ) { return IMEAccept; }
		if (HX_FIELD_EQ(inName,"Separator") ) { return Separator; }
		if (HX_FIELD_EQ(inName,"LShiftKey") ) { return LShiftKey; }
		if (HX_FIELD_EQ(inName,"RShiftKey") ) { return RShiftKey; }
		if (HX_FIELD_EQ(inName,"MediaStop") ) { return MediaStop; }
		if (HX_FIELD_EQ(inName,"OemPeriod") ) { return OemPeriod; }
		if (HX_FIELD_EQ(inName,"OemQuotes") ) { return OemQuotes; }
		if (HX_FIELD_EQ(inName,"PadBottom") ) { return PadBottom; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ControlKey") ) { return ControlKey; }
		if (HX_FIELD_EQ(inName,"HangulMode") ) { return HangulMode; }
		if (HX_FIELD_EQ(inName,"IMEConvert") ) { return IMEConvert; }
		if (HX_FIELD_EQ(inName,"VolumeMute") ) { return VolumeMute; }
		if (HX_FIELD_EQ(inName,"VolumeDown") ) { return VolumeDown; }
		if (HX_FIELD_EQ(inName,"LaunchMail") ) { return LaunchMail; }
		if (HX_FIELD_EQ(inName,"ProcessKey") ) { return ProcessKey; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"HanguelMode") ) { return HanguelMode; }
		if (HX_FIELD_EQ(inName,"PrintScreen") ) { return PrintScreen; }
		if (HX_FIELD_EQ(inName,"LControlKey") ) { return LControlKey; }
		if (HX_FIELD_EQ(inName,"RControlKey") ) { return RControlKey; }
		if (HX_FIELD_EQ(inName,"BrowserBack") ) { return BrowserBack; }
		if (HX_FIELD_EQ(inName,"BrowserStop") ) { return BrowserStop; }
		if (HX_FIELD_EQ(inName,"BrowserHome") ) { return BrowserHome; }
		if (HX_FIELD_EQ(inName,"SelectMedia") ) { return SelectMedia; }
		if (HX_FIELD_EQ(inName,"OemQuestion") ) { return OemQuestion; }
		if (HX_FIELD_EQ(inName,"KeyCodeMask") ) { return KeyCodeMask; }
		if (HX_FIELD_EQ(inName,"AltModifier") ) { return AltModifier; }
		if (HX_FIELD_EQ(inName,"ButtonStart") ) { return ButtonStart; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"OemSemicolon") ) { return OemSemicolon; }
		if (HX_FIELD_EQ(inName,"OemBackslash") ) { return OemBackslash; }
		if (HX_FIELD_EQ(inName,"LeftShoulder") ) { return LeftShoulder; }
		if (HX_FIELD_EQ(inName,"ButtonSelect") ) { return ButtonSelect; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"IMENonconvert") ) { return IMENonconvert; }
		if (HX_FIELD_EQ(inName,"IMEModeChange") ) { return IMEModeChange; }
		if (HX_FIELD_EQ(inName,"BrowserSearch") ) { return BrowserSearch; }
		if (HX_FIELD_EQ(inName,"ShiftModifier") ) { return ShiftModifier; }
		if (HX_FIELD_EQ(inName,"RightShoulder") ) { return RightShoulder; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"BrowserForward") ) { return BrowserForward; }
		if (HX_FIELD_EQ(inName,"BrowserRefresh") ) { return BrowserRefresh; }
		if (HX_FIELD_EQ(inName,"MediaNextTrack") ) { return MediaNextTrack; }
		if (HX_FIELD_EQ(inName,"MediaPlayPause") ) { return MediaPlayPause; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"OemOpenBrackets") ) { return OemOpenBrackets; }
		if (HX_FIELD_EQ(inName,"ControlModifier") ) { return ControlModifier; }
		if (HX_FIELD_EQ(inName,"LeftAnalogueHor") ) { return LeftAnalogueHor; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"BrowserFavorites") ) { return BrowserFavorites; }
		if (HX_FIELD_EQ(inName,"OemCloseBrackets") ) { return OemCloseBrackets; }
		if (HX_FIELD_EQ(inName,"LeftAnalogueVert") ) { return LeftAnalogueVert; }
		if (HX_FIELD_EQ(inName,"RightAnalogueHor") ) { return RightAnalogueHor; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"LeftAnalogueStick") ) { return LeftAnalogueStick; }
		if (HX_FIELD_EQ(inName,"RightAnalogueVert") ) { return RightAnalogueVert; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"MediaPreviousTrack") ) { return MediaPreviousTrack; }
		if (HX_FIELD_EQ(inName,"LaunchApplication1") ) { return LaunchApplication1; }
		if (HX_FIELD_EQ(inName,"LaunchApplication2") ) { return LaunchApplication2; }
		if (HX_FIELD_EQ(inName,"LeftShoulderBottom") ) { return LeftShoulderBottom; }
		if (HX_FIELD_EQ(inName,"RightAnalogueStick") ) { return RightAnalogueStick; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"RightShoulderBottom") ) { return RightShoulderBottom; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic KeyCode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"A") ) { A=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"B") ) { B=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"C") ) { C=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"D") ) { D=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"E") ) { E=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F") ) { F=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"G") ) { G=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"H") ) { H=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"I") ) { I=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"J") ) { J=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"K") ) { K=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"L") ) { L=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"M") ) { M=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"N") ) { N=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"O") ) { O=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"P") ) { P=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Q") ) { Q=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"R") ) { R=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"S") ) { S=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"T") ) { T=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"U") ) { U=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"V") ) { V=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"W") ) { W=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"X") ) { X=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Y") ) { Y=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Z") ) { Z=inValue.Cast< int >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"Up") ) { Up=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"D0") ) { D0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"D1") ) { D1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"D2") ) { D2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"D3") ) { D3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"D4") ) { D4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"D5") ) { D5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"D6") ) { D6=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"D7") ) { D7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"D8") ) { D8=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"D9") ) { D9=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F1") ) { F1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F2") ) { F2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F3") ) { F3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F4") ) { F4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F5") ) { F5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F6") ) { F6=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F7") ) { F7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F8") ) { F8=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F9") ) { F9=inValue.Cast< int >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"Tab") ) { Tab=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Alt") ) { Alt=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"End") ) { End=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Add") ) { Add=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F10") ) { F10=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F11") ) { F11=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F12") ) { F12=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F13") ) { F13=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F14") ) { F14=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F15") ) { F15=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F16") ) { F16=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F17") ) { F17=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F18") ) { F18=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F19") ) { F19=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F20") ) { F20=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F21") ) { F21=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F22") ) { F22=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F23") ) { F23=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"F24") ) { F24=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Pa1") ) { Pa1=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"None") ) { None=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Back") ) { Back=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Next") ) { Next=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Home") ) { Home=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Left") ) { Left=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Down") ) { Down=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Help") ) { Help=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LWin") ) { LWin=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RWin") ) { RWin=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Apps") ) { Apps=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LAlt") ) { LAlt=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RAlt") ) { RAlt=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Oem1") ) { Oem1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Oem2") ) { Oem2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Oem3") ) { Oem3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Oem4") ) { Oem4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Oem5") ) { Oem5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Oem6") ) { Oem6=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Oem7") ) { Oem7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Oem8") ) { Oem8=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Attn") ) { Attn=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Play") ) { Play=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Zoom") ) { Zoom=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { Clear=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Enter") ) { Enter=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Pause") ) { Pause=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Space") ) { Space=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Prior") ) { Prior=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Right") ) { Right=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Print") ) { Print=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Sleep") ) { Sleep=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Crsel") ) { Crsel=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Exsel") ) { Exsel=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Face1") ) { Face1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Face2") ) { Face2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Face3") ) { Face3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Face4") ) { Face4=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Mouse0") ) { Mouse0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Mouse1") ) { Mouse1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Cancel") ) { Cancel=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Mouse2") ) { Mouse2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Mouse3") ) { Mouse3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Mouse4") ) { Mouse4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Return") ) { Return=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Escape") ) { Escape=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PageUp") ) { PageUp=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Select") ) { Select=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Insert") ) { Insert=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Delete") ) { Delete=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Divide") ) { Divide=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Scroll") ) { Scroll=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Oem102") ) { Oem102=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Packet") ) { Packet=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NoName") ) { NoName=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PadTop") ) { PadTop=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Capital") ) { Capital=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Execute") ) { Execute=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NumPad0") ) { NumPad0=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NumPad1") ) { NumPad1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NumPad2") ) { NumPad2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NumPad3") ) { NumPad3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NumPad4") ) { NumPad4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NumPad5") ) { NumPad5=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NumPad6") ) { NumPad6=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NumPad7") ) { NumPad7=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NumPad8") ) { NumPad8=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NumPad9") ) { NumPad9=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Decimal") ) { Decimal=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NumLock") ) { NumLock=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Oemplus") ) { Oemplus=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OemPipe") ) { OemPipe=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PadLeft") ) { PadLeft=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"LineFeed") ) { LineFeed=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ShiftKey") ) { ShiftKey=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CapsLock") ) { CapsLock=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"KanaMode") ) { KanaMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PageDown") ) { PageDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Snapshot") ) { Snapshot=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Multiply") ) { Multiply=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Subtract") ) { Subtract=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"VolumeUp") ) { VolumeUp=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Oemcomma") ) { Oemcomma=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OemMinus") ) { OemMinus=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Oemtilde") ) { Oemtilde=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"EraseEof") ) { EraseEof=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OemClear") ) { OemClear=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PadRight") ) { PadRight=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"Modifiers") ) { Modifiers=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"JunjaMode") ) { JunjaMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"FinalMode") ) { FinalMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"KanjiMode") ) { KanjiMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HanjaMode") ) { HanjaMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"IMEAceept") ) { IMEAceept=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"IMEAccept") ) { IMEAccept=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Separator") ) { Separator=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LShiftKey") ) { LShiftKey=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RShiftKey") ) { RShiftKey=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MediaStop") ) { MediaStop=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OemPeriod") ) { OemPeriod=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OemQuotes") ) { OemQuotes=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PadBottom") ) { PadBottom=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ControlKey") ) { ControlKey=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HangulMode") ) { HangulMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"IMEConvert") ) { IMEConvert=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"VolumeMute") ) { VolumeMute=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"VolumeDown") ) { VolumeDown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LaunchMail") ) { LaunchMail=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ProcessKey") ) { ProcessKey=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"HanguelMode") ) { HanguelMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PrintScreen") ) { PrintScreen=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LControlKey") ) { LControlKey=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RControlKey") ) { RControlKey=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BrowserBack") ) { BrowserBack=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BrowserStop") ) { BrowserStop=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BrowserHome") ) { BrowserHome=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SelectMedia") ) { SelectMedia=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OemQuestion") ) { OemQuestion=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"KeyCodeMask") ) { KeyCodeMask=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"AltModifier") ) { AltModifier=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ButtonStart") ) { ButtonStart=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"OemSemicolon") ) { OemSemicolon=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OemBackslash") ) { OemBackslash=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LeftShoulder") ) { LeftShoulder=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ButtonSelect") ) { ButtonSelect=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"IMENonconvert") ) { IMENonconvert=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"IMEModeChange") ) { IMEModeChange=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BrowserSearch") ) { BrowserSearch=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ShiftModifier") ) { ShiftModifier=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RightShoulder") ) { RightShoulder=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"BrowserForward") ) { BrowserForward=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BrowserRefresh") ) { BrowserRefresh=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MediaNextTrack") ) { MediaNextTrack=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MediaPlayPause") ) { MediaPlayPause=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"OemOpenBrackets") ) { OemOpenBrackets=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ControlModifier") ) { ControlModifier=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LeftAnalogueHor") ) { LeftAnalogueHor=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"BrowserFavorites") ) { BrowserFavorites=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OemCloseBrackets") ) { OemCloseBrackets=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LeftAnalogueVert") ) { LeftAnalogueVert=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RightAnalogueHor") ) { RightAnalogueHor=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"LeftAnalogueStick") ) { LeftAnalogueStick=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RightAnalogueVert") ) { RightAnalogueVert=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"MediaPreviousTrack") ) { MediaPreviousTrack=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LaunchApplication1") ) { LaunchApplication1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LaunchApplication2") ) { LaunchApplication2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LeftShoulderBottom") ) { LeftShoulderBottom=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RightAnalogueStick") ) { RightAnalogueStick=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"RightShoulderBottom") ) { RightShoulderBottom=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void KeyCode_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Modifiers"),
	HX_CSTRING("None"),
	HX_CSTRING("Mouse0"),
	HX_CSTRING("Mouse1"),
	HX_CSTRING("Cancel"),
	HX_CSTRING("Mouse2"),
	HX_CSTRING("Mouse3"),
	HX_CSTRING("Mouse4"),
	HX_CSTRING("Back"),
	HX_CSTRING("Tab"),
	HX_CSTRING("LineFeed"),
	HX_CSTRING("Clear"),
	HX_CSTRING("Enter"),
	HX_CSTRING("Return"),
	HX_CSTRING("ShiftKey"),
	HX_CSTRING("ControlKey"),
	HX_CSTRING("Alt"),
	HX_CSTRING("Pause"),
	HX_CSTRING("CapsLock"),
	HX_CSTRING("Capital"),
	HX_CSTRING("KanaMode"),
	HX_CSTRING("HanguelMode"),
	HX_CSTRING("HangulMode"),
	HX_CSTRING("JunjaMode"),
	HX_CSTRING("FinalMode"),
	HX_CSTRING("KanjiMode"),
	HX_CSTRING("HanjaMode"),
	HX_CSTRING("Escape"),
	HX_CSTRING("IMEConvert"),
	HX_CSTRING("IMENonconvert"),
	HX_CSTRING("IMEAceept"),
	HX_CSTRING("IMEAccept"),
	HX_CSTRING("IMEModeChange"),
	HX_CSTRING("Space"),
	HX_CSTRING("Prior"),
	HX_CSTRING("PageUp"),
	HX_CSTRING("Next"),
	HX_CSTRING("PageDown"),
	HX_CSTRING("End"),
	HX_CSTRING("Home"),
	HX_CSTRING("Left"),
	HX_CSTRING("Up"),
	HX_CSTRING("Right"),
	HX_CSTRING("Down"),
	HX_CSTRING("Select"),
	HX_CSTRING("Print"),
	HX_CSTRING("Execute"),
	HX_CSTRING("PrintScreen"),
	HX_CSTRING("Snapshot"),
	HX_CSTRING("Insert"),
	HX_CSTRING("Delete"),
	HX_CSTRING("Help"),
	HX_CSTRING("D0"),
	HX_CSTRING("D1"),
	HX_CSTRING("D2"),
	HX_CSTRING("D3"),
	HX_CSTRING("D4"),
	HX_CSTRING("D5"),
	HX_CSTRING("D6"),
	HX_CSTRING("D7"),
	HX_CSTRING("D8"),
	HX_CSTRING("D9"),
	HX_CSTRING("A"),
	HX_CSTRING("B"),
	HX_CSTRING("C"),
	HX_CSTRING("D"),
	HX_CSTRING("E"),
	HX_CSTRING("F"),
	HX_CSTRING("G"),
	HX_CSTRING("H"),
	HX_CSTRING("I"),
	HX_CSTRING("J"),
	HX_CSTRING("K"),
	HX_CSTRING("L"),
	HX_CSTRING("M"),
	HX_CSTRING("N"),
	HX_CSTRING("O"),
	HX_CSTRING("P"),
	HX_CSTRING("Q"),
	HX_CSTRING("R"),
	HX_CSTRING("S"),
	HX_CSTRING("T"),
	HX_CSTRING("U"),
	HX_CSTRING("V"),
	HX_CSTRING("W"),
	HX_CSTRING("X"),
	HX_CSTRING("Y"),
	HX_CSTRING("Z"),
	HX_CSTRING("LWin"),
	HX_CSTRING("RWin"),
	HX_CSTRING("Apps"),
	HX_CSTRING("Sleep"),
	HX_CSTRING("NumPad0"),
	HX_CSTRING("NumPad1"),
	HX_CSTRING("NumPad2"),
	HX_CSTRING("NumPad3"),
	HX_CSTRING("NumPad4"),
	HX_CSTRING("NumPad5"),
	HX_CSTRING("NumPad6"),
	HX_CSTRING("NumPad7"),
	HX_CSTRING("NumPad8"),
	HX_CSTRING("NumPad9"),
	HX_CSTRING("Multiply"),
	HX_CSTRING("Add"),
	HX_CSTRING("Separator"),
	HX_CSTRING("Subtract"),
	HX_CSTRING("Decimal"),
	HX_CSTRING("Divide"),
	HX_CSTRING("F1"),
	HX_CSTRING("F2"),
	HX_CSTRING("F3"),
	HX_CSTRING("F4"),
	HX_CSTRING("F5"),
	HX_CSTRING("F6"),
	HX_CSTRING("F7"),
	HX_CSTRING("F8"),
	HX_CSTRING("F9"),
	HX_CSTRING("F10"),
	HX_CSTRING("F11"),
	HX_CSTRING("F12"),
	HX_CSTRING("F13"),
	HX_CSTRING("F14"),
	HX_CSTRING("F15"),
	HX_CSTRING("F16"),
	HX_CSTRING("F17"),
	HX_CSTRING("F18"),
	HX_CSTRING("F19"),
	HX_CSTRING("F20"),
	HX_CSTRING("F21"),
	HX_CSTRING("F22"),
	HX_CSTRING("F23"),
	HX_CSTRING("F24"),
	HX_CSTRING("NumLock"),
	HX_CSTRING("Scroll"),
	HX_CSTRING("LShiftKey"),
	HX_CSTRING("RShiftKey"),
	HX_CSTRING("LControlKey"),
	HX_CSTRING("RControlKey"),
	HX_CSTRING("LAlt"),
	HX_CSTRING("RAlt"),
	HX_CSTRING("BrowserBack"),
	HX_CSTRING("BrowserForward"),
	HX_CSTRING("BrowserRefresh"),
	HX_CSTRING("BrowserStop"),
	HX_CSTRING("BrowserSearch"),
	HX_CSTRING("BrowserFavorites"),
	HX_CSTRING("BrowserHome"),
	HX_CSTRING("VolumeMute"),
	HX_CSTRING("VolumeDown"),
	HX_CSTRING("VolumeUp"),
	HX_CSTRING("MediaNextTrack"),
	HX_CSTRING("MediaPreviousTrack"),
	HX_CSTRING("MediaStop"),
	HX_CSTRING("MediaPlayPause"),
	HX_CSTRING("LaunchMail"),
	HX_CSTRING("SelectMedia"),
	HX_CSTRING("LaunchApplication1"),
	HX_CSTRING("LaunchApplication2"),
	HX_CSTRING("Oem1"),
	HX_CSTRING("OemSemicolon"),
	HX_CSTRING("Oemplus"),
	HX_CSTRING("Oemcomma"),
	HX_CSTRING("OemMinus"),
	HX_CSTRING("OemPeriod"),
	HX_CSTRING("OemQuestion"),
	HX_CSTRING("Oem2"),
	HX_CSTRING("Oemtilde"),
	HX_CSTRING("Oem3"),
	HX_CSTRING("Oem4"),
	HX_CSTRING("OemOpenBrackets"),
	HX_CSTRING("OemPipe"),
	HX_CSTRING("Oem5"),
	HX_CSTRING("Oem6"),
	HX_CSTRING("OemCloseBrackets"),
	HX_CSTRING("Oem7"),
	HX_CSTRING("OemQuotes"),
	HX_CSTRING("Oem8"),
	HX_CSTRING("Oem102"),
	HX_CSTRING("OemBackslash"),
	HX_CSTRING("ProcessKey"),
	HX_CSTRING("Packet"),
	HX_CSTRING("Attn"),
	HX_CSTRING("Crsel"),
	HX_CSTRING("Exsel"),
	HX_CSTRING("EraseEof"),
	HX_CSTRING("Play"),
	HX_CSTRING("Zoom"),
	HX_CSTRING("NoName"),
	HX_CSTRING("Pa1"),
	HX_CSTRING("OemClear"),
	HX_CSTRING("KeyCodeMask"),
	HX_CSTRING("ShiftModifier"),
	HX_CSTRING("ControlModifier"),
	HX_CSTRING("AltModifier"),
	HX_CSTRING("Face1"),
	HX_CSTRING("Face2"),
	HX_CSTRING("Face3"),
	HX_CSTRING("Face4"),
	HX_CSTRING("LeftShoulder"),
	HX_CSTRING("RightShoulder"),
	HX_CSTRING("LeftShoulderBottom"),
	HX_CSTRING("RightShoulderBottom"),
	HX_CSTRING("ButtonSelect"),
	HX_CSTRING("ButtonStart"),
	HX_CSTRING("LeftAnalogueStick"),
	HX_CSTRING("RightAnalogueStick"),
	HX_CSTRING("PadTop"),
	HX_CSTRING("PadBottom"),
	HX_CSTRING("PadLeft"),
	HX_CSTRING("PadRight"),
	HX_CSTRING("LeftAnalogueHor"),
	HX_CSTRING("LeftAnalogueVert"),
	HX_CSTRING("RightAnalogueHor"),
	HX_CSTRING("RightAnalogueVert"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(KeyCode_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Modifiers,"Modifiers");
	HX_MARK_MEMBER_NAME(KeyCode_obj::None,"None");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Mouse0,"Mouse0");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Mouse1,"Mouse1");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Cancel,"Cancel");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Mouse2,"Mouse2");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Mouse3,"Mouse3");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Mouse4,"Mouse4");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Back,"Back");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Tab,"Tab");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LineFeed,"LineFeed");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Clear,"Clear");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Enter,"Enter");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Return,"Return");
	HX_MARK_MEMBER_NAME(KeyCode_obj::ShiftKey,"ShiftKey");
	HX_MARK_MEMBER_NAME(KeyCode_obj::ControlKey,"ControlKey");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Alt,"Alt");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Pause,"Pause");
	HX_MARK_MEMBER_NAME(KeyCode_obj::CapsLock,"CapsLock");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Capital,"Capital");
	HX_MARK_MEMBER_NAME(KeyCode_obj::KanaMode,"KanaMode");
	HX_MARK_MEMBER_NAME(KeyCode_obj::HanguelMode,"HanguelMode");
	HX_MARK_MEMBER_NAME(KeyCode_obj::HangulMode,"HangulMode");
	HX_MARK_MEMBER_NAME(KeyCode_obj::JunjaMode,"JunjaMode");
	HX_MARK_MEMBER_NAME(KeyCode_obj::FinalMode,"FinalMode");
	HX_MARK_MEMBER_NAME(KeyCode_obj::KanjiMode,"KanjiMode");
	HX_MARK_MEMBER_NAME(KeyCode_obj::HanjaMode,"HanjaMode");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Escape,"Escape");
	HX_MARK_MEMBER_NAME(KeyCode_obj::IMEConvert,"IMEConvert");
	HX_MARK_MEMBER_NAME(KeyCode_obj::IMENonconvert,"IMENonconvert");
	HX_MARK_MEMBER_NAME(KeyCode_obj::IMEAceept,"IMEAceept");
	HX_MARK_MEMBER_NAME(KeyCode_obj::IMEAccept,"IMEAccept");
	HX_MARK_MEMBER_NAME(KeyCode_obj::IMEModeChange,"IMEModeChange");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Space,"Space");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Prior,"Prior");
	HX_MARK_MEMBER_NAME(KeyCode_obj::PageUp,"PageUp");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Next,"Next");
	HX_MARK_MEMBER_NAME(KeyCode_obj::PageDown,"PageDown");
	HX_MARK_MEMBER_NAME(KeyCode_obj::End,"End");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Home,"Home");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Left,"Left");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Up,"Up");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Right,"Right");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Down,"Down");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Select,"Select");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Print,"Print");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Execute,"Execute");
	HX_MARK_MEMBER_NAME(KeyCode_obj::PrintScreen,"PrintScreen");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Snapshot,"Snapshot");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Insert,"Insert");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Delete,"Delete");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Help,"Help");
	HX_MARK_MEMBER_NAME(KeyCode_obj::D0,"D0");
	HX_MARK_MEMBER_NAME(KeyCode_obj::D1,"D1");
	HX_MARK_MEMBER_NAME(KeyCode_obj::D2,"D2");
	HX_MARK_MEMBER_NAME(KeyCode_obj::D3,"D3");
	HX_MARK_MEMBER_NAME(KeyCode_obj::D4,"D4");
	HX_MARK_MEMBER_NAME(KeyCode_obj::D5,"D5");
	HX_MARK_MEMBER_NAME(KeyCode_obj::D6,"D6");
	HX_MARK_MEMBER_NAME(KeyCode_obj::D7,"D7");
	HX_MARK_MEMBER_NAME(KeyCode_obj::D8,"D8");
	HX_MARK_MEMBER_NAME(KeyCode_obj::D9,"D9");
	HX_MARK_MEMBER_NAME(KeyCode_obj::A,"A");
	HX_MARK_MEMBER_NAME(KeyCode_obj::B,"B");
	HX_MARK_MEMBER_NAME(KeyCode_obj::C,"C");
	HX_MARK_MEMBER_NAME(KeyCode_obj::D,"D");
	HX_MARK_MEMBER_NAME(KeyCode_obj::E,"E");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F,"F");
	HX_MARK_MEMBER_NAME(KeyCode_obj::G,"G");
	HX_MARK_MEMBER_NAME(KeyCode_obj::H,"H");
	HX_MARK_MEMBER_NAME(KeyCode_obj::I,"I");
	HX_MARK_MEMBER_NAME(KeyCode_obj::J,"J");
	HX_MARK_MEMBER_NAME(KeyCode_obj::K,"K");
	HX_MARK_MEMBER_NAME(KeyCode_obj::L,"L");
	HX_MARK_MEMBER_NAME(KeyCode_obj::M,"M");
	HX_MARK_MEMBER_NAME(KeyCode_obj::N,"N");
	HX_MARK_MEMBER_NAME(KeyCode_obj::O,"O");
	HX_MARK_MEMBER_NAME(KeyCode_obj::P,"P");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Q,"Q");
	HX_MARK_MEMBER_NAME(KeyCode_obj::R,"R");
	HX_MARK_MEMBER_NAME(KeyCode_obj::S,"S");
	HX_MARK_MEMBER_NAME(KeyCode_obj::T,"T");
	HX_MARK_MEMBER_NAME(KeyCode_obj::U,"U");
	HX_MARK_MEMBER_NAME(KeyCode_obj::V,"V");
	HX_MARK_MEMBER_NAME(KeyCode_obj::W,"W");
	HX_MARK_MEMBER_NAME(KeyCode_obj::X,"X");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Y,"Y");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Z,"Z");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LWin,"LWin");
	HX_MARK_MEMBER_NAME(KeyCode_obj::RWin,"RWin");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Apps,"Apps");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Sleep,"Sleep");
	HX_MARK_MEMBER_NAME(KeyCode_obj::NumPad0,"NumPad0");
	HX_MARK_MEMBER_NAME(KeyCode_obj::NumPad1,"NumPad1");
	HX_MARK_MEMBER_NAME(KeyCode_obj::NumPad2,"NumPad2");
	HX_MARK_MEMBER_NAME(KeyCode_obj::NumPad3,"NumPad3");
	HX_MARK_MEMBER_NAME(KeyCode_obj::NumPad4,"NumPad4");
	HX_MARK_MEMBER_NAME(KeyCode_obj::NumPad5,"NumPad5");
	HX_MARK_MEMBER_NAME(KeyCode_obj::NumPad6,"NumPad6");
	HX_MARK_MEMBER_NAME(KeyCode_obj::NumPad7,"NumPad7");
	HX_MARK_MEMBER_NAME(KeyCode_obj::NumPad8,"NumPad8");
	HX_MARK_MEMBER_NAME(KeyCode_obj::NumPad9,"NumPad9");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Multiply,"Multiply");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Add,"Add");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Separator,"Separator");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Subtract,"Subtract");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Decimal,"Decimal");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Divide,"Divide");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F1,"F1");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F2,"F2");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F3,"F3");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F4,"F4");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F5,"F5");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F6,"F6");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F7,"F7");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F8,"F8");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F9,"F9");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F10,"F10");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F11,"F11");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F12,"F12");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F13,"F13");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F14,"F14");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F15,"F15");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F16,"F16");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F17,"F17");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F18,"F18");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F19,"F19");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F20,"F20");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F21,"F21");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F22,"F22");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F23,"F23");
	HX_MARK_MEMBER_NAME(KeyCode_obj::F24,"F24");
	HX_MARK_MEMBER_NAME(KeyCode_obj::NumLock,"NumLock");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Scroll,"Scroll");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LShiftKey,"LShiftKey");
	HX_MARK_MEMBER_NAME(KeyCode_obj::RShiftKey,"RShiftKey");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LControlKey,"LControlKey");
	HX_MARK_MEMBER_NAME(KeyCode_obj::RControlKey,"RControlKey");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LAlt,"LAlt");
	HX_MARK_MEMBER_NAME(KeyCode_obj::RAlt,"RAlt");
	HX_MARK_MEMBER_NAME(KeyCode_obj::BrowserBack,"BrowserBack");
	HX_MARK_MEMBER_NAME(KeyCode_obj::BrowserForward,"BrowserForward");
	HX_MARK_MEMBER_NAME(KeyCode_obj::BrowserRefresh,"BrowserRefresh");
	HX_MARK_MEMBER_NAME(KeyCode_obj::BrowserStop,"BrowserStop");
	HX_MARK_MEMBER_NAME(KeyCode_obj::BrowserSearch,"BrowserSearch");
	HX_MARK_MEMBER_NAME(KeyCode_obj::BrowserFavorites,"BrowserFavorites");
	HX_MARK_MEMBER_NAME(KeyCode_obj::BrowserHome,"BrowserHome");
	HX_MARK_MEMBER_NAME(KeyCode_obj::VolumeMute,"VolumeMute");
	HX_MARK_MEMBER_NAME(KeyCode_obj::VolumeDown,"VolumeDown");
	HX_MARK_MEMBER_NAME(KeyCode_obj::VolumeUp,"VolumeUp");
	HX_MARK_MEMBER_NAME(KeyCode_obj::MediaNextTrack,"MediaNextTrack");
	HX_MARK_MEMBER_NAME(KeyCode_obj::MediaPreviousTrack,"MediaPreviousTrack");
	HX_MARK_MEMBER_NAME(KeyCode_obj::MediaStop,"MediaStop");
	HX_MARK_MEMBER_NAME(KeyCode_obj::MediaPlayPause,"MediaPlayPause");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LaunchMail,"LaunchMail");
	HX_MARK_MEMBER_NAME(KeyCode_obj::SelectMedia,"SelectMedia");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LaunchApplication1,"LaunchApplication1");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LaunchApplication2,"LaunchApplication2");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Oem1,"Oem1");
	HX_MARK_MEMBER_NAME(KeyCode_obj::OemSemicolon,"OemSemicolon");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Oemplus,"Oemplus");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Oemcomma,"Oemcomma");
	HX_MARK_MEMBER_NAME(KeyCode_obj::OemMinus,"OemMinus");
	HX_MARK_MEMBER_NAME(KeyCode_obj::OemPeriod,"OemPeriod");
	HX_MARK_MEMBER_NAME(KeyCode_obj::OemQuestion,"OemQuestion");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Oem2,"Oem2");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Oemtilde,"Oemtilde");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Oem3,"Oem3");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Oem4,"Oem4");
	HX_MARK_MEMBER_NAME(KeyCode_obj::OemOpenBrackets,"OemOpenBrackets");
	HX_MARK_MEMBER_NAME(KeyCode_obj::OemPipe,"OemPipe");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Oem5,"Oem5");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Oem6,"Oem6");
	HX_MARK_MEMBER_NAME(KeyCode_obj::OemCloseBrackets,"OemCloseBrackets");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Oem7,"Oem7");
	HX_MARK_MEMBER_NAME(KeyCode_obj::OemQuotes,"OemQuotes");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Oem8,"Oem8");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Oem102,"Oem102");
	HX_MARK_MEMBER_NAME(KeyCode_obj::OemBackslash,"OemBackslash");
	HX_MARK_MEMBER_NAME(KeyCode_obj::ProcessKey,"ProcessKey");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Packet,"Packet");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Attn,"Attn");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Crsel,"Crsel");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Exsel,"Exsel");
	HX_MARK_MEMBER_NAME(KeyCode_obj::EraseEof,"EraseEof");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Play,"Play");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Zoom,"Zoom");
	HX_MARK_MEMBER_NAME(KeyCode_obj::NoName,"NoName");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Pa1,"Pa1");
	HX_MARK_MEMBER_NAME(KeyCode_obj::OemClear,"OemClear");
	HX_MARK_MEMBER_NAME(KeyCode_obj::KeyCodeMask,"KeyCodeMask");
	HX_MARK_MEMBER_NAME(KeyCode_obj::ShiftModifier,"ShiftModifier");
	HX_MARK_MEMBER_NAME(KeyCode_obj::ControlModifier,"ControlModifier");
	HX_MARK_MEMBER_NAME(KeyCode_obj::AltModifier,"AltModifier");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Face1,"Face1");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Face2,"Face2");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Face3,"Face3");
	HX_MARK_MEMBER_NAME(KeyCode_obj::Face4,"Face4");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LeftShoulder,"LeftShoulder");
	HX_MARK_MEMBER_NAME(KeyCode_obj::RightShoulder,"RightShoulder");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LeftShoulderBottom,"LeftShoulderBottom");
	HX_MARK_MEMBER_NAME(KeyCode_obj::RightShoulderBottom,"RightShoulderBottom");
	HX_MARK_MEMBER_NAME(KeyCode_obj::ButtonSelect,"ButtonSelect");
	HX_MARK_MEMBER_NAME(KeyCode_obj::ButtonStart,"ButtonStart");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LeftAnalogueStick,"LeftAnalogueStick");
	HX_MARK_MEMBER_NAME(KeyCode_obj::RightAnalogueStick,"RightAnalogueStick");
	HX_MARK_MEMBER_NAME(KeyCode_obj::PadTop,"PadTop");
	HX_MARK_MEMBER_NAME(KeyCode_obj::PadBottom,"PadBottom");
	HX_MARK_MEMBER_NAME(KeyCode_obj::PadLeft,"PadLeft");
	HX_MARK_MEMBER_NAME(KeyCode_obj::PadRight,"PadRight");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LeftAnalogueHor,"LeftAnalogueHor");
	HX_MARK_MEMBER_NAME(KeyCode_obj::LeftAnalogueVert,"LeftAnalogueVert");
	HX_MARK_MEMBER_NAME(KeyCode_obj::RightAnalogueHor,"RightAnalogueHor");
	HX_MARK_MEMBER_NAME(KeyCode_obj::RightAnalogueVert,"RightAnalogueVert");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(KeyCode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Modifiers,"Modifiers");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::None,"None");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Mouse0,"Mouse0");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Mouse1,"Mouse1");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Cancel,"Cancel");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Mouse2,"Mouse2");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Mouse3,"Mouse3");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Mouse4,"Mouse4");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Back,"Back");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Tab,"Tab");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LineFeed,"LineFeed");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Clear,"Clear");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Enter,"Enter");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Return,"Return");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::ShiftKey,"ShiftKey");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::ControlKey,"ControlKey");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Alt,"Alt");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Pause,"Pause");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::CapsLock,"CapsLock");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Capital,"Capital");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::KanaMode,"KanaMode");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::HanguelMode,"HanguelMode");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::HangulMode,"HangulMode");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::JunjaMode,"JunjaMode");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::FinalMode,"FinalMode");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::KanjiMode,"KanjiMode");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::HanjaMode,"HanjaMode");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Escape,"Escape");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::IMEConvert,"IMEConvert");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::IMENonconvert,"IMENonconvert");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::IMEAceept,"IMEAceept");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::IMEAccept,"IMEAccept");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::IMEModeChange,"IMEModeChange");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Space,"Space");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Prior,"Prior");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::PageUp,"PageUp");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Next,"Next");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::PageDown,"PageDown");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::End,"End");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Home,"Home");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Left,"Left");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Up,"Up");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Right,"Right");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Down,"Down");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Select,"Select");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Print,"Print");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Execute,"Execute");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::PrintScreen,"PrintScreen");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Snapshot,"Snapshot");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Insert,"Insert");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Delete,"Delete");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Help,"Help");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::D0,"D0");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::D1,"D1");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::D2,"D2");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::D3,"D3");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::D4,"D4");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::D5,"D5");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::D6,"D6");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::D7,"D7");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::D8,"D8");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::D9,"D9");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::A,"A");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::B,"B");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::C,"C");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::D,"D");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::E,"E");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F,"F");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::G,"G");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::H,"H");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::I,"I");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::J,"J");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::K,"K");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::L,"L");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::M,"M");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::N,"N");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::O,"O");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::P,"P");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Q,"Q");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::R,"R");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::S,"S");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::T,"T");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::U,"U");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::V,"V");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::W,"W");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::X,"X");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Y,"Y");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Z,"Z");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LWin,"LWin");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::RWin,"RWin");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Apps,"Apps");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Sleep,"Sleep");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::NumPad0,"NumPad0");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::NumPad1,"NumPad1");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::NumPad2,"NumPad2");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::NumPad3,"NumPad3");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::NumPad4,"NumPad4");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::NumPad5,"NumPad5");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::NumPad6,"NumPad6");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::NumPad7,"NumPad7");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::NumPad8,"NumPad8");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::NumPad9,"NumPad9");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Multiply,"Multiply");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Add,"Add");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Separator,"Separator");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Subtract,"Subtract");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Decimal,"Decimal");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Divide,"Divide");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F1,"F1");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F2,"F2");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F3,"F3");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F4,"F4");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F5,"F5");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F6,"F6");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F7,"F7");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F8,"F8");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F9,"F9");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F10,"F10");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F11,"F11");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F12,"F12");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F13,"F13");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F14,"F14");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F15,"F15");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F16,"F16");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F17,"F17");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F18,"F18");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F19,"F19");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F20,"F20");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F21,"F21");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F22,"F22");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F23,"F23");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::F24,"F24");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::NumLock,"NumLock");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Scroll,"Scroll");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LShiftKey,"LShiftKey");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::RShiftKey,"RShiftKey");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LControlKey,"LControlKey");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::RControlKey,"RControlKey");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LAlt,"LAlt");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::RAlt,"RAlt");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::BrowserBack,"BrowserBack");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::BrowserForward,"BrowserForward");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::BrowserRefresh,"BrowserRefresh");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::BrowserStop,"BrowserStop");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::BrowserSearch,"BrowserSearch");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::BrowserFavorites,"BrowserFavorites");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::BrowserHome,"BrowserHome");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::VolumeMute,"VolumeMute");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::VolumeDown,"VolumeDown");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::VolumeUp,"VolumeUp");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::MediaNextTrack,"MediaNextTrack");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::MediaPreviousTrack,"MediaPreviousTrack");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::MediaStop,"MediaStop");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::MediaPlayPause,"MediaPlayPause");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LaunchMail,"LaunchMail");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::SelectMedia,"SelectMedia");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LaunchApplication1,"LaunchApplication1");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LaunchApplication2,"LaunchApplication2");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Oem1,"Oem1");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::OemSemicolon,"OemSemicolon");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Oemplus,"Oemplus");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Oemcomma,"Oemcomma");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::OemMinus,"OemMinus");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::OemPeriod,"OemPeriod");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::OemQuestion,"OemQuestion");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Oem2,"Oem2");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Oemtilde,"Oemtilde");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Oem3,"Oem3");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Oem4,"Oem4");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::OemOpenBrackets,"OemOpenBrackets");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::OemPipe,"OemPipe");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Oem5,"Oem5");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Oem6,"Oem6");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::OemCloseBrackets,"OemCloseBrackets");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Oem7,"Oem7");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::OemQuotes,"OemQuotes");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Oem8,"Oem8");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Oem102,"Oem102");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::OemBackslash,"OemBackslash");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::ProcessKey,"ProcessKey");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Packet,"Packet");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Attn,"Attn");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Crsel,"Crsel");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Exsel,"Exsel");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::EraseEof,"EraseEof");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Play,"Play");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Zoom,"Zoom");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::NoName,"NoName");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Pa1,"Pa1");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::OemClear,"OemClear");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::KeyCodeMask,"KeyCodeMask");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::ShiftModifier,"ShiftModifier");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::ControlModifier,"ControlModifier");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::AltModifier,"AltModifier");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Face1,"Face1");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Face2,"Face2");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Face3,"Face3");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::Face4,"Face4");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LeftShoulder,"LeftShoulder");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::RightShoulder,"RightShoulder");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LeftShoulderBottom,"LeftShoulderBottom");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::RightShoulderBottom,"RightShoulderBottom");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::ButtonSelect,"ButtonSelect");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::ButtonStart,"ButtonStart");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LeftAnalogueStick,"LeftAnalogueStick");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::RightAnalogueStick,"RightAnalogueStick");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::PadTop,"PadTop");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::PadBottom,"PadBottom");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::PadLeft,"PadLeft");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::PadRight,"PadRight");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LeftAnalogueHor,"LeftAnalogueHor");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::LeftAnalogueVert,"LeftAnalogueVert");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::RightAnalogueHor,"RightAnalogueHor");
	HX_VISIT_MEMBER_NAME(KeyCode_obj::RightAnalogueVert,"RightAnalogueVert");
};

#endif

Class KeyCode_obj::__mClass;

void KeyCode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.input.KeyCode"), hx::TCanCast< KeyCode_obj> ,sStaticFields,sMemberFields,
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

void KeyCode_obj::__boot()
{
	Modifiers= (int)-65536;
	None= (int)0;
	Mouse0= (int)1;
	Mouse1= (int)2;
	Cancel= (int)3;
	Mouse2= (int)4;
	Mouse3= (int)5;
	Mouse4= (int)6;
	Back= (int)8;
	Tab= (int)9;
	LineFeed= (int)10;
	Clear= (int)12;
	Enter= (int)13;
	Return= (int)13;
	ShiftKey= (int)16;
	ControlKey= (int)17;
	Alt= (int)18;
	Pause= (int)19;
	CapsLock= (int)20;
	Capital= (int)20;
	KanaMode= (int)21;
	HanguelMode= (int)21;
	HangulMode= (int)21;
	JunjaMode= (int)23;
	FinalMode= (int)24;
	KanjiMode= (int)25;
	HanjaMode= (int)25;
	Escape= (int)27;
	IMEConvert= (int)28;
	IMENonconvert= (int)29;
	IMEAceept= (int)30;
	IMEAccept= (int)30;
	IMEModeChange= (int)31;
	Space= (int)32;
	Prior= (int)33;
	PageUp= (int)33;
	Next= (int)34;
	PageDown= (int)34;
	End= (int)35;
	Home= (int)36;
	Left= (int)37;
	Up= (int)38;
	Right= (int)39;
	Down= (int)40;
	Select= (int)41;
	Print= (int)42;
	Execute= (int)43;
	PrintScreen= (int)44;
	Snapshot= (int)44;
	Insert= (int)45;
	Delete= (int)46;
	Help= (int)47;
	D0= (int)48;
	D1= (int)49;
	D2= (int)50;
	D3= (int)51;
	D4= (int)52;
	D5= (int)53;
	D6= (int)54;
	D7= (int)55;
	D8= (int)56;
	D9= (int)57;
	A= (int)65;
	B= (int)66;
	C= (int)67;
	D= (int)68;
	E= (int)69;
	F= (int)70;
	G= (int)71;
	H= (int)72;
	I= (int)73;
	J= (int)74;
	K= (int)75;
	L= (int)76;
	M= (int)77;
	N= (int)78;
	O= (int)79;
	P= (int)80;
	Q= (int)81;
	R= (int)82;
	S= (int)83;
	T= (int)84;
	U= (int)85;
	V= (int)86;
	W= (int)87;
	X= (int)88;
	Y= (int)89;
	Z= (int)90;
	LWin= (int)91;
	RWin= (int)92;
	Apps= (int)93;
	Sleep= (int)95;
	NumPad0= (int)96;
	NumPad1= (int)97;
	NumPad2= (int)98;
	NumPad3= (int)99;
	NumPad4= (int)100;
	NumPad5= (int)101;
	NumPad6= (int)102;
	NumPad7= (int)103;
	NumPad8= (int)104;
	NumPad9= (int)105;
	Multiply= (int)106;
	Add= (int)107;
	Separator= (int)108;
	Subtract= (int)109;
	Decimal= (int)110;
	Divide= (int)111;
	F1= (int)112;
	F2= (int)113;
	F3= (int)114;
	F4= (int)115;
	F5= (int)116;
	F6= (int)117;
	F7= (int)118;
	F8= (int)119;
	F9= (int)120;
	F10= (int)121;
	F11= (int)122;
	F12= (int)123;
	F13= (int)124;
	F14= (int)125;
	F15= (int)126;
	F16= (int)127;
	F17= (int)128;
	F18= (int)129;
	F19= (int)130;
	F20= (int)131;
	F21= (int)132;
	F22= (int)133;
	F23= (int)134;
	F24= (int)135;
	NumLock= (int)144;
	Scroll= (int)145;
	LShiftKey= (int)160;
	RShiftKey= (int)161;
	LControlKey= (int)162;
	RControlKey= (int)163;
	LAlt= (int)164;
	RAlt= (int)165;
	BrowserBack= (int)166;
	BrowserForward= (int)167;
	BrowserRefresh= (int)168;
	BrowserStop= (int)169;
	BrowserSearch= (int)170;
	BrowserFavorites= (int)171;
	BrowserHome= (int)172;
	VolumeMute= (int)173;
	VolumeDown= (int)174;
	VolumeUp= (int)175;
	MediaNextTrack= (int)176;
	MediaPreviousTrack= (int)177;
	MediaStop= (int)178;
	MediaPlayPause= (int)179;
	LaunchMail= (int)180;
	SelectMedia= (int)181;
	LaunchApplication1= (int)182;
	LaunchApplication2= (int)183;
	Oem1= (int)186;
	OemSemicolon= (int)186;
	Oemplus= (int)187;
	Oemcomma= (int)188;
	OemMinus= (int)189;
	OemPeriod= (int)190;
	OemQuestion= (int)191;
	Oem2= (int)191;
	Oemtilde= (int)192;
	Oem3= (int)192;
	Oem4= (int)219;
	OemOpenBrackets= (int)219;
	OemPipe= (int)220;
	Oem5= (int)220;
	Oem6= (int)221;
	OemCloseBrackets= (int)221;
	Oem7= (int)222;
	OemQuotes= (int)222;
	Oem8= (int)223;
	Oem102= (int)226;
	OemBackslash= (int)226;
	ProcessKey= (int)229;
	Packet= (int)231;
	Attn= (int)246;
	Crsel= (int)247;
	Exsel= (int)248;
	EraseEof= (int)249;
	Play= (int)250;
	Zoom= (int)251;
	NoName= (int)252;
	Pa1= (int)253;
	OemClear= (int)254;
	KeyCodeMask= (int)65535;
	ShiftModifier= (int)65536;
	ControlModifier= (int)131072;
	AltModifier= (int)262144;
	Face1= (int)0;
	Face2= (int)1;
	Face3= (int)2;
	Face4= (int)3;
	LeftShoulder= (int)4;
	RightShoulder= (int)5;
	LeftShoulderBottom= (int)6;
	RightShoulderBottom= (int)7;
	ButtonSelect= (int)8;
	ButtonStart= (int)9;
	LeftAnalogueStick= (int)10;
	RightAnalogueStick= (int)11;
	PadTop= (int)12;
	PadBottom= (int)13;
	PadLeft= (int)14;
	PadRight= (int)15;
	LeftAnalogueHor= (int)0;
	LeftAnalogueVert= (int)1;
	RightAnalogueHor= (int)2;
	RightAnalogueVert= (int)3;
}

} // end namespace haxor
} // end namespace input
