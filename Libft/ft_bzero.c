/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:08:36 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/24 21:00:14 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Modifies a portion of memory in place by setting bytes to zero
//should not modify the memory outside the buffer - overflow
//ARG: pointer to block of memory, num bytes to zero out
//void *type(can point to any type of data)
//unsigned char is 1byte positive
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	if (s == NULL)
		return;
	p = (unsigned char *)s;//to work wth individual bytes
	while (n-- > 0) //setting each byte to 0 as long as n > 0
	{
		*p++ = 0;//access a memory location and assigns it to 0, zeroing byte
		//increments the pointer to next byte
	}
}
