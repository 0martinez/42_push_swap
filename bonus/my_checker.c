/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:16:14 by omartine          #+#    #+#             */
/*   Updated: 2022/02/15 19:37:24 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	*to_stack(char **argv, t_stack_gen *st)
{
	t_to_stack	rt;

	rt.j = 1;
	while (argv[rt.j])
	{
		if (argv[rt.j][0] == 0)
			st->error = 1;
		if (st->error != 0)
			break ;
		rt.z = 0;
		rt.to_add = split_atoi(argv[rt.j], st, &rt.z);
		if (st->error != 0 || !rt.to_add)
		{
			if (rt.to_add)
				free(rt.to_add);
			return (0);
		}
		rt.stack = add_to_stack(rt.to_add, rt.stack, rt.z, st);
		free(rt.to_add);
		if (st->error != 0)
			return (0);
		rt.j++;
	}
	return (rt.stack);
}

struct stacks	check_move(char *move_str, t_stack_gen st)
{
	if (move_str[0] == 'p')
		st = push_checker(move_str, st);
	if (move_str[0] == 's')
		st = swap_checker(move_str, st);
	if (move_str[0] == 'r')
	{
		if (ft_strlen(move_str) > 3 && move_str[1] == 'r')
			st = reverse_checker(move_str, st);
		else
			st = rotate_checker(move_str, st);
	}
	free(move_str);
	return (st);
}

struct stacks	init_stack(char **argv)
{
	t_stack_gen	st;

	st.mvs = 0;
	st.error = 0;
	st.alen = 0;
	st.blen = 0;
	st.a = to_stack(argv, &st);
	st.clen = st.alen;
	return (st);
}

int	check_if_error(char *str)
{
	if (str == NULL)
		return (0);
	if (str[0] == 'E' && str[1] == 'r' && str[2] == 'r' && str[3] == 'o'
		&& str[4] == 'r' && str[5] == '\n')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_gen	st;

	if (argc == 1)
		return (0);
	st = init_stack(argv);
	if (st.error != 0)
		return (print_error());
	st.str = get_next_line(STDIN_FILENO);
	if (st.str == NULL)
		return (ok_or_ko(st, 0));
	if (check_if_error(st.str) == 0)
	{
		free(st.str);
		return (print_error());
	}
	while (st.str != 0)
	{
		st = check_move(st.str, st);
		if (st.error != 0)
			return (print_error());
		st.str = get_next_line(STDIN_FILENO);
	}
	ok_or_ko(st, 1);
	st = free_management(st, st.str);
	return (0);
}
