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

## 动态类型

JavaScript 是一种“动态类型语言”，你不需要指定变量将包含什么数据类型。

