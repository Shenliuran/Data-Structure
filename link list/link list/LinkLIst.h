#pragma once

#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef int ElemType;
extern int n;

//�п�
int isEmpty(int n);
//����
int isFull(int n);

//�������α�����
void create(ElemType A[], const int n);
//����
int insert(ElemType A[], int &n, int i, ElemType e);
//ɾ��Ԫ��
void delete_(ElemType A[], int &n, int i);
//��ʾ��������
void display(const ElemType A[], const int n);
//���ҺͶ�λ
void search_spot(const ElemType A[], const int n, const int i);
//���α���չ
ElemType * enlarge(ElemType A[], const int n);