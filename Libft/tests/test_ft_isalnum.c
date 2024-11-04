/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:22:59 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/14 15:41:55 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <assert.h>
#include <stdio.h>

int	ft_isalnum(int c);

void	test_ft_isalnum()
{
	assert(ft_isalnum('A') == 1);
	assert(ft_isalnum('c') == 1);
	assert(ft_isalnum('1') == 1);
	assert(ft_isalnum(' ') == 0);
	assert(ft_isalnum('@') == 0);
	assert(ft_isalnum(66) == 1);
	assert(ft_isalnum(0) == 0);
}

int	main()
{
	test_ft_isalnum();
	printf("All tests are passed! You are a genious!\n");
	return (0);
}
