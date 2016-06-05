#pragma once

#include "hge_interface.h"
#include "global.h"

DWORD color = 0;

bool RenderFunc() {
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0xB0E5FA);	// sky color

	int det = settings->land_detalization;

	/* 0xFED448 - ground color */

	hge->Gfx_EndScene();

	return false;
}