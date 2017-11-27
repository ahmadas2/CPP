
/*
 * Programmer: Ali S Ahmad
 * Adv - EGRE 246
 * Program 3
 * Due date: 02-28-2017
 * Due time: 2359
 * Finish time: 2300
 * 
*/

#ifndef __HAVE_PLAYER_H
#define __HAVE_PLAYER_H

#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>

/***** SYMBOLIC CONSTANTS ******/

#define CARDS 52
#define FACES 13
#define SUITS 4
#define MAX 10

using namespace std;

/****** CARD STRUCTURES *******/

struct Card {
	string face;
	string suit;
	
	int sn;
	
};

/***** FUNCTIONS PROTOTYPES *****/



/******* PLAYER CLASS ******/
/** EVERYTHING IS PUBLIC **/

class Player{

	private:
	 
		string fname;
		string lname;
		int mula;
		double score;
		Card hand[MAX];
		
		//struct card[]; //	hand is an array of cards :) 
	
	public:
	
	double getCash();
	string getFirstName();
	string getLastName();
	int getScore();
    Player();
    Player(string, string, int, double);
	void setCash(double);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void showHand();
	int addCard(Card);
	
};
	int check(Card *, int , int );
	void shuffle_deck(Card *, int );
	Card getTopCard(Card *, int);


#endif
