package haxor.input;
    
/**
 * Enumeration class for all KeyCodes used in the Input system.
 */
class KeyCode
{
	// Summary:
	//     The bitmask to extract modifiers from a key value.
	static public var Modifiers = -65536;
	//
	// Summary:
	//     No key pressed.
	static public var None = 0;
	//
	// Summary:
	//     The left mouse button.
	static public var Mouse0 = 1;
	//
	// Summary:
	//     The right mouse button.
	static public var Mouse1 = 2;
	//
	// Summary:
	//     The CANCEL key.
	static public var Cancel = 3;
	//
	// Summary:
	//     The middle mouse button (three-button mouse).
	static public var Mouse2 = 4;
	//
	// Summary:
	//     The first x mouse button (five-button mouse).
	static public var Mouse3 = 5;
	//
	// Summary:
	//     The second x mouse button (five-button mouse).
	static public var Mouse4 = 6;
	//
	// Summary:
	//     The BACKSPACE key.
	static public var Back = 8;
	//
	// Summary:
	//     The TAB key.
	static public var Tab = 9;
	//
	// Summary:
	//     The LINEFEED key.
	static public var LineFeed = 10;
	//
	// Summary:
	//     The CLEAR key.
	static public var Clear = 12;
	//
	// Summary:
	//     The ENTER key.
	static public var Enter = 13;
	//
	// Summary:
	//     The RETURN key.
	static public var Return = 13;
	//
	// Summary:
	//     The SHIFT key.
	static public var ShiftKey = 16;
	//
	// Summary:
	//     The CTRL key.
	static public var ControlKey = 17;
	//
	// Summary:
	//     The ALT key.
	static public var Alt = 18;
	//
	// Summary:
	//     The PAUSE key.
	static public var Pause = 19;
	//
	// Summary:
	//     The CAPS LOCK key.
	static public var CapsLock = 20;
	//
	// Summary:
	//     The CAPS LOCK key.
	static public var Capital = 20;
	//
	// Summary:
	//     The IME Kana mode key.
	static public var KanaMode = 21;
	//
	// Summary:
	//     The IME Hanguel mode key. (maintained for compatibility; use HangulMode)
	static public var HanguelMode = 21;
	//
	// Summary:
	//     The IME Hangul mode key.
	static public var HangulMode = 21;
	//
	// Summary:
	//     The IME Junja mode key.
	static public var JunjaMode = 23;
	//
	// Summary:
	//     The IME final mode key.
	static public var FinalMode = 24;
	//
	// Summary:
	//     The IME Kanji mode key.
	static public var KanjiMode = 25;
	//
	// Summary:
	//     The IME Hanja mode key.
	static public var HanjaMode = 25;
	//
	// Summary:
	//     The ESC key.
	static public var Escape = 27;
	//
	// Summary:
	//     The IME convert key.
	static public var IMEConvert = 28;
	//
	// Summary:
	//     The IME nonconvert key.
	static public var IMENonconvert = 29;
	//
	// Summary:
	//     The IME accept key. Obsolete; use System.Windows.Forms.Keys.IMEAccept instead.
	static public var IMEAceept = 30;
	//
	// Summary:
	//     The IME accept key; replaces System.Windows.Forms.Keys.IMEAceept.
	static public var IMEAccept = 30;
	//
	// Summary:
	//     The IME mode change key.
	static public var IMEModeChange = 31;
	//
	// Summary:
	//     The SPACEBAR key.
	static public var Space = 32;
	//
	// Summary:
	//     The PAGE UP key.
	static public var Prior = 33;
	//
	// Summary:
	//     The PAGE UP key.
	static public var PageUp = 33;
	//
	// Summary:
	//     The PAGE DOWN key.
	static public var Next = 34;
	//
	// Summary:
	//     The PAGE DOWN key.
	static public var PageDown = 34;
	//
	// Summary:
	//     The END key.
	static public var End = 35;
	//
	// Summary:
	//     The HOME key.
	static public var Home = 36;
	//
	// Summary:
	//     The LEFT ARROW key.
	static public var Left = 37;
	//
	// Summary:
	//     The UP ARROW key.
	static public var Up = 38;
	//
	// Summary:
	//     The RIGHT ARROW key.
	static public var Right = 39;
	//
	// Summary:
	//     The DOWN ARROW key.
	static public var Down = 40;
	//
	// Summary:
	//     The SELECT key.
	static public var Select = 41;
	//
	// Summary:
	//     The PRINT key.
	static public var Print = 42;
	//
	// Summary:
	//     The EXECUTE key.
	static public var Execute = 43;
	//
	// Summary:
	//     The PRINT SCREEN key.
	static public var PrintScreen = 44;
	//
	// Summary:
	//     The PRINT SCREEN key.
	static public var Snapshot = 44;
	//
	// Summary:
	//     The INS key.
	static public var Insert = 45;
	//
	// Summary:
	//     The DEL key.
	static public var Delete = 46;
	//
	// Summary:
	//     The HELP key.
	static public var Help = 47;
	//
	// Summary:
	//     The 0 key.
	static public var D0 = 48;
	//
	// Summary:
	//     The 1 key.
	static public var D1 = 49;
	//
	// Summary:
	//     The 2 key.
	static public var D2 = 50;
	//
	// Summary:
	//     The 3 key.
	static public var D3 = 51;
	//
	// Summary:
	//     The 4 key.
	static public var D4 = 52;
	//
	// Summary:
	//     The 5 key.
	static public var D5 = 53;
	//
	// Summary:
	//     The 6 key.
	static public var D6 = 54;
	//
	// Summary:
	//     The 7 key.
	static public var D7 = 55;
	//
	// Summary:
	//     The 8 key.
	static public var D8 = 56;
	//
	// Summary:
	//     The 9 key.
	static public var D9 = 57;
	//
	// Summary:
	//     The A key.
	static public var A = 65;
	//
	// Summary:
	//     The B key.
	static public var B = 66;
	//
	// Summary:
	//     The C key.
	static public var C = 67;
	//
	// Summary:
	//     The D key.
	static public var D = 68;
	//
	// Summary:
	//     The E key.
	static public var E = 69;
	//
	// Summary:
	//     The F key.
	static public var F = 70;
	//
	// Summary:
	//     The G key.
	static public var G = 71;
	//
	// Summary:
	//     The H key.
	static public var H = 72;
	//
	// Summary:
	//     The I key.
	static public var I = 73;
	//
	// Summary:
	//     The J key.
	static public var J = 74;
	//
	// Summary:
	//     The K key.
	static public var K = 75;
	//
	// Summary:
	//     The L key.
	static public var L = 76;
	//
	// Summary:
	//     The M key.
	static public var M = 77;
	//
	// Summary:
	//     The N key.
	static public var N = 78;
	//
	// Summary:
	//     The O key.
	static public var O = 79;
	//
	// Summary:
	//     The P key.
	static public var P = 80;
	//
	// Summary:
	//     The Q key.
	static public var Q = 81;
	//
	// Summary:
	//     The R key.
	static public var R = 82;
	//
	// Summary:
	//     The S key.
	static public var S = 83;
	//
	// Summary:
	//     The T key.
	static public var T = 84;
	//
	// Summary:
	//     The U key.
	static public var U = 85;
	//
	// Summary:
	//     The V key.
	static public var V = 86;
	//
	// Summary:
	//     The W key.
	static public var W = 87;
	//
	// Summary:
	//     The X key.
	static public var X = 88;
	//
	// Summary:
	//     The Y key.
	static public var Y = 89;
	//
	// Summary:
	//     The Z key.
	static public var Z = 90;
	//
	// Summary:
	//     The left Windows logo key (Microsoft Natural Keyboard).
	static public var LWin = 91;
	//
	// Summary:
	//     The right Windows logo key (Microsoft Natural Keyboard).
	static public var RWin = 92;
	//
	// Summary:
	//     The application key (Microsoft Natural Keyboard).
	static public var Apps = 93;
	//
	// Summary:
	//     The computer sleep key.
	static public var Sleep = 95;
	//
	// Summary:
	//     The 0 key on the numeric keypad.
	static public var NumPad0 = 96;
	//
	// Summary:
	//     The 1 key on the numeric keypad.
	static public var NumPad1 = 97;
	//
	// Summary:
	//     The 2 key on the numeric keypad.
	static public var NumPad2 = 98;
	//
	// Summary:
	//     The 3 key on the numeric keypad.
	static public var NumPad3 = 99;
	//
	// Summary:
	//     The 4 key on the numeric keypad.
	static public var NumPad4 = 100;
	//
	// Summary:
	//     The 5 key on the numeric keypad.
	static public var NumPad5 = 101;
	//
	// Summary:
	//     The 6 key on the numeric keypad.
	static public var NumPad6 = 102;
	//
	// Summary:
	//     The 7 key on the numeric keypad.
	static public var NumPad7 = 103;
	//
	// Summary:
	//     The 8 key on the numeric keypad.
	static public var NumPad8 = 104;
	//
	// Summary:
	//     The 9 key on the numeric keypad.
	static public var NumPad9 = 105;
	//
	// Summary:
	//     The multiply key.
	static public var Multiply = 106;
	//
	// Summary:
	//     The add key.
	static public var Add = 107;
	//
	// Summary:
	//     The separator key.
	static public var Separator = 108;
	//
	// Summary:
	//     The subtract key.
	static public var Subtract = 109;
	//
	// Summary:
	//     The decimal key.
	static public var Decimal = 110;
	//
	// Summary:
	//     The divide key.
	static public var Divide = 111;
	//
	// Summary:
	//     The F1 key.
	static public var F1 = 112;
	//
	// Summary:
	//     The F2 key.
	static public var F2 = 113;
	//
	// Summary:
	//     The F3 key.
	static public var F3 = 114;
	//
	// Summary:
	//     The F4 key.
	static public var F4 = 115;
	//
	// Summary:
	//     The F5 key.
	static public var F5 = 116;
	//
	// Summary:
	//     The F6 key.
	static public var F6 = 117;
	//
	// Summary:
	//     The F7 key.
	static public var F7 = 118;
	//
	// Summary:
	//     The F8 key.
	static public var F8 = 119;
	//
	// Summary:
	//     The F9 key.
	static public var F9 = 120;
	//
	// Summary:
	//     The F10 key.
	static public var F10 = 121;
	//
	// Summary:
	//     The F11 key.
	static public var F11 = 122;
	//
	// Summary:
	//     The F12 key.
	static public var F12 = 123;
	//
	// Summary:
	//     The F13 key.
	static public var F13 = 124;
	//
	// Summary:
	//     The F14 key.
	static public var F14 = 125;
	//
	// Summary:
	//     The F15 key.
	static public var F15 = 126;
	//
	// Summary:
	//     The F16 key.
	static public var F16 = 127;
	//
	// Summary:
	//     The F17 key.
	static public var F17 = 128;
	//
	// Summary:
	//     The F18 key.
	static public var F18 = 129;
	//
	// Summary:
	//     The F19 key.
	static public var F19 = 130;
	//
	// Summary:
	//     The F20 key.
	static public var F20 = 131;
	//
	// Summary:
	//     The F21 key.
	static public var F21 = 132;
	//
	// Summary:
	//     The F22 key.
	static public var F22 = 133;
	//
	// Summary:
	//     The F23 key.
	static public var F23 = 134;
	//
	// Summary:
	//     The F24 key.
	static public var F24 = 135;
	//
	// Summary:
	//     The NUM LOCK key.
	static public var NumLock = 144;
	//
	// Summary:
	//     The SCROLL LOCK key.
	static public var Scroll = 145;
	//
	// Summary:
	//     The left SHIFT key.
	static public var LShiftKey = 160;
	//
	// Summary:
	//     The right SHIFT key.
	static public var RShiftKey = 161;
	//
	// Summary:
	//     The left CTRL key.
	static public var LControlKey = 162;
	//
	// Summary:
	//     The right CTRL key.
	static public var RControlKey = 163;
	//
	// Summary:
	//     The left ALT key.	
	static public var LAlt = 164;
	//
	// Summary:
	//     The right ALT key.
	static public var RAlt = 165;
	//
	// Summary:
	//     The browser back key (Windows 2000 or later).
	static public var BrowserBack = 166;
	//
	// Summary:
	//     The browser forward key (Windows 2000 or later).
	static public var BrowserForward = 167;
	//
	// Summary:
	//     The browser refresh key (Windows 2000 or later).
	static public var BrowserRefresh = 168;
	//
	// Summary:
	//     The browser stop key (Windows 2000 or later).
	static public var BrowserStop = 169;
	//
	// Summary:
	//     The browser search key (Windows 2000 or later).
	static public var BrowserSearch = 170;
	//
	// Summary:
	//     The browser favorites key (Windows 2000 or later).
	static public var BrowserFavorites = 171;
	//
	// Summary:
	//     The browser home key (Windows 2000 or later).
	static public var BrowserHome = 172;
	//
	// Summary:
	//     The volume mute key (Windows 2000 or later).
	static public var VolumeMute = 173;
	//
	// Summary:
	//     The volume down key (Windows 2000 or later).
	static public var VolumeDown = 174;
	//
	// Summary:
	//     The volume up key (Windows 2000 or later).
	static public var VolumeUp = 175;
	//
	// Summary:
	//     The media next track key (Windows 2000 or later).
	static public var MediaNextTrack = 176;
	//
	// Summary:
	//     The media previous track key (Windows 2000 or later).
	static public var MediaPreviousTrack = 177;
	//
	// Summary:
	//     The media Stop key (Windows 2000 or later).
	static public var MediaStop = 178;
	//
	// Summary:
	//     The media play pause key (Windows 2000 or later).
	static public var MediaPlayPause = 179;
	//
	// Summary:
	//     The launch mail key (Windows 2000 or later).
	static public var LaunchMail = 180;
	//
	// Summary:
	//     The select media key (Windows 2000 or later).
	static public var SelectMedia = 181;
	//
	// Summary:
	//     The start application one key (Windows 2000 or later).
	static public var LaunchApplication1 = 182;
	//
	// Summary:
	//     The start application two key (Windows 2000 or later).
	static public var LaunchApplication2 = 183;
	//
	// Summary:
	//     The OEM 1 key.
	static public var Oem1 = 186;
	//
	// Summary:
	//     The OEM Semicolon key on a US standard keyboard (Windows 2000 or later).
	static public var OemSemicolon = 186;
	//
	// Summary:
	//     The OEM plus key on any country/region keyboard (Windows 2000 or later).
	static public var Oemplus = 187;
	//
	// Summary:
	//     The OEM comma key on any country/region keyboard (Windows 2000 or later).
	static public var Oemcomma = 188;
	//
	// Summary:
	//     The OEM minus key on any country/region keyboard (Windows 2000 or later).
	static public var OemMinus = 189;
	//
	// Summary:
	//     The OEM period key on any country/region keyboard (Windows 2000 or later).
	static public var OemPeriod = 190;
	//
	// Summary:
	//     The OEM question mark key on a US standard keyboard (Windows 2000 or later).
	static public var OemQuestion = 191;
	//
	// Summary:
	//     The OEM 2 key.
	static public var Oem2 = 191;
	//
	// Summary:
	//     The OEM tilde key on a US standard keyboard (Windows 2000 or later).
	static public var Oemtilde = 192;
	//
	// Summary:
	//     The OEM 3 key.
	static public var Oem3 = 192;
	//
	// Summary:
	//     The OEM 4 key.
	static public var Oem4 = 219;
	//
	// Summary:
	//     The OEM open bracket key on a US standard keyboard (Windows 2000 or later).
	static public var OemOpenBrackets = 219;
	//
	// Summary:
	//     The OEM pipe key on a US standard keyboard (Windows 2000 or later).
	static public var OemPipe = 220;
	//
	// Summary:
	//     The OEM 5 key.
	static public var Oem5 = 220;
	//
	// Summary:
	//     The OEM 6 key.
	static public var Oem6 = 221;
	//
	// Summary:
	//     The OEM close bracket key on a US standard keyboard (Windows 2000 or later).
	static public var OemCloseBrackets = 221;
	//
	// Summary:
	//     The OEM 7 key.
	static public var Oem7 = 222;
	//
	// Summary:
	//     The OEM singled/double quote key on a US standard keyboard (Windows 2000
	//     or later).
	static public var OemQuotes = 222;
	//
	// Summary:
	//     The OEM 8 key.
	static public var Oem8 = 223;
	//
	// Summary:
	//     The OEM 102 key.
	static public var Oem102 = 226;
	//
	// Summary:
	//     The OEM angle bracket or backslash key on the RT 102 key keyboard (Windows
	//     2000 or later).
	static public var OemBackslash = 226;
	//
	// Summary:
	//     The PROCESS KEY key.
	static public var ProcessKey = 229;
	//
	// Summary:
	//     Used to pass Unicode characters as if they were keystrokes. The Packet key
	//     value is the low word of a 32-bit virtual-key value used for non-keyboard
	//     input methods.
	static public var Packet = 231;
	//
	// Summary:
	//     The ATTN key.
	static public var Attn = 246;
	//
	// Summary:
	//     The CRSEL key.
	static public var Crsel = 247;
	//
	// Summary:
	//     The EXSEL key.
	static public var Exsel = 248;
	//
	// Summary:
	//     The ERASE EOF key.
	static public var EraseEof = 249;
	//
	// Summary:
	//     The PLAY key.
	static public var Play = 250;
	//
	// Summary:
	//     The ZOOM key.
	static public var Zoom = 251;
	//
	// Summary:
	//     A constant reserved for future use.
	static public var NoName = 252;
	//
	// Summary:
	//     The PA1 key.
	static public var Pa1 = 253;
	//
	// Summary:
	//     The CLEAR key.
	static public var OemClear = 254;
	//
	// Summary:
	//     The bitmask to extract a key code from a key value.
	static public var KeyCodeMask = 65535;
	//
	// Summary:
	//     The SHIFT modifier key.
	static public var ShiftModifier = 65536;
	//
	// Summary:
	//     The CTRL modifier key.
	static public var ControlModifier = 131072;
	//
	// Summary:
	//     The ALT modifier key.
	static public var AltModifier = 262144;
	
}

