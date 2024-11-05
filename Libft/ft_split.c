/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:04:43 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/04 20:28:23 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//splits a string by a delimiter into array of strings
//PRM string to split, delimiter
//RTRN array of split strings, nul terminated
//breakdown of delimited string into individual words
//gives exact number of words, allowing proper memory alloc
//dinamically alloc memory for each word based on delimiter
//by tracking each word's start and lenght, ensures correct cpy
//cpy characters, handling word-by-word cpy and nul termination
//RTRN array of pointers to the words, with NULL pointer at the end
static size_t	count_words(const char *s, char c)//staitc-limits visibility
{
	size_t	i;//size_t non-negative integer, iterates over s
	size_t	count;

	if (!s)//check for a NULL string input
		return (0);//avoids null-pointer dereferencing
	i = 0;
	count = 0;
	while (s[i] != '\0')//iterates through each char in s
	{
		while (s[i] == c && s[i] != '\0')//skip any leading delimiters or
											//between the words
			i++;
		if (s[i] != '\0')//count words
		{
			count++;//increments when non-delimiter encounter
			while (s[i] != '\0' && s[i] != c)//skip the word to next delimiter
				i++;
		}
	}
	return (count);//sequences of non-delimiter characters
}

static void	free_words(char **strings, size_t word)//mem cleanup if alloc fails
								//while building array of **strings - words
								//number of allocated words
{
	size_t	i;

	i = 0;
	while (i < word)//iterates through each string up to word times
	{
		free (strings[i]);//free each string before strings itself
		i++;
	}
	free (strings);//frees array that holds ** of each word/pervents mem leacks
}

static char	*next_word(const char *s, char c, size_t *let)//locates&extracts
							//*let pointer to index in s where next word begins
							//let keeps track of position in s between calls
{
	size_t	start;
	size_t	word_len;

	while (s[*let] == c && s[*let] != '\0')//skippin delimiters
		(*let)++;
	start = *let;//set to current position
	word_len = 0;//init to count word's len
	while (s[*let] != '\0' && s[*let] != c)
	{
		(*let)++;//advances counting len
		word_len++;//calculates the lenght of word
	}
	return (ft_substr(s, start, word_len));//mem alloc and cpy wach word in cell
}

char	**ft_split(char const *s, char c)
{
	size_t	let;//index tracker in s
	size_t	word;//num words added to string
	char	**strings;//array yo hold each split word

	word = 0;
	let = 0;
	strings = malloc(sizeof(char *) * (count_words(s, c) + 1));//alloc mem for word pointers
	if (!strings || !s)
		return (NULL);
	while (word < count_words(s, c))
	{
		strings[word] = next_word(s, c, &let);
		if (!strings[word])
		{
			free_words (strings, word);
			return (NULL);
		}
		if (strings[word][0] != '\0')
			word++;
	}
	strings[word] = NULL;
	return (strings);
}
