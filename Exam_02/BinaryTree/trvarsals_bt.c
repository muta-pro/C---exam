/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trvarsals_bt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:33:17 by imutavdz          #+#    #+#             */
/*   Updated: 2025/10/28 10:42:55 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "binary_tree.h"

void	inorder(t_btree *root)
{
	if (!root)
		return ;
	inorder(root->left);
	inorder(root->right);
}
