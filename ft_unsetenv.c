/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 15:36:58 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 12:59:43 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**ft_unsetenvbis(char **tab, char *s)
{
	t_ebis e;

	e.n = 0;
	e.j = 0;
	e.i = 0;
	while (tab[e.i])
		e.i++;
	if (!(e.env = (char **)malloc(sizeof(char *) * e.i - 1)))
		return (NULL);
	e.env[e.i - 1] = NULL;
	e.i = 0;
	while (tab[e.i])
	{
		e.tmp = ft_strsub(tab[e.i], 0, ft_strlen(s));
		if ((ft_strcmp(e.tmp, s)) == 0 && !e.j)
			e.j++, e.i++;
		else if (tab[e.i])
			e.env[e.n++] = ft_strdup(tab[e.i++]);
	}
	if (e.j)
		return (e.env);
	return (tab);
}

char	**ft_unsetenv(char **tab, char **line)
{
	char	**env;
	int		i;

	if (line[0] && line[1] == '\0')
	{
		ft_putendl("unsetenv: Too few arguments.");
		return (tab);
	}
	i = 1;
	env = ft_copy_tab(tab);
	env = ft_unsetenvbis(env, line[i]);
	i++;
	if (!line[i])
		return (env);
	while (line[i])
	{
		env = ft_unsetenvbis(env, line[i]);
		i++;
	}
	return (env);
}
