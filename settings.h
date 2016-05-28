#pragma once


struct Settings {
	
	int land_detalization = 4;	// 1/2/4
	int enemies = 10;
	int maplen = 1000;
	int startheight = 100;
	
	/*
	TODO: Add settings to change in file 'n use in code
	*/
};

Settings* load_settings(const char* file_name);