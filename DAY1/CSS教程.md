CSS教程
1.字体font-family
  几乎所有系统都能够支持的几种字体：Arial，Courier New，Georgia，Times New Roman，Trebuchet MS，Verdana。

2.字体大小和颜色font-size
单位：px，em
通过color来控制颜色

3.字体样式-粗体font-weight
normal：字体正常
bold：文字加粗

4.字体样式-斜体font-style
normal：正常
ilalic：斜体

5.字体装饰text-decoration
none：取消修饰
underline：文本下划线
overline：文本上划线
line-through：穿过文本的线，删除线

6.段落
缩进text-indent
行高line-heght
中文字间距，字母间距letter-spacing
对齐：text-alien

7.列表样式 list-style-type

disc 无序列表的默认值，实心圆。
circle 空心圆。
square 实心方块。
decimal 有序列表的默认值阿拉伯数字。
lower-alpha 小写英文字母。
upper-alpha 大写英文字母。

8.伪类元素
选择器中有以下几种伪类 
:link、 连接
:hover、悬停 
:active、 激活
:visited、访问过
示例：
<style>
  a:hover {
    color: red;
    text-decoration: none;
    /*鼠标经过，字体颜色变成红色，并且去掉下划线*/
  }
</style>
<body>
  <a href="https://www.lanqiao.cn/">实验楼</a>
</body>