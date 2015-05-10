#include <malloc.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include "bigint.h"

using namespace std;

//------------------------------------------------------------------------------
void BigInt::checkzero(){
	int check = 0, i;
	if (number[0]=='-')i = 1;
	else i = 0;
	for (; i < number.length(); i++){
		if ((number[i] - '0') && !check){
			check = 1; break;
		}
		else continue;
	}
	if(check)setNumber(number.substr(i));
}
BigInt::BigInt() { // empty constructor initializes zero
	number = "0";
	sign = false;
	count++;
}

BigInt::BigInt(string s) { // "string" constructor
	if (isdigit(s[0])) { // if not signed
		setNumber(s);
		sign = false; // +ve
	}
	else {
		setNumber(s.substr(1));
		sign = (s[0] == '-');
	}
	checkzero();
	count++;
}

BigInt::BigInt(string s, bool sin) { // "string" constructor
	setNumber(s);
	setSign(sin);
	count++;
}

BigInt::BigInt(int n) { // "int" constructor
	stringstream ss;
	string s;
	ss << n;
	ss >> s;


	if (isdigit(s[0])) { // if not signed
		setNumber(s);
		setSign(false); // +ve
	}
	else {
		setNumber(s.substr(1));
		setSign(s[0] == '-');
	}
	count++;
}
BigInt::BigInt(int s, int size){
	int num = s, i, j;
	if (s < 0)sign = 1;
	else sign = 0;
	for (i = 0; num > 0; i++){
		num /= 10;
	}
	if (i > size)num = size;
	else num = i;
	j = pow(10, num);
	s %= j;
	char *copy = new char[num];
	copy[num] = '\0';
	for (i = 0; i < num; i++){
		copy[i] = (s % 10) + '0';
		s /= 10;
	}
	setNumber(copy);
	count++;
}
BigInt::BigInt(BigInt & copy){
	sign = copy.sign;
	number = copy.number;
	count++;
}
BigInt::~BigInt(){
	--count;
}
void BigInt::setNumber(string s) {
	number = s;
}

const string& BigInt::getNumber() { // retrieves the number
	return number;
}

void BigInt::setSign(bool s) {
	sign = s;
}

const bool& BigInt::getSign() {
	return sign;
}

BigInt BigInt::absolute() {
	return BigInt(getNumber()); // +ve by default
}
BigInt & BigInt::operator = (string s) {
	if (isdigit(s[0])) { // if not signed
		setNumber(s);
		sign = false; // +ve
	}
	else {
		setNumber(s.substr(1));
		sign = (s[0] == '-');
	}
	checkzero();
	return *this;
}

BigInt & BigInt::operator = (BigInt b) {
	setNumber(b.getNumber());
	setSign(b.getSign());
	return *this;
}

bool BigInt::operator == (BigInt b) {
	return equals((*this), b);
}

bool BigInt::operator != (BigInt b) {
	return !equals((*this), b);
}

bool BigInt::operator > (BigInt b) {
	return greater((*this), b);
}

bool BigInt::operator < (BigInt b) {
	return less((*this), b);
}

bool BigInt::operator >= (BigInt b) {
	return equals((*this), b)
		|| greater((*this), b);
}

bool BigInt::operator <= (BigInt b) {
	return equals((*this), b)
		|| less((*this), b);
}

BigInt& BigInt::operator ++() { // prefix
	(*this) = (*this) + 1;
	return (*this);
}

BigInt BigInt::operator ++(int) { // postfix
	BigInt before = (*this);

	(*this) = (*this) + 1;

	return before;
}

BigInt& BigInt::operator --() { // prefix
	(*this) = (*this) - 1;
	return (*this);

}

BigInt BigInt::operator --(int) { // postfix
	BigInt before = (*this);

	(*this) = (*this) - 1;

	return before;
}

BigInt BigInt::operator + (BigInt b) {
	BigInt addition;
	if (getSign() == b.getSign()) { // both +ve or -ve
		addition.setNumber(add(getNumber(), b.getNumber()));
		addition.setSign(getSign());
	}
	else { // sign different
		if (absolute() > b.absolute()) {
			addition.setNumber(subtract(getNumber(), b.getNumber()));
			addition.setSign(getSign());
		}
		else {
			addition.setNumber(subtract(b.getNumber(), getNumber()));
			addition.setSign(b.getSign());
		}
	}
	if (addition.getNumber() == "0") // avoid (-0) problem
		addition.setSign(false);

	return addition;
}

