
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

}	stack_gen;

struct stacks swap_a(stack_gen st);

struct stacks	push_b(stack_gen st);

#endif