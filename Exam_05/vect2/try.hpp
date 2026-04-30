/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:51:05 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/28 20:26:52 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <ostream>

class vect2 {
public:
	vect2();
	vect2(int x, int y);
	vect2(const vect2 &copy);
	vect2 &operator=(const vect2 &assign);
	~vect2();

	int &operator[](int indx);
	const int &operator[](int indx) const;

	vect2 &operator+=(const vect2 &other);
	vect2 &operator-=(const vect2 &other);
	vect2 &operator*=(int scalar);

	vect2 &operator++();
	vect2 operator++(int);
	vect2 &operator--();
	vect2 operator--(int);

	vect2 operator-() const;
private:
	int _v[2];
};

std::ostream &operator<<(std::ostream &out, const vect2 &v);

vect2 operator+(const vect2 &lhs, const vect2 &rhs);
vect2 operator-(const vect2 &lhs, const vect2 &rhs);
vect2 operator*(int scalar, const vect2 &v);
vect2 operator*(const vect2 &v, int scalar);

bool operator==(const vect2 &lhs, const vect2 &rhs);
bool operator!=(const vect2 &lhs, const vect2 &rhs); 

#endif