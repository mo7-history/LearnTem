//密码检验程式

var password =123456;
var input;
var entry_count = 0;
var entry_limit = 3;
var out_of_limit = false;

while(password!=input && !out_of_limit){
    entry_count++;
    if(entry_count<=entry_limit){
    input=prompt("请输入密码");
    }
    else{
        out_of_limit=true;
    }
}
if(out_of_limit){
    alert("超出输入次数");
}
else{
    alert("登入成功");
}