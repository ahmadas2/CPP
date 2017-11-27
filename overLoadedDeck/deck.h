#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <iomanip>
#include <ios>
#include <sstream>

#define CARDS_PER_DECK 52
#define FACES 13
#define SUITS 4

using namespace std;

class Deck
{
	private:
		
		// Private Data Members
		struct card{
			string face; // A,2,3,4,5,6,7,8,9,10,J,Q,K
			string suit; // H,C,D,S
			int sn;		 // Serial Number
			card* next;
		};
		
		card *top;		 // Top of the deck
		int size;		 // Size of the deck
		int numDecks;	 // Number of traditional decks in this deck of cards	
		
		// Utility Functions
		
		string calcF(int);	//Calculates face from random number associated with card;
		string calcS(int);  //Calculates suit from random number associated with card;
				
		bool isDuplicate(int);
		void pop();  //POP
		void push(); //PUSH
		
	public:
		Deck(); //	Constructor
		~Deck();//	Deconstructor
		
		//Mutators
		string getCard();   // Returns FF-S (FF-Face, S-Suit) of the top card and deletes the top card from the deck
		void shuffle(int);	//Adds nodes over and over again until the size of the Deck reaches the number of decks passed times 52
		
		//Accessors
		void displayDeck(); // Displays the total number of cards and the cards in the deck
		void displayDeck(ostream&);	// taylored for the operator overload setting everything to ostream. 
		string getFace();   // Returns the face of the top card
		int getSize();		// Returns the number of cards that are currently in the deck
		int getSN();		// Returns the sn   of the top card
		string getSuit();	// Returns the suit of the top card
		
		
		// Overloaded Operators//
		//1- Operator <<
		//2- Operator []
		//3- Operator --
		//4- Operator ++
		void  operator++();
		void  operator++(int);
		void  operator--();
		void  operator--(int);
		friend ostream& operator<<(ostream& os, Deck &dt); 
		//ostream& operator<<(ostream&); <- made for testing purposes 
		string operator [](int);	
};

#endif
