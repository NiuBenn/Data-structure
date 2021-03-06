#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"SList.h"

SListNode* BuySListNode(DataType x)//创建结点
{
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	if (tmp != NULL)
	{
		tmp->_data = x;
		tmp->_next = NULL;
		return tmp;
	}
	printf("节点创建失败！");
	return tmp;
}

void SLitsPrintTailToHead(SListNode* pHead)//打印单链表
{
	if (pHead == NULL)
	{
		printf("该链表为空！\n");
	}
	else
	{
		while (pHead)
		{
			printf("%d->", pHead->_data);
			pHead = pHead->_next;
		}
		printf("NULL\n");
	}
}

void SListPushBack(SListNode** ppHead, DataType x)//从尾部插入数据
{
	SListNode* newNode;
	SListNode* tmp;
	newNode = BuySListNode(x);
	tmp = *ppHead;
	if (NULL == *ppHead)
	{
		*ppHead = newNode;
		(*ppHead)->_next = NULL;
	}
	else
	{
		while (tmp->_next)
		{
			tmp = tmp->_next;
		}
		tmp->_next = newNode;
		newNode->_next = NULL;
	}
}

void SListPrintTailToHeadR1(SListNode* pHead)//从尾到头打印单链表(递归算法）
{
	if(pHead == NULL)
	{
		return;
	}
	SListPrintTailToHeadR1(pHead->_next);
	printf("%d->", pHead->_data);
}

void SListPrintTailToHeadR2(SListNode* pHead)//从尾到头打印单链表(非递归算法）
{
	SListNode* tmp = pHead;
	SListNode* cur = pHead;
	if (pHead == NULL)
	{
		printf("该链表为空！！\n");
		return;
	}
	while (cur)
	{
		cur = cur->_next;
	}
	while (cur != pHead)
	{
		while ((tmp->_next) != cur)
		{
			tmp = tmp->_next;
		}
		printf("%d->", tmp->_data);
		cur = tmp;
		tmp = pHead;
	}
}

void SListDelNonTailNode(SListNode* pos)//删除一个无头单链表非尾结点(不能遍历链表）
{
	assert(pos);
	SListNode* tmp = pos->_next;
	pos->_data = pos->_next->_data;
	pos->_next = pos->_next->_next;
	free(tmp);
	//tmp = NULL;
}

void SListInsertFrontNode(SListNode* pos, DataType x)//在无头单链表的一个节点前插入一个节点（不能遍历链表）
{
	assert(pos);
	SListNode* NewNode = BuySListNode(pos->_data);
	NewNode->_next = pos->_next;
	pos->_next = NewNode;
	pos->_data = x;
}

SListNode* SListJosephCircle(SListNode* pHead, int k)//单链表实现约瑟夫环(JosephCircle) 
{
	SListNode* cur = pHead;
	SListNode* tmp = NULL;
	while (cur != cur->_next)
	{
		int count = k;
		while (--count)
		{
			cur = cur->_next;
		}
		tmp = cur->_next;
		cur->_data = tmp->_data;
		cur->_next = tmp->_next;
		free(tmp);
		//tmp = NULL;
	}
	return cur;
}

SListNode* SListFind(SListNode* pHead, DataType x)//找到链表中的某个元素
{
	SListNode* tmp;
	tmp = pHead;
	while (tmp)
	{
		if (tmp->_data == x)
		{
			return tmp;
		}
		tmp = tmp->_next;
	}
	return tmp;
}

SListNode* SListReverse(SListNode* list)//单链表的逆置反转
{
	SListNode* cur = list;
	SListNode* NewList = NULL;
	SListNode* tmp = NULL;
	while (cur)
	{
		tmp = cur->_next;
		cur->_next = NewList;
		NewList = cur;
		cur = tmp;
	}
	return NewList;
}

void SListBubbleSort(SListNode* list)//单链表的冒泡排序
{
	if (list == NULL)
	{
		printf("该链表为空！！\n");
		return;
	}
	SListNode* tmp = list;
	SListNode* cur = NULL;
	while (cur != list)
	{
		tmp = list;
		while ((tmp->_next) != cur)
		{
			int temp;
			if((tmp->_data) > (tmp->_next->_data))
			{
				temp = tmp->_data;
				tmp->_data = tmp->_next->_data;
				tmp->_next->_data = temp;
			}
			tmp = tmp->_next;
		}
		cur = tmp;
	}
}

