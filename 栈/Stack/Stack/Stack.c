#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Stack.h"

void StackInit(Stack* s)//初始化栈
{
	s->_array = (DataType*)malloc(sizeof(DataType)*NUM);//malloc申请内存空间
	if (s->_array != NULL)
	{
		s->_end = s->_top = 0;
		return;
	}
	printf("栈初始化失败！！");
	return;
}

void StackPush(Stack* s, DataType x)//入栈
{
	assert(s);
	if (s->_top == NUM)
	{
		printf("stack overflow");//栈溢出
		return;
	}
	s->_array[s->_top] = x;
	s->_top++;
}

void StackPop(Stack* s)//出栈
{
	assert(s);
	s->_top--;
}

DataType StackTop(Stack* s) //栈顶元素
{
	assert(s);
	if (s->_top == 0)
	{
		printf("栈为空！！");
		return -1;
	}
	else
		return s->_array[s->_top- 1];
}

size_t StackSize(Stack* s)//栈内元素个数
{
	assert(s);
	return s->_top;
}

int StackEmpty(Stack* s)//清空栈
{
	s->_top = 0;
	return 0;
}

void StackPrintf(Stack* s)//打印栈内元素
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
	printf("栈内元素为：");
	StackPrintf(&s);
	printf("栈内元素个数为：%d\n", StackSize(&s));
	printf("栈顶元素为：%d\n", StackTop(&s));
	system("pause");
	return 0;
}