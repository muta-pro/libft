/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:56:12 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/16 01:15:14 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c);

void	test_ft_strchr()
{
	char str1[] = "Imam pare.";
	assert(ft_strchr(str1, 'p') == (char *)&str1[5]);
	assert(ft_strchr(str1, 'z') == 0);
	assert(ft_strchr(str1, '\0') == (char *)&str1[10]);
	
	char str2[] = "";
	assert(ft_strchr(str2, 'b') == 0);

	char str3[] = "g";
	assert(ft_strchr(str3, 'g') == (char *)&str3[0]);
}

int	main()
{
	test_ft_strchr();
	printf("All tests passed!\n");
	return (0);
}
