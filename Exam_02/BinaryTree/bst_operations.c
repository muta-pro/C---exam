/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:11:06 by imutavdz          #+#    #+#             */
/*   Updated: 2025/10/28 10:42:44 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"
#include <stdlib.h>

t_btree	*new_node(int val)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->value = val;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_btree	*bst_insert(t_btree *root, int value)
{
	if (!root)
		return (new_node(value));
	if (value < root->value)
		root->left = bst_insert(root->left, value);
	else if (value > root->value)
		root->right = bst_insert(root->right, value);
	return (root);
}

struct s_btree	*bst_delete(t_btree *root, int value)
{
	t_btree	*r;
	t_btree	*l;
	t_btree	*temp;

	if (!root)
		return (NULL);
	if (value < root->value)
		root->left = (bst_delete(root->left, value));
	else if (value > root->value)
		root->right = (bst_delete(root->right, value));
	else
	{
		if (root->left == NULL && root->right == NULL) //LEAF
		{
			free(root);
			return (NULL);
		}
		else if (root->left == NULL) //ONE CHILD
		{
			r = root;
			root = root->right;
			free(r);
		}
		else if (root->right == NULL)
		{
			l = root;
			root = root->left;
			free(l);
		}
		else //TWO CHILDREN
		{
			temp = minimum_value(root->right);
			root->value = temp->value;
			root->right = bst_delete(root->right, temp->value);
		}
	}
	return (root);
}

void	free_tree(t_btree *root)
{
	if (!root)
		return ;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

int	*bst_search(int value, t_btree *root)
{
	if (!root)
		return (0);
	if (root->value == value)
		return (1);
	else if (value < root->value)
		return (bst_search(value, root->left));
	else
		return (bst_search(value, root->right));
}

int	height_binary_tree(t_btree *root);

int depth(t_btree *root);

