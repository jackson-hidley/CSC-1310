/*
NAME: Jackson Hidley
DATE: 4/22/2020
TITLE: Driver.cpp
*/

#include <iostream>
#include "Heap.h"
#include "Student.h"
#include <string>

using namespace std;

int main()
{
	Heap* heap1Ptr = new Heap(50); //create a heap of 50
	
	//creates the 10 students that will be put in the heap
	Student student1(2.6, "Cosette Mealbone", "HPC");
	Student student2(4.0, "April Crockette", "CSSC");
	Student student3(3.8, "Beatrix Longbottom", "CYBERSECURITY");
	Student student4(3.9, "Blaire Strange", "DATA SCIENCE");
	Student student5(2.9, "Cybil Lidscrew", "CSSC");
	Student student6(1.4, "Coco Mobo", "DATA SCIENCE");
	Student student7(3.2, "Alabama Joebob", "CSSC");
	Student student8(3.6, "Diem Carpefat", "HPC");
	Student student9(3.9, "Chichi Musicpaper", "CSSC");
	Student student0(2.7, "Bentlee Caryellow", "CYBERSECURITY");
	
	//inserts the students in the heap
	heap1Ptr->insert(student1);
	heap1Ptr->insert(student2);
	heap1Ptr->insert(student3);
	heap1Ptr->insert(student4);
	heap1Ptr->insert(student5);
	heap1Ptr->insert(student6);
	heap1Ptr->insert(student7);
	heap1Ptr->insert(student8);
	heap1Ptr->insert(student9);
	heap1Ptr->insert(student0);
	
	cout << "Heap 1: " << endl;
	while (!heap1Ptr->isEmpty())
    {
		cout << "# of nodes: " << heap1Ptr->getNumberOfNodes() << endl;
		cout << "Height: "     << heap1Ptr->getHeight() << endl;
		heap1Ptr->remove();
		cout << endl << endl;
    }  // end while
}