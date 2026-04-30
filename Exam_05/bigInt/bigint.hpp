/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 03:57:33 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/29 09:47:18 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <cstddef>

//custom number type - digit representation: data repres. design
//internal digit storage -define how value neters obj world
//obj must always stay in clean valid state: normalizatoin
class bigint {
public:
	bigint();
	bigint(unsigned int value); //also for adaptation in expressions
	bigint(const bigint &copy);
	bigint &operator=(const bigint &assign);
	~bigint();

	bigint &operator+=(const bigint &other);
	bigint operator+(const bigint &other) const;

	bigint &operator++();
	bigint operator++(int);
//decimal digit shift
	bigint &operator<<=(const int shift); 
	bigint &operator>>=(const int shift);
	bigint operator<<(const int shift) const;
	bigint operator>>(const int shift) const;
	
	bool operator==(const bigint &other) const;
	
	bool operator!=(const bigint &other) const;
	
	bool operator<(const bigint &other) const;
	
	bool operator>(const bigint &other) const;
	
	bool operator<=(const bigint &other) const;
	
	bool operator>=(const bigint &other) const;

	std::string getStr() const;

private:
	std::string _n; //"number" stored as text

	void normalize(); //protects the class invariant - valid
	int compare(const bigint &other) const;
	std::size_t to_size_t() const;
};
//design split: display internal repres. in a correct way
std::ostream &operator<<(std::ostream &out, const bigint &value);



#endif