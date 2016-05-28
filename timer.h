#pragma once

#include "hge_interface.h"
#include <functional>

class TimerHost {
	struct Timer {
		float seconds_left;
		std::function<void()> func;
		Timer* next;
	} * first = 0, * last = 0;

public:
	void AddTimer(float seconds, const std::function<void()> func);

	void Update();
};

extern TimerHost timerHost;
