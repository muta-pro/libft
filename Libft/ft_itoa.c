/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:10:41 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/03 21:27:31 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
// Converts an integer to a string.
// Params: int n (integer to convert)
// Return: char* - pointer to the resulting null-terminated string
//if n is negative the num will include -
static size_t	count_digit(long nbr);
static void		fill_string(char *nstr, long nbr, size_t len, int is_negative);

char	*ft_itoa(int n)//converts n to a dynamically allocated string
{
	long	nbr;//to store n to avoid overflow issues (INT-MIN)
	char	*nstr;//* to string where int will be stored
	size_t	len;//len of final string - depending on digits and sing
	int		is_negative;//flag to mark if negative numb

	is_negative = 0;
	nbr = n;
	if (nbr < 0)//determin if negative and convert to positive
	{
		is_negative = 1;
		nbr = -nbr;
	}
	len = count_digit(nbr) + is_negative;//count len for string + 1
	nstr = (char *)ft_calloc(len + 1, sizeof(char));//allocate mem fo string
	if (!nstr)
	{
		return (NULL);
	}
	fill_string(nstr, nbr, len, is_negative);//populate nstr with string of num
	return (nstr);
}

static size_t	count_digit(long nbr)//counts number of digits in nbr
{
	size_t	count;

	count = 0;
	if (nbr == 0)
		count ++;
	while (nbr > 0)
	{
		count++;
		nbr = nbr / 10;//to remove last digit, shift number
	}
	return (count);
}

static void	fill_string(char *nstr, long nbr, size_t len, int is_negative)
{
	size_t	i;

	i = len - 1;//sets i to the last index of the string - strart from end
	if (nbr == 0)
	{
		nstr[0] = '0';
		nstr[1] = '\0';
	}
	if (is_negative)
	{
		nstr[0] = '-';
	}
	while (nbr > 0)//convert nbr to string in reverse
	{
		nstr[i] = '0' + (nbr % 10);//converts digit to char
		nbr = nbr / 10;//drop the last digit
		i--;
	}
}
