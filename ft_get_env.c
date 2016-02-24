/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 20:55:17 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/09 22:01:53 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	*ft_get_env(char *new, char **env)
{
	char	*tmp;
	char	*find;
	int		i;
	int		l;

	l = ft_strlen(new);
	i = 0;
	if (!*env)
		return (NULL);
	while (env[i])
	{
		tmp = ft_strsub(env[i], 0, l);
		if ((ft_strcmp(new, tmp)) == 0)
		{
			find = ft_strsub(env[i], l + 1, ft_strlen(env[i]) - l - 1);
			return (find);
		}
		free (tmp);
		i++;
	}
	return (NULL);
}
