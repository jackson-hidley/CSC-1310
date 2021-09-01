/*
NAME: Jackson Hidley
DATE: 4/21/2020
TITLE: GraphList.h
*/

#include <iostream>

using namespace std;

#ifndef GraphList_H
#define GraphList_H

	class list
	{
		private:
			struct ListNode
			{
				int value;
				ListNode* next;
			};
			
			ListNode** headArray;
			int numVertices;
			int numEdges;
		public:
			list( int numVer )
			{
				numVertices = numVer;
				headArray = new ListNode* [numVertices];
				
				for( int i = 0; i < numVertices; ++i )
				{
					headArray[i] = NULL;
				}
			}
			
			~list()
			{
				delete [] headArray;
			}
			
			void addEdge( int verS, int verE )
			{
				ListNode* temp = new ListNode;
				temp->value = verE;
				temp->next = NULL;
				
				if( headArray[verS] == NULL )
				{
					headArray[verS] = temp;
				}
				else
				{
					headArray[verS]->next = temp;
				}
			}
			
			//print out the Adjacency List
			void printGraph()
			{
				cout << "Adjacency List..." << endl;
				
				ListNode* nodePtr;  // To move through the list
				
				for( int i = 0; i < numVertices; i++ )
				{
					cout << i;
					
					// Position nodePtr at the head of the list.
					nodePtr = headArray[i];
					// While nodePtr points to a node, traverse the list.
					while (nodePtr)
					{
						// Display the value in this node.
						cout << "--->" << nodePtr->value;

						// Move to the next node.
						nodePtr = nodePtr->next;
					}
					cout << "--->NULL" << endl;
				}
			}
	};
	
#endif