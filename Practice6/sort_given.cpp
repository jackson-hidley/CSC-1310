/*
	Purpose:	In-class Practice for sorting
*/
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

void displayArray(int*, int);
void changeToChar(int*,int);
void mergeSort(int*, int, int );
void merge( int*, int, int, int );
void swapping(int &, int &);
void display(int *, int );

int main()
{	

	string plainText;
	int i;
    cout << "\n\nEnter a string of characters: ";
    getline(cin, plainText);
	
	int n=plainText.size();
	int myArr[n];
    int originalArray[n];
	
    for ( i = 0; i < n; i++) 
	{
		myArr[i] = static_cast<int>(plainText[i]);
    }
    cout << "\n\n#################################################";
	//display the array
	cout << "\n\nArray before changing to ASCII values: " << plainText << endl;
    cout << "ASCII Array before Sorting: ";
	displayArray(myArr,n);
	
	//sort the array
	mergeSort( myArr, 0, n );

	//display the array
    cout << "\n\nASCII Array after Sorting: ";
	displayArray(myArr,n);
	changeToChar(myArr,n);
	cout << "\n#################################################";
	cout << endl << endl;

	return 0;
}

void displayArray(int *arr, int size)
{
	for(int i=0; i<size; i++)
	{	
		cout << arr[i]<< " ";
	}
}

void changeToChar(int *r,int n) 
{
   int i;
   char s[n];
   cout<<"\n\nThe sorted string is = ";
   for ( i = 0; i < n; i++) 
   {
	   s[i]=static_cast<char>(r[i]);
       cout<<s[i];
   }
   cout<<"\n"; 
}

void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}

// left( l ) right ( r )
void mergeSort( int arry[], int l, int r )
{
	int mid = 0; 
	
	if( l < r )
	{
		mid = ( l + r ) / 2; //find the mid-pointer
		
		//Recursively sort left and right 
		mergeSort( arry, l, mid );
		mergeSort( arry, mid + 1, r );
		
		//merge left and right partiution in sorted order
		merge( arry, l, mid, r );
		
	}
}

void merge( int arry[], int l, int mid, int r )
{
	int mergedSize = r - l + 1;
	int mergePos = 0;
	int leftPos = 0;
	int rightPos = 0;
	int* mergedNums = new int[ mergedSize ];
	
	leftPos = l;
	rightPos = mid + 1;
	
	//add smallest element from left to right 
	while( leftPos <= mid && rightPos <= r )
	{
		if( arry[ leftPos ] < arry[ rightPos ] )
		{
			mergedNums[ mergePos ] = arry[ leftPos ];
			++leftPos;
		}
		else
		{
			mergedNums[ mergePos ] = arry[ rightPos ];
			++rightPos;
		}
		
		++mergePos;
	}
	
	//if left partition is not empty, add remaining elements
	while( leftPos <= mid )
	{
		mergedNums[ mergePos ] = arry[ leftPos ];
		++leftPos;
		++mergePos;
	}
	
	//if right partitiion is not empty, add remaiing elements to merged nums
	while (rightPos <= r)
	{
		  mergedNums[ mergePos ] = arry[ rightPos ];
		  ++rightPos;
		  ++mergePos;
	}
	
	//copy merged numbers back
	for( mergePos = 0; mergePos < mergedSize; ++mergePos )
	{
		arry[ l + mergePos ] = mergedNums[ mergePos ];
	}
		
	delete [] mergedNums;
}