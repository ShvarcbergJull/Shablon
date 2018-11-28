#pragma once
#include <iostream>

//using namespace std;

template <class T> class LineListElem
{
	T data;
	LineListElem* next;
public:
	LineListElem(const T& adata, LineListElem* anext);
	const T& getData() const;
	LineListElem* getNext();
	template <class T>	friend class LineList; 
};

template <class T> class LineList
{
	LineListElem<T>* start;
	LineList(const LineList& list);
	LineList& operator =(const LineList& list);

public:
	LineList();
	~LineList();
	LineListElem<T>* getStart();
	void deleteFirst();
	void deleteAfter(LineListElem<T>* ptr);
	void insertFirst(const T& data);
	void insertAfter(LineListElem<T>* ptr, const T& data);

	template <class T> friend std::ostream &operator<<(ostream &out, const LineList<T> &list);
};

class LineListException{};

/*
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
}*/
