/*
NAME: Jackson Hidley
DATE: 4/01/2020
TITLE: Lab7.cpp
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//Function definitions
int getStudentData( int );
void sort( vector<int>& );
void print( vector<int> );
void getAverage( vector<int> );
void getMedian( vector<int> );
void getMode( vector<int> );

int main()
{
	vector<int>  s;
	int temp;
	int studentNum = 1;
	
	//call getStudentData	
	cout << "Enter the number of hours each student spent watching Netflix." << endl;
	cout << "Enter -1 when you are finished entering student data." << endl;
	
	do
	{
		
		temp = getStudentData( studentNum );
		
		if( temp != -1 )
		{
			s.push_back( temp );
			studentNum++;
		}
			
	}while( temp != -1 );
	
	sort( s );
	print( s );
	getAverage( s );
	getMedian( s );
	getMode( s );
}


//get student data from the user
int getStudentData( int num )
{
	int x;

	do
	{
		cin.clear();
		cout << "Student " << num << ": ";
		cin >> x;
		
		//verify for int input
		if( cin.fail() )
		{
			cout << "Invalid input. Please try again." << endl;
		}
	}while( cin.fail() );
	
	return x;
}
	

//Insertion sort algorithm
void sort( vector<int> &data )
{
	int i, j, temp;
	
	cout << "Sorting the vector with Insertion Sort algorithm." << endl;
	
	//Insertion sort algorithm
	for ( i = 1; i < data.size(); i++ )
	{
		j = i;
		temp = data[i];
		
		while ( j > 0 && temp < data[j - 1] )
		{
			data[j] = data[j - 1];
			j--;
		}
		data[j] = temp;
	}
}


void print( vector<int> data )
{
	cout << "Hours each student watched Netflix in ascending order: ";
	
	for( int i = 0; i < data.size(); i++ )
	{
		cout << data[i] << " ";
	}
	cout << endl << endl;
}

//print out the number of average hours a student spends on watching Netflix
void getAverage( vector<int> data )
{
	int hold;
	double avg;
	
	//add all of the student hours together
	for( int i = 0; i < data.size(); i++ )
	{
		hold = hold + data[i];
	}
	
	//calculate the average of hours a student spends watching Netflix
	avg = static_cast<double>( hold ) / static_cast<double>( data.size() );
	
	cout << "\t\tNETFLIX STATISTICS" << endl;
	cout << "Average: " << setprecision(2) << fixed << static_cast<double>(avg) << endl;
}


void getMedian( vector<int> data )
{
	double size = static_cast<double>( data.size() ) - 1.0;
	double med;
	
	if( (data.size() ) % 2 != 0 )
	{
		med = static_cast<double>(data[ size / 2.0 ]); 
	}
	else
	{
		med = static_cast<double>( (data[(size - 1) / 2.0] + data[size / 2.0]) / 2.0 );
	}
	
	cout << "Median:	 " << setprecision(2) << fixed << setfill('0') << med << endl;
}



void getMode( vector<int> data )
{
	int number = data[0];
	int mode = number;
	int count = 1;
	int countMode = 1;
	int maxCount = 1;

	for ( int i = 1; i < data.size(); i++ )
	{
		if ( data[i] == number ) 
		{ // count occurrences of the current number
			++count;
		}
		
		else
		{ // now this is a different number
			if ( count > countMode ) 
			{
				countMode = count; // mode is the biggest ocurrences
				mode = number;
			}
			count = 1; // reset count for the new number
			number = data[i];
		}	
	}
	
	if( countMode > 1 )
		cout << "Mode:	 " << mode << endl;
	else 
		cout << "Mode: 	 There is no mode." << endl;
}