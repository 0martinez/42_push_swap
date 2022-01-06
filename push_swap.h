
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct stacks
{
	int	*a;
	int	*b;
	int	alen;
	int	blen;

	int	its_ord;
	int	mvs;

}	stack_gen;

static int atoi_checker;

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

#endif