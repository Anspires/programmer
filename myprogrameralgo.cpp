#include "myprogrameralgo.h"
int max(int p,int q)
{
	if(p >= q)
	{
		return p;
	}
	return q;
}
int CUT_ROD(int p [ ],int n)
{
	int q = INT_INVALID_VALUE;
	if(0 == n)
	{
		return 0;
	}
	for(int i = 0;i < n;i++)
	{
		q = max(q,p[i] + CUT_ROD(p,n - i - 1));
	}

    return q;
}
