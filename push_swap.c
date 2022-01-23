/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:23:34 by omartine          #+#    #+#             */
/*   Updated: 2022/01/21 19:25:02 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks -q a.out");
}

int	*to_stack(char **argv, t_stack_gen *st)
{
	int	*stack;
	int	j;
	int	z;
	int	*to_add;

	j = 1;
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
	return (stack);
}

void	print_stack(t_stack_gen st)
{
	int	i;

	i = 0;
	printf("\n\n\n");
	while (i < st.alen)
	{
		printf("<%d>", st.a[i]);
		i++;
	}
	printf("%d", st.mvs);
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
		//printf("%d", st.error);
		st = free_management(st);
		return (print_error());
	}
	//print_stack(st);
	st = free_management(st);
	//atexit(leaks);
	return (0);
}
