
#include "resources.h"
#include "global.h"

inline void err_load(char* wrong_file);

/* checks if file is loaded, reports and loads resource */
#define LOAD(file, category)	\
	tex = hge ## ->Texture_Load("Resources/" #file ".png");				\
	if (!tex) {					\
	hge ## ->System_Log("!! cannot load resource file %s", #file ".png");	\
	return true;				\
} res. ## category ## . ## file = new hgeSprite(tex, 0, 0, 0, 0)
/****************************/

/* loads resources */
bool load_res()
{
	
	/*----------loading sprites----------*/

	HTEXTURE tex; // buffer

	LOAD(ground, sprites);
	LOAD(helly, sprites);

	return false;
}

inline void err_load(char* wrong_file) {
	
}