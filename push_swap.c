/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:23:34 by omartine          #+#    #+#             */
/*   Updated: 2022/02/11 13:39:20 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		while (argv[j] && argv[j][0] == 0)
			j++;
		if (!argv[j])
			break ;
		z = 0;
		if (argv[j][0] != 0)
			flg++;
		to_add = split_atoi(argv[j], st, &z);
		if (st->error != 0 || !to_add)
			return (0);
		stack = add_to_stack(to_add, stack, z, st);
		if (to_add)
			free(to_add);
		if (st->error != 0)
			return (0);
		j++;
	}
	if (flg == 0)
		st->error = 1;
	return (stack);
}

struct stacks	init_stack(void)
{
	t_stack_gen	st;

	st.mvs = 0;
	st.error = 0;
	st.alen = 0;
	st.blen = 0;
	return (st);
}

void	leaks(void)
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	t_stack_gen	st;

	//atexit(leaks);
	st = init_stack();
	if (argc == 1)
		return (0);
	st.a = to_stack(argv, &st);
	if (st.error != 0)
	{
		st = free_management(st);
		return (print_error());
	}
	st = sort_management(st);
	if (st.error != 0 && st.error != 10 && st.error != 100)
	{
		st = free_management(st);
		return (print_error());
	}
	st = free_management(st);
	return (0);
}
