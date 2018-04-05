#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"QueueNode .h"

QueueNode* BuyNewQueueNode(DataType x)//�����µĽ��
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

void QueuePush(Queue* q, DataType x)//���
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

DataType QueueFront(Queue* q)//��ͷԪ��
{
	assert(q&&q->_head);
	return q->_head->_data;
}

DataType QueueBack(Queue* q)//��βԪ��
{
	assert(q&&q->_tail);
	return q->_tail->_data;
}

size_t QueueSize(Queue* q)//����Ԫ�ظ���
{
	assert(q);
	return q->_size;
}

int QueueEmpty(Queue* q)//��ն���
{
	assert(q);
	if (q->_size == 0)
	{
		return 0;
	}
	else
	{
		QueueNode* cur = q->_head->_next;
		while (q->_head != q->_tail)
		{
			free(q->_head);
			q->_head = cur;
			cur = cur->_next;
		}
		free(q->_head);
		q->_head = NULL;
		q->_tail = NULL;
		q->_size = 0;
		return 0;
	}
}


int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePop(&q);
	printf("����Ԫ��Ϊ��%d\n", QueueFront(&q));
	printf("��βԪ��Ϊ��%d\n", QueueBack(&q));
	printf("����Ԫ�ظ���Ϊ��%d\n", QueueSize(&q));	
	system("pause");
	return 0;
}