/*
NAME: Jackson Hidley
DATE: 3/11/2020
TITLE: Stack.h
*/
#include <iostream>
#include <string>
using namespace std;

#ifndef Stack_H
#define Stack_H

template < class T >
class Stack
{
	private:
		struct ListNode
		{
			T data;
			struct ListNode* next;//points to the next node
		};
		
		ListNode* head;
		ListNode* tail;

	
	public:
		Stack()
		{
			head = NULL;
			tail = NULL;
		}
		
		void push( T str )
		{ 
			// create new node temp and allocate memory 
			ListNode* temp; 
			temp = new ListNode(); 
		  
			// check if stack is full
			if (!temp) { 
				cout << "\nHeap Overflow"; 
			} 
		  
			// initialize str into temp data field 
			temp->data = str; 
		  
			// put head pointer reference into temp next 
			temp->next = head; 
		  
			// make temp as head of Stack 
			head = temp; 
		} 
		
		T pop()
		{ 
			T tempData;
			// check for stack underflow 
			if (head == NULL)
			{ 
				cout << "\nStack Underflow" << endl; 
			} 
			else 
			{ 
				// head assign into temp 
				tempData = head->data; 
				// assign second node to head 
				if( head->next != NULL )
					head = head->next; 
				else
					head = NULL;
				// release memory of head node 
				return tempData;
			} 
		} 
		
		//check to see if the stack is empty or not
		bool isEmpty()
		{
			//return true if empty
			if( head == NULL )
			{
				return true;
			}
			//return false if not empty
			else
			{
				return false;
			}
		}
	
};

#endif