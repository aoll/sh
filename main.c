/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:37:41 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 16:49:25 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void			sig(int sig)
{
	sig = sig;
	ft_putchar('\n');
	ft_putstr("$>");
}

char			**mainbis(char *line, char **env)
{
	char **tmp;

	if (!(line = ft_strtrim(line)))
		return (env);
	tmp = ft_strsplit(line, ' ');
	if ((ft_strcmp(tmp[0], "unsetenv")) == 0 && env)
		env = ft_unsetenv(env, tmp);
	else if ((ft_strcmp(tmp[0], "setenv")) == 0)
		env = ft_setenv(env, tmp);
	else if ((ft_strcmp(tmp[0], "env")) == 0)
		ft_env(env, tmp);
	else if ((ft_strcmp(tmp[0], "exit")) == 0)
		ft_exit(tmp);
	else if ((ft_strcmp(tmp[0], "cd")) == 0)
		env = ft_cd(tmp, env);
	else if ((ft_strcmp(tmp[0], "cd") != 0))
	{
		if (env == NULL)
			ft_putendl("env: No PATH");
		else
			ft_execve(tmp, env);
	}
	return (env);
}

static char		**mainter(int ac, char **env, char *line)
{
	char **tmp;

	line = ft_strtrim(line);
	tmp = ft_strsplit(line, ';');
	ac = 0;
	while (tmp[ac])
	{
		env = mainbis(tmp[ac], env);
		ac++;
	}
	return (env);
}

int				main(int ac, char **av, char **envs)
{
	char	*line;
	int		red;
	char	**env;

	av = av;
	env = ((envs[0]) ? ft_copy_tab(envs) : NULL);
	signal(SIGINT, sig);
	while (42)
	{
		ft_putstr("$>");
		if ((red = get_next_line(0, &line)))
		{
			if ((ft_strlen(line)) > 0)
			{
				env = mainter(ac, env, line);
			}
			((red < 0) ? exit (0) : 0);
		}
		((red == 0) ? (ft_putchar('\n'), exit (0)) : 0);
	}
	return (0);
}
