# 入力を検知する



## キー入力を検知する

::: code-group

``` js [ES5]
var Raia = require('raia');
var core = new Raia.Core();
var window = new Raia.Window("title", 800, 600);

window.onKey(function (window, key, scancode, action, mods) {
    core.print("key:" + key + " action:" + action);
});

window.onUpdate(function (){});
```

``` js [ES6]
var {Window, Core} = require('raia');
var core = new Core();
var window = new Window("title", 800, 600);

window.onKey((window, key, scancode, action, mods) => {
    core.print("key:" + key + " action:" + action);
});

window.onUpdate(()=>{
});
```

:::

### onKey()

キー入力を受け取るコールバック関数です。keyは押したキーが数値で格納され、actionは押されときは1、離されたときは0が格納されます。

```js
onKey(function(window, key, scancode, action, mods){})
```

::: warning
コールバック関数で受け取る引数が若干わかりにくいので将来的に修正される可能性があります。
:::