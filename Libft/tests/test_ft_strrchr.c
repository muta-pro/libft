/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:15:03 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/16 01:12:31 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <assert.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c);

void	test_ft_strrchr()
{
	char	str1[] = "Imam si pare.";
	assert(ft_strrchr(str1, 'm') == (char *)&str1[3]);
	assert(ft_strrchr(str1, 'x') == 0);
	assert(ft_strrchr(str1, '\0') == (char *)&str1[13]);

	char	str2[] = "";
	assert(ft_strrchr(str2, 'r') == 0);

	char	str3[] = "g";
	assert(ft_strrchr(str3, 'g') == (char *)&str3[0]);
}

int	main()
{
	test_ft_strrchr();
	printf("All Tests Shall Pass!\n");
}
