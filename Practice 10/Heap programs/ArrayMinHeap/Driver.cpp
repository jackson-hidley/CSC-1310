/*
NAME: Jackson Hidley
DATE: 4/30/2020
TITLE: MinHeap.h
*/

#include <iostream>
#include <string>
#include "MinHeap.h"

using namespace std;

int main()
{
	MinHeap heap(4);
	
	heap.insert("everyday ");
	heap.insert("do ");
	heap.insert("coding ");
	heap.insert("like ");
	heap.insert("I ");
	
	cout << "SIZE:   " << heap.getSize() << endl;
	cout << "HEIGHT: " << heap.getHeight() << endl;
	cout << "ROOT:   " << heap.peek() << endl;

	int s = heap.getSize();
	
	for( int i = 0; i < s; ++i )
	{
		cout << heap.remove();
	}
	cout << endl;
	
	heap.insert("nonsense");
	
	heap.emptyHeap();
	
	if( heap.isEmpty() == true )
		cout << "Heap has been cleared to the screen" << endl;
	else
		cout << "Heap was not cleared" << endl;
	
	return 0;
}

