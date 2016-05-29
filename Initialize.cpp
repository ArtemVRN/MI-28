
#include "hge_interface.h"
#include "global.h"
#include "mapgen.h"

extern DWORD color;
extern bool Exit;

bool Initialize() {

	hge->System_SetState(HGE_LOGFILE, "log.txt");
	hge->System_Log("Game successfully started. Initializing...");

	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENWIDTH, 800);

	hge->System_Log("~ window made");

	settings = load_settings("settings.txt");
	
	if (!settings) {
		hge->System_Log("! failed to load settings - no settings file. Using defaults");
	}else{
		hge->System_Log("~ settings loaded");
	}

	hge->System_Log("~ creating map");
	if (!generate_map()) {
		hge->System_Log("~ map was successfully generated");
	}
	else {
		hge->System_Log("!! map was not generated. Can not continue initialization");
		return true;
	}

	hge->System_Log("~ initialization finished\n\nGame Cycling...");
	
	return false;
}