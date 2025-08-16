#pragma once

// C23でコンパイルするかを検証する
// TODO: 0b表記を10進数表記に直し、C99でコンパイルできるようにする
#if __STDC_VERSION__ < 202311L
    #error "C23 以上でコンパイルしてください"
#endif

// 不要な機能を除外する
#define WIN32_LEAN_AND_MEAN
#define NOCOM

#include <Windows.h>
#include <dontuse.h>
#include <kbd.h>

/* レイアウトデータの属性設定 */
#if defined(_M_IA64)
    // データセクションを定義する
    #pragma section(".data")
    // キーボードデータの属性マクロを定義する
    #define ATTR_KBD_DATA __declspec(allocate(".data"))
    #pragma message("build for IA64")
#else
    // 広域変数のデータセクション名を指定する
    #pragma data_seg(".data")
    // キーボードデータの属性マクロを定義する
    #define ATTR_KBD_DATA
    #pragma message("build for not IA64")
#endif

#define VK_INVAILED 0x00ff

// キーボードレイアウトのサブタイプ
#define KBD_SUB_TYPE 0xff
// 製造元のID
#define OEM_ID 0xff // TODO: 個人制作の場合にどうするかを調べる

// ASCII の制御文字定数
#define ASCII_DEL  0x007f
#define ASCII_EXT  0x0003
#define ASCII_ESC  0x001b
#define ASCII_FSEP 0x001c
#define ASCII_GSEP 0x001d
#define ASCII_RSEP 0x001e
#define ASCII_USEP 0x001f

