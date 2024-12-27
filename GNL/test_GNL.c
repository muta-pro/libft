/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_GNL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:51:53 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/23 19:20:53 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"



//latest version

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    if (fd < 0)
    {
    	perror("Error opening file");
    	close(fd);
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // IMPORTANT: Free the line returned by get_next_line
    }
    printf("Returned NULL for empty file.\n");
    close(fd);
    return (0);
}
// //test getnextline first version
// int main(void)
// {
// 	int fd;
// 	char *line;
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
// 		line = get_next_line(fd);
// 		if (line = NULL)
// 			break ;
// 		count++;
// 		printf("[%d]:%s\n", count, line);
// 		free(line);
// 		line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }

// // testing the read function > >
// int main()
// {
// 	int fd; //declare file descriptor
// 	char buf[256]; //declare buffer to read into
// 	int chars_read; // to stock return chars of read 



// 	fd = open("file.txt", O_RDONLY);
// 	while ((chars_read = read(fd, buf, 10)))
// 	{
// 		buf[chars_read] = '\0'; //we need to add nul terminator do the position
// 		printf("buffer -> %s\n", buf);
// 	}

// }

// int main()
// {
// 	char data[256];

// 	if(read(0, data, 128) < 0)
// 		write(2, "Error occur in read.\n", 21);
// 	exit(0);
// }


// //test open function
// int main()
// {
// 	size_t fd = open("file.txt", O_WRONLY | O_CREAT, 0644);
// 	if(fd < 0)
// 		return 1;
// 	if(write(fd, "testfile output.txt\n", 20) != 20)
// 	{
// 		write(2,"error writing to testfile.txt\n", 30);
// 		return 1;
// 	}
// 	close(fd);
// 	return 0;
// }
// //closing fd
// int main()
// {
// 	char *buffer = malloc(1024);
// 	if (buffer == NULL)
// 		return 1;
// 	free(buffer);
// 	return 0;
// }
