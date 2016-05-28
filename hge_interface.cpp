
#include "hge_interface.h"
#include "timer.h"

HGE* hge;

bool engine__frame(){

	timerHost.Update();
	return FrameFunc() || RenderFunc();

}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_FRAMEFUNC, engine__frame);
	
	/* To optimize it: --> */
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	/* So, we can not to open fullscreen by the time we execute the app */

	if (hge->System_Initiate()) {

		if (!Initialize())
			hge->System_Start();
	}

	Clean();
	hge->System_Shutdown();
	hge->Release();
}