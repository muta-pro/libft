/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 05:23:24 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/03 21:45:15 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <assert.h>

void *ft_memchr(const void *s, int c, size_t n);

void test_ft_memchr() {
    char buffer[] = "Hello, World!";
    
    // Test Case 1: Character found in the middle
    assert(ft_memchr(buffer, 'W', sizeof(buffer)) == &buffer[7]);

    // Test Case 2: Character found at the beginning
    assert(ft_memchr(buffer, 'H', sizeof(buffer)) == &buffer[0]);

    // Test Case 3: Character found at the end
    assert(ft_memchr(buffer, '!', sizeof(buffer)) == &buffer[12]);

    // Test Case 4: Character not in the string
    assert(ft_memchr(buffer, 'x', sizeof(buffer)) == NULL);

    // Test Case 5: Searching for null terminator
    assert(ft_memchr(buffer, '\0', sizeof(buffer)) == &buffer[13]);

    // Test Case 6: Zero bytes to search
    assert(ft_memchr(buffer, 'H', 0) == NULL);

    printf("All tests passed!\n");
}

int main() {
    test_ft_memchr();
    return 0;
}
