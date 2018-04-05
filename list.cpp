#include "list.h"
#include "stdio.h"
NODE *create_list(int length)
{
	if(length <= 0)
	{
		printf("empty list.\n");
		return NULL;
	}
	NODE *head = new NODE;
	NODE *current = head;
	NODE *prev = NULL;
	//NODE *temp = NULL;
	
	for(int i = 0;i < length;i++)
	{
		if(i >= 1)
		{
			current = new NODE;
			prev->next = current;
		}
		current->a = i;
		prev = current;

		if(i == length - 1)
		{
			current->next = NULL;
		}
		//current++;
	}

	return head;
}
//NODE *delete_node(NODE *head,int value)
//{
//	//NODE *rtn_e
//	NODE *current = head;
//	NODE *prev = NULL;
//	NODE *temp = NULL;
//	int bFound = 0;
//	if(NULL == head)//如果头节点是NULL，则直接返回
//	{
//		return NULL;
//	}
//	else
//	{
//		//prev = current;
//		if(value == head->a)
//		{
//			if(NULL == head->next)//只有一个头节点
//			{
//				delete head;
//				return NULL;	
//			}
//			else
//			{
//				temp = head->next;
//				delete head;
//				return temp;
//			}
//		}
//		else
//		{
//			prev = current;
//			current = current->next;
//			while(NULL != current)
//			{
//				if(value == current->a)
//				{
//					bFound = 1;
//					break;
//				}
//				prev = current;
//				current = current->next;
//			}
//			if(bFound)
//			{
//				if(NULL == current->next)//说明是尾节点
//				{
//					delete current;
//					prev->next = NULL;
//				}
//				else
//				{
//					temp = current->next;
//					delete current;
//					prev->next = temp;
//				}
//			}
//		}
//	}
//	return head;
//}
NODE *delete_node(NODE *head,int value)
{
	NODE *current = head;
	NODE *prev = NULL;
	while(NULL != current)
	{
		if(value == current->a)
		{
			if(NULL == prev)//说明是第一个节点
			{
				if(NULL == current->next)//说明只有一个头节点
				{
					delete current;
					head = NULL;
					return head;
				}
				else//说明头节点是
				{
					prev = current->next;
					delete current;
					return prev;
				}
			}
			prev->next = current->next;
			delete current;
			break;
		}
		prev = current;
		current = current->next;
	}

	return head;
}
NODE *reverse(NODE *head)
{
	NODE *current = head;
	NODE *next = NULL;
	NODE *prev = NULL;
	if(NULL == current->next)
	{
		return head;
	}
	else
	{
		//next = current->next;
		while(NULL != current->next)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		current->next = prev;
		return current;
	}
}