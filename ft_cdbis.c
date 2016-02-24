/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 12:19:24 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 12:23:14 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**ft_cdbis(char **env, char **line)
{
	ft_putstr("cd: string not in pwd: "), ft_putendl(line[2]);
	return (env);
}

char	**ft_cdter(char **env)
{
	ft_putendl("cd: too many arguments");
	return (env);
}

char	**ft_check_env(char **env, char *s, char *old)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		tmp = ft_strsub(env[i], 0, ft_strlen(s));
		if ((ft_strcmp(tmp, s)) == 0)
		{
			env[i] = ft_strjoin(s, "=");
			env[i] = ft_strjoin(env[i], old);
			return (env);
		}
		i++;
	}
	return (env);
}

char	**ft_cdend(char **env, char *path, char *old)
{
	chdir(path);
	env = ft_check_env(env, "OLDPWD", old);
	env = ft_check_env(env, "PWD", path);
	return (env);
}
