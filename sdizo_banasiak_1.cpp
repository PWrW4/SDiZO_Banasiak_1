// sdizo_banasiak_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
	cout << "SDiZO jest super!"<<endl;

	DoublyLinkedList DLList;

	DLList.addEnd(10);
	DLList.addStart(1);
	DLList.addStart(2);
	DLList.addEnd(3);
	DLList.addAfter(4,1);
	DLList.addAfter(5,3);
	DLList.addAfter(0,0);
	DLList.addAfter(0,0);

	DLList.countAndDisplay();
	DLList.display();

	getchar();
    return 0;
}

