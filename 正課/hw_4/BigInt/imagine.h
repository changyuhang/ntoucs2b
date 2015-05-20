#include"bigint.h"
class BigImaginarynumber{
	BigInt real;
	BigInt complex;
public:
	BigImaginarynumber();
	BigImaginarynumber(string, string);
	BigImaginarynumber(int, int);
	BigImaginarynumber & operator = (BigImaginarynumber &);
	BigImaginarynumber  operator + (BigImaginarynumber &);
	BigImaginarynumber  operator - (BigImaginarynumber &);
	BigImaginarynumber & operator += (BigImaginarynumber);
	BigImaginarynumber & operator -= (BigImaginarynumber);
	BigImaginarynumber & operator *= (BigImaginarynumber);
	BigImaginarynumber  operator * (BigImaginarynumber &);
	void setValue(int, int);
	friend ostream & operator<<(ostream &, BigImaginarynumber &);
};