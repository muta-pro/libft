/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:49:43 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/09 15:00:28 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *extract_line(char *buffer)
{
	size_t len = 0;
	while (buffer[len] && buffer[len] != '\n')
	len++;
	char *line = malloc(len + 1);
	if (!line)
		return NULL;

		strncpy(line, buffer, len);
		line[len] = '\0';
		return line;
}
void shift_buffer(char *buffer)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;

	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	 buffer[j] = '\0';
}

char *get_next_line(int fd)
{
	int bytes_read;
	char *cup_buffer[BUFFER_SIZE];
	int *line;

	cup_buffer = malloc (3 + 1, sizeof(char));
	if (cup_buffer == NULL)
		return (NULL);
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return NULL;
	return (cup_buffer);
	cup_buffer[bytes_read] = '\0';
	char *newline = ft_strchr(cup_buffer, '\n');
}