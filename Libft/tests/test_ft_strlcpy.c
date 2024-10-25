/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:08:02 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/22 22:56:36 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t ft_strlcpy(char *dst, const char *src, size_t size);

int test_ft_strlcpy()
{
	char buffer[100];
	//Basic copying
	memset(buffer, 0, sizeof(buffer)); //Clear the buffer
	size_t result = ft_strlcpy(buffer, "Lepo je!", sizeof(buffer)); //Call the strlcpy
	assert(result == strlen("Lepo je!")); //check return value is = src string
	assert(strcmp(buffer, "Lepo je") == 0); // check the dest string = to src string

	//Source longer than destination
	memset(buffer, 0, sizeof(buffer));
	result = ft_strlcpy(buffer, "Lepo je!", 5);
	assert(result == strlen("Lepo je!"));
	assert(strcmp(buffer, "Lepo ") == 0); //ensure truncation

	//Exact fit
	memset(buffer, 0, sizeof(buffer));
	result = ft_strlcpy(buffer, "123456789", 10); Fits
	assert(result == strlen("123456789"));
	assert(strcmp(buffer, "123456789") == 0);

	//Empty source string
	memset(buffer, 0, sizeof(buffer));
	result = ft_strlcpy(buffer, "", sizeof(buffer));
	assert(result == 0);
	assert(strcmp(buffer, "") == 0);

	//Null source string
	memset(buffer, 0, sizeof(buffer));
	result = ft_strlcpy(buffer, NULL, sizeof(buffer));
	assert(result == 0);
	assert(strcmp(buffer, "") == 0);

	//Null destination buffer
	size_t len = ft_strlcpy(NULL, "Some string", sizeof(buffer));
	assert(len = strlen("Some string"));

	//Buffer overflow pervention
	char long_src[150];
	memset(long_src, 'A', sizeof(long_src) - 1);
	long_src[sizeof(long_src) - 1] = '\0'; //create long src string
	memset(buffer, 0, sizeof(buffer)); //clear the buffer
	size_t result = ft_strlcpy(buffer, long_src, 10);
	assert(result == strlen(long_src)); //check return value src_len
	assert(strcmp(buffer, "AAAAAAAA") == 0); //check buffer with truncated string
}

int main()
{
	test_ft_strlcpy();
	printf("All Passed!\n");
	return (0);
}
