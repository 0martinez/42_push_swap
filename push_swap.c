/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:23:34 by omartine          #+#    #+#             */
/*   Updated: 2022/01/13 18:36:19 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checker(int argc)
{
	if (argc == 1)
		return (0);
	return (1);
}

static int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void	leaks(void)
{
	system("leaks -q a.out");
}

int	ft_atoi(const char *str, stack_gen *st)
{
	int				simb;
	unsigned long	num;
	int				i;

	i = 0;
	num = 0;
	simb = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			simb = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num = simb * num;
	if (str[i] != 0 || num > 2147483647 || num < 0)
	{
		st->error = 2;
		return (0);
	}
	return ((int )num);
}

static int	*to_stack(int argc, char **argv, stack_gen *st)
{
	int	*stack;
	int	i;
	int	j;

	i = 0;
	j = 1;
	stack = (int *) malloc(sizeof(int) * argc);
	if (!stack)
	{
		st->error = 1;
		return (0);
	}
	stack[argc] = 0;
	while (i < argc - 1)
	{
		stack[i] = ft_atoi(argv[j], st);
		if (st->error == 2)
			return (0);
		//printf("%d ", stack[i]);
		i++;
		j++;
	}
	return (stack);
}

void	print_stack(stack_gen st)
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

struct stacks	init_stack(int argc)
{
	stack_gen	st;

	st.mvs = 0;
	st.error = 0;
	st.alen = argc - 1;
	st.blen = 0;
	st.pos_if_ordered = 2;
	return (st);
}

int	main(int argc, char **argv)
{
	stack_gen	st;

	st = init_stack(argc);
	if (checker(argc) == 0)
		return (print_error());
	st.a = to_stack(argc, argv, &st);
	if (st.error != 0)
	{
		st = free_management(st);
		return (print_error());
	}
	st = sort_manager(st);
	if (st.error != 0 && st.error != 10)
	{
		st = free_management(st);
		return (print_error());
	}
	print_stack(st);
	st = free_management(st);
	//atexit(leaks);
	return (0);
}
