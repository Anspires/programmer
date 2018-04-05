
#include<stdio.h>
#include<iostream>
#include "list.h"
#include<string>
#include<math.h>
#include "misc.h"
#include "fft.h"
#include "mytemplate.h"
#include"singleton.h"
#include "arraySearch.h"
#define CONVERT2STR(str) #str
typedef struct desc_struct
{
	unsigned long a,b;
}desc_table[256];
using namespace std;
class TextBlock
{
public:
	TextBlock(std::string str)
	{
		strncpy(text,str.c_str(),10);
	}
	const char &operator[](std::size_t position) const
	{return text[position];}
	//char &operator[](std::size_t position)
	//{return text[position];}
private:
	char text[10];
};
union endian
{
	int i;
	char x[2];
};
bool findNum(int *data,int length,int value)
{
	int i = 0;
	for(i = 0;i < length;i++)
	{
		
	}
	return false;
}
int arraydata[] = {1,2,5,10,MAX_VALUE};  
int main()
{
	ShowResult(arraydata,sizeof(arraydata)/sizeof(int)); 
	int Money=3;  
    int coin[]={4,5,7};  
    FindMin(Money,coin,3); 
	int set[3] = {7,5,4};
	printf("return = %d\n",arraySearch(20,3,set));
	int iii = 3;
	printf("%d\n",(++iii)+++iii+++iii);
	char pp[3] = "ab";
	printf("sizeof(p) = %d\n",strlen(pp));
	union
	{
		int i;
		char j;
	}ENDIAN;
	ENDIAN.i = 1;
	if(ENDIAN.j == 1)
	{
		printf("little endian\n");
	}
	else
	{
		printf("big endian\n");
	}
	union endian xx;
	xx.x[0] = 10;
	xx.x[1] = 1;
	printf("xx.i = 0x%x\n",xx.i);
	int c = 9;
	int bcc = 0;
	c = (c++%5);
	bcc = c;
	printf("c = %d\n",bcc);
	char kjh = 5;
	printf("kjh = %d\n",(++kjh)++);
	TextBlock tb("HELLO");
	const TextBlock ctb("WORLD");
	std::cout<<tb[0]<<std::endl;
	std::cout<<ctb[0]<<std::endl;
	//tb[0] = 'X';
	//ctb[0] = 'Y';
	//char *poi = &ctb[0];
	desc_table gdt;
	LOG_TRACE("MMM");
	LOG_TRACE("NNN");
	printf("gdt.addr = 0x%x\n",gdt);
	printf("gdt+4.addr = 0x%x\n",gdt + 4);
	printf("file = %s,line = %d\n",__FILE__,__LINE__);
	char clo = 'c';
	//value_finder<int> k(10);
	//k(std::map<int,int>(1,100));
	//int N = 64;
	//for(int i = 0;i < N;i++)
	//{
	//	printf("s[%d] = c[%d]\n",i,inverse(i,N));
	//}
	//printf("w = %d\n",bit_w);
	//std::map<int,double> k;
	//std::map<int,double>::value_type &t = k::value_type;
	static volatile int kijffsf = 0;
	COMPLEX_STRUCT pSrc[8] = {{1,0},{2,0},{3,0},{4,0},{1,0},{2,0},{3,0},{5,0}};
	COMPLEX_STRUCT pDst[8] = {{0,0}};

	fft(8,pSrc,0,pDst);

	cout<<++clo<<endl;
	cout<<clo + 1<<endl;
	typedef int (*pFunc)(void);
	pFunc pFc = NULL;
	stock stock1(10);
	printf("object address = 0x%08x\n",(&stock1));
	printf("object address = 0x%08x\n",(int *)(&stock1));
	printf("virtual table address = 0x%08x\n",(int *)(*(int *)(&stock1)));
	printf("first virtual table address = 0x%08x\n",(int *)(*(int *)(*(int *)(&stock1))));
	printf("m_value = %d\n",get_class_value(stock1));
	
	double a = exp(-2.0 * SUL_PI *100.0 * 0.0004) - 1;
	double b = exp(-2.0 * SUL_PI *100.0 * 0.0004);
	printf("sizeof(long long) = %d\n",sizeof(long long));
	printf("a = %f,b = %f\n",a,b);
	char mychar[10] = {'m','b','c','c','c','c','a','b','c','\0'};
	string tempstr("mbccccabc");
	printf("temp.c_str() = %s\n",tempstr.c_str());
	//printf("temp.size() = %d\n",string::npos);
	printf("temp.find() = %d\n",tempstr.find("c"));
	
	struct bitStruct data;
	printf("convert2str(get set) = %s\n",CONVERT2STR(get set));
	printf("sizeof(data) = %d\n",sizeof(data));
	
	NODE *head = NULL;
	NODE *temp = NULL;
	head = create_list(2);
	head = delete_node(head,0);
	/*head = reverse(head);
	head = reverse(head);*/
	temp = head;
	int i = 0;
	while(NULL != temp)
	{
		printf("%d->a = %d\n",i,temp->a);
		temp = temp->next;
		i++;
	}

	cin.get();
	//while(1);
	return 0;
}