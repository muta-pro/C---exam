/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bag.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:42:26 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/25 06:39:20 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree_bag.hpp"
#include <iostream>

tree_bag::tree_bag() {
	tree = NULL;
}

tree_bag::tree_bag(const tree_bag &copy) {
	tree = copy_node(copy.tree);
}

tree_bag::~tree_bag() {
	destroy_tree(tree);
}

tree_bag &tree_bag::operator=(const tree_bag &assign) {
	if (this != &assign) {
		destroy_tree(tree);
		tree = copy_node(assign.tree);
	}
	return *this;
}

tree_bag::node *tree_bag::extract_tree() {
	node *temp = tree;
	tree = NULL;
	return temp;
}

void tree_bag::set_tree(node *new_tree) {
	destroy_tree(tree);
	tree = new_tree;
}

void tree_bag::insert(int item) {
	node *new_node = new node;
	new_node->value = item;
	new_node->l = NULL;
	new_node->r = NULL;
	if (tree == NULL)
		tree = new_node;
	else {
		node *curr = tree;
		while (true) {
			if (item < curr->value) {
				if (curr->l == NULL) {
					curr->l = new_node;
					break ;
				}
				else
					curr = curr->l;
			}
			else if (item > curr->value) {
				if (curr->r == NULL) {
					curr->r = new_node;
					break ;
				}
				else
					curr = curr->r;
			}
		}
	}
}

void tree_bag::insert(int *items, int count) {
	for (int i =  0; i < count; i++)
		insert(items[i]);
}

void tree_bag::print() const {
	print_node(tree);
	std::cout << std::endl;
}

void tree_bag::clear() {
	destroy_tree(tree);
	tree = NULL;
}

void tree_bag::destroy_tree(node *curr) {
	if (curr != NULL) {
		std::cout << "destroying value " << curr->value << std::endl;
		destroy_tree(curr->l);
		destroy_tree(curr->r);
		delete curr;
	}
}

void tree_bag::print_node(node *curr) {
	if (curr != NULL) {
		print_node(curr->l);
		if (curr != NULL)
			std::cout << curr->value << " ";
		print_node(curr->r);
	}
}

tree_bag::node *tree_bag::copy_node(node *curr) {
	if (curr == NULL) {
		return NULL;
	}
	else {
		node *new_node = new node;
		new_node->value = curr->value;
		new_node->l = copy_node(curr->l);
		new_node->r = copy_node(curr->r);
		return new_node;
	}
}
