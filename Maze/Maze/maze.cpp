#include "maze.h"

enum direction { up, right, down, left };//up -> 0, right -> 1, down -> 2, left -> 3





bool Node::is_in_borders(int size)
{
	if (x < 0 || x >(size - 1) || y < 0 || y >(size - 1))
		return false;
	else
		return true;
}
Node::Node(const int const_x, const int const_y)
{
	if (special_rand(WALL_INT, ROAD_INT) == 1)
		type = ROAD_CHAR;
	else
		type = WALL_CHAR;
	visited = false;
	loaded = false;
	x = const_x;
	y = const_y;
}
bool Node::is_visited()
{
	return visited;
}
bool Node::operator==(Node compared_node)
{
	if (x == compared_node.get_x()
		&& y == compared_node.get_y())
		return true;
	else
		return false;
}


/****************************************************************************/
/*创建迷宫*/
Maze::Maze(const int const_size, int step_num)
{
	size = const_size;
	map = (Node**) new Node*[size];
	for (int i = 0; i < size; i++)
	{
		map[i] = (Node*) new Node[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Node node(i, j);
			map[i][j] = node;
		}
	}
	end = create_path(step_num);
}
Node Maze::search_next_path_node(Node current_node)
{
	current_node.set_type(ROAD_CHAR);
	map[current_node.get_x()][current_node.get_y()].set_type(current_node.get_type());
	map[current_node.get_x()][current_node.get_y()].set_visited(true);

	Node up_flag, right_flag, down_flag, left_flag;
	if (UP_JUDGE)
	{
		up_flag = UP_POINTER;
		up_flag.set_type(special_rand(WALL_INT, ROAD_INT));
	}
	if (RIGHT_JUDGE)
	{
		right_flag = RIGHT_POINTER;
		right_flag.set_type(special_rand(WALL_INT, ROAD_INT));
	}
	if (DOWN_JUDGE)
	{
		down_flag = DOWN_POINTER;
		down_flag.set_type(special_rand(WALL_INT, ROAD_INT));
	}
	if (LEFT_JUDGE)
	{
		left_flag = LEFT_POINTER;
		left_flag.set_type(special_rand(WALL_INT, ROAD_INT));
	}

	Node flag_node;
	Direction direction_flag;
	//while (flag_node.get_type() != 0)
	//{
	//	direction_flag = special_rand(direction::up, direction::left);
	//	if (direction_flag == direction::up && up_flag.get_type() != BORDERS_CHAR && up_flag.is_visited() != true)
	//		flag_node = up_flag;
	//	if (direction_flag == direction::right && right_flag.get_type() != BORDERS_CHAR && right_flag.is_visited() != true)
	//		flag_node = right_flag;
	//	if (direction_flag == direction::down && down_flag.get_type() != BORDERS_CHAR && down_flag.is_visited() != true)
	//		flag_node = down_flag;
	//	if (direction_flag == direction::left && left_flag.get_type() != BORDERS_CHAR && left_flag.is_visited() != true)
	//		flag_node = left_flag;
	if (up_flag.get_type() != BORDERS_CHAR
		&& up_flag.is_visited() != true)
		flag_node = up_flag;

	if (right_flag.get_type() != BORDERS_CHAR
		&& right_flag.is_visited() != true)
		flag_node = right_flag;

	if (down_flag.get_type() != BORDERS_CHAR
		&& down_flag.is_visited() != true)
		flag_node = down_flag;

	if (left_flag.get_type() != BORDERS_CHAR
		&& left_flag.is_visited() != true)
		flag_node = left_flag;

	flag_node.set_visited(true);
	return flag_node;
}
Node Maze::create_path(const int step_num)
{
	start.set_x(special_rand(0, size - 1));
	start.set_y(special_rand(0, size - 1));
	Node next_node;
	next_node = search_next_path_node(start);

	for (int i = 0; i < step_num - 2; i++)
	{
		next_node = search_next_path_node(next_node);
	}
	search_next_path_node(next_node);
	return next_node;
}

