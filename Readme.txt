Project "MI-28"

Files:
	+headers
	|	+engine
	|	|	hge_interface.h
	|	\	timer.h
	|	
	|	+gameplay
	|	\	mapgen.h
	|	
	|	+other
	|	|	global.h
	|	|	resources.h
	\	\	settings.h
	
	+sources
	|	+engine
	|	|	hge_interface.cpp
	|	\	timer.cpp
	|
	|	+gameplay
	|	\	mapgen.cpp
	|
	|	+other
	|	|	global.cpp
	|	|	resources.cpp
	\	\	settings.cpp
	
	+resources
	\	Readme.txt

Summary:
		folder "[headers/sources]engine" is for all functions, that in-game engine provides
			file "hge_interface[.h/.cpp]" is for structuring complete program
			file "timerp[.h/.cpp]" is for providing interface to use timers
		folder "[headers/sources]gameplay" is for creating gameplay
			file "mapgen[.h/.cpp]" is for creating map landscape
		folder "[headers/sources]other" is for common needings
			file "global[.h/.cpp]" is for using global variables and structure in each file (such as settings etc.)
			file "resources[.h/.cpp]" is for structuring all resources in game
			file "sttings[.h/.cpp]" is for crearing setings system (including parsing)

Comments:
	Log:
		~ message about normal work
		! not disasterous error
		!! fatal error