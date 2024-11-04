/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 05:24:12 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/03 21:45:16 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
// Searches for a byte in memory.
// Params: const void *s(memory area), int c(byte to find), n(bytes to search)
// Return: void* - pointer to the found byte or NULL if not found
// locates first occurence of c(converted to unsigned char)in string s.
//works with byte string(not litteral like strchr)
//n for num bytes to search no nul character
//returns the address, void - versatile for different types of data
//pointer arithmetic
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = (const unsigned char *)s;//to a byte opinter to inspect bytes
	while (n-- > 0)//each byte to be inspected
	{
		if (*p == (unsigned char)c)//current byte matching c
			return ((void *)p);
		p++;
	}
	return (NULL);//if no match is found
}
