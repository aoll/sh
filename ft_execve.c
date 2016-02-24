/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:32:12 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 13:27:59 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		ft_execve(char **tab, char **env)
{
	t_env e;

	e.i = 0;
	if ((ft_strcmp(tab[0], "env") == 0) ||
(ft_strcmp(tab[0], "setenv") == 0) || (ft_strcmp(tab[0], "unsetenv") == 0))
		return (0);
	e.pathenv = ft_get_env("PATH", env);
	if (!e.pathenv)
	{
		ft_putendl("sh1: No PATH");
		return (0);
	}
	e.path = ft_strsplit(e.pathenv, ':');
	e.tmpls = ft_strjoin("/", tab[0]);
	(((e.fa = fork()) > 0) ? wait(0) : 0);
	if (e.fa == 0)
	{
		signal(SIGINT, sig);
		execve(tab[0], tab, env);
		e.tmp = ft_strjoin(e.path[e.i++], e.tmpls);
		while ((execve(e.tmp, tab, env)) < 0 && e.path[e.i])
			e.tmp = ft_strjoin(e.path[e.i++], e.tmpls);
		ft_putstr(tab[0]), ft_putendl(": command not found");
	}
	return (0);
}
