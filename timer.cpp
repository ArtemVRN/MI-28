#include "timer.h"
#include <functional>

TimerHost timerHost;

void TimerHost::AddTimer(float seconds, const std::function<void()> func)
{

	Timer* timer =
		first ? (last ? first->next = last = last->next = new Timer : first->next = new Timer())
		:
		first = new Timer();
	/* if list is empty, we take the first element, else
	if number of elements == 1, we take last element, else
	we take new element */

	timer->seconds_left = seconds;
	timer->func = func;
	timer->next = 0;
}

void TimerHost::Update()
{
	float delta = hge->Timer_GetDelta();

	for (Timer* timer = first, * prev = first; timer;) {
		if ((timer->seconds_left -= delta) < 0) {
			timer->func();
			if (timer == first) {
				Timer* tmp = first->next;
				delete timer; // == (delete first)
				timer = first = tmp;
			}
			else {
				prev->next = timer->next;
				delete timer;
				timer = prev;
				prev = timer;
				timer = timer->next;
			}
		}
		else {
			prev = timer;
			timer = timer->next;
		}

	}
}
