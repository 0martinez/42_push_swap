# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartine <omartine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:02:43 by omartine          #+#    #+#              #
#    Updated: 2022/02/15 19:32:07 by omartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	push_swap.c movements/push.c movements/reverse.c movements/rotates.c \
		movements/swaps.c sort_management/3_sort.c sort_management/100_sort.c \
		sort_management/500_sort.c sort_management/sort_utils.c \
		sort_management/sort_management.c utils/to_be_free.c utils/main_utils.c \
		utils/split.c

SRCS_BONUS = bonus/my_checker.c bonus/movements_bonus/push.c bonus/movements_bonus/reverse.c \
		bonus/movements_bonus/rotates.c bonus/movements_bonus/swaps.c bonus/sort_management_bonus/3_sort.c \
		bonus/sort_management_bonus/100_sort.c bonus/sort_management_bonus/500_sort.c bonus/utils/split.c \
		bonus/sort_management_bonus/sort_utils.c bonus/sort_management_bonus/sort_management.c \
		bonus/utils/to_be_free.c bonus/utils/main_utils.c bonus/get_next_line/get_next_line.c \
		bonus/get_next_line/get_next_line_utils.c bonus/utils/my_checker_utils.c

OBJS = $(SRCS:.c=.o)

BONUS_O = $(SRCS_BONUS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MAKE			= make
NAME			= push_swap
NAME_BONUS		= checker_omartine

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS) $(BONUS_O)
fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean $(NAME)

bonus:			$(NAME_BONUS)

$(NAME_BONUS):	$(BONUS_O)
				$(CC) $(CFLAGS) $(BONUS_O) -o $(NAME_BONUS)

rebonus:		fclean $(NAME) $(NAME_BONUS)

.PHONY:			all clean fclean re bonus
