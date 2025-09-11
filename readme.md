# KBDHH
英字配列キーボード向け日本語レイアウトDLL．

## 概要
KBDHHは、WindowsにてUS配列のキーボードによる日本語入力を実現するレイアウトDLLで、英字配列に下記のキーが追加されたレイアウトを表す．
これより変換/無変換キーを用いてIMEのオン/オフを切り替え、英字キーボードでも日本語入力を可能にする．

- [x] 変換
- [x] 無変換

## ビルド方法
構成環境とプラットフォームを下記のとおりに設定し、ビルドコマンドを実行する．
- プラットフォーム：実行環境のアーキテクチャ
- 構成環境：`Release`

## インストール
日本語環境のWindowsにインストールする方法を紹介する．
インストールに失敗した場合に備え、Windowsの復旧手段を用意しておくことを***強く勧める***．

まず、生成されたDLLファイル`kbdhh.dll`をWindowsのシステムフォルダ`C:\Windows\System32`内に置く．
次に、レジストリキー`HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\i8042prt\Parameters`のエントリを以下のように変更する．
エントリが存在しない場合、「設定」アプリにてハードウェアキーボードレイアウトを変更し、エントリを生成する必要がある．

```
Windows Registry Editor Version 5.00

[HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\i8042prt\Parameters]
"LayerDriver JPN"="kbdhh.dll"
"OverrideKeyboardIdentifier"="KBDHH"
"OverrideKeyboardType"=dword:00000007
"OverrideKeyboardSubtype"=dword:00000001
```

最後にWindowsの再起動を実行する．インストールが成功した場合、再起動後にログイン画面が表示される．

## インストールが失敗した場合
再起動後にログイン画面に到達できないなら、WindowsによるDLLの読み込みが失敗したことになる．
この場合、インストールにて変更したエントリを元の値に戻した状態で起動すれば再度ログインできるようになる．
Windowsの外からレジストリを変更するには`chntpw`を使用すればよい．
このツールはLinux上で動作し、ディスク内のレジストリデータを編集することができる．
そのため外部メディアからUbuntu等を起動できれば、そこからWindowsがインストールされたディスクにアクセスし、エントリを修復することができる．

* `chntpw`のホームページ: https://pogostick.net/~pnh/ntpasswd/
* `chntpw`の使用例: https://www.nexia.jp/comapny/index.html

## DLLのビルド
### 構成マネージャ
実行環境に合わせて構成、プラットフォームを決定する．
多くの場合では構成環境を`Release`、プラットフォームを実行環境のアーキテクチャに設定すればよい．

### オプション
コンパイル、ビルドのオプションを下記のとおりに設定する．

- 全般
	* 構成の種類: ダイナミックライブラリ
	* プラットフォームツールセット: `WindowsApplicationForDrivers10.0`
- リンカ
    * 入力
        + すべての既定のライブラリの無視: はい（`/NODEFAULTLIB`）
        + モジュール定義ファイル: `path/to/file.def`
    * 詳細設定
        + エントリポイントなし: はい（`/NOENTRY`）
    * すべてのオプション
        + その他のオプション: `-merge:.edata=.data -merge:.rdata=.data -merge:.bss=.data -section:.data,r /ignore:4254`

上記の設定に加え、プログラムの実装ミスをコンパイル時に検知するために下記の設定を追加してもよい．

- C/C++
    * 全般
        + 警告レベル: レベル4

### モジュール定義ファイル
キーボードレイアウトDLLの実装を記述しただけではC関数`KbdLayerDescriptor`、`KbdNlsLayerDescriptor`をエクスポートできない．
これらの関数を外部に公開するにはモジュール定義ファイルが必要になる．
このファイルの記述は下図のとおりで、リンカにDLLの生成を指示する．
1行目の`LIBRARY`節は名前`KBDHH`を持つDLLの生成をリンカーに指示する．
この節はファイルの先頭に置かれる必要がある．
3-5行目の`EXPORTS`節はエクスポート対象の関数名とその序数を定義する．
各関数に割り当てられる序数は決められている．

```
LIBRARY KBDHH

EXPORTS
    KbdLayerDescriptor    @1
    KbdNlsLayerDescriptor @2
```

### リソースファイル
キーボードレイアウトDLLのプロパティ画面では、DLLのバージョン情報や対応言語を確認することができる．
これらの情報はリソースファイルにて定義され、DLLのビルド時に埋め込まれる．
リソースファイルの実装は下図のとおりで、Cのプリプロセス命令のサブセットで記述される．
```
#include <windows.h>
#include <ntverp.h>

#define VER_FILETYPE              VFT_DLL
#define VER_FILESUBTYPE           VFT2_UNKNOWN
#define VER_FILEDESCRIPTION_STR   "Custom 105 layout"
#define VER_INTERNALNAME_STR      "KBDHH"
#define VER_ORIGINALFILENAME_STR  "kbdhh.dll"
#define VER_LANGNEUTRAL

#include "common.ver"
```
4-9行目では以下の情報を持つのマクロ定数を定義する．
11行目では、これらのマクロ定数をファイル`common.ver`内の雛形に当てはめ、バージョン情報の定義を生成する．

| マクロ定数 | 内容 |
| :-----------------------| :--- |
|`VER_FILETYPE` | ファイルの種類 |
|`VER_FILESUBTYPE` | ファイルのサブタイプ|
|`VER_FILEDESCRIPTION_STR` |ファイルの概要文|
|`VER_INTERNALNAME_STR`|ファイルの内部名|
|`VER_ORIGINALFILENAME_STR`|ファイル名|
|`VER_LANGNEUTRAL`|ロケールを指定しない|

`common.ver`内の雛形を使用するため、マクロ定数の定義では以下のマクロが持つ値を定める必要がある．
* `VER_FILETYPE`
* `VER_FILESUBTYPE`
* `VER_FILEDESCRIPTION_STR`
* `VER_INTERNALNAME_STR`
