/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:25:37 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/23 19:41:00 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static t_gnl    *get_node(t_gnl **head, int fd)
{
    t_gnl    *node;

    node = *head;
    while (node)
    {
        if (node->fd == fd)
            return (node);
        node = node->next;
    }
    node = malloc(sizeof(t_gnl));
    if (!node)
        return (NULL);
    node->fd = fd;
    node->buffer = ft_strdup("");
    if (!node->buffer)
    {
        free(node);
        return (NULL);
    }
    node->next = *head;
    *head = node;
    return (node);
}

static void    free_node(t_gnl **head, int fd)
{
    t_gnl    *previous;
    t_gnl    *current;

    previous = NULL;
    current = *head;
    while (current)
    {
        if (current->fd == fd)
        {
            if (previous)
                previous->next = current->next;
            else
                *head = current->next;
            free(current->buffer);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

static char    *join_buffer(char *s1, char *s2)
{
    char    *result;
    size_t  i;
    size_t  j;
    size_t  len1;
    size_t  len2;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    result = malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);
    i = 0;
    while (i < len1)
    {
        result[i] = s1[i];
        i++;
    }
    j = 0;
    while (j < len2)
        result[i++] = s2[j++];
    result[i] = '\0';
    return (result);
}

static int    read_into_buf(t_gnl *node)
{
    char    *buffer;
    char    *temp;
    int     char_read;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (-1);
    char_read = read(node->fd, buffer, BUFFER_SIZE);
    if (char_read <= 0)
    {
        free(buffer);
        return (char_read);
    }
    buffer[char_read] = '\0';
    temp = join_buffer(node->buffer, buffer);
    free(buffer);
    free(node->buffer);
    node->buffer = temp;
    return (temp ? 1 : -1);
}

static char    *extract_line(char **buffer)
{
    char    *line;
    char    *temp;
    size_t  i;

    i = 0;
    if (!*buffer || !**buffer)
        return (NULL);
    while ((*buffer)[i] && (*buffer)[i] != '\n')
        i++;
    if ((*buffer)[i] == '\n')
        i++;
    line = ft_strndup(*buffer, i);
    if (!line)
        return (NULL);
    temp = ft_strdup(*buffer + i);
    free(*buffer);
    *buffer = temp;
    return (line);
}

char    *get_next_line(int fd)
{
    static t_gnl    *head;
    t_gnl           *node;
    char            *line;
    int             res;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    node = get_node(&head, fd);
    if (!node)
        return (NULL);
    res = 1;
    while (res > 0 && !ft_strchr(node->buffer, '\n'))
        res = read_into_buf(node);
    if (res == -1)
    {
        free_node(&head, fd);
        return (NULL);
    }
    line = extract_line(&node->buffer);
    if (!line || !node->buffer)
        free_node(&head, fd);
    return (line);
}
