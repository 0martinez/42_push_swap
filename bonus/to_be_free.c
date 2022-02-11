/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_be_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:16:36 by omartine          #+#    #+#             */
/*   Updated: 2022/02/11 13:43:58 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	leaks(void)
{
	system("leaks -q checker_omartine");
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
