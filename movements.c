#include "push_swap.h"

struct stacks	swap_a(stack_gen st)
{
	int	aux;

	if (st.alen == 0 || st.alen == 1)
		return (st);
	aux = st.a[0];
	st.a[0] = st.a[1];
	st.a[1] = aux;
	return (st);
}

struct stacks	swap_b(stack_gen st)
{
	int	aux;

	if (st.blen == 0 ||st.blen == 1)
		return (st);
	aux = st.b[0];
	st.b[0] = st.b[1];
	st.b[1] = aux;
	return (st);
}

struct stacks	swap_ab(stack_gen st)
{
	st = swap_a(st);
	st = swap_b(st);
	return (st);
}

struct stacks	push_a(stack_gen st)
{
	int	i;
	int	j;
	int *new_a;
	int *new_b;

	i = 1;
	j = 0;
	if (st.blen == 0)
		return (st);
	st.blen--;
	st.alen++;
	new_b = malloc(sizeof(int) * st.blen);
	new_a = malloc(sizeof(int) * st.alen);
	if (!new_a || !new_b)
		return st;
	new_a[0] = st.b[0];
	while (j < st.blen)
	{
		new_b[j] = st.b[i];
		i++;
		j++;
	}
	free(st.b);
	st.b = new_b;
	i = 1;
	j = 0;
	while (i < st.alen)
	{
		new_a[i] = st.a[j];
		i++;
		j++;
	}
	free(st.a);
	st.a = new_a;
	return (st);
}

struct stacks push_b(stack_gen st)
{
	int	i;
	int	j;
	int *new_a;
	int *new_b;

	i = 1;
	j = 0;
	if (st.alen == 0)
		return (st);
	st.alen--;
	st.blen++;
	new_b = malloc(sizeof(int) * st.blen);
	new_a = malloc(sizeof(int) * st.alen);
	if (!new_a || !new_b)
		return st;
	new_b[0] = st.a[0];
	while (j < st.alen)
	{
		new_a[j] = st.a[i];
		i++;
		j++;
	}
	free(st.a);
	st.a = new_a;
	i = 1;
	j = 0;
	while (i < st.blen)
	{
		new_b[i] = st.b[j];
		i++;
		j++;
	}
	free(st.b);
	st.b = new_b;
	return (st);
}

struct stacks	rotate_a(stack_gen st)
{
	int	aux;
	int	i;

	i = 0;
	aux = st.a[0];
	while (i < st.alen - 1)
	{
		
		st.a[i] = st.a[i + 1];
		i++;
	}
	st.a[i] = aux;
	return (st);
}

struct stacks	rotate_b(stack_gen st)
{
	int	aux;
	int	i;

	i = 0;
	aux = st.b[0];
	while (i < st.blen - 1)
	{
		st.b[i] = st.b[i + 1];
		i++;
	}
	st.b[i] = aux;
	return (st);
}

struct stacks	rotate_ab(stack_gen st)
{
	st = rotate_a(st);
	st = rotate_b(st);
	return (st);
}

struct stacks	reverse_a(stack_gen st)
{
	int	aux;
	int	i;

	if (st.alen == 0 || st.alen == 1)
		return (st);
	i = st.alen - 1;
	aux = st.a[st.alen - 1];
	while (i > 0)
	{
		st.a[i] = st.a[i - 1];
		i--;
	}
	st.a[0] = aux;
	return (st);
}

struct stacks	reverse_b(stack_gen st)
{
	int	aux;
	int	i;
	if (st.blen == 0 || st.blen == 1)
		return (st);
	i = st.blen - 1;
	aux = st.b[st.blen - 1];
	while (i > 0)
	{
		st.b[i] = st.b[i - 1];
		i--;
	}
	st.b[0] = aux;
	return (st);
}

struct stacks	reverse_ab(stack_gen st)
{
	st = reverse_a(st);
	st = reverse_b(st);
	return (st);
}

/*
int main (void)
{
	stack_gen st;

	st.alen = 3;
	st.blen = 3;
	st.a = malloc (sizeof(int) * 3);
	st.b = malloc (sizeof(int) * 3);
	st.a[0] = 1;
	st.a[1] = 2;
	st.a[2] = 3;

	st.b[0] = 5;
	st.b[1] = 6;
	st.b[2] = 7;

	st = push_a(st);
	st = push_a(st);
	st = push_a(st);
	st = push_a(st);
	st = push_a(st);
	int i = 0;
	while (i < st.alen)
	{
		printf("-%d-", st.a[i]);
		i++;
	}
	i = 0;
	while (i < st.blen)
	{
		printf("+%d+", st.b[i]);
		i++;
	}
	printf("   ");
	st = rotate_a(st);
	i = 0;
	while (i < st.alen)
	{
		printf("/%d/", st.a[i]);
		i++;
	}
	st = push_b(st);
	st = push_b(st);
	st = rotate_b(st);
	st = push_a(st);
	i = 0;
	while (i < st.blen)
	{
		printf("|%d|", st.b[i]);
		i++;
	}
	printf("    ");
	i = 0;
	while (i < st.alen)
	{
		printf("<%d>", st.a[i]);
		i++;
	}
	i = 0;
	printf("    ");
	st = reverse_a(st);
	while (i < st.alen)
	{
		printf("<%d>", st.a[i]);
		i++;
	}
	printf("    ");
	st = reverse_a(st);
	st = reverse_a(st);
	i = 0;
	while (i < st.alen)
	{
		printf("<%d>", st.a[i]);
		i++;
	}
	printf("   ");
	st = push_b(st);
	st = push_b(st);
	i = 0;
	while (i < st.alen)
	{
		printf("<%d>", st.a[i]);
		i++;
	}
	printf("   ");
	i = 0;
	while (i < st.blen)
	{
		printf("|%d|", st.b[i]);
		i++;
	}
	st = reverse_b(st);
	printf("   ");
	i = 0;
	while (i < st.blen)
	{
		printf("|%d|", st.b[i]);
		i++;
	}
	st = reverse_ab(st);
	printf("   ");
	i = 0;
	while (i < st.blen)
	{
		printf("|%d|", st.b[i]);
		i++;
	}
	printf("   ");
	i = 0;
	while (i < st.alen)
	{
		printf("<%d>", st.a[i]);
		i++;
	}
	return (0);
}*/