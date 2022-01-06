#include "push_swap.h"

struct stacks	check_if_ordered(stack_gen st)
{
	int	i;
	int flg;

	i = 0;
	flg = 0;
	if (st.blen == 1)
		return (st);
	while (i + 1 < st.blen)
	{
		if (st.b[i] > st.b[i + 1])
			flg++;
		i++;
	}
	st.its_ord = 0;
	if (flg == st.blen - 1)
		st.its_ord = 1;
	return (st);
}

struct stacks	first_check_b(stack_gen st)
{
	int	i;
	int	j;
	int	flg;
	
	j = 1;
	i = 0;
	flg = 0;
	st = check_if_ordered(st);
	if (st.blen == 1 || st.its_ord == 1)
		return (st);
	if (st.blen == 2)
	{
		if (st.b[0] < st.b[1])
			st = swap_b(st);
		return (st);
	}
	if (st.blen == 3 && st.b[0] < st.b[1])
	{
		st = swap_b(st);
		return (st);
	}
	return (st);
}

int	position_b(stack_gen st)
{
	int	i;

	if (st.blen == 0 || st.blen == 1)
		return (0);
	i = 0;
	while (st.b[st.blen - 1] < st.b[i])
		i++;
	return (i);
}

struct stacks	final_or(stack_gen st)
{
	int	i;
	int	pos;

	i = 0;
	st = rotate_b(st);
	st = check_if_ordered(st);
	if (st.its_ord == 1)
		return (st);
	if (st.blen == 1 || st.blen == 2)
	{
		if (st.blen == 0 && st.b[0] < st.b[1])
			st = swap_b(st);
		return (st);
	}
	else
	{
		pos = position_b(st);
		//printf("position value = %d || blen = %d\n", pos, st.blen);
		while (i < pos)
		{
			st = push_a(st);
			i++;
		}
		st = reverse_b(st);
		i = 0;
		while (i < pos)
		{
			st = push_b(st);
			i++;
		}
		st.its_ord = 1;
		return (st);	
	}
	
}

struct stacks	swaps(stack_gen st)
{
	int	i;
	int	brk;
	int	flg;
	int	pos;

	brk = st.alen;
	flg = 0;
	i = 0;
	while (st.blen != brk && st.alen != 0)
	{
		//printf("\nINIT_PROCESS\n");
		if (st.a[0] > st.a[1])
		{
			st = swap_a(st);
			st = push_b(st);
		}
		else
			st = push_b(st);
		//printf("\nPRE_CHECK\n");
		st = first_check_b(st);
		//printf("\nPOST_CHECK\n");
		st = check_if_ordered(st);
		if (st.its_ord == 0)
		{
			//pos = position_b(st);
			st = final_or(st);
		}	
		if (st.alen == 1)
			st = push_b(st);
		//printf("\nEND_PROCESS\n");
	}
	printf("-------\n");
	while (st.alen != brk)
		st = push_a(st);
	return (st);
}