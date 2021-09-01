/*
NAME: Jackson Hidley
DATE: 3/25/2020
TITLE: main.cpp
*/


#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"
#include "HashEntry.h"
#include "Classname.h"

using namespace std;

//function definitions
void printMenu();
void loadFile( HashTable<OPS*> *myTable );
void manualEntry( HashTable<OPS*> *myTable );
void searchData( HashTable<OPS*> *myTable );
void deleteData( HashTable<OPS*> *myTable );
void endProgram();

int main()
{
	int key;
	bool valid;
	bool play = true;
	HashTable<OPS*> *myTable = new HashTable<OPS*>(10);
	
	do
	{
		do
		{
			printMenu();
			int choice;
			cout << "CHOICE( 1-6 ): ";
			cin >> choice;
			
			switch(choice)
			{
				case 1:	
						loadFile( myTable );
						valid = true;
				break;
				case 2:
						manualEntry( myTable );
						valid = true;
				break;
				case 3:
						searchData( myTable );
						valid = true;
				break;
				case 4:
						deleteData( myTable );
						valid = true;
				break;
				case 5:
						myTable->printHashTable();
						valid = true;
				break;
				case 6:
						play = false;
						endProgram();
						valid = true;
				break;
				default:
						cout << "Invalid input. Please try again." << endl;
						valid = false;
			}
				
		}while( valid != true );
	}while( play );

}

//print out the menu options
void printMenu()
{
	cout << "1. Add Operators From File" << endl;
	cout << "2. Add Operator Manually" << endl;
	cout << "3. Search for Operator" << endl;
	cout << "4. Delete a Operator" << endl;
	cout << "5. Print Hash Table" << endl;	
	cout << "6. End Program" << endl;
}
	
//load data from a file 
void loadFile( HashTable<OPS*> *myTable )
{
	fstream myFile;
	myFile.open("dataFile.txt");
	
	int idNum;//used as the key in the hash table 
	string name;//name of the operator
	string operative;//what op the operator was from (ex: S.A.S, FBI, etc)
	int seasonReleased;//the season the operator was released
	int cost;//how much Renown is needed to buy the operator
	bool isDef;//true if the operator can be used on defense rounds
	int def;
	bool isAtck;//true if the operator can be used on attack rounds
	int atck;
	string utility;//the operator's special gadget
	bool hasEliteSkin;//true if the operator has an elite skin available
	int skin;
	int armor;//1-3 1 having the least amount of armor, and 3 having the most
	int speed;//1-3 1 being the slowest, and 3 being the fastest
	int difficulty;//1-3 1 meaning the operator is the easiest to use, and 3 meaning the operator is the hardest to use
	

	if( myFile.is_open() )
	{
		while( !myFile.eof() )
		{
			myFile >> idNum;
			myFile.ignore();
			getline( myFile, name );			
			getline( myFile, operative );
			myFile >> seasonReleased;
			myFile >> cost;
			myFile >> def;
			//set input to true or false
			if( def == 1 )
			{
				isDef = true;
			}
			else if ( def == 0 )
			{
				isDef = false;
			}
			else
			{
				cout << "Error geting isDef. Setting it to false." << endl;
				isDef = false;
			}
			
			myFile >> atck;
			//set input to true or false
			if( atck == 1 )
			{
				isAtck = true;
			}
			else if ( atck == 0 )
			{
				isAtck = false;
			}
			else
			{
				cout << "Error geting isAtck. Setting it to false." << endl;
				isAtck = false;
			}
			myFile.ignore();
			getline( myFile, utility );
			
			myFile >> skin;
			//set input to true or false
			if( skin == 1 )
			{
				hasEliteSkin = true;
			}
			else if ( skin == 0 )
			{
				hasEliteSkin = false;
			}
			else
			{
				cout << "Error geting hasEliteSkin. Setting it to false." << endl;
				hasEliteSkin = false;
			}
			
			myFile >> armor;
			myFile >> speed;
			myFile >> difficulty;
			
			OPS* temp;
			temp = new OPS( idNum, name, operative, seasonReleased, cost, isDef, isAtck, utility, hasEliteSkin, armor, speed, difficulty );
			myTable->putValue( idNum, temp );			
			cout << "Entering operator "<< name << " with ID " << idNum << endl;
				
		}
	}
	else
		cout << "Error opening file." << endl;
	
	myFile.close();

}


