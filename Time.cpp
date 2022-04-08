#include <iostream>
#include "Time.h"

using namespace std;

Time::Time() {
	sec = 0;
	min = 0;
	hour = 0;
}

Time::Time(const Time & src){
	sec = src.sec;
	min = src.min;
	hour = src.hour;
}

Time::~Time() {
	sec = 0;
	min = 0;
	hour = 0;
}

void Time::addHour(int value) {
	hour = hour + value;
}

void Time::addMin(int value) {
	min = min + value;
	while (min >= 60){
		min = min - 60;
		addHour(1);
	}
}

void Time::addSec(int value) {
	sec = sec + value;
	while (sec >= 60) {
		sec = sec - 60;
		addMin(1);
	}
}

void Time::removeHour(int value) {
	if (value >= hour) {
		hour = 0;
		min = 0;
		sec = 0;
	}
	else {
		hour = hour - value;
	} 
}

void Time::removeMin(int value) {
	min = min - value;
	while (min < 0) {
		min = 60 + min;
		removeHour(1);
	}
}

void Time::removeSec(int value) {
	sec = sec - value;
	while (sec < 0) {
		sec = 60 + sec;
		removeMin(1);
	}
}

void Time::clearTime() {
	sec = 0;
	min = 0;
	hour = 0;
}

void Time::print() {
	cout << hour << ":";

	if (min >= 10) cout << min << ":";
	else cout << "0" << min << ":";

	if (sec >= 10) cout << sec;
	else cout << "0" << sec;

}

Time Time::operator + (int r)
{
	this->addSec(r);
	return *this;
}

Time operator - (const Time &t, int r)
{
	Time tmp = t;
	tmp.removeSec(r);
	return tmp;
}

bool operator>(const Time &t1, const Time &t2)
{
	int time1, time2;
	time1 = 3600 * t1.hour + 60 * t1.min + t1.sec;
	time2 = 3600 * t2.hour + 60 * t2.min + t2.sec;
	if (time1 > time2) {
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<(const Time &t1, const Time &t2)
{
	int time1, time2;
	time1 = 3600 * t1.hour + 60 * t1.min + t1.sec;
	time2 = 3600 * t2.hour + 60 * t2.min + t2.sec;
	if (time1 < time2) {
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>=(const Time &t1, const Time &t2)
{
	int time1, time2;
	time1 = 3600 * t1.hour + 60 * t1.min + t1.sec;
	time2 = 3600 * t2.hour + 60 * t2.min + t2.sec;
	if (time1 >= time2) {
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<=(const Time &t1, const Time &t2)
{
	int time1, time2;
	time1 = 3600 * t1.hour + 60 * t1.min + t1.sec;
	time2 = 3600 * t2.hour + 60 * t2.min + t2.sec;
	if (time1 <= time2) {
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Time &t1, const Time &t2)
{
	int time1, time2;
	time1 = 3600 * t1.hour + 60 * t1.min + t1.sec;
	time2 = 3600 * t2.hour + 60 * t2.min + t2.sec;
	if (time1 != time2) {
		return true;
	}
	else
	{
		return false;
	}
}

bool operator==(const Time &t1, const Time &t2)
{
	int time1, time2;
	time1 = 3600 * t1.hour + 60 * t1.min + t1.sec;
	time2 = 3600 * t2.hour + 60 * t2.min + t2.sec;
	if (time1 == time2) {
		return true;
	}
	else
	{
		return false;
	}
}


