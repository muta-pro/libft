/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:53:04 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/23 22:11:07 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

char    *ft_strchr(const char *s, int c)
{
    size_t  i;

    i = 0;
    if (!s)
        return (NULL);
    while (s[i])
    {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
        i++;
    }
    if ((char)c == '\0')
        return ((char *)&s[i]);
    return (NULL);
}

char    *ft_strdup(const char *s)
{
    char    *dup;
    size_t  len;
    size_t  i;

    if (!s)
        return (NULL);
    len = ft_strlen(s);
    dup = malloc(len + 1);
    if (!dup)
        return (NULL);
    i = 0;
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char    *ft_strndup(const char *s, size_t n)
{
    size_t    i;
    char    *dup;

    if (!s)
        return (NULL);
    dup = malloc(n + 1);
    if (!dup)
        return (NULL);
    i = 0;
    while (i < n && s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}
