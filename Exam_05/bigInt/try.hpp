/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:53:59 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/04 17:09:49 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRY_HPP
#define TRY_HPP


#include <iosream>
#include <cstddef>
#include <string>

class bigint {
	public:
			bigint();
			bigint(unsigned int value);
			bigint(const bigint &copy);
			bigint &operator=(const bigint &assign);
			~bigint();

			bigint &operator+=(const bigint &other);

			bigint &operator++();
			bigint operator++(int);
			
			bigint operator<<=(const bigint &shift);
			bigint operator>>=(const bigint &shift);
			bigint operator>(const bigint &shift) const;
			bigint operator<(const bigint &shift) const;

			bigint operator<=(const bigint &other) const;
			bigint operator>=(const bigint &other) const;
			bigint operator<(const bigint &other) const;
			bigint operator>(const bigint &other) const;
			bigint operator==(const bigint &other) const;
			bigint operator!=(const bigint &other) const;

			std::string &getstr() const;


	private:
		std::string _n;

		void normalize();
		int compare(bigint const &other) const;
		size_t to_size_t();
};

std::ostream &operator<<(std::ostream &out, std::ostream &n);

bigint operator+(const bigint &other) const;

#endif
