/*
	Title:  Lab3.cpp
	Author: YOUR NAME HERE!!!
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrWithoutSpaces, userStrModified;
	userStrWithoutSpaces->userStrModified;
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << sumOfNumbers( num ) << endl;//print out the result of the sumOfNumbers function here
				
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				cout << isMember( myArray, num, ARRAY_SIZE );//print if the value that the user entered is in the array or not here
				
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				cout << stringReverser(userString, userString.length() ) << endl;//call string reverser function here
				
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				multiply(num1, num2);//print out the value returned from the multiply function here
				
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!

// Case 1
int sumOfNumbers( int num)
{
	if( num > 0 )
		return num + sumOfNumbers(num-1);
	
	else if( num < 0 )
		return num + sumOfNumbers(num+1);

	else
		return num;
}

// Case 2
bool isMember( int* arry, int val, int size )
{
	if( isMember ( arry, val, size-1 ) && size >= 0)
		return true;
	
	else
		return false;
}


// Case 3
void stringReverser( string str, int l )
{
	int i = 0;
	
	if( str.length() == l )
	{
		return;
	}
	
	stringReverser( str, l-1 );
	
	if( i <= l )
	{
		swap( str[i++], str[l] );
	}
}


// Case 4
bool isPalindrome( string )
{
	
	

}


// Case 5
int multiply( int x, int y )
{
	if( y > 0 )
		return x + multiply( x, y - 1 );
	else if( y < 0 )
		return x + multiply( x, y + 1 );
	else 
		return 0;
}