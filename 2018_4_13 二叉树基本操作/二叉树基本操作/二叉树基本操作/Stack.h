#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include"BinaryTree.h"

#define NUM 50//ջ�Ĵ�С
typedef BTNode* SDataType;

typedef struct Stack
{
	SDataType* _array;
	size_t	_top; //ջ�� 
	size_t	_end;
}Stack;

void StackInit(Stack* s)//��ʼ��ջ
{
	s->_array = (SDataType*)malloc(sizeof(SDataType)*NUM);//malloc�����ڴ�ռ�
	if (s->_array != NULL)
	{
		s->_end = s->_top = 0;
		return;
	}
	printf("ջ��ʼ��ʧ�ܣ���");
	return;
}

void StackPush(Stack* s, SDataType x)//��ջ
{
	assert(s);
	if (s->_top == NUM)
	{
		printf("stack overflow");//ջ���
		return;
	}
	s->_array[s->_top] = x;
	s->_top++;
}

void StackPop(Stack* s)//��ջ
{
	assert(s);
	s->_top--;
}

int  StackEmpty(Stack* s)//�ж�ջ�Ƿ�Ϊ��
{
	if (s->_top == 0)
		return 0;
	else
		return  -1;
}

SDataType StackTop(Stack* s) //ջ��Ԫ��
{
	assert(s);
	assert(StackEmpty(s) != 0);
	return s->_array[s->_top - 1];
}

