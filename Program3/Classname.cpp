/*
NAME: Jackson Hidley
DATE: 3/25/2020
TITLE: Classname.cpp
*/

#include <iomanip>
#include <iostream>
#include <string>
#include "Classname.h"

using namespace std;

//OPS constructer
OPS::OPS( int id, string n, string aff, int release, int c, bool def, bool at, string ut, bool elite, int ar, int sp, int dif )
{
	idNum = id;
	name = n;
	operative = aff;
	seasonReleased = release;
	cost = c;
	isDef = def;
	isAtck = at;
	utility = ut;
	hasEliteSkin = elite;
	armor = ar;
	speed = sp;
	difficulty = dif;
}

int OPS::getIdNum()
{
	return idNum;
}

string OPS::getName()
{
	return name;
}

void OPS::printForHash()
{
	cout << "ID:\t" << idNum << ", NAME:\t" << name;
}

void OPS::printInfo()
{
	cout << "ID:\t" << idNum << endl;
	cout << "NAME:\t" << name << endl;
	cout << "AFFILIATION:\t" << operative << endl;
	cout << "SEASON RELEASED:\t" << seasonReleased << endl;
	cout << "COST:\t" << cost << endl;
	
	if( isDef == true)
		cout << "DEFENSIVE OPERATOR?\t" << "Yes" << endl;
	else
		cout << "DEFENSIVE OPERATOR?\t" << "No" << endl;
	
	if( isAtck == true )
		cout << "ATTACK OPERATOR?\t" << "Yes" << endl;
	else
		cout << "ATTACK OPERATOR?\t" << "No" << endl;
	
	cout << "UTILITY:\t" << utility << endl;
	
	if( hasEliteSkin == true )
		cout << "Operator has an elite skin" << endl;
	else
		cout << "Operator does not have an elite skin" << endl;
	
	cout << "ARMOR:\t" << armor << endl;
	cout << "SPEED:\t" << speed << endl;
	cout << "DIFFICULTY:\t" << difficulty << endl;
	cout << endl;
}