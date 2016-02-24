/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 16:58:34 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 13:26:46 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static int		ft_check_exitbis(char *s, int i)
{
	int j;
	int j2;

	j = 0;
	j2 = 0;
	while (s[i])
	{
		if (s[i] == '(')
			j++;
		if (s[i] == ')')
			j2++;
		i++;
	}
	if (j > j2)
	{
		ft_putendl("Too many ('s.");
		return (-1);
	}
	if (j > j2)
	{
		ft_putendl("Too many ('s.");
		return (-1);
	}
	return (0);
}

int				ft_check_exit(char *s)
{
	int i;

	i = 0;
	if ((ft_check_exitbis(s, i) < 0))
		return (-1);
	while (s[i] == '(')
		i++;
	while (s[i] && s[i] != ')')
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '-')
			return (1);
		i++;
	}
	while (s[i])
	{
		if (s[i] != ')')
		{
			ft_putendl("exit: Expression Sintax");
			return (-1);
		}
		i++;
	}
	return (0);
}

int				ft_exit(char **line)
{
	if (line[1] == NULL)
		exit (0);
	if (line[2])
	{
		ft_putendl("exit: Expression Syntax.");
		return (0);
	}
	if ((ft_check_exit(line[1])) == 1)
	{
		ft_putendl("exit: Expression Syntax.");
		return (0);
	}
	else if ((ft_check_exit(line[1])) == -1)
		return (0);
	else
		exit(ft_atoi_sh(line[1]));
	return (0);
}
