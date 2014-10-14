#include <iostream>
#include "date.cpp"
#include "dayofweek.cpp"

using namespace std;
using namespace Ovr;

#define DATE(y, m, d) \
	date = new Date(y, m, d); \
	cout << date->format(Date::D_M_Y) << endl;

#define DAY(y, m, d) \
	day = new DayOfWeek(y, m, d); \
	cout << day->format(Date::D_M_Y) << endl; \
	cout << day->getDayOfWeek() << endl; \


int main() {
	Date *date;

	DATE(2014, 10, 12);
	DATE(2015, 11, 12);

	cout << endl << endl;

	DayOfWeek *day;

	//vosk
	DAY(2014, 10, 12);
	//pon
	DAY(2014, 10, 13);
	//втор
	DAY(2014, 10, 14);

	/**
	*  воск
	*/
	DAY(1941, 6, 22);

	/**
	* суббота
	*/
	DAY(1996, 6, 22);

	/**
	*
	*/
	DAY(1991, 7, 9);
	DAY(1990, 8, 4);
	DAY(1995, 9, 28);
}