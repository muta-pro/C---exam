/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 21:41:03 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/25 06:35:00 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set(searchable_bag& bag) : _bag(bag) {}

set::set(const set& copy) : _bag(copy._bag) {}

set &set::operator=(const set& assign) {
	(void)assign;
	return *this;
}

set::~set() {}

void set::insert(int value) {
	if (!_bag.has(value))
		_bag.insert(value);
}

void set::insert(int *value, int count) {
	for (int i = 0; i < count; i++) {
		insert(value[i]);
	}
}

void set::print() const {
	_bag.print();
}

void set::clear() {
	_bag.clear();
}

bool set::has(int value) const {
	return _bag.has(value);
}

const searchable_bag &set::get_bag() const {
	return _bag;
}


