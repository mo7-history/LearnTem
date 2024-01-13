# 内置对象Math

## 常见方法

- Math.abs()**返回绝对值**
- Math.floor()**向下取整**（向小取）
- Math.ceil()**向上取整**（向大取）
- Math.round()四舍五入取整（正数四舍五入，负数五舍六入）
- Math.random()生成0-1之间的随机数 不包含0和1
- Math.max(x, y, z)返回多个数中的最大值
- Math.min(x, y, z)返回多个数中的最小值
- Math.pow(x,y)返回 x 的 y 次幂Math.sqrt()对一个数进行开方运算

Math不是一个构造函数，不需要创建对象，属于一个工具类，里面等装了数学运算相关的属性和方法

## Math.random()

生成 0-x 之间的随机数：
    `Math.round(Math.random()*(y-x)+x)`
生成 x-y 之间的随机数：
    `Math.round(Math.random()*(y-x)+x)`

## url 编码和解码

URI (Uniform ResourceIdentifiers,通用资源标识符)进行编码，以便发送给浏览器。有效的URI中不能包含某些字符，例如空格。而这URI编码方法就可以对URI进行编码，它们用特殊的UTF-8编码替换所有无效的字符，从而让浏览器能够接受和理解。

```js
encodeURIComponent();   //把字符串作为 URI 组件进行编码
decodeURIComponent();   //把字符串作为 URI 组件进行解码
var url = "http://www.cnblogs.com/smyhvae/";
var str = encodeURIComponent(url);
console.log(str);                           //打印url的编码
console.log(decodeURIComponent(str));       //对url进行编码后，再解码
```
