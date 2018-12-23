#include "LinkList.h"
#include<iostream>
using namespace std;

//1、创建链表
LinkList create(const int n)
{
	LinkList list = nullptr;
	LinkList p, r;
	for (int i = 1; i <= n; i++)
	{
		p = (LinkList) new LNode;
		if (list == nullptr)
		{
			cout << "请输入第1个元素：" << endl;
			list = p;
			cin >> p->date;
			p->link = nullptr;
			r = p;
		}
		else
		{
			cout << "请输入第" << i << "个元素：" << endl;
			cin >> p->date;
			p->link = nullptr;
			r->link = p;
			r = p;
			//r = r->link;
		}
	}
	return list;
}
//2、链表判空
int isEmpty(LinkList list)
{
	if (list == nullptr)
		return 1;
	else
		return 0;
}
//ps：链表元素个数
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
//3、链表元素输出
void display(const LinkList list)
{
	LinkList p;
	p = list;
	if (isEmpty(list))
		cout << "链表为空！" << endl;
	else
	{
		cout << "表中现在的元素为：" << endl;
		while (p)
		{
			cout << p->date << " ";
			p = p->link;
		}
		cout << endl;
	}
	cout << "元素总数为：" << total_num(list) << endl;
}
//4、查找元素x的位置
void search_location(const LinkList list, const ElemType e)
{
	LinkList p;
	p = list;
	int location = 1;
	while (p)
	{
		if (p->date == e)
		{
			cout << "需要查找的元素是第" << location << "个元素" << endl;
			break;
		}
		else
		{
			p = p->link;
			location++;
		}
	}
	if (p == nullptr)
		cout << "表中没有此元素！" << endl;
}
//5、查找第i个元素
void search_elem(const LinkList list, const int location)
{
	LinkList p;
	p = list;
	int count = 1;
	while (p)
	{
		if (count == location)
		{
			cout << "需要查找的元素是" << p->date << endl;
			break;
		}
		else
		{
			p = p->link;
			count++;
		}
	}
	if (p == nullptr)
		cout << "表中没有此元素！" << endl;
}
//6、在第i个元素之后插入一个元素
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
			cout << "请输入需要插入的元素的值:" << endl;
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
//7、在第i个元素之前插入一个元素
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
		cout << "请输入需要插入的元素：" << endl;
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
//8、删除值为ｘ的第一个元素
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
				cout << "无此元素！" << endl;
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
		cout << "链表为空！" << endl;
}
//9、销毁链表
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