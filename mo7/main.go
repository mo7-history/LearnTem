package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"text/template"
)

// 返回静态页面
func handleIndex(writer http.ResponseWriter, request *http.Request) {
	t, _ := template.ParseFiles("./demo.html")
	t.Execute(writer, nil)
}

// 处理GET请求
func handleGet(writer http.ResponseWriter, request *http.Request) {
	query := request.URL.Query()

	// 第一种方式
	// id := query["id"][0]

	// 第二种方式
	id := query.Get("id")

	fmt.Printf("GET: id=%s\n", id)

	fmt.Fprintf(writer, `{"code":0}`+id+"}")
	fmt.Fprintf(writer, "<div>go-toolkit</div>")
}

// 处理application/json类型的POST请求
func handlePostJson(writer http.ResponseWriter, request *http.Request) {
	writer.Header().Set("Access-Control-Allow-Origin", "*")             // 允许访问所有域
	writer.Header().Add("Access-Control-Allow-Headers", "Content-Type") // header的类型
	writer.Header().Set("content-type", "application/json")             // 返回数据格式是json

	str, _ := ioutil.ReadAll(request.Body) // 把	body 内容读入字符串 s
	fmt.Println(string(str))               // 在返回页面中显示内容。

	fmt.Fprintf(writer, string(str))
}

func main() {
	http.HandleFunc("/testGet", handleGet)

	http.HandleFunc("/testPostJson", handlePostJson)

	port := ":9456"
	fmt.Println("Running at port " + port)
	err := http.ListenAndServe(port, nil)
	if err != nil {
		fmt.Println("ListenAndServe", err.Error())
	}
}
