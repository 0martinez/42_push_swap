/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:22:16 by omartine          #+#    #+#             */
/*   Updated: 2022/01/25 17:22:32 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	ft_atoi(const char *str, t_stack_gen *st)
{
	int		simb;
	long	num;
	int		i;

	i = 0;
	num = 0;
	simb = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			simb = -1;
		i++;
		if (str[i] == 0)
		{
			st->error = 2;
			return (0);
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	if (str[i] != 0 || num * simb > 2147483647 || num * simb < -2147483648)
		st->error = 2;
	return ((int )num * simb);
}

int	*split_atoi(const char *s, t_stack_gen *st, int *z)
{
	int		i;
	int		*new_stack;
	int		num_of_words;
	char	**str;

	i = 0;
	num_of_words = wordcount(s, 0, 0, ' ');
	str = ft_split(s, ' ');
	if (!str || num_of_words == 0)
	{
		st->error = 2;
		return (0);
	}
	new_stack = malloc(sizeof(int) * num_of_words);
	while (i < num_of_words)
	{
		new_stack[i] = ft_atoi(str[i], st);
		if (st->error != 0)
			return (0);
		i++;
	}
	st->alen += num_of_words;
	*z = num_of_words;
	free_split(str, num_of_words);
	return (new_stack);
}

int	*add_to_stack(int *to_add, int *old_stack, int add_length, t_stack_gen *st)
{
	int	i;
	int	j;
	int	*new_stack;

	i = 0;
	j = 0;
	new_stack = malloc(sizeof(int) * st->alen);
	if (!new_stack)
	{
		st->error = 2;
		return (0);
	}
	while (i < st->alen - add_length)
	{
		new_stack[i] = old_stack[i];
		i++;
	}
	while (i < st->alen)
		new_stack[i++] = to_add[j++];
	if (st->alen - add_length != 0)
		free(old_stack);
	return (new_stack);
}
