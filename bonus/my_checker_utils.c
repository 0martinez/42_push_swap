/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:58:44 by omartine          #+#    #+#             */
/*   Updated: 2022/02/11 13:42:40 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

struct stacks	push_checker(char *str, t_stack_gen st)
{
	if (str[1] == 'b' && str[2] == '\n')
		st = push_b(st);
	else if (str[1] == 'a' && str[2] == '\n')
		st = push_a(st);
	else
		st.error = 1;
	return (st);
}

struct stacks	swap_checker(char *str, t_stack_gen st)
{
	if (str[1] == 'a' && str[2] == '\n')
		st = swap_a(st);
	else if (str[1] == 'b' && str[2] == '\n')
		st = swap_b(st);
	else if (str[1] == 's' && str[2] == '\n')
		st = swap_ab(st);
	else
		st.error = 1;
	return (st);
}

struct stacks	rotate_checker(char *str, t_stack_gen st)
{
	if (str[1] == 'a' && str[2] == '\n')
		st = rotate_a(st);
	else if (str[1] == 'b' && str[2] == '\n')
		st = rotate_b(st);
	else if (str[1] == 'r' && str[2] == '\n')
		st = rotate_ab(st);
	else
		st.error = 1;
	return (st);
}

struct stacks	reverse_checker(char *str, t_stack_gen st)
{
	if (str[2] == 'a' && str[3] == '\n')
		st = reverse_a(st);
	else if (str[2] == 'b' && str[3] == '\n')
		st = reverse_b(st);
	else if (str[2] == 'r' && str[3] == '\n')
		st = reverse_ab(st);
	else
		st.error = 1;
	return (st);
}

int	ok_or_ko(t_stack_gen st, int flg)
{
	if (flg == 0)
	{
		if (check_if_a_ordered(st) == 0)
			write(1, "OK!\n", 4);
		else
			write(1, "KO!\n", 4);
	}
	else
	{
		if (check_if_a_ordered(st) == 0 && st.alen == st.clen)
			write(1, "OK!\n", 4);
		else
			write(1, "KO!\n", 4);
	}
	return (0);
}
