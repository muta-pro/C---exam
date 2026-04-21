/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_bag.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:28:40 by imutavdz          #+#    #+#             */
/*   Updated: 2026/04/21 15:41:37 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_BAG_HPP
#define TREE_BAG_HPP

#include "bag.hpp"

class tree_bag : virtual public bag {
	protected:
		struct node {
			node *l;
			node *r;
			int value;
		};
		node *tree;	

	public:
			tree_bag();
			tree_bag(const tree_bag &copy);
			tree_bag &operator=(const tree_bag &assign);
			~tree_bag();

			node *extract_tree();
			void set_tree(node *);

			virtual void insert(int);
			virtual void insert(int *array, int size);
			virtual void print() const;
			virtual void clear();

	private:
		static void destroy_tree(node *);
		static void print_node(node *);
		static void *copy_node(node *);
};

#endif