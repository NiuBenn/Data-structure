#pragma once
typedef int DataType;

typedef struct SListNode
{
	struct SListNode* _next;
	DataType _data;
}SListNode;//结点包括两部分，一个是指向结点类型的指针，一个是用来存放数据的data


SListNode* BuySListNode(DataType x);//创建新的结点
void SListPrint(SListNode* pHead);//打印单链表
void SListDestory(SListNode** ppHead);//摧毁单链表

void SListPushBack(SListNode** ppHead, DataType x);//尾插
void SListPopBack(SListNode** ppHead);//尾删
void SListPushFront(SListNode** ppHead, DataType x);//头插
void SListPopFront(SListNode** ppHead);//头删
SListNode* SListFind(SListNode* pHead, DataType x);//寻找某个结点,返回它的地址
void SListInsest(SListNode** ppHead, SListNode* pos, DataType x);//在pos位置插入结点
void SListErase(SListNode** ppHead, SListNode* pos);//删除pos位置的结点
