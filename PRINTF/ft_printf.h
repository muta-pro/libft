/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:34:18 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/31 14:34:48 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *, ...);

int	handle_placeholder(char spec, va_list args);
int	parse_fs(const char *fs, va_list args);
int	conv_char(int c);
int	conv_string(char *str);
int	conv_p(void *ptr);
int	conv_int(int num);
int	conv_unsigned(unsigned int num);
int	conv_hex(unsigned int num, int upp);
int	conv_percent(void);

#endif
