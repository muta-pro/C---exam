/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:52:17 by imutavdz          #+#    #+#             */
/*   Updated: 2026/05/06 22:57:36 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIFE_H
#define LIFE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct life
{
	int	w;
	int	h;
	int	iter;
	int	alive;
	int	dead;
	int	i;
	int	j;
	int	draw;
	char	**board;	
} t_life;

int		init(t_life *game, char *argv[]);
void	fill_board(t_life *game);
int 	play(t_life *game);
void	print_board(t_life *game);
void	free_board(t_life *game);

#endif