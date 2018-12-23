#include "LinkList.h"
#include<iostream>
using namespace std;
int main(void)
{
	LinkList list = nullptr;
	int n;
	int select;
	while (true)
	{
		cout << "1、创建链表并输入数据" << endl;
		cout << "2、查找链表中元素X的位置" << endl;
		cout << "3、查找第i个元素" << endl;
		cout << "4、在第i个元素之后插入一个元素" << endl;
		cout << "5、在第i个元素之前插入一个元素" << endl;
		cout << "6、删除值为ｘ的第一个元素" << endl;
		cout << "7、销毁链表" << endl;
		cout << "8、链表输出" << endl;
		cout << "9、退出" << endl;
		cout << "请输入需要进行的操作号：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "请输入需要创建的链表的大小：" << endl;
			cin >> n;
			list = create(n);
			cout << endl;
			break;
		case 2:
			cout << "请输入需要查找的元素：" << endl;
			ElemType e_search;
			cin >> e_search;
			search_location(list, e_search);
			cout << endl;
			break;
		case 3:
			cout << "请输入需要查找的元素的下标：" << endl;
			int location_search;
			cin >> location_search;
			search_elem(list, location_search);
			cout << endl;
			break;
		case 4:
			cout << "请输入需要插入的位置：" << endl;
			int location_insert_later;
			cin >> location_insert_later;
			insert_elem_later(list, location_insert_later);
			cout << endl;
			break;
		case 5:
			cout << "请输入需要插入的位置：" << endl;
			int location_insert_front;
			cin >> location_insert_front;
			list = insert_elem_front(list, location_insert_front);
			break;
		case 6:
			cout << "请输入需要删除的值：" << endl;
			ElemType e_delete;
			cin >> e_delete;
			list = delete_elem(list, e_delete);
			cout << endl;
			break;
		case 7:
			list = drop_list(list);
			cout << endl;
			break;
		case 8:
			display(list);
			cout << endl;
			break;
		default:
			return 0;
		}
	}
}