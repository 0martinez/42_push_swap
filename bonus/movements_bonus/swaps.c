/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:15:14 by omartine          #+#    #+#             */
/*   Updated: 2022/01/24 17:11:01 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus.h"

struct stacks	swap_a(t_stack_gen st)
{
	int	aux;

	if (st.alen == 0 || st.alen == 1)
		return (st);
	aux = st.a[0];
	st.a[0] = st.a[1];
	st.a[1] = aux;
	st.mvs++;
	return (st);
}

struct stacks	swap_b(t_stack_gen st)
{
	int	aux;

	if (st.blen == 0 || st.blen == 1)
		return (st);
	aux = st.b[0];
	st.b[0] = st.b[1];
	st.b[1] = aux;
	st.mvs++;
	return (st);
}

struct stacks	swap_ab(t_stack_gen st)
{
	st = swap_a(st);
	st = swap_b(st);
	st.mvs++;
	return (st);
}
