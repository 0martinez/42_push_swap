/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:23:34 by omartine          #+#    #+#             */
/*   Updated: 2022/02/15 17:58:22 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*free_stack(int *to_add)
{
	if (to_add)
		free(to_add);
	return (0);
}

int	*to_stack(char **argv, t_stack_gen *st)
{
	t_to_stack	rt;

	rt.j = 1;
	rt.flg = 0;
	while (argv[rt.j])
	{
		while (argv[rt.j] && argv[rt.j][0] == 0)
			rt.j++;
		if (!argv[rt.j])
			break ;
		rt.z = 0;
		if (argv[rt.j][0] != 0)
			rt.flg++;
		rt.to_add = split_atoi(argv[rt.j], st, &rt.z);
		if (st->error != 0 || !rt.to_add)
			return (free_stack(rt.to_add));
		rt.stack = add_to_stack(rt.to_add, rt.stack, rt.z, st);
		free(rt.to_add);
		if (st->error != 0)
			return (0);
		rt.j++;
	}
	if (rt.flg == 0)
		st->error = 1;
	return (rt.stack);
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
