/*
NAME: Jackson Hidley
DATE: 3/25/2020
TITLE: Classname.h
*/

#include <iostream>
#include <string>

using namespace std;

#ifndef Classname_H
#define Classname_H

class OPS
{
	private:
		int idNum;//used as the key in the hash table 
		string name;//name of the operator
		string operative;//what op the operator was from (ex: S.A.S, FBI, etc)
		int seasonReleased;//the season the operator was released
		int cost;//how much Renown is needed to buy the operator
		bool isDef;//true if the operator can be used on defense rounds
		bool isAtck;//true if the operator can be used on attack rounds
		string utility;//the operator's special gadget
		bool hasEliteSkin;//true if the operator has an elite skin available
		int armor;//1-3 1 having the least amount of armor, and 3 having the most
		int speed;//1-3 1 being the slowest, and 3 being the fastest
		int difficulty;//1-3 1 meaning the operator is the easiest to use, and 3 meaning the operator is the hardest to use
	
	public:
	
		OPS(){}
		OPS( int id, string n, string aff, int release, int c, bool def, bool at, string ut, bool elite, int ar, int sp, int dif );
		int getIdNum();
		string getName();
		void printForHash();
		void printInfo();
		
		//over load "<<" operator and format output
		friend ostream& operator << ( ostream& o, OPS op )
		{
			o << "ID: " << op.idNum<< endl;
			o << "NAME: " << op.name << endl;
			o << "AFFILIATION: " << op.operative << endl;
			o << "SEASON RELEASED: " << op.seasonReleased << endl;
			o << "SPECIAL UTILITY: " << op.utility << endl;
			o << "ARMOR: " << op.armor << "	SPEED: " << op.speed << "	DIFFICULTY: " << op.difficulty << endl;
			//****************************************************************************
			if ( op.isAtck == true && op.isDef == false )
				o << "ATTACK/DEFENSE: " << "ATTACK OPERATOR" << endl;
			else if( op.isAtck == false && op.isDef == true )
				o << "ATTACK/DEFENSE: " << "DEFENSE OPERATOR" << endl;
			else if( op.isAtck == true && op.isDef == true )
				o << "ATTACK/DEFENSE: " << "ATTACK AND DEFENSE OPERATOR" << endl;
			else
				o << "ERROR: OPERATOR MUST BE ABLE TO ATTACK OR DEFEND" << endl;
			//****************************************************************************
			if ( op.hasEliteSkin == false )
				o << "The operator does NOT have an elite skin." << endl;
			else
				o << "The operator has an elite skin." << endl;
			//****************************************************************************
			if( op.cost > 0 )
				o << "COST: " << op.cost << " RENOWN" << endl;
			else if( op.cost == 0 )
				o << "COST: " << "FREE" << endl;
			else
				o << "ERROR: CANNOT HAVE A NEGATIVE COST VALUE" << endl;
			//****************************************************************************
		}

};
#endif
	