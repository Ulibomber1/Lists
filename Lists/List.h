#ifndef LIST_H
#define LIST_H

#include <algorithm>
using namespace std;

template <typename T>
class List
{
private:
	// The basic doubly linked list node.
	// Nested inside of List, can be public
	// because the Node is itself private
	struct Node
	{
		T data;
		Node *prev;
		Node *next;

		Node(const T & d = T{}, Node * p = nullptr, Node * n = nullptr)
			: data{d}, prev{p}, next{n} { }
	};

public:
	// Public constructor for const_iterator.
	const_iterator( ) : current{nullptr}
	{}

	const T & operator* () const
	{
		return retrieve();
	}

	const_iterator & operator
};

#endif
