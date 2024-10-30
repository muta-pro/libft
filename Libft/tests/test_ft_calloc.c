/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:35:06 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/29 22:48:04 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <assert.h>
#include "libft.h"
#include <string.h>

void *ft_calloc(size_t nmemb, size_t size);

void test_ft_calloc()
{
	//basic allocation and zero-init
	size_t nmemb = 5;
	size_t size = sizeof(int);
	int *arr = (int *)ft_calloc(nmemb, size);//want arr to be array of int(cast)
	assert(arr != NULL);
	for (size_t i = 0; i < nmemb; i++;)
		assert(arr[i] == 0); //each byte zeroed
	free(arr);

	//zero elements (nmemb is 0)
	nememb = 0;
	size = sizeof(int);
	arr = (int *)ft_calloc(nmemb, size);//create array of int
	assert(arr == NULL || (nmemb == 0 && arr != NULL));//NULL pointer or unsuable
	free(arr);

	//zero size
	nmemb = 5;
	size = 0;
	arr = (int *)ft_calloc(nmemb, size);
	assert(arr == NULL || (size == 0 && arr != NULL));//depends on implementatoin
	free(arr);

	//very large allocatoin - overflow
	nmemb = SIZE_MAX;
	size = SIZE_MAX;
	arr = (int *)ft_calloc(nmemb, size);
	assert(arr == NULL);//no alloc possible	
}

int main()
{
	test_ft_calloc();
	printf("All test passed, WIN_MAX!\n");
	return (0);
}

