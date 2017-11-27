/****************************************************************************
 * Project number: Project 4
 *
 * Programmer: Ali S Ahmad
 *
 * Due Date: 3/17/2017
 *
 * EGRE 246 Spring 2017
 *
 * Pledge: I have neither given nor received unauthorized aid on the program.
 *
 * Description: Simulate decks with linked list and then remove top card
 *
 * Inputs: number of decks, number to seed srand()
 *
 * Output: list of cards and the removed card value
 *
 ***************************************************************************/
 
#ifndef __HAVE_PLAYER_H //checks if header file has been opened 
#define __HAVE_PLAYER_H
 
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;
//Library Inclusions

#define CARDS 52
#define FACE 13
#define SUITS 4
#define MAXCARD 10
//Constantants 

class masterDeck{
	public:
		masterDeck();
		~masterDeck();
		string drawCard();
		void shuffle(int);
		void dispayDeck(int);
		void delNode(); //pop function 
	private:
		struct card{
			int value;
			string suit;
			string face;
			card *next;
			};
		card *top;	
		int getValue(int);
		bool isthere(int);
		void addNode(int);  //push function
		string getFace(int);
		string getSuit(int);
		
		
		int getSize();
};

#endif