/*路径探索*/
void Maze::explore()
{
	start.set_loaded(true);
	search_list.push_back(map[start.get_x()][start.get_y()]);
	Node next_node;
	path_list.push_back(search_list.back());
	next_node = surround_node_push_return_stack_top_elem(search_list, map[start.get_x()][start.get_y()]);
	while (!(next_node == end))
	{
		next_node = surround_node_push_return_stack_top_elem(search_list, map[next_node.get_x()][next_node.get_y()]);
	}
	search_list.push_back(map[end.get_x()][end.get_y()]);
}
Node Maze::surround_node_push_return_stack_top_elem(list<Node> &search_list, Node current_node)
{
	Node up_node, right_node, down_node, left_node;
	map[current_node.get_x()][current_node.get_y()].set_loaded(true);
	//数据预处理
	if (UP_JUDGE && current_node.get_type() != BORDERS_CHAR)
		up_node = UP_POINTER;
	if (RIGHT_JUDGE && current_node.get_type() != BORDERS_CHAR)
		right_node = RIGHT_POINTER;
	if (DOWN_JUDGE && current_node.get_type() != BORDERS_CHAR)
		down_node = DOWN_POINTER;
	if (LEFT_JUDGE && current_node.get_type() != BORDERS_CHAR)
		left_node = LEFT_POINTER;

	//方向指针设置
	Direction pointer = -1;
	if (up_node.is_loaded() == false
		&& up_node.get_type() == ROAD_CHAR)
	{
		search_list.push_back(map[up_node.get_x()][up_node.get_y()]);
		map[up_node.get_x()][up_node.get_y()].set_loaded(true);
		pointer = direction::up;
	}
	if (right_node.is_loaded() == false
		&& right_node.get_type() == ROAD_CHAR)
	{
		search_list.push_back(map[right_node.get_x()][right_node.get_y()]);
		map[right_node.get_x()][right_node.get_y()].set_loaded(true);
		pointer = direction::right;
	}
	if (down_node.is_loaded() == false
		&& down_node.get_type() == ROAD_CHAR)
	{
		search_list.push_back(map[down_node.get_x()][down_node.get_y()]);
		map[down_node.get_x()][down_node.get_y()].set_loaded(true);
		pointer = direction::down;
	}
	if (left_node.is_loaded() == false
		&& left_node.get_type() == ROAD_CHAR)
	{
		search_list.push_back(map[left_node.get_x()][left_node.get_y()]);
		map[left_node.get_x()][left_node.get_y()].set_loaded(true);
		pointer = direction::left;
	}
	path_list.push_back(search_list.back());
	search_list.pop_back();
	if (pointer == direction::up)
		return up_node;
	else if (pointer == direction::right)
		return right_node;
	else if (pointer == direction::down)
		return down_node;
	else if (pointer == direction::left)
		return left_node;
	else
	{
		path_list.pop_back();
		search_list.pop_back();
		return Node();
	}
}


/*显示迷宫*/
void Maze::display_maze()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << map[i][j].get_type() << " ";
			if (j == size - 1)
				cout << endl;
		}
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << map[i][j].is_visited() << " ";
			if (j == size - 1)
				cout << endl;
		}
	}
	cout << endl;
	cout << "起点的坐标为：" << "(" << start.get_x() << "," << start.get_y() << ")" << endl;
	cout << "终点的坐标为：" << "(" << end.get_x() << "," << end.get_y() << ")" << endl;
}
void Maze::display_path()
{
	explore();
	while (path_list.empty() == false)
	{
		cout << "(" << path_list.front().get_x() << "," << path_list.front().get_y() << ")";
		if (path_list.size() - 1 != 0)
			cout << "->";
		path_list.pop_front();
	}
	cout << endl;
}

int special_rand(const int begin, const int end)
{
	return rand() % (end - begin + 1) + begin;
}