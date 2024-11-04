/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:17:54 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/04 13:17:54 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
//Calculates the length of a string.
//Params: const char *s (string)
//Return: size_t - length of the string
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
