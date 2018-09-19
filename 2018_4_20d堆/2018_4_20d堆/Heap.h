#pragma once
typedef int HeapDateType;

typedef struct Heap
{
	HeapDateType* _a;
	size_t _size;
	size_t _capacity;
}Heap;

void HeapInit(Heap* hp, HeapDateType* a, size_t n);
//�ѵĳ�ʼ����hpΪҪ��ʼ���Ķѣ�aΪҪ��������飬nΪԪ�ظ���

void HeapMake(Heap* hp);//����(�˴������)
void HeapAdjustDown(Heap* hp, int root);//���µ���
void swap(HeapDateType* a, HeapDateType* b);
void HeapPrint(Heap* hp);//��ӡ��

void Expand(Heap* hp);//����
void HeapPush(Heap* hp, HeapDateType x);//����(β��)
void HeapPop(Heap* hp);//ɾ��(ͷɾ)
size_t HeapSize(Heap* hp);//����Ԫ�ظ���
size_t HeapEmpty(Heap* hp);//�п� �շ���0���ǿշ���-1
HeapDateType HeapTop(Heap* hp);//���ضѶ���ֵ
void HeapSort(Heap* hp);//������
void HeapAdjustUp(Heap* hp, int child);//���ϵ����㷨