static ATTR_KBD_DATA USHORT Scancode2VK[] = {
    [0x00] = VK_INVAILED,
    [0x01] = VK_ESCAPE,
    [0x02] = '1',
    [0x03] = '2',
    [0x04] = '3',
    [0x05] = '4',
    [0x06] = '5',
    [0x07] = '6',
    [0x08] = '7',
    [0x09] = '8',
    [0x0a] = '9',
    [0x0b] = '0',
    [0x0c] = VK_OEM_MINUS,
    [0x0d] = VK_OEM_PLUS,
    [0x0e] = VK_BACK,
    [0x0f] = VK_TAB,
    [0x10] = 'Q',
    [0x11] = 'W',
    [0x12] = 'E',
    [0x13] = 'R',
    [0x14] = 'T',
    [0x15] = 'Y',
    [0x16] = 'U',
    [0x17] = 'I',
    [0x18] = 'O',
    [0x19] = 'P',
    [0x1a] = VK_OEM_4,
    [0x1b] = VK_OEM_6,
    [0x1c] = VK_RETURN,
    [0x1d] = VK_LCONTROL,
    [0x1e] = 'A',
    [0x1f] = 'S',
    [0x20] = 'D',
    [0x21] = 'F',
    [0x22] = 'G',
    [0x23] = 'H',
    [0x24] = 'J',
    [0x25] = 'K',
    [0x26] = 'L',
    [0x27] = VK_OEM_1,
    [0x28] = VK_OEM_7,
    [0x29] = VK_OEM_3,
    [0x2a] = VK_SHIFT,
    [0x2b] = VK_OEM_5,
    [0x2c] = 'Z',
    [0x2d] = 'X',
    [0x2e] = 'C',
    [0x2f] = 'V',
    [0x30] = 'B',
    [0x31] = 'N',
    [0x32] = 'M',
    [0x33] = VK_OEM_COMMA,
    [0x34] = VK_OEM_PERIOD,
    [0x35] = VK_OEM_2,
    [0x36] = VK_RSHIFT | KBDEXT,
    [0x37] = VK_MULTIPLY | KBDMULTIVK, // Ctrl/Shiftとの組み合わせ時にSnapShotを押下する
    [0x38] = VK_LMENU,    // デフォルトのaltキー
    [0x39] = VK_SPACE,
    [0x3a] = VK_CAPITAL, // Caps Lock (無効にしてもよい)
    [0x3b] = VK_F1,
    [0x3c] = VK_F2,
    [0x3d] = VK_F3,
    [0x3e] = VK_F4,
    [0x3f] = VK_F5,
    [0x40] = VK_F6,
    [0x41] = VK_F7,
    [0x42] = VK_F8,
    [0x43] = VK_F9,
    [0x44] = VK_F10,
    [0x45] = VK_NUMLOCK | KBDEXT | KBDMULTIVK, // Ctrlとの組み合わせ時にPauseを押下する
    [0x46] = VK_SCROLL | KBDMULTIVK, //  Ctrlとの組み合わせ時にCancelを出力する
    [0x47] = VK_HOME | KBDNUMPAD | KBDSPECIAL, // KBDNUMPAD: テンキーの数字キーまたは少数点キー
    [0x48] = VK_UP | KBDNUMPAD | KBDSPECIAL, // KBDSPECIAL: 特殊キー
    [0x49] = VK_PRIOR | KBDNUMPAD | KBDSPECIAL,
    [0x4a] = VK_SUBTRACT,
    [0x4b] = VK_LEFT | KBDNUMPAD | KBDSPECIAL,
    [0x4c] = VK_CLEAR | KBDNUMPAD | KBDSPECIAL,
    [0x4d] = VK_RIGHT | KBDNUMPAD | KBDSPECIAL,
    [0x4e] = VK_ADD,
    [0x4f] = VK_END | KBDNUMPAD | KBDSPECIAL,
    [0x50] = VK_DOWN | KBDNUMPAD | KBDSPECIAL,
    [0x51] = VK_NEXT | KBDNUMPAD | KBDSPECIAL,
    [0x52] = VK_INSERT | KBDNUMPAD | KBDSPECIAL,
    [0x53] = VK_DELETE | KBDNUMPAD | KBDSPECIAL,
    [0x54] = VK_SNAPSHOT,
    [0x55] = VK_INVAILED,
    [0x56] = VK_OEM_102,
    [0x57] = VK_F11,
    [0x58] = VK_F12,
    [0x59] = VK_CLEAR,
    [0x5a] = VK_NONCONVERT, // AX105のVK_NONCONVERT
    [0x5b] = VK_CONVERT,    // AX105のVK_CONVERT
    [0x5c] = VK_OEM_AX,
    [0x5d] = VK_EREOF,
    [0x5e] = VK_INVAILED,
    [0x5f] = VK_NONAME,
    [0x60] = VK_INVAILED,
    [0x61] = VK_INVAILED,
    [0x62] = VK_INVAILED,
    [0x63] = VK_INVAILED,
    [0x64] = VK_F13,
    [0x65] = VK_F14,
    [0x66] = VK_F15,
    [0x67] = VK_F16,
    [0x68] = VK_F17,
    [0x69] = VK_F18,
    [0x6a] = VK_F19,
    [0x6b] = VK_F20,
    [0x6c] = VK_F21,
    [0x6d] = VK_F22,
    [0x6e] = VK_F23,
    [0x6f] = VK_INVAILED,
    [0x70] = VK_INVAILED,
    [0x71] = VK_INVAILED,
    [0x72] = VK_INVAILED,
    [0x73] = VK_INVAILED,
    [0x74] = VK_INVAILED,
    [0x75] = VK_INVAILED,
    [0x76] = VK_F24,
    [0x77] = VK_INVAILED,
    [0x78] = VK_INVAILED,
    [0x79] = VK_CONVERT,    // USBキーボードの変換キー対応
    [0x7a] = VK_INVAILED,
    [0x7b] = VK_NONCONVERT, // USBキーボードの変換キー対応
    [0x7c] = VK_TAB,
    [0x7d] = VK_INVAILED,
    [0x7e] = 0xC2,           // 予約済仮想キーコード
    [0x7f] = VK_OEM_PA2,
};

