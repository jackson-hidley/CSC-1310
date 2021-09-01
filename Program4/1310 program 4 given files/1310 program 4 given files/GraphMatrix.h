/*
NAME: Jackson Hidley
DATE: 4/21/2020
TITLE: GraphMatrix.h
*/

#include <iostream>

using namespace std;

#ifndef GraphMatrix_H
#define GraphMatrix_H

	class matrix
	{
		private:
			int** vertexMatrix;
			int numVertices;
			int numEdges;
		public:
			matrix(){}
			
			matrix( int numVer )
			{
				numVertices = numVer;
				
				//allocate the 2d array
				vertexMatrix = new int* [numVertices]; //set rows
				for( int i = 0; i < numVertices; i++ )
					vertexMatrix[i] = new int [numVertices]; //set columns 

				for( int i = 0; i < numVertices; i++ )
				{
					
					for( int j = 0; j < numVertices; j++ )
					{
						vertexMatrix[i][j] = 0;
					}
				}
			}
			
			~matrix(){}
			
			void addEdge( int verS, int verE )
			{
				vertexMatrix[verS][verE] = 1;
			}
			
			printGraph()
			{
				//print out the Adjacency Matrix
				cout << "Adjacency Matrix:" << endl;
				
				for( int i = 0; i < numVertices; i++ )
				{
					for( int j = 0; j < numVertices; j++ )
					{
						if( vertexMatrix[i][j] == 1 )
							cout << "1 ";
						else
							cout << "0 ";
					}
					cout << endl;
				}
			}
			
			bool isThereAnEdge( int row, int column )
			{
				if( vertexMatrix[row][column] == 1 )
					return true;
				else
					return false;
			}
	};

#endif