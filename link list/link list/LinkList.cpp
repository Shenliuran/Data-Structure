#include "LinkList.h"

//判空
int isEmpty(int n)
{
	if (n == 0)
		return 1;
	else
		return 0;
}

//判满
int isFull(int n)
{
	if (MAXSIZE <= n)
		return 1;
	else
		return 0;
}
//创建线形表并输入
void create(ElemType A[], const int n)
{

	if (n)
	{
		if (n <= MAXSIZE)
		{
			//ElemType elem;
			cout << "请依次输入" << n << "个元素：" << endl;
			for (int i = 0; i < n; i++)
			{
				//cin >> elem;
				cin >> A[i];
			}
		}
		else
		{
			cout << "超出数组最大范围，请重新输入!" << endl;
		}
	}
}
//插入
int insert(ElemType A[], int &n, int i, ElemType e)
{
	if (!isFull(n))
	{
		if (i < 1 || i >(n + 1))
		{
			cout << "超出线性表范围！" << endl;
			return 0;
		}
		else if (i < n + 1)
		{
			for (int j = i - 1; j < n + 1; j++)
			{
				A[j + 1] = A[j];
			}
			A[i - 1] = e;
			n++;
			return 1;
		}
		else
		{
			A[n] = e;
			n++;
			return 1;
		}
	}
	else
	{
		cout << "线性表已满，请进行扩充！" << endl;
		char s;
		cout << "请选择是否要进行扩充？ " << endl;
		cin >> s;
		if (s == 'y')
			A = enlarge(A, n);
		return 0;
	}
}
//删除元素
void delete_(ElemType A[], int &n, int i)
{
	if (!isEmpty(n))
	{
		if (i < 1 || i > n)
			cout << "" << endl;
		else if (i < n)
		{
			for (int j = i - 1; j < n; j++)
			{
				A[j] = A[j + 1];
			}
			n--;
		}
		else
		{
			n--;
		}
	}
}
//显示表中数据
void display(const ElemType A[], const int n)
{
	if (!isEmpty(n))
	{
		for (int i = 0; i < n; i++)
		{
			cout << A[i] << " ";
		}
	}
}
//查找和定位
void search_spot(const ElemType A[], const int n, const int i)
{
	if (i < 1 || i > n)
	{
		cout << "超出查找范围！" << endl;
	}
	else
	{
		cout << "需要查找的元素是：" << A[i - 1] << endl;
	}
}
//线性表扩展
ElemType *enlarge(ElemType A[], const int n)
{
	ElemType * new_A = (ElemType *)new ElemType[2 * MAXSIZE];
	for (int i = 0; i < n; i++)
	{
		new_A[i] = A[i];
	}
	return new_A;
}