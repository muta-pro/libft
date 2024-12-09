/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:50:59 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/08 15:22:35 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
//node of the linked list
typedef struct	s_list
{
	char		*str_buf;
	struct		s_list *next;
}				t_list;

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
#endif