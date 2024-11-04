/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 00:19:34 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/04 15:55:11 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//duplicates a string by allocating momory for the copy
//PRM string to dupplicate
//cpy each character
//RTRN pointer to the duplicate
//useful when you want a fresh cpy of a string to modify or free
char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	dest = (char *) malloc((ft_strlen(s) + 1));//alloc for the new string
	if (!dest)//check for malloc if successful
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
