
#include "settings.h"

#include <stdio.h>
#include <cctype>
#include <string>

Settings * load_settings(const char * file_name)
{
	FILE* file = fopen(file_name, "rt");
	
	if (!file)
		return 0;

	Settings* ret = new Settings;
	char buf[32];

	do
	{ 
		char c;
		for (int i = 0; c = getc(file), buf[i] = isalpha(c) ? c : '\0'; i++)
			;

		if (!strcmp(buf, "land_detalization")) {
			fscanf(file, "%d", &ret->land_detalization);
		}
		else if (!strcmp(buf, "enemies")) {
			fscanf(file, "%d", &ret->enemies);
		}
		else if (!strcmp(buf, "maplen")) {
			fscanf(file, "%d", &ret->maplen);
		}
		else if (!strcmp(buf, "startheight")) {
			fscanf(file, "%d", &ret->startheight);
		}

	} while (!feof(file));

	return ret;
}
