/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:20:48 by omartine          #+#    #+#             */
/*   Updated: 2022/01/21 19:19:53 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

struct stacks	reverse_a(t_stack_gen st)
{
	int	aux;
	int	i;

	if (st.alen == 0 || st.alen == 1)
		return (st);
	i = st.alen - 1;
	aux = st.a[st.alen - 1];
	while (i > 0)
	{
		st.a[i] = st.a[i - 1];
		i--;
	}
	st.a[0] = aux;
	st.mvs++;
	write(1, "rra\n", 4);
	return (st);
}

struct stacks	reverse_b(t_stack_gen st)
{
	int	aux;
	int	i;

	if (st.blen == 0 || st.blen == 1)
		return (st);
	i = st.blen - 1;
	aux = st.b[st.blen - 1];
	while (i > 0)
	{
		st.b[i] = st.b[i - 1];
		i--;
	}
	st.b[0] = aux;
	st.mvs++;
	write(1, "rrb\n", 4);
	return (st);
}

struct stacks	reverse_ab(t_stack_gen st)
{
	st = reverse_a(st);
	st = reverse_b(st);
	st.mvs++;
	write(1, "rrr\n", 3);
	return (st);
}
