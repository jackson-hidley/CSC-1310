/*
NAME: Jackson Hidley
DATE: 4/21/2020
TITLE: graph.cpp
*/

#include <iostream>
#include <string>
#include <fstream>
#include "GraphMatrix.h"
#include "GraphList.h"
#include "Stack.h"

using namespace std;

int main()
{
	string fileName;
	int numVer;
	int edgeStart;
	int edgeEnd;
	
	ifstream myFile;
	
	cout << "What is the filename of the file that contains the graph information? (EX: graph_1.txt)" << endl;
	
	//get the filename from the user and check if it opens
	do
	{
		
		cout << "FILENAME:\t";
		cin.clear();
		getline( cin, fileName );
		myFile.open( fileName.c_str() );
		
		//check to see if the file opened
		if( !myFile.is_open() )
			cout << "Error opening " << fileName << ". Please try again." << endl;
		
	}while( !myFile.is_open() );
	
	//get numVer
	myFile >> numVer;
	
	//create the list and matrix class
	list myList( numVer );
	matrix myMatrix( numVer );
	
	//read in all of the edges from the file and put them into the matrix and list
	while( !myFile.eof() )
	{
		myFile >> edgeStart >> edgeEnd;
		myList.addEdge( edgeStart, edgeEnd );
		myMatrix.addEdge( edgeStart, edgeEnd );
	}
	
	myFile.close();
	
	//print out the matrix and list
	cout << endl << endl;
	myMatrix.printGraph();
	cout << endl << endl;
	myList.printGraph();
	
	//create a int stack object to use the DFS algorithm
	Stack<int> myStack;
	bool* visited = new bool [numVer];
	
	for( int i = 0; i < numVer; ++i )
		visited[i] = false;
	
	for( int i = 0; i < numVer; ++i )
	{
		for( int j = 0; j < numVer; ++j )
		{
			if( (myMatrix.isThereAnEdge( i, j ) == true) && (visited[i] == false) )
				visited[i] = true;
			
			else if( visited[i] == true )
				visited[i] = true;
			
			else
				visited[i] = false;
		}
	}
	
	//print out visited vertices
	cout << "Now traversing & printing graph vertices with DFS." << endl << endl;
	
	for( int i = 0; i < numVer; ++i )
	{
		if( visited[i] == true )
		{
			myStack.push(i);
			cout << i << "\t";
		}
	}
	
	cout << endl;
	
	return 0;
}
