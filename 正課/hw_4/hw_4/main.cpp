#include <iostream>
#include <string.h>
#include "bigint.h"

using namespace std;
void main() {
	Bigint x, y("1234"), z("00000987654321");
	cout << "x y z values: " << x << ' ' << y << ' ' << z << endl;
	Bigint i(44); // Array ¤j¤p 2		 
	Bigint j(i);
	Bigint k(10);
	cout << "i j k values: " << i << ' ' << j << ' ' << k << endl;
	cout << "Total BigInt Object Count: " << Bigint::getCount() << endl;
	x = y = "987654321098765432109876543210987654321098765432109876543210";
	cout << "x y z values: " << x << ' ' << y << ' ' << z << endl;
	y = 10; y *= -88;
	cout << "y values: " << y << endl;
	y = 10;
	y *= i;
	cout << "y values: " << y << endl;
	//y = x / 8;
	cout << "y values: " << y << endl;
	//x /= -8;
	cout << "x values: " << x << endl;
	//x /= i;
	cout << "x values: " << x << endl;
	y = 10; y += (long long)-88;
	cout << "y values: " << y << endl;
	y = 10;
	y += i;

	cout << "y values: " << y << endl;
	i = -88;
	y = 10; y -= i;
	cout << "y values: " << y << endl;
	y = 10; y -= i;
	cout << "y values: " << y << endl;
	x = i + 3 + j * 2 * k;
	cout << "x values: " << x << endl;
	x = i - 3 - j * 2 * k;
	cout << "x values: " << x << endl;
	cout << "k values: " << k++ << ' ' << k << endl;
	k = 10;	x = ++k++;
	cout << "x k values: " << x << ' ' << k << endl;
	//k = 10;	x = --k--;
	cout << "x k values: " << x << ' ' << k << endl;
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
}