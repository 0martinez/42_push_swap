/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:49:38 by omartine          #+#    #+#             */
/*   Updated: 2022/01/25 17:55:02 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

struct stacks	push_all_b(t_stack_gen st)
{
	int	aux;
	int	middle;

	aux = 0;
	while (st.alen != 2)
	{
		if (st.alen % 2 == 0)
			aux += (st.alen / 2) - 1;
		else
			aux += st.alen / 2;
		middle = st.c[aux];
		while (check_if_lower_than_middle(st, middle) != 0 && st.alen != 2)
		{
			if (st.a[0] <= middle)
				st = push_b(st);
			else
				st = rotate_a(st);
			if ((check_if_a_ordered(st) == 0)
				&& (check_if_lower_than_middle(st, middle) == 0))
				return (st);
		}
	}
	if (st.a[0] > st.a[1])
		st = swap_a(st);
	return (st);
}

struct stacks	push_all_a_aux(t_stack_gen st, int i)
{
	int	num_to_push;

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
	return (st);
}

struct stacks	push_all_a(t_stack_gen st)
{
	int	i;

	i = (st.clen - st.alen) - 1;
	if (check_if_a_ordered(st) == 0 && st.error == 10)
		return (st);
	if (i < 0)
		return (st);
	while (st.blen > 2)
	{
		st = push_all_a_aux(st, i);
		i--;
	}
	if (st.b[0] < st.b[1] && st.blen == 2)
		st = swap_b(st);
	while (st.blen != 0)
		st = push_a(st);
	return (st);
}

struct stacks	sort_100(t_stack_gen st)
{
	st = push_all_b(st);
	st = push_all_a(st);
	return (st);
}
