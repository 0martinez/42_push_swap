/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:17:35 by omartine          #+#    #+#             */
/*   Updated: 2022/01/19 17:14:55 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

struct stacks	push_a(t_stack_gen st)
{
	int	i;
	int	j;
	int	*new_a;
	int	*new_b;

	i = 1;
	j = 0;
	if (st.blen == 0)
		return (st);
	st.blen--;
	st.alen++;
	new_b = malloc(sizeof(int) * st.blen);
	new_a = malloc(sizeof(int) * st.alen);
	if (!new_a || !new_b)
	{
		st.error = 4;
		return (st);
	}
	new_a[0] = st.b[0];
	while (j < st.blen)
	{
		new_b[j] = st.b[i];
		i++;
		j++;
	}
	free(st.b);
	st.b = new_b;
	i = 1;
	j = 0;
	while (i < st.alen)
	{
		new_a[i] = st.a[j];
		i++;
		j++;
	}
	free(st.a);
	st.a = new_a;
	st.mvs++;
	printf("pa ");
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
	printf("\n");
	return (st);
}

struct stacks	push_b(t_stack_gen st)
{
	int	i;
	int	j;
	int	*new_a;
	int	*new_b;

	i = 1;
	j = 0;
	if (st.alen == 0)
		return (st);
	st.alen--;
	st.blen++;
	new_b = malloc(sizeof(int) * st.blen);
	new_a = malloc(sizeof(int) * st.alen);
	if (!new_a || !new_b)
	{
		st.error = 4;
		return (st);
	}
	new_b[0] = st.a[0];
	while (j < st.alen)
	{
		new_a[j] = st.a[i];
		i++;
		j++;
	}
	free(st.a);
	st.a = new_a;
	i = 1;
	j = 0;
	while (i < st.blen)
	{
		new_b[i] = st.b[j];
		i++;
		j++;
	}
	if (st.blen == 1)
		st.b = new_b;
	else
	{
		free(st.b);
		st.b = new_b;
	}
	st.b = new_b;
	st.mvs++;
	printf("pb ");
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
	printf("\n");
	return (st);
}
