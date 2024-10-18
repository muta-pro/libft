/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:05:37 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/14 15:40:02 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

int	ft_toupper(int c);

void	test_ft_toupper()
{
	assert(ft_toupper(0) == 0);
	assert(ft_toupper(77) == 77);
	assert(ft_toupper(97) == 65);
	assert(ft_toupper(' ') == ' ');
	assert(ft_toupper('@') == '@');
	assert(ft_toupper(200) == 200);
	assert(ft_toupper(-1) == -1);
	assert(ft_toupper(10) == 10);
}
int	main()
{
	test_ft_toupper();
	printf("All tests are passed, happy?\n");
}