// AX105をベースにいくつかのキーを追加
// TODO: 未対応の拡張キーを追加する
static ATTR_KBD_DATA VSC_VK E0Scancode2VK[] = {
  {0x1c, KBDEXT | VK_MEDIA_PREV_TRACK },
  {0x35, KBDEXT | VK_DIVIDE},
  {0x37, KBDEXT | VK_SNAPSHOT},
  {0x38, KBDEXT | VK_RMENU}, // VK_KANJI | KBDSPECIAL から修正
  {0X46, KBDEXT | VK_CANCEL}, // Break key (by Ctrl pasue)
  {0X47, KBDEXT | VK_HOME},
  {0X48, KBDEXT | VK_UP},
  {0X49, KBDEXT | VK_PRIOR},
  {0X4B, KBDEXT | VK_LEFT},
  {0X4D, KBDEXT | VK_RIGHT},
  {0X4F, KBDEXT | VK_END},
  {0x50, KBDEXT | VK_DOWN},
  {0x51, KBDEXT | VK_NEXT},
  {0x52, KBDEXT | VK_INSERT},
  {0x53, KBDEXT | VK_DELETE},
  {0x5b, KBDEXT | VK_LWIN},
  {0x5c, KBDEXT | VK_RWIN},
  {0x5d, KBDEXT | VK_APPS},
  {0x00, 0x00}
};

// E1接頭辞付キー
static ATTR_KBD_DATA VSC_VK E1Scancode2VK[] = {
    {0x1D, VK_PAUSE},
    {0x00, 0x00 }
};

// キー名リスト
static ATTR_KBD_DATA VSC_LPWSTR KeyName[] = {
    {0x01, L"Esc"},
    {0x0e, L"Backspace"},
    {0x0f, L"Tab"},
    {0x1c, L"Enter"},
    {0x1d, L"Ctrl"},
    {0x2a, L"Shift"},
    {0x36, L"Right Shift"},
    {0x37, L"Num *"},
    {0x38, L"Alt"},
    {0x39, L"Space"},
    {0x3a, L"Caps Lock"},
    {0x3b, L"F1"},
    {0x3c, L"F2"},
    {0x3d, L"F3"},
    {0x3e, L"F4"},
    {0x3f, L"F5"},
    {0x40, L"F6"},
    {0x41, L"F7"},
    {0x42, L"F8"},
    {0x43, L"F9"},
    {0x44, L"F10"},
    {0x45, L"Pause"},
    {0x46, L"Scroll Lock"},
    {0x47, L"Num 7"},
    {0x48, L"Num 8"},
    {0x49, L"Num 9"},
    {0x4a, L"Num -"},
    {0x4b, L"Num 4"},
    {0x4c, L"Num 5"},
    {0x4d, L"Num 6"},
    {0x4e, L"Num +"},
    {0x4f, L"Num 1"},
    {0x50, L"Num 2"},
    {0x51, L"Num 3"},
    {0x52, L"Num 0"},
    {0x53, L"Num Del"},
    {0x54, L"Sys Req"},
    {0x57, L"F11"},
    {0x58, L"F12"},
    {0x7b, L"無変換"},
    {0x79, L"変換"},
    {0x5c, L"AX"},
    {0x7c, L"F13"},
    {0x7d, L"F14"},
    {0x7e, L"F15"},
    {0x7f, L"F16"},
    {0x80, L"F17"},
    {0x81, L"F18"},
    {0x82, L"F19"},
    {0x83, L"F20"},
    {0x84, L"F21"},
    {0x85, L"F22"},
    {0x86, L"F23"},
    {0x87, L"F24"},
    {0x00, NULL}
};

