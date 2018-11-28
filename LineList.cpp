#include <iostream>
#include "LineList.h"

using namespace std;

template <class T> LineListElem<T>::LineListElem(const T& adata, LineListElem<T>* anext)
{
	data = adata;
	next = anext;
}

template <class T> LineListElem<T>* LineListElem<T>::getNext()
{
	return next;
}

template <class T> void LineList<T>::deleteFirst()
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

template <class T> LineList<T>::LineList()
{
	start = 0;
}

template <class T> LineList<T>::~LineList()
{
	while (start)
		deleteFirst();
}

template <class T> void LineList<T>::insertFirst(const T& data)
{
	LineListElem<T>* second = start;
	start = new LineListElem<T>(data, second);
}

template <class T> void LineList<T>::deleteAfter(LineListElem<T>* ptr)
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

template <class T> void LineList<T>::insertAfter(LineListElem<T>* ptr, const T& data)
{
	if (ptr)
	{
		LineListElem<T>* temp = ptr->next;
		ptr->next = new LineListElem<T>(data, temp);
	}
	else
		throw LineListException();
} 

template <class T> const T& LineListElem<T>::getData() const
{
	return data; 
}

template <class T> LineListElem<T>* LineList<T>::getStart()
{
	return start;
}

template <class T> LineList<T>& LineList<T>::operator =(const LineList& list)
{
	start = list.start;
}

template <class T> ostream& operator <<(ostream& out, LineList<T>& list)
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
