/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgraczyk <kgraczyk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:10:54 by kgraczyk          #+#    #+#             */
/*   Updated: 2024/04/29 23:31:15 by kgraczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int		ft_printf(const char *__format, ...);
int		print_string(char const *str);
int		print_point(void *ptr_addr);
int		print_int(int n);
int		print_unsigned(unsigned int nbr);
int		print_hex(unsigned int nbr, bool upper_case);

#endif
