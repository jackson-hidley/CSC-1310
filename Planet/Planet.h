//Planet.h

#ifndef Planet_H
#define Planet_H

#include <iostream>
using namespace std;

class Planet
{
	private:
		float minTempF;
		float maxTempF;
		float radiusMiles;
	
	public:
		Planet(float, float, float);//Constroctor
		~Planet()//Destructure
		{
			  cout << "\nI am in the destructor of planets!\n";
		}
		void setMinTempF(float);
		void setMaxTempF(float);
		void setRadiusMiles(float);
		
		float getMinTempF() const
		{	
		return minTempF;
		}
		
		float getMaxTempF() const
		{	
			return maxTempF;	
		}
		
		float getRadiusMiles() const
		{	
			return radiusMiles;
		}
};
#endif
