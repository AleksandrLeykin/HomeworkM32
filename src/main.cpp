#include <iostream>
#include "ThatUsesDB.h"


int main(int argc, char* argv[]) {
	
	ThatUsesDB server;
	DBConnection cn;
	
	int result = server.useConnection(cn, "Ivan", "123");
	if (result == 0) {
		std::cout << "request successful!\n";
	}
	else {
		std::cout << "request not successful!\n";
	}

	return 0;
}