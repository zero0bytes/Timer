
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "Timer.h" 


void Timer::every(unsigned long period, void (*callback)(),bool start)
{
	this->period = period;
	this->callback = callback;
	this->lastEventTime = clock() / 1000;
	this->is_working = start;
return;
}

void Timer::setperiod(unsigned long period)
{
	this->period = period;
return;
}

void Timer::stop()
{
	this->is_working = false;
return;	
}

void Timer::start()
{
	this->is_working = true;
return;	
}

void Timer::update()
{
	if(this->is_working == true)
	{
		this->now = clock() / 1000;
		if (this->now - this->lastEventTime >= this->period)
		{
			// printf("period: %ld millis\n", this->period);  // uncomment for test!!
			// printf("Time: %ld millis\n", this->now - this->lastEventTime); // uncomment for test!!
			(*callback)();
			this->lastEventTime = this->now;
		}
    }
}

