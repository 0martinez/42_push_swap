/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:23:20 by omartine          #+#    #+#             */
/*   Updated: 2022/01/10 18:22:22 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_ordered_reference(stack_gen st, int x)
{
	int	i;
	int	flg;
	int	aux;

	i = 0;
	flg = 0;
	if (x == 1)
		aux = st.alen - 1;
	else
		aux = st.reference_pos;
	while (i + 1 < aux)
	{
		if (st.a[i] < st.a[i + 1])
			flg++;
		i++;
	}
	if (flg == i)
		return (1);
	return (0);
}

struct stacks	mooves(stack_gen st)
{
	int	i;
	int	aux;
	int	j;
	int	flg = 0;

	i = st.last_reference_pos;
	j = st.reference_pos;
	while (i < st.reference_pos)
	{
		if (st.a[i] >= st.reference)
		{
			if (st.a[i] == st.reference_pos)
			{
				printf("ERRROR");
				//TO DO---> CHECK IF THERE ARE EQUALS NUMBERS, THEN PRINT ERROR
			}
			aux = st.reference;
			j = st.reference_pos - 1;
			while (j > i)
			{
				if (st.a[j] < aux)
				{
					st.a[i] = st.a[j];
					st.a[j] = aux;
					break ;
				}
				j--;
			}
			if (j == i)
			{
				aux = st.a[i];
				st.a[i] = st.a[st.reference_pos];
				st.a[st.reference_pos] = aux;
				flg++;
				break ;
			}
		}
		i++;
	}
	
	return (st);
}

struct stacks	reference_swap(stack_gen st)
{
	int	i;
	int	aux;

	i = 0;
	while (st.a[i] < st.reference)
		i++;
	aux = st.a[i];
	st.a[i] = st.a[st.reference_pos];
	st.a[st.reference_pos] = aux;
	printf("adeblas");
	return (st);
}

struct stacks	new_sort(stack_gen st)
{
	int	i;
	int	aux;

	i = 0;
	aux = 0;
	i = 0;
	st.reference_pos = st.alen - 1;
	st.reference = st.a[st.reference_pos];
	while (check_if_ordered_reference(st, 1) != 1)
	{
		while (i < st.alen)
		{
			printf("(%d)", st.a[i]);
			i++;
		}
		printf("\n\n");
		i = 0;
		if (check_if_ordered_reference(st, 0) == 1)
		{
			printf("jejeje");
			printf("-%d-", st.reference_pos);
			st.last_reference_pos = st.reference_pos;
			st.reference_pos = st.alen - 1;
			st.reference = st.a[st.reference_pos];
			printf("-%d-", st.reference_pos);
		}
		st = mooves(st);
		st = reference_swap(st);
		st.reference_pos = st.reference_pos - 1;
		st.reference_pos = st.a[st.reference_pos];
	}
	printf("----%d----", check_if_ordered_reference(st, st.alen - 1));
	return (st);
}
