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
	QueueNode* _head;//��ͷ
	QueueNode* _tail;//��β
	size_t _size;
}Queue;


QueueNode* BuyNewQueueNode(QDataType x);//�����µĽ��
void QueueInit(Queue* q);//���еĳ�ʼ��
void QueuePush(Queue* q, QDataType x);//���
void QueuePop(Queue* q);//����
QDataType QueueFront(Queue* q);//��ͷԪ��

QueueNode* BuyNewQueueNode(QDataType x)//�����µĽ��
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

void QueueInit(Queue* q)//���еĳ�ʼ��
{
	q->_head = NULL;
	q->_tail = NULL;
	q->_size = 0;
}

void QueuePush(Queue* q, QDataType x)//���
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

void QueuePop(Queue* q)//����
{
	assert(q);
	if (q->_size == 0)
	{
		printf("����Ϊ�գ��޿ɳ���Ԫ�أ���\n");
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

QDataType QueueFront(Queue* q)//��ͷԪ��
{
	assert(q&&q->_head);
	return q->_head->_data;
}

