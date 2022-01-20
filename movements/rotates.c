/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:19:07 by omartine          #+#    #+#             */
/*   Updated: 2022/01/20 16:33:47 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

struct stacks	rotate_a(t_stack_gen st)
{
	int	aux;
	int	i;

	i = 0;
	aux = st.a[0];
	while (i < st.alen - 1)
	{
		st.a[i] = st.a[i + 1];
		i++;
	}
	st.a[i] = aux;
	st.mvs++;
	/*printf("ra ");
	i = 0;
	while (i < st.alen)
	{
		printf("<%d>", st.a[i]);
		i++;
	}
	i = 0;
	printf("---");
	while (i < st.blen)
	{
		printf("(%d)", st.b[i]);
		i++;
	}
	printf("\n");*/
	return (st);
}

struct stacks	rotate_b(t_stack_gen st)
{
	int	aux;
	int	i;

	i = 0;
	if (st.blen == 0 || st.blen == 1 || st.blen == 2)
		return (st);
	aux = st.b[0];
	while (i < st.blen - 1)
	{
		st.b[i] = st.b[i + 1];
		i++;
	}
	st.b[i] = aux;
	st.mvs++;
	/*printf("rb ");
	i = 0;
	while (i < st.alen)
	{
		printf("<%d>", st.a[i]);
		i++;
	}
	i = 0;
	printf("---");
	while (i < st.blen)
	{
		printf("(%d)", st.b[i]);
		i++;
	}
	printf("\n");*/
	return (st);
}

struct stacks	rotate_ab(t_stack_gen st)
{
	st = rotate_a(st);
	st = rotate_b(st);
	st.mvs++;
	return (st);
}
