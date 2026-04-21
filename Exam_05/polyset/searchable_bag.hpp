/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_bag.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:54:20 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/21 14:26:03 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH_BAG_HPP
#define SEARCH_BAG_HPP

#include "bag.hpp"

class searchable_bag : virtual public bag {
	public:
		virtual bool has(int) const = 0;
};

#endif