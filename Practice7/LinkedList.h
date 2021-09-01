/*
NAME: Jackson Hidley
DATE: 2/26/2020
TITLE: LinkedList.h
*/

#include <string>
#include <iostream>
using namespace std;
#ifndef LinkedList_H
#define LinkedList_H
class LinkedList
{
	private:
	
	struct ListNode
	{
		string value;
		struct ListNode *next;//points to the next node
	};
	
	ListNode* head;
	ListNode* tail;
	
	public:
	
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
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
	
	void appendNode( string str )
		{
			ListNode *newNode;  // To point to a new node

			// Allocate a new node and store str there.
			newNode = new ListNode;
			newNode->value = str;
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
		
	void displayList() const
	{
		ListNode *nodePtr;  // To move through the list

		if(head != NULL)
		{
			// Position nodePtr at the head of the list.
			nodePtr = head;
			// While nodePtr points to a node, traverse the list.
			while (nodePtr)
			{
				// Display the value in this node.
				cout << nodePtr->value << endl;

				// Move to the next node.
				nodePtr = nodePtr->next;
			}
		}
		else
			cout << "\nThere are no nodes in the list.\n\n";
	}
};
#endif