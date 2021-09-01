/*
NAME: Jackson Hidley
DATE: 3/11/2020
TITLE: fileReverser.cpp
*/


#include "Stack.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	Stack<char> list;
	char line;
	int i = 0;
	char temp;
	
	cout << "Opening file1.txt as input" << endl;
	fstream inFile;
	inFile.open( "file1.txt" );
	cout << "Reading one character at a time from file1.txt and pushing the character on the stack." << endl;
		
	while( inFile.get(line) )
	{
		list.push( line );
		i++;
	}
	cout << i << endl;
	//close the in file 
	inFile.close();
	cout << "Done reading all of file1.txt.  All characters from the file have been pushed on the stack." << endl;
	cout << "Opening file2.txt as output." << endl;
	ofstream outFile;
	outFile.open( "file2.txt" );
	
	cout << "Popping one character at a time from the stack and writing the character to file2.txt." << endl;
	
	for( int j = 0; j < i; j++ )
	{
	temp = list.pop();
	outFile.put(temp);
	}	
	//close the out file
	outFile.close();
	cout << "Done!  See your results in file2.txt." << endl;
}
	