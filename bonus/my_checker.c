/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:16:14 by omartine          #+#    #+#             */
/*   Updated: 2022/01/24 18:09:51 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	*to_stack(char **argv, t_stack_gen *st)
{
	int	*stack;
	int	j;
	int	z;
	int	*to_add;

	j = 1;
	while (argv[j])
	{
		z = 0;
		to_add = split_atoi(argv[j], st, &z);
		if (st->error != 0 || !to_add)
			return (0);
		stack = add_to_stack(to_add, stack, z, st);
		free(to_add);
		if (st->error != 0)
			return (0);
		j++;
	}
	return (stack);
}

/*int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}*/

struct stacks	push_checker(char *str, t_stack_gen st)
{
	if (str[1] == 'b' && str[2] == '\n')
		st = push_b(st);
	else if (str[1] == 'a' && str[2] == '\n')
		st = push_a(st);
	else
		st.error = 1;
	return (st);
}

struct stacks	swap_checker(char *str, t_stack_gen st)
{
	if (str[1] == 'a' && str[2] == '\n')
		st = swap_a(st);
	else if (str[1] == 'b' && str[2] == '\n')
		st = swap_b(st);
	else if (str[1] == 's' && str[2] == '\n')
		st = swap_ab(st);
	else
		st.error = 1;
	return (st);
}

struct stacks	rotate_checker(char *str, t_stack_gen st)
{
	if (str[1] == 'a' && str[2] == '\n')
		st = rotate_a(st);
	else if (str[1] == 'b' && str[2] == '\n')
		st = rotate_b(st);
	else if (str[1] == 'r' && str[2] == '\n')
		st = rotate_ab(st);
	else
		st.error = 1;
	return (st);
}

struct stacks	reverse_checker(char *str, t_stack_gen st)
{
	if (str[2] == 'a' && str[3] == '\n')
		st = reverse_a(st);
	else if (str[2] == 'b' && str[3] == '\n')
		st = reverse_b(st);
	else if (str[2] == 'r' && str[3] == '\n')
		st = reverse_ab(st);
	else
		st.error = 1;
	return (st);
}

struct stacks	check_move(char *move_str, t_stack_gen st)
{
	if (move_str[0] == 'p')
		st = push_checker(move_str, st);
	if (move_str[0] == 's')
		st = swap_checker(move_str, st);
	if (move_str[0] == 'r')
	{
		if (ft_strlen(move_str) > 3 && move_str[1] == 'r')
			st = reverse_checker(move_str, st);
		else
			st = rotate_checker(move_str, st);
	}
	return (st);
}

struct stacks	init_stack(void)
{
	t_stack_gen	st;

	st.mvs = 0;
	st.error = 0;
	st.alen = 0;
	st.blen = 0;
	return (st);
}

int	check_if_error(char *str)
{
	if (str[0] == 'E' && str[1] == 'r' && str[2] == 'r' && str[3] == 'o'
		&& str[4] == 'r' && str[5] == '\n')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	t_stack_gen	st;
	char		*str;

	i = 0;
	argc++;
	if (argc == 1)
		return (0);
	st = init_stack();
	st.a = to_stack(argv, &st);
	st.clen = st.alen;
	if (st.error != 0)
		return (print_error());
	str = get_next_line(STDIN_FILENO);
	if (check_if_error(str) == 0 || !str)
		return (print_error());
	printf("eo");
	getchar();
	while (str != 0)
	{
		st = check_move(str, st);
		free(str);
		if (st.error != 0)
			return (print_error());
		str = get_next_line(STDIN_FILENO);
		i++;
	}
	if (check_if_a_ordered(st) == 0 && st.alen == st.clen)
		write(1, "OK!", 3);
	else
		write(1, "KO!", 3);
	//st = free_management(st);
	return (0);
}
