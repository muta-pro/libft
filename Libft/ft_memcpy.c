/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:49:41 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/25 05:21:13 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// deals with raw bytes(8bits), you can copy arrays of integers or any type data
//unsigned char represents a single byte
//copying memory happens byte by byte, regardless of the type of data
//It takes three arguments:
//dst: a pointer to the destination memory block where you want to copy data.
//src: a pointer to the source memory block that you want to copy from.
//n: the number of bytes to copy.
//It returns a void*, which is a generic pointer to memory.
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*s;

	if (dest && src == 0)
		return (dest);
	dst = (unsigned char *)dest; //cnvrt dest pointer to byte pointer
	s = (const unsigned char *)src;
	while (n-- > 0)
	{
		*dst++ = *s++; //cpy byte by byte from src to dst and increment
	}
	return (dest); //original dest pointer, continue work wth modified memory
}
