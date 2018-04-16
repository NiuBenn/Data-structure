#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"ComplexList.h"

ComplexListNode* BuySListNode(DataType x)
{
	ComplexListNode* tmp = (ComplexListNode*)malloc(sizeof(ComplexListNode));
	if (tmp)
	{
		tmp->_data = x;
		tmp->_next = NULL;
		tmp->_random = NULL;
		return tmp;
	}
	printf("结点创建失败!!!\n");
	return NULL;
}

ComplexListNode* CopyComplexList(ComplexListNode* list)
{

	ComplexListNode* pNode = list;
	ComplexListNode* tmp = NULL;
	ComplexListNode* NewNode = NULL;
	ComplexListNode* NewHead = NULL;

	if (list == NULL)
	{
		return NewHead;
	}
	else
	{
		while (pNode)
		{
			NewNode = BuySListNode(pNode->_data);
			pNode->_next = NewNode;
			NewNode->_next = pNode->_next;
			pNode = NewNode->_next;
		}
		pNode = list;
		while (pNode)
		{
			NewNode = pNode->_next;
			if (pNode->_random)
			{
				NewNode->_random = pNode->_random->_next;
			}
			pNode = NewNode->_next;
		}
		pNode = list;
		NewHead = NewNode = pNode->_next;
		pNode->_next = NewNode->_next;
		pNode = pNode->_next;
		while (pNode)
		{
			NewNode->_next = pNode->_next;
			NewNode = NewNode->_next;
			pNode->_next = NewNode->_next;
			pNode = pNode->_next;
		}
		return NewHead;
	}
}


int main()
{
	printf("hello");
	system("pause");


}