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

	LineListElem<T>* getPointer(const T& adata)
		{
			LineListElem<T>* ptr = start;
			while (ptr && ptr->next)
			{
				if (ptr->next->data == adata)
					return ptr->next;
				ptr = ptr->next;
			}
			throw LineListException();
			return 0;
		}

	LineListElem<T>* getPoint(const int& i)
	{
		LineListElem<T>* ptr = start;
		int j = 0;
		while (ptr->next)
		{
			if (j == i)
				return ptr;
			ptr = ptr->next;
			j++;
		}
		throw LineListException();
		return 0;
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

	template <class T> friend ostream &operator<<(ostream &out, const LineListElem<T>* pointer)
	{
		out << pointer;
		return out;
	}
};
