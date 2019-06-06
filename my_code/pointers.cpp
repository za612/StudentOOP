#include <iostream>
#include "pointers.h"

using namespace std;

/*
 * Increment n.
 * */
void inc_by_value(int n) {
	++n;
}


/*
 * Increment n.
 * */
void inc_with_pointer(int* iptr) {
	++*iptr;
}


/*
 * Increment n.
 * */
void inc_with_reference(int& n) {
	++n;
}


/*
 * Create an array of n things, each one with its val set to
 * its index in the Thing array.
 * */
Thing** create_array_of_things(int n) {	
	Thing ** things = new Thing*[n];
	for (int i = 0; i < n; i++) {
		things[i] = new Thing(i);
	}
	return things;
}

/*
 * Print all of the things created in the function above.
 * */
void print_all_things(Thing** things, int n) {
	for (int i = 0; i < n; i++) {
		cout << things[i]->val << " ";
	}
	cout << endl;
}

/*
 * Double the value of each thing (use *=).
 * */
void double_all_things(Thing** things, int n) {
	for (int i = 0; i < n; i++) {
		things[i]->val *= 2;
	}
}


/*
 * Delete all of the things, and the Thing array, that you have created.
 * */
void delete_all_things(Thing** things, int n) {
	for (int i = 0; i < n; i++) {
		delete[] things[i];
	}
	delete[] things;
}


/*
 * Assign student `s` the TA `ta`.
 * */
void assignTA(Student* s, Student* ta) {
	s->ta = ta;
}


/*
 * Print who has which TA.
 * */
void printTAs(vector<Student*>& students) {
	for (size_t i = 0; i < students.size(); ++i) {
		cout << "Student: " << students[i]->name << ", TA: ";
		if (students[i]->ta != nullptr) {
			cout << students[i]->ta->name << endl;
		}
		else {
			cout << "none\n";
		}
	}
}
