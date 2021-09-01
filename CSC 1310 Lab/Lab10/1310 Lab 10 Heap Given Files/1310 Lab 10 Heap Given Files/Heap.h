/*
NAME: Jackson Hidley
DATE: 4/22/2020
TITLE: Heap.h
*/

#ifndef Heap_H
#define Heap_H

#include <iostream>
#include <cmath>
#include "Student.h"

class Heap
{
	private:
		
		Student* items; //array of heap students
		int heap_size; //current count of heap students
		int capacity;
		void swap( Student* x, Student* y )
		{
			Student temp = *x;
			*x = *y;
			*y = temp;
		}
		
		int parent( int i ) //get the parent of index i
		{
			return (i-1)/2;
		}
		int left( int i) //get the left child of index i
		{
			return (2*i +1);
		}
		int right( int i ) //get the right child of index i
		{
			return (2*i+2);
		}
		
		
		bool isLeaf(int nodeIndex)	//tests whether this node is a leaf.
		{
			return (left(nodeIndex) >= heap_size);
		}
		
		
		//Converts a semiheap to a heap
		void heapRebuild(const int subTreeNodeIndex);
		void resizeArray();
		
	public:
		
		Heap(int);
		~Heap();
		
		bool isEmpty() const; //check to see if the heap is empty
		
		int getNumberOfNodes() const; //gets the number of nodes in this heap
		
		int getHeight() const; //gets the height of this heap
		
		void insert( Student newData ); //insert newData in the heap
		
		Student remove(); //remove the root (maximum value) & return it
		
		friend ostream &operator << (ostream &strm, Heap &s)
		{
			strm << s.items;
			return strm;
		}
};

//******************************************************************
// 
// Private functions start here
//
//******************************************************************

void Heap::heapRebuild(const int subTreeNodeIndex)
{
	if (!isLeaf(subTreeNodeIndex))
	{
		// Find larger child
		int leftChildIndex = left(subTreeNodeIndex);   	// A left child must exist
		int largerChildIndex = leftChildIndex;         	// Make assumption about larger child
		int rightChildIndex = right(subTreeNodeIndex); 	// A right child might not exist

		// Check to see whether a right child exists
		if (rightChildIndex < heap_size)
		{
			// A right child exists; check whether it is larger
			if (items[rightChildIndex] > items[largerChildIndex])
				largerChildIndex = rightChildIndex;		// Asssumption was wrong
		} 

		// If root value is smaller that the value in the larger child, swap values
		if (items[subTreeNodeIndex] < items[largerChildIndex])
		{
			swap(&items[largerChildIndex], &items[subTreeNodeIndex]);

			// Continue with the recursion at that child
			heapRebuild(largerChildIndex);
		}  
	}  
} 


Heap::Heap(int num)
{  
	heap_size = 0;
	capacity = num;
	items = new Student[capacity];
}

Heap::~Heap()
{  
   delete [] items;
}

bool Heap::isEmpty() const
{
	if(heap_size == 0)
		return true;
	else
		return false;
}

int Heap::getHeight() const
{
	return ceil(log2(heap_size + 1));
}  

int Heap::getNumberOfNodes() const
{
	return heap_size;
}

void Heap::resizeArray()	//make an array 2 times as big as original
{
	int cap = capacity * 2; 
	Student *newHeapArray = new Student[cap];
	
	for(int x = 0; x < capacity; x++)
	{
		newHeapArray[x] = items[x];
	}
	delete [] items;
	items = newHeapArray;
	capacity = cap;
}

void Heap::insert(Student newData)
{
	if (heap_size == capacity)
	{
		resizeArray();	//double the size of array & capacity
	}
	// First insert the new value at the end
	items[heap_size] = newData;
	heap_size++;

	// Fix the max heap property if it is violated
	int i = heap_size-1;
	while ((i != 0) && (items[parent(i)] < items[i]))
	{
		swap(&items[i], &items[parent(i)]);
		i = parent(i);
	} 
}

Student Heap::remove()
{
	Student temp;
	if (!isEmpty()) 
	{
		temp = items[0];						//Store the root value so it can be returned later
		items[0] = items[heap_size - 1];		//Set the root node (first element) to the last element (step 2 in remove process)
		heap_size--;							//Decrement the heap's size
		heapRebuild(0);							//adjust heap - shift elements down as needed(step 3 in remove process)
		cout << temp;
	}
	else
	{
		cout << "\nThe heap is empty so I can't remove any values.\n";
	}

	return temp;
} 

#endif