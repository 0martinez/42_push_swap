/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   500_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:49:11 by omartine          #+#    #+#             */
/*   Updated: 2022/01/24 12:36:19 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus.h"

struct	stacks	no_negative_numbers(t_stack_gen st)
{
	int	i;
	int	j;

	i = 0;
	while (i < st.alen)
	{
		j = 0;
		while (st.a[i] != st.c[j])
			j++;
		st.a[i] = j;
		i++;
	}
	return (st);
}

int	b_reference_length(t_stack_gen st)
{
	int	i;

	i = 0;
	while ((st.c[st.clen - 1] >> i) != 0)
		i++;
	return (i);
}

struct stacks	reasign_values(t_stack_gen st)
{
	int	i;

	i = 0;
	while (i < st.clen)
	{
		st.a[i] = st.c[st.a[i]];
		i++;
	}
	return (st);
}

struct stacks	binary_operation(t_stack_gen st)
{
	int	i;
	int	movements;
	int	reference_length;

	i = 0;
	reference_length = b_reference_length(st);
	while (i < reference_length)
	{
		movements = 0;
		while (movements < st.clen)
		{
			if (((st.a[0] >> i) & 1) == 0)
				st = push_b(st);
			else
				st = rotate_a(st);
			movements++;
		}
		while (st.blen != 0)
			st = push_a(st);
		i++;
	}
	return (st);
}

struct stacks	sort_500(t_stack_gen st)
{
	int	i;

	i = 0;
	if (check_if_a_ordered(st) == 0)
	{
		st.error = 10;
		return (st);
	}
	st = no_negative_numbers(st);
	st = binary_operation(st);
	st = reasign_values(st);
	return (st);
}
