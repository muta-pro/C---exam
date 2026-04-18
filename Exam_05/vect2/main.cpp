/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 22:01:16 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/18 23:17:31 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
obj - (x, y) -> class = value
small operator-overloading lab
turning a user-defined type into a usable value type
value - manipulation using operators
syntax to express oprations
additoin
subtraction
scalar multiplication
unary minus
*/
#include "vect2.hpp"
#include <iostream>

int main()
{
	//obj construction
	vect2 v2;
	vect2 v2(1, 2);
	const vect2 v3(v2);
	//value semantics: vector as value not other - copy of indip obj/same content
	vect2 v4 = v2;

	std::cout << "v1:" << v1 << std::endl;
	std::cout << "v1:" << "{" << v1[0] << ", " << v[1] << "}" << std::endl;
	std::cout << "v2:" << v2 << std::endl;
	std::cout << "v3:" << v3 << std::endl;
	std::cout << "v4:" << v4 << std::endl;
	//operator overlad - write specific fucntions: 
	//modifying operat change curr obj (+=/-=/*=/++/--/[]) - return a ref to modif obj;
	// VS
	//non (+/-/*/==/!=) produce new result;
	//binary operators / unary operators / compound assignment / incr/decr / []
	std::cout << v4++ << std::endl;
	std::cout << ++v4 << std::endl;
	std::cout << v4-- << std::endl;
	std::cout << --v4 << std::endl;
	v2 += v3;
	v1 -= v2;
	v2 = v3 + v3 * 2;
	v2 = 3 * v2;
	//chained expr
	//-> compound assignment operators modify the object and return *this by reference.
	v2 += v2 += v3;
	v1 *= 42;
	// + - * defined in terms of += -=, it's built form them 
	v1 = v1 - v1 + v1;
	std::cout << "v1:" << v1 << std::endl;
	std::cout << "v2:" << v2 << std::endl;
	std::cout << "-v2:" << -v2 << std::endl;
	//[] needs two versions - const and non const obj
	std::cout << "v1[1]:" << v1[1] << std::endl;
	v1[1] = 12;
	std::cout << "v1[1]:" << v1[1] << std::endl;
	std::cout << "v3[1]:" << v3[1] << std::endl;
	std::cout << "v1 == v3" << (v1 == v3) << std::endl;
	std::cout << "v1 == v1" << (v1 == v1) << std::endl;
	std::cout << "v1 != v3" << (v1 != v3) << std::endl;
	std::cout << "v1 != v1" << (v1 != v1) << std::endl;
	return (0);
}
