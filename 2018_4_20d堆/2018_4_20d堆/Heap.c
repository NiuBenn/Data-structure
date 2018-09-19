#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Heap.h"


//堆的初始化，hp为要初始化的堆，a为要处理的数组，n为元素个数
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


void HeapAdjustDown(Heap* hp, int root)//向下调整算法
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

void Expand(Heap* hp)	//扩容
{
	assert(hp);
	size_t capacity = hp->_capacity * 2;

	HeapDateType* tmp = (HeapDateType*)realloc(hp->_a, sizeof(HeapDateType)*capacity);
	assert(tmp);
	hp->_a = tmp;
	hp->_capacity = capacity;
}

void HeapPrint(Heap* hp)//打印堆
{
	size_t i = 0;
	for (i; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

void HeapPush(Heap* hp, HeapDateType x)		//插入元素（尾插）
{
	if (hp->_size == hp->_capacity)
	{
		Expand(hp);
	}

	hp->_a[hp->_size] = x;
	HeapAdjustUp( hp, hp->_size);
	hp->_size++;
}

void HeapPop(Heap* hp)//删除堆顶元素
{
	swap(&(hp->_a[0]), &(hp->_a[hp->_size - 1]));
	hp->_size--;
	HeapAdjustDown(hp, 0);

}
size_t HeapSize(Heap* hp)//堆内元素个数
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

HeapDateType HeapTop(Heap* hp)//返回堆定元素的值
{
	assert(hp);
	return hp->_a[0];
}

void HeapSort(Heap* hp)//堆排序
{
	assert(hp);
	size_t size = hp->_size;

	while (HeapEmpty(hp))//非空时
	{
		swap(&(hp->_a[0]), &(hp->_a[hp->_size - 1]));//将堆顶元素与最后一位元素交换
		hp->_size--;
		HeapAdjustDown(hp, 0);//从堆顶向下调整
	}
	hp->_size = size;
}

void HeapAdjustUp(Heap* hp, int child)//向上调整算法
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
