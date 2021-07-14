#include "MyList.h"

int MyList::clear()
{
	int old_size = _size;
	while(_size > 0)
	{
		remove(header->succ);
	}
	return old_size;
}

MyList::MyList()
{
	header = new Node;
	trailer = new Node;
	header->succ = trailer;
	header->pred = NULL;
	trailer->pred = header;
	trailer->succ = NULL;
	_size = 0;
}
MyList::MyList(Node* p, int n)
{
	MyList();
	while (n--)
	{
		insertAsLast(p->data);
		p = p->succ;
	}
}
MyList::~MyList()
{
	clear();
	delete header;
	delete trailer;
}
int MyList::operator[](Rank r)
{
	Node* p = header;
	while (0 < r--)
	{
		p = p->succ;
	}
	return p->data;
}

// protect
void MyList::insertionSort(Node* p, int n)
{
	for (int r = 0; r < n; r++)
	{
		insertA(search(p->data, r, p), p->data);
		p = p->succ;
		remove(p->pred);
	}
}

// 只读
Node* MyList::find(int const& e, int n, Node* p)
{
	while (0 < n--)
	{
		if ((p = p->pred)->data == e)
		{
			return p;
		}
	}
	return NULL;
}

Node* MyList::search(int const& e, int n, Node* p)
{
	while (0 < n--)
	{
		if ((p = p->pred)->data <= e) break;
	}
	return p;
}
	
void MyList::display()
{
	for (Node* p = first(); p != trailer; p = p->succ)
	{
		cout << p->data << " ";
	}
	cout << endl;
}

// 可写
Node* MyList::insertAsFirst(int const& e)
{
	_size++;
	return header->insertAsSucc(e);
}
Node* MyList::insertAsLast(int const& e)
{
	_size++;
	return trailer->insertAsPred(e);
}

Node* MyList::insertA(Node* p, int const& e)
{
	_size++;
	return p->insertAsSucc(e);
}

Node* MyList::insertB(Node* p, int const& e)
{
	_size++;
	return p->insertAsPred(e);
}

int MyList::remove(Node* p)
{
	int e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	--_size;
	return e;
}

void MyList::append(int e)
{
	insertAsLast(e);
}

int MyList::deduplicate()
{
	if (_size < 2) return 0;
	int old_size = _size;
	int r = 0;
	Node* p = header;
	while ((p = p->succ) != trailer)
	{	
		Node* q = find(p->data, r, p);
		q ? remove(q) : r++;
	}
	return _size - old_size;
}
