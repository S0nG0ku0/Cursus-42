#include "../libft/libft.h"

static void push(int *num1, int *num2, int *count_1, int *count_2)
{
    if (count_1 == 0)
    {
        ft_printf("Invalid input\n");
        return ;
    }
    int i = 0;
    int temp[*count_2];
    while (i < *count_2)
    {
        temp[i] = num2[i];
        i++;
    }
    num2[0] = num1[0];
    ((*count_1)--, i = 0);
    while (i < *count_1)
    {
        num1[i] = num1[i + 1];
        i++;
    }
    ((*count_2)++, i = 0);
    while (i < *count_2)
    {
        num2[i + 1] = temp[i];
        i++;
    }
}

void push_a(int *a, int *b, int *count_a, int *count_b)
{
    push(b, a, count_b, count_a);
    ft_printf("pa\n");
}

void push_b(int *a, int *b, int *count_a, int *count_b)
{
    push(a, b, count_a, count_b);
    ft_printf("pb\n");
}