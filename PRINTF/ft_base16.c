/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:25:19 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/31 14:34:49 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_printf.h>
//for %h
int ft_puthex(unsigned int n, int type)
{
	char *a;

	if (type == 'x')
		a = "0123456789abcdef";
	else
		a = "0123456789ABCDEF";
	return (ft_base16(n, a));
}
//for &p
int ft_putptr(void *arg)
{
	int chars_print;
	char *a;
	unsigned long arg2;

	arg2 = (unsigned long)arg;
	a = "0123456789abcdef";
	chars_print = 0;
	chars_print += ft_putstr('0x');
	chars_print += ft_base16(arg2, a);
	return (chars_print);
}

int ft_base16(unsigned long n, char *a)
{
	int chars_print;

	if (!n)
		return (-1);
	chars_print = 0;
	if (n > 15)
	{
		chars_print += ft_base16(n / 16, a);
		chars_print += ft_base16(n % 16, a);
	}
	else
		chars_print += ft_putchar(a[n]);
	return (chars_print);
}
