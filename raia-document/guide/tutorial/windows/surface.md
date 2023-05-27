# サーフェスに描画する

画像バッファであるサーフェスを使って描画します。

## サーフェスに描画してウィンドウに転写します

::: code-group

```js [ES5]
var Raia = require('raia');
var window = new Raia.Window("title", 800, 600);
var surface = new Raia.Surface(800, 600);
surface.loadImage("fore.png");
window.blendSurface(surface);
window.onUpdate(function () {
    window.redraw();
});
```

```js [ES6]
var {Window, Surface} = require('raia');
var window = new Window("title", 800, 600);
var surface = new Surface(800, 600);
surface.loadImage("fore.png");
window.blendSurface(surface);
window.onUpdate(()=>{
    window.redraw();
});
```

:::

### blendSurface()

サーフェスの画素情報をウィンドウに転写します。第一引数でSurfaceのインスタンスを指定します。

```js
blendSurface(surface)
```

::: tip サーフェスを使用する理由

Windowオブジェクトの`loadImage()`関数でも画像を読み込んで表示することは可能ですが、画像にフィルターをかけたり移動させたりするには何度もファイルを読み込むことになるので非効率です。

サーフェスに一旦読み込んで`blendSurface()`でWindowオブジェクトに合成することで、負荷を軽くして処理を効率化することができます。

:::

### スクリーンショット

![](draw_image.png)


