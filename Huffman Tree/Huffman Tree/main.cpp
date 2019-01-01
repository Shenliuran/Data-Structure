#include "HuffmanTree.h"
#include<string>
int main(void)
{
	while (true)
	{
		string str;
		cout << "typing the string:" << endl;
		cin >> str;
		Process pro1(str);
		pro1.displayVector();
		cout << endl;
		HuffmanTree h(pro1);
		h.displayHuffmanCode();
	}
	return 0;
}