/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 21:31:37 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/11 17:44:51 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	ft_print_tab(char **tab)
{
	int i;

	i = 0;
	if (!*tab)
		return ;
	while (tab[i])
	{
		ft_putstr(tab[i]), ft_putchar('\n');
		i++;
	}
}
