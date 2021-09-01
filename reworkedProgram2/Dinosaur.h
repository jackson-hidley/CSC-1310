/*
NAME: Jackson Hidley
DATE: 2/24/2020
TITLE: Dinosaur.h
*/

#include <string>

using namespace std;

#ifndef Dinosaur_H
#define Dinosaur_H

class dino
{
	private:
	string name;
	string desc;
	int life, hp;
	
	public:
	//default constructer
	dino(){}
	//overloaded constructer
	dino( string n, string d, int l, int h )
	{
		name = n;
		desc = d;
		life = l;
		hp = h;
	}
	~dino(){}
	string getName();
	string getDesc();
	int getLife();
	int getHP();
	
	void setName( string );
	void setDesc( string );
	void setLife( int );
	void setHP( int );
};

#endif