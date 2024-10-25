/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:07:53 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/24 20:59:45 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//memcmp for two blocks of memory byte-by-byte at once
//memset for filling large blocks of memory with spec byte value,
//breaking task into chunks speeding up the process. 
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n);

void test_ft_bzero()
{
	char buffer[10];
	char expected[10];

	//n == 0 - array uncharnged
	strcpy(buffer, "da");
	strcpy(expected, "da");
	ft_bzero(buffer, 0);
	assert(memcmp(buffer, expected, strlen(expected)) == 0); //check whole buffer

	//n > 0 - n bytes zeroed
	strcpy(buffer, "dailine");
	memset(expected, 0, sizeof(expected));
	strncpy(&expected[3], "line", 4);//first 3 bytes zeroed
	ft_bzero(buffer, 3);
	assert(memcmp(buffer, expected, 7) == 0);

	//n == buffer
	strcpy(buffer, "da");
	strcpy(expected, "\0\0");
	ft_bzero(buffer, 2); //n zeroes whole buffer
	assert(memcmp(buffer, expected, 2) == 0); //buffer zeroed

	//n > buffer - undefined behabiour
	strcpy(buffer, "da");
	ft_bzero(buffer, 15);//n zeroes buffer
	//just check the whole crash

	//n == 1 - first byte zeroed
	strcpy(buffer, "d");
	strcpy(expected, "\0");
	ft_bzero(buffer, 1);
	assert(memcmp(buffer, expected, 1) == 0);

	//NULL pointer / defensive programming**
	char *null_p = NULL;
	ft_bzero(null_p, 3);//check for crashes, shouldn't crash

	//array with data (partial zeroing)
	strcpy(buffer, "123456");
	memset(expected, 0, 3); //set 1st three to 0
	memcpy(&expected[3], "456", 3); // copy the rest '456'
	ft_bzero(buffer, 3);
	assert(memcmp(buffer, expected, 6) == 0);

	//multy-byte data type - array of int not char
	//murltiple bytes must be zeroed at once
	int arr[] = {1, 2, 3 ,4};
	int expected_int[] = {0, 0, 3, 4};
	ft_bzero(arr, 2 * sizeof(int)); //zero out 1st two int(tot 8bytes)
	assert(memcmp(arr, expected_int, sizeof(arr)) == 0);

	//memory alignments - how data is laid out in memory
	strcpy(buffer, "dailine");
	ft_bzero(&buffer[2], 3); //zeroing from a misaligned position 'i'
	assert(memcmp(buffer, "da\0\0ine", 2) == 0); //expeting zeroed 'c','d'&'e'


	//large input - for correctnes and performance
	char xl_buffer[1000];
	char xl_expected[1000] = {0}; //expexted zeroed buff
	memset(xl_buffer, 'A', sizeof(xl_buffer)); //initialize buff to 'A'
	ft_bzero(xl_buffer, 1000); //zero out buff
	assert(memcmp(xl_buffer, xl_expected, 1000) == 0);//cmp whole buff
}

int main()
{
	test_ft_bzero();
	printf("All test passed!!!!!!\n");
	return (0);
}
