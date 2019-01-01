#include "HuffmanTree.h"


HuffmanTree::HuffmanTree(Process constPro)
{
	process = constPro;
	Ptr<TreeNode> ptrLChild;
	Ptr<TreeNode> ptrRChild;
	while (process.wightVector.getSize() != 1)
	{
		ptrLChild = process.wightVector.pop_front();
		if (ptrLChild->elem.getCh() != '\0')
			copiedWightVector.push_back(ptrLChild);
		ptrRChild = process.wightVector.pop_front();
		if (ptrRChild->elem.getCh() != '\0')
			copiedWightVector.push_back(ptrRChild);
		Ptr<TreeNode> ptrNew = new ListNode<TreeNode>;
		ptrNew->elem.ptrLChild = ptrLChild;
		ptrNew->elem.ptrRChild = ptrRChild;
		ptrNew->elem.setWight(ptrLChild->elem.getCode() + ptrRChild->elem.getCode());
		ptrLChild->elem.ptrParent = ptrNew;
		ptrRChild->elem.ptrParent = ptrNew;
		ptrLChild->elem.setCode(0);
		ptrRChild->elem.setCode(1);
		process.wightVector.push_back(ptrNew);
	}
	rootNode = process.wightVector.pop_front();
}

void HuffmanTree::displayCode(Ptr<TreeNode> ptrSearchNode)
{
	MyList<int> huffmanCode;
	Ptr<TreeNode> flagNode;
	flagNode = ptrSearchNode;
	while (flagNode != rootNode)
	{
		huffmanCode.push_back(flagNode->elem.getCode());
		flagNode = flagNode->elem.ptrParent;
	}
	huffmanCode.print_whole_list(REVERSE);
}

void HuffmanTree::displayHuffmanCode()
{
	while (copiedWightVector.getSize() != 0)
	{
		Ptr<TreeNode> flagNode = copiedWightVector.pop_front();
		cout << flagNode->elem.getCh() << ":";
		displayCode(flagNode);
		cout << endl;
	}
}
