/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:26:43 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/23 21:33:18 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARHCABLEARRAYBAG_HPP
#define SEARHCABLEARRAYBAG_HPP

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class Searchable_array_bag : public array_bag, public searchable_bag {
	public:
			Searchable_array_bag();
			Searchable_array_bag(const Searchable_array_bag &copy);
			Searchable_array_bag &operator=(const Searchable_array_bag &assign);
			~Searchable_array_bag();

			virtual bool has(int value) const;
	private:
};

#endif