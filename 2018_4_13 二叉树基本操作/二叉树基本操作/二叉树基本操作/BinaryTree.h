#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
	BTDataType _data;
}BTNode;


BTNode* BuyBTNode(BTDataType x);
// �������������

BTNode* CreateBTree(BTDataType* a, size_t* pIndex, BTDataType invalid);//����������

void BTreePrevOrder(BTNode* root);//ǰ�����
void BTreeInOrder(BTNode* root);//�������
void BTreePostOrder(BTNode* root);//�������

size_t BTreeSize(BTNode* root);//������
size_t BTreeLeafSize(BTNode* root);//Ҷ�ӽ�����
size_t BTreeKLevelSize(BTNode* root, size_t k);//��K�������
size_t BTreeDepth(BTNode* root);//���
BTNode* BTreeFind(BTNode* root, BTDataType x);//Ѱ�ҽ��
void BTreeLevelOrder(BTNode* root);//�������

								   
int IsCompleteBTree(BTNode* root);// �ж���ȫ������ 
int IsCompleteBTree1(BTNode* root); // flag�ķ�ʽ�ж� 
								   
void BTreePrevOrderNonR(BTNode* root);//�ǵݹ�ǰ�����  
void BTreeInOrderNonR(BTNode* root);// �ǵݹ��������
void BTreePostOrderNonR(BTNode* root);//�ǵݹ�������� 

void TestBinaryTree()
{
	int a[] = { 1, 2, 3, '#', '#',/*4,'#',*/ '#', 5, 6,'#' ,'#' ,'#' };
	size_t index = 0;
	BTNode* tree = CreateBTree(a, &index, '#');
	BTreePrevOrder(tree);
	printf("\n");
	BTreePrevOrderNonR(tree);
	BTreeInOrder(tree);
	printf("\n");
	BTreeInOrderNonR(tree);
	BTreePostOrder(tree);
	printf("\n");
	BTreePostOrderNonR(tree);

	printf("BTreeSize?%d\n", BTreeSize(tree));
	printf("BTreeLeafSize?%d\n", BTreeLeafSize(tree));
	printf("BTreeKLevelSize?%d\n", BTreeKLevelSize(tree, 3));
	printf("BTreeDepth?%d\n", BTreeDepth(tree));
	printf("IsCompleteBTree?%d\n", IsCompleteBTree(tree));
	printf("IsCompleteBTree1?%d\n", IsCompleteBTree1(tree));
	BTreeLevelOrder(tree);
}