#include <iostream>
#include <locale.h>
#include "LineList.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	LineList<int> list;
	cout << "Начало: " << list << endl;
	list.insertFirst(10);
	LineListElem<int>* ptr = list.getStart();
	list.insertAfter(ptr, 15);
	list.insertAfter(ptr->getNext(), 12);
	list.insertFirst(7);
	cout << "Шаг 1: " << list << endl;
	cout << "Шаг 2: " << list.getPointer(15) << endl;
	cout << "Шаг 3: " << list.getPoint(1) << endl;
	
	system("pause");
	return 0;
}
