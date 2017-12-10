/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:49:22 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/10 14:44:43 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
//#include <cstddef>
#include "libft/libft.h"
#include "ft_printf.h"

static	int	nb_dg(intmax_t n)
{
	int i;
	uintmax_t nb;

	i = 1;
	if (n < 0)
	{
		i = 2;
		nb = (uintmax_t)n * -1;
	}
	else
		nb = (uintmax_t)n;
	while (nb > 9)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_itoa_max(intmax_t n)
{
	char	*number;
	int		len;
	intmax_t	cp_n;

	len = nb_dg(n);
	if (!(number = (char *)malloc(len + 1)))
		return (NULL);
	number[len] = '\0';
	if (!n)
		number[0] = '0';
	if (n < 0)
	{
		number[0] = '-';
		cp_n = (uintmax_t)n * -1;
	}
	else
		cp_n = (uintmax_t)n;
	while (cp_n)
	{
		number[--len] = cp_n % 10 + '0';
		cp_n = cp_n / 10;
	}
	return (number);
}

void	con_s(va_list args, t_data *data, char *format, int size)
{
	data->ori = va_arg(args, char *);
	set_cast(data, format, size);
	set_flags(data, format, size);
	//ft_putendl("test 00000000000000000000");
	set_print_s(data);
}

/*
   void	con_c(va_list args, t_data *data, char *format, int size)
   {
   data->ori = "va_arg(args, char)";
   set_flags(data, format, size);
   }
   */
/*
   void	cast_nu(t_data *data, intmax_t nb)
   {
   if (data->cast == z)
   data->ori = ft_itoa_max((size_t)nb);
   else
   {
   if (nb < 0)
   data->positive = 0;
   if (data->cast == none)
   data->ori = ft_itoa_max((int)nb);
   else if (data->cast == hh)
   data->ori = ft_itoa_max((signed char)nb);
   else if (data->cast == h)
   data->ori = ft_itoa_max((short int)nb);
   else if (data->cast == l)
   data->ori = ft_itoa_max((long int)nb);
   else if (data->cast == ll)
   data->ori = ft_itoa_max((long long int)nb);
   else if (data->cast == j)
   data->ori = ft_itoa_max(nb);
//else if (data->cast == t)
//			data->ori = ft_itoa_max((ptrdiff_t)nb);
}
}
*/

void	cast_nu(va_list args, t_data *data, char *format, int size)
{
	set_cast(data, format, size);
	//data->ori =	NULL;
	//ft_putendl("data->cast = ");
	//ft_putnbr(data->cast);
	//ft_putendl("");
	if (data->cast == z)
		data->ori = ft_itoa_max(va_arg(args, size_t));
	else	if (data->cast == none)
		data->ori = ft_itoa(va_arg(args, int));
	else	if (data->cast == hh)
		data->ori = ft_itoa_max(va_arg(args, int));
	else	if (data->cast == h)
		data->ori = ft_itoa_max(va_arg(args, int));
	else	if (data->cast == l)
		data->ori = ft_itoa_max(va_arg(args,long int));
	else	if (data->cast == ll)
		data->ori = ft_itoa_max(va_arg(args, long long int));
	else	if (data->cast == j)
		data->ori = ft_itoa_max(va_arg(args, intmax_t));
}



void	set_print_d(t_data *data)
{
	int		len;
	int		blank;
	len = max_3(data->width, ft_strlen(data->ori), data->precison);
	if (data->precison == -1)
		data->precison = ft_strlen(data->ori);
	if (!(data->precison == 0 && data->ori[0] == '0'))
	{
		if (ft_strchr(data->flags, '+') && data->ori[0] != '-')
			blank = len - data->precison - 1;
		else
			blank = len - data->precison;
		if (!ft_strchr(data->flags, '-'))
		{
			ft_putnchar(' ', blank);
			if (ft_strchr(data->flags, '+'))
			{
				if (data->ori[0] != '-')
					ft_putchar('+');
			}
			ft_putnchar('0', data->precison - ft_strlen(data->ori));
			ft_putstr(data->ori);
		}
		else
		{
			if (ft_strchr(data->flags, '+'))
			{
				if (data->ori[0] != '-')
					ft_putchar('+');
			}
			ft_putnchar('0', data->precison - ft_strlen(data->ori));
			ft_putstr(data->ori);
			ft_putnchar(' ', blank);
		}
	}
}



void	con_d(va_list args, t_data *data, char *format, int size)
{
	//	char	nb;
	//	nb = va_arg(args, int);
	//	data->ori = ft_itoa_max(va_arg(args, int));;
	cast_nu(args, data, format, size);
	set_flags(data, format, size);
	//ft_putendl("enters here ?????");
	set_print_d(data);
}
