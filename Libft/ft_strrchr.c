/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:15:47 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/17 17:38:27 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;
	char			*last_uc;

	last_uc = NULL; /*set to NULL in case mantch not found*/
	uc = (unsigned char)c; /*casting charachter*/
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			last_uc = ((char *)&s[i]); /*put updated address of matching char*/
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]); /*pointer to \0*/
	return (last_uc);
}
