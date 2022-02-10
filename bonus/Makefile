# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartine <omartine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 12:21:40 by omartine          #+#    #+#              #
#    Updated: 2022/02/10 18:53:02 by omartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = my_checker.c movements_bonus/push.c movements_bonus/reverse.c \
		movements_bonus/rotates.c movements_bonus/swaps.c sort_management_bonus/3_sort.c \
		sort_management_bonus/100_sort.c sort_management_bonus/500_sort.c split.c \
		sort_management_bonus/sort_utils.c sort_management_bonus/sort_management.c \
		to_be_free.c main_utils.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c my_checker_utils.c


OBJS = $(SRCS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MAKE			= make
NAME			= checker_omartine
all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				mv $(NAME) ../
clean:
				$(RM) $(OBJS)
fclean:			clean
				$(RM) $(NAME)
re:				fclean $(NAME)
.PHONY:			all clean fclean re
