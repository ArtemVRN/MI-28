#pragma once

#include "settings.h"
#include "resources.h"

struct Player {
	float x, height, hp;
	int patrons, casset;
};
extern Player player;

struct Enemy {
	enum Type{
		EMPTY = 0, INFANTRY, TANK, BUILDING//, SHIP, BOAT
	} type = EMPTY;
	int x;
	Enemy* next;
};
extern int enemyCount; // number of enemies

extern Enemy* enemies; // list of enemies
extern int* heighmap;	// each mapheight strongly per 40px
extern Settings* settings; // global settings

extern Resources res;