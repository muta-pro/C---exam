/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:42:38 by imutavdz          #+#    #+#             */
/*   Updated: 2025/11/20 11:47:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

// void	print_char(char *str)
// {
// 	if (*str == '\0')
// 		return ;
// 	printf("%c\n", *str);
// 	print_char(str + 1);
// }

 //reverse print
void	print_char_rev(char *str)
{
	if (*str == 0)
		return ;
	print_char_rev(str + 1);
	printf("%c\n", *str);
}
int	main(void)
{
	// print_char("hello");
	print_char_rev("hello");
	return (0);
}
