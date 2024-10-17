/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_islower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:46:04 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/14 16:08:37 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

int	ft_tolower(int c);

void	test_ft_tolower()
{
	assert(ft_tolower(0) == 0);
	assert(ft_tolower(77) == 77);
	assert(ft_tolower(65) == 97);
	assert(ft_tolower(' ') == ' ');
	assert(ft_tolower('@') == '@');
	assert(ft_tolower(200) == 200);
	assert(ft_tolower(-1) == -1);
	assert(ft_tolower(10) == 10);
}
int	main()
{
	test_ft_tolower();
	printf("All tests are passed, chill.\n");
}
