/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:23:20 by omartine          #+#    #+#             */
/*   Updated: 2022/01/25 17:54:47 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

struct stacks	asign_c(t_stack_gen st)
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
	st = bubble_sort(st);
	return (st);
}

struct stacks	sort_management(t_stack_gen st)
{
	st = asign_c(st);
	if (st.error != 0)
		return (st);
	if (st.alen <= 3)
		st = sort_3(st);
	else if (st.alen <= 100)
	{
		if (check_if_a_ordered(st) == 0)
		{
			st.error = 10;
			return (st);
		}
		st = sort_100(st);
	}
	else
		st = sort_500(st);
	return (st);
}
