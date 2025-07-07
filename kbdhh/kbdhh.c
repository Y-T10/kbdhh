#pragma once

// 不要な機能を除外する

// 不要な機能を除外する
#define WIN32_LEAN_AND_MEAN
#define NOCOM

#include <Windows.h>
#include <dontuse.h>
#include <kbd.h>

/* レイアウトデータの属性設定 */
#if defined(_WIN64)
    // データセクションを定義する
    #pragma section(".data")
    // キーボードデータの属性マクロを定義する
    #define ATTR_KBD_DATA __declspec(allocate(".data"))
#elif defined(_WIN32)
    // 広域変数のデータセクション名を指定する
    #pragma data_seg(".data")
    // キーボードデータの属性マクロを定義する
    #define ATTR_KBD_DATA
#else
    #error "Target platform is not supported."
#endif

#define VK_INVAILED 0x00ff

// キーボードレイアウトのサブタイプ
#define KBD_SUB_TYPE 0xff
// 製造元のID
#define OEM_ID 0xff // TODO: 個人制作の場合にどうするかを調べる

static const ATTR_KBD_DATA USHORT Scancode2VK[] = {
    [0x00] =  VK_INVAILED,
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
    [0x3a] = VK_INVAILED, // Caps Lock(VK_CAPITAL)を無効にする
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
    [0x5a] = VK_INVAILED, // AX105のVK_NONCONVERT
    [0x5b] = VK_INVAILED, // AX105のVK_CONVERT
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
    [0x79] = VK_CONVERT | KBDSPECIAL,    // USBキーボードの変換キー対応
    [0x7a] = VK_INVAILED,
    [0x7b] = VK_NONCONVERT | KBDSPECIAL, // USBキーボードの変換キー対応
    [0x7c] = VK_TAB,
    [0x7d] = VK_INVAILED,
    [0x7e] = 0xC2,           // 予約済仮想キーコード
    [0x7f] = VK_OEM_PA2,
};

// AX105をベースにいくつかのキーを追加
// TODO: 未対応の拡張キーを追加する
static const ATTR_KBD_DATA VSC_VK E0Scancode2VK[] = {
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
  {0x52, KBDEXT | VK_INSERT },
  {0x53, KBDEXT | VK_DELETE},
  {0x5b, KBDEXT | VK_LWIN},
  {0x5c, KBDEXT | VK_RWIN},
  {0x5d, KBDEXT | VK_APPS},
};

// E1接頭辞付キー
static const ATTR_KBD_DATA VSC_VK E1Scancode2VK[] = {
    {0x1D, VK_PAUSE}
};

// キー名リスト
static const ATTR_KBD_DATA VSC_LPWSTR KeyName[] = {
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
static const ATTR_KBD_DATA VSC_LPWSTR KeyNameExt[] = {
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
    {0x54, L"<00>"},
    {0x56, L"Help"},
    {0x5b, L"Left Windows"},
    {0x5c, L"Right Windows"},
    {0x5d, L"Application"},
    {0x00, NULL}
};

// レイアウト情報
const ATTR_KBD_DATA KBDTABLES TablesHH = {
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
    .dwSubType = MAKEWORD(KBD_SUB_TYPE, OEM_ID)
};

//  言語固有のレイアウト情報
const ATTR_KBD_DATA KBDNLSTABLES NLSTablesHH = {
    .OEMIdentifier = OEM_ID,
    .LayoutInformation = 0,
    .NumOfMouseVKey = 0,
    .pusMouseVKey = NULL
};

// キーボードレイアウト情報を返す
const KBDTABLES* KbdLayerDescriptor() {
    return &TablesHH;
}

// 言語固有の機能情報を返す
const KBDNLSTABLES* KbdNlsLayerDescriptor() {
    return &NLSTablesHH;
}
