/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:04:43 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/30 17:37:46 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//break down a delimited string into individual words
//gives the exact number of words, allowing proper memory allocation.
//dynamically allocates memory for each word based on the delimiter. 
//By tracking each word's start and length, it ensures correct copying.
//copying of characters, handling word-by-word copying and null-termination
//eturns an array of pointers to the words, with a NULL pointer at the end.

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')//skip delimiters
			i++;
		if (s[i] != '\0')//counting words
		{
			count++;
			while (s[i] != '\0' && s[i] != c)//skip the word
				i++;
		}
	}
	return (count);//sequences of non-delimiter characters
}

static void	free_words(char **strings, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word)
	{
		free (strings[i]);
		i++;
	}
	free (strings);
}

static char	*next_word(const char *s, char c, size_t *let)
{
	size_t	start;
	size_t	word_len;

	while (s[*let] == c && s[*let] != '\0')
		(*let)++;
	start = *let;
	word_len = 0;
	while (s[*let] != '\0' && s[*let] != c)
	{
		(*let)++;
		word_len++;
	}
	return (ft_substr(s, start, word_len));
}

char	**ft_split(char const *s, char c)
{
	size_t	let;
	size_t	word;
	char	**strings;

	word = 0;
	let = 0;
	strings = malloc(sizeof(char *) * (count_words(s, c) + 1));
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

// static int	ft_wordcount(char *str, char delimiter)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while(str[i] != '\0')
// 	{
// 		if (str[i] != delimiter)//identifies start of each word
// 		{
// 			count++;
// 			while(str[i] != delimiter && str[i] != '\0')
// 				i++;
// 			if (str[i] == '\0')
// 				return (count);
// 		}
// 		i++;
// 	}
// 	return (count);//improtant for memory allocation of output array
// }

// static void ft_strcpy(char *word, char *str, char c, int j)
// {
// 	int i;

// 	i = 0;
// 	while(str[j] == c)
// 		j++;
// 	while(str[j + i] != c && str[j + i] != '\0')
// 	{
// 		word[i] = str[j + i];
// 		i++;
// 	}
// 	word[i] = '\0';
// }

// static char	*ft_stralloc(char *str, char c, int *k)
// {
// 	char	*word;
// 	int		start;
// 	int		lenght;

// 	start = *k;
// 	lenght = 0;
// 	while (str[*k] != '\0')
// 	{
// 		if (str[*k] != c)//tracks each word start and len to cpy
// 		{
// 			start = *k;
// 			while (str[*k] != '\0' && str[*k] != c)
// 			{
// 				lenght++;
// 				(*k)++;
// 			}
// 			word = (char *)malloc(lenght + 1);
// 			if (word == NULL)
// 				return (NULL);
// 			ft_strcpy(word, str, c, start);
// 			return (word);
// 		}
// 		(*k)++;
// 	}
// 	return (NULL);
// }

// char	**ft_split(char const *str, char c) //CREATE ARRAY OW WORDS
// {
// 	char	**strs; //ARRAY OF POINTERS
// 	int		i;
// 	int		word_count;
// 	int		pos;

// 	if (str == NULL)
// 		return(NULL);
// 	i = 0;
// 	pos = 0;
// 	word_count = ft_wordcount((char *) str, c); //CALL
// 	strs = (char **)malloc(sizeof(char *) * (word_count + 1));
// 	if (strs == 0)
// 		return (NULL);
// 	while (i < word_count)
// 	{
// 		str[i] = ft_stralloc((char *) str, c, &pos); //CALL FILLS **STRS
// 		if (strs[i] == NULL)
// 			return (NULL);
// 		i++;
// 	}
// 	str[i] = NULL; //NUL pointer TERMINATES STRS END ARRAY
// 	return (strs);//array of pointers to the words
// }
