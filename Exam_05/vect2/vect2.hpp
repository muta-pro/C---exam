/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 22:15:30 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/18 23:17:34 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

class vect2 { //container of two ints
	public:
			vect2();
			vect2(int x, int y);
			vect2(const vect2 &copy);
			vect2 &operator=(const vect2 &assign);
			~vect2();
	private:
};

#endif