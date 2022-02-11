/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:16:14 by omartine          #+#    #+#             */
/*   Updated: 2022/02/11 14:02:00 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	*to_stack(char **argv, t_stack_gen *st)
{
	int	*stack;
	int	j;
	int	z;
	int	*to_add;
	int	flg;

	j = 1;
	flg = 0;
	while (argv[j])
	{
		z = 0;
		to_add = split_atoi(argv[j], st, &z);
		if (st->error != 0 || !to_add)
			return (0);
		stack = add_to_stack(to_add, stack, z, st);
		free(to_add);
		if (st->error != 0)
			return (0);
		j++;
	}
	if (flg == 0)
		st->error = 1;
	return (stack);
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
	char		*str;

	atexit(leaks);
	if (argc == 1)
		return (0);
	st = init_stack(argv);
	if (st.error != 0)
		return (print_error());
	str = get_next_line(STDIN_FILENO);
	if (str == NULL)
		return (ok_or_ko(st, 0));
	if (check_if_error(str) == 0)
		return (print_error());
	while (str != 0)
	{
		st = check_move(str, st);
		free(str);
		if (st.error != 0)
			return (print_error());
		str = get_next_line(STDIN_FILENO);
	}
	ok_or_ko(st, 1);
	st = free_management(st, str);
	return (0);
}
