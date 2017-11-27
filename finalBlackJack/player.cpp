/*
 * Programmer: Ali S Ahmad
 * Adv - EGRE 246
 * Program: BlackJack
 * Due date: 05-02-2017
 * Due time: 2359
 * Finish time: ----
 * 
*/

#include "player.h"


Player::Player() {
   for(int i = 0; i < MAX; i++){
	   hand[i].sn = -1;
   }
   string fname;
   string lname; 
   int score; 
   double money;
   
}
	Player::~Player() { 				// Deconstructor 
		
		 for(int i = 0; i < MAX; i++){
           			hand[i].sn = -1;
  			}

		}

	/****MUTATOR FUNCTIONS****/
	
	void Player::setCash(double cash){

			money = cash;

		}
	void Player::setFirstName(string firstName){

			fname = firstName;
	
		}
	void Player::setLastName(string lastName){

			lname = lastName;

		}
	void Player::addCard(card out){

			int i = 0;
                	while (hand[i].sn!=-1){
                			i++;
                		}
       			hand[i]=out;
        		getScore();
        		
		}
	
	/****ACCESSSOR FUNCTIONS****/
	
	string Player::getFirstName() { return fname; }

        string Player::getLastName() { return lname; }

	void Player::showHand(){

			cout<<"Hand: ";
                	for(int i = 0; (i<10 && hand[i].sn!=-1); i++){
                        cout<< i+1 <<". " << hand[i].face << "-" << hand[i].suit << "   ";
                		if(hand[i].sn == -1) break;
 
        			//cout << endl;
			}
		}

	int Player::getScore() {
	        	int score = 0;
       			int val = 0;
        		for (int i = 0; i < 10; i++){

                		val = (hand[i].sn % 13) + 1;

                		switch (val) {

                       		 	 case 1: if(score + 11 > 21) score+=1; else  score += 11; break;

                 		       	 case 2: score += 2; break;

                  		      	 case 3: score += 3; break;
       
                     		   	 case 4: score += 4; break;

                        		 case 5: score += 5; break;
       
                        	 	 case 6: score += 6; break;

                        	 	 case 7: score += 7; break;

                      			 case 8: score += 8; break;

                       		 	 case 9: score += 9; break;
        
                   	         	 case 10: case 11: case 12: case 13: score += 10; break;

                			}
        			}

        		return score;
		}

	double Player::getCash(){
                return money;
        }


	card getTopCard(card *deck, int size){
		card out;
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
