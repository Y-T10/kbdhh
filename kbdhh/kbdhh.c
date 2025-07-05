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
