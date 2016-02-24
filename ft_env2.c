/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 13:34:26 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 14:48:22 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**ft_envbis2tab(int n, int *j, int *i)
{
	char	**env;
	int		tp;

	*j = 1;
	*i = 0;
	tp = 0;
	env = (char **)malloc(sizeof(char *) * n + 1);
	tp = 0;
	while (tp <= n)
		env[tp++] = NULL;
	return (env);
}

void	ft_envbis2error(char *line)
{
	ft_putstr("env: "), ft_putstr(line);
	ft_putendl(": No such file or directory");
}

char	*ft_envbis2name(char *line, int l, int *tp, int *t)
{
	char *name;

	name = ft_strnew(0);
	name = ft_strsub(line, 0, l);
	*tp = -1;
	*t = 0;
	return (name);
}
