#pragma once

#include "settings.h"

struct Player {
	int x, height, patrons, hp;
};
extern Player player;

struct Enemy {
	enum Type{
		EMPTY = 0, INFANTRY, TANK, BUILDING, SHIP, BOAT
	} type = EMPTY;
	int x;
};

extern Enemy* enemies;
extern int* heighmap;	// each mapheight strongly per 40px
extern Settings* settings;