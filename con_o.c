/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:49:22 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/10 14:06:42 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
//#include <cstddef>
#include "libft/libft.h"
#include "ft_printf.h"

void	cast_nu_o(va_list args, t_data *data, char *format, int size)
{
	set_cast(data, format, size);
	if (data->cast == z)
		data->ori = itoa_base(va_arg(args, size_t), 10, 8);
	//if (nb < 0)
	//	data->positive = 0;
	else if (data->cast == none || data->cast == hh || data->cast == l)
		data->ori = itoa_base(va_arg(args, unsigned int), 10, 8);
	else if (data->cast == l)
		data->ori = itoa_base(va_arg(args,unsigned long), 10, 8);
	else if (data->cast == ll)
		data->ori = itoa_base(va_arg(args, unsigned long long), 10, 8);
	else if (data->cast == j)
		data->ori = itoa_base(va_arg(args, uintmax_t), 10, 8);
}

void	cast_nu_O(va_list args, t_data *data, char *format, int size)
{
	set_cast(data, format, size);
	data->ori = ft_itoa_max(va_arg(args,unsigned long));
}

void	set_print_oxu(t_data *data)
{
	int		len;
	int		blank;

	len = max_3(data->width, ft_strlen(data->ori), data->precison);
	if (data->precison == -1 || data->precison < (int)ft_strlen(data->ori))
		data->precison = ft_strlen(data->ori);
	if (!(len == 1 && data->ori[0] == '0'))
	{
			blank = len - data->precison;
		if (data->ori[0] == '0')
			blank = len;
		if (!ft_strchr(data->flags, '-'))
		{
			ft_putnchar(' ', blank);
			ft_putnchar('0', data->precison - ft_strlen(data->ori));
			if (data->ori[0] != '0')
			ft_putstr(data->ori);
		}
		else
		{
			ft_putnchar('0', data->precison - ft_strlen(data->ori));
			if (data->ori[0] != '0')
			ft_putstr(data->ori);
			ft_putnchar(' ', blank);
		}
	}
}

/*
void	set_print_ox(t_data *data)
{
	int		len;
	int		blank;
	len = max_3(data->width, ft_strlen(data->ori), data->precison);
	if (data->precison == -1 || data->precison < (int)ft_strlen(data->ori))
		data->precison = ft_strlen(data->ori);
	if (!(data->precison == 0 && data->ori[0] == '0'))
	{
			blank = len - data->precison;
		if (!ft_strchr(data->flags, '-'))
		{
			ft_putnchar(' ', blank);
			ft_putnchar('0', data->precison - ft_strlen(data->ori));
			ft_putstr(data->ori);
		}
		else
		{
			ft_putnchar('0', data->precison - ft_strlen(data->ori));
			ft_putstr(data->ori);
			ft_putnchar(' ', blank);
		}
	}
}
*/

void	con_o(va_list args, t_data *data, char *format, int size)
{
	cast_nu_o(args, data, format, size);
	//ft_putendl("enters here ?????");
	set_flags(data, format, size);
	set_print_oxu(data);
	//ft_putendl("enters here ?????");
	//set_print_d(data);
}

void	con_O(va_list args, t_data *data, char *format, int size)
{
	cast_nu_O(args, data, format, size);
	set_flags(data, format, size);
	set_print_oxu(data);
	//ft_putendl("enters here ?????");
	//set_print_d(data);
}
