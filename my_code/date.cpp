#include <iostream>
#include "date.h"

using namespace std;

Date::Date(int d, int m, int y) {
	if ((d < 1) || (d > 31)) throw(d);
	if ((m < 1) || (m > 12)) throw(m);
	if ((y < 1800) || (y > 2200)) throw(y);

	day = d;
	month = m;
	year = y;
}

ostream& operator<<(ostream& os, const Date& date) {
	os << date.month << "/" << date.day << "/" << date.year;
	return os;
}
