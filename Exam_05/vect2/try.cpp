/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:47:22 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/28 18:30:34 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "try.hpp"

vect2::vect2() {
	_v[0] = 0;
	_v[1] = 0;
}

vect2::vect2(int x, int y) {
	_v[0] = x;
	_v[1] = y;
}

vect2::vect2(const vect2 &copy) {
	_v[0] = copy._v[0];
	_v[1] = copy._v[1];
}

vect2 &vect2::operator=(const vect2 &assign) {
	if (this != &assign) {
		_v[0] = assign._v[0];
		_v[1] = assign._v[1];
	}
	return *this;
}

vect2::~vect2() {}

int &vect2::operator[](int indx) {
	return _v[indx];
}

const int &vect2::operator[](int indx) const {
	return _v[indx];
}

vect2 &vect2::operator+=(const vect2 &other) {
	_v[0] += other._v[0];
	_v[1] += other._v[1];
	return *this;
}

vect2 &vect2::operator-=(const vect2 &other) {
	_v[0] -= other._v[0];
	_v[1] -= other._v[1];
	return *this;
}

vect2 &vect2::operator*=(int scalar) {
	_v[0] *= scalar;
	_v[1] *= scalar;
	return *this;
}

vect2 &vect2::operator++() {
	_v[0]++;
	_v[1]++;
	return *this;
}

vect2 vect2::operator++(int) {
	vect2 t(*this);
	++(*this);
	return t;
}

vect2 &vect2::operator--() {
	_v[0]++;
	_v[1]++;
	return *this;
}

vect2 vect2::operator--(int) {
	vect2 t(*this);
	--(*this);
	return t;
}

vect2 vect2::operator-() const {
	return vect2(-_v[0], -_v[1]);
}


