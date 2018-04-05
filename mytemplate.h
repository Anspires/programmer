#ifndef MY_TEMPLATE_H_
#define MY_TEMPLATE_H_
#include <map>
#include <utility>
using namespace std;
template <typename type_value1>
class value_finder
{
public:
	value_finder(type_value1 type):m_type(type)
	{
		cout<<"type = "<<type<<endl;
	}
	bool operator()(const typename std::map<int,type_value1>::value_type &p)
	{
		cout<<"second = "<<p.second<<endl;
		return p.second == m_type;
	}
private:
	const type_value1 m_type;
};

#endif