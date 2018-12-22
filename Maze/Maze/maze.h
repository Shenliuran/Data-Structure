#pragma once
#define WALL_CHAR '#'
#define ROAD_CHAR '0'
#define BORDERS_CHAR '_'
#define WALL_INT 0
#define ROAD_INT 1

#define UP_POINTER map[current_node.get_x() - 1][current_node.get_y()]
#define RIGHT_POINTER map[current_node.get_x()][current_node.get_y() + 1]
#define DOWN_POINTER map[current_node.get_x() + 1][current_node.get_y()]
#define LEFT_POINTER map[current_node.get_x()][current_node.get_y() - 1]

#define UP_JUDGE current_node.get_x() - 1 >= 0 && current_node.get_x() - 1 <= size - 1
#define RIGHT_JUDGE current_node.get_y() + 1 >= 0 && current_node.get_y() + 1 <= size - 1
#define DOWN_JUDGE current_node.get_x() + 1 >= 0 && current_node.get_x() + 1 <= size - 1
#define LEFT_JUDGE current_node.get_y() - 1 >= 0 && current_node.get_y() - 1 <= size - 1
#include<ctime>
#include<cstdlib>
#include<list>
#include<iostream>

using namespace std;

typedef int Direction;
typedef char Type;

class Node
{
private:
	int x, y;
	bool visited;//检测节点是否被访问
	Type type;//节点的类型是墙还是路
	bool loaded;
public:
	Node() { visited = false; type = BORDERS_CHAR; loaded = false; }
	Node(const int const_x, const int const_y);//生成墙或路
	void set_x(const int set_x) { x = set_x; }
	void set_y(const int set_y) { y = set_y; }
	void set_type(const Type const_type) { type = const_type; }
	void set_visited(const bool const_visited) { visited = const_visited; }
	void set_loaded(const bool const_loaded) { loaded = const_loaded; }
	int get_x() { return x; }
	int get_y() { return y; }
	Type get_type() { return type; }
	bool is_visited();//返回visited
	bool is_in_borders(int size);
	bool is_loaded() { return loaded; }
	bool operator ==(const Node compared_node);
};

class Maze
{
private:
	Node **map;
	int size;
	Node start, end;
	void explore();//找路
	list<Node> path_list;
	list<Node> search_list;
	Node surround_node_push_return_stack_top_elem(list<Node> &path_list, const Node current_node);
	Node search_next_path_node(Node node);
public:
	Maze(const int const_size, int step_num);//生成迷宫
	Node create_path(const int step_num);//生成一条路径
	void display_maze();
	void display_path();
};

//生成指定范围的随机数
int special_rand(const int begin, const int end);