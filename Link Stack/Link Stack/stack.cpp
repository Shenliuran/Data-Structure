#include "stack.h"

//1.initialize stack
LinkStack init_stack(LinkStack list)
{
	list = (LinkStack) new SNode;
	list->link = nullptr;
	list->data = 0;
	return list;
}
//2.come into the stack
void push(LinkStack list, const ElemType elem)
{
	LinkStack p;
	p = (LinkStack) new SNode;
	p->data = elem;
	p->link = list->link;
	list->link = p;
	list->data++;
}
//3.get out of the stack
void pop(LinkStack list)
{
	if (list->link == nullptr)
		cout << "empty stack!" << endl;
	else
	{
		LinkStack p = list->link;
		cout << p->data;
		list->link = list->link->link;
		free(p);
	}
}