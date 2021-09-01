/*
Name: Jackson Hidley
Date: 2/5/2020
Title: Cat.h
*/

#ifndef cat_H
#define cat_H

class Cat //creates new class called Cat
{
	private:
	
	string name,
		   breed,
		   color;
		   
	int 	age;
	
	public:
	
	Cat( string n, string b, string c, int a ) //creates a new cat passenger
	{
		//sets private class variables
		this-> name = n;
		this-> breed = b;
		this -> color = c;
		this -> age = a;
	}

	//formats output
	friend ostream& operator << ( ostream& o, Cat c )
	{
		o << c.name << " , " << c.breed << " , " << c.color << " , " << c.age << endl;
		return o;
	}

};



#endif