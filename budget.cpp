// School budget
// By suclearnub

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <limits>
using namespace std;

int main()
{
	
	bool developerMode;
	float version = 0.3;
	int schoolBudget; // Currency
	int schoolBudgetAdd; // Currency to add every month where month != 1
	double reputation = 1.0; // Hidden reputation, can use sB to check
	int schoolPop = 100; // Always known, school population
	int month = 0; // Month
	int choice; // Choice
	int rng; //RNGesus
	string name;
	
	double score;
	
	srand(time(0)*time(0)*time(0)*time(0)); //init rand
	
	schoolBudget = rand() % 100000 + 50000;
	
	cout << "Welcome to School Budget Simulator 2015. Version " << version << "\n";
	cout << "What's your name? ";
	cin >> name;
	cout << "Hello, " << name <<".\n\n"; // Easter egg
	if(name=="Kenny") {
		cout << "ey b0ss\n";
	}
	//cout << "It is new year. You have new amount of money!\n";
	//cout << "You have: " << schoolBudget << " HKD. How lucky.\n";
	
	cout << "...\n";
	
	
	for(month = 1; month <= 12; month++) {
		
		cout << "-----------------------\n";
		cout << "Month " << month << "\n";
		if(month!=1) {	//schoolBudgetAdd
			cout << "Last month has brought you some extra budget.\n";
			rng = rand() % 20 + 30; //redo rng
			schoolBudgetAdd = reputation*schoolPop*rng;
			cout << schoolBudgetAdd << " has been added to your account.\n";
			schoolBudget += schoolBudgetAdd;
		}
		cout << "Welcome. What would you like to work on? \n";
		cout << "\n";
		cout << "Right now you have: " << schoolBudget << " dollars.\n";
		cout << "...\n";
			cout << "1. Improve the toilets ($20000)\n";
			cout << "2. Put flower pots for more beauty ($15000)\n";
			cout << "3. Dress up day ($1000). Chance of increasing or decreasing reputation.\n";
			cout << "4. Food sale (+$10000). Will lower population in exchange for money boost.\n";
			
		cout << "What would you like to do this month? ";
		while( ! ( cin >> choice ) ) {
			cout << "Invalid input. Try again: ";
			cin.clear();
			cin.ignore( numeric_limits<int>::max(), '\n' );
		}
		
		cout << "Alright... As you wish.\n\n";
		switch(choice) {
			case 1:	// Is this python?
				cout << "You've improved the toilets.\n";
				schoolBudget -= 20000;
				reputation += 0.4;
				break;
			case 2:
				cout << "You put flower pots around the school.\n";
				schoolBudget -= 15000;
				reputation += 0.1;
				break;
			case 3:
				cout << "You put up a fabulous dress up day.\n";
				schoolBudget -= 1000;
				rng = rand() % 4; // There we go fixed it
				cout << "That went ";
				if(rng>=2) {
					rng = 1;
					cout << "alright. You gained " << rng << " reputation.\n\n";
					reputation += rng;
				}
				else {
					rng = -0.5;
					cout << "Not very well. You lost 0.5 reputation.\n\n";
					reputation -= 0.5;
				}
				reputation += rng;
				break;
			case 4:
				cout << "You ask the students to make food for sale.\n";
				cout << "You've lost 10 population but you gained some money!\n";
				schoolPop -= 100;
				schoolBudget += 10000;
				break;
			default:
				cout << "Administration didn't understand what you mean. They spent the whole month on seminars. [default]";
				schoolBudget -= 1000;
				//break; <<-- don't
			
		}
		
	}
	
	
	//cout << "Foobar";
	score = sqrt(schoolBudget);
	cout << "It's the end of a year. You've done an excellent job. Your score is...\n";
	if(schoolBudget>=0) {
		cout << score;
	}
	else {
		cout <<" so bad, it's negative. Ask yourself, did you even try?";	//gg no re
	}
	
	cout << "\nExit the game by entering anything. > ";
	cin >> score;
	
	
	//schoolBudget = 0;
	//cout << "School budget is: " << schoolBudget << " dollars.";
	//return 0;
	//Haha
	
	return 0;
}