SListNode* SListMerge(SListNode* list1, SListNode* list2)//合并两个有序链表，合并后的链表依然有序
{
	SListNode* list = NULL;
	SListNode* NewList = NULL;
	if (list1 == NULL)
	{
		return list1;
	}
	if (list2 == NULL)
	{
		return list2;
	}
	if ((list1->_data) < (list2->_data))
	{
		list = NewList = list1;
		list1 = list1->_next;
	}
	else
	{
		list = NewList = list2;
		list2 = list2->_next;
	}
	while (list1&&list2)
	{
		if ((list1->_data) < (list2->_data))
		{
			NewList->_next = list1;
			list1 = list1->_next;
		}
		else
		{
			NewList->_next = list2;
			list2 = list2->_next;
		}
		NewList = NewList->_next;
	}
	if (list1)
	{
		NewList->_next = list1;
	}
	if(list2)
	{
		NewList->_next = list2;
	}
	return list;
}

SListNode* SListFindMidNode(SListNode* list)//查找链表中间结点(只能遍历一次链表）
{
	SListNode* slow = list;
	SListNode* fast = list;
	while (fast->_next)
	{
		fast = fast->_next;
		if (fast->_next == NULL)
		{
			break;
		}
		fast = fast->_next;
		slow = slow->_next;
	}
	return slow;
}

SListNode* SListFindTailKNode(SListNode* list, size_t k)//查找链表倒数第K个结点
{
	SListNode* slow = list;
	SListNode* fast = list;
	while (--k)
	{
		fast = fast->_next;
	}
	while (fast->_next)
	{
		fast = fast->_next;
		slow = slow->_next;
	}
	return slow;
}

SListNode* SListIsCycle(SListNode* list)//判断链表是否带环
{
	SListNode* fast;
	SListNode* slow;
	slow = fast = list;
	while (fast)
	{
		fast = fast->_next;
		if (fast != NULL)
		{
			fast = fast->_next;
		}
		slow = slow->_next;
		if (fast == slow)
		{
			return fast;
		}
	}
	return NULL;
}

int SListCycleLen(SListNode* meetNode)//计算环的长度
{
	int Len = 0;
	SListNode* tmp = meetNode;
	while ((tmp->_next) != meetNode)
	{
		tmp = tmp->_next;
		Len++;
	}
	Len++;
	return Len;
}

SListNode* SListEntryNode(SListNode* list, SListNode* meetNode)//求环的入口点
{
	while (list != meetNode)
	{
		list = list->_next;
		meetNode = meetNode->_next;
	}
	return list;
}

SListNode* SListIsCrossNode(SListNode* list1, SListNode* list2)//判断两个链表是否相交，若相交，求交点。（假设链表不带环）
{
	SListNode* cur1 = list1;
	SListNode* cur2 = list2;
	int count1 = 0;
	int count2 = 0;
	int tmp = 0;
	while (cur1)
	{
		cur1 = cur1->_next;
		count1++;
	}
	while (cur2)
	{
		cur2 = cur2->_next;
		count2++;
	}
	if (cur1 != cur2)
	{
		printf("两个链表不相交！！\n");
		return NULL;
	}
	else
	{
		if (count1 > count2)
		{
			tmp = count1 - count2;
			while (tmp--)
			{
				list1 = list1->_next;
			}
		}
		else
		{
			tmp = count2 - count1;
			while (tmp--)
			{
				list2 = list2->_next;
			}
		}
		while (list1 != list2)
		{
			list1 = list1->_next;
			list2 = list2->_next;
		}
		return list1;
	}
}

//SListNode *SListIsCrossNode(SListNode* SL1, SListNode*SL2)
//{
//	int len1 = 0;
//	int len2 = 0;
//	int len = 0;
//	SListNode*cur1 = SL1;
//	SListNode*cur2 = SL2;
//	//统计两个链表长度
//	while (cur1)
//	{
//		len1++;
//		cur1 = cur1->_next;
//	}
//	while (cur2)
//	{
//		len2++;
//		cur2 = cur2->_next;
//	}
//	//比较长度，长的链表先走绝对值之差步
//	if (len1 > len2)
//	{
//		len = len1 - len2;
//		while (len--)
//			SL1 = SL1->_next;
//	}
//	if (len1 < len2)
//	{
//		len = len2 - len1;
//		while (len--)
//			SL2 = SL2->_next;
//	}
//	//两个链表一起走
//	while (SL1 != SL2)
//	{
//		SL1 = SL1->_next;
//		SL2 = SL2->_next;
//	}
//	return SL1;
//}

