// School budget
// By suclearnub

#define GAME_VERSION "0.3.6"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <limits>
#include <functional>
#include <vector>
using namespace std;

// http://www.codeguru.com/cpp/cpp/cpp_mfc/stl/article.php/c4027/C-Tutorial-A-Beginners-Guide-to-stdvector-Part-1.htm
// http://stackoverflow.com/questions/6601930/c11-lambda-as-member-variable
// http://stackoverflow.com/questions/8906545/how-to-initialize-a-vector-in-c
// http://stackoverflow.com/questions/11516657/c-structure-initialization
struct ActionChoice {
	string title;
	string resultMessage;
	function<void()> action;
};

string promptUsername()
{
	string name;

	cout << "Welcome to School Budget Simulator 2015. Version " << GAME_VERSION << "\n";
	cout << "What's your name? ";
	cin >> name;
	cout << "Hello, " << name <<".\n\n"; // Easter egg
	if(name=="Kenny") {
		cout << "ey b0ss\n";
	}
	if(name=="boss") {
		cout << "can i habe a pizza pls?";
	}

	cout << "...\n";

	return name;
}

int main()
{
	bool fail;
	bool developerMode;
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
	vector<ActionChoice> actionChoices;

	srand(time(0)*time(0)*time(0)*time(0)); //init rand

	schoolBudget = rand() % 100000 + 50000;

	name = promptUsername();

	actionChoices = {
		{
			"Improve the toilets ($20000).",
			"You've improved the toilets.",
			[&]() {
				schoolBudget -= 20000;
				reputation += 0.4;
			}
		},
		{
			"Put flower pots for more beauty ($15000).",
			"You put flower pots around the school.",
			[&]() {
				schoolBudget -= 15000;
				reputation += 0.1;
			}
		},
		{
			"Dress up day ($1000). Chance of increasing or decreasing reputation.",
			"You put up a fabulous dress up day.",
			[&]() {
				rng = rand() % 4;
				schoolBudget -= 1000;
				cout << "That went ";
				if(rng>=2) {
					cout << "alright. You gained 0.1 reputation.\n";
					reputation += 0.1;
				}
				else {
					cout << "not very well. You lost 0.1 reputation.\n";
					reputation -= 0.1;
				}
				reputation += rng;
			}
		},
		{
			"Food sale (+$10000). Will lower population in exchange for money boost.",
			"You ask the students to make food for sale.",
			[&]() {
				cout << "You've lost 5 population but you gained some money!\n";
				schoolPop -= 5;
				schoolBudget += 10000;
			}
		},
		{
			"Introduction to school ($5000). Chance of increasing or decreasing population.",
			"You introduce more people to the school.",
			[&]() {
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
			}
		},
		{
			"Improve sound systems ($20000). Will lower reputation in exchange for population.",
			"You install new sound systems for the school.",
			[&]() {
				cout << "How tragic: During testing of the sound systems, some students have their eardrums severely injured.\n";
				cout << "Please pay some respects: ";
				cin >> sixChoice;
				if(sixChoice == "F","f") {
					reputation -= 0.1;
				}
				else {
					reputation -= 0.2;
					schoolPop += 5;
				}
			}
		},
		{
			"Automagic water fountains ($10000). Make the students happier?",
			"You install new automatic water fountains.",
			[&]() {
				cout << "However, none of them work.\n";
				rng = rand() % 1 + 2;
				if(rng==2) {
					cout << "It flooded the school! You have to pay lots of money to fix it now.\n";
					schoolBudget -= 20000;
				}
				else {
					cout << "Thank god that it didn't flood or break. They just don't work.\n";
				}
				cout << "Oh well, back to manual water fountains it is.\n";
			}
		},
		{
			"Parasols in cafeteria ($15000). Will lower population in exchange for reputation.",
			"These new parasols look great! Everyone loves you for it. However some students have left because they are allergic to yellow umbrellas.",
			[&]() {
				schoolPop -= 5;
				reputation += 0.15;
			}
		},
	};

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
		}
		cout << "Welcome. What would you like to work on? \n";
		cout << "\n";
		cout << "Right now you have: " << schoolBudget << " dollars.\n";
		cout << "...\n";

		// http://stackoverflow.com/questions/12702561/c-iterate-through-vector-using-for-loop
		int i = 1;
		for (auto &choice : actionChoices) {
			cout << i++ << ". " << choice.title << "\n";
		}

		cout << "What would you like to do this month? ";

		while( ! ( cin >> choice ) ) {
			cout << "Invalid input. Try again: ";
			cin.clear();
			cin.ignore( numeric_limits<int>::max(), '\n' );
		}

		cout << "Alright... As you wish.\n\n";

		choice -= 1;

		if (choice >= 0 && choice < actionChoices.size()) {
			cout << actionChoices[choice].resultMessage << "\n";
			actionChoices[choice].action();
		} else {
			cout << "Administration didn't understand what you mean. They spent the whole month on seminars. (-$1000)\n";
			schoolBudget -= 1000;
		}

	}

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

	return 0;
}
