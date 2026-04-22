/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:05:21 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/22 16:02:38 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"
#include "set.hpp"
#include <cstdlib>
#include <iostream>

int main(int ac, char **argv) {
	if (ac == 1)
		return 1;
	searchable_bag *t = new searchable_tree_bag;
	searchable_bag *a = new searchabe_array_bag;

	for (int i = 1; i < ac; i++) {
		t->insert(atoi(argv[i]));
		a->insert(atoi(argv[i]));
	}
	t->print();
	a->print();
	for (int i = 1; i < ac; i++) {
		std::cout << t->has(atoi(argv[i])) << std::endl;
		std::cout << a->has(atoi(argv[i])) << std::endl;
		std::cout << t->has(atoi(argv[i]) - 1) << std::endl;
		std::cout << a->has(atoi(argv[i]) - 1) << std::endl;
	}
	t->clear();
	a->clear();
	const searchabe_array_bag tmp(static_cast<searchabe_array_bag &>(*a));
	tmp.print();
	tmp.has(1);

	set sa(*a);
	set st(*t);
	for (int i = 1; i< ac; i++) {
		st.insert(atoi(argv[i]));
		sa.insert(atoi(argv[i]));

		sa.has(atoi(argv[i]));
		sa.print();
		sa.get_bag().print();
		st.print();
		sa.clear();
		sa.insert((int[]){1, 2, 3, 4,}, 4);
		std::cout << std::endl;
	}
	return 0;
}
