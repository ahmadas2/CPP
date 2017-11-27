/* 
 * Advanced Programming using C++
 * Project 2
 * Ali S Ahmad
 * Tuesday 02-07-2017
 * 
 */

#include <iostream>
#include <vector>
#include <time.h> 
#include <string.h>

#define CARD 52
 
using namespace std;

struct Card {
  int number;
  string face; 
  string suit;
};
// ************prototyping**************// 
void shuffle_deck(Card * , int ); 

int check(Card *, int , int );

void print(Card *, int);;
// Main
int main(){
	int numdeck = 0; 
	
	cout << "Deck of Cards" << endl;
	cout << endl << "Enter the number of decks: ";  //gets number of decks from user and assigns it to variable 
	cin  >> numdeck ;
	cout << endl;
	
	
	Card deck[CARD*numdeck]; //
	
	shuffle_deck(deck, numdeck);
	print(deck, numdeck);

    return 0;
}

void shuffle_deck(Card* deck, int numdeck){
	
	int maxvalue = CARD * numdeck; // max number of cards 
	srand(time(0)); //seeded with time 
	int ran = 0;
	for (int i = 0 ; i < maxvalue; i++){
		do{ran = rand()%maxvalue;
		}while(check(deck, i, ran) == 1); //checks if card has has been used 
	deck[i].number=ran; 
	// assigns the face
			if (ran %13 == 0)
			deck[i].face="A";
			if (ran %13 == 1)
			deck[i].face="2";
			if (ran %13 == 2)
			deck[i].face="3";
			if (ran %13 == 3)
			deck[i].face="4";
			if (ran %13 == 4)
			deck[i].face="5";
			if (ran %13 == 5)
			deck[i].face="6";
			if (ran %13 == 6)
			deck[i].face="7";
			if (ran %13 == 7)
			deck[i].face="8";
			if (ran %13 == 8)
			deck[i].face="9";
			if (ran %13 == 9)
			deck[i].face="10";
			if (ran %13 == 10)
			deck[i].face="J";
			if (ran %13 == 11)
			deck[i].face="Q";
			if (ran %13 == 12)
			deck[i].face="K";
	//assigns the suit 
	deck[i].suit=(3+ran%4);
	}
}


int check(Card* deck, int j, int ran){
	int rval = 0; 
	for(int i = 0; i<j; i++){
		if(deck[i].number == ran){
		rval = 1;
		break;}
	}
	return rval;
}

void print(Card* deck,int numdeck){
	
	for (int i = 0; i < numdeck*CARD; i++){ // do i really need to explain the PRINT function ???
		cout << i << ": " << deck[i].face << deck[i].suit<< endl;
	}
}

