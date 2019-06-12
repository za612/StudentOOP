#include <iostream>
#include <vector>
#include <string>
#include "weather.h"

using namespace std;

const double C_TO_F = 9.0 / 5.0;

/*
 * Image class:
*/

Image::Image(int w, int h, string flnm) : width(w), height(h){
	filename = flnm;
	image_buf = new char[image_sz()];
}

	// copy constructor
Image::Image(const Image& img2) {
	copy_fields(img2);
}

// destructor
Image::~Image() {
	if (image_buf != nullptr) {
		delete image_buf;
	}
}

// assignment operator:
Image& Image::operator=(const Image& img2) {
	if (&img2 != this) {
		if (image_buf != nullptr) {
			delete image_buf;
		}
		copy_fields(img2);
	}
	return *this;
}

int Image::image_sz() {
	return width * height;
}

void Image::copy_fields(const Image& img2) {
	width = img2.width;
	height = img2.height;
	image_buf = new char[image_sz()];
	for (int i = 0; i < image_sz(); i++) {
		image_buf[i] = img2.image_buf[i];
	}
}

/*
	* Setting `display() = 0` here makes this an abstract
	* class that can't be implemented.
	* */
string Image::display(string s) {
	return "Displaying image " + s;
}

/*
 * WReading class:
*/

ostream& operator<<(ostream& os, const WReading& wr) {
	os << wr.date << "; temp: " << wr.temperature << "; humid: "
		<< wr.humidity << "; wind: " << wr.windspeed;
	return os;
}

WReading::WReading(Date dt, double temp, double hum, double ws)
	: date(dt), temperature(temp), humidity(hum), windspeed(ws) {} // can have this just in header

double WReading::get_tempF() const{
	return (temperature * C_TO_F + 32.0);
}


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