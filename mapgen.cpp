#include "mapgen.h"

#include "hge_interface.h"

/* Returns true if map was generated successfully */
bool generate_map()
{
	int len = settings->maplen; len += len % 4; // we should have len = 4*n
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

	for (int i = 0; i < 80; i++) {
		heighmap[i] = start;
	}

	int direction = 1;	// 1 - up; -1 - down
	for (int i = 80; i < len + 80; i += 4) {
		
		char enemy = ((rand() % 101) + 1) < enem; // is enemy
		if (enemy) {			/*  Check this  */
			heighmap[i] = heighmap[i - 1];
			curen->type = (Enemy::Type)(rand() % 4 + 1); // main issue is gen in water
			curen->x = i;
			curen = curen->next = new Enemy;
		}						/*  Check enemy gen  */
		else {
			for (int j = 0; j < 4; j++)
				heighmap[i + j] = heighmap[i + j - 1] + direction * (rand() % 3);

			direction -= 2 * direction;
		}
	}
	
	/*
		Now map generated. Every cell has its own heigh,
		not depends on detalization.
		Detalization only used in graphics. Sure? Go!
	*/

	return false;
}
