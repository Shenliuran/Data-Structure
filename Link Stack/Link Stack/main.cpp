#include "stack.h"
int main(void)
{
	LinkStack list = nullptr;
	int select;
	while (true)
	{
		cout << "1.��ʼ����ջ" << endl;
		cout << "2.Ԫ�ؽ�ջ" << endl;
		cout << "3.Ԫ�س�ջ" << endl;
		cout << "��������Ҫ���еĲ�����" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			list = init_stack(list);
			cout << endl;
			break;
		case 2:
			cout << "��������Ҫ��ջ��Ԫ�أ�" << endl;
			ElemType elem;
			cin >> elem;
			push(list, elem);
			cout << endl;
			break;
		case 3:
			cout << "Ŀǰ��ջ��Ԫ���ǣ�" << endl;
			pop(list);
			cout << endl;
			break;
		default:
			return 0;
		}
	}
}