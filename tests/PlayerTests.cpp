#include "diego/catch/catch.hpp"

#include "../src/Player.h"

TEST_CASE( "promptName" ) {
	Player *p = new Player();
	p->promptName();

	SECTION("sets the name property") {
    	REQUIRE( p->name == "foobar" );
	}

    delete p;
}
