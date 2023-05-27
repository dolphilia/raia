# インストールとセットアップ

## ダウンロード

RaiaEngineは実行バイナリ形式をZIP圧縮したものを配布しています。[ダウンロードページ](https://raia-engine.github.io/download/)から最新版をダウンロードしてください。

## 起動の方法

ダウンロードしたZIPファイルを解凍して展開してください。

展開したディレクトリを開き`raia_core.exe`をダブルクリックして起動します。

## raia_config.json の設定

```json
{
  "debug_mode": false,
  "typescript_mode": false,
  "es2015_mode": false,
  "startup_script": "main.js",
  "preprocess": true,
  "preprocess_script": "preprocess.js",
  "modules_directory": "modules"
}
```

- `debug_mode`: ダミー項目です。デバッグモードのON/OFFを設定します。
- `typescript_mode`: ダミー項目です。起動時に`.ts`ファイルをTypeScriptでトランスコンパイルするかどうかを設定します。
- `es2015_mode`: 起動時に`.es6`ファイルをECMAScript2015でトランスコンパイルするかどうかを設定します。trueもしくはfalseを設定します。
- `startup_script`: 実行ファイルの起動時に読み込まれるメインとなるスクリプトファイル名を設定します。文字列で設定します。
- `preprocess`: メインのスクリプトを読み込む前に事前処理をするかを設定します。trueもしくはfalseを設定します。
- `preprocess_script`: 事前処理のスクリプトファイル名を設定します。文字列で設定します。
- `modules_directory`: モジュールを格納したディレクトリ名を設定します。文字列で設定します。