/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 21:20:18 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/24 02:12:35 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class Set {
	public:
			Set(searchable_bag &bag);
			Set(const Set &copy);
			Set &operator=(const Set &assign);
			~Set();

			void insert(int value);
			void insert(int *value, int count);
			bool has(int value) const;
			void print() const;
			void clear();
			searchable_bag &get_bag() const; //main needs

	private:
		searchable_bag *_bag; //composition
};

#endif

