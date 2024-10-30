/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:26:04 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/26 14:19:36 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n);

void test_ft_memcmp()
{
	char buffer1[] = "Gde si brate.";
	char buffer2[] = "Gde si brate.";
	char buffer3[] = "Gde si batko!";
	char buffer4[] = "HEEEEEEEE.";
	char buffer5[] = "Gde";
	char buffer6[] = "";

	//identical strigs
	assert(ft_memcmp(buffer1, buffer2, sizeof(buffer1)) == 0);

	//different strings same prefix
	assert(ft_memcmp(buffer1, buffer3, sizeof(buffer1)) > 0);

	//different strings
	assert(ft_memcmp(buffer1, buffer4, sizeof(buffer1)) < 0);

	//partial comparison
	assert(ft_memcmp(buffer1, buffer5, 3) == 0);

	//empty buffer
	assert(ft_memcmp(buffer1, buffer6, 0) == 0);

	//comparison up to a certain point where differ
	assert(ft_memcmp(buffer1, buffer3, 7) == 0);

}

int main()
{
	test_ft_memcmp();
	printf("All test did pass, asshole.\n");
	return (0);
}
