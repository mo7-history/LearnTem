

##  1.安装
### 遇到的问题

在linux系统中配置gopath后，需要在vscode中的设置里面配置
```go
"go.gopath": "/go"   //我的gopath路径  
否则会无法安装go相关工具

修改代理源为：
go env -w GOPROXY=https://goproxy.cn/
以及修改模块:（这样如果没有mod文件也可以执行，不会报错）
go env -w GO111MODULE='auto'

整合vscode使用codeium无法使用
即WSL中vs code的插件代理错误修复
报错：WSL： Failed to establish a socket connection to proxies: ["PROXY 127.0.0.1:7890"]
解决办法：在vscode中用户的setting.json中加入  
"http.proxySupport": "off",


//第一个go程序  使用Ctrl+F5运行
package main

import (
	"fmt"
)

func main() {

	fmt.Println("hello world！")
}


```
