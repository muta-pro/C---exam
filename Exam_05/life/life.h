/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:52:17 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/14 19:58:25 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIFE_H
#define LIFE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct life
{
	char	**board;
	int		w;
	int		h;	
}	t_life;

char	**alloc_board(int w, int h);
void	fill_board(t_life *g);
int		count_neighbors(t_life *g, int row, int col);
int		next_gen(t_life *g);
void	print_board(t_life *game);
void	free_board(t_life *game);

#endif