/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:59:54 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/14 15:40:03 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

int	ft_isprint(int c);

void	test_ft_isprint()
{
	assert(ft_isprint(0) == 0);
	assert(ft_isprint(18) == 0);
	assert(ft_isprint('3') == 1);
	assert(ft_isprint(' ') == 1);
	assert(ft_isprint(127) == 0);
	assert(ft_isprint(-1) == 0);
	assert(ft_isprint(500) == 0);
	assert(ft_isprint('@') == 1);
}
int	main()
{
	test_ft_isprint();
	printf("All tests are passed! You can go home.\n");
	return (0);
}
