/****************************************************************************
 * Project number: 1
 *
 * Programmer: Ali S. Ahmad
 *
 * Due Date: 01-27-2017
 *
 * EGRE 246 Spring 2017
 *
 * Pledge: I have neither given nor received unauthorized aid on the program.
 *
 * Description: ROCK PAPER SCISSORS LIZZARD SPOCK
 *
 * Inputs: choices of user / computer choice
 *
 * Output: Score / words LOL
 *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int play_game(int *); // Returns 0 if player won, 1 if the computer won, 2 if there is a tie, and -1 if the player decides to quit
int menu(int *); // Displays choices to user // Receives score array

void flushing_buffer(){
	int dank;
	do { 
		dank = getchar();
	}
	while (dank !='\n' && dank!=EOF); // reads to the end of the file  before continuing :) 
}

int main()
{
	srand(42); // Seeding Random with 42
	int score[3]; // Array keeping Player, Computer, and Tie Scores
	score [0] = 0; // Player - initialized to Zero
	score [1] = 0; // Computer - initialized to Zero
	score [2] = 0; // Tie - initialized to Zero
	
    int winner=0; // Winner index of 
	
	printf("ROCK PAPER SCISSORS LIZZARD SPOCK!\n\n");

	
	while(winner >=0) // If Winner == -1 -> the game stops
	{
		winner = play_game(score); // Plays the game.
		if(winner >=0) // If a value to not stop the game comes in.
			score[winner]++; // Increment score counter
	}
	
	printf("GOOD BYE!\n");
	return 0;
}
int menu(int *score) {
	printf("*MENU*****************\n\n");
	
	
	printf("Player:      %d\n", score[0]);
	printf("Computer:    %d\n", score[1]);
	printf("Tie: 	     %d\n\n", score[2]);
	
	printf("1) Rock \n");
	printf("2) Paper \n");
	printf("3) Scissors\n");
	printf("4) Lizzard\n");
	printf("5) Spock\n\n");
	
	printf("9) Exit\n\n");
	printf("***********************\n");
		
	return 0;
}

int play_game(int *score){
	menu(score);
	int ran = 0;
	ran = rand()%5+1;
	int choice = 0;
		do {
		printf("Choice?");				  // Asks user for input :) 
		scanf("%d", &choice);			 //  Reads value and sets it to variable choice
		flushing_buffer();				//   Clears buffer (since it doesnt work on unix) 
		} while(choice < 1 || (choice > 5 && choice !=9) ); 		   //    Error Handler (if user enters letter) 
		
		switch(choice){
		case 1: // player is rock
		printf(" Player:	");
		printf("Rock\n");
		if (ran == 3){ // SCISSORS
			printf(" Computer:	Scissors\n");
			printf(" WIN - Rock crushes Scissors\n\n");
			return 0;
		}
		else if (ran == 2){ // PAPER
			printf(" Computer:	Paper\n");
			printf(" LOSS - Paper covers Rock\n\n");
			return 1;
			
		}
		else if (ran == 1){ // ROCK 
			printf(" Computer:	Rock\n"); 
			printf(" Tie - Rock is Rock\n\n");
			return 2;
		}
		else if (ran == 4){ // LIZZARD
			printf(" Computer:	LIZZARD\n"); 
			printf(" WIN - Rock crushes Lizard\n\n");
			return 0;
		}
		else if (ran == 5){ //SPOCK
			printf(" Computer:	SPOCK\n"); 
			printf(" Tie - Spock vaporizes Rock\n\n");
			return 1;
		}
		break;
	
		case 2: //player is paper 
		printf(" Player:	");
		printf("Paper\n");
 		if (ran == 3){ //scissors 
			printf(" Computer:	Scissors\n");
			printf(" LOSS - Scissors cuts Paper\n\n");
			return 1;
		}
		else if (ran == 2){ // paper
			printf(" Computer:	Paper\n");
			printf(" TIE - Paper is Paper\n\n");
			return 2;
		}
		else if (ran == 1){ // rock
			printf(" Computer:	Rock\n");
			printf(" WIN - Paper covers Rock\n\n");
			return 0;
		}
		else if (ran == 4){ // lizzard
			printf(" Computer:	Lizzard\n");
			printf(" LOSS - Lizzard eats Paper\n\n");
			return 1;
		}
		else if (ran == 5){ // spock 
			printf(" Computer:	Spock\n");
			printf(" WIN - Paper disproves Spock\n\n");
			return 0;
		}
		
		break; 
 		
		case 3: // player is scissors 
		printf(" Player:	");
		printf("Scissors\n");
		if (ran == 3){ // scissors
			printf(" Computer:	Scissors\n");
			printf(" TIE - Scissors is Scissors\n\n");
			return 2;
		}
		else if (ran == 2){ // paper
			printf(" Computer:	Paper\n");
			printf(" WIN - Scissors cuts Paper\n\n");
			return 0;
		}
		else if (ran == 1){  // rock
			printf(" Computer:	Rock\n");
			printf(" LOSS - Rock crushes Scissors \n\n");
			return 1;
		}
		else if (ran == 4){ //Lizzard
			printf(" Computer:	Lizzard\n");
			printf(" WIN - Scissors decapitates Lizard\n\n");
			return 0;
		}
		else if (ran == 5){ //Spock
			printf(" Computer:	Spock\n");
			printf(" LOSS - Spock smashes Scissors \n\n");
			return 1;
		}
		break;
		// INCASE YOU THINK I COPIED SOMEONE HERE ... I JUST GOT 
		// TIRED OF GETTING CONFUSED CUZ NUMBERS WERE NOT IN ORDER
		// I ALSO ADDED A FEW PLOT TWISTS LOL :) HOPE YOU LIKE WHAT I DID
		case 4:
		printf(" Player:	");
		printf("Lizzard\n");
		if (ran == 1){  // rock
			printf(" Computer:	Rock\n");
			printf(" LOSS - Rock crushes Lizard\n\n");
			return 1;
		}
		else if (ran == 2){ //paper 
			printf(" Computer:	Paper\n");
			printf(" WIN - Lizzard eats Paper\n\n");
			return 0;
		}
		else if (ran == 3){ //scissors 
			printf(" Computer:	Scissors\n");
			printf(" LOSS - Scissors decapitates Lizard\n\n");
			return 1;
		}
		else if (ran == 4){ // lizzard 
			printf(" Computer:	Lizzard\n");
			printf(" TIE - The Lizzards start a family\n\n");
			return 2;
		}
		else if (ran == 5){ //spock
			printf(" Computer:	Spock\n");
			printf(" WIN - Lizzard poisons Spock\n\n");
			return 0;
		}
		break;
		 
		case 5:
		printf(" Player:	");
		printf("Spock\n");
		if (ran == 1){  // rock
			printf(" Computer:	Rock\n");
			printf(" Win - Spock vaporises Rock\n\n");
			return 0;
		}
		else if (ran == 2){ //paper 
			printf(" Computer:	Paper\n");
			printf(" Loss - Paper disapproves Spock\n\n");
			return 1;
		}
		else if (ran == 3){ //scissors 
			printf(" Computer:	Scissors\n");
			printf(" Win - Spock crushes Scissors\n\n");
			return 0;
		}
		else if (ran == 4){ // lizzard 
			printf(" Computer:	Lizzard\n");
			printf(" Loss - Lizzard poisons Spock\n\n");
			return 1;
		}
		else if (ran == 5){ //spock
			printf(" Computer:	Spock\n");
			printf(" TIE - The 2 Spocks elope in California\n\n");
			return 2;
		}
		break; 
		
		case 9:
			return -1;
		break;
	    
	    default:
			//printf("Illegal Choice\n");
			return 9;
		break;
		}
	}

