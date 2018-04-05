#ifndef _LIST_H_
#define _LIST_H_
struct bitStruct
{
	int a:4;
	unsigned char b:3;
};
typedef struct node
{
	int a;
	struct node *next;
}NODE;
//创建多少长度的单链表,返回head节点
NODE *create_list(int length);
NODE *delete_node(NODE *head,int value);
NODE *reverse(NODE *head);
#endif
