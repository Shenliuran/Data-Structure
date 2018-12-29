#pragma once
#include "mylist.h"
using namespace std;

class TreeNode
{
private:
	char ch;
	int wight;
	int code;
protected:
	PtrNode<TreeNode> ptrLChild, ptrRChild;
	PtrNode<TreeNode> ptrParent;
public:
	TreeNode() { ch = '\0'; wight = 0; ptrParent = ptrLChild = ptrRChild = nullptr; code = 0; }
	void setCh(const char constCh) { ch = constCh; }
	void setWight(const int constWight) { wight = constWight; }
	void setWight() { wight++; }
	void getCode(const int constCode) { code = constCode; }
	char getCh() { return ch; }
	char getWight() { return wight; }
	int getCode() { return code; }
	bool operator <(TreeNode comparedNode)
	{
		if (wight < comparedNode.getWight())
			return true;
		else
			return false;
	}
	bool operator >(TreeNode comparedNode)
	{
		if (wight > comparedNode.getWight())
			return true;
		else
			return false;
	}
};

class Process
{
private:
	int size;
	string originStr;
protected:
	void generateWightVector();
	MyList<TreeNode> wightVector;
public:
	Process(const string constStr) { size = 0; originStr = constStr; }
	Process() {}
	int getSize() { return size; }
	string getOriginStr() { return originStr; }
	void displayVector();
};

class HuffmanTree
{
private:
	Node<TreeNode> root_node;
	TreeNode tree_node;
	Process process;
public:
	HuffmanTree(Process const_pro);
	void display_huffman_code();
	void display_code(const TreeNode search_node);

	void quick_sort(MyList<TreeNode> targe_list, MyList<TreeNode> it_middle);
};