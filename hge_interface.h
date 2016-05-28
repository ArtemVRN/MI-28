#pragma once

#include <hge/hge.h>
#include <hge/hgesprite.h>
#include <hge/hgefont.h>
#include <hge/hgeparticle.h>



extern HGE* hge; // HGE interface

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);

/* Define it by yourself :) */
bool FrameFunc();

/* Draw only here */
bool RenderFunc();

/* Initialization is in your hands */
bool Initialize();

/* Kill all of them!!! MWAHAHAHAHAHAHAHAHAHAHA! */
void Clean();