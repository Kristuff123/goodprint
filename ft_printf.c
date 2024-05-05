/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgraczyk <kgraczyk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:58:53 by kgraczyk          #+#    #+#             */
/*   Updated: 2024/05/05 11:16:15 by kgraczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int	process_format(char format_specifier, va_list args)
{
	if (format_specifier == '%')
		return (write(1, "%", 1));
	else if (format_specifier == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (format_specifier == 's')
		return (print_string(va_arg(args, char *)));
	else if (format_specifier == 'p')
		return (print_point(va_arg(args, void *)));
	else if (format_specifier == 'd' || format_specifier == 'i')
		return (print_int(va_arg(args, int)));
	else if (format_specifier == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (format_specifier == 'x')
		return (print_hex(va_arg(args, ssize_t), false));
	else if (format_specifier == 'X')
		return (print_hex(va_arg(args, ssize_t), true));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!format)
		return (0);
	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += process_format(format[i], args);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
