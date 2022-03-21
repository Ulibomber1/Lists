// For CSE 2020, Spring 2022
// KV, for Lab9 

#ifndef SEARCHING_H_
#define SEARCHING_H_

#include "Vector.h"
#include "List.h"
using namespace std;

// LINEAR SEARCH OF VECTOR
// return index at which target found, if not found  return -1;
template <typename T>
int linear_search_V(const Vector<T>& vec, const T& target, int& ops)
{
	ops = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		ops++;
		if (vec[i] == target)
			return i;
	}
	return -1; // not found
}

// LINEAR SEARCH OF LINKED LIST with iterator 
// return iterator to node at which target
// found in lst; else return iterator at end() of lst;

template <typename T>
typename List<T>::const_iterator linear_search_L(const List<T>& lst, const T& target, int& ops)
{
	ops = 0;

	typename List<T>::const_iterator itr;
	for (itr = lst.begin(); itr != lst.end(); ++itr)
	{
		ops++;
		if (*itr == target)
			return itr;
	}
	return lst.end();
}

// Linear search of List with pseudo-random access [int] operator
// added to List 
// List parameter should NOT be const for this experiment to work ... 
template <typename T>
int linear_search_L_explore(List<T> lst, const T& target, int& ops)
{
	ops = 0;
	for (int i = 0; i < lst.size; i++)
	{
		ops++;
		if (lst[i] == target)
			return i;
	}
	return -1; // not found
}




#endif
