#pragma once
typedef int ElemType;

typedef struct Node
{
	ElemType date;
	struct Node *link;
}LNode, *LinkList;

//1、创建链表
LinkList create(const int n);
//2、链表判空
int isEmpty(LinkList list);
//3、链表元素输出
void display(const LinkList list);
//4、查找元素x的位置
void search_location(const LinkList list, const ElemType e);
//5、查找第i个元素
void search_elem(const LinkList list, const int location);
//6、在第i个元素之后插入一个元素
void insert_elem_later(LinkList list, const int location);
//7、在第i个元素之前插入一个元素
LinkList insert_elem_front(LinkList list, const int location);
//8、删除值为ｘ的第一个元素
LinkList delete_elem(LinkList list, const ElemType e);
//9、销毁链表
LinkList drop_list(LinkList list);
//ps:链表元素总数
int total_num(LinkList);