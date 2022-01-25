/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_be_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:16:36 by omartine          #+#    #+#             */
/*   Updated: 2022/01/25 17:32:49 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	leaks(void)
{
	system("leaks -q a.out");
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
