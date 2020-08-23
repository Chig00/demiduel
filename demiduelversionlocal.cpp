#include <iostream>
#include "sdlandnet.hpp"

// The incomplete command to run a specific demiduel version.
constexpr const char* PROTO_COMMAND = "\"versions/demiduel v";

// The terminating character of the command.
constexpr const char* COMMAND_TERMINATOR = "\" 700 400";

/**
 * Runs one instance of the demiduel version.
 */
int run(void* data) noexcept {
	System::command(static_cast<const char*>(data));
	return 0;
}

/**
 * A function that allows one to run two instances of any available version of demiduel.
 * The version of demiduel is run in small screen mode.
 * Note that older versions do not support small screen mode.
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
	
	// Two instances of the desired version are run.
	
	Thread thread(run, const_cast<char*>(command.c_str()));
	run(const_cast<char*>(command.c_str()));
	thread.wait();
	
	return 0;
}