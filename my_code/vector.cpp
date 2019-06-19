#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const vector& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

vector::vector() {
	sz = 0;
	capacity = DEF_CAPACITY;
	data = new int[DEF_CAPACITY];
}

/*
 * copy control stuff
**/
vector::vector(const vector& v2) { // copy construstor
	capacity = v2.capacity;
	sz = v2.size();
	data = new int[capacity];
	// copy over existing data;
	for (int i = 0; i < size(); i++) {
		data[i] = v2.data[i];
	}
}

vector::~vector() {
	delete[] data;
}

vector& vector::operator=(const vector& v2) { // assignment opp
	if (&v2 != this) { // making sure it is not a self assignment 
		delete[] data;
		capacity = v2.capacity;
		sz = v2.size();
		data = new int[capacity];
		// copy over existing data;
		for (int i = 0; i < size(); i++) {
			data[i] = v2.data[i];
		}
	}
	return *this;
}

/*
 * Puts an element at the back of a vector.
 * */
void vector::push_back(int val) {
	if (sz == (capacity - 1)) {
		cout << "Increasing capacity\n";
		// get new array of capacity * 2
		capacity *= 2;
		int* temp = new int[capacity];
		// copy over existing data;
		for (int i = 0; i < sz; i++) {
			temp[i] = data[i];
		}
		// delete old array
		delete[] data;
		// set pointer to new array
		data = temp;
	}

	data[sz++] = val;
}

int vector::operator[](int i) const {
	return data[i];
}

int& vector::operator[](int i) {
	return data[i];
}

/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(vector& v1, vector& v2) {
	if (v1.size() != v2.size()) return false;
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != v2[i]) return false;
	}
	return true;
}