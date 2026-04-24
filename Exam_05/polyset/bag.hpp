/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bag.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:54:05 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/24 02:23:15 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BAG_hpp
#define BAG_hpp

class bag {
	public:
		virtual ~bag() {}
		virtual void insert(int) = 0;
		virtual void insert(int *, int) = 0;
		virtual void print() const = 0;
		virtual void clear() = 0;
};

#endif
