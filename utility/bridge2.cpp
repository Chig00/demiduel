#include <iostream>
#include "sdlandnet.hpp"

// The number of arguments that should be passed.
constexpr int ARGUMENTS = 4;

/**
 * Hosts a two-way server bridge at two ports for connecting two clients.
 * Takes 3 command line arguments.
 * The first two should be the ports that the clients should connect to.
 * The third should be the string that, when sent from
 *   both of the clients, terminates this program.
 */
int main(int argc, char** argv) {
	// The program will not run, unless the command line argument are passed.
	if (argc != ARGUMENTS) {
		std::cerr << "\nInvalid argument count.\n";
		return -1;
	}
	
	// The system is intialised for networking.
	System::initialise(System::NET);
	
	// The version of SDL and Net utilities ia announced.
	std::cout
		<< "\nPowered by:\n"
		<< System::info()
		<< std::endl
	;
	
	{
		// The servers are intialised in another thread,
		//   such that the clients may connect in any order.
		bool dummy = false;
		std::unique_ptr<Server> source;
		std::unique_ptr<Server> destination;
		ServerPackage source_package(source, dummy, std::stoi(argv[1]));
		ServerPackage destination_package(destination, dummy, std::stoi(argv[2]));
		Thread source_thread(ServerPackage::make_server, &source_package);
		Thread destination_thread(ServerPackage::make_server, &destination_package);
		
		// Waits for both clients to connect.
		while (!source || !destination);
		
		// The two-way bridge is formed and will last until
		//   the terminator string is sent from both clients.
		// The terminator string is still sent before termination.
		ClientPackage package(*source, *destination, argv[3]);
		Thread thread(ClientPackage::make_bridge, &package);
		ClientPackage package2(*destination, *source, argv[3]);
		Thread thread2(ClientPackage::make_bridge, &package2);
	}
	
	// The sytem is terminated.
	System::terminate();
	return 0;
}