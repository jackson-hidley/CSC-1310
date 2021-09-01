/*
Name: Jackson Hidley
Date: 2/5/2020
Title: Train.h
*/

#include <iostream>
#include <string>
using namespace std;

#ifndef Train_H
#define Train_H



	//create a template class called T
	template < class T >
	//create a class called Train
	class Train
	{
		private:
		string name,
			   homeTown;
		int capacity;
		int currPass;
		T* passengers; //creates a template class T pointer
		
		public:

	Train( string n, string ht, int c ) //creates a new train
	{
		//sets private class variables
		this-> name = n;
		this-> homeTown = ht;
		this-> capacity = c;
		this-> currPass = 0;
		this-> passengers = new T [capacity];
	}

	~Train()//destructure
	{
		delete [] passengers; //deletes the dynamicly allocated array
	}

	string getTrainName() //access private class name and return the name of the train
	{
		return name;
	}

	void addPassenger( T NewTrain )
	{
		//check to see if the train is already at full capacity. I the train is not at full capacity, then add a new passenger
		if( currPass == capacity )
		{
			cout << "This train is already at full capacity. " << endl;
		}
		else
		{
			this-> passengers[currPass] = NewTrain;
			this-> currPass = currPass + 1;
			
		}
	}

	void printPassengers()//print out all of the passengers on the train
	{
		for( int i = 0; i < currPass; ++i )
		{
			cout << *passengers[i] << endl;
		}
	}
	};

#endif