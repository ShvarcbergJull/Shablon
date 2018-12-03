#pragma once
#include <iostream>

using namespace std;

class LineListException {};

template <class T> class LineListElem
{
	T data;
	LineListElem* next;
public:
	LineListElem(const T& adata, LineListElem* anext)
	{
		data = adata;
		next = anext;
	}
	const T& getData() const
	{
		return data;
	}
	LineListElem* getNext()
	{
		return next;
	}
	template <class T>	friend class LineList; 
};

template <class T> class LineList
{
	LineListElem<T>* start;
	LineList(const LineList& list);
	LineList& operator =(const LineList& list)
	{
		start = list.start;
	}

public:
	LineList()
	{
		start = 0;
	}
	~LineList()
	{
		while (start)
			deleteFirst();
	}
	LineListElem<T>* getStart()
	{
		return start;
	}
	void deleteFirst()
	{
		if (start)
		{
			LineListElem<T>* temp = start->next;
			delete start;
			start = temp;
		}
		else
			throw LineListException();
	}
	void deleteAfter(LineListElem<T>* ptr)
	{
		if (ptr && ptr->next)
		{
			LineListElem<T>* temp = ptr->next;
			ptr->next = temp->next;
			delete temp;
		}
		else
			throw LineListException();

	}
	void insertFirst(const T& data)
	{
		LineListElem<T>* second = start;
		start = new LineListElem<T>(data, second);
	}
	void insertAfter(LineListElem<T>* ptr, const T& data)
	{
		if (ptr)
		{
			LineListElem<T>* temp = ptr->next;
			ptr->next = new LineListElem<T>(data, temp);
		}
		else
			throw LineListException();
	}

	template <class T> friend ostream &operator<<(ostream &out, const LineList<T> &list)
	{
		LineListElem<T>* ptr = list.start;
		if (!ptr)
			cout << "EMPTY" << endl;
		else
			while (ptr)
			{
				out << ptr->getData() << ' ';
				ptr = ptr->getNext();
			}
		return out;
	}
};
