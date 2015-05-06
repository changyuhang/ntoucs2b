#ifndef BIGINT_H_
#define BIGINT_H_

#include <vector>
#include <iostream>
#include <map>

namespace Bigint {
	class Bigint {
	private:
	public:
		std::vector<int> number;
		bool positive;
		int base;
		unsigned int skip;

	public:
		//Magic methods
		Bigint();
		Bigint(long long);
		Bigint(char*);

		//Adding
		Bigint operator++();
		Bigint operator++(int);
		Bigint operator+(Bigint const &b) const;
		Bigint& operator+=(Bigint const &b);
		Bigint operator+(long long const &b) const;
		Bigint& operator+=(long long b);

		//Subtraction
		Bigint operator-(Bigint const &b) const;
		Bigint& operator-=(Bigint const &b);

		//Multiplication
		Bigint operator*(Bigint const &b);
		Bigint& operator*=(Bigint const &b);
		Bigint operator*(long long const &b);
		Bigint& operator*=(int const &b);

		//Compare
		bool operator<(const Bigint &a) const;
		bool operator>(const Bigint &a) const;
		bool operator<=(const Bigint &a) const;
		bool operator>=(const Bigint &a) const;
		bool operator==(const Bigint &a) const;

		//Allocation
		Bigint operator=(const long long &a);
		Bigint operator=(const Bigint &b);

		//Access
		int operator[](int const &b);
		//Input&Output
		friend std::istream &operator>>(std::istream &in, Bigint &a);
		friend std::ostream &operator<<(std::ostream &out, Bigint a);

		//Helpers
		void clear();
		Bigint& abs();

		//Power
		Bigint& pow(int const &power);
		//Trivia
		int digits() const;
		int trailing_zeros() const;
	private:
		int segment_length(int segment) const;
		Bigint pow(int const &power, std::map<int, Bigint> &lookup);
		int compare(Bigint const &b) const; //0 a == b, -1 a < b, 1 a > b
	};
	Bigint abs(Bigint value);
	std::string to_string(Bigint value);
	Bigint factorial(int n);
}

#endif