// School budget
// By suclearnub

#define GAME_VERSION "0.6.1"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
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

void addRandomAmountToBudget(int &schoolBudget, int reputation, int schoolPop)
{
	cout << "Last month has brought you some extra budget.\n";
	int rng = rand() % 20 + 30; //redo rng
	int schoolBudgetAdd = (reputation*schoolPop*rng);
	cout << schoolBudgetAdd << " has been added to your account.\n";
	schoolBudget += schoolBudgetAdd;
}

int main()
{
	bool fail;
	int schoolBudget; // Currency
	int schoolBudgetAdd; // Currency to add every month where month != 1
	double reputation = 1.0; // Hidden reputation, can use sB to check
	int schoolPop = 100; // Always known, school population
	int month = 0; // Month
	int selectedChoiceNumber;
	string name;
	double score;
	vector<ActionChoice> actionChoices;
	
	// Teacher improvement
	char teachers[10][15] = {
		"Carlos", "5",
		"Benjamin", "4",
		"Lenny", "8",
		"Jenny", "3",
		"Herlit", "2",
	};

	srand(time(0)*time(0)*time(0)*time(0)); //init rand

	schoolBudget = rand() % 100000 + 50000;

	name = promptUsername();

	actionChoices = {
		{
			"Improve the toilets ($20,000).",
			"You've improved the toilets.",
			[&]() {
				schoolBudget -= 20000;
				reputation += 0.4;
			}
		},
		{
			"Put flower pots for more beauty ($15,000).",
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
				int rng = rand() % 4;
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
			"Food sale (+$10,000). Will lower population in exchange for money boost.",
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
				int rng = rand() % 4;
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
			"Improve sound systems ($20,000). Will lower reputation in exchange for population.",
			"You install new sound systems for the school.",
			[&]() {
				string respects;
				cout << "How tragic: During testing of the sound systems, some students have their eardrums severely injured.\n";
				cout << "Please pay some respects: ";
				cin >> respects;
				if(respects == "F","f") {
					reputation -= 0.1;
				}
				else {
					reputation -= 0.2;
					schoolPop += 5;
				}
			}
		},
		{
			"Automagic water fountains ($10,000). Make the students happier?",
			"You install new automatic water fountains.",
			[&]() {
				cout << "However, none of them work.\n";
				int rng = rand() % 1 + 2;
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
			"Parasols in cafeteria ($15,000). Will lower population in exchange for reputation.",
			"These new parasols look great! Everyone loves you for it. However some students have left because they are allergic to yellow umbrellas.",
			[&]() {
				schoolPop -= 5;
				reputation += 0.15;
			}
		},

		{
			"New building block ($100,000). Money in exchange for population and reputation boost.",
			"You build a new building - hopefully not with tofu.",
			[&]() {
				cout << "Everyone loves you now! They have more rooms to  learn in. \n";
				schoolBudget -= 100000;
				schoolPop += 15;
				reputation += 0.3;
			}
		},

		{
			"Hire a teacher of unknown quality for an unknown cost.",
			"You hired a teacher - but it'll be some time before you know how well he performs.",
			[&]() {
				int teacherQuality, teacherCost;
				string teacherQualityDescription;

				teacherQuality = rand() % 1 + 3;
				if(teacherQuality==3) {
					teacherQualityDescription = "loved";
					teacherCost = 15000;
				}
				else if(teacherQuality==2) {
					teacherQualityDescription = "neutral";
					teacherCost = 10000;
				}
				else if(teacherQuality==1)  {
					teacherQualityDescription = "hated";
					teacherCost = 5000;
				}
				else {
					teacherQualityDescription = "bugged";
				}

				cout << "This teacher is... " << teacherQualityDescription << " It costed you " << teacherCost << " to hire the teacher.";

				schoolBudget -= teacherCost;
			}
		},
		
		{
			"Open up some extra scholarship spots ($30000). Population in exchange for huge amounts of reputation and a bit of money.",
			"You open up some spots for those who are really good at stuff like science and sports.",
			[&]() {
				schoolBudget -= 30000;
				schoolPop += 30;
				reputation -= 0.6;
				cout << "You have lost 0.6 reputation because many people claim that the money could've been spent in a better way that fund a student that isn't poor.";
			}
		},
	};

	for(month = 1; month <= 12; month++) {	// <- Loops through 12 months

		cout << "-----------------------\n";
		cout << "Month " << month << "\n";
		if(month!=1) {	//schoolBudgetAdd
			addRandomAmountToBudget(schoolBudget, reputation, schoolPop);
		}
		if(reputation<=0) {
			cout << "The school is very disappointed with you. You have been dismissed.";
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

		while( ! ( cin >> selectedChoiceNumber ) ) {
			cout << "Invalid input. Try again: ";
			cin.clear();
			cin.ignore( numeric_limits<int>::max(), '\n' );
		}

		cout << "Alright... As you wish.\n\n";

		selectedChoiceNumber -= 1;

		if (selectedChoiceNumber >= 0 && selectedChoiceNumber < actionChoices.size()) {
			cout << actionChoices[selectedChoiceNumber].resultMessage << "\n";
			actionChoices[selectedChoiceNumber].action();
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
