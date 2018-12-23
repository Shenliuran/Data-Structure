#pragma once

#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef int ElemType;
extern int n;

//判空
int isEmpty(int n);
//判满
int isFull(int n);

//创建线形表并输入
void create(ElemType A[], const int n);
//插入
int insert(ElemType A[], int &n, int i, ElemType e);
//删除元素
void delete_(ElemType A[], int &n, int i);
//显示表中数据
void display(const ElemType A[], const int n);
//查找和定位
void search_spot(const ElemType A[], const int n, const int i);
//线形表扩展
ElemType * enlarge(ElemType A[], const int n);