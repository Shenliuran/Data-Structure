#pragma once
#pragma once

#define POSTIVE 1
#define REVERSE 2
#define DESC 1
#define ASC 2
#define PTR Ptr<ElemType>
#define PTRFIRST ptrHeadNode->ptrNext
#define SORT_POINTER_RESET	ptrNow = ptrHeadNode->ptrNext;\
							int i = 1;\
							while(i != nowNodeLocation)\
							{ptrNow = ptrNow->ptrNext;i++;}
#define TAIL_POINTER_REST	PTR ptrNewTail = PTRFIRST;\
							while (ptrNewTail->ptrNext != nullptr)\
							{ptrNewTail = ptrNewTail->ptrNext;}\
							ptrTail = ptrNewTail
#include<iostream>
using namespace std;
typedef int PrintStyle;
typedef int SortStype;
/**************************/
/**************************/
/**************************/
template<class ElemType>
class ListNode
{
public:
	ElemType elem;
public:
	template<class ElemType>
	using Ptr = ListNode<ElemType>*;
	PTR ptrFront, ptrNext;
	ListNode(const ElemType constElem) { elem = constElem; ptrFront = ptrNext = nullptr; }
	ListNode() { ptrFront = ptrNext = nullptr; }
	void setElem(const ElemType constElem) { elem = constElem; }
	ElemType getElem() { return elem; }
};
/***************************/
template<class ElemType>
using Ptr = ListNode<ElemType>*;
/***************************/
/***************************/
/***************************/
template<class ElemType>
class MyList
{
private:
	int size;
protected:
	PTR ptrHeadNode;
	PTR ptrTail;
	void swapNode(PTR &frontNode, PTR &backNode);
	void deleteNode(PTR &nowNode);
	void insertNode(PTR &newNodeFront, PTR&newNode);
public:
	MyList()
	{
		ptrHeadNode = new ListNode<ElemType>(ElemType());
		ptrHeadNode->ptrFront = ptrHeadNode;
		ptrHeadNode->ptrNext = ptrHeadNode;
		size = 0;
		ptrTail = ptrHeadNode;
	}
	int getSize() { return size; }
	void push_back(const ElemType newElem);
	void push_back(Ptr<ElemType> ptrNewNode);
	void push_front(const ElemType newElem);
	void push_front(Ptr<ElemType> ptrNewElem);
	Ptr<ElemType> pop_back();
	Ptr<ElemType> pop_front();
	ElemType operator [](const int index);//start from index = 1
	void print_whole_list(const PrintStyle style = POSTIVE);
	void bubble_sort(const SortStype stype = ASC);
	void qucik_sort(const SortStype stype = ASC);
	void deleteNodeByIndex(const int deletedIndex);
	void deleteNodeByElem(const ElemType deletedElem);
	void insertNodeByIndex(const int index, const ElemType insertedElem);
	void reverseList();
};
/***************************/
/***************************/
/***************************/
/***************************/
/***************************/
/***************************/
/***************************/
/***************************/
/***************************/
/***************************/
/***************************/
/***************************/
/***************************/
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::swapNode(PTR &frontNode, PTR &backNode)
{
	PTR ptrFrontNodeFront, ptrFrontNodeNext, ptrBackNodeFront, ptrBackNodeNext;
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
		PTR ptrBetween;
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
	PTR ptrNewNode = new ListNode<ElemType>(newElem);
	if (size == 0)
	{
		PTRFIRST = ptrNewNode;
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
void MyList<ElemType>::push_back(Ptr<ElemType> ptrNewNode)
{
	if (size == 0)
	{
		PTRFIRST = ptrNewNode;
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
	PTR ptrNewNode = new ListNode<ElemType>(newElem);
	if (size == 0)
	{
		PTRFIRST = ptrNewNode;
		ptrNewNode->ptrFront = ptrHeadNode;
		ptrTail = ptrNewNode;
	}
	else
	{
		PTR ptrOriginalFirstNode;
		ptrOriginalFirstNode = PTRFIRST;
		ptrNewNode->ptrNext = PTRFIRST;
		PTRFIRST = ptrNewNode;
		ptrOriginalFirstNode->ptrFront = ptrNewNode;
		ptrNewNode->ptrFront = ptrHeadNode;
	}
	size++;
}
template<class ElemType>
void MyList<ElemType>::push_front(Ptr<ElemType> ptrNewNode)
{
	if (size == 0)
	{
		PTRFIRST = ptrNewNode;
		ptrNewNode->ptrFront = ptrHeadNode;
		ptrTail = ptrNewNode;
	}
	else
	{
		PTR ptrOriginalFirstNode;
		ptrOriginalFirstNode = PTRFIRST;
		ptrNewNode->ptrNext = PTRFIRST;
		PTRFIRST = ptrNewNode;
		ptrOriginalFirstNode->ptrFront = ptrNewNode;
		ptrNewNode->ptrFront = ptrHeadNode;
	}
	size++;
}
template<class ElemType>
Ptr<ElemType> MyList<ElemType>::pop_back()
{
	PTR ptrDelete;
	if (size != 0)
	{
		ptrDelete = ptrTail;
		ptrTail = ptrDelete->ptrFront;
		ptrTail->ptrNext = nullptr;
		size--;
		return ptrDelete;
	}
	else
	{
		cout << "can not be functioned, because this is a empty list!!" << endl;
		return nullptr;
	}
}
template<class ElemType>
Ptr<ElemType> MyList<ElemType>::pop_front()
{
	if (size != 0)
	{
		PTR ptrDelete;
		ptrDelete = PTRFIRST;
		PTRFIRST = ptrDelete->ptrNext;
		size--;
		return ptrDelete;
	}
	else
	{
		cout << "can not be functioned, because this is a empty list!!" << endl;
		return nullptr;
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
		PTR ptrNow = PTRFIRST;
		while (i != index)
		{
			ptrNow = ptrNow->ptrNext;
			i++;
		}
		return ptrNow->getElem();
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::print_whole_list(const PrintStyle style)
{
	PTR ptrFlag;
	if (style == POSTIVE)
	{
		ptrFlag = PTRFIRST;
		if (ptrFlag == nullptr)
			cout << "can not ba functioned, because this is an empty list!!" << endl;
		else
		{
			while (ptrFlag)
			{
				cout << ptrFlag->getElem();
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
				cout << ptrFlag->getElem();
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
void list_copy(MyList<ElemType> originalList, MyList<ElemType> &targetList)
{
	for (int i = 1; i <= originalList.getSize(); i++)
	{
		targetList.push_back(originalList[i]);
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::deleteNode(PTR &nowNode)
{
	if (nowNode->ptrNext == nullptr)
	{
		ptrTail = nowNode->ptrFront;
		delete nowNode;
		ptrTail->ptrNext = nullptr;
	}
	else
	{
		PTR ptrNowFront = nowNode->ptrFront;
		PTR ptrNowNext = nowNode->ptrNext;
		ptrNowFront->ptrNext = ptrNowNext;
		ptrNowNext->ptrFront = ptrNowFront;
		delete nowNode;
	}
	size--;
}
template<class ElemType>
void MyList<ElemType>::deleteNodeByIndex(const int deletedIndex)
{
	if (deletedIndex < 1 || deletedIndex > size)
		cout << "crossing!!" << endl;
	else
	{
		PTR ptrNow = PTRFIRST;
		int i = 1;
		while (i != deletedIndex)
		{
			ptrNow = ptrNow->ptrNext;
			i++;
		}
		deleteNode(ptrNow);
	}
}
template<class ElemType>
void MyList<ElemType>::deleteNodeByElem(const ElemType deletedElem)
{
	PTR ptrNow = PTRFIRST;
	int record = 0;
	while (ptrNow != nullptr)
	{
		PTR ptrNowNext = ptrNow->ptrNext;
		if (deletedElem == ptrNow->getElem())
		{
			deleteNode(ptrNow);
			record++;
		}
		ptrNow = ptrNowNext;
	}
	if (record == 0)
		cout << "there is no such element!!" << endl;
	else
	{
		cout << "there is " << record << " elements you have deleted yet!!" << endl;
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::insertNode(PTR &newNodeFront, PTR &newNode)
{
	if (newNodeFront->ptrNext == nullptr)
	{
		newNodeFront->ptrNext = newNode;
		newNode->ptrFront = newNodeFront;
		ptrTail = newNode;
	}
	else
	{
		PTR newNodeNext = newNodeFront->ptrNext;
		newNodeFront->ptrNext = newNode;
		newNode->ptrFront = newNodeFront;
		newNodeNext->ptrFront = newNode;
		newNode->ptrNext = newNodeNext;
	}
	size++;

}
template<class ElemType>
void MyList<ElemType>::insertNodeByIndex(const int index, const ElemType insertedElem)
{
	int recordSize = size;
	if (index < 1 || index > recordSize + 1)
	{
		cout << "crossing!!" << endl;
	}
	else
	{
		PTR newNode = new ListNode<ElemType>(insertedElem);
		if (index == 1)
			insertNode(ptrHeadNode, newNode);
		else
		{
			PTR ptrNow = ptrHeadNode->ptrNext;
			int i = 2;
			while (i != index)
			{
				ptrNow = ptrNow->ptrNext;
				i++;
			}
			insertNode(ptrNow, newNode);
		}
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::reverseList()
{
	PTR ptrNow = PTRFIRST;
	PTR ptrOrigianlNext;
	PTR ptrMove;
	PTR ptrTailOriginalFront = ptrTail->ptrFront;
	ptrHeadNode->ptrNext = ptrTail;
	ptrOrigianlNext = ptrNow->ptrNext;
	ptrMove = ptrOrigianlNext->ptrNext;
	ptrTail->ptrFront = ptrHeadNode;
	ptrTail->ptrNext = ptrTailOriginalFront;
	ptrTail = ptrNow;
	ptrNow->ptrFront = ptrOrigianlNext;
	ptrOrigianlNext->ptrNext = ptrNow;
	ptrNow->ptrNext = nullptr;
	ptrNow = ptrOrigianlNext;
	ptrOrigianlNext = ptrMove;
	ptrOrigianlNext->ptrFront = ptrMove;
	ptrMove = ptrMove->ptrNext;
	while (ptrOrigianlNext != PTRFIRST)
	{
		ptrNow->ptrFront = ptrOrigianlNext;
		ptrOrigianlNext->ptrNext = ptrNow;
		ptrOrigianlNext->ptrFront = ptrMove;
		ptrNow = ptrOrigianlNext;
		ptrOrigianlNext = ptrMove;
		ptrMove = ptrMove->ptrNext;
	}
}

/******************************/
/******************************/
/******************************/
/******************************/
/******************************/
/******************************/
/******************************/
/******************************/
/******************************/
/******************************/
/******************************/
/******************************/
template<class ElemType>
void MyList<ElemType>::bubble_sort(const SortStype stype)
{
	Ptr<ElemType> ptrNow, ptrCompared;
	ptrNow = ptrHeadNode->ptrNext;
	int nowNodeLocation = 1;
	while (ptrNow)
	{
		ptrCompared = ptrNow->ptrNext;
		while (ptrCompared)
		{
			Ptr<ElemType> ptrComparedNext = ptrCompared->ptrNext;
			if (stype == ASC && ptrNow->getElem() > ptrCompared->getElem())
				swapNode(ptrNow, ptrCompared);
			else if (stype == DESC && ptrNow->getElem() < ptrCompared->getElem())
				swapNode(ptrNow, ptrCompared);
			ptrCompared = ptrComparedNext;
			SORT_POINTER_RESET;
		}
		SORT_POINTER_RESET;
		ptrNow = ptrNow->ptrNext;
		nowNodeLocation++;
	}
	TAIL_POINTER_REST;
}
/******************************/
/******************************/
/******************************/