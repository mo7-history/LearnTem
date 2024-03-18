#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <string.h>
#include <fstream>
using namespace std;

namespace pzy {

	namespace utils {

//  \���������ӣ���֪��һ����Ϊ��ǰ��ͬһ���֣� ## ���Ӳ����������������б��ж��ය��
//__VA_ARGS__ ��C++Ԥ�������еĿɱ�������ʶ��������ʾ���ݸ��������ʣ��������Զ��ŷָ���
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
				//�� C �� C++ �У��������ö�ٳ�Աָ�������ֵ����ô����ֵ��Ĭ�ϴ���һ����Ա�Ļ������Զ�����
				DEBUG = 0,
				INFO,
				WARN,
				ERROR,
				FATAL,
				LEVEL_COUNT
			};
			
			//��¼��־����   ����Ϊ�� �ȼ����ļ�λ�ã��кţ� ��־�����ò����������� 
			//const char format*: ����һ����ʽ���ַ�����������C���Ե�printf������
			// ����������־��Ϣ��ʵ�����ݼ����ʽ�����԰���ռλ������ %s, %d, %f �ȣ���������Ը��䳤�����б�ͨ��...��ʾ����
			//... (�䳤�����б�) : ��Щ����������format֮��������������ȡ����format�ַ����е�ռλ����
			// ���ǻᱻ���뵽format�ַ����е��ʵ�λ�ã����������յ���־��Ϣ����
			void log(Level level, const char* file, int line, const char* format, ...);

			//���ص��� instance() ����Ӧ���Ǿ�̬��Ա����������ʵ�ֵ���ģʽ
			static Logger* instance();

			void open(const string& filename); //���ļ�
			void close(); //�ر��ļ�
			void level(Level level);   //��־�������

			void max(int max);   
		


		private:
			Logger();
			~Logger();
			void rotate(); // ʵ���ļ�����



		private:
			string m_filename;
			ofstream m_fout;  //�����ļ����������m_fout��Ϊ��Ա������˵������������ļ�д����־������
			static const char* s_level[LEVEL_COUNT];
			static Logger* m_instance;   //ȫ��Ψһʵ�����浽��ָ����

			Level m_level; //��ǰ���õĹ��˼���

			int m_max;   //�ļ�����С
			int m_len;   //�ļ�����
		};

	
	
	}


}
