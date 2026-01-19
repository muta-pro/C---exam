/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:12:27 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/19 19:47:37 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vbc.h"

static node	*parse_sum(char **s);

static node	*new_node(node n)
{
	node	*ret;

	ret = (node *)calloc(1, sizeof(node));
	if (!ret)
		return (NULL);
	*ret = n;
	return (ret);
}

static void	destroy_tree(node *n)
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

static void	unexpected(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input\n");
}

static int	accept(char **s, char c)
{
	if (**s == c)
	{
		(*s)++;
		return (1);
	}
	return (0);
}

int	expect(char **s, char c)
{
	if (accept(s, c))
		return (1);
	unexpected(**s);
	return (0);
}

static node	*parse_factor(char **s) //to add
{
	node	*inside;
	node	*ret;

	if (isdigit((unsigned char)**s))
	{
		ret = new_node((node){.type = VAL, .val = **s - '0', .l = NULL, .r = NULL});
		if (!ret)
			return (NULL);
		(*s)++;
		return (ret);
	}
	if (accept(s, '('))
	{
		inside = parse_sum(s);
		if (!inside)
			return (NULL);
		if (!expect(s, ')'))
			return (destroy_tree(inside), NULL);
		return (inside);
	}
	unexpected(**s);
	return (NULL);
}

static node	*parse_product(char **s) //to add
{
	node	*l;
	node	*r;
	node	*op;

	l = parse_factor(s);
	if (!l)
		return (NULL);
	while (accept(s, '*'))
	{
		r = parse_factor(s);
		if (!r)
			return (destroy_tree(l), NULL);
		op = new_node((node){.type = MULTI, .val = 0, .l = l, .r = r});
		if (!op)
			return (destroy_tree(l), destroy_tree(r), NULL);
		l = op;
	}
	return (l);
}

static node	*parse_sum(char **s) //to add
{
	node	*l;
	node	*r;
	node	*op;

	l = parse_product(s);
	if (!l)
		return (NULL);
	while (accept(s, '+'))
	{
		r = parse_product(s);
		if (!r)
			return (destroy_tree(l), NULL);
		op = new_node((node){.type = ADD, .val = 0, .l = l, .r = r});
		if (!op)
			return (destroy_tree(l), destroy_tree(r), NULL);
		l = op;
	}
	return (l);
}

static node	*parse_expr(char *cur) //to fix
{
	node	*ret;

	ret = parse_sum(&cur);
	if (!ret)
		return (NULL);
	if (*cur)
	{
		unexpected(*cur);
		destroy_tree(ret);
		return (NULL);
	}
	return (ret);
}

int	eval_tree(node *tree) //to fix
{
	if (tree->type == ADD)
		return (eval_tree(tree->l) + eval_tree(tree->r));
	if (tree->type == MULTI)
		return (eval_tree(tree->l) * eval_tree(tree->r));
	return (tree->val);
}
int	main(int argc, char **argv)
{
	node	*tree;

	if (argc != 2)
		return (1);
	tree = parse_expr(argv[1]);
	if (!tree)
		return (1);
	printf("%d\n", eval_tree(tree));
	destroy_tree(tree);
	return (0);
}
