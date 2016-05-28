#pragma once

#include "hge_interface.h"


struct Resources {
	HTEXTURE helly, infantry, inf_w, tank, tank_w,
		aa, aa_w, car, car_w, build1, build2, boat, boat_w,
		ship, ship_w;
	
	HMUSIC theme;
	HEFFECT explosion, pif, shot_in, ag_rocket, aa_rocket;
};

extern Resources res;