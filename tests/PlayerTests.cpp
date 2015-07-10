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

	// doNameDialog outputs some messages which will turn test results to mess.
	// Let's redirect cout to our own buffer, capture messages, and then
	// redirect cout back to system stdout.
	std::streambuf *originalSystemStdout = std::cout.rdbuf();
	std::stringstream redirectedHiddenCoutBuffer;
	std::cout.rdbuf(redirectedHiddenCoutBuffer.rdbuf());

	SECTION( "sets player name" ) {

		player->setName("foobar");
		player->doNameDialog();

		REQUIRE( player->name == "foobar" );

	}

	SECTION( "outputs welcome messages" ) {

		player->setName("foobar");
		player->doNameDialog();

		std::string coutMessages = redirectedHiddenCoutBuffer.str();

		REQUIRE( coutMessages.find( "Welcome" ) != std::string::npos );
		REQUIRE( coutMessages.find( "name" ) != std::string::npos );
		REQUIRE( coutMessages.find( "Hello, foobar" ) != std::string::npos );

	}

	std::cout.rdbuf(originalSystemStdout);

	delete player;

}
