#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(Process constPro)
{
	process = constPro;
	PtrInst<TreeNode> ptrLeft, ptrRight;
	copiedWightVector = process.wightVector.copy(process.wightVector);
	//哈夫曼树为左子树权值小于右子树权值
	while (constPro.wightVector.getSize() != 1)
	{
		ptrLeft = constPro.wightVector.getPtrFirst();
		constPro.wightVector.pop_front();
		ptrRight = constPro.wightVector.getPtrFirst();
		constPro.wightVector.pop_front();
		PtrInst<TreeNode> NewNode = new Node<TreeNode>;
		NewNode->elem.ptrLChild = &ptrLeft->elem;
		NewNode->elem.ptrRChild = &ptrRight->elem;
		ptrLeft->elem.ptrParent = &NewNode->elem;
		ptrRight->elem.ptrRChild = &NewNode->elem;
		ptrLeft->elem.setCode(0);
		ptrRight->elem.setCode(1);
		constPro.wightVector.push_back(NewNode->elem);
		constPro.wightVector.bubble_sort();
	}
	rootNode = *constPro.wightVector.getPtrFirst();
}

void HuffmanTree::displayCode(TreeNode searchNode)
{
	MyList<int> huffmanCode;
	Node<TreeNode> flagNode;
	flagNode.elem = searchNode;
	while (flagNode != rootNode)
	{
		huffmanCode.push_front(flagNode.elem.getCode());
		flagNode.elem = *searchNode.ptrParent;
	}
	huffmanCode.print_whole_list(REVERSE);
}

void HuffmanTree::displayHuffmanCode()
{
	while (copiedWightVector.getSize() != 0)
	{
		TreeNode flagNode = copiedWightVector.pop_front();
		cout << flagNode.getCh() << ":";
		displayCode(flagNode);
		cout << endl;
	}
}
