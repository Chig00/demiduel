#include <iostream>
#include <string>
#include <cstdlib>

// The incomplete command to run a specific demiduel version.
constexpr const char* PROTO_COMMAND = "\"versions/demiduel v";

// The terminating character of the command.
constexpr char COMMAND_TERMINATOR = '"';

/**
 * A function that allows one to run any available version of demiduel.
 */
int main(int argc, char** argv) noexcept {
	std::string command(PROTO_COMMAND);
	
	// If the version was specified in the command line, it is used.
	if (argc > 1) {
		command += argv[1];
	}
	
	// Else, the version is prompted for.
	else {
		std::cout << "Version: v";
		std::string version;
		std::getline(std::cin, version);
		command += version;
	}
	
	// The command must be terminated with a speech mark.
	command += COMMAND_TERMINATOR;
	
	// The desired version is run.
	system(command.c_str());
}