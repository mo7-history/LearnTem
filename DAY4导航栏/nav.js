$(function () {
  // 绑定 hover 事件
  $(".nav li").hover(
    function () {
      // stop 方法用于停止当前正在运行的动画
      $("span", this).stop().css("height", "2px");
      // 添加动画
      $("span", this).animate(
        {
          //使底部红线和菜单一样宽
          left: "0",
          width: "100%",
          right: "0",
        },
        200,
      );
    },
    function () {
      $("span", this).stop().animate(
        {
          //鼠标移出时 重置小红线位置及长度
          left: "50%",
          width: "0",
        },
        200,
      );
    },
  );
});