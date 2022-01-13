/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:23:20 by omartine          #+#    #+#             */
/*   Updated: 2022/01/13 18:01:27 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct stacks	sort_100(stack_gen st)
{
	int	i;
	int	flg;
	int	aux;

	aux = 0;
	i = 0;
	flg = 0;
	st.error = 0;
	while (flg != st.alen - 1)
	{
		flg = 0;
		i = 0;
		while (i != st.alen - 1)
		{
			if (st.c[i] >= st.c[i + 1])
			{
				if (st.c[i] == st.c[i + 1])
				{
					st.error = 1;
					return (st);
				}
				aux = st.c[i];
				st.c[i] = st.c[i + 1];
				st.c[i + 1] = aux;
			}
			else
				flg++;
			i++;
		}
	}
	return (st);
}

struct stacks	asign_c(stack_gen st)
{
	int	i;

	i = 0;
	st.clen = st.alen;
	st.c = (int *) malloc(sizeof(int) * st.alen);
	if (!st.c)
	{
		st.error = 3;
		return (st);
	}
	while (i < st.alen)
	{
		st.c[i] = st.a[i];
		i++;
	}
	st = sort_100(st);
	return (st);
}

int	check_if_lower_than_middle(stack_gen st, int middle)
{
	int	i;

	i = 0;
	while (i < st.alen)
	{
		if (st.a[i] <= middle)
			return (1);
		i++;
	}
	return (0);
}

struct stacks	push_all_b(stack_gen st)
{
	int	aux;
	int	middle;

	/*if (check_if_a_ordered(st) == 0)
	{
		st.error = 10;
		return (st);
	}*/
	if (st.alen % 2 == 0)
		aux = (st.clen / 2) - 1;
	else
		aux = st.clen / 2;
	middle = st.c[aux];
	while (st.alen != 2)
	{
		while (check_if_lower_than_middle(st, middle) != 0 && st.alen != 2)
		{
			printf("middle = %d\n", middle);
			if (st.a[0] <= middle)
				st = push_b(st);
			else
				st = rotate_a(st);
			if (check_if_a_ordered(st) == 0)
				return (st);
		}
		if (st.alen % 2 == 0)
			aux += (st.alen / 2) - 1;
		else
			aux += st.alen / 2;
		middle = st.c[aux];
	}
	if (st.a[0] > st.a[1])
		st = swap_a(st);
	return (st);
}

int	search_num_in_b(stack_gen st, int num_to_push)
{
	int	i;

	i = 0;
	while (st.b[i] != num_to_push)
		i++;
	return (i);
}

struct stacks	push_all_a(stack_gen st)
{
	int	i;
	int	num_to_push;

	i = (st.clen - 1) - st.alen;
	//printf("||||%d||||", i);
	//printf("&%d&", st.error);
	if (i < 0)
		return (st);
	while (st.blen > 2)
	{
		num_to_push = st.c[i];
		if (search_num_in_b(st, num_to_push) > st.blen / 2)
		{
			while (st.b[0] != num_to_push)
					st = reverse_b(st);
		}
		else
		{
			while (st.b[0] != num_to_push)
			{
				if (st.b[1] == num_to_push)
					st = swap_b(st);
				else
					st = rotate_b(st);
			}
		}
		st = push_a(st);
		i--;
	}
	if (st.b[0] < st.b[1] && st.blen == 2)
		st = swap_b(st);
	while (st.blen != 0)
		st = push_a(st);
	return (st);
}

int	check_if_a_ordered(stack_gen st)
{
	int	i;

	i = 0;
	while (i + 1 < st.alen)
	{
		if (st.a[i] < st.a[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

struct stacks	sort_3(stack_gen st)
{
	int	i;

	i = 0;
	if (check_if_a_ordered(st) == 0)
		return (st);
	if (st.alen == 2)
	{
		if (st.a[0] > st.a[1])
			st = swap_a(st);
		return (st);
	}
	while (st.a[2] != st.c[2])
		st = rotate_a(st);
	if (st.a[0] > st.a[1])
		st = swap_a(st);
	return (st);
}

struct stacks	sort_manager(stack_gen st)
{
	int	i;

	i = 0;
	st = asign_c(st);
	if (st.error != 0)
		return (st);
	if (st.alen <= 3)
	{
		st = sort_3(st);
		return (st);
	}
	else if (st.alen <= 600)
	{
		st = push_all_b(st);
		st = push_all_a(st);
	}
	if (st.error != 0)
		return (st);
	while (i < st.alen)
	{
		printf("<%d>", st.a[i]);
		i++;
	}
	printf("---");
	i = 0;
	while (i < st.blen)
	{
		printf("<%d>", st.b[i]);
		i++;
	}
	return (st);
}
