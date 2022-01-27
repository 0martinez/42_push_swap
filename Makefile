# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartine <omartine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:02:43 by omartine          #+#    #+#              #
#    Updated: 2022/01/27 16:42:25 by omartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	push_swap.c movements/push.c movements/reverse.c movements/rotates.c \
		movements/swaps.c sort_management/3_sort.c sort_management/100_sort.c \
		sort_management/500_sort.c sort_management/sort_utils.c \
		sort_management/sort_management.c to_be_free.c main_utils.c \
		split.c

OBJS = $(SRCS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MAKE			= make
NAME			= push_swap
all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
				$(RM) $(OBJS)
fclean:			clean
				$(RM) $(NAME)
re:				fclean $(NAME)
.PHONY:			all clean fclean re
