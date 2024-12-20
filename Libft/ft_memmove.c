/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:27:24 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/03 23:34:12 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * ft_memmove: Moves memory from source to destination, safe for overlapping.
 * Params: void *dst, const void *src (source and destination), size_t n (number of bytes)
 * Return: void* - pointer to the destination memory area
 */
//cpy `n` bytes from `src` to `dest`, safely handling overlaps by BACKWARDcpy
//adjusting the copying direction if needed.
//useful for cases of src and dst ovelap. 
//returns pointer to 'dest'.
//ARG pointer dst block of memory, src block and size ob cpy bytes
// +++++++++++++++++++++++++++++++
// | 'a' | 'b' | 'c' | 'd' | 'e' |
// +++++++++++++++++++++++++++++++
//  0x100 0x101 0x102 0x103 0x104
// first copies the bytes to be copied into a temporary array
// then pastes them into the destination block
//OR 1st check if overlaping, to decide direction
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;// coverts to pointers to manipulate raw byte by byte
	s = (const unsigned char *)src;//handling single bytes and sign-extentions
	if (!dest && !src)// Check if both dest and src are NULL
		return (NULL);
	i = 0;
	if (d > s)// If `dest` starts after `src`, copy backwards - no corruption
	{
		while (n-- > 0)// Copy each byte from the end going backward
			d[n] = s[n];
	}
	else// Otherwise, copy forwards (left to right)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);//gives flexibility in chain operations - track data location
}
