/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 13:00:30 by aollivie          #+#    #+#             */
/*   Updated: 2015/02/02 10:05:14 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fc(char *s, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] >= '0' && s[i + 1] <= '9')
			n++;
		i++;
	}
	return (n);
}
