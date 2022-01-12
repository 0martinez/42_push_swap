/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:23:28 by omartine          #+#    #+#             */
/*   Updated: 2022/01/12 12:50:38 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct stacks
{
	int	*a;
	int	*b;
	int	*c;
	int	alen;
	int	blen;
	int	clen;

	int	its_ord;
	int	mvs;
	int	error;

}	stack_gen;

int atoi_checker;

struct stacks	swap_a(stack_gen st);

struct stacks	swap_b(stack_gen st);

struct stacks	swap_ab(stack_gen st);

struct stacks	push_a(stack_gen st);

struct stacks	push_b(stack_gen st);

struct stacks	rotate_a(stack_gen st);

struct stacks	rotate_b(stack_gen st);

struct stacks	rotate_ab(stack_gen st);

struct stacks	reverse_a(stack_gen st);

struct stacks	reverse_b(stack_gen st);

struct stacks	reverse_ab(stack_gen st);

struct stacks	swaps(stack_gen st);

struct stacks	final_or(stack_gen st);

int				position_b(stack_gen st);

struct stacks	first_check_b(stack_gen st);

struct stacks	new_sort(stack_gen st);

struct stacks	sort_100(stack_gen st);

struct stacks	sort_manager(stack_gen st);

#endif