void manualEntry( HashTable<OPS*> *myTable )
{	
	int idNum;//used as the key in the hash table 
	string name;//name of the operator
	string operative;//what op the operator was from (ex: S.A.S, FBI, etc)
	int seasonReleased;//the season the operator was released
	int cost;//how much Renown is needed to buy the operator
	bool isDef;//true if the operator can be used on defense rounds
	bool isAtck;//true if the operator can be used on attack rounds
	string utility;//the operator's special gadget
	bool hasEliteSkin;//true if the operator has an elite skin available
	int armor;//1-3 1 having the least amount of armor, and 3 having the most
	int speed;//1-3 1 being the slowest, and 3 being the fastest
	int difficulty;//1-3 1 meaning the operator is the easiest to use, and 3 meaning the operator is the hardest to use
	bool valid;
	
	do
	{
		cin.clear();
		cout << "ID: ";
		cin >> idNum;
		
	}while( idNum <= 0 );

	cout << "NAME: ";
	cin.ignore();
	getline( cin, name );
	
	cout << "AFFILIATIOM: ";
	cin.ignore();
	getline( cin, operative );

	do
	{	
		cin.clear();
		cout << "SEASON RELEASED(1-5): ";
		cin >> seasonReleased;
		
		if( seasonReleased > 5 && seasonReleased <= 0 )
			cout << "Invalid entry. Please try again." << endl;
		
		
	}while( seasonReleased > 0 && seasonReleased <= 5 );
	
	do
	{
		cin.clear();
		cout << "COST(0-30000): ";
		cin >> cost;
		
		if( cost >= 0 && cost <= 30000 )
			break;
		else
			cout << "Invalid entry. Please try again." << endl;
		
	}while( !(cost >= 0 && cost <= 30000 ) );
	
	do
	{
		valid = NULL;
		cin.clear();
		char input;
		cout << "DEFENSE OPERATOR?(Y/N): ";
		cin >> input;
		
		switch( input )
		{
			case 'y':
			case 'Y':
						valid = true;
						isDef = true;
						break;
			case 'n':
			case 'N':
						valid = true;
						isDef = false;
						break;
			default:
						valid = false;
		}
		
	}while( !valid );
	
	do
	{
		valid = NULL;
		char input;
		cout << "ATTACK OPERATOR?(Y/N): ";
		cin >> input;
		
		switch( input )
		{
			case 'y':
			case 'Y':
						valid = true;
						isAtck = true;
						break;
			case 'n':
			case 'N':
						valid = true;
						isAtck = false;
						break;
			default:
						valid = false;
		}
		
	}while( !valid );
	
	cout << "SPECIAL UTILITY: ";
	cin.ignore();
	getline( cin, utility );
	
	do
	{
		valid = NULL;
		char input;
		cout << "DOES THE OPERATOR HAVE AN ELITE SKIN?(Y/N): ";
		cin >> input;
		
		switch( input )
		{
			case 'y':
			case 'Y':
						valid = true;
						hasEliteSkin = true;
						break;
			case 'n':
			case 'N':
						valid = true;
						hasEliteSkin = false;
						break;
			default:
						valid = false;
		}
		
	}while( !valid );
	
	do
	{
		valid = NULL;
		cin.clear();
		cout << "ARMOR STAT(1-3): ";
		cin >> armor;
		
		if( armor > 0 && armor < 4 )
			valid = true;
		else
		{
			cout << "Invalid entry. Please try again." << endl;
			valid = false;
		}
		
	}while( !valid );
	
	do
	{
		valid = NULL;
		cin.clear();
		cout << "SPEED STAT(1-3): ";
		cin >> speed;
		
		if( speed > 0 && speed < 4 )
			valid = true;
		else
		{
			cout << "Invalid entry. Please try again." << endl;
			valid = false;
		}
		
	}while( !valid );
	
	do
	{
		valid = NULL;
		cin.clear();
		cout << "DIFFICULTY STAT(1-3): ";
		cin >> difficulty;
		
		if( difficulty > 0 && difficulty < 4 )
			valid = true;
		else
		{
			cout << "Invalid entry. Please try again." << endl;
			valid = false;
		}
		
	}while( !valid );
	
	//create a temp holder and pass it in setValue
	OPS* temp;
	temp = new OPS( idNum, name, operative, seasonReleased, cost, isDef, isAtck, utility, hasEliteSkin, armor, speed, difficulty );
	myTable->putValue( idNum, temp );
	delete temp;
}


void searchData( HashTable<OPS*> *myTable )
{
	int key;
	bool valid;
	OPS* temp;
	
	do
	{
		cin.clear();
		cout << "What is the key of the Operator you are searching for?" << endl;
		cout << "ID:		";
		cin >> key;
		
		if ( key > 0 )
			valid = true;
		else
		{
			cout << "Invalid entry. Please try again." << endl;
			valid = false;
		}
		
	}while( !valid );
	
	temp = myTable->getValue( key );
	
	if( temp == NULL )
	{
		cout << "There are no Operators with that key in the table." << endl << endl;
	}
	else
	{
		myTable->getValue( key )->printInfo();
	}
}


void deleteData( HashTable<OPS*> *myTable )
{
	int key;
	bool valid;
	
	cout << "The following is a list of all of the current Operators:" << endl;
	
	myTable->printHashTable();
	
	do 
	{
		cin.clear();
		cout << "What is the ID of the Operator you wish to remove?" << endl;
		cout << "OPERATOR ID:	";
		cin >> key;
		
		if( key > 0 )
			valid = true;
		else
		{
			cout << "Invalid entry. Please try again." << endl;
			valid = false;
		}
		
	}while( !valid );
	
	myTable->removeValue( key );
	
	cout << "You have removed the operator." << endl << endl;
}


void endProgram()
{
	cout << "You have choose to end the program." << endl;
	cout << "GOODBYE!!!" << endl;
}


