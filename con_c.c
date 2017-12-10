/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:49:22 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/10 13:11:24 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
//#include <cstddef>
#include "libft/libft.h"
#include "ft_printf.h"

/*
void	cast_nu_c(va_list args, t_data *data, char *format, int size)
{
	data->ori = (char *)malloc
	set_cast(data, format, size);
	if (data->cast == none)
		data->ori[0] = va_arg(args, int);
	else if (data->cast == l)
		data->ori[0] = va_arg(args, wchar_t);
	data->ori[1] = '\0';
}
*/

void	set_print_c(va_list args, t_data *data)
{
	int		len;

	len = max_2(1, data->width);
	if (ft_strchr(data->flags, '-'))
	{
		ft_putchar(va_arg(args, int));
		ft_putnchar(' ', len - 1);
	}
	else
	{
		ft_putnchar(' ', len - 1);
		ft_putchar(va_arg(args, int));
	}
}

void	con_c(va_list args, t_data *data, char *format, int size)
{
	set_cast(data, format, size);
	//cast_nu_c(args, data, format, size);
	set_flags(data, format, size);
	set_print_c(args, data);
}
