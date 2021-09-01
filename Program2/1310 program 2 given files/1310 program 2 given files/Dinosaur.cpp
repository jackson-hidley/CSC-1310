/*
NAME: Jackson Hidley
DATE: 2/24/2020
TITLE: Dinosaur.cpp
*/

#include "Dinosaur.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;


//get the name of the dinosaur
string dino::getname()
{
	return name;
}

//get the description of the dinosaur
string dino::getDesc()
{
	return desc;
}

//get the current life points of the dinosaur
int dino::getLife()
{
	return life;
}

//get the current number of hit points of the dinosaur
int dino::getHP()
{
	return hp;
}


//set the name of a dinosaur
void dino::setName( string n )
{
	name = n;
}

//set the descriptio of a dinosaur 
void dino::setDesc( string d )
{
	desc = d;
}


//set the life points a dinosaur will have 
void dino::setLife( int l )
{
	life = l;
}

//set the hit points of a dinosaur
void dino::setHP( int h )
{
	hp = h;
}

void dino::printDinos( dino arry, int numDinos )
{
	for( int j = 0; j < numDinos; j++ )
	{
		cout << "****************************************************" << endl;
		cout << "DINOSAUR " <<  j + 1 << ":" >> endl;
		cout << "NAME:	" << arrry[j].getName() << endl;
		cout << "DESCRIPTION:" << endl;
		cout << arry[j].getDesc() << endl << endl;
		cout << "LIFE POINTS:		" << getLife() << endl;
		cout << "HIT POINTS:		" << getHP() << endl << endl;
	}
}

int dino::binarySearch( dino arry, int r, int l, dino x )
{
	if( r >= l )
	{
		int mid = l + ( r - 1 ) / 2;
		
		//if the element is present at the middle itself
		if( arry[ mid ].getName() == x.getName() )
		{
			return mid;
		}
		
		//If the element is smaller than mid, then
		//it can only be present in the left subarray
		if( arry[ mid ].getName() > x.getName() )
		{
			return binarySearch( arry, l, mid - 1, x );
		}
		
		//Else the element can only be present
		//in the right subarray
		return binarySearch( arry, mid + 1, r, x );
	}
	return -1;
}

//print all of the names of the dinosaurs that the user can choose
void printMenu( dino arry, int numDinos )
{
	cout << "*****************************************************" << endl << endl;
	
	for( int i = 0; i < numDinos; i++ )
	{
		cout << setw(20) << i + 1 << "-" << arry[i].getName();
		
		if( i % 3 == 0 )
		{
			cout << endl;
		}
		
	}
	cout << endl << "*****************************************************" << endl << endl;
}