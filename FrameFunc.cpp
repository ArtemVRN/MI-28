
#include "hge_interface.h"
#include "timer.h"
#include "global.h"

/* State is function, what program should do this time */
void(*state)();


bool FrameFunc() {
	
	int key = hge->Input_GetKey();

	switch (key) {
	case HGEK_UP:
		y++;
		//hge->System_Log("~ key pressed: y = %u", y);
		break;
	case HGEK_DOWN:
		y--;
		//hge->System_Log("~ key pressed: y = %u", y);
		break;
	case HGEK_RIGHT:
		x+= 4/settings->land_detalization;
		//hge->System_Log("~ key pressed: x = %u", x);
		break;
	case HGEK_LEFT:
		x-= 4 / settings->land_detalization;
		//hge->System_Log("~ key pressed: x = %u", x);
		break;
	case HGEK_ESCAPE:
		hge->System_Log("* escape pressed. Exiting");
		return true;
	}

	return false;
}