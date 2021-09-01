#include <iostream>
#include "Planet.h"
using namespace std;


//Constructor
	Planet::Planet( float minTemp, float maxTemp, float radius )
	{
		this->minTempF = minTemp;
		this->maxTempF = maxTemp;
		this->radiusMiles = radius;
		cout << "I am a constroctor!\n"; 
	}
		
//Set the min temp	
	void Planet::setMinTempF(float min)
	{
	minTempF = min;
	}
	
//Set the max temp	
	void Planet::setMaxTempF(float max)
	{
	maxTempF = max;
	}
	
//Set the radius	
	void Planet::setRadiusMiles(float radius)
	{
	radiusMiles = radius;
	}
