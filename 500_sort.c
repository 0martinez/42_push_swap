/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   500_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:35:00 by omartine          #+#    #+#             */
/*   Updated: 2022/01/17 19:03:18 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct stacks	to_binary(stack_gen st)
{
	int		i;
	int		binary;
	int		div;

	i = 0;
	while (i < st.alen)
	{
		div = st.binary_int[i];
		binary = 0;
		while (div != 0)
		{
			binary = (binary * 10) + (div % 2);
			div = div / 2;
		}
		st.binary_int[i] = binary;
		i++;
	}
	return (st);
}

struct stacks	no_negative_asignament(stack_gen st)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	st.binary_int = (int *) malloc(sizeof(int) * st.alen);
	if (!st.binary_int)
	{
		st.error = 1000;
		return (st);
	}
	while (i < st.alen)
	{
		j = 0;
		while (st.c[j] != st.a[i])
			j++;
		st.binary_int[i] = j;
		i++;
	}
	return (st);
}

static int	length_itoa(int n)
{
	int			len;
	long int	n2;

	n2 = (long) n;
	len = 0;
	while (n2 > 0)
	{
		n2 = n2 / 10;
		len++;
	}
	if (n == 0)
		len = 1;
	return (len);
}

char	*ft_itoa(long n)
{
	char	*num;
	int		len;

	len = length_itoa(n);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = 0;
	if (n == 0)
		num[0] = '0';
	while (n > 0)
	{
		num[len - 1] = 48 + (n % 10);
		n = n / 10;
		len--;
	}
	return (num);
}

struct stacks	add_left(stack_gen st, int biggest_length)
{
	int		i;
	char	*aux;
	int		j;
	int		save_len;

	i = 0;
	while (i < st.clen)
	{
		save_len = length_itoa(st.binary_int[i]);
		if (save_len < biggest_length)
		{
			j = biggest_length;
			aux = (char *) malloc (sizeof(char) * j + 1);
			if (!aux)
				return (st);
			aux[j] = 0;
			while (j >= 0)
			{
				if (save_len >= 0)
					aux[j] = st.binary_char[i][save_len];
				else
					aux[j] = '0';
				j--;
				save_len--;
			}
			free(st.binary_char[i]);
			st.binary_char[i] = aux;
			free(aux);
		}
		i++;
	}
	return (st);
}

struct stacks	binary_to_char(stack_gen st)
{
	int	i;
	int	biggest_length;

	i = 0;
	st.binary_char = (char **) malloc(sizeof(char *) * st.clen + 1);
	if (!st.binary_char)
		return (st);
	st.binary_char[st.clen] = 0;
	biggest_length = 0;
	while (i < st.clen)
	{
		st.binary_char[i] = ft_itoa(st.binary_int[i]);
		if (!st.binary_char)
			return (st);
		if (length_itoa(st.binary_int[i]) > biggest_length)
			biggest_length = length_itoa(st.binary_int[i]);
		i++;
	}
	st = add_left(st, biggest_length);
	st.biggest_length = biggest_length;
	return (st);
}

struct stacks	reasignament(stack_gen st)
{
	int	i;

	i = 0;
	while (i < st.alen)
	{
		free(st.binary_char[i]);
		i++;
	}
	free(st.binary_int);
	//free(st.binary_char);
	st = to_binary(st);
	st = binary_to_char(st);
	return (st);
}

struct stacks	big_stack_sort(stack_gen st)
{
	int	i;
	int	aux;

	while (st.biggest_length >= 0)
	{
		i = 0;
		while (i < st.clen)
		{
			if (st.binary_char[i][st.biggest_length] == 0)
				st = push_b(st);
			else
				st = rotate_a(st);
			i++;
		}
		st.biggest_length--;
		while (st.blen > 0)
			st = push_a(st);
		st = reasignament(st);
	}
	return (st);
}

struct stacks	big_stack_management(stack_gen st)
{
	int	i;

	i = 0;
	st = no_negative_asignament(st);
	if (st.error != 0)
		return (st);
	st = to_binary(st);
	printf("\n\n\n\n");
	while (i < st.alen)
	{
		printf("%d\n", st.binary_int[i]);
		i++;
	}
	//st = binary_to_char(st);

	//st = big_stack_sort(st);
	return (st);
}
