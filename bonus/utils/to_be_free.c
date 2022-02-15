/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_be_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:16:36 by omartine          #+#    #+#             */
/*   Updated: 2022/02/15 19:31:48 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus.h"

void	leaks(void)
{
	system("leaks -q checker_omartine");
}

int	*first_split_error(char **str, int num_of_words, t_stack_gen *st)
{
	if (!str)
		free_split(str, num_of_words);
	st->error = 2;
	return (0);
}

int	*second_split_error(char **str, int num_words, int *stack)
{
	free(stack);
	free_split(str, num_words);
	return (0);
}

struct stacks	free_management(t_stack_gen st, char *str)
{
	if (st.error == 1)
		return (st);
	if (st.error == 2 || st.error == 3)
		free(st.a);
	else
	{
		free(st.a);
		free(str);
		if (st.blen != 0)
			free(st.b);
	}
	return (st);
}
