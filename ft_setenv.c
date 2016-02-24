/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 14:37:04 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 13:18:08 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static char		**ft_set_tab(char **line)
{
	char **env;

	env = (char **)malloc(sizeof(char *) * 2);
	env[1] = NULL;
	env[0] = ft_strnew(0);
	env[0] = ft_strjoin(line[1], "=");
	if (line[2])
		env[0] = ft_strjoin(env[0], line[2]);
	return (env);
}

static char		**ft_setbis(int i, char **tab, char **line)
{
	char	**env;
	int		tp;

	tp = 0;
	i = ft_tablen(tab);
	env = NULL;
	env = (char **)malloc(sizeof(char *) * i + 2 + 7);
	while (tp <= i + 7)
		env[tp++] = NULL;
	env[i + 1] = NULL;
	i = 0;
	while (tab[i] != NULL && tab[i])
	{
		env[i] = ft_strnew(0);
		env[i] = ft_strdup(tab[i]);
		i++;
	}
	env[i] = ft_strnew(0);
	env[i] = ft_strjoin(line[1], "=");
	if (line[2])
		env[i] = ft_strjoin(env[i], line[2]);
	env[i + 1] = NULL;
	return (env);
}

static int		ft_setend(char **tab, char **line)
{
	if (!line[1])
	{
		ft_print_tab(tab);
		return (1);
	}
	if (ft_tablen(line) > 3)
	{
		ft_putendl("setenv: Too many arguments.");
		return (1);
	}
	return (0);
}

char			**ft_setenv(char **tab, char **line)
{
	char	*tmp;
	int		i;

	if ((ft_setend(tab, line) > 0))
		return (tab);
	if (tab == NULL)
		return (ft_set_tab(line));
	i = 0;
	while (tab[i])
	{
		tmp = ft_strsub(tab[i], 0, ft_strlen(line[1]));
		if ((ft_strcmp(tmp, line[1])) == 0)
		{
			tab[i] = ft_strjoin(line[1], "=");
			if (line[2])
				tab[i] = ft_strjoin(tab[i], line[2]);
			return (tab);
		}
		i++;
	}
	return ((ft_setbis(i, tab, line)));
}
