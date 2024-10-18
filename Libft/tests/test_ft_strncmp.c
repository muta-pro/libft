/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:37:47 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/18 20:59:58 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n);

int test_ft_strncmp()
{
	/*Have same strings with greater n*/
	if (ft_strncmp("Lepo je lepo.", "Lepo je lepo.", 14) != 0) return (1); //fail
	//Have s2 shorter string
	if (ft_strncmp("Lepo je lepo.", "Lepo i nije.", 14) <= 0) return (2); //fail
	//Smaller n
	if (ft_strncmp(" Lepo je lepo", "Lepo je lepo.", 3) >= 0) return (3); //fail
	//Different strings
	if (ft_strncmp("Lepo", "Nije", 5) >= 0) return (4); //fail
	//Empty strings
	if (ft_strncmp("", "", 3) != 0) return (5); //fail
	//Special characters or null terminators
	if (ft_strncmp("!\n", "\0", 1) <= 0) return (6); //fail
	//when n is zero
	if (ft_strncmp("Leop je", "Lepo je", 0) != 0) return (7); //fail
	//one string shorter but n limits comparison
	if (ft_strncmp("Lepo je", "Lep", 3) != 0) return (8); //fail
	return (0);
}

int main()
{
	int result = test_ft_strncmp();

	if (result == 0)
	{
		printf("test_ft_strncmp PASSED!!!\n");
	}
	else
	{
		printf("test_ft_strncmp FAILED (Error Code %d)\n", result);
	}
	return (0);
}
