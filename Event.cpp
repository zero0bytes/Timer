
#include <wiringPi.h>
#include "Event.h"

Event::Event(void)
{
	eventType = EVENT_NONE;
}

void Event::update(void)
{
    unsigned long now = millis();
    update(now);
}

void Event::update(unsigned long now)
{
	if (now - lastEventTime >= period)
	{
		(*callback)();
		lastEventTime = now;
	}
}
