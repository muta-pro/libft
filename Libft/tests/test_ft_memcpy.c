/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:02:58 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/25 05:20:17 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h> //input - output standard functions
#include <string.h> //memory functions and comparison utilities

void *ft_memcpy(void *dest, const void *src, size_t n);

void test_ft_memcpy()
{
	char buffer1[100], buffer2[100]; //buffers char arrays for testing

	//basic functionality
	char src1[] = "Tvoje oci vrlo dobro znam."; //string literal
	memcpy(buffer1, src1, strlen(src1) + 1); //+1 to copy null-terminator
	assert(strcmp(buffer1, src1) == 0); //Assert that both strings are equal

	//copy zero bytes
	memset(buffer1, 'x', 5); //prefill with 'x'
	memcpy(buffer1, src1, 0); //cpy 0 bytes
	assert(buffer1[0] == 'x'); // assert that buffer1 is unchanged

	//copy overlapping buffers
	strcpy(buffer1, src1); 
	memcpy(buffer1 + 5, buffer1, 5); //overlapping regions
	//behaviour undefined

	//copy large blocks of memory
	char large_src[1000], large_dest[1000];
	memset(large_src, 'A', 1000); //fill source with 'A'
	memcpy(large_dest, large_src, 1000); //cpy large block
	assert(memcmp(large_dest, large_src, 1000) == 0); //assert both strings equal

	//copy exact size of dest buffer
	char src2[] = "Progone me tvoje oci.";
	memcpy(buffer1, src2, sizeof(src2));
	assert(strcmp(buffer1, src2) == 0); //assert both str equal
	
	//copy non-char data
	int src3[] = {1, 2, 3, 4, 5};
	int dst3[5] = {0};
	memcpy(dst3, src3, 5 * sizeof(int)); //cpy integers
	assert(memcmp(dst3, src3, 5 * sizeof(int)) == 0); //memory areas are the same

	//source&dest are identical
	strcpy(buffer1, "Ime ti zovem");
	memcpy(buffer1, buffer1, strlen(buffer1));
	assert(strcmp(buffer1, "Ime ti zovem") == 0); //unchanged

	//copy part of larger memory block
	strcpy(buffer1, "meni je to bas neshvatljivo");
	memcpy(buffer2, buffer1, 7); //cpy first 7 characters from buff1 to buff2
	buffer2[7] = '\0'; //null-terminate manually buff2 as a valid string
	assert(strcmp(buffer2, "meni je") == 0); //copied part is correct
}

int main()
{
	test_ft_memcpy();
	printf("All tests passed!\n");
	return (0);
}
