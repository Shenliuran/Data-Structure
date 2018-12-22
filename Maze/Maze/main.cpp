#include "maze.h"

int main(void)
{
	while (true)
	{
		cout << "请输入地图的维度：" << endl;
		int maze_size;
		cin >> maze_size;
		cout << "请输入步数：" << endl;
		int step_num;
		cin >> step_num;
		cout << "迷宫正在生成..." << endl;
		Maze maze1(maze_size, step_num);
		cout << "生成结果：" << endl;
		maze1.display_maze();
		cout << "寻找到的路径为：" << endl;
		maze1.display_path();
	}
	return 0;
}