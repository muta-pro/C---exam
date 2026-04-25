/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 21:20:18 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/25 06:35:05 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set {
	public:
			set(searchable_bag &bag);
			set(const set &copy);
			set &operator=(const set &assign);
			~set();

			void insert(int value);
			void insert(int *value, int count);
			bool has(int value) const;
			void print() const;
			void clear();
			const searchable_bag &get_bag() const; //main needs

	private:
		searchable_bag& _bag; //composition
};

#endif

