#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Stack.h"

void StackInit(Stack* s)//��ʼ��ջ
{
	s->_array = (DataType*)malloc(sizeof(DataType)*NUM);//malloc�����ڴ�ռ�
	if (s->_array != NULL)
	{
		s->_end = s->_top = 0;
		return;
	}
	printf("ջ��ʼ��ʧ�ܣ���");
	return;
}

void StackPush(Stack* s, DataType x)//��ջ
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

DataType StackTop(Stack* s) //ջ��Ԫ��
{
	assert(s);
	if (s->_top == 0)
	{
		printf("ջΪ�գ���");
		return -1;
	}
	else
		return s->_array[s->_top- 1];
}

size_t StackSize(Stack* s)//ջ��Ԫ�ظ���
{
	assert(s);
	return s->_top;
}

int StackEmpty(Stack* s)//���ջ
{
	s->_top = 0;
	return 0;
}

void StackPrintf(Stack* s)//��ӡջ��Ԫ��
{
	assert(s);
	rsize_t i = 0;
	for (i = 0; i < s->_top; i++)
	{
		printf("%-3d", s->_array[i]);
	}
	printf("\n");
}

int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPop(&s);
	StackPush(&s, 6);
	printf("ջ��Ԫ��Ϊ��");
	StackPrintf(&s);
	printf("ջ��Ԫ�ظ���Ϊ��%d\n", StackSize(&s));
	printf("ջ��Ԫ��Ϊ��%d\n", StackTop(&s));
	system("pause");
	return 0;
}