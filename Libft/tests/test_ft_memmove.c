/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:27:15 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/27 00:15:13 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n);

void	test_ft_memmove()
{
	char	buffer1[20] = "Hello, World";
	char	overl_src[] = "Overlap test!";
	char	overl_dest[20];

	//basic non-overlap copy from src to dst
	char	dest1[20];
	ft_memmove(dest1, buffer1, strlen(buffer1) + 1);
	printf("Expected: %s, Got: %s\n", buffer1, dest1);
	assert(strcmp(dest1, buffer1) == 0); //identical contents

   // Partial overlap: `dest` starts after `src`
    strcpy(overl_dest, overl_src); // Reset destination
    ft_memmove(overl_dest + 4, overl_dest, strlen(overl_dest) + 1);
    printf("Expected: OverOverlap test!, Got: %s\n", overl_dest);
    assert(strcmp(overl_dest, "OverOverlap test!") == 0);

	//cpy with partial overlap - src after dst
	strcpy(overl_dest, overl_src); //reset dest
	ft_memmove(overl_dest, overl_src + 4, strlen(overl_dest + 4) + 1);
	assert(strcmp(overl_dest, "lap test!") == 0);//moving forward same buffer

	//cpy zero bytes
	char	dest2[20] = "Unchanged";
	ft_memmove(dest2, buffer1, 0);
	assert(strcmp(dest2, "Unchanged") == 0);//destination unchanfed

	//exact buffer copy with 'n' bytes
	char	exact_dst[20];
	ft_memmove(exact_dst, buffer1, strlen(buffer1));
	assert(strncmp(exact_dst, buffer1, strlen(buffer1)) == 0);

	//large overlapping copy - shift to the right
	    // Initial setup: 'abcdefghijklmnopqrstuvwxyz'
    // Initial setup: 'abcdefghijklmnopqrstuvwxyz'
    char	large_ov_src[50] = "abcdefghijklmnopqrstuvwxyz";

    // Expected outcome after shifting: 'abcdeabcdefghijklmnopqrstuvwxyz'
    ft_memmove(large_ov_src + 5, large_ov_src, 21);
    
    printf("Expected: abcdeabcdefghijklmnopqrstuvwxyz, Got: %s\n", large_ov_src);
    assert(strcmp(large_ov_src, "abcdeabcdefghijklmnopqrstuvwxyz") == 0);

	//copying '\0' as parto of the transfer
	char	dest3[20] = "Initial";
	ft_memmove(dest3, "Short\0er", 7);
	assert(strcmp(dest3, "Short") == 0); //cpy stops when found '\0'
}

int main()
{
	test_ft_memmove();
	printf("All tests are mmmmoved, now mmmove your ass!\n");
	return (0);
}
//TEST FAIL!!!!!###########################################################