BigInt BigInt::operator - (BigInt b) {
	b.setSign(!b.getSign()); // x - y = x + (-y)
	return (*this) + b;
}

BigInt BigInt::operator * (BigInt b) {
	BigInt mul;

	mul.setNumber(multiply(getNumber(), b.getNumber()));
	mul.setSign(getSign() != b.getSign());

	if (mul.getNumber() == "0") // avoid (-0) problem
		mul.setSign(false);

	return mul;
}

// Warning: Denomerator must be within "long long" size not "BigInt"
BigInt BigInt::operator / (BigInt b) {
	long long den = toInt(b.getNumber());
	BigInt div;

	div.setNumber(divide(getNumber(), den).first);
	div.setSign(getSign() != b.getSign());

	if (div.getNumber() == "0") // avoid (-0) problem
		div.setSign(false);

	return div;
}

// Warning: Denomerator must be within "long long" size not "BigInt"
BigInt BigInt::operator % (BigInt b) {
	long long den = toInt(b.getNumber());

	BigInt rem;
	long long rem_int = divide(number, den).second;
	rem.setNumber(toString(rem_int));
	rem.setSign(getSign() != b.getSign());

	if (rem.getNumber() == "0") // avoid (-0) problem
		rem.setSign(false);

	return rem;
}

BigInt& BigInt::operator += (BigInt b) {
	(*this) = (*this) + b;
	return (*this);
}

BigInt& BigInt::operator -= (BigInt b) {
	(*this) = (*this) - b;
	return (*this);
}

BigInt& BigInt::operator *= (BigInt b) {
	(*this) = (*this) * b;
	return (*this);
}

BigInt& BigInt::operator /= (BigInt b) {
	(*this) = (*this) / b;
	return (*this);
}

BigInt& BigInt::operator %= (BigInt b) {
	(*this) = (*this) % b;
	return (*this);
}

BigInt& BigInt::operator [] (int n) {
	return *(this + (n*sizeof(BigInt)));
}

BigInt BigInt::operator -() { // unary minus sign
	return (*this) * -1;
}

BigInt::operator string() { // for conversion from BigInt to string
	string signedString = (getSign()) ? "-" : ""; // if +ve, don't print + sign
	signedString += number;
	return signedString;
}

bool BigInt::equals(BigInt n1, BigInt n2) {
	return n1.getNumber() == n2.getNumber()
		&& n1.getSign() == n2.getSign();
}

bool BigInt::less(BigInt n1, BigInt n2) {
	bool sign1 = n1.getSign();
	bool sign2 = n2.getSign();

	if (sign1 && !sign2) // if n1 is -ve and n2 is +ve
		return true;

	else if (!sign1 && sign2)
		return false;

	else if (!sign1) { // both +ve
		if (n1.getNumber().length() < n2.getNumber().length())
			return true;
		if (n1.getNumber().length() > n2.getNumber().length())
			return false;
		return n1.getNumber() < n2.getNumber();
	}
	else { // both -ve
		if (n1.getNumber().length() > n2.getNumber().length())
			return true;
		if (n1.getNumber().length() < n2.getNumber().length())
			return false;
		return n1.getNumber().compare(n2.getNumber()) > 0; // greater with -ve sign is LESS
	}
}

bool BigInt::greater(BigInt n1, BigInt n2) {
	return !equals(n1, n2) && !less(n1, n2);
}

string BigInt::add(string number1, string number2) {
	string add = (number1.length() > number2.length()) ? number1 : number2;
	char carry = '0';
	int differenceInLength = abs((int)(number1.size() - number2.size()));

	if (number1.size() > number2.size())
		number2.insert(0, differenceInLength, '0'); // put zeros from left

	else// if(number1.size() < number2.size())
		number1.insert(0, differenceInLength, '0');

	for (int i = number1.size() - 1; i >= 0; --i) {
		add[i] = ((carry - '0') + (number1[i] - '0') + (number2[i] - '0')) + '0';

		if (i != 0) {
			if (add[i] > '9') {
				add[i] -= 10;
				carry = '1';
			}
			else
				carry = '0';
		}
	}
	if (add[0] > '9') {
		add[0] -= 10;
		add.insert(0, 1, '1');
	}
	return add;
}

