/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:45:02 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/22 22:59:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len);

void	test_ft_strnstr()
{
	//little is '\0' = match at the start.
	char	*big = "Pomog' Bog";
	char	*result = ft_strnstr(big, "", 5);

	assert(result == big);

	//little found within len
	result = ft_strnstr(big, "Bog", 10);
	assert(result == &big[7]);

	//little found byond len i+j >= len
	result = ft_strnstr(big, "Bog", 5);
	assert(result == NULL);

	//little not found in big
	result = ft_strnstr(big, "Lele", 10);
	assert(result == NULL);

	//big is smaller than len
	result = ft_strnstr("Pomog", "og", 10); //search "og" in "Pomog"
	assert(result == &"Pomog"[3]); //pointer to the start of "o"

	//big and little are same string
	result = ft_strnstr("Pomog'", "Pomog'", 6);
	assert(strcmp(result, "Pomog'") == 0);

	//little is partly within len limit
	result = ft_strnstr("Pomog' Bog", "Bog", 9);
	assert(result == NULL);

	//len is 0
	result = ft_strnstr("Pomog' Bog", "Bog", 0);
	assert(result == NULL);
}

int main()
{
	test_ft_strnstr();
	printf("All test passed!\n");
	return (0);
}
