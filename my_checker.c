

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

struct stacks	push_checker(char *str, t_stack_gen st)
{
	if (str[1] == 'b' && str[2] == 0)
		st = push_b(st);
	else if (str[1] == 'a' && str[2] == 0)
		st = push_a(st);
	else
		st.error = 1;
	return (st);
}

struct stacks	swap_checker(char *str, t_stack_gen st)
{
	if (str[1] == 'a' && str[2] == 0)
		st = swap_a(st);
	else if (str[1] == 'b' && str[2] == 0)
		st = swap_b(st);
	else if (str[1] == 's' && str[2] == 0)
		st = swap_ab(st);
	else
		st.error = 1;
	return (st);
}

struct stacks	rotate_checker(char *str, t_stack_gen st)
{
	if (str[1] == 'a' && str[2] == 0)
		st = rotate_a(st);
	else if (str[1] == 'b' && str[2] == 0)
		st = rotate_b(st);
	else if (str[1] == 'r' && str[2] == 0)
		st = rotate_ab(st);
	else
		st.error = 1;
	return (st);
	
}


struct stacks	reverse_checker(char *str, t_stack_gen st)
{
	if (str[2] == 'a' && str[3] == 0)
		st = reverse_a(st);
	else if (str[2] == 'b' && str[3] == 0)
		st = reverse_b(st);
	else if (str[2] == 'r' && str[3] == 0)
		st = reverse_ab(st);
	else
		st.error = 1;
	return (st);
}


struct stacks	check_move(char *move_str, t_stack_gen st)
{
	int	i;
	int	is_valid;

	is_valid = 0;
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

int	main(int argc, char **argv)
{
	int	i;
	char **moves;
	t_stack_gen st;


	i = 0;
	st = init_stack();
	st.a = to_stack(argv, &st);
	moves = ft_split(argv[1], '\n');
	if (st.error != 0)
	{
		st = free_management(st);
		return (print_error());
	}
	while (moves[i])
	{
		st = check_move(moves[i], st);
		if (st.error != 0)
			return (print_error());
		i++;
	}
	if (check_if_a_ordered(st) == 0)
		write(1, "OK!", 3);
	else
		write(1, "KO!", 3);
	free(moves);
	st = free_management(st);
	return (0);
}