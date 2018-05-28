
#include <wiringPi.h>
#include "Timer.h"

Timer::Timer(void)
{
}

int8_t Timer::every(unsigned long period, void (*callback)())
{
	int8_t i = findFreeEventIndex();
	if (i == -1) return -1;

	_events[i].eventType = EVENT_EVERY;
	_events[i].period = period;
	_events[i].callback = callback;
	_events[i].lastEventTime = millis();
	return i;
}

void Timer::setperiod(unsigned long period,int id)
{

	_events[id].period = period;
	return;
}


// Stop timer by its ID 
void Timer::stop(int8_t id)
{
	if (id >= 0 && id < MAX_NUMBER_OF_EVENTS)
	{
		_events[id].eventType = EVENT_NONE;
	}
}


//update By ID of event kocik add this
void Timer::update_by_ID(int8_t id)
{
	unsigned long now = millis();
	if (_events[id].eventType != EVENT_NONE)
	{
		_events[id].update(now);
	}
}


int8_t Timer::findFreeEventIndex(void)
{
	for (int8_t i = 0; i < MAX_NUMBER_OF_EVENTS; i++)
	{
		if (_events[i].eventType == EVENT_NONE)
		{
			return i;
		}
	}
	return NO_TIMER_AVAILABLE;
}
