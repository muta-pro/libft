/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:27:42 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/03 21:57:00 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
// Compares two blocks of memory.
// Params: const void *s1, const void *s2 (memory areas), size_t n (number of bytes)
// Return: int - negative, zero, or positive depending on comparison
//comparing two blocks of memory byte by byte.
//ARG ponters two mem blocks and num od bytes to cmp, regardless '\0'
//int is result of comparison 
//casting allow us to treat memory as an array of bytes to compare
//and prevents issues with sign extenntion during comparison
//reusult can be positive negativ or 0 when no difference
//useful for sorting ordering
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;//s1 to byte pointer
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
