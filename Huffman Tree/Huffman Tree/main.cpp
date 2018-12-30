#include "HuffmanTree.h"

int main(void)
{
	string str = "aaaaabbbbbcccccdddeee";
	cout << "typing the string:" << endl;
	//cin >> str;
	Process pro1(str);
	pro1.displayVector();
	HuffmanTree h(pro1);
	h.displayHuffmanCode();
	return 0;
}