#pragma once

#include "hge_interface.h"
#include "global.h"

DWORD color = 0;

bool RenderFunc() {
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0xB0E5FA);

	/*hgeQuad* q = new hgeQuad;
	//q->blend = 0;
	q->tex = 0;*/
	for (int i = 0; i < 80; i++) {
		/*
		q->v[0].x = x + i;
		q->v[0].y = heighmap[i] + y;
		
		q->v[1].x = x + i + 1;
		q->v[1].y = heighmap[i+1] + y;

		q->v[2].x = x + i + 1;
		q->v[2].y = 600;

		q->v[3].x = x + i;
		q->v[3].y = 600;

		q->v[0].col = q->v[1].col = q->v[2].col = q->v[3].col = 0xFED448;

		hge->Gfx_RenderQuad(q);*/

		hgeSprite s(0, i*10, heighmap[i + x] + y*10, 10, 600 - heighmap[i] - y*10);
		s.Render(i*10, 600 - 10*(heighmap[i + x] - y));
	}

	/* 0xFED448 - ground color */

	hge->Gfx_EndScene();

	return false;
}