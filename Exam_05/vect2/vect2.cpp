/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 10:09:27 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/19 14:24:52 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::vect2(int x, int y) : x(0), y(0) {}

vect2::vect2(const vect2 &copy) {}

vect2 &vect2::operator=(const vect2 &assign) {}

vect2::~vect2() {}

int &vect2::operator[](int indx);

