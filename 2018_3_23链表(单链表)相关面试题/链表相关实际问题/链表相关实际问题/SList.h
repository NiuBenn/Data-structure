#pragma once
typedef int DataType;

typedef struct SListNode
{
	struct SListNode* _next;
	DataType _data;
}SListNode;


void UnionSet(SListNode* l1, SListNode* l2);//��������������������ͬ������
                

SListNode* BuySListNode(DataType x);
void SListPushBack(SListNode** ppHead, DataType x);
SListNode* SListFind(SListNode* pHead, DataType x);


void SLitsPrintTailToHead(SListNode* pHead);//��ͷ��β��ӡ������
void SListPrintTailToHeadR1(SListNode* pHead);//��β��ͷ��ӡ������(�ݹ��㷨��
void SListPrintTailToHeadR2(SListNode* pHead);//��β��ͷ��ӡ������(�ǵݹ��㷨��

void SListDelNonTailNode(SListNode* pos);//ɾ��һ����ͷ�������β���(���ܱ�������
void SListInsertFrontNode(SListNode* pos, DataType x);//����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
SListNode* SListJosephCircle(SListNode* pHead, int k);//������ʵ��Լɪ��(JosephCircle) 
SListNode* SListReverse(SListNode* list);//����������÷�ת
void SListBubbleSort(SListNode* list);//�������ð������
// ���� 
SListNode* SListMerge(SListNode* list1, SListNode* list2);//�ϲ��������������ϲ����������Ȼ����
SListNode* SListFindMidNode(SListNode* list);//���������м���(ֻ�ܱ���һ������
SListNode* SListFindTailKNode(SListNode* list, size_t k);//������������K�����

// ����������� 
SListNode* SListIsCycle(SListNode* list);//�ж������Ƿ����
int SListCycleLen(SListNode* meetNode);//���㻷�ĳ���
SListNode* SListEntryNode(SListNode* list, SListNode* meetNode);//�󻷵���ڵ�

// �����ཻ���� 
SListNode* SListIsCrossNode(SListNode* list1, SListNode* list2);//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣����������������
SListNode* SListCrossNode(SListNode* list1, SListNode* list2);


