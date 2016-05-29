
#include "hge_interface.h"
#include "timer.h"

/* State is function, what program should do this time */
void(*state)();


bool FrameFunc() {
	
	static float x = 40, y = 90;
	int key = hge->Input_GetKey();

	switch (key) {
	case HGEK_UP:
		y++;
		break;
	case HGEK_DOWN:
		y--;
		break;
	case HGEK_RIGHT:
		x++;
		break;
	case HGEK_LEFT:
		x--;
		break;
	case HGEK_ESCAPE:
		hge->System_Log("* Escape pressed. Exiting");
		return true;
	}

	return false;
}