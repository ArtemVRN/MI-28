#pragma once

#include "settings.h"

struct Player {
	int x, height, patrons, hp;
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

extern unsigned x, y; // camera