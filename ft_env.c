/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 13:30:36 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 16:27:40 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		ft_check_char(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int		ft_nb_v(char **line)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (line[i])
	{
		if ((ft_check_char(line[i], '=')))
			j++;
		i++;
	}
	return (j);
}

void	ft_envbis(char **line)
{
	t_eter	e;

	if (!(e.n = ft_nb_v(line)))
		return ;
	e.env = ft_envbis2tab(e.n, &e.j, &e.i);
	while (e.i < e.n)
	{
		if ((e.l = ft_check_char(line[e.j], '=')))
		{
			e.name = ft_envbis2name(line[e.j], e.l, &e.tp, &e.t);
			while (++e.tp < e.i)
			{
				e.tmp = ft_strsub(e.env[e.tp], 0, e.l);
				if ((ft_strcmp(e.tmp, e.name) == 0))
					e.env[e.tp] = ft_strdup(line[e.j++]), e.t++, e.n--;
			}
			e.env[e.i++] = ((!e.t) ? ft_strdup(line[e.j++]) : 0);
		}
		else
		{
			ft_envbis2error(line[e.j]);
			return ;
		}
	}
	ft_print_tab(e.env);
}

void	ft_env(char **tab, char **line)
{
	t_eter e;

	if (!(e.n = ft_env4error(tab, line)))
		return ;
	e.env = ft_env4j(tab, &e.j);
	while (line[++e.j])
		if ((ft_env3checkline(line[e.j])))
			return ;
	e.env = ft_env3tab(tab, &e.n, &e.i);
	e.j = 1;
	while (e.i < e.n && line[e.j])
	{
		if ((e.l = ft_check_char(line[e.j], '=')))
		{
			e.name = ft_tab3tp(line[e.j], e.l, &e.tp, &e.t);
			while (++e.tp < e.i)
			{
				e.tmp = ft_strsub(e.env[e.tp], 0, e.l);
				if ((ft_strcmp(e.tmp, e.name) == 0))
					e.env[e.tp] = ft_strdup(line[e.j++]), e.t++, e.n--;
			}
			e.env[e.i++] = ((!(e.t)) ? ft_strdup(line[e.j++]) : 0);
		}
	}
	ft_print_tab(e.env);
}
