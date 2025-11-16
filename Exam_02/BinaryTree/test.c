/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:08:48 by imutavdz          #+#    #+#             */
/*   Updated: 2025/08/01 19:13:58 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_btree	*root;

	root = new_node(4);
	if (!root)
		return (0);
	root->left = new_node(3);
	root->right = new_node(5);
	root->right->right = new_node(10);
	root->left->left = new_node(2);
	printf("Tree h: %d\n", h_tree(root));
	printf("Empty tree size: %d\n", h_tree(NULL));
	free_tree(root);
	return (0);
}
//NEXT THING LEARN FIND OUT IF TREE BALANCED.