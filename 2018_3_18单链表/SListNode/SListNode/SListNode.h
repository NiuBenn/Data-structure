#pragma once
typedef int DataType;

typedef struct SListNode
{
	struct SListNode* _next;
	DataType _data;
}SListNode;//�����������֣�һ����ָ�������͵�ָ�룬һ��������������ݵ�data


SListNode* BuySListNode(DataType x);//�����µĽ��
void SListPrint(SListNode* pHead);//��ӡ������
void SListDestory(SListNode** ppHead);//�ݻٵ�����

void SListPushBack(SListNode** ppHead, DataType x);//β��
void SListPopBack(SListNode** ppHead);//βɾ
void SListPushFront(SListNode** ppHead, DataType x);//ͷ��
void SListPopFront(SListNode** ppHead);//ͷɾ
SListNode* SListFind(SListNode* pHead, DataType x);//Ѱ��ĳ�����,�������ĵ�ַ
void SListInsest(SListNode** ppHead, SListNode* pos, DataType x);//��posλ�ò�����
void SListErase(SListNode** ppHead, SListNode* pos);//ɾ��posλ�õĽ��
