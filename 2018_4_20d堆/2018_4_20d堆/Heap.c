#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Heap.h"


//�ѵĳ�ʼ����hpΪҪ��ʼ���Ķѣ�aΪҪ��������飬nΪԪ�ظ���
void HeapInit(Heap* hp, HeapDateType* a, size_t n)
{
	assert(hp);
	assert(n > 0);
	hp->_capacity = n * 2;
	hp->_size = n;
	hp->_a = (HeapDateType*)malloc(sizeof(HeapDateType)*(hp->_size));
	assert(hp->_a);

	for(size_t i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	
}


void HeapMake(Heap* hp)
{
	assert(hp);
	int i = (hp->_size - 2) >> 1;
	for (; i >= 0; --i)
	{
		HeapAdjustDown(hp, i);
	}
}

void swap(HeapDateType* a, HeapDateType* b)
{
	HeapDateType c = *a;
	*a = *b;
	*b = c;
}


void HeapAdjustDown(Heap* hp, int root)//���µ����㷨
{
	assert(hp);
	int parent = root;
	int child = parent * 2 + 1;

	while (child <= (int)(hp->_size - 1))
	{
		if ((child + 1 <= (int)(hp->_size - 1))&&(hp->_a[child + 1] > hp->_a[child]))
		{
			child = child + 1;
		}
		if (hp->_a[child] > hp->_a[parent])
		{
			swap(&(hp->_a[parent]), &(hp->_a[child]));
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void Expand(Heap* hp)	//����
{
	assert(hp);
	size_t capacity = hp->_capacity * 2;

	HeapDateType* tmp = (HeapDateType*)realloc(hp->_a, sizeof(HeapDateType)*capacity);
	assert(tmp);
	hp->_a = tmp;
	hp->_capacity = capacity;
}

void HeapPrint(Heap* hp)//��ӡ��
{
	size_t i = 0;
	for (i; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

void HeapPush(Heap* hp, HeapDateType x)		//����Ԫ�أ�β�壩
{
	if (hp->_size == hp->_capacity)
	{
		Expand(hp);
	}

	hp->_a[hp->_size] = x;
	HeapAdjustUp( hp, hp->_size);
	hp->_size++;
}

void HeapPop(Heap* hp)//ɾ���Ѷ�Ԫ��
{
	swap(&(hp->_a[0]), &(hp->_a[hp->_size - 1]));
	hp->_size--;
	HeapAdjustDown(hp, 0);

}
size_t HeapSize(Heap* hp)//����Ԫ�ظ���
{
	return hp->_size;
}
size_t HeapEmpty(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
		return 0;
	else
		return 1;
}

HeapDateType HeapTop(Heap* hp)//���ضѶ�Ԫ�ص�ֵ
{
	assert(hp);
	return hp->_a[0];
}

void HeapSort(Heap* hp)//������
{
	assert(hp);
	size_t size = hp->_size;

	while (HeapEmpty(hp))//�ǿ�ʱ
	{
		swap(&(hp->_a[0]), &(hp->_a[hp->_size - 1]));//���Ѷ�Ԫ�������һλԪ�ؽ���
		hp->_size--;
		HeapAdjustDown(hp, 0);//�ӶѶ����µ���
	}
	hp->_size = size;
}

void HeapAdjustUp(Heap* hp, int child)//���ϵ����㷨
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (hp->_a[child] > hp->_a[parent])
		{
			swap(&(hp->_a[parent]), &(hp->_a[child]));

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	Heap hp;
	HeapInit(&hp, a, 10);
	HeapMake(&hp);
	HeapPrint(&hp);
	HeapPush(&hp, 12);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("%d\n", HeapEmpty(&hp));
	printf("%d\n", HeapTop(&hp));
	printf("%d\n", HeapSize(&hp));
	HeapSort(&hp);
	HeapPrint(&hp);



	system("pause");
	return 0;
}
