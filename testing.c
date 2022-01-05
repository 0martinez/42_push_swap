#include <stdio.h>
#include <stdlib.h>

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
    while (*st.c + i)
    {
        printf("%d", i);
        i++;
    }
    printf("+%d+", i);   
    st = ft_return(st);
    printf("%d %d", st.a, st.b);
    return 0;
}
