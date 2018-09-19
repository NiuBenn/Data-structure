#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include"BinaryTree.h"

#define NUM 50//Õ»µÄ´óÐ¡
typedef BTNode* SDataType;

typedef struct Stack
{
	SDataType* _array;
	size_t	_top; //Õ»¶¥ 
	size_t	_end;
}Stack;

void StackInit(Stack* s)//³õÊ¼»¯Õ»
{
	s->_array = (SDataType*)malloc(sizeof(SDataType)*NUM);//mallocÉêÇëÄÚ´æ¿Õ¼ä
	if (s->_array != NULL)
	{
		s->_end = s->_top = 0;
		return;
	}
	printf("Õ»³õÊ¼»¯Ê§°Ü£¡£¡");
	return;
}

void StackPush(Stack* s, SDataType x)//ÈëÕ»
{
	assert(s);
	if (s->_top == NUM)
	{
		printf("stack overflow");//Õ»Òç³ö
		return;
	}
	s->_array[s->_top] = x;
	s->_top++;
}

void StackPop(Stack* s)//³öÕ»
{
	assert(s);
	s->_top--;
}

int  StackEmpty(Stack* s)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
{
	if (s->_top == 0)
		return 0;
	else
		return  -1;
}

SDataType StackTop(Stack* s) //Õ»¶¥ÔªËØ
{
	assert(s);
	assert(StackEmpty(s) != 0);
	return s->_array[s->_top - 1];
}

