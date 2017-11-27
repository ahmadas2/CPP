#include "player.h"


using namespace std;



enum state{
	state_mMenu, 		// State 0
	state_GameMenu,		// State 2
	state_LoadGame,		// State 3
	state_Settings,		// State 4
	state_Exit,		// State 5
	state_Save,		// Sub stage of Game menu
	state_playGame, 	// Sub Stage of Game menu
	state_other		// Easter Egg
};

state statemMenu();
state stateGameMenu(string, string);
state stateLoadGame(Player *);
state stateSettings(int *, double *,int *,Player *);
state stateSave(Player);
state stateplayGame(int,double,Player*,Player);
void clearp();
void options();
void tester(bool *,double,Player, Player *);
void info(double,Player *,Player);
void playinfo(Player *);
void dealinfo(Player );
int main()
{
	string fname = "Ali";
	string lname = "Ahmad";
	double cash =  420;
	int numdecks = 1;
	double min = 10; 	// Minimum bet amount, here right now for testing (moved to settings in final part and passed as paramater)
	int seed  = 69;
	Player player;
	Player dealer;

	player.setFirstName(fname);
	player.setLastName(lname);
	player.setCash(cash);	
	srand(seed);
	state curr = state_mMenu;
	
	while(curr != state_Exit)
	{
		clearp();
		switch(curr)
		{	
			case state_mMenu:
				curr = statemMenu();
			break;
			
			
			case state_GameMenu:
				curr = stateGameMenu(fname,lname);
			break;
			
			case state_LoadGame:
				curr = stateLoadGame(&player);
			break;
			
			case state_Settings:
				curr = stateSettings(&numdecks,&min,&seed,&player);
				srand(seed);
			break;

			case state_Save:
				curr = stateSave(player);
			break;
			
			case state_playGame:
				curr = stateplayGame(numdecks,min,&player,dealer);
			break;

			default:
				cout << "Looks like easter came twice this year"<<endl;
				curr = state_mMenu;
			break;
		}

	}
	
	
	return 0;
}

state statemMenu()
{
	int choice;
	state next = state_mMenu;
	cout <<"---Main Menu----------- \n\n";
	cout <<"\t1 - Game Menu\n";
	cout <<"\t2 - Settings\n";
	cout <<"\t3 - Load Game\n";
	cout <<"\t4 - Exit\n";
	cout <<"---------------------- \n\n";
	cout << "Chocie: ";
	cin >> choice;
	if(cin.good())
	{
		if(choice == 1) next = state_GameMenu;
		if(choice == 2) next = state_Settings;
		if(choice == 3) next = state_LoadGame;
		if(choice == 4) next = state_Exit;
	}
	cin.clear();
	cin.ignore(10000,'\n');
		
	cout << endl;	
	return next;
}



state stateGameMenu(string fname, string lname)
{	
	int choice;
	state next = state_GameMenu;
	cout << "--Game Menu-----------"<<endl;
	cout << "1.Play Game" << endl;
	cout << "2.Save Game" << endl;
	cout << "3.Main Menu" << endl;
	cout <<"---------------------- \n\n";
	cout << "Chocie: ";
	cin >> choice;
	if(cin.good()){
		if (choice == 1) next = state_playGame;
	
		if (choice == 2) next = state_Save;

		if (choice == 3) next = state_mMenu;

	}
	
	 cin.clear();
     	 cin.ignore(10000,'\n');
		
   	return next;
}

