
/*
 * Programmer: Ali S Ahmad
 * Adv - EGRE 246
 * Program 3
 * Due date: 02-28-2017
 * Due time: 2359
 * Finish time: 2300
 * 
*/

#include "player.h"



/*********** "CLASS STUFF" ***********/

Player::Player(string fname, string lname, int mula, double score) {
   for(int i = 0; i < MAX; i++){
	   hand[i].sn = -1;
   }
}

Player::Player() {
	for(int i = 0; i < MAX; i++){
	   hand[i].sn = -1;
   }
}


int Player::getScore() {
	int score = 0;
	int val = 0;
	for (int i = 0; i < 10; i++){
	
		val = (hand[i].sn % 13) + 1;
		
		switch (val) {
		
			case 1:
				if(score + 11 > 21){
					score+=1;
				}
				else {
					score += 11;
				}
			break;
	
			case 2:
				score += 2;
			break;
			
			case 3:
				score += 3;
			break;
			
			case 4:
				score += 4;
			break;
			
			case 5:
				score += 5;
			break;
			
			case 6:
				score += 6;
			break;
			
			case 7:
				score += 7;
			break;
			
			case 8:
				score += 8;
			break;
			
			case 9:
				score += 9;
			break;
			
			case 10:
			case 11:
			case 12:
			case 13:
				score += 10;
			break;
	
	
	
		}
	}
	return score;
}


	void Player::setFirstName(string firstName){
		fname = firstName;
	}
	string Player::getFirstName(){
	return fname;
	}
	
	void Player::setLastName(string lastName){
		lname = lastName;
	}
	
	string Player::getLastName(){
		return lname;
	}
	
	  
	 void Player::setCash(double money){
		mula = money;
	 }
	 
    double Player::getCash(){
		return mula;
	}
	

	void Player::showHand(){
		cout<<"Hand: ";		
		for(int i = 0; (i<10 && hand[i].sn!=-1); i++){
			cout<< i+1 <<". " << hand[i].face << "-" << hand[i].suit << "   ";
		if(hand[i].sn == -1)
			break;
	}
	cout << endl;
}


int Player::addCard(Card out){
		int i = 0;
		while (hand[i].sn!=-1){
		i++;
		}	
	hand[i]=out;
	getScore();
	return 0;
}

	
/********** "NON CLASS STUFF" : RYAN *******************/

void shuffle_deck(Card* deck, int numdecks){
	
	int i = 0;
	int number = 0;
	int stuff = numdecks*CARDS;
	
	for(i = 0; i<stuff; i++){ 
		do{number = rand()%stuff;
		}while(check(deck,i,number) != 0);
	deck[i].sn=number;

	switch(number%13){
		case 0:
			deck[i].face="A";
			break;
		case 1:
			deck[i].face="2";
			break;
		case 2:
			deck[i].face="3";
			break;
		case 3:
			deck[i].face="4";
			break;
		case 4:
			deck[i].face="5";
			break;
		case 5:
			deck[i].face="6";
			break;
		case 6:
			deck[i].face="7";
			break;
		case 7:
			deck[i].face="8";
			break;
		case 8:
			deck[i].face="9";
			break;
		case 9:
			deck[i].face="10";
			break;
		case 10:
			deck[i].face="J";
			break;
		case 11:
			deck[i].face="Q";
			break;
		case 12:
			deck[i].face="K";
		break;}
	deck[i].suit=(3+number%4);
	}
	}


int check(Card *deck, int j, int ran){
	int rval = 0; 
	for(int i = 0; i<j; i++){
		if(deck[i].sn == ran){
		rval = 1;
		break;}
	}
	return rval;
}

Card getTopCard(Card *deck, int size){
	Card out;
	out.sn = -1;
	
	int i = 0;
	
	while ( i < size && deck[i].sn < 0 ){
		i++;
	}
	
	out.sn   = deck[i].sn;
	out.face = deck[i].face;
	out.suit = deck[i].suit;
	deck[i].sn = -1;
	return out;
}