// 0xE0接頭辞付きキー名リスト
static ATTR_KBD_DATA VSC_LPWSTR KeyNameExt[] = {
    {0x1c, L"Num Enter"},
    {0x35, L"Num /"},
    {0x37, L"Prnt Scrn"},
    {0x38, L"Right Alt"},
    {0x45, L"Num Lock"},
    {0x46, L"Break"},
    {0x47, L"Home"},
    {0x48, L"Up"},
    {0x49, L"Page Up"},
    {0x4b, L"Left"},
    {0x4d, L"Right"},
    {0x4f, L"End"},
    {0x50, L"Down"},
    {0x51, L"Page Down"},
    {0x52, L"Insert"},
    {0x53, L"Delete"},
    {0x56, L"Help"},
    {0x5b, L"Left Windows"},
    {0x5c, L"Right Windows"},
    {0x5d, L"Application"},
    {0x00, NULL}
};

// 修飾キーのビット位置を指定
static ATTR_KBD_DATA VK_TO_BIT VKBitPos[] = {
    // 下記設定は必須
    { VK_SHIFT   , KBDSHIFT},
    { VK_CONTROL , KBDCTRL},
    { VK_MENU    , KBDALT},
    { 0          , 0 }
};

// 修飾キー情報
static ATTR_KBD_DATA MODIFIERS ModifierConf = {
    .pVkToBit = (PVK_TO_BIT)(VKBitPos),
    .wMaxModBits = 7,           // 修飾キー押下パターン個数
    .ModNumber = {
        [0b000] = 0,            // キー入力なし
        [0b001] = 1,            // Shift押下
        [0b010] = 2,            // Control押下
        [0b011] = 3,            // Shift,Control押下
        [0b100] = SHFT_INVALID, // Alt押下時に文字列を出力しない
        [0b101] = SHFT_INVALID,
        [0b110] = SHFT_INVALID,
        [0b111] = SHFT_INVALID,
    }
};

static ATTR_KBD_DATA VK_TO_WCHARS4 VKCharsAll[] = {
    {.VirtualKey = '2'          , .Attributes = 0, .wch = {L'2'     , L'@'      , WCH_NONE  , L'\0'     }},
    {.VirtualKey = '6'          , .Attributes = 0, .wch = {L'6'     , L'^'      , WCH_NONE  , ASCII_RSEP}},
    {.VirtualKey = VK_OEM_MINUS , .Attributes = 0, .wch = {L'-'     , L'_'      , WCH_NONE  , ASCII_USEP}},
    {.VirtualKey = 0            , .Attributes = 0, .wch = {L'\0'    , L'\0'     , L'\0'     , L'\0'     }}
};

static ATTR_KBD_DATA VK_TO_WCHARS3 VKCharsShCtr[] = {
    {.VirtualKey = VK_BACK      , .Attributes = 0, .wch = {L'\b'    , L'\b'    , ASCII_DEL }},
    {.VirtualKey = VK_CANCEL    , .Attributes = 0, .wch = {ASCII_EXT, ASCII_EXT, ASCII_EXT }},
    {.VirtualKey = VK_ESCAPE    , .Attributes = 0, .wch = {ASCII_ESC, ASCII_ESC, ASCII_ESC }},
    {.VirtualKey = VK_OEM_4     , .Attributes = 0, .wch = {L'['     , L'{'     , ASCII_ESC }},
    {.VirtualKey = VK_OEM_5     , .Attributes = 0, .wch = {L'\\'    , L'|'     , ASCII_ESC }},
    {.VirtualKey = VK_OEM_102   , .Attributes = 0, .wch = {L'\\'    , L'|'     , ASCII_FSEP}},
    {.VirtualKey = VK_OEM_6     , .Attributes = 0, .wch = {L']'     , L'}'     , ASCII_GSEP}},
    {.VirtualKey = VK_RETURN    , .Attributes = 0, .wch = {L'\r'    , L'\r'    , L'\n'     }},
    {.VirtualKey = VK_SPACE     , .Attributes = 0, .wch = {L' '     , L' '     , L' '      }},
    {.VirtualKey = 0            , .Attributes = 0, .wch = {L'\0'    , L'\0'    , L'\0'     }}
};

