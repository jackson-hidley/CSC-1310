/*
NAME: Jackson Hidley
DATE: 2/24/2020
TITLE: DinosaurFight.cpp
*/

#include "LinkedList.h"
#include "Dinosaur.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	LinkedList<dino> list;
	string player1, player2;//holds the players names
	int player1Dino, player2Dino;//holds the choice of what dinosaur the player selects
	string name, desc;//used for dino
	int hp, life;//used for dinos
	int numDinos;//hold the number of dinosaurs in the list
	char enter;//used for "PRESS ENTER TO CONTINUE"
	bool search;//used with binarySearch() to see if a dinosaur already exists in the list
	bool againBool;//used in the switch to see if the players want to play again
	bool valid; //in a do while statement seeing if the play again char is valid
	bool dinoIn;
	char againChar; //used in switch to play again
	string temp;
	char choice;
	int roundNum = 1;//keeps track of the # of rounds
	char printDesc;//used to ask users if they want to print the descriptions of all of the diosaurs
	bool ver = false;
	int r; //used for randomly generated int	
	srand(time(NULL));//set seed for rand
	//open the file "dinosaurFile.txt" to read in the dinosaurs
	fstream myFile;
	myFile.open( "dinosaurFile.txt" );

	while( !myFile.eof() )
	{
		//get information from the file
		getline( myFile, name );
		getline( myFile, desc );
		myFile >> life;
		myFile >> hp;
		myFile.ignore();
		//create a dino temp holder
		dino temp( name, desc, life, hp );
		//search to see if the dinosaur already exists
		search = list.binarySearch( temp );
		//if the dinosaur does NOT already exists, create the dinosaur, and tell the players that it was added to the list
		if( search == false )
		{	
			list.appendNode( temp );
			numDinos++;

			cout << name << " was added to the list." << endl;
		}
		//tell the players that the dinosaur already exists, so it was not added again to the list
		else
		{
			cout << name << " was skipped becaue it was already in the list." << endl;
		}
	}
	//mergeSort the list of dinosaurs by name
	//list.callMergeSort();
	//close myFile
	myFile.close();
	//print out how many dinos have been added to the list
	cout << numDinos << " dinosaurs have been added to the list." << endl;
	
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
	cout << endl << endl;
	
	do
	{
		//get the players names
		cout << "PLAYER 1 NAME:   ";
		getline( cin, player1 );
		cout << "PLAYER 2 NAME:   ";
		getline( cin, player2 );
		cout << endl;
		
		cout << "Before you have to select your dinosaur," << endl;
		cout << "do you want to print details about each one" << endl;
		cout << "'( Y / N ): ";

		while( !ver )
		{
			cin >> printDesc;	
			
			switch( printDesc )
			{
				case 'N':
				case 'n':	ver = true;
							break;
				case 'Y':
				case 'y':	list.displayList();
				
							ver = true;
							break;
							
				default: 	ver = false;
							cout << "Invalid choice. Please try again." << endl;
							cout << "( Y / N ): ";
			}
		}
			
		cout << player1 << ", ENTER THE DINOSAUR NUMBER YOU WISH TO USE TO FIGHT!!!" << endl;
		//print out just the dinosaur names which are numbered
		list.printMenu();
		//verify that the players input is valid
		int x;
		do
		{
			
			cout << player1 << " DINOSAUR CHOICE (1-" << numDinos << ")" << endl;
			cin >> player1Dino;
			//subtract 2 to match with the elements
			player1Dino--;
			player1Dino--;
			
			//if player1's choice is less than 0 or greater than the number of dinosaurs, execute
			if( player1Dino < numDinos && player1Dino >= -1 )
			{
				dinoIn = true;
				cout << "Valid Input." << endl;
			}
			else
			{
				cout << "Invalid option. Please try  again." << endl;
				dinoIn = false;

			}
			
		}while( !dinoIn );//loop until player1 chooses a valid input
		
		//get the selected dinosaurs data form the LinkedList and set it to dino1
		dino dino1 = list.getData( player1Dino );
		
		cout << player2 << ", ENTER THE DINOSAUR NUMBER YOU WISH TO USE TO FIGHT!!!" << endl;
		//print out just the dinosaur names which are numbered
		list.printMenu();
		
		//verify that the players input is valid
		do
		{
			cout << player2 << " DINOSAUR CHOICE (1-" << numDinos << ")" << endl;
			cin >> player2Dino;
			//subtract 1 to match with the elements
			player2Dino--;
			player2Dino--;
			
			//if player2's choice is less than 0 or greater than the number of dinosaurs, execute
			if( player2Dino > numDinos || player2Dino < -1 )
				cout << "Invalid option. Please try  again." << endl;
			else
				break;
			
		}while( true );//loop until player2 chooses a valid input
		
		//get the selected dinosaurs data form the LinkedList and set it to dino2
		dino dino2 = list.getData( player2Dino );
		
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
		cout << endl << endl;
		
		while( (dino1.getLife() > 0) && (dino2.getLife() > 0) && (roundNum < 4) )
		{
			cout << "*****************************" << "ROUND " << roundNum << "*****************************" << endl;
	
			//player1's turn
			cout << player1 << ", HIT ENTER TO ROLL THE DIE TO DO DAMAGE TO " << player2 << "\'s " << dino2.getName() << endl << endl;
			
			cin >> enter;
			cin.ignore();
			
			r = rand() % 1 + 6;
			//subract the amount of life points to the dinosaur that was hit
			dino2.setLife( dino2.getLife() - ( r * dino1.getHP() ) );
			
			cout << dino2.getName() << " NOW HAS " << dino2.getLife() << endl;
			
			if( dino2.getLife() <= 0 )
			{
				cout << player1 << " and there " << dino1.getName() << " won!" << endl;
				break;
			}
		
//**********************************************************************************************************************************************************************
		
			//player2's turn
			cout << player2 << ", HIT ENTER TO ROLL THE DIE TO DO DAMAGE TO " << player1 << "\'s " << dino1.getName() << endl << endl;
			
			cin >> enter;
			cin.ignore();
			
			r = rand() % 1 + 6;
			//subract the amount of life points to the dinosaur that was hit
			dino1.setLife( dino1.getLife() - ( r * dino2.getHP() ) ); 
			
			cout << dino1.getName() << " NOW HAS " << dino1.getLife() << endl;
			
			if( dino1.getLife() <= 0 )
			{
				cout << player2 << " and there " << dino2.getName() << " won!" << endl;
				break;
			}
			
			if( roundNum > 3 && dino1.getLife() > 0 && dino2.getLife() > 0 )
			{
				if( dino1.getLife() > dino2.getLife() )
				{
					cout << player1 << " and there " << dino1.getName() << " won!" << endl;
				}
				else if( dino1.getLife() < dino2.getLife() )
				{
					cout << player2 << " and there " << dino2.getName() << " won!" << endl;
				}
				else
				{
					cout << "Some how it was a draw." << endl;
				}
			}
		}

		cout << endl << endl << endl;
		
		do
		{
			cout << "Would you like to play again? (y/n)	";
			cin >> againChar;
			
			switch ( againChar )
			{
				case 'y':
				case 'Y': valid = true;
						  againBool = true;
						  break;
				case 'n':
				case 'N': valid = true;
						  againBool = false;
						  break;
				default:  valid = false;
						  cout << "You did not enter either \'y\' or \'n\'.";
			}
			
		}while( !valid );//loop until there is a valid input
		
	}while( againBool );//loop when the players want to play again
}