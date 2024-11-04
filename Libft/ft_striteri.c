/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:12:07 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/04 15:55:05 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//applies a funciton pointer f to each character of a string by index
//it iterates over each character in the string
//PRM string to modify, function to apply
//f gets access to address and character itself
//char* pointer to the character at this index
//RTRN none
//useful for transformation or operation to each char while tracking position
//defining the general behaviour we pass a specific func for different behav
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i; //current index tracking in string

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);//calls f, passing i and address of char at this index
		//as arguments
		i++;
	}
}
