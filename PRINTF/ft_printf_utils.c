/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:33:37 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/31 14:34:47 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
//fot %c
void	ft_putchar(char c, int fd)
{
	write (fd, &c, 1);
}
//for %s
void	ft_putstr(char *s, int fd)
{
	int	chars_read;

	if (!*s)
		return (-1);
	if (s == NULL)
		return (write(fd, "(null)", 6));
	chars_read = 0;
	while (s[chars_read])
	{
		write (fd, &s[chars_read], 1);
		chars_read++;
	}
	return (chars_read);
}
//for %d and %i
void	ft_putnbr_fd(int n, int fd)
{
	char	chars_read;

	if (!n)
		return (-1);
	chars_read = 0;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		chars_read += ft_putchar('-');
		chars_read += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		chars_read += ft_putnbr(n / 10, fd);
		chars_read += ft_putnbr(n / % 10, fd);
	}
	else
		chars_read += ft_putchar(n + '0');
}
//for %u
int ft_putuns(unsigned int n)
{
	int chars_read;

	if(!n)
		return (-1);
	chars_read = 0;
	if (n > 0)
	{
		chars_read += ft_putnbr(n / 10);
		chars_read += ft_putnbr(n % 10);
	}
	else if (n >= 0 && n < 10)
		chars_read += ft_putnbr(n + '0');
	if (chars_read < 0)
		return (-1);
	return (chars_read);
}
