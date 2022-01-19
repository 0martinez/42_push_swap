/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:23:28 by omartine          #+#    #+#             */
/*   Updated: 2022/01/19 17:13:05 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct stacks
{
	int		*a;
	int		*b;
	int		*c;
	int		alen;
	int		blen;
	int		clen;

	int		biggest_length;
	int		mvs;
	int		error;

}	t_stack_gen;

struct stacks	swap_a(t_stack_gen st);
struct stacks	swap_b(t_stack_gen st);
struct stacks	swap_ab(t_stack_gen st);
struct stacks	push_a(t_stack_gen st);
struct stacks	push_b(t_stack_gen st);
struct stacks	rotate_a(t_stack_gen st);
struct stacks	rotate_b(t_stack_gen st);
struct stacks	rotate_ab(t_stack_gen st);
struct stacks	reverse_a(t_stack_gen st);
struct stacks	reverse_b(t_stack_gen st);
struct stacks	reverse_ab(t_stack_gen st);

struct stacks	sort_management(t_stack_gen st);

struct stacks	sort_3(t_stack_gen st);
struct stacks	sort_100(t_stack_gen st);
struct	stacks	sort_500(t_stack_gen st);

struct stacks	bubble_sort(t_stack_gen st);
int				check_if_a_ordered(t_stack_gen st);
int				check_if_lower_than_middle(t_stack_gen st, int middle);
int				search_num_in_b(t_stack_gen st, int num_to_push);

struct stacks	free_management(t_stack_gen st);

#endif
