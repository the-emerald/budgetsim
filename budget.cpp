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
	bool fail;
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
	string sixChoice; //choice for option 6
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
	if(name=="boss") {
		cout << "can i habe a pizza pls?";
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
		if(reputation<=0) {
			cout << "The school is very disappointed with you. You have been dismissed. There will be no score.";
			fail = true;
			break;
			//exit;
			//return 0;	 Who cares? Whatever it is, I'm not going to make a function. (fixed)
		}
		cout << "Welcome. What would you like to work on? \n";
		cout << "\n";
		cout << "Right now you have: " << schoolBudget << " dollars.\n";
		cout << "...\n";
			cout << "1. Improve the toilets ($20000)\n";
			cout << "2. Put flower pots for more beauty ($15000)\n";
			cout << "3. Dress up day ($1000). Chance of increasing or decreasing reputation.\n";
			cout << "4. Food sale (+$10000). Will lower population in exchange for money boost.\n";
			cout << "5. Introduction to school ($5000). Chance of increasing or decreasing population.\n";
			cout << "6. Improve sound systems ($20000). Will lower reputation in exchange for population.\n";
			cout << "7. Automagic water fountains ($10000). Make the students happier?";
			cout << "8. Parasols in cafeteria ($15000). Will lower population in exchange for reputation";
			
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
					cout << "alright. You gained 0.1 reputation.\n\n";
					reputation += 0.1;
				}
				else {
					cout << "Not very well. You lost 0.1 reputation.\n\n";
					reputation -= 0.1;
				}
				reputation += rng;
				break;
			case 4:
				cout << "You ask the students to make food for sale.\n";
				cout << "You've lost 5 population but you gained some money!\n";
				schoolPop -= 5;
				schoolBudget += 10000;
				break;
			case 5:
				cout << "You introduce more people to the school.";
				schoolBudget -= 5000;
				cout << "The event went ";
				rng = rand() % 4;
				if(rng>=2) {
					rng = 10;
					cout << "alright. You gained 10 students! \n";
				}
				else {
					rng = -10;
					cout << "terribly wrong. Students are leaving! You've lost 10 students.\n";
				}
				break;
			case 6:
				schoolBudget -= 20000;
				cout << "You install new sound systems for the school.";
				cout << "How tragic: During testing of the sound systems, some students have their eardrums severely injured.\n";
				cout << "Please pay some respects: ";
				cin >> sixChoice;
				if(sixChoice == "F","f") {
					//schoolBudget += 5000
					reputation -= 0.1;
				}
				else {
					reputation -= 0.2;
					schoolPop += 5;
				}
				break;
			case 7:
				schoolBudget -= 10000;
				cout << "You install new automatic water fountains.\n";
				cout << "However, none of them work.";
				rng = rand() % 1 + 2;
				if(rng==2) {
					cout << "It flooded the school! You have to pay lots of money to fix it now.\n";
					schoolBudget -= 20000;
				}
				else {
					cout << "Thank god that it didn't flood or break. They just don't work.\n";
				}
				cout << "Oh well, back to manual water fountains it is.\n";
				break;
			case 8:
				schoolBudget -= 15000;
				cout << "These new parasols look great! Everyone loves you for it. However some students have left because they are allergic to yellow umbrellas.\n";
				schoolPop -= 5;
				reputation += 0.15;
				break;
			default:
				cout << "Administration didn't understand what you mean. They spent the whole month on seminars. (-$1000)";
				schoolBudget -= 1000;
				//break; <<-- don't do it
			
		}
		
	}
	
	
	//cout << "Foobar";
	if(fail==true) {
		score = sqrt(schoolBudget)*0.4;
	}
	else {
		score = sqrt(schoolBudget);
	}
	cout << "\n----------\n";
	cout << "It's the end of your term. Your score is...\n";
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