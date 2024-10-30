/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 05:24:12 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/25 15:11:14 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//locates the first occurence of c (convered to an unsigned char) in string s.
//it works with byte string(not litteral like strchr)
//n for num bytes to search/ no '\0' charachter
//returns the address, void - versatile for different types of data
//POINTER ARITHMETIC
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = (const unsigned char *)s; //to a byte pointer to inspect bytes
	while (n-- > 0) //each byte to be inspected
	{
		if (*p == (unsigned char)c) //current byte matching c
			return (void *)p;
		p++;
	}
	return (NULL);//if no match is found
}
