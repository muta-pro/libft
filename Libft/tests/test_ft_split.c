/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:40:46 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/30 18:01:04 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char    **ft_split(char const *str, char c);
// Helper function to print the result of ft_split
void print_split(char **result) {
    int i = 0;
    while (result[i] != NULL) {
        printf("Word %d: %s\n", i, result[i]);
        i++;
    }
}

// Helper function to free memory allocated by ft_split
void free_split(char **result) {
    int i = 0;
    while (result[i] != NULL) {
        free(result[i]);
        i++;
    }
    free(result);
}

void test_ft_split() {
    // Test case 1: Basic case with words separated by spaces
    char *str1 = "Hello World from ft_split";
    char delimiter1 = ' ';
    char **result1 = ft_split(str1, delimiter1);
    printf("Test 1: Basic case\n");
    print_split(result1);
    free_split(result1);

    // Test case 2: Empty string
    char *str2 = "";
    char delimiter2 = ' ';
    char **result2 = ft_split(str2, delimiter2);
    printf("Test 2: Empty string\n");
    print_split(result2);  // Expected: No output (just NULL)
    free_split(result2);

    // Test case 3: String with only delimiters
    char *str3 = ";;;;;";
    char delimiter3 = ';';
    char **result3 = ft_split(str3, delimiter3);
    printf("Test 3: Only delimiters\n");
    print_split(result3);  // Expected: No output (just NULL)
    free_split(result3);

    // Test case 4: String without any delimiters
    char *str4 = "NoDelimitersHere";
    char delimiter4 = ' ';
    char **result4 = ft_split(str4, delimiter4);
    printf("Test 4: No delimiters\n");
    print_split(result4);  // Expected: "NoDelimitersHere"
    free_split(result4);

    // Test case 5: String with delimiters at the beginning and end
    char *str5 = ";surrounded;by;semicolons;";
    char delimiter5 = ';';
    char **result5 = ft_split(str5, delimiter5);
    printf("Test 5: Delimiters at start and end\n");
    print_split(result5);  // Expected: "surrounded", "by", "semicolons"
    free_split(result5);

    // Test case 6: String with multiple consecutive delimiters
    char *str6 = "word;;word;word";
    char delimiter6 = ';';
    char **result6 = ft_split(str6, delimiter6);
    printf("Test 6: Consecutive delimiters\n");
    print_split(result6);  // Expected: "word", "word", "word"
    free_split(result6);

    // Test case 7: Long string with multiple delimiters
    char *str7 = "This is a long test string with multiple delimiters and words";
    char delimiter7 = ' ';
    char **result7 = ft_split(str7, delimiter7);
    printf("Test 7: Long string with spaces\n");
    print_split(result7);
    free_split(result7);

    // Test case 8: Single character string (non-delimiter)
    char *str8 = "a";
    char delimiter8 = ' ';
    char **result8 = ft_split(str8, delimiter8);
    printf("Test 8: Single character, not delimiter\n");
    print_split(result8);  // Expected: "a"
    free_split(result8);

    // Test case 9: Single character string (delimiter)
    char *str9 = ";";
    char delimiter9 = ';';
    char **result9 = ft_split(str9, delimiter9);
    printf("Test 9: Single character, is delimiter\n");
    print_split(result9);  // Expected: NULL
    free_split(result9);
}

int main() {
    test_ft_split();
    return 0;
}
