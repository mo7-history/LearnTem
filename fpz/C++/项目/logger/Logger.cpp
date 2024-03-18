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
		return ;  //�˳�
	}


	if (m_fout.fail()) {
		// logic_error�Ǽ̳���std::exception�����ڱ�ʾ��������ʱ�������߼�������Ҫʹ�������ռ�std
		throw logic_error("open file failed:" + m_filename);
	}

	time_t ticks = time(NULL); //��ȡ��ǰʱ��� ��1970.1.1��ʼ

	struct tm* ptm = localtime(&ticks); // ת��Ϊ����ʱ�� ����һ��ָ��ptm 
	//����Ϊ�̰߳�ȫ����
	//struct tm ptm;
	//localtime_s(&ptm, &ticks);

	char timestamp[32];  //�����ַ�������0���
	memset(timestamp, 0, sizeof(timestamp));

	//��ptm��ʽ��Ϊ�ַ���  string format time
	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", ptm);
	//cout << timestamp << endl;


	const char* fmt = "%s %s %s:%d "; // ��ʽ�ַ���fmt  ʱ�� ���� �ļ������к� ������˿ո�

	//snprinf�е�sn���� ��ȫ�汾��safe������ȷ����β�Կ��ַ���null����β�� ��ʽ�����
	//���ص��Ǽ����������ַ��� ����д���κεط�
	int size = snprintf(NULL, 0, fmt, timestamp, s_level[level], file, line);
	if (size > 0)
	{
		char* buffer = new char[size + 1];
		// ����ʽ����Ϣд�뻺����
		snprintf(buffer, size + 1, fmt, timestamp, s_level[level], file, line);
		 buffer[size] = 0;  //snprintf�Ѿ���β��Ϊ0��
		//cout << buffer << endl;
		m_fout << buffer; //д���ļ�
		m_len += size;
		delete []buffer;
	}

	//��Ȼ����ͨ��m_fout << format << endl��ʵ���������
    //��ʹ��va_list �����ͱ�Ҫ�����Խ��ܲ�ȷ�����������͵Ĳ���
	va_list arg_ptr;  //����׷�� �����б� �� ʣ����� ��ָ������
	va_start(arg_ptr, format);
	size = vsnprintf(NULL, 0, format, arg_ptr);
	va_end(arg_ptr);

	if (size > 0) {
		char* content = new char[size + 1];
		va_start(arg_ptr, format);
		vsnprintf(content, size + 1, format, arg_ptr);
		va_end(arg_ptr);
		m_fout << content << endl;  // д�벢����
		m_len += size;
		delete[]content;
	}

	m_fout.flush(); //ǿ�����̽�������д�뵽����
	
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
	m_fout.open(m_filename.c_str(), ios::app); //append��׷�ӣ����ļ�����ʱ��
	                                   //�ļ���д�������� << �����������Ḳ��ԭ���ļ����ݣ����ǽ���������ӵ��ļ���ĩβ
	if (m_fout.fail())
	{   
		// logic_error�Ǽ̳���std::exception�����ڱ�ʾ��������ʱ�������߼�������Ҫʹ�������ռ�std
		throw logic_error("open file failed:" + m_filename);
	}

	m_fout.seekp(0, ios::end); //���ڸı��ļ�����д��λ�ã�����һΪƫ���� ������Ϊ�ƶ���ĩβ
	m_len = m_fout.tellp(); //����д��λ�ã����ļ��ĳ��ȣ��ֽ�����

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

	close();  //�ر��ļ�

	time_t ticks = time(NULL);
	struct tm* ptm = localtime(&ticks);
	//struct tm ptm;
	//localtime_s(&ptm, &ticks);
	char timestamp[32];
	memset(timestamp, 0, sizeof(timestamp));
	strftime(timestamp, sizeof(timestamp), ".%Y-%m-%d_%H:%M:%S.txt", ptm);

	string filename = m_filename + timestamp;

	if (rename(m_filename.c_str(), filename.c_str()) != 0) {
		//ע�� �ж���������Ѿ�ʵ�����������������������ؽ������
		//c_str()ָ�����ַ�����ĳ���ָ�룬���ַ�������ת��ΪC����ַ������Ա㴫�ݸ� rename() ����
		//strerror��������errno ת��Ϊ�ַ���
		throw logic_error("rename log file failed:" + string(strerror(errno)));
	}

	open(m_filename);  //��ԭ�ȵ�log���������µ���־д���µ�log.txt�� 

}


pzy::utils::Logger::Logger() :m_max(0),m_len(0),m_level(DEBUG){

}


pzy::utils::Logger::~Logger() {
	close();

}
