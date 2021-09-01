//Jackson Hidley
//Date: 1/24/2020

#include <iostream>
#include <iomanip>
#include "Planet.h"

using namespace std;


int main()
{
	float minTemp, maxTemp, radius;
	
	cout << "What is the min. Temp of the planet in F? ";
	cin >> minTemp;
	
	cout << "What is the max Temp of the planet in F? ";
	cin >> maxTemp;
	
	cout << "What is the radius of the planet in miles? ";
	cin >> radius;
	
	//Create a Planet Object
	Planet mercury(minTemp, maxTemp, radius);
	
/* 	mercury.setMinTempF(-279.67);
	mercury.setMaxTempF(800.33);
	mercury.setRadiusMiles(1516.0); */
	
	//Display the Planet's min Temp, max Temp, and radius
	cout << "Min Temp: " << mercury.getMinTempF() << endl;
	cout << "Max Temp: " << mercury.getMaxTempF() << endl;
	cout << "Radius : " << mercury.getRadiusMiles() << endl;
}