state stateLoadGame(Player *player)
{	
	state next = state_LoadGame;
	clearp();
	int choice;
	string filename = "";
	string fname =""; // buffer for first name 
	string lname =""; // buffer for last name 
	double mula = 0; // buffer for money 
	while (choice != 3){
	clearp(); 
	cout << "--Load Game Menu--"<<endl;
	cout << "1.File Name- " << filename <<endl;
	cout << "2.Load " << endl;
	cout << "3.Main Menu " << endl;
	cout << "------------------"<<endl;
	cout << "Chocie: ";
	cin >> choice;
	if(cin.good()){
		if (choice == 1){
			cout << "Filename: ";
			cin >> filename;
			}
		if (choice == 2){
			ifstream input(filename.c_str());
			if(input.is_open()){
				input >> fname;
				input >> lname;
				input >> mula;
				player->setFirstName(fname);
				player->setLastName(lname);
				player->setCash(mula);
			} 
			
			
			else cout << "invalid filename";
	
			}
		
		} 
		    	 		
	}	
	if (choice == 3) next = state_mMenu;
		

	cin.clear();
	cin.ignore(10000,'\n');
	cout << endl;
	
	return next;	
}
state stateSettings(int *numdecks,double *min,int *seed,Player *player)
{

	int choice;
	string name;
	double cash; 

	while (choice != 7){
	system("clear");
	system("cls");
	cout << "---------------Game Settings-----------"<<endl;
	cout << "PLAYER SETTINGS"<<endl;
	cout << "1.First name- " << player->getFirstName() << endl;
	cout << "2.Last Name- " << player->getLastName()<<endl;
	cout << "3.Start Money- " << player->getCash() <<endl << endl;
	
	cout << "GAME SETTINGS" <<endl;
	cout << "4. Number of decks in master deck- " << endl;
	cout << "5. Minimum Bet- " << *min <<endl;
	cout << "6. Seed Value- " <<*seed<<endl<<endl;
	
	cout << "7. Exit"<<endl;
	cout <<"----------------------------------------"<<endl;
	cout << "Chocie: ";
	cin >> choice;
	if(cin.good()){
		if (choice == 1){
			cout << "First Name: ";
			cin >> name; 
			player->setFirstName(name);
		}
		if (choice == 2){
			cout << "Last Name: ";
			cin >> name;
			player->setLastName(name);
		}
		if (choice == 3){
			cout << "Start Money: ";
			cin >> cash;
			player->setCash(cash);
		}
		if (choice == 4){
			cout << "Number of decks: ";
			cin >> *numdecks;
		}
		if (choice == 5) {
			cout << "Minimum Bet: ";
			cin >> *min;
		}
		if (choice == 6) {
			cout << "Seed Value:";
			cin >> *seed;
		}

	}

}


	
	if (choice == 7) return state_mMenu;
	cin.clear();
	cin.ignore(10000,'\n');
	return state_Settings;
	cout << endl;
	
}
state stateSave(Player player){
	clearp();
	ofstream myfile;
	state next = state_Save;
	int choice = 1;
	string buffer;
	string filename = player.getFirstName() + player.getLastName() + ".jak";
	while ( choice == 1 ){
	cout<<"--------SAVING MENU--------"<<endl;
	cout<<"1. Filename- "<<filename<<endl;
	cout<<"2. Save "<<endl;
	cout<<"3. Cancel "<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"Choice: ";
	cin >> choice;
	if(cin.good()){
		if (choice == 1){
			clearp();
			cout<<"--------Filename --------"<<endl;
			cout<<"Filename: ";
			cin>>buffer;
			filename = buffer + ".jak";
		}
		if (choice == 2){
			
			myfile.open(filename.c_str());
			myfile << player.getFirstName()<<endl;
			myfile << player.getLastName()<<endl;
			myfile << player.getCash()<<endl;
			myfile.close();
			next = state_GameMenu;
		}
		if (choice == 3){
			next = state_GameMenu;
		}
		
	}
}
	cin.clear();
	cin.ignore(10000,'\n');
	return next;

	}

