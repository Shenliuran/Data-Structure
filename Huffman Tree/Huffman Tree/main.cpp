#include "HuffmanTree.h"

int main(void)
{
	string str = "aaaaabbbbbcccccdddeee";
	cout << "typing the string:" << endl;
	//cin >> str;
	Process pro1(str);
	pro1.display_wight_vector();
	HuffmanTree h1(pro1);
	//h1.create_huffman_tree();
	//pro1.display_wight_vector();
	h1.display_huffman_code();
	return 0;
}