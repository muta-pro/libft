/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:04:25 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/29 14:31:35 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//Fill a memory block with a specific byte value.
//ARG starting address to mem block
//ARG byte calue to set in each positoin
//ARG num bytes to fill
//Initial Memory Block: [00, 00, 00, 00, 00]
//c = 0xFF, len = 5
//Iteration 1: [FF, 00, 00, 00, 00]
//Iteration 5: [FF, FF, FF, FF, FF]
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;//key to access each byte in mem block
	p = (unsigned char *)b;//Start p at the beginning of b
	while (len > 0)
	{
		*p = (unsigned char)c; //Fill *p with the value c
		p++; //move to next byte
		len--;
	}
	return (b);
}
