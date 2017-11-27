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
#include "deck.h"

int main(){
	int numDecks = 1;
	int seed = 1;
	masterDeck deck;
	
	srand(seed);
	
	int size = 0;
	size = numDecks * CARDS;
	
	deck.shuffle(size);
	deck.dispayDeck(size);
	cout<<endl<<endl<<endl<<endl;
	deck.drawCard();
	cout<<endl<<endl<<endl;
	deck.dispayDeck(size-1);
	cout<<endl<<endl;
	
	deck.~masterDeck();

	numDecks = 2;
	size = numDecks * CARDS;
	
	deck.shuffle(size);
	deck.dispayDeck(size);
	cout<<endl<<endl<<endl<<endl;
	deck.drawCard();
	cout<<endl<<endl<<endl;
	deck.dispayDeck(size-1);
	cout<<endl<<endl;

	}
