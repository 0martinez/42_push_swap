#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

typedef struct testing
{
    int a;
    int b;
    int *c;
} testeo;

struct testing ft_return(testeo a)
{
    a.a = 2;
    a.b = 4;
    return (a);
}

/*
int main (void)
{
    testeo st;

    st.a = 0;
    int i = 0;
    st.b = 1;
    st.c = malloc(sizeof(int) * 4 + 1);
    st.c[4] = '\0';
    while (i < 4)
    {
        st.c[i] = i;
        printf("-%d-", st.c[i]);
        i++;
    }
    i = 0;
    printf("+%d+", i);
    st = ft_return(st);
    printf("%d %d", st.a, st.b);
    return 0;
}*/

int	asdd(stack_gen *st)
{
	int	i;

	i = 0;
	st->error = 1;
	return (i);
}

int	main(void)
{
	int			i;
	stack_gen	st;

	st.error = 0;
	i = 0;
	i = asdd(&st);
	printf("%d", st.error);
	return (0);
}
