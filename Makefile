#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/02 08:22:38 by aollivie          #+#    #+#              #
#    Updated: 2015/03/14 16:03:07 by aollivie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell1

IDIR = libft/libft.a

SRC = main.c ft_execve.c ft_cd.c ft_get_env.c ft_print_tab.c ft_copy_tab.c ft_unsetenv.c ft_setenv.c ft_env.c ft_exit.c ft_cdbis.c ft_env2.c ft_env3.c ft_env4.c

OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra 

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft/
	@gcc $(FLAG) $(OBJ) $(IDIR) -o $(NAME)

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
