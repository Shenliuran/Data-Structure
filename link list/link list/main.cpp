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
		cout << "1������������������" << endl;
		cout << "2������������Ԫ��X��λ��" << endl;
		cout << "3�����ҵ�i��Ԫ��" << endl;
		cout << "4���ڵ�i��Ԫ��֮�����һ��Ԫ��" << endl;
		cout << "5���ڵ�i��Ԫ��֮ǰ����һ��Ԫ��" << endl;
		cout << "6��ɾ��ֵΪ���ĵ�һ��Ԫ��" << endl;
		cout << "7����������" << endl;
		cout << "8���������" << endl;
		cout << "9���˳�" << endl;
		cout << "��������Ҫ���еĲ����ţ�" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "��������Ҫ����������Ĵ�С��" << endl;
			cin >> n;
			list = create(n);
			cout << endl;
			break;
		case 2:
			cout << "��������Ҫ���ҵ�Ԫ�أ�" << endl;
			ElemType e_search;
			cin >> e_search;
			search_location(list, e_search);
			cout << endl;
			break;
		case 3:
			cout << "��������Ҫ���ҵ�Ԫ�ص��±꣺" << endl;
			int location_search;
			cin >> location_search;
			search_elem(list, location_search);
			cout << endl;
			break;
		case 4:
			cout << "��������Ҫ�����λ�ã�" << endl;
			int location_insert_later;
			cin >> location_insert_later;
			insert_elem_later(list, location_insert_later);
			cout << endl;
			break;
		case 5:
			cout << "��������Ҫ�����λ�ã�" << endl;
			int location_insert_front;
			cin >> location_insert_front;
			list = insert_elem_front(list, location_insert_front);
			break;
		case 6:
			cout << "��������Ҫɾ����ֵ��" << endl;
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