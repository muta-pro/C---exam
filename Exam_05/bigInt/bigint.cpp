/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 03:57:33 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/03 19:41:35 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"
//start from the end and copy over on an empty string
//because size_t is unsigned type we start at len and stop at i > 0
static std::string reverse(const std::string &s) {
	std::string res;
	for (std::size_t i = s.length(); i > 0; i--) {
		res += s[i - 1]; //-1 for right indx
	}
	return res;
}

bigint::bigint() : _n("0") {}
// itoa: int to str
//rip raw int apart and build a string _n
bigint::bigint(unsigned int value) : _n() {
	if (value == 0) { //we set manually to 0
		_n = "0";
		return ;
	}
	_n = "";
	while (value > 0)
	{
		char digit = '0' + (value % 10); //isolate last digit + ascii 48
		_n = digit + _n; //this order of adding bc extracting from right-to-left
		value /= 10;//chop off last digit for the next to process
	}
}

bigint::bigint(const bigint &copy) : _n(copy._n) {}

bigint &bigint::operator=(const bigint &assign) {
	if (this != &assign)
		_n = assign._n;
	return *this;
}

bigint::~bigint() {}
//convert string to number
std::size_t bigint::to_size_t() const {
	std::size_t val = 0;
	for (std::size_t i = 0; i < _n.length(); i++) {
		val = val * 10 + (_n[i] - '0');
	}
	return val;
}
//remove leading zeros
void bigint::normalize() {
	std::size_t pos = 0;
	while (pos < _n.length() - 1 && _n[pos] == '0') {
		pos++;//keep at least one digit
	}
	if (pos > 0) {
		_n = _n.substr(pos);
	}
}

int bigint::compare(const bigint &other) const {
	if (_n.length() < other._n.length()) {
		return -1;
	}
	if (_n.length() > other._n.length()) {
		return 1;
	}
	for (std::size_t i = 0; i < _n.length(); i++) {
		if (_n[i] < other._n[i])
			return -1;
		if (_n[i] > other._n[i])
			return 1;
	}
	return 0;
}

//addition
bigint &bigint::operator+=(const bigint &other) {
	std::string a = reverse(_n);
	std::string b = reverse(other._n);
	std::string res = "";
	int carry = 0;
	std::size_t max_len = a.length();

	if (b.length() > max_len) {
		max_len = b.length();
	}
	for (std::size_t i = 0; i < max_len || carry > 0; i++) {
		int digitA = 0;
		if (i < a.length()) {
			digitA = a[i] - '0';
		}
	int digitB = 0;
	if (i < b.length()) {
		digitB = b[i] - '0';
	}
	int sum = digitA + digitB + carry;
	res += char('0' + (sum % 10));
	carry = sum / 10;
	}
	_n = reverse(res);
	normalize();
	return *this;
}


//incr/decr
bigint &bigint::operator++() {
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int) {
	bigint t(*this);
	++(*this);
	return t;
}

//decimal shift
bigint &bigint::operator<<=(const bigint &shift) {
	if (_n == "0") {
		return *this;
	}
	std::size_t s = shift.to_size_t();
	for(std::size_t i = 0; i < s; i++) {
		_n += '0';
	}
	return *this;
}

bigint bigint::operator<<(const bigint &shift) const {
	bigint res(*this);
	res <<= shift;
	return res;
}

bigint &bigint::operator>>=(const bigint &shift) {
	std::size_t s = shift.to_size_t();
	if (s >= _n.length()) {
		_n = "0";
		return *this;
	}
	_n = _n.substr(0, _n.length() - s);
	normalize();
	return *this;
}

bigint bigint::operator>>(const bigint &shift) const {
	bigint res(*this);
	res >>= shift;
	return res;
}

//comparison
bool bigint::operator==(const bigint &other) const {
	return compare(other) == 0;
}

bool bigint::operator!=(const bigint &other) const {
	return compare(other) != 0;
}

bool bigint::operator<(const bigint &other) const {
	return compare(other) < 0;
}

bool bigint::operator>(const bigint &other) const {
	return compare(other) > 0;
}

bool bigint::operator<=(const bigint &other) const {
	return compare(other) <= 0;
}

bool bigint::operator>=(const bigint &other) const {
	return compare(other) >= 0;
}

std::string bigint::getStr() const {
	return _n;
}

std::ostream &operator<<(std::ostream &out, const bigint &value)  {
	out << value.getStr();
	return out;
}

bigint operator+(const bigint &lhs, const bigint &rhs) {
	bigint res(lhs);
	res += rhs;
	return res;
}
