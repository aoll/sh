/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 15:17:40 by aollivie          #+#    #+#             */
/*   Updated: 2015/03/14 16:53:24 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H
# include <unistd.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_env	t_env;
struct	s_env
{
	pid_t	fa;
	char	**path;
	char	*pathenv;
	char	*tmp;
	char	*tmpls;
	int		i;
};

typedef struct s_ebis	t_ebis;
struct	s_ebis
{
	char	**env;
	int		i;
	int		n;
	int		j;
	char	*tmp;
};

typedef struct s_eter	t_eter;
struct	s_eter
{
	char	**env;
	int		i;
	int		n;
	int		j;
	char	*tmp;
	char	*name;
	int		l;
	int		tp;
	int		t;
	int		z;
};

int		main(int ac, char **av, char **envs);
char	**ft_setenv(char **tab, char **line);
char	**ft_unsetenv(char **tab, char **line);
char	**ft_unsetenvbis(char **tab, char *s);
char	*ft_get_env(char *new, char **env);
char	**ft_copy_tab(char **tab);
void	ft_print_tab(char **tab);
void	sig(int sig);
int		ft_execve(char **tab, char **env);
int		ft_exit(char **line);
int		ft_check_exit(char *s);
char	**ft_cd(char **line, char **env);
char	**ft_cdbis(char **env, char **line);
char	**ft_cdter(char **env);
char	**ft_cdend(char **env, char *path, char *old);
void	ft_env(char **tab, char **line);
void	ft_envbis(char **line);
int		ft_nb_v(char **line);
int		ft_check_char(char *s, char c);
char	**ft_envbis2tab(int n, int *j, int *i);
void	ft_envbis2error(char *line);
char	*ft_envbis2name(char *line, int l, int *tp, int *t);
int		ft_env3tabline(char **tab, char**line);
int		ft_env3checkline(char *line);
char	**ft_env3tab(char **tab, int *n, int *i);
int		ft_env3nbline(char **line);
char	*ft_tab3tp(char *line, int l, int *tp, int *t);
int		ft_env4error(char **tab, char **line);
char	**ft_env4j(char**tab, int *j);
char	**ft_check_env(char **env, char *s, char *old);

#endif
