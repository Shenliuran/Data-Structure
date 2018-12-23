#include "queue.h"

int main(void)
{
	QList queue = nullptr;
	int select = 0;
	while (true)
	{
		cout << "1.initialize a queue\n"
			"2.come into the queue\n"
			"3.get out of the queue\n"
			"choose a operattion you want to try:" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			init_queue(queue);
			cout << "initialize completed!" << endl;
			break;
		case 2:
			cout << "type in the element you want push into the queue:" << endl;
			ElemType elem;
			cin >> elem;
			push_queue(queue, elem);
			cout << "element number of current queue is:" << queue->data << endl;
			break;
		case 3:
			cout << "the top element of current queue is:" << endl;
			pop_queue(queue);
			cout << "element number of current queue is:" << endl;
			break;
		default:
			return 0;
		}
	}
}