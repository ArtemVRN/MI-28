#pragma once

#include "hge_interface.h"

DWORD color = 0;

bool RenderFunc() {
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0xFFFFFFFF);
	hge->Gfx_EndScene();

	return false;
}