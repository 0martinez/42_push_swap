/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:44:50 by omartine          #+#    #+#             */
/*   Updated: 2022/01/25 17:49:46 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static struct stacks	bubble_sort_aux(t_stack_gen st, int i)
{
	int	aux;

	if (st.c[i] == st.c[i + 1])
	{
		st.error = 1;
		return (st);
	}
	aux = st.c[i];
	st.c[i] = st.c[i + 1];
	st.c[i + 1] = aux;
	return (st);
}

struct stacks	bubble_sort(t_stack_gen st)
{
	int	i;
	int	flg;

	flg = 0;
	while (flg != st.alen - 1)
	{
		flg = 0;
		i = 0;
		while (i != st.alen - 1)
		{
			if (st.c[i] >= st.c[i + 1])
			{
				st = bubble_sort_aux(st, i);
				if (st.error != 0)
					return (st);
			}
			else
				flg++;
			i++;
		}
	}
	return (st);
}

int	check_if_a_ordered(t_stack_gen st)
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

int	check_if_lower_than_middle(t_stack_gen st, int middle)
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

int	search_num_in_b(t_stack_gen st, int num_to_push)
{
	int	i;

	i = 0;
	while (st.b[i] != num_to_push)
		i++;
	return (i);
}