string BigInt::subtract(string number1, string number2) {
	string sub = (number1.length()>number2.length()) ? number1 : number2;
	int differenceInLength = abs((int)(number1.size() - number2.size()));

	if (number1.size() > number2.size())
		number2.insert(0, differenceInLength, '0');

	else
		number1.insert(0, differenceInLength, '0');

	for (int i = number1.length() - 1; i >= 0; --i) {
		if (number1[i] < number2[i]) {
			number1[i] += 10;
			number1[i - 1]--;
		}
		sub[i] = ((number1[i] - '0') - (number2[i] - '0')) + '0';
	}

	while (sub[0] == '0' && sub.length() != 1) // erase leading zeros
		sub.erase(0, 1);

	return sub;
}

string BigInt::multiply(string n1, string n2) {
	if (n1.length() > n2.length())
		n1.swap(n2);

	string res = "0";
	for (int i = n1.length() - 1; i >= 0; --i) {
		string temp = n2;
		int currentDigit = n1[i] - '0';
		int carry = 0;

		for (int j = temp.length() - 1; j >= 0; --j) {
			temp[j] = ((temp[j] - '0') * currentDigit) + carry;

			if (temp[j] > 9) {
				carry = (temp[j] / 10);
				temp[j] -= (carry * 10);
			}
			else
				carry = 0;

			temp[j] += '0'; // back to string mood
		}

		if (carry > 0)
			temp.insert(0, 1, (carry + '0'));

		temp.append((n1.length() - i - 1), '0'); // as like mult by 10, 100, 1000, 10000 and so on

		res = add(res, temp); // O(n)
	}

	while (res[0] == '0' && res.length() != 1) // erase leading zeros
		res.erase(0, 1);

	return res;
}

pair<string, long long> BigInt::divide(string n, long long den) {
	long long rem = 0;
	string result;
	result.resize(MAX);

	for (int indx = 0, len = n.length(); indx<len; ++indx) {
		rem = (rem * 10) + (n[indx] - '0');
		result[indx] = rem / den + '0';
		rem %= den;
	}
	result.resize(n.length());

	while (result[0] == '0' && result.length() != 1)
		result.erase(0, 1);

	if (result.length() == 0)
		result = "0";

	return make_pair(result, rem);
}

string BigInt::toString(long long n) {
	stringstream ss;
	string temp;

	ss << n;
	ss >> temp;

	return temp;
}

long long BigInt::toInt(string s) {
	long long sum = 0;

	for (int i = 0; i<s.length(); i++)
		sum = (sum * 10) + (s[i] - '0');

	return sum;
}
ostream & operator<<(ostream & output, BigInt & a){
	string temp;
	temp = a.getNumber();
	if (a.getSign())output << '-';
	output << temp;
	return output;
}
int BigInt::count = 0;
int BigInt::getCount(){
	return count;
}
void main() {
	BigInt x, y("1234"), z("-00000987654321");

	cout << "x y z values: " << x << ' ' << y << ' ' << z << endl;



	BigInt i(44, 2); // Array ¤j¤p 2		 

	BigInt j(i);

	BigInt k(10);

	cout << "i j k values: " << i << ' ' << j << ' ' << k << endl;



	cout << "Total BigInt Object Count: " << BigInt::getCount() << endl;



	x = y = "987654321098765432109876543210987654321098765432109876543210";

	cout << "x y z values: " << x << ' ' << y << ' ' << z << endl;

	y = 246; y *= -897;		cout << "y values: " << y << endl;

	y = 10; y *= i;	 		cout << "y values: " << y << endl;

	y = x / 8;		cout << "y values: " << y << endl;

	x /= -8;			cout << "x values: " << x << endl;

	x /= i;	 			cout << "x values: " << x << endl;

	y = 10; y += -88;		cout << "y values: " << y << endl;

	y = 10; y += i;	 		cout << "y values: " << y << endl;

	y = 10; y -= -88;		cout << "y values: " << y << endl;

	y = 10; y -= i;	 		cout << "y values: " << y << endl;



	x = i + 3 + j * 2 * k;		cout << "x values: " << x << endl;

	x = i - 3 - j * 2 * k;		cout << "x values: " << x << endl;



	cout << "k values: " << k++ << ' ' << k << endl;



	k = 10;	x = ++k++; 		cout << "x k values: " << x << ' ' << k << endl;

	k = 10;	x = --k--; 		cout << "x k values: " << x << ' ' << k << endl;



	x = y = "987654321098765432109876543210";

	cout << "x y z values: " << x << ' ' << y << ' ' << z << endl;

	if (x == y)
		cout << "x == y" << endl;
	else
		cout << "x != y" << endl;
	if (x != z)
		cout << "x != z" << endl;
	else
		cout << "x == z" << endl;
	return;
}