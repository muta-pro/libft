/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:32:53 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/31 14:34:53 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	handle_format(const char *f)
{

}
int	ft_printf(const char *fs, ...)
{
	va_list	args;
	int		chars_print;

	if (!fs)
		return (-1);
	va_start(args, fs);
	i = 0;
	chars_print = 0;
	while (*fs)
	{
		if (*fs == '%')
		{
			fs++;
			chars_print += handle_placeholder(*fs, args);
		}
		else
			chars_print += ft_putchar(fs);
		fs++;
	}
	va_end(args);
	return (chars_print);
}

int handle_placeholder(char spec, va_list args)
{
	int chars_print;

	count = 0;
	if (spec == 'c')
		chars_print += (char)ft_putchar(va_arg(args, int));
	if (spec == 's')
		chars_print += ft_putstr(va_arg(args, char *));
	if (spec == 'd' || spec == 'i')
		chars_print += ft_putnbr(va_arg(args, int));
	if (spec == 'p')
		chars_print += ft_putptr(va_arg(args, void *));
	if (spec == 'u')
		chars_print += ft_putuns(va_arg(args, unsigned int));
	if (spec == 'x' || spec == 'X')
		chars_print += (char)ft_puthex(va_arg(args, int), type);
	if (spec == '%')
		return (write(1, "%", 1));
	return (chars_print);
}
