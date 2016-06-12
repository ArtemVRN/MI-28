#pragma once

#include "hge_interface.h"
#include "global.h"

DWORD color = 0;

bool RenderFunc() {
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0xB0E5FA);

	int det = settings->land_detalization;
	int* map = heighmap; // for shortness

	int x = int(player.x); x -= x % 4;
	float delta = player.x - x, y = player.height;

	for (int i = 0; i < 21 * det; i++) // (21 * det) = (80 * det / 4)
		/* i is 'x' position on screen, where we draw next 4v */
	{

		res.sprites.ground->Render4V(float(i * 40 / det) - delta * 10, float(600 - map[x + i * 4 / det] * 10 + y * 10),
			float(i * 40 / det + 40 / det) - delta * 10, float(600 - map[x + i * 4 / det + 4 / det] * 10 + y * 10),
			float(i * 40 / det + 40 / det) - delta * 10, 600.0f,
			float(i * 40 / det) - delta * 10, 600.0f);

	}


	/* 0xFED448 - ground color */

	hge->Gfx_EndScene();

	return false;
}