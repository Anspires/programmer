#include "misc.h"

stock::stock()
{
	m_value = 0;
}
stock::stock(int value)
{
	m_value = value;
}
stock::~stock()
{

}

int stock::get_value()
{
	return m_value;
}
int get_class_value(const stock &t)
{
	return t.m_value;
}

int stock::g_a()
{
	return m_value + 1;
}