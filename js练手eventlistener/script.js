//event listener

/*第一种方案，添加到HTML里面这一行代码，onclick="handle_click(this)"
function handle_click(element){
    alert("叫你按就按啊？");
    element.innerText = "按屁啊！";
    element.style.color ="red";
}
*/

//第二种方法不需要写onclick/onmouseover这些
var btn = document.getElementById("btn");
btn.addEventListener("click", function(){
        //alert("叫你按就按啊？");
        this.innerText = "按屁啊！";
        this.style.color ="red";
})

var img = document.getElementById("img");
img.addEventListener("mouseover",function(){
    this.src = "hotpot2.jpg"
})

img.addEventListener("mouseout",function(){
    this.src = "hotpot1.jpg"
})