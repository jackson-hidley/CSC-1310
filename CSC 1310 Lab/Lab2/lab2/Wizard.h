/*
Name: Jackson Hidley
Date: 2/5/2020
Title: Wizard.h
*/

#ifndef Wizard_H
#define Wizard_H

class Wizard //creates new class called Wizard
{
	private:
	
	string name;
	int age;
	int height;

	public:
	
	Wizard( string n, int a, int h ) //put the parameters into the private area of the class
	{
		//sets private class variables
		this-> name = n;
		this-> age = a;
		this-> height = h;
	}

	//formats output
	friend ostream& operator << ( ostream& o, Wizard w )
	{
		o << w.name << " , " << w.age << " , " << w.height << endl;
		return o;
	}
};

#endif