/*
NAME: Jackson Hidley
DATE: 3/25/2020
TITLE: HashTable.h
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "HashEntry.h"
#include "Classname.h"

using namespace std;

#ifndef HashTable_H
#define HashTable_H

template<class T>
class HashTable
{
	private:
		int tableSize;
		HashEntry<OPS*>** hashArray;
		
	public:
		HashTable(){}
		HashTable(int size){
			tableSize = size;
			hashArray = new HashEntry<OPS*> *[tableSize];
			for(int i=0; i<tableSize; i++)
				hashArray[i] = NULL;
		}
		~HashTable()
		{
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
				{
					HashEntry<OPS*> *prevEntry = NULL;
					HashEntry<OPS*> *entry = hashArray[i];
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
		
		T getValue(int key)
		{
			int bucketIndex = key % tableSize;
			if(hashArray[bucketIndex] == NULL)
			{
				return NULL;
			}
			else
			{
				HashEntry<OPS*>* entry = hashArray[bucketIndex];
				while(entry != NULL && entry->getKey() != key)
					entry = entry->getNext();
				if(entry == NULL)
					return NULL;
				else
					return entry->getValue();
			}
		}
		
		void putValue(int key, T value)
		{
			int bucketIndex = key % tableSize;
			
			if(hashArray[bucketIndex] == NULL) //no collision
			{
				hashArray[bucketIndex] = new HashEntry<OPS*>(key, value);
			}
			else //collision
			{
				HashEntry<OPS*>* entry = hashArray[bucketIndex];
				while(entry->getNext() != NULL)
					entry = entry->getNext();
				if(entry->getKey() == key)
					entry->setValue(value);
				else
					entry->setNext(new HashEntry<OPS*>(key, value));
			}
		}
		
		void removeValue(int key)
		{
			HashEntry<OPS*> *entry;
			HashEntry<OPS*> *prevEntry;
			int bucketIndex = key% tableSize;
			if(hashArray[bucketIndex] != NULL)
			{
				//traverse through list and find matched key
				prevEntry = NULL;
				entry = hashArray[bucketIndex];
				while(entry->getNext() != NULL & entry->getKey() != key)
				{
					prevEntry = entry;
					entry = entry->getNext();
				}
				if(entry->getKey() == key) //found the key in previous while loop
				{
					if(prevEntry == NULL)
					{
						HashEntry<OPS*> *nextEntry = entry->getNext();
						delete entry;
						hashArray[bucketIndex] = nextEntry; //re-link list 
					}
					else
					{
						HashEntry<OPS*> *next = entry->getNext();
						delete entry;
						prevEntry->setNext(next);
					}
				}
			}		
		}
		
		void printHashTable()
		{
			cout << "----------\n";
			
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
				{
					HashEntry<OPS*> *entry = hashArray[i];
					while(entry->getNext() != NULL)
					{
						
						cout << "Next---->";
						entry->getValue()->printForHash();
						entry = entry->getNext();
					}
					
					cout << "---->";
					entry->getValue()->printForHash();
					cout << "\n";
				}
				else
					cout << setw(8) << -1 << "\n";
			}
			cout << "----------\n\n";
		}
	
};
	
#endif