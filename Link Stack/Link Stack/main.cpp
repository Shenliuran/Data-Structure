#include "stack.h"
int main(void)
{
	LinkStack list = nullptr;
	int select;
	while (true)
	{
		cout << "1.初始化链栈" << endl;
		cout << "2.元素进栈" << endl;
		cout << "3.元素出栈" << endl;
		cout << "请输入需要进行的操作：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			list = init_stack(list);
			cout << endl;
			break;
		case 2:
			cout << "请输入需要进栈的元素：" << endl;
			ElemType elem;
			cin >> elem;
			push(list, elem);
			cout << endl;
			break;
		case 3:
			cout << "目前的栈顶元素是：" << endl;
			pop(list);
			cout << endl;
			break;
		default:
			return 0;
		}
	}
}