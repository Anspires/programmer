#include <vector>
#include <map>
#include <iostream>
#include "arraySearch.h"
using namespace std;
//20块钱找零，零钱由1、2、5、10四种币值  
  

int nextdata[MAX_VALUE] = {0}; 
int arraySearch(int sum,int num,int set[])
{
	//vector<int> v;
	//map<int,vector<int>> map_set;
	//int tmp = 0;
	int count = 0;
	int *nset = new int[num];
	for(int mm = 0;mm < num;mm++)
	{
		nset[mm] = sum / set[mm];
	}
	for(int i = 0;i <= 2;i++)
	{
		for(int j = 0;j <= 4;j++)
		{
			for(int k = 0;k <= 5;k++)
			{
				if((i * 7 + j * 5 + k * 4) == 20)
				{
					printf("i = %d,j = %d,k = %d\n",i,j,k);
					count++;
				}
			}
		}
	}
	return count;
}
void dfs(GNODE adl[],int v)
{
	GNODE *p;
	adl[v].vex = 1;
	p = adl[v].next;
	while(NULL != p)
	{
		if(adl[p->vex].vex == 0)
		{
			dfs(adl,p->vex);
			p = p->next;
		}
	}
}

void FindMin(int money,int *coin, int n)  
{  
    int *coinNum=new int[money+1]();//存储1...money找零最少需要的硬币的个数  
    int *coinValue=new int[money+1]();//最后加入的硬币，方便后面输出是哪几个硬币  
    coinNum[0]=0;  
  
    for(int i=1;i<=money;i++)  
    {  
        int minNum=i;//i面值钱，需要最少硬币个数  
        int usedMoney=0;//这次找零，在原来的基础上需要的硬币  
        for(int j=0;j<n;j++)  
        {  
            if(i>=coin[j])//找零的钱大于这个硬币的面值  
            {  
                //if(coinNum[i-coin[j]]+1<=minNum)//所需硬币个数减少了  
                /* 
                上面的判断语句有问题，在更新时，需要判断i-coin[j]是否能找的开，如果找不开，就不需要更新。 
                多谢zywscq 指正 
                */  
                if(coinNum[i-coin[j]]+1<=minNum&&(i==coin[j]||coinValue[i-coin[j]]!=0))//所需硬币个数减少了  
                {  
                    minNum=coinNum[i-coin[j]]+1;//更新  
                    usedMoney=coin[j];//更新  
                }  
            }  
        }  
        coinNum[i]=minNum;  
        coinValue[i]=usedMoney;  
    }  
  
    //输出结果  
    if(coinValue[money]==0)  
        cout<<"找不开零钱"<<endl;  
    else  
    {  
		for(int i = 0;i < money + 1;i++)
		{
			cout<<coinValue[i]<<" ";
		}
		cout<<endl;
        cout<<"需要最少硬币个数为："<<coinNum[money]<<endl;  
        cout<<"硬币分别为:";  
        while(money>0)  
        {  
            cout<<coinValue[money]<<",";  
            money-=coinValue[money];  
        }  
    }  
    delete []coinNum;  
    delete []coinValue;  
}  

 
  
void SegNum(int nSum, int* pData, int nDepth)  
{  
    if(nSum < 0)  
        return;  
  
    if(nSum == 0)  
    {  
        for(int j = 0; j < nDepth; j++)  
            cout << pData[j] << " ";  
        cout << endl;  
  
        return;  
    }  
  
    int i = (nDepth == 0 ? nextdata[0] : pData[nDepth-1]);  
    for(; i <= nSum;)  
    {  
        pData[nDepth++] = i;  
        SegNum(nSum-i,pData,nDepth);  
        nDepth--;  
  
        i = nextdata[i];  
    }  
}  
  
void ShowResult(int array[],int nLen)  
{  
    nextdata[0] = array[0];  
    int i = 0;  
    for(; i < nLen-1; i++)  
        nextdata[array[i]] = array[i+1];  
    nextdata[array[i]] = array[i]+1;  
  
    int* pData = new int [MAX_VALUE];  
    SegNum(MAX_VALUE,pData,0);  
    delete [] pData;  
} 