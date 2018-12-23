#include "cycle_queue.h"

int main(void)
{
	CycleQueue CQueue;
	int select = 0;
	while (true)
	{
		cout << "1.initialize cycle queue\n"
			"2.come into the cycle queue\n"
			"3.get out of the cycle queue\n"
			"choose an operation you want to try:" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			init_queue(CQueue);
			cout << "initialize completed!!!" << endl;
			break;
		case 2:
			ElemType elem;
			cout << "type in the elem you want to push into the cycle queue:" << endl;
			cin >> elem;
			push_cycle_queue(CQueue, elem);
			break;
		case 3:
			pop_cycle_queue(CQueue);
			break;
		default:
			return 0;
		}
	}
}