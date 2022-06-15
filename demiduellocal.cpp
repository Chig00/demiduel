#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>
#include "sdlandnet.hpp"

std::string x;
std::string y;

/**
 * Runs one instance of demiduelmini.
 */
int run(void* data = nullptr) noexcept {
    if (x.size() && y.size()) {
        System::command(("demiduel " + x + " " + y).c_str());
    }
    
    else {
        System::command("demiduelmini");
    }
	return 0;
}

/**
 * Runs two instances of demiduelmini simultaneously.
 */
int main(int argc, char** argv) noexcept {
    if (argc == 3) {
        x = argv[1];
        y = argv[2];
    }
    
	Thread thread(run);
	run();
	thread.wait();
	
	return 0;
}