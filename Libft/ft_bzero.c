/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:08:36 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/03 21:01:15 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
// Params: void *s (starting memory address), size_t n (number of bytes)
// Return: None (void)
//Modifies a portion of memory in place by setting bytes to zero
//should not modify the memory outside the buffer - overflow
//ARG: pointer to block of memory, num bytes to zero out
//void *type(can point to any type of data)
//unsigned char is 1byte positive
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;//to work with individual bytes
	while (n-- > 0)//setting each byte to 0 as long as n > 0
	{
		*p++ = 0;//access memory location and assign it to 0
		//increments the pointer to next byte
	}
}
