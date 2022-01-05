#include "push_swap.h"

struct stacks	first_check_b(stack_gen st)
{
	int	i;
	int	j;
	int	flg;
	
	j = 1;
	i = 0;
	flg = 0;
	if (st.blen == 0 || st.blen == 1)
		return (st);
	if (st.blen == 2)
	{
		if (st.b[0] < st.b[1])
			st = swap_b(st);
		return (st);
	}
	while (j <= st.blen - 1)
	{
		if (st.b[i] > st.b[j])
			flg++;
		i++;
		j++;
	}
	printf("%d", flg);
	if (flg == st.blen - 1)
		st.its_ord = 1;
	else
		st.its_ord = 0;
	return (st);
}

int	position_b(stack_gen st)
{
	int	i;
	int	j;

	if (st.blen == 0 || st.blen == 1)
		return (0);
	i = 0;
	j = 1;
	while (st.b[i] > st.b[j] && j < st.blen)
	{
		i++;
		j++;
	}
	return (j);
}

struct stacks	final_or(stack_gen st, int pos)
{
	int	i;

	i = 0;
	st = rotate_b(st);
	while (i <= pos)
	{
		st = push_a(st);
		i++;
	}
	st = rotate_b(st);
	i = 0;
	while (i < pos)
	{
		st = push_b(st);
		i++;
	}
	st.its_ord = 1;
	return (st);
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
	while (st.blen != brk)
	{
		if (st.alen > 1)
		{
			if (st.a[0] > st.a[1])
			{
				st = swap_a(st);
				st = push_b(st);
			}
			else
				st = push_b(st);
			st.its_ord = 0;
			st = first_check_b(st);
			break;
			if (st.its_ord == 0)
			{
				pos = position_b(st);
				st = final_or(st, pos);
			}	
		}
		if (st.alen == 1)
			st = push_b(st);
		
	}
	printf("bbbbbb");
	while (st.alen != brk)
	{
		st = push_a(st);
	}
	return (st);
}