#include "maze.h"

int main(void)
{
	while (true)
	{
		cout << "�������ͼ��ά�ȣ�" << endl;
		int maze_size;
		cin >> maze_size;
		cout << "�����벽����" << endl;
		int step_num;
		cin >> step_num;
		cout << "�Թ���������..." << endl;
		Maze maze1(maze_size, step_num);
		cout << "���ɽ����" << endl;
		maze1.display_maze();
		cout << "Ѱ�ҵ���·��Ϊ��" << endl;
		maze1.display_path();
	}
	return 0;
}