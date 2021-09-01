/*
Name: Jackson Hidley
Purpose: Recusion Practice
Date: 2/5/2020
Title: Driver.cpp
*/

#include <iostream>
using namespace std;

int arraySum( int array[], int size );

int main() 
{	
	int mysize = 10;
	int myarray[mysize];
	//ask user for integers to be put in the array
	cout << "Input intergers to go into the array." << endl;
	for ( int i = 0; i < mysize; ++i ) 
	{
		cin >> myarray[i];
	}
	//printout the sum of the array
	cout << "Total of the array is: " << arraySum( myarray, mysize ) << endl;
	
	return 0;
}

int arraySum( int array[], int size ) //adds all of the array elements togeather and returns the sum 
{
	if ( size >= 0 )
	{
	return arraySum( array, size - 1 ) + array[size]; //recrusion 
	}
	else 
	{
		return 0;
	}
}