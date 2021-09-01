/*
NAME: Jackson Hidley
DATE: 2/24/2020
TITLE: DinosaurFight.cpp
*/

#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.h"
#include "dinosaur.h"

using namespace std;

int main()
{
	LinkedList list;
	string player1, player2;//player names
	string name, desc;
	string temp; //press enter to continue
	int life, hp, numDinos = 0;
	int search;//used to see if the same dino already exists in the list
	int player1Dino, player2Dino;
	bool again;//used in the switch to see if the players want to play again
	char ag; //used in switch to play again
	char choice;
	int roundNum = 1;//keeps track of the # of rounds
	char printDesc;//used to ask users if they want to print the descriptions of all of the diosaurs
	bool ver = false;
	int r; //used for randomly generated int
	dino arry[1000];
	//open the file "dinosaurFile.txt" to read in the dinosaurs
	fstream myFile;
	myFile.open( "dinosaurFile.txt" );
	
	//read all the information from the file
	while( !myFile.eof() )
	{
		getline( cin, name );
		cout << name << " was added to the list of dinosaurs." << endl;
		getline( cin, desc );
		myFile >> life;
		myFile >> hp;
		
		dino temp( name, desc, life, hp );
		//search to see if the dinosaur already exists
		search = binarySearch( arry, numDinos, 0, temp );
		//if the dinosaur does NOT already exists, create the dinosaur, and tell the players that it was added to the list
		if ( search != -1 )
		{
			dino arry[numDinos]( name, desc, life, hp );
			
			list.appendNode(temp);
			numDinos++;
			//mergeSort the list of dinosaurs by name
			list.merge( 0, numDinos, temp );
			cout << name << " was added to the list." << endl;
		}
		//tell the players that the dinosaur already exists, so it was not added again to the list
		else
		{
			cout << name << " was skipped becaue it was already in the list." << endl;
		}
	}
	//close the file after reading in all of the dinosaurs
	myFile.close();
	//Print out how many dinosaurs have been added frpom the file
	cout << numDinos << " Dinosaurs have been added." << endl;
	
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
	cout << endl << endl;
	
	do{
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
				case 'y':	printDinos( arry, numDinos );
				
							ver = true;
							break;
							
				default: 	ver = false;
							cout << "Invalid choice. Please try again." << endl;
							cout << "( Y / N ): ";
			}
		}
		
		cout << player1 << ", ENTER THE DINOSAUR NUMBER YOU WISH TO USE TO FIGHT!!!" << endl;
		
		//print the menu of dinosaurs that can be choosen
		printMenu( arry, numDinos );
		
		do
		{
			cout << player1 << "DINOSAUR CHOICE (1-" << numDinos << ")" << endl;
			cin >> player1Dino;
			//subtract 1 to match with array
			player1Dino--;
			
			//if player1's choice is less than 0 or greater than the number of dinosaurs, execute
			if( player1Dino >= numDinos || player1Dino <= 0 )
				cout << "Invalid option. Please try  again." << endl;
			else
				break;
			
		}while( true )//loop until player1 chooses a valid input
			
			
		dino dino1 = new ( arry[player1Dino].getName(), arry[player1Dino].getDesc(), arry[player1Dino].getHP(), arry[player1Dino].getLife() );	
			
		cout << player2 << ", ENTER THE DINOSAUR NUMBER YOU WISH TO USE TO FIGHT!!!" << endl;
		
		//print the menu of dinosaurs that can be choosen
		printMenu( arry, numDinos );
		
			do
		{
			cout << player2 << "DINOSAUR CHOICE (1-" << numDinos << ")" << endl;
			cin >> player2Dino;
			//subtract 1 to match with array
			player2Dino--;
			
			//if player2's choice is less than 0 or greater than the number of dinosaurs, execute
			if( player2Dino >= numDinos || player2Dino <= 0 )
				cout << "Invalid option. Please try  again." << endl;
			else
				break;
			
		}while( true )//loop until player2 chooses a valid input
		
		dino dino2 = new ( arry[player2Dino].getName(), arry[player2Dino].getDesc(), arry[player2Dino].getHP(), arry[player2Dino].getLife() );
		
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
			cout << player1 << ", HIT ENTER TO ROLL  THE DIE TO DO DAMAGE TO " << player2 << " " << dino2.getName() << endl << endl;
			
			cin >> temp;
			cin.ignore();
			
			r = random( 1, 6 );
			//subract the amount of life points to the dinosaur that was hit
			arry[player2Dino].setLife() = arry[player2Dino].getLife() - ( r * arry[player1Dino].getHP() );
			
			cout << dino2.getName() << " NOW HAS " << dino2.getLife() << endl;
			
			//runs when player2's dino has 0 or less life
			if( arry[player2Dino].getLife() <= 0 )
			{
				cout << player1 << " and there " << arry[player1Dino].getName() << " won!" << endl;
				break;
			}
			
			//player2's trun 
			cout << player2 << ", HIT ENTER TO ROLL  THE DIE TO DO DAMAGE TO " << player1 << " " << dino1.getName() << endl << endl;
			
			cin >> temp;
			cin.ignore();
			
			r = random( 1, 6 );
			//subract the amount of life points to the dinosaur that was hit
			arry[player1Dino].setLife() = arry[player1Dino].getLife() - ( r * arry[player2Dino].getHP() );
			
			cout << dino1.getName() << " NOW HAS " << dino1.getLife() << endl;
			//runs when player1's dino has 0 or less life
			if( arry[player1Dino].getLife() <= 0 )
			{
				cout << player2 << " and there " << arry[player2Dino].getName() << " won!" << endl;
				break;
			}
			
		}
		
		cout << endl << endl << endl;
		
		do
		{
			cout << "Would you like to play again? (y/n)	";
			cin >> ag;
			
			switch ( ag )
			{
				case 'y':
				case 'Y': valid = true;
						  again = true;
						  break;
				case 'n':
				case 'N': valid = true;
						  agian = false;
						  break;
				default:  valid = false;
						  cout << "You did not enter either \'y\' or \'n\'.";
			}
			
		}while( !valid );//loop until there is a valid input
		
	}while( again );//loop when the players want to play again
}