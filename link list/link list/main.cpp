#include "LinkList.h"

int main(void)
{
	ElemType *A = (ElemType *) new ElemType[MAXSIZE];;
	int n = 0;
	int k = 0;
	while (true)
	{
		cout << "****************************************" << endl;
		cout << "��ѡ����Ҫ���еĲ�����" << endl;
		cout << "1������һ�����Ա��������ݡ�" << endl;
		cout << "2���������ݡ�" << endl;
		cout << "3��ɾ�����ݡ�" << endl;
		cout << "4����ʾ�����������ݡ�" << endl;
		cout << "5�����ұ������ݡ�" << endl;
		cout << "****************************************" << endl;
		int select;
		cout << "��������Ҫ���еĲ����ţ�" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "��������Ҫ�����Ԫ�ظ�����" << endl;
			cin >> n;
			create(A, n);
			cout << "****************************************" << endl;
			break;
		case 2:
		temp: cout << "��������Ҫ�����λ�ã�" << endl;
			int insert_location;
			cin >> insert_location;
			cout << "��������Ҫ�����Ԫ�أ�" << endl;
			ElemType elem;
			cin >> elem;
			k = insert(A, n, insert_location, elem);
			if (!k)
				goto temp;
			cout << "****************************************" << endl;
			break;
		case 3:
			cout << "��������Ҫɾ����Ԫ�ص�λ�ã�" << endl;
			int delete_location;
			cin >> delete_location;
			delete_(A, n, delete_location);
			cout << "****************************************" << endl;
			break;
		case 4:
			display(A, n);
			cout << "****************************************" << endl;
			break;
		case 5:
			cout << "��������Ҫ���ҵ�Ԫ�ص�λ�ã�" << endl;
			int search_location;
			cin >> search_location;
			search_spot(A, n, search_location);
			cout << "****************************************" << endl;
			break;
		}
	}
	return 0;
}