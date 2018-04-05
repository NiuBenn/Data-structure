#pragma once
typedef int DataType;

typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;//队头
	QueueNode* _tail;//队尾
	size_t _size;
}Queue;

QueueNode* BuyNewQueueNode(DataType x);//创建新的结点
void QueueInit(Queue* q);//队列的初始化
void QueuePush(Queue* q, DataType x);//入队
void QueuePop(Queue* q);//出队
DataType QueueFront(Queue* q);//队头元素
DataType QueueBack(Queue* q);//队尾元素
size_t QueueSize(Queue* q);//队内元素个数
int QueueEmpty(Queue* q);//清空队