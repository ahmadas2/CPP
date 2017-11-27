/****************************************************************************
 * Project num: Project 4
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
 * Inputs: num of decks, num to seed srand()
 *
 * Output: list of cards and the removed card value
 *
 ***************************************************************************/
#include "deck.h"

masterDeck::masterDeck(){
	top = NULL;
}
masterDeck::~masterDeck(){
	card *ptr;                        
	while(top!=NULL&&top->next!=NULL){
		ptr=top;
		top=ptr->next;
		delete ptr;
	}
	delete top;
	top = NULL;
}
string masterDeck::drawCard(){
	card *ptr;
	ptr=top;                      //"draws" the top card of deck and deletes it 
	top=ptr->next;
	cout<<ptr->face<<" "<<ptr->suit<<endl;
	
	}

void masterDeck::shuffle(int num){
	this->~masterDeck();
	for(int i = 0; i < num; i++) { 
		addNode(getValue(num)); //shuffles and adds card
		}
}

void masterDeck::delNode(){ 			//pop function
	card *ptr;
	ptr=top;
	top=ptr->next;
	delete ptr;
	delete top;
}

void masterDeck::addNode(int var){	  //push function 
	card *nCard; 	// adds new card to the top	of linked list
	nCard=new card;
	//nCard->value=getValue(var);  << DUMB!
	nCard->suit=getSuit(var);
	nCard->face=getFace(var);
	
	nCard-> next = top;
	top = nCard;
}
int masterDeck::getValue(int var){
	int num = 1;
	do{num = rand()%var;
		}while(isthere(num)); //gets random generated value to use for other functions 
		//cout << num << endl;
	return num;
}
string masterDeck::getSuit(int num){
	string suit = "";
	switch(num%4){  //assigns suit
		case 0: suit="S";  break;
		case 1: suit="H";  break;
		case 2: suit="D";  break;
		case 3: suit="C";  break;
	}
	return suit;
}

string masterDeck::getFace(int num){ 	// sets a "random face to card"
	string face = "";
	switch(num%13){ //assigns face
		case 0: face="A";  break;
		case 1: face="2";  break;
		case 2: face="3";  break;
		case 3: face="4";  break;
		case 4: face="5";  break;
		case 5: face="6";  break;
		case 6: face="7";  break;
		case 7: face="8";  break;
		case 8: face="9";  break;
		case 9: face="10"; break;
		case 10:face="J";  break;
		case 11:face="Q";  break;
		case 12:face="K";  break;
		}
		
	return face;
}

bool masterDeck::isthere(int num){
	bool outcome = false; //checks if card already exits
	card *ptr;
	ptr=top;
	while(ptr!=NULL){
		if(num==ptr->value){
		return true;
		ptr=ptr->next;
	}
	return outcome;
	}
}

int masterDeck::getSize(){
	
	int size = 0;
	card *ptr;
	ptr=top;
	
	while(ptr!=NULL){
		size++;				// size of linked list (number of cards)
		ptr=ptr->next;
	}
	
	return size;
	
}

void masterDeck::dispayDeck(int size){
	cout<<"Total num of cards:"<<getSize()<<endl;
	card *ptr;
	ptr=top;
	int i=1;
	while(ptr!=NULL){
		if(i%5==4){
			std::cout.width(3); std::cout << std::right <<i<<". "<<ptr->face<<" "<<ptr->suit<<"\t";}
		else if(i%5==3){
			std::cout.width(3); std::cout << std::right <<i<<". "<<ptr->face<<" "<<ptr->suit<<"\t";}
		else if(i%5==2){
			std::cout.width(3); std::cout << std::right <<i<<". "<<ptr->face<<" "<<ptr->suit<<"\t";}
		else if(i%5==1){
			std::cout.width(3); std::cout << std::right <<i<<". "<<ptr->face<<" "<<ptr->suit<<"\t";}
		else if(i%5==0){
			std::cout.width(3); std::cout << std::right <<i<<". "<<ptr->face<<" "<<ptr->suit<<endl;}
	
		ptr=ptr->next;
		i++;
	}
	
}
