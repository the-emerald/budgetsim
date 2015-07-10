#include <iostream>

class Player {
	protected:
		virtual std::string promptName();
	public:
		std::string name;
		void doNameDialog();
};
