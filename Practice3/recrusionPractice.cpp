/*
Name: Jackson Hidley
Purpose: Recusion Practice
Date: 2/5/2020
Title: recrusionPractice.cpp
*/

#include "recrusionPractice.h"

double arraySum( double array[], int size )
{
	return arraySum( array, size - 1 ) + array[size];
}