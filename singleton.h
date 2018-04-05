#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include <string>
#include <stdlib.h> 
#include <stdio.h> 
#define LOG_TRACE(str) singleton::log_trace(__FILE__,__LINE__,str);
class singleton
{
public:
	static singleton *get_instance();
	static void log_trace(const char *file,long line_number,const std::string &s);
private:
	singleton();//
	//���������������͹��캯��
	~singleton();
	//static FILE *m_fp;
	//static int qq;
};

#endif