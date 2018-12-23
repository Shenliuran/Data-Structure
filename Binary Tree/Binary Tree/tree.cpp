#include "tree.h"

//1.create a binary tree
void init_binary_tree(BT & BTree)
{
	ElemType e;
	cin >> e;
	if (e == '#')
		BTree = nullptr;
	else
	{
		BTree = new BTNode;
		BTree->elem = e;
		init_binary_tree(BTree->lchild);
		init_binary_tree(BTree->rchild);
	}
}
//2.preorder traversal
void pre_traversal(BT BTree)
{
	if (BTree != nullptr)
	{
		cout << BTree->elem;
		pre_traversal(BTree->lchild);
		pre_traversal(BTree->rchild);
	}
}
//3.inorder traversal
void in_traversal(BT BTree)
{
	if (BTree != nullptr)
	{
		in_traversal(BTree->lchild);
		cout << BTree->elem;
		in_traversal(BTree->rchild);
	}
}
//4.postorder traversal
void post_traversal(BT BTree)
{
	if (BTree != nullptr)
	{
		post_traversal(BTree->lchild);
		post_traversal(BTree->rchild);
		cout << BTree->elem;
	}
}
//5.search node
BT search_node(BT BTree, const ElemType x)
{
	if (BTree != nullptr)
	{
		if (BTree->elem == x)
			return BTree;
		else
		{
			BT left, right;
			left = search_node(BTree->lchild, x);
			if (left != nullptr)
				return search_node(BTree->lchild, x);
			else
				return search_node(BTree->rchild, x);
		}
	}
	else
		return nullptr;
}
//6.the total number of leaf
int total_num_of_leaf(BT BTree)
{
	if (BTree != nullptr)
	{
		if (BTree->lchild == nullptr && BTree->rchild == nullptr)
			return 1;
		else
			return total_num_of_leaf(BTree->lchild) + total_num_of_leaf(BTree->rchild);
	}
	else
		return 0;
}
//7.the total number of node
int total_num_of_node(BT BTree)
{
	if (BTree != nullptr)
		return 1 + total_num_of_node(BTree->lchild) + total_num_of_node(BTree->rchild);
	else
		return 0;
}
//8.the deepth of one specific node
int depth_of_node(BT BTree, const ElemType x)
{
	int lchilddepth, rchilddepth;
	if (BTree == nullptr)
		return -1;
	if (BTree->elem == x)
		return 0;
	else
	{
		lchilddepth = depth_of_node(BTree->lchild, x);
		rchilddepth = depth_of_node(BTree->rchild, x);
		return lchilddepth > rchilddepth ? (lchilddepth + 1) : (rchilddepth + 1);
	}
}