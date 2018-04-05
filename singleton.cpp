#include "singleton.h"
//singleton::m_fp = fopen("mylog.txt","a+");
//int singleton::qq = 0;
singleton::singleton()
{
	//m_fp = fopen("mylog.txt","a+");
}
singleton::~singleton()
{
	//fclose(m_fp);
	//m_fp = NULL;
}
singleton *singleton::get_instance()
{
	static singleton obj;
	return &obj;
}
void singleton::log_trace(const char *file,long line_number,const std::string &s)
{
	static FILE *m_fp = NULL;
	if(NULL == m_fp)
	{
		m_fp = fopen("mylog.txt","a+");
	}
	if(NULL != m_fp)
	{
		fprintf(m_fp,"file:%s:line_number:%d:%s\n",file,line_number,s.c_str());
		fclose(m_fp);
		m_fp = NULL;
	}
}

singleton *log_inst = singleton::get_instance();