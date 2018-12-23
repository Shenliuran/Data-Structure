#include "LinkList.h"

//�п�
int isEmpty(int n)
{
	if (n == 0)
		return 1;
	else
		return 0;
}

//����
int isFull(int n)
{
	if (MAXSIZE <= n)
		return 1;
	else
		return 0;
}
//�������α�����
void create(ElemType A[], const int n)
{

	if (n)
	{
		if (n <= MAXSIZE)
		{
			//ElemType elem;
			cout << "����������" << n << "��Ԫ�أ�" << endl;
			for (int i = 0; i < n; i++)
			{
				//cin >> elem;
				cin >> A[i];
			}
		}
		else
		{
			cout << "�����������Χ������������!" << endl;
		}
	}
}
//����
int insert(ElemType A[], int &n, int i, ElemType e)
{
	if (!isFull(n))
	{
		if (i < 1 || i >(n + 1))
		{
			cout << "�������Ա�Χ��" << endl;
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
		cout << "���Ա���������������䣡" << endl;
		char s;
		cout << "��ѡ���Ƿ�Ҫ�������䣿 " << endl;
		cin >> s;
		if (s == 'y')
			A = enlarge(A, n);
		return 0;
	}
}
//ɾ��Ԫ��
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
//��ʾ��������
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
//���ҺͶ�λ
void search_spot(const ElemType A[], const int n, const int i)
{
	if (i < 1 || i > n)
	{
		cout << "�������ҷ�Χ��" << endl;
	}
	else
	{
		cout << "��Ҫ���ҵ�Ԫ���ǣ�" << A[i - 1] << endl;
	}
}
//���Ա���չ
ElemType *enlarge(ElemType A[], const int n)
{
	ElemType * new_A = (ElemType *)new ElemType[2 * MAXSIZE];
	for (int i = 0; i < n; i++)
	{
		new_A[i] = A[i];
	}
	return new_A;
}