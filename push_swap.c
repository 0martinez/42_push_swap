#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	if (str[i] < '0' && str[i] > '9')
	{
		printf("aaa");
		return 0;
	}
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

static int	stack_len(int *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack[i] != 0)
		i++;
	return (i);
}

static int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	int *stack;
	int *new_stack;
	if (checker(argc, argv) == 0)
		return (print_error());
	stack = to_stack(argc, argv);
	if (!stack)
		return (print_error());
	return (0);
}