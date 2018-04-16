#pragma once

typedef int DataType;

typedef struct ComplexListNode
{
	int _data;
	struct ComplexListNode* _next;
	struct ComplexListNode* _random;
}ComplexListNode;

ComplexListNode* BuySListNode(DataType x);
ComplexListNode* CopyComplexList(ComplexListNode* list);