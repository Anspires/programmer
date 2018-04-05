#ifndef MISC_H_
#define MISC_H_
class stock
{
public:
	stock();
	stock(int value);
	virtual ~stock();
	int get_value();
	friend int get_class_value(const stock&);

	virtual int g_a();
	//virtual int g_b();
protected:
	//virtual int gg_a();
private:
	
	int m_value;
};

class DEstock : public stock
{
public:
	DEstock();
	DEstock(int m,int n);
	~DEstock();
	int g_a();
	//int g_b();
protected:
	int gg_a();
private:
	int m_value;
};
#endif;
