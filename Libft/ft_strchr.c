/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:59:00 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/04 16:23:58 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
//Finds the first occurrence of a character in a string.
//Params: const char *s (string), int c (character to find)
//Return: char* - pointer to first occurrence or NULL if not found
char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
