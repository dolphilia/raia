# ドキュメントの草稿

## RaiaEngineの思想

何か一つの言語やプラットフォームに縛られることなくゲーム制作を楽しめる開発環境。

## 共有ライブラリ + インターフェース +JSON

```c
const char * func_name(const char *s)
```

## 共有ライブラリによる機能の共通化



## このドキュメントについて

RaiaEngineに関する包括的な解説を記述することを目的としています。

### RaiaEngineの特徴

- C言語基盤
- JavaScriptで記述できる
- スクリプトベース
- クロスプラットフォーム
- 拡張しやすいモジュール

規模なIDEを必要とせず、既存のエディターで編集することができます。プログラミング中心の開発に慣れている方におすすめです。


スクリプト言語にはJavaScript(ECMAScript)を採用しています。非常に広く使われているプログラミング言語ですので、学習コストを最小限にすることができます。TypeScriptやCoffeeScriptからトランスコンパイルしたコードにも対応しているため、より堅実に開発を進めることができます。

### 対応するプラットフォーム

- Windows
- macOS
- Linux

::: info
iOS、Androidおよびウェブ対応について:
デスクトップアプリとウェブアプリやモバイルアプリではゲーム体験が大きく異なります。そのため開発の優先度は低く見積もっています。
:::

### RaiaEngineの技術基盤

描画処理にはANGLEを採用しており、各プラットフォームに最適なグラフィックAPIが呼び出されます。例えばWindowsであればDirectX、macOSであればMetalAPIが選ばれます。ANGLEはGpenGLES互換レイヤーでもあるため、GpenGLESを利用するウェブやモバイルへの移植も容易になっています。
RaiaEngineはC言語で記述されており、移植性が高く、拡張が容易です。
サウンド処理にはOpenALを採用しています。

## 拡張しやすいモジュラー式

RaiaEngineはコンパクトな実行バイナリであるraia_coreに拡張プラグインを追加する形で動作します。これによりコードは独立して保守しやすくなります。また、RaiaEngineの拡張プラグインは比較的容易に作成できるため、高速で高度なシーンにも対応します。

## RaiaEngineのスクリプト

### JavaScript ES5

スクリプト言語には組み込み可能なECMAScriptエンジンであるDuktapeを採用しています。DukutapeはES5.0/ES5.1に準拠しています。

ES6以降のJavaScriptやTypeScriptもES5にトランスコンパイルすることで使用することができます。

### トランスコンパイル機能

raia_config.jsonのes6modeが有効になっているとき自動的にbabel.jsの機能を使って、es6形式のスクリプトをトランスコンパイルします。

TODO: typescriptのトランスコンパイル。

#### RaiaCore

#### `__Raia__`

__Raia__がスクリプトで使用するグローバルなオブジェクト変数です。RaiaEngineが初期状態で提供するすべての関数やプロパティは__Raia__オブジェクトに入っています。

#### `__Raia__.Core`

#### `__Raia__.Lib`

## ES6環境をセットアップする

ES6でゲーム開発したい場合の環境構築方法について説明します。

## TypeScript環境をセットアップする

TypeScriptでゲーム開発したい場合の環境構築方法について説明します。

## プラグイン開発ガイド

ランプレートのraia_sdkを参考にしてください。

プロジェクト構成、configファイル、ヘッダーファイル。

## C言語との連携

RaiaEngineはゲームで使用するデータをJavaScript側で保持するように設計しています。これによりプラグインを使用するときにスムーズにデータのやり取りができます。

### Windowsの場合

Windowsでの拡張プラグイン開発には現状ではVisualStudioが必要になります。コードは共通化できますが、いくつかのファイルが追加されます。

### Linux, macOSの場合

RaiaEngine公式プラグインはCmakeを用いていますが、Duktapeの機能を利用できる、共有ライブラリとして出力できる環境であれば問題ありません。

### コントリビューションガイド

RaiaEngine本体の開発に興味がありますか。

# Summary

* [はじめに](README.md)

### 初心者ガイド

* [インストールと実行](guide/setup.md)
* [チュートリアル](guide/tutorial.md)



### トピック

* [概要](overview.md)
* [スクリプト](script.md)
* [コンテキスト](context.md)

### コンテキスト

* [Raia.context](ctx/context.md)

### APIリファレンス

#### 組み込みJavaScriptのAPI
#### Raiaで提供されているAPI

* [Raia](api/raia.md)
  * [Core](api/raia_core.md)
  * [App](api/raia_app.md)


## 二重構造のRaiaEngineAPI

RaiaEngineはC言語とやり取りしやすい形でJavaScriptに渡し、それをJavaScriptのモジュール側で使いやすいようにカスタマイズするという方法を取っています。基本的にJavaScriptにチューニングされた機能をお使いいただき、元の関数などは気にしなくて問題ありません。

元の関数は__Raia__オブジェクトに格納されます。カスタマイズされた関数はそれを参照する形で実行します。

- Raia
  - Core
    - Context
      - init: コンテキストを返す
    - Lib
      - init:
      - open: ダイナミックライブラリを開く
      - close: ライブラリを閉じる
      - closeAll: すべてのライブラリを閉じる
      - funcGlobal: ライブラリの関数をグローバルオブジェクトに登録する
      - func: ライブラリの関数を返す
    - IO
      - loadStringFilename: テキストファイルを読み込む
  - App
    - Window
      - init: ウィンドウを生成する
      - setTitle: タイトルを設定する
      - shouldClose: クローズボタンが押されたか
      - pollEvents: イベントをプールする
    - Screen
      - redraw: スクリーンを再描画する
    - Event
      - key: キー入力のコールバックを登録する
      - error: エラーのコールバックを登録する
      - corsor: マウス移動のコールバックを登録する
      - mouse: マウスボタンのコールバックを登録する
      - char: 文字入力のコールバックを登録する
      - enter: マウスの入退出のコールバックを登録する
      - scroll: スクロールのコールバックを登録する
      - joystick: ジョイスティック接続・解除のコールバックを登録する
      - drop: ドラッグ＆ドロップのコールバックを登録する
      - update: 再描画のコールバックを登録する
      - updateEnable: 再描画のコールバックを有効にする
    - GLFW
    - GLES
  - 