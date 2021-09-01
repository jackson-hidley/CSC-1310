/*
NAME: Jackson Hidley
DATE: 2/24/2020
TITLE: LinkedList.h
*/
#include <iostream>
#include "Dinosaur.h"
using namespace std;


#ifndef LinkedList_H
#define LinkedList_H

//create structe called list
class LinkedList
{
	private:
	struct ListNode
	{
		dino dinosaur;
		struct ListNode* nextNode;//poin tto next node
	};
	
	ListNode* head;
	ListNode* tail;
	
	public:
		// Constructor
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}

		// Destructor (deallocates all nodes)
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
		
		void appendNode( dino d )
		{
				ListNode *newNode;  // To point to a new node

				// Allocate a new node and store d there.
				newNode = new ListNode;
				newNode->dinosaur = d;
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
			
		
		void deleteNode( dino d )
		{
			ListNode *nodePtr;       // To traverse the list
			ListNode *previousNode;  // To point to the previous node

			// If the list is empty, do nothing.
			if (!head)
				return;

			// Determine if the first node is the one.
			if (head->dinosaur.getName() == d.getName())
			{
				nodePtr = head->next;
				delete head;
				head = nodePtr;
			}
			else
			{
				// Initialize nodePtr to head of list
				nodePtr = head;

				// Skip all nodes whose value member is 
				// not equal to num.
				while (nodePtr != NULL && nodePtr->dinosaur != d)
				{  
					previousNode = nodePtr;
					nodePtr = nodePtr->next;
				}

				// If nodePtr is not at the end of the list, 
				// link the previous node to the node after
				// nodePtr, then delete nodePtr.
				if (nodePtr)
				{
					if(nodePtr == tail)
					{
						tail = previousNode;
					}
					previousNode->next = nodePtr->next;
					delete nodePtr;
				}
			}
		}
		
		ListNode* merge( dino arry, int l, int r, dino x )
		{
			
		}
		
		void mergeSort()
		{
			
		}
		
		int getNodeData( int position )
		{
			ListNode *nodePtr;
			if(!head)
				return -1;
			else
			{
				if(position == 0)
					return head->dinosaur;
				nodePtr = head;
				int currentPos = 0;
				while(position >= currentPos && nodePtr != NULL)
				{
					if(position == currentPos)
						return nodePtr->dinosaur;
					currentPos++;
					nodePtr = nodePtr->next;
				}
			}
			return -1;
		}
	
		void displayList()
		{
			
};

#endif