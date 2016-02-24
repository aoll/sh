/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 15:05:03 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/02 19:18:46 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_mycpy(char **stat, char **line)
{
	size_t	i;
	char	*tp;

	tp = ft_strdup(*stat);
	*line = ft_strnew(0);
	i = 0;
	if (*stat[0] == '\n' || *stat[0] == '\0')
	{
		*line = ft_strnew(0);
		*stat = ft_strsub((char *)tp, 1, ft_strlen(tp) - 1);
		free (tp);
		return (1);
	}
	while (tp[i] != '\n' && tp[i] != '\0')
		i++;
	if (tp[i] == '\n')
	{
		*stat = ft_strnew(0);
		*line = ft_strsub((char *)tp, 0, i);
		*stat = ft_strsub((char *)tp, i + 1, ft_strlen(tp) - i - 1);
		free (tp);
		return (1);
	}
	return (0);
}

void	ft_no_place(char **line, char **buf)
{
	*line = ft_strnew(0);
	*buf = ft_strnew(BUFF_SIZE);
}

int		get_next_line(int const fd, char **line)
{
	char		*buf;
	static char *stat;
	int			rd;

	if (fd < 0 || !line || fd > 255)
		return (-1);
	ft_no_place(line, &buf);
	if (stat && (rd = ft_mycpy(&stat, line)) > 0)
		return (1);
	while ((rd = read(fd, buf, BUFF_SIZE)))
	{
		if (rd < 0)
			return (-1);
		buf[rd] = '\0';
		stat = ft_strjoin((const char *)stat, (const char *)buf);
		if ((rd = ft_mycpy(&stat, line)) > 0)
			return (1);
	}
	if (stat && (*line = ft_strdup(stat)))
	{
		stat = NULL;
		return (1);
	}
	*line = NULL;
	return (0);
}
