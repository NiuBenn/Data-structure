#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
#include"Queue.h"
#include"Stack.h"

BTNode* BuyBTNode(BTDataType x)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	assert(NewNode);
	NewNode->_data = x;
	NewNode->_left = NULL;
	NewNode->_right = NULL;
	return NewNode;
}

BTNode* CreateBTree(BTDataType* a, size_t* pIndex, BTDataType invalid)//创建二叉树
{
	assert(a);
	BTNode* root = NULL;
	while (a[*pIndex] != invalid)
	{
		root = BuyBTNode(a[*pIndex]);
		++(*pIndex);
		root->_left = CreateBTree(a, pIndex, invalid);
		++(*pIndex);
		root->_right = CreateBTree(a, pIndex, invalid);
	}
	return root;
}
void BTreePrevOrder(BTNode* root)//前序遍历
{
	if (root == NULL)
		return;
	printf("%d ", root->_data);
	BTreePrevOrder(root->_left);
	BTreePrevOrder(root->_right);
}



void BTreeInOrder(BTNode* root)//中序遍历
{
	if (root == NULL)
		return;
	BTreeInOrder(root->_left);
	printf("%d ", root->_data);
	BTreeInOrder(root->_right);
}
void BTreePostOrder(BTNode* root)//后序遍历
{
	if (root == NULL)
		return;
	BTreePostOrder(root->_left);
	BTreePostOrder(root->_right);
	printf("%d ", root->_data);
}
size_t BTreeSize(BTNode* root)//结点个数
{
	if (root == NULL)
		return 0;
	return BTreeSize(root->_left) + BTreeSize(root->_right) + 1;
}
size_t BTreeLeafSize(BTNode* root)//叶子结点个数
{
	if (root == 0)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BTreeLeafSize(root->_left) + BTreeLeafSize(root->_right);
}

size_t BTreeKLevelSize(BTNode* root, size_t k)//第K层结点个数
{
	if (root == 0)
		return 0;
	if (k == 1)
		return 1;
	return BTreeKLevelSize(root->_left, k - 1) + BTreeKLevelSize(root->_right, k - 1);
}

size_t BTreeDepth(BTNode* root)//深度
{
	if (root == 0)
		return 0;
	size_t LeftDepth = BTreeDepth(root->_left);
	size_t RightDepth = BTreeDepth(root->_right);
	return LeftDepth > RightDepth ? LeftDepth + 1 : RightDepth + 1;
}
BTNode* BTreeFind(BTNode* root, BTDataType x)//寻找结点
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* LeftNode = BTreeFind(root->_left, x);
	if (LeftNode->_data == x)
		return LeftNode;
	BTNode* RightNode = BTreeFind(root->_right, x);
	if (RightNode->_data == x)
		return RightNode;
	return NULL;
}

void BTreeLevelOrder(BTNode* root)//层序遍历
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (q._size!= 0)
	{
		BTNode* Front = QueueFront(&q);
		printf("%d", Front->_data);
		QueuePop(&q);
		if (Front->_left != NULL)
			QueuePush(&q, Front->_left);
		if (Front->_right != NULL)
			QueuePush(&q, Front->_right);
	}
	printf("\n");
}


int IsCompleteBTree(BTNode* root)// 判断完全二叉树 (0为是完全二叉树，1为非完全二叉树)
{
	Queue q;
	BTNode* Front;
	QueueInit(&q);
	if (root == NULL)
		return 0;
	QueuePush(&q, root);
	while (q._size)
	{
		Front = QueueFront(&q);
		QueuePop(&q);
		if (Front == NULL)
			break;
		QueuePush(&q, Front->_left);
		QueuePush(&q, Front->_right);
	}
	while (q._size)
	{
		Front = QueueFront(&q);
		if (Front != NULL)
		{
			return 1;
		}
		QueuePop(&q);
	}
	return 0;
}
int IsCompleteBTree1(BTNode* root) // flag的方式判断 
{
	int flag = 0;
	BTNode* Front;
	Queue q;
	QueueInit(&q);
	if (root == NULL)
		return 0;
	QueuePush(&q, root);
	while (q._size != 0)
	{
		Front = QueueFront(&q);
		QueuePop(&q);
		if (Front->_left)
		{
			if (flag == 1)
				return 1;
			QueuePush(&q, Front->_left);
		}
		else
		{
			flag = 1;
		}
		if (Front->_right)
		{
			if (flag == 1)
				return 1;
			QueuePush(&q, Front->_right);
		}
		else
		{
			flag = 1;
		}
	}
	return 0;
}
void BTreePrevOrderNonR(BTNode* root)//非递归前序遍历  
{
	assert(root);
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	BTNode* top = NULL;

	if (root == NULL)
		return;

	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			printf("%d ", cur->_data);
			StackPush(&s, cur);
			cur = cur->_left;
		}
		top = StackTop(&s);
		StackPop(&s);
		cur = top->_right;
	}
	printf("\n");

}
void BTreeInOrderNonR(BTNode* root)// 非递归中序遍历
{
	assert(root);
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	BTNode* top = NULL;

	if (root == NULL)
		return;

	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		top = StackTop(&s);
		printf("%d ", top->_data);
		StackPop(&s);
		cur = top->_right;
	}
	printf("\n");
}
void BTreePostOrderNonR(BTNode* root)//非递归后续遍历 
{
	assert(root);
	Stack s;
	StackInit(&s);
	BTNode* cur = root;
	BTNode* top = NULL;
	BTNode* prev = NULL;


	if (root == NULL)
		return;

	while (cur || StackEmpty(&s) != 0)
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		top = StackTop(&s);
		if (top->_right == NULL || top->_right == prev)
		{
			printf("%d ", top->_data);
			prev = top;
			StackPop(&s);
		}
		else
		{
			cur = top->_right;
		}
	}
	printf("\n");
}

int main()
{

	TestBinaryTree();
	system("pause");
	return 0;
}