state stateplayGame(int numdecks,double min,Player *player,Player dealer){
	state next = state_playGame;
	double bet = min; // money on the table
	int choice = 0; // option selected (jumps to default in start)
	bool exit = false;

	Deck deck;	
	deck.shuffle(numdecks);

	
	for (int i = 0; i < 2; i++){         // begins game by giving out 2 cards; 
		player->addCard(deck.getTopCard()); // deals 2 cards to player
		deck--;
		dealer.addCard(deck.getTopCard()); // deals 2 cards to dealer
		deck--;
	}
	tester(&exit,bet,dealer,player);
	while(exit == false){
		double bufbet = 0; // Buffer value to add to bet (incase player wants to add more with each round) 
		clearp();
		info(bet,player,dealer); // Display game info (ie score and stuff)
		
		options(); // displays game options 
                cin >> choice;
		if (cin.good()){
		switch(choice){		
			
				case 1: //Bet Minimum Amount
					bufbet = bet+min; 
					if (bufbet > player->getCash()) cout << "BRAH YOU GOT A GAMBLING PROBLEM"<<endl;
					else bet = bufbet;
				break; 
				case 2: //Bet Custom Amount
					cout <<"Please enter custom bet:"<<endl;
					cin >> bufbet;					// REVISE FOR IF CASH IS TOO LITTLE
					bufbet = bet + bufbet;
                                	if (bufbet > player->getCash()) cout << "BRAH YOU GOT A GAMBLING PROBLEM"<<endl;
                	        	else
					bet = bufbet;
				break;
	
				case 3: //Hit (add card to player)
					player->addCard(deck.getTopCard()); 
					deck--;
				break; 
				case 4: 
					exit = true;
				
				break; // Hold (and tests hand)
				case 5: // exits 
					next = state_mMenu;
					exit = true; 
				break;  
				default: cout<<"Improper Choice"<<endl; break; //Default case ( Does nothing );
				
			}
		}
		else{
			cin.clear();
			cin.ignore(10000,'\n');
		}
			tester(&exit,bet,dealer,player);
			
			if(dealer.getScore() < 19){
				dealer.addCard(deck.getTopCard()); // deals 2 cards to dealer
				deck--;
			}
	}
	
		
		if (choice==4){
			clearp();
			dealinfo(dealer);
			tester(&exit,bet,dealer,player); //checks for winner  
			if ( dealer.getScore() > player->getScore() && dealer.getScore() < 21) {
				cout << "		Dealer Wins "<<endl;
                        	player->setCash(player->getCash() - bet);
			}
	
			if ( player->getScore() > dealer.getScore() && player->getScore() < 21){
				cout << "		Player Wins "<<endl<<endl;
                        	player->setCash(player->getCash() + bet);
			
			}
			playinfo(player);
			int menu = 1;
         		   	cout <<"1-Play another game"<<endl;
        			cout <<"2-Save Game"<<endl;
         			cout <<"3-Main Menu"<<endl;
         			cout <<"choice:";
         			cin >> menu;
         		
  
         		if (menu == 1) next = state_playGame;
         		if (menu == 2) next = state_Save;
         		if (menu == 3) next = state_mMenu;
         		
  
         	}	
				
	
	player->~Player();
	return next;
}

void clearp(){

        system("clear");
        system("cls");
	cout<<" ______________________________________"<<endl;
	cout<<"/    _______________________________   \\"<<endl;
	cout<<"|   |            __ __              |   |"<<endl;
	cout<<"| _ |    /\\     ) _) /''''',        |   |"<<endl;
	cout<<"|(.)|   <  >    \\\\ ) // '  `,       |   |"<<endl;
	cout<<"| ` |    \\/       \\\\/// ~ |~:    +  |   | "<<endl;
	cout<<"|   |             ///*\\  ' :    |   |   |"<<endl;
	cout<<"| B |            ///***\\_~.'    |   |   |"<<endl;
	cout<<"| L |  .'.    __///````,,..\\_   |   |   |"<<endl;
	cout<<"| A |   ` \\ _/* +_\\#\\\\~\\ooo/ \\  |   |   |"<<endl;
	cout<<"| C |     |/:\\ + *\\_\\#\\~\\so/!!\\ |   |   |"<<endl;
	cout<<"| K |    _\\_::\\ * + \\-\\#\\\\o/!!!\\|   |   |"<<endl;
	cout<<"|   |   / <_=::\\ + */_____@_!!!_|   |   |"<<endl;
	cout<<"| * |  <__/_____\\ */( /\\______ _|   |   |"<<endl;
	cout<<"|   |   |_   _ __\\/_)/* \\   ._/  >  |   |"<<endl;
	cout<<"|   |   | !!! @     /* + \\::=_>_/   |   |"<<endl;
	cout<<"| J |   |\\!!!/o\\\\#\\_\\ + * \\::_\\     |   |"<<endl;
	cout<<"| A |   | \\!!/os\\~\\#_\\_* + \\:/|     |   |"<<endl;
	cout<<"| C |   |  \\_/ooo\\~\\\\#_\\+_*/- \\     |   |"<<endl;
	cout<<"| K |   |    \\''``,,,,///      .`.  |   |"<<endl;
	cout<<"|   |   |     ,.- ***///        '   |   |"<<endl;
	cout<<"|   |   |    : ~  \\*///             |   |"<<endl;
	cout<<"|   |   +    : |   \\//\\             |   |"<<endl;
	cout<<"|   |        ,~  ~ //_( \\     /\\    | ; |"<<endl;
	cout<<"|   |        ,'  ` /_(__(    <  >   |(_)|"<<endl;
	cout<<"|   |         `````           \\/    |   |"<<endl;
	cout<<"|   |_______________________________|   |"<<endl;
	cout<<"\\______________________________________/"<<endl;
	cout<<"The game to end all games, and your fortune"<<endl<<"By: Ali S Ahmad"<<endl<<endl;
}

