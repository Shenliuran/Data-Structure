#include "HuffmanTree.h"

void Process::generateWightVector()
{
	TreeNode alphabet[52];

	for (int i = 0; i < originStr.size(); i++)
	{
		if (originStr[i] >= 'A' && originStr[i] <= 'Z')
		{
			alphabet[(int)originStr[i] - 65].setWight();
			alphabet[(int)originStr[i] - 65].setCh(originStr[i]);
		}
		if (originStr[i] >= 'a' && originStr[i] <= 'z')
		{
			alphabet[(int)originStr[i] - 97 + 26].setWight();
			alphabet[(int)originStr[i] - 97 + 26].setCh(originStr[i]);
		}
	}

	int i = 0;
	for (int index = 0; index < 52; index++)
	{
		if (alphabet[index].getWight() != 0)
		{
			wightVector.push_back(alphabet[index]);
		}
	}
	size = wightVector.getSize();
	wightVector.bubble_sort();
}

void Process::displayVector()
{
	for (int i = 1; i <= wightVector.getSize(); i++)
	{
		cout << wightVector[i].getCh() << ":" << wightVector[i].getWight() << endl;
	}
}