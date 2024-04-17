#include "../libft/libft.h"

static void swap(int *num, int count)
{
    int temp;
    if (num == NULL)
        return ;
    if (count == 1)
        return ;
    temp = num[0];
    num[0] = num[1];
    num[1] = temp;
}

void swap_a(int *num, int count)
{
    swap(num, count);
    ft_printf("sa\n");
}

void swap_b(int *num, int count)
{
    swap(num, count);
    ft_printf("sb\n");
}

void ss(int *num_a, int *num_b, int count_a, int count_b)
{
    swap(num_a, count_a);
    swap(num_b, count_b);
    ft_printf("ss\n");
}