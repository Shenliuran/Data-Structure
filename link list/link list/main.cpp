#include "LinkList.h"

int main(void)
{
	ElemType *A = (ElemType *) new ElemType[MAXSIZE];;
	int n = 0;
	int k = 0;
	while (true)
	{
		cout << "****************************************" << endl;
		cout << "请选择需要进行的操作：" << endl;
		cout << "1、创建一个线性表并输入数据。" << endl;
		cout << "2、插入数据。" << endl;
		cout << "3、删除数据。" << endl;
		cout << "4、显示表中所有数据。" << endl;
		cout << "5、查找表中数据。" << endl;
		cout << "****************************************" << endl;
		int select;
		cout << "请输入需要进行的操作号：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "请输入需要输入的元素个数：" << endl;
			cin >> n;
			create(A, n);
			cout << "****************************************" << endl;
			break;
		case 2:
		temp: cout << "请输入需要插入的位置：" << endl;
			int insert_location;
			cin >> insert_location;
			cout << "请输入需要插入的元素：" << endl;
			ElemType elem;
			cin >> elem;
			k = insert(A, n, insert_location, elem);
			if (!k)
				goto temp;
			cout << "****************************************" << endl;
			break;
		case 3:
			cout << "请输入需要删除的元素的位置：" << endl;
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
			cout << "请输入需要查找的元素的位置：" << endl;
			int search_location;
			cin >> search_location;
			search_spot(A, n, search_location);
			cout << "****************************************" << endl;
			break;
		}
	}
	return 0;
}