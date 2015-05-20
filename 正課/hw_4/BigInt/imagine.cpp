#include "imagine.h"
BigImaginarynumber::BigImaginarynumber() {
	real = "0";
	complex = "0";
}
BigImaginarynumber::BigImaginarynumber(string s1, string s2) {
	real = s1;
	complex = s2;
}
BigImaginarynumber::BigImaginarynumber(int i1, int i2) {
	real = i1;
	complex = i2;
}
BigImaginarynumber & BigImaginarynumber::operator = (BigImaginarynumber & copy) {
	real = copy.real;
	complex = copy.complex;
	return *this;
}
BigImaginarynumber BigImaginarynumber::operator + (BigImaginarynumber & addend) {
	BigImaginarynumber temp(*this);
	temp.real += addend.real;
	temp.complex += addend.complex;
	return temp;
}
BigImaginarynumber & BigImaginarynumber::operator += (BigImaginarynumber addend) {
	real += addend.real;
	complex += addend.complex;
	return *this;
}
BigImaginarynumber BigImaginarynumber::operator - (BigImaginarynumber & addend) {
	BigImaginarynumber temp(*this);
	temp.real -= addend.real;
	temp.complex -= addend.complex;
	return temp;
}
BigImaginarynumber & BigImaginarynumber::operator -= (BigImaginarynumber addend) {
	real -= addend.real;
	complex -= addend.complex;
	return *this;
}
BigImaginarynumber BigImaginarynumber::operator * (BigImaginarynumber & addend) {
	BigImaginarynumber temp(*this);
	temp.real = real*addend.real - complex*addend.complex;
	temp.complex = real*addend.complex + complex*addend.real;
	return temp;
}
BigImaginarynumber & BigImaginarynumber::operator *= (BigImaginarynumber addend) {
	(*this) = (*this)*addend;
	return *this;
}
void BigImaginarynumber::setValue(int a, int b) {
	real = a;
	complex = b;
}
ostream & operator<<(ostream & out, BigImaginarynumber & data) {
	if (data.real != 0)out << data.real;
	if (!data.complex.getSign() && data.real != 0)out << "+";
	if (data.complex != 0)out << data.complex << 'i';
	if (data.real == 0 && data.complex == 0)out << '0';
	return out;
}