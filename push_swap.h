/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:23:28 by omartine          #+#    #+#             */
/*   Updated: 2022/02/10 17:19:00 by omartine         ###   ########.fr       */
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

int				print_error(void);

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

int				*split_atoi(const char *str, t_stack_gen *st, int *z);
int				ft_atoi(const char *str, t_stack_gen *st);
int				*add_to_stack(int *to_add, int *old_stack,
					int add_length, t_stack_gen *st);

char			**ft_split(char const *s, char c);
size_t			wordcount(char const *s, char c);
void			*free_split(char **aux, int words);

int				*to_stack(char **argv, t_stack_gen *st);

#endif
