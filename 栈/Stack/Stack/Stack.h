#pragma once
#define NUM 50//ջ�Ĵ�С
typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	size_t	_top; //ջ�� 
	size_t	_end;
}Stack;

// ջ��ʵ�ֽӿ� 
void StackInit(Stack* s);//ջ�ĳ�ʼ��
void StackPush(Stack* s, DataType x);//��ջ
void StackPop(Stack* s);//��ջ
DataType StackTop(Stack* s);//�鿴ջ��Ԫ��
size_t StackSize(Stack* s);//ջ��Ԫ�ظ���
int StackEmpty(Stack* s);//���ջ
void StackPrintf(Stack* s);//��ӡջ��Ԫ��(��ջ�׵�ջ��)