#pragma once

#include "hge_interface.h"


struct Resources {
	struct Sprites{
		hgeSprite *helly, *infantry, *inf_w, *tank, *tank_w,
			*aa, *aa_w, *car, *car_w, *build1, *build2, *boat, *boat_w,
			*ship, *ship_w, *ground;
	} sprites;
	
	struct Music{
		HMUSIC *theme;
	} music;

	struct Effects{
		HEFFECT *explosion, *pif, *shot_in, *ag_rocket, *aa_rocket;
	}effects;
};


bool load_res();