#pragma once
typedef int HeapDateType;

typedef struct Heap
{
	HeapDateType* _a;
	size_t _size;
	size_t _capacity;
}Heap;

void HeapInit(Heap* hp, HeapDateType* a, size_t n);
//堆的初始化，hp为要初始化的堆，a为要处理的数组，n为元素个数

void HeapMake(Heap* hp);//建堆(此处建大堆)
void HeapAdjustDown(Heap* hp, int root);//向下调整
void swap(HeapDateType* a, HeapDateType* b);
void HeapPrint(Heap* hp);//打印堆

void Expand(Heap* hp);//扩容
void HeapPush(Heap* hp, HeapDateType x);//插入(尾插)
void HeapPop(Heap* hp);//删除(头删)
size_t HeapSize(Heap* hp);//堆内元素个数
size_t HeapEmpty(Heap* hp);//判空 空返回0，非空返回-1
HeapDateType HeapTop(Heap* hp);//返回堆定的值
void HeapSort(Heap* hp);//堆排序
void HeapAdjustUp(Heap* hp, int child);//向上调整算法
