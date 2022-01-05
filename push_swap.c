
#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	simb;
	unsigned long	num;
	int	i;

	i = 0;
	num = 0;
	simb = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			simb = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != 0)
		return 0;
	return ((int )simb * num);
}


static int  *to_stack(int argc, char **argv)
{
    int *stack;
    int i;
    int j;

    i = 0;
    j = 1;
    stack = (int *) malloc(sizeof(int) * argc);
    if (!stack)
        return (0);
    stack[argc] = 0;
    while (i < argc - 1)
    {
        stack[i] = ft_atoi(argv[j]);
		if (!stack[i])
			return (0);
        printf("%d ", stack[i]);
        i++;
        j++;
    }
    return (stack);
}

static int	checker(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	return 1;
}

static int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
struct stacks	sort_5(stack_gen st)
{
	int	flg;
	int	i;

	flg = 0;
	i = 0;
	while (flg != slen)
	{
		flg = 0;
		if (stack_a[0] > stack_a[1])
		{
			stack_a = swap_a(stack_a);

		}
		else
		{

		}
	}
}


int	main(int argc, char **argv)
{
	stack_gen st;
	if (checker(argc, argv) == 0)
		return (print_error());
	st.a = to_stack(argc, argv);
	if (!st.a)
		return (print_error());
	st.alen = argc - 1;
	st.blen = 0;
	if (st.alen <= 5)
		st = sort_5(st);
	return (0);
}