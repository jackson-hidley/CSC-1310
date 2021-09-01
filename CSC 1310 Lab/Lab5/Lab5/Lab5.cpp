/*
NAME: Jackson Hidley
DATE: 2/26/2020
TITLE: Lab5.cpp
*/

#include <string>
#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	//define a list object
	list link;
	
	link.appendNode("boogeyman");
	link.appendNode("ghost");
	link.appendNode("scarecrow");
	link.appendNode("witch");
	link.appendNode("zombie");
	
	cout << "Inserting several strings into the list." << endl;
	
	link.displayList();
	
	link.insertNode(3, "vampire");
	cout << "Printing \"vampire\" to the list." << endl;
	
	link.displayList();
	
	link.deleteNode("ghost");
	cout << "Deleting \"ghost\" from the list." << endl;
	
	link.displayList();
	
	return 0;
}