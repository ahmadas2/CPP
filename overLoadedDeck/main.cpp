/****************************************************************************
 * Project number:5
 *
 * Programmer: Ali S Ahmad
 *
 * Due Date: 04-06-2017
 *
 * EGRE 246 Spring 2017
 *
 * Pledge: I have neither given nor received unauthorized aid on the program.
 *
 * Description: Operator overloading
 *
 * Inputs: objects in deck 
 *
 * Output: Data into the ostream
 *
 ***************************************************************************/
#include "deck.h"


using namespace std;

int main()
{
		
	Deck deck; // Creates a Deck Object
	
	deck.shuffle(1); // Shuffles one traditional deck of cards into the Deck Object
	
	deck.displayDeck();	// Displays the Deck of cards
	
	cout << "Card 1: "<<deck.getCard() << endl; // Removes top deck of the card and displays it to the screen
	cout << "Card 2: "<<deck.getCard() << endl; // Removes top deck of the card and displays it to the screen
	cout << "Card 3: "<<deck.getCard() << endl; // Removes top deck of the card and displays it to the screen
	
	cout << endl<<endl;
	
	cout << "Remove 2 Cards."<<endl;
	--deck; //	Removes a Card - Prefix
	deck--; //	Removes a Card - Postfix
	cout << endl<<endl;	
	deck.displayDeck();
	// Alternate way of displaying the deck of cards
	cout << "Total number of cards: " << deck.getSize() << endl;
	for(int i = 1; i <=deck.getSize(); i++) // getSize() returns the number of cards in the deck
	{	
		cout <<i<<setw(4)<<left<< setfill(' ')<<".";
		
		cout <<setw(5)<<setfill(' ')<<left << deck[i-1]<< "\t";
		if(i%4 == 0) // Formatting to make the display a little easier to read
			cout<< endl;
	} 
	cout << endl<<endl<<endl;
	
	cout << "Add 2 Cards."<<endl;
	++deck;	//	Adds a card back to the deck - Prefix
	deck++;	//	Adds a card back to the deck - Postfix 
	cout <<endl<<endl;
	//deck.displayDeck();
	cout << deck;	// Displays the Deck of cards
	
	return 0;
}
