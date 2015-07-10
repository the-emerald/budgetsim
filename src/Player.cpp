#include "Player.h"

#include <iostream>

using namespace std;

string Player::promptName() {
	string name;
	cin >> name;
	return name;
}

void Player::doNameDialog() {
	name = promptName();
}
