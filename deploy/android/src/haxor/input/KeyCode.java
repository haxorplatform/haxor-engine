package haxor.input;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class KeyCode extends haxe.lang.HxObject
{
	static 
	{
		haxor.input.KeyCode.Modifiers = -65536;
		haxor.input.KeyCode.None = 0;
		haxor.input.KeyCode.Mouse0 = 1;
		haxor.input.KeyCode.Mouse1 = 2;
		haxor.input.KeyCode.Cancel = 3;
		haxor.input.KeyCode.Mouse2 = 4;
		haxor.input.KeyCode.Mouse3 = 5;
		haxor.input.KeyCode.Mouse4 = 6;
		haxor.input.KeyCode.Back = 8;
		haxor.input.KeyCode.Tab = 9;
		haxor.input.KeyCode.LineFeed = 10;
		haxor.input.KeyCode.Clear = 12;
		haxor.input.KeyCode.Enter = 13;
		haxor.input.KeyCode.Return = 13;
		haxor.input.KeyCode.ShiftKey = 16;
		haxor.input.KeyCode.ControlKey = 17;
		haxor.input.KeyCode.Alt = 18;
		haxor.input.KeyCode.Pause = 19;
		haxor.input.KeyCode.CapsLock = 20;
		haxor.input.KeyCode.Capital = 20;
		haxor.input.KeyCode.KanaMode = 21;
		haxor.input.KeyCode.HanguelMode = 21;
		haxor.input.KeyCode.HangulMode = 21;
		haxor.input.KeyCode.JunjaMode = 23;
		haxor.input.KeyCode.FinalMode = 24;
		haxor.input.KeyCode.KanjiMode = 25;
		haxor.input.KeyCode.HanjaMode = 25;
		haxor.input.KeyCode.Escape = 27;
		haxor.input.KeyCode.IMEConvert = 28;
		haxor.input.KeyCode.IMENonconvert = 29;
		haxor.input.KeyCode.IMEAceept = 30;
		haxor.input.KeyCode.IMEAccept = 30;
		haxor.input.KeyCode.IMEModeChange = 31;
		haxor.input.KeyCode.Space = 32;
		haxor.input.KeyCode.Prior = 33;
		haxor.input.KeyCode.PageUp = 33;
		haxor.input.KeyCode.Next = 34;
		haxor.input.KeyCode.PageDown = 34;
		haxor.input.KeyCode.End = 35;
		haxor.input.KeyCode.Home = 36;
		haxor.input.KeyCode.Left = 37;
		haxor.input.KeyCode.Up = 38;
		haxor.input.KeyCode.Right = 39;
		haxor.input.KeyCode.Down = 40;
		haxor.input.KeyCode.Select = 41;
		haxor.input.KeyCode.Print = 42;
		haxor.input.KeyCode.Execute = 43;
		haxor.input.KeyCode.PrintScreen = 44;
		haxor.input.KeyCode.Snapshot = 44;
		haxor.input.KeyCode.Insert = 45;
		haxor.input.KeyCode.Delete = 46;
		haxor.input.KeyCode.Help = 47;
		haxor.input.KeyCode.D0 = 48;
		haxor.input.KeyCode.D1 = 49;
		haxor.input.KeyCode.D2 = 50;
		haxor.input.KeyCode.D3 = 51;
		haxor.input.KeyCode.D4 = 52;
		haxor.input.KeyCode.D5 = 53;
		haxor.input.KeyCode.D6 = 54;
		haxor.input.KeyCode.D7 = 55;
		haxor.input.KeyCode.D8 = 56;
		haxor.input.KeyCode.D9 = 57;
		haxor.input.KeyCode.A = 65;
		haxor.input.KeyCode.B = 66;
		haxor.input.KeyCode.C = 67;
		haxor.input.KeyCode.D = 68;
		haxor.input.KeyCode.E = 69;
		haxor.input.KeyCode.F = 70;
		haxor.input.KeyCode.G = 71;
		haxor.input.KeyCode.H = 72;
		haxor.input.KeyCode.I = 73;
		haxor.input.KeyCode.J = 74;
		haxor.input.KeyCode.K = 75;
		haxor.input.KeyCode.L = 76;
		haxor.input.KeyCode.M = 77;
		haxor.input.KeyCode.N = 78;
		haxor.input.KeyCode.O = 79;
		haxor.input.KeyCode.P = 80;
		haxor.input.KeyCode.Q = 81;
		haxor.input.KeyCode.R = 82;
		haxor.input.KeyCode.S = 83;
		haxor.input.KeyCode.T = 84;
		haxor.input.KeyCode.U = 85;
		haxor.input.KeyCode.V = 86;
		haxor.input.KeyCode.W = 87;
		haxor.input.KeyCode.X = 88;
		haxor.input.KeyCode.Y = 89;
		haxor.input.KeyCode.Z = 90;
		haxor.input.KeyCode.LWin = 91;
		haxor.input.KeyCode.RWin = 92;
		haxor.input.KeyCode.Apps = 93;
		haxor.input.KeyCode.Sleep = 95;
		haxor.input.KeyCode.NumPad0 = 96;
		haxor.input.KeyCode.NumPad1 = 97;
		haxor.input.KeyCode.NumPad2 = 98;
		haxor.input.KeyCode.NumPad3 = 99;
		haxor.input.KeyCode.NumPad4 = 100;
		haxor.input.KeyCode.NumPad5 = 101;
		haxor.input.KeyCode.NumPad6 = 102;
		haxor.input.KeyCode.NumPad7 = 103;
		haxor.input.KeyCode.NumPad8 = 104;
		haxor.input.KeyCode.NumPad9 = 105;
		haxor.input.KeyCode.Multiply = 106;
		haxor.input.KeyCode.Add = 107;
		haxor.input.KeyCode.Separator = 108;
		haxor.input.KeyCode.Subtract = 109;
		haxor.input.KeyCode.Decimal = 110;
		haxor.input.KeyCode.Divide = 111;
		haxor.input.KeyCode.F1 = 112;
		haxor.input.KeyCode.F2 = 113;
		haxor.input.KeyCode.F3 = 114;
		haxor.input.KeyCode.F4 = 115;
		haxor.input.KeyCode.F5 = 116;
		haxor.input.KeyCode.F6 = 117;
		haxor.input.KeyCode.F7 = 118;
		haxor.input.KeyCode.F8 = 119;
		haxor.input.KeyCode.F9 = 120;
		haxor.input.KeyCode.F10 = 121;
		haxor.input.KeyCode.F11 = 122;
		haxor.input.KeyCode.F12 = 123;
		haxor.input.KeyCode.F13 = 124;
		haxor.input.KeyCode.F14 = 125;
		haxor.input.KeyCode.F15 = 126;
		haxor.input.KeyCode.F16 = 127;
		haxor.input.KeyCode.F17 = 128;
		haxor.input.KeyCode.F18 = 129;
		haxor.input.KeyCode.F19 = 130;
		haxor.input.KeyCode.F20 = 131;
		haxor.input.KeyCode.F21 = 132;
		haxor.input.KeyCode.F22 = 133;
		haxor.input.KeyCode.F23 = 134;
		haxor.input.KeyCode.F24 = 135;
		haxor.input.KeyCode.NumLock = 144;
		haxor.input.KeyCode.Scroll = 145;
		haxor.input.KeyCode.LShiftKey = 160;
		haxor.input.KeyCode.RShiftKey = 161;
		haxor.input.KeyCode.LControlKey = 162;
		haxor.input.KeyCode.RControlKey = 163;
		haxor.input.KeyCode.LAlt = 164;
		haxor.input.KeyCode.RAlt = 165;
		haxor.input.KeyCode.BrowserBack = 166;
		haxor.input.KeyCode.BrowserForward = 167;
		haxor.input.KeyCode.BrowserRefresh = 168;
		haxor.input.KeyCode.BrowserStop = 169;
		haxor.input.KeyCode.BrowserSearch = 170;
		haxor.input.KeyCode.BrowserFavorites = 171;
		haxor.input.KeyCode.BrowserHome = 172;
		haxor.input.KeyCode.VolumeMute = 173;
		haxor.input.KeyCode.VolumeDown = 174;
		haxor.input.KeyCode.VolumeUp = 175;
		haxor.input.KeyCode.MediaNextTrack = 176;
		haxor.input.KeyCode.MediaPreviousTrack = 177;
		haxor.input.KeyCode.MediaStop = 178;
		haxor.input.KeyCode.MediaPlayPause = 179;
		haxor.input.KeyCode.LaunchMail = 180;
		haxor.input.KeyCode.SelectMedia = 181;
		haxor.input.KeyCode.LaunchApplication1 = 182;
		haxor.input.KeyCode.LaunchApplication2 = 183;
		haxor.input.KeyCode.Oem1 = 186;
		haxor.input.KeyCode.OemSemicolon = 186;
		haxor.input.KeyCode.Oemplus = 187;
		haxor.input.KeyCode.Oemcomma = 188;
		haxor.input.KeyCode.OemMinus = 189;
		haxor.input.KeyCode.OemPeriod = 190;
		haxor.input.KeyCode.OemQuestion = 191;
		haxor.input.KeyCode.Oem2 = 191;
		haxor.input.KeyCode.Oemtilde = 192;
		haxor.input.KeyCode.Oem3 = 192;
		haxor.input.KeyCode.Oem4 = 219;
		haxor.input.KeyCode.OemOpenBrackets = 219;
		haxor.input.KeyCode.OemPipe = 220;
		haxor.input.KeyCode.Oem5 = 220;
		haxor.input.KeyCode.Oem6 = 221;
		haxor.input.KeyCode.OemCloseBrackets = 221;
		haxor.input.KeyCode.Oem7 = 222;
		haxor.input.KeyCode.OemQuotes = 222;
		haxor.input.KeyCode.Oem8 = 223;
		haxor.input.KeyCode.Oem102 = 226;
		haxor.input.KeyCode.OemBackslash = 226;
		haxor.input.KeyCode.ProcessKey = 229;
		haxor.input.KeyCode.Packet = 231;
		haxor.input.KeyCode.Attn = 246;
		haxor.input.KeyCode.Crsel = 247;
		haxor.input.KeyCode.Exsel = 248;
		haxor.input.KeyCode.EraseEof = 249;
		haxor.input.KeyCode.Play = 250;
		haxor.input.KeyCode.Zoom = 251;
		haxor.input.KeyCode.NoName = 252;
		haxor.input.KeyCode.Pa1 = 253;
		haxor.input.KeyCode.OemClear = 254;
		haxor.input.KeyCode.KeyCodeMask = 65535;
		haxor.input.KeyCode.ShiftModifier = 65536;
		haxor.input.KeyCode.ControlModifier = 131072;
		haxor.input.KeyCode.AltModifier = 262144;
		haxor.input.KeyCode.Face1 = 0;
		haxor.input.KeyCode.Face2 = 1;
		haxor.input.KeyCode.Face3 = 2;
		haxor.input.KeyCode.Face4 = 3;
		haxor.input.KeyCode.ButtonA = 0;
		haxor.input.KeyCode.ButtonB = 1;
		haxor.input.KeyCode.ButtonX = 2;
		haxor.input.KeyCode.ButtonY = 3;
		haxor.input.KeyCode.LeftShoulder = 4;
		haxor.input.KeyCode.RightShoulder = 5;
		haxor.input.KeyCode.LeftShoulderBottom = 6;
		haxor.input.KeyCode.RightShoulderBottom = 7;
		haxor.input.KeyCode.ButtonSelect = 8;
		haxor.input.KeyCode.ButtonStart = 9;
		haxor.input.KeyCode.LeftAnalogueStick = 10;
		haxor.input.KeyCode.RightAnalogueStick = 11;
		haxor.input.KeyCode.PadTop = 12;
		haxor.input.KeyCode.PadBottom = 13;
		haxor.input.KeyCode.PadLeft = 14;
		haxor.input.KeyCode.PadRight = 15;
		haxor.input.KeyCode.LeftAnalogueHor = 0;
		haxor.input.KeyCode.LeftAnalogueVert = 1;
		haxor.input.KeyCode.RightAnalogueHor = 2;
		haxor.input.KeyCode.RightAnalogueVert = 3;
	}
	public    KeyCode(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    KeyCode()
	{
		haxor.input.KeyCode.__hx_ctor_haxor_input_KeyCode(this);
	}
	
	
	public static   void __hx_ctor_haxor_input_KeyCode(haxor.input.KeyCode __temp_me160547)
	{
		{
		}
		
	}
	
	
	public static  int Modifiers;
	
	public static  int None;
	
	public static  int Mouse0;
	
	public static  int Mouse1;
	
	public static  int Cancel;
	
	public static  int Mouse2;
	
	public static  int Mouse3;
	
	public static  int Mouse4;
	
	public static  int Back;
	
	public static  int Tab;
	
	public static  int LineFeed;
	
	public static  int Clear;
	
	public static  int Enter;
	
	public static  int Return;
	
	public static  int ShiftKey;
	
	public static  int ControlKey;
	
	public static  int Alt;
	
	public static  int Pause;
	
	public static  int CapsLock;
	
	public static  int Capital;
	
	public static  int KanaMode;
	
	public static  int HanguelMode;
	
	public static  int HangulMode;
	
	public static  int JunjaMode;
	
	public static  int FinalMode;
	
	public static  int KanjiMode;
	
	public static  int HanjaMode;
	
	public static  int Escape;
	
	public static  int IMEConvert;
	
	public static  int IMENonconvert;
	
	public static  int IMEAceept;
	
	public static  int IMEAccept;
	
	public static  int IMEModeChange;
	
	public static  int Space;
	
	public static  int Prior;
	
	public static  int PageUp;
	
	public static  int Next;
	
	public static  int PageDown;
	
	public static  int End;
	
	public static  int Home;
	
	public static  int Left;
	
	public static  int Up;
	
	public static  int Right;
	
	public static  int Down;
	
	public static  int Select;
	
	public static  int Print;
	
	public static  int Execute;
	
	public static  int PrintScreen;
	
	public static  int Snapshot;
	
	public static  int Insert;
	
	public static  int Delete;
	
	public static  int Help;
	
	public static  int D0;
	
	public static  int D1;
	
	public static  int D2;
	
	public static  int D3;
	
	public static  int D4;
	
	public static  int D5;
	
	public static  int D6;
	
	public static  int D7;
	
	public static  int D8;
	
	public static  int D9;
	
	public static  int A;
	
	public static  int B;
	
	public static  int C;
	
	public static  int D;
	
	public static  int E;
	
	public static  int F;
	
	public static  int G;
	
	public static  int H;
	
	public static  int I;
	
	public static  int J;
	
	public static  int K;
	
	public static  int L;
	
	public static  int M;
	
	public static  int N;
	
	public static  int O;
	
	public static  int P;
	
	public static  int Q;
	
	public static  int R;
	
	public static  int S;
	
	public static  int T;
	
	public static  int U;
	
	public static  int V;
	
	public static  int W;
	
	public static  int X;
	
	public static  int Y;
	
	public static  int Z;
	
	public static  int LWin;
	
	public static  int RWin;
	
	public static  int Apps;
	
	public static  int Sleep;
	
	public static  int NumPad0;
	
	public static  int NumPad1;
	
	public static  int NumPad2;
	
	public static  int NumPad3;
	
	public static  int NumPad4;
	
	public static  int NumPad5;
	
	public static  int NumPad6;
	
	public static  int NumPad7;
	
	public static  int NumPad8;
	
	public static  int NumPad9;
	
	public static  int Multiply;
	
	public static  int Add;
	
	public static  int Separator;
	
	public static  int Subtract;
	
	public static  int Decimal;
	
	public static  int Divide;
	
	public static  int F1;
	
	public static  int F2;
	
	public static  int F3;
	
	public static  int F4;
	
	public static  int F5;
	
	public static  int F6;
	
	public static  int F7;
	
	public static  int F8;
	
	public static  int F9;
	
	public static  int F10;
	
	public static  int F11;
	
	public static  int F12;
	
	public static  int F13;
	
	public static  int F14;
	
	public static  int F15;
	
	public static  int F16;
	
	public static  int F17;
	
	public static  int F18;
	
	public static  int F19;
	
	public static  int F20;
	
	public static  int F21;
	
	public static  int F22;
	
	public static  int F23;
	
	public static  int F24;
	
	public static  int NumLock;
	
	public static  int Scroll;
	
	public static  int LShiftKey;
	
	public static  int RShiftKey;
	
	public static  int LControlKey;
	
	public static  int RControlKey;
	
	public static  int LAlt;
	
	public static  int RAlt;
	
	public static  int BrowserBack;
	
	public static  int BrowserForward;
	
	public static  int BrowserRefresh;
	
	public static  int BrowserStop;
	
	public static  int BrowserSearch;
	
	public static  int BrowserFavorites;
	
	public static  int BrowserHome;
	
	public static  int VolumeMute;
	
	public static  int VolumeDown;
	
	public static  int VolumeUp;
	
	public static  int MediaNextTrack;
	
	public static  int MediaPreviousTrack;
	
	public static  int MediaStop;
	
	public static  int MediaPlayPause;
	
	public static  int LaunchMail;
	
	public static  int SelectMedia;
	
	public static  int LaunchApplication1;
	
	public static  int LaunchApplication2;
	
	public static  int Oem1;
	
	public static  int OemSemicolon;
	
	public static  int Oemplus;
	
	public static  int Oemcomma;
	
	public static  int OemMinus;
	
	public static  int OemPeriod;
	
	public static  int OemQuestion;
	
	public static  int Oem2;
	
	public static  int Oemtilde;
	
	public static  int Oem3;
	
	public static  int Oem4;
	
	public static  int OemOpenBrackets;
	
	public static  int OemPipe;
	
	public static  int Oem5;
	
	public static  int Oem6;
	
	public static  int OemCloseBrackets;
	
	public static  int Oem7;
	
	public static  int OemQuotes;
	
	public static  int Oem8;
	
	public static  int Oem102;
	
	public static  int OemBackslash;
	
	public static  int ProcessKey;
	
	public static  int Packet;
	
	public static  int Attn;
	
	public static  int Crsel;
	
	public static  int Exsel;
	
	public static  int EraseEof;
	
	public static  int Play;
	
	public static  int Zoom;
	
	public static  int NoName;
	
	public static  int Pa1;
	
	public static  int OemClear;
	
	public static  int KeyCodeMask;
	
	public static  int ShiftModifier;
	
	public static  int ControlModifier;
	
	public static  int AltModifier;
	
	public static  int Face1;
	
	public static  int Face2;
	
	public static  int Face3;
	
	public static  int Face4;
	
	public static  int ButtonA;
	
	public static  int ButtonB;
	
	public static  int ButtonX;
	
	public static  int ButtonY;
	
	public static  int LeftShoulder;
	
	public static  int RightShoulder;
	
	public static  int LeftShoulderBottom;
	
	public static  int RightShoulderBottom;
	
	public static  int ButtonSelect;
	
	public static  int ButtonStart;
	
	public static  int LeftAnalogueStick;
	
	public static  int RightAnalogueStick;
	
	public static  int PadTop;
	
	public static  int PadBottom;
	
	public static  int PadLeft;
	
	public static  int PadRight;
	
	public static  int LeftAnalogueHor;
	
	public static  int LeftAnalogueVert;
	
	public static  int RightAnalogueHor;
	
	public static  int RightAnalogueVert;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.input.KeyCode(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.input.KeyCode();
	}
	
	
}


