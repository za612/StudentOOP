#include <iostream>
#include <istream>
#include <iomanip>
//#include <cmath> // travis wants this
#include "complex.h"

using namespace std;

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

bool operator==(const Complex& c1, const Complex& c2) {
    return ((abs(c1.get_real() - c2.get_real())<0.001) && (abs(c1.get_imag() == c2.get_imag())<0.001));
    //return (((c1.get_real() - c2.get_real())<0.001) && ((c1.get_imag() == c2.get_imag())<0.001));
}

bool operator!=(const Complex& c1, const Complex& c2) {
    return !(c1 == c2);
}


ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
    os << setprecision(10) << c.real << showpos
        << c.imag << "i" << noshowpos << endl;
    return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>>(istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}

Complex::operator bool() const {
    if (real != 0.0 || imag != 0.0) {
        return true;
    }
    else {
        return false;
    }
}

Complex& Complex::operator++() {
    ++real;
    return *this;
}

Complex Complex::operator++(int dummy) {
    Complex temp = *this;
    real++;
    return temp;
}

Complex operator+(const Complex& c1, const Complex& c2){
    Complex temp(c1.get_real() + c2.get_real(), c1.get_imag() + c2.get_imag());
    return temp;
}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

Complex Complex::operator*(const int i) {
    Complex temp(real * 2, imag * 2);
    return temp;
}

Complex operator-(const Complex& c1, const Complex& c2){
    Complex temp(c1.get_real() - c2.get_real(), c1.get_imag() - c2.get_imag());
    return temp;
}

Complex Complex::operator--(int dummy) {
    Complex temp = *this;
    real--;
    return temp;
}

Complex& Complex::operator--() {
    --real;
    return *this;
}

Complex Complex::operator-=(const Complex& c) {
    real -= c.get_real();
    imag -= c.get_imag();
    return *this;
}