/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:09:42 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/04 14:01:37 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//creates new string allocating enough memory
//cpy both input strings into the new one
//useful for joining a filename with a path or comining strings
// Joins two strings into a new allocated string.
// Params: const char *s1, const char *s2 (strings to join)
// Return: char* - pointer to the new string
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;//newly allocated string
	size_t	i;//index to track cpy position in string
	size_t	j;

	i = 0;
	j = 0;
	dst = (char *)malloc(ft_strlen(s1) + (ft_strlen(s2) + 1) * sizeof(char));
	//allocate memory for number of elements of size char
	//returns a pointer to newly allocated space
	if (!dst)//if malloc fails to allocate
		return (NULL);
	while (s1[i] != '\0')//cpy s1 to dst
	{
		dst[i] = s1[i];
		i++;// i is set to last index copied, where the s2 continues
	}
	while (s2[j] != '\0')
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';//place to mark end of the string
	return (dst);//holding concatenated result
}
