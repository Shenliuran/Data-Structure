#pragma once
#pragma once
#define POSTIVE 1
#define REVERSE 2
#define DESC 1
#define ASC 2
#define SORT_POINTER_RESET	ptrNow = ptrHeadNode->ptrNext;\
							int i = 1;\
							while(i != nowNodeLocation)\
							{ptrNow = ptrNow->ptrNext;i++;}
#include<iostream>
using namespace std;
typedef int PrintStyle;
typedef int SortStype;
/**************************/
/**************************/
/**************************/
template<class ElemType>
class Node
{
public:
	ElemType elem;
	template<class ElemType>
	using PtrInst = Node<ElemType>*;
	template<class ElemType>
	using PtrNode = Node<ElemType>*;
	PtrInst<ElemType> ptrFront, ptrNext;
	Node(const ElemType constElem) { elem = constElem; ptrFront = ptrNext = nullptr; }
	Node(){ ptrFront = ptrNext = nullptr; }
	bool operator !=(Node comparedNode)
	{
		if (elem != comparedNode.elem)
			return true;
		else
			return false;
	}
};
/***************************/
template<class ElemType>
using PtrInst = Node<ElemType>*;
template<class ElemType>
using PtrNode = Node<ElemType>*;
/***************************/
/***************************/
/***************************/
template<class ElemType>
class MyList
{
private:
	int size;
protected:
	PtrNode<ElemType> ptrHeadNode;
	PtrInst <ElemType> ptrTail;
	void swapNode(PtrNode<ElemType> &frontNode, PtrNode<ElemType> &backNode);
public:
	MyList()
	{
		ptrHeadNode = new Node<ElemType>(ElemType());
		ptrHeadNode->ptrFront = ptrHeadNode;
		ptrHeadNode->ptrNext = ptrHeadNode;
		size = 0;
		ptrTail = ptrHeadNode;
	}
	int getSize() { return size; }
	PtrInst<ElemType> getPtrFirst() { return ptrHeadNode->ptrNext; }
	void push_back(const ElemType newElem);
	void push_front(const ElemType newElem);
	ElemType pop_back();
	ElemType pop_front();
	ElemType operator [](const int index);//start from index = 1
	void print_whole_list(const PrintStyle style = POSTIVE);
	void bubble_sort(const SortStype stype = ASC);
	void qucik_sort(const SortStype stype = ASC);
	MyList<ElemType> copy(MyList<ElemType> origialList)
	{
		MyList<ElemType> newList;
		int i = 1;
		while (i != size)
		{
			newList.push_back(origialList[i]);
			i++;
		}
		return newList;
	}
};

