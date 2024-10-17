/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:18:35 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/14 15:40:04 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

int	ft_isascii(int c);

void	test_ft_isascii()
{
	assert(ft_isascii(0) == 1);
	assert(ft_isascii('A') == 1);
	assert(ft_isascii('t') == 1);
	assert(ft_isascii(10) == 1);
	assert(ft_isascii(32) == 1);
	assert(ft_isascii(-1) == 0);
	assert(ft_isascii(150) == 0);
}
int	main()
{
	test_ft_isascii();
	printf("All tests are passed! You are the best!\n");
}