/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc_proba.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:59:28 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/21 10:28:20 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vbc.h"
static node *parse_sum(char **s);

static node *new_node(node n)
{
	node *ret;

	ret = calloc(1, sizeof(*ret));
	if (!ret)
		return (NULL);
	*ret = n;
	return (ret);
}

static void destroy_tree(node *n)
{
	if (!n)
		return ;
	if (n->type != VAL)
	{
		destroy_tree(n->l);
		destroy_tree(n->r);
	}
	free(n);
}

static void unexpected(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input\n");
}

static int accept(char **s, char c)
{
	if (**s == c)
	{
		(*s)++;
		return (1);
	}
	return (0);
}

int expect(char **s, char c)
{
	if (accept(s, c))
		return (1);
	unexpected(**s);
	return (0);
}

//
//

int main(int argc, char **argv)
{
	node *tree;

	if (argc < 2)
		return (1);
	tree = parse_expr(argv[1]);
	if (!tree)
		return (1);
	printf("%d\n", eval_tree(tree));
	destroy_tree(tree);
	return (0);
}