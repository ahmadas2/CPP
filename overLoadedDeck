#include "deck.h"

using namespace std;

//Constructor
Deck::Deck()
{
	top = NULL; 
	size = 0; 		//Initializes size to 0
	numDecks = 1; 	//Defaults the number of decks to 1
	srand(42);		//Loads srand with one of my favorite numbers
}

//Destructor
Deck::~Deck()
{
		
	while(top != NULL) // While the list isn't empty
	{
		pop();			//Remove a node;
	}
}

//Private
string Deck::calcF(int val)
{
	val = (val%FACES)+1;	// Bound the Serial number to a number between [0,12]
	string out = "";	// C++ string output buffer
	char buf[256];		// C-string buffer to be used with sprintf()
	switch(val)
	{
		//Set C++ string output buffer to ...
		case 1:
			out = "A";	//Ace Card
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:			// Number cards between [2,9]
			sprintf(buf,"%d",val);
			out = buf;
			break;
		case 10:		// 10 Card
			out = "10";
			break;
		case 11:		// Jack Card
			out = "J";
			break;
		case 12:		// Queen Card
			out = "Q";
			break;
		case 13:		// King Card
			out = "K";
			break;
	}
	return out;			// Return the C++ string output buffer
}

string Deck::calcS(int val)
{
	val = (val%SUITS);		// Bound the Serial number to a number between [0,3]
	string out = "";	// C++ string output buffer
	switch(val)
	{
		//Set C++ string output buffer to ..
		case 0:			// Spade
			out = "S";	
			break;
		case 1:			// Diamond
			out = "D";
			break;
		case 2:			// Club
			out = "C";
			break;
		case 3:			// Heart
			out = "H";
			break;
	}
	return out;			// Return the C++ string output buffer
}

bool Deck::isDuplicate(int val)
{
	card *ptr;
	ptr = top;			// Setting a parsing pointer to the top of the list
	bool out = false;	// Default output of the function should be false 
	
	for(int i = 0; i < size; i++)	//Loop through the List until the end
	{
		if(ptr->sn == val)			// If the card being pointed at matches the value being searched for
		{
			out = true;				// Set the output to true
			break;					// End the for loop
		}
		ptr = ptr->next;			// Increment the parsing pointer
	}
	
	return out;			// Return the true/false output depending on what is found
}

void Deck::pop()
{
	card* ptr;
	ptr = top;			// Setting a parsing pointer to the top of the list
	
	if(top !=NULL)		//Only perform this if the list is not empty
	{
		top = ptr->next;	// Move the top pointer to the next card
		delete ptr;			// Delete whatever is at the parsing pointer
		size--;				// Decrement the size of the list
	}
}

void Deck::push()
{
	if(size < numDecks*CARDS_PER_DECK)	// Only do this if all the cards have not been used.
	{
	card *nCard, *ptr;
	nCard = new card;								// Create a new instance of card in memory
	nCard->sn = rand()%(numDecks*CARDS_PER_DECK);	// Set the serial number to a random integer between [0,numDecks*CARDS_PER_DECK-1]
	nCard->next = NULL;								// next points to default NULL value
	
	if(top == NULL)	// If the list is empty
	{
		top = nCard;	// Set the top card to the new instance of the card and move on.
	}
	else 			// If the list is NOT empty
	{
		while(isDuplicate(nCard->sn))	// Check to see if the serial number has been used before. If so...
		{
			nCard->sn = rand()%(numDecks*CARDS_PER_DECK);	// Set the serial number to a random integer between [0,numDecks*CARDS_PER_DECK-1]
		}								// Do this until the serial number doesn't match anything
		nCard->next = top;				// Set the next to point to the top card
		top = nCard;					// Move the top card to the new instance of the card and move on.
	}
	size++;									// increase the size of the list
	nCard->face = this->calcF(nCard->sn);	// Set the face of the card
	nCard->suit = this->calcS(nCard->sn);	// set the suit of the card
	}
}


//Public

//Mutators
string Deck::getCard()
{
	string out;			// C++ string output buffer
	if(top == NULL)		// If the list is empty
	{
		out = "EMPTY DECK";		// Output string is set to EMPTY DECK
	}
	else
	{
		out = top->face + "-" + top->suit;	//Output buffer is set to "FF-S" of the top card. FF is face and S is suit. 
		pop();								// Remove a card.
	}
	
	return out;	// Return output string
}

void Deck::shuffle(int num)
{
	this->~Deck();	// Destructor deletes all of the cards in the list in case we have to reshuffle
	numDecks = num;	// Sets the number of decks numDecks to passed value.
	for(int i = 0; i < (numDecks*CARDS_PER_DECK); i++)
	{
		push();	// Add a card numDecks*CARDS_PER_DECK times
	}
}

void Deck::operator++() // prefix
{
        if (getSize() < 52 ) push();
}
void Deck::operator++(int unused) // postfix
{
        if (getSize() < 52 ) push();
}
void Deck::operator--() // prefix
{
        pop();
}
void Deck::operator--(int unused) // postfix
{
        pop();
}


//Accessors
void Deck::displayDeck()
{
	card *ptr; // parsing pointer
	ptr = top;
	cout << "Total number of cards: " << size << endl;	// Displays the number of cards in the deck
	int i = 1;
	while(ptr !=NULL)
	{
		cout << i << ".  " << ptr->face << "-" << ptr->suit;	// Outputs the number in the deck, face, and suit of a card
		if(i%4 == 0)											// Creative output formatting
			cout<< endl;
		else if(i < 10)											// More creative output formatting
			cout <<"\t\t";
		else 													// Even more creative output formatting
			cout << "\t";
		ptr = ptr->next;										// Move the parsing pointer to the next card
	i++;													// Increment the number
	}
	cout << endl << endl;
}
ostream& operator<<(ostream& os, Deck &dt){

	dt.displayDeck(os);

	return os;

}
void Deck::displayDeck(ostream& os){
	card *ptr; // parsing pointer
	ptr = top;
	os << "Total number of cards: " << size << endl;			// outputs strings to ostream 
	int i = 1;
	while(ptr !=NULL)
	{
		os << i << ".  " << ptr->face << "-" << ptr->suit;		// Outputs the number in the deck, face, and suit of a card into ostream 
		if(i%4 == 0)							// Creative output formatting
			os<< endl;
		else if(i < 10)							// More creative output formatting
			os <<"\t\t";
		else 								// Even more creative output formatting
			os << "\t";
		ptr = ptr->next;						// Move the parsing pointer to the next card
		i++;								// Increment the number
	}
	os << endl << endl;

}
string Deck::operator[](int ind){
	if(ind<0)		ind=0;
	if(ind>size-1)		ind= size-1;
	
	card *ptr; // parsing pointer
	ptr = top;
	for(int i=0; i<=ind; i++) 	ptr = ptr->next;
	
	string value;
	
	if(ptr ==NULL)			value = ""; // setting value = null once reached the end of the file 
	
	else				value = ptr->face+"-"+ptr->suit;
	
	return value;
}


string Deck::getFace()
{
	return top->face;	// Returns the face of the top card
}

int Deck::getSize()
{
	return size;		// Returns the size of the deck
}

int Deck::getSN()
{
	return top->sn;		// Returns the Serial Number of the top card
}

string Deck::getSuit()
{
	return top->suit;	// Returns the suit of the top card
}


