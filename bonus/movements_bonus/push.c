/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:17:35 by omartine          #+#    #+#             */
/*   Updated: 2022/01/25 18:42:05 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus.h"

static struct stacks	push_a_asign_ab(t_stack_gen st, int *new_b, int *new_a)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (st.blen != 0)
	{
		while (j < st.blen)
		{
			new_b[j] = st.b[i];
			i++;
			j++;
		}
		free(st.b);
		st.b = new_b;
	}
	else
		free(st.b);
	i = 1;
	j = 0;
	while (i < st.alen)
		new_a[i++] = st.a[j++];
	free(st.a);
	st.a = new_a;
	return (st);
}

struct stacks	push_a(t_stack_gen st)
{
	int	*new_a;
	int	*new_b;

	if (st.blen == 0)
		return (st);
	st.blen--;
	st.alen++;
	if (st.blen != 0)
		new_b = malloc(sizeof(int) * st.blen);
	new_a = malloc(sizeof(int) * st.alen);
	if (!new_a)
	{
		st.error = 4;
		return (st);
	}
	new_a[0] = st.b[0];
	st = push_a_asign_ab(st, new_b, new_a);
	st.mvs++;
	return (st);
}

struct stacks	push_b_asign_ab(t_stack_gen st, int *new_b, int *new_a)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j < st.alen)
		new_a[j++] = st.a[i++];
	free(st.a);
	st.a = new_a;
	i = 1;
	j = 0;
	while (i < st.blen)
		new_b[i++] = st.b[j++];
	if (st.blen == 1)
		st.b = new_b;
	else
	{
		free(st.b);
		st.b = new_b;
	}
	st.b = new_b;
	return (st);
}

struct stacks	push_b(t_stack_gen st)
{
	int	*new_a;
	int	*new_b;

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
	st = push_b_asign_ab(st, new_b, new_a);
	st.mvs++;
	return (st);
}
