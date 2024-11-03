/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:19:34 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/03 13:49:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

void	test_ft_atoi()
{
	assert(ft_atoi("123") == 123);
	assert(ft_atoi("-123") == -123);
	assert(ft_atoi( "12 ") ==  12 );
	assert(ft_atoi("--12") == 0);
	assert(ft_atoi("as123") == 0);
	assert(ft_atoi("123as") == 123);
	assert(ft_atoi("000123") == 123);
	assert(ft_atoi("\n") == 0);
	assert(ft_atoi("") == 0);
	assert(ft_atoi("--+") == 0);
	assert(ft_atoi("ab a") == 0);
	assert(ft_atoi("2147483647") == 2147483647);
	assert(ft_atoi("-2147483648") == -2147483648);
}
int	main()
{
	test_ft_atoi();
	printf("All tests passed! Bravo\n");
}