static ATTR_KBD_DATA VK_TO_WCHARS2 VKCharsSh[] = {
    {.VirtualKey = '0'          , .Attributes = 0     , .wch = {L'0'    , L')'    }},
    {.VirtualKey = '1'          , .Attributes = 0     , .wch = {L'1'    , L'!'    }},
    {.VirtualKey = '3'          , .Attributes = 0     , .wch = {L'3'    , L'#'    }},
    {.VirtualKey = '4'          , .Attributes = 0     , .wch = {L'4'    , L'$'    }},
    {.VirtualKey = '5'          , .Attributes = 0     , .wch = {L'5'    , L'%'    }},
    {.VirtualKey = '7'          , .Attributes = 0     , .wch = {L'7'    , L'&'    }},
    {.VirtualKey = '8'          , .Attributes = 0     , .wch = {L'8'    , L'*'    }},
    {.VirtualKey = '9'          , .Attributes = 0     , .wch = {L'9'    , L'('    }},
    {.VirtualKey = 'A'          , .Attributes = CAPLOK, .wch = {L'a'    , L'A'    }},
    {.VirtualKey = 'B'          , .Attributes = CAPLOK, .wch = {L'b'    , L'B'    }},
    {.VirtualKey = 'C'          , .Attributes = CAPLOK, .wch = {L'c'    , L'C'    }},
    {.VirtualKey = 'D'          , .Attributes = CAPLOK, .wch = {L'd'    , L'D'    }},
    {.VirtualKey = 'E'          , .Attributes = CAPLOK, .wch = {L'e'    , L'E'    }},
    {.VirtualKey = 'F'          , .Attributes = CAPLOK, .wch = {L'f'    , L'F'    }},
    {.VirtualKey = 'G'          , .Attributes = CAPLOK, .wch = {L'g'    , L'G'    }},
    {.VirtualKey = 'H'          , .Attributes = CAPLOK, .wch = {L'h'    , L'H'    }},
    {.VirtualKey = 'I'          , .Attributes = CAPLOK, .wch = {L'i'    , L'I'    }},
    {.VirtualKey = 'J'          , .Attributes = CAPLOK, .wch = {L'j'    , L'J'    }},
    {.VirtualKey = 'K'          , .Attributes = CAPLOK, .wch = {L'k'    , L'K'    }},
    {.VirtualKey = 'L'          , .Attributes = CAPLOK, .wch = {L'l'    , L'L'    }},
    {.VirtualKey = 'M'          , .Attributes = CAPLOK, .wch = {L'm'    , L'M'    }},
    {.VirtualKey = 'N'          , .Attributes = CAPLOK, .wch = {L'n'    , L'N'    }},
    {.VirtualKey = 'O'          , .Attributes = CAPLOK, .wch = {L'o'    , L'O'    }},
    {.VirtualKey = 'P'          , .Attributes = CAPLOK, .wch = {L'p'    , L'P'    }},
    {.VirtualKey = 'Q'          , .Attributes = CAPLOK, .wch = {L'q'    , L'Q'    }},
    {.VirtualKey = 'R'          , .Attributes = CAPLOK, .wch = {L'r'    , L'R'    }},
    {.VirtualKey = 'S'          , .Attributes = CAPLOK, .wch = {L's'    , L'S'    }},
    {.VirtualKey = 'T'          , .Attributes = CAPLOK, .wch = {L't'    , L'T'    }},
    {.VirtualKey = 'U'          , .Attributes = CAPLOK, .wch = {L'u'    , L'U'    }},
    {.VirtualKey = 'V'          , .Attributes = CAPLOK, .wch = {L'v'    , L'V'    }},
    {.VirtualKey = 'W'          , .Attributes = CAPLOK, .wch = {L'w'    , L'W'    }},
    {.VirtualKey = 'X'          , .Attributes = CAPLOK, .wch = {L'x'    , L'X'    }},
    {.VirtualKey = 'Y'          , .Attributes = CAPLOK, .wch = {L'y'    , L'Y'    }},
    {.VirtualKey = 'Z'          , .Attributes = CAPLOK, .wch = {L'z'    , L'Z'    }},
    {.VirtualKey = VK_OEM_1     , .Attributes = 0     , .wch = {L';'    , L':'    }},
    {.VirtualKey = VK_OEM_2     , .Attributes = 0     , .wch = {L'/'    , L'?'    }},
    {.VirtualKey = VK_OEM_3     , .Attributes = 0     , .wch = {L'`'    , L'~'    }},
    {.VirtualKey = VK_OEM_7     , .Attributes = 0     , .wch = {L'\''   , L'\"'   }},
    {.VirtualKey = VK_OEM_8     , .Attributes = 0     , .wch = {WCH_NONE, WCH_NONE}},
    {.VirtualKey = VK_OEM_PERIOD, .Attributes = 0     , .wch = {L'.'    , L'>'    }},
    {.VirtualKey = VK_OEM_COMMA , .Attributes = 0     , .wch = {L','    , L'<'    }},
    {.VirtualKey = VK_OEM_PLUS  , .Attributes = 0     , .wch = {L'='    , L'+'    }},
    {.VirtualKey = VK_TAB       , .Attributes = 0     , .wch = {L'\t'   , L'\t'   }},
    {.VirtualKey = VK_ADD       , .Attributes = 0     , .wch = {L'+'    , L'+'    }},
    {.VirtualKey = VK_DECIMAL   , .Attributes = 0     , .wch = {L'.'    , L'.'    }},
    {.VirtualKey = VK_DIVIDE    , .Attributes = 0     , .wch = {L'/'    , L'/'    }},
    {.VirtualKey = VK_MULTIPLY  , .Attributes = 0     , .wch = {L'*'    , L'*'    }},
    {.VirtualKey = VK_SUBTRACT  , .Attributes = 0     , .wch = {L'-'    , L'-'    }},
    {.VirtualKey = 0            , .Attributes = 0     , .wch = {L'\0'   , L'\0'   }}
};

