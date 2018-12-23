#include "queue.h"

//1.initialize queue
void init_queue(QList & queue)
{
	queue = (QList) new QNode;
	queue->data = 0;
	queue->link = nullptr;
}
//2.come into the queue
void push_queue(QList & queue, ElemType elem)
{
	QList p, r;
	p = (QList) new QNode;
	p->data = elem;
	p->link = nullptr;
	if (queue->link == nullptr)
		queue->link = p;
	else
	{
		r = queue->link;
		while (r)
		{
			if (r->link == nullptr)
				r->link = p;
			r = r->link->link;
		}
	}
	queue->data++;
}
//3.get out of the queue
void pop_queue(QList & queue)
{
	QList p;
	p = queue->link;
	if (p == nullptr)
		cout << "this is an empty queue!" << endl;
	else
	{
		cout << p->data << endl;
		queue->link = p->link;
	}
	delete[] p;
	queue->data--;
}