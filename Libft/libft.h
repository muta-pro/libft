#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
int	ft_atoi(const char *str);
int	ft_tolower(int c);
int	ft_toupper(int c);
int	ft_isprint(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
#endif