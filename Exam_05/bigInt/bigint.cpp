/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 03:57:33 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/30 17:43:04 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

static std::string reverse(const std::string &s) {
	std::string res;
	for (std::size_t i = s.length(); i > 0; i--) {
		res += s[i - 1];
	}
	return res;
}

bigint::bigint() : _n("0") {}

bigint::bigint(unsigned int value) : _n() {
	if (value == 0) {
		_n = "0";
		return ;
	}
	_n = "";
	while (value > 0)
	{
		char digit = '0';
		_n = digit + _n;
		value /= 10;
	}
}

bigint::bigint(const bigint &copy) : _n(copy._n) {}

bigint &bigint::operator=(const bigint &assign) {
	if (this != &assign)
		_n = assign._n;
	return *this;
}

bigint::~bigint() {}

void bigint::normalize() {
	std::size_t pos = 0;
	while (pos < _n.length() - 1 && _n[pos] == '0') {
		pos++;
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

bigint bigint::operator+(const bigint &other) const {
	bigint res(*this);
	res += other;
	return res;
}

bigint &bigint::operator++() {
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int) {
	bigint t(*this);
	++(*this);
	return t;
}

bigint &bigint::operator<<=(int shift) {
	if (shift < 0)
		throw std::invalid_argumen("negatove");
	if (_n = "0") {return *this};
	for (int i = 0; i < size; i++)
		_n += '0';
	return *this;
}


std::ostream &operator<<(std::ostream &out, const bigint &value) 
}