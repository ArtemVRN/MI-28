#pragma once

#include "hge_interface.h"
#include "global.h"

DWORD color = 0;

bool RenderFunc() {
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0xB0E5FA);

	int det = settings->land_detalization;
	int* map = heighmap; // for shortness

	for (int i = 0; i < 80 * det / 4; i++)
	/* i is 'x' position on screen, where we draw next 4v */
	{

		static hgeSprite s(0, 0, 0, 0, 0);

		s.Render4V(float(i * 40 / det), float(600 - map[x + i * 4 / det] * 10 + y * 10),
			float(i * 40 / det + 40 / det), float(600 - map[x + i * 4 / det + 4/det] * 10 + y * 10),
			float(i * 40 / det + 40 / det), 600.0f,
			float(i * 40 / det), 600.0f);

	}


	/* 0xFED448 - ground color */

	hge->Gfx_EndScene();

	return false;
}