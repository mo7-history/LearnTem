# JavaScript笔记

## 调用

- `async` 和 `defer` 都指示浏览器在一个单独的线程中下载脚本，而页面的其他部分（DOM 等）正在下载，因此在获取过程中页面加载不会被阻塞。
- `async` 属性的脚本将在下载完成后立即执行。这将阻塞页面，并不保证任何特定的执行顺序。
- 带有 `defer` 属性的脚本将按照它们的顺序加载，并且只有在所有脚本加载完毕后才会执行。
- 如果脚本无需等待页面解析，且无依赖独立运行，那么应使用 async。
- 如果脚本需要等待页面解析，且依赖于其他脚本，调用这些脚本时应使用 `defer`，将关联的脚本按所需顺序置于 HTML 的相应 `<script>` 元素中。

## 查找并解决错误

代码错误主要分为两种：

- 语法错误，代码中存在拼写错误，将导致程序完全或部分不能运行，只要熟悉语言并了解出错信息的含义，就能够顺利修复它们。`TypeError:`
- 逻辑错误，代码语法虽然正确，但是执行结果喝预期相悖，便存在着错误。

```
SyntaxError: missing ; before statement
（语法错误：语句缺少分号）
SyntaxError: missing :)after argument list
（语法错误：参数表末尾缺少括号）
SyntaxError: missing : after property id
（语法错误：属性 ID 后缺少冒号）
SystaxError: missing } after function body
（语法错误：函数体末尾缺少花括号）
SyntaxError: expected expression, got 'string'
（语法错误：得到一个 'string' 而非表达式）
SyntaxError: unterminated string literal
（语法错误：字符串字面量未正常结束）
```

## 变量

变量就是一个用于存放数值的容器。其独特之处在于他存放的数值是可以改变的。

```Javascript
<button>请点击</button>
const bt=document.querySelector("button");
button.onclick = function(){
    let name = prompt("what is your name?");
    alert("hello"+name+",nice to meet you!");
}
```

变量的另一个特性就是他们能够存储任何的东西，不只是字符串和数字，还能存储更复杂的数据，甚至是函数。

### 声明变量

声明一个变量的语法是在`var`或`let`关键字之后加上这个变量的名字。

```Javascript
let myName
myName;//调用会得到一个undefined的返回值，是因为这个变量没有赋值。
```

### 初始化变量

定义变量以后使用“=”，后面跟上数值；
`myName="duran";`,这次调用就会返回duran

### var和let的区别

`var`是JavaScript最初创建的时候的关键字，有时会在工作方式上因它的设计会令人困惑。`let`是现代版本中的一个新的关键字。

1. 在初始化一个变量之后用`var`声明，它仍然可以工作。

```javascript
myName="duran";
var myName;
```

这是由于变量的提升，[变量提升](变量提升.md)。变量提升不适用于`let`。
2. 在使用`var`时，可以根据需要生命相同名称的变量，但是`let`不能。

```javascript
var myName="kk";
var myName="duran";
let myName="kk";
let myName="duran";//此时会引发错误
```

### 变量的命名规则

一般应坚持使用拉丁字符（0-9,a-z,A-）和下划线字符。

- 变量名不要以下划线开头——以下划线开头的被某些 JavaScript 设计为特殊的含义，因此可能让人迷惑。
- 变量名不要以数字开头，会引发一个错误。
- 让变量名直观，它们描述了所包含的数据。不要只使用单一的字母/数字，或者长句。
- 变量名大小写敏感——因此`myname`与`myName`是 2 个不同的变量。
- 不能以JavaScript的关键字来命名变量名。
- 采用**小写驼峰命名法**，用来将多个单词组在一起，小写整个命名的第一个字母然后大写剩下单词的首字符。

### 变量类型

Number

可以在变量中存储数字。可以是整数也可以是浮点数（带小数点的）。
在给一个变量数字赋值时，不需要用引号括起来。

String

字符串时文本的一部分。当你在给一个变量赋值为字符串时，需要用单引号或者双引号把值给包起来，否则 JavaScript 将会把这个字符串值理解成别的变量名。

Boolean

布尔值，值有两种：true或false。用于测试条件是否成功。

Array

数组是一个单个对象，包含很多值，用方括号[]括起来，逗号分隔。

Object

对象，用来存储信息。

## 动态类型

JavaScript 是一种“动态类型语言”，你不需要指定变量将包含什么数据类型。
