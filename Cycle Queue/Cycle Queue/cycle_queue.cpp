#include "cycle_queue.h"

//1.initialize cycle queue
void init_queue(CycleQueue & CQueue)
{
	CQueue.top = -1;
	CQueue.rear = -1;
	CQueue.total = 0;
}
//2.cycle queue empty
bool is_emply_queue(CycleQueue CQueue)
{
	if (CQueue.top == CQueue.rear)
		return true;
	else
		return false;
}
//3.cycle queue full
bool is_full_queue(CycleQueue CQueue)
{
	if ((CQueue.rear + 1) % MAXSIZE == CQueue.top)
		return true;
	else
		return false;
}
//4.come into the cycle queue
void push_cycle_queue(CycleQueue & CQueue, ElemType elem)
{
	if (is_emply_queue(CQueue))
	{
		CQueue.storage[++CQueue.rear] = elem;
		CQueue.total++;
	}
	else if (is_full_queue(CQueue))
	{
		cout << "cycle queue is full!!!" << endl;
	}
	else
	{
		CQueue.storage[++CQueue.rear] = elem;
		CQueue.total++;
	}
}
//5.get out of the cycle queue
void pop_cycle_queue(CycleQueue & CQueue)
{
	if (is_emply_queue(CQueue))
		cout << "this is a emply queue!!!" << endl;
	else
	{
		cout << "the top elem of current cycle queue is:" << endl;
		cout << CQueue.storage[++CQueue.top] << endl;
		CQueue.total--;
	}
}