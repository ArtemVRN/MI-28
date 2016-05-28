
#include "hge_interface.h"
#include "timer.h"

/* State is function, what program should do this time */
void(*state)();


bool FrameFunc() {
	
	int key;
	if (key = hge->Input_GetKey()) {

		hge->System_Log("* Key %d pressed. Exiting", key);
		return true;
	}

	return false;
}