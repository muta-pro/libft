/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:09:11 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/04 20:24:59 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//extracts a substring from start to len.
//RTRN pointer to a newly allocated substring
//
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))//checks if start is beyound end of the string
		return (ft_strdup(""));//returns empty string is no substring
	if (len > ft_strlen(s + start))//adjusting the len to fit up to s
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));//mem alloc for substr
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)//cpy characters to nre string
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
