#pragma once
#include <iostream>

typedef int Rank;
using namespace std;


struct Node
{
	int data;
	Node* succ;
	Node* pred;
	Node(){}
	Node(int e, Node* p = NULL, Node* s = NULL) :data(e), pred(p), succ(s) {}
	Node* insertAsPred(int const& e)
	{
		Node* x = new Node(e, pred, this); //创建新节点
		pred->succ = x; pred = x; //设置正向链接
		return x; //返回新节点的位置
	}
	Node* insertAsSucc(int const& e)
	{
		Node* x = new Node(e, this, succ); //创建新节点
		succ->pred = x; succ = x; //设置逆向链接
		return x; //返回新节点的位置
	}	
};

class MyList
{
private:
	int _size;
	Node* header;
	Node* trailer;

protected:
	int clear();
	void insertionSort(Node* p, int n);

public:
	MyList();
	MyList(Node* p, int n);
	int operator[](Rank r);
	~MyList();

	// 只读
	int size() { return _size; }
	bool empty() { return _size <= 0; }
	Node* first() { return header->succ; }
	Node* last() { return trailer->pred; }
	Node* find(int const& e, int n, Node* p);
	Node* search(int const& e, int n, Node* p);
	void display();

	// 可写
	Node* insertAsFirst(int const& e);
	Node* insertAsLast(int const& e);
	Node* insertA(Node* p, int const& e);
	Node* insertB(Node* p, int const& e);
	int remove(Node* p);
	void append(int e);
	int deduplicate();
	void sort() { insertionSort(first(), _size); }
};
