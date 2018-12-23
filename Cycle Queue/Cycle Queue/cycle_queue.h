#pragma once

#define MAXSIZE 10
#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct Node
{
	ElemType storage[MAXSIZE];
	int top, rear;
	int total;
}CycleQueue;

//1.initialize cycle queue
void init_queue(CycleQueue & CQueue);
//2.cycle queue empty
bool is_emply_queue(CycleQueue CQueue);
//3.cycle queue full
bool is_full_queue(CycleQueue CQueue);
//4.come into the cycle queue
void push_cycle_queue(CycleQueue & CQueue, ElemType elem);
//5.get out of the cycle queue
void pop_cycle_queue(CycleQueue & CQueue);
