/*
NAME: Jackson Hidley
DATE: 3/25/2020
TITLE: HashEntry.h
*/

#include <iostream>
#include "Classname.h"

using namespace std;

#ifndef HASHENTRY_H
#define HASHENTRY_H

template<class T>
class HashEntry
{
	private:
		int key;
		T value;
		HashEntry* next;
		
	public:
		HashEntry(int k, T v)
		{
			this->key = k;
			this->value = v;
			this->next = NULL;
		}
		
		int getKey()
		{
			return key;
		}
		T getValue()
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
		void setValue(T v)
		{
			value = v;
		}
};

#endif