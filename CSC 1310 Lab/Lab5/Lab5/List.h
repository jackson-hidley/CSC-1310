/*
NAME: Jackson Hidley
DATE: 2/26/2020
TITLE: List.h
*/

#include <string>
using namespace std;


#ifndef List_H
#define List_H

class list
{
	private:
	
		struct node
		{
			string data;
			node* next;
		};
			
			node* tail;
			node* head;
			
	public:
		list()
		{
			head = NULL;
			tail = NULL;
		}
		~list()
		{
			node *nodePtr;   // To traverse the list
			node *nextNode;  // To point to the next node

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
			
		
		void appendNode(string str)
		{
			node *newNode;  // To point to a new node

			// Allocate a new node and store str there.
			newNode = new node;
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


		void deleteNode( string str )
		{
			node *nodePtr;       // To traverse the list
			node *previousNode;  // To point to the previous node

			// If the list is empty, do nothing.
			if (!head)
				return;

			// Determine if the first node is the one.
			if (head->data == str)
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
				// not equal to str.
				while (nodePtr != NULL && nodePtr->data != str)
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
		
		
		void insertNode( int position, string str )
		{
			node *nodePtr;
			node *newNode;
			
			newNode = new node;
			newNode->data = str;
			
			if(!head)
			{
				if(position != 0)
				{
					//can't insert node at position (>0) if there is not already a node
					cout << "\n\nUnable to insert a node at position " << position << " because there are currently no nodes in the list.  I am going to insert this node at position 0.\n\n";
				}
				head = newNode;
				tail = newNode;
			}
			else
			{
				nodePtr = head;
				int nodeCount = 0;
				if(position == 0)
				{
					newNode->next = head->next;
					head = newNode;
				}
				while(nodePtr != tail && nodeCount < position)
				{
					nodeCount++;
					if(nodeCount == position)
						break;
					nodePtr = nodePtr->next;
				}
				
				//now nodePtr is positioned 1 node BEFORE the node we want to insert
				if(nodePtr->next == NULL) //we are appending this node to the end
					tail = newNode;
					
				newNode->next = nodePtr->next;
				nodePtr->next = newNode;
				
			}
			
		}
		
	void displayList() const
	{
		node *nodePtr;  // To move through the list

		if(head != NULL)
		{
			// Position nodePtr at the head of the list.
			nodePtr = head;
			// While nodePtr points to a node, traverse the list.
			while (nodePtr)
			{
				// Display the value in this node.
				cout << nodePtr->data << endl;

				// Move to the next node.
				nodePtr = nodePtr->next;
			}
		}
		else
			cout << "\nThere are no nodes in the list.\n\n";
	}
};
#endif