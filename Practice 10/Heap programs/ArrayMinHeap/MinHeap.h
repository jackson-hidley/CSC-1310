/*
NAME: Jackson Hidley
DATE: 4/30/2020
TITLE: MinHeap.h
*/


#ifndef MinHeap_H
#define MinHeap_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class MinHeap
{
	private:
		string *heap; //string pointer array dynamically allocated
		int sz; //current size of the array 
		int capacity; //max size of the heap
		
		void swap(string *x, string *y)
		{
			string temp = *x;
			*x = *y;
			*y = temp;
		}			
		
		int parent(int i)//get the parent of node i
		{
			return (i-1)/2; 
		}
		
		int left(int i) //get the left child of node i
		{
			return (2*i + 1); 
		}
		
		int right(int i) //get the right child of node i
		{
			return (2*i + 2);
		}
		
		void resize()
		{
			int cap = capacity * 2; 
			string *newHeapArray = new string[cap];
			
			for(int x = 0; x < capacity; x++)
			{
				newHeapArray[x] = heap[x];
			}
			delete [] heap;
			heap = newHeapArray;
			capacity = cap;
		}
		
	public:
		MinHeap(int c)
		{
			capacity = c;
			sz = 0;
			heap = new string [capacity];
		}
		
		~MinHeap()
		{
			delete [] heap;
		}
		
		void insert(string s) //insert a string into the heap
		{
			if (sz == capacity)
			{
				resize();	//double the size of array & capacity
			}
			// First insert the new value at the end
			heap[sz] = s;
			sz++;

			// Fix the max heap property if it is violated
			int i = sz - 1;
			while ((i != 0) && (heap[parent(i)] < heap[i]))
			{
				swap(&heap[i], &heap[parent(i)]);
				i = parent(i);
			} 
		} 
		
		string remove()
		{
			if (sz == 0)
			{
				cout << "Error:  there is no nodes in the heap.\n";
				return "ERROR";
			}
			else if (sz == 1)
			{
				sz--;
				return heap[0];
			}

			string root = heap[0]; 				//remove the root (which will be returned from this function)
			heap[0] = heap[sz-1];	//take last element in array and move to first element (step 2 in remove process)
			sz--;							//reduce size of heap
			minHeapify(0);							//adjust heap - shift elements down as needed(step 3 in remove process)
			return root;
		}
		
		//check to see if the heap is empty
		//if the heap is empty the function retruns true
		bool isEmpty() const
		{
			if(sz == 0)
				return true;
			else
				return false;
		}
		
		//get the current size of the array
		int getSize()
		{
			return sz;
		}
		
		//get the height of the heap
		int getHeight()
		{
			return ceil(log2(sz + 1));
		}
		
		//returns the string at the root 
		string peek() const
		{
			return heap[0];
		}
		
		string emptyHeap()
		{
			
			if( sz == 0 )
			{
				remove();
				return "\"\"";
			}
			else
			{
				do
				{
					remove();
					
				}while( sz != 0 );
				return " ";
			}
		}
		
		void minHeapify(int i)
		{
			int l = left(i);
			int r = right(i);
			int smallest = i;
			if (l < sz && heap[l] < heap[i])
				smallest = l;
			if (r < sz && heap[r] < heap[smallest])
				smallest = r;
			if (smallest != i)
			{
				swap(&heap[i], &heap[smallest]);
				minHeapify(smallest);
			}
		}
};

#endif