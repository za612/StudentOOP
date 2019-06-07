#include <iostream>
#include <vector>
#include <string>
#include "weather.h"

using namespace std;

/*
 * WReading class:
*/

ostream& operator<<(ostream& os, const WReading& wr) {
	os << wr.date << "; temp: " << wr.temperature << "; humid: "
		<< wr.humidity << "; wind: " << wr.windspeed;
	return os;
}

WReading::WReading(Date dt, double temp, double hum, double ws)
	: date(dt), temperature(temp), humidity(hum), windspeed(ws) {}




ostream& operator<<(ostream& os, const GPS& gps) {
	os << "latitude: " << gps.latitude << "; longitude: " << gps.longitude;
	return os;
}

/*
 * A constructor for weather class.
 * */
Weather::Weather(string nm, GPS loc) :
	station_nm(nm), my_loc(loc) {
}


string Weather::get_name() const {
	return station_nm;
}

int Weather::get_rating() const {
	return rating;
}

void Weather::set_rating(int new_rating) {
	rating = new_rating;
}

void Weather::add_reading(WReading wr) {
	wreadings.push_back(wr);
}

ostream& operator<<(ostream& os, const Weather& w) {
	os << w.get_name() << ": rating: " << w.get_rating() << "; " << w.my_loc << endl;
	for (WReading wr : w.wreadings) {
		os << "    " << wr << endl;
	}
	return os;
}