/*
NAME: Jackson Hidley
DATE: 2/24/2020
TITLE: LinkedList.h
*/

//Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include "Dinosaur.h"
using namespace std;

#ifndef LinkedList_H
#define LinkedList_H

//create a template called T
template <class T>
class LinkedList
{
	private:
		struct ListNode
		{
			T data;
			struct ListNode* next;
		};
		
		ListNode* head;
		ListNode* tail;
		
	public:
		//constructor
		LinkedList()
		{
			head = NULL;
			tail = NULL;
		}
		//deconstructor
		~LinkedList()
		{
			ListNode *nodePtr;   // To traverse the list
			ListNode *nextNode;  // To point to the next node

			// Position nodePtr at the head of the list.
			nodePtr = head;

			// While nodePtr is not at the end of the list...
			while (nodePtr != NULL)
			{
				// Save a pointer to the next node.
				nextNode = nodePtr->next;

				// Delete the current node.
				delete nodePtr;

				// Position nodePtr at the next node.
				nodePtr = nextNode;
			}
		}
		
		void appendNode( T str )
		{
			ListNode *newNode;  // To point to a new node

			// Allocate a new node and store str there.
			newNode = new ListNode;
			newNode->data = str;
			newNode->next = NULL;

			// If there are no nodes in the list make newNode the first node.
			if (!head ) 
			{
				head = newNode;
				tail = newNode;
			}
			else  // Otherwise, insert newNode at end.
			{
				//set the current last node's next pointer to the new node
				tail->next = newNode;
				
				//now the tail is the new node
				tail = newNode;
			}
		}
	
		int displayList()
		{
			ListNode *nodePtr;  // To move through the list
			int i = 1;
			if( head != NULL )
			{
				// Position nodePtr at the head of the list.
				nodePtr = head;
				// While nodePtr points to a node, traverse the list.
				while ( nodePtr )
				{
					cout << "***************************************************************************************************" << endl;
					cout << "DINOSAUR " << i << ":" << endl;//display the dinosaurs number
					cout << nodePtr->data.getName() << endl;//display name of the dinosaur
					cout << "DESCRIPTION:" << endl << nodePtr->data.getDesc() << endl;//display the description of the dinosaur
					cout << "LIFE POINTS:		" << nodePtr->data.getLife() << endl;//dispplay  the life points of the dinosaur
					cout << "HIT POINTS:		" << nodePtr->data.getHP() << endl;//display the hit points of the dinosaur

					// Move to the next node.
					nodePtr = nodePtr->next;
					i++;
				}
				return i;
			}
			else
				cout << "\nThere are no nodes in the list.\n\n";
				return -1;
		}
		
		bool binarySearch( T x )
		{
			ListNode *nodePtr;  // To move through the list

			// Position nodePtr at the head of the list.
			nodePtr = head;

			// While nodePtr points to a node, traverse the list.
			while (nodePtr)
			{
				//see if this node matches the value
				if(nodePtr->data.getName() == x.getName() )
					return true;

				// Move to the next node.
				nodePtr = nodePtr->next;
			}
			return false; //node couldn't be found
		}
		
		void callMergeSort()
		{
			MergeSort( &head );
		}
		//sorts the linked list by changing next pointers (not data)
		void MergeSort(ListNode** headRef) 
		{ 
			ListNode* h = *headRef; 
			ListNode* a; 
			ListNode* b; 
		  
			// Base case -- length 0 or 1
			if ((h == NULL) || (h->next == NULL)) { 
				return; 
			} 
		  
			// Split head into 'a' and 'b' sublists
			FrontBackSplit(head, &a, &b); 
		  
			// Recursively sort the sublists
			MergeSort(&a); 
			MergeSort(&b); 
		  
			// answer = merge the two sorted lists together
			*headRef = SortedMerge(a, b); 
		} 
		
		ListNode* SortedMerge( ListNode* a, ListNode* b)
		{ 
			ListNode* result = NULL; 
		  
			// Base cases 
			if (a == NULL) 
				return b; 
			else if (b == NULL) 
				return a; 
		  
			// Pick either a or b, and recur
			if (a->data.getName() <= b->data.getName() ) { 
				result = a; 
				result->next = SortedMerge(a->next, b); 
			} 
			else { 
				result = b; 
				result->next = SortedMerge(a, b->next); 
			} 
			return result; 
		} 
		  
		// Split the nodes of the given list into front and back halves
		void FrontBackSplit( ListNode* source, ListNode** frontRef, ListNode** backRef) 
		{ 
			ListNode* fast; 
			ListNode* slow; 
			slow = source; 
			fast = source->next; 
		  
			// Advance 'fast' two nodes, and advance 'slow' one node
			while (fast != NULL) { 
				fast = fast->next; 
				if (fast != NULL) { 
					slow = slow->next; 
					fast = fast->next; 
				} 
			} 
			*frontRef = source; 
			*backRef = slow->next; 
			slow->next = NULL; 
		} 
		//Print out the dinosaur names in 4 columns
		void printMenu()
		{
			ListNode *nodePtr;  // To move through the list
			int i = 0;
			if( head != NULL )
			{
				// Position nodePtr at the head of the list.
				nodePtr = head;

				cout << "************************************************************************************************************************************************" << endl;
				// While nodePtr points to a node, traverse the list.
				while ( nodePtr )
				{
					cout << setw(20) << i + 1 << "-" << nodePtr->data.getName();
					
					if( i % 3 == 0 && i != 0 )
					{
						cout << endl;
					}
					// Move to the next node.
					nodePtr = nodePtr->next;
					i++;
				}
				cout << endl;
				cout << "************************************************************************************************************************************************" << endl;
			}
			
			else
				cout << "No dinosaurs to show." << endl;
			
		}
		
		//get the data from a specific node
		T getData( int num )
		{
			ListNode* nodePtr;
			
			if ( head != NULL )
			{
				int i = 0;
				// Position nodePtr at the head of the list.
				nodePtr = head;
				
				while( nodePtr && i <= num )
				{
					//move to the next node
					i++;
					nodePtr = nodePtr->next;
				}
				//return the data
				return nodePtr->data;
			}
			
			else 
				cout << "There are no nodes in the list." << endl;
		}
		
		//get the head node of the list
		ListNode* getHead()
		{
			return head;
		}
		
		//getLength() returns the number of nodes in the list.
		int getLength()
		{
			int counter = 0;
			ListNode *nodePtr;
			
			nodePtr = head;
			
			while(nodePtr != tail)
			{
				counter++;
				nodePtr = nodePtr->next;
				if (nodePtr == tail)
					counter++;
			}
			return counter;
		}

};
		
#endif