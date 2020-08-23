#include "sdlandnet.hpp"

/**
 * Runs one instance of demiduelmini.
 */
int run(void* data = nullptr) noexcept {
	System::command("demiduelmini");
	return 0;
}

/**
 * Runs two instances of demiduelmini simultaneously.
 */
int main(int argc, char** argv) noexcept {
	Thread thread(run);
	run();
	thread.wait();
	
	return 0;
}