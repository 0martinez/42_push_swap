/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:48:52 by omartine          #+#    #+#             */
/*   Updated: 2022/01/19 17:32:13 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

struct stacks	sort_3(t_stack_gen st)
{
	int	i;

	i = 0;
	if (check_if_a_ordered(st) == 0)
	{
		st.error = 10;
		return (st);
	}
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
	st.error = 100;
	return (st);
}
