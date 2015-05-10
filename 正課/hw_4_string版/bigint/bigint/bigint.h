#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;
#ifndef BIGINT_H
#define BIGINT_H
#define MAX 10000 // for strings

using namespace std;
class BigInt {
private:
	string number;
	bool sign;
public:
	friend ostream & operator<<(ostream &, BigInt &);
	BigInt(); // empty constructor initializes zero
	BigInt(string s); // "string" constructor
	BigInt(string s, bool sin); // "string" constructor
	BigInt(int s,int size);
	BigInt(int n); // "int" constructor
	BigInt(BigInt & copy);
	~BigInt();
	void checkzero();
	void setNumber(string s);
	const string& getNumber(); // retrieves the number
	void setSign(bool s);
	const bool& getSign();
	BigInt absolute(); // returns the absolute value
	BigInt & operator = (BigInt);
	BigInt & operator = (string);
	bool operator == (BigInt);
	bool operator != (BigInt);
	bool operator > (BigInt);
	bool operator < (BigInt);
	bool operator >= (BigInt);
	bool operator <= (BigInt);
	BigInt& operator ++(); // prefix
	BigInt  operator ++(int); // postfix
	BigInt& operator --(); // prefix
	BigInt  operator --(int); // postfix
	BigInt operator + (BigInt);
	BigInt operator - (BigInt);
	BigInt operator * (BigInt);
	BigInt operator / (BigInt);
	BigInt operator % (BigInt);
	BigInt& operator += (BigInt);
	BigInt& operator -= (BigInt);
	BigInt& operator *= (BigInt);
	BigInt& operator /= (BigInt);
	BigInt& operator %= (BigInt);
	BigInt& operator [] (int);
	BigInt operator -(); // unary minus sign
	operator string(); // for conversion from BigInt to string
	static int getCount();
	
private:
	bool equals(BigInt n1, BigInt n2);
	bool less(BigInt n1, BigInt n2);
	bool greater(BigInt n1, BigInt n2);
	string add(string number1, string number2);
	string subtract(string number1, string number2);
	string multiply(string n1, string n2);
	pair<string, long long> divide(string n, long long den);
	string toString(long long n);
	long long toInt(string s);
	static int count;
};



#endif