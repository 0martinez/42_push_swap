/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_be_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:16:36 by omartine          #+#    #+#             */
/*   Updated: 2022/01/24 12:36:44 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

struct stacks	free_management(t_stack_gen st)
{
	if (st.error == 1)
		return (st);
	if (st.error == 2 || st.error == 3)
		free(st.a);
	else
	{
		free(st.a);
		free(st.c);
	}
	return (st);
}
