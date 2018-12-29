//#include "HuffmanTree.h"
//
//HuffmanTree::HuffmanTree(Process const_pro)
//{
//	process = const_pro;
//	vector<Node>::iterator left_ptr, right_ptr;
//
//	//哈夫曼树为左子树权值小于右子树权值
//	int i = 0;
//	vector<Node>::iterator it = process.wight_vector.begin();
//	while (it != process.wight_vector.end())
//	{
//		left_ptr = it;
//		right_ptr = ++it;
//		Node new_node;
//		if (right_ptr != process.wight_vector.end())
//		{
//			new_node.set_wight_percentage
//			(
//				left_ptr->get_wight_percentage() + right_ptr->get_wight_percentage()
//			);
//			new_node.set_wight(left_ptr->get_wight() + right_ptr->get_wight());
//			left_ptr->set_code(0);
//			right_ptr->set_code(1);
//			new_node.set_lchild(left_ptr);
//			new_node.set_rchild(right_ptr);
//			left_ptr->set_parent(new_node.get_self());
//			right_ptr->set_parent(new_node.get_self());
//		}
//		else
//		{
//			new_node.set_wight_percentage
//			(
//				left_ptr->get_wight_percentage() + 0
//			);
//			new_node.set_wight(left_ptr->get_wight() + 0);
//			left_ptr->set_code(0);
//			new_node.set_lchild(left_ptr);
//			left_ptr->set_parent(new_node.get_self());
//			process.wight_vector.push_back(new_node);
//
//			root_node = new_node.get_self();
//			break;
//		}
//		//it++;
//		process.wight_vector.push_back(new_node);
//		it = process.wight_vector.begin() + 2 * (++i);
//		sort(it, process.wight_vector.end());
//	}
//}
//
//void HuffmanTree::display_code(Node node)
//{
//	list<int> huffman_code;
//	Node *search_ptr;
//	search_ptr = node.get_parent();
//	while (search_ptr != root_node)
//	{
//		huffman_code.push_back(search_ptr->get_code());
//		search_ptr = search_ptr->get_parent();
//	}
//	cout << node.get_ch() << ":";
//	for (const auto temp : huffman_code)
//	{
//		cout << temp;
//	}
//	cout << endl;
//}
//
//void HuffmanTree::display_huffman_code()
//{
//	for (auto temp : process.wight_vector)
//	{
//		if (temp.get_ch())
//		display_code(temp);
//	}
//}