template<class ElemType>
void MyList<ElemType>::swapNode(PtrNode<ElemType> &frontNode, PtrNode<ElemType> &backNode)
{
	PtrInst<ElemType> ptrFrontNodeFront, ptrFrontNodeNext, ptrBackNodeFront, ptrBackNodeNext;
	if (frontNode->ptrNext == backNode)
	{
		ptrFrontNodeFront = frontNode->ptrFront;
		ptrBackNodeNext = backNode->ptrNext;
		ptrFrontNodeFront->ptrNext = backNode;
		backNode->ptrFront = ptrFrontNodeFront;
		backNode->ptrNext = frontNode;
		frontNode->ptrNext = ptrBackNodeNext;
		frontNode->ptrFront = backNode;
		if (ptrBackNodeNext != nullptr)
		{
			ptrBackNodeNext->ptrFront = frontNode;
		}
	}
	else if (backNode == ptrTail && frontNode->ptrNext->ptrNext != backNode)
	{
		ptrFrontNodeFront = frontNode->ptrFront;
		ptrFrontNodeNext = frontNode->ptrNext;
		ptrBackNodeFront = backNode->ptrFront;
		ptrBackNodeNext = backNode->ptrNext;

		ptrFrontNodeFront->ptrNext = backNode;
		backNode->ptrFront = ptrFrontNodeFront;
		backNode->ptrNext = ptrFrontNodeNext;
		ptrFrontNodeNext->ptrFront = backNode;
		backNode->ptrNext = ptrFrontNodeNext;
		ptrBackNodeFront->ptrNext = frontNode;
		frontNode->ptrFront = ptrBackNodeFront;
		frontNode->ptrNext = ptrBackNodeNext;
	}
	else if (frontNode->ptrNext->ptrNext == backNode)
	{
		PtrInst<ElemType> ptrBetween;
		ptrBetween = frontNode->ptrNext;
		ptrFrontNodeFront = frontNode->ptrFront;
		ptrBackNodeNext = backNode->ptrNext;

		ptrBetween->ptrFront = backNode;
		ptrBetween->ptrNext = frontNode;
		ptrFrontNodeFront->ptrNext = backNode;
		backNode->ptrFront = ptrFrontNodeFront;
		backNode->ptrNext = ptrBetween;
		frontNode->ptrFront = ptrBetween;
		frontNode->ptrNext = ptrBackNodeNext;
		if (ptrBackNodeNext != nullptr)
			ptrBackNodeNext->ptrFront = frontNode;
	}
	else
	{
		ptrFrontNodeFront = frontNode->ptrFront;
		ptrFrontNodeNext = frontNode->ptrNext;
		ptrBackNodeFront = backNode->ptrFront;
		ptrBackNodeNext = backNode->ptrNext;

		ptrFrontNodeFront->ptrNext = backNode;
		backNode->ptrFront = ptrFrontNodeFront;
		backNode->ptrNext = ptrFrontNodeNext;
		ptrFrontNodeNext->ptrFront = backNode;

		ptrBackNodeFront->ptrNext = frontNode;
		frontNode->ptrFront = ptrBackNodeFront;
		frontNode->ptrNext = ptrBackNodeNext;
		if (ptrBackNodeNext != nullptr)
			ptrBackNodeNext->ptrFront = frontNode;
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::push_back(const ElemType newElem)
{
	PtrNode<ElemType> ptrNewNode = new Node<ElemType>(newElem);
	if (size == 0)
	{
		ptrHeadNode->ptrNext = ptrNewNode;
		ptrNewNode->ptrFront = ptrHeadNode;
		ptrTail = ptrNewNode;
	}
	else
	{
		ptrTail->ptrNext = ptrNewNode;
		ptrNewNode->ptrFront = ptrTail;
		ptrTail = ptrNewNode;
	}
	size++;
}
template<class ElemType>
void MyList<ElemType>::push_front(const ElemType newElem)
{
	PtrNode<ElemType> ptrNewNode = new Node<ElemType>(newElem);
	if (size == 0)
	{
		ptrHeadNode->ptrNext = ptrNewNode;
		ptrNewNode->ptrFront = ptrHeadNode;
		ptrTail = ptrNewNode;
	}
	else
	{
		PtrInst<ElemType> ptrOriginalFirstNode;
		ptrOriginalFirstNode = ptrHeadNode->ptrNext;
		ptrNewNode->ptrNext = ptrHeadNode->ptrNext;
		ptrHeadNode->ptrNext = ptrNewNode;
		ptrOriginalFirstNode->ptrFront = ptrNewNode;
		ptrNewNode->ptrFront = ptrHeadNode;
	}
	size++;
}
template<class ElemType>
ElemType MyList<ElemType>::pop_back()
{
	PtrInst<ElemType> ptrDelete;
	ElemType record;
	if (size != 0)
	{
		record = ptrTail->elem;
		ptrDelete = ptrTail;
		ptrTail = ptrDelete->ptrFront;
		delete ptrDelete;
		ptrTail->ptrNext = nullptr;
		size--;
		return record;
	}
	else
	{
		cout << "can not be functioned, because this is a empty list!!" << endl;
		return ElemType();
	}
}
template<class ElemType>
ElemType MyList<ElemType>::pop_front()
{
	if (size != 0)
	{
		PtrInst<ElemType> ptrDelete;
		ElemType record;
		ptrDelete = ptrHeadNode->ptrNext;
		record = ptrDelete->elem;
		ptrHeadNode->ptrNext = ptrDelete->ptrNext;
		delete ptrDelete;
		size--;
		return record;
	}
	else
	{
		cout << "can not be functioned, because this is a empty list!!" << endl;
		return ElemType();
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
ElemType MyList<ElemType>::operator [](const int index)
{
	if (index > size || index < 1)
	{
		cout << "crossing!!" << endl;
		return ElemType();
	}
	else
	{
		int i = 1;
		PtrInst<ElemType> ptrNow = ptrHeadNode->ptrNext;
		while (i != index)
		{
			ptrNow = ptrNow->ptrNext;
			i++;
		}
		return ptrNow->elem;
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::print_whole_list(const PrintStyle style)
{
	PtrInst<ElemType> ptrFlag;
	if (style == POSTIVE)
	{
		ptrFlag = ptrHeadNode->ptrNext;
		if (ptrFlag == nullptr)
			cout << "can not ba functioned, because this is an empty list!!" << endl;
		else
		{
			while (ptrFlag)
			{
				cout << ptrFlag->elem;
				if (ptrFlag == nullptr)
					cout << endl;
				ptrFlag = ptrFlag->ptrNext;
			}
			cout << endl;
		}
	}
	else
	{
		ptrFlag = ptrTail;
		if (ptrFlag == nullptr)
			cout << "can not ba functioned, because this is an empty list!!" << endl;
		else
		{
			while (ptrFlag != ptrHeadNode)
			{
				cout << ptrFlag->elem;
				if (ptrFlag == ptrHeadNode)
					cout << endl;
				ptrFlag = ptrFlag->ptrFront;
			}
			cout << endl;
		}
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::bubble_sort(const SortStype stype)
{
	PtrInst<ElemType> ptrNow, ptrCompared;
	ptrNow = ptrHeadNode->ptrNext;
	int nowNodeLocation = 1;
	while (ptrNow)
	{
		ptrCompared = ptrNow->ptrNext;
		while (ptrCompared)
		{
			PtrInst<ElemType> ptrComparedNext = ptrCompared->ptrNext;
			if (stype == ASC && ptrNow->elem > ptrCompared->elem)
				swapNode(ptrNow, ptrCompared);
			else if (stype == DESC && ptrNow->elem < ptrCompared->elem)
				swapNode(ptrNow, ptrCompared);
			ptrCompared = ptrComparedNext;
			SORT_POINTER_RESET;
		}
		SORT_POINTER_RESET;
		ptrNow = ptrNow->ptrNext;
		nowNodeLocation++;
	}
	int i = 1;
	PtrInst<ElemType> ptrNowTail = ptrHeadNode->ptrNext;
	while (i != size)
	{
		ptrNowTail = ptrNowTail->ptrNext;
		i++;
	}
	ptrTail = ptrNowTail;
}