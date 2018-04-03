#pragma once
typedef int DataType;

typedef struct SListNode
{
	struct SListNode* _next;
	DataType _data;
}SListNode;


void UnionSet(SListNode* l1, SListNode* l2);//求两个已排序单链表中相同的数据
                

SListNode* BuySListNode(DataType x);
void SListPushBack(SListNode** ppHead, DataType x);
SListNode* SListFind(SListNode* pHead, DataType x);


void SLitsPrintTailToHead(SListNode* pHead);//从头到尾打印单链表
void SListPrintTailToHeadR1(SListNode* pHead);//从尾到头打印单链表(递归算法）
void SListPrintTailToHeadR2(SListNode* pHead);//从尾到头打印单链表(非递归算法）

void SListDelNonTailNode(SListNode* pos);//删除一个无头单链表非尾结点(不能遍历链表）
void SListInsertFrontNode(SListNode* pos, DataType x);//在无头单链表的一个节点前插入一个节点（不能遍历链表）
SListNode* SListJosephCircle(SListNode* pHead, int k);//单链表实现约瑟夫环(JosephCircle) 
SListNode* SListReverse(SListNode* list);//单链表的逆置反转
void SListBubbleSort(SListNode* list);//单链表的冒泡排序
// 升序 
SListNode* SListMerge(SListNode* list1, SListNode* list2);//合并两个有序链表，合并后的链表依然有序
SListNode* SListFindMidNode(SListNode* list);//查找链表中间结点(只能遍历一次链表）
SListNode* SListFindTailKNode(SListNode* list, size_t k);//查找链表倒数第K个结点

// 链表带环问题 
SListNode* SListIsCycle(SListNode* list);//判断链表是否带环
int SListCycleLen(SListNode* meetNode);//计算环的长度
SListNode* SListEntryNode(SListNode* list, SListNode* meetNode);//求环的入口点

// 链表相交问题 
SListNode* SListIsCrossNode(SListNode* list1, SListNode* list2);//判断两个链表是否相交，若相交，求交点。（假设链表不带环）
SListNode* SListCrossNode(SListNode* list1, SListNode* list2);


