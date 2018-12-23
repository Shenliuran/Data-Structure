#include "tree.h"

int main(void)
{
	BT BTree = nullptr;
	int select;
	while (true)
	{
		cout <<
			"1.initialize binary tree\n"
			"2.preorder traversal\n"
			"3.inorder traversal\n"
			"4.postorder traversal\n"
			"5.search node\n"
			"6.the total number of leaf\n"
			"7.the total number of node\n"
			"8.the depth of one specific node"
			<< endl;
		cout << "please typing in the operation you want to try:" << endl;

		cin >> select;
		switch (select)
		{
		case 1:
			cout << "typing in the element sequence:" << endl;
			init_binary_tree(BTree);
			cout << "initializtion completed!!!" << endl;

			break;
		case 2:
			cout << "the result of preorder traversal is:" << endl;
			pre_traversal(BTree);
			cout << endl;
			break;
		case 3:
			cout << "the result of inorder traversal is:" << endl;
			in_traversal(BTree);
			cout << endl;
			break;
		case 4:
			cout << "the result of postorder traversal is:" << endl;
			post_traversal(BTree);
			cout << endl;
			break;
		case 5:
			cout << "typing the node's data want to search:" << endl;
			ElemType elem;
			cin >> elem;
			if (search_node(BTree, elem) != nullptr)
				cout << "this node is exist!!!" << endl;
			else
				cout << "this node is NOT exist!!!" << endl;
			break;
		case 6:
			cout << "the total number of binary tree's leaf is:" << total_num_of_leaf(BTree) << endl;
			break;
		case 7:
			cout << "the total number of binary tree's node is:" << total_num_of_node(BTree) << endl;
			break;
		case 8:
			cout << "typing the data" << endl;
			ElemType data;
			cin >> data;
			cout << "the depth of this node is:" << depth_of_node(BTree, data) << endl;
			break;
		default:
			return 0;
		}
	}
}