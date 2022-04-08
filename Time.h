#pragma once
class Time
{
	friend Time operator -(const Time &, int);			//list - int

	friend bool operator>(const Time&, const Time&);
	friend bool operator<(const Time&, const Time&);
	friend bool operator>=(const Time&, const Time&);
	friend bool operator<=(const Time&, const Time&);
	friend bool operator!=(const Time&, const Time&);
	friend bool operator==(const Time&, const Time&);

private:
	int sec, min, hour;

	void addHour(int);
	void addMin(int);
	void addSec(int);
	void removeHour(int);
	void removeMin(int);
	void removeSec(int);

public:
	explicit Time();
	Time(const Time &);
	~Time();

	void clearTime();			//очистка
	void print();				//вывод

	Time operator +(int);		//list + int
	
};