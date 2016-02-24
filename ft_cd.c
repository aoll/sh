/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 12:37:35 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 16:48:50 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static char	**ft_tabcd(char *old)
{
	char **env;

	env = malloc(sizeof(char *) * 3);
	env[0] = NULL;
	env[1] = NULL;
	env[2] = NULL;
	env[0] = ft_strnew(0);
	env[0] = ft_strjoin("OLDPWD", "=");
	env[0] = ft_strjoin(env[0], old);
	env[1] = ft_strjoin("PWD", "=");
	env[1] = ft_strjoin(env[1], old);
	return (env);
}

static char	**ft_cd1(char *path, char **env, int y)
{
	if (chdir(path) < 0)
		ft_putendl("cd: No home");
	else
	{
		if (!y)
			env = ft_check_env(env, "PWD", path);
		if (y)
			env[1] = ft_strjoin("PWD=", path);
	}
	return (env);
}

static char	**ft_cd2(char *old, char **env, int y)
{
	char *new;

	new = ft_strnew(0);
	new = ft_get_env("OLDPWD", env);
	if (chdir(ft_get_env("OLDPWD", env)) < 0)
		ft_putendl("cd: No home");
	else
	{
		if (y == 0)
		{
			env = ft_check_env(env, "OLDPWD", old);
			env = ft_check_env(env, "PWD", new);
		}
		if (y)
		{
			old = ft_strnew(1000);
			old = getcwd(old, 1000);
			env[1] = ft_strjoin("PWD=", old);
		}
	}
	return (env);
}

static char	**ft_cd3(char *old, char **env, char **line, int y)
{
	if (chdir(line[1]) < 0)
		ft_putstr("cd: no such file or directory: "), ft_putendl(line[1]);
	else
	{
		old = ft_strnew(1000);
		old = getcwd(old, 1000);
		if (!y)
			env = ft_check_env(env, "PWD", old);
		if (y)
			env[1] = ft_strjoin("PWD=", old);
	}
	return (env);
}

char		**ft_cd(char **line, char **env)
{
	char	*path;
	char	*old;
	int		y;

	y = 0;
	old = getcwd(ft_strnew(1000), 1000);
	if (env)
	{
		path = ft_get_env("HOME", env);
		env = ((!line[1]) ? ft_cdend(env, path, old) : ft_copy_tab(env));
		if ((ft_strcmp(line[1], "-") != 0))
			env = ft_check_env(env, "OLDPWD", old);
	}
	((env == NULL) ? ((env = ft_tabcd(old)), y++) : 0);
	if (line[1] == NULL || (ft_strcmp(line[1], "~") == 0))
		return (ft_cd1(path, env, y));
	if ((ft_strcmp(line[1], "-") == 0))
		return (ft_cd2(old, env, y));
	if (line[2] && !line[3])
		return (ft_cdbis(env, line));
	if (ft_tablen(line) > 2)
		return (ft_cdter(env));
	if (line[1])
		return (ft_cd3(old, env, line, y));
	return (env);
}
