#include <cstdlib>

/**
 * Compiles demiduel.cpp into the executable demiduel.exe
 */
int main() noexcept {
	system("g++ demiduel.cpp -o demiduel -l mingw32 -l sdl2main -l sdl2 -l sdl2_net");
	return 0;
}