/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 14:51:16 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 16:16:33 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		ft_env3tabline(char **tab, char **line)
{
	if (tab == NULL)
	{
		ft_envbis(line);
		return (1);
	}
	if (!line[1])
	{
		if (tab[0])
			ft_print_tab(tab);
		return (1);
	}
	return (0);
}

int		ft_env3nbline(char **line)
{
	int n;

	if (!(n = ft_nb_v(line)))
	{
		ft_putstr("env: "), ft_putstr(line[1]);
		ft_putendl(": No such file or directory");
		return (0);
	}
	return (n);
}

int		ft_env3checkline(char *line)
{
	if ((ft_check_char(line, '=') == 0))
	{
		ft_putstr("env: "), ft_putstr(line);
		ft_putendl(": No such file or directory");
		return (1);
	}
	return (0);
}

char	**ft_env3tab(char **tab, int *n, int *i)
{
	int		tp;
	int		l;
	char	**env;
	int		z;
	int		i2;

	z = 0;
	l = *n;
	tp = 0;
	i2 = 0;
	l = l + ft_tablen(tab);
	env = (char **)malloc(sizeof(char *) * l + 1);
	env[l] = NULL;
	tp = 0;
	*n = l;
	while (tp <= l)
		env[tp++] = NULL;
	while (tab[z])
		env[i2++] = ft_strdup(tab[z++]);
	*i = i2;
	return (env);
}

char	*ft_tab3tp(char *line, int l, int *tp, int *t)
{
	char *name;

	name = ft_strsub(line, 0, l);
	*tp = -1;
	*t = 0;
	return (name);
}