static ATTR_KBD_DATA VK_TO_WCHARS2 NumpadChars[] = {
    {.VirtualKey = VK_NUMPAD0, .Attributes = 0, .wch = {L'0' , WCH_NONE}},
    {.VirtualKey = VK_NUMPAD1, .Attributes = 0, .wch = {L'1' , WCH_NONE}},
    {.VirtualKey = VK_NUMPAD2, .Attributes = 0, .wch = {L'2' , WCH_NONE}},
    {.VirtualKey = VK_NUMPAD3, .Attributes = 0, .wch = {L'3' , WCH_NONE}},
    {.VirtualKey = VK_NUMPAD4, .Attributes = 0, .wch = {L'4' , WCH_NONE}},
    {.VirtualKey = VK_NUMPAD5, .Attributes = 0, .wch = {L'5' , WCH_NONE}},
    {.VirtualKey = VK_NUMPAD6, .Attributes = 0, .wch = {L'6' , WCH_NONE}},
    {.VirtualKey = VK_NUMPAD7, .Attributes = 0, .wch = {L'7' , WCH_NONE}},
    {.VirtualKey = VK_NUMPAD8, .Attributes = 0, .wch = {L'8' , WCH_NONE}},
    {.VirtualKey = VK_NUMPAD9, .Attributes = 0, .wch = {L'9' , WCH_NONE}},
    {.VirtualKey = 0         , .Attributes = 0, .wch = {L'\0',0        }}
};

