/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_GNL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:51:53 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/08 14:25:53 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
// #include "get_next_line"

// int main(void)
// {
// 	int fd;
// 	char *next_line;
// 	int count;

// 	count = 0;
// 	fd = open("file.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error open");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		next_line = get_next_line(fd);
// 		count++;
// 		printf("[%d]:%s\n", count, next_line);
// 		free(line);
// 		next_line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }

// testing the read function > >
int main()
{
	int fd; //declare file descriptor
	char buf[256]; //declare buffer to read into
	int chars_read; // to stock return chars of read 



	fd = open("file.txt", O_RDONLY);
	while ((chars_read = read(fd, buf, 10)))
	{
		buf[chars_read] = '\0'; //we need to add nul terminator do the position
		printf("buffer -> %s\n", buf);
	}

}