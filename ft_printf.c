/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:11:07 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/04 18:37:28 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

int		is_format(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||\
			c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||\
			c == 'c' || c == 'C' || c == 'e' || c == 'E' || c == 'f' || c == 'F' ||\
			c == 'g' || c == 'G' || c == 'a' || c == 'A' || c == 'n');
}



int		d_format(const char *str, int index, int nbr)
{
	int		ct;
	char	*to_str;

	to_str = ft_itoa(nbr);
	ct = ft_strlen(to_str);
	ct = before_format(str, index, ct);
	return (ct);
}

int		before_format(const char *str, int index, int count)
{
	char	*s;
	int		i;
	int		width;

	i = 0;
}




int		ft_printf(const char *restrict format, ...)
{
	va_list		args;
	va_start(args, format);
	int			i;
	int			nbr;

	i = 0;
	nbr = 0;
	while (*format)
	{
		if( *format == '%')
		{
			while(format[i] && !is_format(format[i]))
				i++;
			if (format[i] == 'd')
			nbr = nbr + d_format(format, i, va_arg(args, int));
			format = format + i + 1;
		}
			ft_putchar(*format++);
		nbr++;
	}
	return (nbr);
}
