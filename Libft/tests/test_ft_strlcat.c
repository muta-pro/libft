/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:40:19 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/22 22:56:34 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t ft_strlcat(char *dst, const char *src, size_t size);

void test_ft_strlcat()
{
	char buffer[100];
	size_t result;

	//dst has space for both strings and NUL
	memset(buffer, 0, sizeof(buffer)); //clear the buffer
	strcpy(buffer, "Lepo je"); //initialise dst with src
	result = ft_strlcat(buffer, " sve.", sizeof(buffer));
	assert(result == strlen("Lepo je sve.")); //checks if returns tot len
	assert(strcmp(buffer, "Lepo je sve.") == 0); //matching of buffer and str

	//buffer too small to append full src
	memset(buffer, 0 , sizeof(buffer));
	strcpy(buffer, "Lepo je");
	result = ft_strlcat(buffer, " sve.", 3);//small buffer
	assert(result == 3 + strlen(" sve.")); 
	assert(strcmp(buffer, "Lepo je") == 0); //checks if truncation

	//dst buffer full
	memset(buffer, 0, sizeof(buffer));
	strcpy(buffer, "Lepo je");
	result = ft_strlcat(buffer, " sve.", 8);//full buffer
	assert(result == strlen("Lepo je sve."));
	assert(strcmp(buffer, "Lepo je") == 0);

	//empty dst buffer
	memset(buffer, 0, sizeof(buffer));
	result = ft_strlcat(buffer, " sve.", sizeof(buffer));
	assert(result == strlen(" sve."));
	assert(strcmp(buffer, " sve.") == 0);

	//empty src
	memset(buffer, 0, sizeof(buffer));
	strcpy(buffer, "Lepo je");
	result = ft_strlcat(buffer, "", sizeof(buffer));
	assert(result == strlen("Lepo je"));
	assert(strcmp(buffer, "Lepo je") == 0);

	//empty dst and src
	memset(buffer, 0, sizeof(buffer));
	result = ft_strlcat(buffer, "", sizeof(buffer));
	assert(result == strlen(""));
	assert(strcmp(buffer, "") == 0);
	
	//size 0 dst buffer/ size == 0
	memset(buffer, 0, sizeof(buffer));
	strcpy(buffer, "Lepo je"); //intitialize dst
	result = ft_strlcat(buffer, " sve.", 0); //0 size buffer
	assert(result == strlen( " sve.")); //lenght return
	assert(strcmp(buffer, "Lepo je") == 0); //unchanged buffer

	//1 byte dst size
	memset(buffer, 0, sizeof(buffer));
	strcpy(buffer, "A"); //init dst with single chr
	result = ft_strlcat(buffer, " sve", 1); //dst buffer 1 size
	assert(result == strlen("A") + strlen(" sve"));
	assert(strcmp(buffer, "A") == 0); //buffer remains unchanged

	//buffer with 1 byte left for NUL
	memset(buffer, 0, sizeof(buffer));
	strcpy(buffer, "A");
	result = ft_strlcat(buffer, "B", 2); //space for A and NUL
	assert(result == strlen("A") + strlen("B")); // lenght AB
	assert(strcmp(buffer, "A") == 0); // no room to append, buffer stays same

	//src longer than total dst
	memset(buffer, 0, sizeof(buffer));
	strcpy(buffer, "Lepo je");
	result = ft_strlcat(buffer, " sve.....", 10); //small buffer
	assert(result == strlen("Lepo je") + strlen(" sve....."));
	assert(strcmp(buffer, "Lepo je s") == 0); //only part of src fits
}

int main()
{
	test_ft_strlcat();
	printf("All passed!\n");
	return (0);
}