#ifndef __ARRAYSEARCH_H__
#define __ARRAYSEARCH_H__
#define MAX_VALUE   20  

typedef struct gnode
{
	int vex;
	struct gnode *next;
}GNODE;
void dfs(GNODE adl[],int v);
int arraySearch(int sum,int num,int set[]);
void FindMin(int money,int *coin, int n);
void SegNum(int nSum, int* pData, int nDepth);
void ShowResult(int array[],int nLen);

void insertion_sort(int array[],int length,int new_array[]);
#endif