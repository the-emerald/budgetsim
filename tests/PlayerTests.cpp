#include "diego/catch/catch.hpp"
#include "../src/Player.h"

#include <iostream>

class MockedPlayer : public Player {
	protected:
		std::string promptName() {
			return "foobar";
		}
};

TEST_CASE( "doNameDialog" ) {
	MockedPlayer *player = new MockedPlayer();

	SECTION( "sets player name" ) {
		player->doNameDialog();
		REQUIRE( player->name == "foobar" );
	}

	delete player;
}
