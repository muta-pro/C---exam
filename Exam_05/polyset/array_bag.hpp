/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bag.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:28:27 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/21 14:32:17 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_BAG_HPP
#define ARR_BAG_HPP

#include "bag.hpp"

class array_bag : virtual public bag {
	public:
			array_bag();
			array_bag(const array_bag &copy);
			array_bag &operator=(const array_bag &assign);
			~array_bag();

			void insert();
			void insert(int *, int);
			void print() const;
			void clear();

	protected:
		int *data;
		int size;
};

#endif