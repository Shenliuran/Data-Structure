#include "LinkList.h"
#include<iostream>
using namespace std;

//1����������
LinkList create(const int n)
{
	LinkList list = nullptr;
	LinkList p, r;
	for (int i = 1; i <= n; i++)
	{
		p = (LinkList) new LNode;
		if (list == nullptr)
		{
			cout << "�������1��Ԫ�أ�" << endl;
			list = p;
			cin >> p->date;
			p->link = nullptr;
			r = p;
		}
		else
		{
			cout << "�������" << i << "��Ԫ�أ�" << endl;
			cin >> p->date;
			p->link = nullptr;
			r->link = p;
			r = p;
			//r = r->link;
		}
	}
	return list;
}
//2�������п�
int isEmpty(LinkList list)
{
	if (list == nullptr)
		return 1;
	else
		return 0;
}
//ps������Ԫ�ظ���
int total_num(LinkList list)
{
	LinkList p;
	p = list;
	int count = 0;
	while (p)
	{
		count++;
		p = p->link;
	}
	return count;
}
//3������Ԫ�����
void display(const LinkList list)
{
	LinkList p;
	p = list;
	if (isEmpty(list))
		cout << "����Ϊ�գ�" << endl;
	else
	{
		cout << "�������ڵ�Ԫ��Ϊ��" << endl;
		while (p)
		{
			cout << p->date << " ";
			p = p->link;
		}
		cout << endl;
	}
	cout << "Ԫ������Ϊ��" << total_num(list) << endl;
}
//4������Ԫ��x��λ��
void search_location(const LinkList list, const ElemType e)
{
	LinkList p;
	p = list;
	int location = 1;
	while (p)
	{
		if (p->date == e)
		{
			cout << "��Ҫ���ҵ�Ԫ���ǵ�" << location << "��Ԫ��" << endl;
			break;
		}
		else
		{
			p = p->link;
			location++;
		}
	}
	if (p == nullptr)
		cout << "����û�д�Ԫ�أ�" << endl;
}
//5�����ҵ�i��Ԫ��
void search_elem(const LinkList list, const int location)
{
	LinkList p;
	p = list;
	int count = 1;
	while (p)
	{
		if (count == location)
		{
			cout << "��Ҫ���ҵ�Ԫ����" << p->date << endl;
			break;
		}
		else
		{
			p = p->link;
			count++;
		}
	}
	if (p == nullptr)
		cout << "����û�д�Ԫ�أ�" << endl;
}
//6���ڵ�i��Ԫ��֮�����һ��Ԫ��
void insert_elem_later(LinkList list, const int location)
{
	LinkList p, r, q;
	p = list;
	int count = 1;
	while (p)
	{
		if (count == location)
		{
			q = (LinkList) new LNode;
			cout << "��������Ҫ�����Ԫ�ص�ֵ:" << endl;
			cin >> q->date;
			r = p->link;
			q->link = r;
			p->link = q;
			break;
		}
		else
		{
			p = p->link;
			count++;
		}
	}
}
//7���ڵ�i��Ԫ��֮ǰ����һ��Ԫ��
LinkList insert_elem_front(LinkList list, const int location)
{
	LinkList l, p, q;
	l = list;
	q = l->link;
	int count = 1;
	if (isEmpty(list))
	{
		cin >> list->date;
	}
	else
	{
		cout << "��������Ҫ�����Ԫ�أ�" << endl;
		p = (LinkList) new LNode;
		cin >> p->date;
		p->link = nullptr;
		if (location == 1)
		{
			p->link = list;
			list = p;
			return list;
		}
		while (q)
		{
			if (count == location)
			{
				l->link = p;
				p->link = q;
				return list;
			}
			else
			{
				l = l->link;
				q = q->link;
				count++;
			}
		}
	}
}
//8��ɾ��ֵΪ���ĵ�һ��Ԫ��
LinkList delete_elem(LinkList list, const ElemType e)
{
	LinkList p, r;
	r = list;
	p = list->link;
	if (!isEmpty(list))
	{
		if (list->link == nullptr)
		{
			if (list->date == e)
			{
				free(list);
				return nullptr;
			}
			else
				cout << "�޴�Ԫ�أ�" << endl;
		}
		else
		{
			while (p)
			{
				if (p->date == e)
				{
					r->link = p->link;
					free(p);
					return list;
				}
				else
				{
					r = r->link;
					p = p->link;
				}

			}
		}
	}
	else
		cout << "����Ϊ�գ�" << endl;
}
//9����������
LinkList drop_list(LinkList list)
{
	LinkList p;
	p = list;
	if (!isEmpty(list))
	{
		while (p)
		{
			list = p->link;
			free(p);
			p = list;
		}
	}

	return list;
}