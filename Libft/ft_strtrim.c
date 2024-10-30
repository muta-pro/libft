/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:10:16 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/30 18:01:34 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	match_making(char c, const char *set);

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!set || !*set)
		return (ft_strdup(s1));
	while (s1[start] && match_making(s1[start], set))
		start++;
	while (end > start && match_making(s1[end - 1], set))
		end--;
	if (start == end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start));
}

int	match_making(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
