#pragma once
typedef int ElemType;

typedef struct Node
{
	ElemType date;
	struct Node *link;
}LNode, *LinkList;

//1����������
LinkList create(const int n);
//2�������п�
int isEmpty(LinkList list);
//3������Ԫ�����
void display(const LinkList list);
//4������Ԫ��x��λ��
void search_location(const LinkList list, const ElemType e);
//5�����ҵ�i��Ԫ��
void search_elem(const LinkList list, const int location);
//6���ڵ�i��Ԫ��֮�����һ��Ԫ��
void insert_elem_later(LinkList list, const int location);
//7���ڵ�i��Ԫ��֮ǰ����һ��Ԫ��
LinkList insert_elem_front(LinkList list, const int location);
//8��ɾ��ֵΪ���ĵ�һ��Ԫ��
LinkList delete_elem(LinkList list, const ElemType e);
//9����������
LinkList drop_list(LinkList list);
//ps:����Ԫ������
int total_num(LinkList);