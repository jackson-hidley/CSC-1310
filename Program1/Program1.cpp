/*
Name: Jackson Hidley
Date: 1/29/2020
Title: Program1.cpp
*/

#include <iostream>
#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"

using namespace std;

int main()
{
	int libMax, //The max about of games the users libary can hold
		userChoice; //users choice from the meu
	string fileName; //name of file that hold the list of games
	
	cout << "How many video games can your libary hold? ";
	cin >> libMax;
	
	videoGameLib libArray(libMax); //dynamically allocated videoGameLib object
	do
	{
		//Print menu and ask user for choice
		cout << "What would you like to do?" << endl;
		cout << "1.\tLoad video game from file.\n";
		cout << "2.\tSave video game to a file.\n";
		cout << "3.\tAdd a video game.\n";
		cout << "4.\tRemove video game.\n";
		cout << "5.\tDisplay all video games.\n";
		cout << "6.\tRemove ALL video games from this libary and end program.\n";
		cout << "CHOOSE 1-6: ";
		cin >> userChoice;
		
		while(userChoice < 1 || userChoice > 6 )
		{
			cout << "\nOops!  That was an invalid choice.\n";
			cout << "CHOOSE 1-6:  ";
			cin >> userChoice;
		}
		
			switch( userChoice )
			{
				case 1:	cout << "What is the name of the file that you want to load?\n";
						cin >> fileName;
						libArray.loadVideoGamesFromFile( fileName );
						break;
				
				case 2: cout << "What is the name of the file you that you want to save to?" << endl << "FILENAME: ";
						cin >> fileName;
						libArray.saveToFile( fileName );
						break;
				
				case 3: libArray.addVideoGameToArray();
						break;
				
				case 4: libArray.removeVideoGameFromArray();
						break;
				
				case 5: libArray.displayVideoGames();
						break;
				
				case 6: //delete [] *libArray;
						cout << "Deleting the library." << endl;
						break;
			}
		
	}while( userChoice != 6 );
	
	cout << "GOODBYE!" << endl;
}