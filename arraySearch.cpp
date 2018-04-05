#include <vector>
#include <map>
#include <iostream>
#include "arraySearch.h"
using namespace std;
//20��Ǯ���㣬��Ǯ��1��2��5��10���ֱ�ֵ  
  

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
    int *coinNum=new int[money+1]();//�洢1...money����������Ҫ��Ӳ�ҵĸ���  
    int *coinValue=new int[money+1]();//�������Ӳ�ң��������������ļ���Ӳ��  
    coinNum[0]=0;  
  
    for(int i=1;i<=money;i++)  
    {  
        int minNum=i;//i��ֵǮ����Ҫ����Ӳ�Ҹ���  
        int usedMoney=0;//������㣬��ԭ���Ļ�������Ҫ��Ӳ��  
        for(int j=0;j<n;j++)  
        {  
            if(i>=coin[j])//�����Ǯ�������Ӳ�ҵ���ֵ  
            {  
                //if(coinNum[i-coin[j]]+1<=minNum)//����Ӳ�Ҹ���������  
                /* 
                ������ж���������⣬�ڸ���ʱ����Ҫ�ж�i-coin[j]�Ƿ����ҵĿ�������Ҳ������Ͳ���Ҫ���¡� 
                ��лzywscq ָ�� 
                */  
                if(coinNum[i-coin[j]]+1<=minNum&&(i==coin[j]||coinValue[i-coin[j]]!=0))//����Ӳ�Ҹ���������  
                {  
                    minNum=coinNum[i-coin[j]]+1;//����  
                    usedMoney=coin[j];//����  
                }  
            }  
        }  
        coinNum[i]=minNum;  
        coinValue[i]=usedMoney;  
    }  
  
    //������  
    if(coinValue[money]==0)  
        cout<<"�Ҳ�����Ǯ"<<endl;  
    else  
    {  
		for(int i = 0;i < money + 1;i++)
		{
			cout<<coinValue[i]<<" ";
		}
		cout<<endl;
        cout<<"��Ҫ����Ӳ�Ҹ���Ϊ��"<<coinNum[money]<<endl;  
        cout<<"Ӳ�ҷֱ�Ϊ:";  
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