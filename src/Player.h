#ifndef __PLAYER_GUARD__
#define __PLAYER_GUARD__

#include <iostream>

class Player {
	protected:
		virtual std::string promptName();
	public:
		std::string name;
		void doNameDialog();
};

#endif __PLAYER_GUARD__
