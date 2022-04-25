# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 17:06:47 by daykim            #+#    #+#              #
#    Updated: 2022/04/25 12:43:43 by daykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs
RM = rm -rf

PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./libft

SRCS = \
		ft_printf.c\
		ft_printf_utils1.c\
		ft_printf_utils2.c
OBJS = $(addprefix $(PRINTF_DIR)/,$(SRCS:.c=.o))


all : $(NAME)

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
