/*
NAME: Jackson Hidley
DATE: 2/12/2020
TITLE: AT_Cast.h
*/

#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;

#ifndef AT_Cast_H
#define AT_Cast_H

	class AT_Cast
	{
		private:
			int ID;
			string name;
			
		public:
			AT_Cast()
			{
				name = "None";
				ID = 0;
			}
			AT_Cast( int num, string n )
			{
				ID = num;
				name = n;
			}
			void setID( int num )
			{
				ID = num;
			}
			void setName( string n )
			{
				name = n;
			}
			int getID()
			{
				return ID;
			}
			string getName()
			{
				return name;
			}
	
			bool operator < ( const AT_Cast& member )
			{
				return this->ID < member.ID;
			}
			
			bool operator > ( const AT_Cast& member )
			{
				return this->ID > member.ID;
			}
			
			friend ostream& operator << ( ostream& strm, AT_Cast &member )
			{
				strm << "Cast ID Number: " << member.ID;
				strm << "\tName: " << member.name << endl;
				return strm;
			}
	};
	
#endif