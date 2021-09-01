/*
NAME: Jackson Hidley
DATE: 3/11/2020
TITLE: HashEntry.h
*/



#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>
#include <string>
using namespace std;

class HashEntry
{
	private:
		string key;
		string value;
		HashEntry* next;
		
	public:
		HashEntry( string k, string v )
		{
			this->key = k;
			this->value = v;
			this->next = NULL;
		}
		
		string getKey()
		{
			return key;
		}
		string getValue()
		{
			return value;
		}
		HashEntry* getNext()
		{
			return next;
		}
		void setNext(HashEntry *next)
		{
			this->next = next;
		}
		void setValue(string v)
		{
			value = v;
		}
};

#endif