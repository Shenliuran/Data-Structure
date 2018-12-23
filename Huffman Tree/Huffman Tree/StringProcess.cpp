#include "HuffmanTree.h"

void Process::sorted_wight_vector()
{
	Node alphabet[52];

	for (int i = 0; i < origin_str.size(); i++)
	{
		if (origin_str[i] >= 'A' && origin_str[i] <= 'Z')
		{
			alphabet[(int)origin_str[i] - 65].self_add_wight();
			alphabet[(int)origin_str[i] - 65].set_ch(origin_str[i]);
		}
		if (origin_str[i] >= 'a' && origin_str[i] <= 'z')
		{
			alphabet[(int)origin_str[i] - 97 + 26].self_add_wight();
			alphabet[(int)origin_str[i] - 97 + 26].set_ch(origin_str[i]);
		}
	}

	int i = 0;
	for (int index = 0; index < 52; index++)
	{
		if (alphabet[index].get_wight() != 0)
		{
			wight_vector.push_back(alphabet[index]);
		}
	}
	size = wight_vector.size();
	for (list<Node>::iterator it = wight_vector.begin(); it != wight_vector.end(); it++)
		it->set_wight_percentage(origin_str);
	//sort
	wight_vector.sort();
}


void Process::display_wight_vector()
{
	sorted_wight_vector();
	for (list<Node>::iterator it = wight_vector.begin(); it != wight_vector.end(); it++)
	{
		cout << it->get_ch() << ":" << it->get_wight() << endl;
	}
	cout << get_size() << endl;
}