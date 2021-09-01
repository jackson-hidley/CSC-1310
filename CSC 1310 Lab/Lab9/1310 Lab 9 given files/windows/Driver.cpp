/*
NAME: Jackson Hidley
DATE: 4/15/2020
TITLE: Driver.cpp
*/


#include <iostream>
#include <fstream>
#include "GraphList.h"

using namespace std;

int main()
{
	int numServ;//number of vertice
	int ver1;//starting vertice
	int ver2;//ending vertice
	
	//open file with the verticies
	fstream myFile;
	myFile.open( "graph.txt" );
	
	//read in the number of verticies from the file
	myFile >> numServ;
	cout << "There are " << numServ << " verticies in the graph." << endl << endl;
	
	//create graphList class from GraphList.h
	graphList graph( numServ );
	
	//read in and add edges
	while( !myFile.eof() )
	{
		myFile >> ver1 >> ver2;
		cout << "Adding an edge from " << ver1 << " to " << ver2 << "." << endl;
		//call addEdge from GraphList.h
		graph.addEdge( ver1, ver2 );
		
	}
	cout << endl;
	
	//call printGraph from GraphList.h
	graph.printGraph();
	
	return 0;
}