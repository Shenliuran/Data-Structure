#pragma once
#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct Node
{
	ElemType elem;
	struct Node * lchild, *rchild;
}BTNode, *BT;

//1.create a binary tree
void init_binary_tree(BT & BTree);
//2.preorder traversal
void pre_traversal(BT BTree);
//3.inorder traversal
void in_traversal(BT BTree);
//4.postorder traversal
void post_traversal(BT BTree);
//5.search node
BT search_node(BT BTree, const ElemType x);
//6.the total number of leaf
int total_num_of_leaf(BT BTree);
//7.the total number of node
int total_num_of_node(BT BTree);
//8.the depth of one specific node
int depth_of_node(BT BTree, const ElemType x);
