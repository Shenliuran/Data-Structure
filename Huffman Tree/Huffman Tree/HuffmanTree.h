#pragma once
#include "mylist.h"
#include<vector>
using namespace std;

class TreeNode
{
private:
	char ch;
	int wight;
	int code;
	int key;
public:
	Ptr<TreeNode> ptrLChild;
	Ptr<TreeNode>ptrRChild;
	Ptr<TreeNode> ptrParent;
	TreeNode() { ch = '\0'; wight = 0; ptrParent = ptrLChild = ptrRChild = nullptr; code = 0; key = 0; }
	void setCh(const char constCh) { ch = constCh; }
	void setKey(const int constKey) { key = constKey; }
	void setWight(const int constWight) { wight = constWight; }
	void setWight() { wight++; }
	void setCode(const int constCode) { code = constCode; }
	char getCh() { return ch; }
	int getWight() { return wight; }
	int getCode() { return code; }
	int getKey() { return key; }
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
	bool operator !=(TreeNode comparedNode)
	{
		if (key != comparedNode.getKey())
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
public:
	MyList<TreeNode> wightVector;
	Process(const string constStr) { size = 0; originStr = constStr; }
	Process() {}
	int getSize() { return size; }
	string getOriginStr() { return originStr; }
	void displayVector();
};

class HuffmanTree
{
private:
	Ptr<TreeNode> rootNode;
	Process process;
protected:
	void displayCode(Ptr<TreeNode> ptrSearchNode);
	MyList<TreeNode> copiedWightVector;
public:
	HuffmanTree(Process constPro);
	void displayHuffmanCode();
};