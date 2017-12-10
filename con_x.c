/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:49:22 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/10 18:11:39 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
//#include <cstddef>
#include "libft/libft.h"
#include "ft_printf.h"

void	cast_nu_x(va_list args, t_data *data, char *format, int size)
{
	set_cast(data, format, size);
	if (data->cast == z)
		data->ori = itoa_hex(va_arg(args, size_t), 'x');
	else if (data->cast == none || data->cast == hh || data->cast == l)
		data->ori = itoa_hex(va_arg(args, unsigned int), 'x');
	else if (data->cast == l)
		data->ori = itoa_hex(va_arg(args,unsigned long), 'x');
	else if (data->cast == ll)
		data->ori = itoa_hex(va_arg(args, unsigned long long), 'x');
	else if (data->cast == j)
		data->ori = itoa_hex(va_arg(args, uintmax_t), 'x');
}

void	cast_nu_X(va_list args, t_data *data, char *format, int size)
{
	set_cast(data, format, size);
	if (data->cast == z)
		data->ori = itoa_hex(va_arg(args, size_t), 'X');
	else if (data->cast == none || data->cast == hh || data->cast == l)
		data->ori = itoa_hex(va_arg(args, unsigned int), 'X');
	else if (data->cast == l)
		data->ori = itoa_hex(va_arg(args,unsigned long), 'X');
	else if (data->cast == ll)
		data->ori = itoa_hex(va_arg(args, unsigned long long), 'X');
	else if (data->cast == j)
		data->ori = itoa_hex(va_arg(args, uintmax_t), 'X');
}

void	set_print_x(t_data *data)
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

void	set_print_x_hash(t_data *data)
{
	int		len;
	int		no_pre;
	int		blank;

	no_pre = 0;
	if (data->precison == -1)
		no_pre = 1;
	if (data->ori[0] == '0')
		len = max_3(data->width, ft_strlen(data->ori), data->precison);
	else
		len = max_3(data->width, ft_strlen(data->ori) + 2, data->precison);

	if (data->precison < (int)ft_strlen(data->ori))
		data->precison = ft_strlen(data->ori);
	if (!(len == 1 && data->ori[0] == '0'))
	{
		if (no_pre)
		{
					blank = len - ft_strlen(data->ori);
					if (data->ori[0] != '0')
						blank = blank - 2;
			if (ft_strchr(data->flags, '-'))
			{
				if (data->ori[0] != '0')
					ft_putstr("0x");
				ft_putstr(data->ori);
				ft_putnchar(' ' , blank);
			}
			else
			{
				if (ft_strchr(data->flags, '0'))
				{
					if (data->ori[0] != '0')
						ft_putstr("0x");
					ft_putnchar('0' , blank);
					ft_putstr(data->ori);
				}
				else
				{
					ft_putnchar(' ' , blank);
					if (data->ori[0] != '0')
						ft_putstr("0x");
					ft_putstr(data->ori);
				}
			}
		}
		else
		{
			blank = len - data->precison;
				if (!data->precison && data->ori[0] == '0')
					blank++;
			if (data->ori[0] != '0')
				blank = blank - 2;
			if (ft_strchr(data->flags, '-'))
			{
				if (data->ori[0] != '0')
					ft_putstr("0x");
				ft_putnchar('0', data->precison - ft_strlen(data->ori));
				//if (!(data->precison && data->ori[0] == '0'))
					ft_putstr(data->ori);
				ft_putnchar(' ', blank);
			}
			else 
			{
				ft_putnchar(' ', blank);
				if (data->ori[0] != '0')
					ft_putstr("0x");
				ft_putnchar('0', data->precison - ft_strlen(data->ori));
			//	if (!(data->precison && data->ori[0] == '0'))
				ft_putstr(data->ori);
			//ft_putendl("enters here ?");
			}
		}
	}
}
	/*


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
	   */
/*
void	set_print_x_try(t_data *data)
{
	int		len;
	int		blank;
	int		o_pre;

	o_pre = 0;
	if (data->precison == -1)
		o_pre = 1;
	if (data->ori[0] != '0' && ft_strchr(data->flags, '#'))
		len = max_3(data->width, ft_strlen(data->ori) + 2, data->precison);
	else
		len = max_3(data->width, ft_strlen(data->ori), data->precison);
	if (data->precison < (int)ft_strlen(data->ori))
		data->precison = ft_strlen(data->ori);
	if (!(len == 1 && data->ori[0] == '0'))
	{
		if (data->ori[0] != '0' && ft_strchr(data->flags, '#'))
			blank = len - data->precison - 2;
		else
			blank = len - data->precison;
		if (data->ori[0] == '0')
			blank = len;
		if (!ft_strchr(data->flags, '-'))
		{
			if (!o_pre)
			{
				ft_putnchar(' ', blank);
				if (data->ori[0] != '0' && ft_strchr(data->flags, '#'))
					ft_putstr("0x");
				ft_putnchar('0', data->precison - ft_strlen(data->ori));
				if (data->ori[0] != '0')
					ft_putstr(data->ori);
			}
			else
			{
				if (data->ori[0] != '0' && ft_strchr(data->flags, '#'))
					ft_putstr("0x");
				ft_putnchar('0', blank);
				if (data->ori[0] != '0')
					ft_putstr(data->ori);
			}
		}
		else
		{
			if (data->ori[0] != '0' && ft_strchr(data->flags, '#'))
				ft_putstr("0x");
			ft_putnchar('0', data->precison - ft_strlen(data->ori));
			if (data->ori[0] != '0')
				ft_putstr(data->ori);
			ft_putnchar(' ', blank);
		}
	}
}
*/

void	con_x(va_list args, t_data *data, char *format, int size)
{
	cast_nu_x(args, data, format, size);
	set_flags(data, format, size);
	if (ft_strchr(data->flags, '#'))
	set_print_x_hash(data);
	else
	set_print_x(data);
}

void	con_XX(va_list args, t_data *data, char *format, int size)
{
	cast_nu_X(args, data, format, size);
	set_flags(data, format, size);
	set_print_oxu(data);
}
