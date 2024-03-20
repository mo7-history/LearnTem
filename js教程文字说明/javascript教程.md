javascript教程

1.如何撰写javascript
第一种方法，body里面写script
第二种方法，script引入src

2.js结尾必须要带分号;

3.js的注解
//双斜杠
js的多行注解(/*sssssssss*/)

4.js的几种数据类型
字符串
数字
boll值,T/F

变数
var 变数名字
变数规则，
只能是英文大小写 数字 $ 和_ 的这四种组合组合。
开头不能是数字

5.如何使用字串，字串的用法

\斜杠转译，使用双引号

.length算字串长度
.toUpperCase()变大写
.toLowerCase()变小写
.charAt()回传字符串
.indexOf()回传字符串的位数
.substring(几,几)回传字串段儿
类似于python的用法

6.如何使用数字，使用数字用法
%取余数
document.write(Math.abs(number));绝对值
document.write(Math.max(number));回传最大数
document.write(Math.min(number));回传最小数
document.write(Math.round(number));回传小数位数
document.write(Math.pow(number));回传幂运算
document.write(Math.sqrt(number));回传开根号
document.write(Math.random(number));回传随机数

7.制作一个js计算机
获得一个输入prompt("请输入你的名字")

获得多个输入
var num1 = prompt("请输入数字1");
var num2 = prompt("请输入数字2");
document.write(num1 + num2);
（这里有一个问题是，这个是字串类型，堆叠，并不是数字运算）

如何把字串转换成数字呢？
第一个方法，parseInt()把字串转换成整数，回传
第二个方法，parseFloat()把字串转换成小数，回传
![Alt text](%7BF36D1BAA-AB9A-476d-B593-ED1D696398B6%7D.png)
8.数组array
存放【数字，"字串"，boolean值（T/F）】

9.函数 function
语法：
funtion 函数名(){
    巴拉巴拉巴拉...... ;
}
函数名();

return 巴拉巴拉巴拉 **回传的数字覆盖原先的变量
**碰到return就不继续执行下面的东西了
![Alt text](%7B76ABA7BD-14D8-47dc-8872-2C4BDBB16357%7D.png)

10.if判断 if...else...如果，否则
语法
if（判断条件）{
    执行结果
}
否则（else）{
    执行结果
}

if多重条件判断
if..
条件1..怎么怎么样

elif..（或是如果）
条件2..怎么怎么样

else..（否则）
条件3..怎么怎么样

&&两个and符号，代表了"且"的意思
双重条件

||两根竖线，代表了"或"的意思

!感叹号代表了，否定条件的意思，没有的意思！

11.键值对儿
key键 value值
键值对表示Object物件

12.while(条件判断){
    巴拉巴拉巴拉
}，
重复执行到false停止.

i++ 等效于 i=i+1

do{
    巴拉巴拉巴拉；
}while(条件判断)

do...while....表示的是先运行括号里面的程序，在判断条件，跳出程序

13.密码检验器
见教程

14.for循环
for i in range

15.制作一个回答程式

16.二维阵列&巢状回圈
二维阵列，就是阵列里面镶嵌阵列

巢状回圈，就是for循环里面又嵌套一个for循环

17.class模板
避免重复，提高效率
class就是物件的模板

18.获取html元素
document.write()是属于window全局下面的部件
在html里面写东西
document.getElementById("id")
console.log()把东西印出到f12的console里面
如果<script src="script.js"></script>这个放在了前面，没有办法获取后面的HTML元素了
因为自上而下执行的，先执行了js后执行html里面的内容，就找不到html里面的内容了

19.event listener事件监听
两种方法，第一种方法直接写在html档案里面，需要加on...onclick/onmouseover

第二种方法，在js里面写addEventListener

20.制作部落格，项目
