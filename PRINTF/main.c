#include <stdio.h>
#include "ft_printf.h"
int main(void)
{
    char c = 'A';
    char *p = &c;
    printf("Val: %d\n", ft_printf("Hello\n"));
    printf("");
    ft_printf("%d\n", 0);
    printf("%d\n", -2147483649);
    ft_printf("%d\n", -2147483649);
    printf("%d%%677\n", 1);
    ft_printf("%d%", 1);
    //ft_printf("%p\n", p);


    return (0);
}