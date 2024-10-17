/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:59:15 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/14 15:37:32 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

int	ft_isalpha(int c);

void	test_ft_isalpha()
{
	assert(ft_isalpha('A') == 1);
	assert(ft_isalpha('z') == 1);
	assert(ft_isalpha('1') == 0);
	assert(ft_isalpha('@') == 0);
	assert(ft_isalpha(' ') == 0);
	assert(ft_isalpha(65) == 1);
	assert(ft_isalpha(97) == 1);
	assert(ft_isalpha(0) == 0);
}

int	main()
{
	test_ft_isalpha();
	printf("All tests passed!\n");
	return (0);
}