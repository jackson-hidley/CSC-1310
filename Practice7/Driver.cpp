/*
NAME: Jackson Hidley
DATE: 2/26/2020
TITLE: Driver.cpp
*/

#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	LinkedList dogBreeds;
	
	dogBreeds.appendNode( "Corgi" );
	dogBreeds.appendNode( "English Bulldog" );
	dogBreeds.appendNode( "Dalmation" );
	dogBreeds.appendNode( "German Shepard" );
	dogBreeds.appendNode( "Poodle" );
	
	dogBreeds.displayList();
	
	cout << "Goodbye!" << endl;
}