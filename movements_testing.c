/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:44:02 by omartine          #+#    #+#             */
/*   Updated: 2022/01/17 17:44:29 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct stacks	swap_a(stack_gen st)
{
	int	aux;
	int	i;

	if (st.alen == 0 || st.alen == 1)
		return (st);
	aux = st.a[0];
	st.a[0] = st.a[1];
	st.a[1] = aux;
	st.mvs++;
	printf("sa ");
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

struct stacks	swap_b(stack_gen st)
{
	int	aux;
	int	i;

	if (st.blen == 0 || st.blen == 1)
		return (st);
	aux = st.b[0];
	st.b[0] = st.b[1];
	st.b[1] = aux;
	st.mvs++;
	printf("sb ");
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

struct stacks	swap_ab(stack_gen st)
{
	st = swap_a(st);
	st = swap_b(st);
	st.mvs++;
	return (st);
}

struct stacks	push_a(stack_gen st)
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

struct stacks	push_b(stack_gen st)
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

struct stacks	rotate_a(stack_gen st)
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
	printf("ra ");
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

struct stacks	rotate_b(stack_gen st)
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
	printf("rb ");
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

struct stacks	rotate_ab(stack_gen st)
{
	st = rotate_a(st);
	st = rotate_b(st);
	st.mvs++;
	//printf("rr\n");
	return (st);
}

struct stacks	reverse_a(stack_gen st)
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
	printf("rra ");
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

struct stacks	reverse_b(stack_gen st)
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
	printf("rrb ");
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

struct stacks	reverse_ab(stack_gen st)
{
	st = reverse_a(st);
	st = reverse_b(st);
	st.mvs++;
	return (st);
}
