#pragma once
#define NUM 50//栈的大小
typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	size_t	_top; //栈顶 
	size_t	_end;
}Stack;

// 栈的实现接口 
void StackInit(Stack* s);//栈的初始化
void StackPush(Stack* s, DataType x);//入栈
void StackPop(Stack* s);//出栈
DataType StackTop(Stack* s);//查看栈顶元素
size_t StackSize(Stack* s);//栈内元素个数
int StackEmpty(Stack* s);//清空栈
void StackPrintf(Stack* s);//打印栈内元素(由栈底到栈顶)