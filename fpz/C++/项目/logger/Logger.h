#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <string.h>
#include <fstream>
using namespace std;

namespace pzy {

	namespace utils {

//  \用于行连接，告知下一行视为当前行同一部分， ## 连接操作符，用于消除列表中多余逗号
//__VA_ARGS__ 是C++预处理器中的可变参数宏标识符，它表示传递给宏的所有剩余参数（以逗号分隔）
#define debug(format,...) \
       Logger::instance()->log(Logger::DEBUG, __FILE__, __LINE__, format , ##__VA_ARGS__);
#define info(format,...) \
       Logger::instance()->log(Logger::INFO, __FILE__, __LINE__, format , ##__VA_ARGS__);
#define warn(format,...) \
       Logger::instance()->log(Logger::WARN, __FILE__, __LINE__, format , ##__VA_ARGS__);
#define error(format,...) \
       Logger::instance()->log(Logger::ERROR, __FILE__, __LINE__, format , ##__VA_ARGS__);
#define fatal(format,...) \
       Logger::instance()->log(Logger::FATAL, __FILE__, __LINE__, format , ##__VA_ARGS__);

		class Logger {
		public:

			enum Level {
				//在 C 和 C++ 中，如果不给枚举成员指定具体的值，那么它的值会默认从上一个成员的基础上自动递增
				DEBUG = 0,
				INFO,
				WARN,
				ERROR,
				FATAL,
				LEVEL_COUNT
			};
			
			//记录日志函数   参数为： 等级，文件位置，行号， 日志内容用不定参数来传 
			//const char format*: 这是一个格式化字符串，类似于C语言的printf函数。
			// 它定义了日志消息的实际内容及其格式，可以包含占位符（如 %s, %d, %f 等），后面可以跟变长参数列表（通过...表示）。
			//... (变长参数列表) : 这些参数跟随在format之后，其数量和类型取决于format字符串中的占位符。
			// 它们会被插入到format字符串中的适当位置，以生成最终的日志消息内容
			void log(Level level, const char* file, int line, const char* format, ...);

			//返回单例 instance() 方法应该是静态成员函数，用于实现单例模式
			static Logger* instance();

			void open(const string& filename); //打开文件
			void close(); //关闭文件
			void level(Level level);   //日志级别过滤

			void max(int max);   
		


		private:
			Logger();
			~Logger();
			void rotate(); // 实现文件翻滚



		private:
			string m_filename;
			ofstream m_fout;  //用于文件输出操作。m_fout作为成员变量，说明该类具有向文件写入日志的能力
			static const char* s_level[LEVEL_COUNT];
			static Logger* m_instance;   //全局唯一实例保存到该指针里

			Level m_level; //当前设置的过滤级别

			int m_max;   //文件最大大小
			int m_len;   //文件长度
		};

	
	
	}


}
