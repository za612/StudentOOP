#include <iostream>
#include "tvector.h"

using namespace std;

template<typename T>
void print_vector(const MyVec<T>& v) {
	for (T i : v) cout << i << " ";
	cout << endl;
}

template<typename T>
MyVec<T>::MyVec() : sz(0) {
	capacity = DEF_CAPACITY;
	data = new T[DEF_CAPACITY];
}

template<typename T>
MyVec<T>::MyVec(int sz, T val) : sz{ sz } {
	capacity = sz * 2;
	data = new T[capacity];
	for (int i = 0; i < sz; i++) {
		data[i] = val;
	}
}

template<typename T>
MyVec<T>::MyVec(const MyVec& v2) {
	copy(v2);
}

template<typename T>
MyVec<T>::~MyVec() {
	delete[] data;
}

template<typename T>
MyVec<T>& MyVec<T>::operator=(const MyVec& v2) {
	if (this != &v2) {
		delete[] data;
		copy(v2);
	}
	return *this;
}

template<typename T>
MyVec<T>::Iterator<T> MyVec<T>::begin() const {
	return Iterator(data);
}

template<typename T>
MyVec<T>::Iterator<T> MyVec<T>::end() const {
	return Iterator(data + sz);
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
template<typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2) { // use iterator
	if (v1.size() != v2.size()) return false;
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != v2[i]) return false;
	}
	return true;
}

/*
 * Puts an element at the back of a vector.
 * */
template<typename T>
void MyVec<T>::push_back(T val) {
	sz++;
	if (sz > capacity) {
		cout << "Increasing capacity\n";
		int* old_data = data;
		data = new T[capacity * CAPACITY_MULT];
		for (int i = 0; i < sz; i++) {
			data[i] = old_data[i];
		}
		capacity *= CAPACITY_MULT;
		delete[] old_data;
	}
	data[sz - 1] = val;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
template<typename T>
T MyVec<T>::operator[](int i) const {
	return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
template<typename T>
T& MyVec<T>::operator[](int i) {
	return data[i];
}

template<typename T>
void MyVec<T>::copy(const MyVec& v2) {
	sz = v2.sz;
	capacity = v2.capacity;
	data = new T[capacity];
	for (int i = 0; i < sz; i++) {
		data[i] = v2.data[i];
	}
}
