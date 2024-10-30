/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:08:32 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/22 22:57:03 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//is designed specifically for strings. 
//It copies characters from one location to another 
//until it encounters a null terminator (\0).
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int i;
	size_t src_len;

	src_len = ft_strlen(src);

	if (src == NULL) //checks if the pointer is NULL
		return (0);
	if (dst[i] == NULL || size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}