SListNode* SListCrossNode(SListNode* list1, SListNode* list2)//判断链表是否相交(可能带环)
{
	assert(list1&&list2);

	SListNode* flag1 = SListIsCycle(list1);
	SListNode* flag2 = SListIsCycle(list2);
	if ((flag1 == NULL && flag2 != NULL)||(flag1 !=NULL && flag2 == NULL))//如果一个带环一个不带环则肯定不相交
	{
		return NULL;
	}
	else if ((flag1 == NULL)&&(flag2 == NULL))//如果两个都不带环
	{
		return SListIsCrossNode(list1, list2);//调用判断链表是否相交的函数(不带环)
	}
	else
	{
		SListNode* tmp1 = SListIsCycle(list1);//链表1里面快慢指针相遇点
		SListNode* tmp2 = SListIsCycle(list2); //链表2里面快慢指针相遇点
		SListNode* cur = tmp1;//记录链表1快慢指针的相遇点
		while (cur->_next != tmp1)
		{
			if (cur == tmp2)//如果cur等于tmp2，则说明两个指针在同一个环里面
			{
				SListNode* Enter1 = SListEntryNode(list1,tmp1);//链表1环的入口
				SListNode* Enter2 = SListEntryNode(list2,tmp2);//链表2环的入口 
				if (Enter1 != Enter2)//如果这两个入口不相等，则这两个入口都可以做交点
				{
					return Enter1;
				}
				else
				{
					SListNode* cur1 = list1;
					SListNode* cur2 = list2;
					int count1 = 0;
					int count2 = 0;
					int tmp = 0;
					while (cur1->_next!=Enter1)
					{
						cur1 = cur1->_next;
						count1++;
					}
					while (cur2->_next!=Enter1)
					{
						cur2 = cur2->_next;
						count2++;
					}
					if (count1 > count2)
					{
						tmp = count1 - count2;
						while (tmp--)
						{
							list1 = list1->_next;
						}
					}
					else
					{
						tmp = count2 - count1;
						while (tmp--)
						{
							list2 = list2->_next;
						}
					}
					while (list1->_next != list2->_next)
					{
						list1 = list1->_next;
						list2 = list2->_next;
					}
					return list1->_next;
				}
			}
			cur = cur->_next;
		}
		return NULL;//如果上面while循环执行完了，则说明两个指针在两个不同的环里面，则不可能相交
	}
}

void UnionSet(SListNode* l1, SListNode* l2)//求两个已排序单链表中相同的数据
{
	SListNode* cur1 = l1;
	SListNode* cur2 = l2;
	while (cur1&&cur2)
	{
		if (cur1->_data == cur2->_data)
		{
			printf("%d\n", cur1->_data);
			cur1 = cur1->_next;
			cur2 = cur2->_next;
		}
		else if (cur1->_data < cur2->_data)
		{
			cur1 = cur1->_next;
		}
		else
		{
			cur2 = cur2->_next;
		}
	}
}

int main()
{

	SListNode* SList1 = NULL;
	SListNode* SList2 = NULL;

	SListPushBack(&SList1, 1);
	SListPushBack(&SList1, 2);
	SListPushBack(&SList1, 3);
	SListPushBack(&SList1, 5);
	SListPushBack(&SList1, 6);
	SListPushBack(&SList1, 7);
	SListFind(SList1, 7)->_next = SListFind(SList1, 1);
	printf("%d\n", SListJosephCircle(SList1, 3)->_data);
	
	/*SListPushBack(&SList2, 1);
	SListPushBack(&SList2, 2);
	SListPushBack(&SList2, 3);
	SListPushBack(&SList2, 4);
	SListPushBack(&SList2, 5);
	SListPushBack(&SList2, 6);
	SListPushBack(&SList2, 7);
	SListPushBack(&SList2, 8);

	UnionSet(SList1, SList2);*/
	
	
	system("pause");
	return 0;
}