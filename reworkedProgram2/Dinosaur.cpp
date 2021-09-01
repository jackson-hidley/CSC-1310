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
string dino::getName()
{
	return this->name;
}

//get the description of the dinosaur
string dino::getDesc()
{
	return this->desc;
}

//get the current life points of the dinosaur
int dino::getLife()
{
	return this->life;
}

//get the current number of hit points of the dinosaur
int dino::getHP()
{
	return this->hp;
}


//set the name of a dinosaur
void dino::setName( string n )
{
	this->name = n;
}

//set the descriptio of a dinosaur 
void dino::setDesc( string d )
{
	this->desc = d;
}


//set the life points a dinosaur will have 
void dino::setLife( int l )
{
	this->life = l;
}

//set the hit points of a dinosaur
void dino::setHP( int h )
{
	this->hp = h;
}


