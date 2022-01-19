/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:23:34 by omartine          #+#    #+#             */
/*   Updated: 2022/01/19 17:13:29 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void	leaks(void)
{
	system("leaks -q a.out");
}

int	ft_atoi(const char *str, t_stack_gen *st)
{
	int		simb;
	long	num;
	int		i;

	i = 0;
	num = 0;
	simb = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			simb = -1;
		i++;
		if (str[i] == 0)
		{
			st->error = 2;
			return (0);
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num = simb * num;
	if (str[i] != 0 || num > 2147483647 || num < -2147483648)
	{
		st->error = 2;
		return (0);
	}
	return ((int )num);
}

static int	*to_stack(int argc, char **argv, t_stack_gen *st)
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
	while (i < argc - 1)
	{
		stack[i] = ft_atoi(argv[j], st);
		if (st->error == 2)
			return (0);
		i++;
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

struct stacks	init_stack(int argc)
{
	t_stack_gen	st;

	st.mvs = 0;
	st.error = 0;
	st.alen = argc - 1;
	st.blen = 0;
	return (st);
}

int	main(int argc, char **argv)
{
	t_stack_gen	st;

	st = init_stack(argc);
	if (argc == 1)
		return (print_error());
	st.a = to_stack(argc, argv, &st);
	if (st.error != 0)
	{
		st = free_management(st);
		return (print_error());
	}
	st = sort_management(st);
	if (st.error != 0 && st.error != 10 && st.error != 100)
	{
		printf("%d", st.error);
		st = free_management(st);
		return (print_error());
	}
	print_stack(st);
	st = free_management(st);
	atexit(leaks);
	return (0);
}
