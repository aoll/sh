/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 21:51:55 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 16:29:07 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**ft_copy_tab(char **tab)
{
	char	**new;
	int		i;
	int		n;

	if (!*tab)
		return (NULL);
	i = 0;
	n = 0;
	while (tab[n])
		n++;
	new = (char **)malloc(sizeof(char *) * n + 1);
	new[n] = NULL;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	return (tab);
}