// 印字情報一覧
static ATTR_KBD_DATA VK_TO_WCHAR_TABLE PrintedCharTables[] = {
    {(PVK_TO_WCHARS1)(VKCharsAll)   , 4, sizeof(VKCharsAll[0])},
    {(PVK_TO_WCHARS1)(VKCharsShCtr) , 3, sizeof(VKCharsShCtr[0])},
    {(PVK_TO_WCHARS1)(VKCharsSh)    , 2, sizeof(VKCharsSh[0])},
    {(PVK_TO_WCHARS1)(NumpadChars)  , 2, sizeof(NumpadChars[0])},
    {NULL, 0, 0}
};

// レイアウト情報
ATTR_KBD_DATA KBDTABLES TablesHH = {
    // 印字テーブル
    .pVkToWcharTable = PrintedCharTables,

    // 言語固有の処理はない
    .fLocaleFlags = 0,
    
    // デッドキーを使用しない
    .pDeadKey = NULL,

    // リガチャを使用しない
    .pLigature = NULL,
    .cbLgEntry = 0,
    .nLgMax = 0,

    // 修飾情報
    .pCharModifiers = &ModifierConf,

    // スキャンコード変換情報
    .pusVSCtoVK = Scancode2VK,
    .bMaxVSCtoVK = sizeof(Scancode2VK) / sizeof(Scancode2VK[0]),
    .pVSCtoVK_E0 = E0Scancode2VK,
    .pVSCtoVK_E1 = E1Scancode2VK,

    // キー名
    .pKeyNames = KeyName,
    .pKeyNamesExt = KeyNameExt,
    .pKeyNamesDead = NULL,

    // レイアウト情報
    .dwType = KEYBOARD_TYPE_JAPAN,
    .dwSubType = 0
};

// キーの機能テーブル
static ATTR_KBD_DATA VK_F VKFuncTable[] = {
    // CapsLockの機能
    {
        .Vk = VK_CAPITAL, .NLSFEProcType = KBDNLS_TYPE_TOGGLE,
        .NLSFEProcCurrent = KBDNLS_INDEX_NORMAL,
        .NLSFEProcSwitch = 0x08,
        .NLSFEProc = {
            {KBDNLS_SEND_BASE_VK,0},        // Base
            {KBDNLS_ALPHANUM,0},            // Shift
            {KBDNLS_HIRAGANA,0},            // Control
            {KBDNLS_SEND_PARAM_VK,VK_KANA}, // Shift+Control
            {KBDNLS_KATAKANA,0},            // Alt
            {KBDNLS_SEND_BASE_VK,0},        // Shift+Alt
            {KBDNLS_SEND_BASE_VK,0},        // Control+Alt
            {KBDNLS_SEND_BASE_VK,0}         // Shift+Control+Alt
        },
        .NLSFEProcAlt = {
            {KBDNLS_SEND_PARAM_VK,0}, // Base
            {KBDNLS_SEND_PARAM_VK,0}, // Shift
            {KBDNLS_SEND_PARAM_VK,0}, // Control
            {KBDNLS_SEND_PARAM_VK,0}, // Shift+Control
            {KBDNLS_SEND_BASE_VK,0},  // Alt
            {KBDNLS_SEND_BASE_VK,0},  // Shift+Alt
            {KBDNLS_SEND_BASE_VK,0},  // Control+Alt
            {KBDNLS_SEND_BASE_VK,0}   // Shift+Control+Alt
        }
    }
};

//  言語固有のレイアウト情報
ATTR_KBD_DATA KBDNLSTABLES NLSTablesHH = {
    .OEMIdentifier = OEM_ID,
    .LayoutInformation = 0,
    .NumOfMouseVKey = 0,
    .pusMouseVKey = NULL,
    .pVkToF = VKFuncTable,
    .NumOfVkToF = sizeof(VKFuncTable)/sizeof(VKFuncTable[0])
};

// キーボードレイアウト情報を返す
PKBDTABLES KbdLayerDescriptor() {
    return &TablesHH;
}

// 言語固有の機能情報を返す
PKBDNLSTABLES KbdNlsLayerDescriptor() {
    return &NLSTablesHH;
}
