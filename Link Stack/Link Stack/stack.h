#pragma once
#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node * link;
} *LinkStack, SNode;

//1.initialize stack
LinkStack init_stack(LinkStack list);
//2.come into the stack
void push(LinkStack list, const ElemType elem);
//3.get out of the stack
void pop(LinkStack list);