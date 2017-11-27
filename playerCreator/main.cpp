
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
// #include "player.cpp"
int main (){
	Player ali;
	int numdecks;
	int seed;
	int numcards;
	cout<<"Please Enter Number of Decks: ";
	cin >> numdecks ;
	cout<< endl <<"Please Enter a number to seed Srand(): ";
	cin >> seed;
	cout<< endl << "How many cards do you want to draw: ";
	cin >> numcards;
	while(numcards < 1 || numcards > 10){
		cout<<endl << "The number of cards must be between 1 and 10: " ;
		cin >> numcards;
	}
	
	int size = numdecks * CARDS; // full amount of cards
	
	
	Card deck[numdecks * CARDS];
	srand(seed);

	shuffle_deck(deck, numdecks);

	ali.setFirstName("Ali ");
	cout << endl <<"Name: "<<ali.getFirstName();
	
	ali.setLastName("Ahmad");
	cout << ali.getLastName()<<endl;
	
	ali.setCash(69);

	cout << "Cash: $" << ali.getCash() <<endl << endl;
	
	for (int i = 0; i < numcards; i++){

		ali.addCard(getTopCard(deck, size));
		ali.showHand();
		cout << "Score:" << ali.getScore()<<endl<<endl;
	
	}
	
	
	return 0;
}
