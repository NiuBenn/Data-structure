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
// 创建二叉树结点

BTNode* CreateBTree(BTDataType* a, size_t* pIndex, BTDataType invalid);//创建二叉树

void BTreePrevOrder(BTNode* root);//前序遍历
void BTreeInOrder(BTNode* root);//中序遍历
void BTreePostOrder(BTNode* root);//后序遍历

size_t BTreeSize(BTNode* root);//结点个数
size_t BTreeLeafSize(BTNode* root);//叶子结点个数
size_t BTreeKLevelSize(BTNode* root, size_t k);//第K层结点个数
size_t BTreeDepth(BTNode* root);//深度
BTNode* BTreeFind(BTNode* root, BTDataType x);//寻找结点
void BTreeLevelOrder(BTNode* root);//层序遍历

								   
int IsCompleteBTree(BTNode* root);// 判断完全二叉树 
int IsCompleteBTree1(BTNode* root); // flag的方式判断 
								   
void BTreePrevOrderNonR(BTNode* root);//非递归前序遍历  
void BTreeInOrderNonR(BTNode* root);// 非递归中序遍历
void BTreePostOrderNonR(BTNode* root);//非递归后续遍历 

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