#include "STACK.h"

int main(void)
{
	subsequ_stack stack = (subsequ_stack) new Stack;
	int select;
	ElemType elem;
	while (true)
	{
		cout << "1.initialize the stack" << endl;
		cout << "2.come into the stack" << endl;
		cout << "3.get out of the stack" << endl;
		cout << "please select a operation you want to do:" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			stack = init_stack(stack);
			cout << endl;
			break;
		case 2:
			cout << "please type an elemet you want to push into the stack:" << endl;
			cin >> elem;
			push(stack, elem);
			cout << endl;
			break;
		case 3:
			cout << "the top elemet of current stact is:" << endl;
			pop(stack);
			cout << endl;
			break;
		default:
			return 0;
		}
	}
}