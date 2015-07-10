#include "diego/catch/catch.hpp"
#include "../src/Player.h"

#include <iostream>

class MockedPlayer : public Player {
	protected:
		std::string promptName() {
			return name;
		}
	public:
		void setName(std::string newName) {
			name = newName;
		}
};

TEST_CASE( "Player::doNameDialog" ) {

	MockedPlayer *player = new MockedPlayer();

	SECTION( "sets player name" ) {

		player->setName("foobar");
		player->doNameDialog();

		REQUIRE( player->name == "foobar" );

	}

	delete player;

}
