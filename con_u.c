/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:49:22 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/10 16:18:31 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
//#include <cstddef>
#include "libft/libft.h"
#include "ft_printf.h"

void	cast_nu_u(va_list args, t_data *data, char *format, int size)
{
	set_cast(data, format, size);
	if (data->cast == z)
		data->ori = ft_itoa_max(va_arg(args, size_t));
	else if (data->cast == none || data->cast == hh || data->cast == l)
		data->ori = ft_itoa_max(va_arg(args, unsigned int));
	else if (data->cast == l)
		data->ori = ft_itoa_max(va_arg(args,unsigned long));
	else if (data->cast == ll)
		data->ori = ft_itoa_max(va_arg(args, unsigned long long));
	else if (data->cast == j)
		data->ori = ft_itoa_max(va_arg(args, uintmax_t));
}

void	cast_nu_U(va_list args, t_data *data, char *format, int size)
{
	set_cast(data, format, size);
		data->ori = ft_itoa_max(va_arg(args,unsigned long));
}

void	con_u(va_list args, t_data *data, char *format, int size)
{
	cast_nu_u(args, data, format, size);
	set_flags(data, format, size);
	set_print_oxu(data);
	//ft_putendl("enters here ?????");
	//set_print_d(data);
}

void	con_U(va_list args, t_data *data, char *format, int size)
{
	cast_nu_u(args, data, format, size);
	set_flags(data, format, size);
	set_print_oxu(data);
}
