/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_doble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:27:29 by omartine          #+#    #+#             */
/*   Updated: 2022/02/16 15:34:46 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus.h"

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

struct stacks	asign_c(t_stack_gen st)
{
	int	i;

	i = 0;
	st.clen = st.alen;
	st.c = (int *) malloc(sizeof(int) * st.alen);
	if (!st.c)
	{
		st.error = 2;
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

int	*check_if_dobled(t_stack_gen st)
{
	st.c = asign_c(st);
	return (st.c);
}
