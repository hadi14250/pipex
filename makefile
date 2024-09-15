# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 19:45:04 by hakaddou          #+#    #+#              #
#    Updated: 2022/05/30 11:07:16 by hakaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_parse.c ft_printf.c  ft_put_address.c ft_put_hex.c \
					ft_putchar.c ft_putnbr_u.c ft_putnbr.c ft_putstr.c pipex.c \
					parsing_and_errors.c split_and_join.c libft_funs.c initialize.c\
					extras.c
					
					
OBJS			= $(SRCS:.c=.o)

BONUS			=

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc -g3
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= pipex

all:			$(NAME)

$(NAME):		$(OBJS)
				 $(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
