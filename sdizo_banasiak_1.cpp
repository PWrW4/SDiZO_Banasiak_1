// sdizo_banasiak_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
	cout << "SDiZO jest super!"<<endl;

	DoublyLinkedList * DLList = new DoublyLinkedList(1);

	DLList->add_start(&DLList,2);
	DLList->add_start(&DLList,3);
	DLList->add_start(&DLList,4);

	cout << DLList->count();
	//DLList->display();

	getchar();
    return 0;
}

