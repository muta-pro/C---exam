/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:20:24 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/24 02:02:25 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class Searchable_tree_bag
{
public:
    Searchable_tree_bag();
    Searchable_tree_bag(const Searchable_tree_bag& copy);
    Searchable_tree_bag& operator=(const Searchable_tree_bag& assign);
    ~Searchable_tree_bag();

    virtual bool has(int value) const;
private:
	static bool search_node(node *curr, int item);
};

#endif
