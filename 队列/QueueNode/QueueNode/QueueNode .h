#pragma once
typedef int DataType;

typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;//��ͷ
	QueueNode* _tail;//��β
	size_t _size;
}Queue;

QueueNode* BuyNewQueueNode(DataType x);//�����µĽ��
void QueueInit(Queue* q);//���еĳ�ʼ��
void QueuePush(Queue* q, DataType x);//���
void QueuePop(Queue* q);//����
DataType QueueFront(Queue* q);//��ͷԪ��
DataType QueueBack(Queue* q);//��βԪ��
size_t QueueSize(Queue* q);//����Ԫ�ظ���
int QueueEmpty(Queue* q);//��ն