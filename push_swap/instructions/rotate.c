#include "../libft/libft.h"

static void rotate(int *num, int count)
{
    int i = 0;
    int tmp[count];
    while (i < count)
    {
        tmp[i] = num[i];
        i++;
    }
    i = 0;
    while (i < count)
    {
        num[i] = tmp[i + 1];
        i++;
    }
    num[count - 1] = tmp[0];
}

void rotate_a(int *num, int count)
{
    rotate(num, count);
    ft_printf("ra\n");
}

void rotate_b(int *num, int count)
{
    rotate(num, count);
    ft_printf("rb\n");
}

void rotate_a_b(int *a, int *b, int count_a, int count_b)
{
    rotate(a, count_a);
    rotate(b, count_b);
    ft_printf("rr\n");
}