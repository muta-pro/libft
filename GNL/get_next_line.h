/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:33:03 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/23 19:15:45 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

typedef struct s_gnl
{
    int             fd;
    char            *buffer;
    struct s_gnl    *next;
}               t_gnl;

char    *get_next_line(int fd);
char    *ft_strdup(const char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_strndup(const char *s, size_t n);
size_t  ft_strlen(const char *s);

#endif
