/*
NAME: Jackson Hidley
DATE: 3/11/2020
TITLE: HashTable.h
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "HashEntry.h"
using namespace std;

class HashTable
{
	private:
		int tableSize;
		HashEntry** hashArray;
		
	public:
		HashTable (int size )
		{
			tableSize = size;
			hashArray = new HashEntry*[tableSize];
			for(int i=0; i<tableSize; i++)
				hashArray[i] = NULL;
		}
		~HashTable()
		{
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
				{
					HashEntry *prevEntry = NULL;
					HashEntry *entry = hashArray[i];
					while(entry != NULL)
					{
						prevEntry = entry;
						entry = entry->getNext();
						delete prevEntry;
					}
				}
			}
			delete [] hashArray;
		}

		string putValue( string key, string value, int index )
		{
			int bucketIndex = index % tableSize;
			cout << "BUCKET " << bucketIndex << endl;
			
			if(hashArray[bucketIndex] == NULL) //no collision
			{
				hashArray[bucketIndex] = new HashEntry(key, value);
			}
			else //collision
			{
				HashEntry* entry = hashArray[bucketIndex];
				while(entry->getNext() != NULL)
					entry = entry->getNext();
				if(entry->getKey() == key)
					entry->setValue(value);
				else
					entry->setNext(new HashEntry(key, value));
			}
			cout << "In putValue. Key = " << key << endl;
			return key;
		}

		void printHashTable()
		{
			cout << "----------\n";
			
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
				{
					HashEntry* entry = hashArray[i];
					while(entry->getNext() != NULL)
					{
						cout << "---->" << setw(8) << entry->getValue();
						entry = entry->getNext();
					}
					cout << "---->" << setw(8) << entry->getValue();
					cout << "\n";
				}
				else
					cout << setw(8) << -1 << "\n";
			}
			cout << "----------\n\n";
		}
	
};


#endif