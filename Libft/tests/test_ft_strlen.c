/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:16:36 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/16 03:06:38 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <assert.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);

void	test_ft_strlen()
{
	char str[] = "Smex";
	assert(ft_strlen(str) == 4);
	char str1[] = "";
	assert(ft_strlen(str1) == 0);
	char str2[] = " ";
	assert(ft_strlen(str2) == 1);
	char str3[] = "\0";
	assert(ft_strlen(str3) == 0);
	char str4[] = "Smek  si!\n";
	assert(ft_strlen(str4) == 10);
	char str5[] = "this is a loooooooong string to test my funciton";
	assert(ft_strlen(str5) == 48);
}

int	main()
{
	test_ft_strlen();
	printf("All test are passed!\n");
}
