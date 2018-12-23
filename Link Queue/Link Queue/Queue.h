#pragma once
#pragma once
#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node * link;
} *QList, QNode;

//1.initialize queue
void init_queue(QList & queue);
//2.come into the queue
void push_queue(QList & queue, ElemType elem);
//3.get out of the queue
void pop_queue(QList & queue);