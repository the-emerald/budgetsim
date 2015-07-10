// School budget
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <limits>
#include <functional>
#include <vector>

#include "metadata.h"
#include "Player.h"

using namespace std;

struct ActionChoice {
	string title;
	string resultMessage;
	function<void()> action;
};

void addRandomAmountToBudget(int &schoolBudget, int reputation, int schoolPop)
{
	cout << "Last month has brought you some extra budget.\n";

	int rng = rand() % 20 + 30; //redo rng
	int schoolBudgetAdd = (reputation*schoolPop*rng);
	schoolBudget += schoolBudgetAdd;

	cout << schoolBudgetAdd << " has been added to your account.\n";
}

int main()
{
	Player *player = new Player;

	bool fail;
	int schoolBudget;
	int schoolBudgetAdd;
	double reputation = 1.0;
	int schoolPop = 100;
	int month = 0;
	int selectedChoiceNumber;
	int teacherA;
	double score;
	int teacherRandom;
	vector<ActionChoice> actionChoices;

	char teachers[10][15] = {
		"Carlos", "5",
		"Benjamin", "4",
		"Lenny", "8",
		"Jenny", "-3",
		"Herlit", "-2",
	};

	srand(time(0)*time(0)*time(0)*time(0));

	schoolBudget = rand() % 100000 + 50000;

	player->doNameDialog();

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
			"Hire a teacher. Administration has given you a list already.",
			"You take a look...",
			[&]() {
				int teacherChoice;
				cout << "The teachers are...\n";
				cout << "1. Carlos\n";
				cout << "2. Benjamin\n";
				cout << "3. Lenny\n";
				cout << "4. Jenny\n";
				cout << "5. Herlit\n";
				cout << "...\n";
				cout << "What's your choice? ";
				while( ! ( cin >> teacherChoice ) ) {
					cout << "Invalid input. Try again: ";
					cin.clear();
					cin.ignore( numeric_limits<int>::max(), '\n' );
				}
				if(teacherChoice > 5) {
					cout << "What teacher? Administration asks. So all they did this month was sit around a desk and discuss their plans for next month.";
				}
				else {
					teacherChoice = (teacherChoice*2)-1;
					cout << "The teacher has been interviewed and has been given a mark out of ten. The mark is " << teachers[teacherChoice] << " .";
					string teacherOutput = teachers[teacherChoice];
					teacherA = atoi(teacherOutput.c_str());

					reputation += teacherA/10;
					schoolBudget -= teacherA*1000;
				}
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

	for (month = 1; month <= 12; month++) {
		cout << "-----------------------\n";
		cout << "Month " << month << "\n";

		if (month != 1) {
			addRandomAmountToBudget(schoolBudget, reputation, schoolPop);
		}

		if (reputation <= 0) {
			cout << "The school is very disappointed with you. You have been dismissed.";
			fail = true;
			break;
		}

		cout << "Welcome. What would you like to work on? \n";
		cout << "\n";
		cout << "Right now you have: " << schoolBudget << " dollars.\n";
		cout << "...\n";

		int i = 1;
		for (auto &choice : actionChoices) {
			cout << i++ << ". " << choice.title << "\n";
		}

		cout << "What would you like to do this month? ";

		while (!(cin >> selectedChoiceNumber)) {
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

	if (fail) {
		score = sqrt(schoolBudget)*0.4;
	} else {
		score = sqrt(schoolBudget);
	}

	cout << "\n----------\n";
	cout << "It's the end of your term. Your score is...\n";

	if (schoolBudget >= 0) {
		cout << score;
	} else {
		cout <<" so bad, it's negative. Ask yourself, did you even try?";
	}

	cout << "\nExit the game by entering anything. > ";
	cin >> score;

	return 0;
}
