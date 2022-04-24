# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 17:06:47 by daykim            #+#    #+#              #
#    Updated: 2022/04/24 17:06:47 by daykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -rf

INCLUDES = ./ft_printf.h

SRCS = ft_printf.c ft_printf_utils1.c ft_printf_utils2.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ %<

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re