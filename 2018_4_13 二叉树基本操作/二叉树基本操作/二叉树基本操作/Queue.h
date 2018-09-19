#pragma once
#include<assert.h>
#include<malloc.h>
#include<stdio.h>
#include"BinaryTree.h"
typedef BTNode* QDataType;

typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;//队头
	QueueNode* _tail;//队尾
	size_t _size;
}Queue;


QueueNode* BuyNewQueueNode(QDataType x);//创建新的结点
void QueueInit(Queue* q);//队列的初始化
void QueuePush(Queue* q, QDataType x);//入队
void QueuePop(Queue* q);//出队
QDataType QueueFront(Queue* q);//队头元素

QueueNode* BuyNewQueueNode(QDataType x)//创建新的结点
{
	QueueNode* tmp = (QueueNode*)malloc(sizeof(QueueNode));
	if (tmp != NULL)
	{
		tmp->_data = x;
		tmp->_next = NULL;
		return tmp;
	}
	return NULL;
}

void QueueInit(Queue* q)//队列的初始化
{
	q->_head = NULL;
	q->_tail = NULL;
	q->_size = 0;
}

void QueuePush(Queue* q, QDataType x)//入队
{
	assert(q);
	QueueNode* NewNode = BuyNewQueueNode(x);
	if (q->_size == 0)
	{
		q->_head = NewNode;
		q->_tail = NewNode;
		q->_size++;
	}
	else
	{
		q->_tail->_next = NewNode;
		q->_tail = NewNode;
		q->_size++;
	}
}

void QueuePop(Queue* q)//出队
{
	assert(q);
	if (q->_size == 0)
	{
		printf("队列为空，无可出队元素！！\n");
		return;
	}
	if (q->_size == 1)
	{
		free(q->_head);
		q->_head = NULL;
		q->_tail = NULL;
		q->_size--;
		return;
	}
	else
	{
		QueueNode* cur = q->_head->_next;
		free(q->_head);
		q->_head = cur;
		q->_size--;
		return;
	}
}

QDataType QueueFront(Queue* q)//队头元素
{
	assert(q&&q->_head);
	return q->_head->_data;
}

