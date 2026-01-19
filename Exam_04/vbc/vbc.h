/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:12:39 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/19 19:23:12 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VBC_H
# define VBC_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct node
{
	enum {ADD, MULTI, VAL} type;
	int			val;
	struct node	*l;
	struct node	*r;
}				node;

#endif