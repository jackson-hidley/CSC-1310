/*
NAME: Jackson Hidley
DATE: 4/15/2020
TITLE: GraphList.h
*/



#ifndef GraphList_H
#define GraphList_H

#include <iostream>
using namespace std;


	class graphList
	{
		private:
			struct ListNode
			{
				int value1;
				int value2;
				ListNode* next;
			};
			ListNode** headArray;
			int numVertices;
			int numEdges;
			
		public:
			graphList( int numVer )
			{
				this->numVertices = numVer;
				headArray = new ListNode* [numVertices];
				numEdges = 0;
			}
			
			~graphList(){}
			
			
			void addEdge( int v1, int v2 )
			{
				ListNode *newNode;  // To point to a new node

				// Allocate a new node and store d there.
				newNode = new ListNode;
				newNode->value1 = v1;
				newNode->value2 = v2;
				newNode->next = NULL;
				
				headArray[numEdges] = newNode;
				numEdges++;
			}
			
			
			void printGraph()
			{
				cout << "Adjancency List..." << endl;
				cout << "0";
				int j = 0;
				for( int i = 0; i < numEdges-1; i++ )
				{
					if( headArray[i+1]->value1 != j)
					{
						cout << "--->NULL" << endl;
						j++;
						cout << j;
					}
					else
					{
						cout << "--->" << headArray[i+1]->value2;
					}
				}
			}
	};

#endif