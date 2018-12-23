#pragma once

#include<list>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

class Node
{
private:
	char ch;
	int wight;
	Node *lchild, *rchild;
	Node *parent;
	int code;
	double wight_percentage;
public:
	Node() { ch = '\0'; wight = 0; parent = lchild = rchild = nullptr; code = 0; }

	void set_ch(const char const_ch) { ch = const_ch; }
	void set_wight(const int const_wight) { wight = const_wight; }
	void self_add_wight() { wight++; }
	void set_parent(Node *parent_ptr) { parent = parent_ptr; }
	void set_lchild(Node *lchild_ptr) { lchild = lchild_ptr; }
	void set_rchild(Node *rchild_ptr) { rchild = rchild_ptr; }
	void set_wight_percentage(const string origin_str) { wight_percentage = (double)wight / origin_str.size(); }
	void set_wight_percentage(const double const_wight_per) { wight_percentage = const_wight_per; }
	void set_code(const int const_code) { code = const_code; }

	char get_ch() { return ch; }
	double get_wight_percentage() { return wight_percentage; }
	int get_wight() { return wight; }
	int get_code() { return code; }
	Node *get_parent() { return parent; }
	Node *get_lchild() { return lchild; }
	Node *get_rchild() { return rchild; }

	bool operator <(Node compared_node) {
		if (wight < compared_node.get_wight()) return true;
		else return false;
	}
};
typedef Node *Root, *Leaf;


class Process
{
private:
	int size;
	string origin_str;
	//list<Node> wight_vector;
public:
	Process(const string const_str) { size = 0; origin_str = const_str; }
	Process() {}
	int get_size() { return size; }
	string get_origin_str() { return origin_str; }

	void sorted_wight_vector();
	void display_wight_vector();
	//void display_alphabet();
	list<Node> wight_vector;
	/*list<Node> get_wight_vector() {
		list<Node> vector = wight_vector;
		return vector;
	}*/
};

class HuffmanTree
{
private:
	Root root_node;
	Node tree_node;
	Process process;
public:
	HuffmanTree(Process const_pro);
	void display_huffman_code();
	void display_code(const Node search_node);
};