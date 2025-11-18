/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_inv_paren.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:08:29 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/18 15:52:57 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
check the balance but removing parentheses to make it balanced
and check all valid results
with recursion and backtracking
generating all possible valid variations 
generate ALL valid possibilities by removing bad parentheses
 → this is a classic backtracking / DFS problem:

choose a char → keep or delete → recurse → prune invalid branches.*/