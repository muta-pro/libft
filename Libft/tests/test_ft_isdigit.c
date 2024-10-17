/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:18:16 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/14 15:41:36 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

int	ft_isdigit(int c);

void	test_ft_isdigit()
{
	assert(ft_isdigit('8') == 1);
	assert(ft_isdigit(' ') == 0);
	assert(ft_isdigit('A') == 0);
	assert(ft_isdigit('!') == 0);
	assert(ft_isdigit(48) == 1);
	assert(ft_isdigit(35) == 0);
	assert(ft_isdigit(0) == 0);
}

int	main()
{
	test_ft_isdigit();
	printf("All tests passed!\n");
	return (0);
}
