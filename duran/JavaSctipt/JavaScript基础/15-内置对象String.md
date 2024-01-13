# 内置对象String

## 基本数据类型不能绑定属性和方法

1. 基本数据类型：string是无法绑定属性和方法的

```js
 var str = "hahaha";
str.aaa = 12;
console.log(typeof str);  //打印结果为：string
console.log(str.aaa);   //undefined 
```

打印`str.aaa`的时候，结果为：undefined。也就是说，不能给 `string` 绑定属性和方法。

可以打印str.length、str.indexOf("m")等等。因为这两个方法的底层做了数据类型转换（**临时**将 `string` 字符串转换为 `String` 对象，然后再调用内置方法）。

2. 引用数据类型

引用数据类型string是可以绑定属性和方法的

```js
var strObj = new String("hahaha");
strObj.aaa = 123;
console.log(strObj);
console.log(typeof strObj);  //打印结果：Object
console.log(strObj.aaa);
```

内置对象Number也有一些自带的方法，比如：

- Number.MAX_VALUE;
- Number.MIN_VALUE;

## 字符串以字符数组的形式保存

在底层中，字符串是以字符数组的形式保存的

```js
var str = "hahaha";
console.log(str.length); // 获取字符串的长度
console.log(str[2]); // 获取字符串中的第2个字符 h
```

hahaha字符串在底层是以['h','a','h','a','h','a']形式保存的，所以可以获取字符串的长度，也可以获取指定索引index位置的单个字符。

## 内置方法

### ### charAt()

`charAt`：返回字符串指定位置的字符。不会修改原字符串。

语法：`字符 = str.charAt(index);`

字符串中第一个字符的下标是 0。如果参数 index 不在 [0, string.length) 之间，该方法将返回一个空字符串。**str.charAt(index)和str[index]的效果是一样的**


```js
var str = new String("abcdefg");
for (var i = 0; i < str.length; i++) {
    console.log(str.charAt(i));
}
```

### charCodeAt()

`charCodeAt`：返回字符串指定位置的字符的 Unicode 编码。不会修改原字符串。

语法：`字符 = str.charCodeAt(index);`

### indexOf()/lastIndexOf()

获取指定字符的索引

语法：`索引值 = str.indexOf(想要查询的字符);`
`indexOf()` 是从前向后索引字符串的位置。同理，`lastIndexOf()`是从后向前寻找。

可以检索一个字符串中是否含有指定内容。如果字符串中含有该内容，则会返回其**第一次出现**的索引；如果没有找到指定的内容，则返回 -1。
因此可以得出一个技巧：**如果获取的索引值为0，说明字符串是以查询的参数为开头的**。

该方法还可以指定第二个参数，用来指定开始查找的位置


```js
var str = "abcdea";
//给字符查索引(索引值为0,说明字符串以查询的参数为开头)
console.log(str.indexOf("c"));
console.log(str.lastIndexOf("c"));

var str = 'abcdeafg';
result = str.indexOf('a', 3); // 从第三个位置开始查找 'a'这个字符 【重要】
console.log(result); // 打印结果：5
```

### concat()

`concat()`：字符串的连接。

语法：`新字符串 = str1.concat(str2);`
数组中也有此方法，并且经常使用。该方法在字符串中基本不用

### slice()

`slice()`：从字符串中截取指定的内容。不会修改原字符串，而是将及截取到的内容返回。

语法：`字符串 = str.slice(开始索引, 结束索引);`

上面的参数，包左不包右：

- (2, 5) 截取时，包左不包右。
- (2) 表示**从指定的索引位置开始，截取到最后**。
- (-3) 表示从倒数第几个开始，截取到最后。
- (1, -1) 表示从第一个截取到倒数第一个。
- (5, 2) 表示前面的大，后面的小，返回值为空

### substring()

`substring()`：从字符串中截取指定的内容。和`slice()`类似。

语法：`字符串 = str.substring(开始索引, 结束索引);`

两个参数也是包左不包右，不同之处在于：

- `substring()`不能接受负值作为参数。如果传递了一个**负值**，则默认使用0。
- `substring()`还会自动调整参数的位置，如果第二个参数小于第一个，则自动交换。比如说， `substring(1, 0)`截取的是第一个字符。

### substr()

`substr()`：从字符串中截取指定的内容。不会修改原字符串，而是将及截取到的内容返回。

语法：`字符串 = str.substr(开始索引, 截取的长度);`

参数举例：

- (2,4)：从索引值为2的字符开始，截取4个字符。
- (1)：从指定位置开始，截取到最后。
- (-3)：从倒数第几个开始，剪到最后.
- 不包括前大后小的情况。

>ECMAscript 没有对 `substr()` 方法进行标准化，因此不建议使用它。

### 重要 split() 重要

`split()`：将一个字符串拆分成一个数组。

语法：`数组 = str.split();`

`split()`这个方法在实际开发中用得非常多。一般来说，从接口拿到的json数据中，经常会收到类似于`"q, i, a, n"`这样的字符串，前端需要将这个字符串拆分成`['q', 'i', 'a', 'n']`数组，这个时候`split()`方法就排上用场了。

```js
var str = "ha,ei,yi,mx"; // 用逗号隔开的字符串
var array = str.split(","); // 将字符串 str 拆分成数组，通过逗号来拆分
console.log(array); // 打印结果是数组：["ha", " ei", " yi", " mx"]

//split()方法：字符串变数组

var str = "世界那么大出去看看haah";
    console.log(str);
    console.log(str.split());   // 无参数，表示：把字符串作为一个元素添加到数组中。
    console.log(str.split(""));  //参数为空字符串，则表示：分隔字符串中每一个字符，分别添加到数组中
    console.log(str.split("|")); //参数为指定字符，表示：此字符将不会出现在数组的任意一个元素中
    console.log(str3.split("大")); //同理
```

### trim()

`trim()`：去除字符串前后的空白。

```js
var str = "   a   b   c   ";
console.log(str.trim());
```

### replace()

`replace()`：将字符串中的指定内容，替换为新的内容并返回。不会修改原字符串。

语法：`新的字符串 = str.replace(被替换的内容，新的内容);`

```js
    //replace()方法：替换
var str = "Today is sunday,today is sunday !!!"
console.log(str);
console.log(str.replace("today","tomorrow"));  //只能替换第一个today
console.log(str.replace(/today/gi,"tomorrow")); //这里用到了正则，才能替换所有的today
```

### 大小写转换

```js
var str = "abcdEFG";
//转换成小写
console.log(str.toLowerCase());
//转换成大写
console.log(str.toUpperCase());
```

### 