#include "Player.h"

#include <iostream>

using namespace std;

string Player::promptName() {
	string name;
	cin >> name;
	return name;
}

void Player::doNameDialog() {
	cout << "Welcome to School Budget Simulator 2015!\n";
	cout << "What's your name? ";

	name = promptName();

	cout << "Hello, " << name << "!";

	if ( name == "Kenny" ) {
		cout << " ey b0ss";
	} else if ( name == "boss" ) {
		cout << " can i habe a pizza pls?";
	}

	cout << "\n\n";
}
