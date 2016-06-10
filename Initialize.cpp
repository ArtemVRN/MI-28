
#include "hge_interface.h"
#include "global.h"
#include "mapgen.h"
#include "resources.h"

extern DWORD color;
extern bool Exit;

void player_init();

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
//		hge->System_Log("~ map was successfully generated");
	}
	else {
		hge->System_Log("!! map was not generated. Can not continue initialization");
		return true;
	}

	hge->System_Log("~ loading resources");
	if (load_res()) {
		hge->System_Log("!! loading of the resources failed");
		return true;
	}

	hge->System_Log("~ initializing player");
	player_init();

	hge->System_Log("~ initialization finished\n\nGame Cycling...");
	
	return false;
}



void player_init() {
	player.x = 50.0f;
	player.height = 90.0f;
	player.hp = 100.0f;
	player.patrons = 10;
	player.casset = 14;
}