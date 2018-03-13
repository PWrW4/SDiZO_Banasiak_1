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
	DLList.addEnd(1);
	DLList.addEnd(2);
	DLList.addEnd(3);
	DLList.addEnd(4);
	DLList.addAtPos(20,3);
	DLList.addAtPos(40,3);




	DLList.countAndDisplay();
	DLList.display();

	DLList.rmAtPos(3);
	DLList.rmAtPos(5);
	DLList.rmAtPos(0);
	DLList.rmAtPos(99);
//	DLList.rmStart();
//	DLList.rmEnd();

	cout << endl;

	DLList.countAndDisplay();
	DLList.display();
	
	getchar();
    return 0;
}

