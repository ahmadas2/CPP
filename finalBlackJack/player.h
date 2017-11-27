#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"

#define MAX 10

class Player{
	
	private:
	 
		string fname;
		string lname;
		int score;
		double money;
		card hand[MAX];
		
			
	public:
	
		Player(); //constructor
		~Player(); // Deconstructor 
	
		/****MUTATOR****/
	
		void setCash(double);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void addCard(card);
	
		/****ACCESSSOR****/
	 
		string getFirstName();
        	string getLastName();
		void showHand();
		int getScore();
		double getCash(); 
	
};

#endif
