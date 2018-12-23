#include "STACK.h"

//1,init stack
subsequ_stack init_stack(subsequ_stack a)
{
	a->storage = (ElemType *) new ElemType[MAXSIZE];
	a->top = -1;
	return a;
}
//2,come into the stack
void push(subsequ_stack a, const ElemType elem)
{
	if (stack_full(a))
		cout << "stack full!" << endl;
	else
	{
		a->storage[++a->top] = elem;
	}
}
//3,get out of the stack
void pop(subsequ_stack a)
{
	if (a->top == -1)
		cout << "empty stack!" << endl;
	else
	{
		ElemType elem = a->storage[a->top--];
		cout << elem;
	}
}
//4,stack full
bool stack_full(subsequ_stack a)
{
	if (a->top == MAXSIZE)
		return true;
	else
		return false;
}