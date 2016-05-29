#include "mapgen.h"

#include "hge_interface.h"

/* Returns true if map was generated successfully */
bool generate_map()
{
	int len = settings->maplen;
	int det = settings->land_detalization;
	int start = settings->startheight;
	int enem = settings->enemies;

	heighmap = new int[len+80];
	enemies = new Enemy;
	Enemy* curen = enemies;

	// secutity   
	if (start <= 0) {
		hge->System_Log("! too low startheight (%d), return to default (100)", start);
		start = settings->startheight = 100;
	}

	for (int i = 0; i < 80; i += 4/det) {
		heighmap[i] = start;
	}

	char direction = 1;	// 1 - up; -1 - down
	for (int i = 80; i < len+80; i += 4 / det) {
		
		char enemy = ((rand() % 101) + 1) < enem; // is enemy
		if (enemy) {
			heighmap[i] = heighmap[i - 1];
			curen->type = (Enemy::Type)(rand() % 4 + 1);
			curen->x = i;
			curen = curen->next = new Enemy;
		}
		else {
			for (int j = 0; j < 4 / det; i++, j++) 
				heighmap[i] = heighmap[i - 1] + direction*((rand() % 2) + 1);
				
			direction -= 2 * direction;
		}
	}

	return false;
}