void options(){
	cout<<"1-Bet Minimum Amount"<<endl;
	cout<<"2-Bet Custom Amount"<<endl;
	cout<<"3-HIT"<<endl;
	cout<<"4-HOLD"<<endl;
	cout<<"5-EXIT"<<endl;
	cout<<"Choice?:";
}

void tester( bool *exit, double bet, Player dealer, Player *player){ 	//TESTS FOR BLACKJACK OR BREAK 	
	
 	 int output = 0; 	

         if (dealer.getScore() == 21) output = 1;
         if (player->getScore() > 21)  output = 2;
         if (dealer.getScore() > 21)  output = 3;
	 if (player->getScore() == 21) output = 4;
                                                                     
	switch(output){
	
		case 1: 
			cout << "		Dealer has blackjack. Dealer Wins" <<endl;
			player->setCash(player->getCash() - bet);	
			*exit = true;	
		break;

		case 2:	
			cout << "		Dealer Wins "<<endl; 
			player->setCash(player->getCash() - bet);
			*exit = true;
		break;
                		
		case 3: 
			cout <<"		Player Wins"<<endl;
			player->setCash(player->getCash() + bet);
			*exit = true;
		break;

		case 4: 
			cout << "		Player has blackjack. Player wins";
                        player->setCash(player->getCash() + bet*2);
			*exit = true;
		break;

		default: cout<<""; break;
	}
	
}	

void info(double bet,Player *player, Player dealer){
	cout << "------------------------------DEAL3R------------------------------"<<endl<<endl;
	dealer.showHand();
	cout << endl<<"Score: "<<dealer.getScore()<<endl<<endl;
	
	
	
	cout<<"		     Money on the Table"<<endl;
	cout<<"			   "<<bet<<endl<<endl<<endl;
	
	
	
	
	cout << "Score: "<<player->getScore()<<endl;
	player->showHand();
	cout << endl<<endl<<"------------------------------Player------------------------------"<<endl<<endl;
	cout << "Name: " << player->getFirstName()<<" " << player->getLastName()<<endl<<endl;
	cout << "Money: $"<<player->getCash()<<endl<<endl;
}
void dealinfo(Player dealer){
	cout << "------------------------------DEAL3R------------------------------"<<endl<<endl;
	dealer.showHand();
	cout << endl<<"Score: "<<dealer.getScore()<<endl<<endl;
}
void playinfo(Player *player){
	cout << "Score: "<<player->getScore()<<endl;
	player->showHand();
	cout << endl<<endl<<"------------------------------Player------------------------------"<<endl<<endl;
	cout << "Name: " << player->getFirstName()<<" " << player->getLastName()<<endl<<endl;
	cout << "Money: $"<<player->getCash()<<endl<<endl;
}
