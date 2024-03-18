#include "Logger.h"
#include <iostream>
#include <stdarg.h>
using namespace pzy::utils;

const char* Logger::s_level[LEVEL_COUNT] = {
 "DEBUG","INFO","WARN", "ERROR","FATAL"

};

Logger* Logger::m_instance = nullptr;

void pzy::utils::Logger::log(Level level, const char* file, int line, const char* format, ...) {
	if (m_level > level)
	{
		return ;  //退出
	}


	if (m_fout.fail()) {
		// logic_error是继承自std::exception，用于表示程序运行时发生的逻辑错误。需要使用命名空间std
		throw logic_error("open file failed:" + m_filename);
	}

	time_t ticks = time(NULL); //获取当前时间戳 从1970.1.1开始

	struct tm* ptm = localtime(&ticks); // 转换为本地时间 返回一个指针ptm 
	//下者为线程安全方法
	//struct tm ptm;
	//localtime_s(&ptm, &ticks);

	char timestamp[32];  //定义字符数组用0填充
	memset(timestamp, 0, sizeof(timestamp));

	//将ptm格式化为字符串  string format time
	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", ptm);
	//cout << timestamp << endl;


	const char* fmt = "%s %s %s:%d "; // 格式字符串fmt  时间 级别 文件名：行号 并添加了空格

	//snprinf中的sn代表 安全版本（safe）的且确保结尾以空字符（null）结尾的 格式化输出
	//返回的是计算所需总字符数 ，不写入任何地方
	int size = snprintf(NULL, 0, fmt, timestamp, s_level[level], file, line);
	if (size > 0)
	{
		char* buffer = new char[size + 1];
		// 将格式化消息写入缓冲区
		snprintf(buffer, size + 1, fmt, timestamp, s_level[level], file, line);
		 buffer[size] = 0;  //snprintf已经结尾置为0了
		//cout << buffer << endl;
		m_fout << buffer; //写入文件
		m_len += size;
		delete []buffer;
	}

	//虽然可以通过m_fout << format << endl来实现内容输出
    //但使用va_list 更灵活和必要，可以接受不确定数量和类型的参数
	va_list arg_ptr;  //用来追踪 参数列表 中 剩余参数 的指针类型
	va_start(arg_ptr, format);
	size = vsnprintf(NULL, 0, format, arg_ptr);
	va_end(arg_ptr);

	if (size > 0) {
		char* content = new char[size + 1];
		va_start(arg_ptr, format);
		vsnprintf(content, size + 1, format, arg_ptr);
		va_end(arg_ptr);
		m_fout << content << endl;  // 写入并换行
		m_len += size;
		delete[]content;
	}

	m_fout.flush(); //强制立刻将缓冲区写入到磁盘
	
	if (m_len >= m_max && m_max >0)
	{
		rotate();
	}
	
   

}

pzy::utils::Logger* Logger::instance() {
	if (m_instance == nullptr)
	{
		m_instance = new Logger();
	}

	return m_instance;
}

void pzy::utils:: Logger::open(const string& filename) {
	m_filename = filename;
	m_fout.open(m_filename.c_str(), ios::app); //append（追加）当文件被打开时，
	                                   //文件的写操作（如 << 操作符）不会覆盖原有文件内容，而是将新内容添加到文件的末尾
	if (m_fout.fail())
	{   
		// logic_error是继承自std::exception，用于表示程序运行时发生的逻辑错误。需要使用命名空间std
		throw logic_error("open file failed:" + m_filename);
	}

	m_fout.seekp(0, ios::end); //用于改变文件流的写入位置，参数一为偏移量 参数二为移动到末尾
	m_len = m_fout.tellp(); //返回写入位置，即文件的长度（字节数）

}

void pzy::utils::Logger::close() {
	m_fout.close();
}

void pzy::utils::Logger::level(Level level) {
	m_level = level;
}

void pzy::utils::Logger::max(int max) {
	m_max = max; 
}

void pzy::utils::Logger::rotate() {

	close();  //关闭文件

	time_t ticks = time(NULL);
	struct tm* ptm = localtime(&ticks);
	//struct tm ptm;
	//localtime_s(&ptm, &ticks);
	char timestamp[32];
	memset(timestamp, 0, sizeof(timestamp));
	strftime(timestamp, sizeof(timestamp), ".%Y-%m-%d_%H:%M:%S.txt", ptm);

	string filename = m_filename + timestamp;

	if (rename(m_filename.c_str(), filename.c_str()) != 0) {
		//注意 判断条件里就已经实现了重命名，而不仅仅返回结果而已
		//c_str()指返回字符数组的常量指针，将字符串对象转换为C风格字符串，以便传递给 rename() 函数
		//strerror将错误码errno 转换为字符串
		throw logic_error("rename log file failed:" + string(strerror(errno)));
	}

	open(m_filename);  //把原先的log重命名后，新的日志写入新的log.txt中 

}


pzy::utils::Logger::Logger() :m_max(0),m_len(0),m_level(DEBUG){

}


pzy::utils::Logger::~Logger() {
	close();

}
