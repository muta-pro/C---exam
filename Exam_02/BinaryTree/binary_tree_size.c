/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:07:15 by imutavdz          #+#    #+#             */
/*   Updated: 2025/10/28 10:42:51 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Implement basic node struct/class and traversal routines.

Practice injections of nodes (BST insert/delete) 
and handling edge cases (empty tree, single node).

Advance to specialized problems (height, width, mirror, splitting, perimeter).*/

#include "ft_btree.h"
#include <stdlib.h>

int	h_tree(t_btree *root)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	left = h_tree(root->left);
	right = h_tree(root->right);
	if (left < right)
		return (left + 1);
	else
		return (right + 1);
}

int	size_binary_tree(t_btree *root)
{
	if (!root)
		return (0);
	return (1
		+ size_binary_tree(root->left)
		+ size_binary_tree(root->right));
}

static t_btree	*minimum_value(t_btree *node)
{
	while (node->left)
		node = node->left;
	return (node);
}

int	is_balanced(t_btree *root)
{
	int	left_h;
	int	right_h;

	if (!root)
		return (1);
	left_h = h_tree(root->left);
	right_h = h_tree(root->right);
	if (left_h - right_h > 1 || right_h - left_h > 1)
		return (0);
	if (!is_balanced(root->left) || !is_balanced(root->right))
		return (0);
	return (1);
}

int	has_value(t_btree *root, int val)
{
	if (!root)
		return (0);
	if (root->value == val)
		return (1);
	if (has_value(root->left, val))
		return (1);
	return (has_value(root->right, val));
}
