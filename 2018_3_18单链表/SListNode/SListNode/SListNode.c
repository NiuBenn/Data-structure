#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"SListNode.h"

SListNode* BuySListNode(DataType x)//创建结点
{
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	if (tmp != NULL)
	{
		tmp->_data = x;
		tmp->_next = NULL;
		return tmp;
	}
	printf("节点创建失败！");
	return tmp;
}

void SListPrint(SListNode* pHead)//打印单链表
{
	if (pHead == NULL)
	{
		printf("该链表为空链表！\n");
	}
	else
	{
		while (pHead)
		{
			printf("%d->", pHead->_data);
			pHead = pHead->_next;
		}
		printf("NULL\n");
	}
}

void SListDestory(SListNode** ppHead)//删除整个单链表
{
	SListNode* tmp;
	if (*ppHead == NULL)
		return;
	else
	{
		while (*ppHead)
		{
			tmp = *ppHead;
			*ppHead = (*ppHead)->_next;
			free(tmp);
			tmp = NULL;
		}
	}
}
void SListPushBack(SListNode** ppHead, DataType x)//从尾部插入数据
{
	SListNode* newNode;
	SListNode* tmp;
	newNode = BuySListNode(x);
	tmp = *ppHead;
	if (NULL == *ppHead)
	{
		*ppHead = newNode;
		(*ppHead)->_next = NULL;
	}
	else
	{
		while (tmp->_next)
		{
			tmp = tmp->_next;
		}
		tmp->_next = newNode;
		newNode->_next = NULL;
	}
}

void SListPopBack(SListNode** ppHead)//从尾部删除数据
{
	//三种情况
	//1.链表为空链表
	//2.链表只有一个结点
	//3.链表有多个节点
	SListNode* tmp;
	tmp = *ppHead;
	if (*ppHead == NULL)
	{
		printf("该链表已经为空表，无需再删除元素！");
	}
	else if ((*ppHead)->_next == NULL)
	{
		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{

		while ((tmp)->_next->_next)
		{
			tmp = tmp->_next;
		}
		free(tmp->_next);
		tmp->_next = NULL;
	}
}

void SListPushFront(SListNode** ppHead, DataType x)//从头部插入数据
{
	SListNode* newNode;
	newNode = BuySListNode(x);
	if (*ppHead == NULL)//链表为空链表
	{
		*ppHead = newNode;
		(*ppHead)->_next = NULL;
	}
	else
	{
		newNode->_next = *ppHead;
		*ppHead = newNode;
	}
}

void SListPopFront(SListNode** ppHead)//从头部删除数据
{
	//三种情况
	//1.链表为空链表
	//2.链表只有一个结点
	//3.链表有多个节点
	SListNode* tmp;
	tmp = *ppHead;
	if (*ppHead == NULL)
	{
		printf("该链表已经为空表，无需再删除元素！");
	}
	else if ((*ppHead)->_next == NULL)
	{
		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{
		*ppHead = (*ppHead)->_next;
		free(tmp);
		tmp = NULL;
	}

}
SListNode* SListFind(SListNode* pHead, DataType x)//找到链表中的某个元素
{
	SListNode* tmp;
	tmp = pHead;
	while (tmp)
	{
		if (tmp->_data == x)
		{
			return tmp;
		}
		tmp = tmp->_next;
	}
	return tmp;
}

void SListInsest(SListNode** ppHead, SListNode* pos, DataType x)//在链表中pos位置插入 x
{
	if (pos == NULL)
	{
		printf("该位置地址为空！无法插入！！\n");
	}
	else
	{
		SListNode* tmp;
		SListNode* newNode;
		newNode = BuySListNode(x);
		tmp = *ppHead;
		if (tmp == pos)
		{
			SListPushFront(ppHead, x);
			return;
		}
		while (tmp)
		{
			if (tmp->_next == pos)
			{
				newNode->_next = tmp->_next;
				tmp->_next = newNode;
				return;
			}
			tmp = tmp->_next;
		}
		printf("该位置不在该顺序表中，插入失败！");
	}
}

void SListErase(SListNode** ppHead, SListNode* pos)//删除链表中pos位置的元素
{
	assert(pos);
	SListNode* tmp;
	SListNode* cur;
	tmp = *ppHead;
	while (tmp->_next == pos)
	{
		tmp = tmp->_next;
	}
	cur = tmp->_next;
	tmp->_next = tmp->_next->_next;
	free(cur);
	cur = NULL;
}

int main()
{
	SListNode* SList;
	SList = BuySListNode(1);
	SListPushBack(&SList,2);
	SListPushBack(&SList, 3);
	SListPushBack(&SList, 4);
	SListPushBack(&SList, 5);
	SListPrint(SList);
	SListPopBack(&SList);
	SListPushFront(&SList, 8);
	SListPrint(SList);
	SListInsest(&SList,SListFind(SList, 2), 9);
	SListPopFront(&SList);
	SListPrint(SList);
	SListErase(&SList, SListFind(SList, 2));
	SListPrint(SList);
	SListDestory(&SList);
	SListPrint(SList);
	system("pause");
	return 0;
}