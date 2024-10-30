/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:49:41 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/25 13:38:05 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//general purpose function, copies anything, moves bytes to different addresses
//deals with raw bytes(8bits), you can copy arrays of integers or any type data
//unsigned char represents a single byte
//copying memory happens byte by byte, assuming memory regions don't overlap!
//It takes three arguments:
//dst: a pointer to the destination memory block where you want to copy data.
//src: a pointer to the source memory block that you want to copy from.
//n: the number of bytes to copy. doesn’t recognize stop at null terminators
//It returns a void*, which is a generic pointer to memory dest.
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*s;

	// if (n == 0 || dest == src)
	// 	return dest; //no action
	// if (dest == (void *)0 && src == (void *)0) //cast is cmp for generic pointers
	// 	return NULL;
	dst = (unsigned char *)dest; //cnvrt dest pointer to byte pointer
	s = (const unsigned char *)src;
	while (n-- > 0) //loop asccess memory addresses through pointers
	{
		*dst++ = *s++; //cpy byte by byte from src to dst and increment
	}
	return (dest); //original dest pointer, continue work wth modified memory
}
