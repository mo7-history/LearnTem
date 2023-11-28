package main

import (
	"fmt"
	"io/ioutil"
	"log"
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
	// 根据请求body创建一个json解析器实例
	// decoder := json.NewDecoder(request.Body)
	b, err := ioutil.ReadAll(request.Body)
	fmt.Println("接收到的参数", b, err)

	// 用于存放参数key=value数据
	// var params map[string]string

	// 解析参数 存入map
	// decoder.Decode(&params)

	// fmt.Printf("POST json: username=%s, password=%s\n", params["username"], params["password"])

	// fmt.Fprintf(writer, `{"code":0}`)
}

func main() {
	http.HandleFunc("/", handleIndex)

	port := ":9456"

	fmt.Println("Running at port " + port)

	http.HandleFunc("/testGet", handleGet)

	http.HandleFunc("/testPostJson", handlePostJson)

	err := http.ListenAndServe(port, nil)
	if err != nil {
		log.Fatal("ListenAndServe: ", err.Error())
	}
}
