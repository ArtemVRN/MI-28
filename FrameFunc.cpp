
#include "hge_interface.h"
#include "timer.h"
#include "global.h"

/* State is function, what program should do this time */
void(*state)();

#define PRESSED(key) if (hge ## ->Input_GetKeyState(key))

bool FrameFunc() {
	
	PRESSED(HGEK_W) {
		player.height += hge->Timer_GetDelta() * 5;
	}
	//hge->System_Log("~ key pressed: y = %u", y);

	PRESSED(HGEK_S) {
		player.height -= hge->Timer_GetDelta() * 5;
	}
	//hge->System_Log("~ key pressed: y = %u", y);

	PRESSED(HGEK_D) {
		player.x += hge->Timer_GetDelta() * 5;
	}
	//hge->System_Log("~ key pressed: x = %u", x);

	PRESSED(HGEK_A) {
		player.x -= hge->Timer_GetDelta() * 5;
	}
	//hge->System_Log("~ key pressed: x = %u", x);

	hge->System_Log("* escape pressed. Exiting");

	return false;
}