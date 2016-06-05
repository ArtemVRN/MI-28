#pragma once

#include "hge_interface.h"
#include "global.h"

DWORD color = 0;

bool RenderFunc() {
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0xB0E5FA);

	int det = settings->land_detalization;

	/*hgeQuad* q = new hgeQuad;
	//q->blend = 0;
	q->tex = 0;*/
	for (int i = 0; i < 80; i+=4/settings->land_detalization) {
		
		hgeSprite s(0, 0, 0, 0, 0);

		s.Render4V(i * 10 * 4 / det, 600 - heighmap[i+x] * 10 * 4 / det + y*10 * 4 / det,
			i * 10 * 4 / det + 10 * 4 / det, 600 - heighmap[i + 1 + x] * 10 * 4 / det + y*10,
			i * 10 * 4 / det + 10 * 4 / det, 600,
			i * 10 * 4 / det, 600);

	}

	/* 0xFED448 - ground color */

	hge->Gfx_EndScene();

	return false;
}