/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 16:03:24 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 16:28:27 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		ft_env4error(char **tab, char **line)
{
	int n;

	if ((ft_env3tabline(tab, line)))
		return (0);
	if (!(n = ft_env3nbline(line)))
		return (0);
	return (n);
}

char	**ft_env4j(char **tab, int *j)
{
	char **env;

	env = ft_copy_tab(tab);
	*j = 0;
	return (env);
}
