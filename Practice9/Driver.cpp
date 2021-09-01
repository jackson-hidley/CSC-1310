/*
NAME: Jackson Hidley
Date: 3/11/2020
Title: Driver.cpp
Purpose: Use a hash table
*/


#include <iostream>
#include <string>
#include "HashTable.h"
#include "HashEntry.h"

using namespace std;

int main()
{
	int tableSize;
	bool validIn;//checks and sees if the user inputed table size is a valid input
	string value;
	int index = 0;
	string temp;

	cout << "Hello." << endl << endl;
	
	do
	{
		cout << "What size is the table? ";
		cin >> tableSize;
		cin.ignore();
		//check to see if the input is valid
		if( tableSize > 0 )
		{
			validIn = true;
		}
		else
		{
			validIn = false;
			cout << "Invalid input. Please try again." << endl;
		}
	}while( !validIn );
	
	//create a hashTabel with the table size
	HashTable table( tableSize );
	
	//get 3 values and put it in the hash table
	cout << "Enter a value: ";
	getline( cin, value );
	cout << endl;
	
	temp = table.putValue( value, value, index );
	cout << "Key is ";
	cout << temp << endl;
	index++;
	
	cout << "Enter a value: ";
	getline( cin, value );
	cout << endl;
	
	temp = table.putValue( value, value, index );
	cout << "Key is ";
	cout << temp << endl;
	index++;
	
	cout << "Enter a value: ";
	getline( cin, value );
	cout << endl;
	
	temp = table.putValue( value, value, index );
	cout << "Key is ";
	cout << temp << endl;
	index++;
	
	cout << endl << endl;
	cout << "HERE IS THE TABLE:";
	cout << endl << endl;
	table.printHashTable();
	cout << endl << endl;
}